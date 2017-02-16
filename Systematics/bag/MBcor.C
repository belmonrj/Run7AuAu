void MBcor()
{

  for(int iswitch=0; iswitch<2; iswitch++)
    {
      for(int itype=0; itype<10; itype++)
	{
	  for(int ipid=0; ipid<3; ipid++)
	    {
	      // UNROLL THOSE LOOPS!!!
	      doit(ipid,itype,iswitch,0);
	    }
	}
    }




  cout<<"all done!  i hope you have a great day!"<<endl;

}

void doit(int ipid=0, int itype=0, int iswitch=0, int centid=0)
{




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

  char pidstring[5];
  sprintf(pidstring,"pion"); // "default"
  if(ipid==0) sprintf(pidstring,"pion");
  if(ipid==1) sprintf(pidstring,"kaon");
  if(ipid==2) sprintf(pidstring,"prot");

  char typestring[5];
  sprintf(typestring,"tfwm"); // "default"
  if(itype==0) sprintf(typestring,"tfwm");
  if(itype==1) sprintf(typestring,"pc3m");
  if(itype==2) sprintf(typestring,"pc3f");
  if(itype==3) sprintf(typestring,"pc1f");
  if(itype==4) sprintf(typestring,"dcfc");
  if(itype==5) sprintf(typestring,"dzed");
  if(itype==6) sprintf(typestring,"spid");
  if(itype==7) sprintf(typestring,"tpid");
  if(itype==8) sprintf(typestring,"gadc");// forgot this one
  if(itype==9) sprintf(typestring,"tepc");// forgot this one

  char switchstring[2];
  sprintf(switchstring,"A"); // "default"
  if(iswitch==0) sprintf(switchstring,"A");
  if(iswitch==1) sprintf(switchstring,"B");

  // char centstring[5];
  // if(centid==0) sprintf(centstring,"0010");
  // else if(centid==1) sprintf(centstring,"1020");
  // else if(centid==2) sprintf(centstring,"2040");
  // else if(centid==3) sprintf(centstring,"4060");
  // else if(centid==4) sprintf(centstring,"6092");
  // else {cout<<"you gonna die"<<endl; return;}

  char centstring[11];
  if(centid==0) sprintf(centstring,"_cent0010");
  else if(centid==1) sprintf(centstring,"_cent1020");
  else if(centid==2) sprintf(centstring,"_cent2040");
  else if(centid==3) sprintf(centstring,"_cent4060");
  else if(centid==4) sprintf(centstring,"_cent6092");
  else {cout<<"you gonna die"<<endl; return;}



  char name_real_tofw_pos_pm[50];
  char name_sim_tofw_pos_pm[50];
  char name_real_tofw_neg_pm[50];
  char name_sim_tofw_neg_pm[50];

  char name_real_tofw_pos_mp[50];
  char name_sim_tofw_pos_mp[50];
  char name_real_tofw_neg_mp[50];
  char name_sim_tofw_neg_mp[50];

  sprintf(name_real_tofw_pos_pm,"ptsys_%s_pos_%s%s",pidstring,typestring,switchstring);
  sprintf(name_sim_tofw_pos_pm,"ptsys_%s_pos_%s%s",pidstring,typestring,switchstring);
  sprintf(name_real_tofw_neg_pm,"ptsys_%s_neg_%s%s",pidstring,typestring,switchstring);
  sprintf(name_sim_tofw_neg_pm,"ptsys_%s_neg_%s%s",pidstring,typestring,switchstring);

  sprintf(name_real_tofw_pos_mp,"ptsys_%s_pos_%s%s",pidstring,typestring,switchstring);
  sprintf(name_sim_tofw_pos_mp,"ptsys_%s_pos_%s%s",pidstring,typestring,switchstring);
  sprintf(name_real_tofw_neg_mp,"ptsys_%s_neg_%s%s",pidstring,typestring,switchstring);
  sprintf(name_sim_tofw_neg_mp,"ptsys_%s_neg_%s%s",pidstring,typestring,switchstring);

  TH1F *h_real_L_tofw_pos_pm = f_real_L_pm->Get(name_real_tofw_pos_pm);
  TH1F *h_real_L_tofw_neg_pm = f_real_L_pm->Get(name_real_tofw_neg_pm);
  TH1F *h_real_L_tofw_pos_mp = f_real_L_mp->Get(name_real_tofw_pos_mp);
  TH1F *h_real_L_tofw_neg_mp = f_real_L_mp->Get(name_real_tofw_neg_mp);

  TH1F *h_real_H_tofw_pos_pm = f_real_H_pm->Get(name_real_tofw_pos_pm);
  TH1F *h_real_H_tofw_neg_pm = f_real_H_pm->Get(name_real_tofw_neg_pm);
  TH1F *h_real_H_tofw_pos_mp = f_real_H_mp->Get(name_real_tofw_pos_mp);
  TH1F *h_real_H_tofw_neg_mp = f_real_H_mp->Get(name_real_tofw_neg_mp);

  if(ipid==0)
    {
      TH1F *h_sim_tofw_pos_pm = f_simpion_pm->Get(name_sim_tofw_pos_pm);
      TH1F *h_sim_tofw_neg_pm = f_simpion_pm->Get(name_sim_tofw_neg_pm);
      TH1F *h_sim_tofw_pos_mp = f_simpion_mp->Get(name_sim_tofw_pos_mp);
      TH1F *h_sim_tofw_neg_mp = f_simpion_mp->Get(name_sim_tofw_neg_mp);
    }
  else if(ipid==1)
    {
      TH1F *h_sim_tofw_pos_pm = f_simkaon_pm->Get(name_sim_tofw_pos_pm);
      TH1F *h_sim_tofw_neg_pm = f_simkaon_pm->Get(name_sim_tofw_neg_pm);
      TH1F *h_sim_tofw_pos_mp = f_simkaon_mp->Get(name_sim_tofw_pos_mp);
      TH1F *h_sim_tofw_neg_mp = f_simkaon_mp->Get(name_sim_tofw_neg_mp);
    }
  else if(ipid==2)
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
  //float embed[9] = {0.542065, 0.653215, 0.751339, 0.81413, 0.882178, 0.924843, 0.949757, 0.968341, 0.972655};
  float embed[3] = {0.542065, 0.653215, 0.751339};
  Long64_t nevents_L_pm = 39733831; // 39.7 M 
  Long64_t nevents_L_mp = 27794082; // 27.8 M
  Long64_t nevents_H_pm = 2136153235; // 2.14 B
  Long64_t nevents_H_mp = 2132453794; // 2.13 B
  float tofw_eff = 0.95; // cosmic ray studies show 95%, in situ studies show 90%
  float tofw_adc = 0.85; // in situ studies show 85%
  float dcqual = 0.9; // percentage of high-quality tracks is lower in real than in sim
  float binwidth_pT = 0.1; // 100 MeV bins
  //float binwidth_cent = 0.1; // 10% centrality bins, adjust as needed
  float binwidth_cent = 0.92; // using MB for systematics
  //if(centid==8) binwidth_cent = 0.12; // not using
  //float twopi = 6.28318531; // corrected spectra are 1/2pi 1/pT
  int slem = 2;

  float konstant_L_pm = nevents_L_pm*embed[slem]*tofw_eff*tofw_adc*dcqual*binwidth_pT*binwidth_cent;
  float konstant_L_mp = nevents_L_mp*embed[slem]*tofw_eff*tofw_adc*dcqual*binwidth_pT*binwidth_cent;
  float konstant_H_pm = nevents_H_pm*embed[slem]*tofw_eff*tofw_adc*dcqual*binwidth_pT*binwidth_cent;
  float konstant_H_mp = nevents_H_mp*embed[slem]*tofw_eff*tofw_adc*dcqual*binwidth_pT*binwidth_cent;

  TF1 *fun = new TF1("fun","pol1",0,10);
  fun->SetParameter(0,0);
  //fun->SetParameter(1,1);
  fun->SetParameter(1,6.28318531); // corrected spectra are 1/(2pipT)





  h_real_L_tofw_pos_pm->Divide(fun,konstant_L_pm);
  h_real_L_tofw_neg_pm->Divide(fun,konstant_L_pm);
  h_real_L_tofw_pos_mp->Divide(fun,konstant_L_mp);
  h_real_L_tofw_neg_mp->Divide(fun,konstant_L_mp);

  h_real_H_tofw_pos_pm->Divide(fun,konstant_H_pm);
  h_real_H_tofw_neg_pm->Divide(fun,konstant_H_pm);
  h_real_H_tofw_pos_mp->Divide(fun,konstant_H_mp);
  h_real_H_tofw_neg_mp->Divide(fun,konstant_H_mp);




  // -------------------------- //
  // --- now combine fields --- //
  // -------------------------- //

  char fnameoutposcb[100];
  char fnameoutnegcb[100];

  sprintf(fnameoutposcb,"Data/ptsys_%s_pos_%s%s.dat",pidstring,typestring,switchstring);
  sprintf(fnameoutnegcb,"Data/ptsys_%s_neg_%s%s.dat",pidstring,typestring,switchstring);

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

