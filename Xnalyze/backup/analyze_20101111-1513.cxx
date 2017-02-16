// Author: Ron Belmont
// Date: 2009-07-28
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>

#include <sys/time.h>
 
#include "hadrontree.h"
 
#include "TROOT.h"
#include "TFile.h" 
#include "TTree.h"
#include "TH1.h" 
#include "TH2.h"   

using namespace std;



const float phbeta  = 29.9792458;
const float mpion   = 0.13957;
const float mkaon   = 0.493677;
const float mproton = 0.938270;



map<string,int> myMap;
void GetRunIndex();

bool goodStrip(int i);
bool isPion(float x, float m2tofw);
bool isKaon(float x, float m2tofw);
bool isProton(float x, float m2tofw);
float isPionNew(float x, float m2tofw);
float isKaonNew(float x, float m2tofw);
float isProtonNew(float x, float m2tofw);
float isPionLow(float x, float m2tofw);
float isKaonLow(float x, float m2tofw);
float isProtonLow(float x, float m2tofw);
bool GoodDCH(int run, float zed, float alpha, float phi);
bool GoodLoDCH(int run, float zed, float alpha, float phi);
bool GoodHiDCH(int run, float zed, float alpha, float phi);
bool GoodPC1(float ppc1z, float ppc1phi);
bool GoodPC2(float pc2z, float pc2phi);
bool GoodPC3(float pc3z, float pc3phi);
void fetchRunOffsetFromFile(int run); // new

float retunepc2sdphi(float x, int charge, float pc2sdphi, int run);
float retunepc2sdz(float x, int charge, float pc2sdz, int run);
float retunepc3sdphi(float mom, int charge, float pc3sdphi, int run);
float retunepc3sdz(float mom, int charge, float pc3sdz, int run);
float retunetofwsdphi(float mom, int charge, float tofwsdphi, int run);
float retunetofwsdz(float mom, int charge, float tofwsdz, int run);


Long64_t nevents = 0;
Long64_t ntracks = 0;
Long64_t ngoodtofwevents = 0;
Long64_t ngoodtofwtracks = 0;
Long64_t ntofwPIDtracks = 0;
Long64_t ngoodtofwtracks_snglevent = 0;

float runoffset = 0; // new


