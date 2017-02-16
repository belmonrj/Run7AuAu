void correct()
{

  cout<<"hello and welcome!"<<endl;
  cout<<"this is a new for Run7 spectra correction macro"<<endl;
  cout<<"based on the histogram division method."<<endl;
  cout<<"it also does the bin width correction, 1/pT correction,"<<endl;
  cout<<"and normalization constants."<<endl;

  //doit(0,0,0);
  //doit(0,2,0);

  //exit(1);

  for(int icent=0; icent<9; icent++)
    {
      for(int ipid=0; ipid<10; ipid++)
	{
	  for(int isec=0; isec<3; isec++)
	    {
	      doit(isec,ipid,icent);
	      //cout<<"doit("<<isec<<","<<ipid<<","<<icent<<");"<<endl;
	    }
	}
    }




  cout<<"all done!  i hope you have a great day!"<<endl;

}

void doit(int sector=0, int pid=0, int centid=0)
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
  TFile *f_simpion_pm = TFile::Open("SimFiles/pion/simsum_pm.root");
  TFile *f_simkaon_pm = TFile::Open("SimFiles/kaon/simsum_pm.root");
  TFile *f_simproton_pm = TFile::Open("SimFiles/proton/simsum_pm.root");

  TFile *f_real_L_mp = TFile::Open("RealFiles/outlowmp.root");
  TFile *f_real_H_mp = TFile::Open("RealFiles/outhighmp.root");
  TFile *f_simpion_mp = TFile::Open("SimFiles/pion/simsum_mp.root");
  TFile *f_simkaon_mp = TFile::Open("SimFiles/kaon/simsum_mp.root");
  TFile *f_simproton_mp = TFile::Open("SimFiles/proton/simsum_mp.root");

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

  if(pid<=3)
    {
      TH1F *h_sim_tofw_pos_pm = f_simpion_pm->Get(name_sim_tofw_pos_pm);
      TH1F *h_sim_tofw_neg_pm = f_simpion_pm->Get(name_sim_tofw_neg_pm);
      TH1F *h_sim_tofw_pos_mp = f_simpion_mp->Get(name_sim_tofw_pos_mp);
      TH1F *h_sim_tofw_neg_mp = f_simpion_mp->Get(name_sim_tofw_neg_mp);
    }
  else if(pid==4||pid==5)
    {
      TH1F *h_sim_tofw_pos_pm = f_simkaon_pm->Get(name_sim_tofw_pos_pm);
      TH1F *h_sim_tofw_neg_pm = f_simkaon_pm->Get(name_sim_tofw_neg_pm);
      TH1F *h_sim_tofw_pos_mp = f_simkaon_mp->Get(name_sim_tofw_pos_mp);
      TH1F *h_sim_tofw_neg_mp = f_simkaon_mp->Get(name_sim_tofw_neg_mp);
    }
  else if(pid>=6)
    {
      TH1F *h_sim_tofw_pos_pm = f_simproton_pm->Get(name_sim_tofw_pos_pm);
      TH1F *h_sim_tofw_neg_pm = f_simproton_pm->Get(name_sim_tofw_neg_pm);
      TH1F *h_sim_tofw_pos_mp = f_simproton_mp->Get(name_sim_tofw_pos_mp);
      TH1F *h_sim_tofw_neg_mp = f_simproton_mp->Get(name_sim_tofw_neg_mp);
    }
  else
    {
      cerr<<"unknown pid number, now dying a quick but horribly painful death"<<endl;
    }

  h_real_L_tofw_pos_pm->Sumw2();
  h_real_L_tofw_neg_pm->Sumw2();
  h_real_L_tofw_pos_mp->Sumw2();
  h_real_L_tofw_neg_mp->Sumw2();

  h_real_H_tofw_pos_pm->Sumw2();
  h_real_H_tofw_neg_pm->Sumw2();
  h_real_H_tofw_pos_mp->Sumw2();
  h_real_H_tofw_neg_mp->Sumw2();

  h_sim_tofw_pos_pm->Sumw2();
  h_sim_tofw_neg_pm->Sumw2();
  h_sim_tofw_pos_mp->Sumw2();
  h_sim_tofw_neg_mp->Sumw2();


  // divide Real histogram by Sim histogram
  
  h_real_L_tofw_pos_pm->Divide(h_sim_tofw_pos_pm);
  h_real_L_tofw_neg_pm->Divide(h_sim_tofw_neg_pm);
  h_real_L_tofw_pos_mp->Divide(h_sim_tofw_pos_mp);
  h_real_L_tofw_neg_mp->Divide(h_sim_tofw_neg_mp);

  h_real_H_tofw_pos_pm->Divide(h_sim_tofw_pos_pm);
  h_real_H_tofw_neg_pm->Divide(h_sim_tofw_neg_pm);
  h_real_H_tofw_pos_mp->Divide(h_sim_tofw_pos_mp);
  h_real_H_tofw_neg_mp->Divide(h_sim_tofw_neg_mp);

  // Multiplicative constants
  // Multiply by the simulation event numbes and acceptance windows
  //float simevents = 2.0e7; // 20M events for all types
  float simevents = 2.0e5; // 20M events for all types, divide by 100 to get per bin
  float window_azi = 0.5; // events are thrown in pi radians, divide by 2pi
  float window_rap = 1.2; // events are thrown in +/- 0.6 units of rapidity, divide by 1

  float simconst = simevents/window_azi/window_rap;

  //cout<<"simulation constant is "<<simconst<<endl;

  TF1 *dummy = new TF1("dummy","pol0",0,10);
  dummy->SetParameter(0,1.0);

  h_real_L_tofw_pos_pm->Multiply(dummy,simconst);
  h_real_L_tofw_neg_pm->Multiply(dummy,simconst);
  h_real_L_tofw_pos_mp->Multiply(dummy,simconst);
  h_real_L_tofw_neg_mp->Multiply(dummy,simconst);

  h_real_H_tofw_pos_pm->Multiply(dummy,simconst);
  h_real_H_tofw_neg_pm->Multiply(dummy,simconst);
  h_real_H_tofw_pos_mp->Multiply(dummy,simconst);
  h_real_H_tofw_neg_mp->Multiply(dummy,simconst);


  // Division constants
  // Divide by the number of real events, various efficiencies, and pT and cent bin-widths
  float embed[9] = {0.542065, 0.653215, 0.751339, 0.81413, 0.882178, 0.924843, 0.949757, 0.968341, 0.972655};
  Long64_t nevents_L_pm = 39733831; // 39.7 M 
  Long64_t nevents_L_mp = 27794082; // 27.8 M
  //Long64_t nevents_H_pm = 2137530958; // 2.14 B // old numbers, from 1 GeV files
  //Long64_t nevents_H_mp = 2126447248; // 2.13 B // old numbers, from 1 GeV files
  Long64_t nevents_H_pm = 2136153235; // 2.14 B
  Long64_t nevents_H_mp = 2132453794; // 2.13 B
  //float tofw_eff = 0.95; // cosmic ray studies show 95%, in situ studies show 90%
  float tofw_eff = 0.90; // cosmic ray studies show 95%, in situ studies show 90%
  float tofw_adc = 0.85; // in situ studies show 85%
  float dcqual = 0.9; // percentage of high-quality tracks is lower in real than in sim
  float binwidth_pT = 0.1; // 100 MeV bins
  float binwidth_cent = 0.1; // 10% centrality bins, adjust as needed
  if(centid==8) binwidth_cent = 0.12;
  binwidth_cent /= 0.93; // correct for trigger bias
  //float twopi = 6.28318531; // corrected spectra are 1/2pi 1/pT
  //float mistake = 0.4;
  //float mistake = 1.0;

  //float konstant_pm = nevents_pm*tofw_eff*tofw_adc*dcqual*binwidth_pT*binwidth_cent*twopi;
  //float konstant_mp = nevents_mp*tofw_eff*tofw_adc*dcqual*binwidth_pT*binwidth_cent*twopi;
  //float konstant_L_pm = nevents_L_pm*embed[centid]*tofw_eff*tofw_adc*dcqual*binwidth_pT*binwidth_cent*mistake;
  //float konstant_L_mp = nevents_L_mp*embed[centid]*tofw_eff*tofw_adc*dcqual*binwidth_pT*binwidth_cent*mistake;
  //float konstant_H_pm = nevents_H_pm*embed[centid]*tofw_eff*tofw_adc*dcqual*binwidth_pT*binwidth_cent*mistake;
  //float konstant_H_mp = nevents_H_mp*embed[centid]*tofw_eff*tofw_adc*dcqual*binwidth_pT*binwidth_cent*mistake;
  float konstant_L_pm = nevents_L_pm*embed[centid]*tofw_eff*tofw_adc*dcqual*binwidth_pT*binwidth_cent;
  float konstant_L_mp = nevents_L_mp*embed[centid]*tofw_eff*tofw_adc*dcqual*binwidth_pT*binwidth_cent;
  float konstant_H_pm = nevents_H_pm*embed[centid]*tofw_eff*tofw_adc*dcqual*binwidth_pT*binwidth_cent;
  float konstant_H_mp = nevents_H_mp*embed[centid]*tofw_eff*tofw_adc*dcqual*binwidth_pT*binwidth_cent;

  TF1 *fun = new TF1("fun","pol1",0,10);
  fun->SetParameter(0,0);
  //fun->SetParameter(1,1);
  fun->SetParameter(1,6.28318531); // corrected spectra are 1/(2pipT)



  //cout<<"normalization constant is "<<konstant_pm<<endl;

  h_real_L_tofw_pos_pm->Divide(fun,konstant_L_pm);
  h_real_L_tofw_neg_pm->Divide(fun,konstant_L_pm);
  h_real_L_tofw_pos_mp->Divide(fun,konstant_L_mp);
  h_real_L_tofw_neg_mp->Divide(fun,konstant_L_mp);

  h_real_H_tofw_pos_pm->Divide(fun,konstant_H_pm);
  h_real_H_tofw_neg_pm->Divide(fun,konstant_H_pm);
  h_real_H_tofw_pos_mp->Divide(fun,konstant_H_mp);
  h_real_H_tofw_neg_mp->Divide(fun,konstant_H_mp);

  //char histotitle[100];
  //sprintf(histotitle,"corrected  #pi^{+}, %s",bigcentstring);
  //h_real_L_tofw_pos_pm->SetTitle(histotitle);
  //h_real_L_tofw_pos_pm->Draw();

  //char figname[100];
  //sprintf(figname,"test_corrspec_pid_%s_%d_cent_%s.gif",sectorstring,pid,centstring);
  //c1->Print("test_correctedspectra.gif");
  //c1->Print(figname);

  // now for the important part

  //cout<<"now doing the most important part"<<endl;

  char fnameoutpospm[100];
  char fnameoutnegpm[100];
  char fnameoutposmp[100];
  char fnameoutnegmp[100];

  sprintf(fnameoutpospm,"Data/ptpid_%s_pos_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegpm,"Data/ptpid_%s_neg_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameoutposmp,"Data/ptpid_%s_pos_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegmp,"Data/ptpid_%s_neg_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);

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

  sprintf(fnameoutposcb,"Data/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegcb,"Data/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

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

  //char histotitle[100];
  //sprintf(histotitle,"corrected  #pi^{+}, rebinned, %s",bigcentstring);
  //h_real_L_tofw_pos_pm->SetTitle(histotitle);
  //h_real_L_tofw_pos_pm->Draw();

  //char figname[100];
  //sprintf(figname,"test_corrspec_R5_pid_%s_%d_cent_%s.gif",sectorstring,pid,centstring);
  //c1->Print("test_correctedspectra.gif");
  //c1->Print(figname);

  // now for the important part

  //cout<<"now doing the most important part"<<endl;

  sprintf(fnameoutpospm,"Data/R5_ptpid_%s_pos_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegpm,"Data/R5_ptpid_%s_neg_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameoutposmp,"Data/R5_ptpid_%s_pos_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegmp,"Data/R5_ptpid_%s_neg_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);

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

  sprintf(fnameoutposcb,"Data/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegcb,"Data/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

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

  h_sim_tofw_pos_pm->Delete();
  h_sim_tofw_neg_pm->Delete();
  h_sim_tofw_pos_mp->Delete();
  h_sim_tofw_neg_mp->Delete();

  // ---

  f_real_L_pm->Close();
  f_real_L_mp->Close();

  f_real_H_pm->Close();
  f_real_H_mp->Close();

  f_simpion_pm->Close();
  f_simkaon_pm->Close();
  f_simproton_pm->Close();

  f_simpion_mp->Close();
  f_simkaon_mp->Close();
  f_simproton_mp->Close();

  // ---

  f_real_L_pm->Delete();
  f_real_L_mp->Delete();

  f_real_H_pm->Delete();
  f_real_H_mp->Delete();

  f_simpion_pm->Delete();
  f_simkaon_pm->Delete();
  f_simproton_pm->Delete();

  f_simpion_mp->Delete();
  f_simkaon_mp->Delete();
  f_simproton_mp->Delete();

  // now it's over!

}

