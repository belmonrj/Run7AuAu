void fit_signal()
{

  sign();

}

void sign()
{

  gStyle->SetOptTitle(1);
  gStyle->SetOptFit(0);

  TCanvas *c1 = new TCanvas("c1","c1");
  c1->SetFillColor(kWhite);
  c1->SetBorderMode(0);
  c1->SetFrameFillColor(kWhite);
  c1->SetFrameBorderMode(0);

  TF1 *fpospmtest = new TF1("fpospmtest","gaus",-2,2);
  TF1 *fnegpmtest = new TF1("fnegpmtest","gaus",-2,2);
  TF1 *fpospm = new TF1("fpospm","gaus(0)+gaus(3)",-5,5);
  TF1 *fnegpm = new TF1("fnegpm","gaus(0)+gaus(3)",-5,5);
  TF1 *fposmptest = new TF1("fposmptest","gaus",-2,2);
  TF1 *fnegmptest = new TF1("fnegmptest","gaus",-2,2);
  TF1 *fposmp = new TF1("fposmp","gaus(0)+gaus(3)",-5,5);
  TF1 *fnegmp = new TF1("fnegmp","gaus(0)+gaus(3)",-5,5);

  fpospmtest->SetLineColor(kBlack);
  fnegpmtest->SetLineColor(kBlack);
  fpospm->SetLineColor(kBlack);
  fnegpm->SetLineColor(kBlack);
  fposmptest->SetLineColor(kBlack);
  fnegmptest->SetLineColor(kBlack);
  fposmp->SetLineColor(kBlack);
  fnegmp->SetLineColor(kBlack);


  TF1 *fpospmfg = new TF1("fpospmfg","gaus",-5,5);
  TF1 *fpospmbg = new TF1("fpospmbg","gaus",-5,5);
  fpospmfg->SetLineColor(kRed);
  fpospmbg->SetLineColor(kBlue);
  TF1 *fnegpmfg = new TF1("fnegpmfg","gaus",-5,5);
  TF1 *fnegpmbg = new TF1("fnegpmbg","gaus",-5,5);
  fnegpmfg->SetLineColor(kRed);
  fnegpmbg->SetLineColor(kBlue);
  TF1 *fposmpfg = new TF1("fposmpfg","gaus",-5,5);
  TF1 *fposmpbg = new TF1("fposmpbg","gaus",-5,5);
  fposmpfg->SetLineColor(kRed);
  fposmpbg->SetLineColor(kBlue);
  TF1 *fnegmpfg = new TF1("fnegmpfg","gaus",-5,5);
  TF1 *fnegmpbg = new TF1("fnegmpbg","gaus",-5,5);
  fnegmpfg->SetLineColor(kRed);
  fnegmpbg->SetLineColor(kBlue);

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

  TH2F *hhtfwbgsdphi_pospm_pT = (TH2F *)filepm->Get("bkgrd_tofwsdphi_pT_sign_pos_cent0");
  TH2F *hhtfwbgsdphi_negpm_pT = (TH2F *)filepm->Get("bkgrd_tofwsdphi_pT_sign_neg_cent0");
 
  TFile *filemp = TFile::Open("outhighmp.root");
  if(!filemp) {cerr<<"Fatal Error!  Cannot open root file "<<endl; exit(1);}

  TH2F *hhtfwbgsdphi_posmp_pT = (TH2F *)filemp->Get("bkgrd_tofwsdphi_pT_sign_pos_cent0");
  TH2F *hhtfwbgsdphi_negmp_pT = (TH2F *)filemp->Get("bkgrd_tofwsdphi_pT_sign_neg_cent0");


  cout<<"now doing loop over pT"<<endl;

  gSystem->Sleep(500); // 1000 msec = 1 sec

  cout<<"this could be interesting"<<endl;

  gSystem->Sleep(500);// 1000 msec = 1 sec

  //exit(0);



  ifstream finpospmRpT("data/tfwbgsdphi_back_cent0_pospm_RpT.txt");
  ifstream finnegpmRpT("data/tfwbgsdphi_back_cent0_negpm_RpT.txt");
  ifstream finposmpRpT("data/tfwbgsdphi_back_cent0_posmp_RpT.txt");
  ifstream finnegmpRpT("data/tfwbgsdphi_back_cent0_negmp_RpT.txt");

  ofstream ftfwbgsdphipospmRpT("data/tfwbgsdphi_sign_cent0_pospm_RpT.txt");
  ofstream ftfwbgsdphinegpmRpT("data/tfwbgsdphi_sign_cent0_negpm_RpT.txt");
  ofstream ftfwbgsdphiposmpRpT("data/tfwbgsdphi_sign_cent0_posmp_RpT.txt");
  ofstream ftfwbgsdphinegmpRpT("data/tfwbgsdphi_sign_cent0_negmp_RpT.txt");


  for(int i=6; i<12; i++)
    {

      // need to adjust accordingly
      float ptlow = i/2.0;
      float pthigh = i/2.0 + 0.5;
      float pt = i/2.0 + 0.25;

      float temp0, mean, temp1, sigma, temp2;



      // ----------------- //
      // --- now pospm --- //
      // ----------------- //

      finpospmRpT>>temp0>>mean>>temp1>>sigma>>temp2;
      if(temp0!=pt) {cerr<<"UGH! Charlie Brown!"<<endl; exit(1);}

      hhtfwbgsdphi_pospm_pT->ProjectionY("htfwbgsdphi_pospm_pT",i*5+1,i*5+5);
      htfwbgsdphi_pospm_pT->Fit("fpospmtest","","",-1.4,1.4);
      htfwbgsdphi_pospm_pT->SetMinimum(0.0);
      sprintf(title,"tfwbgsdphi, sign, 0-10%%,  %2.1f < p_{T} < %2.1f",ptlow,pthigh);
      htfwbgsdphi_pospm_pT->SetTitle(title);

      fpospm->SetParameter(0,0.75*fpospmtest->GetParameter(0));
      fpospm->SetParameter(1,fpospmtest->GetParameter(1));
      fpospm->SetParameter(2,fpospmtest->GetParameter(2));
      fpospm->SetParameter(3,0.1*fpospmtest->GetParameter(0));
      fpospm->FixParameter(4,mean);
      fpospm->FixParameter(5,sigma);
      htfwbgsdphi_pospm_pT->Fit("fpospm","R");
      
      fpospmfg->SetParameter(0,fpospm->GetParameter(0));
      fpospmfg->SetParameter(1,fpospm->GetParameter(1));
      fpospmfg->SetParameter(2,fpospm->GetParameter(2));
      fpospmbg->SetParameter(0,fpospm->GetParameter(3));
      fpospmbg->SetParameter(1,fpospm->GetParameter(4));
      fpospmbg->SetParameter(2,fpospm->GetParameter(5));
      fpospmfg->Draw("same");
      fpospmbg->Draw("same");
      
      sprintf(total,"total");
      sprintf(signal,"#mu=%3.2f, #sigma=%3.2f",fpospmfg->GetParameter(1),fpospmfg->GetParameter(2));
      sprintf(background,"#mu=%3.2f, #sigma=%3.2f",fpospmbg->GetParameter(1),fpospmbg->GetParameter(2));

      leg = new TLegend(0.12,0.68,0.32,0.88);
      leg->SetFillColor(kWhite);
      leg->SetBorderSize(0);
      leg->AddEntry(fpospm,total,"l");
      leg->AddEntry(fpospmfg,signal,"l");
      leg->AddEntry(fpospmbg,background,"l");
      leg->Draw();
      
      sprintf(total2,"%d, %3.2f",
	      (int)10*fpospm->Integral(-2.0,2.0),
	      10*fpospm->Integral(-2.0,2.0)/htfwbgsdphi_pospm_pT->Integral(31,70));
      sprintf(signal2,"%d, %3.2f",
	      (int)10*fpospmfg->Integral(-2.0,2.0),
	      fpospmfg->Integral(-2.0,2.0)/fpospm->Integral(-2.0,2.0));
      sprintf(background2,"%d, %3.2f",
	      (int)10*fpospmbg->Integral(-2.0,2.0),
	      fpospmbg->Integral(-2.0,2.0)/fpospm->Integral(-2.0,2.0));
      
      leg2 = new TLegend(0.68,0.68,0.88,0.88);
      leg2->SetFillColor(kWhite);
      leg2->SetBorderSize(0);
      leg2->AddEntry(fpospm,total2,"l");
      leg2->AddEntry(fpospmfg,signal2,"l");
      leg2->AddEntry(fpospmbg,background2,"l");
      leg2->Draw();
      
      sprintf(figname,"figsfit/tfwbgsdphi_sign_cent0_pospm_RpT_dis_%d.gif",i);
      c1->Print(figname);
      sprintf(figname,"figsfit/tfwbgsdphi_sign_cent0_pospm_RpT_dis_%d.eps",i);
      c1->Print(figname);

      ftfwbgsdphipospmRpT<<pt<<"\t"<<
	fpospmfg->Integral(-2.0,2.0)/fpospm->Integral(-2.0,2.0)<<"\t"<<
	fpospmbg->Integral(-2.0,2.0)/fpospm->Integral(-2.0,2.0)<<"\t"<<
	10*fpospm->Integral(-2.0,2.0)/htfwbgsdphi_pospm_pT->Integral(31,70)<<endl;

      leg->Delete();

      // ----------------- //
      // --- now negpm --- //
      // ----------------- //

      finnegpmRpT>>temp0>>mean>>temp1>>sigma>>temp2;
      if(temp0!=pt) {cerr<<"UGH! Charlie Brown!"<<endl; exit(1);}

      hhtfwbgsdphi_negpm_pT->ProjectionY("htfwbgsdphi_negpm_pT",i*5+1,i*5+5);
      htfwbgsdphi_negpm_pT->Fit("fnegpmtest","","",-1.4,1.4);
      htfwbgsdphi_negpm_pT->SetMinimum(0.0);
      sprintf(title,"tfwbgsdphi, sign, 0-10%%,  %2.1f < p_{T} < %2.1f",ptlow,pthigh);
      htfwbgsdphi_negpm_pT->SetTitle(title);

      fnegpm->SetParameter(0,0.75*fnegpmtest->GetParameter(0));
      fnegpm->SetParameter(1,fnegpmtest->GetParameter(1));
      fnegpm->SetParameter(2,fnegpmtest->GetParameter(2));
      fnegpm->SetParameter(3,0.1*fnegpmtest->GetParameter(0));
      fnegpm->FixParameter(4,mean);
      fnegpm->FixParameter(5,sigma);
      htfwbgsdphi_negpm_pT->Fit("fnegpm","R");
      
      fnegpmfg->SetParameter(0,fnegpm->GetParameter(0));
      fnegpmfg->SetParameter(1,fnegpm->GetParameter(1));
      fnegpmfg->SetParameter(2,fnegpm->GetParameter(2));
      fnegpmbg->SetParameter(0,fnegpm->GetParameter(3));
      fnegpmbg->SetParameter(1,fnegpm->GetParameter(4));
      fnegpmbg->SetParameter(2,fnegpm->GetParameter(5));
      fnegpmfg->Draw("same");
      fnegpmbg->Draw("same");
      
      sprintf(total,"total");
      sprintf(signal,"#mu=%3.2f, #sigma=%3.2f",fnegpmfg->GetParameter(1),fnegpmfg->GetParameter(2));
      sprintf(background,"#mu=%3.2f, #sigma=%3.2f",fnegpmbg->GetParameter(1),fnegpmbg->GetParameter(2));

      leg = new TLegend(0.12,0.68,0.32,0.88);
      leg->SetFillColor(kWhite);
      leg->SetBorderSize(0);
      leg->AddEntry(fnegpm,total,"l");
      leg->AddEntry(fnegpmfg,signal,"l");
      leg->AddEntry(fnegpmbg,background,"l");
      leg->Draw();
      
      sprintf(total2,"%d, %3.2f",
	      (int)10*fnegpm->Integral(-2.0,2.0),
	      10*fnegpm->Integral(-2.0,2.0)/htfwbgsdphi_negpm_pT->Integral(31,70));
      sprintf(signal2,"%d, %3.2f",
	      (int)10*fnegpmfg->Integral(-2.0,2.0),
	      fnegpmfg->Integral(-2.0,2.0)/fnegpm->Integral(-2.0,2.0));
      sprintf(background2,"%d, %3.2f",
	      (int)10*fnegpmbg->Integral(-2.0,2.0),
	      fnegpmbg->Integral(-2.0,2.0)/fnegpm->Integral(-2.0,2.0));
      
      leg2 = new TLegend(0.68,0.68,0.88,0.88);
      leg2->SetFillColor(kWhite);
      leg2->SetBorderSize(0);
      leg2->AddEntry(fnegpm,total2,"l");
      leg2->AddEntry(fnegpmfg,signal2,"l");
      leg2->AddEntry(fnegpmbg,background2,"l");
      leg2->Draw();
      
      sprintf(figname,"figsfit/tfwbgsdphi_sign_cent0_negpm_RpT_dis_%d.gif",i);
      c1->Print(figname);
      sprintf(figname,"figsfit/tfwbgsdphi_sign_cent0_negpm_RpT_dis_%d.eps",i);
      c1->Print(figname);

      ftfwbgsdphinegpmRpT<<pt<<"\t"<<
	fnegpmfg->Integral(-2.0,2.0)/fnegpm->Integral(-2.0,2.0)<<"\t"<<
	fnegpmbg->Integral(-2.0,2.0)/fnegpm->Integral(-2.0,2.0)<<"\t"<<
	10*fnegpm->Integral(-2.0,2.0)/htfwbgsdphi_negpm_pT->Integral(31,70)<<endl;

      leg->Delete();



      // ----------------- //
      // --- now posmp --- //
      // ----------------- //

      finposmpRpT>>temp0>>mean>>temp1>>sigma>>temp2;
      if(temp0!=pt) {cerr<<"UGH! Charlie Brown!"<<endl; exit(1);}

      hhtfwbgsdphi_posmp_pT->ProjectionY("htfwbgsdphi_posmp_pT",i*5+1,i*5+5);
      htfwbgsdphi_posmp_pT->Fit("fposmptest","","",-1.4,1.4);
      htfwbgsdphi_posmp_pT->SetMinimum(0.0);
      sprintf(title,"tfwbgsdphi, sign, 0-10%%,  %2.1f < p_{T} < %2.1f",ptlow,pthigh);
      htfwbgsdphi_posmp_pT->SetTitle(title);

      fposmp->SetParameter(0,0.75*fposmptest->GetParameter(0));
      fposmp->SetParameter(1,fposmptest->GetParameter(1));
      fposmp->SetParameter(2,fposmptest->GetParameter(2));
      fposmp->SetParameter(3,0.1*fposmptest->GetParameter(0));
      fposmp->FixParameter(4,mean);
      fposmp->FixParameter(5,sigma);
      htfwbgsdphi_posmp_pT->Fit("fposmp","R");
      
      fposmpfg->SetParameter(0,fposmp->GetParameter(0));
      fposmpfg->SetParameter(1,fposmp->GetParameter(1));
      fposmpfg->SetParameter(2,fposmp->GetParameter(2));
      fposmpbg->SetParameter(0,fposmp->GetParameter(3));
      fposmpbg->SetParameter(1,fposmp->GetParameter(4));
      fposmpbg->SetParameter(2,fposmp->GetParameter(5));
      fposmpfg->Draw("same");
      fposmpbg->Draw("same");
      
      sprintf(total,"total");
      sprintf(signal,"#mu=%3.2f, #sigma=%3.2f",fposmpfg->GetParameter(1),fposmpfg->GetParameter(2));
      sprintf(background,"#mu=%3.2f, #sigma=%3.2f",fposmpbg->GetParameter(1),fposmpbg->GetParameter(2));

      leg = new TLegend(0.12,0.68,0.32,0.88);
      leg->SetFillColor(kWhite);
      leg->SetBorderSize(0);
      leg->AddEntry(fposmp,total,"l");
      leg->AddEntry(fposmpfg,signal,"l");
      leg->AddEntry(fposmpbg,background,"l");
      leg->Draw();
      
      sprintf(total2,"%d, %3.2f",
	      (int)10*fposmp->Integral(-2.0,2.0),
	      10*fposmp->Integral(-2.0,2.0)/htfwbgsdphi_posmp_pT->Integral(31,70));
      sprintf(signal2,"%d, %3.2f",
	      (int)10*fposmpfg->Integral(-2.0,2.0),
	      fposmpfg->Integral(-2.0,2.0)/fposmp->Integral(-2.0,2.0));
      sprintf(background2,"%d, %3.2f",
	      (int)10*fposmpbg->Integral(-2.0,2.0),
	      fposmpbg->Integral(-2.0,2.0)/fposmp->Integral(-2.0,2.0));
      
      leg2 = new TLegend(0.68,0.68,0.88,0.88);
      leg2->SetFillColor(kWhite);
      leg2->SetBorderSize(0);
      leg2->AddEntry(fposmp,total2,"l");
      leg2->AddEntry(fposmpfg,signal2,"l");
      leg2->AddEntry(fposmpbg,background2,"l");
      leg2->Draw();
      
      sprintf(figname,"figsfit/tfwbgsdphi_sign_cent0_posmp_RpT_dis_%d.gif",i);
      c1->Print(figname);
      sprintf(figname,"figsfit/tfwbgsdphi_sign_cent0_posmp_RpT_dis_%d.eps",i);
      c1->Print(figname);

      ftfwbgsdphiposmpRpT<<pt<<"\t"<<
	fposmpfg->Integral(-2.0,2.0)/fposmp->Integral(-2.0,2.0)<<"\t"<<
	fposmpbg->Integral(-2.0,2.0)/fposmp->Integral(-2.0,2.0)<<"\t"<<
	10*fposmp->Integral(-2.0,2.0)/htfwbgsdphi_posmp_pT->Integral(31,70)<<endl;

      leg->Delete();

      // ----------------- //
      // --- now negmp --- //
      // ----------------- //

      finnegmpRpT>>temp0>>mean>>temp1>>sigma>>temp2;
      if(temp0!=pt) {cerr<<"UGH! Charlie Brown!"<<endl; exit(1);}

      hhtfwbgsdphi_negmp_pT->ProjectionY("htfwbgsdphi_negmp_pT",i*5+1,i*5+5);
      htfwbgsdphi_negmp_pT->Fit("fnegmptest","","",-1.4,1.4);
      htfwbgsdphi_negmp_pT->SetMinimum(0.0);
      sprintf(title,"tfwbgsdphi, sign, 0-10%%,  %2.1f < p_{T} < %2.1f",ptlow,pthigh);
      htfwbgsdphi_negmp_pT->SetTitle(title);

      fnegmp->SetParameter(0,0.75*fnegmptest->GetParameter(0));
      fnegmp->SetParameter(1,fnegmptest->GetParameter(1));
      fnegmp->SetParameter(2,fnegmptest->GetParameter(2));
      fnegmp->SetParameter(3,0.1*fnegmptest->GetParameter(0));
      fnegmp->FixParameter(4,mean);
      fnegmp->FixParameter(5,sigma);
      htfwbgsdphi_negmp_pT->Fit("fnegmp","R");
      
      fnegmpfg->SetParameter(0,fnegmp->GetParameter(0));
      fnegmpfg->SetParameter(1,fnegmp->GetParameter(1));
      fnegmpfg->SetParameter(2,fnegmp->GetParameter(2));
      fnegmpbg->SetParameter(0,fnegmp->GetParameter(3));
      fnegmpbg->SetParameter(1,fnegmp->GetParameter(4));
      fnegmpbg->SetParameter(2,fnegmp->GetParameter(5));
      fnegmpfg->Draw("same");
      fnegmpbg->Draw("same");
      
      sprintf(total,"total");
      sprintf(signal,"#mu=%3.2f, #sigma=%3.2f",fnegmpfg->GetParameter(1),fnegmpfg->GetParameter(2));
      sprintf(background,"#mu=%3.2f, #sigma=%3.2f",fnegmpbg->GetParameter(1),fnegmpbg->GetParameter(2));

      leg = new TLegend(0.12,0.68,0.32,0.88);
      leg->SetFillColor(kWhite);
      leg->SetBorderSize(0);
      leg->AddEntry(fnegmp,total,"l");
      leg->AddEntry(fnegmpfg,signal,"l");
      leg->AddEntry(fnegmpbg,background,"l");
      leg->Draw();
      
      sprintf(total2,"%d, %3.2f",
	      (int)10*fnegmp->Integral(-2.0,2.0),
	      10*fnegmp->Integral(-2.0,2.0)/htfwbgsdphi_negmp_pT->Integral(31,70));
      sprintf(signal2,"%d, %3.2f",
	      (int)10*fnegmpfg->Integral(-2.0,2.0),
	      fnegmpfg->Integral(-2.0,2.0)/fnegmp->Integral(-2.0,2.0));
      sprintf(background2,"%d, %3.2f",
	      (int)10*fnegmpbg->Integral(-2.0,2.0),
	      fnegmpbg->Integral(-2.0,2.0)/fnegmp->Integral(-2.0,2.0));
      
      leg2 = new TLegend(0.68,0.68,0.88,0.88);
      leg2->SetFillColor(kWhite);
      leg2->SetBorderSize(0);
      leg2->AddEntry(fnegmp,total2,"l");
      leg2->AddEntry(fnegmpfg,signal2,"l");
      leg2->AddEntry(fnegmpbg,background2,"l");
      leg2->Draw();
      
      sprintf(figname,"figsfit/tfwbgsdphi_sign_cent0_negmp_RpT_dis_%d.gif",i);
      c1->Print(figname);
      sprintf(figname,"figsfit/tfwbgsdphi_sign_cent0_negmp_RpT_dis_%d.eps",i);
      c1->Print(figname);

      ftfwbgsdphinegmpRpT<<pt<<"\t"<<
	fnegmpfg->Integral(-2.0,2.0)/fnegmp->Integral(-2.0,2.0)<<"\t"<<
	fnegmpbg->Integral(-2.0,2.0)/fnegmp->Integral(-2.0,2.0)<<"\t"<<
	10*fnegmp->Integral(-2.0,2.0)/htfwbgsdphi_negmp_pT->Integral(31,70)<<endl;

      leg->Delete();






    }





}