// Main part of program
int main() 
{ 

  Char_t inFile[100];
  Char_t outFile[100];

  cout<<"Now beginning program"<<endl;
  cout<<"Please enter input file name"<<endl;
  cin>>inFile;
  cout<<"Input file is "<<inFile<<endl;
  cout<<"Please enter output file name"<<endl;
  cin>>outFile;
  cout<<"Output file is "<<outFile<<endl;

  // ----------------------------

  struct timeval Time;

  gettimeofday(&Time,0);
  int begintime = Time.tv_sec;
  //cout<<"begintime is "<<begintime<<endl;

  // ----------------------------

  TFile *mData = new TFile(outFile,"recreate"); // declare output file

  GetRunIndex(); // get runindex from data file

  // -------------------------- //
  // --- Declare histograms --- //
  // -------------------------- //

  TH1F *hcount_no = new TH1F("hcount_no","hcount",120,0,10);
  TH1F *hcount_match = new TH1F("hcount_match","hcount",120,0,10);
  TH1F *hcount_tfwm = new TH1F("hcount_tfwm","hcount",120,0,10);
  TH1F *hcount_pc3m = new TH1F("hcount_pc3m","hcount",120,0,10);
  TH1F *hcount_pc2m = new TH1F("hcount_pc2m","hcount",120,0,10);
  TH1F *hcount_pc1f = new TH1F("hcount_pc1f","hcount",120,0,10);
  TH1F *hcount_pc2f = new TH1F("hcount_pc2f","hcount",120,0,10);
  TH1F *hcount_pc3f = new TH1F("hcount_pc3f","hcount",120,0,10);

  TH1F *qtofwdis = new TH1F("qtofwdis","qtofwdis",1000,0,1000);
  TH1F *qtofwdis_B = new TH1F("qtofwdis_B","qtofwdis",2000,0,2000);
  TH1F *qtofwdis_A = new TH1F("qtofwdis_A","qtofwdis",2000,0,2000);

  TH2F *m2rundis_pos = new TH2F("m2rundis_pos","m2 vs run", 870, 0, 870, 300, -1.0, 2.0);
  TH2F *m2rundis_neg = new TH2F("m2rundis_neg","m2 vs run", 870, 0, 870, 300, -1.0, 2.0);
  TH2F *m2stripdis_pos = new TH2F("m2stripdis_pos","m2 vs strip", 512, 0, 511, 300, -1.0, 2.0);
  TH2F *m2stripdis_neg = new TH2F("m2stripdis_neg","m2 vs strip", 512, 0, 511, 300, -1.0, 2.0);
  TH2F *DeltaTrundis_pos = new TH2F("DeltaTrundis_pos","#Deltat vs run", 870, 0, 870, 400, -2.0, 2.0);
  TH2F *DeltaTrundis_neg = new TH2F("DeltaTrundis_neg","#Deltat vs run", 870, 0, 870, 400, -2.0, 2.0);

  TH2F *m2centdis_pos = new TH2F("m2centdis_pos","m2 vs cent", 100, 0, 100, 300, -1.0, 2.0);
  TH2F *m2centdis_neg = new TH2F("m2centdis_neg","m2 vs cent", 100, 0, 100, 300, -1.0, 2.0);
  TH2F *m2centdis_1_pos = new TH2F("m2centdis_1_pos","m2 vs cent 1-1.1", 100, 0, 100, 300, -1.0, 2.0);
  TH2F *m2centdis_1_neg = new TH2F("m2centdis_1_neg","m2 vs cent 1-1.1", 100, 0, 100, 300, -1.0, 2.0);
  TH2F *m2centdis_2_pos = new TH2F("m2centdis_2_pos","m2 vs cent 2-2.1", 100, 0, 100, 300, -1.0, 2.0);
  TH2F *m2centdis_2_neg = new TH2F("m2centdis_2_neg","m2 vs cent 2-2.1", 100, 0, 100, 300, -1.0, 2.0);
  TH2F *m2centdis_3_pos = new TH2F("m2centdis_3_pos","m2 vs cent 3-3.1", 100, 0, 100, 300, -1.0, 2.0);
  TH2F *m2centdis_3_neg = new TH2F("m2centdis_3_neg","m2 vs cent 3-3.1", 100, 0, 100, 300, -1.0, 2.0);

  TH2F *m2momdis_pos = new TH2F("m2momdis_pos","m2 vs mom", 100, 0, 10, 300, -1.0, 2.0);
  TH2F *m2momdis_neg = new TH2F("m2momdis_neg","m2 vs mom", 100, 0, 10, 300, -1.0, 2.0);
  TH2F *m2momdis_pos_w1 = new TH2F("m2momdis_pos_w1","m2 vs mom", 100, 0, 10, 300, -1.0, 2.0);
  TH2F *m2momdis_neg_w1 = new TH2F("m2momdis_neg_w1","m2 vs mom", 100, 0, 10, 300, -1.0, 2.0);
  TH2F *m2momdis_pos_w2 = new TH2F("m2momdis_pos_w2","m2 vs mom", 100, 0, 10, 300, -1.0, 2.0);
  TH2F *m2momdis_neg_w2 = new TH2F("m2momdis_neg_w2","m2 vs mom", 100, 0, 10, 300, -1.0, 2.0);

  TH2F *isPi_dis_pos = new TH2F("isPi_dis_pos","isPi vs mom", 100, 0, 10, 100, -3.0, 7.0);
  TH2F *isPi_dis_neg = new TH2F("isPi_dis_neg","isPi vs mom", 100, 0, 10, 100, -3.0, 7.0);
  TH2F *isK_dis_pos = new TH2F("isK_dis_pos","isK vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *isK_dis_neg = new TH2F("isK_dis_neg","isK vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *isP_dis_pos = new TH2F("isP_dis_pos","isP vs mom", 100, 0, 10, 100, -7.0, 3.0);
  TH2F *isP_dis_neg = new TH2F("isP_dis_neg","isP vs mom", 100, 0, 10, 100, -7.0, 3.0);

  TH2F *DeltaTPi_dis_pos = new TH2F("DeltaTPi_dis_pos","DeltaTPi vs mom", 100, 0, 10, 400, -2.0, 2.0);
  TH2F *DeltaTPi_dis_neg = new TH2F("DeltaTPi_dis_neg","DeltaTPi vs mom", 100, 0, 10, 400, -2.0, 2.0);
  TH2F *DeltaTK_dis_pos = new TH2F("DeltaTK_dis_pos","DeltaTK vs mom", 100, 0, 10, 400, -2.0, 2.0);
  TH2F *DeltaTK_dis_neg = new TH2F("DeltaTK_dis_neg","DeltaTK vs mom", 100, 0, 10, 400, -2.0, 2.0);
  TH2F *DeltaTP_dis_pos = new TH2F("DeltaTP_dis_pos","DeltaTP vs mom", 100, 0, 10, 400, -2.0, 2.0);
  TH2F *DeltaTP_dis_neg = new TH2F("DeltaTP_dis_neg","DeltaTP vs mom", 100, 0, 10, 400, -2.0, 2.0);


  TH2F *pc2dz_cent_dis_pos = new TH2F("pc2dz_cent_dis_pos","pc2dz vs mom", 100, 0, 100, 100, -5.0, 5.0);
  TH2F *pc2dz_cent_dis_neg = new TH2F("pc2dz_cent_dis_neg","pc2dz vs mom", 100, 0, 100, 100, -5.0, 5.0);
  TH2F *pc2dphi_cent_dis_pos = new TH2F("pc2dphi_cent_dis_pos","pc2dphi vs mom", 100, 0, 100, 100, -5.0, 5.0);
  TH2F *pc2dphi_cent_dis_neg = new TH2F("pc2dphi_cent_dis_neg","pc2dphi vs mom", 100, 0, 100, 100, -5.0, 5.0);

  TH2F *pc2dz_dis_pos = new TH2F("pc2dz_dis_pos","pc2dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc2dz_dis_neg = new TH2F("pc2dz_dis_neg","pc2dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc2dphi_dis_pos = new TH2F("pc2dphi_dis_pos","pc2dphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc2dphi_dis_neg = new TH2F("pc2dphi_dis_neg","pc2dphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc2dz_dis_pos_C = new TH2F("pc2dz_dis_pos_C","pc2dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc2dz_dis_neg_C = new TH2F("pc2dz_dis_neg_C","pc2dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc2dphi_dis_pos_C = new TH2F("pc2dphi_dis_pos_C","pc2dphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc2dphi_dis_neg_C = new TH2F("pc2dphi_dis_neg_C","pc2dphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc2dz_dis_pos_M = new TH2F("pc2dz_dis_pos_M","pc2dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc2dz_dis_neg_M = new TH2F("pc2dz_dis_neg_M","pc2dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc2dphi_dis_pos_M = new TH2F("pc2dphi_dis_pos_M","pc2dphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc2dphi_dis_neg_M = new TH2F("pc2dphi_dis_neg_M","pc2dphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc2dz_dis_pos_P = new TH2F("pc2dz_dis_pos_P","pc2dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc2dz_dis_neg_P = new TH2F("pc2dz_dis_neg_P","pc2dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc2dphi_dis_pos_P = new TH2F("pc2dphi_dis_pos_P","pc2dphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc2dphi_dis_neg_P = new TH2F("pc2dphi_dis_neg_P","pc2dphi vs mom", 100, 0, 10, 100, -5.0, 5.0);

  /*TH2F *pc3dz_dis_pos = new TH2F("pc3dz_dis_pos","pc3dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc3dz_dis_neg = new TH2F("pc3dz_dis_neg","pc3dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc3dphi_dis_pos = new TH2F("pc3dphi_dis_pos","pc3dphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc3dphi_dis_neg = new TH2F("pc3dphi_dis_neg","pc3dphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc3dz_dis_pos_C = new TH2F("pc3dz_dis_pos_C","pc3dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc3dz_dis_neg_C = new TH2F("pc3dz_dis_neg_C","pc3dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc3dphi_dis_pos_C = new TH2F("pc3dphi_dis_pos_C","pc3dphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc3dphi_dis_neg_C = new TH2F("pc3dphi_dis_neg_C","pc3dphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc3dz_dis_pos_M = new TH2F("pc3dz_dis_pos_M","pc3dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc3dz_dis_neg_M = new TH2F("pc3dz_dis_neg_M","pc3dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc3dphi_dis_pos_M = new TH2F("pc3dphi_dis_pos_M","pc3dphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc3dphi_dis_neg_M = new TH2F("pc3dphi_dis_neg_M","pc3dphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc3dz_dis_pos_P = new TH2F("pc3dz_dis_pos_P","pc3dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc3dz_dis_neg_P = new TH2F("pc3dz_dis_neg_P","pc3dz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc3dphi_dis_pos_P = new TH2F("pc3dphi_dis_pos_P","pc3dphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *pc3dphi_dis_neg_P = new TH2F("pc3dphi_dis_neg_P","pc3dphi vs mom", 100, 0, 10, 100, -5.0, 5.0); */


  /*TH2F *tofwdz_dis_pos = new TH2F("tofwdz_dis_pos","tofwdz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *tofwdz_dis_neg = new TH2F("tofwdz_dis_neg","tofwdz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *tofwdphi_dis_pos = new TH2F("tofwdphi_dis_pos","tofwdphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *tofwdphi_dis_neg = new TH2F("tofwdphi_dis_neg","tofwdphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *tofwdz_dis_pos_C = new TH2F("tofwdz_dis_pos_C","tofwdz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *tofwdz_dis_neg_C = new TH2F("tofwdz_dis_neg_C","tofwdz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *tofwdphi_dis_pos_C = new TH2F("tofwdphi_dis_pos_C","tofwdphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *tofwdphi_dis_neg_C = new TH2F("tofwdphi_dis_neg_C","tofwdphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *tofwdz_dis_pos_M = new TH2F("tofwdz_dis_pos_M","tofwdz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *tofwdz_dis_neg_M = new TH2F("tofwdz_dis_neg_M","tofwdz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *tofwdphi_dis_pos_M = new TH2F("tofwdphi_dis_pos_M","tofwdphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *tofwdphi_dis_neg_M = new TH2F("tofwdphi_dis_neg_M","tofwdphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *tofwdz_dis_pos_P = new TH2F("tofwdz_dis_pos_P","tofwdz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *tofwdz_dis_neg_P = new TH2F("tofwdz_dis_neg_P","tofwdz vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *tofwdphi_dis_pos_P = new TH2F("tofwdphi_dis_pos_P","tofwdphi vs mom", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *tofwdphi_dis_neg_P = new TH2F("tofwdphi_dis_neg_P","tofwdphi vs mom", 100, 0, 10, 100, -5.0, 5.0);*/

  // ---



  TH2F *hh_julia_zedpt_before = new TH2F("hh_julia_zedpt_before","zed vs pT before cuts", 100, 0, 10, 180, -90, 90);
  TH2F *hh_julia_zedpt_after = new TH2F("hh_julia_zedpt_after","zed vs pT after cuts", 100, 0, 10, 180, -90, 90);

  // some other stuff
  // 160, 20, 36, - 200, -0.2, 0.2



  // DC fiducial maps both

  // no cuts
  // zed>0
  TH2F *hh_alphaphi_poszed_nc = new TH2F("hh_alphaphi_poszed_nc","alpha vs phi zed>0 no cuts", 920, -0.22, 0.7, 420, -0.21, 0.21);
  TH2F *hh_pos_momphi_poszed_nc = new TH2F("hh_pos_momphi_poszed_nc","mom vs phi zed>0 no cuts", 1300, -0.4, 0.9, 100, 0, 10);
  TH2F *hh_neg_momphi_poszed_nc = new TH2F("hh_neg_momphi_poszed_nc","mom vs phi zed>0 no cuts", 1300, -0.4, 0.9, 100, 0, 10);
  // zed<0
  TH2F *hh_alphaphi_negzed_nc = new TH2F("hh_alphaphi_negzed_nc","alpha vs phi zed<0 no cuts", 920, -0.22, 0.7, 420, -0.21, 0.21);
  TH2F *hh_pos_momphi_negzed_nc = new TH2F("hh_pos_momphi_negzed_nc","mom vs phi zed<0 no cuts", 1300, -0.4, 0.9, 100, 0, 10);
  TH2F *hh_neg_momphi_negzed_nc = new TH2F("hh_neg_momphi_negzed_nc","mom vs phi zed<0 no cuts", 1300, -0.4, 0.9, 100, 0, 10);

  // no cuts
  // zed>0
  TH2F *hh_alphaphi_poszed_mc = new TH2F("hh_alphaphi_poszed_mc","alpha vs phi zed>0 no cuts", 920, -0.22, 0.7, 420, -0.21, 0.21);
  TH2F *hh_pos_momphi_poszed_mc = new TH2F("hh_pos_momphi_poszed_mc","mom vs phi zed>0 no cuts", 1300, -0.4, 0.9, 100, 0, 10);
  TH2F *hh_neg_momphi_poszed_mc = new TH2F("hh_neg_momphi_poszed_mc","mom vs phi zed>0 no cuts", 1300, -0.4, 0.9, 100, 0, 10);
  // zed<0
  TH2F *hh_alphaphi_negzed_mc = new TH2F("hh_alphaphi_negzed_mc","alpha vs phi zed<0 no cuts", 920, -0.22, 0.7, 420, -0.21, 0.21);
  TH2F *hh_pos_momphi_negzed_mc = new TH2F("hh_pos_momphi_negzed_mc","mom vs phi zed<0 no cuts", 1300, -0.4, 0.9, 100, 0, 10);
  TH2F *hh_neg_momphi_negzed_mc = new TH2F("hh_neg_momphi_negzed_mc","mom vs phi zed<0 no cuts", 1300, -0.4, 0.9, 100, 0, 10);

  // all cuts
  // zed>0
  TH2F *hh_alphaphi_poszed_ac = new TH2F("hh_alphaphi_poszed_ac","alpha vs phi zed>0 all cuts", 920, -0.22, 0.7, 420, -0.21, 0.21);
  TH2F *hh_pos_momphi_poszed_ac = new TH2F("hh_pos_momphi_poszed_ac","mom vs phi zed>0 all cuts", 1300, -0.4, 0.9, 100, 0, 10);
  TH2F *hh_neg_momphi_poszed_ac = new TH2F("hh_neg_momphi_poszed_ac","mom vs phi zed>0 all cuts", 1300, -0.4, 0.9, 100, 0, 10);
  // zed<0
  TH2F *hh_alphaphi_negzed_ac = new TH2F("hh_alphaphi_negzed_ac","alpha vs phi zed<0 all cuts", 920, -0.22, 0.7, 420, -0.21, 0.21);
  TH2F *hh_pos_momphi_negzed_ac = new TH2F("hh_pos_momphi_negzed_ac","mom vs phi zed<0 all cuts", 1300, -0.4, 0.9, 100, 0, 10);
  TH2F *hh_neg_momphi_negzed_ac = new TH2F("hh_neg_momphi_negzed_ac","mom vs phi zed<0 all cuts", 1300, -0.4, 0.9, 100, 0, 10);


  TH2F *hh_zedphi_nc = new TH2F("hh_zedphi_nc","phi vs zed no cuts", 160, -80, 80, 1300, -0.4, 0.9);
  TH2F *hh_zedphi_mc = new TH2F("hh_zedphi_mc","phi vs zed matching cuts", 160, -80, 80, 1300, -0.4, 0.9);
  TH2F *hh_zedphi_ac = new TH2F("hh_zedphi_ac","phi vs zed all cuts", 160, -80, 80, 1300, -0.4, 0.9);




  // DC fiducial maps W1

  // no cuts
  // zed>0
  TH2F *hh_alphaphi_poszed_nc1 = new TH2F("hh_alphaphi_poszed_nc1","alpha vs phi zed>0 no cuts", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_momphi_poszed_nc1 = new TH2F("hh_pos_momphi_poszed_nc1","mom vs phi zed>0 no cuts", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_momphi_poszed_nc1 = new TH2F("hh_neg_momphi_poszed_nc1","mom vs phi zed>0 no cuts", 400, -0.2, 0.2, 100, 0, 10);
  // zed<0
  TH2F *hh_alphaphi_negzed_nc1 = new TH2F("hh_alphaphi_negzed_nc1","alpha vs phi zed<0 no cuts", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_momphi_negzed_nc1 = new TH2F("hh_pos_momphi_negzed_nc1","mom vs phi zed<0 no cuts", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_momphi_negzed_nc1 = new TH2F("hh_neg_momphi_negzed_nc1","mom vs phi zed<0 no cuts", 400, -0.2, 0.2, 100, 0, 10);

  // no cuts
  // zed>0
  TH2F *hh_alphaphi_poszed_mc1 = new TH2F("hh_alphaphi_poszed_mc1","alpha vs phi zed>0 no cuts", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_momphi_poszed_mc1 = new TH2F("hh_pos_momphi_poszed_mc1","mom vs phi zed>0 no cuts", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_momphi_poszed_mc1 = new TH2F("hh_neg_momphi_poszed_mc1","mom vs phi zed>0 no cuts", 400, -0.2, 0.2, 100, 0, 10);
  // zed<0
  TH2F *hh_alphaphi_negzed_mc1 = new TH2F("hh_alphaphi_negzed_mc1","alpha vs phi zed<0 no cuts", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_momphi_negzed_mc1 = new TH2F("hh_pos_momphi_negzed_mc1","mom vs phi zed<0 no cuts", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_momphi_negzed_mc1 = new TH2F("hh_neg_momphi_negzed_mc1","mom vs phi zed<0 no cuts", 400, -0.2, 0.2, 100, 0, 10);

  // all cuts
  // zed>0
  TH2F *hh_alphaphi_poszed_ac1 = new TH2F("hh_alphaphi_poszed_ac1","alpha vs phi zed>0 all cuts", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_momphi_poszed_ac1 = new TH2F("hh_pos_momphi_poszed_ac1","mom vs phi zed>0 all cuts", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_momphi_poszed_ac1 = new TH2F("hh_neg_momphi_poszed_ac1","mom vs phi zed>0 all cuts", 400, -0.2, 0.2, 100, 0, 10);
  // zed<0
  TH2F *hh_alphaphi_negzed_ac1 = new TH2F("hh_alphaphi_negzed_ac1","alpha vs phi zed<0 all cuts", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_momphi_negzed_ac1 = new TH2F("hh_pos_momphi_negzed_ac1","mom vs phi zed<0 all cuts", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_momphi_negzed_ac1 = new TH2F("hh_neg_momphi_negzed_ac1","mom vs phi zed<0 all cuts", 400, -0.2, 0.2, 100, 0, 10);



  // DC fiducial maps W2

  // no cuts
  // zed>0
  TH2F *hh_alphaphi_poszed_nc2 = new TH2F("hh_alphaphi_poszed_nc2","alpha vs phi zed>0 no cuts", 400, 0.3, 0.7, 200, -0.1, 0.1);
  TH2F *hh_pos_momphi_poszed_nc2 = new TH2F("hh_pos_momphi_poszed_nc2","mom vs phi zed>0 no cuts", 400, 0.3, 0.7, 100, 0, 10);
  TH2F *hh_neg_momphi_poszed_nc2 = new TH2F("hh_neg_momphi_poszed_nc2","mom vs phi zed>0 no cuts", 400, 0.3, 0.7, 100, 0, 10);
  // zed<0
  TH2F *hh_alphaphi_negzed_nc2 = new TH2F("hh_alphaphi_negzed_nc2","alpha vs phi zed<0 no cuts", 400, 0.3, 0.7, 200, -0.1, 0.1);
  TH2F *hh_pos_momphi_negzed_nc2 = new TH2F("hh_pos_momphi_negzed_nc2","mom vs phi zed<0 no cuts", 400, 0.3, 0.7, 100, 0, 10);
  TH2F *hh_neg_momphi_negzed_nc2 = new TH2F("hh_neg_momphi_negzed_nc2","mom vs phi zed<0 no cuts", 400, 0.3, 0.7, 100, 0, 10);

  // no cuts
  // zed>0
  TH2F *hh_alphaphi_poszed_mc2 = new TH2F("hh_alphaphi_poszed_mc2","alpha vs phi zed>0 no cuts", 400, 0.3, 0.7, 200, -0.1, 0.1);
  TH2F *hh_pos_momphi_poszed_mc2 = new TH2F("hh_pos_momphi_poszed_mc2","mom vs phi zed>0 no cuts", 400, 0.3, 0.7, 100, 0, 10);
  TH2F *hh_neg_momphi_poszed_mc2 = new TH2F("hh_neg_momphi_poszed_mc2","mom vs phi zed>0 no cuts", 400, 0.3, 0.7, 100, 0, 10);
  // zed<0
  TH2F *hh_alphaphi_negzed_mc2 = new TH2F("hh_alphaphi_negzed_mc2","alpha vs phi zed<0 no cuts", 400, 0.3, 0.7, 200, -0.1, 0.1);
  TH2F *hh_pos_momphi_negzed_mc2 = new TH2F("hh_pos_momphi_negzed_mc2","mom vs phi zed<0 no cuts", 400, 0.3, 0.7, 100, 0, 10);
  TH2F *hh_neg_momphi_negzed_mc2 = new TH2F("hh_neg_momphi_negzed_mc2","mom vs phi zed<0 no cuts", 400, 0.3, 0.7, 100, 0, 10);

  // all cuts
  // zed>0
  TH2F *hh_alphaphi_poszed_ac2 = new TH2F("hh_alphaphi_poszed_ac2","alpha vs phi zed>0 all cuts", 400, 0.3, 0.7, 200, -0.1, 0.1);
  TH2F *hh_pos_momphi_poszed_ac2 = new TH2F("hh_pos_momphi_poszed_ac2","mom vs phi zed>0 all cuts", 400, 0.3, 0.7, 100, 0, 10);
  TH2F *hh_neg_momphi_poszed_ac2 = new TH2F("hh_neg_momphi_poszed_ac2","mom vs phi zed>0 all cuts", 400, 0.3, 0.7, 100, 0, 10);
  // zed<0
  TH2F *hh_alphaphi_negzed_ac2 = new TH2F("hh_alphaphi_negzed_ac2","alpha vs phi zed<0 all cuts", 400, 0.3, 0.7, 200, -0.1, 0.1);
  TH2F *hh_pos_momphi_negzed_ac2 = new TH2F("hh_pos_momphi_negzed_ac2","mom vs phi zed<0 all cuts", 400, 0.3, 0.7, 100, 0, 10);
  TH2F *hh_neg_momphi_negzed_ac2 = new TH2F("hh_neg_momphi_negzed_ac2","mom vs phi zed<0 all cuts", 400, 0.3, 0.7, 100, 0, 10);



  //Pad Chamber Fiducial Cut Histograms
  TH2F *PC1ZedPhiDis  = new TH2F("PC1ZedPhiDis", "PC1 phi vs zed w/o FC", 400, -200, 200, 500, -0.3, 0.7);
  TH2F *PC1ZedPhiNewDis  = new TH2F("PC1ZedPhiNewDis", "PC1 phi vs zed w/ FC", 400, -200, 200, 500, -0.3, 0.7);
  TH2F *PC2ZedPhiDis  = new TH2F("PC2ZedPhiDis", "PC2 phi vs zed w/o FC", 400, -200, 200, 500, -0.3, 0.7);
  TH2F *PC2ZedPhiNewDis  = new TH2F("PC2ZedPhiNewDis", "PC2 phi vs zed w/ FC",400, -200, 200, 500, -0.3, 0.7);
  TH2F *PC3ZedPhiDis  = new TH2F("PC3ZedPhiDis", "PC3 phi vs zed w/o FC", 400, -200, 200, 500, -0.3, 0.7);
  TH2F *PC3ZedPhiNewDis  = new TH2F("PC3ZedPhiNewDis", "PC3 phi vs zed w/ FC", 400, -200, 200, 500, -0.3, 0.7);

  TH2F *TOFWZedPhiDis  = new TH2F("TOFWZedPhiDis", "TOFW phi vs zed w/o FC", 400, -200, 200, 500, -0.3, 0.7);
  TH2F *TOFWZedPhiNewDis  = new TH2F("TOFWZedPhiNewDis", "TOFW phi vs zed w/ FC", 400, -200, 200, 500, -0.3, 0.7);
  TH2F *TOFWZedPhiNewNewDis  = new TH2F("TOFWZedPhiNewNewDis", "TOFW phi vs zed w/ all FC", 400, -200, 200, 500, -0.3, 0.7);



  TH2F *adc_strip_before = new TH2F("adc_strip_before","ADC in TOFW vs strip", 512, 0, 511, 1000, 0, 1000);
  TH2F *adc_beta_before = new TH2F("adc_beta_before","ADC vs beta", 600, 0, 1.2, 400, 0, 800);

  TH2F *adc_strip_after = new TH2F("adc_strip_after","ADC in TOFW vs strip", 512, 0, 511, 1000, 0, 1000);
  TH2F *adc_beta_after = new TH2F("adc_beta_after","ADC vs beta", 600, 0, 1.2, 400, 0, 800);


  // being pid histograms


  // end pid histograms

  // being pid histograms

  TH1F *ptpid_tofw_w1_pos_0_dis = new TH1F("ptpid_tofw_w1_pos_0_dis", "tofw w1 0 pos pion sigma #in [-2,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_pos_1_dis = new TH1F("ptpid_tofw_w1_pos_1_dis", "tofw w1 1 pos pion sigma #in [-2,0]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_pos_2_dis = new TH1F("ptpid_tofw_w1_pos_2_dis", "tofw w1 2 pos pion sigma #in [-2,2] && !K", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_pos_3_dis = new TH1F("ptpid_tofw_w1_pos_3_dis", "tofw w1 3 pos pion sigma #in [-2,0] && !K", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_pos_4_dis = new TH1F("ptpid_tofw_w1_pos_4_dis", "tofw w1 4 pos kaon sigma #in [-2,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_pos_5_dis = new TH1F("ptpid_tofw_w1_pos_5_dis", "tofw w1 5 pos kaon sigma #in [-2,2] && !#pi && !p", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_pos_6_dis = new TH1F("ptpid_tofw_w1_pos_6_dis", "tofw w1 6 pos proton sigma #in [-2,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_pos_7_dis = new TH1F("ptpid_tofw_w1_pos_7_dis", "tofw w1 7 pos proton sigma #in [0,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_pos_8_dis = new TH1F("ptpid_tofw_w1_pos_8_dis", "tofw w1 8 pos proton sigma #in [-2,2] && !K", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_pos_9_dis = new TH1F("ptpid_tofw_w1_pos_9_dis", "tofw w1 9 pos proton sigma #in [0,2] && !K", 80, 0, 8.0);

  TH1F *ptpid_tofw_w1_neg_0_dis = new TH1F("ptpid_tofw_w1_neg_0_dis", "tofw w1 0 neg pion sigma #in [-2,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_neg_1_dis = new TH1F("ptpid_tofw_w1_neg_1_dis", "tofw w1 1 neg pion sigma #in [-2,0]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_neg_2_dis = new TH1F("ptpid_tofw_w1_neg_2_dis", "tofw w1 2 neg pion sigma #in [-2,2] && !K", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_neg_3_dis = new TH1F("ptpid_tofw_w1_neg_3_dis", "tofw w1 3 neg pion sigma #in [-2,0] && !K", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_neg_4_dis = new TH1F("ptpid_tofw_w1_neg_4_dis", "tofw w1 4 neg kaon sigma #in [-2,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_neg_5_dis = new TH1F("ptpid_tofw_w1_neg_5_dis", "tofw w1 5 neg kaon sigma #in [-2,2] && !#pi && !p", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_neg_6_dis = new TH1F("ptpid_tofw_w1_neg_6_dis", "tofw w1 6 neg proton sigma #in [-2,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_neg_7_dis = new TH1F("ptpid_tofw_w1_neg_7_dis", "tofw w1 7 neg proton sigma #in [0,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_neg_8_dis = new TH1F("ptpid_tofw_w1_neg_8_dis", "tofw w1 8 neg proton sigma #in [-2,2] && !K", 80, 0, 8.0);
  TH1F *ptpid_tofw_w1_neg_9_dis = new TH1F("ptpid_tofw_w1_neg_9_dis", "tofw w1 9 neg proton sigma #in [0,2] && !K", 80, 0, 8.0);

  TH1F *ptpid_tofw_w2_pos_0_dis = new TH1F("ptpid_tofw_w2_pos_0_dis", "tofw w2 0 pos pion sigma #in [-2,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_pos_1_dis = new TH1F("ptpid_tofw_w2_pos_1_dis", "tofw w2 1 pos pion sigma #in [-2,0]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_pos_2_dis = new TH1F("ptpid_tofw_w2_pos_2_dis", "tofw w2 2 pos pion sigma #in [-2,2] && !K", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_pos_3_dis = new TH1F("ptpid_tofw_w2_pos_3_dis", "tofw w2 3 pos pion sigma #in [-2,0] && !K", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_pos_4_dis = new TH1F("ptpid_tofw_w2_pos_4_dis", "tofw w2 4 pos kaon sigma #in [-2,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_pos_5_dis = new TH1F("ptpid_tofw_w2_pos_5_dis", "tofw w2 5 pos kaon sigma #in [-2,2] && !#pi && !p", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_pos_6_dis = new TH1F("ptpid_tofw_w2_pos_6_dis", "tofw w2 6 pos proton sigma #in [-2,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_pos_7_dis = new TH1F("ptpid_tofw_w2_pos_7_dis", "tofw w2 7 pos proton sigma #in [0,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_pos_8_dis = new TH1F("ptpid_tofw_w2_pos_8_dis", "tofw w2 8 pos proton sigma #in [-2,2] && !K", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_pos_9_dis = new TH1F("ptpid_tofw_w2_pos_9_dis", "tofw w2 9 pos proton sigma #in [0,2] && !K", 80, 0, 8.0);

  TH1F *ptpid_tofw_w2_neg_0_dis = new TH1F("ptpid_tofw_w2_neg_0_dis", "tofw w2 0 neg pion sigma #in [-2,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_neg_1_dis = new TH1F("ptpid_tofw_w2_neg_1_dis", "tofw w2 1 neg pion sigma #in [-2,0]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_neg_2_dis = new TH1F("ptpid_tofw_w2_neg_2_dis", "tofw w2 2 neg pion sigma #in [-2,2] && !K", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_neg_3_dis = new TH1F("ptpid_tofw_w2_neg_3_dis", "tofw w2 3 neg pion sigma #in [-2,0] && !K", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_neg_4_dis = new TH1F("ptpid_tofw_w2_neg_4_dis", "tofw w2 4 neg kaon sigma #in [-2,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_neg_5_dis = new TH1F("ptpid_tofw_w2_neg_5_dis", "tofw w2 5 neg kaon sigma #in [-2,2] && !#pi && !p", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_neg_6_dis = new TH1F("ptpid_tofw_w2_neg_6_dis", "tofw w2 6 neg proton sigma #in [-2,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_neg_7_dis = new TH1F("ptpid_tofw_w2_neg_7_dis", "tofw w2 7 neg proton sigma #in [0,2]", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_neg_8_dis = new TH1F("ptpid_tofw_w2_neg_8_dis", "tofw w2 8 neg proton sigma #in [-2,2] && !K", 80, 0, 8.0);
  TH1F *ptpid_tofw_w2_neg_9_dis = new TH1F("ptpid_tofw_w2_neg_9_dis", "tofw w2 9 neg proton sigma #in [0,2] && !K", 80, 0, 8.0);


  // ------------------------ //
  // --- Histogram Arrays --- //
  // ------------------------ //



  // --- tofw w1 --- //

  TH1F *ptpid_tofw_w1_pos_0_dis_cent[10];
  TH1F *ptpid_tofw_w1_pos_1_dis_cent[10];
  TH1F *ptpid_tofw_w1_pos_2_dis_cent[10];
  TH1F *ptpid_tofw_w1_pos_3_dis_cent[10];
  TH1F *ptpid_tofw_w1_pos_4_dis_cent[10];
  TH1F *ptpid_tofw_w1_pos_5_dis_cent[10];
  TH1F *ptpid_tofw_w1_pos_6_dis_cent[10];
  TH1F *ptpid_tofw_w1_pos_7_dis_cent[10];
  TH1F *ptpid_tofw_w1_pos_8_dis_cent[10];
  TH1F *ptpid_tofw_w1_pos_9_dis_cent[10];

  TH1F *ptpid_tofw_w1_neg_0_dis_cent[10];
  TH1F *ptpid_tofw_w1_neg_1_dis_cent[10];
  TH1F *ptpid_tofw_w1_neg_2_dis_cent[10];
  TH1F *ptpid_tofw_w1_neg_3_dis_cent[10];
  TH1F *ptpid_tofw_w1_neg_4_dis_cent[10];
  TH1F *ptpid_tofw_w1_neg_5_dis_cent[10];
  TH1F *ptpid_tofw_w1_neg_6_dis_cent[10];
  TH1F *ptpid_tofw_w1_neg_7_dis_cent[10];
  TH1F *ptpid_tofw_w1_neg_8_dis_cent[10];
  TH1F *ptpid_tofw_w1_neg_9_dis_cent[10];

  char name_ptpid_tofw_w1_pos_0_dis_cent[30];
  char name_ptpid_tofw_w1_pos_1_dis_cent[30];
  char name_ptpid_tofw_w1_pos_2_dis_cent[30];
  char name_ptpid_tofw_w1_pos_3_dis_cent[30];
  char name_ptpid_tofw_w1_pos_4_dis_cent[30];
  char name_ptpid_tofw_w1_pos_5_dis_cent[30];
  char name_ptpid_tofw_w1_pos_6_dis_cent[30];
  char name_ptpid_tofw_w1_pos_7_dis_cent[30];
  char name_ptpid_tofw_w1_pos_8_dis_cent[30];
  char name_ptpid_tofw_w1_pos_9_dis_cent[30];

  char name_ptpid_tofw_w1_neg_0_dis_cent[30];
  char name_ptpid_tofw_w1_neg_1_dis_cent[30];
  char name_ptpid_tofw_w1_neg_2_dis_cent[30];
  char name_ptpid_tofw_w1_neg_3_dis_cent[30];
  char name_ptpid_tofw_w1_neg_4_dis_cent[30];
  char name_ptpid_tofw_w1_neg_5_dis_cent[30];
  char name_ptpid_tofw_w1_neg_6_dis_cent[30];
  char name_ptpid_tofw_w1_neg_7_dis_cent[30];
  char name_ptpid_tofw_w1_neg_8_dis_cent[30];
  char name_ptpid_tofw_w1_neg_9_dis_cent[30];

  for(int i=0; i<9; i++)
    {
      sprintf(name_ptpid_tofw_w1_pos_0_dis_cent,"ptpid_tofw_w1_pos_0_dis_cent_%d",i);
      ptpid_tofw_w1_pos_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_0_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_pos_1_dis_cent,"ptpid_tofw_w1_pos_1_dis_cent_%d",i);
      ptpid_tofw_w1_pos_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_1_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_pos_2_dis_cent,"ptpid_tofw_w1_pos_2_dis_cent_%d",i);
      ptpid_tofw_w1_pos_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_2_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_pos_3_dis_cent,"ptpid_tofw_w1_pos_3_dis_cent_%d",i);
      ptpid_tofw_w1_pos_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_3_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_pos_4_dis_cent,"ptpid_tofw_w1_pos_4_dis_cent_%d",i);
      ptpid_tofw_w1_pos_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_4_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_pos_5_dis_cent,"ptpid_tofw_w1_pos_5_dis_cent_%d",i);
      ptpid_tofw_w1_pos_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_5_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_pos_6_dis_cent,"ptpid_tofw_w1_pos_6_dis_cent_%d",i);
      ptpid_tofw_w1_pos_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_6_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_pos_7_dis_cent,"ptpid_tofw_w1_pos_7_dis_cent_%d",i);
      ptpid_tofw_w1_pos_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_7_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_pos_8_dis_cent,"ptpid_tofw_w1_pos_8_dis_cent_%d",i);
      ptpid_tofw_w1_pos_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_8_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_pos_9_dis_cent,"ptpid_tofw_w1_pos_9_dis_cent_%d",i);
      ptpid_tofw_w1_pos_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_9_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_neg_0_dis_cent,"ptpid_tofw_w1_neg_0_dis_cent_%d",i);
      ptpid_tofw_w1_neg_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_0_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_neg_1_dis_cent,"ptpid_tofw_w1_neg_1_dis_cent_%d",i);
      ptpid_tofw_w1_neg_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_1_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_neg_2_dis_cent,"ptpid_tofw_w1_neg_2_dis_cent_%d",i);
      ptpid_tofw_w1_neg_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_2_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_neg_3_dis_cent,"ptpid_tofw_w1_neg_3_dis_cent_%d",i);
      ptpid_tofw_w1_neg_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_3_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_neg_4_dis_cent,"ptpid_tofw_w1_neg_4_dis_cent_%d",i);
      ptpid_tofw_w1_neg_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_4_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_neg_5_dis_cent,"ptpid_tofw_w1_neg_5_dis_cent_%d",i);
      ptpid_tofw_w1_neg_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_5_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_neg_6_dis_cent,"ptpid_tofw_w1_neg_6_dis_cent_%d",i);
      ptpid_tofw_w1_neg_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_6_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_neg_7_dis_cent,"ptpid_tofw_w1_neg_7_dis_cent_%d",i);
      ptpid_tofw_w1_neg_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_7_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_neg_8_dis_cent,"ptpid_tofw_w1_neg_8_dis_cent_%d",i);
      ptpid_tofw_w1_neg_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_8_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w1_neg_9_dis_cent,"ptpid_tofw_w1_neg_9_dis_cent_%d",i);
      ptpid_tofw_w1_neg_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_9_dis_cent, "...", 80, 0, 8.0);
    }

  // --- tofw w2 --- //

  TH1F *ptpid_tofw_w2_pos_0_dis_cent[10];
  TH1F *ptpid_tofw_w2_pos_1_dis_cent[10];
  TH1F *ptpid_tofw_w2_pos_2_dis_cent[10];
  TH1F *ptpid_tofw_w2_pos_3_dis_cent[10];
  TH1F *ptpid_tofw_w2_pos_4_dis_cent[10];
  TH1F *ptpid_tofw_w2_pos_5_dis_cent[10];
  TH1F *ptpid_tofw_w2_pos_6_dis_cent[10];
  TH1F *ptpid_tofw_w2_pos_7_dis_cent[10];
  TH1F *ptpid_tofw_w2_pos_8_dis_cent[10];
  TH1F *ptpid_tofw_w2_pos_9_dis_cent[10];

  TH1F *ptpid_tofw_w2_neg_0_dis_cent[10];
  TH1F *ptpid_tofw_w2_neg_1_dis_cent[10];
  TH1F *ptpid_tofw_w2_neg_2_dis_cent[10];
  TH1F *ptpid_tofw_w2_neg_3_dis_cent[10];
  TH1F *ptpid_tofw_w2_neg_4_dis_cent[10];
  TH1F *ptpid_tofw_w2_neg_5_dis_cent[10];
  TH1F *ptpid_tofw_w2_neg_6_dis_cent[10];
  TH1F *ptpid_tofw_w2_neg_7_dis_cent[10];
  TH1F *ptpid_tofw_w2_neg_8_dis_cent[10];
  TH1F *ptpid_tofw_w2_neg_9_dis_cent[10];

  char name_ptpid_tofw_w2_pos_0_dis_cent[30];
  char name_ptpid_tofw_w2_pos_1_dis_cent[30];
  char name_ptpid_tofw_w2_pos_2_dis_cent[30];
  char name_ptpid_tofw_w2_pos_3_dis_cent[30];
  char name_ptpid_tofw_w2_pos_4_dis_cent[30];
  char name_ptpid_tofw_w2_pos_5_dis_cent[30];
  char name_ptpid_tofw_w2_pos_6_dis_cent[30];
  char name_ptpid_tofw_w2_pos_7_dis_cent[30];
  char name_ptpid_tofw_w2_pos_8_dis_cent[30];
  char name_ptpid_tofw_w2_pos_9_dis_cent[30];

  char name_ptpid_tofw_w2_neg_0_dis_cent[30];
  char name_ptpid_tofw_w2_neg_1_dis_cent[30];
  char name_ptpid_tofw_w2_neg_2_dis_cent[30];
  char name_ptpid_tofw_w2_neg_3_dis_cent[30];
  char name_ptpid_tofw_w2_neg_4_dis_cent[30];
  char name_ptpid_tofw_w2_neg_5_dis_cent[30];
  char name_ptpid_tofw_w2_neg_6_dis_cent[30];
  char name_ptpid_tofw_w2_neg_7_dis_cent[30];
  char name_ptpid_tofw_w2_neg_8_dis_cent[30];
  char name_ptpid_tofw_w2_neg_9_dis_cent[30];

  for(int i=0; i<9; i++)
    {
      sprintf(name_ptpid_tofw_w2_pos_0_dis_cent,"ptpid_tofw_w2_pos_0_dis_cent_%d",i);
      ptpid_tofw_w2_pos_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_0_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_pos_1_dis_cent,"ptpid_tofw_w2_pos_1_dis_cent_%d",i);
      ptpid_tofw_w2_pos_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_1_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_pos_2_dis_cent,"ptpid_tofw_w2_pos_2_dis_cent_%d",i);
      ptpid_tofw_w2_pos_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_2_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_pos_3_dis_cent,"ptpid_tofw_w2_pos_3_dis_cent_%d",i);
      ptpid_tofw_w2_pos_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_3_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_pos_4_dis_cent,"ptpid_tofw_w2_pos_4_dis_cent_%d",i);
      ptpid_tofw_w2_pos_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_4_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_pos_5_dis_cent,"ptpid_tofw_w2_pos_5_dis_cent_%d",i);
      ptpid_tofw_w2_pos_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_5_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_pos_6_dis_cent,"ptpid_tofw_w2_pos_6_dis_cent_%d",i);
      ptpid_tofw_w2_pos_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_6_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_pos_7_dis_cent,"ptpid_tofw_w2_pos_7_dis_cent_%d",i);
      ptpid_tofw_w2_pos_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_7_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_pos_8_dis_cent,"ptpid_tofw_w2_pos_8_dis_cent_%d",i);
      ptpid_tofw_w2_pos_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_8_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_pos_9_dis_cent,"ptpid_tofw_w2_pos_9_dis_cent_%d",i);
      ptpid_tofw_w2_pos_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_9_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_neg_0_dis_cent,"ptpid_tofw_w2_neg_0_dis_cent_%d",i);
      ptpid_tofw_w2_neg_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_0_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_neg_1_dis_cent,"ptpid_tofw_w2_neg_1_dis_cent_%d",i);
      ptpid_tofw_w2_neg_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_1_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_neg_2_dis_cent,"ptpid_tofw_w2_neg_2_dis_cent_%d",i);
      ptpid_tofw_w2_neg_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_2_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_neg_3_dis_cent,"ptpid_tofw_w2_neg_3_dis_cent_%d",i);
      ptpid_tofw_w2_neg_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_3_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_neg_4_dis_cent,"ptpid_tofw_w2_neg_4_dis_cent_%d",i);
      ptpid_tofw_w2_neg_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_4_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_neg_5_dis_cent,"ptpid_tofw_w2_neg_5_dis_cent_%d",i);
      ptpid_tofw_w2_neg_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_5_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_neg_6_dis_cent,"ptpid_tofw_w2_neg_6_dis_cent_%d",i);
      ptpid_tofw_w2_neg_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_6_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_neg_7_dis_cent,"ptpid_tofw_w2_neg_7_dis_cent_%d",i);
      ptpid_tofw_w2_neg_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_7_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_neg_8_dis_cent,"ptpid_tofw_w2_neg_8_dis_cent_%d",i);
      ptpid_tofw_w2_neg_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_8_dis_cent, "...", 80, 0, 8.0);
      sprintf(name_ptpid_tofw_w2_neg_9_dis_cent,"ptpid_tofw_w2_neg_9_dis_cent_%d",i);
      ptpid_tofw_w2_neg_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_9_dis_cent, "...", 80, 0, 8.0);
    }

  // end pid histograms


  // --- Done with Histograms ---------------------

  //Now read in the pDSTs listed in the input files
  int ifile=0; 
  char filename[100];
  ifstream fin(inFile);
  if(!inFile)
    {
      cout<<"list input error: file does not exist "<<endl;
      exit(0);
    }
  while(fin.getline(filename,100))
    {

      ifile++; 
      cout<<ifile<<" "<<filename<<endl;

      TFile *f = TFile::Open(filename);
      if(!f)
	{
	  cout<<"pDST input error: file does not exist "<<endl;
	  continue;
	  //exit(0);
	}

      nevents += (Long64_t)((TH1F *)f->Get("hcent"))->GetEntries();

      TTree *t=(TTree *)f->Get("hadrontree");   
      if(!t)
	{
	  cout<<"pDST input error: cannot find tree "<<endl;
	  continue; 
	  //exit(0); 
	}

      int n=(int)t->GetEntries(); // number of events in tree
      hadrontree *ktree = new hadrontree(t); // pointer to tree
      for(int i=0;i<n;i++) // loop over events
	{

	  //reset to 0 for every event
	  ngoodtofwtracks_snglevent = 0;
	  
	  ktree->GetEntry(i); 

	  int run = ktree->run;
	  if(run==228171) continue; // no toffset for now
	  if(run<229000) fetchRunOffsetFromFile(run);
	  else runoffset = 0.0;
	  //if(runoffset==-9999) continue; // best general way to check, but don't need right now

	  stringstream ss;
	  ss<<run;
	  int runindex = myMap[ss.str()]; 

	  //if(run<229000) continue;

	  //input files are now selected by field config
	  //if(run>235810) continue; // +- only
	  //if(run<236133) continue; // -+ only

	  //these cuts are already in the pDSTs
	  //float bbcz = ktree->bbcz;
	  //if(fabs(bbcz)>30) continue;
	  float cent = ktree->cent;
	  //if(cent<0||cent>=100) continue;

	  //if(cent<40) continue; // temp for test

	  int icent=-1;
	  if (cent>0 && cent<=10)        icent=0;
	  else if (cent>10 && cent<=20)  icent=1;
	  else if (cent>20 && cent<=30)  icent=2;
	  else if (cent>30 && cent<=40)  icent=3;
	  else if (cent>40 && cent<=50)  icent=4;
	  else if (cent>50 && cent<=60)  icent=5;
	  else if (cent>60 && cent<=70)  icent=6;
	  else if (cent>70 && cent<=80)  icent=7;
	  else if (cent>80 && cent<=99)  icent=8;

	  //int ecent=-1;
	  //if (cent>0 && cent<=5)         ecent=0;
	  //else if (cent>5 && cent<=10)   ecent=1;
	  //else if (cent>10 && cent<=15)  ecent=2;
	  //else if (cent>15 && cent<=20)  ecent=3;
	  //else if (cent>20 && cent<=30)  ecent=4;
	  //else if (cent>30 && cent<=40)  ecent=5;
	  //else if (cent>40 && cent<=50)  ecent=6;
	  //else if (cent>50 && cent<=60)  ecent=7;
	  //else if (cent>60 && cent<=70)  ecent=8;
	  //else if (cent>70 && cent<=80)  ecent=9;
	  //else if (cent>80 && cent<=94)  ecent=10;
	  //else if (cent>90 && cent<=99)  ecent=11;
	  //else                           ecent=12;

	  for(int itrk=0; itrk<ktree->mNtrack; itrk++)
	    {
	      
	      ntracks++; // count total number of tracks
	      
	      // in the pDSTs, not needed
	      //int dcarm = ktree->HadronTracks_dcarm[itrk];
	      //if(dcarm==0) continue;

	      // --- TOFW, pre

	      float mom = ktree->HadronTracks_mom[itrk];
	      float pT = ktree->HadronTracks_pt[itrk];
	      int striptofw = (int)ktree->HadronTracks_striptofw[itrk];
	      // how much difference does it make?
	      /*if(striptofw<256)
		{
		  mom = 0.9957*mom;
		  pT = 0.9957*pT;
		  }*/
	      //if(pT<0.4) continue; // not looking at anything below
	      if(!goodStrip(striptofw)) continue;
	      int strip = striptofw;
	      //if(strip<0||strip>63) continue; // W1 south bot (box 0, lower half)
	      //if(strip<64||strip>127) continue; // W1 south top (box 0, upper half)
	      //if(strip<128||strip>191) continue; // W1 north bot (box 1, lower half)
	      //if(strip<192||strip>255) continue; // W1 north top (box 1, upper half)

	      // --- DC
	      
	      int quality = ktree->HadronTracks_quality[itrk];
	      float zed   = ktree->HadronTracks_zed[itrk];
	      float phi   = ktree->HadronTracks_phi[itrk];
	      float alpha = ktree->HadronTracks_alpha[itrk];
	      int charge  = ktree->HadronTracks_charge[itrk];
	      //float board = ((0.573231+phi-0.0046*cos(phi+0.05721))/0.01963496); // not currently using

	      float pc2sdz      = ktree->HadronTracks_pc2sdz[itrk];
	      float pc2sdphi    = ktree->HadronTracks_pc2sdphi[itrk];
	      pc2sdz = retunepc2sdz(cent,charge,pc2sdz,run);
	      pc2sdphi = retunepc2sdphi(cent,charge,pc2sdphi,run);
	      bool pc2_matching = fabs(pc2sdphi)<2.0 && fabs(pc2sdz)<2.0;
	      float pc3sdz      = ktree->HadronTracks_pc3sdz[itrk];
	      float pc3sdphi    = ktree->HadronTracks_pc3sdphi[itrk];
	      //pc3sdz = retunepc3sdz(mom,charge,pc3sdz,run);
	      //pc3sdphi = retunepc3sdphi(mom,charge,pc3sdphi,run);
	      bool pc3_matching = fabs(pc3sdphi)<2.0 && fabs(pc3sdz)<2.0;
	      float tofwsdz     = ktree->HadronTracks_tofwsdz[itrk];
	      float tofwsdphi   = ktree->HadronTracks_tofwsdphi[itrk];
	      //tofwsdz = retunetofwsdz(mom,charge,tofwsdz,run);
	      //tofwsdphi = retunetofwsdphi(mom,charge,tofwsdphi,run);
	      bool tfw_matching = fabs(tofwsdphi)<2.0 && fabs(tofwsdz)<2.0;

	      // pos
	      if(charge>0)
		{
		  if(fabs(pc2sdphi)<2.0)  pc2dz_cent_dis_pos->Fill(cent,pc2sdz);
		  if(fabs(pc2sdz)<2.0)    pc2dphi_cent_dis_pos->Fill(cent,pc2sdphi);
		  if(fabs(pc2sdphi)<2.0)  pc2dz_dis_pos->Fill(pT,pc2sdz);
		  if(fabs(pc2sdz)<2.0)    pc2dphi_dis_pos->Fill(pT,pc2sdphi);
		  //if(fabs(pc3sdphi)<2.0)  pc3dz_dis_pos->Fill(pT,pc3sdz);
		  //if(fabs(pc3sdz)<2.0)    pc3dphi_dis_pos->Fill(pT,pc3sdphi);
		  //if(fabs(tofwsdphi)<2.0) tofwdz_dis_pos->Fill(pT,tofwsdz);
		  //if(fabs(tofwsdz)<2.0)   tofwdphi_dis_pos->Fill(pT,tofwsdphi);
		}
	      // neg
	      if(charge<0)
		{
		  if(fabs(pc2sdphi)<2.0)  pc2dz_cent_dis_neg->Fill(cent,pc2sdz);
		  if(fabs(pc2sdz)<2.0)    pc2dphi_cent_dis_neg->Fill(cent,pc2sdphi);
		  if(fabs(pc2sdphi)<2.0)  pc2dz_dis_neg->Fill(pT,pc2sdz);
		  if(fabs(pc2sdz)<2.0)    pc2dphi_dis_neg->Fill(pT,pc2sdphi);
		  //if(fabs(pc3sdphi)<2.0)  pc3dz_dis_neg->Fill(pT,pc3sdz);
		  //if(fabs(pc3sdz)<2.0)    pc3dphi_dis_neg->Fill(pT,pc3sdphi);
		  //if(fabs(tofwsdphi)<2.0) tofwdz_dis_neg->Fill(pT,tofwsdz);
		  //if(fabs(tofwsdz)<2.0)   tofwdphi_dis_neg->Fill(pT,tofwsdphi);
		}
	      if(cent<=10)
		{
		  // pos
		  if(charge>0)
		    {
		      if(fabs(pc2sdphi)<2.0)  pc2dz_dis_pos_C->Fill(pT,pc2sdz);
		      if(fabs(pc2sdz)<2.0)    pc2dphi_dis_pos_C->Fill(pT,pc2sdphi);
		      //if(fabs(pc3sdphi)<2.0)  pc3dz_dis_pos_C->Fill(pT,pc3sdz);
		      //if(fabs(pc3sdz)<2.0)    pc3dphi_dis_pos_C->Fill(pT,pc3sdphi);
		      //if(fabs(tofwsdphi)<2.0) tofwdz_dis_pos_C->Fill(pT,tofwsdz);
		      //if(fabs(tofwsdz)<2.0)   tofwdphi_dis_pos_C->Fill(pT,tofwsdphi);
		    }
		  // neg
		  if(charge<0)
		    {
		      if(fabs(pc2sdphi)<2.0)  pc2dz_dis_neg_C->Fill(pT,pc2sdz);
		      if(fabs(pc2sdz)<2.0)    pc2dphi_dis_neg_C->Fill(pT,pc2sdphi);
		      //if(fabs(pc3sdphi)<2.0)  pc3dz_dis_neg_C->Fill(pT,pc3sdz);
		      //if(fabs(pc3sdz)<2.0)    pc3dphi_dis_neg_C->Fill(pT,pc3sdphi);
		      //if(fabs(tofwsdphi)<2.0) tofwdz_dis_neg_C->Fill(pT,tofwsdz);
		      //if(fabs(tofwsdz)<2.0)   tofwdphi_dis_neg_C->Fill(pT,tofwsdphi);
		    }
		}
	      if(cent>=30&&cent<=50)
		{
		  // pos
		  if(charge>0)
		    {
		      if(fabs(pc2sdphi)<2.0)  pc2dz_dis_pos_M->Fill(pT,pc2sdz);
		      if(fabs(pc2sdz)<2.0)    pc2dphi_dis_pos_M->Fill(pT,pc2sdphi);
		      //if(fabs(pc3sdphi)<2.0)  pc3dz_dis_pos_M->Fill(pT,pc3sdz);
		      //if(fabs(pc3sdz)<2.0)    pc3dphi_dis_pos_M->Fill(pT,pc3sdphi);
		      //if(fabs(tofwsdphi)<2.0) tofwdz_dis_pos_M->Fill(pT,tofwsdz);
		      //if(fabs(tofwsdz)<2.0)   tofwdphi_dis_pos_M->Fill(pT,tofwsdphi);
		    }
		  // neg
		  if(charge<0)
		    {
		      if(fabs(pc2sdphi)<2.0)  pc2dz_dis_neg_M->Fill(pT,pc2sdz);
		      if(fabs(pc2sdz)<2.0)    pc2dphi_dis_neg_M->Fill(pT,pc2sdphi);
		      //if(fabs(pc3sdphi)<2.0)  pc3dz_dis_neg_M->Fill(pT,pc3sdz);
		      //if(fabs(pc3sdz)<2.0)    pc3dphi_dis_neg_M->Fill(pT,pc3sdphi);
		      //if(fabs(tofwsdphi)<2.0) tofwdz_dis_neg_M->Fill(pT,tofwsdz);
		      //if(fabs(tofwsdz)<2.0)   tofwdphi_dis_neg_M->Fill(pT,tofwsdphi);
		    }
		}
	      if(cent>=60)
		{
		  // pos
		  if(charge>0)
		    {
		      if(fabs(pc2sdphi)<2.0)  pc2dz_dis_pos_P->Fill(pT,pc2sdz);
		      if(fabs(pc2sdz)<2.0)    pc2dphi_dis_pos_P->Fill(pT,pc2sdphi);
		      //if(fabs(pc3sdphi)<2.0)  pc3dz_dis_pos_P->Fill(pT,pc3sdz);
		      //if(fabs(pc3sdz)<2.0)    pc3dphi_dis_pos_P->Fill(pT,pc3sdphi);
		      //if(fabs(tofwsdphi)<2.0) tofwdz_dis_pos_P->Fill(pT,tofwsdz);
		      //if(fabs(tofwsdz)<2.0)   tofwdphi_dis_pos_P->Fill(pT,tofwsdphi);
		    }
		  // neg
		  if(charge<0)
		    {
		      if(fabs(pc2sdphi)<2.0)  pc2dz_dis_neg_P->Fill(pT,pc2sdz);
		      if(fabs(pc2sdz)<2.0)    pc2dphi_dis_neg_P->Fill(pT,pc2sdphi);
		      //if(fabs(pc3sdphi)<2.0)  pc3dz_dis_neg_P->Fill(pT,pc3sdz);
		      //if(fabs(pc3sdz)<2.0)    pc3dphi_dis_neg_P->Fill(pT,pc3sdphi);
		      //if(fabs(tofwsdphi)<2.0) tofwdz_dis_neg_P->Fill(pT,tofwsdz);
		      //if(fabs(tofwsdz)<2.0)   tofwdphi_dis_neg_P->Fill(pT,tofwsdphi);
		    }
		}

	      // ----------------------- //
	      // --- test histograms --- //
	      // ----------------------- //

	      //if(zed>0) hh_momphi_poszed_1->Fill(phi,charge*mom);
	      //if(zed<0) hh_momphi_negzed_1->Fill(phi,charge*mom);

	      hh_zedphi_nc->Fill(zed,phi);

	      if(zed>0)
		{
		  hh_alphaphi_poszed_nc->Fill(phi,alpha);
		  hh_alphaphi_poszed_nc1->Fill(phi,alpha);
		  hh_alphaphi_poszed_nc2->Fill(phi,alpha);
		  if(charge>0) hh_pos_momphi_poszed_nc->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_poszed_nc->Fill(phi,mom);
		  if(charge>0) hh_pos_momphi_poszed_nc1->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_poszed_nc1->Fill(phi,mom);
		  if(charge>0) hh_pos_momphi_poszed_nc2->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_poszed_nc2->Fill(phi,mom);
		}
	      if(zed<0)
		{
		  hh_alphaphi_negzed_nc->Fill(phi,alpha);
		  hh_alphaphi_negzed_nc1->Fill(phi,alpha);
		  hh_alphaphi_negzed_nc2->Fill(phi,alpha);
		  if(charge>0) hh_pos_momphi_negzed_nc->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_negzed_nc->Fill(phi,mom);
		  if(charge>0) hh_pos_momphi_negzed_nc1->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_negzed_nc1->Fill(phi,mom);
		  if(charge>0) hh_pos_momphi_negzed_nc2->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_negzed_nc2->Fill(phi,mom);
		}

	      // ----------------------- //
	      // ----------------------- //
	      // ----------------------- //

	      // --- some DC cuts

	      bool good_dc = (fabs(zed)<70&&fabs(zed)>3&&(quality==63||quality==31));
	      //bool good_dc = (fabs(zed)<70&&fabs(zed)>3&&quality>=29); // TEST!!!
	      if(!good_dc) continue;
	      
	      
	      // --- PC1

	      float ppc1x     = ktree->HadronTracks_ppc1x[itrk];
	      float ppc1y     = ktree->HadronTracks_ppc1y[itrk];
	      float ppc1z     = ktree->HadronTracks_ppc1z[itrk];
	      float pc1z = ppc1z;
	      float pc1phi = atan2(ppc1y,ppc1x);  
	      
	      PC1ZedPhiDis->Fill(pc1z,pc1phi);
	      bool good_pc1 = GoodPC1(pc1z,pc1phi);
	      //if(!good_pc1) continue;
	      if(good_pc1) PC1ZedPhiNewDis->Fill(pc1z,pc1phi);

	      float ppc2x     = ktree->HadronTracks_ppc2x[itrk];
	      float ppc2y     = ktree->HadronTracks_ppc2y[itrk];
	      float ppc2z     = ktree->HadronTracks_ppc2z[itrk];
	      float pc2dz     = ktree->HadronTracks_pc2dz[itrk];
	      float pc2dphi   = ktree->HadronTracks_pc2dphi[itrk];
	      float pc2z      = ppc2z -pc2dz;
	      float pc2phi    = atan2(ppc2y,ppc2x) - pc2dphi;
	      
	      if(pc2_matching) PC2ZedPhiDis->Fill(pc2z,pc2phi);
	      //bool good_pc2 = GoodPC2(pc2z,pc2phi)&&pc2_matching;
	      bool good_pc2 = GoodPC2(pc2z,pc2phi);//&&pc2_matching;
	      //if(!good_pc2) continue;
	      //PC2ZedPhiNewDis->Fill(pc2z,pc2phi);
	      if(good_pc2) PC2ZedPhiNewDis->Fill(pc2z,pc2phi);
	      
	      
	      float ppc3x     = ktree->HadronTracks_ppc3x[itrk];
	      float ppc3y     = ktree->HadronTracks_ppc3y[itrk];
	      float ppc3z     = ktree->HadronTracks_ppc3z[itrk];
	      float pc3dz     = ktree->HadronTracks_pc3dz[itrk];
	      float pc3dphi   = ktree->HadronTracks_pc3dphi[itrk];
	      float pc3z      = ppc3z - pc3dz;
	      float pc3phi    = atan2(ppc3y,ppc3x) - pc3dphi;
	      
	      if(pc3_matching) PC3ZedPhiDis->Fill(pc3z,pc3phi);
	      //bool good_pc3 = GoodPC3(pc3z,pc3phi)&&pc3_matching;
	      bool good_pc3 = GoodPC3(pc3z,pc3phi);//&&pc3_matching;
	      //if(!good_pc3) continue;
	      if(good_pc3) PC3ZedPhiNewDis->Fill(pc3z,pc3phi);

	      // --- TOFW

	      float ptofwx     = ktree->HadronTracks_ptofwx[itrk];
	      float ptofwy     = ktree->HadronTracks_ptofwy[itrk];
	      float ptofwz     = ktree->HadronTracks_ptofwz[itrk];
	      float tofwdz     = ktree->HadronTracks_tofwdz[itrk];
	      float tofwdphi   = ktree->HadronTracks_tofwdphi[itrk];
	      float tofwz      = ptofwz - tofwdz;
	      float tofwphi    = atan2(ptofwy,ptofwx) - tofwdphi;
	      
	      TOFWZedPhiDis->Fill(tofwz,tofwphi);
	      bool tofwedge = (fabs(tofwz)<175&&fabs(tofwz)>4) && 
		((tofwphi>-0.1&&tofwphi<0.06)||(tofwphi>0.41&&tofwphi<0.58));
	      //if(!tofwedge||!tfw_matching) continue;
	      if(tfw_matching) TOFWZedPhiNewDis->Fill(tofwz,tofwphi);



	      hcount_no->Fill(mom);
	      if(tfw_matching) hcount_tfwm->Fill(mom);
	      if(pc3_matching) hcount_pc3m->Fill(mom);
	      if(pc2_matching) hcount_pc2m->Fill(mom);
	      if(good_pc1) hcount_pc1f->Fill(mom);
	      if(good_pc2) hcount_pc2f->Fill(mom);
	      if(good_pc3) hcount_pc3f->Fill(mom);

	      //if(!tfw_matching||!pc3_matching) continue;
	      if(!tfw_matching||!pc3_matching||!pc2_matching) continue;

	      hcount_match->Fill(mom);
	      
	      //if(!good_pc1||!good_pc3) continue;
	      if(!good_pc1||!good_pc2||!good_pc3) continue;



	      // --- TOFW, final
	      
	      float pltofw = ktree->HadronTracks_pltofw[itrk];
	      float ttofw = ktree->HadronTracks_ttofw[itrk];
	      ttofw = ttofw - runoffset;
	      float qtofw = ktree->HadronTracks_qtofw[itrk];
	      float beta = pltofw/ttofw/phbeta;
	      adc_beta_before->Fill(beta,qtofw);
	      adc_strip_before->Fill(striptofw,qtofw);

	      if(mom>1.1&&mom<1.5&&cent>60) qtofwdis_B->Fill(qtofw);
	      //continue;
	      //if(qtofw<60||qtofw>600) continue; // old cut
	      //if(qtofw<(20*((float)pow(beta,(float)-2.7)))||qtofw>600) continue;
	      bool good_adc (qtofw>(20*((float)pow(beta,(float)-2.7)))&&qtofw<600);
	      if(!good_adc) continue;



	      // ----------------------- //
	      // --- test histograms --- //
	      // ----------------------- //

	      if(zed>0)
		{
		  hh_alphaphi_poszed_mc->Fill(phi,alpha);
		  hh_alphaphi_poszed_mc1->Fill(phi,alpha);
		  hh_alphaphi_poszed_mc2->Fill(phi,alpha);
		  if(charge>0) hh_pos_momphi_poszed_mc->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_poszed_mc->Fill(phi,mom);
		  if(charge>0) hh_pos_momphi_poszed_mc1->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_poszed_mc1->Fill(phi,mom);
		  if(charge>0) hh_pos_momphi_poszed_mc2->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_poszed_mc2->Fill(phi,mom);
		}
	      if(zed<0)
		{
		  hh_alphaphi_negzed_mc->Fill(phi,alpha);
		  hh_alphaphi_negzed_mc1->Fill(phi,alpha);
		  hh_alphaphi_negzed_mc2->Fill(phi,alpha);
		  if(charge>0) hh_pos_momphi_negzed_mc->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_negzed_mc->Fill(phi,mom);
		  if(charge>0) hh_pos_momphi_negzed_mc1->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_negzed_mc1->Fill(phi,mom);
		  if(charge>0) hh_pos_momphi_negzed_mc2->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_negzed_mc2->Fill(phi,mom);
		}

	      // ----------------------- //
	      // ----------------------- //
	      // ----------------------- //


	      //if(!DCHFiducial(run,alpha,zed,board)) continue;
	      if(!GoodDCH(run,zed,alpha,phi)) continue;
	      //if(pT<0.4) continue; // not looking at anything below // because why not
	      //if(pT>=1.0 && !GoodHiDCH(run,zed,alpha,phi)) continue;
	      //if(pT< 1.0 && !GoodLoDCH(run,zed,alpha,phi)) continue;
	      
	      // ----------------------- //
	      // --- test histograms --- //
	      // ----------------------- //


	      if(zed>0&&pT>0.4)
		{
		  hh_alphaphi_poszed_ac->Fill(phi,alpha);
		  hh_alphaphi_poszed_ac1->Fill(phi,alpha);
		  hh_alphaphi_poszed_ac2->Fill(phi,alpha);
		  if(charge>0) hh_pos_momphi_poszed_ac->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_poszed_ac->Fill(phi,mom);
		  if(charge>0) hh_pos_momphi_poszed_ac1->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_poszed_ac1->Fill(phi,mom);
		  if(charge>0) hh_pos_momphi_poszed_ac2->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_poszed_ac2->Fill(phi,mom);
		}
	      if(zed<0&&pT>0.4)
		{
		  hh_alphaphi_negzed_ac->Fill(phi,alpha);
		  hh_alphaphi_negzed_ac1->Fill(phi,alpha);
		  hh_alphaphi_negzed_ac2->Fill(phi,alpha);
		  if(charge>0) hh_pos_momphi_negzed_ac->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_negzed_ac->Fill(phi,mom);
		  if(charge>0) hh_pos_momphi_negzed_ac1->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_negzed_ac1->Fill(phi,mom);
		  if(charge>0) hh_pos_momphi_negzed_ac2->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_negzed_ac2->Fill(phi,mom);
		}


	      // --- PID

	      //float m2tofw      = ktree->HadronTracks_m2tofw[itrk];
	      float m2tofw = mom*mom*(ttofw*ttofw*phbeta*phbeta/(pltofw*pltofw)-1);
	      float deltat_pion = ttofw - pltofw/phbeta*sqrt(mpion*mpion/mom/mom+1);
	      float deltat_kaon = ttofw - pltofw/phbeta*sqrt(mkaon*mkaon/mom/mom+1);
	      float deltat_proton = ttofw - pltofw/phbeta*sqrt(mproton*mproton/mom/mom+1);
	      //float isPiNew = isPionNew(pT,m2tofw);
	      float isPiNew = isPionLow(pT,m2tofw); // test run
	      float isKNew  = isKaonNew(pT,m2tofw);
	      float isPNew  = isProtonNew(pT,m2tofw);
	      bool isPi = (isPiNew>=-2&&isPiNew<=2);
	      bool isK = (isKNew>=-2&&isKNew<=2);
	      bool isP = (isPNew>=-2&&isPNew<=2);

	      if(charge>0) m2centdis_pos->Fill(cent,m2tofw);
	      if(charge<0) m2centdis_neg->Fill(cent,m2tofw);
	      if(mom>1.0&&mom<1.1&&charge>0) m2centdis_1_pos->Fill(cent,m2tofw);
	      if(mom>1.0&&mom<1.1&&charge<0) m2centdis_1_neg->Fill(cent,m2tofw);
	      if(mom>2.0&&mom<2.1&&charge>0) m2centdis_2_pos->Fill(cent,m2tofw);
	      if(mom>2.0&&mom<2.1&&charge<0) m2centdis_2_neg->Fill(cent,m2tofw);
	      if(mom>3.0&&mom<3.1&&charge>0) m2centdis_3_pos->Fill(cent,m2tofw);
	      if(mom>3.0&&mom<3.1&&charge<0) m2centdis_3_neg->Fill(cent,m2tofw);

	      if(charge>0) m2momdis_pos->Fill(mom,m2tofw);
	      if(charge<0) m2momdis_neg->Fill(mom,m2tofw);
	      if(striptofw<256&&charge>0) m2momdis_pos_w1->Fill(mom,m2tofw);
	      if(striptofw<256&&charge<0) m2momdis_neg_w1->Fill(mom,m2tofw);
	      if(striptofw>255&&charge>0) m2momdis_pos_w2->Fill(mom,m2tofw);
	      if(striptofw>255&&charge<0) m2momdis_neg_w2->Fill(mom,m2tofw);

	      if(charge>0) m2stripdis_pos->Fill(striptofw,m2tofw);
	      if(charge<0) m2stripdis_neg->Fill(striptofw,m2tofw);
	      if(charge>0) m2rundis_pos->Fill(runindex,m2tofw);
	      if(charge<0) m2rundis_neg->Fill(runindex,m2tofw);
	      if(charge>0) DeltaTrundis_pos->Fill(runindex,deltat_pion);
	      if(charge<0) DeltaTrundis_neg->Fill(runindex,deltat_pion);
	      if(charge>0) isPi_dis_pos->Fill(mom,isPiNew);
	      if(charge<0) isPi_dis_neg->Fill(mom,isPiNew);
	      if(charge>0) isK_dis_pos->Fill(mom,isKNew);
	      if(charge<0) isK_dis_neg->Fill(mom,isKNew);
	      if(charge>0) isP_dis_pos->Fill(mom,isPNew);
	      if(charge<0) isP_dis_neg->Fill(mom,isPNew);
	      if(charge>0) DeltaTPi_dis_pos->Fill(mom,deltat_pion);
	      if(charge<0) DeltaTPi_dis_neg->Fill(mom,deltat_pion);
	      if(charge>0) DeltaTK_dis_pos->Fill(mom,deltat_kaon);
	      if(charge<0) DeltaTK_dis_neg->Fill(mom,deltat_kaon);
	      if(charge>0) DeltaTP_dis_pos->Fill(mom,deltat_proton);
	      if(charge<0) DeltaTP_dis_neg->Fill(mom,deltat_proton);
	      


	      // --- EMC && RICH

	      float emcsdz      = ktree->HadronTracks_emcsdz[itrk];
	      float emcsdphi    = ktree->HadronTracks_emcsdphi[itrk];
	      bool emc_matching = fabs(emcsdphi)<2.0 && fabs(emcsdz)<2.0;
	      float ecore = ktree->HadronTracks_ecore[itrk];
	      //float ecent = ktree->HadronTracks_ecent[itrk];
	      float ep = ecore/mom;
	      //float n0 = ktree->HadronTracks_n0[itrk];


	      // ----------------------- //
	      // ----------------------- //
	      // ----------------------- //


	      ngoodtofwtracks++;
	      ngoodtofwtracks_snglevent++;

	      // ----------------- //
	      // --- tofw only --- //
	      // ----------------- //

	      //hh_julia_zedpt_before->Fill(pT,zed);
	      //if(ep<0.1) continue; // ep study
	      //if(!tfw_matching||!pc3_matching) continue;
	      //if(!tfw_matching||!pc3_matching||!pc2_matching) continue;
	      //hh_julia_zedpt_after->Fill(pT,zed);
	      // ---------------------------- //


	      if(striptofw>=0&&striptofw<=255)
		{
		  if(charge>0)
		    {
		      if(isPiNew>=-2.0&&isPiNew<=2.0)
			{
			  ptpid_tofw_w1_pos_0_dis->Fill(pT);
			  ptpid_tofw_w1_pos_0_dis_cent[icent]->Fill(pT);
			}
		      if(isPiNew>=-2.0&&isPiNew<=0.0)
			{
			  ptpid_tofw_w1_pos_1_dis->Fill(pT);
			  ptpid_tofw_w1_pos_1_dis_cent[icent]->Fill(pT);
			}
		      if(isPiNew>=-2.0&&isPiNew<=2.0&&!isK)
			{
			  ptpid_tofw_w1_pos_2_dis->Fill(pT);
			  ptpid_tofw_w1_pos_2_dis_cent[icent]->Fill(pT);
			}
		      if(isPiNew>=-2.0&&isPiNew<=0.0&&!isK)
			{
			  ptpid_tofw_w1_pos_3_dis->Fill(pT);
			  ptpid_tofw_w1_pos_3_dis_cent[icent]->Fill(pT);
			}
		      if(isKNew>=-2.0&&isKNew<=2.0)
			{
			  ptpid_tofw_w1_pos_4_dis->Fill(pT);
			  ptpid_tofw_w1_pos_4_dis_cent[icent]->Fill(pT);
			}
		      if(isKNew>=-2.0&&isKNew<=2.0&&!isPi&&!isP)
			{
			  ptpid_tofw_w1_pos_5_dis->Fill(pT);
			  ptpid_tofw_w1_pos_5_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=-2.0&&isPNew<=2.0)
			{
			  ptpid_tofw_w1_pos_6_dis->Fill(pT);
			  ptpid_tofw_w1_pos_6_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=0.0&&isPNew<=2.0)
			{
			  ptpid_tofw_w1_pos_7_dis->Fill(pT);
			  ptpid_tofw_w1_pos_7_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=-2.0&&isPNew<=2.0&&!isK)
			{
			  ptpid_tofw_w1_pos_8_dis->Fill(pT);
			  ptpid_tofw_w1_pos_8_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=0.0&&isPNew<=2.0&&!isK)
			{
			  ptpid_tofw_w1_pos_9_dis->Fill(pT);
			  ptpid_tofw_w1_pos_9_dis_cent[icent]->Fill(pT);
			}
		    } // end pos
		  if(charge<0)
		    {
		      if(isPiNew>=-2.0&&isPiNew<=2.0)
			{
			  ptpid_tofw_w1_neg_0_dis->Fill(pT);
			  ptpid_tofw_w1_neg_0_dis_cent[icent]->Fill(pT);
			}
		      if(isPiNew>=-2.0&&isPiNew<=0.0)
			{
			  ptpid_tofw_w1_neg_1_dis->Fill(pT);
			  ptpid_tofw_w1_neg_1_dis_cent[icent]->Fill(pT);
			}
		      if(isPiNew>=-2.0&&isPiNew<=2.0&&!isK)
			{
			  ptpid_tofw_w1_neg_2_dis->Fill(pT);
			  ptpid_tofw_w1_neg_2_dis_cent[icent]->Fill(pT);
			}
		      if(isPiNew>=-2.0&&isPiNew<=0.0&&!isK)
			{
			  ptpid_tofw_w1_neg_3_dis->Fill(pT);
			  ptpid_tofw_w1_neg_3_dis_cent[icent]->Fill(pT);
			}
		      if(isKNew>=-2.0&&isKNew<=2.0)
			{
			  ptpid_tofw_w1_neg_4_dis->Fill(pT);
			  ptpid_tofw_w1_neg_4_dis_cent[icent]->Fill(pT);
			}
		      if(isKNew>=-2.0&&isKNew<=2.0&&!isPi&&!isP)
			{
			  ptpid_tofw_w1_neg_5_dis->Fill(pT);
			  ptpid_tofw_w1_neg_5_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=-2.0&&isPNew<=2.0)
			{
			  ptpid_tofw_w1_neg_6_dis->Fill(pT);
			  ptpid_tofw_w1_neg_6_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=0.0&&isPNew<=2.0)
			{
			  ptpid_tofw_w1_neg_7_dis->Fill(pT);
			  ptpid_tofw_w1_neg_7_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=-2.0&&isPNew<=2.0&&!isK)
			{
			  ptpid_tofw_w1_neg_8_dis->Fill(pT);
			  ptpid_tofw_w1_neg_8_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=0.0&&isPNew<=2.0&&!isK)
			{
			  ptpid_tofw_w1_neg_9_dis->Fill(pT);
			  ptpid_tofw_w1_neg_9_dis_cent[icent]->Fill(pT);
			}
		    } // end neg
		} // end w1
	      if(striptofw>=256&&striptofw<=511)
		{
		  if(charge>0)
		    {
		      if(isPiNew>=-2.0&&isPiNew<=2.0)
			{
			  ptpid_tofw_w2_pos_0_dis->Fill(pT);
			  ptpid_tofw_w2_pos_0_dis_cent[icent]->Fill(pT);
			}
		      if(isPiNew>=-2.0&&isPiNew<=0.0)
			{
			  ptpid_tofw_w2_pos_1_dis->Fill(pT);
			  ptpid_tofw_w2_pos_1_dis_cent[icent]->Fill(pT);
			}
		      if(isPiNew>=-2.0&&isPiNew<=2.0&&!isK)
			{
			  ptpid_tofw_w2_pos_2_dis->Fill(pT);
			  ptpid_tofw_w2_pos_2_dis_cent[icent]->Fill(pT);
			}
		      if(isPiNew>=-2.0&&isPiNew<=0.0&&!isK)
			{
			  ptpid_tofw_w2_pos_3_dis->Fill(pT);
			  ptpid_tofw_w2_pos_3_dis_cent[icent]->Fill(pT);
			}
		      if(isKNew>=-2.0&&isKNew<=2.0)
			{
			  ptpid_tofw_w2_pos_4_dis->Fill(pT);
			  ptpid_tofw_w2_pos_4_dis_cent[icent]->Fill(pT);
			}
		      if(isKNew>=-2.0&&isKNew<=2.0&&!isPi&&!isP)
			{
			  ptpid_tofw_w2_pos_5_dis->Fill(pT);
			  ptpid_tofw_w2_pos_5_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=-2.0&&isPNew<=2.0)
			{
			  ptpid_tofw_w2_pos_6_dis->Fill(pT);
			  ptpid_tofw_w2_pos_6_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=0.0&&isPNew<=2.0)
			{
			  ptpid_tofw_w2_pos_7_dis->Fill(pT);
			  ptpid_tofw_w2_pos_7_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=-2.0&&isPNew<=2.0&&!isK)
			{
			  ptpid_tofw_w2_pos_8_dis->Fill(pT);
			  ptpid_tofw_w2_pos_8_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=0.0&&isPNew<=2.0&&!isK)
			{
			  ptpid_tofw_w2_pos_9_dis->Fill(pT);
			  ptpid_tofw_w2_pos_9_dis_cent[icent]->Fill(pT);
			}
		    } // end pos
		  if(charge<0)
		    {
		      if(isPiNew>=-2.0&&isPiNew<=2.0)
			{
			  ptpid_tofw_w2_neg_0_dis->Fill(pT);
			  ptpid_tofw_w2_neg_0_dis_cent[icent]->Fill(pT);
			}
		      if(isPiNew>=-2.0&&isPiNew<=0.0)
			{
			  ptpid_tofw_w2_neg_1_dis->Fill(pT);
			  ptpid_tofw_w2_neg_1_dis_cent[icent]->Fill(pT);
			}
		      if(isPiNew>=-2.0&&isPiNew<=2.0&&!isK)
			{
			  ptpid_tofw_w2_neg_2_dis->Fill(pT);
			  ptpid_tofw_w2_neg_2_dis_cent[icent]->Fill(pT);
			}
		      if(isPiNew>=-2.0&&isPiNew<=0.0&&!isK)
			{
			  ptpid_tofw_w2_neg_3_dis->Fill(pT);
			  ptpid_tofw_w2_neg_3_dis_cent[icent]->Fill(pT);
			}
		      if(isKNew>=-2.0&&isKNew<=2.0)
			{
			  ptpid_tofw_w2_neg_4_dis->Fill(pT);
			  ptpid_tofw_w2_neg_4_dis_cent[icent]->Fill(pT);
			}
		      if(isKNew>=-2.0&&isKNew<=2.0&&!isPi&&!isP)
			{
			  ptpid_tofw_w2_neg_5_dis->Fill(pT);
			  ptpid_tofw_w2_neg_5_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=-2.0&&isPNew<=2.0)
			{
			  ptpid_tofw_w2_neg_6_dis->Fill(pT);
			  ptpid_tofw_w2_neg_6_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=0.0&&isPNew<=2.0)
			{
			  ptpid_tofw_w2_neg_7_dis->Fill(pT);
			  ptpid_tofw_w2_neg_7_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=-2.0&&isPNew<=2.0&&!isK)
			{
			  ptpid_tofw_w2_neg_8_dis->Fill(pT);
			  ptpid_tofw_w2_neg_8_dis_cent[icent]->Fill(pT);
			}
		      if(isPNew>=0.0&&isPNew<=2.0&&!isK)
			{
			  ptpid_tofw_w2_neg_9_dis->Fill(pT);
			  ptpid_tofw_w2_neg_9_dis_cent[icent]->Fill(pT);
			}
		    } // end neg
		} // end w2



	      // ---------------------------- //	      
	      
	      // ---------------------------- //
	      // --- end of tofw only pid --- //
	      // ---------------------------- //
	      
	      if(isPi||isK||isP) ntofwPIDtracks++;
	      //else continue;
	      
	      // ---------------------------- //
	      // --- Done with track loop --- //
	      // ---------------------------- //
	      
	    } // End of track loop
	  
	  // only count as good event if at least one track is used
	  if(ngoodtofwtracks_snglevent>0) ngoodtofwevents++;
	  
	} // End of event loop
      
      t->Delete();
      delete ktree;
      f->Close();
      delete f;
      
    } // End of pDST loop
  
  //TFile *mData=new TFile(outFile,"recreate"); // move to top
  //mData->cd(); don't use
  mData->Write();  
  mData->Close();
  
  cout<<"Number of events: "<<nevents<<endl;
  cout<<"Number of good TOFW events: "<<ngoodtofwevents<<endl;
  cout<<"Number of tracks: "<<ntracks<<endl;
  cout<<"Number of good TOFW tracks: "<<ngoodtofwtracks<<endl;
  cout<<"Number of TOFW PID tracks: "<<ntofwPIDtracks<<endl;
  
  gettimeofday(&Time,0);
  int endtime = Time.tv_sec;
  //cout<<"endtime is "<<endtime<<endl;
  
  int tdiff = endtime-begintime;
  
  cout<<"End of program."<<endl;
  cout<<"Execution time: "<<tdiff<<" seconds"<<endl;
  
  exit(0); 
  
} 

