void pionpubppg()
{


  for(int icent=0; icent<12; icent++)
    {
      for(int ipid=0; ipid<4; ipid++)
	{
	  if(icent>1&&icent<9) continue;
	  doit(0,ipid,icent);
	}
    }
  
  
  cout<<"done!  have a nice day!"<<endl;

}

void doit(int sector=0, int pid=0, int centid=0)
{

  float howhigh = 8.0;

  // --- beginning of code

  gStyle->SetOptTitle(0);

  TCanvas *c1 = new TCanvas("c1","",800,600);
  c1->SetFillColor(kWhite);
  c1->SetFrameFillColor(kWhite);
  c1->SetBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->SetGrid();
  //c1->SetLogy();





  // --- strings for filenames

  char sectorstring[10];
  sprintf(sectorstring,"tofw"); // "default"
  if(sector==0) sprintf(sectorstring,"tofw");
  if(sector==1) sprintf(sectorstring,"tofw_w1");
  if(sector==2) sprintf(sectorstring,"tofw_w2");

  


  char centstring[10];
  sprintf(centstring,"0092"); // "default"
  if(centid==0) sprintf(centstring,"0010");
  if(centid==1) sprintf(centstring,"1020");
  if(centid==2) sprintf(centstring,"2030");
  if(centid==3) sprintf(centstring,"3040");
  if(centid==4) sprintf(centstring,"4050");
  if(centid==5) sprintf(centstring,"5060");
  if(centid==6) sprintf(centstring,"6070");
  if(centid==7) sprintf(centstring,"7080");
  if(centid==8) sprintf(centstring,"8092");
  if(centid==9) sprintf(centstring,"2040");
  if(centid==10) sprintf(centstring,"4060");
  if(centid==11) sprintf(centstring,"6092");

  char bigcentstring[50];
  sprintf(bigcentstring,"MinBias"); // "default"
  if(centid==0) sprintf(bigcentstring,"0-10%%");
  if(centid==1) sprintf(bigcentstring,"10-20%%");
  if(centid==2) sprintf(bigcentstring,"20-30%%");
  if(centid==3) sprintf(bigcentstring,"30-40%%");
  if(centid==4) sprintf(bigcentstring,"40-50%%");
  if(centid==5) sprintf(bigcentstring,"50-60%%");
  if(centid==6) sprintf(bigcentstring,"60-70%%");
  if(centid==7) sprintf(bigcentstring,"70-80%%");
  if(centid==8) sprintf(bigcentstring,"80-92%%");
  if(centid==9) sprintf(bigcentstring,"20-40%%");
  if(centid==10) sprintf(bigcentstring,"40-60%%");
  if(centid==11) sprintf(bigcentstring,"60-92%%");



  // ---



  // --- ppg080 stuff

  float pT_ppg080[23], yield_ppg080[23], eyield_ppg080[23];
  float ept[23];
  char finname[30];
  sprintf(finname,"ppg080/pi0_cent%s.dat",centstring);
  for(int i=0; i<23; i++)
    {
      pT_ppg080[i]=i/2.0+0.25;
      ept[i]=0;
      yield_ppg080[i]=0;
      eyield_ppg080[i]=0;
    }
  ifstream fin080(finname);
  for(int i=0; i<21; i++)
    {
      fin080>>pT_ppg080[i+2]>>yield_ppg080[i+2]>>eyield_ppg080[i+2];
    }
  fin080.close();

  // --- ppg054 stuff

  float pT_ppg054[23], yield_ppg054[23], eyield_ppg054[23];
  float ept[23];
  char finname[30];
  sprintf(finname,"ppg054/ppg054_cent%s.dat",centstring);
  for(int i=0; i<23; i++)
    {
      pT_ppg054[i]=i/2.0+0.25;
      ept[i]=0;
      yield_ppg054[i]=0;
      eyield_ppg054[i]=0;
    }
  ifstream fin054(finname);
  for(int i=0; i<21; i++)
    {
      fin054>>pT_ppg054[i+2]>>yield_ppg054[i+2]>>eyield_ppg054[i+2];
    }
  fin054.close();


  // --- ppg133 stuff

  float pT_ppg133[23], yield_ppg133[23], eyield_ppg133[23];
  float ept[23];
  char finname[30];
  sprintf(finname,"ppg133/ppg133_cent%s.dat",centstring);
  for(int i=0; i<23; i++)
    {
      pT_ppg133[i]=i/2.0+0.25;
      ept[i]=0;
      yield_ppg133[i]=0;
      eyield_ppg133[i]=0;
    }
  ifstream fin133(finname);
  for(int i=0; i<21; i++)
    {
      fin133>>pT_ppg133[i+2]>>yield_ppg133[i+2]>>eyield_ppg133[i+2];
      //cout<<" "<<pT_ppg133[i+2]<<" "<<yield_ppg133[i+2]<<" "<<eyield_ppg133[i+2]<<endl;
    }
  fin133.close();




  // --- ppg026 stuff

  float pTpos_ppg026[45], yieldpos_ppg026[45], eyieldpos_ppg026[45];
  float pTneg_ppg026[45], yieldneg_ppg026[45], eyieldneg_ppg026[45];
  float EPT[45];

  for(int i=0; i<7; i++)
    {
      pTpos_ppg026[i] = i/10.0+0.05;
      //epTpos_ppg026[i] = 0;
      yieldpos_ppg026[i] = 0;
      eyieldpos_ppg026[i] = 0;
      pTneg_ppg026[i] = i/10.0+0.05;
      //epTneg_ppg026[i] = 0;
      yieldneg_ppg026[i] = 0;
      eyieldneg_ppg026[i] = 0;
      EPT[i]=0;
    }

  int number = 1;
  int offset = 0;
  char finposname[30];
  char finnegname[30];
  if(pid<=3)
    {
      number = 28;
      offset = 2;
      sprintf(finposname,"ppg026/pospion_%s.dat",centstring);
      sprintf(finnegname,"ppg026/negpion_%s.dat",centstring);
    }
  else
    {
      cerr<<"unknown pid number, now dying a quick but horribly painful death"<<endl;
      exit(1);
    }

  ifstream finpos026(finposname);
  ifstream finneg026(finnegname);
  for(int i=0; i<number; i++)
    {
      EPT[i+offset]=0;
      finpos026>>pTpos_ppg026[i+offset]>>yieldpos_ppg026[i+offset]>>eyieldpos_ppg026[i+offset];
      finneg026>>pTneg_ppg026[i+offset]>>yieldneg_ppg026[i+offset]>>eyieldneg_ppg026[i+offset];
    }
  finpos026.close();
  finneg026.close();
  


  // ---



  // --- input data

  char fnameinposcb[100];
  char fnameinnegcb[100];

  sprintf(fnameinposcb,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegcb,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

  ifstream finposcb;
  ifstream finnegcb;

  finposcb.open(fnameinposcb);
  finnegcb.open(fnameinnegcb);

  float pT_poscb[100], yield_poscb[100], eyield_poscb[100];
  float pT_negcb[100], yield_negcb[100], eyield_negcb[100];

  for(int i=0; i<100; i++)
    {
      // poscb
      finposcb>>pT_poscb[i]>>yield_poscb[i]>>eyield_poscb[i];
      // negcb
      finnegcb>>pT_negcb[i]>>yield_negcb[i]>>eyield_negcb[i];
      if(i<5||((pid==4||pid==5)&&i>39))
	{
	  yield_poscb[i] = -9;
	  yield_negcb[i] = -9;
	}
      //if(pid==2) yield_poscb[i] /= richembed;
      //if(pid==2) yield_negcb[i] /= richembed;
    }

  finposcb.close();
  finnegcb.close();



  // --- now input the rebinned data
  // --- perfect for the pi0

  sprintf(fnameinposcb,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegcb,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

  finposcb.open(fnameinposcb);
  finnegcb.open(fnameinnegcb);

  float pTR_poscb[20], yieldR_poscb[20], eyieldR_poscb[20];
  float pTR_negcb[20], yieldR_negcb[20], eyieldR_negcb[20];

  for(int i=0; i<20; i++)
    {
      // poscb
      finposcb>>pTR_poscb[i]>>yieldR_poscb[i]>>eyieldR_poscb[i];
      // negcb
      finnegcb>>pTR_negcb[i]>>yieldR_negcb[i]>>eyieldR_negcb[i];
      //if(pid==2) yieldR_poscb[i] /= richembed;
      //if(pid==2) yieldR_negcb[i] /= richembed;
    }
  finposcb.close();
  finnegcb.close();





  float esysratio[45]; // NEW!

  float pT[45], epT[45], ratio[45], eratio[45];
  float pTA[45], epTA[45], yieldA[45], eyieldA[45];
  float pTB[45], epTB[45], yieldB[45], eyieldB[45];

  int j;





  // --------------------------------------- //
  // --- COME HERE FOR THE COMBINED PART --- //
  // --------------------------------------- //


  
  // ------------- //
  // --- poscb --- //
  // ------------- //

  for(int i=0; i<45; i++)
    {
      // A
      j=i;
      pTA[i] = -9;
      epTA[i] = 0;
      yieldA[i] = -9;
      eyieldA[i] = 0;
      j=i;
      pTA[j] = pT_poscb[i];
      epTA[j] = 0;
      yieldA[j] = yield_poscb[i];
      eyieldA[j] = eyield_poscb[i];
      pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;

      pTB[i] = pTpos_ppg026[i];
      epTB[i] = 0;
      yieldB[i] = yieldpos_ppg026[i];
      eyieldB[i] = eyieldpos_ppg026[i];

      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	  esysratio[i] = 0.1*ratio[i]; //NEW!  and temp, to be improved later
	  //cout<<"pt="<<pT[i]<<"\t"<<"run7="<<yieldA[i]<<"\t"<<"run2="<<yieldB[i]<<"\t"<<"ratio="<<ratio[i]<<endl;
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  esysratio[i] = 0;
	}
    }

  TGraphErrors *tge_poscb = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  TGraphErrors *tge_poscbSYS = new TGraphErrors(number+offset,pT,ratio,epT,esysratio);
  tge_poscbSYS->SetMarkerStyle(1);
  tge_poscbSYS->SetMarkerColor(kGray);
  tge_poscbSYS->SetLineWidth(15);
  tge_poscbSYS->SetLineColor(kGray);
  tge_poscb->SetMarkerColor(kBlack);
  tge_poscb->SetMarkerStyle(20);



  // ------------- //
  // --- negcb --- //
  // ------------- //

  for(int i=0; i<45; i++)
    {
      // A
      j=i;
      pTA[i] = -9;
      epTA[i] = 0;
      yieldA[i] = -9;
      eyieldA[i] = 0;
      j=i;
      pTA[j] = pT_negcb[i];
      epTA[j] = 0;
      yieldA[j] = yield_negcb[i];
      eyieldA[j] = eyield_negcb[i];
      pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;

      pTB[i] = pTneg_ppg026[i];
      epTB[i] = 0;
      yieldB[i] = yieldneg_ppg026[i];
      eyieldB[i] = eyieldneg_ppg026[i];

      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	  esysratio[i] = 0.1*ratio[i]; //NEW!  and temp, to be improved later
	  //cout<<"pt="<<pT[i]<<"\t"<<"run7="<<yieldA[i]<<"\t"<<"run2="<<yieldB[i]<<"\t"<<"ratio="<<ratio[i]<<endl;
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  esysratio[i] = 0;
	}
    }

  TGraphErrors *tge_negcb = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  TGraphErrors *tge_negcbSYS = new TGraphErrors(number+offset,pT,ratio,epT,esysratio);
  tge_negcbSYS->SetMarkerStyle(1);
  tge_negcbSYS->SetMarkerColor(kGray);
  tge_negcbSYS->SetLineWidth(15);
  tge_negcbSYS->SetLineColor(kGray);
  tge_negcb->SetMarkerColor(kBlack);
  tge_negcb->SetMarkerStyle(20);


  // --- now for pi0 part --- //

  c1->Clear();

  // -------------- //
  // --- ppg080 --- //
  // -------------- //

  // --- poscb ---//
  
  for(int i=0; i<16; i++)
    {
      //pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;
      
      pTA[i] = pTR_poscb[i];
      epTA[i] = 0;
      yieldA[i] = yieldR_poscb[i];
      eyieldA[i] = eyieldR_poscb[i];
      
      pTB[i] = pT_ppg080[i];
      epTB[i] = 0;
      yieldB[i] = yield_ppg080[i];
      eyieldB[i] = eyield_ppg080[i];
      
      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	  esysratio[i] = 0.1*ratio[i]; //NEW!  and temp, to be improved later
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  esysratio[i] = 0;
	}
      
      //cout<<pT_ppg080[i]<<"\t"<<yield_ppg080[i]<<endl;
      //cout<<pTB[i]<<"\t"<<yieldB[i]<<"\t"<<pTA[i]<<"\t"<<yieldA[i]<<endl;
      
    } // end of for loop to calculate ratio
  TGraphErrors *tge2_poscb = new TGraphErrors(16,pT,ratio,epT,eratio);
  tge2_poscb->SetMarkerColor(kRed);
  tge2_poscb->SetMarkerStyle(21);
  TGraphErrors *tge2_poscbSYS = new TGraphErrors(16,pT,ratio,epT,esysratio);
  tge2_poscbSYS->SetMarkerColor(kRed);
  tge2_poscbSYS->SetMarkerStyle(1);
  tge2_poscbSYS->SetLineColor(kRed-10);
  tge2_poscbSYS->SetLineWidth(15);
  
  // --- negcb ---//
  
  for(int i=0; i<16; i++)
    {
      //pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;
      
      pTA[i] = pTR_negcb[i];
      epTA[i] = 0;
      yieldA[i] = yieldR_negcb[i];
      eyieldA[i] = eyieldR_negcb[i];
      
      pTB[i] = pT_ppg080[i];
      epTB[i] = 0;
      yieldB[i] = yield_ppg080[i];
      eyieldB[i] = eyield_ppg080[i];
      
      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	  esysratio[i] = 0.1*ratio[i]; //NEW!  and temp, to be improved later
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  esysratio[i] = 0;
	}
      
      //cout<<pT_ppg080[i]<<"\t"<<yield_ppg080[i]<<"\t"<<eyield_ppg080[i]<<endl;
      //cout<<pTB[i]<<"\t"<<yieldB[i]<<"\t"<<pTA[i]<<"\t"<<yieldA[i]<<endl;
      //cout<<pTB[i]<<"\t"<<eyieldB[i]<<"\t"<<pTA[i]<<"\t"<<eyieldA[i]<<endl;
      
    } // end of for loop to calculate ratio
  TGraphErrors *tge2_negcb = new TGraphErrors(16,pT,ratio,epT,eratio);
  tge2_negcb->SetMarkerColor(kRed);
  tge2_negcb->SetMarkerStyle(21);
  TGraphErrors *tge2_negcbSYS = new TGraphErrors(16,pT,ratio,epT,esysratio);
  tge2_negcbSYS->SetMarkerColor(kRed);
  tge2_negcbSYS->SetMarkerStyle(1);
  tge2_negcbSYS->SetLineColor(kRed-10);
  tge2_negcbSYS->SetLineWidth(15);
  
  





  // -------------- //
  // --- ppg054 --- //
  // -------------- //

  // --- poscb ---//
  
  for(int i=0; i<16; i++)
    {
      //pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;
      
      pTA[i] = pTR_poscb[i];
      epTA[i] = 0;
      yieldA[i] = yieldR_poscb[i];
      eyieldA[i] = eyieldR_poscb[i];
      
      pTB[i] = pT_ppg054[i];
      epTB[i] = 0;
      yieldB[i] = yield_ppg054[i];
      eyieldB[i] = eyield_ppg054[i];
      
      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	  esysratio[i] = 0.1*ratio[i]; //NEW!  and temp, to be improved later
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  esysratio[i] = 0;
	}
      
      //cout<<pT_ppg054[i]<<"\t"<<yield_ppg054[i]<<endl;
      //cout<<pTB[i]<<"\t"<<yieldB[i]<<"\t"<<pTA[i]<<"\t"<<yieldA[i]<<endl;
      
    } // end of for loop to calculate ratio
  TGraphErrors *tge3_poscb = new TGraphErrors(16,pT,ratio,epT,eratio);
  tge3_poscb->SetMarkerColor(kBlue);
  tge3_poscb->SetMarkerStyle(21);
  TGraphErrors *tge3_poscbSYS = new TGraphErrors(16,pT,ratio,epT,esysratio);
  tge3_poscbSYS->SetMarkerColor(kBlue);
  tge3_poscbSYS->SetMarkerStyle(1);
  tge3_poscbSYS->SetLineColor(kBlue-10);
  tge3_poscbSYS->SetLineWidth(15);
  
  // --- negcb ---//
  
  for(int i=0; i<16; i++)
    {
      //pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;
      
      pTA[i] = pTR_negcb[i];
      epTA[i] = 0;
      yieldA[i] = yieldR_negcb[i];
      eyieldA[i] = eyieldR_negcb[i];
      
      pTB[i] = pT_ppg054[i];
      epTB[i] = 0;
      yieldB[i] = yield_ppg054[i];
      eyieldB[i] = eyield_ppg054[i];
      
      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	  esysratio[i] = 0.1*ratio[i]; //NEW!  and temp, to be improved later
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  esysratio[i] = 0;
	}
      
      //cout<<pT_ppg054[i]<<"\t"<<yield_ppg054[i]<<"\t"<<eyield_ppg054[i]<<endl;
      //cout<<pTB[i]<<"\t"<<yieldB[i]<<"\t"<<pTA[i]<<"\t"<<yieldA[i]<<endl;
      //cout<<pTB[i]<<"\t"<<eyieldB[i]<<"\t"<<pTA[i]<<"\t"<<eyieldA[i]<<endl;
      
    } // end of for loop to calculate ratio
  TGraphErrors *tge3_negcb = new TGraphErrors(16,pT,ratio,epT,eratio);
  tge3_negcb->SetMarkerColor(kBlue);
  tge3_negcb->SetMarkerStyle(21);
  TGraphErrors *tge3_negcbSYS = new TGraphErrors(16,pT,ratio,epT,esysratio);
  tge3_negcbSYS->SetMarkerColor(kBlue);
  tge3_negcbSYS->SetMarkerStyle(1);
  tge3_negcbSYS->SetLineColor(kBlue-10);
  tge3_negcbSYS->SetLineWidth(15);
  
  




  // --- come back here for ppg133


  // -------------- //
  // --- ppg133 --- //
  // -------------- //

  // --- poscb ---//
  
  for(int i=0; i<16; i++)
    {
      //pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;
      
      pTA[i] = pTR_poscb[i];
      epTA[i] = 0;
      yieldA[i] = yieldR_poscb[i];
      eyieldA[i] = eyieldR_poscb[i];
      
      pTB[i] = pT_ppg133[i];
      epTB[i] = 0;
      yieldB[i] = yield_ppg133[i];
      eyieldB[i] = eyield_ppg133[i];
      
      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	  esysratio[i] = 0.1*ratio[i]; //NEW!  and temp, to be improved later
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  esysratio[i] = 0;
	}
      
      //cout<<pT_ppg133[i]<<"\t"<<yield_ppg133[i]<<endl;
      //cout<<pTB[i]<<"\t"<<yieldB[i]<<"\t"<<pTA[i]<<"\t"<<yieldA[i]<<endl;
      
    } // end of for loop to calculate ratio
  TGraphErrors *tge4_poscb = new TGraphErrors(16,pT,ratio,epT,eratio);
  tge4_poscb->SetMarkerColor(kRed);
  tge4_poscb->SetMarkerStyle(21);
  TGraphErrors *tge4_poscbSYS = new TGraphErrors(16,pT,ratio,epT,esysratio);
  tge4_poscbSYS->SetMarkerColor(kRed);
  tge4_poscbSYS->SetMarkerStyle(1);
  tge4_poscbSYS->SetLineColor(kRed-10);
  tge4_poscbSYS->SetLineWidth(15);
  
  // --- negcb ---//
  
  for(int i=0; i<16; i++)
    {
      //pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;
      
      pTA[i] = pTR_negcb[i];
      epTA[i] = 0;
      yieldA[i] = yieldR_negcb[i];
      eyieldA[i] = eyieldR_negcb[i];
      
      pTB[i] = pT_ppg133[i];
      epTB[i] = 0;
      yieldB[i] = yield_ppg133[i];
      eyieldB[i] = eyield_ppg133[i];
      
      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	  esysratio[i] = 0.1*ratio[i]; //NEW!  and temp, to be improved later
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  esysratio[i] = 0;
	}
      
      //cout<<pT_ppg133[i]<<"\t"<<yield_ppg133[i]<<"\t"<<eyield_ppg133[i]<<endl;
      //cout<<pTB[i]<<"\t"<<yieldB[i]<<"\t"<<pTA[i]<<"\t"<<yieldA[i]<<endl;
      //cout<<pTB[i]<<"\t"<<eyieldB[i]<<"\t"<<pTA[i]<<"\t"<<eyieldA[i]<<endl;
      
    } // end of for loop to calculate ratio
  TGraphErrors *tge4_negcb = new TGraphErrors(16,pT,ratio,epT,eratio);
  tge4_negcb->SetMarkerColor(kRed);
  tge4_negcb->SetMarkerStyle(21);
  TGraphErrors *tge4_negcbSYS = new TGraphErrors(16,pT,ratio,epT,esysratio);
  tge4_negcbSYS->SetMarkerColor(kRed);
  tge4_negcbSYS->SetMarkerStyle(1);
  tge4_negcbSYS->SetLineColor(kRed-10);
  tge4_negcbSYS->SetLineWidth(15);
  
  











  // ---------------- //
  // --- now draw --- //
  // ---------------- //


  
  
  c1->Clear();  
  
  TMultiGraph *tmg_pos_cb = new TMultiGraph();
  tmg_pos_cb->Add(tge_poscbSYS);
  //tmg_pos_cb->Add(tge2_poscbSYS);
  tmg_pos_cb->Add(tge4_poscbSYS);
  tmg_pos_cb->Add(tge3_poscbSYS);
  tmg_pos_cb->Add(tge_poscb);
  //tmg_pos_cb->Add(tge2_poscb);
  tmg_pos_cb->Add(tge4_poscb);
  tmg_pos_cb->Add(tge3_poscb);
  tmg_pos_cb->Draw("apz");
  tmg_pos_cb->SetMaximum(2.0);
  tmg_pos_cb->SetMinimum(0.0);
  tmg_pos_cb->GetXaxis()->SetLimits(0.0,howhigh);
  tmg_pos_cb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_pos_cb->GetXaxis()->CenterTitle();
  tmg_pos_cb->GetYaxis()->SetTitle("Ratio");
  tmg_pos_cb->GetYaxis()->CenterTitle();
  
  TPaveText *pave_pos_cb = new TPaveText(1.01, 0.1, 2.5, 0.3, "br");
  pave_pos_cb->SetFillColor(10);
  pave_pos_cb->SetBorderSize(0);
  TText *text_pos_cb = pave_pos_cb->AddText(bigcentstring);
  pave_pos_cb->Draw();
  
  TPaveText *pave2_pos_cb = new TPaveText(0.5, 2.04, 7.5, 2.2, "br");
  pave2_pos_cb->SetFillColor(10);
  pave2_pos_cb->SetBorderSize(0);
  TText *text2_pos_cb = pave2_pos_cb->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  pave2_pos_cb->Draw();
  
  //TLegend *leg_pos_cb = new TLegend(0.68,0.18,0.88,0.38);
  TLegend *leg_pos_cb = new TLegend(0.55,0.12,0.88,0.32);
  leg_pos_cb->SetFillColor(kWhite);
  leg_pos_cb->SetBorderSize(0);
  leg_pos_cb->AddEntry(tge_poscb,"#pi^{+}, Run7/ppg026","p");
  leg_pos_cb->AddEntry(tge3_poscb,"#pi^{+}, Run7/ppg054","p");
  //leg_pos_cb->AddEntry(tge2_poscb,"#pi^{+}, Run7/ppg080","p");
  leg_pos_cb->AddEntry(tge4_poscb,"#pi^{+}, Run7/ppg133","p");
  leg_pos_cb->Draw();
  
  char gifname_pos_cb[100];
  sprintf(gifname_pos_cb,"RatioFigures/PionSingle_published_%s_pos_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_pos_cb[100];
  sprintf(epsname_pos_cb,"RatioFigures/PionSingle_published_%s_pos_%d_dis_cent%s.eps",sectorstring,pid,centstring);
  
  c1->Print(gifname_pos_cb);
  c1->Print(epsname_pos_cb);
  
  
  
  
  
  c1->Clear();  
  
  TMultiGraph *tmg_neg_cb = new TMultiGraph();
  tmg_neg_cb->Add(tge_negcbSYS);
  //tmg_neg_cb->Add(tge2_negcbSYS);
  tmg_neg_cb->Add(tge4_negcbSYS);
  tmg_neg_cb->Add(tge3_negcbSYS);
  tmg_neg_cb->Add(tge_negcb);
  //tmg_neg_cb->Add(tge2_negcb);
  tmg_neg_cb->Add(tge4_negcb);
  tmg_neg_cb->Add(tge3_negcb);
  tmg_neg_cb->Draw("apz");
  tmg_neg_cb->SetMaximum(2.0);
  tmg_neg_cb->SetMinimum(0.0);
  tmg_neg_cb->GetXaxis()->SetLimits(0.0,howhigh);
  tmg_neg_cb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_neg_cb->GetXaxis()->CenterTitle();
  tmg_neg_cb->GetYaxis()->SetTitle("Ratio");
  tmg_neg_cb->GetYaxis()->CenterTitle();
  
  TPaveText *pave_neg_cb = new TPaveText(1.01, 0.1, 2.5, 0.3, "br");
  pave_neg_cb->SetFillColor(10);
  pave_neg_cb->SetBorderSize(0);
  TText *text_neg_cb = pave_neg_cb->AddText(bigcentstring);
  pave_neg_cb->Draw();
  
  TPaveText *pave2_neg_cb = new TPaveText(0.5, 2.04, 7.5, 2.2, "br");
  pave2_neg_cb->SetFillColor(10);
  pave2_neg_cb->SetBorderSize(0);
  TText *text2_neg_cb = pave2_neg_cb->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  pave2_neg_cb->Draw();
  
  //TLegend *leg_neg_cb = new TLegend(0.68,0.18,0.88,0.38);
  TLegend *leg_neg_cb = new TLegend(0.55,0.12,0.88,0.32);
  leg_neg_cb->SetFillColor(kWhite);
  leg_neg_cb->SetBorderSize(0);
  leg_neg_cb->AddEntry(tge_negcb,"#pi^{-}, Run7/ppg026","p");
  leg_neg_cb->AddEntry(tge3_negcb,"#pi^{-}, Run7/ppg054","p");
  //leg_neg_cb->AddEntry(tge2_negcb,"#pi^{-}, Run7/ppg080","p");
  leg_neg_cb->AddEntry(tge4_negcb,"#pi^{-}, Run7/ppg133","p");
  leg_neg_cb->Draw();
  
  char gifname_neg_cb[100];
  sprintf(gifname_neg_cb,"RatioFigures/PionSingle_published_%s_neg_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_neg_cb[100];
  sprintf(epsname_neg_cb,"RatioFigures/PionSingle_published_%s_neg_%d_dis_cent%s.eps",sectorstring,pid,centstring);
  
  c1->Print(gifname_neg_cb);
  c1->Print(epsname_neg_cb);
  
  





  // ----------------------- //
  // --- NEWNEWNEWNEWNEW --- //
  // ----------------------- //

  for(int i=0; i<45; i++)
    {
      // A
      j=i;
      pTA[i] = -9;
      epTA[i] = 0;
      yieldA[i] = -9;
      eyieldA[i] = 0;
      j=i;
      pTA[j] = (pT_negcb[i]+pT_poscb[i])/2.0;
      epTA[j] = 0;
      yieldA[j] = (yield_negcb[i]+yield_poscb[i])/2.0;
      eyieldA[j] = sqrt(eyield_negcb[i]**2+eyield_poscb[i]**2)/2.0;
      pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;

      pTB[i] = (pTneg_ppg026[i]+pTpos_ppg026[i])/2.0;
      epTB[i] = 0;
      yieldB[i] = (yieldneg_ppg026[i]+yieldpos_ppg026[i])/2.0;
      eyieldB[i] = sqrt(eyieldneg_ppg026[i]**2+eyieldpos_ppg026[i]**2)/2.0;

      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	  esysratio[i] = 0.1*ratio[i]; //NEW!  and temp, to be improved later
	  //cout<<"pt="<<pT[i]<<"\t"<<"run7="<<yieldA[i]<<"\t"<<"run2="<<yieldB[i]<<"\t"<<"ratio="<<ratio[i]<<endl;
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  esysratio[i] = 0;
	}
    }

  TGraphErrors *tge_pancb = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  TGraphErrors *tge_pancbSYS = new TGraphErrors(number+offset,pT,ratio,epT,esysratio);
  tge_pancbSYS->SetMarkerStyle(1);
  tge_pancbSYS->SetMarkerColor(kGray);
  tge_pancbSYS->SetLineWidth(15);
  tge_pancbSYS->SetLineColor(kGray);
  tge_pancb->SetMarkerColor(kBlack);
  tge_pancb->SetMarkerStyle(20);

  for(int i=0; i<16; i++)
    {
      //pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;
      
      pTA[i] = (pTR_negcb[i]+pTR_poscb[i])/2.0;
      epTA[i] = 0;
      yieldA[i] = (yieldR_negcb[i]+yieldR_poscb[i])/2.0;
      eyieldA[i] = sqrt(eyieldR_negcb[i]**2+eyieldR_poscb[i]**2)/2.0;
      
      pTB[i] = pT_ppg080[i];
      epTB[i] = 0;
      yieldB[i] = yield_ppg080[i];
      eyieldB[i] = eyield_ppg080[i];
      
      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	  esysratio[i] = 0.1*ratio[i]; //NEW!  and temp, to be improved later
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  esysratio[i] = 0;
	}
      
      //cout<<pT_ppg054[i]<<"\t"<<yield_ppg054[i]<<"\t"<<eyield_ppg054[i]<<endl;
      //cout<<pTB[i]<<"\t"<<yieldB[i]<<"\t"<<pTA[i]<<"\t"<<yieldA[i]<<endl;
      //cout<<pTB[i]<<"\t"<<eyieldB[i]<<"\t"<<pTA[i]<<"\t"<<eyieldA[i]<<endl;
      
    } // end of for loop to calculate ratio
  TGraphErrors *tge2_pancb = new TGraphErrors(16,pT,ratio,epT,eratio);
  tge2_pancb->SetMarkerColor(kRed);
  tge2_pancb->SetMarkerStyle(21);
  TGraphErrors *tge2_pancbSYS = new TGraphErrors(16,pT,ratio,epT,esysratio);
  tge2_pancbSYS->SetMarkerColor(kRed);
  tge2_pancbSYS->SetMarkerStyle(1);
  tge2_pancbSYS->SetLineColor(kRed-10);
  tge2_pancbSYS->SetLineWidth(15);

  for(int i=0; i<16; i++)
    {
      //pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;
      
      pTA[i] = (pTR_negcb[i]+pTR_poscb[i])/2.0;
      epTA[i] = 0;
      yieldA[i] = (yieldR_negcb[i]+yieldR_poscb[i])/2.0;
      eyieldA[i] = sqrt(eyieldR_negcb[i]**2+eyieldR_poscb[i]**2)/2.0;
      
      pTB[i] = pT_ppg054[i];
      epTB[i] = 0;
      yieldB[i] = yield_ppg054[i];
      eyieldB[i] = eyield_ppg054[i];
      
      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	  esysratio[i] = 0.1*ratio[i]; //NEW!  and temp, to be improved later
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  esysratio[i] = 0;
	}
      
      //cout<<pT_ppg054[i]<<"\t"<<yield_ppg054[i]<<"\t"<<eyield_ppg054[i]<<endl;
      //cout<<pTB[i]<<"\t"<<yieldB[i]<<"\t"<<pTA[i]<<"\t"<<yieldA[i]<<endl;
      //cout<<pTB[i]<<"\t"<<eyieldB[i]<<"\t"<<pTA[i]<<"\t"<<eyieldA[i]<<endl;
      
    } // end of for loop to calculate ratio
  TGraphErrors *tge3_pancb = new TGraphErrors(16,pT,ratio,epT,eratio);
  tge3_pancb->SetMarkerColor(kBlue);
  tge3_pancb->SetMarkerStyle(21);
  TGraphErrors *tge3_pancbSYS = new TGraphErrors(16,pT,ratio,epT,esysratio);
  tge3_pancbSYS->SetMarkerColor(kBlue);
  tge3_pancbSYS->SetMarkerStyle(1);
  tge3_pancbSYS->SetLineColor(kBlue-10);
  tge3_pancbSYS->SetLineWidth(15);


  // come back here for ppg133

  for(int i=0; i<16; i++)
    {
      //pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;
      
      pTA[i] = (pTR_negcb[i]+pTR_poscb[i])/2.0;
      epTA[i] = 0;
      yieldA[i] = (yieldR_negcb[i]+yieldR_poscb[i])/2.0;
      eyieldA[i] = sqrt(eyieldR_negcb[i]**2+eyieldR_poscb[i]**2)/2.0;
      
      pTB[i] = pT_ppg133[i];
      epTB[i] = 0;
      yieldB[i] = yield_ppg133[i];
      eyieldB[i] = eyield_ppg133[i];
      
      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	  esysratio[i] = 0.1*ratio[i]; //NEW!  and temp, to be improved later
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  esysratio[i] = 0;
	}
      
      //cout<<pT_ppg133[i]<<"\t"<<yield_ppg133[i]<<"\t"<<eyield_ppg133[i]<<endl;
      //cout<<pTB[i]<<"\t"<<yieldB[i]<<"\t"<<pTA[i]<<"\t"<<yieldA[i]<<endl;
      //cout<<pTB[i]<<"\t"<<eyieldB[i]<<"\t"<<pTA[i]<<"\t"<<eyieldA[i]<<endl;
      
    } // end of for loop to calculate ratio
  TGraphErrors *tge4_pancb = new TGraphErrors(16,pT,ratio,epT,eratio);
  tge4_pancb->SetMarkerColor(kRed);
  tge4_pancb->SetMarkerStyle(21);
  TGraphErrors *tge4_pancbSYS = new TGraphErrors(16,pT,ratio,epT,esysratio);
  tge4_pancbSYS->SetMarkerColor(kRed);
  tge4_pancbSYS->SetMarkerStyle(1);
  tge4_pancbSYS->SetLineColor(kRed-10);
  tge4_pancbSYS->SetLineWidth(15);


  c1->Clear();  
  
  TMultiGraph *tmg_pan_cb = new TMultiGraph();
  tmg_pan_cb->Add(tge_pancbSYS);
  //tmg_pan_cb->Add(tge2_pancbSYS);
  tmg_pan_cb->Add(tge4_pancbSYS);
  tmg_pan_cb->Add(tge3_pancbSYS);
  tmg_pan_cb->Add(tge_pancb);
  //tmg_pan_cb->Add(tge2_pancb);
  tmg_pan_cb->Add(tge4_pancb);
  tmg_pan_cb->Add(tge3_pancb);
  tmg_pan_cb->Draw("apz");
  tmg_pan_cb->SetMaximum(2.0);
  tmg_pan_cb->SetMinimum(0.0);
  tmg_pan_cb->GetXaxis()->SetLimits(0.0,howhigh);
  tmg_pan_cb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_pan_cb->GetXaxis()->CenterTitle();
  tmg_pan_cb->GetYaxis()->SetTitle("Ratio");
  tmg_pan_cb->GetYaxis()->CenterTitle();
  
  TPaveText *pave_pan_cb = new TPaveText(1.01, 0.1, 2.5, 0.3, "br");
  pave_pan_cb->SetFillColor(10);
  pave_pan_cb->SetBorderSize(0);
  TText *text_pan_cb = pave_pan_cb->AddText(bigcentstring);
  pave_pan_cb->Draw();
  
  TPaveText *pave2_pan_cb = new TPaveText(0.5, 2.04, 7.5, 2.2, "br");
  pave2_pan_cb->SetFillColor(10);
  pave2_pan_cb->SetBorderSize(0);
  TText *text2_pan_cb = pave2_pan_cb->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  pave2_pan_cb->Draw();
  
  //TLegend *leg_pan_cb = new TLegend(0.68,0.18,0.88,0.38);
  TLegend *leg_pan_cb = new TLegend(0.51,0.12,0.88,0.32);
  leg_pan_cb->SetFillColor(kWhite);
  leg_pan_cb->SetBorderSize(0);
  leg_pan_cb->AddEntry(tge_pancb, "(#pi^{+}+#pi^{-})/2, Run7/ppg026","p");
  leg_pan_cb->AddEntry(tge3_pancb,"(#pi^{+}+#pi^{-})/2, Run7/ppg054","p");
  //leg_pan_cb->AddEntry(tge2_pancb,"(#pi^{+}+#pi^{-})/2, Run7/ppg080","p");
  leg_pan_cb->AddEntry(tge4_pancb,"(#pi^{+}+#pi^{-})/2, Run7/ppg133","p");
  leg_pan_cb->Draw();
  
  char gifname_pan_cb[100];
  sprintf(gifname_pan_cb,"RatioFigures/PionSingle_published_%s_pan_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_pan_cb[100];
  sprintf(epsname_pan_cb,"RatioFigures/PionSingle_published_%s_pan_%d_dis_cent%s.eps",sectorstring,pid,centstring);
  
  c1->Print(gifname_pan_cb);
  c1->Print(epsname_pan_cb);


    
}
