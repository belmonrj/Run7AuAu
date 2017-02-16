void plot()
{



  TCanvas *c1 = new TCanvas();
  c1->SetBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->SetFillColor(kWhite);
  c1->SetFrameFillColor(kWhite);

  ifstream finnegmp("data/tfwbgsdphi_pion_cent0_negmp_RpT.txt");
  ifstream finnegpm("data/tfwbgsdphi_pion_cent0_negpm_RpT.txt");
  ifstream finposmp("data/tfwbgsdphi_pion_cent0_posmp_RpT.txt");
  ifstream finpospm("data/tfwbgsdphi_pion_cent0_pospm_RpT.txt");

  //float pt[6], ept[6], fg[6], bg[6], tot[6];
  float pt_negmp[6], ept_negmp[6], fg_negmp[6], bg_negmp[6], tot_negmp[6];
  float pt_negpm[6], ept_negpm[6], fg_negpm[6], bg_negpm[6], tot_negpm[6];
  float pt_posmp[6], ept_posmp[6], fg_posmp[6], bg_posmp[6], tot_posmp[6];
  float pt_pospm[6], ept_pospm[6], fg_pospm[6], bg_pospm[6], tot_pospm[6];

  for(int i=0; i<6; i++)
    {
      finnegmp>>pt_negmp[i]>>fg_negmp[i]>>bg_negmp[i]>>tot_negmp[i];
      finnegpm>>pt_negpm[i]>>fg_negpm[i]>>bg_negpm[i]>>tot_negpm[i];
      finposmp>>pt_posmp[i]>>fg_posmp[i]>>bg_posmp[i]>>tot_posmp[i];
      finpospm>>pt_pospm[i]>>fg_pospm[i]>>bg_pospm[i]>>tot_pospm[i];
      ept_negmp[i]=0;
      ept_negpm[i]=0;
      ept_posmp[i]=0;
      ept_pospm[i]=0;
      // cout<<pt_negmp[i]<<"\t"<<fg_negmp[i]<<"\t"<<bg_negmp[i]<<"\t"<<tot_negmp[i]<<endl;
      // cout<<pt_negpm[i]<<"\t"<<fg_negpm[i]<<"\t"<<bg_negpm[i]<<"\t"<<tot_negpm[i]<<endl;
      // cout<<pt_posmp[i]<<"\t"<<fg_posmp[i]<<"\t"<<bg_posmp[i]<<"\t"<<tot_posmp[i]<<endl;
      // cout<<pt_pospm[i]<<"\t"<<fg_pospm[i]<<"\t"<<bg_pospm[i]<<"\t"<<tot_pospm[i]<<endl;
    }

  //TGraphErrors *tge_negmp = new TGraphErrors(6,pt_negmp,fg_negmp,ept_negmp,ept_negmp);

  TGraph *tg_negmp = new TGraph(6,pt_negmp,fg_negmp);
  tg_negmp->SetMarkerStyle(20);
  tg_negmp->SetMarkerColor(1);
  tg_negmp->SetMarkerSize(1.5);
  TGraph *tg_negpm = new TGraph(6,pt_negpm,fg_negpm);
  tg_negpm->SetMarkerStyle(21);
  tg_negpm->SetMarkerColor(2);
  TGraph *tg_posmp = new TGraph(6,pt_posmp,fg_posmp);
  tg_posmp->SetMarkerStyle(22);
  tg_posmp->SetMarkerColor(3);
  TGraph *tg_pospm = new TGraph(6,pt_pospm,fg_pospm);
  tg_pospm->SetMarkerStyle(23);
  tg_pospm->SetMarkerColor(4);

  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tg_negmp);
  tmg->Add(tg_negpm);
  tmg->Add(tg_posmp);
  tmg->Add(tg_pospm);
  tmg->Draw("ap");
  tmg->SetMaximum(1.0);
  tmg->SetMinimum(0.8);
  tmg->GetXaxis()->SetLimits(3.0,6.0);
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetYaxis()->SetTitle("Foreground");

  c1->Print("foreground.gif");
  c1->Print("foreground.eps");

  c1->Clear();



  TGraph *tg2_negmp = new TGraph(6,pt_negmp,bg_negmp);
  tg2_negmp->SetMarkerStyle(20);
  tg2_negmp->SetMarkerColor(1);
  tg2_negmp->SetMarkerSize(1.5);
  TGraph *tg2_negpm = new TGraph(6,pt_negpm,bg_negpm);
  tg2_negpm->SetMarkerStyle(21);
  tg2_negpm->SetMarkerColor(2);
  TGraph *tg2_posmp = new TGraph(6,pt_posmp,bg_posmp);
  tg2_posmp->SetMarkerStyle(22);
  tg2_posmp->SetMarkerColor(3);
  TGraph *tg2_pospm = new TGraph(6,pt_pospm,bg_pospm);
  tg2_pospm->SetMarkerStyle(23);
  tg2_pospm->SetMarkerColor(4);


  TF1 *fun1 = new TF1("fun1","expo(0)+pol0(2)",3.0,6.0);
  TF1 *fun2 = new TF1("fun2","expo(0)+pol0(2)",3.0,6.0);

  fun1->SetParameter(0,-4.928);
  fun1->SetParameter(1,0.6599);
  fun1->SetParameter(2,0.08916);

  fun2->SetParameter(0,-5.2);
  fun2->SetParameter(1,0.75);
  fun2->SetParameter(2,0.1);

  fun2->SetLineStyle(2);

  TMultiGraph *tmg2 = new TMultiGraph();
  tmg2->Add(tg2_negmp);
  tmg2->Add(tg2_negpm);
  tmg2->Add(tg2_posmp);
  tmg2->Add(tg2_pospm);
  tmg2->Draw("ap");
  //tmg2->Fit("pol2","","",3.0,6.0);
  //tmg2->Fit(fun,"","",3.0,6.0);
  //fun1->Draw("same");
  //fun2->Draw("same");
  tmg2->SetMaximum(0.2);
  tmg2->SetMinimum(0.0);
  tmg2->GetXaxis()->SetLimits(3.0,6.0);
  tmg2->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg2->GetYaxis()->SetTitle("Background");

  c1->Print("background.gif");
  c1->Print("background.eps");



}