bool goodStrip(int i)
{
  if((i>=0 &&i<= 7)||
     (i>=12&&i<=15)||
     (i>=20&&i<=23)||
     (i>=28&&i<=31)||
     (i>=36&&i<=40)||
     (i>=44&&i<=47)||
     (i>=52&&i<=55)||
     (i>=60&&i<=63)||
     i==19||i==161||i==372||i==394||i==460)// ||//dead strip
    //i==176||i==288||i==308||i==316||i==320||i==360) 
    return false;//need reproduction
  else return true;
}



bool isPion(float x, float m2tofw)
{
  
  if(x<0.4||x>8.0) return false;
  
  float  p0   =        1.03401e-02;
  float  p1   =       -1.76120e-02;
  float  p2   =        2.91334e-03;
  float  p3   =        6.48013e-02;
  float  p4   =       -1.60995e-01;
  
  float mean = mpion*mpion;
  float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
  
  float n_sigma = (m2tofw - mean)/sigma/1.1;
  if(n_sigma<=0&&n_sigma>-2) return true;
  return false;
  
}



bool isKaon(float x, float m2tofw)
{
  
  if(x<0.4||x>8.0) return false;
  
  float  p0   =        1.75872e-02;  
  float  p1   =       -2.08889e-02;
  float  p2   =        4.16566e-03;
  float  p3   =        6.34606e-02; 
  float  p4   =       -1.58898e-01; 
  
  float mean = mkaon*mkaon;
  float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
  
  float n_sigma = fabs(m2tofw - mean)/sigma/1.1;
  if(n_sigma<2.0) return true;
  return false;
  
}



