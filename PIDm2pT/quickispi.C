void quickispi()
{

  TCanvas *c1 = new TCanvas();
  c1->SetFillColor(kWhite);
  c1->SetBorderMode(0);
  c1->SetFrameFillColor(kWhite);
  c1->SetFrameBorderMode(0);
  c1->SetGridx(1);
  c1->SetGridy(1);

  TFile *file = TFile::Open("outlowpm.root");

  TH2F *ispiposmom = (TH2F *)file->Get("isPi_dis_pos");
  TH2F *ispinegmom = (TH2F *)file->Get("isPi_dis_neg");

  char gifnamepos[100];
  char epsnamepos[100];
  char gifnameneg[100];
  char epsnameneg[100];

  TF1 *fungauspos = new TF1("fungauspos","gaus",-5,5);
  TF1 *fungausneg = new TF1("fungausneg","gaus",-5,5);

  float ptpos[20], meanpos[20], sigmapos[20], eptpos[20], emeanpos[20], esigmapos[20];
  float ptneg[20], meanneg[20], sigmaneg[20], eptneg[20], emeanneg[20], esigmaneg[20];

  float pt[20], ept[20];

  for(int i=0; i<20; i++)
    {

      pt[i] = i/10.0 + 0.05;
      ept[i]=0;

      ispiposmom->ProjectionY("hhpos",i+1,i+1);
      hhpos->Draw();
      //hhpos->Fit("gaus","","",-2,2);
      hhpos->Fit("fungauspos","","",-1,1);
      sprintf(gifnamepos,"hh_ispipos_mom_%d.gif",i);
      sprintf(epsnamepos,"hh_ispipos_mom_%d.eps",i);
      c1->Print(gifnamepos);
      c1->Print(epsnamepos);

      ispinegmom->ProjectionY("hhneg",i+1,i+1);
      hhneg->Draw();
      //hhneg->Fit("gaus","","",-2,2);
      hhneg->Fit("fungausneg","","",-1,1);
      sprintf(gifnameneg,"hh_ispineg_mom_%d.gif",i);
      sprintf(epsnameneg,"hh_ispineg_mom_%d.eps",i);
      c1->Print(gifnameneg);
      c1->Print(epsnameneg);

      meanpos[i] = fungauspos->GetParameter(1);
      emeanpos[i] = fungauspos->GetParError(1);
      meanneg[i] = fungausneg->GetParameter(1);
      emeanneg[i] = fungausneg->GetParError(1);
      sigmapos[i] = fungauspos->GetParameter(2);
      esigmapos[i] = fungauspos->GetParError(2);
      sigmaneg[i] = fungausneg->GetParameter(2);
      esigmaneg[i] = fungausneg->GetParError(2);

    }

  c1->Clear();

  TGraphErrors *tge_meanpos = new TGraphErrors(20,pt,meanpos,ept,emeanpos);
  tge_meanpos->SetMarkerColor(kRed);
  tge_meanpos->SetMarkerStyle(21);
  TGraphErrors *tge_sigmapos = new TGraphErrors(20,pt,sigmapos,ept,esigmapos);
  tge_sigmapos->SetMarkerColor(kRed);
  tge_sigmapos->SetMarkerStyle(21);
  TGraphErrors *tge_meanneg = new TGraphErrors(20,pt,meanneg,ept,emeanneg);
  tge_meanneg->SetMarkerColor(kBlue);
  tge_meanneg->SetMarkerStyle(21);
  TGraphErrors *tge_sigmaneg = new TGraphErrors(20,pt,sigmaneg,ept,esigmaneg);
  tge_sigmaneg->SetMarkerColor(kBlue);
  tge_sigmaneg->SetMarkerStyle(21);

  TMultiGraph *tmg_mean = new TMultiGraph();
  tmg_mean->Add(tge_meanpos);
  tmg_mean->Add(tge_meanneg);
  tmg_mean->Draw("AP");
  tmg_mean->SetMaximum(0.25);
  tmg_mean->SetMinimum(-0.25);
  tmg_mean->GetXaxis()->SetLimits(0.2,2.0);
  tmg_mean->GetXaxis()->SetTitle("mom (GeV/c)");
  tmg_mean->GetXaxis()->CenterTitle();
  tmg_mean->GetYaxis()->SetTitle("mean");
  tmg_mean->GetYaxis()->CenterTitle();
  c1->Print("plot_ispi_mean.gif");
  c1->Print("plot_ispi_mean.eps");

  c1->Clear();

  TMultiGraph *tmg_sigma = new TMultiGraph();
  tmg_sigma->Add(tge_sigmapos);
  tmg_sigma->Add(tge_sigmaneg);
  tmg_sigma->Draw("AP");
  tmg_sigma->SetMaximum(1.5);
  tmg_sigma->SetMinimum(0.0);
  tmg_sigma->GetXaxis()->SetLimits(0.2,2.0);
  tmg_sigma->GetXaxis()->SetLimits(0.2,2.0);
  tmg_sigma->GetXaxis()->SetTitle("mom (GeV/c)");
  tmg_sigma->GetXaxis()->CenterTitle();
  tmg_sigma->GetYaxis()->SetTitle("sigma");
  tmg_sigma->GetYaxis()->CenterTitle();
  c1->Print("plot_ispi_sigma.gif");
  c1->Print("plot_ispi_sigma.eps");

}
