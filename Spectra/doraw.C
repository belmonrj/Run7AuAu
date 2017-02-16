void doraw()
{

  cout<<"raw ensemble!"<<endl;

  for(int icent=0; icent<9; icent++)
    {
      for(int ipid=0; ipid<10; ipid++)
	{
	  doitR(0,ipid,icent);
	  for(int isec=0; isec<3; isec++)
	    {
	      //doit(isec,ipid,icent);
	      //cout<<"doit("<<isec<<","<<ipid<<","<<icent<<");"<<endl;
	    }
	}
    }

  //rebinning
  for(int ipid=0; ipid<10; ipid++)
    {
      doitM(ipid,0);
      doitM(ipid,1);
      doitM(ipid,2);
      doitP(ipid);
    }


  cout<<"all done!  i hope you have a great day!"<<endl;

}

void doitR(int sector=0, int pid=0, int centid=0)
{

  // TCanvas used for printing diagnostic figures
  TCanvas *c1 = new TCanvas();
  c1->SetFillColor(kWhite);
  c1->SetFrameFillColor(kWhite);
  c1->SetBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->SetLogy();



  TFile *f_real_L_pm = TFile::Open("RealFiles/outlowpm.root");
  TFile *f_real_H_pm = TFile::Open("RealFiles/outhighpm.root");

  TFile *f_real_L_mp = TFile::Open("RealFiles/outlowmp.root");
  TFile *f_real_H_mp = TFile::Open("RealFiles/outhighmp.root");

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

  char bigcentstring[50];
  sprintf(bigcentstring,"MinBias"); // "default"
  if(centid==0) sprintf(bigcentstring,"0-10%% cent");
  if(centid==1) sprintf(bigcentstring,"10-20%% cent");
  if(centid==2) sprintf(bigcentstring,"20-30%% cent");
  if(centid==3) sprintf(bigcentstring,"30-40%% cent");
  if(centid==4) sprintf(bigcentstring,"40-50%% cent");
  if(centid==5) sprintf(bigcentstring,"50-60%% cent");
  if(centid==6) sprintf(bigcentstring,"60-70%% cent");
  if(centid==7) sprintf(bigcentstring,"70-80%% cent");
  if(centid==8) sprintf(bigcentstring,"80-92%% cent");


  char name_real_tofw_pos_pm[50];
  char name_sim_tofw_pos_pm[50];
  char name_real_tofw_neg_pm[50];
  char name_sim_tofw_neg_pm[50];

  char name_real_tofw_pos_mp[50];
  char name_sim_tofw_pos_mp[50];
  char name_real_tofw_neg_mp[50];
  char name_sim_tofw_neg_mp[50];

  sprintf(name_real_tofw_pos_pm,"ptpid_%s_pos_%d_dis_cent_%d",sectorstring,pid,centid);
  sprintf(name_sim_tofw_pos_pm,"ptpid_%s_pos_%d_dis",sectorstring,pid);
  sprintf(name_real_tofw_neg_pm,"ptpid_%s_neg_%d_dis_cent_%d",sectorstring,pid,centid);
  sprintf(name_sim_tofw_neg_pm,"ptpid_%s_neg_%d_dis",sectorstring,pid);

  sprintf(name_real_tofw_pos_mp,"ptpid_%s_pos_%d_dis_cent_%d",sectorstring,pid,centid);
  sprintf(name_sim_tofw_pos_mp,"ptpid_%s_pos_%d_dis",sectorstring,pid);
  sprintf(name_real_tofw_neg_mp,"ptpid_%s_neg_%d_dis_cent_%d",sectorstring,pid,centid);
  sprintf(name_sim_tofw_neg_mp,"ptpid_%s_neg_%d_dis",sectorstring,pid);

  TH1F *h_real_L_tofw_pos_pm = f_real_L_pm->Get(name_real_tofw_pos_pm);
  TH1F *h_real_L_tofw_neg_pm = f_real_L_pm->Get(name_real_tofw_neg_pm);
  TH1F *h_real_L_tofw_pos_mp = f_real_L_mp->Get(name_real_tofw_pos_mp);
  TH1F *h_real_L_tofw_neg_mp = f_real_L_mp->Get(name_real_tofw_neg_mp);

  TH1F *h_real_H_tofw_pos_pm = f_real_H_pm->Get(name_real_tofw_pos_pm);
  TH1F *h_real_H_tofw_neg_pm = f_real_H_pm->Get(name_real_tofw_neg_pm);
  TH1F *h_real_H_tofw_pos_mp = f_real_H_mp->Get(name_real_tofw_pos_mp);
  TH1F *h_real_H_tofw_neg_mp = f_real_H_mp->Get(name_real_tofw_neg_mp);


  h_real_L_tofw_pos_pm->Sumw2();
  h_real_L_tofw_neg_pm->Sumw2();
  h_real_L_tofw_pos_mp->Sumw2();
  h_real_L_tofw_neg_mp->Sumw2();

  h_real_H_tofw_pos_pm->Sumw2();
  h_real_H_tofw_neg_pm->Sumw2();
  h_real_H_tofw_pos_mp->Sumw2();
  h_real_H_tofw_neg_mp->Sumw2();


  char fnameoutpospm[100];
  char fnameoutnegpm[100];
  char fnameoutposmp[100];
  char fnameoutnegmp[100];

  sprintf(fnameoutpospm,"RawData/ptpid_%s_pos_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegpm,"RawData/ptpid_%s_neg_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameoutposmp,"RawData/ptpid_%s_pos_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegmp,"RawData/ptpid_%s_neg_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);

  ofstream foutpospm;
  ofstream foutnegpm;
  ofstream foutposmp;
  ofstream foutnegmp;

  foutpospm.open(fnameoutpospm);
  foutnegpm.open(fnameoutnegpm);
  foutposmp.open(fnameoutposmp);
  foutnegmp.open(fnameoutnegmp);

  for(int i=0; i<100; i++)
    {
      float pT, yield, eyield;
      if(i<30)
	{
	  // pospm
	  pT = h_real_L_tofw_pos_pm->GetBinCenter(i+1);
	  yield = h_real_L_tofw_pos_pm->GetBinContent(i+1);
	  eyield = h_real_L_tofw_pos_pm->GetBinError(i+1);
	  foutpospm<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	  // negpm
	  pT = h_real_L_tofw_neg_pm->GetBinCenter(i+1);
	  yield = h_real_L_tofw_neg_pm->GetBinContent(i+1);
	  eyield = h_real_L_tofw_neg_pm->GetBinError(i+1);
	  foutnegpm<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	  // posmp
	  pT = h_real_L_tofw_pos_mp->GetBinCenter(i+1);
	  yield = h_real_L_tofw_pos_mp->GetBinContent(i+1);
	  eyield = h_real_L_tofw_pos_mp->GetBinError(i+1);
	  foutposmp<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	  // negmp
	  pT = h_real_L_tofw_neg_mp->GetBinCenter(i+1);
	  yield = h_real_L_tofw_neg_mp->GetBinContent(i+1);
	  eyield = h_real_L_tofw_neg_mp->GetBinError(i+1);
	  foutnegmp<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	}
      if(i>=30)
	{
	  // pospm
	  pT = h_real_H_tofw_pos_pm->GetBinCenter(i+1);
	  yield = h_real_H_tofw_pos_pm->GetBinContent(i+1);
	  eyield = h_real_H_tofw_pos_pm->GetBinError(i+1);
	  foutpospm<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	  // negpm
	  pT = h_real_H_tofw_neg_pm->GetBinCenter(i+1);
	  yield = h_real_H_tofw_neg_pm->GetBinContent(i+1);
	  eyield = h_real_H_tofw_neg_pm->GetBinError(i+1);
	  foutnegpm<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	  // posmp
	  pT = h_real_H_tofw_pos_mp->GetBinCenter(i+1);
	  yield = h_real_H_tofw_pos_mp->GetBinContent(i+1);
	  eyield = h_real_H_tofw_pos_mp->GetBinError(i+1);
	  foutposmp<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	  // negmp
	  pT = h_real_H_tofw_neg_mp->GetBinCenter(i+1);
	  yield = h_real_H_tofw_neg_mp->GetBinContent(i+1);
	  eyield = h_real_H_tofw_neg_mp->GetBinError(i+1);
	  foutnegmp<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	}
    }

  foutpospm.close();
  foutnegpm.close();
  foutposmp.close();
  foutnegmp.close();



  // -------------------------- //
  // --- now combine fields --- //
  // -------------------------- //

  char fnameoutposcb[100];
  char fnameoutnegcb[100];

  sprintf(fnameoutposcb,"RawData/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegcb,"RawData/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

  ofstream foutposcb;
  ofstream foutnegcb;

  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);

  for(int i=0; i<100; i++)
    {
      float pT, yield, eyield;
      float pT_A, yield_A, eyield_A;
      float pT_B, yield_B, eyield_B;

      if(i<30)
	{
	  // pospm
	  pT_A = h_real_L_tofw_pos_pm->GetBinCenter(i+1);
	  yield_A = h_real_L_tofw_pos_pm->GetBinContent(i+1);
	  eyield_A = h_real_L_tofw_pos_pm->GetBinError(i+1);
	  // posmp
	  pT_B = h_real_L_tofw_pos_mp->GetBinCenter(i+1);
	  yield_B = h_real_L_tofw_pos_mp->GetBinContent(i+1);
	  eyield_B = h_real_L_tofw_pos_mp->GetBinError(i+1);
	}
      if(i>=30)
	{
	  // pospm
	  pT_A = h_real_H_tofw_pos_pm->GetBinCenter(i+1);
	  yield_A = h_real_H_tofw_pos_pm->GetBinContent(i+1);
	  eyield_A = h_real_H_tofw_pos_pm->GetBinError(i+1);
	  // posmp
	  pT_B = h_real_H_tofw_pos_mp->GetBinCenter(i+1);
	  yield_B = h_real_H_tofw_pos_mp->GetBinContent(i+1);
	  eyield_B = h_real_H_tofw_pos_mp->GetBinError(i+1);
	}

      pT = (pT_A+pT_B)/2.0;
      yield = (yield_A+yield_B)/2.0;
      eyield = sqrt(eyield_A**2+eyield_B**2)/2.0;
      foutposcb<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;

      if(i<30)
	{
	  // negpm
	  pT_A = h_real_L_tofw_neg_pm->GetBinCenter(i+1);
	  yield_A = h_real_L_tofw_neg_pm->GetBinContent(i+1);
	  eyield_A = h_real_L_tofw_neg_pm->GetBinError(i+1);
	  // negmp
	  pT_B = h_real_L_tofw_neg_mp->GetBinCenter(i+1);
	  yield_B = h_real_L_tofw_neg_mp->GetBinContent(i+1);
	  eyield_B = h_real_L_tofw_neg_mp->GetBinError(i+1);
	}
      if(i>=30)
	{
	  // negpm
	  pT_A = h_real_H_tofw_neg_pm->GetBinCenter(i+1);
	  yield_A = h_real_H_tofw_neg_pm->GetBinContent(i+1);
	  eyield_A = h_real_H_tofw_neg_pm->GetBinError(i+1);
	  // negmp
	  pT_B = h_real_H_tofw_neg_mp->GetBinCenter(i+1);
	  yield_B = h_real_H_tofw_neg_mp->GetBinContent(i+1);
	  eyield_B = h_real_H_tofw_neg_mp->GetBinError(i+1);
	}

      pT = (pT_A+pT_B)/2.0;
      yield = (yield_A+yield_B)/2.0;
      eyield = sqrt(eyield_A**2+eyield_B**2)/2.0;
      foutnegcb<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
    }

  foutposcb.close();
  foutnegcb.close();

  // ---
  // ---
  // ---

  // ------------------ //
  // --- rebin by 5 --- //
  // ------------------ //

  TF1 *dummy = new TF1("dummy","pol0",0,10);
  dummy->SetParameter(0,1.0);

  h_real_L_tofw_pos_pm->Rebin(5);
  h_real_L_tofw_neg_pm->Rebin(5);
  h_real_L_tofw_pos_mp->Rebin(5);
  h_real_L_tofw_neg_mp->Rebin(5);

  h_real_L_tofw_pos_pm->Divide(dummy,5.0);
  h_real_L_tofw_neg_pm->Divide(dummy,5.0);
  h_real_L_tofw_pos_mp->Divide(dummy,5.0);
  h_real_L_tofw_neg_mp->Divide(dummy,5.0);

  h_real_H_tofw_pos_pm->Rebin(5);
  h_real_H_tofw_neg_pm->Rebin(5);
  h_real_H_tofw_pos_mp->Rebin(5);
  h_real_H_tofw_neg_mp->Rebin(5);

  h_real_H_tofw_pos_pm->Divide(dummy,5.0);
  h_real_H_tofw_neg_pm->Divide(dummy,5.0);
  h_real_H_tofw_pos_mp->Divide(dummy,5.0);
  h_real_H_tofw_neg_mp->Divide(dummy,5.0);

  // ------------------ //
  // ------------------ //
  // ------------------ //


  sprintf(fnameoutpospm,"RawData/R5_ptpid_%s_pos_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegpm,"RawData/R5_ptpid_%s_neg_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameoutposmp,"RawData/R5_ptpid_%s_pos_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegmp,"RawData/R5_ptpid_%s_neg_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);

  foutpospm.open(fnameoutpospm);
  foutnegpm.open(fnameoutnegpm);
  foutposmp.open(fnameoutposmp);
  foutnegmp.open(fnameoutnegmp);

  //for(int i=0; i<100; i++)
  for(int i=0; i<20; i++) // reduce by 5 :)
    {
      float pT, yield, eyield;
      //if(i<30)
      if(i<6)
	{
	  // pospm
	  pT = h_real_L_tofw_pos_pm->GetBinCenter(i+1);
	  yield = h_real_L_tofw_pos_pm->GetBinContent(i+1);
	  eyield = h_real_L_tofw_pos_pm->GetBinError(i+1);
	  foutpospm<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	  // negpm
	  pT = h_real_L_tofw_neg_pm->GetBinCenter(i+1);
	  yield = h_real_L_tofw_neg_pm->GetBinContent(i+1);
	  eyield = h_real_L_tofw_neg_pm->GetBinError(i+1);
	  foutnegpm<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	  // posmp
	  pT = h_real_L_tofw_pos_mp->GetBinCenter(i+1);
	  yield = h_real_L_tofw_pos_mp->GetBinContent(i+1);
	  eyield = h_real_L_tofw_pos_mp->GetBinError(i+1);
	  foutposmp<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	  // negmp
	  pT = h_real_L_tofw_neg_mp->GetBinCenter(i+1);
	  yield = h_real_L_tofw_neg_mp->GetBinContent(i+1);
	  eyield = h_real_L_tofw_neg_mp->GetBinError(i+1);
	  foutnegmp<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	}
      //if(i>=30)
      if(i>=6)
	{
	  // pospm
	  pT = h_real_H_tofw_pos_pm->GetBinCenter(i+1);
	  yield = h_real_H_tofw_pos_pm->GetBinContent(i+1);
	  eyield = h_real_H_tofw_pos_pm->GetBinError(i+1);
	  foutpospm<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	  // negpm
	  pT = h_real_H_tofw_neg_pm->GetBinCenter(i+1);
	  yield = h_real_H_tofw_neg_pm->GetBinContent(i+1);
	  eyield = h_real_H_tofw_neg_pm->GetBinError(i+1);
	  foutnegpm<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	  // posmp
	  pT = h_real_H_tofw_pos_mp->GetBinCenter(i+1);
	  yield = h_real_H_tofw_pos_mp->GetBinContent(i+1);
	  eyield = h_real_H_tofw_pos_mp->GetBinError(i+1);
	  foutposmp<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	  // negmp
	  pT = h_real_H_tofw_neg_mp->GetBinCenter(i+1);
	  yield = h_real_H_tofw_neg_mp->GetBinContent(i+1);
	  eyield = h_real_H_tofw_neg_mp->GetBinError(i+1);
	  foutnegmp<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
	}
    }

  foutpospm.close();
  foutnegpm.close();
  foutposmp.close();
  foutnegmp.close();



  // -------------------------- //
  // --- now combine fields --- //
  // -------------------------- //

  sprintf(fnameoutposcb,"RawData/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegcb,"RawData/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);

  //for(int i=0; i<100; i++)
  for(int i=0; i<20; i++)
    {
      float pT, yield, eyield;
      float pT_A, yield_A, eyield_A;
      float pT_B, yield_B, eyield_B;

      //if(i<30)
      if(i<6)
	{
	  // pospm
	  pT_A = h_real_L_tofw_pos_pm->GetBinCenter(i+1);
	  yield_A = h_real_L_tofw_pos_pm->GetBinContent(i+1);
	  eyield_A = h_real_L_tofw_pos_pm->GetBinError(i+1);
	  // posmp
	  pT_B = h_real_L_tofw_pos_mp->GetBinCenter(i+1);
	  yield_B = h_real_L_tofw_pos_mp->GetBinContent(i+1);
	  eyield_B = h_real_L_tofw_pos_mp->GetBinError(i+1);
	}
      //if(i>=30)
      if(i>=6)
	{
	  // pospm
	  pT_A = h_real_H_tofw_pos_pm->GetBinCenter(i+1);
	  yield_A = h_real_H_tofw_pos_pm->GetBinContent(i+1);
	  eyield_A = h_real_H_tofw_pos_pm->GetBinError(i+1);
	  // posmp
	  pT_B = h_real_H_tofw_pos_mp->GetBinCenter(i+1);
	  yield_B = h_real_H_tofw_pos_mp->GetBinContent(i+1);
	  eyield_B = h_real_H_tofw_pos_mp->GetBinError(i+1);
	}

      pT = (pT_A+pT_B)/2.0;
      yield = (yield_A+yield_B)/2.0;
      eyield = sqrt(eyield_A**2+eyield_B**2)/2.0;
      foutposcb<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;

      //if(i<30)
      if(i<6)
	{
	  // negpm
	  pT_A = h_real_L_tofw_neg_pm->GetBinCenter(i+1);
	  yield_A = h_real_L_tofw_neg_pm->GetBinContent(i+1);
	  eyield_A = h_real_L_tofw_neg_pm->GetBinError(i+1);
	  // negmp
	  pT_B = h_real_L_tofw_neg_mp->GetBinCenter(i+1);
	  yield_B = h_real_L_tofw_neg_mp->GetBinContent(i+1);
	  eyield_B = h_real_L_tofw_neg_mp->GetBinError(i+1);
	}
      //if(i>=30)
      if(i>=6)
	{
	  // negpm
	  pT_A = h_real_H_tofw_neg_pm->GetBinCenter(i+1);
	  yield_A = h_real_H_tofw_neg_pm->GetBinContent(i+1);
	  eyield_A = h_real_H_tofw_neg_pm->GetBinError(i+1);
	  // negmp
	  pT_B = h_real_H_tofw_neg_mp->GetBinCenter(i+1);
	  yield_B = h_real_H_tofw_neg_mp->GetBinContent(i+1);
	  eyield_B = h_real_H_tofw_neg_mp->GetBinError(i+1);
	}

      pT = (pT_A+pT_B)/2.0;
      yield = (yield_A+yield_B)/2.0;
      eyield = sqrt(eyield_A**2+eyield_B**2)/2.0;
      foutnegcb<<pT<<"\t"<<yield<<"\t"<<eyield<<endl;
    }

  foutposcb.close();
  foutnegcb.close();

  // ---
  // ---
  // ---

  // that's it!

  //cout<<"done with routine, now deleting pointers"<<endl;

  h_real_L_tofw_pos_pm->Delete();
  h_real_L_tofw_neg_pm->Delete();
  h_real_L_tofw_pos_mp->Delete();
  h_real_L_tofw_neg_mp->Delete();

  h_real_H_tofw_pos_pm->Delete();
  h_real_H_tofw_neg_pm->Delete();
  h_real_H_tofw_pos_mp->Delete();
  h_real_H_tofw_neg_mp->Delete();


  // ---

  f_real_L_pm->Close();
  f_real_L_mp->Close();

  f_real_H_pm->Close();
  f_real_H_mp->Close();


  // ---

  f_real_L_pm->Delete();
  f_real_L_mp->Delete();

  f_real_H_pm->Delete();
  f_real_H_mp->Delete();


  dummy->Delete();

  // now it's over!

}



