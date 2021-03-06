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
const float pi = 3.141592653589793;


map<string,int> myMap;
void GetRunIndex();

bool goodStrip(int i);

float isPionANA(float x, float m2tofw);
float isKaonANA(float x, float m2tofw);
float isProtonANA(float x, float m2tofw);

float isPionANA_v1(float x, float m2tofw);
float isKaonANA_v1(float x, float m2tofw);
float isProtonANA_v1(float x, float m2tofw);

float isPionANA_v2(float x, float m2tofw);
float isKaonANA_v2(float x, float m2tofw);
float isProtonANA_v2(float x, float m2tofw);

float isPionANA_v3(float x, float m2tofw);
float isKaonANA_v3(float x, float m2tofw);
float isProtonANA_v3(float x, float m2tofw);

float isPionLow(float x, float m2tofw);
float isKaonLow(float x, float m2tofw);
float isProtonLow(float x, float m2tofw);

float isPionLME(float x, float m2tofw);
float isKaonLME(float x, float m2tofw);
float isProtonLME(float x, float m2tofw);

float isPionPDI(float x, float m2tofw);
//float isKaonPDI(float x, float m2tofw);
//float isProtonPDI(float x, float m2tofw);

bool GoodDCH(int run, float zed, float alpha, float phi);
bool GoodEdgeDCH(int run, float zed, float alpha, float phi);
bool GoodInnerDCH(int run, float zed, float alpha, float phi);
bool SysGoodEdgeDCH(int run, float zed, float alpha, float phi);
bool SysGoodInnerDCH(int run, float zed, float alpha, float phi);

bool GoodPC1(float ppc1z, float ppc1phi);
//bool GoodPC2(float pc2z, float pc2phi);
bool GoodPC3(float pc3z, float pc3phi);
bool GoodEMC(float emcz, float emcphi);
bool SysGoodPC1(float ppc1z, float ppc1phi);
//bool SysGoodPC2(float pc2z, float pc2phi);
bool SysGoodPC3(float pc3z, float pc3phi);
bool SysGoodEMC(float emcz, float emcphi);

void fetchRunOffsetFromFile(int run); // new