bool isProton(float x, float m2tofw)
{
  
  if(x<0.4||x>8.0) return false;
  
  float  p0    =      -6.19317e-03;  
  float  p1    =       9.01921e-03;
  float  p2    =       6.82347e-04;
  float  p3    =       6.07866e-02;
  float  p4    =      -1.32903e-01;
  
  float mean = mproton*mproton;
  float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
  
  float n_sigma = (m2tofw - mean)/sigma/1.1;
  if(n_sigma<2.0&&n_sigma>0.0) return true;
  return false;
  
}

// ---
// --- new float pid functions
// ---

float isPionNew(float x, float m2tofw)
{
  
  //if(x<0.4||x>8.0) return false; // doh!
  
  float  p0   =        1.03401e-02;
  float  p1   =       -1.76120e-02;
  float  p2   =        2.91334e-03;
  float  p3   =        6.48013e-02;
  float  p4   =       -1.60995e-01;
  
  float mean = mpion*mpion;
  float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
  
  float n_sigma = (m2tofw - mean)/sigma/1.1;
  return n_sigma;
  
}



float isKaonNew(float x, float m2tofw)
{
  
  //if(x<0.4||x>8.0) return false; // doh!
  
  float  p0   =        1.75872e-02;  
  float  p1   =       -2.08889e-02;
  float  p2   =        4.16566e-03;
  float  p3   =        6.34606e-02; 
  float  p4   =       -1.58898e-01; 

  float mean = mkaon*mkaon;
  float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);

  float n_sigma = (m2tofw - mean)/sigma/1.1;
  return n_sigma;

}



