void fitm2_tripleG1_R5()
{


  float m2pi = 0.01948;
  float m2ka = 0.24332;
  float m2pr = 0.88035;

  TCanvas *c1 = new TCanvas();

  //TFile *fall = TFile::Open("outsum_low.root");
  //TFile *fall = TFile::Open("outnew_pp.root");

  TFile *flow = TFile::Open("outlowpm.root");
  TFile *full = TFile::Open("outhighpm.root");

  TH2F *hh_flow_pos = (TH2F *)flow->Get("m2pTdis_pos");
  TH2F *hh_full_pos = (TH2F *)full->Get("m2pTdis_pos");
  TH2F *hh_flow_neg = (TH2F *)flow->Get("m2pTdis_neg");
  TH2F *hh_full_neg = (TH2F *)full->Get("m2pTdis_neg");

  //TH2F *hh_full_pos = (TH2F *)fall->Get("m2pTdis_pos");
  //TH2F *hh_full_neg = (TH2F *)fall->Get("m2pTdis_neg");

  TF1 *funpion = new TF1("funpion","gaus",-5.0,5.0);
  TF1 *funkaon = new TF1("funkaon","gaus",-5.0,5.0);
  TF1 *funprot = new TF1("funprot","gaus",-5.0,5.0);
  TF1 *funpionA = new TF1("funpionA","gaus",-5.0,5.0);
  TF1 *funkaonA = new TF1("funkaonA","gaus",-5.0,5.0);
  TF1 *funprotA = new TF1("funprotA","gaus",-5.0,5.0);
  TF1 *superfun = new TF1("superfun","gaus(0)+gaus(3)+gaus(6)",-5.0,5.0);

  //TF1 *helperfun = new TF1("helperfun","gaus",-5.0,5.0);
  //helperfun->SetLineColor(kBlack);
  // fixing the mean makes the fits very bad
  //funpion->FixParameter(1,0.01948);
  //funkaon->FixParameter(1,0.24332);
  //superfun->FixParameter(1,0.01948);
  //superfun->FixParameter(4,0.24332);

  funpion->SetLineColor(kBlue);
  funkaon->SetLineColor(kGreen+2);
  funpionA->SetLineColor(kBlue);
  funkaonA->SetLineColor(kGreen+2);
  superfun->SetLineColor(kBlack);

  char pionfigname[100];
  char kaonfigname[100];
  char protfigname[100];



  TF1 *sigmapi = new TF1("sigmapi","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.2,5.0);
  TF1 *sigmaka = new TF1("sigmaka","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.3,5.0);
  TF1 *sigmapr = new TF1("sigmapr","[0]+[1]/x+[2]/x/x+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.5,5.0);

  sigmapi->SetParameter(0,-2.32986e-02);
  sigmapi->SetParameter(1,-1.30028e-03);
  sigmapi->SetParameter(2,-8.26991e-06);
  sigmapi->SetParameter(3, 5.56826e-02);
  sigmapi->SetParameter(4,-1.16173e-01);
  
  sigmaka->SetParameter(0, 1.17930e-02);  
  sigmaka->SetParameter(1,-1.54666e-02);
  sigmaka->SetParameter(2, 2.48918e-03);
  sigmaka->SetParameter(3, 6.50247e-02); 
  sigmaka->SetParameter(4,-1.61286e-01); 

  sigmapr->SetParameter(0,-6.19317e-03);  
  sigmapr->SetParameter(1, 9.01921e-03);
  sigmapr->SetParameter(2, 6.82347e-04);
  sigmapr->SetParameter(3, 6.07866e-02);
  sigmapr->SetParameter(4,-1.32903e-01);



  // ofstream fbothpionout("m2pT_both_pion_par.txt");
  // ofstream fbothkaonout("m2pT_both_kaon_par.txt");
  // ofstream fbothprotout("m2pT_both_prot_par.txt");


  TH1F *hdummy = new TH1F("hdummy","",1,-0.1,0.1);

  TH1F *help;
  TH1F *helppos;
  TH1F *helpneg;


  //for(int INDEX=0; INDEX<12; INDEX++)
  for(int INDEX=6; INDEX<12; INDEX++)
    {

      //float mom = i/10.0+0.05;
      float mom = INDEX/2.0+0.25;
      cout<<"mom is "<<mom<<endl;
      int i  = INDEX*5;

      // hh_full_pos->ProjectionY("hhpos",i+1,i+5);
      // hh_full_neg->ProjectionY("hhneg",i+1,i+5);

      //if (i<10) hh_flow_pos->ProjectionY("hhpos",i+1,i+5);
      if (i<30) hh_flow_pos->ProjectionY("hhpos",i+1,i+5);
      //if (i<40) hh_flow_pos->ProjectionY("hhpos",i+1,i+5);
      else hh_full_pos->ProjectionY("hhpos",i+1,i+5);
      //if (i<10) hh_flow_neg->ProjectionY("hhneg",i+1,i+5);
      if (i<30) hh_flow_neg->ProjectionY("hhneg",i+1,i+5);
      //if (i<40) hh_flow_neg->ProjectionY("hhneg",i+1,i+5);
      else hh_full_neg->ProjectionY("hhneg",i+1,i+5);

      TH1F *hh = (TH1F *)hhpos->Clone();
      hh->Add(hhneg);

      help = (TH1F *)hh->Clone();
      float max = help->GetBinContent(help->GetMaximumBin());


      if(i<10)
	{
	  help->SetMinimum(0);
	  //help->GetXaxis()->SetRange(81,220);
	  help->GetXaxis()->SetRange(51,250);
	  help->Fit("funpion","","",-0.07,0.07);
	  help->Fit("funkaon","","", 0.2,0.3);
	  //help->GetXaxis()->SetRange(160,220);
	  //help->Fit("funprot","","",0.81,0.95);
	  help->Fit("funprot","","",0.80,0.95);
	}
      if(i>=10&&i<15)
	{
	  help->SetMinimum(0);
	  //help->GetXaxis()->SetRange(81,220);
	  help->GetXaxis()->SetRange(51,250);
	  help->Fit("funpion","","",-0.03,0.06);
	  help->Fit("funkaon","","", 0.2,0.3);
	  //help->GetXaxis()->SetRange(160,220);
	  //help->Fit("funprot","","",0.81,0.95);
	  help->Fit("funprot","","",0.80,0.95);
	}
      if(i>=15&&i<20)
	{
	  help->SetMinimum(0);
	  //help->GetXaxis()->SetRange(81,220);
	  help->GetXaxis()->SetRange(51,250);
	  help->Fit("funpion","","",-0.07,0.07);
	  help->Fit("funkaon","","", 0.2,0.3);
	  //help->GetXaxis()->SetRange(160,220);
	  //help->Fit("funprot","","",0.81,0.97);
	  help->Fit("funprot","","",0.79,0.98);
	}
      if(i>=20&&i<25)
	{
	  help->SetMinimum(0);
	  help->GetXaxis()->SetRange(51,250);
	  help->Fit("funpion","","",-0.07,0.07);
	  help->Fit("funkaon","","", 0.2,0.3);
	  //help->GetXaxis()->SetRange(160,220);//CONSIDER REVISING
	  help->Fit("funprot","","",0.79,1.00);
	}
      if(i>=25&&i<30)
	{
	  help->SetMinimum(0);
	  help->GetXaxis()->SetRange(51,250);
	  help->Fit("funpion","","",-0.07,0.07);
	  help->Fit("funkaon","","", 0.2,0.3);
	  //help->GetXaxis()->SetRange(141,240); // GOOD REVISION, MAYBE REDO ANYWAY
	  help->Fit("funprot","","",0.76,1.05);
	}
      if(i>=30&&i<40)
	{
	  help->SetMinimum(0);
	  help->GetXaxis()->SetRange(51,250);
	  help->Fit("funpion","","",-0.15,0.1);
	  help->Fit("funkaon","","", 0.2,0.4);
	  //help->GetXaxis()->SetRange(51,250);
	  help->Fit("funprot","","",0.7,1.1);
	}
      if(i>=40&&i<50)
	{
	  help->SetMinimum(0);
	  help->GetXaxis()->SetRange(51,250);
	  help->Fit("funpion","","",-0.15,0.1);
	  help->Fit("funkaon","","", 0.2,0.4);
	  //help->GetXaxis()->SetRange(51,250);
	  help->Fit("funprot","","",0.7,1.1);
	}
      if(i>=50&&i<60)
	{
	  help->SetMinimum(0);
	  help->GetXaxis()->SetRange(51,250);
	  help->Fit("funpion","","",-0.15,0.1);
	  help->Fit("funkaon","","", 0.2,0.4);
	  //help->GetXaxis()->SetRange(51,250);
	  help->Fit("funprot","","",0.7,1.1);
	}
	 

      superfun->SetParameter(0,funpion->GetParameter(0));
      //superfun->SetParameter(1,funpion->GetParameter(1));
      //superfun->SetParameter(2,funpion->GetParameter(2));
      superfun->SetParameter(3,funkaon->GetParameter(0));
      //superfun->SetParameter(4,funkaon->GetParameter(1));
      //superfun->SetParameter(5,funkaon->GetParameter(2));
      superfun->SetParameter(6,funprot->GetParameter(0));
      //superfun->SetParameter(7,funprot->GetParameter(1));
      //superfun->SetParameter(8,funprot->GetParameter(2));
      // now set the par limits for fitting
      //superfun->SetParLimits(0,0.9*funpion->GetParameter(0),1.1*funpion->GetParameter(0));
      superfun->SetParLimits(1,0.9*m2pi,1.1*m2pi);
      superfun->SetParLimits(2,0.9*sigmapi->Eval(mom),1.1*sigmapi->Eval(mom)); // sigma
      //superfun->SetParLimits(3,0.9*funkaon->GetParameter(0),1.1*funkaon->GetParameter(0));
      superfun->SetParLimits(4,0.9*m2ka,1.00*m2ka);
      superfun->SetParLimits(5,0.9*sigmaka->Eval(mom),1.1*sigmaka->Eval(mom)); // sigma
      //superfun->SetParLimits(6,0.9*funprot->GetParameter(0),1.1*funprot->GetParameter(0));
      superfun->SetParLimits(7,0.9*m2pr,1.1*m2pr);
      superfun->SetParLimits(8,0.9*sigmapr->Eval(mom),1.1*sigmapr->Eval(mom)); // sigma
      if(i<30)help->Fit("superfun","","",-0.2,1.0);
      if(i>=30)help->Fit("superfun","","",-0.4,1.1);
      funpionA->SetParameter(0,superfun->GetParameter(0));
      funpionA->SetParameter(1,superfun->GetParameter(1));
      funpionA->SetParameter(2,superfun->GetParameter(2));
      funkaonA->SetParameter(0,superfun->GetParameter(3));
      funkaonA->SetParameter(1,superfun->GetParameter(4));
      funkaonA->SetParameter(2,superfun->GetParameter(5));
      funprotA->SetParameter(0,superfun->GetParameter(6));
      funprotA->SetParameter(1,superfun->GetParameter(7));
      funprotA->SetParameter(2,superfun->GetParameter(8));
      funpionA->Draw("same");
      funkaonA->Draw("same");
      funprotA->Draw("same");
      sprintf(pionfigname,"m2pT_figs/m2pT_both_tripleG_method1R5_%d.gif",i);
      c1->Print(pionfigname);
      sprintf(pionfigname,"m2pT_figs/m2pT_both_tripleG_method1R5_%d.eps",i);
      c1->Print(pionfigname);



      float pion_const = funpionA->GetParameter(0);
      float pion_mean  = funpionA->GetParameter(1);
      float pion_sigma = funpionA->GetParameter(2);
      float pion_int2s = funpionA->Integral((-2*pion_sigma)+pion_mean,(2*pion_sigma)+pion_mean);
      //float pion_integ = funpionA->Integral((-2*pion_sigma)+pion_mean,(2*pion_sigma)+pion_mean);
      //float pion_integ = funpionA->Integral(-2,2);
      float pion_integ = funpionA->Integral(-1,2);
      float kaon_const = funkaonA->GetParameter(0);
      float kaon_mean  = funkaonA->GetParameter(1);
      float kaon_sigma = funkaonA->GetParameter(2);
      float kaon_int2s = funkaonA->Integral((-2*kaon_sigma)+kaon_mean,(2*kaon_sigma)+kaon_mean);
      //float kaon_integ = funkaonA->Integral((-2*kaon_sigma)+kaon_mean,(2*kaon_sigma)+kaon_mean);
      //float kaon_integ = funkaonA->Integral(-1.8,2.2);
      float kaon_integ = funkaonA->Integral(-1,2);
      float prot_const = funprotA->GetParameter(0);
      float prot_mean  = funprotA->GetParameter(1);
      float prot_sigma = funprotA->GetParameter(2);
      float prot_int2s = funprotA->Integral((-2*prot_sigma)+prot_mean,(2*prot_sigma)+prot_mean);
      //float prot_integ = funprotA->Integral((-2*prot_sigma)+prot_mean,(2*prot_sigma)+prot_mean);
      //float prot_integ = funprotA->Integral(-1.2,2.8);
      float prot_integ = funprotA->Integral(-1,2);

      pion_integ *= 100;//binning?
      kaon_integ *= 100;//binning?
      prot_integ *= 100;//binning?

      float hist_integ = help->Integral(1,300);//-1,2 in GeV, exlcude under/over

      //cerr<<endl<<"max is "<<max<<endl
      cerr<<"max is "<<max
	  <<endl
	  <<"pion height is "<<pion_const
	  <<", pion height ratio is "<<pion_const/(float)max
	  <<endl
	  <<"kaon height is "<<kaon_const
	  <<", kaon height ratio is "<<kaon_const/(float)max
	  <<endl
	  <<"prot height is "<<prot_const
	  <<", prot height ratio is "<<prot_const/(float)max
	  <<endl
	  <<"histogram integral is "<<hist_integ
	  <<endl
	  <<"pion integral is "<<pion_integ
	  <<", pion integral ratio is "<<pion_integ/hist_integ
	  <<endl
	  <<"kaon integral is "<<kaon_integ
	  <<", kaon integral ratio is "<<kaon_integ/hist_integ
	  <<endl
	  <<"prot integral is "<<prot_integ
	  <<", prot integral ratio is "<<prot_integ/hist_integ
	  <<endl
	  <<"sum of integral ratios is "
	  <<(pion_integ/hist_integ)+(kaon_integ/hist_integ)+(prot_integ/hist_integ)
	  <<endl
	  <<"K/pi ratio is "<<kaon_int2s/pion_int2s
	  <<endl
	  <<"p/pi ratio is "<<prot_int2s/pion_int2s
	  <<endl;

    } // for loop












} // void fitm2

