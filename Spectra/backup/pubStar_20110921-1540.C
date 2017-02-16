void pubStar()
{

  cout<<"hello!  now drawing ratios!"<<endl;


  doit();
  
  //exit(0);

  for(int icent=0; icent<5; icent++)
    {
      for(int ipid=0; ipid<3; ipid++)
	{
	  doit(0,ipid,icent);
	}
    }
  
  
  cout<<"done!  have a nice day!"<<endl;

}

void doit(int sector=0, int partid=0, int centid=0)
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



  // --- strings for filenames

  char sectorstring[10];
  sprintf(sectorstring,"tofw"); // "default"
  if(sector==0) sprintf(sectorstring,"tofw");
  else {cerr<<"uh oh "<<endl; exit(0);}
  
  char centstring[10];
  sprintf(centstring,"0092"); // "default"
  if(centid==0) sprintf(centstring,"0010");
  if(centid==1) sprintf(centstring,"1020");
  if(centid==2) sprintf(centstring,"2040");
  if(centid==3) sprintf(centstring,"4060");
  if(centid==4) sprintf(centstring,"6080");
  //if(centid==4) sprintf(centstring,"6092");//this comparison doesn't work at all

  char starcentstring[10];
  sprintf(starcentstring,"MB"); // "default"
  if(centid==0) sprintf(starcentstring,"0010");
  if(centid==1) sprintf(starcentstring,"1020");
  if(centid==2) sprintf(starcentstring,"2040");
  if(centid==3) sprintf(starcentstring,"4060");
  if(centid==4) sprintf(starcentstring,"6080");

  char bigcentstring[50];
  sprintf(bigcentstring,"MinBias"); // "default"
  if(centid==0) sprintf(bigcentstring,"0-10%%");
  if(centid==1) sprintf(bigcentstring,"10-20%%");
  if(centid==2) sprintf(bigcentstring,"20-40%%");
  if(centid==3) sprintf(bigcentstring,"40-60%%");
  if(centid==4) sprintf(bigcentstring,"60-80%%");
  //if(centid==4) sprintf(bigcentstring,"60-92%%");


  // ---


  bool pion = false;
  bool kaon = false;
  bool proton = false;
  if(partid==0) pion = true;
  if(partid==1) kaon = true;
  if(partid==2) proton = true;



  int pid = 0; // careful, may need to change value or revise code
  int pid1 = 0;
  int pid2 = 0;
  int pid3 = 0;

  if(pion) pid = 0;
  if(kaon) pid = 4;
  if(proton) pid = 6;
  //if(pion) pid = 1;
  //if(kaon) pid = 5;
  //if(proton) pid = 7;




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



  // --- STAR stuff

  float pTpos_StarData[39], yieldpos_StarData[39], eyieldpos_StarData[39];
  float pTneg_StarData[39], yieldneg_StarData[39], eyieldneg_StarData[39];
  float EPT[39];

  int NumbeR = 1;
  char finposnameS[30];
  char finnegnameS[30];
  if(pid<=3)
    {
      NumbeR = 22;
      sprintf(finposnameS,"StarData/pp_starR_%s.dat",starcentstring);
      sprintf(finnegnameS,"StarData/pm_starR_%s.dat",starcentstring);
    }
  else if(pid==4||pid==5)
    {
      NumbeR = 10;//blah
      sprintf(finposnameS,"StarData/kp_starR_%s.dat",starcentstring);
      sprintf(finnegnameS,"StarData/km_starR_%s.dat",starcentstring);
    }
  else if(pid>=6)
    {
      NumbeR = 20;
      sprintf(finposnameS,"StarData/pr_starR_%s.dat",starcentstring);
      sprintf(finnegnameS,"StarData/pb_starR_%s.dat",starcentstring);
    }
  else
    {
      cerr<<"unknown pid number, now dying a quick but horribly painful death"<<endl;
      exit(1);
    }

  ifstream finposSTAR(finposnameS);
  ifstream finnegSTAR(finnegnameS);

  for(int i=0; i<NumbeR; i++)
    {
      EPT[i]=0;
      finposSTAR>>pTpos_StarData[i]>>yieldpos_StarData[i]>>eyieldpos_StarData[i];
      finnegSTAR>>pTneg_StarData[i]>>yieldneg_StarData[i]>>eyieldneg_StarData[i];

      if(!finposSTAR)
	{
	  pTpos_StarData[i]=-9;yieldpos_StarData[i]=-9;eyieldpos_StarData[i]=0;
	}
      if(!finnegSTAR)
	{
	  pTneg_StarData[i]=-9;yieldneg_StarData[i]=-9;eyieldneg_StarData[i]=0;
	}

    }
  finposSTAR.close();
  finnegSTAR.close();

  TGraphErrors *ppgposSTAR = new TGraphErrors(NumbeR,pTpos_StarData,yieldpos_StarData,EPT,eyieldpos_StarData);
  ppgposSTAR->SetMarkerColor(kBlue);
  ppgposSTAR->SetMarkerStyle(kFullStar);
  ppgposSTAR->SetMarkerSize(1.8);

  TGraphErrors *ppgnegSTAR = new TGraphErrors(NumbeR,pTneg_StarData,yieldneg_StarData,EPT,eyieldneg_StarData);
  ppgnegSTAR->SetMarkerColor(kBlue);
  ppgnegSTAR->SetMarkerStyle(kFullStar);
  ppgnegSTAR->SetMarkerSize(1.8);

  // ---



      char fnameinposcb[100];
      char fnameinnegcb[100];
      ifstream finposcb;
      ifstream finnegcb;
      float pT_poscb[100], yield_poscb[100], eyield_poscb[100];
      float pT_negcb[100], yield_negcb[100], eyield_negcb[100];
      char fnameinposcb1[100];
      char fnameinnegcb1[100];
      ifstream finposcb1;
      ifstream finnegcb1;
      float pT_poscb1[100], yield_poscb1[100], eyield_poscb1[100];
      float pT_negcb1[100], yield_negcb1[100], eyield_negcb1[100];
      char fnameinposcb2[100];
      char fnameinnegcb2[100];
      ifstream finposcb2;
      ifstream finnegcb2;
      float pT_poscb2[100], yield_poscb2[100], eyield_poscb2[100];
      float pT_negcb2[100], yield_negcb2[100], eyield_negcb2[100];
  // --- input data
  if(!proton)
    {
      sprintf(fnameinposcb,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
      sprintf(fnameinnegcb,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);
      finposcb.open(fnameinposcb);
      finnegcb.open(fnameinnegcb);
      for(int i=0; i<100; i++)
	{
	  // poscb
	  finposcb>>pT_poscb[i]>>yield_poscb[i]>>eyield_poscb[i];
	  // negcb
	  finnegcb>>pT_negcb[i]>>yield_negcb[i]>>eyield_negcb[i];
	  if(i<5)
	    {
	      yield_poscb[i] = -9;
	      yield_negcb[i] = -9;
	    }
	}
      finposcb.close();
      finnegcb.close();
    }
  else
    {
      sprintf(fnameinposcb1,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,6,centstring);
      sprintf(fnameinnegcb1,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,6,centstring);
      finposcb1.open(fnameinposcb1);
      finnegcb1.open(fnameinnegcb1);
      sprintf(fnameinposcb2,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,7,centstring);
      sprintf(fnameinnegcb2,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,7,centstring);
      finposcb2.open(fnameinposcb2);
      finnegcb2.open(fnameinnegcb2);
      for(int i=0; i<100; i++)
	{
	  // poscb1
	  finposcb1>>pT_poscb1[i]>>yield_poscb1[i]>>eyield_poscb1[i];
	  // negcb1
	  finnegcb1>>pT_negcb1[i]>>yield_negcb1[i]>>eyield_negcb1[i];
	  // poscb2
	  finposcb2>>pT_poscb2[i]>>yield_poscb2[i]>>eyield_poscb2[i];
	  // negcb2
	  finnegcb2>>pT_negcb2[i]>>yield_negcb2[i]>>eyield_negcb2[i];
	  if(i<40)
	    {
	      pT_poscb[i] = pT_poscb1[i];
	      yield_poscb[i] = yield_poscb1[i];
	      eyield_poscb[i] = eyield_poscb1[i];
	    }
	  if(i>39)
	    {
	      pT_poscb[i] = pT_poscb2[i];
	      yield_poscb[i] = yield_poscb2[i];
	      eyield_poscb[i] = eyield_poscb2[i];
	    }
	  if(i<5)
	    {
	      yield_poscb[i] = -9;
	      yield_negcb[i] = -9;
	    }
	}
      finposcb1.close();
      finnegcb1.close();
    }



  float pT_phstarpos[30], yield_phstarpos[30], eyield_phstarpos[30];
  float pT_phstarneg[30], yield_phstarneg[30], eyield_phstarneg[30];

  if(pion)
    {
      cout<<"PION!!!"<<endl;
      for(int i=0; i<22; i++)
	{
	  //pt
	  if(i<9) pT_phstarpos[i] = pT_poscb[i+3];
	  if(i>8&&i<14) pT_phstarpos[i] = (pT_poscb[i*2-6]+pT_poscb[i*2-5])/2.0;
	  if(i>13&&i<15) pT_phstarpos[i] = (pT_poscb[i*3-20]+pT_poscb[i*3-19]+pT_poscb[i*3-18])/3.0;
	  if(i>14) pT_phstarpos[i] = (pT_poscb[i*5-50]+
				      pT_poscb[i*5-49]+
				      pT_poscb[i*5-48]+
				      pT_poscb[i*5-47]+
				      pT_poscb[i*5-46])/5.0;
	  //yield
	  if(i<9) yield_phstarpos[i] = yield_poscb[i+3];
	  if(i>8&&i<14) yield_phstarpos[i] = (yield_poscb[i*2-6]+yield_poscb[i*2-5])/2.0;
	  if(i>13&&i<15) yield_phstarpos[i] = (yield_poscb[i*3-20]+yield_poscb[i*3-19]+yield_poscb[i*3-18])/3.0;
	  if(i>14) yield_phstarpos[i] = (yield_poscb[i*5-50]+
					 yield_poscb[i*5-49]+
					 yield_poscb[i*5-48]+
					 yield_poscb[i*5-47]+
					 yield_poscb[i*5-46])/5.0;
	  //eyield
	  if(i<9) eyield_phstarpos[i] = eyield_poscb[i+3];
	  if(i>8&&i<14) eyield_phstarpos[i] = (eyield_poscb[i*2-6]+eyield_poscb[i*2-5])/2.0;
	  if(i>13&&i<15) eyield_phstarpos[i] = (eyield_poscb[i*3-20]+eyield_poscb[i*3-19]+eyield_poscb[i*3-18])/3.0;
	  if(i>14) eyield_phstarpos[i] = sqrt(eyield_poscb[i*5-50]**2+
					      eyield_poscb[i*5-49]**2+
					      eyield_poscb[i*5-48]**2+
					      eyield_poscb[i*5-47]**2+
					      eyield_poscb[i*5-46]**2)/5.0;
	  //pt
	  if(i<9) pT_phstarneg[i] = pT_negcb[i+3];
	  if(i>8&&i<14) pT_phstarneg[i] = (pT_negcb[i*2-6]+pT_negcb[i*2-5])/2.0;
	  if(i>13&&i<15) pT_phstarneg[i] = (pT_negcb[i*3-20]+pT_negcb[i*3-19]+pT_negcb[i*3-18])/3.0;
	  if(i>14) pT_phstarneg[i] = (pT_negcb[i*5-50]+
				      pT_negcb[i*5-49]+
				      pT_negcb[i*5-48]+
				      pT_negcb[i*5-47]+
				      pT_negcb[i*5-46])/5.0;
	  //yield
	  if(i<9) yield_phstarneg[i] = yield_negcb[i+3];
	  if(i>8&&i<14) yield_phstarneg[i] = (yield_negcb[i*2-6]+yield_negcb[i*2-5])/2.0;
	  if(i>13&&i<15) yield_phstarneg[i] = (yield_negcb[i*3-20]+yield_negcb[i*3-19]+yield_negcb[i*3-18])/3.0;
	  if(i>14) yield_phstarneg[i] = (yield_negcb[i*5-50]+
					 yield_negcb[i*5-49]+
					 yield_negcb[i*5-48]+
					 yield_negcb[i*5-47]+
					 yield_negcb[i*5-46])/5.0;
	  //eyield
	  if(i<9) eyield_phstarneg[i] = eyield_negcb[i+3];
	  if(i>8&&i<14) eyield_phstarneg[i] = (eyield_negcb[i*2-5]+eyield_negcb[i*2-5])/2.0;
	  if(i>13&&i<15) eyield_phstarneg[i] = (eyield_negcb[i*3-20]+eyield_negcb[i*3-19]+eyield_negcb[i*3-18])/3.0;
	  if(i>14) eyield_phstarneg[i] = sqrt(eyield_negcb[i*5-50]**2+
					      eyield_negcb[i*5-49]**2+
					      eyield_negcb[i*5-48]**2+
					      eyield_negcb[i*5-47]**2+
					      eyield_negcb[i*5-46]**2)/5.0;
	}
      
    }      
  
  if(proton)
    {  
      cout<<"PROTON!!!"<<endl;
      for(int i=0; i<20; i++)
	{
	  //pt
	  if(i<7) pT_phstarpos[i] = pT_poscb[i+5];
	  if(i>6&&i<12) pT_phstarpos[i] = (pT_poscb[i*2-2]+pT_poscb[i*2-1])/2.0;
	  if(i>11&&i<13) pT_phstarpos[i] = (pT_poscb[i*3-14]+pT_poscb[i*3-13]+pT_poscb[i*3-12])/3.0;
	  if(i>12) pT_phstarpos[i] = (pT_poscb[i*5-40]+
				      pT_poscb[i*5-39]+
				      pT_poscb[i*5-38]+
				      pT_poscb[i*5-37]+
				      pT_poscb[i*5-36])/5.0;
	  //yield
	  if(i<7) yield_phstarpos[i] = yield_poscb[i+5];
	  if(i>6&&i<12) yield_phstarpos[i] = (yield_poscb[i*2-2]+yield_poscb[i*2-1])/2.0;
	  if(i>11&&i<13) yield_phstarpos[i] = (yield_poscb[i*3-14]+yield_poscb[i*3-13]+yield_poscb[i*3-12])/3.0;
	  if(i>12) yield_phstarpos[i] = (yield_poscb[i*5-40]+
					 yield_poscb[i*5-39]+
					 yield_poscb[i*5-38]+
					 yield_poscb[i*5-37]+
					 yield_poscb[i*5-36])/5.0;
	  //eyield
	  if(i<7) eyield_phstarpos[i] = eyield_poscb[i+5];
	  if(i>6&&i<12) eyield_phstarpos[i] = (eyield_poscb[i*2-2]+eyield_poscb[i*2-1])/2.0;
	  if(i>11&&i<13) eyield_phstarpos[i] = (eyield_poscb[i*3-14]+eyield_poscb[i*3-13]+eyield_poscb[i*3-12])/3.0;
	  if(i>12) eyield_phstarpos[i] = sqrt(eyield_poscb[i*5-40]**2+
					      eyield_poscb[i*5-39]**2+
					      eyield_poscb[i*5-38]**2+
					      eyield_poscb[i*5-37]**2+
					      eyield_poscb[i*5-36]**2)/5.0;
	  //pt
	  if(i<7) pT_phstarneg[i] = pT_negcb[i+5];
	  if(i>6&&i<12) pT_phstarneg[i] = (pT_negcb[i*2-2]+pT_negcb[i*2-1])/2.0;
	  if(i>11&&i<13) pT_phstarneg[i] = (pT_negcb[i*3-14]+pT_negcb[i*3-13]+pT_negcb[i*3-12])/3.0;
	  if(i>12) pT_phstarneg[i] = (pT_negcb[i*5-40]+
				      pT_negcb[i*5-39]+
				      pT_negcb[i*5-38]+
				      pT_negcb[i*5-37]+
				      pT_negcb[i*5-36])/5.0;
	  //yield
	  if(i<7) yield_phstarneg[i] = yield_negcb[i+5];
	  if(i>6&&i<12) yield_phstarneg[i] = (yield_negcb[i*2-2]+yield_negcb[i*2-1])/2.0;
	  if(i>11&&i<13) yield_phstarneg[i] = (yield_negcb[i*3-14]+yield_negcb[i*3-13]+yield_negcb[i*3-12])/3.0;
	  if(i>12) yield_phstarneg[i] = (yield_negcb[i*5-40]+
					 yield_negcb[i*5-39]+
					 yield_negcb[i*5-38]+
					 yield_negcb[i*5-37]+
					 yield_negcb[i*5-36])/5.0;
	  //eyield
	  if(i<7) eyield_phstarneg[i] = eyield_negcb[i+5];
	  if(i>6&&i<12) eyield_phstarneg[i] = (eyield_negcb[i*2-2]+eyield_negcb[i*2-1])/2.0;
	  if(i>11&&i<13) eyield_phstarneg[i] = (eyield_negcb[i*3-14]+eyield_negcb[i*3-13]+eyield_negcb[i*3-12])/3.0;
	  if(i>12) eyield_phstarneg[i] = sqrt(eyield_negcb[i*5-40]**2+
					      eyield_negcb[i*5-39]**2+
					      eyield_negcb[i*5-38]**2+
					      eyield_negcb[i*5-37]**2+
					      eyield_negcb[i*5-36]**2)/5.0;
	}
    }




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
    }

  finposcb.close();
  finnegcb.close();












  // --------------------------------------- //
  // --- COME HERE FOR THE COMBINED PART --- //
  // --------------------------------------- //

  float esysratio[45]; // NEW!
  float esysratiostar[45]; // NEW!

  float pT[45], epT[45], ratio[45], eratio[45];
  float pTA[45], epTA[45], yieldA[45], eyieldA[45];
  float pTB[45], epTB[45], yieldB[45], eyieldB[45];
  float pTstar[45], epTstar[45], ratiostar[45], eratiostar[45];
  float pTAstar[45], epTAstar[45], yieldAstar[45], eyieldAstar[45];
  float pTBstar[45], epTBstar[45], yieldBstar[45], eyieldBstar[45];

  int j;

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

  int NUMBER = 22;
  if(pion) NUMBER = 22;
  if(proton) NUMBER = 20;

  for(int i=0; i<NUMBER; i++)
    {
      // A
      j=i;
      pTAstar[i] = -9;
      epTAstar[i] = 0;
      yieldAstar[i] = -9;
      eyieldAstar[i] = 0;
      j=i;
      pTAstar[j] = pT_phstarpos[i];
      epTAstar[j] = 0;
      yieldAstar[j] = yield_phstarpos[i];
      eyieldAstar[j] = eyield_phstarpos[i];
      pTstar[i] = pTAstar[i];
      epTstar[i] = 0;
      ratiostar[i] = -9;
      eratiostar[i] = 0;

      pTBstar[i] = pTpos_StarData[i];
      epTBstar[i] = 0;
      yieldBstar[i] = yieldpos_StarData[i];
      eyieldBstar[i] = eyieldpos_StarData[i];

      // now do ratio
      if(yieldAstar[i]>0&&yieldBstar[i]>0)
	{
	  //pTstar[i] = (pTAstar[i]+pTBstar[i])/2.0;//THIS SHOULD WORK BUT DOESNT
	  pTstar[i] = pTAstar[i];
	  epTstar[i] = 0;
	  ratiostar[i] = yieldAstar[i]/yieldBstar[i];
	  eratiostar[i] = ratiostar[i]*sqrt((eyieldAstar[i]/yieldAstar[i])**2+(eyieldBstar[i]/yieldBstar[i])**2);
	  esysratiostar[i] = 0.1*ratiostar[i]; //NEW!  and temp, to be improved later
	  // cout
	  //   <<"run7 pt="<<pTAstar[i]<<"\t"
	  //   <<"star pt="<<pTAstar[i]<<"\t"
	  //   <<"pt="<<pTstar[i]<<"\t"
	  //   <<"run7="<<yieldAstar[i]<<"\t"
	  //   <<"star="<<yieldBstar[i]<<"\t"
	  //   <<"ratio="<<ratio[i]<<endl;
	}
      else
	{
	  pTstar[i] = pTAstar[i];
	  epTstar[i] = 0;
	  ratiostar[i] = -9;
	  eratiostar[i] = 0;
	  esysratiostar[i] = 0;
	}
      if(proton&&i>20)
	{
	  pTstar[i] = -9;
	  ratiostar[i] = -9;
	}
       // if(proton)
       // 	{
       // 	  cout
       // 	    <<"run7 pt="<<pTAstar[i]<<"\t"
       // 	    <<"star pt="<<pTAstar[i]<<"\t"
       // 	    <<"pt="<<pTstar[i]<<"\t"
       // 	    <<"run7="<<yieldAstar[i]<<"\t"
       // 	    <<"star="<<yieldBstar[i]<<"\t"
       // 	    <<"ratio="<<ratiostar[i]<<endl;
       // 	}
    }


  TGraphErrors *tge_poscb = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  TGraphErrors *tge_poscbSYS = new TGraphErrors(number+offset,pT,ratio,epT,esysratio);
  tge_poscbSYS->SetMarkerStyle(1);
  tge_poscbSYS->SetMarkerColor(kGray);
  tge_poscbSYS->SetLineWidth(15);
  tge_poscbSYS->SetLineColor(kGray);
  tge_poscb->SetMarkerColor(kBlack);
  tge_poscb->SetMarkerStyle(20);

  TGraphErrors *tge_starposcb = new TGraphErrors(NUMBER,pTstar,ratiostar,epTstar,eratiostar);
  TGraphErrors *tge_starposcbSYS = new TGraphErrors(NUMBER,pTstar,ratiostar,epTstar,esysratiostar);
  tge_starposcbSYS->SetMarkerStyle(1);
  tge_starposcbSYS->SetMarkerColor(kBlue-10);
  tge_starposcbSYS->SetLineWidth(15);
  tge_starposcbSYS->SetLineColor(kBlue-10);
  tge_starposcb->SetMarkerColor(kBlue);
  tge_starposcb->SetMarkerStyle(kFullStar);
  tge_starposcb->SetMarkerSize(1.8);

  TMultiGraph *tmgS_poscb = new TMultiGraph();
  tmgS_poscb->Add(tge_poscbSYS);
  tmgS_poscb->Add(tge_poscb);
  tmgS_poscb->Add(tge_starposcbSYS);
  tmgS_poscb->Add(tge_starposcb);
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
  sprintf(gifname_poscb,"RatioFigures/STAR_single_published_%s_pos_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_poscb[100];
  sprintf(epsname_poscb,"RatioFigures/STAR_single_published_%s_pos_%d_dis_cent%s.eps",sectorstring,pid,centstring);

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

  for(int i=0; i<NUMBER; i++)
    {
      // A
      j=i;
      pTAstar[i] = -9;
      epTAstar[i] = 0;
      yieldAstar[i] = -9;
      eyieldAstar[i] = 0;
      j=i;
      pTAstar[j] = pT_phstarneg[i];
      epTAstar[j] = 0;
      yieldAstar[j] = yield_phstarneg[i];
      eyieldAstar[j] = eyield_phstarneg[i];
      pTstar[i] = pTAstar[i];
      epTstar[i] = 0;
      ratiostar[i] = -9;
      eratiostar[i] = 0;

      pTBstar[i] = pTneg_StarData[i];
      epTBstar[i] = 0;
      yieldBstar[i] = yieldneg_StarData[i];
      eyieldBstar[i] = eyieldneg_StarData[i];

      // now do ratio
      if(yieldAstar[i]>0&&yieldBstar[i]>0)
	{
	  //pTstar[i] = (pTAstar[i]+pTBstar[i])/2.0;//THIS SHOULD WORK BUT DOESNT
	  pTstar[i] = pTAstar[i];
	  epTstar[i] = 0;
	  ratiostar[i] = yieldAstar[i]/yieldBstar[i];
	  eratiostar[i] = ratiostar[i]*sqrt((eyieldAstar[i]/yieldAstar[i])**2+(eyieldBstar[i]/yieldBstar[i])**2);
	  esysratiostar[i] = 0.1*ratiostar[i]; //NEW!  and temp, to be improved later
	  // cout
	  //   <<"run7 pt="<<pTAstar[i]<<"\t"
	  //   <<"star pt="<<pTAstar[i]<<"\t"
	  //   <<"pt="<<pTstar[i]<<"\t"
	  //   <<"run7="<<yieldAstar[i]<<"\t"
	  //   <<"star="<<yieldBstar[i]<<"\t"
	  //   <<"ratio="<<ratio[i]<<endl;
	}
      else
	{
	  pTstar[i] = pTAstar[i];
	  epTstar[i] = 0;
	  ratiostar[i] = -9;
	  eratiostar[i] = 0;
	  esysratiostar[i] = 0;
	}
      if(proton&&i>20)
	{
	  pTstar[i] = -9;
	  ratiostar[i] = -9;
	}
       // if(proton)
       // 	{
       // 	  cout
       // 	    <<"run7 pt="<<pTAstar[i]<<"\t"
       // 	    <<"star pt="<<pTAstar[i]<<"\t"
       // 	    <<"pt="<<pTstar[i]<<"\t"
       // 	    <<"run7="<<yieldAstar[i]<<"\t"
       // 	    <<"star="<<yieldBstar[i]<<"\t"
       // 	    <<"ratio="<<ratiostar[i]<<endl;
       // 	}
    }


  TGraphErrors *tge_starnegcb = new TGraphErrors(NUMBER,pTstar,ratiostar,epTstar,eratiostar);
  TGraphErrors *tge_starnegcbSYS = new TGraphErrors(NUMBER,pTstar,ratiostar,epTstar,esysratiostar);
  tge_starnegcbSYS->SetMarkerStyle(1);
  tge_starnegcbSYS->SetMarkerColor(kBlue-10);
  tge_starnegcbSYS->SetLineWidth(15);
  tge_starnegcbSYS->SetLineColor(kBlue-10);
  tge_starnegcb->SetMarkerColor(kBlue);
  tge_starnegcb->SetMarkerStyle(kFullStar);
  tge_starnegcb->SetMarkerSize(1.8);

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
  tmgS_negcb->Add(tge_starnegcbSYS);
  tmgS_negcb->Add(tge_negcb);
  tmgS_negcb->Add(tge_starnegcb);
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
  sprintf(gifname_negcb,"RatioFigures/STAR_single_published_%s_neg_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_negcb[100];
  sprintf(epsname_negcb,"RatioFigures/STAR_single_published_%s_neg_%d_dis_cent%s.eps",sectorstring,pid,centstring);

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
      tmg_pos_cb->Add(tge_starposcbSYS);
      tmg_pos_cb->Add(tge_poscb);
      tmg_pos_cb->Add(tge2_poscb);
      tmg_pos_cb->Add(tge_starposcb);
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
      leg_pos_cb->AddEntry(tge_starposcb,"#pi^{+}, Run7/STAR","p");
      leg_pos_cb->Draw();
      
      char gifname_pos_cb[100];
      sprintf(gifname_pos_cb,"RatioFigures/STAR_single_published_%s_pos_%d_dis_cent%s.gif",sectorstring,pid,centstring);
      char epsname_pos_cb[100];
      sprintf(epsname_pos_cb,"RatioFigures/STAR_single_published_%s_pos_%d_dis_cent%s.eps",sectorstring,pid,centstring);
      
      c1->Print(gifname_pos_cb);
      c1->Print(epsname_pos_cb);



    

      TMultiGraph *tmg_neg_cb = new TMultiGraph();
      tmg_neg_cb->Add(tge_negcbSYS);
      tmg_neg_cb->Add(tge2_negcbSYS);
      tmg_neg_cb->Add(tge_starnegcbSYS);
      tmg_neg_cb->Add(tge_negcb);
      tmg_neg_cb->Add(tge2_negcb);
      tmg_neg_cb->Add(tge_starnegcb);
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
      leg_neg_cb->AddEntry(tge_starnegcb,"#pi^{-}, Run7/STAR","p");
      leg_neg_cb->Draw();
      
      char gifname_neg_cb[100];
      sprintf(gifname_neg_cb,"RatioFigures/STAR_single_published_%s_neg_%d_dis_cent%s.gif",sectorstring,pid,centstring);
      char epsname_neg_cb[100];
      sprintf(epsname_neg_cb,"RatioFigures/STAR_single_published_%s_neg_%d_dis_cent%s.eps",sectorstring,pid,centstring);
      
      c1->Print(gifname_neg_cb);
      c1->Print(epsname_neg_cb);



    }
      
    
}