float isProtonNew(float x, float m2tofw)
{

  //if(x<0.4||x>8.0) return false;

  float  p0    =      -6.19317e-03;  
  float  p1    =       9.01921e-03;
  float  p2    =       6.82347e-04;
  float  p3    =       6.07866e-02;
  float  p4    =      -1.32903e-01;

  float mean = mproton*mproton;
  float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);

  float n_sigma = (m2tofw - mean)/sigma/1.1;
  return n_sigma;

}


float isPionLow(float x, float m2tofw)
{

  //float x = mom;

  float a0 = 0.0123786;
  float a1 = 0.00293974;
  float a2 = -0.000321866;
  float a3 = -0.0110238;
  float a4 = 0.0352101;
  float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);

  float b0 = -0.0446002;
  float b1 = 0.00734916;
  float b2 = -0.000878836;
  float b3 = 0.0355148;
  float b4 = -0.0462926;
  float sigma = b0+b1/x+b2/x/x+b3*exp(sqrt(x))+b4*sqrt(x);

  return (m2tofw - mean)/sigma;

}




// bool GoldenAcc(float ppc2x, float ppc2y, float ppc2z, float ppc3x, float ppc3y, float ppc3z, int accbox, float cut)
// {
//   // Factors of linear interpolation between PC2 and PC3.
//   float cy1 = (ppc3y - ppc2y)/(ppc3x - ppc2x);
//   float cy2 = (ppc3x*ppc2y - ppc2x*ppc3y)/(ppc3x - ppc2x);
//   float cz1 = (ppc3z - ppc2z)/(ppc3x - ppc2x);
//   float cz2 = (ppc3x*ppc2z - ppc2x*ppc3z)/(ppc3x - ppc2x);

