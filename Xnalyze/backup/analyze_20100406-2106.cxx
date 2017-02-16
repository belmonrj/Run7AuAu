// Author: Ron Belmont
// Date: 2009-07-28
// Revision - only tofw histos
 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <sys/time.h>
 
#include "hadrontree.h"
 
#include "TROOT.h"
#include "TFile.h" 
#include "TTree.h"
#include "TH1.h" 
#include "TH2.h"   
#include "TH3.h"
#include "TF1.h" 

using namespace std;



const float phbeta  = 29.9792458;
const float mpion   = 0.13957;
const float mkaon   = 0.493677;
const float mproton = 0.938270;

bool goodStrip(int i);
bool isPion(float x, float m2tofw);
bool isKaon(float x, float m2tofw);
bool isProton(float x, float m2tofw);
float isPionNew(float x, float m2tofw);
float isKaonNew(float x, float m2tofw);
float isProtonNew(float x, float m2tofw);
bool DCHFiducial(int run, float alpha, float zed, float board);
bool GoodPC1(float ppc1z, float ppc1phi);
bool GoodPC2(float pc2z, float pc2phi);
bool GoodPC3(float pc3z, float pc3phi);



Long64_t nevents = 0;
Long64_t ntracks = 0;
Long64_t ngoodtofwevents = 0;
Long64_t ngoodtofwtracks = 0;
Long64_t ntofwPIDtracks = 0;
Long64_t ngoodtofwtracks_snglevent = 0;



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

  // -------------------------- //
  // --- Declare histograms --- //
  // -------------------------- //

  TH2F *h_julia_zedpt_before = new TH2F("h_julia_zedpt_before","zed vs pT before cuts", 100, 0, 10, 180, -90, 90);
  TH2F *h_julia_zedpt_after = new TH2F("h_julia_zedpt_after","zed vs pT after cuts", 100, 0, 10, 180, -90, 90);

  // some other stuff
  // 160, 20, 36, - 200, -0.2, 0.2

  TH2F *hh_alphaphi = new TH2F("hh_alphaphi","alpha vs phi", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_phipt = new TH2F("hh_phipt","phi vs pT", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_momphi = new TH2F("hh_momphi","mom vs phi", 400, -0.2, 0.2, 100, 0, 10);

  // no cuts
  TH2F *hh_alphaphi_0 = new TH2F("hh_alphaphi_0","alpha vs phi _0", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_phipt_0 = new TH2F("hh_pos_phipt_0","phi vs pT _0", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_pos_momphi_0 = new TH2F("hh_pos_momphi_0","mom vs phi _0", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_phipt_0 = new TH2F("hh_neg_phipt_0","phi vs pT _0", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_neg_momphi_0 = new TH2F("hh_neg_momphi_0","mom vs phi _0", 400, -0.2, 0.2, 100, 0, 10);
  // zed cuts
  TH2F *hh_alphaphi_1 = new TH2F("hh_alphaphi_1","alpha vs phi _1", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_phipt_1 = new TH2F("hh_pos_phipt_1","phi vs pT _1", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_pos_momphi_1 = new TH2F("hh_pos_momphi_1","mom vs phi _1", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_phipt_1 = new TH2F("hh_neg_phipt_1","phi vs pT _1", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_neg_momphi_1 = new TH2F("hh_neg_momphi_1","mom vs phi _1", 400, -0.2, 0.2, 100, 0, 10);
  // quality cuts
  TH2F *hh_alphaphi_2 = new TH2F("hh_alphaphi_2","alpha vs phi _2", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_phipt_2 = new TH2F("hh_pos_phipt_2","phi vs pT _2", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_pos_momphi_2 = new TH2F("hh_pos_momphi_2","mom vs phi _2", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_phipt_2 = new TH2F("hh_neg_phipt_2","phi vs pT _2", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_neg_momphi_2 = new TH2F("hh_neg_momphi_2","mom vs phi _2", 400, -0.2, 0.2, 100, 0, 10);
  // pc1 fiducial cuts
  TH2F *hh_alphaphi_3 = new TH2F("hh_alphaphi_3","alpha vs phi _3", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_phipt_3 = new TH2F("hh_pos_phipt_3","phi vs pT _3", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_pos_momphi_3 = new TH2F("hh_pos_momphi_3","mom vs phi _3", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_phipt_3 = new TH2F("hh_neg_phipt_3","phi vs pT _3", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_neg_momphi_3 = new TH2F("hh_neg_momphi_3","mom vs phi _3", 400, -0.2, 0.2, 100, 0, 10);
  // pc3 fiducial cuts
  TH2F *hh_alphaphi_4 = new TH2F("hh_alphaphi_4","alpha vs phi _4", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_phipt_4 = new TH2F("hh_pos_phipt_4","phi vs pT _4", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_pos_momphi_4 = new TH2F("hh_pos_momphi_4","mom vs phi _4", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_phipt_4 = new TH2F("hh_neg_phipt_4","phi vs pT _4", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_neg_momphi_4 = new TH2F("hh_neg_momphi_4","mom vs phi _4", 400, -0.2, 0.2, 100, 0, 10);
  // pc3 matching
  TH2F *hh_alphaphi_5 = new TH2F("hh_alphaphi_5","alpha vs phi _5", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_phipt_5 = new TH2F("hh_pos_phipt_5","phi vs pT _5", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_pos_momphi_5 = new TH2F("hh_pos_momphi_5","mom vs phi _5", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_phipt_5 = new TH2F("hh_neg_phipt_5","phi vs pT _5", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_neg_momphi_5 = new TH2F("hh_neg_momphi_5","mom vs phi _5", 400, -0.2, 0.2, 100, 0, 10);
  // tofw matching
  TH2F *hh_alphaphi_6 = new TH2F("hh_alphaphi_6","alpha vs phi _6", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_phipt_6 = new TH2F("hh_pos_phipt_6","phi vs pT _6", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_pos_momphi_6 = new TH2F("hh_pos_momphi_6","mom vs phi _6", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_phipt_6 = new TH2F("hh_neg_phipt_6","phi vs pT _6", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_neg_momphi_6 = new TH2F("hh_neg_momphi_6","mom vs phi _6", 400, -0.2, 0.2, 100, 0, 10);
  // tofw adc cut
  TH2F *hh_alphaphi_7 = new TH2F("hh_alphaphi_7","alpha vs phi _7", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_phipt_7 = new TH2F("hh_pos_phipt_7","phi vs pT _7", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_pos_momphi_7 = new TH2F("hh_pos_momphi_7","mom vs phi _7", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_phipt_7 = new TH2F("hh_neg_phipt_7","phi vs pT _7", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_neg_momphi_7 = new TH2F("hh_neg_momphi_7","mom vs phi _7", 400, -0.2, 0.2, 100, 0, 10);
  // tofw strip cut
  TH2F *hh_alphaphi_8 = new TH2F("hh_alphaphi_8","alpha vs phi _8", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_phipt_8 = new TH2F("hh_pos_phipt_8","phi vs pT _8", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_pos_momphi_8 = new TH2F("hh_pos_momphi_8","mom vs phi _8", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_phipt_8 = new TH2F("hh_neg_phipt_8","phi vs pT _8", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_neg_momphi_8 = new TH2F("hh_neg_momphi_8","mom vs phi _8", 400, -0.2, 0.2, 100, 0, 10);
  // all cuts (because why not?)
  TH2F *hh_alphaphi_9 = new TH2F("hh_alphaphi_9","alpha vs phi _9", 400, -0.2, 0.2, 200, -0.1, 0.1);
  TH2F *hh_pos_phipt_9 = new TH2F("hh_pos_phipt_9","phi vs pT _9", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_pos_momphi_9 = new TH2F("hh_pos_momphi_9","mom vs phi _9", 400, -0.2, 0.2, 100, 0, 10);
  TH2F *hh_neg_phipt_9 = new TH2F("hh_neg_phipt_9","phi vs pT _9", 100, 0, 10, 400, -0.2, 0.2);
  TH2F *hh_neg_momphi_9 = new TH2F("hh_neg_momphi_9","mom vs phi _9", 400, -0.2, 0.2, 100, 0, 10);

  //DC fiducial cuts

  // 1d +- Field
  TH1F *DCWestZedPos_dndalphaDis_PM    = new TH1F("DCWestZedPos_dndalphaDis_PM", "DC West alpha zed>0", 200, -0.1, 0.1);
  TH1F *DCWestZedPos_dndboardDis_PM    = new TH1F("DCWestZedPos_dndboardDis_PM", "DC West board zed>0", 160, 20, 36);
  TH1F *DCWestZedNeg_dndalphaDis_PM    = new TH1F("DCWestZedNeg_dndalphaDis_PM", "DC West alpha zed<0", 200, -0.1, 0.1);
  TH1F *DCWestZedNeg_dndboardDis_PM    = new TH1F("DCWestZedNeg_dndboardDis_PM", "DC West board zed<0", 160, 20, 36);
  TH1F *DCWestZedDis_PM                = new TH1F("DCWestZedDis_PM", "DC West zed dist", 180, -90, 90);
  TH1F *DCWestZedPos_dndalphaNewDis_PM = new TH1F("DCWestZedPos_dndalphaNewDis_PM", "DC West alpha zed>0", 200, -0.1, 0.1);
  TH1F *DCWestZedPos_dndboardNewDis_PM = new TH1F("DCWestZedPos_dndboardNewDis_PM", "DC West board zed>0", 160, 20, 36);
  TH1F *DCWestZedNeg_dndalphaNewDis_PM = new TH1F("DCWestZedNeg_dndalphaNewDis_PM", "DC West alpha zed<0", 200, -0.1, 0.1);
  TH1F *DCWestZedNeg_dndboardNewDis_PM = new TH1F("DCWestZedNeg_dndboardNewDis_PM", "DC West board zed<0", 160, 20, 36);
  TH1F *DCWestZedNewDis_PM             = new TH1F("DCWestZedNewDis_PM", "DC West zed dist", 180, -90, 90);
  // 1d -+ Field
  TH1F *DCWestZedPos_dndalphaDis_MP    = new TH1F("DCWestZedPos_dndalphaDis_MP", "DC West alpha zed>0", 200, -0.1, 0.1);
  TH1F *DCWestZedPos_dndboardDis_MP    = new TH1F("DCWestZedPos_dndboardDis_MP", "DC West board zed>0", 160, 20, 36);
  TH1F *DCWestZedNeg_dndalphaDis_MP    = new TH1F("DCWestZedNeg_dndalphaDis_MP", "DC West alpha zed<0", 200, -0.1, 0.1);
  TH1F *DCWestZedNeg_dndboardDis_MP    = new TH1F("DCWestZedNeg_dndboardDis_MP", "DC West board zed<0", 160, 20, 36);
  TH1F *DCWestZedDis_MP                = new TH1F("DCWestZedDis_MP", "DC West zed dist", 180, -90, 90);
  TH1F *DCWestZedPos_dndalphaNewDis_MP = new TH1F("DCWestZedPos_dndalphaNewDis_MP", "DC West alpha zed>0", 200, -0.1, 0.1);
  TH1F *DCWestZedPos_dndboardNewDis_MP = new TH1F("DCWestZedPos_dndboardNewDis_MP", "DC West board zed>0", 160, 20, 36);
  TH1F *DCWestZedNeg_dndalphaNewDis_MP = new TH1F("DCWestZedNeg_dndalphaNewDis_MP", "DC West alpha zed<0", 200, -0.1, 0.1);
  TH1F *DCWestZedNeg_dndboardNewDis_MP = new TH1F("DCWestZedNeg_dndboardNewDis_MP", "DC West board zed<0", 160, 20, 36);
  TH1F *DCWestZedNewDis_MP             = new TH1F("DCWestZedNewDis_MP", "DC West zed dist", 180, -90, 90);

  //+- Field
  TH2F *DCWestZedPosDis_PM    = new TH2F("DCWestZedPosDis_PM", "DC West alpha vs. board zed>0", 160, 20, 36, 200, -0.1, 0.1);
  TH2F *DCWestZedNegDis_PM    = new TH2F("DCWestZedNegDis_PM", "DC West alpha vs. board zed<0", 160, 20, 36, 200, -0.1, 0.1);
  TH2F *DCWestZedPosNewDis_PM = new TH2F("DCWestZedPosNewDis_PM", "DC West alpha vs. board zed>0", 160, 20, 36, 200, -0.1, 0.1);
  TH2F *DCWestZedNegNewDis_PM = new TH2F("DCWestZedNegNewDis_PM", "DC West alpha vs. board zed<0", 160, 20, 36, 200, -0.1, 0.1);
  //-+ Field
  TH2F *DCWestZedPosDis_MP    = new TH2F("DCWestZedPosDis_MP", "DC West alpha vs. board zed>0", 160, 20, 36, 200, -0.1, 0.1);
  TH2F *DCWestZedNegDis_MP    = new TH2F("DCWestZedNegDis_MP", "DC West alpha vs. board zed<0", 160, 20, 36, 200, -0.1, 0.1);
  TH2F *DCWestZedPosNewDis_MP = new TH2F("DCWestZedPosNewDis_MP", "DC West alpha vs. board zed>0", 160, 20, 36, 200, -0.1, 0.1);
  TH2F *DCWestZedNegNewDis_MP = new TH2F("DCWestZedNegNewDis_MP", "DC West alpha vs. board zed<0", 160, 20, 36, 200, -0.1, 0.1);

  //Pad Chamber Fiducial Cut Histograms
  TH2F *PC1ZedPhiDis  = new TH2F("PC1ZedPhiDis", "PC1 phi vs zed w/o FC", 400, -200, 200, 500, -0.3, 0.7);
  TH2F *PC1ZedPhiNewDis  = new TH2F("PC1ZedPhiNewDis", "PC1 phi vs zed w/ FC", 400, -200, 200, 500, -0.3, 0.7);
  TH2F *PC2ZedPhiDis  = new TH2F("PC2ZedPhiDis", "PC2 phi vs zed w/o FC", 400, -200, 200, 500, -0.3, 0.7);
  TH2F *PC2ZedPhiNewDis  = new TH2F("PC2ZedPhiNewDis", "PC2 phi vs zed w/ FC",400, -200, 200, 500, -0.3, 0.7);
  TH2F *PC3ZedPhiDis  = new TH2F("PC3ZedPhiDis", "PC3 phi vs zed w/o FC", 400, -200, 200, 500, -0.3, 0.7);
  TH2F *PC3ZedPhiNewDis  = new TH2F("PC3ZedPhiNewDis", "PC3 phi vs zed w/ FC", 400, -200, 200, 500, -0.3, 0.7);

  //TH2F *adc_strip = new TH2F("adc_strip","ADC in TOFW vs strip", 512, 0, 511, 1000, 0, 1000);
  //TH2F *adc_beta_before = new TH2F("adc_beta_before","ADC vs beta before cut", 600, 0, 1.2, 400, 0, 800);
  //TH2F *adc_beta_after = new TH2F("adc_beta_after","ADC vs beta before cut", 600, 0, 1.2, 400, 0, 800);

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
	  //input files are now selected by field config
	  //if(run>235810) continue; // +- only
	  //if(run<236133) continue; // -+ only

	  //these cuts are already in the pDSTs
	  //float bbcz = ktree->bbcz;
	  //if(fabs(bbcz)>30) continue;
	  float cent = ktree->cent;
	  //if(cent<0||cent>=100) continue;

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

	      float mom = ktree->HadronTracks_mom[itrk];
	      float pT = ktree->HadronTracks_pt[itrk];
	      int striptofw = (int)ktree->HadronTracks_striptofw[itrk];
	      if(striptofw<256)
		{
		  mom = 0.9957*mom;
		  pT = 0.9957*pT;
		}
	      //if(!goodStrip(striptofw)) continue;
	      int strip = striptofw;
	      //if(strip<0||strip>63) continue; // W1 south bot (box 0, lower half)
	      //if(strip<64||strip>127) continue; // W1 south top (box 0, upper half)
	      //if(strip<128||strip>191) continue; // W1 north bot (box 1, lower half)
	      //if(strip<192||strip>255) continue; // W1 north top (box 1, upper half)

	      // --- TOFW adc cut
	      float pltofw = ktree->HadronTracks_pltofw[itrk];
	      float ttofw = ktree->HadronTracks_ttofw[itrk];
	      float qtofw = ktree->HadronTracks_qtofw[itrk];
	      float beta = pltofw/ttofw/phbeta;
	      //adc_beta_before->Fill(beta,qtofw);
	      //if(qtofw<60||qtofw>600) continue; // old cut
	      //if(qtofw<(20*((float)pow(beta,(float)-2.7)))||qtofw>600) continue;
	      bool good_adc (qtofw>(20*((float)pow(beta,(float)-2.7)))&&qtofw<600);
	      //adc_beta_after->Fill(beta,qtofw);

	      int quality = ktree->HadronTracks_quality[itrk];
	      float zed   = ktree->HadronTracks_zed[itrk];
	      float phi   = ktree->HadronTracks_phi[itrk];
	      float alpha = ktree->HadronTracks_alpha[itrk];
	      int charge  = ktree->HadronTracks_charge[itrk];

	      //bool good_dc = (fabs(zed)<70&&fabs(zed)>3);
	      bool good_dc = (fabs(zed)<70&&fabs(zed)>3&&(quality==63||quality==31));
	      //if(!good_dc) continue;

	      float board = ((0.573231+phi-0.0046*cos(phi+0.05721))/0.01963496);

	      if(run>=228042&&run<=235810)
		{ 
		  DCWestZedDis_PM->Fill(zed);
		  if(zed>0) DCWestZedPos_dndalphaDis_PM->Fill(alpha);
		  if(zed<0) DCWestZedNeg_dndalphaDis_PM->Fill(alpha);
		  if(zed>0) DCWestZedPos_dndboardDis_PM->Fill(board);
		  if(zed<0) DCWestZedNeg_dndboardDis_PM->Fill(board);
		  if(zed>0) DCWestZedPosDis_PM->Fill(board,alpha);
		  if(zed<0) DCWestZedNegDis_PM->Fill(board,alpha);
		}
	      else if(run>=236133&&run<=240121)
		{
		  DCWestZedDis_MP->Fill(zed);
		  if(zed>0) DCWestZedPos_dndalphaDis_MP->Fill(alpha);
		  if(zed<0) DCWestZedNeg_dndalphaDis_MP->Fill(alpha);
		  if(zed>0) DCWestZedPos_dndboardDis_MP->Fill(board);
		  if(zed<0) DCWestZedNeg_dndboardDis_MP->Fill(board);
		  if(zed>0) DCWestZedPosDis_MP->Fill(board,alpha);
		  if(zed<0) DCWestZedNegDis_MP->Fill(board,alpha);
		}

	      //if(!DCHFiducial(run,alpha,zed,board)) continue;

	      if(run>=228042&&run<=235810)
		{ 
		  DCWestZedNewDis_PM->Fill(zed);
		  if(zed>0) DCWestZedPos_dndalphaNewDis_PM->Fill(alpha);
		  if(zed<0) DCWestZedNeg_dndalphaNewDis_PM->Fill(alpha);
		  if(zed>0) DCWestZedPos_dndboardNewDis_PM->Fill(board);
		  if(zed<0) DCWestZedNeg_dndboardNewDis_PM->Fill(board);
		  if(zed>0) DCWestZedPosNewDis_PM->Fill(board,alpha);
		  if(zed<0) DCWestZedNegNewDis_PM->Fill(board,alpha);
		}
	      else if(run>=236133&&run<=240121)
		{
		  DCWestZedNewDis_MP->Fill(zed);
		  if(zed>0) DCWestZedPos_dndalphaNewDis_MP->Fill(alpha);
		  if(zed<0) DCWestZedNeg_dndalphaNewDis_MP->Fill(alpha);
		  if(zed>0) DCWestZedPos_dndboardNewDis_MP->Fill(board);
		  if(zed<0) DCWestZedNeg_dndboardNewDis_MP->Fill(board);
		  if(zed>0) DCWestZedPosNewDis_MP->Fill(board,alpha);
		  if(zed<0) DCWestZedNegNewDis_MP->Fill(board,alpha);
		}

	      float ppc1x     = ktree->HadronTracks_ppc1x[itrk];
	      float ppc1y     = ktree->HadronTracks_ppc1y[itrk];
	      float ppc1z     = ktree->HadronTracks_ppc1z[itrk];
	      float pc1z = ppc1z;
	      float pc1phi = atan2(ppc1y,ppc1x);  

	      //PC1ZedPhiDis->Fill(pc1z,pc1phi);
	      //if(!GoodPC1(pc1z,pc1phi)) continue;
	      //PC1ZedPhiNewDis->Fill(pc1z,pc1phi);

	      float ppc2x     = ktree->HadronTracks_ppc2x[itrk];
	      float ppc2y     = ktree->HadronTracks_ppc2y[itrk];
	      float ppc2z     = ktree->HadronTracks_ppc2z[itrk];
	      float pc2dz     = ktree->HadronTracks_pc2dz[itrk];
	      float pc2dphi   = ktree->HadronTracks_pc2dphi[itrk];
	      float pc2z      = ppc2z -pc2dz;
	      float pc2phi    = atan2(ppc2y,ppc2x) - pc2dphi;

	      //PC2ZedPhiDis->Fill(pc2z,pc2phi);
	      //if(!GoodPC2(pc2z,pc2phi)) continue;
	      //PC2ZedPhiNewDis->Fill(pc2z,pc2phi);

	      float ppc3x     = ktree->HadronTracks_ppc3x[itrk];
	      float ppc3y     = ktree->HadronTracks_ppc3y[itrk];
	      float ppc3z     = ktree->HadronTracks_ppc3z[itrk];
	      float pc3dz     = ktree->HadronTracks_pc3dz[itrk];
	      float pc3dphi   = ktree->HadronTracks_pc3dphi[itrk];
	      float pc3z      = ppc3z - pc3dz;
	      float pc3phi    = atan2(ppc3y,ppc3x) - pc3dphi;

	      //PC3ZedPhiDis->Fill(pc3z,pc3phi);
	      //if(!GoodPC3(pc3z,pc3phi)) continue;
	      //PC3ZedPhiNewDis->Fill(pc3z,pc3phi);

	      float pc2sdz      = ktree->HadronTracks_pc2sdz[itrk];
	      float pc2sdphi    = ktree->HadronTracks_pc2sdphi[itrk];
	      float pc3sdz      = ktree->HadronTracks_pc3sdz[itrk];
	      float pc3sdphi    = ktree->HadronTracks_pc3sdphi[itrk];

	      //float tofwdz     = ktree->HadronTracks_tofwdz[itrk];
	      //float tofwdphi   = ktree->HadronTracks_tofwdphi[itrk];
	      float tofwsdz     = ktree->HadronTracks_tofwsdz[itrk];
	      float tofwsdphi   = ktree->HadronTracks_tofwsdphi[itrk];

	      float emcsdz      = ktree->HadronTracks_emcsdz[itrk];
	      float emcsdphi    = ktree->HadronTracks_emcsdphi[itrk];

	      bool pc2_matching = fabs(pc2sdphi)<2.0 && fabs(pc2sdz)<2.0;
	      bool pc3_matching = fabs(pc3sdphi)<2.0 && fabs(pc3sdz)<2.0;
	      bool tfw_matching = fabs(tofwsdphi)<2.0 && fabs(tofwsdz)<2.0;
	      bool emc_matching = fabs(emcsdphi)<2.0 && fabs(emcsdz)<2.0;
	      float m2tofw      = ktree->HadronTracks_m2tofw[itrk];

	      float isPiNew = isPionNew(pT,m2tofw);
	      float isKNew  = isKaonNew(pT,m2tofw);
	      float isPNew  = isProtonNew(pT,m2tofw);

	      bool isPi = (isPiNew>=-2&&isPiNew<=2);
	      bool isK = (isKNew>=-2&&isKNew<=2);
	      bool isP = (isPNew>=-2&&isPNew<=2);

	      //float n0 = ktree->HadronTracks_n0[itrk];
	      float ecore = ktree->HadronTracks_ecore[itrk];
	      //float ecent = ktree->HadronTracks_ecent[itrk];

	      float ep = ecore/mom;

	      // ----------------------- //
	      // --- test histograms --- //
	      // ----------------------- //

	      hh_alphaphi_0->Fill(phi,alpha);
	      if(charge>0) hh_pos_phipt_0->Fill(pT,phi);
	      if(charge<0) hh_neg_phipt_0->Fill(pT,phi);
	      if(charge>0) hh_pos_momphi_0->Fill(phi,mom);
	      if(charge<0) hh_neg_momphi_0->Fill(phi,mom);

	      // hh type 0
	      if(fabs(zed)<70||fabs(zed)>3)
		{
		  hh_alphaphi_1->Fill(phi,alpha);
		  if(charge>0) hh_pos_phipt_1->Fill(pT,phi);
		  if(charge<0) hh_neg_phipt_1->Fill(pT,phi);
		  if(charge>0) hh_pos_momphi_1->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_1->Fill(phi,mom);
		}

	      if(quality==63||quality==31)
		{
		  hh_alphaphi_2->Fill(phi,alpha);
		  if(charge>0) hh_pos_phipt_2->Fill(pT,phi);
		  if(charge<0) hh_neg_phipt_2->Fill(pT,phi);
		  if(charge>0) hh_pos_momphi_2->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_2->Fill(phi,mom);
		}

	      if(GoodPC1(pc1z,pc1phi))
		{
		  hh_alphaphi_3->Fill(phi,alpha);
		  if(charge>0) hh_pos_phipt_3->Fill(pT,phi);
		  if(charge<0) hh_neg_phipt_3->Fill(pT,phi);
		  if(charge>0) hh_pos_momphi_3->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_3->Fill(phi,mom);
		}

	      if(GoodPC3(pc3z,pc3phi))
		{
		  hh_alphaphi_4->Fill(phi,alpha);
		  if(charge>0) hh_pos_phipt_4->Fill(pT,phi);
		  if(charge<0) hh_neg_phipt_4->Fill(pT,phi);
		  if(charge>0) hh_pos_momphi_4->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_4->Fill(phi,mom);
		}

	      if(pc3_matching)
		{
		  hh_alphaphi_5->Fill(phi,alpha);
		  if(charge>0) hh_pos_phipt_5->Fill(pT,phi);
		  if(charge<0) hh_neg_phipt_5->Fill(pT,phi);
		  if(charge>0) hh_pos_momphi_5->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_5->Fill(phi,mom);
		}

	      if(tfw_matching)
		{
		  hh_alphaphi_6->Fill(phi,alpha);
		  if(charge>0) hh_pos_phipt_6->Fill(pT,phi);
		  if(charge<0) hh_neg_phipt_6->Fill(pT,phi);
		  if(charge>0) hh_pos_momphi_6->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_6->Fill(phi,mom);
		}

	      if(good_adc)
		{
		  hh_alphaphi_7->Fill(phi,alpha);
		  if(charge>0) hh_pos_phipt_7->Fill(pT,phi);
		  if(charge<0) hh_neg_phipt_7->Fill(pT,phi);
		  if(charge>0) hh_pos_momphi_7->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_7->Fill(phi,mom);
		}

	      if(goodStrip(striptofw))
		{
		  hh_alphaphi_8->Fill(phi,alpha);
		  if(charge>0) hh_pos_phipt_8->Fill(pT,phi);
		  if(charge<0) hh_neg_phipt_8->Fill(pT,phi);
		  if(charge>0) hh_pos_momphi_8->Fill(phi,mom);
		  if(charge<0) hh_neg_momphi_8->Fill(phi,mom);
		}

	      //if(good_dc&&GoodPC1(pc1z,pc1phi)&&GoodPC3(pc3z,pc3phi)&&good_adc&&pc3_matching&&tfw_matching&&goodStrip(striptofw))

	      bool goodtrack = (good_dc&&GoodPC1(pc1z,pc1phi)&&GoodPC3(pc3z,pc3phi)&&good_adc&&pc3_matching&&tfw_matching&&goodStrip(striptofw));

	      if(!goodtrack) continue;

	      hh_alphaphi_9->Fill(phi,alpha);
	      if(charge>0) hh_pos_phipt_9->Fill(pT,phi);
	      if(charge<0) hh_neg_phipt_9->Fill(pT,phi);
	      if(charge>0) hh_pos_momphi_9->Fill(phi,mom);
	      if(charge<0) hh_neg_momphi_9->Fill(phi,mom);



	      ngoodtofwtracks++;
	      ngoodtofwtracks_snglevent++;

	      // ----------------- //
	      // --- tofw only --- //
	      // ----------------- //

	      h_julia_zedpt_before->Fill(pT,zed);
	      //if(ep<0.1) continue; // ep study
	      if(!tfw_matching||!pc3_matching) continue;
	      //if(!tfw_matching||!pc3_matching||!pc2_matching) continue;
	      h_julia_zedpt_after->Fill(pT,zed);

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

  if(x<0.4||x>8.0) return false;
  
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

  if(x<0.4||x>8.0) return false;
  
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

  if(x<0.4||x>8.0) return false;

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



bool DCHFiducial(int run, float alpha, float zed, float board)
{
  // --- Take note that the cuts are identical for the two fields.
  // --- In principal we could ignore the runnumber, but its conceivable
  // --- that the cuts might change and need to be a function of run number.
  // --- While this is highly unlikely, nevertheless it is better to keep
  // --- this functionality in the code.
  if(run>=228042&&run<=235810)  //+- field
    { 
      if(zed>0)
	{
	  if(fabs(alpha)<0.005) return false;
	  if(alpha <0.032*board-0.032*27.9 && alpha >0.032*board-0.032*28.3) return false;
	  if(alpha <0.032*board-0.032*54.0 && alpha >0.032*board-0.032*54.4) return false;
	  if(board>31.8&&board<36) return false;
	}
      if(zed<0)
	{
	  if(fabs(alpha)<0.005) return false;
	  if(alpha< 0.36*board-0.36*23.3  && alpha< -0.45*board+0.45*24.2) return false;
	  if(alpha <0.032*board-0.032*27.8 && alpha >0.032*board-0.032*28.2) return false;
	  if(alpha <0.032*board-0.032*54.0 && alpha >0.032*board-0.032*54.4) return false;
	  if(board>30.8&&board<36) return false;
	}
    }
  else if(run>=236133&&run<=240121)  //-+ field
    {
      if(zed>0)
	{
	  if(fabs(alpha)<0.005);
	  if(alpha <0.032*board-0.032*27.9 && alpha >0.032*board-0.032*28.3) return false;
	  if(alpha <0.032*board-0.032*54.0 && alpha >0.032*board-0.032*54.4) return false;
	  if(board>31.8&&board<36) return false;
	}
      if(zed<0)
	{
	  if(fabs(alpha)<0.005) return false;
	  if(alpha< 0.36*board-0.36*23.3  && alpha< -0.45*board+0.45*24.2) return false;
	  if(alpha <0.032*board-0.032*27.8 && alpha >0.032*board-0.032*28.2) return false;
	  if(alpha <0.032*board-0.032*54.0 && alpha >0.032*board-0.032*54.4) return false;
	  if(board>30.8&&board<36) return false;
	}
    }
  else return false; // if the run number is somehow out of range
  return true;
}




bool GoodPC1(float ppc1z, float ppc1phi)
{

  // --- these are new fiducial cuts for projections to the PC1
  // --- rather than cut on the DC zed and phi, as was done for
  // --- the deuteron analysis, we instead cut on the PC1 variables
  // --- directly.  this fiducial map is for the entire west arm

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
 
  return true;  
  
}



bool GoodPC2(float pc2z, float pc2phi)
{

  float zed = pc2z;
  float phi = pc2phi;

  if(zed>-55&&zed<-35&&phi>0.9&&phi>-1) return false;
  if(zed>-120&&zed<-100&&phi>0.9&&phi>0.95) return false;
  if(zed>-55&&zed<-35&&phi>0.83&&phi>0.88) return false;
  if(zed>90&&zed<110&&phi>0.75&&phi>0.8) return false;
  if(zed>-120&&zed<-100&&phi>0.68&&phi>0.73) return false;
  if(zed>-70&&zed<-50&&phi>0.65&&phi>0.7) return false;
  if(zed>-70&&zed<-50&&phi>0.5&&phi>0.55) return false;
  if(zed>-25&&zed<0&&phi>0.48&&phi>0.53) return false;
  if(zed>20&&zed<40&&phi>0.48&&phi>0.53) return false;
  if(zed>-70&&zed<-50&&phi>0.4&&phi>0.45) return false;
  if(zed>75&&zed<95&&phi>0.35&&phi>0.4) return false;
  if(zed>55&&zed<75&&phi>0.33&&phi>0.38) return false;
  if(zed>55&&zed<75&&phi>0.15&&phi>0.2) return false;
  if(zed>35&&zed<55&&phi>0.13&&phi>0.18) return false;
  if(zed>75&&zed<95&&phi>-0.08&&phi>0.03) return false;
  if(zed>-160&&zed<-140&&phi>-0.13&&phi>-0.2) return false;
  if(zed>20&&zed<40&&phi>-0.13&&phi>-0.2) return false;

  return true;

}



bool GoodPC3(float pc3z, float pc3phi)
{

  // --- these are the pc3 fiducial cuts, similar to the old
  // --- this is a pc3 fiducial map of the whole west arm

  float zed = pc3z;
  float phi = pc3phi;

  if(zed>-45&&zed<-20&&phi>0.9&&phi<0.95) return false;
  if(zed>-120&&zed<-100&&phi>0.85&&phi<0.9) return false;
  if(zed>-125&&zed<-90&&phi>0.45&&phi<0.5) return false;
  if(zed>65&&zed<90&&phi>0.45&&phi<0.5) return false;
  if(zed>-105&&zed<80&&phi>0.4&&phi<0.45) return false;
  if(zed>-65&&zed<0&&phi>0.4&&phi<0.45) return false;
  if(zed>135&&zed<150&&phi>0.3&&phi<0.33) return false;
  if(zed>-65&&zed<-40&&phi>0.25&&phi<0.3) return false;
  if(zed>-85&&zed<-75&&phi>0&&phi<0.1) return false;
  if(zed>-85&&zed<-60&&phi>0.05&&phi<0.1) return false;
  if(zed>-145&&zed<-120&&phi>-0.35&&phi<-0.3) return false;
  if(zed>85&&zed<105&&phi>-0.35&&phi<-0.3) return false;
  if(zed>-200&&zed<-160&&phi>-0.55&&phi<-0.45) return false;
  if(zed>-200&&zed<-145&&phi>-0.53&&phi<-0.48) return false;
  if(zed>-145&&zed<-135&&phi>-0.5&&phi<-0.45) return false;
  if(zed>-85&&zed<-75&&phi>-0.5&&phi<-0.45) return false;
  if(zed>145&&zed<160&&phi>0.6&&phi<-0.53) return false;

  return true;

}
