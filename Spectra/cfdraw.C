void cfdraw()
{

  cout<<"hello and welcome!"<<endl;


  for(int ipid=0; ipid<10; ipid++)
    {
      doit(0,ipid);
    }
  



  cout<<"all done!  i hope you have a great day!"<<endl;

}


void doit(int sector=0, int pid=0)
{


  TCanvas *c1 = new TCanvas("c1","c1",800,600);
  c1->SetFillColor(kWhite);
  c1->SetFrameFillColor(kWhite);
  c1->SetBorderMode(0);
  c1->SetFrameBorderMode(0);
  //c1->SetLogy();



  TFile *f_simpion_pm = TFile::Open("SimFiles/pion/simsum_pm.root");
  TFile *f_simkaon_pm = TFile::Open("SimFiles/kaon/simsum_pm.root");
  TFile *f_simproton_pm = TFile::Open("SimFiles/proton/simsum_pm.root");

  TFile *f_simpion_mp = TFile::Open("SimFiles/pion/simsum_mp.root");
  TFile *f_simkaon_mp = TFile::Open("SimFiles/kaon/simsum_mp.root");
  TFile *f_simproton_mp = TFile::Open("SimFiles/proton/simsum_mp.root");

  char sectorstring[10];
  sprintf(sectorstring,"tofw"); // "default"
  if(sector==0) sprintf(sectorstring,"tofw");
  if(sector==1) sprintf(sectorstring,"tofw_w1");
  if(sector==2) sprintf(sectorstring,"tofw_w2");



  char name_sim_tofw_pos_pm[50];
  char name_sim_tofw_neg_pm[50];

  char name_sim_tofw_pos_mp[50];
  char name_sim_tofw_neg_mp[50];

  sprintf(name_sim_tofw_pos_pm,"ptpid_%s_pos_%d_dis",sectorstring,pid);
  sprintf(name_sim_tofw_neg_pm,"ptpid_%s_neg_%d_dis",sectorstring,pid);

  sprintf(name_sim_tofw_pos_mp,"ptpid_%s_pos_%d_dis",sectorstring,pid);
  sprintf(name_sim_tofw_neg_mp,"ptpid_%s_neg_%d_dis",sectorstring,pid);

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

  h_sim_tofw_pos_pm->Sumw2();
  h_sim_tofw_neg_pm->Sumw2();

  h_sim_tofw_pos_mp->Sumw2();
  h_sim_tofw_neg_mp->Sumw2();



  

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

  h_sim_tofw_pos_pm->Divide(dummy,simconst);
  h_sim_tofw_neg_pm->Divide(dummy,simconst);
  h_sim_tofw_pos_mp->Divide(dummy,simconst);
  h_sim_tofw_neg_mp->Divide(dummy,simconst);

  TH1F *hR5_sim_tofw_pos_pm = (TH1F *)h_sim_tofw_pos_pm->Clone();
  TH1F *hR5_sim_tofw_neg_pm = (TH1F *)h_sim_tofw_neg_pm->Clone();
  TH1F *hR5_sim_tofw_pos_mp = (TH1F *)h_sim_tofw_pos_mp->Clone();
  TH1F *hR5_sim_tofw_neg_mp = (TH1F *)h_sim_tofw_neg_mp->Clone();
  hR5_sim_tofw_pos_pm->Rebin(5);
  hR5_sim_tofw_neg_pm->Rebin(5);
  hR5_sim_tofw_pos_mp->Rebin(5);
  hR5_sim_tofw_neg_mp->Rebin(5);
  hR5_sim_tofw_pos_pm->Divide(dummy,5);
  hR5_sim_tofw_neg_pm->Divide(dummy,5);
  hR5_sim_tofw_pos_mp->Divide(dummy,5);
  hR5_sim_tofw_neg_mp->Divide(dummy,5);

  // -------------------- //
  // --- 100 MeV part --- //
  // -------------------- //
  float pt[100], value[100], evalue[100];
  float ept[100];
  float pt_pospm[100], value_pospm[100], evalue_pospm[100];
  float pt_negpm[100], value_negpm[100], evalue_negpm[100];
  float pt_posmp[100], value_posmp[100], evalue_posmp[100];
  float pt_negmp[100], value_negmp[100], evalue_negmp[100];
  float temp, etemp;
  for(int i=0; i<100; i++)
    {
      temp = h_sim_tofw_pos_pm->GetBinContent(i+1);
      etemp = h_sim_tofw_pos_pm->GetBinError(i+1);
      if(temp>0)
	{
	  value_pospm[i] = 1.0/temp;
	  evalue_pospm[i] = etemp/temp/temp;
	}
      else
	{
	  value_pospm[i] = -9;
	  evalue_pospm[i] = 0;
	}
      pt_pospm[i] = h_sim_tofw_pos_pm->GetBinCenter(i+1);
      ept[i]=0;

      temp = h_sim_tofw_neg_pm->GetBinContent(i+1);
      etemp = h_sim_tofw_neg_pm->GetBinError(i+1);
      if(temp>0)
	{
	  value_negpm[i] = 1.0/temp;
	  evalue_negpm[i] = etemp/temp/temp;
	}
      else
	{
	  value_negpm[i] = -9;
	  evalue_negpm[i] = 0;
	}
      pt_negpm[i] = h_sim_tofw_neg_pm->GetBinCenter(i+1);
      ept[i]=0;

      temp = h_sim_tofw_pos_mp->GetBinContent(i+1);
      etemp = h_sim_tofw_pos_mp->GetBinError(i+1);
      if(temp>0)
	{
	  value_posmp[i] = 1.0/temp;
	  evalue_posmp[i] = etemp/temp/temp;
	}
      else
	{
	  value_posmp[i] = -9;
	  evalue_posmp[i] = 0;
	}
      pt_posmp[i] = h_sim_tofw_pos_mp->GetBinCenter(i+1);
      ept[i]=0;

      temp = h_sim_tofw_neg_mp->GetBinContent(i+1);
      etemp = h_sim_tofw_neg_mp->GetBinError(i+1);
      if(temp>0)
	{
	  value_negmp[i] = 1.0/temp;
	  evalue_negmp[i] = etemp/temp/temp;
	}
      else
	{
	  value_negmp[i] = -9;
	  evalue_negmp[i] = 0;
	}
      pt_negmp[i] = h_sim_tofw_neg_mp->GetBinCenter(i+1);
      ept[i]=0;



    }


  char figname[50];
  char filename[50];
  ofstream fout;

  TGraphErrors *tge_pospm = new TGraphErrors(100,pt_pospm,value_pospm,ept,evalue_pospm);
  tge_pospm->SetMarkerColor(kBlack);
  tge_pospm->SetMarkerStyle(20);
  tge_pospm->Draw("ap");
  tge_pospm->SetMaximum(1000);
  //tge_pospm->SetMaximum(200);
  tge_pospm->SetMinimum(0);
  tge_pospm->GetXaxis()->SetLimits(0.0,6.0);
  tge_pospm->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tge_pospm->GetXaxis()->CenterTitle();
  tge_pospm->GetYaxis()->SetTitle("Correction Factor");
  tge_pospm->GetYaxis()->CenterTitle();

  sprintf(figname,"CorrectionFactors/cf_%s_pospm_%d_dis.gif",sectorstring,pid);
  c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cf_%s_pospm_%d_dis.eps",sectorstring,pid);
  c1->Print(figname);

  sprintf(filename,"CorrectionFactors/cf_%s_pospm_%d_dis.dat",sectorstring,pid);
  fout.open(filename);
  for(int i=0; i<100; i++)
    {
      fout<<pt_pospm[i]<<"\t"<<value_pospm[i]<<"\t"<<evalue_pospm[i]<<endl;
    }
  fout.close();


  TGraphErrors *tge_negpm = new TGraphErrors(100,pt_negpm,value_negpm,ept,evalue_negpm);
  tge_negpm->SetMarkerColor(kBlack);
  tge_negpm->SetMarkerStyle(20);
  tge_negpm->Draw("ap");
  tge_negpm->SetMaximum(1000);
  //tge_negpm->SetMaximum(200);
  tge_negpm->SetMinimum(0);
  tge_negpm->GetXaxis()->SetLimits(0.0,6.0);
  tge_negpm->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tge_negpm->GetXaxis()->CenterTitle();
  tge_negpm->GetYaxis()->SetTitle("Correction Factor");
  tge_negpm->GetYaxis()->CenterTitle();

  sprintf(figname,"CorrectionFactors/cf_%s_negpm_%d_dis.gif",sectorstring,pid);
  c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cf_%s_negpm_%d_dis.eps",sectorstring,pid);
  c1->Print(figname);

  sprintf(filename,"CorrectionFactors/cf_%s_negpm_%d_dis.dat",sectorstring,pid);
  fout.open(filename);
  for(int i=0; i<100; i++)
    {
      fout<<pt_negpm[i]<<"\t"<<value_negpm[i]<<"\t"<<evalue_negpm[i]<<endl;
    }
  fout.close();



  TGraphErrors *tge_posmp = new TGraphErrors(100,pt_posmp,value_posmp,ept,evalue_posmp);
  tge_posmp->SetMarkerColor(kBlack);
  tge_posmp->SetMarkerStyle(20);
  tge_posmp->Draw("ap");
  tge_posmp->SetMaximum(1000);
  //tge_posmp->SetMaximum(200);
  tge_posmp->SetMinimum(0);
  tge_posmp->GetXaxis()->SetLimits(0.0,6.0);
  tge_posmp->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tge_posmp->GetXaxis()->CenterTitle();
  tge_posmp->GetYaxis()->SetTitle("Correction Factor");
  tge_posmp->GetYaxis()->CenterTitle();

  sprintf(figname,"CorrectionFactors/cf_%s_posmp_%d_dis.gif",sectorstring,pid);
  c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cf_%s_posmp_%d_dis.eps",sectorstring,pid);
  c1->Print(figname);

  sprintf(filename,"CorrectionFactors/cf_%s_posmp_%d_dis.dat",sectorstring,pid);
  fout.open(filename);
  for(int i=0; i<100; i++)
    {
      fout<<pt_posmp[i]<<"\t"<<value_posmp[i]<<"\t"<<evalue_posmp[i]<<endl;
    }
  fout.close();



  TGraphErrors *tge_negmp = new TGraphErrors(100,pt_negmp,value_negmp,ept,evalue_negmp);
  tge_negmp->SetMarkerColor(kBlack);
  tge_negmp->SetMarkerStyle(20);
  tge_negmp->Draw("ap");
  tge_negmp->SetMaximum(1000);
  //tge_negmp->SetMaximum(200);
  tge_negmp->SetMinimum(0);
  tge_negmp->GetXaxis()->SetLimits(0.0,6.0);
  tge_negmp->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tge_negmp->GetXaxis()->CenterTitle();
  tge_negmp->GetYaxis()->SetTitle("Correction Factor");
  tge_negmp->GetYaxis()->CenterTitle();

  sprintf(figname,"CorrectionFactors/cf_%s_negmp_%d_dis.gif",sectorstring,pid);
  c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cf_%s_negmp_%d_dis.eps",sectorstring,pid);
  c1->Print(figname);

  sprintf(filename,"CorrectionFactors/cf_%s_negmp_%d_dis.dat",sectorstring,pid);
  fout.open(filename);
  for(int i=0; i<100; i++)
    {
      fout<<pt_negmp[i]<<"\t"<<value_negmp[i]<<"\t"<<evalue_negmp[i]<<endl;
    }
  fout.close();



  c1->Clear();
  TMultiGraph *tmg_pm = new TMultiGraph();
  tge_pospm->SetMarkerStyle(21);
  tge_pospm->SetMarkerColor(kRed);
  tge_negpm->SetMarkerStyle(25);
  tge_negpm->SetMarkerColor(kBlue);
  tmg_pm->Add(tge_pospm);
  tmg_pm->Add(tge_negpm);
  tmg_pm->Draw("ap");
  tmg_pm->SetMaximum(1000);
  //if(pid<2) tmg_pm->SetMaximum(300);
  tmg_pm->SetMinimum(0);
  tmg_pm->GetXaxis()->SetLimits(0.0,6.0);
  tmg_pm->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_pm->GetXaxis()->CenterTitle();
  tmg_pm->GetYaxis()->SetTitle("Correction Factor");
  tmg_pm->GetYaxis()->CenterTitle();
  TLegend *legpm = new TLegend(0.74,0.74,0.88,0.88);
  legpm->SetFillColor(kWhite);
  legpm->SetBorderSize(0);
  if(pid<=3) legpm->AddEntry(tge_pospm,"#pi^{+}","p");
  if(pid<=3) legpm->AddEntry(tge_negpm,"#pi^{-}","p");
  if(pid==4||pid==5) legpm->AddEntry(tge_pospm,"K^{+}","p");
  if(pid==4||pid==5) legpm->AddEntry(tge_negpm,"K^{-}","p");
  if(pid>=6) legpm->AddEntry(tge_pospm,"p","p");
  if(pid>=6) legpm->AddEntry(tge_negpm,"#bar{p}","p");
  legpm->Draw();

  sprintf(figname,"CorrectionFactors/cf_%s_bothpm_%d_dis.gif",sectorstring,pid);
  //c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cf_%s_bothpm_%d_dis.eps",sectorstring,pid);
  //c1->Print(figname);

  c1->Clear();
  TMultiGraph *tmg_mp = new TMultiGraph();
  tge_posmp->SetMarkerStyle(21);
  tge_posmp->SetMarkerColor(kRed);
  tge_negmp->SetMarkerStyle(25);
  tge_negmp->SetMarkerColor(kBlue);
  tmg_mp->Add(tge_posmp);
  tmg_mp->Add(tge_negmp);
  tmg_mp->Draw("ap");
  tmg_mp->SetMaximum(1000);
  //if(pid<2) tmg_mp->SetMaximum(200);
  tmg_mp->SetMinimum(0);
  tmg_mp->GetXaxis()->SetLimits(0.0,6.0);
  tmg_mp->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_mp->GetXaxis()->CenterTitle();
  tmg_mp->GetYaxis()->SetTitle("Correction Factor");
  tmg_mp->GetYaxis()->CenterTitle();
  TLegend *legmp = new TLegend(0.74,0.74,0.88,0.88);
  legmp->SetFillColor(kWhite);
  legmp->SetBorderSize(0);
  if(pid<=3) legmp->AddEntry(tge_posmp,"#pi^{+}","p");
  if(pid<=3) legmp->AddEntry(tge_negmp,"#pi^{-}","p");
  if(pid==4||pid==5) legmp->AddEntry(tge_posmp,"K^{+}","p");
  if(pid==4||pid==5) legmp->AddEntry(tge_negmp,"K^{-}","p");
  if(pid>=6) legmp->AddEntry(tge_posmp,"p","p");
  if(pid>=6) legmp->AddEntry(tge_negmp,"#bar{p}","p");
  legmp->Draw();

  sprintf(figname,"CorrectionFactors/cf_%s_bothmp_%d_dis.gif",sectorstring,pid);
  //c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cf_%s_bothmp_%d_dis.eps",sectorstring,pid);
  //c1->Print(figname);









  c1->Clear();
  TMultiGraph *tmg_gcf = new TMultiGraph();
  tge_pospm->SetMarkerStyle(21);
  tge_pospm->SetMarkerColor(kRed);
  tge_negmp->SetMarkerStyle(25);
  tge_negmp->SetMarkerColor(kBlue);
  tmg_gcf->Add(tge_pospm);
  tmg_gcf->Add(tge_negmp);
  tmg_gcf->Draw("ap");
  tmg_gcf->SetMaximum(1000);
  //if(pid<2) tmg_gcf->SetMaximum(200);
  tmg_gcf->SetMinimum(0);
  tmg_gcf->GetXaxis()->SetLimits(0.0,6.0);
  tmg_gcf->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_gcf->GetXaxis()->CenterTitle();
  tmg_gcf->GetYaxis()->SetTitle("Correction Factor");
  tmg_gcf->GetYaxis()->CenterTitle();
  TLegend *leggcf = new TLegend(0.74,0.74,0.88,0.88);
  leggcf->SetFillColor(kWhite);
  leggcf->SetBorderSize(0);
  if(pid<=3) leggcf->AddEntry(tge_pospm,"#pi^{+}","p");
  if(pid<=3) leggcf->AddEntry(tge_negmp,"#pi^{-}","p");
  if(pid==4||pid==5) leggcf->AddEntry(tge_pospm,"K^{+}","p");
  if(pid==4||pid==5) leggcf->AddEntry(tge_negmp,"K^{-}","p");
  if(pid>=6) leggcf->AddEntry(tge_pospm,"p","p");
  if(pid>=6) leggcf->AddEntry(tge_negmp,"#bar{p}","p");
  legmp->Draw();

  sprintf(figname,"CorrectionFactors/cf_%s_gcf_%d_dis.gif",sectorstring,pid);
  //c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cf_%s_gcf_%d_dis.eps",sectorstring,pid);
  //c1->Print(figname);










  c1->Clear();
  TMultiGraph *tmg_bcf = new TMultiGraph();
  tge_posmp->SetMarkerStyle(21);
  tge_posmp->SetMarkerColor(kRed);
  tge_negpm->SetMarkerStyle(25);
  tge_negpm->SetMarkerColor(kBlue);
  tmg_bcf->Add(tge_posmp);
  tmg_bcf->Add(tge_negpm);
  tmg_bcf->Draw("ap");
  tmg_bcf->SetMaximum(1000);
  //if(pid<2) tmg_bcf->SetMaximum(200);
  tmg_bcf->SetMinimum(0);
  tmg_bcf->GetXaxis()->SetLimits(0.0,6.0);
  tmg_bcf->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_bcf->GetXaxis()->CenterTitle();
  tmg_bcf->GetYaxis()->SetTitle("Correction Factor");
  tmg_bcf->GetYaxis()->CenterTitle();
  TLegend *legbcf = new TLegend(0.74,0.74,0.88,0.88);
  legbcf->SetFillColor(kWhite);
  legbcf->SetBorderSize(0);
  if(pid<=3) legbcf->AddEntry(tge_posmp,"#pi^{+}","p");
  if(pid<=3) legbcf->AddEntry(tge_negpm,"#pi^{-}","p");
  if(pid==4||pid==5) legbcf->AddEntry(tge_posmp,"K^{+}","p");
  if(pid==4||pid==5) legbcf->AddEntry(tge_negpm,"K^{-}","p");
  if(pid>=6) legbcf->AddEntry(tge_posmp,"p","p");
  if(pid>=6) legbcf->AddEntry(tge_negpm,"#bar{p}","p");
  legmp->Draw();

  sprintf(figname,"CorrectionFactors/cf_%s_bcf_%d_dis.gif",sectorstring,pid);
  //c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cf_%s_bcf_%d_dis.eps",sectorstring,pid);
  //c1->Print(figname);



  // ---------------------------------------------------------- //
  // --- you don't have to go home, but you can't stay here --- //
  // ---------------------------------------------------------- //


  // -------------------- //
  // --- 500 MeV part --- //
  // -------------------- //
  // float pt[100], value[100], evalue[100];
  // float ept[100];
  // float pt_pospm[100], value_pospm[100], evalue_pospm[100];
  // float pt_negpm[100], value_negpm[100], evalue_negpm[100];
  // float pt_posmp[100], value_posmp[100], evalue_posmp[100];
  // float pt_negmp[100], value_negmp[100], evalue_negmp[100];
  // float temp, etemp;
  for(int i=0; i<20; i++)
    {
      temp = hR5_sim_tofw_pos_pm->GetBinContent(i+1);
      etemp = hR5_sim_tofw_pos_pm->GetBinError(i+1);
      if(temp>0)
	{
	  value_pospm[i] = 1.0/temp;
	  evalue_pospm[i] = etemp/temp/temp;
	}
      else
	{
	  value_pospm[i] = -9;
	  evalue_pospm[i] = 0;
	}
      pt_pospm[i] = hR5_sim_tofw_pos_pm->GetBinCenter(i+1);
      ept[i]=0;

      temp = hR5_sim_tofw_neg_pm->GetBinContent(i+1);
      etemp = hR5_sim_tofw_neg_pm->GetBinError(i+1);
      if(temp>0)
	{
	  value_negpm[i] = 1.0/temp;
	  evalue_negpm[i] = etemp/temp/temp;
	}
      else
	{
	  value_negpm[i] = -9;
	  evalue_negpm[i] = 0;
	}
      pt_negpm[i] = hR5_sim_tofw_neg_pm->GetBinCenter(i+1);
      ept[i]=0;

      temp = hR5_sim_tofw_pos_mp->GetBinContent(i+1);
      etemp = hR5_sim_tofw_pos_mp->GetBinError(i+1);
      if(temp>0)
	{
	  value_posmp[i] = 1.0/temp;
	  evalue_posmp[i] = etemp/temp/temp;
	}
      else
	{
	  value_posmp[i] = -9;
	  evalue_posmp[i] = 0;
	}
      pt_posmp[i] = hR5_sim_tofw_pos_mp->GetBinCenter(i+1);
      ept[i]=0;

      temp = hR5_sim_tofw_neg_mp->GetBinContent(i+1);
      etemp = hR5_sim_tofw_neg_mp->GetBinError(i+1);
      if(temp>0)
	{
	  value_negmp[i] = 1.0/temp;
	  evalue_negmp[i] = etemp/temp/temp;
	}
      else
	{
	  value_negmp[i] = -9;
	  evalue_negmp[i] = 0;
	}
      pt_negmp[i] = hR5_sim_tofw_neg_mp->GetBinCenter(i+1);
      ept[i]=0;



    }


  // char figname[50];
  // char filename[50];
  // ofstream fout;

  TGraphErrors *tge_pospm = new TGraphErrors(20,pt_pospm,value_pospm,ept,evalue_pospm);
  tge_pospm->SetMarkerColor(kBlack);
  tge_pospm->SetMarkerStyle(20);
  tge_pospm->Draw("ap");
  tge_pospm->SetMaximum(1000);
  //tge_pospm->SetMaximum(200);
  tge_pospm->SetMinimum(0);
  tge_pospm->GetXaxis()->SetLimits(0.0,6.0);
  tge_pospm->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tge_pospm->GetXaxis()->CenterTitle();
  tge_pospm->GetYaxis()->SetTitle("Correction Factor");
  tge_pospm->GetYaxis()->CenterTitle();

  sprintf(figname,"CorrectionFactors/cfR5_%s_pospm_%d_dis.gif",sectorstring,pid);
  c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cfR5_%s_pospm_%d_dis.eps",sectorstring,pid);
  c1->Print(figname);

  sprintf(filename,"CorrectionFactors/cfR5_%s_pospm_%d_dis.dat",sectorstring,pid);
  fout.open(filename);
  for(int i=0; i<100; i++)
    {
      fout<<pt_pospm[i]<<"\t"<<value_pospm[i]<<"\t"<<evalue_pospm[i]<<endl;
    }
  fout.close();


  TGraphErrors *tge_negpm = new TGraphErrors(20,pt_negpm,value_negpm,ept,evalue_negpm);
  tge_negpm->SetMarkerColor(kBlack);
  tge_negpm->SetMarkerStyle(20);
  tge_negpm->Draw("ap");
  tge_negpm->SetMaximum(1000);
  //tge_negpm->SetMaximum(200);
  tge_negpm->SetMinimum(0);
  tge_negpm->GetXaxis()->SetLimits(0.0,6.0);
  tge_negpm->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tge_negpm->GetXaxis()->CenterTitle();
  tge_negpm->GetYaxis()->SetTitle("Correction Factor");
  tge_negpm->GetYaxis()->CenterTitle();

  sprintf(figname,"CorrectionFactors/cfR5_%s_negpm_%d_dis.gif",sectorstring,pid);
  c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cfR5_%s_negpm_%d_dis.eps",sectorstring,pid);
  c1->Print(figname);

  sprintf(filename,"CorrectionFactors/cfR5_%s_negpm_%d_dis.dat",sectorstring,pid);
  fout.open(filename);
  for(int i=0; i<100; i++)
    {
      fout<<pt_negpm[i]<<"\t"<<value_negpm[i]<<"\t"<<evalue_negpm[i]<<endl;
    }
  fout.close();



  TGraphErrors *tge_posmp = new TGraphErrors(20,pt_posmp,value_posmp,ept,evalue_posmp);
  tge_posmp->SetMarkerColor(kBlack);
  tge_posmp->SetMarkerStyle(20);
  tge_posmp->Draw("ap");
  tge_posmp->SetMaximum(1000);
  //tge_posmp->SetMaximum(200);
  tge_posmp->SetMinimum(0);
  tge_posmp->GetXaxis()->SetLimits(0.0,6.0);
  tge_posmp->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tge_posmp->GetXaxis()->CenterTitle();
  tge_posmp->GetYaxis()->SetTitle("Correction Factor");
  tge_posmp->GetYaxis()->CenterTitle();

  sprintf(figname,"CorrectionFactors/cfR5_%s_posmp_%d_dis.gif",sectorstring,pid);
  c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cfR5_%s_posmp_%d_dis.eps",sectorstring,pid);
  c1->Print(figname);

  sprintf(filename,"CorrectionFactors/cfR5_%s_posmp_%d_dis.dat",sectorstring,pid);
  fout.open(filename);
  for(int i=0; i<100; i++)
    {
      fout<<pt_posmp[i]<<"\t"<<value_posmp[i]<<"\t"<<evalue_posmp[i]<<endl;
    }
  fout.close();



  TGraphErrors *tge_negmp = new TGraphErrors(20,pt_negmp,value_negmp,ept,evalue_negmp);
  tge_negmp->SetMarkerColor(kBlack);
  tge_negmp->SetMarkerStyle(20);
  tge_negmp->Draw("ap");
  tge_negmp->SetMaximum(1000);
  //tge_negmp->SetMaximum(200);
  tge_negmp->SetMinimum(0);
  tge_negmp->GetXaxis()->SetLimits(0.0,6.0);
  tge_negmp->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tge_negmp->GetXaxis()->CenterTitle();
  tge_negmp->GetYaxis()->SetTitle("Correction Factor");
  tge_negmp->GetYaxis()->CenterTitle();

  sprintf(figname,"CorrectionFactors/cfR5_%s_negmp_%d_dis.gif",sectorstring,pid);
  c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cfR5_%s_negmp_%d_dis.eps",sectorstring,pid);
  c1->Print(figname);

  sprintf(filename,"CorrectionFactors/cfR5_%s_negmp_%d_dis.dat",sectorstring,pid);
  fout.open(filename);
  for(int i=0; i<100; i++)
    {
      fout<<pt_negmp[i]<<"\t"<<value_negmp[i]<<"\t"<<evalue_negmp[i]<<endl;
    }
  fout.close();



  c1->Clear();
  TMultiGraph *tmg_pm = new TMultiGraph();
  tge_pospm->SetMarkerStyle(21);
  tge_pospm->SetMarkerColor(kRed);
  tge_negpm->SetMarkerStyle(25);
  tge_negpm->SetMarkerColor(kBlue);
  tmg_pm->Add(tge_pospm);
  tmg_pm->Add(tge_negpm);
  tmg_pm->Draw("ap");
  tmg_pm->SetMaximum(1000);
  //if(pid<2) tmg_pm->SetMaximum(300);
  tmg_pm->SetMinimum(0);
  tmg_pm->GetXaxis()->SetLimits(0.0,6.0);
  tmg_pm->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_pm->GetXaxis()->CenterTitle();
  tmg_pm->GetYaxis()->SetTitle("Correction Factor");
  tmg_pm->GetYaxis()->CenterTitle();
  TLegend *legpm = new TLegend(0.74,0.74,0.88,0.88);
  legpm->SetFillColor(kWhite);
  legpm->SetBorderSize(0);
  if(pid<=3) legpm->AddEntry(tge_pospm,"#pi^{+}","p");
  if(pid<=3) legpm->AddEntry(tge_negpm,"#pi^{-}","p");
  if(pid==4||pid==5) legpm->AddEntry(tge_pospm,"K^{+}","p");
  if(pid==4||pid==5) legpm->AddEntry(tge_negpm,"K^{-}","p");
  if(pid>=6) legpm->AddEntry(tge_pospm,"p","p");
  if(pid>=6) legpm->AddEntry(tge_negpm,"#bar{p}","p");
  legpm->Draw();

  sprintf(figname,"CorrectionFactors/cfR5_%s_bothpm_%d_dis.gif",sectorstring,pid);
  //c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cfR5_%s_bothpm_%d_dis.eps",sectorstring,pid);
  //c1->Print(figname);

  c1->Clear();
  TMultiGraph *tmg_mp = new TMultiGraph();
  tge_posmp->SetMarkerStyle(21);
  tge_posmp->SetMarkerColor(kRed);
  tge_negmp->SetMarkerStyle(25);
  tge_negmp->SetMarkerColor(kBlue);
  tmg_mp->Add(tge_posmp);
  tmg_mp->Add(tge_negmp);
  tmg_mp->Draw("ap");
  tmg_mp->SetMaximum(1000);
  //if(pid<2) tmg_mp->SetMaximum(200);
  tmg_mp->SetMinimum(0);
  tmg_mp->GetXaxis()->SetLimits(0.0,6.0);
  tmg_mp->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_mp->GetXaxis()->CenterTitle();
  tmg_mp->GetYaxis()->SetTitle("Correction Factor");
  tmg_mp->GetYaxis()->CenterTitle();
  TLegend *legmp = new TLegend(0.74,0.74,0.88,0.88);
  legmp->SetFillColor(kWhite);
  legmp->SetBorderSize(0);
  if(pid<=3) legmp->AddEntry(tge_posmp,"#pi^{+}","p");
  if(pid<=3) legmp->AddEntry(tge_negmp,"#pi^{-}","p");
  if(pid==4||pid==5) legmp->AddEntry(tge_posmp,"K^{+}","p");
  if(pid==4||pid==5) legmp->AddEntry(tge_negmp,"K^{-}","p");
  if(pid>=6) legmp->AddEntry(tge_posmp,"p","p");
  if(pid>=6) legmp->AddEntry(tge_negmp,"#bar{p}","p");
  legmp->Draw();

  sprintf(figname,"CorrectionFactors/cfR5_%s_bothmp_%d_dis.gif",sectorstring,pid);
  //c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cfR5_%s_bothmp_%d_dis.eps",sectorstring,pid);
  //c1->Print(figname);









  c1->Clear();
  TMultiGraph *tmg_gcf = new TMultiGraph();
  tge_pospm->SetMarkerStyle(21);
  tge_pospm->SetMarkerColor(kRed);
  tge_negmp->SetMarkerStyle(25);
  tge_negmp->SetMarkerColor(kBlue);
  tmg_gcf->Add(tge_pospm);
  tmg_gcf->Add(tge_negmp);
  tmg_gcf->Draw("ap");
  tmg_gcf->SetMaximum(1000);
  //if(pid<2) tmg_gcf->SetMaximum(200);
  tmg_gcf->SetMinimum(0);
  tmg_gcf->GetXaxis()->SetLimits(0.0,6.0);
  tmg_gcf->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_gcf->GetXaxis()->CenterTitle();
  tmg_gcf->GetYaxis()->SetTitle("Correction Factor");
  tmg_gcf->GetYaxis()->CenterTitle();
  TLegend *leggcf = new TLegend(0.74,0.74,0.88,0.88);
  leggcf->SetFillColor(kWhite);
  leggcf->SetBorderSize(0);
  if(pid<=3) leggcf->AddEntry(tge_pospm,"#pi^{+}","p");
  if(pid<=3) leggcf->AddEntry(tge_negmp,"#pi^{-}","p");
  if(pid==4||pid==5) leggcf->AddEntry(tge_pospm,"K^{+}","p");
  if(pid==4||pid==5) leggcf->AddEntry(tge_negmp,"K^{-}","p");
  if(pid>=6) leggcf->AddEntry(tge_pospm,"p","p");
  if(pid>=6) leggcf->AddEntry(tge_negmp,"#bar{p}","p");
  legmp->Draw();

  sprintf(figname,"CorrectionFactors/cfR5_%s_gcfR5_%d_dis.gif",sectorstring,pid);
  //c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cfR5_%s_gcfR5_%d_dis.eps",sectorstring,pid);
  //c1->Print(figname);










  c1->Clear();
  TMultiGraph *tmg_bcf = new TMultiGraph();
  tge_posmp->SetMarkerStyle(21);
  tge_posmp->SetMarkerColor(kRed);
  tge_negpm->SetMarkerStyle(25);
  tge_negpm->SetMarkerColor(kBlue);
  tmg_bcf->Add(tge_posmp);
  tmg_bcf->Add(tge_negpm);
  tmg_bcf->Draw("ap");
  tmg_bcf->SetMaximum(1000);
  //if(pid<2) tmg_bcf->SetMaximum(200);
  tmg_bcf->SetMinimum(0);
  tmg_bcf->GetXaxis()->SetLimits(0.0,6.0);
  tmg_bcf->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_bcf->GetXaxis()->CenterTitle();
  tmg_bcf->GetYaxis()->SetTitle("Correction Factor");
  tmg_bcf->GetYaxis()->CenterTitle();
  TLegend *legbcf = new TLegend(0.74,0.74,0.88,0.88);
  legbcf->SetFillColor(kWhite);
  legbcf->SetBorderSize(0);
  if(pid<=3) legbcf->AddEntry(tge_posmp,"#pi^{+}","p");
  if(pid<=3) legbcf->AddEntry(tge_negpm,"#pi^{-}","p");
  if(pid==4||pid==5) legbcf->AddEntry(tge_posmp,"K^{+}","p");
  if(pid==4||pid==5) legbcf->AddEntry(tge_negpm,"K^{-}","p");
  if(pid>=6) legbcf->AddEntry(tge_posmp,"p","p");
  if(pid>=6) legbcf->AddEntry(tge_negpm,"#bar{p}","p");
  legmp->Draw();

  sprintf(figname,"CorrectionFactors/cfR5_%s_bcfR5_%d_dis.gif",sectorstring,pid);
  //c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cfR5_%s_bcfR5_%d_dis.eps",sectorstring,pid);
  //c1->Print(figname);

  // ---------------------------------------------------------- //
  // --- you don't have to go home, but you can't stay here --- //
  // ---------------------------------------------------------- //


  // ---

  h_sim_tofw_pos_pm->Delete();
  h_sim_tofw_neg_pm->Delete();

  h_sim_tofw_pos_mp->Delete();
  h_sim_tofw_neg_mp->Delete();

  hR5_sim_tofw_pos_pm->Delete();
  hR5_sim_tofw_neg_pm->Delete();

  hR5_sim_tofw_pos_mp->Delete();
  hR5_sim_tofw_neg_mp->Delete();

  // ---

  f_simpion_pm->Close();
  f_simkaon_pm->Close();
  f_simproton_pm->Close();

  f_simpion_mp->Close();
  f_simkaon_mp->Close();
  f_simproton_mp->Close();

  // ---

  f_simpion_pm->Delete();
  f_simkaon_pm->Delete();
  f_simproton_pm->Delete();

  f_simpion_mp->Delete();
  f_simkaon_mp->Delete();
  f_simproton_mp->Delete();

  // now it's over!

}