//   // Projection point on middle plane in X-direction.
//   float ay = cy1 * ACC_X_MIDDLE + cy2;
//   float az = cz1 * ACC_X_MIDDLE + cz2;

//   // Edge of Aerogel Volume
//   float rACC_Y_TOP,rACC_Y_BTM,rACC_Z_NORTH,rACC_Z_SOUTH;

//   if(az > ACC_Z_MIDDLE) // for North Panel
//     {
//       rACC_Y_TOP   = ACC_Y_TOP_N;
//       rACC_Y_BTM   = ACC_Y_BTM_N;
//       rACC_Z_NORTH = ACC_Z_NORTH_N;
//       rACC_Z_SOUTH = ACC_Z_SOUTH_N - ACC_Z_HALFSECTOR;
//     } 
//   else // for South Panel
//     {
//       rACC_Y_TOP   = ACC_Y_TOP_S;
//       rACC_Y_BTM   = ACC_Y_BTM_S;
//       rACC_Z_NORTH = ACC_Z_NORTH_S + ACC_Z_HALFSECTOR;
//       rACC_Z_SOUTH = ACC_Z_SOUTH_S;
//     }
  
//   // HitID
//   //int hitid;
//   if(ay < rACC_Y_BTM || ay > rACC_Y_TOP || az < rACC_Z_SOUTH || az > rACC_Z_NORTH){ // OverRange
//     return false;
//   }
//   else{ // Aerogel Acceptance

