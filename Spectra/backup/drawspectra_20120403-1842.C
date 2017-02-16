void drawspectra()
{

  cout<<"hello!  now drawing spectra!"<<endl;

  //doit();

  //exit(1);

  //for(int icent=0; icent<9; icent++)
  // for(int icent=0; icent<12; icent++)
  //   {
  //     for(int ipid=0; ipid<10; ipid++)
  // 	{
  // 	  for(int isec=0; isec<3; isec++)
  // 	    {
  // 	      if(isec>0) continue;
  // 	      if(icent>1&&icent<9) continue;
  // 	      doit(isec,ipid,icent);
  // 	    }
  // 	}
  //   }

  for(int icent=0; icent<12; icent++)
    {
      for(int ipid=0; ipid<10; ipid++)
	{
	  if(icent>1&&icent<9) continue;
	  doit(0,ipid,icent);
	}
    }


  cout<<"done!  have a nice day!"<<endl;

}

void doit(int sector=0, int pid=0, int centid=0)
{

  // --- beginning of code

  gStyle->SetOptTitle(0);

  TCanvas *c1 = new TCanvas("c1","",800,600);
  c1->SetFillColor(kWhite);
  c1->SetFrameFillColor(kWhite);
  c1->SetBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->SetLogy();



  // --- strings for filenames

  char sectorstring[10];
  sprintf(sectorstring,"tofw"); // "default"
  if(sector==0) sprintf(sectorstring,"tofw");
  if(sector==1) sprintf(sectorstring,"tofw_w1");
  if(sector==2) sprintf(sectorstring,"tofw_w2");


  char centstring[10];
  sprintf(centstring,"0092"); // "default"
  if(centid==0) sprintf(centstring,"0010");
  if(centid==1) sprintf(centstring,"1020");
  if(centid==2) sprintf(centstring,"2030");
  if(centid==3) sprintf(centstring,"3040");
  if(centid==4) sprintf(centstring,"4050");
  if(centid==5) sprintf(centstring,"5060");
  if(centid==6) sprintf(centstring,"6070");
  if(centid==7) sprintf(centstring,"7080");
  if(centid==8) sprintf(centstring,"8092");
  if(centid==9) sprintf(centstring,"2040");
  if(centid==10) sprintf(centstring,"4060");
  if(centid==11) sprintf(centstring,"6092");

  char bigcentstring[50];
  sprintf(bigcentstring,"MinBias"); // "default"
  if(centid==0) sprintf(bigcentstring,"0-10%%");
  if(centid==1) sprintf(bigcentstring,"10-20%%");
  if(centid==2) sprintf(bigcentstring,"20-30%%");
  if(centid==3) sprintf(bigcentstring,"30-40%%");
  if(centid==4) sprintf(bigcentstring,"40-50%%");
  if(centid==5) sprintf(bigcentstring,"50-60%%");
  if(centid==6) sprintf(bigcentstring,"60-70%%");
  if(centid==7) sprintf(bigcentstring,"70-80%%");
  if(centid==8) sprintf(bigcentstring,"80-92%%");
  if(centid==9) sprintf(bigcentstring,"20-40%%");
  if(centid==10) sprintf(bigcentstring,"40-60%%");
  if(centid==11) sprintf(bigcentstring,"60-92%%");


  // ------------------- //
  // --- this is new --- //
  // ------------------- //

  //bool epscale = (pid==2||pid==3)?true:false;
  bool epscale = (pid==2||pid==3||pid==8||pid==9)?true:false;
  //float epx[5] = {1.2,1.2,1.2,1.2,1.2};
  float epx[5];
  if(pid<=3)
    {
      epx[0] = 1.18;
      epx[1] = 1.18;
      epx[2] = 1.18;
      epx[3] = 1.18;
      epx[4] = 1.18;
    }
  if(pid>=8)
    {
      epx[0] = 1.18;
      epx[1] = 1.18;
      epx[2] = 1.18;
      epx[3] = 1.18;
      epx[4] = 1.18;
    }
  float eppt = (pid==3||pid==9)?4.0:3.0;
  cout<<"eppt is "<<eppt<<endl;

  if(centid>=2&&centid<10) centid=2;
  if(centid==10) centid=3;
  if(centid==11) centid=4;

  // ------------------- //
  // ---             --- //
  // ------------------- //

  // ---



  // --- ppg080 stuff

  float pT_ppg080[21], yield_ppg080[21], eyield_ppg080[21];
  float ept[21];
  char finname[30];
  //sprintf(finname,"ppg080/pi0_cent%s.dat",centstring);
  sprintf(finname,"ppg054/ppg054_cent%s.dat",centstring);
  ifstream fin080(finname);
  //for(int i=0; i<21; i++)
  for(int i=0; i<16; i++)
    {
      ept[i]=0;
      fin080>>pT_ppg080[i]>>yield_ppg080[i]>>eyield_ppg080[i];
    }
  fin080.close();

  //TGraphErrors *pion080 = new TGraphErrors(21,pT_ppg080,yield_ppg080,ept,eyield_ppg080);
  TGraphErrors *pion080 = new TGraphErrors(16,pT_ppg080,yield_ppg080,ept,eyield_ppg080);
  pion080->SetMarkerColor(kGreen+2);
  pion080->SetMarkerStyle(20);



  // --- ppg026 stuff

  float pTpos_ppg026[39], yieldpos_ppg026[39], eyieldpos_ppg026[39];
  float pTneg_ppg026[39], yieldneg_ppg026[39], eyieldneg_ppg026[39];
  float EPT[39];

  int number = 1;
  char finposname[30];
  char finnegname[30];
  if(pid<=3)
    {
      number = 28;
      sprintf(finposname,"ppg026/pospion_%s.dat",centstring);
      sprintf(finnegname,"ppg026/negpion_%s.dat",centstring);
    }
  else if(pid==4||pid==5)
    {
      number = 18;
      sprintf(finposname,"ppg026/poskaon_%s.dat",centstring);
      sprintf(finnegname,"ppg026/negkaon_%s.dat",centstring);
    }
  else if(pid>=6)
    {
      number = 39;
      sprintf(finposname,"ppg026/posproton_%s.dat",centstring);
      sprintf(finnegname,"ppg026/negproton_%s.dat",centstring);
    }
  else
    {
      cerr<<"unknown pid number, now dying a quick but horribly painful death"<<endl;
      exit(1);
    }

  ifstream finpos026(finposname);
  ifstream finneg026(finnegname);

  for(int i=0; i<number; i++)
    {
      EPT[i]=0;
      finpos026>>pTpos_ppg026[i]>>yieldpos_ppg026[i]>>eyieldpos_ppg026[i];
      finneg026>>pTneg_ppg026[i]>>yieldneg_ppg026[i]>>eyieldneg_ppg026[i];
    }
  finpos026.close();
  finneg026.close();

  TGraphErrors *ppgpos026 = new TGraphErrors(number,pTpos_ppg026,yieldpos_ppg026,EPT,eyieldpos_ppg026);
  ppgpos026->SetMarkerColor(kRed);
  ppgpos026->SetMarkerStyle(20);

  TGraphErrors *ppgneg026 = new TGraphErrors(number,pTneg_ppg026,yieldneg_ppg026,EPT,eyieldneg_ppg026);
  ppgneg026->SetMarkerColor(kRed);
  ppgneg026->SetMarkerStyle(20);

  // ---



  // --- input data

  char fnameinpospm[100];
  char fnameinnegpm[100];
  char fnameinposmp[100];
  char fnameinnegmp[100];
  char fnameinposcb[100];
  char fnameinnegcb[100];

  sprintf(fnameinpospm,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegpm,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameinposmp,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegmp,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameinposcb,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegcb,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

  ifstream finpospm;
  ifstream finnegpm;
  ifstream finposmp;
  ifstream finnegmp;
  ifstream finposcb;
  ifstream finnegcb;

  finpospm.open(fnameinpospm);
  finnegpm.open(fnameinnegpm);
  finposmp.open(fnameinposmp);
  finnegmp.open(fnameinnegmp);
  finposcb.open(fnameinposcb);
  finnegcb.open(fnameinnegcb);

  float pT_pospm[100], yield_pospm[100], eyield_pospm[100];
  float pT_negpm[100], yield_negpm[100], eyield_negpm[100];
  float pT_posmp[100], yield_posmp[100], eyield_posmp[100];
  float pT_negmp[100], yield_negmp[100], eyield_negmp[100];
  float pT_poscb[100], yield_poscb[100], eyield_poscb[100];
  float pT_negcb[100], yield_negcb[100], eyield_negcb[100];

  for(int i=0; i<100; i++)
    {
      // pospm
      finpospm>>pT_pospm[i]>>yield_pospm[i]>>eyield_pospm[i];
      // negpm
      finnegpm>>pT_negpm[i]>>yield_negpm[i]>>eyield_negpm[i];
      // posmp
      finposmp>>pT_posmp[i]>>yield_posmp[i]>>eyield_posmp[i];
      // negmp
      finnegmp>>pT_negmp[i]>>yield_negmp[i]>>eyield_negmp[i];
      // poscb
      finposcb>>pT_poscb[i]>>yield_poscb[i]>>eyield_poscb[i];
      // negcb
      finnegcb>>pT_negcb[i]>>yield_negcb[i]>>eyield_negcb[i];
      if(i<5||((pid==4||pid==5)&&i>39))
	{
	  yield_poscb[i] = -9;
	  yield_negcb[i] = -9;
	}
      if(pT_poscb[i]>eppt&&epscale)
      	{
	  //cout<<"here i am"<<endl;
	  //cout<<"correction is "<<epx[centid]<<endl;
      	  yield_poscb[i]*=epx[centid];
      	  eyield_poscb[i]*=epx[centid];
	  // don't correct antiprotons
      	  if(pid<6) yield_negcb[i]*=epx[centid];
      	  if(pid<6) eyield_negcb[i]*=epx[centid];
      	}
    }

  finpospm.close();
  finnegpm.close();
  finposmp.close();
  finnegmp.close();
  finposcb.close();
  finnegcb.close();



  // --- now input the rebinned data

  sprintf(fnameinpospm,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegpm,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameinposmp,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegmp,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameinposcb,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegcb,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

  finpospm.open(fnameinpospm);
  finnegpm.open(fnameinnegpm);
  finposmp.open(fnameinposmp);
  finnegmp.open(fnameinnegmp);
  finposcb.open(fnameinposcb);
  finnegcb.open(fnameinnegcb);

  float pTR_pospm[20], yieldR_pospm[20], eyieldR_pospm[20];
  float pTR_negpm[20], yieldR_negpm[20], eyieldR_negpm[20];
  float pTR_posmp[20], yieldR_posmp[20], eyieldR_posmp[20];
  float pTR_negmp[20], yieldR_negmp[20], eyieldR_negmp[20];
  float pTR_poscb[20], yieldR_poscb[20], eyieldR_poscb[20];
  float pTR_negcb[20], yieldR_negcb[20], eyieldR_negcb[20];

  for(int i=0; i<20; i++)
    {
      // pospm
      finpospm>>pTR_pospm[i]>>yieldR_pospm[i]>>eyieldR_pospm[i];
      // negpm
      finnegpm>>pTR_negpm[i]>>yieldR_negpm[i]>>eyieldR_negpm[i];
      // posmp
      finposmp>>pTR_posmp[i]>>yieldR_posmp[i]>>eyieldR_posmp[i];
      // negmp
      finnegmp>>pTR_negmp[i]>>yieldR_negmp[i]>>eyieldR_negmp[i];
      // poscb
      finposcb>>pTR_poscb[i]>>yieldR_poscb[i]>>eyieldR_poscb[i];
      // negcb
      finnegcb>>pTR_negcb[i]>>yieldR_negcb[i]>>eyieldR_negcb[i];
      if(i<1||((pid==4||pid==5)&&i>7))
	{
	  yieldR_poscb[i] = -9;
	  yieldR_negcb[i] = -9;
	}
      if(pTR_poscb[i]>eppt&&epscale)
      	{
	  //cout<<"here i am"<<endl;
	  //cout<<"correction is "<<epx[centid]<<endl;
      	  yieldR_poscb[i]*=epx[centid];
      	  eyieldR_poscb[i]*=epx[centid];
	  // don't correct antiprotons
      	  if(pid<6) yieldR_negcb[i]*=epx[centid];
      	  if(pid<6) eyieldR_negcb[i]*=epx[centid];
      	}
    }

  finpospm.close();
  finnegpm.close();
  finposmp.close();
  finnegmp.close();
  finposcb.close();
  finnegcb.close();



  // --- now make tgrapherrorses

  float pT[44], epT[44], yield[44], eyield[44];

  for(int i=0; i<44; i++)
    {
      pT[i] = -9;
      epT[i] = 0;
      yield[i] = -9;
      eyield[i] = 0;
      //if(i<30)
      if(i<40)
	{
	  pT[i] = pT_pospm[i];
	  epT[i] = 0;
	  yield[i] = yield_pospm[i];
	  eyield[i] = eyield_pospm[i];
	}
      //int k=i-24;
      //if(i>29)
      int k=i-32;
      if(i>39)
	{
	  pT[i] = pTR_pospm[k];
	  epT[i] = 0;
	  yield[i] = yieldR_pospm[k];
	  eyield[i] = eyieldR_pospm[k];
	}
      if(pid<=3&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
      if((pid==4||pid==5)&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
      if(pid>=6&&pT[i]<0.5)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
    }

  TGraphErrors *tge_pospm = new TGraphErrors(44,pT,yield,epT,eyield);
  tge_pospm->SetMarkerColor(kBlack);
  tge_pospm->SetMarkerStyle(20);

  TMultiGraph *tmg_pospm = new TMultiGraph();
  tmg_pospm->Add(tge_pospm);
  tmg_pospm->Add(ppgpos026);
  if(pid<=3) tmg_pospm->Add(pion080);
  tmg_pospm->Draw("ap");
  tmg_pospm->SetMaximum(1e3);
  tmg_pospm->SetMinimum(1e-7);
  tmg_pospm->GetXaxis()->SetLimits(0.0,6.0);
  tmg_pospm->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_pospm->GetXaxis()->CenterTitle();
  //tmg_pospm->GetYaxis()->SetTitle("Corrected Invariant Yield");
  tmg_pospm->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  tmg_pospm->GetYaxis()->CenterTitle();

  TPaveText *tptP_pospm = new TPaveText(0.5, 5e-7, 1.5, 5e-6, "br");
  tptP_pospm->SetFillColor(10);
  tptP_pospm->SetBorderSize(0);
  TText *textP_pospm = tptP_pospm->AddText(bigcentstring);
  tptP_pospm->Draw();

  TPaveText *tptP_pospm2 = new TPaveText(0.5, 1.2e3, 5.5, 6e3, "br");
  tptP_pospm2->SetFillColor(10);
  tptP_pospm2->SetBorderSize(0);
  TText *textP_pospm2 = tptP_pospm2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_pospm2->Draw();

  TLegend *leg_pospm = new TLegend(0.68,0.68,0.88,0.88);
  leg_pospm->SetFillColor(kWhite);
  leg_pospm->SetBorderSize(0);
  if(pid<=3)
    {
      leg_pospm->AddEntry(tge_pospm,"#pi^{+}, +- field","p");
      leg_pospm->AddEntry(ppgpos026,"#pi^{+}, ppg026","p");
      leg_pospm->AddEntry(pion080,"#pi^{0}, ppg080","p");
    }
  if(pid==4||pid==5)
    {
      leg_pospm->AddEntry(tge_pospm,"K^{+}, +- field","p");
      leg_pospm->AddEntry(ppgpos026,"K^{+}, ppg026","p");
    }
  if(pid>=6)
    {
      leg_pospm->AddEntry(tge_pospm,"p, +- field","p");
      leg_pospm->AddEntry(ppgpos026,"p, ppg026","p");
    }
  leg_pospm->Draw();

  char gifname_pospm[100];
  sprintf(gifname_pospm,"SpectraFigures/ptpid_%s_pospm_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_pospm[100];
  sprintf(epsname_pospm,"SpectraFigures/ptpid_%s_pospm_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  // c1->Print(gifname_pospm);
  // c1->Print(epsname_pospm);






  for(int i=0; i<44; i++)
    {
      pT[i] = -9;
      epT[i] = 0;
      yield[i] = -9;
      eyield[i] = 0;
      //if(i<30)
      if(i<40)
	{
	  pT[i] = pT_negpm[i];
	  epT[i] = 0;
	  yield[i] = yield_negpm[i];
	  eyield[i] = eyield_negpm[i];
	}
      //int k=i-24;
      //if(i>29)
      int k=i-32;
      if(i>39)
	{
	  pT[i] = pTR_negpm[k];
	  epT[i] = 0;
	  yield[i] = yieldR_negpm[k];
	  eyield[i] = eyieldR_negpm[k];
	}

      if(pid<=3&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
      if((pid==4||pid==5)&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
      if(pid>=6&&pT[i]<0.5)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
    }

  TGraphErrors *tge_negpm = new TGraphErrors(44,pT,yield,epT,eyield);
  tge_negpm->SetMarkerColor(kBlack);
  tge_negpm->SetMarkerStyle(20);

  TMultiGraph *tmg_negpm = new TMultiGraph();
  tmg_negpm->Add(tge_negpm);
  tmg_negpm->Add(ppgneg026);
  if(pid<=3) tmg_negpm->Add(pion080);
  tmg_negpm->Draw("ap");
  tmg_negpm->SetMaximum(1e3);
  tmg_negpm->SetMinimum(1e-7);
  tmg_negpm->GetXaxis()->SetLimits(0.0,6.0);
  tmg_negpm->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_negpm->GetXaxis()->CenterTitle();
  //tmg_negpm->GetYaxis()->SetTitle("Corrected Invariant Yield");
  tmg_negpm->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  tmg_negpm->GetYaxis()->CenterTitle();

  TPaveText *tptP_negpm = new TPaveText(0.5, 5e-7, 1.5, 5e-6, "br");
  tptP_negpm->SetFillColor(10);
  tptP_negpm->SetBorderSize(0);
  TText *textP_negpm = tptP_negpm->AddText(bigcentstring);
  tptP_negpm->Draw();

  TPaveText *tptP_negpm2 = new TPaveText(0.5, 1.2e3, 5.5, 6e3, "br");
  tptP_negpm2->SetFillColor(10);
  tptP_negpm2->SetBorderSize(0);
  TText *textP_negpm2 = tptP_negpm2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_negpm2->Draw();

  TLegend *leg_negpm = new TLegend(0.68,0.68,0.88,0.88);
  leg_negpm->SetFillColor(kWhite);
  leg_negpm->SetBorderSize(0);
  if(pid<=3)
    {
      leg_negpm->AddEntry(tge_negpm,"#pi^{-}, +- field","p");
      leg_negpm->AddEntry(ppgneg026,"#pi^{-}, ppg026","p");
      leg_negpm->AddEntry(pion080,"#pi^{0}, ppg080","p");
    }
  if(pid==4||pid==5)
    {
      leg_negpm->AddEntry(tge_negpm,"K^{-}, +- field","p");
      leg_negpm->AddEntry(ppgneg026,"K^{-}, ppg026","p");
    }
  if(pid>=6)
    {
      leg_negpm->AddEntry(tge_negpm,"#bar{p}, +- field","p");
      leg_negpm->AddEntry(ppgneg026,"#bar{p}, ppg026","p");
    }
  leg_negpm->Draw();

  char gifname_negpm[100];
  sprintf(gifname_negpm,"SpectraFigures/ptpid_%s_negpm_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_negpm[100];
  sprintf(epsname_negpm,"SpectraFigures/ptpid_%s_negpm_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  // c1->Print(gifname_negpm);
  // c1->Print(epsname_negpm);











  // ---

  for(int i=0; i<44; i++)
    {
      pT[i] = -9;
      epT[i] = 0;
      yield[i] = -9;
      eyield[i] = 0;
      //if(i<30)
      if(i<40)
	{
	  pT[i] = pT_posmp[i];
	  epT[i] = 0;
	  yield[i] = yield_posmp[i];
	  eyield[i] = eyield_posmp[i];
	}
      //int k=i-24;
      //if(i>29)
      int k=i-32;
      if(i>39)
	{
	  pT[i] = pTR_posmp[k];
	  epT[i] = 0;
	  yield[i] = yieldR_posmp[k];
	  eyield[i] = eyieldR_posmp[k];
	}

      if(pid<=3&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
      if((pid==4||pid==5)&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
      if(pid>=6&&pT[i]<0.5)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
    }

  TGraphErrors *tge_posmp = new TGraphErrors(44,pT,yield,epT,eyield);
  tge_posmp->SetMarkerColor(kBlack);
  tge_posmp->SetMarkerStyle(20);

  TMultiGraph *tmg_posmp = new TMultiGraph();
  tmg_posmp->Add(tge_posmp);
  tmg_posmp->Add(ppgpos026);
  if(pid<=3) tmg_posmp->Add(pion080);
  tmg_posmp->Draw("ap");
  tmg_posmp->SetMaximum(1e3);
  tmg_posmp->SetMinimum(1e-7);
  tmg_posmp->GetXaxis()->SetLimits(0.0,6.0);
  tmg_posmp->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_posmp->GetXaxis()->CenterTitle();
  //tmg_posmp->GetYaxis()->SetTitle("Corrected Invariant Yield");
  tmg_posmp->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  tmg_posmp->GetYaxis()->CenterTitle();

  TPaveText *tptP_posmp = new TPaveText(0.5, 5e-7, 1.5, 5e-6, "br");
  tptP_posmp->SetFillColor(10);
  tptP_posmp->SetBorderSize(0);
  TText *textP_posmp = tptP_posmp->AddText(bigcentstring);
  tptP_posmp->Draw();

  TPaveText *tptP_posmp2 = new TPaveText(0.5, 1.2e3, 5.5, 6e3, "br");
  tptP_posmp2->SetFillColor(10);
  tptP_posmp2->SetBorderSize(0);
  TText *textP_posmp2 = tptP_posmp2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_posmp2->Draw();

  TLegend *leg_posmp = new TLegend(0.68,0.68,0.88,0.88);
  leg_posmp->SetFillColor(kWhite);
  leg_posmp->SetBorderSize(0);
  if(pid<=3)
    {
      leg_posmp->AddEntry(tge_posmp,"#pi^{+}, -+ field","p");
      leg_posmp->AddEntry(ppgpos026,"#pi^{+}, ppg026","p");
      leg_posmp->AddEntry(pion080,"#pi^{0}, ppg080","p");
    }
  if(pid==4||pid==5)
    {
      leg_posmp->AddEntry(tge_posmp,"K^{+}, -+ field","p");
      leg_posmp->AddEntry(ppgpos026,"K^{+}, ppg026","p");
    }
  if(pid>=6)
    {
      leg_posmp->AddEntry(tge_posmp,"p, -+ field","p");
      leg_posmp->AddEntry(ppgpos026,"p, ppg026","p");
    }
  leg_posmp->Draw();

  char gifname_posmp[100];
  sprintf(gifname_posmp,"SpectraFigures/ptpid_%s_posmp_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_posmp[100];
  sprintf(epsname_posmp,"SpectraFigures/ptpid_%s_posmp_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  // c1->Print(gifname_posmp);
  // c1->Print(epsname_posmp);






  for(int i=0; i<44; i++)
    {
      pT[i] = -9;
      epT[i] = 0;
      yield[i] = -9;
      eyield[i] = 0;
      //if(i<30)
      if(i<40)
	{
	  pT[i] = pT_negmp[i];
	  epT[i] = 0;
	  yield[i] = yield_negmp[i];
	  eyield[i] = eyield_negmp[i];
	}
      //int k=i-24;
      //if(i>29)
      int k=i-32;
      if(i>39)
	{
	  pT[i] = pTR_negmp[k];
	  epT[i] = 0;
	  yield[i] = yieldR_negmp[k];
	  eyield[i] = eyieldR_negmp[k];
	}

      if(pid<=3&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
      if((pid==4||pid==5)&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
      if(pid>=6&&pT[i]<0.5)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
    }

  TGraphErrors *tge_negmp = new TGraphErrors(44,pT,yield,epT,eyield);
  tge_negmp->SetMarkerColor(kBlack);
  tge_negmp->SetMarkerStyle(20);

  TMultiGraph *tmg_negmp = new TMultiGraph();
  tmg_negmp->Add(tge_negmp);
  tmg_negmp->Add(ppgneg026);
  if(pid<=3) tmg_negmp->Add(pion080);
  tmg_negmp->Draw("ap");
  tmg_negmp->SetMaximum(1e3);
  tmg_negmp->SetMinimum(1e-7);
  tmg_negmp->GetXaxis()->SetLimits(0.0,6.0);
  tmg_negmp->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_negmp->GetXaxis()->CenterTitle();
  //tmg_negmp->GetYaxis()->SetTitle("Corrected Invariant Yield");
  tmg_negmp->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  tmg_negmp->GetYaxis()->CenterTitle();

  TPaveText *tptP_negmp = new TPaveText(0.5, 5e-7, 1.5, 5e-6, "br");
  tptP_negmp->SetFillColor(10);
  tptP_negmp->SetBorderSize(0);
  TText *textP_negmp = tptP_negmp->AddText(bigcentstring);
  tptP_negmp->Draw();

  TPaveText *tptP_negmp2 = new TPaveText(0.5, 1.2e3, 5.5, 6e3, "br");
  tptP_negmp2->SetFillColor(10);
  tptP_negmp2->SetBorderSize(0);
  TText *textP_negmp2 = tptP_negmp2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_negmp2->Draw();

  TLegend *leg_negmp = new TLegend(0.68,0.68,0.88,0.88);
  leg_negmp->SetFillColor(kWhite);
  leg_negmp->SetBorderSize(0);
  if(pid<=3)
    {
      leg_negmp->AddEntry(tge_negmp,"#pi^{-}, -+ field","p");
      leg_negmp->AddEntry(ppgneg026,"#pi^{-}, ppg026","p");
      leg_negmp->AddEntry(pion080,"#pi^{0}, ppg080","p");
    }
  if(pid==4||pid==5)
    {
      leg_negmp->AddEntry(tge_negmp,"K^{-}, -+ field","p");
      leg_negmp->AddEntry(ppgneg026,"K^{-}, ppg026","p");
    }
  if(pid>=6)
    {
      leg_negmp->AddEntry(tge_negmp,"#bar{p}, -+ field","p");
      leg_negmp->AddEntry(ppgneg026,"#bar{p}, ppg026","p");
    }
  leg_negmp->Draw();

  char gifname_negmp[100];
  sprintf(gifname_negmp,"SpectraFigures/ptpid_%s_negmp_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_negmp[100];
  sprintf(epsname_negmp,"SpectraFigures/ptpid_%s_negmp_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  // c1->Print(gifname_negmp);
  // c1->Print(epsname_negmp);



  // now do combined field

  // ---

  for(int i=0; i<44; i++)
    {
      pT[i] = -9;
      epT[i] = 0;
      yield[i] = -9;
      eyield[i] = 0;
      if(i<30)
      //if(i<40)
	{
	  pT[i] = pT_poscb[i];
	  epT[i] = 0;
	  yield[i] = yield_poscb[i];
	  eyield[i] = eyield_poscb[i];
	}
      int k=i-24;
      if(i>29)
      //int k=i-32;
      //if(i>39)
	{
	  pT[i] = pTR_poscb[k];
	  epT[i] = 0;
	  yield[i] = yieldR_poscb[k];
	  eyield[i] = eyieldR_poscb[k];
	}

      if(pid<=3&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
      if((pid==4||pid==5)&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
      if(pid>=6&&pT[i]<0.5)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
    }

  TGraphErrors *tge_poscb = new TGraphErrors(44,pT,yield,epT,eyield);
  tge_poscb->SetMarkerColor(kBlack);
  tge_poscb->SetMarkerStyle(20);

  c1->Clear();

  TMultiGraph *tmg_poscb = new TMultiGraph();
  tmg_poscb->Add(tge_poscb);
  tmg_poscb->Add(ppgpos026);
  if(pid<=3) tmg_poscb->Add(pion080);
  tmg_poscb->Draw("ap");
  tmg_poscb->SetMaximum(1e3);
  tmg_poscb->SetMinimum(1e-7);
  tmg_poscb->GetXaxis()->SetLimits(0.0,6.0);
  tmg_poscb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_poscb->GetXaxis()->CenterTitle();
  //tmg_poscb->GetYaxis()->SetTitle("Corrected Invariant Yield");
  tmg_poscb->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  tmg_poscb->GetYaxis()->CenterTitle();

  TPaveText *tptP_poscb = new TPaveText(0.5, 5e-7, 1.5, 5e-6, "br");
  tptP_poscb->SetFillColor(10);
  tptP_poscb->SetBorderSize(0);
  TText *textP_poscb = tptP_poscb->AddText(bigcentstring);
  tptP_poscb->Draw();

  TPaveText *tptP_poscb2 = new TPaveText(0.5, 1.2e3, 5.5, 6e3, "br");
  tptP_poscb2->SetFillColor(10);
  tptP_poscb2->SetBorderSize(0);
  TText *textP_poscb2 = tptP_poscb2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_poscb2->Draw();

  TLegend *leg_poscb = new TLegend(0.68,0.68,0.88,0.88);
  leg_poscb->SetFillColor(kWhite);
  leg_poscb->SetBorderSize(0);
  if(pid<=3)
    {
      leg_poscb->AddEntry(tge_poscb,"#pi^{+}, Run7","p");
      leg_poscb->AddEntry(ppgpos026,"#pi^{+}, ppg026","p");
      //leg_poscb->AddEntry(pion080,"#pi^{0}, ppg080","p");
      leg_poscb->AddEntry(pion080,"#pi^{0}, ppg054","p");
    }
  if(pid==4||pid==5)
    {
      leg_poscb->AddEntry(tge_poscb,"K^{+}, Run7","p");
      leg_poscb->AddEntry(ppgpos026,"K^{+}, ppg026","p");
    }
  if(pid>=6)
    {
      leg_poscb->AddEntry(tge_poscb,"p, Run7","p");
      leg_poscb->AddEntry(ppgpos026,"p, ppg026","p");
    }
  leg_poscb->Draw();

  char gifname_poscb[100];
  sprintf(gifname_poscb,"SpectraFigures/ptpid_%s_poscb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_poscb[100];
  sprintf(epsname_poscb,"SpectraFigures/ptpid_%s_poscb_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_poscb);
  c1->Print(epsname_poscb);






  for(int i=0; i<44; i++)
    {
      pT[i] = -9;
      epT[i] = 0;
      yield[i] = -9;
      eyield[i] = 0;
      if(i<30)
      //if(i<40)
	{
	  pT[i] = pT_negcb[i];
	  epT[i] = 0;
	  yield[i] = yield_negcb[i];
	  eyield[i] = eyield_negcb[i];
	}
      int k=i-24;
      if(i>29)
      //int k=i-32;
      //if(i>39)
	{
	  pT[i] = pTR_negcb[k];
	  epT[i] = 0;
	  yield[i] = yieldR_negcb[k];
	  eyield[i] = eyieldR_negcb[k];
	}

      if(pid<=3&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
      if((pid==4||pid==5)&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
      if(pid>=6&&pT[i]<0.5)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
    }

  TGraphErrors *tge_negcb = new TGraphErrors(44,pT,yield,epT,eyield);
  tge_negcb->SetMarkerColor(kBlack);
  tge_negcb->SetMarkerStyle(20);

  c1->Clear();

  TMultiGraph *tmg_negcb = new TMultiGraph();
  tmg_negcb->Add(tge_negcb);
  tmg_negcb->Add(ppgneg026);
  if(pid<=3) tmg_negcb->Add(pion080);
  tmg_negcb->Draw("ap");
  tmg_negcb->SetMaximum(1e3);
  tmg_negcb->SetMinimum(1e-7);
  tmg_negcb->GetXaxis()->SetLimits(0.0,6.0);
  tmg_negcb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_negcb->GetXaxis()->CenterTitle();
  //tmg_negcb->GetYaxis()->SetTitle("Corrected Invariant Yield");
  tmg_negcb->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  tmg_negcb->GetYaxis()->CenterTitle();

  TPaveText *tptP_negcb = new TPaveText(0.5, 5e-7, 1.5, 5e-6, "br");
  tptP_negcb->SetFillColor(10);
  tptP_negcb->SetBorderSize(0);
  TText *textP_negcb = tptP_negcb->AddText(bigcentstring);
  tptP_negcb->Draw();

  TPaveText *tptP_negcb2 = new TPaveText(0.5, 1.2e3, 5.5, 6e3, "br");
  tptP_negcb2->SetFillColor(10);
  tptP_negcb2->SetBorderSize(0);
  TText *textP_negcb2 = tptP_negcb2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_negcb2->Draw();

  TLegend *leg_negcb = new TLegend(0.68,0.68,0.88,0.88);
  leg_negcb->SetFillColor(kWhite);
  leg_negcb->SetBorderSize(0);
  if(pid<=3)
    {
      leg_negcb->AddEntry(tge_negcb,"#pi^{-}, Run7","p");
      leg_negcb->AddEntry(ppgneg026,"#pi^{-}, ppg026","p");
      //leg_negcb->AddEntry(pion080,"#pi^{0}, ppg080","p");
      leg_negcb->AddEntry(pion080,"#pi^{0}, ppg054","p");
    }
  if(pid==4||pid==5)
    {
      leg_negcb->AddEntry(tge_negcb,"K^{-}, Run7","p");
      leg_negcb->AddEntry(ppgneg026,"K^{-}, ppg026","p");
    }
  if(pid>=6)
    {
      leg_negcb->AddEntry(tge_negcb,"#bar{p}, Run7","p");
      leg_negcb->AddEntry(ppgneg026,"#bar{p}, ppg026","p");
    }
  leg_negcb->Draw();

  char gifname_negcb[100];
  sprintf(gifname_negcb,"SpectraFigures/ptpid_%s_negcb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_negcb[100];
  sprintf(epsname_negcb,"SpectraFigures/ptpid_%s_negcb_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_negcb);
  c1->Print(epsname_negcb);



}
