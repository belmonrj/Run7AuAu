void fit_background()
{

  cout<<"don't run me!!!"<<endl;
  cout<<"doing nothing..."<<endl;
  exit(0);

  //pion();

}

void pion()
{

  gStyle->SetOptFit(0);

  TCanvas *c1 = new TCanvas("c1","c1");
  c1->SetFillColor(kWhite);
  c1->SetBorderMode(0);
  c1->SetFrameFillColor(kWhite);
  c1->SetFrameBorderMode(0);

  TF1 *fpospmtest = new TF1("fpospmtest","gaus",-2,2);
  TF1 *fnegpmtest = new TF1("fnegpmtest","gaus",-2,2);
  TF1 *fposmptest = new TF1("fposmptest","gaus",-2,2);
  TF1 *fnegmptest = new TF1("fnegmptest","gaus",-2,2);
  TF1 *fpospm = new TF1("fpospm","gaus",-5,5);
  TF1 *fnegpm = new TF1("fnegpm","gaus",-5,5);
  TF1 *fposmp = new TF1("fposmp","gaus",-5,5);
  TF1 *fnegmp = new TF1("fnegmp","gaus",-5,5);

  fpospmtest->SetLineColor(kBlue);
  fposmptest->SetLineColor(kBlue);
  fnegpmtest->SetLineColor(kBlue);
  fnegmptest->SetLineColor(kBlue);

  fpospm->SetLineColor(kGray-1);
  fposmp->SetLineColor(kGray-1);
  fnegpm->SetLineColor(kGray-1);
  fnegmp->SetLineColor(kGray-1);

  // TF1 *fpospmtest = new TF1("fpospmtest","gaus",-2,2);
  // TF1 *fnegpmtest = new TF1("fnegpmtest","gaus",-2,2);
  // TF1 *fpospm = new TF1("fpospm","gaus(0)+gaus(3)",-5,5);
  // TF1 *fnegpm = new TF1("fnegpm","gaus(0)+gaus(3)",-5,5);
  // TF1 *fposmptest = new TF1("fposmptest","gaus",-2,2);
  // TF1 *fnegmptest = new TF1("fnegmptest","gaus",-2,2);
  // TF1 *fposmp = new TF1("fposmp","gaus(0)+gaus(3)",-5,5);
  // TF1 *fnegmp = new TF1("fnegmp","gaus(0)+gaus(3)",-5,5);

  // TF1 *fpospmfg = new TF1("fpospmfg","gaus",-5,5);
  // TF1 *fpospmbg = new TF1("fpospmbg","gaus",-5,5);
  // fpospmfg->SetLineColor(kRed);
  // fpospmbg->SetLineColor(kBlue);
  // TF1 *fnegpmfg = new TF1("fnegpmfg","gaus",-5,5);
  // TF1 *fnegpmbg = new TF1("fnegpmbg","gaus",-5,5);
  // fnegpmfg->SetLineColor(kRed);
  // fnegpmbg->SetLineColor(kBlue);
  // TF1 *fposmpfg = new TF1("fposmpfg","gaus",-5,5);
  // TF1 *fposmpbg = new TF1("fposmpbg","gaus",-5,5);
  // fposmpfg->SetLineColor(kRed);
  // fposmpbg->SetLineColor(kBlue);
  // TF1 *fnegmpfg = new TF1("fnegmpfg","gaus",-5,5);
  // TF1 *fnegmpbg = new TF1("fnegmpbg","gaus",-5,5);
  // fnegmpfg->SetLineColor(kRed);
  // fnegmpbg->SetLineColor(kBlue);

  char title[200];
  char figname[100];
  char total[100];
  char signal[100];
  char background[100];
  char total2[100];
  char signal2[100];
  char background2[100];
  TLegend *leg;
  TLegend *leg2;

  TFile *filepm = TFile::Open("outhighpm.root");
  if(!filepm) {cerr<<"Fatal Error!  Cannot open root file "<<endl; exit(1);}

  TH2F *hhtfwbgsdphi_pospm_pT = (TH2F *)filepm->Get("bkgrd_tofwsdphi_pT_back_pos_cent0");
  TH2F *hhtfwbgsdphi_negpm_pT = (TH2F *)filepm->Get("bkgrd_tofwsdphi_pT_back_neg_cent0");
 
  TFile *filemp = TFile::Open("outhighmp.root");
  if(!filemp) {cerr<<"Fatal Error!  Cannot open root file "<<endl; exit(1);}

  TH2F *hhtfwbgsdphi_posmp_pT = (TH2F *)filemp->Get("bkgrd_tofwsdphi_pT_back_pos_cent0");
  TH2F *hhtfwbgsdphi_negmp_pT = (TH2F *)filemp->Get("bkgrd_tofwsdphi_pT_back_neg_cent0");


  cout<<"now doing loop over pT"<<endl;

  gSystem->Sleep(500); // 1000 msec = 1 sec

  cout<<"this could be interesting"<<endl;

  gSystem->Sleep(500);// 1000 msec = 1 sec

  //exit(0);



  ofstream ftfwbgsdphipospmRpT("data/tfwbgsdphi_back_cent0_pospm_RpT.txt");
  ofstream ftfwbgsdphinegpmRpT("data/tfwbgsdphi_back_cent0_negpm_RpT.txt");
  ofstream ftfwbgsdphiposmpRpT("data/tfwbgsdphi_back_cent0_posmp_RpT.txt");
  ofstream ftfwbgsdphinegmpRpT("data/tfwbgsdphi_back_cent0_negmp_RpT.txt");

  for(int i=6; i<12; i++)
    {

      // need to adjust accordingly
      float ptlow = i/2.0;
      float pthigh = i/2.0 + 0.5;
      float pt = i/2.0 + 0.25;

      // ----------------- //
      // --- now pospm --- //
      // ----------------- //

      hhtfwbgsdphi_pospm_pT->ProjectionY("htfwbgsdphi_pospm_pT",i*5+1,i*5+5);
      htfwbgsdphi_pospm_pT->Fit("fpospmtest","R");
      htfwbgsdphi_pospm_pT->SetMinimum(0.0);
      sprintf(title,"tfwbgsdphi, back, 0-10%%,  %2.1f < p_{T} < %2.1f",ptlow,pthigh);
      htfwbgsdphi_pospm_pT->SetTitle(title);
      htfwbgsdphi_pospm_pT->Fit("fpospm","R");
      fpospmtest->Draw("same");
      sprintf(signal,"#mu=%3.2f, #sigma=%3.2f",fpospmtest->GetParameter(1),fpospmtest->GetParameter(2));
      sprintf(background,"#mu=%3.2f, #sigma=%3.2f",fpospm->GetParameter(1),fpospm->GetParameter(2));

      leg = new TLegend(0.12,0.18,0.32,0.38);
      leg->SetFillColor(kWhite);
      leg->SetBorderSize(0);
      leg->AddEntry(fpospmtest,signal,"l");
      leg->AddEntry(fpospm,background,"l");
      leg->Draw();
      
      sprintf(figname,"figsfit/tfwbgsdphi_back_cent0_pospm_RpT_dis_%d.gif",i);
      c1->Print(figname);
      sprintf(figname,"figsfit/tfwbgsdphi_back_cent0_pospm_RpT_dis_%d.eps",i);
      c1->Print(figname);

      ftfwbgsdphipospmRpT<<pt<<"\t"
			 <<fpospm->GetParameter(1)<<"\t"
			 <<fpospmtest->GetParameter(1)<<"\t"
			 <<fpospm->GetParameter(2)<<"\t"
			 <<fpospmtest->GetParameter(2)<<"\t"
			 <<endl;

      leg->Delete();

      // ----------------- //
      // --- now negpm --- //
      // ----------------- //

      hhtfwbgsdphi_negpm_pT->ProjectionY("htfwbgsdphi_negpm_pT",i*5+1,i*5+5);
      htfwbgsdphi_negpm_pT->Fit("fnegpmtest","R");
      htfwbgsdphi_negpm_pT->SetMinimum(0.0);
      sprintf(title,"tfwbgsdphi, back, 0-10%%,  %2.1f < p_{T} < %2.1f",ptlow,pthigh);
      htfwbgsdphi_negpm_pT->SetTitle(title);
      htfwbgsdphi_negpm_pT->Fit("fnegpm","R");
      fnegpmtest->Draw("same");
      sprintf(signal,"#mu=%3.2f, #sigma=%3.2f",fnegpmtest->GetParameter(1),fnegpmtest->GetParameter(2));
      sprintf(background,"#mu=%3.2f, #sigma=%3.2f",fnegpm->GetParameter(1),fnegpm->GetParameter(2));

      leg = new TLegend(0.12,0.18,0.32,0.38);
      leg->SetFillColor(kWhite);
      leg->SetBorderSize(0);
      leg->AddEntry(fnegpmtest,signal,"l");
      leg->AddEntry(fnegpm,background,"l");
      leg->Draw();
      
      sprintf(figname,"figsfit/tfwbgsdphi_back_cent0_negpm_RpT_dis_%d.gif",i);
      c1->Print(figname);
      sprintf(figname,"figsfit/tfwbgsdphi_back_cent0_negpm_RpT_dis_%d.eps",i);
      c1->Print(figname);

      ftfwbgsdphinegpmRpT<<pt<<"\t"
			 <<fnegpm->GetParameter(1)<<"\t"
			 <<fnegpmtest->GetParameter(1)<<"\t"
			 <<fnegpm->GetParameter(2)<<"\t"
			 <<fnegpmtest->GetParameter(2)<<"\t"
			 <<endl;

      leg->Delete();



      // ----------------- //
      // --- now posmp --- //
      // ----------------- //

      hhtfwbgsdphi_posmp_pT->ProjectionY("htfwbgsdphi_posmp_pT",i*5+1,i*5+5);
      htfwbgsdphi_posmp_pT->Fit("fposmptest","R");
      htfwbgsdphi_posmp_pT->SetMinimum(0.0);
      sprintf(title,"tfwbgsdphi, back, 0-10%%,  %2.1f < p_{T} < %2.1f",ptlow,pthigh);
      htfwbgsdphi_posmp_pT->SetTitle(title);
      htfwbgsdphi_posmp_pT->Fit("fposmp","R");
      fposmptest->Draw("same");
      sprintf(signal,"#mu=%3.2f, #sigma=%3.2f",fposmptest->GetParameter(1),fposmptest->GetParameter(2));
      sprintf(background,"#mu=%3.2f, #sigma=%3.2f",fposmp->GetParameter(1),fposmp->GetParameter(2));

      leg = new TLegend(0.12,0.18,0.32,0.38);
      leg->SetFillColor(kWhite);
      leg->SetBorderSize(0);
      leg->AddEntry(fposmptest,signal,"l");
      leg->AddEntry(fposmp,background,"l");
      leg->Draw();
      
      sprintf(figname,"figsfit/tfwbgsdphi_back_cent0_posmp_RpT_dis_%d.gif",i);
      c1->Print(figname);
      sprintf(figname,"figsfit/tfwbgsdphi_back_cent0_posmp_RpT_dis_%d.eps",i);
      c1->Print(figname);

      ftfwbgsdphiposmpRpT<<pt<<"\t"
			 <<fposmp->GetParameter(1)<<"\t"
			 <<fposmptest->GetParameter(1)<<"\t"
			 <<fposmp->GetParameter(2)<<"\t"
			 <<fposmptest->GetParameter(2)<<"\t"
			 <<endl;

      leg->Delete();

      // ----------------- //
      // --- now negmp --- //
      // ----------------- //

      hhtfwbgsdphi_negmp_pT->ProjectionY("htfwbgsdphi_negmp_pT",i*5+1,i*5+5);
      htfwbgsdphi_negmp_pT->Fit("fnegmptest","R");
      htfwbgsdphi_negmp_pT->SetMinimum(0.0);
      sprintf(title,"tfwbgsdphi, back, 0-10%%,  %2.1f < p_{T} < %2.1f",ptlow,pthigh);
      htfwbgsdphi_negmp_pT->SetTitle(title);
      htfwbgsdphi_negmp_pT->Fit("fnegmp","R");
      fnegmptest->Draw("same");
      sprintf(signal,"#mu=%3.2f, #sigma=%3.2f",fnegmptest->GetParameter(1),fnegmptest->GetParameter(2));
      sprintf(background,"#mu=%3.2f, #sigma=%3.2f",fnegmp->GetParameter(1),fnegmp->GetParameter(2));

      leg = new TLegend(0.12,0.18,0.32,0.38);
      leg->SetFillColor(kWhite);
      leg->SetBorderSize(0);
      leg->AddEntry(fnegmptest,signal,"l");
      leg->AddEntry(fnegmp,background,"l");
      leg->Draw();
      
      sprintf(figname,"figsfit/tfwbgsdphi_back_cent0_negmp_RpT_dis_%d.gif",i);
      c1->Print(figname);
      sprintf(figname,"figsfit/tfwbgsdphi_back_cent0_negmp_RpT_dis_%d.eps",i);
      c1->Print(figname);

      ftfwbgsdphinegmpRpT<<pt<<"\t"
			 <<fnegmp->GetParameter(1)<<"\t"
			 <<fnegmptest->GetParameter(1)<<"\t"
			 <<fnegmp->GetParameter(2)<<"\t"
			 <<fnegmptest->GetParameter(2)<<"\t"
			 <<endl;

      leg->Delete();



    }





}