//     float hity = ay - rACC_Y_BTM;
//     float hitz = az - rACC_Z_SOUTH;

//     int ny = ACC_NROW - 1 - accbox%10;
//     int nz = ACC_NCLM - 1 - accbox/10;

//     float ycenter = ACC_Y_CELL * (ny+0.5);
//     float zcenter = ACC_Z_CELL * (nz+0.5);

//     if(fabs(hity - ycenter)<ACC_Y_HALFCELL-cut &&
//        fabs(hitz - zcenter)<ACC_Z_HALFCELL-cut) {
//       return true;
//     }
//   }
  
//   return false;
// }


bool GoodDCH(int run, float zed, float alpha, float phi)
{

  float slope = 1.72; // 1.72 is latest and greatest, Monday 10/25/1010
  float sline = 25.0;
  float slire = 8.1;

  //if(zed>0) return false; // look at south only
  //if(zed<0) return false; // look at north only
  if(alpha<slope*phi-slope*-0.021 && alpha>slope*phi-slope*0.200 && alpha > 0.00) return false; // pos alpha, w1, worst section

  //return true; // temp testing

  if(zed>0)
    {
      // === W1 === //
      if(alpha<slope*phi-slope*-0.200 && alpha>slope*phi-slope*-0.103) return false; // w1 below box
      if(alpha<slope*phi-slope*-0.021 && alpha>slope*phi-slope*-0.014) return false; // w1 center of box
      if(alpha<slope*phi-slope*0.060  && alpha>slope*phi-slope*0.200) return false; // w1 above box

      if(alpha<slire*phi-slire*0.006 && alpha>slire*phi-slire*0.009) return false; // w1 wire, only one

      // straight
      //if(alpha<slope*phi-slope*-0.021 && phi<-0.083) return false; // NEW
      //if(alpha>slope*phi-slope*-0.014 && phi>0.064) return false; // NEW

      //if(alpha>slope*phi-slope*-0.014 && phi>0.047 && phi<0.054) return false; // NEW // removing corner cuts now

      //if(phi>-0.223&&phi<-0.184) return false; // NEW // removing corner cuts now
      if(phi>-0.105&&phi<-0.089) return false; // widened
      //if(phi>-0.058&&phi<-0.052) return false;
      //if(phi>-0.039&&phi<-0.032) return false;
      //if(phi>-0.021&&phi<-0.013) return false;
      //if(phi>0.020&&phi<0.026) return false;
      //if(phi>0.145&&phi<0.200) return false; // new

      // === W2 === //
      if(alpha<slope*phi-slope*0.300 && alpha>slope*phi-slope*0.415) return false; // w2 below box
      if(alpha<slope*phi-slope*0.494 && alpha>slope*phi-slope*0.501) return false; // w2 center of box
      if(alpha<slope*phi-slope*0.577 && alpha>slope*phi-slope*0.700) return false; // w2 above box

      if(alpha<slire*phi-slire*0.397 && alpha>slire*phi-slire*0.400) return false; // w2 wire, low
      if(alpha<slire*phi-slire*0.543 && alpha>slire*phi-slire*0.547) return false; // w2 wire, middle
      if(alpha<slire*phi-slire*0.593 && alpha>slire*phi-slire*0.596) return false; // w2 wire, high

      if(alpha>slope*phi-slope*0.501&&phi>0.428&&phi<0.438) return false; // 2 // widened // above
      if(alpha>slope*phi-slope*0.501&&phi>0.469&&phi<0.475) return false; // 3 above
      if(alpha>slope*phi-slope*0.501&&phi>0.516&&phi<0.524) return false; // new // north only
      if(alpha<slope*phi-slope*0.494&&phi>0.382&&phi<0.428) return false; // new below
      if(alpha<slope*phi-slope*0.494&&phi>0.526&&phi<0.533) return false; // 6 below
      //if(phi>0.635&&phi<0.700) return false; // cut the corner // no more corner cutting...
    }
  if(zed<0)
    {
      // === W1 === //
      //if(alpha < 7.14*phi-7.14*-0.186 && alpha < -16.00*phi+16.00*-0.190 && alpha < 0) return false; // low, south only
      if(alpha < 7.14*phi-7.14*-0.105 && alpha < -16.00*phi+16.00*-0.095 && alpha < 0) return false; // low, south only

      if(alpha<slope*phi-slope*-0.200 && alpha>slope*phi-slope*-0.105) return false; // w1 below box
      if(alpha<slope*phi-slope*-0.021 && alpha>slope*phi-slope*-0.014) return false; // w1 center of box
      if(alpha<slope*phi-slope*0.060  && alpha>slope*phi-slope*0.200) return false; // w1 above box

      if(alpha<slire*phi-slire*0.006 && alpha>slire*phi-slire*0.009) return false; // w1 wire, only one

      //if(alpha<slope*phi-slope*-0.021 && phi<-0.083) return false; // NEW
      //if(alpha>slope*phi-slope*-0.014 && phi>0.044) return false; // NEW

      // straight
      //if(phi>-0.225&&phi<-0.200) return false; // not present in north
      if(phi>-0.118&&phi<-0.089) return false; // wider than poszed // widened
      //if(phi>-0.058&&phi<-0.052) return false;
      //if(phi>-0.039&&phi<-0.032) return false; // not needed in south
      //if(phi>-0.021&&phi<-0.013) return false;
      //if(phi>0.020&&phi<0.026) return false;
      //if(phi>0.145&&phi<0.200) return false; // new

      // === W2 === //
      if(alpha<slope*phi-slope*0.300 && alpha>slope*phi-slope*0.415) return false; // w2 below box
      if(alpha<slope*phi-slope*0.494 && alpha>slope*phi-slope*0.501) return false; // w2 center of box
      if(alpha<slope*phi-slope*0.577 && alpha>slope*phi-slope*0.700) return false; // w2 above box

      if(alpha<slire*phi-slire*0.397 && alpha>slire*phi-slire*0.400) return false; // w2 wire, low
      if(alpha<slire*phi-slire*0.543 && alpha>slire*phi-slire*0.547) return false; // w2 wire, middle
      if(alpha<slire*phi-slire*0.593 && alpha>slire*phi-slire*0.596) return false; // w2 wire, high

      if(alpha>slope*phi-slope*0.501&&phi>0.428&&phi<0.438) return false; // 2 // widened // above
      if(alpha>slope*phi-slope*0.501&&phi>0.469&&phi<0.475) return false; // 3 above
      if(alpha>slope*phi-slope*0.501&&phi>0.516&&phi<0.524) return false; // new // north only
      if(alpha<slope*phi-slope*0.494&&phi>0.382&&phi<0.428) return false; // new below
      if(alpha<slope*phi-slope*0.494&&phi>0.526&&phi<0.533) return false; // 6 below
      //if(phi>0.635&&phi<0.700) return false; // cut the corner // no more corner cutting
    }

  // from previous version

  if(zed>0)
    {
      //if(fabs(alpha)<0.002) return false; // false high momentum tracks
      // === W1 === //
      //if(alpha<1.778*phi-1.778*-0.2   && alpha>1.778*phi-1.778*-0.103) return false; // w1 below box
      //if(alpha<1.778*phi-1.778*-0.021 && alpha>1.778*phi-1.778*-0.014) return false; // w1 center of box
      //if(alpha<1.778*phi-1.778*0.06   && alpha>1.778*phi-1.778*0.2   ) return false; // w1 above box
      //if(phi>-0.099&&phi<-0.089) return false; // original
      if(phi>-0.105&&phi<-0.089) return false; // widened
      if(phi>-0.058&&phi<-0.052) return false;
      if(phi>-0.039&&phi<-0.032) return false;
      if(phi>-0.021&&phi<-0.013) return false;
      if(phi>0.020&&phi<0.026) return false;
      if(phi>0.039&&phi<0.046) return false;
      if(phi>0.056&&phi<0.065) return false;
      if(phi>0.077&&phi<0.085) return false;
      // === W2 === //
      //if(alpha<1.778*phi-1.778*0.300 && alpha>1.778*phi-1.778*0.415) return false; // w2 below box
      //if(alpha<1.778*phi-1.778*0.494 && alpha>1.778*phi-1.778*0.501) return false; // w2 center of box
      //if(alpha<1.778*phi-1.778*0.577 && alpha>1.778*phi-1.778*0.700) return false; // w2 above box
      if(phi>0.410&&phi<0.419) return false;
      //if(phi>0.430&&phi<0.438) return false; // original
      if(phi>0.428&&phi<0.438) return false; // widened
      if(phi>0.469&&phi<0.475) return false;
      if(phi>0.488&&phi<0.494) return false; // added
      if(phi>0.509&&phi<0.516) return false;
      if(phi>0.526&&phi<0.533) return false;
      if(phi>0.563&&phi<0.573) return false;
      if(phi>0.585&&phi<0.592) return false;
    }
  if(zed<0)
    {
      //if(fabs(alpha)<0.002) return false; // false high momentum tracks
      // === W1 === //
      //if(alpha<1.778*phi-1.778*-0.2   && alpha>1.778*phi-1.778*-0.105) return false; // w1 below box
      //if(alpha<1.778*phi-1.778*-0.021 && alpha>1.778*phi-1.778*-0.014) return false; // w1 center of box
      //if(alpha<1.778*phi-1.778*0.06   && alpha>1.778*phi-1.778*0.2   ) return false; // w1 above box
      //if(phi>-0.115&&phi<-0.089) return false; // wider than poszed // original
      if(phi>-0.118&&phi<-0.089) return false; // wider than poszed // widened
      if(phi>-0.058&&phi<-0.052) return false;
      //if(phi>-0.039&&phi<-0.032) return false; // not needed in south
      if(phi>-0.021&&phi<-0.013) return false;
      if(phi>0.020&&phi<0.026) return false;
      if(phi>0.036&&phi<0.046) return false; // wider than poszed
      if(phi>0.056&&phi<0.065) return false;
      if(phi>0.076&&phi<0.085) return false; // wider than poszed
      // === W2 === //
      //if(alpha<1.778*phi-1.778*0.300 && alpha>1.778*phi-1.778*0.415) return false; // w2 below box
      //if(alpha<1.778*phi-1.778*0.494 && alpha>1.778*phi-1.778*0.501) return false; // w2 center of box
      //if(alpha<1.778*phi-1.778*0.577 && alpha>1.778*phi-1.778*0.700) return false; // w2 above box
      //if(phi>0.410&&phi<0.419) return false; // not needed in south
      //if(phi>0.430&&phi<0.438) return false; // not needed in south
      if(phi>0.469&&phi<0.475) return false;
      if(phi>0.488&&phi<0.494) return false; // always here, recently added to W1
      if(phi>0.509&&phi<0.516) return false;
      if(phi>0.526&&phi<0.533) return false;
      if(phi>0.566&&phi<0.572) return false; // narrower than W1
      //if(phi>0.585&&phi<0.592) return false;
    }


  return true;

}




