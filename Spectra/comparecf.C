void comparecf()
{

  cout<<"hello and welcome!"<<endl;


  // for(int isec=0; isec<3; isec++)
  //   {
  //     doit(isec);
  //   }
  doit(0);
  



  cout<<"all done!  i hope you have a great day!"<<endl;

}

//void doit(int sector=0, int pid=0, int centid=0)
void doit(int sector=0)
{

  // TCanvas used for printing diagnostic figures
  TCanvas *c1 = new TCanvas("c1","c1",800,600);
  c1->SetFillColor(kWhite);
  c1->SetFrameFillColor(kWhite);
  c1->SetBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->SetLogy();



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


  // --- now pion

  //int pid = 0;
  int pid = 2;

  char name_simpion_tofw_pos_pm[50];
  char name_simpion_tofw_neg_pm[50];
  char name_simpion_tofw_pos_mp[50];
  char name_simpion_tofw_neg_mp[50];

  sprintf(name_simpion_tofw_pos_pm,"ptpid_%s_pos_%d_dis",sectorstring,pid);
  sprintf(name_simpion_tofw_neg_pm,"ptpid_%s_neg_%d_dis",sectorstring,pid);
  sprintf(name_simpion_tofw_pos_mp,"ptpid_%s_pos_%d_dis",sectorstring,pid);
  sprintf(name_simpion_tofw_neg_mp,"ptpid_%s_neg_%d_dis",sectorstring,pid);

  TH1F *h_simpion_tofw_pos_pm = f_simpion_pm->Get(name_simpion_tofw_pos_pm);
  TH1F *h_simpion_tofw_neg_pm = f_simpion_pm->Get(name_simpion_tofw_neg_pm);
  TH1F *h_simpion_tofw_pos_mp = f_simpion_mp->Get(name_simpion_tofw_pos_mp);
  TH1F *h_simpion_tofw_neg_mp = f_simpion_mp->Get(name_simpion_tofw_neg_mp);

  h_simpion_tofw_pos_pm->Sumw2();
  h_simpion_tofw_neg_pm->Sumw2();
  h_simpion_tofw_pos_mp->Sumw2();
  h_simpion_tofw_neg_mp->Sumw2();

  // --- now kaon

  //pid = 4;
  pid = 5;

  char name_simkaon_tofw_pos_pm[50];
  char name_simkaon_tofw_neg_pm[50];
  char name_simkaon_tofw_pos_mp[50];
  char name_simkaon_tofw_neg_mp[50];

  sprintf(name_simkaon_tofw_pos_pm,"ptpid_%s_pos_%d_dis",sectorstring,pid);
  sprintf(name_simkaon_tofw_neg_pm,"ptpid_%s_neg_%d_dis",sectorstring,pid);
  sprintf(name_simkaon_tofw_pos_mp,"ptpid_%s_pos_%d_dis",sectorstring,pid);
  sprintf(name_simkaon_tofw_neg_mp,"ptpid_%s_neg_%d_dis",sectorstring,pid);

  TH1F *h_simkaon_tofw_pos_pm = f_simkaon_pm->Get(name_simkaon_tofw_pos_pm);
  TH1F *h_simkaon_tofw_neg_pm = f_simkaon_pm->Get(name_simkaon_tofw_neg_pm);
  TH1F *h_simkaon_tofw_pos_mp = f_simkaon_mp->Get(name_simkaon_tofw_pos_mp);
  TH1F *h_simkaon_tofw_neg_mp = f_simkaon_mp->Get(name_simkaon_tofw_neg_mp);

  h_simkaon_tofw_pos_pm->Sumw2();
  h_simkaon_tofw_neg_pm->Sumw2();
  h_simkaon_tofw_pos_mp->Sumw2();
  h_simkaon_tofw_neg_mp->Sumw2();

  // --- now proton

  //pid = 6;
  pid = 8;

  char name_simproton_tofw_pos_pm[50];
  char name_simproton_tofw_neg_pm[50];
  char name_simproton_tofw_pos_mp[50];
  char name_simproton_tofw_neg_mp[50];

  sprintf(name_simproton_tofw_pos_pm,"ptpid_%s_pos_%d_dis",sectorstring,pid);
  sprintf(name_simproton_tofw_neg_pm,"ptpid_%s_neg_%d_dis",sectorstring,pid);
  sprintf(name_simproton_tofw_pos_mp,"ptpid_%s_pos_%d_dis",sectorstring,pid);
  sprintf(name_simproton_tofw_neg_mp,"ptpid_%s_neg_%d_dis",sectorstring,pid);

  TH1F *h_simproton_tofw_pos_pm = f_simproton_pm->Get(name_simproton_tofw_pos_pm);
  TH1F *h_simproton_tofw_neg_pm = f_simproton_pm->Get(name_simproton_tofw_neg_pm);
  TH1F *h_simproton_tofw_pos_mp = f_simproton_mp->Get(name_simproton_tofw_pos_mp);
  TH1F *h_simproton_tofw_neg_mp = f_simproton_mp->Get(name_simproton_tofw_neg_mp);

  h_simproton_tofw_pos_pm->Sumw2();
  h_simproton_tofw_neg_pm->Sumw2();
  h_simproton_tofw_pos_mp->Sumw2();
  h_simproton_tofw_neg_mp->Sumw2();


  // -------------------- //
  // --- NEW STUFF!!! --- //
  // -------------------- //

  TH2F *hh = new TH2F("hh","",1,0.0,10.0,1,0.0,1.2);

  TLine *line = new TLine(0.0,1.0,10.0,1.0);
  line->SetLineWidth(2);

  TH1F *hpion1 = (TH1F *)h_simpion_tofw_pos_pm->Clone();
  TH1F *hpion2 = (TH1F *)h_simpion_tofw_pos_pm->Clone();
  TH1F *hkaon = (TH1F *)h_simkaon_tofw_pos_pm->Clone();
  TH1F *hproton = (TH1F *)h_simproton_tofw_pos_pm->Clone();

  c1->SetLogy(0);

  hkaon->Divide(hpion1);
  hh->Draw();
  hkaon->Draw("same");
  line->Draw("same");
  c1->Print("CorrectionFactors/simple_kop.gif");
  c1->Print("CorrectionFactors/simple_kop.eps");

  hproton->Divide(hpion2);
  hh->Draw();
  hproton->Draw("same");
  line->Draw("same");
  c1->Print("CorrectionFactors/simple_pop.gif");
  c1->Print("CorrectionFactors/simple_pop.eps");

  c1->SetLogy();

  

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

  h_simpion_tofw_pos_pm->Divide(dummy,simconst);
  h_simpion_tofw_neg_pm->Divide(dummy,simconst);
  h_simpion_tofw_pos_mp->Divide(dummy,simconst);
  h_simpion_tofw_neg_mp->Divide(dummy,simconst);

  h_simkaon_tofw_pos_pm->Divide(dummy,simconst);
  h_simkaon_tofw_neg_pm->Divide(dummy,simconst);
  h_simkaon_tofw_pos_mp->Divide(dummy,simconst);
  h_simkaon_tofw_neg_mp->Divide(dummy,simconst);

  h_simproton_tofw_pos_pm->Divide(dummy,simconst);
  h_simproton_tofw_neg_pm->Divide(dummy,simconst);
  h_simproton_tofw_pos_mp->Divide(dummy,simconst);
  h_simproton_tofw_neg_mp->Divide(dummy,simconst);




  float pt[100], value[100], evalue[100];
  float ept[100];
  float pt_pospm[100], value_pospm[100], evalue_pospm[100];
  float pt_negpm[100], value_negpm[100], evalue_negpm[100];
  float pt_posmp[100], value_posmp[100], evalue_posmp[100];
  float pt_negmp[100], value_negmp[100], evalue_negmp[100];
  float temp, etemp;
  // --- now pion
  for(int i=0; i<100; i++)
    {
      // --- now pospm
      temp = h_simpion_tofw_pos_pm->GetBinContent(i+1);
      etemp = h_simpion_tofw_pos_pm->GetBinError(i+1);
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
      pt_pospm[i] = h_simpion_tofw_pos_pm->GetBinCenter(i+1);
      ept[i]=0;
      // --- now negpm
      temp = h_simpion_tofw_neg_pm->GetBinContent(i+1);
      etemp = h_simpion_tofw_neg_pm->GetBinError(i+1);
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
      pt_negpm[i] = h_simpion_tofw_neg_pm->GetBinCenter(i+1);
      ept[i]=0;
      // --- now posmp
      temp = h_simpion_tofw_pos_mp->GetBinContent(i+1);
      etemp = h_simpion_tofw_pos_mp->GetBinError(i+1);
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
      pt_posmp[i] = h_simpion_tofw_pos_mp->GetBinCenter(i+1);
      ept[i]=0;
      // --- now negmp
      temp = h_simpion_tofw_neg_mp->GetBinContent(i+1);
      etemp = h_simpion_tofw_neg_mp->GetBinError(i+1);
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
      pt_negmp[i] = h_simpion_tofw_neg_mp->GetBinCenter(i+1);
      ept[i]=0;
    }
  TGraphErrors *tgepion_pospm = new TGraphErrors(100,pt_pospm,value_pospm,ept,evalue_pospm);
  tgepion_pospm->SetMarkerColor(kBlack);
  tgepion_pospm->SetMarkerStyle(20);
  TGraphErrors *tgepion_negpm = new TGraphErrors(100,pt_negpm,value_negpm,ept,evalue_negpm);
  tgepion_negpm->SetMarkerColor(kBlack);
  tgepion_negpm->SetMarkerStyle(20);
  TGraphErrors *tgepion_posmp = new TGraphErrors(100,pt_posmp,value_posmp,ept,evalue_posmp);
  tgepion_posmp->SetMarkerColor(kBlack);
  tgepion_posmp->SetMarkerStyle(20);
  TGraphErrors *tgepion_negmp = new TGraphErrors(100,pt_negmp,value_negmp,ept,evalue_negmp);
  tgepion_negmp->SetMarkerColor(kBlack);
  tgepion_negmp->SetMarkerStyle(20);
  // --- now kaon
  for(int i=0; i<100; i++)
    {
      // --- now pospm
      temp = h_simkaon_tofw_pos_pm->GetBinContent(i+1);
      etemp = h_simkaon_tofw_pos_pm->GetBinError(i+1);
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
      pt_pospm[i] = h_simkaon_tofw_pos_pm->GetBinCenter(i+1);
      ept[i]=0;
      // --- now negpm
      temp = h_simkaon_tofw_neg_pm->GetBinContent(i+1);
      etemp = h_simkaon_tofw_neg_pm->GetBinError(i+1);
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
      pt_negpm[i] = h_simkaon_tofw_neg_pm->GetBinCenter(i+1);
      ept[i]=0;
      // --- now posmp
      temp = h_simkaon_tofw_pos_mp->GetBinContent(i+1);
      etemp = h_simkaon_tofw_pos_mp->GetBinError(i+1);
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
      pt_posmp[i] = h_simkaon_tofw_pos_mp->GetBinCenter(i+1);
      ept[i]=0;
      // --- now negmp
      temp = h_simkaon_tofw_neg_mp->GetBinContent(i+1);
      etemp = h_simkaon_tofw_neg_mp->GetBinError(i+1);
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
      pt_negmp[i] = h_simkaon_tofw_neg_mp->GetBinCenter(i+1);
      ept[i]=0;
    }
  TGraphErrors *tgekaon_pospm = new TGraphErrors(100,pt_pospm,value_pospm,ept,evalue_pospm);
  tgekaon_pospm->SetMarkerColor(kBlack);
  tgekaon_pospm->SetMarkerStyle(20);
  TGraphErrors *tgekaon_negpm = new TGraphErrors(100,pt_negpm,value_negpm,ept,evalue_negpm);
  tgekaon_negpm->SetMarkerColor(kBlack);
  tgekaon_negpm->SetMarkerStyle(20);
  TGraphErrors *tgekaon_posmp = new TGraphErrors(100,pt_posmp,value_posmp,ept,evalue_posmp);
  tgekaon_posmp->SetMarkerColor(kBlack);
  tgekaon_posmp->SetMarkerStyle(20);
  TGraphErrors *tgekaon_negmp = new TGraphErrors(100,pt_negmp,value_negmp,ept,evalue_negmp);
  tgekaon_negmp->SetMarkerColor(kBlack);
  tgekaon_negmp->SetMarkerStyle(20);
  // --- now proton
  for(int i=0; i<100; i++)
    {
      // --- now pospm
      temp = h_simproton_tofw_pos_pm->GetBinContent(i+1);
      etemp = h_simproton_tofw_pos_pm->GetBinError(i+1);
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
      pt_pospm[i] = h_simproton_tofw_pos_pm->GetBinCenter(i+1);
      ept[i]=0;
      // --- now negpm
      temp = h_simproton_tofw_neg_pm->GetBinContent(i+1);
      etemp = h_simproton_tofw_neg_pm->GetBinError(i+1);
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
      pt_negpm[i] = h_simproton_tofw_neg_pm->GetBinCenter(i+1);
      ept[i]=0;
      // --- now posmp
      temp = h_simproton_tofw_pos_mp->GetBinContent(i+1);
      etemp = h_simproton_tofw_pos_mp->GetBinError(i+1);
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
      pt_posmp[i] = h_simproton_tofw_pos_mp->GetBinCenter(i+1);
      ept[i]=0;
      // --- now negmp
      temp = h_simproton_tofw_neg_mp->GetBinContent(i+1);
      etemp = h_simproton_tofw_neg_mp->GetBinError(i+1);
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
      pt_negmp[i] = h_simproton_tofw_neg_mp->GetBinCenter(i+1);
      ept[i]=0;
    }
  TGraphErrors *tgeproton_pospm = new TGraphErrors(100,pt_pospm,value_pospm,ept,evalue_pospm);
  tgeproton_pospm->SetMarkerColor(kBlack);
  tgeproton_pospm->SetMarkerStyle(20);
  TGraphErrors *tgeproton_negpm = new TGraphErrors(100,pt_negpm,value_negpm,ept,evalue_negpm);
  tgeproton_negpm->SetMarkerColor(kBlack);
  tgeproton_negpm->SetMarkerStyle(20);
  TGraphErrors *tgeproton_posmp = new TGraphErrors(100,pt_posmp,value_posmp,ept,evalue_posmp);
  tgeproton_posmp->SetMarkerColor(kBlack);
  tgeproton_posmp->SetMarkerStyle(20);
  TGraphErrors *tgeproton_negmp = new TGraphErrors(100,pt_negmp,value_negmp,ept,evalue_negmp);
  tgeproton_negmp->SetMarkerColor(kBlack);
  tgeproton_negmp->SetMarkerStyle(20);













  c1->Clear();
  TMultiGraph *tmg_pospm = new TMultiGraph();
  tgepion_pospm->SetMarkerStyle(20);
  tgepion_pospm->SetMarkerColor(kBlue);
  tgekaon_pospm->SetMarkerStyle(22);
  tgekaon_pospm->SetMarkerColor(kGreen+2);
  tgeproton_pospm->SetMarkerStyle(21);
  tgeproton_pospm->SetMarkerColor(kRed);
  tmg_pospm->Add(tgepion_pospm);
  tmg_pospm->Add(tgekaon_pospm);
  tmg_pospm->Add(tgeproton_pospm);
  tmg_pospm->Draw("ap");
  //tmg_pospm->SetMaximum(1000);
  //tmg_pospm->SetMinimum(0);
  tmg_pospm->SetMaximum(1e6);
  tmg_pospm->SetMinimum(1e1);
  tmg_pospm->GetXaxis()->SetLimits(0.0,6.0);
  tmg_pospm->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_pospm->GetXaxis()->CenterTitle();
  tmg_pospm->GetYaxis()->SetTitle("Correction Factor");
  tmg_pospm->GetYaxis()->CenterTitle();
  TLegend *legpospm = new TLegend(0.74,0.74,0.88,0.88);
  legpospm->SetFillColor(kWhite);
  legpospm->SetBorderSize(0);
  legpospm->AddEntry(tgepion_pospm,"#pi^{+}","p");
  legpospm->AddEntry(tgekaon_pospm,"K^{+}","p");
  legpospm->AddEntry(tgeproton_pospm,"p","p");
  legpospm->Draw();

  char figname[150];
  sprintf(figname,"CorrectionFactors/cf_pikp_%s_pospm_%d_dis_LOG.gif",sectorstring,pid);
  c1->Print(figname);
  sprintf(figname,"CorrectionFactors/cf_pikp_%s_pospm_%d_dis_LOG.eps",sectorstring,pid);
  c1->Print(figname);

  c1->Clear();
  c1->SetLogy(0);
  tmg_pospm->Draw("ap");
  //tmg_pospm->SetMaximum(1000);
  tmg_pospm->SetMaximum(500);
  tmg_pospm->SetMinimum(0);
  legpospm->Draw();

  char figname2[150];

  sprintf(figname2,"CorrectionFactors/cf_pikp_%s_pospm_%d_dis_LIN.gif",sectorstring,pid);
  c1->Print(figname2);
  sprintf(figname2,"CorrectionFactors/cf_pikp_%s_pospm_%d_dis_LIN.eps",sectorstring,pid);
  c1->Print(figname2);



  // ---------------------------------------------------------- //
  // --- you don't have to go home, but you can't stay here --- //
  // ---------------------------------------------------------- //

  // c1->Clear();
  // tmg_pospm->Delete();
  // legpospm->Delete();
  // //c1->Delete();

  // // ---

  // h_simpion_tofw_pos_pm->Delete();
  // h_simpion_tofw_neg_pm->Delete();
  // h_simpion_tofw_pos_mp->Delete();
  // h_simpion_tofw_neg_mp->Delete();

  // h_simkaon_tofw_pos_pm->Delete();
  // h_simkaon_tofw_neg_pm->Delete();
  // h_simkaon_tofw_pos_mp->Delete();
  // h_simkaon_tofw_neg_mp->Delete();

  // h_simproton_tofw_pos_pm->Delete();
  // h_simproton_tofw_neg_pm->Delete();
  // h_simproton_tofw_pos_mp->Delete();
  // h_simproton_tofw_neg_mp->Delete();

  // // ---

  // f_simpion_pm->Close();
  // f_simkaon_pm->Close();
  // f_simproton_pm->Close();

  // f_simpion_mp->Close();
  // f_simkaon_mp->Close();
  // f_simproton_mp->Close();

  // // ---

  // f_simpion_pm->Delete();
  // f_simkaon_pm->Delete();
  // f_simproton_pm->Delete();

  // f_simpion_mp->Delete();
  // f_simkaon_mp->Delete();
  // f_simproton_mp->Delete();

  // now it's over!

}

