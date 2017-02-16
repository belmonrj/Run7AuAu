void cfrat()
{

  doit();

}


void doit()
{

  ifstream fin_prpospm("CorrectionFactors/cf_tofw_pospm_9_dis.dat");
  ifstream fin_prnegpm("CorrectionFactors/cf_tofw_negpm_9_dis.dat");
  ifstream fin_prposmp("CorrectionFactors/cf_tofw_posmp_9_dis.dat");
  ifstream fin_prnegmp("CorrectionFactors/cf_tofw_negmp_9_dis.dat");

  ifstream fin_pipospm("CorrectionFactors/cf_tofw_pospm_3_dis.dat");
  ifstream fin_pinegpm("CorrectionFactors/cf_tofw_negpm_3_dis.dat");
  ifstream fin_piposmp("CorrectionFactors/cf_tofw_posmp_3_dis.dat");
  ifstream fin_pinegmp("CorrectionFactors/cf_tofw_negmp_3_dis.dat");



  float pt_prpospm[100],ept_prpospm[100],cf_prpospm[100],ecf_prpospm[100];
  float pt_prnegpm[100],ept_prnegpm[100],cf_prnegpm[100],ecf_prnegpm[100];
  float pt_prposmp[100],ept_prposmp[100],cf_prposmp[100],ecf_prposmp[100];
  float pt_prnegmp[100],ept_prnegmp[100],cf_prnegmp[100],ecf_prnegmp[100];

  float pt_pipospm[100],ept_pipospm[100],cf_pipospm[100],ecf_pipospm[100];
  float pt_pinegpm[100],ept_pinegpm[100],cf_pinegpm[100],ecf_pinegpm[100];
  float pt_piposmp[100],ept_piposmp[100],cf_piposmp[100],ecf_piposmp[100];
  float pt_pinegmp[100],ept_pinegmp[100],cf_pinegmp[100],ecf_pinegmp[100];

  float pt_protA[100],ept_protA[100],ratio_protA[100],eratio_protA[100];
  float pt_protB[100],ept_protB[100],ratio_protB[100],eratio_protB[100];
  float pt_pionA[100],ept_pionA[100],ratio_pionA[100],eratio_pionA[100];
  float pt_pionB[100],ept_pionB[100],ratio_pionB[100],eratio_pionB[100];

  for(int i=0; i<100; i++)
    {
      ept_prpospm[i]=0;
      fin_prpospm>>pt_prpospm[i]>>cf_prpospm[i]>>ecf_prpospm[i];
      ept_prnegpm[i]=0;
      fin_prnegpm>>pt_prnegpm[i]>>cf_prnegpm[i]>>ecf_prnegpm[i];
      ept_prposmp[i]=0;
      fin_prposmp>>pt_prposmp[i]>>cf_prposmp[i]>>ecf_prposmp[i];
      ept_prnegmp[i]=0;
      fin_prnegmp>>pt_prnegmp[i]>>cf_prnegmp[i]>>ecf_prnegmp[i];

      ratio_protA[i] = cf_prnegpm[i]/cf_prposmp[i];
      ratio_protB[i] = cf_prnegmp[i]/cf_prpospm[i];
      eratio_protA[i] = cf_prnegpm[i]/cf_prposmp[i]*sqrt((ecf_prnegpm[i]/cf_prnegpm[i])**2+(ecf_prposmp[i]/cf_prposmp[i])**2);
      eratio_protB[i] = cf_prnegmp[i]/cf_prpospm[i]*sqrt((ecf_prnegmp[i]/cf_prnegmp[i])**2+(ecf_prpospm[i]/cf_prpospm[i])**2);
      pt_protA[i] = pt_prnegpm[i];
      pt_protB[i] = pt_prnegmp[i];
      ept_protA[i] = ept_prnegpm[i];
      ept_protB[i] = ept_prnegmp[i];



      ept_pipospm[i]=0;
      fin_pipospm>>pt_pipospm[i]>>cf_pipospm[i]>>ecf_pipospm[i];
      ept_pinegpm[i]=0;
      fin_pinegpm>>pt_pinegpm[i]>>cf_pinegpm[i]>>ecf_pinegpm[i];
      ept_piposmp[i]=0;
      fin_piposmp>>pt_piposmp[i]>>cf_piposmp[i]>>ecf_piposmp[i];
      ept_pinegmp[i]=0;
      fin_pinegmp>>pt_pinegmp[i]>>cf_pinegmp[i]>>ecf_pinegmp[i];

      ratio_pionA[i] = cf_pinegpm[i]/cf_piposmp[i];
      ratio_pionB[i] = cf_pinegmp[i]/cf_pipospm[i];
      eratio_pionA[i] = cf_pinegpm[i]/cf_piposmp[i]*sqrt((ecf_pinegpm[i]/cf_pinegpm[i])**2+(ecf_piposmp[i]/cf_piposmp[i])**2);
      eratio_pionB[i] = cf_pinegmp[i]/cf_pipospm[i]*sqrt((ecf_pinegmp[i]/cf_pinegmp[i])**2+(ecf_pipospm[i]/cf_pipospm[i])**2);
      pt_pionA[i] = pt_pinegpm[i];
      pt_pionB[i] = pt_pinegmp[i];
      ept_pionA[i] = ept_pinegpm[i];
      ept_pionB[i] = ept_pinegmp[i];
      if(i<2)
	{
	  ratio_pionA[i]=-9;
	  ratio_pionB[i]=-9;
	}
      if(i<5)
	{
	  ratio_protA[i]=-9;
	  ratio_protB[i]=-9;
	}
    }



  TGraphErrors *tge_protA = new TGraphErrors(100,pt_protA,ratio_protA,ept_protA,eratio_protA);
  tge_protA->SetMarkerColor(kBlack);
  tge_protA->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_protB = new TGraphErrors(100,pt_protB,ratio_protB,ept_protB,eratio_protB);
  tge_protB->SetMarkerColor(kBlack);
  tge_protB->SetMarkerStyle(kFullCircle);

  TGraphErrors *tge_pionA = new TGraphErrors(100,pt_pionA,ratio_pionA,ept_pionA,eratio_pionA);
  tge_pionA->SetMarkerColor(kRed);
  tge_pionA->SetMarkerStyle(kFullSquare);
  TGraphErrors *tge_pionB = new TGraphErrors(100,pt_pionB,ratio_pionB,ept_pionB,eratio_pionB);
  tge_pionB->SetMarkerColor(kBlue);
  tge_pionB->SetMarkerStyle(kFullSquare);



  TLine *line = new TLine(0.0,1.0,6.0,1.0);
  line->SetLineWidth(3.0);

  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tge_pionA);
  tmg->Add(tge_pionB);
  tmg->Add(tge_protA);
  tmg->Add(tge_protB);
  tmg->Draw("ap");
  line->Draw("same");
  tmg->SetMaximum(2.0);
  tmg->SetMinimum(0.0);
  tmg->GetXaxis()->SetLimits(0.0,6.0);
  tmg->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  tmg->GetYaxis()->SetTitle("Ratio cfneg/cfpos");

  TLegend *leg = new TLegend(0.68,0.68,0.88,0.88);
  leg->AddEntry(tge_protB,"p, pos alpha","p");
  leg->AddEntry(tge_protA,"p, neg alpha","p");
  leg->AddEntry(tge_pionB,"#pi, pos alpha","p");
  leg->AddEntry(tge_pionA,"#pi, neg alpha","p");
  leg->Draw();

  c1->Print("CorrectionFactors/tmg.gif");
  c1->Print("CorrectionFactors/tmg.eps");



  //tmg->Delete();
  //leg->Delete();

  c1->Clear();

  TMultiGraph *tmg2 = new TMultiGraph();
  tmg2->Add(tge_pionA);
  tmg2->Add(tge_pionB);
  //tmg2->Add(tge_protA);
  //tmg2->Add(tge_protB);
  tmg2->Draw("ap");
  line->Draw("same");
  tmg2->SetMaximum(2.0);
  tmg2->SetMinimum(0.0);
  tmg2->GetXaxis()->SetLimits(0.0,6.0);
  tmg2->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  tmg2->GetYaxis()->SetTitle("Ratio cfneg/cfpos");

  TLegend *leg2 = new TLegend(0.68,0.68,0.88,0.88);
  //leg2->AddEntry(tge_protB,"p, pos alpha","p");
  //leg2->AddEntry(tge_protA,"p, neg alpha","p");
  leg2->AddEntry(tge_pionB,"#pi, pos alpha","p");
  leg2->AddEntry(tge_pionA,"#pi, neg alpha","p");
  leg2->Draw();

  c1->Print("CorrectionFactors/tmg_pion.gif");
  c1->Print("CorrectionFactors/tmg_pion.eps");




  c1->Clear();

  TF1 *fun = new TF1("fun","expo(0)+pol0(2)",0.5,6.0);

  TMultiGraph *tmg3 = new TMultiGraph();
  //tmg3->Add(tge_pionA);
  //tmg3->Add(tge_pionB);
  tmg3->Add(tge_protA);
  tmg3->Add(tge_protB);
  tmg3->Draw("ap");
  tmg3->Fit(fun,"R");
  line->Draw("same");
  tmg3->SetMaximum(2.0);
  tmg3->SetMinimum(0.0);
  tmg3->GetXaxis()->SetLimits(0.0,6.0);
  tmg3->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  tmg3->GetYaxis()->SetTitle("Ratio cfneg/cfpos");

  //TLegend *leg3 = new TLegend(0.68,0.68,0.88,0.88);
  TLegend *leg3 = new TLegend(0.68,0.18,0.88,0.38);
  leg3->AddEntry(tge_protB,"p, pos alpha","p");
  leg3->AddEntry(tge_protA,"p, neg alpha","p");
  //leg3->AddEntry(tge_pionB,"#pi, pos alpha","p");
  //leg3->AddEntry(tge_pionA,"#pi, neg alpha","p");
  leg3->Draw();

  c1->Print("CorrectionFactors/tmg_prot.eps");
  c1->Print("CorrectionFactors/tmg_prot.gif");

  //tmg->Delete();
  //leg->Delete();








}