bool GoodPC1(float ppc1z, float ppc1phi)
{

  return true;

  float zed = ppc1z;
  float phi = ppc1phi;

  if(zed>0&&zed<13&&phi>0.9&&phi<0.95) return false;
  if(zed>61&&zed<65&&phi>0.9&&phi<0.95) return false;
  if(zed>-55&&zed<-48&&phi>0.81&&phi<0.88) return false;
  if(zed>-70&&zed<-57&&phi>0.78&&phi<0.83) return false;
  if(zed>-30&&zed<-18&&phi>0.55&&phi<0.6) return false;
  if(zed>-30&&zed<-18&&phi>0.35&&phi<0.45) return false;
  if(zed>-3&&zed<0&&phi>0.4&&phi<0.45) return false;
  if(zed>70&&zed<82&&phi>0.35&&phi<0.45) return false;
  if(zed>28&&zed<41&&phi>0.16&&phi<0.2) return false;
  if(zed>-52&&zed<-39&&phi>0.12&&phi<0.16) return false;
  if(zed>0&&zed<11&&phi>-0.26&&phi<-0.22) return false;
  if(zed>-30&&zed<-18&&phi>-0.4&&phi<-0.35) return false;

  // These holes are probably DC holes since they don't appear on a pc1phi vs pc1z plot
  // But it seems you can cut on these holes using the PC1 anyway
  if(zed<0&&phi<-0.088&&phi>-0.108) return false;
  if(zed>49&&zed<60&&phi>0.008&&phi<0.05) return false;
  if(zed>-71&&zed<-59&&phi>0.398&&phi<0.44) return false;
 
  return true;  
  
}



bool GoodPC2(float pc2z, float pc2phi)
{

  //return true;

  float zed = pc2z;
  float phi = pc2phi;

  //if(zed>-70&&zed<-50&&phi>0.51&&phi<0.55) return false; // modified
  //if(zed>-25&&zed<0&&phi>0.46&&phi<0.516) return false; // modified
  //if(zed>20&&zed<42&&phi>0.46&&phi<0.516) return false; // modified
  //if(zed>-70&&zed<-50&&phi>0.4&&phi<0.44) return false; // modified
  //if(zed>73&&zed<94&&phi>-0.076&&phi<0.02) return false; // modified

  if(zed>-73&&zed<-53&&phi>0.508&&phi<0.552) return false;
  if(zed>-23&&zed<0&&phi>0.472&&phi<0.520) return false;
  if(zed>22&&zed<41&&phi>0.472&&phi<0.520) return false;
  if(zed>-100&&zed<-87&&phi>0.370&&phi<0.438) return false;
  if(zed>-73&&zed<-53&&phi>0.370&&phi<0.438) return false;
  if(zed>61&&zed<72&&phi>0.370&&phi<0.438) return false;
  if(zed>73&&zed<93&&phi>-0.076&&phi<-0.022) return false;
  if(zed>81&&zed<93&&phi>-0.022&&phi<0.012) return false;
  if(zed>81&&zed<93&&phi>-0.150&&phi<-0.076) return false;

  if(zed>-85&&zed<-70&&phi>-0.060&&phi<-0.018) return false;

  // holes in simulation that don't exist in real data
  //if(zed>-74&&zed<-52&&phi>-0.080&&phi<-0.030) return false;
  //if(zed>71&&zed<90&&phi>0.032&&phi<0.070) return false;

  return true;

}



bool GoodPC3(float pc3z, float pc3phi)
{

  //return true;

  // --- these are the pc3 fiducial cuts, similar to the old
  // --- this is a pc3 fiducial map of the whole west arm

  float zed = pc3z;
  float phi = pc3phi;

  //if(zed>-125&&zed<-90&&phi>0.45&&phi<0.5) return false;
  //if(zed>63&&zed<90&&phi>0.45&&phi<0.52) return false; // modified
  //if(zed>-105&&zed<-80&&phi>0.4&&phi<0.45) return false;
  //if(zed>-65&&zed<0&&phi>0.4&&phi<0.45) return false;
  //if(zed>66&&zed<84&&phi>0.04&&phi<0.1) return false;
  //if(zed>-86&&zed<-73&&phi>0&&phi<0.1) return false; // modified
  //if(zed>-86&&zed<-60&&phi>0.038&&phi<0.1) return false; // modified
  //if(zed>85&&zed<115&&phi>-0.02&&phi<0.01) return false;

  //if(zed>-126&&zed<-100&&phi>0.476&&phi<0.508) return false;
  if(zed>-126&&zed<-90&&phi>0.470&&phi<0.512) return false;
  if(zed>62&&zed<88&&phi>0.472&&phi<0.516) return false;
  if(zed>-104&&zed<-84&&phi>0.370&&phi<0.444) return false;
  if(zed>-64&&zed<0&&phi>0.370&&phi<0.444) return false;
  if(zed>67&&zed<80&&phi>0.040&&phi<0.100) return false;
  if(zed>-86&&zed<-74&&phi>0.006&&phi<0.100) return false;
  if(zed>-86&&zed<-61&&phi>0.036&&phi<0.100) return false;
  if(zed>84&&zed<112&&phi>-0.034&&phi<0.012) return false;

  if(zed>148&&zed<154&&phi>0.014&&phi<0.048) return false;
  if(zed>155&&zed<161&&phi>-0.100&&phi<-0.076) return false;

  if(zed>14&&zed<28&&phi>0.488&&phi<0.508) return false;
  //if(zed>94&&zed<105&&phi>0.492&&phi<0.506) return false;
  if(zed>94&&zed<105&&phi>0.476&&phi<0.510) return false;

  if(zed>-45&&zed<-30&&phi>0.498&&phi<0.600) return false;





  return true;

}



void GetRunIndex()
{

  string s;
  ifstream f("runs.list");
  if(!f)
    {
      cerr << "Couldn't open file\n";
      exit(1);
    }
  
  int j=0;
  
  while(getline(f,s))
    {
      //cout << s << '\n';
      myMap.insert(make_pair(s,j));
      j++;
    }  

  return;  

}


void fetchRunOffsetFromFile(int run)
{
  //if(run>229000) return;
  if(run>229000) runoffset = 0.0;

  ifstream fin1;
  fin1.open("Shengli/run-by-run-tofw-offset-pass1.dat");

  if(fin1)
    {
      float tmp=-9999;
      int runnum=-9999;
      for(int irun=0; irun<837; irun++)
	{ 
	  fin1>>runnum;
	  fin1>>runoffset;
	  fin1>>tmp;
	  //cout<<irun<<" "<<runnum<<" "<<runoffset<<endl;
	  if(runnum==run)
	    {
	      //cout<<runnum<<" "<<runoffset<<endl;
	      fin1.close();
	      return;
	    }
	}
      runoffset = -9999;
      //cout<<"no such run!!!"<<endl; // don't need now
      fin1.close();
    }
  else
    {
      cout<<"open file error!!!"<<endl;
      exit(1);
    }
}




float retunepc3sdphi(float mom, int charge, float pc3sdphi, int run)
{

  if(run>235809) return pc3sdphi;

  if(mom<1.0&&charge==1)
    {
      pc3sdphi += 2.37098 + 2.41508/mom + -0.167838/mom/mom + -4.62053/sqrt(mom);
    }
  if(mom<1.0&&charge==-1)
    {
      pc3sdphi += -0.607138 + -0.931047/mom + 0.0806186/mom/mom + 1.498/sqrt(mom);
    }
  if(mom>=1.0&&charge==1)
    {
      pc3sdphi += -0.581313 + -1.88684/mom + 0.460376/mom/mom + 2.00206/sqrt(mom);
    }
  if(mom>=1.0&&charge==-1)
    {
      pc3sdphi += -1.64022 + -5.2691/mom + 1.30003/mom/mom + 5.65009/sqrt(mom);
    }
  
  if(mom<1.0&&charge==1)
    {
      pc3sdphi *= 1.61141 + 0.582339/mom + -0.0409053/mom/mom + -1.15727/sqrt(mom);
    }
  if(mom<1.0&&charge==-1)
    {
      pc3sdphi *= 1.58343 + 0.476241/mom + -0.0322883/mom/mom + -1.00415/sqrt(mom);
    }
  if(mom>=1.0&&charge==1)
    {
      pc3sdphi *= 0.172751 + -2.61773/mom + 0.779831/mom/mom + 2.61345/sqrt(mom);
    }
  if(mom>=1.0&&charge==-1)
    {
      pc3sdphi *= -0.446217 + -4.33424/mom + 1.14691/mom/mom + 4.6162/sqrt(mom);
    }

  return pc3sdphi;

}



float retunepc3sdz(float mom, int charge, float pc3sdz, int run)
{

  if(run>235809) return pc3sdz;

  if(mom<1.0&&charge==1)
    {
      pc3sdz += 0.201782 + 0.164564/mom + -0.00845799/mom/mom + -0.364586/sqrt(mom);
    }
  if(mom<1.0&&charge==-1)
    {
      pc3sdz += 0.272696 + 0.159075/mom + -0.00921781/mom/mom + -0.367772/sqrt(mom);
    }
  if(mom>=1.0&&charge==1)
    {
      pc3sdz += 0.00724846 + -0.24908/mom + 0.0804049/mom/mom + 0.154986/sqrt(mom);
    }
  if(mom>=1.0&&charge==-1)
    {
      pc3sdz += -0.764566 + -2.80649/mom + 0.739543/mom/mom + 2.88095/sqrt(mom);
    }
  
  if(mom<1.0&&charge==1)
    {
      pc3sdz *= 1.25063 + 0.321769/mom + -0.0367079/mom/mom + -0.556657/sqrt(mom);
    }
  if(mom<1.0&&charge==-1)
    {
      pc3sdz *= 1.14774 + 0.258845/mom + -0.0355997/mom/mom + -0.392616/sqrt(mom);
    }
  if(mom>=1.0&&charge==1)
    {
      pc3sdz *= 0.520258 + -1.51029/mom + 0.390062/mom/mom + 1.58393/sqrt(mom);
    }
  if(mom>=1.0&&charge==-1)
    {
      pc3sdz *= 1.21903 + 0.56019/mom + -0.124194/mom/mom + -0.667671/sqrt(mom);
    }

  return pc3sdz;
  
}



float retunetofwsdphi(float mom, int charge, float tofwsdphi, int run)
{

  if(run>235809) return tofwsdphi;

  if(mom<1.0&&charge==1)
    {
      tofwsdphi += -0.0856524 + 0.0463195/mom + -0.0113277/mom/mom + 0.0421854/sqrt(mom);
    }
  if(mom<1.0&&charge==-1)
    {
      tofwsdphi += -0.349811 + -0.286594/mom + 0.0217644/mom/mom + 0.561357/sqrt(mom);
    }
  if(mom>=1.0&&charge==1)
    {
      tofwsdphi += 2.40086 + 7.19616/mom + -1.65162/mom/mom + -7.94821/sqrt(mom);
    }
  if(mom>=1.0&&charge==-1)
    {
      tofwsdphi += -1.09199 + -2.5686/mom + 0.462683/mom/mom + 3.1694/sqrt(mom);
    }
  
  if(mom<1.0&&charge==1)
    {
      tofwsdphi *= -0.970694 + -2.29949/mom + 0.199509/mom/mom + 4.12296/sqrt(mom);
    }
  if(mom<1.0&&charge==-1)
    {
      tofwsdphi *= 1.46437 + 0.0334228/mom + 0.0311893/mom/mom + -0.439109/sqrt(mom);
    }
  if(mom>=1.0&&charge==1)
    {
      tofwsdphi *= 0.789783 + -1.00137/mom + 0.364043/mom/mom + 0.918734/sqrt(mom);
    }
  if(mom>=1.0&&charge==-1)
    {
      tofwsdphi *= 5.81935 + 15.3475/mom + -3.82073/mom/mom + -16.2912/sqrt(mom);
    }
  
  return tofwsdphi;

}



float retunetofwsdz(float mom, int charge, float tofwsdz, int run)
{

  if(run>235809) return tofwsdz;

  if(mom<1.0&&charge==1)
    {
      tofwsdz += -0.131251 + -0.168425/mom + 0.0158084/mom/mom + 0.288198/sqrt(mom);
    }
  if(mom<1.0&&charge==-1)
    {
      tofwsdz += -0.159494 + -0.183624/mom + 0.015822/mom/mom + 0.329179/sqrt(mom);
    }
  if(mom>=1.0&&charge==1)
    {
      tofwsdz += 0.216719 + 0.482543/mom + -0.0906608/mom/mom + -0.605824/sqrt(mom);
    }
  if(mom>=1.0&&charge==-1)
    {
      tofwsdz += -0.703019 + -1.89815/mom + 0.413052/mom/mom + 2.19288/sqrt(mom);
    }
  
  if(mom<1.0&&charge==1)
    {
      tofwsdz *= 0.491949 + -0.771236/mom + 0.078896/mom/mom + 1.22198/sqrt(mom);
    }
  if(mom<1.0&&charge==-1)
    {
      tofwsdz *= 0.532333 + -0.703994/mom + 0.0722247/mom/mom + 1.1196/sqrt(mom);
    }
  if(mom>=1.0&&charge==1)
    {
      tofwsdz *= 0.456132 + -1.63351/mom + 0.340878/mom/mom + 1.85854/sqrt(mom);
    }
  if(mom>=1.0&&charge==-1)
    {
      tofwsdz *= 1.11281 + 0.282242/mom + -0.10311/mom/mom + -0.267875/sqrt(mom);
    }

  return tofwsdz;

}



float retunepc2sdphi(float x, int charge, float pc2sdphi, int run)
{

  if(run<235810)
    {
      if(charge==1)
	{
	  pc2sdphi -= 0.0330127;
	}
      if(charge==-1)
	{
	  pc2sdphi -= -0.00315626;
	}
      if(charge==1)
	{
	  pc2sdphi /= 0.728876 + -0.000506321*x;
	}
      if(charge==-1)
	{
	  pc2sdphi /= 0.722949 + -0.000543441*x;
	}
    }

  if(run>235809)
    {
      if(charge==1)
	{
	  pc2sdphi -= 0.0172122;
	}
      if(charge==-1)
	{
	  pc2sdphi -= 0.0138114;
	}
      if(charge==1)
	{
	  pc2sdphi /= 0.742874 + -0.000576458*x;
	}
      if(charge==-1)
	{
	  pc2sdphi /= 0.743706 + -0.000537767*x;
	}
    }

  return pc2sdphi;

}



float retunepc2sdz(float x, int charge, float pc2sdz, int run)
{

  if(run<235810)
    {
      if(charge==1)
	{
	  pc2sdz -= -0.0456155 + 0.0010243*x;
	}
      if(charge==-1)
	{
	  pc2sdz -= -0.0115214 + 0.000954325*x;
	}
      if(charge==1)
	{
	  pc2sdz /= 0.743419 + -0.000788755*x + -1.86537e-05*x*x + 1.6131e-06*x*x*x + 1.6131e-06*x*x*x*x;
	}
      if(charge==-1)
	{
	  pc2sdz /= 0.74298 + -0.00101766*x + -6.65175e-06*x*x + 1.43055e-06*x*x*x + 1.43055e-06*x*x*x*x;
	}
    }

  if(run>235809)
    {
      if(charge==1)
	{
	  pc2sdz -= -0.0195378 + 0.000948001*x;
	}
      if(charge==-1)
	{
	  pc2sdz -= -0.0494192 + 0.000996899*x;
	}
      if(charge==1)
	{
	  pc2sdz /= 0.728193 + -0.000663927*x + -2.2053e-05*x*x + 1.67609e-06*x*x*x + 1.67609e-06*x*x*x*x;
	}
      if(charge==-1)
	{
	  pc2sdz /= 0.722895 + -0.001075*x + -5.78714e-06*x*x + 1.38879e-06*x*x*x + 1.38879e-06*x*x*x*x;
	}
    }

  return pc2sdz;

}
