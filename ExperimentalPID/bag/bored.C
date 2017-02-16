void bored()
{

  //doit1();

  doitR();

}

void doitR()
{

  float low = 0.0;
  float high = 6.0;

  float min = 0.7;
  float max = 1.3;

  TCanvas *c1 = new TCanvas("c1","",800,600);
  c1->SetLogy();

  TF1 *fun = new TF1("fun","pol1",0,10);
  fun->SetParameter(0,0);
  fun->SetParameter(1,1);

  TFile *freal_L = TFile::Open("outlowpm.root");
  TFile *freal_H = TFile::Open("outhighpm.root");
  TFile *fsimpi =  TFile::Open("simpion_pm.root");
  TFile *fsimka =  TFile::Open("simkaon_pm.root");
  TFile *fsimpr =  TFile::Open("simproton_pm.root");

  TH1F *hreal_L_pion_0 = (TH1F *)freal_L->Get("testpid_tofw_pionpos_0_dis");
  TH1F *hreal_L_pion_1 = (TH1F *)freal_L->Get("testpid_tofw_pionpos_1_dis");
  TH1F *hreal_L_pion_2 = (TH1F *)freal_L->Get("testpid_tofw_pionpos_2_dis");
  TH1F *hreal_L_pion_3 = (TH1F *)freal_L->Get("testpid_tofw_pionpos_3_dis");
  TH1F *hreal_L_pion_4 = (TH1F *)freal_L->Get("testpid_tofw_pionpos_4_dis");
  //TH1F *hreal_L_pion_5 = (TH1F *)freal_L->Get("testpid_tofw_pionpos_5_dis");

  TH1F *hreal_L_kaon_0 = (TH1F *)freal_L->Get("testpid_tofw_kaonpos_0_dis");
  TH1F *hreal_L_kaon_1 = (TH1F *)freal_L->Get("testpid_tofw_kaonpos_1_dis");
  TH1F *hreal_L_kaon_2 = (TH1F *)freal_L->Get("testpid_tofw_kaonpos_2_dis");
  TH1F *hreal_L_kaon_3 = (TH1F *)freal_L->Get("testpid_tofw_kaonpos_3_dis");
  TH1F *hreal_L_kaon_4 = (TH1F *)freal_L->Get("testpid_tofw_kaonpos_4_dis");
  //TH1F *hreal_L_kaon_5 = (TH1F *)freal_L->Get("testpid_tofw_kaonpos_5_dis");

  TH1F *hreal_L_proton_0 = (TH1F *)freal_L->Get("testpid_tofw_protonpos_0_dis");
  TH1F *hreal_L_proton_1 = (TH1F *)freal_L->Get("testpid_tofw_protonpos_1_dis");
  TH1F *hreal_L_proton_2 = (TH1F *)freal_L->Get("testpid_tofw_protonpos_2_dis");
  TH1F *hreal_L_proton_3 = (TH1F *)freal_L->Get("testpid_tofw_protonpos_3_dis");
  TH1F *hreal_L_proton_4 = (TH1F *)freal_L->Get("testpid_tofw_protonpos_4_dis");
  //TH1F *hreal_L_proton_5 = (TH1F *)freal_L->Get("testpid_tofw_protonpos_5_dis");

  hreal_L_pion_0->Sumw2();
  hreal_L_pion_1->Sumw2();
  hreal_L_pion_2->Sumw2();
  hreal_L_pion_3->Sumw2();
  hreal_L_pion_4->Sumw2();
  //hreal_L_pion_5->Sumw2();

  hreal_L_kaon_0->Sumw2();
  hreal_L_kaon_1->Sumw2();
  hreal_L_kaon_2->Sumw2();
  hreal_L_kaon_3->Sumw2();
  hreal_L_kaon_4->Sumw2();
  //hreal_L_kaon_5->Sumw2();

  hreal_L_proton_0->Sumw2();
  hreal_L_proton_1->Sumw2();
  hreal_L_proton_2->Sumw2();
  hreal_L_proton_3->Sumw2();
  hreal_L_proton_4->Sumw2();
  //hreal_L_proton_5->Sumw2();

  //freal_L->Close();



  TH1F *hreal_H_pion_0 = (TH1F *)freal_H->Get("testpid_tofw_pionpos_0_dis");
  TH1F *hreal_H_pion_1 = (TH1F *)freal_H->Get("testpid_tofw_pionpos_1_dis");
  TH1F *hreal_H_pion_2 = (TH1F *)freal_H->Get("testpid_tofw_pionpos_2_dis");
  TH1F *hreal_H_pion_3 = (TH1F *)freal_H->Get("testpid_tofw_pionpos_3_dis");
  TH1F *hreal_H_pion_4 = (TH1F *)freal_H->Get("testpid_tofw_pionpos_4_dis");
  //TH1F *hreal_H_pion_5 = (TH1F *)freal_H->Get("testpid_tofw_pionpos_5_dis");

  TH1F *hreal_H_kaon_0 = (TH1F *)freal_H->Get("testpid_tofw_kaonpos_0_dis");
  TH1F *hreal_H_kaon_1 = (TH1F *)freal_H->Get("testpid_tofw_kaonpos_1_dis");
  TH1F *hreal_H_kaon_2 = (TH1F *)freal_H->Get("testpid_tofw_kaonpos_2_dis");
  TH1F *hreal_H_kaon_3 = (TH1F *)freal_H->Get("testpid_tofw_kaonpos_3_dis");
  TH1F *hreal_H_kaon_4 = (TH1F *)freal_H->Get("testpid_tofw_kaonpos_4_dis");
  //TH1F *hreal_H_kaon_5 = (TH1F *)freal_H->Get("testpid_tofw_kaonpos_5_dis");

  TH1F *hreal_H_proton_0 = (TH1F *)freal_H->Get("testpid_tofw_protonpos_0_dis");
  TH1F *hreal_H_proton_1 = (TH1F *)freal_H->Get("testpid_tofw_protonpos_1_dis");
  TH1F *hreal_H_proton_2 = (TH1F *)freal_H->Get("testpid_tofw_protonpos_2_dis");
  TH1F *hreal_H_proton_3 = (TH1F *)freal_H->Get("testpid_tofw_protonpos_3_dis");
  TH1F *hreal_H_proton_4 = (TH1F *)freal_H->Get("testpid_tofw_protonpos_4_dis");
  //TH1F *hreal_H_proton_5 = (TH1F *)freal_H->Get("testpid_tofw_protonpos_5_dis");

  hreal_H_pion_0->Sumw2();
  hreal_H_pion_1->Sumw2();
  hreal_H_pion_2->Sumw2();
  hreal_H_pion_3->Sumw2();
  hreal_H_pion_4->Sumw2();
  //hreal_H_pion_5->Sumw2();

  hreal_H_kaon_0->Sumw2();
  hreal_H_kaon_1->Sumw2();
  hreal_H_kaon_2->Sumw2();
  hreal_H_kaon_3->Sumw2();
  hreal_H_kaon_4->Sumw2();
  //hreal_H_kaon_5->Sumw2();

  hreal_H_proton_0->Sumw2();
  hreal_H_proton_1->Sumw2();
  hreal_H_proton_2->Sumw2();
  hreal_H_proton_3->Sumw2();
  hreal_H_proton_4->Sumw2();
  //hreal_H_proton_5->Sumw2();

  //freal_H->Close();



  TH1F *hreal_pion_0 = (TH1F *)hreal_L_pion_0->Clone();
  TH1F *hreal_pion_1 = (TH1F *)hreal_L_pion_1->Clone();
  TH1F *hreal_pion_2 = (TH1F *)hreal_L_pion_2->Clone();
  TH1F *hreal_pion_3 = (TH1F *)hreal_L_pion_3->Clone();
  TH1F *hreal_pion_4 = (TH1F *)hreal_L_pion_4->Clone();
  //TH1F *hreal_pion_5 = (TH1F *)hreal_L_pion_5->Clone();

  TH1F *hreal_kaon_0 = (TH1F *)hreal_L_kaon_0->Clone();
  TH1F *hreal_kaon_1 = (TH1F *)hreal_L_kaon_1->Clone();
  TH1F *hreal_kaon_2 = (TH1F *)hreal_L_kaon_2->Clone();
  TH1F *hreal_kaon_3 = (TH1F *)hreal_L_kaon_3->Clone();
  TH1F *hreal_kaon_4 = (TH1F *)hreal_L_kaon_4->Clone();
  //TH1F *hreal_kaon_5 = (TH1F *)hreal_L_kaon_5->Clone();

  TH1F *hreal_proton_0 = (TH1F *)hreal_L_proton_0->Clone();
  TH1F *hreal_proton_1 = (TH1F *)hreal_L_proton_1->Clone();
  TH1F *hreal_proton_2 = (TH1F *)hreal_L_proton_2->Clone();
  TH1F *hreal_proton_3 = (TH1F *)hreal_L_proton_3->Clone();
  TH1F *hreal_proton_4 = (TH1F *)hreal_L_proton_4->Clone();
  //TH1F *hreal_proton_5 = (TH1F *)hreal_L_proton_5->Clone();

  for(int i=30; i<100; i++)
    {
      hreal_pion_0->SetBinContent(i+1,hreal_H_pion_0->GetBinContent(i+1));
      hreal_pion_1->SetBinContent(i+1,hreal_H_pion_1->GetBinContent(i+1));
      hreal_pion_2->SetBinContent(i+1,hreal_H_pion_2->GetBinContent(i+1));
      hreal_pion_3->SetBinContent(i+1,hreal_H_pion_3->GetBinContent(i+1));
      hreal_pion_4->SetBinContent(i+1,hreal_H_pion_4->GetBinContent(i+1));
      //hreal_pion_5->SetBinContent(i+1,hreal_H_pion_5->GetBinContent(i+1));

      hreal_kaon_0->SetBinContent(i+1,hreal_H_kaon_0->GetBinContent(i+1));
      hreal_kaon_1->SetBinContent(i+1,hreal_H_kaon_1->GetBinContent(i+1));
      hreal_kaon_2->SetBinContent(i+1,hreal_H_kaon_2->GetBinContent(i+1));
      hreal_kaon_3->SetBinContent(i+1,hreal_H_kaon_3->GetBinContent(i+1));
      hreal_kaon_4->SetBinContent(i+1,hreal_H_kaon_4->GetBinContent(i+1));
      //hreal_kaon_5->SetBinContent(i+1,hreal_H_kaon_5->GetBinContent(i+1));

      hreal_proton_0->SetBinContent(i+1,hreal_H_proton_0->GetBinContent(i+1));
      hreal_proton_1->SetBinContent(i+1,hreal_H_proton_1->GetBinContent(i+1));
      hreal_proton_2->SetBinContent(i+1,hreal_H_proton_2->GetBinContent(i+1));
      hreal_proton_3->SetBinContent(i+1,hreal_H_proton_3->GetBinContent(i+1));
      hreal_proton_4->SetBinContent(i+1,hreal_H_proton_4->GetBinContent(i+1));
      //hreal_proton_5->SetBinContent(i+1,hreal_H_proton_5->GetBinContent(i+1));

      // error

      hreal_pion_0->SetBinError(i+1,hreal_H_pion_0->GetBinError(i+1));
      hreal_pion_1->SetBinError(i+1,hreal_H_pion_1->GetBinError(i+1));
      hreal_pion_2->SetBinError(i+1,hreal_H_pion_2->GetBinError(i+1));
      hreal_pion_3->SetBinError(i+1,hreal_H_pion_3->GetBinError(i+1));
      hreal_pion_4->SetBinError(i+1,hreal_H_pion_4->GetBinError(i+1));
      //hreal_pion_5->SetBinError(i+1,hreal_H_pion_5->GetBinError(i+1));

      hreal_kaon_0->SetBinError(i+1,hreal_H_kaon_0->GetBinError(i+1));
      hreal_kaon_1->SetBinError(i+1,hreal_H_kaon_1->GetBinError(i+1));
      hreal_kaon_2->SetBinError(i+1,hreal_H_kaon_2->GetBinError(i+1));
      hreal_kaon_3->SetBinError(i+1,hreal_H_kaon_3->GetBinError(i+1));
      hreal_kaon_4->SetBinError(i+1,hreal_H_kaon_4->GetBinError(i+1));
      //hreal_kaon_5->SetBinError(i+1,hreal_H_kaon_5->GetBinError(i+1));

      hreal_proton_0->SetBinError(i+1,hreal_H_proton_0->GetBinError(i+1));
      hreal_proton_1->SetBinError(i+1,hreal_H_proton_1->GetBinError(i+1));
      hreal_proton_2->SetBinError(i+1,hreal_H_proton_2->GetBinError(i+1));
      hreal_proton_3->SetBinError(i+1,hreal_H_proton_3->GetBinError(i+1));
      hreal_proton_4->SetBinError(i+1,hreal_H_proton_4->GetBinError(i+1));
      //hreal_proton_5->SetBinError(i+1,hreal_H_proton_5->GetBinError(i+1));
    }





  TH1F *hsim_pion_0 = (TH1F *)fsimpi->Get("testpid_tofw_pionpos_0_dis");
  TH1F *hsim_pion_1 = (TH1F *)fsimpi->Get("testpid_tofw_pionpos_1_dis");
  TH1F *hsim_pion_2 = (TH1F *)fsimpi->Get("testpid_tofw_pionpos_2_dis");
  TH1F *hsim_pion_3 = (TH1F *)fsimpi->Get("testpid_tofw_pionpos_3_dis");
  TH1F *hsim_pion_4 = (TH1F *)fsimpi->Get("testpid_tofw_pionpos_4_dis");
  //TH1F *hsim_pion_5 = (TH1F *)fsimpi->Get("testpid_tofw_pionpos_5_dis");

  TH1F *hsim_kaon_0 = (TH1F *)fsimka->Get("testpid_tofw_kaonpos_0_dis");
  TH1F *hsim_kaon_1 = (TH1F *)fsimka->Get("testpid_tofw_kaonpos_1_dis");
  TH1F *hsim_kaon_2 = (TH1F *)fsimka->Get("testpid_tofw_kaonpos_2_dis");
  TH1F *hsim_kaon_3 = (TH1F *)fsimka->Get("testpid_tofw_kaonpos_3_dis");
  TH1F *hsim_kaon_4 = (TH1F *)fsimka->Get("testpid_tofw_kaonpos_4_dis");
  //TH1F *hsim_kaon_5 = (TH1F *)fsimka->Get("testpid_tofw_kaonpos_5_dis");

  TH1F *hsim_proton_0 = (TH1F *)fsimpr->Get("testpid_tofw_protonpos_0_dis");
  TH1F *hsim_proton_1 = (TH1F *)fsimpr->Get("testpid_tofw_protonpos_1_dis");
  TH1F *hsim_proton_2 = (TH1F *)fsimpr->Get("testpid_tofw_protonpos_2_dis");
  TH1F *hsim_proton_3 = (TH1F *)fsimpr->Get("testpid_tofw_protonpos_3_dis");
  TH1F *hsim_proton_4 = (TH1F *)fsimpr->Get("testpid_tofw_protonpos_4_dis");
  //TH1F *hsim_proton_5 = (TH1F *)fsimpr->Get("testpid_tofw_protonpos_5_dis");

  hsim_pion_0->Sumw2();
  hsim_pion_1->Sumw2();
  hsim_pion_2->Sumw2();
  hsim_pion_3->Sumw2();
  hsim_pion_4->Sumw2();
  //hsim_pion_5->Sumw2();

  hsim_kaon_0->Sumw2();
  hsim_kaon_1->Sumw2();
  hsim_kaon_2->Sumw2();
  hsim_kaon_3->Sumw2();
  hsim_kaon_4->Sumw2();
  //hsim_kaon_5->Sumw2();

  hsim_proton_0->Sumw2();
  hsim_proton_1->Sumw2();
  hsim_proton_2->Sumw2();
  hsim_proton_3->Sumw2();
  hsim_proton_4->Sumw2();
  //hsim_proton_5->Sumw2();



  // --- here here here



  hreal_pion_0->Divide(hsim_pion_0);
  hreal_pion_1->Divide(hsim_pion_1);
  hreal_pion_2->Divide(hsim_pion_2);
  hreal_pion_3->Divide(hsim_pion_3);
  hreal_pion_4->Divide(hsim_pion_4);
  //hreal_pion_5->Divide(hsim_pion_5);

  hreal_kaon_0->Divide(hsim_kaon_0);
  hreal_kaon_1->Divide(hsim_kaon_1);
  hreal_kaon_2->Divide(hsim_kaon_2);
  hreal_kaon_3->Divide(hsim_kaon_3);
  hreal_kaon_4->Divide(hsim_kaon_4);
  //hreal_kaon_5->Divide(hsim_kaon_5);

  hreal_proton_0->Divide(hsim_proton_0);
  hreal_proton_1->Divide(hsim_proton_1);
  hreal_proton_2->Divide(hsim_proton_2);
  hreal_proton_3->Divide(hsim_proton_3);
  hreal_proton_4->Divide(hsim_proton_4);
  //hreal_proton_5->Divide(hsim_proton_5);

  hreal_pion_0->Divide(fun,1.0);
  hreal_pion_1->Divide(fun,1.0);
  hreal_pion_2->Divide(fun,1.0);
  hreal_pion_3->Divide(fun,1.0);
  hreal_pion_4->Divide(fun,1.0);
  //hreal_pion_5->Divide(fun,1.0);

  hreal_kaon_0->Divide(fun,1.0);
  hreal_kaon_1->Divide(fun,1.0);
  hreal_kaon_2->Divide(fun,1.0);
  hreal_kaon_3->Divide(fun,1.0);
  hreal_kaon_4->Divide(fun,1.0);
  //hreal_kaon_5->Divide(fun,1.0);

  hreal_proton_0->Divide(fun,1.0);
  hreal_proton_1->Divide(fun,1.0);
  hreal_proton_2->Divide(fun,1.0);
  hreal_proton_3->Divide(fun,1.0);
  hreal_proton_4->Divide(fun,1.0);
  //hreal_proton_5->Divide(fun,1.0);


  hreal_pion_0->SetLineColor(kBlack);
  hreal_pion_1->SetLineColor(kRed);
  hreal_pion_2->SetLineColor(kBlue);
  hreal_pion_3->SetLineColor(kGreen+2);
  hreal_pion_4->SetLineColor(kMagenta+2);
  //hreal_pion_5->SetLineColor(kYellow+2);

  hreal_kaon_0->SetLineColor(kBlack);
  hreal_kaon_1->SetLineColor(kRed);
  hreal_kaon_2->SetLineColor(kBlue);
  hreal_kaon_3->SetLineColor(kGreen+2);
  hreal_kaon_4->SetLineColor(kMagenta+2);
  //hreal_kaon_5->SetLineColor(kYellow+2);

  hreal_proton_0->SetLineColor(kBlack);
  hreal_proton_1->SetLineColor(kRed);
  hreal_proton_2->SetLineColor(kBlue);
  hreal_proton_3->SetLineColor(kGreen+2);
  hreal_proton_4->SetLineColor(kMagenta+2);
  //hreal_proton_5->SetLineColor(kYellow+2);



  TH2F *hhhh = new TH2F("hhhh","",1,low,high,1,0.001,10000);
  hhhh->Draw();
  hreal_pion_0->Draw("same");
  hreal_pion_1->Draw("same");
  hreal_pion_2->Draw("same");
  hreal_pion_3->Draw("same");
  hreal_pion_4->Draw("same");
  //hreal_pion_5->Draw("same");
  TLegend *leg = new TLegend(0.68,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(hreal_pion_0,"0","l");
  leg->AddEntry(hreal_pion_1,"1","l");
  leg->AddEntry(hreal_pion_2,"2","l");
  leg->AddEntry(hreal_pion_3,"3","l");
  leg->AddEntry(hreal_pion_4,"4","l");
  //leg->AddEntry(hreal_pion_5,"5","l");
  leg->Draw();

  c1->Print("pions.gif");

  gSystem->Sleep(2000);

  hhhh->Draw();
  hreal_kaon_0->Draw("same");
  hreal_kaon_1->Draw("same");
  hreal_kaon_2->Draw("same");
  hreal_kaon_3->Draw("same");
  hreal_kaon_4->Draw("same");
  //hreal_kaon_5->Draw("same");
  leg->Draw();

  c1->Print("kaons.gif");

  gSystem->Sleep(2000);

  hhhh->Draw();
  hreal_proton_0->Draw("same");
  hreal_proton_1->Draw("same");
  hreal_proton_2->Draw("same");
  hreal_proton_3->Draw("same");
  hreal_proton_4->Draw("same");
  //hreal_proton_5->Draw("same");
  leg->Draw();

  c1->Print("protons.gif");

  gSystem->Sleep(2000);

  c1->Clear();



  c1->SetLogy(0);

  TH1F *hreal_pion = (TH1F *)hreal_pion_1->Clone();
  TH1F *hreal_kaon = (TH1F *)hreal_kaon_1->Clone();
  TH1F *hreal_proton = (TH1F *)hreal_proton_1->Clone();

  hreal_pion_0->Divide(hreal_pion);
  hreal_pion_1->Divide(hreal_pion);
  hreal_pion_2->Divide(hreal_pion);
  hreal_pion_3->Divide(hreal_pion);
  hreal_pion_4->Divide(hreal_pion);
  //hreal_pion_5->Divide(hreal_pion);

  hreal_kaon_0->Divide(hreal_kaon);
  hreal_kaon_1->Divide(hreal_kaon);
  hreal_kaon_2->Divide(hreal_kaon);
  hreal_kaon_3->Divide(hreal_kaon);
  hreal_kaon_4->Divide(hreal_kaon);
  //hreal_kaon_5->Divide(hreal_kaon);

  hreal_proton_0->Divide(hreal_proton);
  hreal_proton_1->Divide(hreal_proton);
  hreal_proton_2->Divide(hreal_proton);
  hreal_proton_3->Divide(hreal_proton);
  hreal_proton_4->Divide(hreal_proton);
  //hreal_proton_5->Divide(hreal_proton);

  TH2F *hhh2 = new TH2F("hhh2","",1,low,high,1,min,max);
  hhh2->Draw();
  hreal_pion_0->Draw("same");
  hreal_pion_1->Draw("same");
  hreal_pion_2->Draw("same");
  hreal_pion_3->Draw("same");
  hreal_pion_4->Draw("same");
  //hreal_pion_5->Draw("same");
  leg->Draw();

  c1->Print("pions_ratio.gif");

  gSystem->Sleep(2000);

  hhh2->Draw();
  hreal_kaon_0->Draw("same");
  hreal_kaon_1->Draw("same");
  hreal_kaon_2->Draw("same");
  hreal_kaon_3->Draw("same");
  hreal_kaon_4->Draw("same");
  //hreal_kaon_5->Draw("same");
  leg->Draw();

  c1->Print("kaons_ratio.gif");

  gSystem->Sleep(2000);

  hhh2->Draw();
  hreal_proton_0->Draw("same");
  hreal_proton_1->Draw("same");
  hreal_proton_2->Draw("same");
  hreal_proton_3->Draw("same");
  hreal_proton_4->Draw("same");
  //hreal_proton_5->Draw("same");
  leg->Draw();

  c1->Print("protons_ratio.gif");

}






void doit1()
{

  float low = 0.0;
  float high = 3.0;

  float min = 0.7;
  float max = 1.3;

  TCanvas *c1 = new TCanvas("c1","",800,600);
  c1->SetLogy();

  TF1 *fun = new TF1("fun","pol1",0,10);
  fun->SetParameter(0,0);
  fun->SetParameter(1,1);

  TFile *freal = TFile::Open("outlowpm.root");
  TFile *fsimpi =  TFile::Open("simpion_pm.root");
  TFile *fsimka =  TFile::Open("simkaon_pm.root");
  TFile *fsimpr =  TFile::Open("simproton_pm.root");

  TH1F *hreal_pion_0 = (TH1F *)freal->Get("testpid_tofw_pionpos_0_dis");
  TH1F *hreal_pion_1 = (TH1F *)freal->Get("testpid_tofw_pionpos_1_dis");
  TH1F *hreal_pion_2 = (TH1F *)freal->Get("testpid_tofw_pionpos_2_dis");
  TH1F *hreal_pion_3 = (TH1F *)freal->Get("testpid_tofw_pionpos_3_dis");
  TH1F *hreal_pion_4 = (TH1F *)freal->Get("testpid_tofw_pionpos_4_dis");
  //TH1F *hreal_pion_5 = (TH1F *)freal->Get("testpid_tofw_pionpos_5_dis");

  TH1F *hreal_kaon_0 = (TH1F *)freal->Get("testpid_tofw_kaonpos_0_dis");
  TH1F *hreal_kaon_1 = (TH1F *)freal->Get("testpid_tofw_kaonpos_1_dis");
  TH1F *hreal_kaon_2 = (TH1F *)freal->Get("testpid_tofw_kaonpos_2_dis");
  TH1F *hreal_kaon_3 = (TH1F *)freal->Get("testpid_tofw_kaonpos_3_dis");
  TH1F *hreal_kaon_4 = (TH1F *)freal->Get("testpid_tofw_kaonpos_4_dis");
  //TH1F *hreal_kaon_5 = (TH1F *)freal->Get("testpid_tofw_kaonpos_5_dis");

  TH1F *hreal_proton_0 = (TH1F *)freal->Get("testpid_tofw_protonpos_0_dis");
  TH1F *hreal_proton_1 = (TH1F *)freal->Get("testpid_tofw_protonpos_1_dis");
  TH1F *hreal_proton_2 = (TH1F *)freal->Get("testpid_tofw_protonpos_2_dis");
  TH1F *hreal_proton_3 = (TH1F *)freal->Get("testpid_tofw_protonpos_3_dis");
  TH1F *hreal_proton_4 = (TH1F *)freal->Get("testpid_tofw_protonpos_4_dis");
  //TH1F *hreal_proton_5 = (TH1F *)freal->Get("testpid_tofw_protonpos_5_dis");

  TH1F *hsim_pion_0 = (TH1F *)fsimpi->Get("testpid_tofw_pionpos_0_dis");
  TH1F *hsim_pion_1 = (TH1F *)fsimpi->Get("testpid_tofw_pionpos_1_dis");
  TH1F *hsim_pion_2 = (TH1F *)fsimpi->Get("testpid_tofw_pionpos_2_dis");
  TH1F *hsim_pion_3 = (TH1F *)fsimpi->Get("testpid_tofw_pionpos_3_dis");
  TH1F *hsim_pion_4 = (TH1F *)fsimpi->Get("testpid_tofw_pionpos_4_dis");
  //TH1F *hsim_pion_5 = (TH1F *)fsimpi->Get("testpid_tofw_pionpos_5_dis");

  TH1F *hsim_kaon_0 = (TH1F *)fsimka->Get("testpid_tofw_kaonpos_0_dis");
  TH1F *hsim_kaon_1 = (TH1F *)fsimka->Get("testpid_tofw_kaonpos_1_dis");
  TH1F *hsim_kaon_2 = (TH1F *)fsimka->Get("testpid_tofw_kaonpos_2_dis");
  TH1F *hsim_kaon_3 = (TH1F *)fsimka->Get("testpid_tofw_kaonpos_3_dis");
  TH1F *hsim_kaon_4 = (TH1F *)fsimka->Get("testpid_tofw_kaonpos_4_dis");
  //TH1F *hsim_kaon_5 = (TH1F *)fsimka->Get("testpid_tofw_kaonpos_5_dis");

  TH1F *hsim_proton_0 = (TH1F *)fsimpr->Get("testpid_tofw_protonpos_0_dis");
  TH1F *hsim_proton_1 = (TH1F *)fsimpr->Get("testpid_tofw_protonpos_1_dis");
  TH1F *hsim_proton_2 = (TH1F *)fsimpr->Get("testpid_tofw_protonpos_2_dis");
  TH1F *hsim_proton_3 = (TH1F *)fsimpr->Get("testpid_tofw_protonpos_3_dis");
  TH1F *hsim_proton_4 = (TH1F *)fsimpr->Get("testpid_tofw_protonpos_4_dis");
  //TH1F *hsim_proton_5 = (TH1F *)fsimpr->Get("testpid_tofw_protonpos_5_dis");

  hreal_pion_0->Sumw2();
  hreal_pion_1->Sumw2();
  hreal_pion_2->Sumw2();
  hreal_pion_3->Sumw2();
  hreal_pion_4->Sumw2();
  //hreal_pion_5->Sumw2();

  hreal_kaon_0->Sumw2();
  hreal_kaon_1->Sumw2();
  hreal_kaon_2->Sumw2();
  hreal_kaon_3->Sumw2();
  hreal_kaon_4->Sumw2();
  //hreal_kaon_5->Sumw2();

  hreal_proton_0->Sumw2();
  hreal_proton_1->Sumw2();
  hreal_proton_2->Sumw2();
  hreal_proton_3->Sumw2();
  hreal_proton_4->Sumw2();
  //hreal_proton_5->Sumw2();

  hsim_pion_0->Sumw2();
  hsim_pion_1->Sumw2();
  hsim_pion_2->Sumw2();
  hsim_pion_3->Sumw2();
  hsim_pion_4->Sumw2();
  //hsim_pion_5->Sumw2();

  hsim_kaon_0->Sumw2();
  hsim_kaon_1->Sumw2();
  hsim_kaon_2->Sumw2();
  hsim_kaon_3->Sumw2();
  hsim_kaon_4->Sumw2();
  //hsim_kaon_5->Sumw2();

  hsim_proton_0->Sumw2();
  hsim_proton_1->Sumw2();
  hsim_proton_2->Sumw2();
  hsim_proton_3->Sumw2();
  hsim_proton_4->Sumw2();
  //hsim_proton_5->Sumw2();

  hreal_pion_0->Divide(hsim_pion_0);
  hreal_pion_1->Divide(hsim_pion_1);
  hreal_pion_2->Divide(hsim_pion_2);
  hreal_pion_3->Divide(hsim_pion_3);
  hreal_pion_4->Divide(hsim_pion_4);
  //hreal_pion_5->Divide(hsim_pion_5);

  hreal_kaon_0->Divide(hsim_kaon_0);
  hreal_kaon_1->Divide(hsim_kaon_1);
  hreal_kaon_2->Divide(hsim_kaon_2);
  hreal_kaon_3->Divide(hsim_kaon_3);
  hreal_kaon_4->Divide(hsim_kaon_4);
  //hreal_kaon_5->Divide(hsim_kaon_5);

  hreal_proton_0->Divide(hsim_proton_0);
  hreal_proton_1->Divide(hsim_proton_1);
  hreal_proton_2->Divide(hsim_proton_2);
  hreal_proton_3->Divide(hsim_proton_3);
  hreal_proton_4->Divide(hsim_proton_4);
  //hreal_proton_5->Divide(hsim_proton_5);

  hreal_pion_0->Divide(fun,1.0);
  hreal_pion_1->Divide(fun,1.0);
  hreal_pion_2->Divide(fun,1.0);
  hreal_pion_3->Divide(fun,1.0);
  hreal_pion_4->Divide(fun,1.0);
  //hreal_pion_5->Divide(fun,1.0);

  hreal_kaon_0->Divide(fun,1.0);
  hreal_kaon_1->Divide(fun,1.0);
  hreal_kaon_2->Divide(fun,1.0);
  hreal_kaon_3->Divide(fun,1.0);
  hreal_kaon_4->Divide(fun,1.0);
  //hreal_kaon_5->Divide(fun,1.0);

  hreal_proton_0->Divide(fun,1.0);
  hreal_proton_1->Divide(fun,1.0);
  hreal_proton_2->Divide(fun,1.0);
  hreal_proton_3->Divide(fun,1.0);
  hreal_proton_4->Divide(fun,1.0);
  //hreal_proton_5->Divide(fun,1.0);


  hreal_pion_0->SetLineColor(kBlack);
  hreal_pion_1->SetLineColor(kRed);
  hreal_pion_2->SetLineColor(kBlue);
  hreal_pion_3->SetLineColor(kGreen+2);
  hreal_pion_4->SetLineColor(kMagenta+2);
  //hreal_pion_5->SetLineColor(kYellow+2);

  hreal_kaon_0->SetLineColor(kBlack);
  hreal_kaon_1->SetLineColor(kRed);
  hreal_kaon_2->SetLineColor(kBlue);
  hreal_kaon_3->SetLineColor(kGreen+2);
  hreal_kaon_4->SetLineColor(kMagenta+2);
  //hreal_kaon_5->SetLineColor(kYellow+2);

  hreal_proton_0->SetLineColor(kBlack);
  hreal_proton_1->SetLineColor(kRed);
  hreal_proton_2->SetLineColor(kBlue);
  hreal_proton_3->SetLineColor(kGreen+2);
  hreal_proton_4->SetLineColor(kMagenta+2);
  //hreal_proton_5->SetLineColor(kYellow+2);

  TH2F *hhhh = new TH2F("hhhh","",1,low,high,1,0.001,10000);
  hhhh->Draw();
  hreal_pion_0->Draw("same");
  hreal_pion_1->Draw("same");
  hreal_pion_2->Draw("same");
  hreal_pion_3->Draw("same");
  hreal_pion_4->Draw("same");
  //hreal_pion_5->Draw("same");
  TLegend *leg = new TLegend(0.68,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(hreal_pion_0,"0","l");
  leg->AddEntry(hreal_pion_1,"1","l");
  leg->AddEntry(hreal_pion_2,"2","l");
  leg->AddEntry(hreal_pion_3,"3","l");
  leg->AddEntry(hreal_pion_4,"4","l");
  //leg->AddEntry(hreal_pion_5,"5","l");
  leg->Draw();

  c1->Print("pions.gif");

  gSystem->Sleep(2000);

  hhhh->Draw();
  hreal_kaon_0->Draw("same");
  hreal_kaon_1->Draw("same");
  hreal_kaon_2->Draw("same");
  hreal_kaon_3->Draw("same");
  hreal_kaon_4->Draw("same");
  //hreal_kaon_5->Draw("same");
  leg->Draw();

  c1->Print("kaons.gif");

  gSystem->Sleep(2000);

  hhhh->Draw();
  hreal_proton_0->Draw("same");
  hreal_proton_1->Draw("same");
  hreal_proton_2->Draw("same");
  hreal_proton_3->Draw("same");
  hreal_proton_4->Draw("same");
  //hreal_proton_5->Draw("same");
  leg->Draw();

  c1->Print("protons.gif");

  gSystem->Sleep(2000);

  c1->Clear();

  c1->SetLogy(0);

  TH1F *hreal_pion = (TH1F *)hreal_pion_1->Clone();
  TH1F *hreal_kaon = (TH1F *)hreal_kaon_1->Clone();
  TH1F *hreal_proton = (TH1F *)hreal_proton_1->Clone();

  hreal_pion_0->Divide(hreal_pion);
  hreal_pion_1->Divide(hreal_pion);
  hreal_pion_2->Divide(hreal_pion);
  hreal_pion_3->Divide(hreal_pion);
  hreal_pion_4->Divide(hreal_pion);
  //hreal_pion_5->Divide(hreal_pion);

  hreal_kaon_0->Divide(hreal_kaon);
  hreal_kaon_1->Divide(hreal_kaon);
  hreal_kaon_2->Divide(hreal_kaon);
  hreal_kaon_3->Divide(hreal_kaon);
  hreal_kaon_4->Divide(hreal_kaon);
  //hreal_kaon_5->Divide(hreal_kaon);

  hreal_proton_0->Divide(hreal_proton);
  hreal_proton_1->Divide(hreal_proton);
  hreal_proton_2->Divide(hreal_proton);
  hreal_proton_3->Divide(hreal_proton);
  hreal_proton_4->Divide(hreal_proton);
  //hreal_proton_5->Divide(hreal_proton);

  TH2F *hhh2 = new TH2F("hhh2","",1,low,high,1,min,max);
  hhh2->Draw();
  hreal_pion_0->Draw("same");
  hreal_pion_1->Draw("same");
  hreal_pion_2->Draw("same");
  hreal_pion_3->Draw("same");
  hreal_pion_4->Draw("same");
  //hreal_pion_5->Draw("same");
  leg->Draw();

  c1->Print("pions_ratio.gif");

  gSystem->Sleep(2000);

  hhh2->Draw();
  hreal_kaon_0->Draw("same");
  hreal_kaon_1->Draw("same");
  hreal_kaon_2->Draw("same");
  hreal_kaon_3->Draw("same");
  hreal_kaon_4->Draw("same");
  //hreal_kaon_5->Draw("same");
  leg->Draw();

  c1->Print("kaons_ratio.gif");

  gSystem->Sleep(2000);

  hhh2->Draw();
  hreal_proton_0->Draw("same");
  hreal_proton_1->Draw("same");
  hreal_proton_2->Draw("same");
  hreal_proton_3->Draw("same");
  hreal_proton_4->Draw("same");
  //hreal_proton_5->Draw("same");
  leg->Draw();

  c1->Print("protons_ratio.gif");

}