void doitP(int pid=0)
{



  char sectorstring[10];
  sprintf(sectorstring,"tofw");

  // char centstring[10];
  char centstring1[10];
  char centstring2[10];
  char centstring3[10];
  char centstringP[10];

  sprintf(centstring1,"6070");
  sprintf(centstring2,"7080");
  sprintf(centstring3,"8092");
  sprintf(centstringP,"6092");




  // --- first centrality

  char fnameinposcb1[100];
  char fnameinnegcb1[100];
  sprintf(fnameinposcb1,"RawData/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"RawData/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  ifstream finposcb1;
  ifstream finnegcb1;
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pT_poscb1[100], yield_poscb1[100], eyield_poscb1[100];
  float pT_negcb1[100], yield_negcb1[100], eyield_negcb1[100];
  for(int i=0; i<100; i++)
    {
      // poscb1
      finposcb1>>pT_poscb1[i]>>yield_poscb1[i]>>eyield_poscb1[i];
      // negcb1
      finnegcb1>>pT_negcb1[i]>>yield_negcb1[i]>>eyield_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb1,"RawData/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"RawData/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pTR_poscb1[20], yieldR_poscb1[20], eyieldR_poscb1[20];
  float pTR_negcb1[20], yieldR_negcb1[20], eyieldR_negcb1[20];
  for(int i=0; i<20; i++)
    {
      // poscb1
      finposcb1>>pTR_poscb1[i]>>yieldR_poscb1[i]>>eyieldR_poscb1[i];
      // negcb1
      finnegcb1>>pTR_negcb1[i]>>yieldR_negcb1[i]>>eyieldR_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();



  // --- second centrality
  char fnameinposcb2[100];
  char fnameinnegcb2[100];
  sprintf(fnameinposcb2,"RawData/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"RawData/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  ifstream finposcb2;
  ifstream finnegcb2;
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pT_poscb2[100], yield_poscb2[100], eyield_poscb2[100];
  float pT_negcb2[100], yield_negcb2[100], eyield_negcb2[100];
  for(int i=0; i<100; i++)
    {
      // poscb2
      finposcb2>>pT_poscb2[i]>>yield_poscb2[i]>>eyield_poscb2[i];
      // negcb2
      finnegcb2>>pT_negcb2[i]>>yield_negcb2[i]>>eyield_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb2,"RawData/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"RawData/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pTR_poscb2[20], yieldR_poscb2[20], eyieldR_poscb2[20];
  float pTR_negcb2[20], yieldR_negcb2[20], eyieldR_negcb2[20];
  for(int i=0; i<20; i++)
    {
      // poscb2
      finposcb2>>pTR_poscb2[i]>>yieldR_poscb2[i]>>eyieldR_poscb2[i];
      // negcb2
      finnegcb2>>pTR_negcb2[i]>>yieldR_negcb2[i]>>eyieldR_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();

  // --- third centrality
  char fnameinposcb3[100];
  char fnameinnegcb3[100];
  sprintf(fnameinposcb3,"RawData/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameinnegcb3,"RawData/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  ifstream finposcb3;
  ifstream finnegcb3;
  finposcb3.open(fnameinposcb3);
  finnegcb3.open(fnameinnegcb3);
  float pT_poscb3[100], yield_poscb3[100], eyield_poscb3[100];
  float pT_negcb3[100], yield_negcb3[100], eyield_negcb3[100];
  for(int i=0; i<100; i++)
    {
      // poscb3
      finposcb3>>pT_poscb3[i]>>yield_poscb3[i]>>eyield_poscb3[i];
      // negcb3
      finnegcb3>>pT_negcb3[i]>>yield_negcb3[i]>>eyield_negcb3[i];
    }
  finposcb3.close();
  finnegcb3.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb3,"RawData/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameinnegcb3,"RawData/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  finposcb3.open(fnameinposcb3);
  finnegcb3.open(fnameinnegcb3);
  float pTR_poscb3[20], yieldR_poscb3[20], eyieldR_poscb3[20];
  float pTR_negcb3[20], yieldR_negcb3[20], eyieldR_negcb3[20];
  for(int i=0; i<20; i++)
    {
      // poscb3
      finposcb3>>pTR_poscb3[i]>>yieldR_poscb3[i]>>eyieldR_poscb3[i];
      // negcb3
      finnegcb3>>pTR_negcb3[i]>>yieldR_negcb3[i]>>eyieldR_negcb3[i];
    }
  finposcb3.close();
  finnegcb3.close();

  // ------------------------- //
  // ------------------------- //
  // ------------------------- //

  // --- now do the output --- //

  // ------------------------- //
  // ------------------------- //
  // ------------------------- //

  char fnameoutposcb[100];
  char fnameoutnegcb[100];
  sprintf(fnameoutposcb,"RawData/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  sprintf(fnameoutnegcb,"RawData/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  ofstream foutposcb;
  ofstream foutnegcb;
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pT_poscb[100], yield_poscb[100], eyield_poscb[100];
  float pT_negcb[100], yield_negcb[100], eyield_negcb[100];
  for(int i=0; i<100; i++)
    {
      // poscb
      pT_poscb[i] = (pT_poscb1[i]+pT_poscb2[i]+pT_poscb3[i])/3.0;
      yield_poscb[i] = (yield_poscb1[i]+yield_poscb2[i]+yield_poscb3[i])/3.0;
      eyield_poscb[i] = sqrt(eyield_poscb1[i]**2+eyield_poscb2[i]**2+eyield_poscb3[i]**2)/3.0;
      foutposcb<<pT_poscb[i]<<"\t"<<yield_poscb[i]<<"\t"<<eyield_poscb[i]<<endl;
      // negcb
      pT_negcb[i] = (pT_negcb1[i]+pT_negcb2[i]+pT_negcb3[i])/3.0;
      yield_negcb[i] = (yield_negcb1[i]+yield_negcb2[i]+yield_negcb3[i])/3.0;
      eyield_negcb[i] = sqrt(eyield_negcb1[i]**2+eyield_negcb2[i]**2+eyield_negcb3[i]**2)/3.0;
      foutnegcb<<pT_negcb[i]<<"\t"<<yield_negcb[i]<<"\t"<<eyield_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();

  // --- now output the rebinned data
  sprintf(fnameoutposcb,"RawData/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  sprintf(fnameoutnegcb,"RawData/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pTR_poscb[20], yieldR_poscb[20], eyieldR_poscb[20];
  float pTR_negcb[20], yieldR_negcb[20], eyieldR_negcb[20];
  for(int i=0; i<20; i++)
    {
      // poscb
      pTR_poscb[i] = (pTR_poscb1[i]+pTR_poscb2[i]+pTR_poscb3[i])/3.0;
      yieldR_poscb[i] = (yieldR_poscb1[i]+yieldR_poscb2[i]+yieldR_poscb3[i])/3.0;
      eyieldR_poscb[i] = sqrt(eyieldR_poscb1[i]**2+eyieldR_poscb2[i]**2+eyieldR_poscb3[i]**2)/3.0;
      foutposcb<<pTR_poscb[i]<<"\t"<<yieldR_poscb[i]<<"\t"<<eyieldR_poscb[i]<<endl;
      // negcb
      pTR_negcb[i] = (pTR_negcb1[i]+pTR_negcb2[i]+pTR_negcb3[i])/3.0;
      yieldR_negcb[i] = (yieldR_negcb1[i]+yieldR_negcb2[i]+yieldR_negcb3[i])/3.0;
      eyieldR_negcb[i] = sqrt(eyieldR_negcb1[i]**2+eyieldR_negcb2[i]**2+eyieldR_negcb3[i]**2)/3.0;
      foutnegcb<<pTR_negcb[i]<<"\t"<<yieldR_negcb[i]<<"\t"<<eyieldR_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();



} // doitP







void doitM(int pid=0, int centid=0)
{



  char sectorstring[10];
  sprintf(sectorstring,"tofw");

  // char centstring[10];
  char centstring1[10];
  char centstring2[10];
  char centstring3[10];

  if(centid==0)
    {
      sprintf(centstring1,"2030");
      sprintf(centstring2,"3040");
      sprintf(centstring3,"2040");
    }

  if(centid==1)
    {
      sprintf(centstring1,"4050");
      sprintf(centstring2,"5060");
      sprintf(centstring3,"4060");
    }

  if(centid==2)
    {
      sprintf(centstring1,"6070");
      sprintf(centstring2,"7080");
      sprintf(centstring3,"6080");
    }




  // --- first centrality

  char fnameinposcb1[100];
  char fnameinnegcb1[100];
  sprintf(fnameinposcb1,"RawData/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"RawData/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  ifstream finposcb1;
  ifstream finnegcb1;
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pT_poscb1[100], yield_poscb1[100], eyield_poscb1[100];
  float pT_negcb1[100], yield_negcb1[100], eyield_negcb1[100];
  for(int i=0; i<100; i++)
    {
      // poscb1
      finposcb1>>pT_poscb1[i]>>yield_poscb1[i]>>eyield_poscb1[i];
      // negcb1
      finnegcb1>>pT_negcb1[i]>>yield_negcb1[i]>>eyield_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb1,"RawData/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"RawData/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pTR_poscb1[20], yieldR_poscb1[20], eyieldR_poscb1[20];
  float pTR_negcb1[20], yieldR_negcb1[20], eyieldR_negcb1[20];
  for(int i=0; i<20; i++)
    {
      // poscb1
      finposcb1>>pTR_poscb1[i]>>yieldR_poscb1[i]>>eyieldR_poscb1[i];
      // negcb1
      finnegcb1>>pTR_negcb1[i]>>yieldR_negcb1[i]>>eyieldR_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();



  // --- second centrality
  char fnameinposcb2[100];
  char fnameinnegcb2[100];
  sprintf(fnameinposcb2,"RawData/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"RawData/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  ifstream finposcb2;
  ifstream finnegcb2;
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pT_poscb2[100], yield_poscb2[100], eyield_poscb2[100];
  float pT_negcb2[100], yield_negcb2[100], eyield_negcb2[100];
  for(int i=0; i<100; i++)
    {
      // poscb2
      finposcb2>>pT_poscb2[i]>>yield_poscb2[i]>>eyield_poscb2[i];
      // negcb2
      finnegcb2>>pT_negcb2[i]>>yield_negcb2[i]>>eyield_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb2,"RawData/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"RawData/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pTR_poscb2[20], yieldR_poscb2[20], eyieldR_poscb2[20];
  float pTR_negcb2[20], yieldR_negcb2[20], eyieldR_negcb2[20];
  for(int i=0; i<20; i++)
    {
      // poscb2
      finposcb2>>pTR_poscb2[i]>>yieldR_poscb2[i]>>eyieldR_poscb2[i];
      // negcb2
      finnegcb2>>pTR_negcb2[i]>>yieldR_negcb2[i]>>eyieldR_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();

  // ------------------------- //
  // ------------------------- //
  // ------------------------- //

  // --- now do the output --- //

  // ------------------------- //
  // ------------------------- //
  // ------------------------- //

  char fnameoutposcb[100];
  char fnameoutnegcb[100];
  sprintf(fnameoutposcb,"RawData/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameoutnegcb,"RawData/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  ofstream foutposcb;
  ofstream foutnegcb;
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pT_poscb[100], yield_poscb[100], eyield_poscb[100];
  float pT_negcb[100], yield_negcb[100], eyield_negcb[100];
  for(int i=0; i<100; i++)
    {
      // poscb
      pT_poscb[i] = (pT_poscb1[i]+pT_poscb2[i])/2.0;
      yield_poscb[i] = (yield_poscb1[i]+yield_poscb2[i])/2.0;
      eyield_poscb[i] = sqrt(eyield_poscb1[i]**2+eyield_poscb2[i]**2)/2.0;
      foutposcb<<pT_poscb[i]<<"\t"<<yield_poscb[i]<<"\t"<<eyield_poscb[i]<<endl;
      // negcb
      pT_negcb[i] = (pT_negcb1[i]+pT_negcb2[i])/2.0;
      yield_negcb[i] = (yield_negcb1[i]+yield_negcb2[i])/2.0;
      eyield_negcb[i] = sqrt(eyield_negcb1[i]**2+eyield_negcb2[i]**2)/2.0;
      foutnegcb<<pT_negcb[i]<<"\t"<<yield_negcb[i]<<"\t"<<eyield_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();

  // --- now output the rebinned data
  sprintf(fnameoutposcb,"RawData/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameoutnegcb,"RawData/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pTR_poscb[20], yieldR_poscb[20], eyieldR_poscb[20];
  float pTR_negcb[20], yieldR_negcb[20], eyieldR_negcb[20];
  for(int i=0; i<20; i++)
    {
      // poscb
      pTR_poscb[i] = (pTR_poscb1[i]+pTR_poscb2[i])/2.0;
      yieldR_poscb[i] = (yieldR_poscb1[i]+yieldR_poscb2[i])/2.0;
      eyieldR_poscb[i] = sqrt(eyieldR_poscb1[i]**2+eyieldR_poscb2[i]**2)/2.0;
      foutposcb<<pTR_poscb[i]<<"\t"<<yieldR_poscb[i]<<"\t"<<eyieldR_poscb[i]<<endl;
      // negcb
      pTR_negcb[i] = (pTR_negcb1[i]+pTR_negcb2[i])/2.0;
      yieldR_negcb[i] = (yieldR_negcb1[i]+yieldR_negcb2[i])/2.0;
      eyieldR_negcb[i] = sqrt(eyieldR_negcb1[i]**2+eyieldR_negcb2[i]**2)/2.0;
      foutnegcb<<pTR_negcb[i]<<"\t"<<yieldR_negcb[i]<<"\t"<<eyieldR_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();



}
