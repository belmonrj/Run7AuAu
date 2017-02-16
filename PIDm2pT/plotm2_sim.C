void plotm2_sim()
{

  gStyle->SetOptFit(0);

  //TCanvas *c1 = new TCanvas("c1","",800,600);
  TCanvas *c1 = new TCanvas();
  c1->SetFillColor(kWhite);
  c1->SetBorderMode(0);
  c1->SetFrameFillColor(kWhite);
  c1->SetFrameBorderMode(0);



  float pt[40], ept[40], mean[40], emean[40], sigma[40], esigma[40];

  TF1 *funmean = new TF1("funmean","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.2,4.0);
  TF1 *funsigma = new TF1("funsigma","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.2,4.0);
  TF1 *funline = new TF1("funline","pol0",0.2,4.0);


  // --- pion

  ifstream finpospion("m2mom_pos_pion_par_sim.txt");
  for(int i=0; i<40; i++)
    {
      finpospion>>pt[i]>>mean[i]>>emean[i]>>sigma[i]>>esigma[i];
      ept[i]=0;
      if(emean[i]>0.2) {mean[i]=-9;emean[i]=0;}
      if(esigma[i]>0.2) {sigma[i]=-9;esigma[i]=0;}
    }

  TGraphErrors *tge_pospionmean = new TGraphErrors(40,pt,mean,ept,emean);
  tge_pospionmean->SetMarkerColor(kBlue);
  tge_pospionmean->SetMarkerStyle(20);
  tge_pospionmean->Draw("ap");
  tge_pospionmean->Fit(funmean,"R");
  tge_pospionmean->SetMinimum(0.0);
  tge_pospionmean->SetMaximum(0.025);
  tge_pospionmean->GetXaxis()->SetLimits(0.0,4.2);
  tge_pospionmean->GetXaxis()->SetTitle("p (GeV/c)");
  tge_pospionmean->GetXaxis()->CenterTitle();
  tge_pospionmean->GetYaxis()->SetTitle("#mu_{m^{2}}");
  tge_pospionmean->GetYaxis()->CenterTitle();

  c1->Print("m2mom_pos_pion_mean_sim.gif");
  c1->Print("m2mom_pos_pion_mean_sim.eps");

  TGraphErrors *tge_pospionsigma = new TGraphErrors(40,pt,sigma,ept,esigma);
  tge_pospionsigma->SetMarkerColor(kBlue);
  tge_pospionsigma->SetMarkerStyle(20);
  tge_pospionsigma->Draw("ap");
  tge_pospionsigma->Fit(funsigma,"R");
  tge_pospionsigma->SetMinimum(0.0);
  tge_pospionsigma->SetMaximum(0.2);
  tge_pospionsigma->GetXaxis()->SetLimits(0.0,4.2);
  tge_pospionsigma->GetXaxis()->SetTitle("p (GeV/c)");
  tge_pospionsigma->GetXaxis()->CenterTitle();
  tge_pospionsigma->GetYaxis()->SetTitle("#sigma_{m^{2}}");
  tge_pospionsigma->GetYaxis()->CenterTitle();

  c1->Print("m2mom_pos_pion_sigma_sim.gif");
  c1->Print("m2mom_pos_pion_sigma_sim.eps");

  // ----------------------------------------------------------------------

  // ---  now write to file

  // cout<<"now writing output file for pion pid function pion_pid_sim.C "<<endl;

  // ofstream foutpionpid("pion_pid_sim.C");
  // foutpionpid<<"float isPionLow(float mom, float m2tofw)\n{\n"
  // 	     <<"float x = mom;\n"
  // 	     <<"float a0 = "<<funmean->GetParameter(0)<<";\n"
  // 	     <<"float a1 = "<<funmean->GetParameter(1)<<";\n"
  // 	     <<"float a2 = "<<funmean->GetParameter(2)<<";\n"
  // 	     <<"float a3 = "<<funmean->GetParameter(3)<<";\n"
  // 	     <<"float a4 = "<<funmean->GetParameter(4)<<";\n"
  // 	     <<"float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);\n"
  // 	     <<"float b0 = "<<funsigma->GetParameter(0)<<";\n"
  // 	     <<"float b1 = "<<funsigma->GetParameter(1)<<";\n"
  // 	     <<"float b2 = "<<funsigma->GetParameter(2)<<";\n"
  // 	     <<"float b3 = "<<funsigma->GetParameter(3)<<";\n"
  // 	     <<"float b4 = "<<funsigma->GetParameter(4)<<";\n"
  // 	     <<"float sigma = b0+b1/x+b2/x/x+b3*exp(sqrt(x))+b4*sqrt(x);\n"
  // 	     <<"return (m2tofw - mean)/sigma;\n}\n"<<endl;

  // cout<<"done writing out pion pid function"<<endl;

  // ----------------------------------------------------------------------



  ifstream finnegpion("m2mom_neg_pion_par_sim.txt");
  for(int i=0; i<40; i++)
    {
      finnegpion>>pt[i]>>mean[i]>>emean[i]>>sigma[i]>>esigma[i];
      ept[i]=0;
      if(emean[i]>0.2) {mean[i]=-9;emean[i]=0;}
      if(esigma[i]>0.2) {sigma[i]=-9;esigma[i]=0;}
    }

  TGraphErrors *tge_negpionmean = new TGraphErrors(40,pt,mean,ept,emean);
  tge_negpionmean->SetMarkerColor(kBlue);
  tge_negpionmean->SetMarkerStyle(24);
  tge_negpionmean->Draw("ap");
  tge_negpionmean->Fit(funmean,"R");
  tge_negpionmean->SetMinimum(0.0);
  tge_negpionmean->SetMaximum(0.025);
  tge_negpionmean->GetXaxis()->SetLimits(0.0,4.2);
  tge_negpionmean->GetXaxis()->SetTitle("p (GeV/c)");
  tge_negpionmean->GetXaxis()->CenterTitle();
  tge_negpionmean->GetYaxis()->SetTitle("#mu_{m^{2}}");
  tge_negpionmean->GetYaxis()->CenterTitle();

  c1->Print("m2mom_neg_pion_mean_sim.gif");
  c1->Print("m2mom_neg_pion_mean_sim.eps");

  TGraphErrors *tge_negpionsigma = new TGraphErrors(40,pt,sigma,ept,esigma);
  tge_negpionsigma->SetMarkerColor(kBlue);
  tge_negpionsigma->SetMarkerStyle(24);
  tge_negpionsigma->Draw("ap");
  tge_negpionsigma->Fit(funsigma,"R");
  tge_negpionsigma->SetMinimum(0.0);
  tge_negpionsigma->SetMaximum(0.2);
  tge_negpionsigma->GetXaxis()->SetLimits(0.0,4.2);
  tge_negpionsigma->GetXaxis()->SetTitle("p (GeV/c)");
  tge_negpionsigma->GetXaxis()->CenterTitle();
  tge_negpionsigma->GetYaxis()->SetTitle("#sigma_{m^{2}}");
  tge_negpionsigma->GetYaxis()->CenterTitle();

  c1->Print("m2mom_neg_pion_sigma_sim.gif");
  c1->Print("m2mom_neg_pion_sigma_sim.eps");


  // --- drawn together :)

  c1->Clear();

  TMultiGraph *tmg_mean = new TMultiGraph();
  tmg_mean->Add(tge_pospionmean);
  tmg_mean->Add(tge_negpionmean);
  tmg_mean->Draw("ap");
  tmg_mean->SetMinimum(-0.1);
  tmg_mean->SetMaximum(0.4);
  tmg_mean->GetXaxis()->SetLimits(0.0,4.2);
  tmg_mean->GetXaxis()->SetTitle("p (GeV/c)");
  tmg_mean->GetXaxis()->CenterTitle();
  tmg_mean->GetYaxis()->SetTitle("#mu_{m^{2}}");
  tmg_mean->GetYaxis()->CenterTitle();

  c1->Print("m2mom_together_mean_sim.gif");
  c1->Print("m2mom_together_mean_sim.eps");

  c1->Clear();

  TMultiGraph *tmg_sigma = new TMultiGraph();
  tmg_sigma->Add(tge_pospionsigma);
  tmg_sigma->Add(tge_negpionsigma);
  tmg_sigma->Draw("ap");
  tmg_sigma->SetMinimum(0.0);
  tmg_sigma->SetMaximum(0.2);
  tmg_sigma->GetXaxis()->SetLimits(0.0,4.2);
  tmg_sigma->GetXaxis()->SetTitle("p (GeV/c)");
  tmg_sigma->GetXaxis()->CenterTitle();
  tmg_sigma->GetYaxis()->SetTitle("#sigma_{m^{2}}");
  tmg_sigma->GetYaxis()->CenterTitle();

  c1->Print("m2mom_together_sigma_sim.gif");
  c1->Print("m2mom_together_sigma_sim.eps");




}
