// Ron Belmont
// Code to Run on pDSTs, Taxi 160 and 169
// This version does very little except run by run stuff
 
#define onepi 3.1415927
#define twopi 6.2831853

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>

 
#include "hadrontree.h"


#include "TROOT.h"
#include "TFile.h" 
#include "TH1.h" 
#include "TH2.h"   
#include "TH3.h"
#include "TF1.h" 
#include "TTree.h"

using namespace std;

//using std::pair;
//using std::make_pair;

static const int NRUN = 867;

long neve[NRUN];
long numpos[NRUN];
long numneg[NRUN];
//long numpos_W1[NRUN];
//long numneg_W1[NRUN];
//long numpos_W2[NRUN];
//long numneg_W2[NRUN];

map<string,int> myMap;

const float phbeta  = 29.9792458;

void GetRunIndex();
bool goodStrip(int i);



Long64_t nevents = 0;
Long64_t ntracks = 0;



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

  TFile *mData = new TFile(outFile,"recreate");

  // -------------------------- //
  // --- Declare histograms --- //
  // -------------------------- //

  TH1F *h_neve = new TH1F("h_neve","Number of events vs run number",867,0,867);
  TH1F *h_numpos = new TH1F("h_numpos","Number of tracks vs run number",867,0,867);
  TH1F *h_numneg = new TH1F("h_numneg","Number of tracks vs run number",867,0,867);

  //TH1F *h_neve_W1 = new TH1F("h_neve_W1","Number of events vs run number",867,0,867);
  //TH1F *h_numpos_W1 = new TH1F("h_numpos_W1","Number of tracks vs run number",867,0,867);
  //TH1F *h_numneg_W1 = new TH1F("h_numneg_W1","Number of tracks vs run number",867,0,867);

  //TH1F *h_neve_W2 = new TH1F("h_neve_W2","Number of events vs run number",867,0,867);
  //TH1F *h_numpos_W2 = new TH1F("h_numpos_W2","Number of tracks vs run number",867,0,867);
  //TH1F *h_numneg_W2 = new TH1F("h_numneg_W2","Number of tracks vs run number",867,0,867);

  // --- Done with Histograms ---------------------

  GetRunIndex();

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

	  ktree->GetEntry(i); 

	  int run = ktree->run;
	  
	  //GetRunIndex();
	  std::stringstream ss;
	  ss<<run;
	  int runindex = myMap[ss.str()]; 
	  //cout<<"run = "<<run<<" runindex = "<<runindex<<endl;
	  neve[runindex]++; // count events per run
	  h_neve->Fill(runindex); // events per run histograms

	  //these cuts are already in the pDSTs
	  //float bbcz = ktree->bbcz;
	  //if(fabs(bbcz)>30) continue;
	  float cent = ktree->cent;
	  //if(cent<0||cent>=100) continue;

	  for(int itrk=0; itrk<ktree->mNtrack; itrk++)
	    {

	      ntracks++; // count total number of tracks

	      int quality = ktree->HadronTracks_quality[itrk];
	      float zed   = ktree->HadronTracks_zed[itrk];
	      float phi   = ktree->HadronTracks_phi[itrk];
	      float alpha = ktree->HadronTracks_alpha[itrk];
	      int charge  = ktree->HadronTracks_charge[itrk];

	      bool good_dc = (fabs(zed)<70&&fabs(zed)>3&&(quality==63||quality==31));
	      //if(!good_dc)continue;

	      if(charge>0)
		{
		  numpos[runindex]++; // count number of +tracks per run
		  h_numpos->Fill(runindex); // hisogr of +tracks per run
		}
	      if(charge<0)
		{
		  numneg[runindex]++; // count number of -tracks per run
		  h_numneg->Fill(runindex); // hisogr of -tracks per run
		}
	      
	    } // End of track loop
 
	} // End of event loop

      t->Delete();
      delete ktree;
      f->Close();
      delete f;

    } // End of pDST loop


  //TFile *mData = new TFile(outFile,"recreate");
  //mData->cd();
  mData->Write();  
  mData->Close();

  cout<<"Number of events: "<<nevents<<endl;
  cout<<"Number of tracks: "<<ntracks<<endl;
  
  cout<<"End of program"<<endl; 
  exit(0); 

} 




void GetRunIndex()
{

  std::string s;
  std::ifstream f("mostruns.list");
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


