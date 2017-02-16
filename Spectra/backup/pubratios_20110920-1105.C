void pubratios()
{

  cout<<"hello! unfortunately, this is nowhere near as much fun "<<endl
      <<"as the name of the macro would suggest but it will make some"<<endl
      <<"nice plots of the ratios of the Run7 spectra to the"<<endl
      <<"published Run2 spectra for you."<<endl;

  //doit();

  //exit(0);

  // for(int icent=0; icent<12; icent++)
  //   {
  //     for(int ipid=0; ipid<10; ipid++)
  // 	{
  // 	  for(int isec=0; isec<3; isec++)
  // 	    {
  // 	      //if(icent>8&&isec>0) continue;
  // 	      doit(isec,ipid,icent);
  // 	      //cout<<"doit("<<isec<<","<<ipid<<","<<icent<<");"<<endl;
  // 	    }
  // 	}
  //   }

  for(int icent=0; icent<12; icent++)
    {
      for(int ipid=0; ipid<10; ipid++)
	{
	  for(int isec=0; isec<3; isec++)
	    {
	      if(isec>0) continue;
	      if(icent>1&&icent<9) continue;
	      doit(isec,ipid,icent);
	    }
	}
    }
  
  
  cout<<"done!  have a nice day!"<<endl;

}

void doit(int sector=0, int pid=0, int centid=0)
{

  // --- beginning of code

  gStyle->SetOptTitle(0);

  TCanvas *c1 = new TCanvas("c1","",800,600);
  c1->SetFillColor(kWhite);
  c1->SetFrameFillColor(kWhite);
  c1->SetBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->SetGrid();
  //c1->SetLogy();


  // rich embedding numbers
  // 5 0.857551 0.00863363
  // 15 0.881892 0.00950517
  // 25 0.914069 0.0105898
  // 35 0.924324 0.0114576
  // 45 0.94237 0.0121242
  // 55 0.949989 0.0125796
  // 65 0.957725 0.0130903
  // 75 0.959496 0.0130969
  // 85 0.964765 0.0131558
  // float richembed;
  // if(centid==0) richembed = 0.85;//sprintf(centstring,"0010");
  // if(centid==1) richembed = 0.88;//sprintf(centstring,"1020");
  // if(centid==2) richembed = 0.91;//sprintf(centstring,"2030");
  // if(centid==3) richembed = 0.92;//sprintf(centstring,"3040");
  // if(centid==4) richembed = 0.94;//sprintf(centstring,"4050");
  // if(centid==5) richembed = 0.95;//sprintf(centstring,"5060");
  // if(centid==6) richembed = 0.96;//sprintf(centstring,"6070");
  // if(centid==7) richembed = 0.96;//sprintf(centstring,"7080");
  // if(centid==8) richembed = 0.96;//sprintf(centstring,"8092");
  // if(centid==9) richembed = 0.92;//sprintf(centstring,"2040");
  // if(centid==10) richembed = 0.94;//sprintf(centstring,"4060");
  // if(centid==11) richembed = 0.96;//sprintf(centstring,"6092");



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
  else if(pid==4||pid==5)
    {
      number = 18;
      offset = 2;
      sprintf(finposname,"ppg026/poskaon_%s.dat",centstring);
      sprintf(finnegname,"ppg026/negkaon_%s.dat",centstring);
    }
  else if(pid>=6)
    {
      number = 39;
      offset = 6;
      sprintf(finposname,"ppg026/posproton_%s.dat",centstring);
      sprintf(finnegname,"ppg026/negproton_%s.dat",centstring);
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

  char fnameinpospm[100];
  char fnameinnegpm[100];
  char fnameinposmp[100];
  char fnameinnegmp[100];
  char fnameinposcb[100];
  char fnameinnegcb[100];

  sprintf(fnameinpospm,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegpm,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameinposmp,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegmp,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameinposcb,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegcb,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

  ifstream finpospm;
  ifstream finnegpm;
  ifstream finposmp;
  ifstream finnegmp;
  ifstream finposcb;
  ifstream finnegcb;

  finpospm.open(fnameinpospm);
  finnegpm.open(fnameinnegpm);
  finposmp.open(fnameinposmp);
  finnegmp.open(fnameinnegmp);
  finposcb.open(fnameinposcb);
  finnegcb.open(fnameinnegcb);

  float pT_pospm[100], yield_pospm[100], eyield_pospm[100];
  float pT_negpm[100], yield_negpm[100], eyield_negpm[100];
  float pT_posmp[100], yield_posmp[100], eyield_posmp[100];
  float pT_negmp[100], yield_negmp[100], eyield_negmp[100];
  float pT_poscb[100], yield_poscb[100], eyield_poscb[100];
  float pT_negcb[100], yield_negcb[100], eyield_negcb[100];

  for(int i=0; i<100; i++)
    {
      // pospm
      finpospm>>pT_pospm[i]>>yield_pospm[i]>>eyield_pospm[i];
      //cout<<pT_pospm[i]<<"\t"<<yield_pospm[i]<<"\t"<<eyield_pospm[i]<<endl;
      // negpm
      finnegpm>>pT_negpm[i]>>yield_negpm[i]>>eyield_negpm[i];
      // posmp
      finposmp>>pT_posmp[i]>>yield_posmp[i]>>eyield_posmp[i];
      // negmp
      finnegmp>>pT_negmp[i]>>yield_negmp[i]>>eyield_negmp[i];
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

  finpospm.close();
  finnegpm.close();
  finposmp.close();
  finnegmp.close();
  finposcb.close();
  finnegcb.close();



  // --- now input the rebinned data
  // --- perfect for the pi0

  sprintf(fnameinpospm,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegpm,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameinposmp,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegmp,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameinposcb,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegcb,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

  finpospm.open(fnameinpospm);
  finnegpm.open(fnameinnegpm);
  finposmp.open(fnameinposmp);
  finnegmp.open(fnameinnegmp);
  finposcb.open(fnameinposcb);
  finnegcb.open(fnameinnegcb);

  float pTR_pospm[20], yieldR_pospm[20], eyieldR_pospm[20];
  float pTR_negpm[20], yieldR_negpm[20], eyieldR_negpm[20];
  float pTR_posmp[20], yieldR_posmp[20], eyieldR_posmp[20];
  float pTR_negmp[20], yieldR_negmp[20], eyieldR_negmp[20];
  float pTR_poscb[20], yieldR_poscb[20], eyieldR_poscb[20];
  float pTR_negcb[20], yieldR_negcb[20], eyieldR_negcb[20];

  for(int i=0; i<20; i++)
    {
      // pospm
      finpospm>>pTR_pospm[i]>>yieldR_pospm[i]>>eyieldR_pospm[i];
      // negpm
      finnegpm>>pTR_negpm[i]>>yieldR_negpm[i]>>eyieldR_negpm[i];
      // posmp
      finposmp>>pTR_posmp[i]>>yieldR_posmp[i]>>eyieldR_posmp[i];
      // negmp
      finnegmp>>pTR_negmp[i]>>yieldR_negmp[i]>>eyieldR_negmp[i];
      // poscb
      finposcb>>pTR_poscb[i]>>yieldR_poscb[i]>>eyieldR_poscb[i];
      // negcb
      finnegcb>>pTR_negcb[i]>>yieldR_negcb[i]>>eyieldR_negcb[i];
      //if(pid==2) yieldR_poscb[i] /= richembed;
      //if(pid==2) yieldR_negcb[i] /= richembed;
    }

  finpospm.close();
  finnegpm.close();
  finposmp.close();
  finnegmp.close();
  finposcb.close();
  finnegcb.close();





  float esysratio[45]; // NEW!

  float pT[45], epT[45], ratio[45], eratio[45];
  float pTA[45], epTA[45], yieldA[45], eyieldA[45];
  float pTB[45], epTB[45], yieldB[45], eyieldB[45];

  int j;

  // ----------------------------------------- //
  // --- THIS IS WHERE THE RUN8 CODE BEGAN --- //
  // ------------- SO START HERE ------------- //
  // ----------------------------------------- //

  // ------------- //
  // --- pospm --- //
  // ------------- //

  // for(int i=0; i<36; i++)
  //   {
  //     // A
  //     j=i;
  //     pTA[i] = -9;
  //     epTA[i] = 0;
  //     yieldA[i] = -9;
  //     eyieldA[i] = 0;
  //     if(i<15)
  // 	{
  // 	  j=i;
  // 	  pTA[j] = pT_pospm[i];
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = yield_pospm[i];
  // 	  eyieldA[j] = eyield_pospm[i];
  // 	}
  //     if(i>14&&i<27)
  // 	{
  // 	  if(i%2!=1) continue;
  // 	  j=i/2+8;
  // 	  pTA[j] = (pT_pospm[i]+pT_pospm[i+1])/2.0;
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = (yield_pospm[i]+yield_pospm[i+1])/2.0;
  // 	  eyieldA[j] = sqrt(eyield_pospm[i]**2+eyield_pospm[i+1]**2)/2.0;
  // 	}
  //     if(i==27)
  // 	{
  // 	  j=21;
  // 	  pTA[j] = (pT_pospm[i]+pT_pospm[i+1]+pT_pospm[i+2]+pT_pospm[i+3])/4.0;
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = (yield_pospm[i]+yield_pospm[i+1]+yield_pospm[i+2]+yield_pospm[i+3])/4.0;
  // 	  eyieldA[j] = sqrt(eyield_pospm[i]**2+eyield_pospm[i+1]**2+eyield_pospm[i+2]**2+eyield_pospm[i+3]**2)/4.0;
  // 	}
  //     if(i>27)
  // 	{
  // 	  if(i%6!=1) continue;
  // 	  j=i/6+17;
  // 	  pTA[j] = (pT_pospm[i]+pT_pospm[i+1]+pT_pospm[i+2]+
  // 		    pT_pospm[i+3]+pT_pospm[i+4]+pT_pospm[i+5])/6.0;
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = (yield_pospm[i]+yield_pospm[i+1]+yield_pospm[i+2]+
  // 		       yield_pospm[i+3]+yield_pospm[i+4]+yield_pospm[i+5])/6.0;
  // 	  eyieldA[j] = sqrt(eyield_pospm[i]**2+eyield_pospm[i+1]**2+eyield_pospm[i+2]**2+
  // 			    eyield_pospm[i+3]**2+eyield_pospm[i+4]**2+eyield_pospm[i+5]**2)/6.0;
  // 	}

  //   } // end of for loop for rebinning

  // for(int i=0; i<23; i++)
  //   {
  //     pT[i] = pTA[i];
  //     epT[i] = 0;
  //     ratio[i] = -9;
  //     eratio[i] = 0;

  //     pTB[i] = pTpos_ppg026[i];
  //     epTB[i] = 0;
  //     yieldB[i] = yieldpos_ppg026[i];
  //     eyieldB[i] = eyieldpos_ppg026[i];

  //     // now do ratio
  //     if(yieldA[i]>0&&yieldB[i]>0)
  // 	{
  // 	  pT[i] = (pTA[i]+pTB[i])/2.0;
  // 	  epT[i] = 0;
  // 	  ratio[i] = yieldA[i]/yieldB[i];
  // 	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
  // 	}
  //     else
  // 	{
  // 	  pT[i] = pTA[i];
  // 	  epT[i] = 0;
  // 	  ratio[i] = -9;
  // 	  eratio[i] = 0;
  // 	}
  //   } // end of for loop to calculate ratio
  // TGraphErrors *tge_pospm = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  // tge_pospm->SetMarkerColor(kBlue);
  // tge_pospm->SetMarkerStyle(20);

  // // ---

  // // ------------- //
  // // --- negpm --- //
  // // ------------- //

  // for(int i=0; i<36; i++)
  //   {
  //     // A
  //     j=i;
  //     pTA[i] = -9;
  //     epTA[i] = 0;
  //     yieldA[i] = -9;
  //     eyieldA[i] = 0;
  //     if(i<15)
  // 	{
  // 	  j=i;
  // 	  pTA[j] = pT_negpm[i];
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = yield_negpm[i];
  // 	  eyieldA[j] = eyield_negpm[i];
  // 	}
  //     if(i>14&&i<27)
  // 	{
  // 	  if(i%2!=1) continue;
  // 	  j=i/2+8;
  // 	  pTA[j] = (pT_negpm[i]+pT_negpm[i+1])/2.0;
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = (yield_negpm[i]+yield_negpm[i+1])/2.0;
  // 	  eyieldA[j] = sqrt(eyield_negpm[i]**2+eyield_negpm[i+1]**2)/2.0;
  // 	}
  //     if(i==27)
  // 	{
  // 	  j=21;
  // 	  pTA[j] = (pT_negpm[i]+pT_negpm[i+1]+pT_negpm[i+2]+pT_negpm[i+3])/4.0;
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = (yield_negpm[i]+yield_negpm[i+1]+yield_negpm[i+2]+yield_negpm[i+3])/4.0;
  // 	  eyieldA[j] = sqrt(eyield_negpm[i]**2+eyield_negpm[i+1]**2+eyield_negpm[i+2]**2+eyield_negpm[i+3]**2)/4.0;
  // 	}
  //     if(i>27)
  // 	{
  // 	  if(i%6!=1) continue;
  // 	  j=i/6+17;
  // 	  pTA[j] = (pT_negpm[i]+pT_negpm[i+1]+pT_negpm[i+2]+
  // 		    pT_negpm[i+3]+pT_negpm[i+4]+pT_negpm[i+5])/6.0;
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = (yield_negpm[i]+yield_negpm[i+1]+yield_negpm[i+2]+
  // 		       yield_negpm[i+3]+yield_negpm[i+4]+yield_negpm[i+5])/6.0;
  // 	  eyieldA[j] = sqrt(eyield_negpm[i]**2+eyield_negpm[i+1]**2+eyield_negpm[i+2]**2+
  // 			    eyield_negpm[i+3]**2+eyield_negpm[i+4]**2+eyield_negpm[i+5]**2)/6.0;
  // 	}

  //   } // end of for loop for rebinning

  // for(int i=0; i<23; i++)
  //   {
  //     pT[i] = pTA[i];
  //     epT[i] = 0;
  //     ratio[i] = -9;
  //     eratio[i] = 0;

  //     // this is where the typo was
  //     pTB[i] = pTneg_ppg026[i];
  //     epTB[i] = 0;
  //     yieldB[i] = yieldneg_ppg026[i];
  //     eyieldB[i] = eyieldneg_ppg026[i];

  //     // now do ratio
  //     if(yieldA[i]>0&&yieldB[i]>0)
  // 	{
  // 	  pT[i] = (pTA[i]+pTB[i])/2.0;
  // 	  epT[i] = 0;
  // 	  ratio[i] = yieldA[i]/yieldB[i];
  // 	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
  // 	}
  //     else
  // 	{
  // 	  pT[i] = pTA[i];
  // 	  epT[i] = 0;
  // 	  ratio[i] = -9;
  // 	  eratio[i] = 0;
  // 	}
  //   } // end of for loop to calculate ratio
  // TGraphErrors *tge_negpm = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  // tge_negpm->SetMarkerColor(kRed);
  // tge_negpm->SetMarkerStyle(21);

  // // ---

  // // ------------- //
  // // --- posmp --- //
  // // ------------- //

  // for(int i=0; i<36; i++)
  //   {
  //     // A
  //     j=i;
  //     pTA[i] = -9;
  //     epTA[i] = 0;
  //     yieldA[i] = -9;
  //     eyieldA[i] = 0;
  //     if(i<15)
  // 	{
  // 	  j=i;
  // 	  pTA[j] = pT_posmp[i];
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = yield_posmp[i];
  // 	  eyieldA[j] = eyield_posmp[i];
  // 	}
  //     if(i>14&&i<27)
  // 	{
  // 	  if(i%2!=1) continue;
  // 	  j=i/2+8;
  // 	  pTA[j] = (pT_posmp[i]+pT_posmp[i+1])/2.0;
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = (yield_posmp[i]+yield_posmp[i+1])/2.0;
  // 	  eyieldA[j] = sqrt(eyield_posmp[i]**2+eyield_posmp[i+1]**2)/2.0;
  // 	}
  //     if(i==27)
  // 	{
  // 	  j=21;
  // 	  pTA[j] = (pT_posmp[i]+pT_posmp[i+1]+pT_posmp[i+2]+pT_posmp[i+3])/4.0;
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = (yield_posmp[i]+yield_posmp[i+1]+yield_posmp[i+2]+yield_posmp[i+3])/4.0;
  // 	  eyieldA[j] = sqrt(eyield_posmp[i]**2+eyield_posmp[i+1]**2+eyield_posmp[i+2]**2+eyield_posmp[i+3]**2)/4.0;
  // 	}
  //     if(i>27)
  // 	{
  // 	  if(i%6!=1) continue;
  // 	  j=i/6+17;
  // 	  pTA[j] = (pT_posmp[i]+pT_posmp[i+1]+pT_posmp[i+2]+
  // 		    pT_posmp[i+3]+pT_posmp[i+4]+pT_posmp[i+5])/6.0;
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = (yield_posmp[i]+yield_posmp[i+1]+yield_posmp[i+2]+
  // 		       yield_posmp[i+3]+yield_posmp[i+4]+yield_posmp[i+5])/6.0;
  // 	  eyieldA[j] = sqrt(eyield_posmp[i]**2+eyield_posmp[i+1]**2+eyield_posmp[i+2]**2+
  // 			    eyield_posmp[i+3]**2+eyield_posmp[i+4]**2+eyield_posmp[i+5]**2)/6.0;
  // 	}

  //   } // end of for loop for rebinning

  // for(int i=0; i<23; i++)
  //   {
  //     pT[i] = pTA[i];
  //     epT[i] = 0;
  //     ratio[i] = -9;
  //     eratio[i] = 0;

  //     pTB[i] = pTpos_ppg026[i];
  //     epTB[i] = 0;
  //     yieldB[i] = yieldpos_ppg026[i];
  //     eyieldB[i] = eyieldpos_ppg026[i];

  //     // now do ratio
  //     if(yieldA[i]>0&&yieldB[i]>0)
  // 	{
  // 	  pT[i] = (pTA[i]+pTB[i])/2.0;
  // 	  epT[i] = 0;
  // 	  ratio[i] = yieldA[i]/yieldB[i];
  // 	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
  // 	}
  //     else
  // 	{
  // 	  pT[i] = pTA[i];
  // 	  epT[i] = 0;
  // 	  ratio[i] = -9;
  // 	  eratio[i] = 0;
  // 	}
  //   } // end of for loop to calculate ratio
  // TGraphErrors *tge_posmp = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  // tge_posmp->SetMarkerColor(kBlue);
  // tge_posmp->SetMarkerStyle(20);

  // // ---

  // // ------------- //
  // // --- negmp --- //
  // // ------------- //

  // for(int i=0; i<36; i++)
  //   {
  //     // A
  //     j=i;
  //     pTA[i] = -9;
  //     epTA[i] = 0;
  //     yieldA[i] = -9;
  //     eyieldA[i] = 0;
  //     if(i<15)
  // 	{
  // 	  j=i;
  // 	  pTA[j] = pT_negmp[i];
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = yield_negmp[i];
  // 	  eyieldA[j] = eyield_negmp[i];
  // 	}
  //     if(i>14&&i<27)
  // 	{
  // 	  if(i%2!=1) continue;
  // 	  j=i/2+8;
  // 	  pTA[j] = (pT_negmp[i]+pT_negmp[i+1])/2.0;
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = (yield_negmp[i]+yield_negmp[i+1])/2.0;
  // 	  eyieldA[j] = sqrt(eyield_negmp[i]**2+eyield_negmp[i+1]**2)/2.0;
  // 	}
  //     if(i==27)
  // 	{
  // 	  j=21;
  // 	  pTA[j] = (pT_negmp[i]+pT_negmp[i+1]+pT_negmp[i+2]+pT_negmp[i+3])/4.0;
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = (yield_negmp[i]+yield_negmp[i+1]+yield_negmp[i+2]+yield_negmp[i+3])/4.0;
  // 	  eyieldA[j] = sqrt(eyield_negmp[i]**2+eyield_negmp[i+1]**2+eyield_negmp[i+2]**2+eyield_negmp[i+3]**2)/4.0;
  // 	}
  //     if(i>27)
  // 	{
  // 	  if(i%6!=1) continue;
  // 	  j=i/6+17;
  // 	  pTA[j] = (pT_negmp[i]+pT_negmp[i+1]+pT_negmp[i+2]+
  // 		    pT_negmp[i+3]+pT_negmp[i+4]+pT_negmp[i+5])/6.0;
  // 	  epTA[j] = 0;
  // 	  yieldA[j] = (yield_negmp[i]+yield_negmp[i+1]+yield_negmp[i+2]+
  // 		       yield_negmp[i+3]+yield_negmp[i+4]+yield_negmp[i+5])/6.0;
  // 	  eyieldA[j] = sqrt(eyield_negmp[i]**2+eyield_negmp[i+1]**2+eyield_negmp[i+2]**2+
  // 			    eyield_negmp[i+3]**2+eyield_negmp[i+4]**2+eyield_negmp[i+5]**2)/6.0;
  // 	}

  //   } // end of for loop for rebinning

  // for(int i=0; i<23; i++)
  //   {
  //     pT[i] = pTA[i];
  //     epT[i] = 0;
  //     ratio[i] = -9;
  //     eratio[i] = 0;

  //     // this is where the typo was
  //     pTB[i] = pTneg_ppg026[i];
  //     epTB[i] = 0;
  //     yieldB[i] = yieldneg_ppg026[i];
  //     eyieldB[i] = eyieldneg_ppg026[i];

  //     // now do ratio
  //     if(yieldA[i]>0&&yieldB[i]>0)
  // 	{
  // 	  pT[i] = (pTA[i]+pTB[i])/2.0;
  // 	  epT[i] = 0;
  // 	  ratio[i] = yieldA[i]/yieldB[i];
  // 	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
  // 	}
  //     else
  // 	{
  // 	  pT[i] = pTA[i];
  // 	  epT[i] = 0;
  // 	  ratio[i] = -9;
  // 	  eratio[i] = 0;
  // 	}
  //   } // end of for loop to calculate ratio
  // TGraphErrors *tge_negmp = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  // tge_negmp->SetMarkerColor(kRed);
  // tge_negmp->SetMarkerStyle(21);

  // ----------------------------------- //
  // --- COME HERE FOR THE RUN7 PART --- //
  // ----------------------------------- //

  // --- 

  // ------------- //
  // --- pospm --- //
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
      pTA[j] = pT_pospm[i];
      epTA[j] = 0;
      yieldA[j] = yield_pospm[i];
      eyieldA[j] = eyield_pospm[i];
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
	  //cout<<"pt="<<pT[i]<<"\t"<<"run7="<<yieldA[i]<<"\t"<<"run2="<<yieldB[i]<<"\t"<<"ratio="<<ratio[i]<<endl;
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	}
    }
  TGraphErrors *tge_pospm = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  tge_pospm->SetMarkerColor(kBlue);
  tge_pospm->SetMarkerStyle(20);

  // ---

  // ------------- //
  // --- negpm --- //
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
      pTA[j] = pT_negpm[i];
      epTA[j] = 0;
      yieldA[j] = yield_negpm[i];
      eyieldA[j] = eyield_negpm[i];

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
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	}
    }
  TGraphErrors *tge_negpm = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  tge_negpm->SetMarkerColor(kRed);
  tge_negpm->SetMarkerStyle(21);

  // ---

  // ------------- //
  // --- posmp --- //
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
      pTA[j] = pT_posmp[i];
      epTA[j] = 0;
      yieldA[j] = yield_posmp[i];
      eyieldA[j] = eyield_posmp[i];

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
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	}
    }
  TGraphErrors *tge_posmp = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  tge_posmp->SetMarkerColor(kBlue);
  tge_posmp->SetMarkerStyle(20);

  // ---

  // ------------- //
  // --- negmp --- //
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
      pTA[j] = pT_negmp[i];
      epTA[j] = 0;
      yieldA[j] = yield_negmp[i];
      eyieldA[j] = eyield_negmp[i];

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
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	}
    }
  TGraphErrors *tge_negmp = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  tge_negmp->SetMarkerColor(kRed);
  tge_negmp->SetMarkerStyle(21);

  // ---










  // ---

  TMultiGraph *tmg_good = new TMultiGraph();
  tmg_good->Add(tge_pospm);
  tmg_good->Add(tge_negmp);
  tmg_good->Draw("ap");
  tmg_good->SetMaximum(2.0);
  tmg_good->SetMinimum(0.0);
  tmg_good->GetXaxis()->SetLimits(0.0,3.5);
  tmg_good->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_good->GetXaxis()->CenterTitle();
  tmg_good->GetYaxis()->SetTitle("Ratio");
  tmg_good->GetYaxis()->CenterTitle();

  TPaveText *pave_good = new TPaveText(0.51, 0.1, 1.49, 0.3, "br");
  pave_good->SetFillColor(10);
  pave_good->SetBorderSize(0);
  TText *text_good = pave_good->AddText(bigcentstring);
  pave_good->Draw();

  TPaveText *pave2_good = new TPaveText(0.25, 2.04, 2.75, 2.2, "br");
  pave2_good->SetFillColor(10);
  pave2_good->SetBorderSize(0);
  TText *text2_good = pave2_good->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  pave2_good->Draw();

  TLegend *leg_good = new TLegend(0.68,0.18,0.88,0.38);
  leg_good->SetFillColor(kWhite);
  leg_good->SetBorderSize(0);
  if(pid<=3)
    {
      leg_good->AddEntry(tge_pospm,"#pi^{+}, +- field","p");
      leg_good->AddEntry(tge_negmp,"#pi^{-}, -+ field","p");
    }
  if(pid==4||pid==5)
    {
      leg_good->AddEntry(tge_pospm,"K^{+}, +- field","p");
      leg_good->AddEntry(tge_negmp,"K^{-}, -+ field","p");
    }
  if(pid>=6)
    {
      leg_good->AddEntry(tge_pospm,"p, +- field","p");
      leg_good->AddEntry(tge_negmp,"#bar{p}, -+ field","p");
    }
  leg_good->Draw();

  char gifname_good[100];
  sprintf(gifname_good,"RatioFigures/published_%s_goodchfi_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_good[100];
  sprintf(epsname_good,"RatioFigures/published_%s_goodchfi_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  //c1->Print(gifname_good);
  //c1->Print(epsname_good);


  // ---

  TMultiGraph *tmg_bad = new TMultiGraph();
  tmg_bad->Add(tge_posmp);
  tmg_bad->Add(tge_negpm);
  tmg_bad->Draw("ap");
  tmg_bad->SetMaximum(2.0);
  tmg_bad->SetMinimum(0.0);
  tmg_bad->GetXaxis()->SetLimits(0.0,3.5);
  tmg_bad->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_bad->GetXaxis()->CenterTitle();
  tmg_bad->GetYaxis()->SetTitle("Ratio");
  tmg_bad->GetYaxis()->CenterTitle();

  TPaveText *pave_bad = new TPaveText(0.51, 0.1, 1.49, 0.3, "br");
  pave_bad->SetFillColor(10);
  pave_bad->SetBorderSize(0);
  TText *text_bad = pave_bad->AddText(bigcentstring);
  pave_bad->Draw();

  TPaveText *pave2_bad = new TPaveText(0.25, 2.04, 2.75, 2.2, "br");
  pave2_bad->SetFillColor(10);
  pave2_bad->SetBorderSize(0);
  TText *text2_bad = pave2_bad->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  pave2_bad->Draw();

  TLegend *leg_bad = new TLegend(0.68,0.18,0.88,0.38);
  leg_bad->SetFillColor(kWhite);
  leg_bad->SetBorderSize(0);
  if(pid<=3)
    {
      leg_bad->AddEntry(tge_posmp,"#pi^{+}, -+ field","p");
      leg_bad->AddEntry(tge_negpm,"#pi^{-}, +- field","p");
    }
  if(pid==4||pid==5)
    {
      leg_bad->AddEntry(tge_posmp,"K^{+}, -+ field","p");
      leg_bad->AddEntry(tge_negpm,"K^{-}, +- field","p");
    }
  if(pid>=6)
    {
      leg_bad->AddEntry(tge_posmp,"p, -+ field","p");
      leg_bad->AddEntry(tge_negpm,"#bar{p}, +- field","p");
    }
  leg_bad->Draw();

  char gifname_bad[100];
  sprintf(gifname_bad,"RatioFigures/published_%s_badchfi_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_bad[100];
  sprintf(epsname_bad,"RatioFigures/published_%s_badchfi_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  //c1->Print(gifname_bad);
  //c1->Print(epsname_bad);

  // ---
  // ---
  // ---

  // ---

  TMultiGraph *tmg_pm = new TMultiGraph();
  tmg_pm->Add(tge_pospm);
  tmg_pm->Add(tge_negpm);
  tmg_pm->Draw("ap");
  tmg_pm->SetMaximum(2.0);
  tmg_pm->SetMinimum(0.0);
  tmg_pm->GetXaxis()->SetLimits(0.0,3.5);
  tmg_pm->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_pm->GetXaxis()->CenterTitle();
  tmg_pm->GetYaxis()->SetTitle("Ratio");
  tmg_pm->GetYaxis()->CenterTitle();

  TPaveText *pave_pm = new TPaveText(0.51, 0.1, 1.49, 0.3, "br");
  pave_pm->SetFillColor(10);
  pave_pm->SetBorderSize(0);
  TText *text_pm = pave_pm->AddText(bigcentstring);
  pave_pm->Draw();

  TPaveText *pave2_pm = new TPaveText(0.25, 2.04, 2.75, 2.2, "br");
  pave2_pm->SetFillColor(10);
  pave2_pm->SetBorderSize(0);
  TText *text2_pm = pave2_pm->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  pave2_pm->Draw();

  TLegend *leg_pm = new TLegend(0.68,0.18,0.88,0.38);
  leg_pm->SetFillColor(kWhite);
  leg_pm->SetBorderSize(0);
  if(pid<=3)
    {
      leg_pm->AddEntry(tge_pospm,"#pi^{+}, +- field","p");
      leg_pm->AddEntry(tge_negpm,"#pi^{-}, +- field","p");
    }
  if(pid==4||pid==5)
    {
      leg_pm->AddEntry(tge_pospm,"K^{+}, +- field","p");
      leg_pm->AddEntry(tge_negpm,"K^{-}, +- field","p");
    }
  if(pid>=6)
    {
      leg_pm->AddEntry(tge_pospm,"p, +- field","p");
      leg_pm->AddEntry(tge_negpm,"#bar{p}, +- field","p");
    }
  leg_pm->Draw();

  char gifname_pm[100];
  sprintf(gifname_pm,"RatioFigures/published_%s_pm_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_pm[100];
  sprintf(epsname_pm,"RatioFigures/published_%s_pm_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  //c1->Print(gifname_pm);
  //c1->Print(epsname_pm);

  // ---

  TMultiGraph *tmg_mp = new TMultiGraph();
  tmg_mp->Add(tge_posmp);
  tmg_mp->Add(tge_negmp);
  tmg_mp->Draw("ap");
  tmg_mp->SetMaximum(2.0);
  tmg_mp->SetMinimum(0.0);
  tmg_mp->GetXaxis()->SetLimits(0.0,3.5);
  tmg_mp->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_mp->GetXaxis()->CenterTitle();
  tmg_mp->GetYaxis()->SetTitle("Ratio");
  tmg_mp->GetYaxis()->CenterTitle();

  TPaveText *pave_mp = new TPaveText(0.51, 0.1, 1.49, 0.3, "br");
  pave_mp->SetFillColor(10);
  pave_mp->SetBorderSize(0);
  TText *text_mp = pave_mp->AddText(bigcentstring);
  pave_mp->Draw();

  TPaveText *pave2_mp = new TPaveText(0.25, 2.04, 2.75, 2.2, "br");
  pave2_mp->SetFillColor(10);
  pave2_mp->SetBorderSize(0);
  TText *text2_mp = pave2_mp->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  pave2_mp->Draw();

  TLegend *leg_mp = new TLegend(0.68,0.18,0.88,0.38);
  leg_mp->SetFillColor(kWhite);
  leg_mp->SetBorderSize(0);
  if(pid<=3)
    {
      leg_mp->AddEntry(tge_posmp,"#pi^{+}, -+ field","p");
      leg_mp->AddEntry(tge_negmp,"#pi^{-}, -+ field","p");
    }
  if(pid==4||pid==5)
    {
      leg_mp->AddEntry(tge_posmp,"K^{+}, -+ field","p");
      leg_mp->AddEntry(tge_negmp,"K^{-}, -+ field","p");
    }
  if(pid>=6)
    {
      leg_mp->AddEntry(tge_posmp,"p, -+ field","p");
      leg_mp->AddEntry(tge_negmp,"#bar{p}, -+ field","p");
    }
  leg_mp->Draw();

  char gifname_mp[100];
  sprintf(gifname_mp,"RatioFigures/published_%s_mp_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_mp[100];
  sprintf(epsname_mp,"RatioFigures/published_%s_mp_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  //c1->Print(gifname_mp);
  //c1->Print(epsname_mp);



  // ---

  tge_pospm->SetMarkerColor(kBlue);
  tge_pospm->SetMarkerStyle(20);
  tge_posmp->SetMarkerColor(kRed);
  tge_posmp->SetMarkerStyle(21);
  TMultiGraph *tmg_pos = new TMultiGraph();
  tmg_pos->Add(tge_pospm);
  tmg_pos->Add(tge_posmp);
  tmg_pos->Draw("ap");
  tmg_pos->SetMaximum(2.0);
  tmg_pos->SetMinimum(0.0);
  tmg_pos->GetXaxis()->SetLimits(0.0,3.5);
  tmg_pos->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_pos->GetXaxis()->CenterTitle();
  tmg_pos->GetYaxis()->SetTitle("Ratio");
  tmg_pos->GetYaxis()->CenterTitle();

  TPaveText *pave_pos = new TPaveText(0.51, 0.1, 1.49, 0.3, "br");
  pave_pos->SetFillColor(10);
  pave_pos->SetBorderSize(0);
  TText *text_pos = pave_pos->AddText(bigcentstring);
  pave_pos->Draw();

  TPaveText *pave2_pos = new TPaveText(0.25, 2.04, 2.75, 2.2, "br");
  pave2_pos->SetFillColor(10);
  pave2_pos->SetBorderSize(0);
  TText *text2_pos = pave2_pos->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  pave2_pos->Draw();

  TLegend *leg_pos = new TLegend(0.68,0.18,0.88,0.38);
  leg_pos->SetFillColor(kWhite);
  leg_pos->SetBorderSize(0);
  if(pid<=3)
    {
      leg_pos->AddEntry(tge_pospm,"#pi^{+}, +- field","p");
      leg_pos->AddEntry(tge_posmp,"#pi^{+}, -+ field","p");
    }
  if(pid==4||pid==5)
    {
      leg_pos->AddEntry(tge_pospm,"K^{+}, +- field","p");
      leg_pos->AddEntry(tge_posmp,"K^{+}, -+ field","p");
    }
  if(pid>=6)
    {
      leg_pos->AddEntry(tge_pospm,"p, +- field","p");
      leg_pos->AddEntry(tge_posmp,"p, -+ field","p");
    }
  leg_pos->Draw();

  char gifname_pos[100];
  sprintf(gifname_pos,"RatioFigures/published_%s_pos_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_pos[100];
  sprintf(epsname_pos,"RatioFigures/published_%s_pos_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_pos);
  c1->Print(epsname_pos);


  tge_negpm->SetMarkerColor(kBlue);
  tge_negpm->SetMarkerStyle(20);
  tge_negmp->SetMarkerColor(kRed);
  tge_negmp->SetMarkerStyle(21);
  TMultiGraph *tmg_neg = new TMultiGraph();
  tmg_neg->Add(tge_negpm);
  tmg_neg->Add(tge_negmp);
  tmg_neg->Draw("ap");
  tmg_neg->SetMaximum(2.0);
  tmg_neg->SetMinimum(0.0);
  tmg_neg->GetXaxis()->SetLimits(0.0,3.5);
  tmg_neg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_neg->GetXaxis()->CenterTitle();
  tmg_neg->GetYaxis()->SetTitle("Ratio");
  tmg_neg->GetYaxis()->CenterTitle();

  TPaveText *pave_neg = new TPaveText(0.51, 0.1, 1.49, 0.3, "br");
  pave_neg->SetFillColor(10);
  pave_neg->SetBorderSize(0);
  TText *text_neg = pave_neg->AddText(bigcentstring);
  pave_neg->Draw();

  TPaveText *pave2_neg = new TPaveText(0.25, 2.04, 2.75, 2.2, "br");
  pave2_neg->SetFillColor(10);
  pave2_neg->SetBorderSize(0);
  TText *text2_neg = pave2_neg->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  pave2_neg->Draw();

  TLegend *leg_neg = new TLegend(0.68,0.18,0.88,0.38);
  leg_neg->SetFillColor(kWhite);
  leg_neg->SetBorderSize(0);
  if(pid<=3)
    {
      leg_neg->AddEntry(tge_negpm,"#pi^{-}, +- field","p");
      leg_neg->AddEntry(tge_negmp,"#pi^{-}, -+ field","p");
    }
  if(pid==4||pid==5)
    {
      leg_neg->AddEntry(tge_negpm,"K^{-}, +- field","p");
      leg_neg->AddEntry(tge_negmp,"K^{-}, -+ field","p");
    }
  if(pid>=6)
    {
      leg_neg->AddEntry(tge_negpm,"#bar{p}, +- field","p");
      leg_neg->AddEntry(tge_negmp,"#bar{p}, -+ field","p");
    }
  leg_neg->Draw();

  char gifname_neg[100];
  sprintf(gifname_neg,"RatioFigures/published_%s_neg_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_neg[100];
  sprintf(epsname_neg,"RatioFigures/published_%s_neg_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_neg);
  c1->Print(epsname_neg);














  // -------------------------- //
  // --- now doing pi0 part --- //
  // -------------------------- //

  c1->Clear();

  //if(pid>3) return; // need to restructure

  if(pid<=3)
    {

      // --- pospm ---//
      
      for(int i=0; i<12; i++)
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  
	  pTA[i] = pTR_pospm[i];
	  epTA[i] = 0;
	  yieldA[i] = yieldR_pospm[i];
	  eyieldA[i] = eyieldR_pospm[i];
	  
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
	    }
	  else
	    {
	      pT[i] = pTA[i];
	      epT[i] = 0;
	      ratio[i] = -9;
	      eratio[i] = 0;
	    }
	  
	  //cout<<pT_ppg080[i]<<"\t"<<yield_ppg080[i]<<endl;
	  //cout<<pTB[i]<<"\t"<<yieldB[i]<<"\t"<<pTA[i]<<"\t"<<yieldA[i]<<endl;
	  
	} // end of for loop to calculate ratio
      TGraphErrors *tge2_pospm = new TGraphErrors(12,pT,ratio,epT,eratio);
      tge2_pospm->SetMarkerColor(kBlue);
      tge2_pospm->SetMarkerStyle(20);
      
      // --- negpm --- //
      
      for(int i=0; i<12; i++)
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  
	  pTA[i] = pTR_negpm[i];
	  epTA[i] = 0;
	  yieldA[i] = yieldR_negpm[i];
	  eyieldA[i] = eyieldR_negpm[i];
	  
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
	    }
	} // end of for loop to calculate ratio
      TGraphErrors *tge2_negpm = new TGraphErrors(12,pT,ratio,epT,eratio);
      tge2_negpm->SetMarkerColor(kRed);
      tge2_negpm->SetMarkerStyle(21);
      
      // ---
      
      // --- posmp --- //
      
      for(int i=0; i<12; i++)
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  
	  pTA[i] = pTR_posmp[i];
	  epTA[i] = 0;
	  yieldA[i] = yieldR_posmp[i];
	  eyieldA[i] = eyieldR_posmp[i];
	  
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
	    }
	} // end of for loop to calculate ratio
      TGraphErrors *tge2_posmp = new TGraphErrors(12,pT,ratio,epT,eratio);
      tge2_posmp->SetMarkerColor(kBlue);
      tge2_posmp->SetMarkerStyle(20);
      
      // --- negmp --- //
      
      for(int i=0; i<12; i++)
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	  
	  pTA[i] = pTR_negmp[i];
	  epTA[i] = 0;
	  yieldA[i] = yieldR_negmp[i];
	  eyieldA[i] = eyieldR_negmp[i];
	  
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
	    }
	} // end of for loop to calculate ratio
      TGraphErrors *tge2_negmp = new TGraphErrors(12,pT,ratio,epT,eratio);
      tge2_negmp->SetMarkerColor(kRed);
      tge2_negmp->SetMarkerStyle(21);
      
      // ---
      
      
      
      
      
      // ---
      
      TMultiGraph *tmg_good_pi0 = new TMultiGraph();
      tmg_good_pi0->Add(tge2_pospm);
      tmg_good_pi0->Add(tge2_negmp);
      tmg_good_pi0->Draw("ap");
      tmg_good_pi0->SetMaximum(2.0);
      tmg_good_pi0->SetMinimum(0.0);
      tmg_good_pi0->GetXaxis()->SetLimits(0.0,6.0);
      tmg_good_pi0->GetXaxis()->SetTitle("p_{T} (GeV/c)");
      tmg_good_pi0->GetXaxis()->CenterTitle();
      tmg_good_pi0->GetYaxis()->SetTitle("Ratio");
      tmg_good_pi0->GetYaxis()->CenterTitle();
      
      TPaveText *pave_good_pi0 = new TPaveText(1.01, 0.1, 2.5, 0.3, "br");
      pave_good_pi0->SetFillColor(10);
      pave_good_pi0->SetBorderSize(0);
      TText *text_good_pi0 = pave_good_pi0->AddText(bigcentstring);
      pave_good_pi0->Draw();
      
      TPaveText *pave2_good_pi0 = new TPaveText(0.5, 2.04, 5.5, 2.2, "br");
      pave2_good_pi0->SetFillColor(10);
      pave2_good_pi0->SetBorderSize(0);
      TText *text2_good_pi0 = pave2_good_pi0->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
      pave2_good_pi0->Draw();
      
      TLegend *leg_good_pi0 = new TLegend(0.68,0.18,0.88,0.38);
      leg_good_pi0->SetFillColor(kWhite);
      leg_good_pi0->SetBorderSize(0);
      leg_good_pi0->AddEntry(tge2_pospm,"#pi^{+}, +- field","p");
      leg_good_pi0->AddEntry(tge2_negmp,"#pi^{-}, -+ field","p");
      leg_good_pi0->Draw();
      
      char gifname_good_pi0[100];
      sprintf(gifname_good_pi0,"RatioFigures/published_pi0_%s_goodchfi_%d_dis_cent%s.gif",sectorstring,pid,centstring);
      char epsname_good_pi0[100];
      sprintf(epsname_good_pi0,"RatioFigures/published_pi0_%s_goodchfi_%d_dis_cent%s.eps",sectorstring,pid,centstring);
      
      //c1->Print(gifname_good_pi0);
      //c1->Print(epsname_good_pi0);
      
      
      
      TMultiGraph *tmg_bad_pi0 = new TMultiGraph();
      tmg_bad_pi0->Add(tge2_posmp);
      tmg_bad_pi0->Add(tge2_negpm);
      tmg_bad_pi0->Draw("ap");
      tmg_bad_pi0->SetMaximum(2.0);
      tmg_bad_pi0->SetMinimum(0.0);
      tmg_bad_pi0->GetXaxis()->SetLimits(0.0,6.0);
      tmg_bad_pi0->GetXaxis()->SetTitle("p_{T} (GeV/c)");
      tmg_bad_pi0->GetXaxis()->CenterTitle();
      tmg_bad_pi0->GetYaxis()->SetTitle("Ratio");
      tmg_bad_pi0->GetYaxis()->CenterTitle();
      
      TPaveText *pave_bad_pi0 = new TPaveText(1.01, 0.1, 2.5, 0.3, "br");
      pave_bad_pi0->SetFillColor(10);
      pave_bad_pi0->SetBorderSize(0);
      TText *text_bad_pi0 = pave_bad_pi0->AddText(bigcentstring);
      pave_bad_pi0->Draw();
      
      TPaveText *pave2_bad_pi0 = new TPaveText(0.5, 2.04, 5.5, 2.2, "br");
      pave2_bad_pi0->SetFillColor(10);
      pave2_bad_pi0->SetBorderSize(0);
      TText *text2_bad_pi0 = pave2_bad_pi0->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
      pave2_bad_pi0->Draw();
      
      TLegend *leg_bad_pi0 = new TLegend(0.68,0.18,0.88,0.38);
      leg_bad_pi0->SetFillColor(kWhite);
      leg_bad_pi0->SetBorderSize(0);
      leg_bad_pi0->AddEntry(tge2_posmp,"#pi^{+}, -+ field","p");
      leg_bad_pi0->AddEntry(tge2_negpm,"#pi^{-}, +- field","p");
      leg_bad_pi0->Draw();
      
      char gifname_bad_pi0[100];
      sprintf(gifname_bad_pi0,"RatioFigures/published_pi0_%s_badchfi_%d_dis_cent%s.gif",sectorstring,pid,centstring);
      char epsname_bad_pi0[100];
      sprintf(epsname_bad_pi0,"RatioFigures/published_pi0_%s_badchfi_%d_dis_cent%s.eps",sectorstring,pid,centstring);
      
      //c1->Print(gifname_bad_pi0);
      //c1->Print(epsname_bad_pi0);
      
      
      
      // ---

      tge2_negpm->SetMarkerColor(kRed);
      tge2_negpm->SetMarkerStyle(21);
      TMultiGraph *tmg_pm_pi0 = new TMultiGraph();
      tmg_pm_pi0->Add(tge2_pospm);
      tmg_pm_pi0->Add(tge2_negpm);
      tmg_pm_pi0->Draw("ap");
      tmg_pm_pi0->SetMaximum(2.0);
      tmg_pm_pi0->SetMinimum(0.0);
      tmg_pm_pi0->GetXaxis()->SetLimits(0.0,6.0);
      tmg_pm_pi0->GetXaxis()->SetTitle("p_{T} (GeV/c)");
      tmg_pm_pi0->GetXaxis()->CenterTitle();
      tmg_pm_pi0->GetYaxis()->SetTitle("Ratio");
      tmg_pm_pi0->GetYaxis()->CenterTitle();
      
      TPaveText *pave_pm_pi0 = new TPaveText(1.01, 0.1, 2.5, 0.3, "br");
      pave_pm_pi0->SetFillColor(10);
      pave_pm_pi0->SetBorderSize(0);
      TText *text_pm_pi0 = pave_pm_pi0->AddText(bigcentstring);
      pave_pm_pi0->Draw();
      
      TPaveText *pave2_pm_pi0 = new TPaveText(0.5, 2.04, 5.5, 2.2, "br");
      pave2_pm_pi0->SetFillColor(10);
      pave2_pm_pi0->SetBorderSize(0);
      TText *text2_pm_pi0 = pave2_pm_pi0->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
      pave2_pm_pi0->Draw();
      
      TLegend *leg_pm_pi0 = new TLegend(0.68,0.18,0.88,0.38);
      leg_pm_pi0->SetFillColor(kWhite);
      leg_pm_pi0->SetBorderSize(0);
      leg_pm_pi0->AddEntry(tge2_pospm,"#pi^{+}, +- field","p");
      leg_pm_pi0->AddEntry(tge2_negmp,"#pi^{-}, +- field","p");
      leg_pm_pi0->Draw();
      
      char gifname_pm_pi0[100];
      sprintf(gifname_pm_pi0,"RatioFigures/published_pi0_%s_pm_%d_dis_cent%s.gif",sectorstring,pid,centstring);
      char epsname_pm_pi0[100];
      sprintf(epsname_pm_pi0,"RatioFigures/published_pi0_%s_pm_%d_dis_cent%s.eps",sectorstring,pid,centstring);
      
      //c1->Print(gifname_pm_pi0);
      //c1->Print(epsname_pm_pi0);
      
      
      
      tge2_negmp->SetMarkerColor(kRed);
      tge2_negmp->SetMarkerStyle(21);
      TMultiGraph *tmg_mp_pi0 = new TMultiGraph();
      tmg_mp_pi0->Add(tge2_posmp);
      tmg_mp_pi0->Add(tge2_negmp);
      tmg_mp_pi0->Draw("ap");
      tmg_mp_pi0->SetMaximum(2.0);
      tmg_mp_pi0->SetMinimum(0.0);
      tmg_mp_pi0->GetXaxis()->SetLimits(0.0,6.0);
      tmg_mp_pi0->GetXaxis()->SetTitle("p_{T} (GeV/c)");
      tmg_mp_pi0->GetXaxis()->CenterTitle();
      tmg_mp_pi0->GetYaxis()->SetTitle("Ratio");
      tmg_mp_pi0->GetYaxis()->CenterTitle();
      
      TPaveText *pave_mp_pi0 = new TPaveText(1.01, 0.1, 2.5, 0.3, "br");
      pave_mp_pi0->SetFillColor(10);
      pave_mp_pi0->SetBorderSize(0);
      TText *text_mp_pi0 = pave_mp_pi0->AddText(bigcentstring);
      pave_mp_pi0->Draw();
      
      TPaveText *pave2_mp_pi0 = new TPaveText(0.5, 2.04, 5.5, 2.2, "br");
      pave2_mp_pi0->SetFillColor(10);
      pave2_mp_pi0->SetBorderSize(0);
      TText *text2_mp_pi0 = pave2_mp_pi0->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
      pave2_mp_pi0->Draw();
      
      TLegend *leg_mp_pi0 = new TLegend(0.68,0.18,0.88,0.38);
      leg_mp_pi0->SetFillColor(kWhite);
      leg_mp_pi0->SetBorderSize(0);
      leg_mp_pi0->AddEntry(tge2_posmp,"#pi^{+}, -+ field","p");
      leg_mp_pi0->AddEntry(tge2_negmp,"#pi^{-}, -+ field","p");
      leg_mp_pi0->Draw();
      
      char gifname_mp_pi0[100];
      sprintf(gifname_mp_pi0,"RatioFigures/published_pi0_%s_mp_%d_dis_cent%s.gif",sectorstring,pid,centstring);
      char epsname_mp_pi0[100];
      sprintf(epsname_mp_pi0,"RatioFigures/published_pi0_%s_mp_%d_dis_cent%s.eps",sectorstring,pid,centstring);
      
      //c1->Print(gifname_mp_pi0);
      //c1->Print(epsname_mp_pi0);
      
      
      
      
      
      
      tge2_pospm->SetMarkerColor(kBlue);
      tge2_pospm->SetMarkerStyle(20);
      tge2_posmp->SetMarkerColor(kRed);
      tge2_posmp->SetMarkerStyle(21);
      TMultiGraph *tmg_pos_pi0 = new TMultiGraph();
      tmg_pos_pi0->Add(tge2_pospm);
      tmg_pos_pi0->Add(tge2_posmp);
      tmg_pos_pi0->Draw("ap");
      tmg_pos_pi0->SetMaximum(2.0);
      tmg_pos_pi0->SetMinimum(0.0);
      tmg_pos_pi0->GetXaxis()->SetLimits(0.0,6.0);
      tmg_pos_pi0->GetXaxis()->SetTitle("p_{T} (GeV/c)");
      tmg_pos_pi0->GetXaxis()->CenterTitle();
      tmg_pos_pi0->GetYaxis()->SetTitle("Ratio");
      tmg_pos_pi0->GetYaxis()->CenterTitle();
      
      TPaveText *pave_pos_pi0 = new TPaveText(1.01, 0.1, 2.5, 0.3, "br");
      pave_pos_pi0->SetFillColor(10);
      pave_pos_pi0->SetBorderSize(0);
      TText *text_pos_pi0 = pave_pos_pi0->AddText(bigcentstring);
      pave_pos_pi0->Draw();
      
      TPaveText *pave2_pos_pi0 = new TPaveText(0.5, 2.04, 5.5, 2.2, "br");
      pave2_pos_pi0->SetFillColor(10);
      pave2_pos_pi0->SetBorderSize(0);
      TText *text2_pos_pi0 = pave2_pos_pi0->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
      pave2_pos_pi0->Draw();
      
      TLegend *leg_pos_pi0 = new TLegend(0.68,0.18,0.88,0.38);
      leg_pos_pi0->SetFillColor(kWhite);
      leg_pos_pi0->SetBorderSize(0);
      leg_pos_pi0->AddEntry(tge2_pospm,"#pi^{+}, +- field","p");
      leg_pos_pi0->AddEntry(tge2_posmp,"#pi^{+}, -+ field","p");
      leg_pos_pi0->Draw();
      
      char gifname_pos_pi0[100];
      sprintf(gifname_pos_pi0,"RatioFigures/published_pi0_%s_pos_%d_dis_cent%s.gif",sectorstring,pid,centstring);
      char epsname_pos_pi0[100];
      sprintf(epsname_pos_pi0,"RatioFigures/published_pi0_%s_pos_%d_dis_cent%s.eps",sectorstring,pid,centstring);
      
      c1->Print(gifname_pos_pi0);
      c1->Print(epsname_pos_pi0);
      
      
      
      tge2_negpm->SetMarkerColor(kBlue);
      tge2_negpm->SetMarkerStyle(20);
      tge2_negmp->SetMarkerColor(kRed);
      tge2_negmp->SetMarkerStyle(21);
      TMultiGraph *tmg_neg_pi0 = new TMultiGraph();
      tmg_neg_pi0->Add(tge2_negpm);
      tmg_neg_pi0->Add(tge2_negmp);
      tmg_neg_pi0->Draw("ap");
      tmg_neg_pi0->SetMaximum(2.0);
      tmg_neg_pi0->SetMinimum(0.0);
      tmg_neg_pi0->GetXaxis()->SetLimits(0.0,6.0);
      tmg_neg_pi0->GetXaxis()->SetTitle("p_{T} (GeV/c)");
      tmg_neg_pi0->GetXaxis()->CenterTitle();
      tmg_neg_pi0->GetYaxis()->SetTitle("Ratio");
      tmg_neg_pi0->GetYaxis()->CenterTitle();
      
      TPaveText *pave_neg_pi0 = new TPaveText(1.01, 0.1, 2.5, 0.3, "br");
      pave_neg_pi0->SetFillColor(10);
      pave_neg_pi0->SetBorderSize(0);
      TText *text_neg_pi0 = pave_neg_pi0->AddText(bigcentstring);
      pave_neg_pi0->Draw();
      
      TPaveText *pave2_neg_pi0 = new TPaveText(0.5, 2.04, 5.5, 2.2, "br");
      pave2_neg_pi0->SetFillColor(10);
      pave2_neg_pi0->SetBorderSize(0);
      TText *text2_neg_pi0 = pave2_neg_pi0->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
      pave2_neg_pi0->Draw();
      
      TLegend *leg_neg_pi0 = new TLegend(0.68,0.18,0.88,0.38);
      leg_neg_pi0->SetFillColor(kWhite);
      leg_neg_pi0->SetBorderSize(0);
      leg_neg_pi0->AddEntry(tge2_negpm,"#pi^{-}, +- field","p");
      leg_neg_pi0->AddEntry(tge2_negmp,"#pi^{-}, -+ field","p");
      leg_neg_pi0->Draw();
      
      char gifname_neg_pi0[100];
      sprintf(gifname_neg_pi0,"RatioFigures/published_pi0_%s_neg_%d_dis_cent%s.gif",sectorstring,pid,centstring);
      char epsname_neg_pi0[100];
      sprintf(epsname_neg_pi0,"RatioFigures/published_pi0_%s_neg_%d_dis_cent%s.eps",sectorstring,pid,centstring);
      
      c1->Print(gifname_neg_pi0);
      c1->Print(epsname_neg_pi0);
      
    } // end of pid selector

  // ----------------------- //  
  // --- end of pi0 part --- //
  // ----------------------- //  
  
  


  
  
  



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

  TMultiGraph *tmgS_poscb = new TMultiGraph();
  tmgS_poscb->Add(tge_poscbSYS);
  tmgS_poscb->Add(tge_poscb);
  tmgS_poscb->Draw("apz");
  tmgS_poscb->SetMaximum(2.0);
  tmgS_poscb->SetMinimum(0.0);
  if(pid==4||pid==5) tmgS_poscb->GetXaxis()->SetLimits(0.0,3.0);
  if(pid>=6) tmgS_poscb->GetXaxis()->SetLimits(0.0,6.0);
  tmgS_poscb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgS_poscb->GetXaxis()->CenterTitle();
  tmgS_poscb->GetYaxis()->SetTitle("Ratio");
  tmgS_poscb->GetYaxis()->CenterTitle();

  char gifname_poscb[100];
  sprintf(gifname_poscb,"RatioFigures/single_published_%s_pos_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_poscb[100];
  sprintf(epsname_poscb,"RatioFigures/single_published_%s_pos_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  if(pid>=4)
    {
      c1->Print(gifname_poscb);
      c1->Print(epsname_poscb);
    }



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

  TMultiGraph *tmgS_negcb = new TMultiGraph();
  tmgS_negcb->Add(tge_negcbSYS);
  tmgS_negcb->Add(tge_negcb);
  tmgS_negcb->Draw("apz");
  tmgS_negcb->SetMaximum(2.0);
  tmgS_negcb->SetMinimum(0.0);
  if(pid==4||pid==5) tmgS_negcb->GetXaxis()->SetLimits(0.0,3.0);
  if(pid>=6) tmgS_negcb->GetXaxis()->SetLimits(0.0,6.0);
  tmgS_negcb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgS_negcb->GetXaxis()->CenterTitle();
  tmgS_negcb->GetYaxis()->SetTitle("Ratio");
  tmgS_negcb->GetYaxis()->CenterTitle();

  char gifname_negcb[100];
  sprintf(gifname_negcb,"RatioFigures/single_published_%s_neg_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_negcb[100];
  sprintf(epsname_negcb,"RatioFigures/single_published_%s_neg_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  if(pid>=4)
    {
      c1->Print(gifname_negcb);
      c1->Print(epsname_negcb);
    }



  // --- now for pi0 part --- //

  c1->Clear();

  if(pid<=3)
    {
      
      // --- poscb ---//
      
      for(int i=0; i<12; i++)
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
      TGraphErrors *tge2_poscb = new TGraphErrors(12,pT,ratio,epT,eratio);
      tge2_poscb->SetMarkerColor(kRed);
      tge2_poscb->SetMarkerStyle(21);
      TGraphErrors *tge2_poscbSYS = new TGraphErrors(12,pT,ratio,epT,esysratio);
      tge2_poscbSYS->SetMarkerColor(kRed);
      tge2_poscbSYS->SetMarkerStyle(1);
      tge2_poscbSYS->SetLineColor(kRed-10);
      tge2_poscbSYS->SetLineWidth(15);
      
      // --- negcb ---//
      
      for(int i=0; i<12; i++)
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
      TGraphErrors *tge2_negcb = new TGraphErrors(12,pT,ratio,epT,eratio);
      tge2_negcb->SetMarkerColor(kRed);
      tge2_negcb->SetMarkerStyle(21);
      TGraphErrors *tge2_negcbSYS = new TGraphErrors(12,pT,ratio,epT,esysratio);
      tge2_negcbSYS->SetMarkerColor(kRed);
      tge2_negcbSYS->SetMarkerStyle(1);
      tge2_negcbSYS->SetLineColor(kRed-10);
      tge2_negcbSYS->SetLineWidth(15);

      




      TMultiGraph *tmg_pos_cb = new TMultiGraph();
      tmg_pos_cb->Add(tge_poscbSYS);
      tmg_pos_cb->Add(tge2_poscbSYS);
      tmg_pos_cb->Add(tge_poscb);
      tmg_pos_cb->Add(tge2_poscb);
      tmg_pos_cb->Draw("apz");
      tmg_pos_cb->SetMaximum(2.0);
      tmg_pos_cb->SetMinimum(0.0);
      tmg_pos_cb->GetXaxis()->SetLimits(0.0,6.0);
      tmg_pos_cb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
      tmg_pos_cb->GetXaxis()->CenterTitle();
      tmg_pos_cb->GetYaxis()->SetTitle("Ratio");
      tmg_pos_cb->GetYaxis()->CenterTitle();
      
      TPaveText *pave_pos_cb = new TPaveText(1.01, 0.1, 2.5, 0.3, "br");
      pave_pos_cb->SetFillColor(10);
      pave_pos_cb->SetBorderSize(0);
      TText *text_pos_cb = pave_pos_cb->AddText(bigcentstring);
      pave_pos_cb->Draw();
      
      TPaveText *pave2_pos_cb = new TPaveText(0.5, 2.04, 5.5, 2.2, "br");
      pave2_pos_cb->SetFillColor(10);
      pave2_pos_cb->SetBorderSize(0);
      TText *text2_pos_cb = pave2_pos_cb->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
      pave2_pos_cb->Draw();
      
      TLegend *leg_pos_cb = new TLegend(0.68,0.18,0.88,0.38);
      leg_pos_cb->SetFillColor(kWhite);
      leg_pos_cb->SetBorderSize(0);
      leg_pos_cb->AddEntry(tge_poscb,"#pi^{+}, Run7/Run2","p");
      leg_pos_cb->AddEntry(tge2_poscb,"#pi^{+}, Run7/Run4","p");
      leg_pos_cb->Draw();
      
      char gifname_pos_cb[100];
      sprintf(gifname_pos_cb,"RatioFigures/single_published_%s_pos_%d_dis_cent%s.gif",sectorstring,pid,centstring);
      char epsname_pos_cb[100];
      sprintf(epsname_pos_cb,"RatioFigures/single_published_%s_pos_%d_dis_cent%s.eps",sectorstring,pid,centstring);
      
      c1->Print(gifname_pos_cb);
      c1->Print(epsname_pos_cb);



    

      TMultiGraph *tmg_neg_cb = new TMultiGraph();
      tmg_neg_cb->Add(tge_negcbSYS);
      tmg_neg_cb->Add(tge2_negcbSYS);
      tmg_neg_cb->Add(tge_negcb);
      tmg_neg_cb->Add(tge2_negcb);
      tmg_neg_cb->Draw("apz");
      tmg_neg_cb->SetMaximum(2.0);
      tmg_neg_cb->SetMinimum(0.0);
      tmg_neg_cb->GetXaxis()->SetLimits(0.0,6.0);
      tmg_neg_cb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
      tmg_neg_cb->GetXaxis()->CenterTitle();
      tmg_neg_cb->GetYaxis()->SetTitle("Ratio");
      tmg_neg_cb->GetYaxis()->CenterTitle();
      
      TPaveText *pave_neg_cb = new TPaveText(1.01, 0.1, 2.5, 0.3, "br");
      pave_neg_cb->SetFillColor(10);
      pave_neg_cb->SetBorderSize(0);
      TText *text_neg_cb = pave_neg_cb->AddText(bigcentstring);
      pave_neg_cb->Draw();
      
      TPaveText *pave2_neg_cb = new TPaveText(0.5, 2.04, 5.5, 2.2, "br");
      pave2_neg_cb->SetFillColor(10);
      pave2_neg_cb->SetBorderSize(0);
      TText *text2_neg_cb = pave2_neg_cb->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
      pave2_neg_cb->Draw();
      
      TLegend *leg_neg_cb = new TLegend(0.68,0.18,0.88,0.38);
      leg_neg_cb->SetFillColor(kWhite);
      leg_neg_cb->SetBorderSize(0);
      leg_neg_cb->AddEntry(tge_negcb,"#pi^{-}, Run7/Run2","p");
      leg_neg_cb->AddEntry(tge2_negcb,"#pi^{-}, Run7/Run4","p");
      leg_neg_cb->Draw();
      
      char gifname_neg_cb[100];
      sprintf(gifname_neg_cb,"RatioFigures/single_published_%s_neg_%d_dis_cent%s.gif",sectorstring,pid,centstring);
      char epsname_neg_cb[100];
      sprintf(epsname_neg_cb,"RatioFigures/single_published_%s_neg_%d_dis_cent%s.eps",sectorstring,pid,centstring);
      
      c1->Print(gifname_neg_cb);
      c1->Print(epsname_neg_cb);



    }
      
    
}