//float retunepc2sdphi(float x, int charge, float pc2sdphi, int run);
//float retunepc2sdz(float x, int charge, float pc2sdz, int run);
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
int main(int argc, char *argv[]) 
{ 

  //Char_t inFile[100];
  //Char_t outFile[100];
  char inFile[100];
  char outFile[100];

  if(argc==1)
    {
      cout<<"Now beginning program"<<endl;
      cout<<"Program name is "<<argv[0]<<endl;
      cout<<"Please enter input file name"<<endl;
      cin>>inFile;
      cout<<"Input file is "<<inFile<<endl;
      cout<<"Please enter output file name"<<endl;
      cin>>outFile;
      cout<<"Output file is "<<outFile<<endl;
    }
  else if(argc==3)
    {
      strcpy(inFile,argv[1]);
      strcpy(outFile,argv[2]);
      cout<<"Now beginning program"<<endl;
      cout<<"Program name is "<<argv[0]<<endl;
      cout<<"Input file is "<<inFile<<endl;
      cout<<"Output file is "<<outFile<<endl;
    }
  else
    {
      cout<<"Wrong number of input arguments"<<endl;
      cout<<"This program takes 0 or 2 arguments"<<endl;
      cout<<"With 0 arguments it prompts the user for the file list and output root file"<<endl;
      cout<<"With 2 arguments the first is the file list and the second is the output root file"<<endl;
      return 1;
    }

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

  TH1F *hhcent = new TH1F("hhcent","cent",100,0,100); // doesn't work, event bias
  TH1F *hhbbcz = new TH1F("hhbbcz","bbcz",100,-50,50);

  // counting histograms

  // matching tuning histograms




  // ------------------ //
  // --- background --- //
  // ------------------ //

  TH2F *bkgrd_tofwsdphi_pT_back_pos = new TH2F("bkgrd_tofwsdphi_pT_back_pos","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_back_neg = new TH2F("bkgrd_tofwsdphi_pT_back_neg","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_back_pos_cent0 = new TH2F("bkgrd_tofwsdphi_pT_back_pos_cent0","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_back_neg_cent0 = new TH2F("bkgrd_tofwsdphi_pT_back_neg_cent0","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_back_pos_cent1 = new TH2F("bkgrd_tofwsdphi_pT_back_pos_cent1","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_back_neg_cent1 = new TH2F("bkgrd_tofwsdphi_pT_back_neg_cent1","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_back_pos_cent2 = new TH2F("bkgrd_tofwsdphi_pT_back_pos_cent2","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_back_neg_cent2 = new TH2F("bkgrd_tofwsdphi_pT_back_neg_cent2","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_back_pos_cent3 = new TH2F("bkgrd_tofwsdphi_pT_back_pos_cent3","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_back_neg_cent3 = new TH2F("bkgrd_tofwsdphi_pT_back_neg_cent3","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_back_pos_cent4 = new TH2F("bkgrd_tofwsdphi_pT_back_pos_cent4","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_back_neg_cent4 = new TH2F("bkgrd_tofwsdphi_pT_back_neg_cent4","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);

  TH2F *bkgrd_tofwsdphi_pT_fore_pos = new TH2F("bkgrd_tofwsdphi_pT_fore_pos","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_fore_neg = new TH2F("bkgrd_tofwsdphi_pT_fore_neg","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_fore_pos_cent0 = new TH2F("bkgrd_tofwsdphi_pT_fore_pos_cent0","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_fore_neg_cent0 = new TH2F("bkgrd_tofwsdphi_pT_fore_neg_cent0","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_fore_pos_cent1 = new TH2F("bkgrd_tofwsdphi_pT_fore_pos_cent1","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_fore_neg_cent1 = new TH2F("bkgrd_tofwsdphi_pT_fore_neg_cent1","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_fore_pos_cent2 = new TH2F("bkgrd_tofwsdphi_pT_fore_pos_cent2","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_fore_neg_cent2 = new TH2F("bkgrd_tofwsdphi_pT_fore_neg_cent2","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_fore_pos_cent3 = new TH2F("bkgrd_tofwsdphi_pT_fore_pos_cent3","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_fore_neg_cent3 = new TH2F("bkgrd_tofwsdphi_pT_fore_neg_cent3","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_fore_pos_cent4 = new TH2F("bkgrd_tofwsdphi_pT_fore_pos_cent4","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_fore_neg_cent4 = new TH2F("bkgrd_tofwsdphi_pT_fore_neg_cent4","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);

  TH2F *bkgrd_tofwsdphi_pT_sign_pos = new TH2F("bkgrd_tofwsdphi_pT_sign_pos","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_sign_neg = new TH2F("bkgrd_tofwsdphi_pT_sign_neg","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_sign_pos_cent0 = new TH2F("bkgrd_tofwsdphi_pT_sign_pos_cent0","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_sign_neg_cent0 = new TH2F("bkgrd_tofwsdphi_pT_sign_neg_cent0","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_sign_pos_cent1 = new TH2F("bkgrd_tofwsdphi_pT_sign_pos_cent1","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_sign_neg_cent1 = new TH2F("bkgrd_tofwsdphi_pT_sign_neg_cent1","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_sign_pos_cent2 = new TH2F("bkgrd_tofwsdphi_pT_sign_pos_cent2","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_sign_neg_cent2 = new TH2F("bkgrd_tofwsdphi_pT_sign_neg_cent2","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_sign_pos_cent3 = new TH2F("bkgrd_tofwsdphi_pT_sign_pos_cent3","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_sign_neg_cent3 = new TH2F("bkgrd_tofwsdphi_pT_sign_neg_cent3","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_sign_pos_cent4 = new TH2F("bkgrd_tofwsdphi_pT_sign_pos_cent4","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_sign_neg_cent4 = new TH2F("bkgrd_tofwsdphi_pT_sign_neg_cent4","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);



  TH2F *bkgrd_tofwsdphi_pT_epsi_pos = new TH2F("bkgrd_tofwsdphi_pT_epsi_pos","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_epsi_neg = new TH2F("bkgrd_tofwsdphi_pT_epsi_neg","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_epsi_pos_cent0 = new TH2F("bkgrd_tofwsdphi_pT_epsi_pos_cent0","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_epsi_neg_cent0 = new TH2F("bkgrd_tofwsdphi_pT_epsi_neg_cent0","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_epsi_pos_cent1 = new TH2F("bkgrd_tofwsdphi_pT_epsi_pos_cent1","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_epsi_neg_cent1 = new TH2F("bkgrd_tofwsdphi_pT_epsi_neg_cent1","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_epsi_pos_cent2 = new TH2F("bkgrd_tofwsdphi_pT_epsi_pos_cent2","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_epsi_neg_cent2 = new TH2F("bkgrd_tofwsdphi_pT_epsi_neg_cent2","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_epsi_pos_cent3 = new TH2F("bkgrd_tofwsdphi_pT_epsi_pos_cent3","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_epsi_neg_cent3 = new TH2F("bkgrd_tofwsdphi_pT_epsi_neg_cent3","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_epsi_pos_cent4 = new TH2F("bkgrd_tofwsdphi_pT_epsi_pos_cent4","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
  TH2F *bkgrd_tofwsdphi_pT_epsi_neg_cent4 = new TH2F("bkgrd_tofwsdphi_pT_epsi_neg_cent4","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);





  // DC fiducial maps

  TH2F *hh_alphaphi_poszed_nc_FW = new TH2F("hh_alphaphi_poszed_nc_FW","alpha vs phi zed>0 no cuts", 920, -0.22, 0.7, 420, -0.21, 0.21);
  TH2F *hh_alphaphi_negzed_nc_FW = new TH2F("hh_alphaphi_negzed_nc_FW","alpha vs phi zed<0 no cuts", 920, -0.22, 0.7, 420, -0.21, 0.21);
  TH2F *hh_alphaphi_poszed_mc_FW = new TH2F("hh_alphaphi_poszed_mc_FW","alpha vs phi zed>0 matching cuts", 920, -0.22, 0.7, 420, -0.21, 0.21);
  TH2F *hh_alphaphi_negzed_mc_FW = new TH2F("hh_alphaphi_negzed_mc_FW","alpha vs phi zed<0 matching cuts", 920, -0.22, 0.7, 420, -0.21, 0.21);
  TH2F *hh_alphaphi_poszed_ec_FW = new TH2F("hh_alphaphi_poszed_ec_FW","alpha vs phi zed>0 edge cuts", 920, -0.22, 0.7, 420, -0.21, 0.21);
  TH2F *hh_alphaphi_negzed_ec_FW = new TH2F("hh_alphaphi_negzed_ec_FW","alpha vs phi zed<0 edge cuts", 920, -0.22, 0.7, 420, -0.21, 0.21);
  TH2F *hh_alphaphi_poszed_ac_FW = new TH2F("hh_alphaphi_poszed_ac_FW","alpha vs phi zed>0 all cuts", 920, -0.22, 0.7, 420, -0.21, 0.21);
  TH2F *hh_alphaphi_negzed_ac_FW = new TH2F("hh_alphaphi_negzed_ac_FW","alpha vs phi zed<0 all cuts", 920, -0.22, 0.7, 420, -0.21, 0.21);


  // no cuts
  // zed>0
  TH2F *hh_alphaphi_poszed_nc = new TH2F("hh_alphaphi_poszed_nc","alpha vs phi zed>0 no cuts", 1300, -0.4, 0.9, 840, -0.42, 0.42);
  TH2F *hh_pos_momphi_poszed_nc = new TH2F("hh_pos_momphi_poszed_nc","pT vs phi zed>0 no cuts", 1300, -0.4, 0.9, 100, 0, 10);
  TH2F *hh_neg_momphi_poszed_nc = new TH2F("hh_neg_momphi_poszed_nc","pT vs phi zed>0 no cuts", 1300, -0.4, 0.9, 100, 0, 10);
  // zed<0
  TH2F *hh_alphaphi_negzed_nc = new TH2F("hh_alphaphi_negzed_nc","alpha vs phi zed<0 no cuts", 1300, -0.4, 0.9, 840, -0.42, 0.42);
  TH2F *hh_pos_momphi_negzed_nc = new TH2F("hh_pos_momphi_negzed_nc","pT vs phi zed<0 no cuts", 1300, -0.4, 0.9, 100, 0, 10);
  TH2F *hh_neg_momphi_negzed_nc = new TH2F("hh_neg_momphi_negzed_nc","pT vs phi zed<0 no cuts", 1300, -0.4, 0.9, 100, 0, 10);

  // matching cuts
  // zed>0
  TH2F *hh_alphaphi_poszed_mc = new TH2F("hh_alphaphi_poszed_mc","alpha vs phi zed>0 matching cuts", 1300, -0.4, 0.9, 840, -0.42, 0.42);
  TH2F *hh_pos_momphi_poszed_mc = new TH2F("hh_pos_momphi_poszed_mc","pT vs phi zed>0 matching cuts", 1300, -0.4, 0.9, 100, 0, 10);
  TH2F *hh_neg_momphi_poszed_mc = new TH2F("hh_neg_momphi_poszed_mc","pT vs phi zed>0 matching cuts", 1300, -0.4, 0.9, 100, 0, 10);
  // zed<0
  TH2F *hh_alphaphi_negzed_mc = new TH2F("hh_alphaphi_negzed_mc","alpha vs phi zed<0 matching cuts", 1300, -0.4, 0.9, 840, -0.42, 0.42);
  TH2F *hh_pos_momphi_negzed_mc = new TH2F("hh_pos_momphi_negzed_mc","pT vs phi zed<0 matching cuts", 1300, -0.4, 0.9, 100, 0, 10);
  TH2F *hh_neg_momphi_negzed_mc = new TH2F("hh_neg_momphi_negzed_mc","pT vs phi zed<0 matching cuts", 1300, -0.4, 0.9, 100, 0, 10);

  // edge cuts
  // zed>0
  TH2F *hh_alphaphi_poszed_ec = new TH2F("hh_alphaphi_poszed_ec","alpha vs phi zed>0 edge cuts", 1300, -0.4, 0.9, 840, -0.42, 0.42);
  TH2F *hh_pos_momphi_poszed_ec = new TH2F("hh_pos_momphi_poszed_ec","pT vs phi zed>0 edge cuts", 1300, -0.4, 0.9, 100, 0, 10);
  TH2F *hh_neg_momphi_poszed_ec = new TH2F("hh_neg_momphi_poszed_ec","pT vs phi zed>0 edge cuts", 1300, -0.4, 0.9, 100, 0, 10);
  // zed<0
  TH2F *hh_alphaphi_negzed_ec = new TH2F("hh_alphaphi_negzed_ec","alpha vs phi zed<0 edge cuts", 1300, -0.4, 0.9, 840, -0.42, 0.42);
  TH2F *hh_pos_momphi_negzed_ec = new TH2F("hh_pos_momphi_negzed_ec","pT vs phi zed<0 edge cuts", 1300, -0.4, 0.9, 100, 0, 10);
  TH2F *hh_neg_momphi_negzed_ec = new TH2F("hh_neg_momphi_negzed_ec","pT vs phi zed<0 edge cuts", 1300, -0.4, 0.9, 100, 0, 10);

  // all cuts
  // zed>0
  TH2F *hh_alphaphi_poszed_ac = new TH2F("hh_alphaphi_poszed_ac","alpha vs phi zed>0 all cuts", 1300, -0.4, 0.9, 840, -0.42, 0.42);
  TH2F *hh_pos_momphi_poszed_ac = new TH2F("hh_pos_momphi_poszed_ac","pT vs phi zed>0 all cuts", 1300, -0.4, 0.9, 100, 0, 10);
  TH2F *hh_neg_momphi_poszed_ac = new TH2F("hh_neg_momphi_poszed_ac","pT vs phi zed>0 all cuts", 1300, -0.4, 0.9, 100, 0, 10);
  // zed<0
  TH2F *hh_alphaphi_negzed_ac = new TH2F("hh_alphaphi_negzed_ac","alpha vs phi zed<0 all cuts", 1300, -0.4, 0.9, 840, -0.42, 0.42);
  TH2F *hh_pos_momphi_negzed_ac = new TH2F("hh_pos_momphi_negzed_ac","pT vs phi zed<0 all cuts", 1300, -0.4, 0.9, 100, 0, 10);
  TH2F *hh_neg_momphi_negzed_ac = new TH2F("hh_neg_momphi_negzed_ac","pT vs phi zed<0 all cuts", 1300, -0.4, 0.9, 100, 0, 10);

  // dc zed vs phi
  TH2F *hh_zedphi_nc = new TH2F("hh_zedphi_nc","phi vs zed no cuts", 160, -80, 80, 1300, -0.4, 0.9);
  TH2F *hh_zedphi_mc = new TH2F("hh_zedphi_mc","phi vs zed matching cuts", 160, -80, 80, 1300, -0.4, 0.9);
  TH2F *hh_zedphi_ec = new TH2F("hh_zedphi_ec","phi vs zed edge cuts", 160, -80, 80, 1300, -0.4, 0.9);
  TH2F *hh_zedphi_ac = new TH2F("hh_zedphi_ac","phi vs zed all cuts", 160, -80, 80, 1300, -0.4, 0.9);


  //Pad Chamber Fiducial Cut Histograms
  TH2F *PC1ZedPhiDis  = new TH2F("PC1ZedPhiDis", "PC1 phi vs zed w/o FC", 400, -200, 200, 500, -0.3, 0.7);
  TH2F *PC1ZedPhiNewDis  = new TH2F("PC1ZedPhiNewDis", "PC1 phi vs zed w/ FC", 400, -200, 200, 500, -0.3, 0.7);
  // TH2F *PC2ZedPhiDis  = new TH2F("PC2ZedPhiDis", "PC2 phi vs zed w/o FC", 400, -200, 200, 500, -0.3, 0.7);
  // TH2F *PC2ZedPhiNewDis  = new TH2F("PC2ZedPhiNewDis", "PC2 phi vs zed w/ FC",400, -200, 200, 500, -0.3, 0.7);
  TH2F *PC3ZedPhiDis  = new TH2F("PC3ZedPhiDis", "PC3 phi vs zed w/o FC", 400, -200, 200, 500, -0.3, 0.7);
  TH2F *PC3ZedPhiNewDis  = new TH2F("PC3ZedPhiNewDis", "PC3 phi vs zed w/ FC", 400, -200, 200, 500, -0.3, 0.7);
  // tofw fiducial histograms
  TH2F *TOFWZedPhiDis  = new TH2F("TOFWZedPhiDis", "TOFW phi vs zed w/o FC", 400, -200, 200, 500, -0.3, 0.7);
  TH2F *TOFWZedPhiNewDis  = new TH2F("TOFWZedPhiNewDis", "TOFW phi vs zed w/ FC", 400, -200, 200, 500, -0.3, 0.7);
  //TH2F *TOFWZedPhiNewNewDis  = new TH2F("TOFWZedPhiNewNewDis", "TOFW phi vs zed w/ all FC", 400, -200, 200, 500, -0.3, 0.7); // unused for now
  //
  TH2F *EMCZedPhiDis  = new TH2F("EMCZedPhiDis", "EMC phi vs zed w/o FC", 400, -200, 200, 500, -0.3, 0.7);
  TH2F *EMCZedPhiNewDis  = new TH2F("EMCZedPhiNewDis", "EMC phi vs zed w/ FC",400, -200, 200, 500, -0.3, 0.7);


  // ---------------------------- //
  // --- begin pid histograms --- //
  // ---------------------------- //

  TH2F *m2momdis_pos = new TH2F("m2momdis_pos","m2 vs mom", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2momdis_neg = new TH2F("m2momdis_neg","m2 vs mom", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2momdis_pos_w1 = new TH2F("m2momdis_pos_w1","m2 vs mom", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2momdis_neg_w1 = new TH2F("m2momdis_neg_w1","m2 vs mom", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2momdis_pos_w2 = new TH2F("m2momdis_pos_w2","m2 vs mom", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2momdis_neg_w2 = new TH2F("m2momdis_neg_w2","m2 vs mom", 100, 0.0, 10.0, 300, -1.0, 2.0);

  TH2F *isPi_dis_pos_cent0010 = new TH2F("isPi_dis_pos_cent0010","isPi vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isPi_dis_neg_cent0010 = new TH2F("isPi_dis_neg_cent0010","isPi vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isPi_dis_pos_cent1020 = new TH2F("isPi_dis_pos_cent1020","isPi vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isPi_dis_neg_cent1020 = new TH2F("isPi_dis_neg_cent1020","isPi vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isPi_dis_pos_cent2040 = new TH2F("isPi_dis_pos_cent2040","isPi vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isPi_dis_neg_cent2040 = new TH2F("isPi_dis_neg_cent2040","isPi vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isPi_dis_pos_cent4060 = new TH2F("isPi_dis_pos_cent4060","isPi vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isPi_dis_neg_cent4060 = new TH2F("isPi_dis_neg_cent4060","isPi vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isPi_dis_pos_cent6092 = new TH2F("isPi_dis_pos_cent6092","isPi vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isPi_dis_neg_cent6092 = new TH2F("isPi_dis_neg_cent6092","isPi vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);

  TH2F *isK_dis_pos_cent0010 = new TH2F("isK_dis_pos_cent0010","isK vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isK_dis_neg_cent0010 = new TH2F("isK_dis_neg_cent0010","isK vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isK_dis_pos_cent1020 = new TH2F("isK_dis_pos_cent1020","isK vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isK_dis_neg_cent1020 = new TH2F("isK_dis_neg_cent1020","isK vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isK_dis_pos_cent2040 = new TH2F("isK_dis_pos_cent2040","isK vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isK_dis_neg_cent2040 = new TH2F("isK_dis_neg_cent2040","isK vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isK_dis_pos_cent4060 = new TH2F("isK_dis_pos_cent4060","isK vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isK_dis_neg_cent4060 = new TH2F("isK_dis_neg_cent4060","isK vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isK_dis_pos_cent6092 = new TH2F("isK_dis_pos_cent6092","isK vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isK_dis_neg_cent6092 = new TH2F("isK_dis_neg_cent6092","isK vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);

  TH2F *isP_dis_pos_cent0010 = new TH2F("isP_dis_pos_cent0010","isP vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isP_dis_neg_cent0010 = new TH2F("isP_dis_neg_cent0010","isP vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isP_dis_pos_cent1020 = new TH2F("isP_dis_pos_cent1020","isP vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isP_dis_neg_cent1020 = new TH2F("isP_dis_neg_cent1020","isP vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isP_dis_pos_cent2040 = new TH2F("isP_dis_pos_cent2040","isP vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isP_dis_neg_cent2040 = new TH2F("isP_dis_neg_cent2040","isP vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isP_dis_pos_cent4060 = new TH2F("isP_dis_pos_cent4060","isP vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isP_dis_neg_cent4060 = new TH2F("isP_dis_neg_cent4060","isP vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isP_dis_pos_cent6092 = new TH2F("isP_dis_pos_cent6092","isP vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isP_dis_neg_cent6092 = new TH2F("isP_dis_neg_cent6092","isP vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);


  TH2F *isPi_dis_pos = new TH2F("isPi_dis_pos","isPi vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isPi_dis_neg = new TH2F("isPi_dis_neg","isPi vs mom", 100, 0.0, 10.0, 100, -3.0, 7.0);
  TH2F *isK_dis_pos = new TH2F("isK_dis_pos","isK vs mom", 100, 0.0, 10.0, 100, -5.0, 5.0);
  TH2F *isK_dis_neg = new TH2F("isK_dis_neg","isK vs mom", 100, 0.0, 10.0, 100, -5.0, 5.0);
  TH2F *isP_dis_pos = new TH2F("isP_dis_pos","isP vs mom", 100, 0.0, 10.0, 100, -7.0, 3.0);
  TH2F *isP_dis_neg = new TH2F("isP_dis_neg","isP vs mom", 100, 0.0, 10.0, 100, -7.0, 3.0);

  TH2F *m2pTdis_pos = new TH2F("m2pTdis_pos","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_neg = new TH2F("m2pTdis_neg","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);

  TH2F *m2pTdis_pos_cent0 = new TH2F("m2pTdis_pos_cent0","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_pos_cent1 = new TH2F("m2pTdis_pos_cent1","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_pos_cent2 = new TH2F("m2pTdis_pos_cent2","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_pos_cent3 = new TH2F("m2pTdis_pos_cent3","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_pos_cent4 = new TH2F("m2pTdis_pos_cent4","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);

  TH2F *m2pTdis_neg_cent0 = new TH2F("m2pTdis_neg_cent0","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_neg_cent1 = new TH2F("m2pTdis_neg_cent1","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_neg_cent2 = new TH2F("m2pTdis_neg_cent2","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_neg_cent3 = new TH2F("m2pTdis_neg_cent3","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_neg_cent4 = new TH2F("m2pTdis_neg_cent4","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);

  TH2F *m2pTdis_epc_pos = new TH2F("m2pTdis_epc_pos","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_epc_neg = new TH2F("m2pTdis_epc_neg","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);

  TH2F *m2pTdis_epc_pos_cent0 = new TH2F("m2pTdis_epc_pos_cent0","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_epc_pos_cent1 = new TH2F("m2pTdis_epc_pos_cent1","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_epc_pos_cent2 = new TH2F("m2pTdis_epc_pos_cent2","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_epc_pos_cent3 = new TH2F("m2pTdis_epc_pos_cent3","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_epc_pos_cent4 = new TH2F("m2pTdis_epc_pos_cent4","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);

  TH2F *m2pTdis_epc_neg_cent0 = new TH2F("m2pTdis_epc_neg_cent0","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_epc_neg_cent1 = new TH2F("m2pTdis_epc_neg_cent1","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_epc_neg_cent2 = new TH2F("m2pTdis_epc_neg_cent2","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_epc_neg_cent3 = new TH2F("m2pTdis_epc_neg_cent3","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
  TH2F *m2pTdis_epc_neg_cent4 = new TH2F("m2pTdis_epc_neg_cent4","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);

  // ---------------------------- //
  // ---- end pid histograms ---- //
  // ---------------------------- //



  // ---------------------------- //
  // --- begin sys histograms --- //
  // ---------------------------- //

  TH1F *ptsys_pion_pos_tfwmA = new TH1F("ptsys_pion_pos_tfwmA", "pion pos sys tfwm A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_tfwmA = new TH1F("ptsys_kaon_pos_tfwmA", "kaon pos sys tfwm A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_tfwmA = new TH1F("ptsys_prot_pos_tfwmA", "prot pos sys tfwm A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_pc3mA = new TH1F("ptsys_pion_pos_pc3mA", "pion pos sys pc3m A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_pc3mA = new TH1F("ptsys_kaon_pos_pc3mA", "kaon pos sys pc3m A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_pc3mA = new TH1F("ptsys_prot_pos_pc3mA", "prot pos sys pc3m A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_pc3fA = new TH1F("ptsys_pion_pos_pc3fA", "pion pos sys pc3f A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_pc3fA = new TH1F("ptsys_kaon_pos_pc3fA", "kaon pos sys pc3f A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_pc3fA = new TH1F("ptsys_prot_pos_pc3fA", "prot pos sys pc3f A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_pc1fA = new TH1F("ptsys_pion_pos_pc1fA", "pion pos sys pc1f A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_pc1fA = new TH1F("ptsys_kaon_pos_pc1fA", "kaon pos sys pc1f A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_pc1fA = new TH1F("ptsys_prot_pos_pc1fA", "prot pos sys pc1f A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_gadcA = new TH1F("ptsys_pion_pos_gadcA", "pion pos sys gadc A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_gadcA = new TH1F("ptsys_kaon_pos_gadcA", "kaon pos sys gadc A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_gadcA = new TH1F("ptsys_prot_pos_gadcA", "prot pos sys gadc A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_dcfcA = new TH1F("ptsys_pion_pos_dcfcA", "pion pos sys dcfc A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_dcfcA = new TH1F("ptsys_kaon_pos_dcfcA", "kaon pos sys dcfc A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_dcfcA = new TH1F("ptsys_prot_pos_dcfcA", "prot pos sys dcfc A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_dzedA = new TH1F("ptsys_pion_pos_dzedA", "pion pos sys dzed A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_dzedA = new TH1F("ptsys_kaon_pos_dzedA", "kaon pos sys dzed A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_dzedA = new TH1F("ptsys_prot_pos_dzedA", "prot pos sys dzed A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_spidA = new TH1F("ptsys_pion_pos_spidA", "pion pos sys spid A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_spidA = new TH1F("ptsys_kaon_pos_spidA", "kaon pos sys spid A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_spidA = new TH1F("ptsys_prot_pos_spidA", "prot pos sys spid A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_tpidA = new TH1F("ptsys_pion_pos_tpidA", "pion pos sys tpid A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_tpidA = new TH1F("ptsys_kaon_pos_tpidA", "kaon pos sys tpid A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_tpidA = new TH1F("ptsys_prot_pos_tpidA", "prot pos sys tpid A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_tepcA = new TH1F("ptsys_pion_pos_tepcA", "pion pos sys tepc A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_tepcA = new TH1F("ptsys_kaon_pos_tepcA", "kaon pos sys tepc A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_tepcA = new TH1F("ptsys_prot_pos_tepcA", "prot pos sys tepc A", 100, 0.0, 10.0);

  TH1F *ptsys_pion_pos_tfwmB = new TH1F("ptsys_pion_pos_tfwmB", "pion pos sys tfwm B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_tfwmB = new TH1F("ptsys_kaon_pos_tfwmB", "kaon pos sys tfwm B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_tfwmB = new TH1F("ptsys_prot_pos_tfwmB", "prot pos sys tfwm B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_pc3mB = new TH1F("ptsys_pion_pos_pc3mB", "pion pos sys pc3m B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_pc3mB = new TH1F("ptsys_kaon_pos_pc3mB", "kaon pos sys pc3m B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_pc3mB = new TH1F("ptsys_prot_pos_pc3mB", "prot pos sys pc3m B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_pc3fB = new TH1F("ptsys_pion_pos_pc3fB", "pion pos sys pc3f B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_pc3fB = new TH1F("ptsys_kaon_pos_pc3fB", "kaon pos sys pc3f B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_pc3fB = new TH1F("ptsys_prot_pos_pc3fB", "prot pos sys pc3f B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_pc1fB = new TH1F("ptsys_pion_pos_pc1fB", "pion pos sys pc1f B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_pc1fB = new TH1F("ptsys_kaon_pos_pc1fB", "kaon pos sys pc1f B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_pc1fB = new TH1F("ptsys_prot_pos_pc1fB", "prot pos sys pc1f B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_gadcB = new TH1F("ptsys_pion_pos_gadcB", "pion pos sys gadc B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_gadcB = new TH1F("ptsys_kaon_pos_gadcB", "kaon pos sys gadc B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_gadcB = new TH1F("ptsys_prot_pos_gadcB", "prot pos sys gadc B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_dcfcB = new TH1F("ptsys_pion_pos_dcfcB", "pion pos sys dcfc B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_dcfcB = new TH1F("ptsys_kaon_pos_dcfcB", "kaon pos sys dcfc B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_dcfcB = new TH1F("ptsys_prot_pos_dcfcB", "prot pos sys dcfc B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_dzedB = new TH1F("ptsys_pion_pos_dzedB", "pion pos sys dzed B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_dzedB = new TH1F("ptsys_kaon_pos_dzedB", "kaon pos sys dzed B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_dzedB = new TH1F("ptsys_prot_pos_dzedB", "prot pos sys dzed B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_spidB = new TH1F("ptsys_pion_pos_spidB", "pion pos sys spid B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_spidB = new TH1F("ptsys_kaon_pos_spidB", "kaon pos sys spid B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_spidB = new TH1F("ptsys_prot_pos_spidB", "prot pos sys spid B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_tpidB = new TH1F("ptsys_pion_pos_tpidB", "pion pos sys tpid B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_tpidB = new TH1F("ptsys_kaon_pos_tpidB", "kaon pos sys tpid B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_tpidB = new TH1F("ptsys_prot_pos_tpidB", "prot pos sys tpid B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_pos_tepcB = new TH1F("ptsys_pion_pos_tepcB", "pion pos sys tepc B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_pos_tepcB = new TH1F("ptsys_kaon_pos_tepcB", "kaon pos sys tepc B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_pos_tepcB = new TH1F("ptsys_prot_pos_tepcB", "prot pos sys tepc B", 100, 0.0, 10.0);

  TH1F *ptsys_pion_neg_tfwmA = new TH1F("ptsys_pion_neg_tfwmA", "pion neg sys tfwm A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_tfwmA = new TH1F("ptsys_kaon_neg_tfwmA", "kaon neg sys tfwm A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_tfwmA = new TH1F("ptsys_prot_neg_tfwmA", "prot neg sys tfwm A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_pc3mA = new TH1F("ptsys_pion_neg_pc3mA", "pion neg sys pc3m A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_pc3mA = new TH1F("ptsys_kaon_neg_pc3mA", "kaon neg sys pc3m A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_pc3mA = new TH1F("ptsys_prot_neg_pc3mA", "prot neg sys pc3m A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_pc3fA = new TH1F("ptsys_pion_neg_pc3fA", "pion neg sys pc3f A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_pc3fA = new TH1F("ptsys_kaon_neg_pc3fA", "kaon neg sys pc3f A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_pc3fA = new TH1F("ptsys_prot_neg_pc3fA", "prot neg sys pc3f A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_pc1fA = new TH1F("ptsys_pion_neg_pc1fA", "pion neg sys pc1f A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_pc1fA = new TH1F("ptsys_kaon_neg_pc1fA", "kaon neg sys pc1f A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_pc1fA = new TH1F("ptsys_prot_neg_pc1fA", "prot neg sys pc1f A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_gadcA = new TH1F("ptsys_pion_neg_gadcA", "pion neg sys gadc A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_gadcA = new TH1F("ptsys_kaon_neg_gadcA", "kaon neg sys gadc A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_gadcA = new TH1F("ptsys_prot_neg_gadcA", "prot neg sys gadc A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_dcfcA = new TH1F("ptsys_pion_neg_dcfcA", "pion neg sys dcfc A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_dcfcA = new TH1F("ptsys_kaon_neg_dcfcA", "kaon neg sys dcfc A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_dcfcA = new TH1F("ptsys_prot_neg_dcfcA", "prot neg sys dcfc A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_dzedA = new TH1F("ptsys_pion_neg_dzedA", "pion neg sys dzed A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_dzedA = new TH1F("ptsys_kaon_neg_dzedA", "kaon neg sys dzed A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_dzedA = new TH1F("ptsys_prot_neg_dzedA", "prot neg sys dzed A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_spidA = new TH1F("ptsys_pion_neg_spidA", "pion neg sys spid A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_spidA = new TH1F("ptsys_kaon_neg_spidA", "kaon neg sys spid A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_spidA = new TH1F("ptsys_prot_neg_spidA", "prot neg sys spid A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_tpidA = new TH1F("ptsys_pion_neg_tpidA", "pion neg sys tpid A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_tpidA = new TH1F("ptsys_kaon_neg_tpidA", "kaon neg sys tpid A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_tpidA = new TH1F("ptsys_prot_neg_tpidA", "prot neg sys tpid A", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_tepcA = new TH1F("ptsys_pion_neg_tepcA", "pion neg sys tepc A", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_tepcA = new TH1F("ptsys_kaon_neg_tepcA", "kaon neg sys tepc A", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_tepcA = new TH1F("ptsys_prot_neg_tepcA", "prot neg sys tepc A", 100, 0.0, 10.0);

  TH1F *ptsys_pion_neg_tfwmB = new TH1F("ptsys_pion_neg_tfwmB", "pion neg sys tfwm B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_tfwmB = new TH1F("ptsys_kaon_neg_tfwmB", "kaon neg sys tfwm B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_tfwmB = new TH1F("ptsys_prot_neg_tfwmB", "prot neg sys tfwm B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_pc3mB = new TH1F("ptsys_pion_neg_pc3mB", "pion neg sys pc3m B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_pc3mB = new TH1F("ptsys_kaon_neg_pc3mB", "kaon neg sys pc3m B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_pc3mB = new TH1F("ptsys_prot_neg_pc3mB", "prot neg sys pc3m B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_pc3fB = new TH1F("ptsys_pion_neg_pc3fB", "pion neg sys pc3f B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_pc3fB = new TH1F("ptsys_kaon_neg_pc3fB", "kaon neg sys pc3f B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_pc3fB = new TH1F("ptsys_prot_neg_pc3fB", "prot neg sys pc3f B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_pc1fB = new TH1F("ptsys_pion_neg_pc1fB", "pion neg sys pc1f B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_pc1fB = new TH1F("ptsys_kaon_neg_pc1fB", "kaon neg sys pc1f B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_pc1fB = new TH1F("ptsys_prot_neg_pc1fB", "prot neg sys pc1f B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_gadcB = new TH1F("ptsys_pion_neg_gadcB", "pion neg sys gadc B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_gadcB = new TH1F("ptsys_kaon_neg_gadcB", "kaon neg sys gadc B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_gadcB = new TH1F("ptsys_prot_neg_gadcB", "prot neg sys gadc B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_dcfcB = new TH1F("ptsys_pion_neg_dcfcB", "pion neg sys dcfc B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_dcfcB = new TH1F("ptsys_kaon_neg_dcfcB", "kaon neg sys dcfc B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_dcfcB = new TH1F("ptsys_prot_neg_dcfcB", "prot neg sys dcfc B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_dzedB = new TH1F("ptsys_pion_neg_dzedB", "pion neg sys dzed B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_dzedB = new TH1F("ptsys_kaon_neg_dzedB", "kaon neg sys dzed B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_dzedB = new TH1F("ptsys_prot_neg_dzedB", "prot neg sys dzed B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_spidB = new TH1F("ptsys_pion_neg_spidB", "pion neg sys spid B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_spidB = new TH1F("ptsys_kaon_neg_spidB", "kaon neg sys spid B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_spidB = new TH1F("ptsys_prot_neg_spidB", "prot neg sys spid B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_tpidB = new TH1F("ptsys_pion_neg_tpidB", "pion neg sys tpid B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_tpidB = new TH1F("ptsys_kaon_neg_tpidB", "kaon neg sys tpid B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_tpidB = new TH1F("ptsys_prot_neg_tpidB", "prot neg sys tpid B", 100, 0.0, 10.0);
  TH1F *ptsys_pion_neg_tepcB = new TH1F("ptsys_pion_neg_tepcB", "pion neg sys tepc B", 100, 0.0, 10.0);
  TH1F *ptsys_kaon_neg_tepcB = new TH1F("ptsys_kaon_neg_tepcB", "kaon neg sys tepc B", 100, 0.0, 10.0);
  TH1F *ptsys_prot_neg_tepcB = new TH1F("ptsys_prot_neg_tepcB", "prot neg sys tepc B", 100, 0.0, 10.0);

  // -------------------------- //
  // --- end sys histograms --- //
  // -------------------------- //



  // ------------------------------------ //
  // --- begin special pid histograms --- //
  // ------------------------------------ //

  TH1F *ptpid_tofw_pos_0_dis_cent0010 = new TH1F("ptpid_tofw_pos_0_dis_cent0010", "tofw 0 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_0_dis_cent1020 = new TH1F("ptpid_tofw_pos_0_dis_cent1020", "tofw 0 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_0_dis_cent2040 = new TH1F("ptpid_tofw_pos_0_dis_cent2040", "tofw 0 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_0_dis_cent4060 = new TH1F("ptpid_tofw_pos_0_dis_cent4060", "tofw 0 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_0_dis_cent6092 = new TH1F("ptpid_tofw_pos_0_dis_cent6092", "tofw 0 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_2_dis_cent0010 = new TH1F("ptpid_tofw_pos_2_dis_cent0010", "tofw 2 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_2_dis_cent1020 = new TH1F("ptpid_tofw_pos_2_dis_cent1020", "tofw 2 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_2_dis_cent2040 = new TH1F("ptpid_tofw_pos_2_dis_cent2040", "tofw 2 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_2_dis_cent4060 = new TH1F("ptpid_tofw_pos_2_dis_cent4060", "tofw 2 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_2_dis_cent6092 = new TH1F("ptpid_tofw_pos_2_dis_cent6092", "tofw 2 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_4_dis_cent0010 = new TH1F("ptpid_tofw_pos_4_dis_cent0010", "tofw 4 pos ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_4_dis_cent1020 = new TH1F("ptpid_tofw_pos_4_dis_cent1020", "tofw 4 pos ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_4_dis_cent2040 = new TH1F("ptpid_tofw_pos_4_dis_cent2040", "tofw 4 pos ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_4_dis_cent4060 = new TH1F("ptpid_tofw_pos_4_dis_cent4060", "tofw 4 pos ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_4_dis_cent6092 = new TH1F("ptpid_tofw_pos_4_dis_cent6092", "tofw 4 pos ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_6_dis_cent0010 = new TH1F("ptpid_tofw_pos_6_dis_cent0010", "tofw 6 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_6_dis_cent1020 = new TH1F("ptpid_tofw_pos_6_dis_cent1020", "tofw 6 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_6_dis_cent2040 = new TH1F("ptpid_tofw_pos_6_dis_cent2040", "tofw 6 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_6_dis_cent4060 = new TH1F("ptpid_tofw_pos_6_dis_cent4060", "tofw 6 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_6_dis_cent6092 = new TH1F("ptpid_tofw_pos_6_dis_cent6092", "tofw 6 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_8_dis_cent0010 = new TH1F("ptpid_tofw_pos_8_dis_cent0010", "tofw 8 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_8_dis_cent1020 = new TH1F("ptpid_tofw_pos_8_dis_cent1020", "tofw 8 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_8_dis_cent2040 = new TH1F("ptpid_tofw_pos_8_dis_cent2040", "tofw 8 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_8_dis_cent4060 = new TH1F("ptpid_tofw_pos_8_dis_cent4060", "tofw 8 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_8_dis_cent6092 = new TH1F("ptpid_tofw_pos_8_dis_cent6092", "tofw 8 pos pr ", 100, 0.0, 10.0);

  TH1F *ptpid_tofw_neg_0_dis_cent0010 = new TH1F("ptpid_tofw_neg_0_dis_cent0010", "tofw 0 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_0_dis_cent1020 = new TH1F("ptpid_tofw_neg_0_dis_cent1020", "tofw 0 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_0_dis_cent2040 = new TH1F("ptpid_tofw_neg_0_dis_cent2040", "tofw 0 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_0_dis_cent4060 = new TH1F("ptpid_tofw_neg_0_dis_cent4060", "tofw 0 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_0_dis_cent6092 = new TH1F("ptpid_tofw_neg_0_dis_cent6092", "tofw 0 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_2_dis_cent0010 = new TH1F("ptpid_tofw_neg_2_dis_cent0010", "tofw 2 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_2_dis_cent1020 = new TH1F("ptpid_tofw_neg_2_dis_cent1020", "tofw 2 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_2_dis_cent2040 = new TH1F("ptpid_tofw_neg_2_dis_cent2040", "tofw 2 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_2_dis_cent4060 = new TH1F("ptpid_tofw_neg_2_dis_cent4060", "tofw 2 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_2_dis_cent6092 = new TH1F("ptpid_tofw_neg_2_dis_cent6092", "tofw 2 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_4_dis_cent0010 = new TH1F("ptpid_tofw_neg_4_dis_cent0010", "tofw 4 neg ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_4_dis_cent1020 = new TH1F("ptpid_tofw_neg_4_dis_cent1020", "tofw 4 neg ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_4_dis_cent2040 = new TH1F("ptpid_tofw_neg_4_dis_cent2040", "tofw 4 neg ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_4_dis_cent4060 = new TH1F("ptpid_tofw_neg_4_dis_cent4060", "tofw 4 neg ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_4_dis_cent6092 = new TH1F("ptpid_tofw_neg_4_dis_cent6092", "tofw 4 neg ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_6_dis_cent0010 = new TH1F("ptpid_tofw_neg_6_dis_cent0010", "tofw 6 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_6_dis_cent1020 = new TH1F("ptpid_tofw_neg_6_dis_cent1020", "tofw 6 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_6_dis_cent2040 = new TH1F("ptpid_tofw_neg_6_dis_cent2040", "tofw 6 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_6_dis_cent4060 = new TH1F("ptpid_tofw_neg_6_dis_cent4060", "tofw 6 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_6_dis_cent6092 = new TH1F("ptpid_tofw_neg_6_dis_cent6092", "tofw 6 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_8_dis_cent0010 = new TH1F("ptpid_tofw_neg_8_dis_cent0010", "tofw 8 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_8_dis_cent1020 = new TH1F("ptpid_tofw_neg_8_dis_cent1020", "tofw 8 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_8_dis_cent2040 = new TH1F("ptpid_tofw_neg_8_dis_cent2040", "tofw 8 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_8_dis_cent4060 = new TH1F("ptpid_tofw_neg_8_dis_cent4060", "tofw 8 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_8_dis_cent6092 = new TH1F("ptpid_tofw_neg_8_dis_cent6092", "tofw 8 neg pr ", 100, 0.0, 10.0);

  // ----------- //
  // --- end --- //
  // ----------- //



  // ---------------------------- //
  // --- begin pid histograms --- //
  // ---------------------------- //

  TH1F *ptpid_tofw_pos_0_dis = new TH1F("ptpid_tofw_pos_0_dis", "tofw 0 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_1_dis = new TH1F("ptpid_tofw_pos_1_dis", "tofw 1 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_2_dis = new TH1F("ptpid_tofw_pos_2_dis", "tofw 2 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_3_dis = new TH1F("ptpid_tofw_pos_3_dis", "tofw 3 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_4_dis = new TH1F("ptpid_tofw_pos_4_dis", "tofw 4 pos ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_5_dis = new TH1F("ptpid_tofw_pos_5_dis", "tofw 5 pos ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_6_dis = new TH1F("ptpid_tofw_pos_6_dis", "tofw 6 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_7_dis = new TH1F("ptpid_tofw_pos_7_dis", "tofw 7 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_8_dis = new TH1F("ptpid_tofw_pos_8_dis", "tofw 8 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_pos_9_dis = new TH1F("ptpid_tofw_pos_9_dis", "tofw 9 pos pr ", 100, 0.0, 10.0);

  TH1F *ptpid_tofw_neg_0_dis = new TH1F("ptpid_tofw_neg_0_dis", "tofw 0 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_1_dis = new TH1F("ptpid_tofw_neg_1_dis", "tofw 1 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_2_dis = new TH1F("ptpid_tofw_neg_2_dis", "tofw 2 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_3_dis = new TH1F("ptpid_tofw_neg_3_dis", "tofw 3 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_4_dis = new TH1F("ptpid_tofw_neg_4_dis", "tofw 4 neg ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_5_dis = new TH1F("ptpid_tofw_neg_5_dis", "tofw 5 neg ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_6_dis = new TH1F("ptpid_tofw_neg_6_dis", "tofw 6 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_7_dis = new TH1F("ptpid_tofw_neg_7_dis", "tofw 7 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_8_dis = new TH1F("ptpid_tofw_neg_8_dis", "tofw 8 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_neg_9_dis = new TH1F("ptpid_tofw_neg_9_dis", "tofw 9 neg pr ", 100, 0.0, 10.0);

  TH1F *ptpid_tofw_w1_pos_0_dis = new TH1F("ptpid_tofw_w1_pos_0_dis", "tofw w1 0 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_pos_1_dis = new TH1F("ptpid_tofw_w1_pos_1_dis", "tofw w1 1 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_pos_2_dis = new TH1F("ptpid_tofw_w1_pos_2_dis", "tofw w1 2 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_pos_3_dis = new TH1F("ptpid_tofw_w1_pos_3_dis", "tofw w1 3 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_pos_4_dis = new TH1F("ptpid_tofw_w1_pos_4_dis", "tofw w1 4 pos ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_pos_5_dis = new TH1F("ptpid_tofw_w1_pos_5_dis", "tofw w1 5 pos ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_pos_6_dis = new TH1F("ptpid_tofw_w1_pos_6_dis", "tofw w1 6 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_pos_7_dis = new TH1F("ptpid_tofw_w1_pos_7_dis", "tofw w1 7 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_pos_8_dis = new TH1F("ptpid_tofw_w1_pos_8_dis", "tofw w1 8 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_pos_9_dis = new TH1F("ptpid_tofw_w1_pos_9_dis", "tofw w1 9 pos pr ", 100, 0.0, 10.0);

  TH1F *ptpid_tofw_w1_neg_0_dis = new TH1F("ptpid_tofw_w1_neg_0_dis", "tofw w1 0 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_neg_1_dis = new TH1F("ptpid_tofw_w1_neg_1_dis", "tofw w1 1 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_neg_2_dis = new TH1F("ptpid_tofw_w1_neg_2_dis", "tofw w1 2 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_neg_3_dis = new TH1F("ptpid_tofw_w1_neg_3_dis", "tofw w1 3 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_neg_4_dis = new TH1F("ptpid_tofw_w1_neg_4_dis", "tofw w1 4 neg ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_neg_5_dis = new TH1F("ptpid_tofw_w1_neg_5_dis", "tofw w1 5 neg ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_neg_6_dis = new TH1F("ptpid_tofw_w1_neg_6_dis", "tofw w1 6 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_neg_7_dis = new TH1F("ptpid_tofw_w1_neg_7_dis", "tofw w1 7 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_neg_8_dis = new TH1F("ptpid_tofw_w1_neg_8_dis", "tofw w1 8 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w1_neg_9_dis = new TH1F("ptpid_tofw_w1_neg_9_dis", "tofw w1 9 neg pr ", 100, 0.0, 10.0);

  TH1F *ptpid_tofw_w2_pos_0_dis = new TH1F("ptpid_tofw_w2_pos_0_dis", "tofw w2 0 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_pos_1_dis = new TH1F("ptpid_tofw_w2_pos_1_dis", "tofw w2 1 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_pos_2_dis = new TH1F("ptpid_tofw_w2_pos_2_dis", "tofw w2 2 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_pos_3_dis = new TH1F("ptpid_tofw_w2_pos_3_dis", "tofw w2 3 pos pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_pos_4_dis = new TH1F("ptpid_tofw_w2_pos_4_dis", "tofw w2 4 pos ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_pos_5_dis = new TH1F("ptpid_tofw_w2_pos_5_dis", "tofw w2 5 pos ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_pos_6_dis = new TH1F("ptpid_tofw_w2_pos_6_dis", "tofw w2 6 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_pos_7_dis = new TH1F("ptpid_tofw_w2_pos_7_dis", "tofw w2 7 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_pos_8_dis = new TH1F("ptpid_tofw_w2_pos_8_dis", "tofw w2 8 pos pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_pos_9_dis = new TH1F("ptpid_tofw_w2_pos_9_dis", "tofw w2 9 pos pr ", 100, 0.0, 10.0);

  TH1F *ptpid_tofw_w2_neg_0_dis = new TH1F("ptpid_tofw_w2_neg_0_dis", "tofw w2 0 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_neg_1_dis = new TH1F("ptpid_tofw_w2_neg_1_dis", "tofw w2 1 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_neg_2_dis = new TH1F("ptpid_tofw_w2_neg_2_dis", "tofw w2 2 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_neg_3_dis = new TH1F("ptpid_tofw_w2_neg_3_dis", "tofw w2 3 neg pi ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_neg_4_dis = new TH1F("ptpid_tofw_w2_neg_4_dis", "tofw w2 4 neg ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_neg_5_dis = new TH1F("ptpid_tofw_w2_neg_5_dis", "tofw w2 5 neg ka ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_neg_6_dis = new TH1F("ptpid_tofw_w2_neg_6_dis", "tofw w2 6 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_neg_7_dis = new TH1F("ptpid_tofw_w2_neg_7_dis", "tofw w2 7 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_neg_8_dis = new TH1F("ptpid_tofw_w2_neg_8_dis", "tofw w2 8 neg pr ", 100, 0.0, 10.0);
  TH1F *ptpid_tofw_w2_neg_9_dis = new TH1F("ptpid_tofw_w2_neg_9_dis", "tofw w2 9 neg pr ", 100, 0.0, 10.0);


  // --- 1d arrays process way, way faster than 2d arrays (a factor of several hundred times faster)

  // --- tofw both sectors --- //

  TH1F *ptpid_tofw_pos_0_dis_cent[10];
  TH1F *ptpid_tofw_pos_1_dis_cent[10];
  TH1F *ptpid_tofw_pos_2_dis_cent[10];
  TH1F *ptpid_tofw_pos_3_dis_cent[10];
  TH1F *ptpid_tofw_pos_4_dis_cent[10];
  TH1F *ptpid_tofw_pos_5_dis_cent[10];
  TH1F *ptpid_tofw_pos_6_dis_cent[10];
  TH1F *ptpid_tofw_pos_7_dis_cent[10];
  TH1F *ptpid_tofw_pos_8_dis_cent[10];
  TH1F *ptpid_tofw_pos_9_dis_cent[10];

  TH1F *ptpid_tofw_neg_0_dis_cent[10];
  TH1F *ptpid_tofw_neg_1_dis_cent[10];
  TH1F *ptpid_tofw_neg_2_dis_cent[10];
  TH1F *ptpid_tofw_neg_3_dis_cent[10];
  TH1F *ptpid_tofw_neg_4_dis_cent[10];
  TH1F *ptpid_tofw_neg_5_dis_cent[10];
  TH1F *ptpid_tofw_neg_6_dis_cent[10];
  TH1F *ptpid_tofw_neg_7_dis_cent[10];
  TH1F *ptpid_tofw_neg_8_dis_cent[10];
  TH1F *ptpid_tofw_neg_9_dis_cent[10];

  char name_ptpid_tofw_pos_0_dis_cent[30];
  char name_ptpid_tofw_pos_1_dis_cent[30];
  char name_ptpid_tofw_pos_2_dis_cent[30];
  char name_ptpid_tofw_pos_3_dis_cent[30];
  char name_ptpid_tofw_pos_4_dis_cent[30];
  char name_ptpid_tofw_pos_5_dis_cent[30];
  char name_ptpid_tofw_pos_6_dis_cent[30];
  char name_ptpid_tofw_pos_7_dis_cent[30];
  char name_ptpid_tofw_pos_8_dis_cent[30];
  char name_ptpid_tofw_pos_9_dis_cent[30];

  char name_ptpid_tofw_neg_0_dis_cent[30];
  char name_ptpid_tofw_neg_1_dis_cent[30];
  char name_ptpid_tofw_neg_2_dis_cent[30];
  char name_ptpid_tofw_neg_3_dis_cent[30];
  char name_ptpid_tofw_neg_4_dis_cent[30];
  char name_ptpid_tofw_neg_5_dis_cent[30];
  char name_ptpid_tofw_neg_6_dis_cent[30];
  char name_ptpid_tofw_neg_7_dis_cent[30];
  char name_ptpid_tofw_neg_8_dis_cent[30];
  char name_ptpid_tofw_neg_9_dis_cent[30];

  for(int i=0; i<9; i++)
    {
      sprintf(name_ptpid_tofw_pos_0_dis_cent,"ptpid_tofw_pos_0_dis_cent_%d",i);
      ptpid_tofw_pos_0_dis_cent[i] = new TH1F(name_ptpid_tofw_pos_0_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_pos_1_dis_cent,"ptpid_tofw_pos_1_dis_cent_%d",i);
      ptpid_tofw_pos_1_dis_cent[i] = new TH1F(name_ptpid_tofw_pos_1_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_pos_2_dis_cent,"ptpid_tofw_pos_2_dis_cent_%d",i);
      ptpid_tofw_pos_2_dis_cent[i] = new TH1F(name_ptpid_tofw_pos_2_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_pos_3_dis_cent,"ptpid_tofw_pos_3_dis_cent_%d",i);
      ptpid_tofw_pos_3_dis_cent[i] = new TH1F(name_ptpid_tofw_pos_3_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_pos_4_dis_cent,"ptpid_tofw_pos_4_dis_cent_%d",i);
      ptpid_tofw_pos_4_dis_cent[i] = new TH1F(name_ptpid_tofw_pos_4_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_pos_5_dis_cent,"ptpid_tofw_pos_5_dis_cent_%d",i);
      ptpid_tofw_pos_5_dis_cent[i] = new TH1F(name_ptpid_tofw_pos_5_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_pos_6_dis_cent,"ptpid_tofw_pos_6_dis_cent_%d",i);
      ptpid_tofw_pos_6_dis_cent[i] = new TH1F(name_ptpid_tofw_pos_6_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_pos_7_dis_cent,"ptpid_tofw_pos_7_dis_cent_%d",i);
      ptpid_tofw_pos_7_dis_cent[i] = new TH1F(name_ptpid_tofw_pos_7_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_pos_8_dis_cent,"ptpid_tofw_pos_8_dis_cent_%d",i);
      ptpid_tofw_pos_8_dis_cent[i] = new TH1F(name_ptpid_tofw_pos_8_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_pos_9_dis_cent,"ptpid_tofw_pos_9_dis_cent_%d",i);
      ptpid_tofw_pos_9_dis_cent[i] = new TH1F(name_ptpid_tofw_pos_9_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_neg_0_dis_cent,"ptpid_tofw_neg_0_dis_cent_%d",i);
      ptpid_tofw_neg_0_dis_cent[i] = new TH1F(name_ptpid_tofw_neg_0_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_neg_1_dis_cent,"ptpid_tofw_neg_1_dis_cent_%d",i);
      ptpid_tofw_neg_1_dis_cent[i] = new TH1F(name_ptpid_tofw_neg_1_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_neg_2_dis_cent,"ptpid_tofw_neg_2_dis_cent_%d",i);
      ptpid_tofw_neg_2_dis_cent[i] = new TH1F(name_ptpid_tofw_neg_2_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_neg_3_dis_cent,"ptpid_tofw_neg_3_dis_cent_%d",i);
      ptpid_tofw_neg_3_dis_cent[i] = new TH1F(name_ptpid_tofw_neg_3_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_neg_4_dis_cent,"ptpid_tofw_neg_4_dis_cent_%d",i);
      ptpid_tofw_neg_4_dis_cent[i] = new TH1F(name_ptpid_tofw_neg_4_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_neg_5_dis_cent,"ptpid_tofw_neg_5_dis_cent_%d",i);
      ptpid_tofw_neg_5_dis_cent[i] = new TH1F(name_ptpid_tofw_neg_5_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_neg_6_dis_cent,"ptpid_tofw_neg_6_dis_cent_%d",i);
      ptpid_tofw_neg_6_dis_cent[i] = new TH1F(name_ptpid_tofw_neg_6_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_neg_7_dis_cent,"ptpid_tofw_neg_7_dis_cent_%d",i);
      ptpid_tofw_neg_7_dis_cent[i] = new TH1F(name_ptpid_tofw_neg_7_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_neg_8_dis_cent,"ptpid_tofw_neg_8_dis_cent_%d",i);
      ptpid_tofw_neg_8_dis_cent[i] = new TH1F(name_ptpid_tofw_neg_8_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_neg_9_dis_cent,"ptpid_tofw_neg_9_dis_cent_%d",i);
      ptpid_tofw_neg_9_dis_cent[i] = new TH1F(name_ptpid_tofw_neg_9_dis_cent, "...", 100, 0, 10.0);
    }

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
      ptpid_tofw_w1_pos_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_0_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_pos_1_dis_cent,"ptpid_tofw_w1_pos_1_dis_cent_%d",i);
      ptpid_tofw_w1_pos_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_1_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_pos_2_dis_cent,"ptpid_tofw_w1_pos_2_dis_cent_%d",i);
      ptpid_tofw_w1_pos_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_2_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_pos_3_dis_cent,"ptpid_tofw_w1_pos_3_dis_cent_%d",i);
      ptpid_tofw_w1_pos_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_3_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_pos_4_dis_cent,"ptpid_tofw_w1_pos_4_dis_cent_%d",i);
      ptpid_tofw_w1_pos_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_4_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_pos_5_dis_cent,"ptpid_tofw_w1_pos_5_dis_cent_%d",i);
      ptpid_tofw_w1_pos_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_5_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_pos_6_dis_cent,"ptpid_tofw_w1_pos_6_dis_cent_%d",i);
      ptpid_tofw_w1_pos_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_6_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_pos_7_dis_cent,"ptpid_tofw_w1_pos_7_dis_cent_%d",i);
      ptpid_tofw_w1_pos_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_7_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_pos_8_dis_cent,"ptpid_tofw_w1_pos_8_dis_cent_%d",i);
      ptpid_tofw_w1_pos_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_8_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_pos_9_dis_cent,"ptpid_tofw_w1_pos_9_dis_cent_%d",i);
      ptpid_tofw_w1_pos_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_9_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_neg_0_dis_cent,"ptpid_tofw_w1_neg_0_dis_cent_%d",i);
      ptpid_tofw_w1_neg_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_0_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_neg_1_dis_cent,"ptpid_tofw_w1_neg_1_dis_cent_%d",i);
      ptpid_tofw_w1_neg_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_1_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_neg_2_dis_cent,"ptpid_tofw_w1_neg_2_dis_cent_%d",i);
      ptpid_tofw_w1_neg_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_2_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_neg_3_dis_cent,"ptpid_tofw_w1_neg_3_dis_cent_%d",i);
      ptpid_tofw_w1_neg_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_3_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_neg_4_dis_cent,"ptpid_tofw_w1_neg_4_dis_cent_%d",i);
      ptpid_tofw_w1_neg_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_4_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_neg_5_dis_cent,"ptpid_tofw_w1_neg_5_dis_cent_%d",i);
      ptpid_tofw_w1_neg_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_5_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_neg_6_dis_cent,"ptpid_tofw_w1_neg_6_dis_cent_%d",i);
      ptpid_tofw_w1_neg_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_6_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_neg_7_dis_cent,"ptpid_tofw_w1_neg_7_dis_cent_%d",i);
      ptpid_tofw_w1_neg_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_7_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_neg_8_dis_cent,"ptpid_tofw_w1_neg_8_dis_cent_%d",i);
      ptpid_tofw_w1_neg_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_8_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w1_neg_9_dis_cent,"ptpid_tofw_w1_neg_9_dis_cent_%d",i);
      ptpid_tofw_w1_neg_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_9_dis_cent, "...", 100, 0, 10.0);
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
      ptpid_tofw_w2_pos_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_0_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_pos_1_dis_cent,"ptpid_tofw_w2_pos_1_dis_cent_%d",i);
      ptpid_tofw_w2_pos_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_1_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_pos_2_dis_cent,"ptpid_tofw_w2_pos_2_dis_cent_%d",i);
      ptpid_tofw_w2_pos_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_2_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_pos_3_dis_cent,"ptpid_tofw_w2_pos_3_dis_cent_%d",i);
      ptpid_tofw_w2_pos_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_3_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_pos_4_dis_cent,"ptpid_tofw_w2_pos_4_dis_cent_%d",i);
      ptpid_tofw_w2_pos_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_4_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_pos_5_dis_cent,"ptpid_tofw_w2_pos_5_dis_cent_%d",i);
      ptpid_tofw_w2_pos_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_5_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_pos_6_dis_cent,"ptpid_tofw_w2_pos_6_dis_cent_%d",i);
      ptpid_tofw_w2_pos_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_6_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_pos_7_dis_cent,"ptpid_tofw_w2_pos_7_dis_cent_%d",i);
      ptpid_tofw_w2_pos_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_7_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_pos_8_dis_cent,"ptpid_tofw_w2_pos_8_dis_cent_%d",i);
      ptpid_tofw_w2_pos_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_8_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_pos_9_dis_cent,"ptpid_tofw_w2_pos_9_dis_cent_%d",i);
      ptpid_tofw_w2_pos_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_9_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_neg_0_dis_cent,"ptpid_tofw_w2_neg_0_dis_cent_%d",i);
      ptpid_tofw_w2_neg_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_0_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_neg_1_dis_cent,"ptpid_tofw_w2_neg_1_dis_cent_%d",i);
      ptpid_tofw_w2_neg_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_1_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_neg_2_dis_cent,"ptpid_tofw_w2_neg_2_dis_cent_%d",i);
      ptpid_tofw_w2_neg_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_2_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_neg_3_dis_cent,"ptpid_tofw_w2_neg_3_dis_cent_%d",i);
      ptpid_tofw_w2_neg_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_3_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_neg_4_dis_cent,"ptpid_tofw_w2_neg_4_dis_cent_%d",i);
      ptpid_tofw_w2_neg_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_4_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_neg_5_dis_cent,"ptpid_tofw_w2_neg_5_dis_cent_%d",i);
      ptpid_tofw_w2_neg_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_5_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_neg_6_dis_cent,"ptpid_tofw_w2_neg_6_dis_cent_%d",i);
      ptpid_tofw_w2_neg_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_6_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_neg_7_dis_cent,"ptpid_tofw_w2_neg_7_dis_cent_%d",i);
      ptpid_tofw_w2_neg_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_7_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_neg_8_dis_cent,"ptpid_tofw_w2_neg_8_dis_cent_%d",i);
      ptpid_tofw_w2_neg_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_8_dis_cent, "...", 100, 0, 10.0);
      sprintf(name_ptpid_tofw_w2_neg_9_dis_cent,"ptpid_tofw_w2_neg_9_dis_cent_%d",i);
      ptpid_tofw_w2_neg_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_9_dis_cent, "...", 100, 0, 10.0);
    }

  // end pid histograms


  // ---------------------------- //
  // ---- end pid histograms ---- //
  // ---------------------------- //







  // ------------------------------------------ //
  // --- begin extra special pid histograms --- //
  // ------------------------------------------ //

  // --- pion

  TH1F *hhptpid_tofw_pospion_0_dis_cent0010 = new TH1F("hhptpid_tofw_pospion_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_0_dis_cent1020 = new TH1F("hhptpid_tofw_pospion_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_0_dis_cent2040 = new TH1F("hhptpid_tofw_pospion_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_0_dis_cent4060 = new TH1F("hhptpid_tofw_pospion_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_0_dis_cent6092 = new TH1F("hhptpid_tofw_pospion_0_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_0_dis_cent0010 = new TH1F("hhptpid_tofw_negpion_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_0_dis_cent1020 = new TH1F("hhptpid_tofw_negpion_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_0_dis_cent2040 = new TH1F("hhptpid_tofw_negpion_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_0_dis_cent4060 = new TH1F("hhptpid_tofw_negpion_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_0_dis_cent6092 = new TH1F("hhptpid_tofw_negpion_0_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_0_dis_cent0010 = new TH1F("hhptpid_tfec_pospion_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_0_dis_cent1020 = new TH1F("hhptpid_tfec_pospion_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_0_dis_cent2040 = new TH1F("hhptpid_tfec_pospion_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_0_dis_cent4060 = new TH1F("hhptpid_tfec_pospion_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_0_dis_cent6092 = new TH1F("hhptpid_tfec_pospion_0_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_0_dis_cent0010 = new TH1F("hhptpid_tfec_negpion_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_0_dis_cent1020 = new TH1F("hhptpid_tfec_negpion_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_0_dis_cent2040 = new TH1F("hhptpid_tfec_negpion_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_0_dis_cent4060 = new TH1F("hhptpid_tfec_negpion_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_0_dis_cent6092 = new TH1F("hhptpid_tfec_negpion_0_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *hhptpid_tofw_pospion_1_dis_cent0010 = new TH1F("hhptpid_tofw_pospion_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_1_dis_cent1020 = new TH1F("hhptpid_tofw_pospion_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_1_dis_cent2040 = new TH1F("hhptpid_tofw_pospion_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_1_dis_cent4060 = new TH1F("hhptpid_tofw_pospion_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_1_dis_cent6092 = new TH1F("hhptpid_tofw_pospion_1_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_1_dis_cent0010 = new TH1F("hhptpid_tofw_negpion_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_1_dis_cent1020 = new TH1F("hhptpid_tofw_negpion_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_1_dis_cent2040 = new TH1F("hhptpid_tofw_negpion_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_1_dis_cent4060 = new TH1F("hhptpid_tofw_negpion_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_1_dis_cent6092 = new TH1F("hhptpid_tofw_negpion_1_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_1_dis_cent0010 = new TH1F("hhptpid_tfec_pospion_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_1_dis_cent1020 = new TH1F("hhptpid_tfec_pospion_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_1_dis_cent2040 = new TH1F("hhptpid_tfec_pospion_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_1_dis_cent4060 = new TH1F("hhptpid_tfec_pospion_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_1_dis_cent6092 = new TH1F("hhptpid_tfec_pospion_1_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_1_dis_cent0010 = new TH1F("hhptpid_tfec_negpion_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_1_dis_cent1020 = new TH1F("hhptpid_tfec_negpion_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_1_dis_cent2040 = new TH1F("hhptpid_tfec_negpion_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_1_dis_cent4060 = new TH1F("hhptpid_tfec_negpion_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_1_dis_cent6092 = new TH1F("hhptpid_tfec_negpion_1_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *hhptpid_tofw_pospion_2_dis_cent0010 = new TH1F("hhptpid_tofw_pospion_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_2_dis_cent1020 = new TH1F("hhptpid_tofw_pospion_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_2_dis_cent2040 = new TH1F("hhptpid_tofw_pospion_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_2_dis_cent4060 = new TH1F("hhptpid_tofw_pospion_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_2_dis_cent6092 = new TH1F("hhptpid_tofw_pospion_2_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_2_dis_cent0010 = new TH1F("hhptpid_tofw_negpion_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_2_dis_cent1020 = new TH1F("hhptpid_tofw_negpion_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_2_dis_cent2040 = new TH1F("hhptpid_tofw_negpion_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_2_dis_cent4060 = new TH1F("hhptpid_tofw_negpion_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_2_dis_cent6092 = new TH1F("hhptpid_tofw_negpion_2_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_2_dis_cent0010 = new TH1F("hhptpid_tfec_pospion_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_2_dis_cent1020 = new TH1F("hhptpid_tfec_pospion_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_2_dis_cent2040 = new TH1F("hhptpid_tfec_pospion_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_2_dis_cent4060 = new TH1F("hhptpid_tfec_pospion_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_2_dis_cent6092 = new TH1F("hhptpid_tfec_pospion_2_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_2_dis_cent0010 = new TH1F("hhptpid_tfec_negpion_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_2_dis_cent1020 = new TH1F("hhptpid_tfec_negpion_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_2_dis_cent2040 = new TH1F("hhptpid_tfec_negpion_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_2_dis_cent4060 = new TH1F("hhptpid_tfec_negpion_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_2_dis_cent6092 = new TH1F("hhptpid_tfec_negpion_2_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *hhptpid_tofw_pospion_3_dis_cent0010 = new TH1F("hhptpid_tofw_pospion_3_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_3_dis_cent1020 = new TH1F("hhptpid_tofw_pospion_3_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_3_dis_cent2040 = new TH1F("hhptpid_tofw_pospion_3_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_3_dis_cent4060 = new TH1F("hhptpid_tofw_pospion_3_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_3_dis_cent6092 = new TH1F("hhptpid_tofw_pospion_3_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_3_dis_cent0010 = new TH1F("hhptpid_tofw_negpion_3_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_3_dis_cent1020 = new TH1F("hhptpid_tofw_negpion_3_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_3_dis_cent2040 = new TH1F("hhptpid_tofw_negpion_3_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_3_dis_cent4060 = new TH1F("hhptpid_tofw_negpion_3_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_3_dis_cent6092 = new TH1F("hhptpid_tofw_negpion_3_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_3_dis_cent0010 = new TH1F("hhptpid_tfec_pospion_3_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_3_dis_cent1020 = new TH1F("hhptpid_tfec_pospion_3_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_3_dis_cent2040 = new TH1F("hhptpid_tfec_pospion_3_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_3_dis_cent4060 = new TH1F("hhptpid_tfec_pospion_3_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_3_dis_cent6092 = new TH1F("hhptpid_tfec_pospion_3_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_3_dis_cent0010 = new TH1F("hhptpid_tfec_negpion_3_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_3_dis_cent1020 = new TH1F("hhptpid_tfec_negpion_3_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_3_dis_cent2040 = new TH1F("hhptpid_tfec_negpion_3_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_3_dis_cent4060 = new TH1F("hhptpid_tfec_negpion_3_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_3_dis_cent6092 = new TH1F("hhptpid_tfec_negpion_3_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *hhptpid_tofw_pospion_4_dis_cent0010 = new TH1F("hhptpid_tofw_pospion_4_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_4_dis_cent1020 = new TH1F("hhptpid_tofw_pospion_4_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_4_dis_cent2040 = new TH1F("hhptpid_tofw_pospion_4_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_4_dis_cent4060 = new TH1F("hhptpid_tofw_pospion_4_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_4_dis_cent6092 = new TH1F("hhptpid_tofw_pospion_4_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_4_dis_cent0010 = new TH1F("hhptpid_tofw_negpion_4_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_4_dis_cent1020 = new TH1F("hhptpid_tofw_negpion_4_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_4_dis_cent2040 = new TH1F("hhptpid_tofw_negpion_4_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_4_dis_cent4060 = new TH1F("hhptpid_tofw_negpion_4_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_4_dis_cent6092 = new TH1F("hhptpid_tofw_negpion_4_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_4_dis_cent0010 = new TH1F("hhptpid_tfec_pospion_4_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_4_dis_cent1020 = new TH1F("hhptpid_tfec_pospion_4_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_4_dis_cent2040 = new TH1F("hhptpid_tfec_pospion_4_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_4_dis_cent4060 = new TH1F("hhptpid_tfec_pospion_4_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_4_dis_cent6092 = new TH1F("hhptpid_tfec_pospion_4_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_4_dis_cent0010 = new TH1F("hhptpid_tfec_negpion_4_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_4_dis_cent1020 = new TH1F("hhptpid_tfec_negpion_4_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_4_dis_cent2040 = new TH1F("hhptpid_tfec_negpion_4_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_4_dis_cent4060 = new TH1F("hhptpid_tfec_negpion_4_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_4_dis_cent6092 = new TH1F("hhptpid_tfec_negpion_4_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *hhptpid_tofw_pospion_5_dis_cent0010 = new TH1F("hhptpid_tofw_pospion_5_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_5_dis_cent1020 = new TH1F("hhptpid_tofw_pospion_5_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_5_dis_cent2040 = new TH1F("hhptpid_tofw_pospion_5_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_5_dis_cent4060 = new TH1F("hhptpid_tofw_pospion_5_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_pospion_5_dis_cent6092 = new TH1F("hhptpid_tofw_pospion_5_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_5_dis_cent0010 = new TH1F("hhptpid_tofw_negpion_5_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_5_dis_cent1020 = new TH1F("hhptpid_tofw_negpion_5_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_5_dis_cent2040 = new TH1F("hhptpid_tofw_negpion_5_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_5_dis_cent4060 = new TH1F("hhptpid_tofw_negpion_5_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negpion_5_dis_cent6092 = new TH1F("hhptpid_tofw_negpion_5_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_5_dis_cent0010 = new TH1F("hhptpid_tfec_pospion_5_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_5_dis_cent1020 = new TH1F("hhptpid_tfec_pospion_5_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_5_dis_cent2040 = new TH1F("hhptpid_tfec_pospion_5_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_5_dis_cent4060 = new TH1F("hhptpid_tfec_pospion_5_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_pospion_5_dis_cent6092 = new TH1F("hhptpid_tfec_pospion_5_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_5_dis_cent0010 = new TH1F("hhptpid_tfec_negpion_5_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_5_dis_cent1020 = new TH1F("hhptpid_tfec_negpion_5_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_5_dis_cent2040 = new TH1F("hhptpid_tfec_negpion_5_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_5_dis_cent4060 = new TH1F("hhptpid_tfec_negpion_5_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negpion_5_dis_cent6092 = new TH1F("hhptpid_tfec_negpion_5_dis_cent6092", "...", 100, 0.0, 10.0);

  // --- kaon

  TH1F *hhptpid_tofw_poskaon_0_dis_cent0010 = new TH1F("hhptpid_tofw_poskaon_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_0_dis_cent1020 = new TH1F("hhptpid_tofw_poskaon_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_0_dis_cent2040 = new TH1F("hhptpid_tofw_poskaon_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_0_dis_cent4060 = new TH1F("hhptpid_tofw_poskaon_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_0_dis_cent6092 = new TH1F("hhptpid_tofw_poskaon_0_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_0_dis_cent0010 = new TH1F("hhptpid_tofw_negkaon_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_0_dis_cent1020 = new TH1F("hhptpid_tofw_negkaon_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_0_dis_cent2040 = new TH1F("hhptpid_tofw_negkaon_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_0_dis_cent4060 = new TH1F("hhptpid_tofw_negkaon_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_0_dis_cent6092 = new TH1F("hhptpid_tofw_negkaon_0_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_0_dis_cent0010 = new TH1F("hhptpid_tfec_poskaon_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_0_dis_cent1020 = new TH1F("hhptpid_tfec_poskaon_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_0_dis_cent2040 = new TH1F("hhptpid_tfec_poskaon_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_0_dis_cent4060 = new TH1F("hhptpid_tfec_poskaon_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_0_dis_cent6092 = new TH1F("hhptpid_tfec_poskaon_0_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_0_dis_cent0010 = new TH1F("hhptpid_tfec_negkaon_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_0_dis_cent1020 = new TH1F("hhptpid_tfec_negkaon_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_0_dis_cent2040 = new TH1F("hhptpid_tfec_negkaon_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_0_dis_cent4060 = new TH1F("hhptpid_tfec_negkaon_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_0_dis_cent6092 = new TH1F("hhptpid_tfec_negkaon_0_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *hhptpid_tofw_poskaon_1_dis_cent0010 = new TH1F("hhptpid_tofw_poskaon_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_1_dis_cent1020 = new TH1F("hhptpid_tofw_poskaon_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_1_dis_cent2040 = new TH1F("hhptpid_tofw_poskaon_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_1_dis_cent4060 = new TH1F("hhptpid_tofw_poskaon_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_1_dis_cent6092 = new TH1F("hhptpid_tofw_poskaon_1_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_1_dis_cent0010 = new TH1F("hhptpid_tofw_negkaon_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_1_dis_cent1020 = new TH1F("hhptpid_tofw_negkaon_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_1_dis_cent2040 = new TH1F("hhptpid_tofw_negkaon_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_1_dis_cent4060 = new TH1F("hhptpid_tofw_negkaon_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_1_dis_cent6092 = new TH1F("hhptpid_tofw_negkaon_1_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_1_dis_cent0010 = new TH1F("hhptpid_tfec_poskaon_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_1_dis_cent1020 = new TH1F("hhptpid_tfec_poskaon_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_1_dis_cent2040 = new TH1F("hhptpid_tfec_poskaon_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_1_dis_cent4060 = new TH1F("hhptpid_tfec_poskaon_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_1_dis_cent6092 = new TH1F("hhptpid_tfec_poskaon_1_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_1_dis_cent0010 = new TH1F("hhptpid_tfec_negkaon_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_1_dis_cent1020 = new TH1F("hhptpid_tfec_negkaon_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_1_dis_cent2040 = new TH1F("hhptpid_tfec_negkaon_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_1_dis_cent4060 = new TH1F("hhptpid_tfec_negkaon_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_1_dis_cent6092 = new TH1F("hhptpid_tfec_negkaon_1_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *hhptpid_tofw_poskaon_2_dis_cent0010 = new TH1F("hhptpid_tofw_poskaon_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_2_dis_cent1020 = new TH1F("hhptpid_tofw_poskaon_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_2_dis_cent2040 = new TH1F("hhptpid_tofw_poskaon_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_2_dis_cent4060 = new TH1F("hhptpid_tofw_poskaon_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_2_dis_cent6092 = new TH1F("hhptpid_tofw_poskaon_2_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_2_dis_cent0010 = new TH1F("hhptpid_tofw_negkaon_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_2_dis_cent1020 = new TH1F("hhptpid_tofw_negkaon_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_2_dis_cent2040 = new TH1F("hhptpid_tofw_negkaon_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_2_dis_cent4060 = new TH1F("hhptpid_tofw_negkaon_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_2_dis_cent6092 = new TH1F("hhptpid_tofw_negkaon_2_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_2_dis_cent0010 = new TH1F("hhptpid_tfec_poskaon_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_2_dis_cent1020 = new TH1F("hhptpid_tfec_poskaon_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_2_dis_cent2040 = new TH1F("hhptpid_tfec_poskaon_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_2_dis_cent4060 = new TH1F("hhptpid_tfec_poskaon_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_2_dis_cent6092 = new TH1F("hhptpid_tfec_poskaon_2_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_2_dis_cent0010 = new TH1F("hhptpid_tfec_negkaon_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_2_dis_cent1020 = new TH1F("hhptpid_tfec_negkaon_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_2_dis_cent2040 = new TH1F("hhptpid_tfec_negkaon_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_2_dis_cent4060 = new TH1F("hhptpid_tfec_negkaon_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_2_dis_cent6092 = new TH1F("hhptpid_tfec_negkaon_2_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *hhptpid_tofw_poskaon_3_dis_cent0010 = new TH1F("hhptpid_tofw_poskaon_3_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_3_dis_cent1020 = new TH1F("hhptpid_tofw_poskaon_3_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_3_dis_cent2040 = new TH1F("hhptpid_tofw_poskaon_3_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_3_dis_cent4060 = new TH1F("hhptpid_tofw_poskaon_3_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_3_dis_cent6092 = new TH1F("hhptpid_tofw_poskaon_3_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_3_dis_cent0010 = new TH1F("hhptpid_tofw_negkaon_3_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_3_dis_cent1020 = new TH1F("hhptpid_tofw_negkaon_3_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_3_dis_cent2040 = new TH1F("hhptpid_tofw_negkaon_3_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_3_dis_cent4060 = new TH1F("hhptpid_tofw_negkaon_3_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_3_dis_cent6092 = new TH1F("hhptpid_tofw_negkaon_3_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_3_dis_cent0010 = new TH1F("hhptpid_tfec_poskaon_3_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_3_dis_cent1020 = new TH1F("hhptpid_tfec_poskaon_3_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_3_dis_cent2040 = new TH1F("hhptpid_tfec_poskaon_3_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_3_dis_cent4060 = new TH1F("hhptpid_tfec_poskaon_3_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_3_dis_cent6092 = new TH1F("hhptpid_tfec_poskaon_3_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_3_dis_cent0010 = new TH1F("hhptpid_tfec_negkaon_3_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_3_dis_cent1020 = new TH1F("hhptpid_tfec_negkaon_3_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_3_dis_cent2040 = new TH1F("hhptpid_tfec_negkaon_3_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_3_dis_cent4060 = new TH1F("hhptpid_tfec_negkaon_3_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_3_dis_cent6092 = new TH1F("hhptpid_tfec_negkaon_3_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *hhptpid_tofw_poskaon_4_dis_cent0010 = new TH1F("hhptpid_tofw_poskaon_4_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_4_dis_cent1020 = new TH1F("hhptpid_tofw_poskaon_4_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_4_dis_cent2040 = new TH1F("hhptpid_tofw_poskaon_4_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_4_dis_cent4060 = new TH1F("hhptpid_tofw_poskaon_4_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_4_dis_cent6092 = new TH1F("hhptpid_tofw_poskaon_4_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_4_dis_cent0010 = new TH1F("hhptpid_tofw_negkaon_4_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_4_dis_cent1020 = new TH1F("hhptpid_tofw_negkaon_4_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_4_dis_cent2040 = new TH1F("hhptpid_tofw_negkaon_4_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_4_dis_cent4060 = new TH1F("hhptpid_tofw_negkaon_4_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_4_dis_cent6092 = new TH1F("hhptpid_tofw_negkaon_4_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_4_dis_cent0010 = new TH1F("hhptpid_tfec_poskaon_4_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_4_dis_cent1020 = new TH1F("hhptpid_tfec_poskaon_4_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_4_dis_cent2040 = new TH1F("hhptpid_tfec_poskaon_4_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_4_dis_cent4060 = new TH1F("hhptpid_tfec_poskaon_4_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_4_dis_cent6092 = new TH1F("hhptpid_tfec_poskaon_4_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_4_dis_cent0010 = new TH1F("hhptpid_tfec_negkaon_4_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_4_dis_cent1020 = new TH1F("hhptpid_tfec_negkaon_4_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_4_dis_cent2040 = new TH1F("hhptpid_tfec_negkaon_4_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_4_dis_cent4060 = new TH1F("hhptpid_tfec_negkaon_4_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_4_dis_cent6092 = new TH1F("hhptpid_tfec_negkaon_4_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *hhptpid_tofw_poskaon_5_dis_cent0010 = new TH1F("hhptpid_tofw_poskaon_5_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_5_dis_cent1020 = new TH1F("hhptpid_tofw_poskaon_5_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_5_dis_cent2040 = new TH1F("hhptpid_tofw_poskaon_5_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_5_dis_cent4060 = new TH1F("hhptpid_tofw_poskaon_5_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_poskaon_5_dis_cent6092 = new TH1F("hhptpid_tofw_poskaon_5_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_5_dis_cent0010 = new TH1F("hhptpid_tofw_negkaon_5_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_5_dis_cent1020 = new TH1F("hhptpid_tofw_negkaon_5_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_5_dis_cent2040 = new TH1F("hhptpid_tofw_negkaon_5_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_5_dis_cent4060 = new TH1F("hhptpid_tofw_negkaon_5_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negkaon_5_dis_cent6092 = new TH1F("hhptpid_tofw_negkaon_5_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_5_dis_cent0010 = new TH1F("hhptpid_tfec_poskaon_5_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_5_dis_cent1020 = new TH1F("hhptpid_tfec_poskaon_5_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_5_dis_cent2040 = new TH1F("hhptpid_tfec_poskaon_5_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_5_dis_cent4060 = new TH1F("hhptpid_tfec_poskaon_5_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_poskaon_5_dis_cent6092 = new TH1F("hhptpid_tfec_poskaon_5_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_5_dis_cent0010 = new TH1F("hhptpid_tfec_negkaon_5_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_5_dis_cent1020 = new TH1F("hhptpid_tfec_negkaon_5_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_5_dis_cent2040 = new TH1F("hhptpid_tfec_negkaon_5_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_5_dis_cent4060 = new TH1F("hhptpid_tfec_negkaon_5_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negkaon_5_dis_cent6092 = new TH1F("hhptpid_tfec_negkaon_5_dis_cent6092", "...", 100, 0.0, 10.0);

  // --- proton

  TH1F *hhptpid_tofw_posproton_0_dis_cent0010 = new TH1F("hhptpid_tofw_posproton_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_0_dis_cent1020 = new TH1F("hhptpid_tofw_posproton_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_0_dis_cent2040 = new TH1F("hhptpid_tofw_posproton_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_0_dis_cent4060 = new TH1F("hhptpid_tofw_posproton_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_0_dis_cent6092 = new TH1F("hhptpid_tofw_posproton_0_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_0_dis_cent0010 = new TH1F("hhptpid_tofw_negproton_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_0_dis_cent1020 = new TH1F("hhptpid_tofw_negproton_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_0_dis_cent2040 = new TH1F("hhptpid_tofw_negproton_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_0_dis_cent4060 = new TH1F("hhptpid_tofw_negproton_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_0_dis_cent6092 = new TH1F("hhptpid_tofw_negproton_0_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_0_dis_cent0010 = new TH1F("hhptpid_tfec_posproton_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_0_dis_cent1020 = new TH1F("hhptpid_tfec_posproton_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_0_dis_cent2040 = new TH1F("hhptpid_tfec_posproton_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_0_dis_cent4060 = new TH1F("hhptpid_tfec_posproton_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_0_dis_cent6092 = new TH1F("hhptpid_tfec_posproton_0_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_0_dis_cent0010 = new TH1F("hhptpid_tfec_negproton_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_0_dis_cent1020 = new TH1F("hhptpid_tfec_negproton_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_0_dis_cent2040 = new TH1F("hhptpid_tfec_negproton_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_0_dis_cent4060 = new TH1F("hhptpid_tfec_negproton_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_0_dis_cent6092 = new TH1F("hhptpid_tfec_negproton_0_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *hhptpid_tofw_posproton_1_dis_cent0010 = new TH1F("hhptpid_tofw_posproton_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_1_dis_cent1020 = new TH1F("hhptpid_tofw_posproton_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_1_dis_cent2040 = new TH1F("hhptpid_tofw_posproton_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_1_dis_cent4060 = new TH1F("hhptpid_tofw_posproton_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_1_dis_cent6092 = new TH1F("hhptpid_tofw_posproton_1_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_1_dis_cent0010 = new TH1F("hhptpid_tofw_negproton_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_1_dis_cent1020 = new TH1F("hhptpid_tofw_negproton_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_1_dis_cent2040 = new TH1F("hhptpid_tofw_negproton_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_1_dis_cent4060 = new TH1F("hhptpid_tofw_negproton_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_1_dis_cent6092 = new TH1F("hhptpid_tofw_negproton_1_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_1_dis_cent0010 = new TH1F("hhptpid_tfec_posproton_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_1_dis_cent1020 = new TH1F("hhptpid_tfec_posproton_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_1_dis_cent2040 = new TH1F("hhptpid_tfec_posproton_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_1_dis_cent4060 = new TH1F("hhptpid_tfec_posproton_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_1_dis_cent6092 = new TH1F("hhptpid_tfec_posproton_1_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_1_dis_cent0010 = new TH1F("hhptpid_tfec_negproton_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_1_dis_cent1020 = new TH1F("hhptpid_tfec_negproton_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_1_dis_cent2040 = new TH1F("hhptpid_tfec_negproton_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_1_dis_cent4060 = new TH1F("hhptpid_tfec_negproton_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_1_dis_cent6092 = new TH1F("hhptpid_tfec_negproton_1_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *hhptpid_tofw_posproton_2_dis_cent0010 = new TH1F("hhptpid_tofw_posproton_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_2_dis_cent1020 = new TH1F("hhptpid_tofw_posproton_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_2_dis_cent2040 = new TH1F("hhptpid_tofw_posproton_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_2_dis_cent4060 = new TH1F("hhptpid_tofw_posproton_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_2_dis_cent6092 = new TH1F("hhptpid_tofw_posproton_2_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_2_dis_cent0010 = new TH1F("hhptpid_tofw_negproton_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_2_dis_cent1020 = new TH1F("hhptpid_tofw_negproton_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_2_dis_cent2040 = new TH1F("hhptpid_tofw_negproton_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_2_dis_cent4060 = new TH1F("hhptpid_tofw_negproton_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_2_dis_cent6092 = new TH1F("hhptpid_tofw_negproton_2_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_2_dis_cent0010 = new TH1F("hhptpid_tfec_posproton_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_2_dis_cent1020 = new TH1F("hhptpid_tfec_posproton_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_2_dis_cent2040 = new TH1F("hhptpid_tfec_posproton_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_2_dis_cent4060 = new TH1F("hhptpid_tfec_posproton_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_2_dis_cent6092 = new TH1F("hhptpid_tfec_posproton_2_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_2_dis_cent0010 = new TH1F("hhptpid_tfec_negproton_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_2_dis_cent1020 = new TH1F("hhptpid_tfec_negproton_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_2_dis_cent2040 = new TH1F("hhptpid_tfec_negproton_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_2_dis_cent4060 = new TH1F("hhptpid_tfec_negproton_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_2_dis_cent6092 = new TH1F("hhptpid_tfec_negproton_2_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *hhptpid_tofw_posproton_3_dis_cent0010 = new TH1F("hhptpid_tofw_posproton_3_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_3_dis_cent1020 = new TH1F("hhptpid_tofw_posproton_3_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_3_dis_cent2040 = new TH1F("hhptpid_tofw_posproton_3_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_3_dis_cent4060 = new TH1F("hhptpid_tofw_posproton_3_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_3_dis_cent6092 = new TH1F("hhptpid_tofw_posproton_3_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_3_dis_cent0010 = new TH1F("hhptpid_tofw_negproton_3_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_3_dis_cent1020 = new TH1F("hhptpid_tofw_negproton_3_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_3_dis_cent2040 = new TH1F("hhptpid_tofw_negproton_3_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_3_dis_cent4060 = new TH1F("hhptpid_tofw_negproton_3_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_3_dis_cent6092 = new TH1F("hhptpid_tofw_negproton_3_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_3_dis_cent0010 = new TH1F("hhptpid_tfec_posproton_3_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_3_dis_cent1020 = new TH1F("hhptpid_tfec_posproton_3_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_3_dis_cent2040 = new TH1F("hhptpid_tfec_posproton_3_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_3_dis_cent4060 = new TH1F("hhptpid_tfec_posproton_3_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_3_dis_cent6092 = new TH1F("hhptpid_tfec_posproton_3_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_3_dis_cent0010 = new TH1F("hhptpid_tfec_negproton_3_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_3_dis_cent1020 = new TH1F("hhptpid_tfec_negproton_3_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_3_dis_cent2040 = new TH1F("hhptpid_tfec_negproton_3_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_3_dis_cent4060 = new TH1F("hhptpid_tfec_negproton_3_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_3_dis_cent6092 = new TH1F("hhptpid_tfec_negproton_3_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *hhptpid_tofw_posproton_4_dis_cent0010 = new TH1F("hhptpid_tofw_posproton_4_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_4_dis_cent1020 = new TH1F("hhptpid_tofw_posproton_4_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_4_dis_cent2040 = new TH1F("hhptpid_tofw_posproton_4_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_4_dis_cent4060 = new TH1F("hhptpid_tofw_posproton_4_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_4_dis_cent6092 = new TH1F("hhptpid_tofw_posproton_4_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_4_dis_cent0010 = new TH1F("hhptpid_tofw_negproton_4_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_4_dis_cent1020 = new TH1F("hhptpid_tofw_negproton_4_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_4_dis_cent2040 = new TH1F("hhptpid_tofw_negproton_4_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_4_dis_cent4060 = new TH1F("hhptpid_tofw_negproton_4_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_4_dis_cent6092 = new TH1F("hhptpid_tofw_negproton_4_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_4_dis_cent0010 = new TH1F("hhptpid_tfec_posproton_4_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_4_dis_cent1020 = new TH1F("hhptpid_tfec_posproton_4_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_4_dis_cent2040 = new TH1F("hhptpid_tfec_posproton_4_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_4_dis_cent4060 = new TH1F("hhptpid_tfec_posproton_4_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_4_dis_cent6092 = new TH1F("hhptpid_tfec_posproton_4_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_4_dis_cent0010 = new TH1F("hhptpid_tfec_negproton_4_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_4_dis_cent1020 = new TH1F("hhptpid_tfec_negproton_4_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_4_dis_cent2040 = new TH1F("hhptpid_tfec_negproton_4_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_4_dis_cent4060 = new TH1F("hhptpid_tfec_negproton_4_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_4_dis_cent6092 = new TH1F("hhptpid_tfec_negproton_4_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *hhptpid_tofw_posproton_5_dis_cent0010 = new TH1F("hhptpid_tofw_posproton_5_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_5_dis_cent1020 = new TH1F("hhptpid_tofw_posproton_5_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_5_dis_cent2040 = new TH1F("hhptpid_tofw_posproton_5_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_5_dis_cent4060 = new TH1F("hhptpid_tofw_posproton_5_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_posproton_5_dis_cent6092 = new TH1F("hhptpid_tofw_posproton_5_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_5_dis_cent0010 = new TH1F("hhptpid_tofw_negproton_5_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_5_dis_cent1020 = new TH1F("hhptpid_tofw_negproton_5_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_5_dis_cent2040 = new TH1F("hhptpid_tofw_negproton_5_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_5_dis_cent4060 = new TH1F("hhptpid_tofw_negproton_5_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tofw_negproton_5_dis_cent6092 = new TH1F("hhptpid_tofw_negproton_5_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_5_dis_cent0010 = new TH1F("hhptpid_tfec_posproton_5_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_5_dis_cent1020 = new TH1F("hhptpid_tfec_posproton_5_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_5_dis_cent2040 = new TH1F("hhptpid_tfec_posproton_5_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_5_dis_cent4060 = new TH1F("hhptpid_tfec_posproton_5_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_posproton_5_dis_cent6092 = new TH1F("hhptpid_tfec_posproton_5_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_5_dis_cent0010 = new TH1F("hhptpid_tfec_negproton_5_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_5_dis_cent1020 = new TH1F("hhptpid_tfec_negproton_5_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_5_dis_cent2040 = new TH1F("hhptpid_tfec_negproton_5_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_5_dis_cent4060 = new TH1F("hhptpid_tfec_negproton_5_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *hhptpid_tfec_negproton_5_dis_cent6092 = new TH1F("hhptpid_tfec_negproton_5_dis_cent6092", "...", 100, 0.0, 10.0);

  // ---

  TH1F *testpid_tofw_pionpos_0_dis = new TH1F("testpid_tofw_pionpos_0_dis", "tofw 0 pionpos", 100, 0.0, 10.0);
  TH1F *testpid_tofw_pionpos_1_dis = new TH1F("testpid_tofw_pionpos_1_dis", "tofw 1 pionpos", 100, 0.0, 10.0);
  TH1F *testpid_tofw_pionpos_2_dis = new TH1F("testpid_tofw_pionpos_2_dis", "tofw 2 pionpos", 100, 0.0, 10.0);
  TH1F *testpid_tofw_pionpos_3_dis = new TH1F("testpid_tofw_pionpos_3_dis", "tofw 3 pionpos", 100, 0.0, 10.0);
  TH1F *testpid_tofw_pionpos_4_dis = new TH1F("testpid_tofw_pionpos_4_dis", "tofw 4 pionpos", 100, 0.0, 10.0);
  TH1F *testpid_tofw_pionpos_5_dis = new TH1F("testpid_tofw_pionpos_5_dis", "tofw 5 pionpos", 100, 0.0, 10.0);
										        
  TH1F *testpid_tofw_pionneg_0_dis = new TH1F("testpid_tofw_pionneg_0_dis", "tofw 0 pionneg", 100, 0.0, 10.0);
  TH1F *testpid_tofw_pionneg_1_dis = new TH1F("testpid_tofw_pionneg_1_dis", "tofw 1 pionneg", 100, 0.0, 10.0);
  TH1F *testpid_tofw_pionneg_2_dis = new TH1F("testpid_tofw_pionneg_2_dis", "tofw 2 pionneg", 100, 0.0, 10.0);
  TH1F *testpid_tofw_pionneg_3_dis = new TH1F("testpid_tofw_pionneg_3_dis", "tofw 3 pionneg", 100, 0.0, 10.0);
  TH1F *testpid_tofw_pionneg_4_dis = new TH1F("testpid_tofw_pionneg_4_dis", "tofw 4 pionneg", 100, 0.0, 10.0);
  TH1F *testpid_tofw_pionneg_5_dis = new TH1F("testpid_tofw_pionneg_5_dis", "tofw 5 pionneg", 100, 0.0, 10.0);

  TH1F *testpid_tofw_kaonpos_0_dis = new TH1F("testpid_tofw_kaonpos_0_dis", "tofw 0 kaonpos", 100, 0.0, 10.0);
  TH1F *testpid_tofw_kaonpos_1_dis = new TH1F("testpid_tofw_kaonpos_1_dis", "tofw 1 kaonpos", 100, 0.0, 10.0);
  TH1F *testpid_tofw_kaonpos_2_dis = new TH1F("testpid_tofw_kaonpos_2_dis", "tofw 2 kaonpos", 100, 0.0, 10.0);
  TH1F *testpid_tofw_kaonpos_3_dis = new TH1F("testpid_tofw_kaonpos_3_dis", "tofw 3 kaonpos", 100, 0.0, 10.0);
  TH1F *testpid_tofw_kaonpos_4_dis = new TH1F("testpid_tofw_kaonpos_4_dis", "tofw 4 kaonpos", 100, 0.0, 10.0);
  TH1F *testpid_tofw_kaonpos_5_dis = new TH1F("testpid_tofw_kaonpos_5_dis", "tofw 5 kaonpos", 100, 0.0, 10.0);
										        
  TH1F *testpid_tofw_kaonneg_0_dis = new TH1F("testpid_tofw_kaonneg_0_dis", "tofw 0 kaonneg", 100, 0.0, 10.0);
  TH1F *testpid_tofw_kaonneg_1_dis = new TH1F("testpid_tofw_kaonneg_1_dis", "tofw 1 kaonneg", 100, 0.0, 10.0);
  TH1F *testpid_tofw_kaonneg_2_dis = new TH1F("testpid_tofw_kaonneg_2_dis", "tofw 2 kaonneg", 100, 0.0, 10.0);
  TH1F *testpid_tofw_kaonneg_3_dis = new TH1F("testpid_tofw_kaonneg_3_dis", "tofw 3 kaonneg", 100, 0.0, 10.0);
  TH1F *testpid_tofw_kaonneg_4_dis = new TH1F("testpid_tofw_kaonneg_4_dis", "tofw 4 kaonneg", 100, 0.0, 10.0);
  TH1F *testpid_tofw_kaonneg_5_dis = new TH1F("testpid_tofw_kaonneg_5_dis", "tofw 5 kaonneg", 100, 0.0, 10.0);

  TH1F *testpid_tofw_protonpos_0_dis = new TH1F("testpid_tofw_protonpos_0_dis", "tofw 0 protonpos", 100, 0.0, 10.0);
  TH1F *testpid_tofw_protonpos_1_dis = new TH1F("testpid_tofw_protonpos_1_dis", "tofw 1 protonpos", 100, 0.0, 10.0);
  TH1F *testpid_tofw_protonpos_2_dis = new TH1F("testpid_tofw_protonpos_2_dis", "tofw 2 protonpos", 100, 0.0, 10.0);
  TH1F *testpid_tofw_protonpos_3_dis = new TH1F("testpid_tofw_protonpos_3_dis", "tofw 3 protonpos", 100, 0.0, 10.0);
  TH1F *testpid_tofw_protonpos_4_dis = new TH1F("testpid_tofw_protonpos_4_dis", "tofw 4 protonpos", 100, 0.0, 10.0);
  TH1F *testpid_tofw_protonpos_5_dis = new TH1F("testpid_tofw_protonpos_5_dis", "tofw 5 protonpos", 100, 0.0, 10.0);
										        
  TH1F *testpid_tofw_protonneg_0_dis = new TH1F("testpid_tofw_protonneg_0_dis", "tofw 0 protonneg", 100, 0.0, 10.0);
  TH1F *testpid_tofw_protonneg_1_dis = new TH1F("testpid_tofw_protonneg_1_dis", "tofw 1 protonneg", 100, 0.0, 10.0);
  TH1F *testpid_tofw_protonneg_2_dis = new TH1F("testpid_tofw_protonneg_2_dis", "tofw 2 protonneg", 100, 0.0, 10.0);
  TH1F *testpid_tofw_protonneg_3_dis = new TH1F("testpid_tofw_protonneg_3_dis", "tofw 3 protonneg", 100, 0.0, 10.0);
  TH1F *testpid_tofw_protonneg_4_dis = new TH1F("testpid_tofw_protonneg_4_dis", "tofw 4 protonneg", 100, 0.0, 10.0);
  TH1F *testpid_tofw_protonneg_5_dis = new TH1F("testpid_tofw_protonneg_5_dis", "tofw 5 protonneg", 100, 0.0, 10.0);



  TH1F *xpid_tofw_pospion_0_dis_cent0010 = new TH1F("xpid_tofw_pospion_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_pospion_0_dis_cent1020 = new TH1F("xpid_tofw_pospion_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_pospion_0_dis_cent2040 = new TH1F("xpid_tofw_pospion_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_pospion_0_dis_cent4060 = new TH1F("xpid_tofw_pospion_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_pospion_0_dis_cent6092 = new TH1F("xpid_tofw_pospion_0_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negpion_0_dis_cent0010 = new TH1F("xpid_tofw_negpion_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negpion_0_dis_cent1020 = new TH1F("xpid_tofw_negpion_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negpion_0_dis_cent2040 = new TH1F("xpid_tofw_negpion_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negpion_0_dis_cent4060 = new TH1F("xpid_tofw_negpion_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negpion_0_dis_cent6092 = new TH1F("xpid_tofw_negpion_0_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *xpid_tofw_pospion_1_dis_cent0010 = new TH1F("xpid_tofw_pospion_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_pospion_1_dis_cent1020 = new TH1F("xpid_tofw_pospion_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_pospion_1_dis_cent2040 = new TH1F("xpid_tofw_pospion_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_pospion_1_dis_cent4060 = new TH1F("xpid_tofw_pospion_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_pospion_1_dis_cent6092 = new TH1F("xpid_tofw_pospion_1_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negpion_1_dis_cent0010 = new TH1F("xpid_tofw_negpion_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negpion_1_dis_cent1020 = new TH1F("xpid_tofw_negpion_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negpion_1_dis_cent2040 = new TH1F("xpid_tofw_negpion_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negpion_1_dis_cent4060 = new TH1F("xpid_tofw_negpion_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negpion_1_dis_cent6092 = new TH1F("xpid_tofw_negpion_1_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *xpid_tofw_pospion_2_dis_cent0010 = new TH1F("xpid_tofw_pospion_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_pospion_2_dis_cent1020 = new TH1F("xpid_tofw_pospion_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_pospion_2_dis_cent2040 = new TH1F("xpid_tofw_pospion_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_pospion_2_dis_cent4060 = new TH1F("xpid_tofw_pospion_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_pospion_2_dis_cent6092 = new TH1F("xpid_tofw_pospion_2_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negpion_2_dis_cent0010 = new TH1F("xpid_tofw_negpion_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negpion_2_dis_cent1020 = new TH1F("xpid_tofw_negpion_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negpion_2_dis_cent2040 = new TH1F("xpid_tofw_negpion_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negpion_2_dis_cent4060 = new TH1F("xpid_tofw_negpion_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negpion_2_dis_cent6092 = new TH1F("xpid_tofw_negpion_2_dis_cent6092", "...", 100, 0.0, 10.0);



  TH1F *xpid_tofw_posproton_0_dis_cent0010 = new TH1F("xpid_tofw_posproton_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_posproton_0_dis_cent1020 = new TH1F("xpid_tofw_posproton_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_posproton_0_dis_cent2040 = new TH1F("xpid_tofw_posproton_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_posproton_0_dis_cent4060 = new TH1F("xpid_tofw_posproton_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_posproton_0_dis_cent6092 = new TH1F("xpid_tofw_posproton_0_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negproton_0_dis_cent0010 = new TH1F("xpid_tofw_negproton_0_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negproton_0_dis_cent1020 = new TH1F("xpid_tofw_negproton_0_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negproton_0_dis_cent2040 = new TH1F("xpid_tofw_negproton_0_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negproton_0_dis_cent4060 = new TH1F("xpid_tofw_negproton_0_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negproton_0_dis_cent6092 = new TH1F("xpid_tofw_negproton_0_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *xpid_tofw_posproton_1_dis_cent0010 = new TH1F("xpid_tofw_posproton_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_posproton_1_dis_cent1020 = new TH1F("xpid_tofw_posproton_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_posproton_1_dis_cent2040 = new TH1F("xpid_tofw_posproton_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_posproton_1_dis_cent4060 = new TH1F("xpid_tofw_posproton_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_posproton_1_dis_cent6092 = new TH1F("xpid_tofw_posproton_1_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negproton_1_dis_cent0010 = new TH1F("xpid_tofw_negproton_1_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negproton_1_dis_cent1020 = new TH1F("xpid_tofw_negproton_1_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negproton_1_dis_cent2040 = new TH1F("xpid_tofw_negproton_1_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negproton_1_dis_cent4060 = new TH1F("xpid_tofw_negproton_1_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negproton_1_dis_cent6092 = new TH1F("xpid_tofw_negproton_1_dis_cent6092", "...", 100, 0.0, 10.0);

  TH1F *xpid_tofw_posproton_2_dis_cent0010 = new TH1F("xpid_tofw_posproton_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_posproton_2_dis_cent1020 = new TH1F("xpid_tofw_posproton_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_posproton_2_dis_cent2040 = new TH1F("xpid_tofw_posproton_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_posproton_2_dis_cent4060 = new TH1F("xpid_tofw_posproton_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_posproton_2_dis_cent6092 = new TH1F("xpid_tofw_posproton_2_dis_cent6092", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negproton_2_dis_cent0010 = new TH1F("xpid_tofw_negproton_2_dis_cent0010", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negproton_2_dis_cent1020 = new TH1F("xpid_tofw_negproton_2_dis_cent1020", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negproton_2_dis_cent2040 = new TH1F("xpid_tofw_negproton_2_dis_cent2040", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negproton_2_dis_cent4060 = new TH1F("xpid_tofw_negproton_2_dis_cent4060", "...", 100, 0.0, 10.0);
  TH1F *xpid_tofw_negproton_2_dis_cent6092 = new TH1F("xpid_tofw_negproton_2_dis_cent6092", "...", 100, 0.0, 10.0);



  TH1F *h_neve = new TH1F("h_neve","Number of events vs run number",848,0,848);
  TH1F *h_numb = new TH1F("h_numb","Number of tracks vs run number",848,0,848);
  TH1F *h_numpos = new TH1F("h_numpos","Number of tracks vs run number",848,0,848);
  TH1F *h_numneg = new TH1F("h_numneg","Number of tracks vs run number",848,0,848);
  TH1F *h_numbC = new TH1F("h_numbC","Number of tracks vs run number",848,0,848);
  TH1F *h_numposC = new TH1F("h_numposC","Number of tracks vs run number",848,0,848);
  TH1F *h_numnegC = new TH1F("h_numnegC","Number of tracks vs run number",848,0,858);

  // ---------------------------- //
  // --- Done with Histograms --- //
  // ---------------------------- //



  // --- Now read in the pDSTs listed in the input files

  int ifile=0; 
  char filename[100];
  ifstream fin(inFile);
  if(!fin)
    {
      cout<<"list input error: file does not exist "<<endl;
      return 1;
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
	}

      nevents += (Long64_t)((TH1F *)f->Get("hcent"))->GetEntries();

      TTree *t=(TTree *)f->Get("hadrontree");   
      if(!t)
	{
	  cout<<"pDST input error: cannot find tree "<<endl;
	  continue; 
	}


      int n=(int)t->GetEntries(); // number of events in tree
      hadrontree *ktree = new hadrontree(t); // pointer to tree
      for(int i=0;i<n;i++) // loop over events
	{

	  //reset to 0 for every event
	  ngoodtofwtracks_snglevent = 0;
	  
	  ktree->GetEntry(i); 

	  int run = ktree->run;
	  if(run==228171) continue; // no toffset for this run
	  if(run<229000) fetchRunOffsetFromFile(run);
	  else runoffset = 0.0;
	  //if(runoffset==-9999) continue; // best general way to check, but don't need right now

	  // get the run index
	  stringstream ss;
	  ss<<run;
	  int runindex = myMap[ss.str()]; 
	  h_neve->Fill(runindex); // events per run histograms

	  float bbcz = ktree->bbcz;
	  //if(fabs(bbcz)>30) continue;
	  float cent = ktree->cent;
	  //if(cent<0||cent>=100) continue;

	  hhcent->Fill(cent);
	  hhbbcz->Fill(bbcz);

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

	  int ICENT=-1;
	  if (cent>0 && cent<=10)        ICENT=0;
	  else if (cent>10 && cent<=20)  ICENT=1;
	  else if (cent>20 && cent<=40)  ICENT=2;
	  else if (cent>40 && cent<=60)  ICENT=3;
	  else if (cent>60 && cent<=99)  ICENT=4;


	  for(int itrk=0; itrk<ktree->mNtrack; itrk++)
	    {
	      
	      ntracks++; // count total number of tracks

	      float mom = ktree->HadronTracks_mom[itrk];
	      float pT = ktree->HadronTracks_pt[itrk];
	      int striptofw = (int)ktree->HadronTracks_striptofw[itrk];

	      // tiny momentum scale retuning
	      //if(striptofw<256) {mom = 0.9957*mom; pT = 0.9957*pT;}

	      //if(pT<0.3||pT>0.4) continue;  // super temp testing!
	      //if(pT<0.2||pT>0.8) continue;  // super temp testing!
	      //if(pT<0.5||pT>0.8) continue;  // super temp testing!

	      //if(striptofw<0||striptofw>63) continue; // W1 south bot (box 0, lower half)
	      //if(striptofw<64||striptofw>127) continue; // W1 south top (box 0, upper half)
	      //if(striptofw<128||striptofw>191) continue; // W1 north bot (box 1, lower half)
	      //if(striptofw<192||striptofw>255) continue; // W1 north top (box 1, upper half)

	      // --- DC
	      
	      int quality = ktree->HadronTracks_quality[itrk];
	      float zed   = ktree->HadronTracks_zed[itrk];
	      float phi   = ktree->HadronTracks_phi[itrk];
	      float alpha = ktree->HadronTracks_alpha[itrk];
	      int charge  = ktree->HadronTracks_charge[itrk];

	      h_numb->Fill(runindex);
	      if(charge>0) h_numpos->Fill(runindex);
	      if(charge<0) h_numneg->Fill(runindex);

	      // ----------------------- //
	      // --- dcfc histograms --- //
	      // ----------------------- //

	      hh_zedphi_nc->Fill(zed,phi);

	      if(zed>0)
		{
		  hh_alphaphi_poszed_nc->Fill(phi,alpha);
		  if(pT>0.4) hh_alphaphi_poszed_nc_FW->Fill(phi,alpha);
		  if(charge>0) hh_pos_momphi_poszed_nc->Fill(phi,pT);
		  if(charge<0) hh_neg_momphi_poszed_nc->Fill(phi,pT);
		}
	      if(zed<0)
		{
		  hh_alphaphi_negzed_nc->Fill(phi,alpha);
		  if(pT>0.4) hh_alphaphi_negzed_nc_FW->Fill(phi,alpha);
		  if(charge>0) hh_pos_momphi_negzed_nc->Fill(phi,pT);
		  if(charge<0) hh_neg_momphi_negzed_nc->Fill(phi,pT);
		}

	      // ----------------------- //
	      // ----------------------- //
	      // ----------------------- //

	      // track matching

	      // float pc2sdz      = ktree->HadronTracks_pc2sdz[itrk];
	      // float pc2sdphi    = ktree->HadronTracks_pc2sdphi[itrk];
	      // pc2sdz = retunepc2sdz(cent,charge,pc2sdz,run);
	      // pc2sdphi = retunepc2sdphi(cent,charge,pc2sdphi,run);
	      // bool pc2_matching = fabs(pc2sdphi)<2.0 && fabs(pc2sdz)<2.0;
	      float pc3sdz      = ktree->HadronTracks_pc3sdz[itrk];
	      float pc3sdphi    = ktree->HadronTracks_pc3sdphi[itrk];
	      //pc3sdz = retunepc3sdz(mom,charge,pc3sdz,run);
	      //pc3sdphi = retunepc3sdphi(mom,charge,pc3sdphi,run);
	      bool pc3_matching = fabs(pc3sdphi)<2.0 && fabs(pc3sdz)<2.0;
	      bool pc3_HM = fabs(pc3sdphi)<1.5 && fabs(pc3sdz)<1.5;
	      float tofwsdz     = ktree->HadronTracks_tofwsdz[itrk];
	      float tofwsdphi   = ktree->HadronTracks_tofwsdphi[itrk];
	      //float sigma_tofw = sqrt(tofwsdz*tofwsdz+tofwsdphi*tofwsdphi);
	      //tofwsdz = retunetofwsdz(mom,charge,tofwsdz,run);
	      //tofwsdphi = retunetofwsdphi(mom,charge,tofwsdphi,run);
	      bool tfw_matching = fabs(tofwsdphi)<2.0 && fabs(tofwsdz)<2.0;
	      bool tfw_HM = fabs(tofwsdphi)<1.5 && fabs(tofwsdz)<1.5;



	    
	      // --- PC1

	      // float ppc1x   = ktree->HadronTracks_ppc1x[itrk];
	      // float ppc1y   = ktree->HadronTracks_ppc1y[itrk];
	      // float ppc1z   = ktree->HadronTracks_ppc1z[itrk];
	      // float pc1z    = ppc1z;
	      // float pc1phi  = atan2(ppc1y,ppc1x);  
	      float pc1z    = ktree->HadronTracks_pc1z[itrk]; // NEW
	      float pc1phi  = ktree->HadronTracks_pc1phi[itrk]; // NEW
	      bool good_pc1 = GoodPC1(pc1z,pc1phi);
	      bool sysgood_pc1 = SysGoodPC1(pc1z,pc1phi);
	      
	      PC1ZedPhiDis->Fill(pc1z,pc1phi);
	      if(good_pc1&&pT>0.4) PC1ZedPhiNewDis->Fill(pc1z,pc1phi);

	      // --- PC2

	      // float ppc2x   = ktree->HadronTracks_ppc2x[itrk];
	      // float ppc2y   = ktree->HadronTracks_ppc2y[itrk];
	      // float ppc2z   = ktree->HadronTracks_ppc2z[itrk];
	      // float pc2dz   = ktree->HadronTracks_pc2dz[itrk];
	      // float pc2dphi = ktree->HadronTracks_pc2dphi[itrk];
	      // float pc2z    = ppc2z - pc2dz;
	      // float pc2phi  = atan2(ppc2y,ppc2x) - pc2dphi;
	      // float pc2z    = ktree->HadronTracks_pc2z[itrk]; // NEW
	      // float pc2phi  = ktree->HadronTracks_pc2phi[itrk]; // NEW
	      // bool good_pc2 = GoodPC2(pc2z,pc2phi);
	      
	      // if(pc2_matching) PC2ZedPhiDis->Fill(pc2z,pc2phi);
	      // if(pc2_matching&&good_pc2) PC2ZedPhiNewDis->Fill(pc2z,pc2phi);

	      // --- PC3

	      // float ppc3x   = ktree->HadronTracks_ppc3x[itrk];
	      // float ppc3y   = ktree->HadronTracks_ppc3y[itrk];
	      // float ppc3z   = ktree->HadronTracks_ppc3z[itrk];
	      // float pc3dz   = ktree->HadronTracks_pc3dz[itrk];
	      // float pc3dphi = ktree->HadronTracks_pc3dphi[itrk];
	      // float pc3z    = ppc3z - pc3dz;
	      // float pc3phi  = atan2(ppc3y,ppc3x) - pc3dphi;
	      float pc3z    = ktree->HadronTracks_pc3z[itrk]; // NEW
	      float pc3phi  = ktree->HadronTracks_pc3phi[itrk]; // NEW
	      if(pT>=3.0) pc3phi = pi/2 - pc3phi; // TEMP!
	      bool good_pc3 = GoodPC3(pc3z,pc3phi);
	      bool sysgood_pc3 = SysGoodPC3(pc3z,pc3phi);
	      
	      if(pc3_matching) PC3ZedPhiDis->Fill(pc3z,pc3phi);
	      if(pc3_matching&&good_pc3) PC3ZedPhiNewDis->Fill(pc3z,pc3phi);

	      // --- TOFW

	      // float ptofwx   = ktree->HadronTracks_ptofwx[itrk];
	      // float ptofwy   = ktree->HadronTracks_ptofwy[itrk];
	      // float ptofwz   = ktree->HadronTracks_ptofwz[itrk];
	      // float tofwdz   = ktree->HadronTracks_tofwdz[itrk];
	      // float tofwdphi = ktree->HadronTracks_tofwdphi[itrk];
	      // float tofwz    = ptofwz - tofwdz;
	      // float tofwphi  = atan2(ptofwy,ptofwx) - tofwdphi;
	      float tofwz    = ktree->HadronTracks_tofwz[itrk]; // NEW
	      float tofwphi  = ktree->HadronTracks_tofwphi[itrk]; // NEW
	      if(pT>=3.0) tofwphi = pi/2 - tofwphi; // TEMP!
	      float pltofw   = ktree->HadronTracks_pltofw[itrk];
	      float qtofw    = ktree->HadronTracks_qtofw[itrk];
	      float ttofw    = ktree->HadronTracks_ttofw[itrk];
	      ttofw = ttofw - runoffset;
	      //float beta     = pltofw/ttofw/phbeta; // unused for now
	      bool goodstrip = goodStrip(striptofw);
	      bool good_adc  = qtofw>60 && qtofw<600;// && qtofw<(20*((float)pow(beta,(float)-2.7)));
	      //bool adc_beta  = qtofw>(20*((float)pow(beta,(float)-2.7))); // unused for now
	      /*bool tofwedge = (fabs(tofwz)<175&&fabs(tofwz)>4) && 
		((tofwphi>-0.1&&tofwphi<0.06)||(tofwphi>0.41&&tofwphi<0.58));*/
	      
	      if(tfw_matching) TOFWZedPhiDis->Fill(tofwz,tofwphi);
	      if(tfw_matching&&goodstrip) TOFWZedPhiNewDis->Fill(tofwz,tofwphi);

	      // --- EMC && RICH

	      float emcz      = ktree->HadronTracks_emcz[itrk];
	      float emcphi    = ktree->HadronTracks_emcphi[itrk];
	      if(pT>=3.0) emcphi = pi/2 - emcphi;
	      float emcsdz      = ktree->HadronTracks_emcsdz[itrk];
	      float emcsdphi    = ktree->HadronTracks_emcsdphi[itrk];
	      int warnmap       = ktree->HadronTracks_warnmap[itrk];
	      int deadmap       = ktree->HadronTracks_deadmap[itrk];
	      bool emc_matching = fabs(emcsdphi)<2.0 && fabs(emcsdz)<2.0;
	      float ecore = ktree->HadronTracks_ecore[itrk];
	      float ecent = ktree->HadronTracks_ecent[itrk];
	      //float emce  = ktree->HadronTracks_emce[itrk];
	      //float ep = ecore/mom;
	      //float ep = ecent/mom;
	      float ep = ecore/pT; // NEW
	      bool goodemc = GoodEMC(emcz,emcphi);
	      //bool sysgoodemc = SysGoodEMC(emcz,emcphi); // unused for now
	      bool good_emc = emc_matching && goodemc && deadmap==0 && warnmap==0; // dead and warn redundant?
	      if(emc_matching&&deadmap==0&&warnmap==0) EMCZedPhiDis->Fill(emcz,emcphi);
	      if(emc_matching&&good_emc) EMCZedPhiNewDis->Fill(emcz,emcphi);
	      // COME BACK HERE!!!
	      //float n0 = ktree->HadronTracks_n0[itrk]; // GONE
	      //bool DeadMap = ((tofwphi>0.535&&tofwz<-113) || (tofwphi>0.453&&tofwphi<0.505 && tofwz>-102&&tofwz<-76));

	      // ---

	      bool good_dc = (fabs(zed)<70&&fabs(zed)>3&&(quality==63||quality==31));
	      //bool good_dc = (fabs(zed)<70&&fabs(zed)>3&&quality>=29); // TEST!!!

	      // now do actual cuts

	      // good_dc and goodstrip common to all systematics, additional cuts to be made on zed as needed
	      if(!good_dc) continue;
	      if(!goodstrip) continue;

	      // CUTS ARE DEFINTED HERE!
	      bool regular_cuts = tfw_matching && pc3_matching && good_pc1 && good_pc3 && good_adc;
	      bool syst_tfwmatch = pc3_matching && good_pc1 && good_pc3 && good_adc;	
	      bool syst_pc3match = tfw_matching && good_pc1 && good_pc3 && good_adc;
	      bool syst_pc3fiducial = tfw_matching && pc3_matching && good_pc1 && good_adc;
	      bool syst_pc1fiducial = tfw_matching && pc3_matching && good_pc3 && good_adc;
	      bool syst_goodadc = tfw_matching && pc3_matching && good_pc1 && good_pc3;


	      // SUPER DUPER ULTRA MEGA TESTING!
	      //if(!regular_cuts) continue;
	      //if(!syst_tfwmatch) continue;
	      //if(!syst_pc3match) continue;
	      //if(!syst_pc3fiducial) continue;
	      //if(!syst_pc1fiducial) continue;
	      //if(!syst_goodadc) continue;


	      // ----------------------- //
	      // --- dcfc histograms --- //
	      // ----------------------- //

	      hh_zedphi_mc->Fill(zed,phi);

	      if(regular_cuts&&zed>0) // new
		{
		  hh_alphaphi_poszed_mc->Fill(phi,alpha);
		  if(pT>0.4) hh_alphaphi_poszed_mc_FW->Fill(phi,alpha);
		  if(charge>0) hh_pos_momphi_poszed_mc->Fill(phi,pT);
		  if(charge<0) hh_neg_momphi_poszed_mc->Fill(phi,pT);
		}
	      if(regular_cuts&&zed<0)
		{
		  hh_alphaphi_negzed_mc->Fill(phi,alpha);
		  if(pT>0.4) hh_alphaphi_negzed_mc_FW->Fill(phi,alpha);
		  if(charge>0) hh_pos_momphi_negzed_mc->Fill(phi,pT);
		  if(charge<0) hh_neg_momphi_negzed_mc->Fill(phi,pT);
		}

	      // ----------------------- //
	      // ----------------------- //
	      // ----------------------- //

	      //if(!GoodEdgeDCH(run,zed,alpha,phi)) continue; // modified
	      bool edge = GoodEdgeDCH(run,zed,alpha,phi);
	      bool sysedge = SysGoodEdgeDCH(run,zed,alpha,phi);

	      // ----------------------- //
	      // ----------------------- //
	      // ----------------------- //

	      if(regular_cuts&&edge) hh_zedphi_ec->Fill(zed,phi);

	      if(regular_cuts&&edge&&zed>0)
		{
		  hh_alphaphi_poszed_ec->Fill(phi,alpha);
		  if(pT>0.4) hh_alphaphi_poszed_ec_FW->Fill(phi,alpha);
		  if(charge>0) hh_pos_momphi_poszed_ec->Fill(phi,pT);
		  if(charge<0) hh_neg_momphi_poszed_ec->Fill(phi,pT);
		}
	      if(regular_cuts&&edge&&zed<0)
		{
		  hh_alphaphi_negzed_ec->Fill(phi,alpha);
		  if(pT>0.4) hh_alphaphi_negzed_ec_FW->Fill(phi,alpha);
		  if(charge>0) hh_pos_momphi_negzed_ec->Fill(phi,pT);
		  if(charge<0) hh_neg_momphi_negzed_ec->Fill(phi,pT);
		}

	      // ----------------------- //
	      // ----------------------- //
	      // ----------------------- //

	      //if(!GoodInnerDCH(run,zed,alpha,phi)) continue;
	      bool inner = GoodInnerDCH(run,zed,alpha,phi);
	      bool sysinner = SysGoodInnerDCH(run,zed,alpha,phi);
	      if(regular_cuts&&edge&&inner) hh_zedphi_ac->Fill(zed,phi);

	      // ----------------------- //
	      // ----------------------- //
	      // ----------------------- //

	      if(regular_cuts&&edge&&inner&&zed>0)
		{
		  hh_alphaphi_poszed_ac->Fill(phi,alpha);
		  if(pT>0.4) hh_alphaphi_poszed_ac_FW->Fill(phi,alpha);
		  if(charge>0) hh_pos_momphi_poszed_ac->Fill(phi,pT);
		  if(charge<0) hh_neg_momphi_poszed_ac->Fill(phi,pT);
		}
	      if(regular_cuts&&edge&&inner&&zed<0)
		{
		  hh_alphaphi_negzed_ac->Fill(phi,alpha);
		  if(pT>0.4) hh_alphaphi_negzed_ac_FW->Fill(phi,alpha);
		  if(charge>0) hh_pos_momphi_negzed_ac->Fill(phi,pT);
		  if(charge<0) hh_neg_momphi_negzed_ac->Fill(phi,pT);
		}

	      // ----------------------- //
	      // ----------------------- //
	      // ----------------------- //

	      if(regular_cuts&&edge&&inner)
		{
		  h_numbC->Fill(runindex);
		  if(charge>0) h_numposC->Fill(runindex);
		  if(charge<0) h_numnegC->Fill(runindex);
		}



	      // --- PID

	      //float m2tofw = ktree->HadronTracks_m2tofw[itrk];
	      float m2tofw = mom*mom*(ttofw*ttofw*phbeta*phbeta/(pltofw*pltofw)-1);


	      //float deltat_pion = ttofw - pltofw/phbeta*sqrt(mpion*mpion/mom/mom+1);
	      //float deltat_kaon = ttofw - pltofw/phbeta*sqrt(mkaon*mkaon/mom/mom+1);
	      //float deltat_proton = ttofw - pltofw/phbeta*sqrt(mproton*mproton/mom/mom+1);

	      float isPiANA = isPionANA(pT,m2tofw);
	      float isKANA  = isKaonANA(pT,m2tofw);
	      float isPANA  = isProtonANA(pT,m2tofw);

	      float isPiLow = isPionLow(pT,m2tofw);
	      float isKLow  = isKaonLow(pT,m2tofw);
	      float isPLow  = isProtonLow(pT,m2tofw);

	      float isPiLME = isPionLME(pT,m2tofw);
	      float isKLME  = isKaonLME(pT,m2tofw);
	      float isPLME  = isProtonLME(pT,m2tofw);

	      float isPiPDI = isPionPDI(pT,m2tofw);// only one that's different
	      float isKPDI  = isKaonLME(pT,m2tofw);// LME
	      float isPPDI  = isProtonLME(pT,m2tofw);// LME

	      //isPiLME /= 0.85; // SUPER TEMP
	      //isPiANA /= 0.85; // SUPER TEMP

	      // bool isPi = (isPiLME>=-2&&isPiLME<=2);
	      // bool isK = (isKLME>=-2&&isKLME<=2);
	      // bool isP = (isPLME>=-2&&isPLME<=2);


	      if(regular_cuts&&edge&&inner)
		{
		  if(charge>0) m2momdis_pos->Fill(mom,m2tofw);
		  if(charge<0) m2momdis_neg->Fill(mom,m2tofw);
		  if(striptofw<256&&charge>0) m2momdis_pos_w1->Fill(mom,m2tofw);
		  if(striptofw<256&&charge<0) m2momdis_neg_w1->Fill(mom,m2tofw);
		  if(striptofw>255&&charge>0) m2momdis_pos_w2->Fill(mom,m2tofw);
		  if(striptofw>255&&charge<0) m2momdis_neg_w2->Fill(mom,m2tofw);
		  if(cent> 0&&cent<=10&&charge>0) isPi_dis_pos_cent0010->Fill(pT,isPiLME);//important
		  if(cent> 0&&cent<=10&&charge<0) isPi_dis_neg_cent0010->Fill(pT,isPiLME);//important
		  if(cent>10&&cent<=20&&charge>0) isPi_dis_pos_cent1020->Fill(pT,isPiLME);//important
		  if(cent>10&&cent<=20&&charge<0) isPi_dis_neg_cent1020->Fill(pT,isPiLME);//important
		  if(cent>20&&cent<=40&&charge>0) isPi_dis_pos_cent2040->Fill(pT,isPiLME);//important
		  if(cent>20&&cent<=40&&charge<0) isPi_dis_neg_cent2040->Fill(pT,isPiLME);//important
		  if(cent>40&&cent<=60&&charge>0) isPi_dis_pos_cent4060->Fill(pT,isPiLME);//important
		  if(cent>40&&cent<=60&&charge<0) isPi_dis_neg_cent4060->Fill(pT,isPiLME);//important
		  if(cent>60&&cent<=92&&charge>0) isPi_dis_pos_cent6092->Fill(pT,isPiLME);//important
		  if(cent>60&&cent<=92&&charge<0) isPi_dis_neg_cent6092->Fill(pT,isPiLME);//important
		  if(cent> 0&&cent<=10&&charge>0) isK_dis_pos_cent0010->Fill(pT,isKLME);//important
		  if(cent> 0&&cent<=10&&charge<0) isK_dis_neg_cent0010->Fill(pT,isKLME);//important
		  if(cent>10&&cent<=20&&charge>0) isK_dis_pos_cent1020->Fill(pT,isKLME);//important
		  if(cent>10&&cent<=20&&charge<0) isK_dis_neg_cent1020->Fill(pT,isKLME);//important
		  if(cent>20&&cent<=40&&charge>0) isK_dis_pos_cent2040->Fill(pT,isKLME);//important
		  if(cent>20&&cent<=40&&charge<0) isK_dis_neg_cent2040->Fill(pT,isKLME);//important
		  if(cent>40&&cent<=60&&charge>0) isK_dis_pos_cent4060->Fill(pT,isKLME);//important
		  if(cent>40&&cent<=60&&charge<0) isK_dis_neg_cent4060->Fill(pT,isKLME);//important
		  if(cent>60&&cent<=92&&charge>0) isK_dis_pos_cent6092->Fill(pT,isKLME);//important
		  if(cent>60&&cent<=92&&charge<0) isK_dis_neg_cent6092->Fill(pT,isKLME);//important
		  if(cent> 0&&cent<=10&&charge>0) isP_dis_pos_cent0010->Fill(pT,isPLME);//important
		  if(cent> 0&&cent<=10&&charge<0) isP_dis_neg_cent0010->Fill(pT,isPLME);//important
		  if(cent>10&&cent<=20&&charge>0) isP_dis_pos_cent1020->Fill(pT,isPLME);//important
		  if(cent>10&&cent<=20&&charge<0) isP_dis_neg_cent1020->Fill(pT,isPLME);//important
		  if(cent>20&&cent<=40&&charge>0) isP_dis_pos_cent2040->Fill(pT,isPLME);//important
		  if(cent>20&&cent<=40&&charge<0) isP_dis_neg_cent2040->Fill(pT,isPLME);//important
		  if(cent>40&&cent<=60&&charge>0) isP_dis_pos_cent4060->Fill(pT,isPLME);//important
		  if(cent>40&&cent<=60&&charge<0) isP_dis_neg_cent4060->Fill(pT,isPLME);//important
		  if(cent>60&&cent<=92&&charge>0) isP_dis_pos_cent6092->Fill(pT,isPLME);//important
		  if(cent>60&&cent<=92&&charge<0) isP_dis_neg_cent6092->Fill(pT,isPLME);//important
		  if(charge>0) isPi_dis_pos->Fill(pT,isPiLME);//important
		  if(charge<0) isPi_dis_neg->Fill(pT,isPiLME);//important
		  if(charge>0) isK_dis_pos->Fill(pT,isKLME);
		  if(charge<0) isK_dis_neg->Fill(pT,isKLME);
		  if(charge>0) isP_dis_pos->Fill(pT,isPLME);
		  if(charge<0) isP_dis_neg->Fill(pT,isPLME);
		  if(charge>0) m2pTdis_pos->Fill(pT,m2tofw);
		  if(charge<0) m2pTdis_neg->Fill(pT,m2tofw);
		  if(charge>0&&ICENT==0) m2pTdis_pos_cent0->Fill(pT,m2tofw);
		  if(charge<0&&ICENT==0) m2pTdis_neg_cent0->Fill(pT,m2tofw);
		  if(charge>0&&ICENT==1) m2pTdis_pos_cent1->Fill(pT,m2tofw);
		  if(charge<0&&ICENT==1) m2pTdis_neg_cent1->Fill(pT,m2tofw);
		  if(charge>0&&ICENT==2) m2pTdis_pos_cent2->Fill(pT,m2tofw);
		  if(charge<0&&ICENT==2) m2pTdis_neg_cent2->Fill(pT,m2tofw);
		  if(charge>0&&ICENT==3) m2pTdis_pos_cent3->Fill(pT,m2tofw);
		  if(charge<0&&ICENT==3) m2pTdis_neg_cent3->Fill(pT,m2tofw);
		  if(charge>0&&ICENT==4) m2pTdis_pos_cent4->Fill(pT,m2tofw);
		  if(charge<0&&ICENT==4) m2pTdis_neg_cent4->Fill(pT,m2tofw);
		  // ep cut
		  if(ecore/pT>0.2)
		    {
		      if(charge>0) m2pTdis_epc_pos->Fill(pT,m2tofw);
		      if(charge<0) m2pTdis_epc_neg->Fill(pT,m2tofw);
		      if(charge>0&&ICENT==0) m2pTdis_epc_pos_cent0->Fill(pT,m2tofw);
		      if(charge<0&&ICENT==0) m2pTdis_epc_neg_cent0->Fill(pT,m2tofw);
		      if(charge>0&&ICENT==1) m2pTdis_epc_pos_cent1->Fill(pT,m2tofw);
		      if(charge<0&&ICENT==1) m2pTdis_epc_neg_cent1->Fill(pT,m2tofw);
		      if(charge>0&&ICENT==2) m2pTdis_epc_pos_cent2->Fill(pT,m2tofw);
		      if(charge<0&&ICENT==2) m2pTdis_epc_neg_cent2->Fill(pT,m2tofw);
		      if(charge>0&&ICENT==3) m2pTdis_epc_pos_cent3->Fill(pT,m2tofw);
		      if(charge<0&&ICENT==3) m2pTdis_epc_neg_cent3->Fill(pT,m2tofw);
		      if(charge>0&&ICENT==4) m2pTdis_epc_pos_cent4->Fill(pT,m2tofw);
		      if(charge<0&&ICENT==4) m2pTdis_epc_neg_cent4->Fill(pT,m2tofw);
		    }
		}


	      // ----------------------- //
	      // ----------------------- //
	      // ----------------------- //


	      ngoodtofwtracks++;
	      ngoodtofwtracks_snglevent++;

	      // ----------------------- //
	      // ----------------------- //
	      // ----------------------- //

	      float isPiNew = isPionLow(pT,m2tofw);
	      float isKNew = isKaonLow(pT,m2tofw);
	      float isPNew = isProtonLow(pT,m2tofw);
	      float isPiOld = isPionLME(pT,m2tofw);
	      float isKOld = isKaonLME(pT,m2tofw);
	      float isPOld = isProtonLME(pT,m2tofw);
	      float isPiAna1 = isPionANA_v1(pT,m2tofw);
	      float isKAna1 = isKaonANA_v1(pT,m2tofw);
	      float isPAna1 = isProtonANA_v1(pT,m2tofw);
	      float isPiAna2 = isPionANA_v2(pT,m2tofw);
	      float isKAna2 = isKaonANA_v2(pT,m2tofw);
	      float isPAna2 = isProtonANA_v2(pT,m2tofw);
	      float isPiAna3 = isPionANA_v3(pT,m2tofw);
	      float isKAna3 = isKaonANA_v3(pT,m2tofw);
	      float isPAna3 = isProtonANA_v3(pT,m2tofw);

	      // float isPi = isPiOld;
	      // float isK = isKOld;
	      // float isP = isPOld;

	      float isPi = isPiAna2;
	      float isK = isKAna2;
	      float isP = isPAna2;

	      bool piondis0 = isPiNew>=-2 && isPiNew<=2 && isKNew<=-2;
	      bool piondis1 = isPiOld>=-2 && isPiOld<=2 && isKOld<=-2;
	      bool piondis2 = isPiAna1>=-2 && isPiAna1<=2 && isKAna1<=-2;
	      bool piondis3 = isPiAna2>=-2 && isPiAna2<=2 && isKAna2<=-2;
	      bool piondis4 = isPiAna3>=-2 && isPiAna3<=2 && isKAna3<=-2;
	      bool piondis5 = true;
	      bool kaondis0 = isKNew>=-2 && isKNew<=2 && isPiNew>=2 && isPNew<=-2;
	      bool kaondis1 = isKOld>=-2 && isKOld<=2 && isPiOld>=2 && isPOld<=-2;
	      bool kaondis2 = isKAna1>=-2 && isKAna1<=2 && isPiAna1>=2 && isPAna1<=-2;
	      bool kaondis3 = isKAna2>=-2 && isKAna2<=2 && isPiAna2>=2 && isPAna2<=-2;
	      bool kaondis4 = isKAna3>=-2 && isKAna3<=2 && isPiAna3>=2 && isPAna3<=-2;
	      bool kaondis5 = true;
	      bool protondis0 = isPNew>=-2 && isPNew<=2 && isKNew>=2;
	      bool protondis1 = isPOld>=-2 && isPOld<=2 && isKOld>=2;
	      bool protondis2 = isPAna1>=-2 && isPAna1<=2 && isKAna1>=2;
	      bool protondis3 = isPAna2>=-2 && isPAna2<=2 && isKAna2>=2;
	      bool protondis4 = isPAna3>=-2 && isPAna3<=2 && isKAna3>=2;
	      bool protondis5 = true;

	      if(regular_cuts&&edge&&inner)
		{
		  if(charge>0)
		    {
		      if(piondis0) testpid_tofw_pionpos_0_dis->Fill(pT);
		      if(piondis1) testpid_tofw_pionpos_1_dis->Fill(pT);
		      if(piondis2) testpid_tofw_pionpos_2_dis->Fill(pT);
		      if(piondis3) testpid_tofw_pionpos_3_dis->Fill(pT);
		      if(piondis4) testpid_tofw_pionpos_4_dis->Fill(pT);
		      if(piondis5) testpid_tofw_pionpos_5_dis->Fill(pT);
		      if(kaondis0) testpid_tofw_kaonpos_0_dis->Fill(pT);
		      if(kaondis1) testpid_tofw_kaonpos_1_dis->Fill(pT);
		      if(kaondis2) testpid_tofw_kaonpos_2_dis->Fill(pT);
		      if(kaondis3) testpid_tofw_kaonpos_3_dis->Fill(pT);
		      if(kaondis4) testpid_tofw_kaonpos_4_dis->Fill(pT);
		      if(kaondis5) testpid_tofw_kaonpos_5_dis->Fill(pT);
		      if(protondis0) testpid_tofw_protonpos_0_dis->Fill(pT);
		      if(protondis1) testpid_tofw_protonpos_1_dis->Fill(pT);
		      if(protondis2) testpid_tofw_protonpos_2_dis->Fill(pT);
		      if(protondis3) testpid_tofw_protonpos_3_dis->Fill(pT);
		      if(protondis4) testpid_tofw_protonpos_4_dis->Fill(pT);
		      if(protondis5) testpid_tofw_protonpos_5_dis->Fill(pT);
		    }
		  if(charge<0)
		    {
		      if(piondis0) testpid_tofw_pionneg_0_dis->Fill(pT);
		      if(piondis1) testpid_tofw_pionneg_1_dis->Fill(pT);
		      if(piondis2) testpid_tofw_pionneg_2_dis->Fill(pT);
		      if(piondis3) testpid_tofw_pionneg_3_dis->Fill(pT);
		      if(piondis4) testpid_tofw_pionneg_4_dis->Fill(pT);
		      if(piondis5) testpid_tofw_pionneg_5_dis->Fill(pT);
		      if(kaondis0) testpid_tofw_kaonneg_0_dis->Fill(pT);
		      if(kaondis1) testpid_tofw_kaonneg_1_dis->Fill(pT);
		      if(kaondis2) testpid_tofw_kaonneg_2_dis->Fill(pT);
		      if(kaondis3) testpid_tofw_kaonneg_3_dis->Fill(pT);
		      if(kaondis4) testpid_tofw_kaonneg_4_dis->Fill(pT);
		      if(kaondis5) testpid_tofw_kaonneg_5_dis->Fill(pT);
		      if(protondis0) testpid_tofw_protonneg_0_dis->Fill(pT);
		      if(protondis1) testpid_tofw_protonneg_1_dis->Fill(pT);
		      if(protondis2) testpid_tofw_protonneg_2_dis->Fill(pT);
		      if(protondis3) testpid_tofw_protonneg_3_dis->Fill(pT);
		      if(protondis4) testpid_tofw_protonneg_4_dis->Fill(pT);
		      if(protondis5) testpid_tofw_protonneg_5_dis->Fill(pT);
		    }
		}

	      bool pika0 = isPi>=-2.0 && isPi<=0.0;
	      bool pika1 = isPi>=-2.0 && isPi<=1.0;
	      bool pika2 = isPi>=-2.0 && isPi<=2.0;
	      bool kapr0 = isP>= 0.0 && isP<=2.0;
	      bool kapr1 = isP>=-1.0 && isP<=2.0;
	      bool kapr2 = isP>=-2.0 && isP<=2.0;
	      //if(regular_cuts&&good_dcfc)
	      if(regular_cuts&&edge&&inner)
		{
		  if(charge>0)
		    {
		      if(pika0&&cent> 0&&cent<=10) xpid_tofw_pospion_0_dis_cent0010->Fill(pT);
		      if(pika0&&cent>10&&cent<=20) xpid_tofw_pospion_0_dis_cent1020->Fill(pT);
		      if(pika0&&cent>20&&cent<=40) xpid_tofw_pospion_0_dis_cent2040->Fill(pT);
		      if(pika0&&cent>40&&cent<=60) xpid_tofw_pospion_0_dis_cent4060->Fill(pT);
		      if(pika0&&cent>60&&cent<=92) xpid_tofw_pospion_0_dis_cent6092->Fill(pT);
		      if(pika1&&cent> 0&&cent<=10) xpid_tofw_pospion_1_dis_cent0010->Fill(pT);
		      if(pika1&&cent>10&&cent<=20) xpid_tofw_pospion_1_dis_cent1020->Fill(pT);
		      if(pika1&&cent>20&&cent<=40) xpid_tofw_pospion_1_dis_cent2040->Fill(pT);
		      if(pika1&&cent>40&&cent<=60) xpid_tofw_pospion_1_dis_cent4060->Fill(pT);
		      if(pika1&&cent>60&&cent<=92) xpid_tofw_pospion_1_dis_cent6092->Fill(pT);
		      if(pika2&&cent> 0&&cent<=10) xpid_tofw_pospion_2_dis_cent0010->Fill(pT);
		      if(pika2&&cent>10&&cent<=20) xpid_tofw_pospion_2_dis_cent1020->Fill(pT);
		      if(pika2&&cent>20&&cent<=40) xpid_tofw_pospion_2_dis_cent2040->Fill(pT);
		      if(pika2&&cent>40&&cent<=60) xpid_tofw_pospion_2_dis_cent4060->Fill(pT);
		      if(pika2&&cent>60&&cent<=92) xpid_tofw_pospion_2_dis_cent6092->Fill(pT);
		      if(kapr0&&cent> 0&&cent<=10) xpid_tofw_posproton_0_dis_cent0010->Fill(pT);
		      if(kapr0&&cent>10&&cent<=20) xpid_tofw_posproton_0_dis_cent1020->Fill(pT);
		      if(kapr0&&cent>20&&cent<=40) xpid_tofw_posproton_0_dis_cent2040->Fill(pT);
		      if(kapr0&&cent>40&&cent<=60) xpid_tofw_posproton_0_dis_cent4060->Fill(pT);
		      if(kapr0&&cent>60&&cent<=92) xpid_tofw_posproton_0_dis_cent6092->Fill(pT);
		      if(kapr1&&cent> 0&&cent<=10) xpid_tofw_posproton_1_dis_cent0010->Fill(pT);
		      if(kapr1&&cent>10&&cent<=20) xpid_tofw_posproton_1_dis_cent1020->Fill(pT);
		      if(kapr1&&cent>20&&cent<=40) xpid_tofw_posproton_1_dis_cent2040->Fill(pT);
		      if(kapr1&&cent>40&&cent<=60) xpid_tofw_posproton_1_dis_cent4060->Fill(pT);
		      if(kapr1&&cent>60&&cent<=92) xpid_tofw_posproton_1_dis_cent6092->Fill(pT);
		      if(kapr2&&cent> 0&&cent<=10) xpid_tofw_posproton_2_dis_cent0010->Fill(pT);
		      if(kapr2&&cent>10&&cent<=20) xpid_tofw_posproton_2_dis_cent1020->Fill(pT);
		      if(kapr2&&cent>20&&cent<=40) xpid_tofw_posproton_2_dis_cent2040->Fill(pT);
		      if(kapr2&&cent>40&&cent<=60) xpid_tofw_posproton_2_dis_cent4060->Fill(pT);
		      if(kapr2&&cent>60&&cent<=92) xpid_tofw_posproton_2_dis_cent6092->Fill(pT);
		    }
		  if(charge<0)
		    {
		      if(pika0&&cent> 0&&cent<=10) xpid_tofw_negpion_0_dis_cent0010->Fill(pT);
		      if(pika0&&cent>10&&cent<=20) xpid_tofw_negpion_0_dis_cent1020->Fill(pT);
		      if(pika0&&cent>20&&cent<=40) xpid_tofw_negpion_0_dis_cent2040->Fill(pT);
		      if(pika0&&cent>40&&cent<=60) xpid_tofw_negpion_0_dis_cent4060->Fill(pT);
		      if(pika0&&cent>60&&cent<=92) xpid_tofw_negpion_0_dis_cent6092->Fill(pT);
		      if(pika1&&cent> 0&&cent<=10) xpid_tofw_negpion_1_dis_cent0010->Fill(pT);
		      if(pika1&&cent>10&&cent<=20) xpid_tofw_negpion_1_dis_cent1020->Fill(pT);
		      if(pika1&&cent>20&&cent<=40) xpid_tofw_negpion_1_dis_cent2040->Fill(pT);
		      if(pika1&&cent>40&&cent<=60) xpid_tofw_negpion_1_dis_cent4060->Fill(pT);
		      if(pika1&&cent>60&&cent<=92) xpid_tofw_negpion_1_dis_cent6092->Fill(pT);
		      if(pika2&&cent> 0&&cent<=10) xpid_tofw_negpion_2_dis_cent0010->Fill(pT);
		      if(pika2&&cent>10&&cent<=20) xpid_tofw_negpion_2_dis_cent1020->Fill(pT);
		      if(pika2&&cent>20&&cent<=40) xpid_tofw_negpion_2_dis_cent2040->Fill(pT);
		      if(pika2&&cent>40&&cent<=60) xpid_tofw_negpion_2_dis_cent4060->Fill(pT);
		      if(pika2&&cent>60&&cent<=92) xpid_tofw_negpion_2_dis_cent6092->Fill(pT);
		      if(kapr0&&cent> 0&&cent<=10) xpid_tofw_negproton_0_dis_cent0010->Fill(pT);
		      if(kapr0&&cent>10&&cent<=20) xpid_tofw_negproton_0_dis_cent1020->Fill(pT);
		      if(kapr0&&cent>20&&cent<=40) xpid_tofw_negproton_0_dis_cent2040->Fill(pT);
		      if(kapr0&&cent>40&&cent<=60) xpid_tofw_negproton_0_dis_cent4060->Fill(pT);
		      if(kapr0&&cent>60&&cent<=92) xpid_tofw_negproton_0_dis_cent6092->Fill(pT);
		      if(kapr1&&cent> 0&&cent<=10) xpid_tofw_negproton_1_dis_cent0010->Fill(pT);
		      if(kapr1&&cent>10&&cent<=20) xpid_tofw_negproton_1_dis_cent1020->Fill(pT);
		      if(kapr1&&cent>20&&cent<=40) xpid_tofw_negproton_1_dis_cent2040->Fill(pT);
		      if(kapr1&&cent>40&&cent<=60) xpid_tofw_negproton_1_dis_cent4060->Fill(pT);
		      if(kapr1&&cent>60&&cent<=92) xpid_tofw_negproton_1_dis_cent6092->Fill(pT);
		      if(kapr2&&cent> 0&&cent<=10) xpid_tofw_negproton_2_dis_cent0010->Fill(pT);
		      if(kapr2&&cent>10&&cent<=20) xpid_tofw_negproton_2_dis_cent1020->Fill(pT);
		      if(kapr2&&cent>20&&cent<=40) xpid_tofw_negproton_2_dis_cent2040->Fill(pT);
		      if(kapr2&&cent>40&&cent<=60) xpid_tofw_negproton_2_dis_cent4060->Fill(pT);
		      if(kapr2&&cent>60&&cent<=92) xpid_tofw_negproton_2_dis_cent6092->Fill(pT);
		    }
		}


	      // sector and charge
	      bool w1pos = charge>0 && striptofw>=0 && striptofw<=255;
	      bool w1neg = charge<0 && striptofw>=0 && striptofw<=255;
	      bool w2pos = charge>0 && striptofw>=256 && striptofw<=511;
	      bool w2neg = charge<0 && striptofw>=256 && striptofw<=511;

	      // bool dis0 = piondis3;
	      // bool dis1 = piondis3 && good_emc && ep>0.2;
	      // bool dis2 = (pT>=3.0)?dis1:dis0;
	      // //bool dis3 = (pT>=4.0)?dis1:dis0;
	      // //bool dis3 = piondis3 && fabs(bbcz)<10.0 && fabs(zed)<40.0;
	      // bool dis3 = piondis3 && fabs(bbcz)<30.0 && fabs(zed)<40.0;
	      // bool dis4 = kaondis3;
	      // bool dis5 = kaondis3 && tfw_HM && pc3_HM;
	      // bool dis6 = protondis3;
	      // bool dis7 = protondis3 && good_emc && ep>0.2;
	      // bool dis8 = (pT>=3.0)?dis7:dis6;
	      // //bool dis9 = (pT>=4.0)?dis7:dis6;
	      // //bool dis9 = protondis3 && fabs(bbcz)<10.0 && fabs(zed)<40.0;
	      // bool dis9 = protondis3 && fabs(bbcz)<30.0 && fabs(zed)<40.0;

	      bool dis0 = piondis3;
	      bool dis1 = piondis0;
	      bool dis2 = (pT>=3.0)?(dis0&&good_emc&&ep>0.2):dis0;
	      bool dis3 = (pT>=3.0)?(dis1&&good_emc&&ep>0.2):dis1;
	      bool dis4 = kaondis3;
	      bool dis5 = kaondis3 && tfw_HM && pc3_HM;
	      bool dis6 = protondis3;
	      bool dis7 = protondis0;
	      bool dis8 = (pT>=3.0)?(dis6&&good_emc&&ep>0.2):dis6;
	      bool dis9 = (pT>=3.0)?(dis7&&good_emc&&ep>0.2):dis7;

	      bool piA = piondis2;
	      bool kaA = kaondis2;
	      bool prA = protondis2;
	      bool piB = piondis4;
	      bool kaB = kaondis4;
	      bool prB = protondis4;

	      bool piX = isPi>=-1.5 && isPi<=1.5 && isK<=-2;
	      bool kaX = isK>=-1.5 && isK<=1.5 && isPi>=2 && isP<=-2;
	      bool prX = isP>=-1.5 && isP<=1.5 && isK>=2;
	      bool piY = isPi>=-2 && isPi<=2 && isK<=-2.5;
	      bool kaY = isK>=-2 && isK<=2 && isPi>=2.5 && isP<=-2.5;
	      bool prY = isP>=-2 && isP<=2 && isK>=2.5;

	      bool good_dcfc = edge && inner; // define DC fiducial cut
	      //regular_cuts &= good_dcfc; // do NOT redefine
	      // redefine the sytematics to include dcfc
	      syst_tfwmatch &= good_dcfc;
	      syst_pc3match &= good_dcfc;
	      syst_pc3fiducial &= good_dcfc;
	      syst_pc1fiducial &= good_dcfc;
	      syst_goodadc &= good_dcfc;
	      bool syst_dcfc = regular_cuts;

	      // ------------------------------------------ //
	      // --- new pid experimentation histograms --- //
	      // ------------------------------------------ //
	      
	      // pions
	      bool distofwpion0 = isPiLME>=-2 && isPiLME<=2 && isKLME<=-2 ;
	      bool distofwpion1 = isPiLME>=-2 && isPiLME<=0 ;
	      bool distofwpion2 = isPiLow>=-2 && isPiLow<=0 ;
	      bool distofwpion3 = isPiPDI>=-2 && isPiPDI<=2 && isKPDI<=-2 ; // real only (LME in sim)
	      bool distofwpion4 = isPiPDI>=-2 && isPiPDI<=2 && isKPDI<=-2 ; // sim and real
	      bool distofwpion5 = isPiLME>=-2 && isPiLME<=2 ;
	      //kaons
	      bool distofwkaon0 = isKLME>=-2 && isKLME<=2 && isPiLME>=2 && isPLME<=-2 ;
	      bool distofwkaon1 = isKLow>=-2 && isKLow<=2 && isPiLow>=2 && isPLow<=-2 ;
	      bool distofwkaon2 = isKANA>=-2 && isKANA<=2 && isPiANA>=2 && isPANA<=-2 ;
	      bool distofwkaon3 = isKPDI>=-2 && isKPDI<=2 && isPiPDI>=2 && isPPDI<=-2 ; // real only (LME in sim)
	      bool distofwkaon4 = isKPDI>=-2 && isKPDI<=2 && isPiPDI>=2 && isPPDI<=-2 ; // sim and real
	      bool distofwkaon5 = isKLow>=-2 && isKLow<=2 ;
	      // protons
	      bool distofwproton0 = isPLME>=-2 && isPLME<=2 && isKLME>=2 ;
	      bool distofwproton1 = isPLME>= 0 && isPLME<=2 ;
	      bool distofwproton2 = isPLow>= 0 && isPLow<=2 ;
	      bool distofwproton3 = isPPDI>=-2 && isPPDI<=2 && isKPDI>=2 ; // real only (LME in sim)
	      bool distofwproton4 = isPPDI>=-2 && isPPDI<=2 && isKPDI>=2 ; // sim and real
	      bool distofwproton5 = isPLow>=-2 && isPLow<=2 ;

	      // emc stuff
	      bool tfecpion = isPiLME>=-2 && isPiLME<=2 && isKLME<=-2 && good_emc;
	      bool tfeckaon = isKLME>=-2 && isKLME<=2 && isPiLME>=2 && isPLME<=-2 && good_emc;
	      bool tfecproton = isPLME>=-2 && isPLME<=2 && isKLME>=2 && good_emc;
	      bool distfec1 = ecore/pT>0.2;                    
	      bool distfec2 = ecore>0.3;
	      bool distfec3 = ecore>0.5;
	      bool distfec4 = ecore>1.0;                       
	      bool distfec5 = ecent/ecore<0.55; // compactness cut, see e.g. AN330
	      //pions
	      bool distfecpion0 = tfecpion;
	      bool distfecpion1 = tfecpion && distfec1;
	      bool distfecpion2 = tfecpion && distfec2;
	      bool distfecpion3 = tfecpion && distfec3;
	      bool distfecpion4 = tfecpion && distfec4;
	      bool distfecpion5 = tfecpion && distfec5;
	      //kaons
	      bool distfeckaon0 = tfeckaon;            
	      bool distfeckaon1 = tfeckaon && distfec1;
	      bool distfeckaon2 = tfeckaon && distfec2;
	      bool distfeckaon3 = tfeckaon && distfec3;
	      bool distfeckaon4 = tfeckaon && distfec4;
	      bool distfeckaon5 = tfeckaon && distfec5;
	      // protons
	      bool distfecproton0 = tfecproton;            
	      bool distfecproton1 = tfecproton && distfec1;
	      bool distfecproton2 = tfecproton && distfec2;
	      bool distfecproton3 = tfecproton && distfec3;
	      bool distfecproton4 = tfecproton && distfec4;
	      bool distfecproton5 = tfecproton && distfec5;

	      //if(regular_cuts&&edge&&inner) // new, test
	      if(regular_cuts&&good_dcfc)
		{
		  if(charge>0)
		    {
		      //now pion
		      //dis0
		      if(distofwpion0&&cent> 0&&cent<=10) hhptpid_tofw_pospion_0_dis_cent0010->Fill(pT);
		      if(distofwpion0&&cent>10&&cent<=20) hhptpid_tofw_pospion_0_dis_cent1020->Fill(pT);
		      if(distofwpion0&&cent>20&&cent<=40) hhptpid_tofw_pospion_0_dis_cent2040->Fill(pT);
		      if(distofwpion0&&cent>40&&cent<=60) hhptpid_tofw_pospion_0_dis_cent4060->Fill(pT);
		      if(distofwpion0&&cent>60&&cent<=92) hhptpid_tofw_pospion_0_dis_cent6092->Fill(pT);
		      if(distfecpion0&&cent> 0&&cent<=10) hhptpid_tfec_pospion_0_dis_cent0010->Fill(pT);
		      if(distfecpion0&&cent>10&&cent<=20) hhptpid_tfec_pospion_0_dis_cent1020->Fill(pT);
		      if(distfecpion0&&cent>20&&cent<=40) hhptpid_tfec_pospion_0_dis_cent2040->Fill(pT);
		      if(distfecpion0&&cent>40&&cent<=60) hhptpid_tfec_pospion_0_dis_cent4060->Fill(pT);
		      if(distfecpion0&&cent>60&&cent<=92) hhptpid_tfec_pospion_0_dis_cent6092->Fill(pT);
		      //dis1
		      if(distofwpion1&&cent> 0&&cent<=10) hhptpid_tofw_pospion_1_dis_cent0010->Fill(pT);
		      if(distofwpion1&&cent>10&&cent<=20) hhptpid_tofw_pospion_1_dis_cent1020->Fill(pT);
		      if(distofwpion1&&cent>20&&cent<=40) hhptpid_tofw_pospion_1_dis_cent2040->Fill(pT);
		      if(distofwpion1&&cent>40&&cent<=60) hhptpid_tofw_pospion_1_dis_cent4060->Fill(pT);
		      if(distofwpion1&&cent>60&&cent<=92) hhptpid_tofw_pospion_1_dis_cent6092->Fill(pT);
		      if(distfecpion1&&cent> 0&&cent<=10) hhptpid_tfec_pospion_1_dis_cent0010->Fill(pT);
		      if(distfecpion1&&cent>10&&cent<=20) hhptpid_tfec_pospion_1_dis_cent1020->Fill(pT);
		      if(distfecpion1&&cent>20&&cent<=40) hhptpid_tfec_pospion_1_dis_cent2040->Fill(pT);
		      if(distfecpion1&&cent>40&&cent<=60) hhptpid_tfec_pospion_1_dis_cent4060->Fill(pT);
		      if(distfecpion1&&cent>60&&cent<=92) hhptpid_tfec_pospion_1_dis_cent6092->Fill(pT);
		      //dis2
		      if(distofwpion2&&cent> 0&&cent<=10) hhptpid_tofw_pospion_2_dis_cent0010->Fill(pT);
		      if(distofwpion2&&cent>10&&cent<=20) hhptpid_tofw_pospion_2_dis_cent1020->Fill(pT);
		      if(distofwpion2&&cent>20&&cent<=40) hhptpid_tofw_pospion_2_dis_cent2040->Fill(pT);
		      if(distofwpion2&&cent>40&&cent<=60) hhptpid_tofw_pospion_2_dis_cent4060->Fill(pT);
		      if(distofwpion2&&cent>60&&cent<=92) hhptpid_tofw_pospion_2_dis_cent6092->Fill(pT);
		      if(distfecpion2&&cent> 0&&cent<=10) hhptpid_tfec_pospion_2_dis_cent0010->Fill(pT);
		      if(distfecpion2&&cent>10&&cent<=20) hhptpid_tfec_pospion_2_dis_cent1020->Fill(pT);
		      if(distfecpion2&&cent>20&&cent<=40) hhptpid_tfec_pospion_2_dis_cent2040->Fill(pT);
		      if(distfecpion2&&cent>40&&cent<=60) hhptpid_tfec_pospion_2_dis_cent4060->Fill(pT);
		      if(distfecpion2&&cent>60&&cent<=92) hhptpid_tfec_pospion_2_dis_cent6092->Fill(pT);
		      //dis3
		      if(distofwpion3&&cent> 0&&cent<=10) hhptpid_tofw_pospion_3_dis_cent0010->Fill(pT);
		      if(distofwpion3&&cent>10&&cent<=20) hhptpid_tofw_pospion_3_dis_cent1020->Fill(pT);
		      if(distofwpion3&&cent>20&&cent<=40) hhptpid_tofw_pospion_3_dis_cent2040->Fill(pT);
		      if(distofwpion3&&cent>40&&cent<=60) hhptpid_tofw_pospion_3_dis_cent4060->Fill(pT);
		      if(distofwpion3&&cent>60&&cent<=92) hhptpid_tofw_pospion_3_dis_cent6092->Fill(pT);
		      if(distfecpion3&&cent> 0&&cent<=10) hhptpid_tfec_pospion_3_dis_cent0010->Fill(pT);
		      if(distfecpion3&&cent>10&&cent<=20) hhptpid_tfec_pospion_3_dis_cent1020->Fill(pT);
		      if(distfecpion3&&cent>20&&cent<=40) hhptpid_tfec_pospion_3_dis_cent2040->Fill(pT);
		      if(distfecpion3&&cent>40&&cent<=60) hhptpid_tfec_pospion_3_dis_cent4060->Fill(pT);
		      if(distfecpion3&&cent>60&&cent<=92) hhptpid_tfec_pospion_3_dis_cent6092->Fill(pT);
		      //dis4
		      if(distofwpion4&&cent> 0&&cent<=10) hhptpid_tofw_pospion_4_dis_cent0010->Fill(pT);
		      if(distofwpion4&&cent>10&&cent<=20) hhptpid_tofw_pospion_4_dis_cent1020->Fill(pT);
		      if(distofwpion4&&cent>20&&cent<=40) hhptpid_tofw_pospion_4_dis_cent2040->Fill(pT);
		      if(distofwpion4&&cent>40&&cent<=60) hhptpid_tofw_pospion_4_dis_cent4060->Fill(pT);
		      if(distofwpion4&&cent>60&&cent<=92) hhptpid_tofw_pospion_4_dis_cent6092->Fill(pT);
		      if(distfecpion4&&cent> 0&&cent<=10) hhptpid_tfec_pospion_4_dis_cent0010->Fill(pT);
		      if(distfecpion4&&cent>10&&cent<=20) hhptpid_tfec_pospion_4_dis_cent1020->Fill(pT);
		      if(distfecpion4&&cent>20&&cent<=40) hhptpid_tfec_pospion_4_dis_cent2040->Fill(pT);
		      if(distfecpion4&&cent>40&&cent<=60) hhptpid_tfec_pospion_4_dis_cent4060->Fill(pT);
		      if(distfecpion4&&cent>60&&cent<=92) hhptpid_tfec_pospion_4_dis_cent6092->Fill(pT);
		      //dis5
		      if(distofwpion5&&cent> 0&&cent<=10) hhptpid_tofw_pospion_5_dis_cent0010->Fill(pT);
		      if(distofwpion5&&cent>10&&cent<=20) hhptpid_tofw_pospion_5_dis_cent1020->Fill(pT);
		      if(distofwpion5&&cent>20&&cent<=40) hhptpid_tofw_pospion_5_dis_cent2040->Fill(pT);
		      if(distofwpion5&&cent>40&&cent<=60) hhptpid_tofw_pospion_5_dis_cent4060->Fill(pT);
		      if(distofwpion5&&cent>60&&cent<=92) hhptpid_tofw_pospion_5_dis_cent6092->Fill(pT);
		      if(distfecpion5&&cent> 0&&cent<=10) hhptpid_tfec_pospion_5_dis_cent0010->Fill(pT);
		      if(distfecpion5&&cent>10&&cent<=20) hhptpid_tfec_pospion_5_dis_cent1020->Fill(pT);
		      if(distfecpion5&&cent>20&&cent<=40) hhptpid_tfec_pospion_5_dis_cent2040->Fill(pT);
		      if(distfecpion5&&cent>40&&cent<=60) hhptpid_tfec_pospion_5_dis_cent4060->Fill(pT);
		      if(distfecpion5&&cent>60&&cent<=92) hhptpid_tfec_pospion_5_dis_cent6092->Fill(pT);
		      //nowkaon
		      //dis0
		      if(distofwkaon0&&cent> 0&&cent<=10) hhptpid_tofw_poskaon_0_dis_cent0010->Fill(pT);
		      if(distofwkaon0&&cent>10&&cent<=20) hhptpid_tofw_poskaon_0_dis_cent1020->Fill(pT);
		      if(distofwkaon0&&cent>20&&cent<=40) hhptpid_tofw_poskaon_0_dis_cent2040->Fill(pT);
		      if(distofwkaon0&&cent>40&&cent<=60) hhptpid_tofw_poskaon_0_dis_cent4060->Fill(pT);
		      if(distofwkaon0&&cent>60&&cent<=92) hhptpid_tofw_poskaon_0_dis_cent6092->Fill(pT);
		      if(distfeckaon0&&cent> 0&&cent<=10) hhptpid_tfec_poskaon_0_dis_cent0010->Fill(pT);
		      if(distfeckaon0&&cent>10&&cent<=20) hhptpid_tfec_poskaon_0_dis_cent1020->Fill(pT);
		      if(distfeckaon0&&cent>20&&cent<=40) hhptpid_tfec_poskaon_0_dis_cent2040->Fill(pT);
		      if(distfeckaon0&&cent>40&&cent<=60) hhptpid_tfec_poskaon_0_dis_cent4060->Fill(pT);
		      if(distfeckaon0&&cent>60&&cent<=92) hhptpid_tfec_poskaon_0_dis_cent6092->Fill(pT);
		      //dis1
		      if(distofwkaon1&&cent> 0&&cent<=10) hhptpid_tofw_poskaon_1_dis_cent0010->Fill(pT);
		      if(distofwkaon1&&cent>10&&cent<=20) hhptpid_tofw_poskaon_1_dis_cent1020->Fill(pT);
		      if(distofwkaon1&&cent>20&&cent<=40) hhptpid_tofw_poskaon_1_dis_cent2040->Fill(pT);
		      if(distofwkaon1&&cent>40&&cent<=60) hhptpid_tofw_poskaon_1_dis_cent4060->Fill(pT);
		      if(distofwkaon1&&cent>60&&cent<=92) hhptpid_tofw_poskaon_1_dis_cent6092->Fill(pT);
		      if(distfeckaon1&&cent> 0&&cent<=10) hhptpid_tfec_poskaon_1_dis_cent0010->Fill(pT);
		      if(distfeckaon1&&cent>10&&cent<=20) hhptpid_tfec_poskaon_1_dis_cent1020->Fill(pT);
		      if(distfeckaon1&&cent>20&&cent<=40) hhptpid_tfec_poskaon_1_dis_cent2040->Fill(pT);
		      if(distfeckaon1&&cent>40&&cent<=60) hhptpid_tfec_poskaon_1_dis_cent4060->Fill(pT);
		      if(distfeckaon1&&cent>60&&cent<=92) hhptpid_tfec_poskaon_1_dis_cent6092->Fill(pT);
		      //dis2
		      if(distofwkaon2&&cent> 0&&cent<=10) hhptpid_tofw_poskaon_2_dis_cent0010->Fill(pT);
		      if(distofwkaon2&&cent>10&&cent<=20) hhptpid_tofw_poskaon_2_dis_cent1020->Fill(pT);
		      if(distofwkaon2&&cent>20&&cent<=40) hhptpid_tofw_poskaon_2_dis_cent2040->Fill(pT);
		      if(distofwkaon2&&cent>40&&cent<=60) hhptpid_tofw_poskaon_2_dis_cent4060->Fill(pT);
		      if(distofwkaon2&&cent>60&&cent<=92) hhptpid_tofw_poskaon_2_dis_cent6092->Fill(pT);
		      if(distfeckaon2&&cent> 0&&cent<=10) hhptpid_tfec_poskaon_2_dis_cent0010->Fill(pT);
		      if(distfeckaon2&&cent>10&&cent<=20) hhptpid_tfec_poskaon_2_dis_cent1020->Fill(pT);
		      if(distfeckaon2&&cent>20&&cent<=40) hhptpid_tfec_poskaon_2_dis_cent2040->Fill(pT);
		      if(distfeckaon2&&cent>40&&cent<=60) hhptpid_tfec_poskaon_2_dis_cent4060->Fill(pT);
		      if(distfeckaon2&&cent>60&&cent<=92) hhptpid_tfec_poskaon_2_dis_cent6092->Fill(pT);
		      //dis3
		      if(distofwkaon3&&cent> 0&&cent<=10) hhptpid_tofw_poskaon_3_dis_cent0010->Fill(pT);
		      if(distofwkaon3&&cent>10&&cent<=20) hhptpid_tofw_poskaon_3_dis_cent1020->Fill(pT);
		      if(distofwkaon3&&cent>20&&cent<=40) hhptpid_tofw_poskaon_3_dis_cent2040->Fill(pT);
		      if(distofwkaon3&&cent>40&&cent<=60) hhptpid_tofw_poskaon_3_dis_cent4060->Fill(pT);
		      if(distofwkaon3&&cent>60&&cent<=92) hhptpid_tofw_poskaon_3_dis_cent6092->Fill(pT);
		      if(distfeckaon3&&cent> 0&&cent<=10) hhptpid_tfec_poskaon_3_dis_cent0010->Fill(pT);
		      if(distfeckaon3&&cent>10&&cent<=20) hhptpid_tfec_poskaon_3_dis_cent1020->Fill(pT);
		      if(distfeckaon3&&cent>20&&cent<=40) hhptpid_tfec_poskaon_3_dis_cent2040->Fill(pT);
		      if(distfeckaon3&&cent>40&&cent<=60) hhptpid_tfec_poskaon_3_dis_cent4060->Fill(pT);
		      if(distfeckaon3&&cent>60&&cent<=92) hhptpid_tfec_poskaon_3_dis_cent6092->Fill(pT);
		      //dis4
		      if(distofwkaon4&&cent> 0&&cent<=10) hhptpid_tofw_poskaon_4_dis_cent0010->Fill(pT);
		      if(distofwkaon4&&cent>10&&cent<=20) hhptpid_tofw_poskaon_4_dis_cent1020->Fill(pT);
		      if(distofwkaon4&&cent>20&&cent<=40) hhptpid_tofw_poskaon_4_dis_cent2040->Fill(pT);
		      if(distofwkaon4&&cent>40&&cent<=60) hhptpid_tofw_poskaon_4_dis_cent4060->Fill(pT);
		      if(distofwkaon4&&cent>60&&cent<=92) hhptpid_tofw_poskaon_4_dis_cent6092->Fill(pT);
		      if(distfeckaon4&&cent> 0&&cent<=10) hhptpid_tfec_poskaon_4_dis_cent0010->Fill(pT);
		      if(distfeckaon4&&cent>10&&cent<=20) hhptpid_tfec_poskaon_4_dis_cent1020->Fill(pT);
		      if(distfeckaon4&&cent>20&&cent<=40) hhptpid_tfec_poskaon_4_dis_cent2040->Fill(pT);
		      if(distfeckaon4&&cent>40&&cent<=60) hhptpid_tfec_poskaon_4_dis_cent4060->Fill(pT);
		      if(distfeckaon4&&cent>60&&cent<=92) hhptpid_tfec_poskaon_4_dis_cent6092->Fill(pT);
		      //dis5
		      if(distofwkaon5&&cent> 0&&cent<=10) hhptpid_tofw_poskaon_5_dis_cent0010->Fill(pT);
		      if(distofwkaon5&&cent>10&&cent<=20) hhptpid_tofw_poskaon_5_dis_cent1020->Fill(pT);
		      if(distofwkaon5&&cent>20&&cent<=40) hhptpid_tofw_poskaon_5_dis_cent2040->Fill(pT);
		      if(distofwkaon5&&cent>40&&cent<=60) hhptpid_tofw_poskaon_5_dis_cent4060->Fill(pT);
		      if(distofwkaon5&&cent>60&&cent<=92) hhptpid_tofw_poskaon_5_dis_cent6092->Fill(pT);
		      if(distfeckaon5&&cent> 0&&cent<=10) hhptpid_tfec_poskaon_5_dis_cent0010->Fill(pT);
		      if(distfeckaon5&&cent>10&&cent<=20) hhptpid_tfec_poskaon_5_dis_cent1020->Fill(pT);
		      if(distfeckaon5&&cent>20&&cent<=40) hhptpid_tfec_poskaon_5_dis_cent2040->Fill(pT);
		      if(distfeckaon5&&cent>40&&cent<=60) hhptpid_tfec_poskaon_5_dis_cent4060->Fill(pT);
		      if(distfeckaon5&&cent>60&&cent<=92) hhptpid_tfec_poskaon_5_dis_cent6092->Fill(pT);
		      //nowproton
		      //dis0
		      if(distofwproton0&&cent> 0&&cent<=10) hhptpid_tofw_posproton_0_dis_cent0010->Fill(pT);
		      if(distofwproton0&&cent>10&&cent<=20) hhptpid_tofw_posproton_0_dis_cent1020->Fill(pT);
		      if(distofwproton0&&cent>20&&cent<=40) hhptpid_tofw_posproton_0_dis_cent2040->Fill(pT);
		      if(distofwproton0&&cent>40&&cent<=60) hhptpid_tofw_posproton_0_dis_cent4060->Fill(pT);
		      if(distofwproton0&&cent>60&&cent<=92) hhptpid_tofw_posproton_0_dis_cent6092->Fill(pT);
		      if(distfecproton0&&cent> 0&&cent<=10) hhptpid_tfec_posproton_0_dis_cent0010->Fill(pT);
		      if(distfecproton0&&cent>10&&cent<=20) hhptpid_tfec_posproton_0_dis_cent1020->Fill(pT);
		      if(distfecproton0&&cent>20&&cent<=40) hhptpid_tfec_posproton_0_dis_cent2040->Fill(pT);
		      if(distfecproton0&&cent>40&&cent<=60) hhptpid_tfec_posproton_0_dis_cent4060->Fill(pT);
		      if(distfecproton0&&cent>60&&cent<=92) hhptpid_tfec_posproton_0_dis_cent6092->Fill(pT);
		      //dis1
		      if(distofwproton1&&cent> 0&&cent<=10) hhptpid_tofw_posproton_1_dis_cent0010->Fill(pT);
		      if(distofwproton1&&cent>10&&cent<=20) hhptpid_tofw_posproton_1_dis_cent1020->Fill(pT);
		      if(distofwproton1&&cent>20&&cent<=40) hhptpid_tofw_posproton_1_dis_cent2040->Fill(pT);
		      if(distofwproton1&&cent>40&&cent<=60) hhptpid_tofw_posproton_1_dis_cent4060->Fill(pT);
		      if(distofwproton1&&cent>60&&cent<=92) hhptpid_tofw_posproton_1_dis_cent6092->Fill(pT);
		      if(distfecproton1&&cent> 0&&cent<=10) hhptpid_tfec_posproton_1_dis_cent0010->Fill(pT);
		      if(distfecproton1&&cent>10&&cent<=20) hhptpid_tfec_posproton_1_dis_cent1020->Fill(pT);
		      if(distfecproton1&&cent>20&&cent<=40) hhptpid_tfec_posproton_1_dis_cent2040->Fill(pT);
		      if(distfecproton1&&cent>40&&cent<=60) hhptpid_tfec_posproton_1_dis_cent4060->Fill(pT);
		      if(distfecproton1&&cent>60&&cent<=92) hhptpid_tfec_posproton_1_dis_cent6092->Fill(pT);
		      //dis2
		      if(distofwproton2&&cent> 0&&cent<=10) hhptpid_tofw_posproton_2_dis_cent0010->Fill(pT);
		      if(distofwproton2&&cent>10&&cent<=20) hhptpid_tofw_posproton_2_dis_cent1020->Fill(pT);
		      if(distofwproton2&&cent>20&&cent<=40) hhptpid_tofw_posproton_2_dis_cent2040->Fill(pT);
		      if(distofwproton2&&cent>40&&cent<=60) hhptpid_tofw_posproton_2_dis_cent4060->Fill(pT);
		      if(distofwproton2&&cent>60&&cent<=92) hhptpid_tofw_posproton_2_dis_cent6092->Fill(pT);
		      if(distfecproton2&&cent> 0&&cent<=10) hhptpid_tfec_posproton_2_dis_cent0010->Fill(pT);
		      if(distfecproton2&&cent>10&&cent<=20) hhptpid_tfec_posproton_2_dis_cent1020->Fill(pT);
		      if(distfecproton2&&cent>20&&cent<=40) hhptpid_tfec_posproton_2_dis_cent2040->Fill(pT);
		      if(distfecproton2&&cent>40&&cent<=60) hhptpid_tfec_posproton_2_dis_cent4060->Fill(pT);
		      if(distfecproton2&&cent>60&&cent<=92) hhptpid_tfec_posproton_2_dis_cent6092->Fill(pT);
		      //dis3
		      if(distofwproton3&&cent> 0&&cent<=10) hhptpid_tofw_posproton_3_dis_cent0010->Fill(pT);
		      if(distofwproton3&&cent>10&&cent<=20) hhptpid_tofw_posproton_3_dis_cent1020->Fill(pT);
		      if(distofwproton3&&cent>20&&cent<=40) hhptpid_tofw_posproton_3_dis_cent2040->Fill(pT);
		      if(distofwproton3&&cent>40&&cent<=60) hhptpid_tofw_posproton_3_dis_cent4060->Fill(pT);
		      if(distofwproton3&&cent>60&&cent<=92) hhptpid_tofw_posproton_3_dis_cent6092->Fill(pT);
		      if(distfecproton3&&cent> 0&&cent<=10) hhptpid_tfec_posproton_3_dis_cent0010->Fill(pT);
		      if(distfecproton3&&cent>10&&cent<=20) hhptpid_tfec_posproton_3_dis_cent1020->Fill(pT);
		      if(distfecproton3&&cent>20&&cent<=40) hhptpid_tfec_posproton_3_dis_cent2040->Fill(pT);
		      if(distfecproton3&&cent>40&&cent<=60) hhptpid_tfec_posproton_3_dis_cent4060->Fill(pT);
		      if(distfecproton3&&cent>60&&cent<=92) hhptpid_tfec_posproton_3_dis_cent6092->Fill(pT);
		      //dis4
		      if(distofwproton4&&cent> 0&&cent<=10) hhptpid_tofw_posproton_4_dis_cent0010->Fill(pT);
		      if(distofwproton4&&cent>10&&cent<=20) hhptpid_tofw_posproton_4_dis_cent1020->Fill(pT);
		      if(distofwproton4&&cent>20&&cent<=40) hhptpid_tofw_posproton_4_dis_cent2040->Fill(pT);
		      if(distofwproton4&&cent>40&&cent<=60) hhptpid_tofw_posproton_4_dis_cent4060->Fill(pT);
		      if(distofwproton4&&cent>60&&cent<=92) hhptpid_tofw_posproton_4_dis_cent6092->Fill(pT);
		      if(distfecproton4&&cent> 0&&cent<=10) hhptpid_tfec_posproton_4_dis_cent0010->Fill(pT);
		      if(distfecproton4&&cent>10&&cent<=20) hhptpid_tfec_posproton_4_dis_cent1020->Fill(pT);
		      if(distfecproton4&&cent>20&&cent<=40) hhptpid_tfec_posproton_4_dis_cent2040->Fill(pT);
		      if(distfecproton4&&cent>40&&cent<=60) hhptpid_tfec_posproton_4_dis_cent4060->Fill(pT);
		      if(distfecproton4&&cent>60&&cent<=92) hhptpid_tfec_posproton_4_dis_cent6092->Fill(pT);
		      //dis5
		      if(distofwproton5&&cent> 0&&cent<=10) hhptpid_tofw_posproton_5_dis_cent0010->Fill(pT);
		      if(distofwproton5&&cent>10&&cent<=20) hhptpid_tofw_posproton_5_dis_cent1020->Fill(pT);
		      if(distofwproton5&&cent>20&&cent<=40) hhptpid_tofw_posproton_5_dis_cent2040->Fill(pT);
		      if(distofwproton5&&cent>40&&cent<=60) hhptpid_tofw_posproton_5_dis_cent4060->Fill(pT);
		      if(distofwproton5&&cent>60&&cent<=92) hhptpid_tofw_posproton_5_dis_cent6092->Fill(pT);
		      if(distfecproton5&&cent> 0&&cent<=10) hhptpid_tfec_posproton_5_dis_cent0010->Fill(pT);
		      if(distfecproton5&&cent>10&&cent<=20) hhptpid_tfec_posproton_5_dis_cent1020->Fill(pT);
		      if(distfecproton5&&cent>20&&cent<=40) hhptpid_tfec_posproton_5_dis_cent2040->Fill(pT);
		      if(distfecproton5&&cent>40&&cent<=60) hhptpid_tfec_posproton_5_dis_cent4060->Fill(pT);
		      if(distfecproton5&&cent>60&&cent<=92) hhptpid_tfec_posproton_5_dis_cent6092->Fill(pT);
		    }//pos
		  if(charge<0)
		    {
		      //now pion
		      //dis0
		      if(distofwpion0&&cent> 0&&cent<=10) hhptpid_tofw_negpion_0_dis_cent0010->Fill(pT);
		      if(distofwpion0&&cent>10&&cent<=20) hhptpid_tofw_negpion_0_dis_cent1020->Fill(pT);
		      if(distofwpion0&&cent>20&&cent<=40) hhptpid_tofw_negpion_0_dis_cent2040->Fill(pT);
		      if(distofwpion0&&cent>40&&cent<=60) hhptpid_tofw_negpion_0_dis_cent4060->Fill(pT);
		      if(distofwpion0&&cent>60&&cent<=92) hhptpid_tofw_negpion_0_dis_cent6092->Fill(pT);
		      if(distfecpion0&&cent> 0&&cent<=10) hhptpid_tfec_negpion_0_dis_cent0010->Fill(pT);
		      if(distfecpion0&&cent>10&&cent<=20) hhptpid_tfec_negpion_0_dis_cent1020->Fill(pT);
		      if(distfecpion0&&cent>20&&cent<=40) hhptpid_tfec_negpion_0_dis_cent2040->Fill(pT);
		      if(distfecpion0&&cent>40&&cent<=60) hhptpid_tfec_negpion_0_dis_cent4060->Fill(pT);
		      if(distfecpion0&&cent>60&&cent<=92) hhptpid_tfec_negpion_0_dis_cent6092->Fill(pT);
		      //dis1
		      if(distofwpion1&&cent> 0&&cent<=10) hhptpid_tofw_negpion_1_dis_cent0010->Fill(pT);
		      if(distofwpion1&&cent>10&&cent<=20) hhptpid_tofw_negpion_1_dis_cent1020->Fill(pT);
		      if(distofwpion1&&cent>20&&cent<=40) hhptpid_tofw_negpion_1_dis_cent2040->Fill(pT);
		      if(distofwpion1&&cent>40&&cent<=60) hhptpid_tofw_negpion_1_dis_cent4060->Fill(pT);
		      if(distofwpion1&&cent>60&&cent<=92) hhptpid_tofw_negpion_1_dis_cent6092->Fill(pT);
		      if(distfecpion1&&cent> 0&&cent<=10) hhptpid_tfec_negpion_1_dis_cent0010->Fill(pT);
		      if(distfecpion1&&cent>10&&cent<=20) hhptpid_tfec_negpion_1_dis_cent1020->Fill(pT);
		      if(distfecpion1&&cent>20&&cent<=40) hhptpid_tfec_negpion_1_dis_cent2040->Fill(pT);
		      if(distfecpion1&&cent>40&&cent<=60) hhptpid_tfec_negpion_1_dis_cent4060->Fill(pT);
		      if(distfecpion1&&cent>60&&cent<=92) hhptpid_tfec_negpion_1_dis_cent6092->Fill(pT);
		      //dis2
		      if(distofwpion2&&cent> 0&&cent<=10) hhptpid_tofw_negpion_2_dis_cent0010->Fill(pT);
		      if(distofwpion2&&cent>10&&cent<=20) hhptpid_tofw_negpion_2_dis_cent1020->Fill(pT);
		      if(distofwpion2&&cent>20&&cent<=40) hhptpid_tofw_negpion_2_dis_cent2040->Fill(pT);
		      if(distofwpion2&&cent>40&&cent<=60) hhptpid_tofw_negpion_2_dis_cent4060->Fill(pT);
		      if(distofwpion2&&cent>60&&cent<=92) hhptpid_tofw_negpion_2_dis_cent6092->Fill(pT);
		      if(distfecpion2&&cent> 0&&cent<=10) hhptpid_tfec_negpion_2_dis_cent0010->Fill(pT);
		      if(distfecpion2&&cent>10&&cent<=20) hhptpid_tfec_negpion_2_dis_cent1020->Fill(pT);
		      if(distfecpion2&&cent>20&&cent<=40) hhptpid_tfec_negpion_2_dis_cent2040->Fill(pT);
		      if(distfecpion2&&cent>40&&cent<=60) hhptpid_tfec_negpion_2_dis_cent4060->Fill(pT);
		      if(distfecpion2&&cent>60&&cent<=92) hhptpid_tfec_negpion_2_dis_cent6092->Fill(pT);
		      //dis3
		      if(distofwpion3&&cent> 0&&cent<=10) hhptpid_tofw_negpion_3_dis_cent0010->Fill(pT);
		      if(distofwpion3&&cent>10&&cent<=20) hhptpid_tofw_negpion_3_dis_cent1020->Fill(pT);
		      if(distofwpion3&&cent>20&&cent<=40) hhptpid_tofw_negpion_3_dis_cent2040->Fill(pT);
		      if(distofwpion3&&cent>40&&cent<=60) hhptpid_tofw_negpion_3_dis_cent4060->Fill(pT);
		      if(distofwpion3&&cent>60&&cent<=92) hhptpid_tofw_negpion_3_dis_cent6092->Fill(pT);
		      if(distfecpion3&&cent> 0&&cent<=10) hhptpid_tfec_negpion_3_dis_cent0010->Fill(pT);
		      if(distfecpion3&&cent>10&&cent<=20) hhptpid_tfec_negpion_3_dis_cent1020->Fill(pT);
		      if(distfecpion3&&cent>20&&cent<=40) hhptpid_tfec_negpion_3_dis_cent2040->Fill(pT);
		      if(distfecpion3&&cent>40&&cent<=60) hhptpid_tfec_negpion_3_dis_cent4060->Fill(pT);
		      if(distfecpion3&&cent>60&&cent<=92) hhptpid_tfec_negpion_3_dis_cent6092->Fill(pT);
		      //dis4
		      if(distofwpion4&&cent> 0&&cent<=10) hhptpid_tofw_negpion_4_dis_cent0010->Fill(pT);
		      if(distofwpion4&&cent>10&&cent<=20) hhptpid_tofw_negpion_4_dis_cent1020->Fill(pT);
		      if(distofwpion4&&cent>20&&cent<=40) hhptpid_tofw_negpion_4_dis_cent2040->Fill(pT);
		      if(distofwpion4&&cent>40&&cent<=60) hhptpid_tofw_negpion_4_dis_cent4060->Fill(pT);
		      if(distofwpion4&&cent>60&&cent<=92) hhptpid_tofw_negpion_4_dis_cent6092->Fill(pT);
		      if(distfecpion4&&cent> 0&&cent<=10) hhptpid_tfec_negpion_4_dis_cent0010->Fill(pT);
		      if(distfecpion4&&cent>10&&cent<=20) hhptpid_tfec_negpion_4_dis_cent1020->Fill(pT);
		      if(distfecpion4&&cent>20&&cent<=40) hhptpid_tfec_negpion_4_dis_cent2040->Fill(pT);
		      if(distfecpion4&&cent>40&&cent<=60) hhptpid_tfec_negpion_4_dis_cent4060->Fill(pT);
		      if(distfecpion4&&cent>60&&cent<=92) hhptpid_tfec_negpion_4_dis_cent6092->Fill(pT);
		      //dis5
		      if(distofwpion5&&cent> 0&&cent<=10) hhptpid_tofw_negpion_5_dis_cent0010->Fill(pT);
		      if(distofwpion5&&cent>10&&cent<=20) hhptpid_tofw_negpion_5_dis_cent1020->Fill(pT);
		      if(distofwpion5&&cent>20&&cent<=40) hhptpid_tofw_negpion_5_dis_cent2040->Fill(pT);
		      if(distofwpion5&&cent>40&&cent<=60) hhptpid_tofw_negpion_5_dis_cent4060->Fill(pT);
		      if(distofwpion5&&cent>60&&cent<=92) hhptpid_tofw_negpion_5_dis_cent6092->Fill(pT);
		      if(distfecpion5&&cent> 0&&cent<=10) hhptpid_tfec_negpion_5_dis_cent0010->Fill(pT);
		      if(distfecpion5&&cent>10&&cent<=20) hhptpid_tfec_negpion_5_dis_cent1020->Fill(pT);
		      if(distfecpion5&&cent>20&&cent<=40) hhptpid_tfec_negpion_5_dis_cent2040->Fill(pT);
		      if(distfecpion5&&cent>40&&cent<=60) hhptpid_tfec_negpion_5_dis_cent4060->Fill(pT);
		      if(distfecpion5&&cent>60&&cent<=92) hhptpid_tfec_negpion_5_dis_cent6092->Fill(pT);
		      //nowkaon
		      //dis0
		      if(distofwkaon0&&cent> 0&&cent<=10) hhptpid_tofw_negkaon_0_dis_cent0010->Fill(pT);
		      if(distofwkaon0&&cent>10&&cent<=20) hhptpid_tofw_negkaon_0_dis_cent1020->Fill(pT);
		      if(distofwkaon0&&cent>20&&cent<=40) hhptpid_tofw_negkaon_0_dis_cent2040->Fill(pT);
		      if(distofwkaon0&&cent>40&&cent<=60) hhptpid_tofw_negkaon_0_dis_cent4060->Fill(pT);
		      if(distofwkaon0&&cent>60&&cent<=92) hhptpid_tofw_negkaon_0_dis_cent6092->Fill(pT);
		      if(distfeckaon0&&cent> 0&&cent<=10) hhptpid_tfec_negkaon_0_dis_cent0010->Fill(pT);
		      if(distfeckaon0&&cent>10&&cent<=20) hhptpid_tfec_negkaon_0_dis_cent1020->Fill(pT);
		      if(distfeckaon0&&cent>20&&cent<=40) hhptpid_tfec_negkaon_0_dis_cent2040->Fill(pT);
		      if(distfeckaon0&&cent>40&&cent<=60) hhptpid_tfec_negkaon_0_dis_cent4060->Fill(pT);
		      if(distfeckaon0&&cent>60&&cent<=92) hhptpid_tfec_negkaon_0_dis_cent6092->Fill(pT);
		      //dis1
		      if(distofwkaon1&&cent> 0&&cent<=10) hhptpid_tofw_negkaon_1_dis_cent0010->Fill(pT);
		      if(distofwkaon1&&cent>10&&cent<=20) hhptpid_tofw_negkaon_1_dis_cent1020->Fill(pT);
		      if(distofwkaon1&&cent>20&&cent<=40) hhptpid_tofw_negkaon_1_dis_cent2040->Fill(pT);
		      if(distofwkaon1&&cent>40&&cent<=60) hhptpid_tofw_negkaon_1_dis_cent4060->Fill(pT);
		      if(distofwkaon1&&cent>60&&cent<=92) hhptpid_tofw_negkaon_1_dis_cent6092->Fill(pT);
		      if(distfeckaon1&&cent> 0&&cent<=10) hhptpid_tfec_negkaon_1_dis_cent0010->Fill(pT);
		      if(distfeckaon1&&cent>10&&cent<=20) hhptpid_tfec_negkaon_1_dis_cent1020->Fill(pT);
		      if(distfeckaon1&&cent>20&&cent<=40) hhptpid_tfec_negkaon_1_dis_cent2040->Fill(pT);
		      if(distfeckaon1&&cent>40&&cent<=60) hhptpid_tfec_negkaon_1_dis_cent4060->Fill(pT);
		      if(distfeckaon1&&cent>60&&cent<=92) hhptpid_tfec_negkaon_1_dis_cent6092->Fill(pT);
		      //dis2
		      if(distofwkaon2&&cent> 0&&cent<=10) hhptpid_tofw_negkaon_2_dis_cent0010->Fill(pT);
		      if(distofwkaon2&&cent>10&&cent<=20) hhptpid_tofw_negkaon_2_dis_cent1020->Fill(pT);
		      if(distofwkaon2&&cent>20&&cent<=40) hhptpid_tofw_negkaon_2_dis_cent2040->Fill(pT);
		      if(distofwkaon2&&cent>40&&cent<=60) hhptpid_tofw_negkaon_2_dis_cent4060->Fill(pT);
		      if(distofwkaon2&&cent>60&&cent<=92) hhptpid_tofw_negkaon_2_dis_cent6092->Fill(pT);
		      if(distfeckaon2&&cent> 0&&cent<=10) hhptpid_tfec_negkaon_2_dis_cent0010->Fill(pT);
		      if(distfeckaon2&&cent>10&&cent<=20) hhptpid_tfec_negkaon_2_dis_cent1020->Fill(pT);
		      if(distfeckaon2&&cent>20&&cent<=40) hhptpid_tfec_negkaon_2_dis_cent2040->Fill(pT);
		      if(distfeckaon2&&cent>40&&cent<=60) hhptpid_tfec_negkaon_2_dis_cent4060->Fill(pT);
		      if(distfeckaon2&&cent>60&&cent<=92) hhptpid_tfec_negkaon_2_dis_cent6092->Fill(pT);
		      //dis3
		      if(distofwkaon3&&cent> 0&&cent<=10) hhptpid_tofw_negkaon_3_dis_cent0010->Fill(pT);
		      if(distofwkaon3&&cent>10&&cent<=20) hhptpid_tofw_negkaon_3_dis_cent1020->Fill(pT);
		      if(distofwkaon3&&cent>20&&cent<=40) hhptpid_tofw_negkaon_3_dis_cent2040->Fill(pT);
		      if(distofwkaon3&&cent>40&&cent<=60) hhptpid_tofw_negkaon_3_dis_cent4060->Fill(pT);
		      if(distofwkaon3&&cent>60&&cent<=92) hhptpid_tofw_negkaon_3_dis_cent6092->Fill(pT);
		      if(distfeckaon3&&cent> 0&&cent<=10) hhptpid_tfec_negkaon_3_dis_cent0010->Fill(pT);
		      if(distfeckaon3&&cent>10&&cent<=20) hhptpid_tfec_negkaon_3_dis_cent1020->Fill(pT);
		      if(distfeckaon3&&cent>20&&cent<=40) hhptpid_tfec_negkaon_3_dis_cent2040->Fill(pT);
		      if(distfeckaon3&&cent>40&&cent<=60) hhptpid_tfec_negkaon_3_dis_cent4060->Fill(pT);
		      if(distfeckaon3&&cent>60&&cent<=92) hhptpid_tfec_negkaon_3_dis_cent6092->Fill(pT);
		      //dis4
		      if(distofwkaon4&&cent> 0&&cent<=10) hhptpid_tofw_negkaon_4_dis_cent0010->Fill(pT);
		      if(distofwkaon4&&cent>10&&cent<=20) hhptpid_tofw_negkaon_4_dis_cent1020->Fill(pT);
		      if(distofwkaon4&&cent>20&&cent<=40) hhptpid_tofw_negkaon_4_dis_cent2040->Fill(pT);
		      if(distofwkaon4&&cent>40&&cent<=60) hhptpid_tofw_negkaon_4_dis_cent4060->Fill(pT);
		      if(distofwkaon4&&cent>60&&cent<=92) hhptpid_tofw_negkaon_4_dis_cent6092->Fill(pT);
		      if(distfeckaon4&&cent> 0&&cent<=10) hhptpid_tfec_negkaon_4_dis_cent0010->Fill(pT);
		      if(distfeckaon4&&cent>10&&cent<=20) hhptpid_tfec_negkaon_4_dis_cent1020->Fill(pT);
		      if(distfeckaon4&&cent>20&&cent<=40) hhptpid_tfec_negkaon_4_dis_cent2040->Fill(pT);
		      if(distfeckaon4&&cent>40&&cent<=60) hhptpid_tfec_negkaon_4_dis_cent4060->Fill(pT);
		      if(distfeckaon4&&cent>60&&cent<=92) hhptpid_tfec_negkaon_4_dis_cent6092->Fill(pT);
		      //dis5
		      if(distofwkaon5&&cent> 0&&cent<=10) hhptpid_tofw_negkaon_5_dis_cent0010->Fill(pT);
		      if(distofwkaon5&&cent>10&&cent<=20) hhptpid_tofw_negkaon_5_dis_cent1020->Fill(pT);
		      if(distofwkaon5&&cent>20&&cent<=40) hhptpid_tofw_negkaon_5_dis_cent2040->Fill(pT);
		      if(distofwkaon5&&cent>40&&cent<=60) hhptpid_tofw_negkaon_5_dis_cent4060->Fill(pT);
		      if(distofwkaon5&&cent>60&&cent<=92) hhptpid_tofw_negkaon_5_dis_cent6092->Fill(pT);
		      if(distfeckaon5&&cent> 0&&cent<=10) hhptpid_tfec_negkaon_5_dis_cent0010->Fill(pT);
		      if(distfeckaon5&&cent>10&&cent<=20) hhptpid_tfec_negkaon_5_dis_cent1020->Fill(pT);
		      if(distfeckaon5&&cent>20&&cent<=40) hhptpid_tfec_negkaon_5_dis_cent2040->Fill(pT);
		      if(distfeckaon5&&cent>40&&cent<=60) hhptpid_tfec_negkaon_5_dis_cent4060->Fill(pT);
		      if(distfeckaon5&&cent>60&&cent<=92) hhptpid_tfec_negkaon_5_dis_cent6092->Fill(pT);
		      //nowproton
		      //dis0
		      if(distofwproton0&&cent> 0&&cent<=10) hhptpid_tofw_negproton_0_dis_cent0010->Fill(pT);
		      if(distofwproton0&&cent>10&&cent<=20) hhptpid_tofw_negproton_0_dis_cent1020->Fill(pT);
		      if(distofwproton0&&cent>20&&cent<=40) hhptpid_tofw_negproton_0_dis_cent2040->Fill(pT);
		      if(distofwproton0&&cent>40&&cent<=60) hhptpid_tofw_negproton_0_dis_cent4060->Fill(pT);
		      if(distofwproton0&&cent>60&&cent<=92) hhptpid_tofw_negproton_0_dis_cent6092->Fill(pT);
		      if(distfecproton0&&cent> 0&&cent<=10) hhptpid_tfec_negproton_0_dis_cent0010->Fill(pT);
		      if(distfecproton0&&cent>10&&cent<=20) hhptpid_tfec_negproton_0_dis_cent1020->Fill(pT);
		      if(distfecproton0&&cent>20&&cent<=40) hhptpid_tfec_negproton_0_dis_cent2040->Fill(pT);
		      if(distfecproton0&&cent>40&&cent<=60) hhptpid_tfec_negproton_0_dis_cent4060->Fill(pT);
		      if(distfecproton0&&cent>60&&cent<=92) hhptpid_tfec_negproton_0_dis_cent6092->Fill(pT);
		      //dis1
		      if(distofwproton1&&cent> 0&&cent<=10) hhptpid_tofw_negproton_1_dis_cent0010->Fill(pT);
		      if(distofwproton1&&cent>10&&cent<=20) hhptpid_tofw_negproton_1_dis_cent1020->Fill(pT);
		      if(distofwproton1&&cent>20&&cent<=40) hhptpid_tofw_negproton_1_dis_cent2040->Fill(pT);
		      if(distofwproton1&&cent>40&&cent<=60) hhptpid_tofw_negproton_1_dis_cent4060->Fill(pT);
		      if(distofwproton1&&cent>60&&cent<=92) hhptpid_tofw_negproton_1_dis_cent6092->Fill(pT);
		      if(distfecproton1&&cent> 0&&cent<=10) hhptpid_tfec_negproton_1_dis_cent0010->Fill(pT);
		      if(distfecproton1&&cent>10&&cent<=20) hhptpid_tfec_negproton_1_dis_cent1020->Fill(pT);
		      if(distfecproton1&&cent>20&&cent<=40) hhptpid_tfec_negproton_1_dis_cent2040->Fill(pT);
		      if(distfecproton1&&cent>40&&cent<=60) hhptpid_tfec_negproton_1_dis_cent4060->Fill(pT);
		      if(distfecproton1&&cent>60&&cent<=92) hhptpid_tfec_negproton_1_dis_cent6092->Fill(pT);
		      //dis2
		      if(distofwproton2&&cent> 0&&cent<=10) hhptpid_tofw_negproton_2_dis_cent0010->Fill(pT);
		      if(distofwproton2&&cent>10&&cent<=20) hhptpid_tofw_negproton_2_dis_cent1020->Fill(pT);
		      if(distofwproton2&&cent>20&&cent<=40) hhptpid_tofw_negproton_2_dis_cent2040->Fill(pT);
		      if(distofwproton2&&cent>40&&cent<=60) hhptpid_tofw_negproton_2_dis_cent4060->Fill(pT);
		      if(distofwproton2&&cent>60&&cent<=92) hhptpid_tofw_negproton_2_dis_cent6092->Fill(pT);
		      if(distfecproton2&&cent> 0&&cent<=10) hhptpid_tfec_negproton_2_dis_cent0010->Fill(pT);
		      if(distfecproton2&&cent>10&&cent<=20) hhptpid_tfec_negproton_2_dis_cent1020->Fill(pT);
		      if(distfecproton2&&cent>20&&cent<=40) hhptpid_tfec_negproton_2_dis_cent2040->Fill(pT);
		      if(distfecproton2&&cent>40&&cent<=60) hhptpid_tfec_negproton_2_dis_cent4060->Fill(pT);
		      if(distfecproton2&&cent>60&&cent<=92) hhptpid_tfec_negproton_2_dis_cent6092->Fill(pT);
		      //dis3
		      if(distofwproton3&&cent> 0&&cent<=10) hhptpid_tofw_negproton_3_dis_cent0010->Fill(pT);
		      if(distofwproton3&&cent>10&&cent<=20) hhptpid_tofw_negproton_3_dis_cent1020->Fill(pT);
		      if(distofwproton3&&cent>20&&cent<=40) hhptpid_tofw_negproton_3_dis_cent2040->Fill(pT);
		      if(distofwproton3&&cent>40&&cent<=60) hhptpid_tofw_negproton_3_dis_cent4060->Fill(pT);
		      if(distofwproton3&&cent>60&&cent<=92) hhptpid_tofw_negproton_3_dis_cent6092->Fill(pT);
		      if(distfecproton3&&cent> 0&&cent<=10) hhptpid_tfec_negproton_3_dis_cent0010->Fill(pT);
		      if(distfecproton3&&cent>10&&cent<=20) hhptpid_tfec_negproton_3_dis_cent1020->Fill(pT);
		      if(distfecproton3&&cent>20&&cent<=40) hhptpid_tfec_negproton_3_dis_cent2040->Fill(pT);
		      if(distfecproton3&&cent>40&&cent<=60) hhptpid_tfec_negproton_3_dis_cent4060->Fill(pT);
		      if(distfecproton3&&cent>60&&cent<=92) hhptpid_tfec_negproton_3_dis_cent6092->Fill(pT);
		      //dis4
		      if(distofwproton4&&cent> 0&&cent<=10) hhptpid_tofw_negproton_4_dis_cent0010->Fill(pT);
		      if(distofwproton4&&cent>10&&cent<=20) hhptpid_tofw_negproton_4_dis_cent1020->Fill(pT);
		      if(distofwproton4&&cent>20&&cent<=40) hhptpid_tofw_negproton_4_dis_cent2040->Fill(pT);
		      if(distofwproton4&&cent>40&&cent<=60) hhptpid_tofw_negproton_4_dis_cent4060->Fill(pT);
		      if(distofwproton4&&cent>60&&cent<=92) hhptpid_tofw_negproton_4_dis_cent6092->Fill(pT);
		      if(distfecproton4&&cent> 0&&cent<=10) hhptpid_tfec_negproton_4_dis_cent0010->Fill(pT);
		      if(distfecproton4&&cent>10&&cent<=20) hhptpid_tfec_negproton_4_dis_cent1020->Fill(pT);
		      if(distfecproton4&&cent>20&&cent<=40) hhptpid_tfec_negproton_4_dis_cent2040->Fill(pT);
		      if(distfecproton4&&cent>40&&cent<=60) hhptpid_tfec_negproton_4_dis_cent4060->Fill(pT);
		      if(distfecproton4&&cent>60&&cent<=92) hhptpid_tfec_negproton_4_dis_cent6092->Fill(pT);
		      //dis5
		      if(distofwproton5&&cent> 0&&cent<=10) hhptpid_tofw_negproton_5_dis_cent0010->Fill(pT);
		      if(distofwproton5&&cent>10&&cent<=20) hhptpid_tofw_negproton_5_dis_cent1020->Fill(pT);
		      if(distofwproton5&&cent>20&&cent<=40) hhptpid_tofw_negproton_5_dis_cent2040->Fill(pT);
		      if(distofwproton5&&cent>40&&cent<=60) hhptpid_tofw_negproton_5_dis_cent4060->Fill(pT);
		      if(distofwproton5&&cent>60&&cent<=92) hhptpid_tofw_negproton_5_dis_cent6092->Fill(pT);
		      if(distfecproton5&&cent> 0&&cent<=10) hhptpid_tfec_negproton_5_dis_cent0010->Fill(pT);
		      if(distfecproton5&&cent>10&&cent<=20) hhptpid_tfec_negproton_5_dis_cent1020->Fill(pT);
		      if(distfecproton5&&cent>20&&cent<=40) hhptpid_tfec_negproton_5_dis_cent2040->Fill(pT);
		      if(distfecproton5&&cent>40&&cent<=60) hhptpid_tfec_negproton_5_dis_cent4060->Fill(pT);
		      if(distfecproton5&&cent>60&&cent<=92) hhptpid_tfec_negproton_5_dis_cent6092->Fill(pT);
		    }//neg
		}//new,test

	      // --------------------------------------- //
	      // --- end experimental pid histograms --- //
	      // --------------------------------------- //

	      // --------------------------------- //
	      // --- some pid histos sans dcfc --- //
	      // --------------------------------- //

	      //if(regular_cuts)
	      if(regular_cuts&&edge&&inner) // new, test
		{
		  if(charge>0)
		    {
		      if(dis0&&cent> 0&&cent<=10) ptpid_tofw_pos_0_dis_cent0010->Fill(pT);
		      if(dis0&&cent>10&&cent<=20) ptpid_tofw_pos_0_dis_cent1020->Fill(pT);
		      if(dis0&&cent>20&&cent<=40) ptpid_tofw_pos_0_dis_cent2040->Fill(pT);
		      if(dis0&&cent>40&&cent<=60) ptpid_tofw_pos_0_dis_cent4060->Fill(pT);
		      if(dis0&&cent>60&&cent<=92) ptpid_tofw_pos_0_dis_cent6092->Fill(pT);
		      if(dis2&&cent> 0&&cent<=10) ptpid_tofw_pos_2_dis_cent0010->Fill(pT);
		      if(dis2&&cent>10&&cent<=20) ptpid_tofw_pos_2_dis_cent1020->Fill(pT);
		      if(dis2&&cent>20&&cent<=40) ptpid_tofw_pos_2_dis_cent2040->Fill(pT);
		      if(dis2&&cent>40&&cent<=60) ptpid_tofw_pos_2_dis_cent4060->Fill(pT);
		      if(dis2&&cent>60&&cent<=92) ptpid_tofw_pos_2_dis_cent6092->Fill(pT);
		      if(dis4&&cent> 0&&cent<=10) ptpid_tofw_pos_4_dis_cent0010->Fill(pT);
		      if(dis4&&cent>10&&cent<=20) ptpid_tofw_pos_4_dis_cent1020->Fill(pT);
		      if(dis4&&cent>20&&cent<=40) ptpid_tofw_pos_4_dis_cent2040->Fill(pT);
		      if(dis4&&cent>40&&cent<=60) ptpid_tofw_pos_4_dis_cent4060->Fill(pT);
		      if(dis4&&cent>60&&cent<=92) ptpid_tofw_pos_4_dis_cent6092->Fill(pT);
		      if(dis6&&cent> 0&&cent<=10) ptpid_tofw_pos_6_dis_cent0010->Fill(pT);
		      if(dis6&&cent>10&&cent<=20) ptpid_tofw_pos_6_dis_cent1020->Fill(pT);
		      if(dis6&&cent>20&&cent<=40) ptpid_tofw_pos_6_dis_cent2040->Fill(pT);
		      if(dis6&&cent>40&&cent<=60) ptpid_tofw_pos_6_dis_cent4060->Fill(pT);
		      if(dis6&&cent>60&&cent<=92) ptpid_tofw_pos_6_dis_cent6092->Fill(pT);
		      if(dis8&&cent> 0&&cent<=10) ptpid_tofw_pos_8_dis_cent0010->Fill(pT);
		      if(dis8&&cent>10&&cent<=20) ptpid_tofw_pos_8_dis_cent1020->Fill(pT);
		      if(dis8&&cent>20&&cent<=40) ptpid_tofw_pos_8_dis_cent2040->Fill(pT);
		      if(dis8&&cent>40&&cent<=60) ptpid_tofw_pos_8_dis_cent4060->Fill(pT);
		      if(dis8&&cent>60&&cent<=92) ptpid_tofw_pos_8_dis_cent6092->Fill(pT);
		    }
		  if(charge<0)
		    {
		      if(dis0&&cent> 0&&cent<=10) ptpid_tofw_neg_0_dis_cent0010->Fill(pT);
		      if(dis0&&cent>10&&cent<=20) ptpid_tofw_neg_0_dis_cent1020->Fill(pT);
		      if(dis0&&cent>20&&cent<=40) ptpid_tofw_neg_0_dis_cent2040->Fill(pT);
		      if(dis0&&cent>40&&cent<=60) ptpid_tofw_neg_0_dis_cent4060->Fill(pT);
		      if(dis0&&cent>60&&cent<=92) ptpid_tofw_neg_0_dis_cent6092->Fill(pT);
		      if(dis2&&cent> 0&&cent<=10) ptpid_tofw_neg_2_dis_cent0010->Fill(pT);
		      if(dis2&&cent>10&&cent<=20) ptpid_tofw_neg_2_dis_cent1020->Fill(pT);
		      if(dis2&&cent>20&&cent<=40) ptpid_tofw_neg_2_dis_cent2040->Fill(pT);
		      if(dis2&&cent>40&&cent<=60) ptpid_tofw_neg_2_dis_cent4060->Fill(pT);
		      if(dis2&&cent>60&&cent<=92) ptpid_tofw_neg_2_dis_cent6092->Fill(pT);
		      if(dis4&&cent> 0&&cent<=10) ptpid_tofw_neg_4_dis_cent0010->Fill(pT);
		      if(dis4&&cent>10&&cent<=20) ptpid_tofw_neg_4_dis_cent1020->Fill(pT);
		      if(dis4&&cent>20&&cent<=40) ptpid_tofw_neg_4_dis_cent2040->Fill(pT);
		      if(dis4&&cent>40&&cent<=60) ptpid_tofw_neg_4_dis_cent4060->Fill(pT);
		      if(dis4&&cent>60&&cent<=92) ptpid_tofw_neg_4_dis_cent6092->Fill(pT);
		      if(dis6&&cent> 0&&cent<=10) ptpid_tofw_neg_6_dis_cent0010->Fill(pT);
		      if(dis6&&cent>10&&cent<=20) ptpid_tofw_neg_6_dis_cent1020->Fill(pT);
		      if(dis6&&cent>20&&cent<=40) ptpid_tofw_neg_6_dis_cent2040->Fill(pT);
		      if(dis6&&cent>40&&cent<=60) ptpid_tofw_neg_6_dis_cent4060->Fill(pT);
		      if(dis6&&cent>60&&cent<=92) ptpid_tofw_neg_6_dis_cent6092->Fill(pT);
		      if(dis8&&cent> 0&&cent<=10) ptpid_tofw_neg_8_dis_cent0010->Fill(pT);
		      if(dis8&&cent>10&&cent<=20) ptpid_tofw_neg_8_dis_cent1020->Fill(pT);
		      if(dis8&&cent>20&&cent<=40) ptpid_tofw_neg_8_dis_cent2040->Fill(pT);
		      if(dis8&&cent>40&&cent<=60) ptpid_tofw_neg_8_dis_cent4060->Fill(pT);
		      if(dis8&&cent>60&&cent<=92) ptpid_tofw_neg_8_dis_cent6092->Fill(pT);
		    }
		}

	      // ----------------------------------- //
	      // --- background estimation study --- //
	      // ----------------------------------- //

	      //back
	      if(fabs(tofwsdz)>3.0)
		{
		  bkgrd_tofwsdphi_pT_back_pos->Fill(pT,tofwsdphi);
		  if(ICENT==0) bkgrd_tofwsdphi_pT_back_pos_cent0->Fill(pT,tofwsdphi);
		  if(ICENT==1) bkgrd_tofwsdphi_pT_back_pos_cent1->Fill(pT,tofwsdphi);
		  if(ICENT==2) bkgrd_tofwsdphi_pT_back_pos_cent2->Fill(pT,tofwsdphi);
		  if(ICENT==3) bkgrd_tofwsdphi_pT_back_pos_cent3->Fill(pT,tofwsdphi);
		  if(ICENT==4) bkgrd_tofwsdphi_pT_back_pos_cent4->Fill(pT,tofwsdphi);
		}
	      if(fabs(tofwsdz)>3.0)
		{
		  bkgrd_tofwsdphi_pT_back_neg->Fill(pT,tofwsdphi);
		  if(ICENT==0) bkgrd_tofwsdphi_pT_back_neg_cent0->Fill(pT,tofwsdphi);
		  if(ICENT==1) bkgrd_tofwsdphi_pT_back_neg_cent1->Fill(pT,tofwsdphi);
		  if(ICENT==2) bkgrd_tofwsdphi_pT_back_neg_cent2->Fill(pT,tofwsdphi);
		  if(ICENT==3) bkgrd_tofwsdphi_pT_back_neg_cent3->Fill(pT,tofwsdphi);
		  if(ICENT==4) bkgrd_tofwsdphi_pT_back_neg_cent4->Fill(pT,tofwsdphi);
		}

	      //fore
	      if(fabs(tofwsdz)<3.0)
		{
		  bkgrd_tofwsdphi_pT_fore_pos->Fill(pT,tofwsdphi);
		  if(ICENT==0) bkgrd_tofwsdphi_pT_fore_pos_cent0->Fill(pT,tofwsdphi);
		  if(ICENT==1) bkgrd_tofwsdphi_pT_fore_pos_cent1->Fill(pT,tofwsdphi);
		  if(ICENT==2) bkgrd_tofwsdphi_pT_fore_pos_cent2->Fill(pT,tofwsdphi);
		  if(ICENT==3) bkgrd_tofwsdphi_pT_fore_pos_cent3->Fill(pT,tofwsdphi);
		  if(ICENT==4) bkgrd_tofwsdphi_pT_fore_pos_cent4->Fill(pT,tofwsdphi);
		}
	      if(fabs(tofwsdz)<3.0)
		{
		  bkgrd_tofwsdphi_pT_fore_neg->Fill(pT,tofwsdphi);
		  if(ICENT==0) bkgrd_tofwsdphi_pT_fore_neg_cent0->Fill(pT,tofwsdphi);
		  if(ICENT==1) bkgrd_tofwsdphi_pT_fore_neg_cent1->Fill(pT,tofwsdphi);
		  if(ICENT==2) bkgrd_tofwsdphi_pT_fore_neg_cent2->Fill(pT,tofwsdphi);
		  if(ICENT==3) bkgrd_tofwsdphi_pT_fore_neg_cent3->Fill(pT,tofwsdphi);
		  if(ICENT==4) bkgrd_tofwsdphi_pT_fore_neg_cent4->Fill(pT,tofwsdphi);
		}
	      //sign
	      if(fabs(tofwsdz)<3.0&&pc3_matching)
		{
		  bkgrd_tofwsdphi_pT_sign_pos->Fill(pT,tofwsdphi);
		  if(ICENT==0) bkgrd_tofwsdphi_pT_sign_pos_cent0->Fill(pT,tofwsdphi);
		  if(ICENT==1) bkgrd_tofwsdphi_pT_sign_pos_cent1->Fill(pT,tofwsdphi);
		  if(ICENT==2) bkgrd_tofwsdphi_pT_sign_pos_cent2->Fill(pT,tofwsdphi);
		  if(ICENT==3) bkgrd_tofwsdphi_pT_sign_pos_cent3->Fill(pT,tofwsdphi);
		  if(ICENT==4) bkgrd_tofwsdphi_pT_sign_pos_cent4->Fill(pT,tofwsdphi);
		}
	      if(fabs(tofwsdz)<3.0&&pc3_matching)
		{
		  bkgrd_tofwsdphi_pT_sign_neg->Fill(pT,tofwsdphi);
		  if(ICENT==0) bkgrd_tofwsdphi_pT_sign_neg_cent0->Fill(pT,tofwsdphi);
		  if(ICENT==1) bkgrd_tofwsdphi_pT_sign_neg_cent1->Fill(pT,tofwsdphi);
		  if(ICENT==2) bkgrd_tofwsdphi_pT_sign_neg_cent2->Fill(pT,tofwsdphi);
		  if(ICENT==3) bkgrd_tofwsdphi_pT_sign_neg_cent3->Fill(pT,tofwsdphi);
		  if(ICENT==4) bkgrd_tofwsdphi_pT_sign_neg_cent4->Fill(pT,tofwsdphi);
		}
	      //epsi
	      if(fabs(tofwsdz)<3.0&&pc3_matching&&ecore>1.0)
		{
		  bkgrd_tofwsdphi_pT_epsi_pos->Fill(pT,tofwsdphi);
		  if(ICENT==0) bkgrd_tofwsdphi_pT_epsi_pos_cent0->Fill(pT,tofwsdphi);
		  if(ICENT==1) bkgrd_tofwsdphi_pT_epsi_pos_cent1->Fill(pT,tofwsdphi);
		  if(ICENT==2) bkgrd_tofwsdphi_pT_epsi_pos_cent2->Fill(pT,tofwsdphi);
		  if(ICENT==3) bkgrd_tofwsdphi_pT_epsi_pos_cent3->Fill(pT,tofwsdphi);
		  if(ICENT==4) bkgrd_tofwsdphi_pT_epsi_pos_cent4->Fill(pT,tofwsdphi);
		}
	      if(fabs(tofwsdz)<3.0&&pc3_matching&&ecore>1.0)
		{
		  bkgrd_tofwsdphi_pT_epsi_neg->Fill(pT,tofwsdphi);
		  if(ICENT==0) bkgrd_tofwsdphi_pT_epsi_neg_cent0->Fill(pT,tofwsdphi);
		  if(ICENT==1) bkgrd_tofwsdphi_pT_epsi_neg_cent1->Fill(pT,tofwsdphi);
		  if(ICENT==2) bkgrd_tofwsdphi_pT_epsi_neg_cent2->Fill(pT,tofwsdphi);
		  if(ICENT==3) bkgrd_tofwsdphi_pT_epsi_neg_cent3->Fill(pT,tofwsdphi);
		  if(ICENT==4) bkgrd_tofwsdphi_pT_epsi_neg_cent4->Fill(pT,tofwsdphi);
		}


	      // ------------------------------- //
	      // --- begin systematics study --- //
	      // ------------------------------- //

	      if(charge>0)
		{
		  // tofw matching
		  if(syst_tfwmatch)
		    {
		      if(fabs(tofwsdphi)<1.5&&fabs(tofwsdz)<1.5)
			{
			  if(dis2) ptsys_pion_pos_tfwmA->Fill(pT);
			  if(dis4) ptsys_kaon_pos_tfwmA->Fill(pT);
			  if(dis8) ptsys_prot_pos_tfwmA->Fill(pT);
			}
		      if(fabs(tofwsdphi)<2.5&&fabs(tofwsdz)<2.5)
			{
			  if(dis2) ptsys_pion_pos_tfwmB->Fill(pT);
			  if(dis4) ptsys_kaon_pos_tfwmB->Fill(pT);
			  if(dis8) ptsys_prot_pos_tfwmB->Fill(pT);
			}
		    }
		  
		  // pc3 matching
		  if(syst_pc3match)
		    {
		      if(fabs(pc3sdphi)<1.5&&fabs(pc3sdz)<1.5)
			{
			  if(dis2) ptsys_pion_pos_pc3mA->Fill(pT);
			  if(dis4) ptsys_kaon_pos_pc3mA->Fill(pT);
			  if(dis8) ptsys_prot_pos_pc3mA->Fill(pT);
			}
		      if(fabs(pc3sdphi)<2.5&&fabs(pc3sdz)<2.5)
			{
			  if(dis2) ptsys_pion_pos_pc3mB->Fill(pT);
			  if(dis4) ptsys_kaon_pos_pc3mB->Fill(pT);
			  if(dis8) ptsys_prot_pos_pc3mB->Fill(pT);
			}
		    }
		  
		  // pc3 fiducial
		  if(syst_pc3fiducial)
		    {
		      if(sysgood_pc3)
			{		      
			  if(dis0) ptsys_pion_pos_pc3fA->Fill(pT);
			  if(dis4) ptsys_kaon_pos_pc3fA->Fill(pT);
			  if(dis6) ptsys_prot_pos_pc3fA->Fill(pT);
			}
		      if(dis0) ptsys_pion_pos_pc3fB->Fill(pT);
		      if(dis4) ptsys_kaon_pos_pc3fB->Fill(pT);
		      if(dis6) ptsys_prot_pos_pc3fB->Fill(pT);
		    }
		  
		  // pc1 fiducial
		  if(syst_pc1fiducial)
		    {
		      if(sysgood_pc1)
			{		      
			  if(dis0) ptsys_pion_pos_pc1fA->Fill(pT);
			  if(dis4) ptsys_kaon_pos_pc1fA->Fill(pT);
			  if(dis6) ptsys_prot_pos_pc1fA->Fill(pT);
			}
		      if(dis0) ptsys_pion_pos_pc1fB->Fill(pT);
		      if(dis4) ptsys_kaon_pos_pc1fB->Fill(pT);
		      if(dis6) ptsys_prot_pos_pc1fB->Fill(pT);
		    }
		  
		  // tofw adc cut
		  if(syst_goodadc)
		    {
		      if(qtofw>65&&qtofw<550)
			{
			  if(dis0) ptsys_pion_pos_gadcA->Fill(pT);
			  if(dis4) ptsys_kaon_pos_gadcA->Fill(pT);
			  if(dis6) ptsys_prot_pos_gadcA->Fill(pT);
			}
		      if(qtofw>55&&qtofw<650)
			{
			  if(dis0) ptsys_pion_pos_gadcB->Fill(pT);
			  if(dis4) ptsys_kaon_pos_gadcB->Fill(pT);
			  if(dis6) ptsys_prot_pos_gadcB->Fill(pT);
			}
		    }
		  
		  // fiducial cuts
		  if(syst_dcfc)
		    {
		      if(sysedge&&sysinner)
			{
			  if(dis0) ptsys_pion_pos_dcfcA->Fill(pT);
			  if(dis4) ptsys_kaon_pos_dcfcA->Fill(pT);
			  if(dis6) ptsys_prot_pos_dcfcA->Fill(pT);
			}
		      if(edge)
			{
			  if(dis0) ptsys_pion_pos_dcfcB->Fill(pT);
			  if(dis4) ptsys_kaon_pos_dcfcB->Fill(pT);
			  if(dis6) ptsys_prot_pos_dcfcB->Fill(pT);
			}
		    }
		  
		  // dc zed
		  if(regular_cuts&&good_dcfc)
		    {
		      if(fabs(zed<40))
			{
			  if(dis0) ptsys_pion_pos_dzedA->Fill(pT);
			  if(dis4) ptsys_kaon_pos_dzedA->Fill(pT);
			  if(dis6) ptsys_prot_pos_dzedA->Fill(pT);
			}
		      if(fabs(zed>40))
			{
			  if(dis0) ptsys_pion_pos_dzedB->Fill(pT);
			  if(dis4) ptsys_kaon_pos_dzedB->Fill(pT);
			  if(dis6) ptsys_prot_pos_dzedB->Fill(pT);
			}
		    }
		  
		  // pid
		  if(regular_cuts&&good_dcfc)
		    {
		      if(piA) ptsys_pion_pos_spidA->Fill(pT);
		      if(kaA) ptsys_kaon_pos_spidA->Fill(pT);
		      if(prA) ptsys_prot_pos_spidA->Fill(pT);
		      if(piB) ptsys_pion_pos_spidB->Fill(pT);
		      if(kaB) ptsys_kaon_pos_spidB->Fill(pT);
		      if(prB) ptsys_prot_pos_spidB->Fill(pT);
		    }
		  // pid
		  if(regular_cuts&&good_dcfc)
		    {
		      if(piX) ptsys_pion_pos_tpidA->Fill(pT);
		      if(kaX) ptsys_kaon_pos_tpidA->Fill(pT);
		      if(prX) ptsys_prot_pos_tpidA->Fill(pT);
		      if(piY) ptsys_pion_pos_tpidB->Fill(pT);
		      if(kaY) ptsys_kaon_pos_tpidB->Fill(pT);
		      if(prY) ptsys_prot_pos_tpidB->Fill(pT);
		    }

		  // ep cut
		  if(regular_cuts&&good_dcfc)
		    {
		      if(pT<3.0||(pT>=3.0&&ecore/pT>0.15))
			{
			  if(dis0) ptsys_pion_pos_tepcA->Fill(pT);
			  if(dis4) ptsys_kaon_pos_tepcA->Fill(pT);
			  if(dis6) ptsys_prot_pos_tepcA->Fill(pT);
			}
		      if(pT<3.0||(pT>=3.0&&ecore/pT>0.25))
			{
			  if(dis0) ptsys_pion_pos_tepcB->Fill(pT);
			  if(dis4) ptsys_kaon_pos_tepcB->Fill(pT);
			  if(dis6) ptsys_prot_pos_tepcB->Fill(pT);
			}
		    }
		}//positive
	      if(charge<0)
		{
		  // tofw matching
		  if(syst_tfwmatch)
		    {
		      if(fabs(tofwsdphi)<1.5&&fabs(tofwsdz)<1.5)
			{
			  if(dis2) ptsys_pion_neg_tfwmA->Fill(pT);
			  if(dis4) ptsys_kaon_neg_tfwmA->Fill(pT);
			  if(dis8) ptsys_prot_neg_tfwmA->Fill(pT);
			}
		      if(fabs(tofwsdphi)<2.5&&fabs(tofwsdz)<2.5)
			{
			  if(dis2) ptsys_pion_neg_tfwmB->Fill(pT);
			  if(dis4) ptsys_kaon_neg_tfwmB->Fill(pT);
			  if(dis8) ptsys_prot_neg_tfwmB->Fill(pT);
			}
		    }
		  
		  // pc3 matching
		  if(syst_pc3match)
		    {
		      if(fabs(pc3sdphi)<1.5&&fabs(pc3sdz)<1.5)
			{
			  if(dis2) ptsys_pion_neg_pc3mA->Fill(pT);
			  if(dis4) ptsys_kaon_neg_pc3mA->Fill(pT);
			  if(dis8) ptsys_prot_neg_pc3mA->Fill(pT);
			}
		      if(fabs(pc3sdphi)<2.5&&fabs(pc3sdz)<2.5)
			{
			  if(dis2) ptsys_pion_neg_pc3mB->Fill(pT);
			  if(dis4) ptsys_kaon_neg_pc3mB->Fill(pT);
			  if(dis8) ptsys_prot_neg_pc3mB->Fill(pT);
			}
		    }
		  
		  // pc3 fiducial
		  if(syst_pc3fiducial)
		    {
		      if(sysgood_pc3)
			{		      
			  if(dis0) ptsys_pion_neg_pc3fA->Fill(pT);
			  if(dis4) ptsys_kaon_neg_pc3fA->Fill(pT);
			  if(dis6) ptsys_prot_neg_pc3fA->Fill(pT);
			}
		      if(dis0) ptsys_pion_neg_pc3fB->Fill(pT);
		      if(dis4) ptsys_kaon_neg_pc3fB->Fill(pT);
		      if(dis6) ptsys_prot_neg_pc3fB->Fill(pT);
		    }
		  
		  // pc1 fiducial
		  if(syst_pc1fiducial)
		    {
		      if(sysgood_pc1)
			{		      
			  if(dis0) ptsys_pion_neg_pc1fA->Fill(pT);
			  if(dis4) ptsys_kaon_neg_pc1fA->Fill(pT);
			  if(dis6) ptsys_prot_neg_pc1fA->Fill(pT);
			}
		      if(dis0) ptsys_pion_neg_pc1fB->Fill(pT);
		      if(dis4) ptsys_kaon_neg_pc1fB->Fill(pT);
		      if(dis6) ptsys_prot_neg_pc1fB->Fill(pT);
		    }
		  
		  // tofw adc cut
		  if(syst_goodadc)
		    {
		      if(qtofw>65&&qtofw<550)
			{
			  if(dis0) ptsys_pion_neg_gadcA->Fill(pT);
			  if(dis4) ptsys_kaon_neg_gadcA->Fill(pT);
			  if(dis6) ptsys_prot_neg_gadcA->Fill(pT);
			}
		      if(qtofw>55&&qtofw<650)
			{
			  if(dis0) ptsys_pion_neg_gadcB->Fill(pT);
			  if(dis4) ptsys_kaon_neg_gadcB->Fill(pT);
			  if(dis6) ptsys_prot_neg_gadcB->Fill(pT);
			}
		    }
		  
		  // fiducial cuts
		  if(syst_dcfc)
		    {
		      if(sysedge&&sysinner)
			{
			  if(dis0) ptsys_pion_neg_dcfcA->Fill(pT);
			  if(dis4) ptsys_kaon_neg_dcfcA->Fill(pT);
			  if(dis6) ptsys_prot_neg_dcfcA->Fill(pT);
			}
		      if(edge)
			{
			  if(dis0) ptsys_pion_neg_dcfcB->Fill(pT);
			  if(dis4) ptsys_kaon_neg_dcfcB->Fill(pT);
			  if(dis6) ptsys_prot_neg_dcfcB->Fill(pT);
			}
		    }
		  
		  // dc zed
		  if(regular_cuts&&good_dcfc)
		    {
		      if(fabs(zed<40))
			{
			  if(dis0) ptsys_pion_neg_dzedA->Fill(pT);
			  if(dis4) ptsys_kaon_neg_dzedA->Fill(pT);
			  if(dis6) ptsys_prot_neg_dzedA->Fill(pT);
			}
		      if(fabs(zed>40))
			{
			  if(dis0) ptsys_pion_neg_dzedB->Fill(pT);
			  if(dis4) ptsys_kaon_neg_dzedB->Fill(pT);
			  if(dis6) ptsys_prot_neg_dzedB->Fill(pT);
			}
		    }
		  
		  // pid
		  if(regular_cuts&&good_dcfc)
		    {
		      if(piA) ptsys_pion_neg_spidA->Fill(pT);
		      if(kaA) ptsys_kaon_neg_spidA->Fill(pT);
		      if(prA) ptsys_prot_neg_spidA->Fill(pT);
		      if(piB) ptsys_pion_neg_spidB->Fill(pT);
		      if(kaB) ptsys_kaon_neg_spidB->Fill(pT);
		      if(prB) ptsys_prot_neg_spidB->Fill(pT);
		    }
		  // pid
		  if(regular_cuts&&good_dcfc)
		    {
		      if(piX) ptsys_pion_neg_tpidA->Fill(pT);
		      if(kaX) ptsys_kaon_neg_tpidA->Fill(pT);
		      if(prX) ptsys_prot_neg_tpidA->Fill(pT);
		      if(piY) ptsys_pion_neg_tpidB->Fill(pT);
		      if(kaY) ptsys_kaon_neg_tpidB->Fill(pT);
		      if(prY) ptsys_prot_neg_tpidB->Fill(pT);
		    }

		  // ep cut
		  if(regular_cuts&&good_dcfc)
		    {
		      if(pT<3.0||(pT>=3.0&&ecore/pT>0.15))
			{
			  if(dis0) ptsys_pion_neg_tepcA->Fill(pT);
			  if(dis4) ptsys_kaon_neg_tepcA->Fill(pT);
			  if(dis6) ptsys_prot_neg_tepcA->Fill(pT);
			}
		      if(pT<3.0||(pT>=3.0&&ecore/pT>0.25))
			{
			  if(dis0) ptsys_pion_neg_tepcB->Fill(pT);
			  if(dis4) ptsys_kaon_neg_tepcB->Fill(pT);
			  if(dis6) ptsys_prot_neg_tepcB->Fill(pT);
			}
		    }
		}//negative

	      // -------------------------------- //
	      // --- end of systematics study --- //
	      // -------------------------------- //

	      // ---

	      // --------------------- //
	      // --- tofw only pid --- //
	      // --------------------- //

	      if(regular_cuts&&good_dcfc)
		{
		  if(charge>0)
		    {
		      //1-d
		      if(dis0) ptpid_tofw_pos_0_dis->Fill(pT);
		      if(dis1) ptpid_tofw_pos_1_dis->Fill(pT);
		      if(dis2) ptpid_tofw_pos_2_dis->Fill(pT);
		      if(dis3) ptpid_tofw_pos_3_dis->Fill(pT);
		      if(dis4) ptpid_tofw_pos_4_dis->Fill(pT);
		      if(dis5) ptpid_tofw_pos_5_dis->Fill(pT);
		      if(dis6) ptpid_tofw_pos_6_dis->Fill(pT);
		      if(dis7) ptpid_tofw_pos_7_dis->Fill(pT);
		      if(dis8) ptpid_tofw_pos_8_dis->Fill(pT);
		      if(dis9) ptpid_tofw_pos_9_dis->Fill(pT);
		      //1-d
		      if(dis0) ptpid_tofw_pos_0_dis_cent[icent]->Fill(pT);
		      if(dis1) ptpid_tofw_pos_1_dis_cent[icent]->Fill(pT);
		      if(dis2) ptpid_tofw_pos_2_dis_cent[icent]->Fill(pT);
		      if(dis3) ptpid_tofw_pos_3_dis_cent[icent]->Fill(pT);
		      if(dis4) ptpid_tofw_pos_4_dis_cent[icent]->Fill(pT);
		      if(dis5) ptpid_tofw_pos_5_dis_cent[icent]->Fill(pT);
		      if(dis6) ptpid_tofw_pos_6_dis_cent[icent]->Fill(pT);
		      if(dis7) ptpid_tofw_pos_7_dis_cent[icent]->Fill(pT);
		      if(dis8) ptpid_tofw_pos_8_dis_cent[icent]->Fill(pT);
		      if(dis9) ptpid_tofw_pos_9_dis_cent[icent]->Fill(pT);
		    }
		  if(charge<0)
		    {
		      //1-d
		      if(dis0) ptpid_tofw_neg_0_dis->Fill(pT);
		      if(dis1) ptpid_tofw_neg_1_dis->Fill(pT);
		      if(dis2) ptpid_tofw_neg_2_dis->Fill(pT);
		      if(dis3) ptpid_tofw_neg_3_dis->Fill(pT);
		      if(dis4) ptpid_tofw_neg_4_dis->Fill(pT);
		      if(dis5) ptpid_tofw_neg_5_dis->Fill(pT);
		      if(dis6) ptpid_tofw_neg_6_dis->Fill(pT);
		      if(dis7) ptpid_tofw_neg_7_dis->Fill(pT);
		      if(dis8) ptpid_tofw_neg_8_dis->Fill(pT);
		      if(dis9) ptpid_tofw_neg_9_dis->Fill(pT);
		      //1-d
		      if(dis0) ptpid_tofw_neg_0_dis_cent[icent]->Fill(pT);
		      if(dis1) ptpid_tofw_neg_1_dis_cent[icent]->Fill(pT);
		      if(dis2) ptpid_tofw_neg_2_dis_cent[icent]->Fill(pT);
		      if(dis3) ptpid_tofw_neg_3_dis_cent[icent]->Fill(pT);
		      if(dis4) ptpid_tofw_neg_4_dis_cent[icent]->Fill(pT);
		      if(dis5) ptpid_tofw_neg_5_dis_cent[icent]->Fill(pT);
		      if(dis6) ptpid_tofw_neg_6_dis_cent[icent]->Fill(pT);
		      if(dis7) ptpid_tofw_neg_7_dis_cent[icent]->Fill(pT);
		      if(dis8) ptpid_tofw_neg_8_dis_cent[icent]->Fill(pT);
		      if(dis9) ptpid_tofw_neg_9_dis_cent[icent]->Fill(pT);
		    }
		  if(w1pos)
		    {
		      //1-d
		      if(dis0) ptpid_tofw_w1_pos_0_dis->Fill(pT);
		      if(dis1) ptpid_tofw_w1_pos_1_dis->Fill(pT);
		      if(dis2) ptpid_tofw_w1_pos_2_dis->Fill(pT);
		      if(dis3) ptpid_tofw_w1_pos_3_dis->Fill(pT);
		      if(dis4) ptpid_tofw_w1_pos_4_dis->Fill(pT);
		      if(dis5) ptpid_tofw_w1_pos_5_dis->Fill(pT);
		      if(dis6) ptpid_tofw_w1_pos_6_dis->Fill(pT);
		      if(dis7) ptpid_tofw_w1_pos_7_dis->Fill(pT);
		      if(dis8) ptpid_tofw_w1_pos_8_dis->Fill(pT);
		      if(dis9) ptpid_tofw_w1_pos_9_dis->Fill(pT);
		      //1-d
		      if(dis0) ptpid_tofw_w1_pos_0_dis_cent[icent]->Fill(pT);
		      if(dis1) ptpid_tofw_w1_pos_1_dis_cent[icent]->Fill(pT);
		      if(dis2) ptpid_tofw_w1_pos_2_dis_cent[icent]->Fill(pT);
		      if(dis3) ptpid_tofw_w1_pos_3_dis_cent[icent]->Fill(pT);
		      if(dis4) ptpid_tofw_w1_pos_4_dis_cent[icent]->Fill(pT);
		      if(dis5) ptpid_tofw_w1_pos_5_dis_cent[icent]->Fill(pT);
		      if(dis6) ptpid_tofw_w1_pos_6_dis_cent[icent]->Fill(pT);
		      if(dis7) ptpid_tofw_w1_pos_7_dis_cent[icent]->Fill(pT);
		      if(dis8) ptpid_tofw_w1_pos_8_dis_cent[icent]->Fill(pT);
		      if(dis9) ptpid_tofw_w1_pos_9_dis_cent[icent]->Fill(pT);
		    }
		  if(w1neg)
		    {
		      //1-d
		      if(dis0) ptpid_tofw_w1_neg_0_dis->Fill(pT);
		      if(dis1) ptpid_tofw_w1_neg_1_dis->Fill(pT);
		      if(dis2) ptpid_tofw_w1_neg_2_dis->Fill(pT);
		      if(dis3) ptpid_tofw_w1_neg_3_dis->Fill(pT);
		      if(dis4) ptpid_tofw_w1_neg_4_dis->Fill(pT);
		      if(dis5) ptpid_tofw_w1_neg_5_dis->Fill(pT);
		      if(dis6) ptpid_tofw_w1_neg_6_dis->Fill(pT);
		      if(dis7) ptpid_tofw_w1_neg_7_dis->Fill(pT);
		      if(dis8) ptpid_tofw_w1_neg_8_dis->Fill(pT);
		      if(dis9) ptpid_tofw_w1_neg_9_dis->Fill(pT);
		      //1-d
		      if(dis0) ptpid_tofw_w1_neg_0_dis_cent[icent]->Fill(pT);
		      if(dis1) ptpid_tofw_w1_neg_1_dis_cent[icent]->Fill(pT);
		      if(dis2) ptpid_tofw_w1_neg_2_dis_cent[icent]->Fill(pT);
		      if(dis3) ptpid_tofw_w1_neg_3_dis_cent[icent]->Fill(pT);
		      if(dis4) ptpid_tofw_w1_neg_4_dis_cent[icent]->Fill(pT);
		      if(dis5) ptpid_tofw_w1_neg_5_dis_cent[icent]->Fill(pT);
		      if(dis6) ptpid_tofw_w1_neg_6_dis_cent[icent]->Fill(pT);
		      if(dis7) ptpid_tofw_w1_neg_7_dis_cent[icent]->Fill(pT);
		      if(dis8) ptpid_tofw_w1_neg_8_dis_cent[icent]->Fill(pT);
		      if(dis9) ptpid_tofw_w1_neg_9_dis_cent[icent]->Fill(pT);
		    }
		  if(w2pos)
		    {
		      //1-d
		      if(dis0) ptpid_tofw_w2_pos_0_dis->Fill(pT);
		      if(dis1) ptpid_tofw_w2_pos_1_dis->Fill(pT);
		      if(dis2) ptpid_tofw_w2_pos_2_dis->Fill(pT);
		      if(dis3) ptpid_tofw_w2_pos_3_dis->Fill(pT);
		      if(dis4) ptpid_tofw_w2_pos_4_dis->Fill(pT);
		      if(dis5) ptpid_tofw_w2_pos_5_dis->Fill(pT);
		      if(dis6) ptpid_tofw_w2_pos_6_dis->Fill(pT);
		      if(dis7) ptpid_tofw_w2_pos_7_dis->Fill(pT);
		      if(dis8) ptpid_tofw_w2_pos_8_dis->Fill(pT);
		      if(dis9) ptpid_tofw_w2_pos_9_dis->Fill(pT);
		      //1-d
		      if(dis0) ptpid_tofw_w2_pos_0_dis_cent[icent]->Fill(pT);
		      if(dis1) ptpid_tofw_w2_pos_1_dis_cent[icent]->Fill(pT);
		      if(dis2) ptpid_tofw_w2_pos_2_dis_cent[icent]->Fill(pT);
		      if(dis3) ptpid_tofw_w2_pos_3_dis_cent[icent]->Fill(pT);
		      if(dis4) ptpid_tofw_w2_pos_4_dis_cent[icent]->Fill(pT);
		      if(dis5) ptpid_tofw_w2_pos_5_dis_cent[icent]->Fill(pT);
		      if(dis6) ptpid_tofw_w2_pos_6_dis_cent[icent]->Fill(pT);
		      if(dis7) ptpid_tofw_w2_pos_7_dis_cent[icent]->Fill(pT);
		      if(dis8) ptpid_tofw_w2_pos_8_dis_cent[icent]->Fill(pT);
		      if(dis9) ptpid_tofw_w2_pos_9_dis_cent[icent]->Fill(pT);
		    }
		  if(w2neg)
		    {
		      //1-d
		      if(dis0) ptpid_tofw_w2_neg_0_dis->Fill(pT);
		      if(dis1) ptpid_tofw_w2_neg_1_dis->Fill(pT);
		      if(dis2) ptpid_tofw_w2_neg_2_dis->Fill(pT);
		      if(dis3) ptpid_tofw_w2_neg_3_dis->Fill(pT);
		      if(dis4) ptpid_tofw_w2_neg_4_dis->Fill(pT);
		      if(dis5) ptpid_tofw_w2_neg_5_dis->Fill(pT);
		      if(dis6) ptpid_tofw_w2_neg_6_dis->Fill(pT);
		      if(dis7) ptpid_tofw_w2_neg_7_dis->Fill(pT);
		      if(dis8) ptpid_tofw_w2_neg_8_dis->Fill(pT);
		      if(dis9) ptpid_tofw_w2_neg_9_dis->Fill(pT);
		      //1-d
		      if(dis0) ptpid_tofw_w2_neg_0_dis_cent[icent]->Fill(pT);
		      if(dis1) ptpid_tofw_w2_neg_1_dis_cent[icent]->Fill(pT);
		      if(dis2) ptpid_tofw_w2_neg_2_dis_cent[icent]->Fill(pT);
		      if(dis3) ptpid_tofw_w2_neg_3_dis_cent[icent]->Fill(pT);
		      if(dis4) ptpid_tofw_w2_neg_4_dis_cent[icent]->Fill(pT);
		      if(dis5) ptpid_tofw_w2_neg_5_dis_cent[icent]->Fill(pT);
		      if(dis6) ptpid_tofw_w2_neg_6_dis_cent[icent]->Fill(pT);
		      if(dis7) ptpid_tofw_w2_neg_7_dis_cent[icent]->Fill(pT);
		      if(dis8) ptpid_tofw_w2_neg_8_dis_cent[icent]->Fill(pT);
		      if(dis9) ptpid_tofw_w2_neg_9_dis_cent[icent]->Fill(pT);
		    }
		}//regular_cuts

	      // ---------------------------- //
	      // --- end of tofw only pid --- //
	      // ---------------------------- //
	      
	      if(isPi||isK||isP) ntofwPIDtracks++;
	      
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
  
  // write the histograms to file and close
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
  
} // end of main

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



float isPionANA(float x, float m2tofw)
{

  float c_light =  29.9792458; //  speed of light in cm/ns
  float L = 495.0; // distance to tofw
  float K1 = 75.0; // field integral 
  float par0 = 0.896; // angular resolution
  float par1 = 0.992; // multiple scattering term
  float par2 = 0.074; // timing resolution

  float m2 = mpion*mpion;
  float pterm = -9999;
  float tterm = -9999;
  float varia = -9999;
  float sigma = -9999;

  pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
  pterm = pterm/(K1*K1);
  tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
  varia = 4*(pterm + tterm);
  sigma = sqrt(varia);

  return (m2tofw-m2)/sigma;

}



float isKaonANA(float x, float m2tofw)
{
  
  float c_light =  29.9792458; //  speed of light in cm/ns
  float L = 495.0; // distance to tofw
  float K1 = 75.0; // field integral 
  float par0 = 0.896; // angular resolution
  float par1 = 0.992; // multiple scattering term
  float par2 = 0.074; // timing resolution

  float m2 = mkaon*mkaon;
  float pterm = -9999;
  float tterm = -9999;
  float varia = -9999;
  float sigma = -9999;

  pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
  pterm = pterm/(K1*K1);
  tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
  varia = 4*(pterm + tterm);
  sigma = sqrt(varia);

  return (m2tofw-m2)/sigma;

}



float isProtonANA(float x, float m2tofw)
{

  float c_light =  29.9792458; //  speed of light in cm/ns
  float L = 495.0; // distance to tofw
  float K1 = 75.0; // field integral 
  float par0 = 0.896; // angular resolution
  float par1 = 0.992; // multiple scattering term
  float par2 = 0.074; // timing resolution

  float m2 = mproton*mproton;
  float pterm = -9999;
  float tterm = -9999;
  float varia = -9999;
  float sigma = -9999;

  pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
  pterm = pterm/(K1*K1);
  tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
  varia = 4*(pterm + tterm);
  sigma = sqrt(varia);

  return (m2tofw-m2)/sigma;

}


float isPionANA_v1(float x, float m2tofw)
{

  float c_light =  29.9792458; //  speed of light in cm/ns
  float L = 495.0; // distance to tofw
  float K1 = 75.0; // field integral 
  float par0 = 0.896; // angular resolution
  float par1 = 0.992; // multiple scattering term
  float par2 = 0.074; // timing resolution

  float a0 = 0.0123786;
  float a1 = 0.00293974;
  float a2 = -0.000321866;
  float a3 = -0.0110238;
  float a4 = 0.0352101;
  float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);
  //float m2 = mpion*mpion;
  float m2 = mean; // why not?
  float pterm = -9999;
  float tterm = -9999;
  float varia = -9999;
  float sigma = -9999;

  pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
  pterm = pterm/(K1*K1);
  tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
  varia = 4*(pterm + tterm);
  sigma = sqrt(varia);

  return (m2tofw-m2)/sigma;

}



float isKaonANA_v1(float x, float m2tofw)
{
  
  float c_light =  29.9792458; //  speed of light in cm/ns
  float L = 495.0; // distance to tofw
  float K1 = 75.0; // field integral 
  float par0 = 0.896; // angular resolution
  float par1 = 0.992; // multiple scattering term
  float par2 = 0.074; // timing resolution

  float m2 = mkaon*mkaon;
  float pterm = -9999;
  float tterm = -9999;
  float varia = -9999;
  float sigma = -9999;

  pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
  pterm = pterm/(K1*K1);
  tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
  varia = 4*(pterm + tterm);
  sigma = sqrt(varia);

  return (m2tofw-m2)/sigma;

}



float isProtonANA_v1(float x, float m2tofw)
{

  float c_light =  29.9792458; //  speed of light in cm/ns
  float L = 495.0; // distance to tofw
  float K1 = 75.0; // field integral 
  float par0 = 0.896; // angular resolution
  float par1 = 0.992; // multiple scattering term
  float par2 = 0.074; // timing resolution

  float  a0    =       8.58341e-01;
  float  a1    =      -2.89831e-02;
  float  a2    =       1.68868e-02;
  float  a3    =      -9.42405e-03;
  float  a4    =       6.23467e-02;
  float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);
  //float m2 = mproton*mproton;
  float m2 = mean; // why not?
  float pterm = -9999;
  float tterm = -9999;
  float varia = -9999;
  float sigma = -9999;

  pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
  pterm = pterm/(K1*K1);
  tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
  varia = 4*(pterm + tterm);
  sigma = sqrt(varia);

  return (m2tofw-m2)/sigma;

}


float isPionANA_v2(float x, float m2tofw)
{

  float c_light =  29.9792458; //  speed of light in cm/ns
  float L = 495.0; // distance to tofw
  float K1 = 75.0; // field integral 
  float par0 = 0.896; // angular resolution
  float par1 = 0.992; // multiple scattering term
  float par2 = 0.084; // timing resolution

  float m2 = mpion*mpion;
  float pterm = -9999;
  float tterm = -9999;
  float varia = -9999;
  float sigma = -9999;

  pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
  pterm = pterm/(K1*K1);
  tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
  varia = 4*(pterm + tterm);
  sigma = sqrt(varia);

  return (m2tofw-m2)/sigma;

}



float isKaonANA_v2(float x, float m2tofw)
{
  
  float c_light =  29.9792458; //  speed of light in cm/ns
  float L = 495.0; // distance to tofw
  float K1 = 75.0; // field integral 
  float par0 = 0.896; // angular resolution
  float par1 = 0.992; // multiple scattering term
  float par2 = 0.084; // timing resolution

  float m2 = mkaon*mkaon;
  float pterm = -9999;
  float tterm = -9999;
  float varia = -9999;
  float sigma = -9999;

  pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
  pterm = pterm/(K1*K1);
  tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
  varia = 4*(pterm + tterm);
  sigma = sqrt(varia);

  return (m2tofw-m2)/sigma;

}



float isProtonANA_v2(float x, float m2tofw)
{

  float c_light =  29.9792458; //  speed of light in cm/ns
  float L = 495.0; // distance to tofw
  float K1 = 75.0; // field integral 
  float par0 = 0.896; // angular resolution
  float par1 = 0.992; // multiple scattering term
  float par2 = 0.084; // timing resolution

  float m2 = mproton*mproton;
  float pterm = -9999;
  float tterm = -9999;
  float varia = -9999;
  float sigma = -9999;

  pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
  pterm = pterm/(K1*K1);
  tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
  varia = 4*(pterm + tterm);
  sigma = sqrt(varia);

  return (m2tofw-m2)/sigma;

}


float isPionANA_v3(float x, float m2tofw)
{

  float c_light =  29.9792458; //  speed of light in cm/ns
  float L = 495.0; // distance to tofw
  float K1 = 75.0; // field integral 
  float par0 = 0.896; // angular resolution
  float par1 = 0.992; // multiple scattering term
  float par2 = 0.074; // timing resolution

  float m2 = mpion*mpion;
  float pterm = -9999;
  float tterm = -9999;
  float varia = -9999;
  float sigma = -9999;

  pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
  pterm = pterm/(K1*K1);
  tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
  varia = 4*(pterm + tterm);
  sigma = sqrt(varia);

  return (m2tofw-m2)/sigma;

}



float isKaonANA_v3(float x, float m2tofw)
{
  
  float c_light =  29.9792458; //  speed of light in cm/ns
  float L = 495.0; // distance to tofw
  float K1 = 75.0; // field integral 
  float par0 = 0.896; // angular resolution
  float par1 = 0.992; // multiple scattering term
  float par2 = 0.074; // timing resolution

  float m2 = mkaon*mkaon;
  float pterm = -9999;
  float tterm = -9999;
  float varia = -9999;
  float sigma = -9999;

  pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
  pterm = pterm/(K1*K1);
  tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
  varia = 4*(pterm + tterm);
  sigma = sqrt(varia);

  return (m2tofw-m2)/sigma;

}



float isProtonANA_v3(float x, float m2tofw)
{

  float c_light =  29.9792458; //  speed of light in cm/ns
  float L = 495.0; // distance to tofw
  float K1 = 75.0; // field integral 
  float par0 = 0.896; // angular resolution
  float par1 = 0.992; // multiple scattering term
  float par2 = 0.074; // timing resolution

  float m2 = mproton*mproton;
  float pterm = -9999;
  float tterm = -9999;
  float varia = -9999;
  float sigma = -9999;

  pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
  pterm = pterm/(K1*K1);
  tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
  varia = 4*(pterm + tterm);
  sigma = sqrt(varia);

  return (m2tofw-m2)/sigma;

}


float isPionLME(float x, float m2tofw)
{

  // this mean is more radical
  // consider going with less radical
  float a0 = 0.0123786;
  float a1 = 0.00293974;
  float a2 = -0.000321866;
  float a3 = -0.0110238;
  float a4 = 0.0352101;
  float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);

  // based on simulation
  // new
  float  p0   =       -2.32986e-02;
  float  p1   =       -1.30028e-03;
  float  p2   =       -8.26991e-06;
  float  p3   =        5.56826e-02;
  float  p4   =       -1.16173e-01;
  float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
  // new
  // float  p0   =       -4.32359e-02;
  // float  p1   =        6.44942e-03;
  // float  p2   =       -8.09058e-04;
  // float  p3   =        3.91918e-02;
  // float  p4   =       -5.68094e-02;
  // float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
  
  return (m2tofw - mean)/sigma;

}



float isKaonLME(float x, float m2tofw)
{
  
  float  p0   =        1.17930e-02;
  float  p1   =       -1.54666e-02;
  float  p2   =        2.48918e-03;
  float  p3   =        6.50247e-02;
  float  p4   =       -1.61286e-01;
  float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);

  float mean = mkaon*mkaon; // mean is very stable

  return (m2tofw - mean)/sigma;

}



float isProtonLME(float x, float m2tofw)
{

  float  a0    =       8.58341e-01;
  float  a1    =      -2.89831e-02;
  float  a2    =       1.68868e-02;
  float  a3    =      -9.42405e-03;
  float  a4    =       6.23467e-02;
  float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);

  float  p0    =      -6.19317e-03;  
  float  p1    =       9.01921e-03;
  float  p2    =       6.82347e-04;
  float  p3    =       6.07866e-02;
  float  p4    =      -1.32903e-01;
  float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);

  return (m2tofw - mean)/sigma;

}











float isPionLow(float x, float m2tofw)
{

  // this mean is more radical
  // consider going with less radical
  // float a0 = 0.0123786;
  // float a1 = 0.00293974;
  // float a2 = -0.000321866;
  // float a3 = -0.0110238;
  // float a4 = 0.0352101;
  // float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);

  float mean = mpion*mpion;

  // based on simulation
  // new
  float  p0   =       -2.32986e-02;
  float  p1   =       -1.30028e-03;
  float  p2   =       -8.26991e-06;
  float  p3   =        5.56826e-02;
  float  p4   =       -1.16173e-01;
  float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
  // new
  // float  p0   =       -4.32359e-02;
  // float  p1   =        6.44942e-03;
  // float  p2   =       -8.09058e-04;
  // float  p3   =        3.91918e-02;
  // float  p4   =       -5.68094e-02;
  // float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
  
  return (m2tofw - mean)/sigma;

}



float isKaonLow(float x, float m2tofw)
{
  
  float  p0   =        1.17930e-02;
  float  p1   =       -1.54666e-02;
  float  p2   =        2.48918e-03;
  float  p3   =        6.50247e-02;
  float  p4   =       -1.61286e-01;
  float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);

  float mean = mkaon*mkaon; // mean is very stable

  return (m2tofw - mean)/sigma;

}



float isProtonLow(float x, float m2tofw)
{

  // float  a0    =       8.58341e-01;
  // float  a1    =      -2.89831e-02;
  // float  a2    =       1.68868e-02;
  // float  a3    =      -9.42405e-03;
  // float  a4    =       6.23467e-02;
  // float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);

  float mean = mproton*mproton;

  float  p0    =      -6.19317e-03;  
  float  p1    =       9.01921e-03;
  float  p2    =       6.82347e-04;
  float  p3    =       6.07866e-02;
  float  p4    =      -1.32903e-01;
  float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);

  return (m2tofw - mean)/sigma;

}




float isPionPDI(float x, float m2tofw)
{

  // this mean is more radical
  // consider going with less radical
  float a0 = 0.0123786;
  float a1 = 0.00293974;
  float a2 = -0.000321866;
  float a3 = -0.0110238;
  float a4 = 0.0352101;
  float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);

  // based on simulation
  // new
  // float  p0   =       -2.32986e-02;
  // float  p1   =       -1.30028e-03;
  // float  p2   =       -8.26991e-06;
  // float  p3   =        5.56826e-02;
  // float  p4   =       -1.16173e-01;
  // float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
  // from fit to real data
  // new
  float  p0   =       -4.32359e-02;
  float  p1   =        6.44942e-03;
  float  p2   =       -8.09058e-04;
  float  p3   =        3.91918e-02;
  float  p4   =       -5.68094e-02;
  float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
  
  return (m2tofw - mean)/sigma;

}


bool GoodPC1(float ppc1z, float ppc1phi)
{

  float zed = ppc1z;
  float phi = ppc1phi;

  if(zed>-70&&zed<-57&&phi>0.78&&phi<0.83) return false;
  if(zed>-30&&zed<-18&&phi>0.55&&phi<0.6) return false;
  if(zed>-30&&zed<-18&&phi>0.35&&phi<0.45) return false;
  if(zed>-3&&zed<0&&phi>0.4&&phi<0.45) return false;
  if(zed>70&&zed<82&&phi>0.35&&phi<0.45) return false;
  if(zed>28&&zed<41&&phi>0.16&&phi<0.2) return false;
  if(zed>-52&&zed<-39&&phi>0.12&&phi<0.16) return false;
  if(zed>49&&zed<61&&phi>0.0&&phi<0.05) return false;
  if(zed>0&&zed<10&&phi>-0.27&&phi<-0.22) return false;


  //DC holes...
  //if(zed<0&&phi<-0.065&&phi>-0.105) return false; // modified
  //if(zed>49&&zed<60&&phi>0.008&&phi<0.05) return false;
  //if(zed>-71&&zed<-59&&phi>0.398&&phi<0.44) return false;
 
  return true;  
  
}
bool SysGoodPC1(float ppc1z, float ppc1phi)
{

  float zed = ppc1z;
  float phi = ppc1phi;

  if(zed>-72&&zed<-57&&phi>0.78&&phi<0.835) return false;
  if(zed>-32&&zed<-18&&phi>0.55&&phi<0.605) return false;
  if(zed>-32&&zed<-18&&phi>0.35&&phi<0.455) return false;
  if(zed>-5&&zed<0&&phi>0.4&&phi<0.455) return false;
  if(zed>68&&zed<82&&phi>0.35&&phi<0.455) return false;
  if(zed>26&&zed<41&&phi>0.16&&phi<0.205) return false;
  if(zed>-54&&zed<-39&&phi>0.12&&phi<0.165) return false;
  if(zed>47&&zed<61&&phi>0.0&&phi<0.055) return false;
  if(zed>-2&&zed<10&&phi>-0.27&&phi<-0.215) return false;



  return true;  
  
}






bool GoodPC3(float pc3z, float pc3phi)
{

  float zed = pc3z;
  float phi = pc3phi;

  if(zed>14&&zed<28&&phi>0.488&&phi<0.508) return false;//w2
  if(zed>-45&&zed<-30&&phi>0.498&&phi<0.600) return false;//w2
  if(zed>-126&&zed<-90&&phi>0.470&&phi<0.512) return false;//w2
  if(zed>62&&zed<88&&phi>0.47&&phi<0.516) return false;//w2
  if(zed>94&&zed<105&&phi>0.476&&phi<0.510) return false;//w2
  if(zed>-104&&zed<-84&&phi>0.370&&phi<0.444) return false;//w2
  if(zed>-64&&zed<0&&phi>0.370&&phi<0.444) return false;//w2

  if(zed>67&&zed<80&&phi>0.040&&phi<0.100) return false;//w1
  if(zed>-86&&zed<-74&&phi>0.006&&phi<0.100) return false;//w1
  if(zed>-86&&zed<-61&&phi>0.036&&phi<0.100) return false;//w1
  if(zed>84&&zed<112&&phi>-0.034&&phi<0.012) return false;//w1
  if(zed>148&&zed<154&&phi>0.014&&phi<0.048) return false;//w1
  if(zed>155&&zed<161&&phi>-0.100&&phi<-0.076) return false;//w1


  return true;

}
bool SysGoodPC3(float pc3z, float pc3phi)
{

  float zed = pc3z;
  float phi = pc3phi;

  if(zed>12&&zed<28&&phi>0.488&&phi<0.513) return false;//w2
  if(zed>-47&&zed<-30&&phi>0.498&&phi<0.605) return false;//w2
  if(zed>-128&&zed<-90&&phi>0.470&&phi<0.517) return false;//w2
  if(zed>60&&zed<88&&phi>0.47&&phi<0.521) return false;//w2
  if(zed>92&&zed<105&&phi>0.476&&phi<0.515) return false;//w2
  if(zed>-106&&zed<-84&&phi>0.370&&phi<0.449) return false;//w2
  if(zed>-66&&zed<0&&phi>0.370&&phi<0.449) return false;//w2

  if(zed>65&&zed<80&&phi>0.040&&phi<0.105) return false;//w1
  if(zed>-88&&zed<-74&&phi>0.006&&phi<0.105) return false;//w1
  if(zed>-88&&zed<-61&&phi>0.036&&phi<0.105) return false;//w1
  if(zed>82&&zed<112&&phi>-0.034&&phi<0.017) return false;//w1
  if(zed>146&&zed<154&&phi>0.014&&phi<0.053) return false;//w1
  if(zed>153&&zed<161&&phi>-0.100&&phi<-0.081) return false;//w1



  return true;

}



bool GoodEMC(float emcz, float emcphi)
{

  float zed = emcz;
  float phi = emcphi;

  if(zed<-120&&phi>0.535) return false;//w2
  if(zed>130&&zed<150&&phi>0.472&&phi<0.508) return false;//w2
  if(zed>20&&zed<45&&phi>0.486&&phi<0.536) return false;//w2
  if(zed>-100&&zed<-80&&phi>0.450&&phi<0.506) return false;//w2
  if(zed>-125&&zed<-100&&phi>0.470&&phi<0.506) return false;//w2
  if(zed>-155&&zed<-135&&phi>0.016&&phi<0.058) return false;//w1


  return true;

}
bool SysGoodEMC(float emcz, float emcphi)
{

  float zed = emcz;
  float phi = emcphi;

  if(zed<-120&&phi>0.535) return false;//w2
  if(zed>128&&zed<150&&phi>0.472&&phi<0.513) return false;//w2
  if(zed>18&&zed<45&&phi>0.486&&phi<0.541) return false;//w2
  if(zed>-102&&zed<-80&&phi>0.450&&phi<0.511) return false;//w2
  if(zed>-127&&zed<-100&&phi>0.470&&phi<0.511) return false;//w2
  if(zed>-157&&zed<-135&&phi>0.016&&phi<0.063) return false;//w1


  return true;

}



void GetRunIndex()
{

  string s;
  ifstream f("runs.list");
  if(!f)
    {
      cerr<<"Couldn't open file"<<endl;
      exit(1);
    }
  
  int j=0;
  
  while(getline(f,s))
    {
      //cout<<s<<endl;
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




















bool GoodEdgeDCH(int run, float zed, float alpha, float phi)
{

  float slope = 1.72; // 1.72 is latest and greatest, Monday 10/25/1010
  //float sline = 25.0; // unused in this routine
  float slire = 8.1;

  // === W1 === //
  if(alpha<slope*phi-slope*-0.200 && alpha>slope*phi-slope*-0.105) return false; // w1 below box
  if(alpha<slope*phi-slope*-0.021 && alpha>slope*phi-slope*-0.014) return false; // w1 center of box
  if(alpha<slope*phi-slope*0.060  && alpha>slope*phi-slope*0.200) return false; // w1 above box
  
  // === W2 === //
  if(alpha<slope*phi-slope*0.300 && alpha>slope*phi-slope*0.415) return false; // w2 below box
  if(alpha<slope*phi-slope*0.494 && alpha>slope*phi-slope*0.501) return false; // w2 center of box
  if(alpha<slope*phi-slope*0.577 && alpha>slope*phi-slope*0.700) return false; // w2 above box
  
  if(alpha<slire*phi-slire*0.397 && alpha>slire*phi-slire*0.400) return false; // w2 wire, low
  if(alpha<slire*phi-slire*0.543 && alpha>slire*phi-slire*0.547) return false; // w2 wire, middle
  if(alpha<slire*phi-slire*0.593 && alpha>slire*phi-slire*0.596) return false; // w2 wire, high
  


  return true;

}


bool SysGoodEdgeDCH(int run, float zed, float alpha, float phi)
{

  float slope = 1.72; // 1.72 is latest and greatest, Monday 10/25/1010
  //float sline = 25.0; // unused this routine
  float slire = 8.1;

  // === W1 === //
  // --- box edges
  if(alpha<slope*phi-slope*-0.200 && alpha>slope*phi-slope*-0.101) return false; // w1 below box
  if(alpha<slope*phi-slope*-0.022 && alpha>slope*phi-slope*-0.013) return false; // w1 center of box
  if(alpha<slope*phi-slope*0.058  && alpha>slope*phi-slope*0.200) return false; // w1 above box
  // --- internal wires
  // both w1 wires are much less pronounced than w2  
  //if(alpha<slire*phi-slire*-0.191 && alpha>slire*phi-slire*-0.188) return false; // w1 wire // problematically not straight
  //if(alpha<slire*phi-slire*0.006 && alpha>slire*phi-slire*0.009) return false; // w1 wire // leave out
  // === W2 === //
  // --- box edges
  if(alpha<slope*phi-slope*0.300 && alpha>slope*phi-slope*0.417) return false; // w2 below box
  if(alpha<slope*phi-slope*0.493 && alpha>slope*phi-slope*0.502) return false; // w2 center of box
  if(alpha<slope*phi-slope*0.575 && alpha>slope*phi-slope*0.700) return false; // w2 above box
  // --- internal wires
  if(alpha<slire*phi-slire*0.397 && alpha>slire*phi-slire*0.400) return false; // w2 wire, low
  if(alpha<slire*phi-slire*0.543 && alpha>slire*phi-slire*0.547) return false; // w2 wire, middle
  if(alpha<slire*phi-slire*0.593 && alpha>slire*phi-slire*0.596) return false; // w2 wire, high
  
  return true;

}


bool GoodInnerDCH(int run, float zed, float alpha, float phi)
{
  // 1.72 is latest and greatest, Monday 10/25/1010
  // none of these used in this routine
  //float slope = 1.72;
  //float sline = 25.0;
  //float slire = 8.1;


  // large stripe covering far upper alpha of w1 and far lower alpha of w2
  //if(alpha<22.0*phi-22.0*0.175 && alpha>22.0*phi-22.0*0.276) return false; // checked // run8 only

  // === W1 ===//
  // --- patchy region, upper alpha
  //if(alpha<-14.8469*phi+14.8469*0.199158 && alpha>-21.3095*phi+21.3095*0.0383544 && alpha>0) return false; // checked, 4/11/2011
  //if(alpha>22.3703*phi-22.3703*0.118409 && alpha>-21.3095*phi+21.3095*0.0383544 && alpha>0) return false; // 
  //if(alpha>22.3703*phi-22.3703*0.1205 && alpha>-21.3095*phi+21.3095*0.0383544 && alpha>0) return false; // reverted 4/26/2011
  if(alpha>22.3703*phi-22.3703*0.14 && alpha>-21.3095*phi+21.3095*0.0383544 && alpha>0) return false; // changed 4/27/2011
  // parellel hole with negative slope for upper alpha, higher phi
  //if(alpha<-14.8469*phi+14.8469*0.199158 && alpha>-13.1329*phi+13.1329*0.181353 && alpha>0) return false; // checked
  if(alpha<-14.8469*phi+14.8469*0.199158 && alpha>-13.1329*phi+13.1329*0.181353 && alpha>0) return false; // checked


  // === W2 === //
  // --- small corner, lower alpha, low phi
  if(phi>0.185 && phi<0.225 && alpha<0) return false; // run7 only



  // now do zed dependence
  if(zed>0)
    {
      // === W1 === //
      // --- left-most corner
      if(phi<-0.373) return false; // checked
      // --- small stripe, lower alpha, lower phi
      if(alpha>23.7666*phi-23.7666*-0.225933 && alpha<14.5819*phi-14.5819*-0.227896) return false; // checked
      // slice, upper alpha, high phi
      if(alpha<25.1495*phi-25.1495*0.178771 && alpha>12.7551*phi-12.7551*0.195642) return false; // run7 only
      // === W2 === //
      // --- triangular hole, lower alpha
      //if(alpha<26.4147*phi-26.4147*0.393654 && alpha<-23.0095*phi+23.0095*0.435974) return false; // checked // run8 only
      //if(alpha>13.7928*phi-13.7928*0.666602 && alpha>-48.9766*phi+48.9766*0.653529) return false; // negzed only // maybe not???
      if(alpha<-16.11*phi+16.11*0.532 && alpha>-16.118*phi+16.11*0.521) return false; // small piece, new 5/1/2011
    }
  if(zed<0)
    {
      // === W1 === //
      // --- triangular hole for lower alpha, higher phi
      if(alpha<25.5628*phi-25.5628*-0.115491 && alpha<-19.9631*phi+19.9631*-0.092522) return false; // checked
      // --- triangular hole, lower alpha higher phi, simulation hole is larger and more complicated than real
      if(alpha>8.27513*phi-8.27513*-0.0636948 && alpha<8.27513*phi-8.27513*-0.105588) return false; // checked
      if(alpha<-20.6432*phi+20.6432*-0.0917881 && phi>-0.119) return false;
      // --- A-shaped hole, lower alpha lower phi, egregious mismatch between sim and real requires large hole
      if(alpha<29.0282*phi-29.0282*-0.217561 && alpha<-16.4706*phi+16.4706*-0.192351) return false;
      // slice, upper alpha, high phi
      //if(alpha<25.1495*phi-25.1495*0.178771 && alpha>12.7551*phi-12.7551*0.195642) return false; // run7 only
      if(alpha<40.1888*phi-40.1888*0.182412 && alpha>11.321*phi-11.321*0.200919) return false; // run7 only
      // === W2 === //
      // --- small stripe, upper alpha, higher phi
      if(alpha<22.0*phi-22.0*0.725 && alpha>22.0*phi-22.0*0.745) return false; // checked
      // --- inverted triangular shape, upper alpha lower phi
      if(alpha>13.7928*phi-13.7928*0.666602 && alpha>-48.9766*phi+48.9766*0.653529) return false; // checked // run8 only // maybe not???
    }

  return true;

}




bool SysGoodInnerDCH(int run, float zed, float alpha, float phi)
{
  // 1.72 is latest and greatest, Monday 10/25/1010
  // none of these used in this routine
  //float slope = 1.72;
  //float sline = 25.0;
  //float slire = 8.1;


  // large stripe covering far upper alpha of w1 and far lower alpha of w2
  //if(alpha<22.0*phi-22.0*0.175 && alpha>22.0*phi-22.0*0.276) return false; // checked // run8 only

  // === W1 ===//
  // --- patchy region, upper alpha
  //if(alpha<-14.8469*phi+14.8469*0.199158 && alpha>-21.3095*phi+21.3095*0.0383544 && alpha>0) return false; // checked, 4/11/2011
  //if(alpha>22.3703*phi-22.3703*0.118409 && alpha>-21.3095*phi+21.3095*0.0383544 && alpha>0) return false; // 
  //if(alpha>22.3703*phi-22.3703*0.1205 && alpha>-21.3095*phi+21.3095*0.0383544 && alpha>0) return false; // reverted 4/26/2011
  //if(alpha>22.3703*phi-22.3703*0.14 && alpha>-21.3095*phi+21.3095*0.0383544 && alpha>0) return false; // original
  if(alpha>22.3703*phi-22.3703*0.14 && alpha>-21.3095*phi+21.3095*0.0383544 && alpha>0) return false; // systematic
  // parellel hole with negative slope for upper alpha, higher phi
  //if(alpha<-14.8469*phi+14.8469*0.199158 && alpha>-13.1329*phi+13.1329*0.181353 && alpha>0) return false; // original
  if(alpha<-14.8469*phi+14.8469*0.199158 && alpha>-13.1329*phi+13.1329*0.181353 && alpha>0) return false; // systematic


  // === W2 === //
  // --- small corner, lower alpha, low phi
  //if(phi>0.185 && phi<0.225 && alpha<0) return false; // original
  if(phi>0.185 && phi<0.225 && alpha<0) return false; // systematic



  // now do zed dependence
  if(zed>0)
    {
      // === W1 === //
      // --- left-most corner
      //if(phi<-0.373) return false; // original
      if(phi<-0.373) return false; // systematic
      // --- small stripe, lower alpha, lower phi
      //if(alpha>23.7666*phi-23.7666*-0.225933 && alpha<14.5819*phi-14.5819*-0.227896) return false; // original
      if(alpha>23.7666*phi-23.7666*-0.225933 && alpha<14.5819*phi-14.5819*-0.227896) return false; // systematic
      // slice, upper alpha, high phi
      //if(alpha<25.1495*phi-25.1495*0.178771 && alpha>12.7551*phi-12.7551*0.195642) return false; // original
      if(alpha<25.1495*phi-25.1495*0.178771 && alpha>12.7551*phi-12.7551*0.195642) return false; // systematic
      // === W2 === //
      // --- triangular hole, lower alpha
      //if(alpha<26.4147*phi-26.4147*0.393654 && alpha<-23.0095*phi+23.0095*0.435974) return false; // checked // run8 only
      //if(alpha>13.7928*phi-13.7928*0.666602 && alpha>-48.9766*phi+48.9766*0.653529) return false; // negzed only // maybe not???
      //if(alpha<-16.11*phi+16.11*0.532 && alpha>-16.118*phi+16.11*0.521) return false; // original
      if(alpha<-16.11*phi+16.11*0.532 && alpha>-16.118*phi+16.11*0.521) return false; // systematic
    }
  if(zed<0)
    {
      // === W1 === //
      // --- triangular hole for lower alpha, higher phi
      //if(alpha<25.5628*phi-25.5628*-0.115491 && alpha<-19.9631*phi+19.9631*-0.092522) return false; // original
      if(alpha<25.5628*phi-25.5628*-0.115491 && alpha<-19.9631*phi+19.9631*-0.092522) return false; // systematic
      // --- triangular hole, lower alpha higher phi, simulation hole is larger and more complicated than real
      //if(alpha>8.27513*phi-8.27513*-0.0636948 && alpha<8.27513*phi-8.27513*-0.105588) return false; // original
      if(alpha>8.27513*phi-8.27513*-0.0636948 && alpha<8.27513*phi-8.27513*-0.105588) return false; // systematic
      //if(alpha<-20.6432*phi+20.6432*-0.0917881 && phi>-0.119) return false; // original
      if(alpha<-20.6432*phi+20.6432*-0.0917881 && phi>-0.119) return false; // systematic
      // --- A-shaped hole, lower alpha lower phi, egregious mismatch between sim and real requires large hole
      //if(alpha<29.0282*phi-29.0282*-0.217561 && alpha<-16.4706*phi+16.4706*-0.192351) return false; // original
      if(alpha<29.0282*phi-29.0282*-0.217561 && alpha<-16.4706*phi+16.4706*-0.192351) return false; // systematic
      // slice, upper alpha, high phi
      //if(alpha<25.1495*phi-25.1495*0.178771 && alpha>12.7551*phi-12.7551*0.195642) return false; // run7 only
      //if(alpha<40.1888*phi-40.1888*0.182412 && alpha>11.321*phi-11.321*0.200919) return false; // original
      if(alpha<40.1888*phi-40.1888*0.182412 && alpha>11.321*phi-11.321*0.200919) return false; // systematic
      // === W2 === //
      // --- small stripe, upper alpha, higher phi
      //if(alpha<22.0*phi-22.0*0.725 && alpha>22.0*phi-22.0*0.745) return false; // original
      if(alpha<22.0*phi-22.0*0.725 && alpha>22.0*phi-22.0*0.745) return false; // systematic
      // --- inverted triangular shape, upper alpha lower phi
      //if(alpha>13.7928*phi-13.7928*0.666602 && alpha>-48.9766*phi+48.9766*0.653529) return false; // original
      if(alpha>13.7928*phi-13.7928*0.666602 && alpha>-48.9766*phi+48.9766*0.653529) return false; // systematic
    }

  return true;

}

