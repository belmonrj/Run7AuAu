void plotm2_proton()
{

  TF1 *shenglisigmapi = new TF1("shenglisigmapi","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.2,4.0);
  TF1 *shenglisigmaka = new TF1("shenglisigmaka","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.2,4.0);
  TF1 *shenglisigmapr = new TF1("shenglisigmapr","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.5,4.0);

  shenglisigmapi->SetParameter(0, 1.03401e-02);
  shenglisigmapi->SetParameter(1,-1.76120e-02);
  shenglisigmapi->SetParameter(2, 2.91334e-03);
  shenglisigmapi->SetParameter(3, 6.48013e-02);
  shenglisigmapi->SetParameter(4,-1.60995e-01);
  
  shenglisigmaka->SetParameter(0, 1.75872e-02);  
  shenglisigmaka->SetParameter(1,-2.08889e-02);
  shenglisigmaka->SetParameter(2, 4.16566e-03);
  shenglisigmaka->SetParameter(3, 6.34606e-02); 
  shenglisigmaka->SetParameter(4,-1.58898e-01); 

  shenglisigmapr->SetParameter(0,-6.19317e-03);  
  shenglisigmapr->SetParameter(1, 9.01921e-03);
  shenglisigmapr->SetParameter(2, 6.82347e-04);
  shenglisigmapr->SetParameter(3, 6.07866e-02);
  shenglisigmapr->SetParameter(4,-1.32903e-01);

  shenglisigmapi->SetLineStyle(2);
  shenglisigmaka->SetLineStyle(2);
  shenglisigmapr->SetLineStyle(2);

  TF1 *pdgmasspi = new TF1("pdgmasspi","pol0",0.0,4.2);
  pdgmasspi->SetParameter(0,0.01948);
  TF1 *pdgmasska = new TF1("pdgmasska","pol0",0.0,4.2);
  pdgmasska->SetParameter(0,0.24332);
  TF1 *pdgmasspr = new TF1("pdgmasspr","pol0",0.0,6.2);
  pdgmasspr->SetParameter(0,0.88035);

  pdgmasspi->SetLineWidth(0);
  pdgmasska->SetLineWidth(0);
  pdgmasspr->SetLineWidth(0);

  //funpion->FixParameter(1,0.01948);
  //funkaon->FixParameter(1,0.24332);
  //pr0.88035

  gStyle->SetOptFit(0);

  //TCanvas *c1 = new TCanvas("c1","",800,600);
  TCanvas *c1 = new TCanvas();
  c1->SetFillColor(kWhite);
  c1->SetBorderMode(0);
  c1->SetFrameFillColor(kWhite);
  c1->SetFrameBorderMode(0);



  float pt[50], ept[50], mean[50], emean[50], sigma[50], esigma[50];


  TF1 *funmean = new TF1("funmean","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.2,5.0);
  TF1 *funmeanpi = new TF1("funmeanpi","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.2,5.0);
  TF1 *funmeanka = new TF1("funmeanka","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.2,5.0);
  TF1 *funmeanpr = new TF1("funmeanpr","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.5,6.0);
  //TF1 *funmeanpr = new TF1("funmeanpr","[0]+[1]/x+[2]/x/x+[3]*sqrt(x)",0.4,5.0);

  TF1 *funsigma = new TF1("funsigma","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.2,5.0);
  TF1 *funsigmapi = new TF1("funsigmapi","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.2,5.0);
  TF1 *funsigmaka = new TF1("funsigmaka","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.2,5.0);
  TF1 *funsigmapr = new TF1("funsigmapr","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.5,5.0);

  TF1 *funline = new TF1("funline","pol0",0.2,5.0);
  TF1 *funlinepi = new TF1("funlinepi","pol0",0.2,5.0);
  TF1 *funlineka = new TF1("funlineka","pol0",0.3,5.0);
  TF1 *funlinepr = new TF1("funlinepr","pol0",0.5,5.0);




  // ----------------------------
  // --- now do both charges together


  // --- proton

  ifstream finbothproton("m2pT_both_proton_par.txt");
  for(int i=0; i<50; i++)
    {
      finbothproton>>pt[i]>>mean[i]>>emean[i]>>sigma[i]>>esigma[i];
      ept[i]=0;
      if(emean[i]>0.1) {mean[i]=-9;emean[i]=0;}
      if(esigma[i]>0.1) {sigma[i]=-9;esigma[i]=0;}
    }

  TGraphErrors *tge_bothprotonmean = new TGraphErrors(50,pt,mean,ept,emean);
  tge_bothprotonmean->SetMarkerColor(kRed);
  tge_bothprotonmean->SetMarkerStyle(21);
  tge_bothprotonmean->Draw("ap");
  //tge_bothprotonmean->Fit(funmeanpr,"R");
  tge_bothprotonmean->Fit(funmeanpr,"","",0.5,4.0);
  funmeanpr->Draw("same");
  pdgmasspr->Draw("same");
  tge_bothprotonmean->SetMinimum(0.6);
  tge_bothprotonmean->SetMaximum(1.0);
  tge_bothprotonmean->GetXaxis()->SetLimits(0.0,6.2);
  tge_bothprotonmean->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tge_bothprotonmean->GetXaxis()->CenterTitle();
  tge_bothprotonmean->GetYaxis()->SetTitle("#mu_{m^{2}}");
  tge_bothprotonmean->GetYaxis()->CenterTitle();

  c1->Print("m2pT_both_proton_mean_FIVE.gif");
  c1->Print("m2pT_both_proton_mean_FIVE.eps");

  TGraphErrors *tge_bothprotonsigma = new TGraphErrors(50,pt,sigma,ept,esigma);
  tge_bothprotonsigma->SetMarkerColor(kRed);
  tge_bothprotonsigma->SetMarkerStyle(21);
  tge_bothprotonsigma->Draw("ap");
  tge_bothprotonsigma->Fit(funsigmapr,"R");
  //tge_bothprotonsigma->Fit(funsigma,"R");
  //tge_bothprotonsigma->Fit(funsigma,"","",0.3,5.0);
  //tge_bothprotonsigma->Fit(funsigma,"","",0.4,3.0);
  tge_bothprotonsigma->SetMinimum(0.0);
  tge_bothprotonsigma->SetMaximum(0.4);
  tge_bothprotonsigma->GetXaxis()->SetLimits(0.0,5.2);
  tge_bothprotonsigma->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tge_bothprotonsigma->GetXaxis()->CenterTitle();
  tge_bothprotonsigma->GetYaxis()->SetTitle("#sigma_{m^{2}}");
  tge_bothprotonsigma->GetYaxis()->CenterTitle();

  c1->Print("m2pT_both_proton_sigma_FIVE.gif");
  c1->Print("m2pT_both_proton_sigma_FIVE.eps");




  exit(0);





  // --- proton

  ifstream finposproton("m2pT_pos_proton_par.txt");
  for(int i=0; i<40; i++)
    {
      finposproton>>pt[i]>>mean[i]>>emean[i]>>sigma[i]>>esigma[i];
      ept[i]=0;
      if(emean[i]>0.1) {mean[i]=-9;emean[i]=0;}
      if(esigma[i]>0.1) {sigma[i]=-9;esigma[i]=0;}
    }

  TGraphErrors *tge_posprotonmean = new TGraphErrors(40,pt,mean,ept,emean);
  tge_posprotonmean->SetMarkerColor(kRed);
  tge_posprotonmean->SetMarkerStyle(21);

  TGraphErrors *tge_posprotonsigma = new TGraphErrors(40,pt,sigma,ept,esigma);
  tge_posprotonsigma->SetMarkerColor(kRed);
  tge_posprotonsigma->SetMarkerStyle(21);

  ifstream finnegproton("m2pT_neg_proton_par.txt");
  for(int i=0; i<40; i++)
    {
      finnegproton>>pt[i]>>mean[i]>>emean[i]>>sigma[i]>>esigma[i];
      ept[i]=0;
      if(emean[i]>0.1) {mean[i]=-9;emean[i]=0;}
      if(esigma[i]>0.1) {sigma[i]=-9;esigma[i]=0;}
    }

  TGraphErrors *tge_negprotonmean = new TGraphErrors(40,pt,mean,ept,emean);
  tge_negprotonmean->SetMarkerColor(kRed);
  tge_negprotonmean->SetMarkerStyle(25);

  TGraphErrors *tge_negprotonsigma = new TGraphErrors(40,pt,sigma,ept,esigma);
  tge_negprotonsigma->SetMarkerColor(kRed);
  tge_negprotonsigma->SetMarkerStyle(25);


  // ---


  // --- drawn together :)

  c1->Clear();

  // now proton both charges

  c1->Clear();

  TMultiGraph *tmg3_mean = new TMultiGraph();
  tmg3_mean->Add(tge_posprotonmean);
  tmg3_mean->Add(tge_negprotonmean);
  tmg3_mean->Draw("ap");
  funmeanpr->Draw("same");
  tmg3_mean->SetMinimum(0.8);
  tmg3_mean->SetMaximum(1.0);
  tmg3_mean->GetXaxis()->SetLimits(0.0,5.2);
  tmg3_mean->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg3_mean->GetXaxis()->CenterTitle();
  tmg3_mean->GetYaxis()->SetTitle("#mu_{m^{2}}");
  tmg3_mean->GetYaxis()->CenterTitle();

  TLegend *leg3mean = new TLegend(0.18,0.68,0.38,0.88);
  leg3mean->SetFillColor(kWhite);
  leg3mean->SetBorderSize(0);
  leg3mean->AddEntry(tge_posprotonmean,"p","p");
  leg3mean->AddEntry(tge_negprotonmean,"#bar{p}","p");
  leg3mean->AddEntry(funmeanpr,"fit","l");
  leg3mean->AddEntry(pdgmasspr,"PDG","l");
  leg3mean->Draw();

  c1->Print("m2pT_protontogether_mean.gif");
  c1->Print("m2pT_protontogether_mean.eps");

  c1->Clear();

  TMultiGraph *tmg3_sigma = new TMultiGraph();
  tmg3_sigma->Add(tge_posprotonsigma);
  tmg3_sigma->Add(tge_negprotonsigma);
  tmg3_sigma->Draw("ap");
  funsigmapr->Draw("same");
  shenglisigmapr->Draw("same");
  tmg3_sigma->SetMinimum(0.0);
  tmg3_sigma->SetMaximum(0.2);
  tmg3_sigma->GetXaxis()->SetLimits(0.0,5.2);
  tmg3_sigma->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg3_sigma->GetXaxis()->CenterTitle();
  tmg3_sigma->GetYaxis()->SetTitle("#sigma_{m^{2}}");
  tmg3_sigma->GetYaxis()->CenterTitle();

  TLegend *leg3sigma = new TLegend(0.18,0.68,0.38,0.88);
  leg3sigma->SetFillColor(kWhite);
  leg3sigma->SetBorderSize(0);
  leg3sigma->AddEntry(tge_posprotonsigma,"p","p");
  leg3sigma->AddEntry(tge_negprotonsigma,"#bar{p}","p");
  leg3sigma->AddEntry(funsigmapr,"new","l");
  leg3sigma->AddEntry(shenglisigmapr,"old","l");
  leg3sigma->Draw();

  c1->Print("m2pT_protontogether_sigma.gif");
  c1->Print("m2pT_protontogether_sigma.eps");









}


