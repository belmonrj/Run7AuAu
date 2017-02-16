void drawStar()
{

  cout<<"hello!  now drawing spectra!"<<endl;



  for(int icent=0; icent<5; icent++)
    {
      for(int ipid=0; ipid<3; ipid++)
	{
	  doit(0,ipid,icent);
	}
    }



  cout<<"done!  have a nice day!"<<endl;

}

void doit(int sector=0, int partid=0, int centid=0)
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
  else {cerr<<"uh oh "<<endl; exit(0);}
  
  char centstring[10];
  sprintf(centstring,"0092"); // "default"
  if(centid==0) sprintf(centstring,"0010");
  if(centid==1) sprintf(centstring,"1020");
  if(centid==2) sprintf(centstring,"2040");
  if(centid==3) sprintf(centstring,"4060");
  if(centid==4) sprintf(centstring,"6080");
  //if(centid==4) sprintf(centstring,"6092");//this comparison doesn't work at all

  char starcentstring[10];
  sprintf(starcentstring,"MB"); // "default"
  if(centid==0) sprintf(starcentstring,"0010");
  if(centid==1) sprintf(starcentstring,"1020");
  if(centid==2) sprintf(starcentstring,"2040");
  if(centid==3) sprintf(starcentstring,"4060");
  if(centid==4) sprintf(starcentstring,"6080");

  char bigcentstring[50];
  sprintf(bigcentstring,"MinBias"); // "default"
  if(centid==0) sprintf(bigcentstring,"0-10%%");
  if(centid==1) sprintf(bigcentstring,"10-20%%");
  if(centid==2) sprintf(bigcentstring,"20-40%%");
  if(centid==3) sprintf(bigcentstring,"40-60%%");
  if(centid==4) sprintf(bigcentstring,"60-80%%");
  //if(centid==4) sprintf(bigcentstring,"60-92%%");


  // ---


  bool pion = false;
  bool kaon = false;
  bool proton = false;
  if(partid==0) pion = true;
  if(partid==1) kaon = true;
  if(partid==2) proton = true;



  int pid = 0; // careful, may need to change value or revise code
  int pid1 = 0;
  int pid2 = 0;
  int pid3 = 0;

  // if(pion) pid = 0;
  // if(kaon) pid = 4;
  // if(proton) pid = 6;
  //if(pion) pid = 1;
  //if(kaon) pid = 5;
  //if(proton) pid = 7;
  if(pion) pid = 2;
  if(kaon) pid = 4;
  if(proton) pid = 8;
  //if(pion) pid = 3;
  //if(kaon) pid = 5;
  //if(proton) pid = 9;


  // --- ppg080 stuff

  float pT_ppg080[21], yield_ppg080[21], eyield_ppg080[21];
  float ept[21];
  char finname[30];
  sprintf(finname,"ppg080/pi0_cent%s.dat",centstring);
  ifstream fin080(finname);
  for(int i=0; i<21; i++)
    {
      ept[i]=0;
      fin080>>pT_ppg080[i]>>yield_ppg080[i]>>eyield_ppg080[i];
    }
  fin080.close();

  TGraphErrors *pion080 = new TGraphErrors(21,pT_ppg080,yield_ppg080,ept,eyield_ppg080);
  pion080->SetMarkerColor(kGreen+2);
  pion080->SetMarkerStyle(20);
  //pion080->SetMarkerColor(kRed);
  //pion080->SetMarkerStyle(kOpenSquare);

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



  // --- STAR stuff

  float pTpos_StarData[39], yieldpos_StarData[39], eyieldpos_StarData[39];
  float pTneg_StarData[39], yieldneg_StarData[39], eyieldneg_StarData[39];
  float EPT[39];

  //int number = 1;
  char finposnameS[30];
  char finnegnameS[30];
  if(pid<=3)
    {
      number = 29;
      sprintf(finposnameS,"StarData/pp_star_%s.dat",starcentstring);
      sprintf(finnegnameS,"StarData/pm_star_%s.dat",starcentstring);
    }
  else if(pid==4||pid==5)
    {
      number = 20;//blah
      sprintf(finposnameS,"StarData/k0s_starR_%s.dat",starcentstring);
      sprintf(finnegnameS,"StarData/k0s_starR_%s.dat",starcentstring);
    }
  else if(pid>=6)
    {
      number = 25;
      sprintf(finposnameS,"StarData/pr_star_%s.dat",starcentstring);
      sprintf(finnegnameS,"StarData/pb_star_%s.dat",starcentstring);
    }
  else
    {
      cerr<<"unknown pid number, now dying a quick but horribly painful death"<<endl;
      exit(1);
    }

  ifstream finposSTAR(finposnameS);
  ifstream finnegSTAR(finnegnameS);

  for(int i=0; i<number; i++)
    {
      EPT[i]=0;
      finposSTAR>>pTpos_StarData[i]>>yieldpos_StarData[i]>>eyieldpos_StarData[i];
      finnegSTAR>>pTneg_StarData[i]>>yieldneg_StarData[i]>>eyieldneg_StarData[i];

      if(!finposSTAR)
	{
	  pTpos_StarData[i]=-9;yieldpos_StarData[i]=-9;eyieldpos_StarData[i]=0;
	}
      if(!finnegSTAR)
	{
	  pTneg_StarData[i]=-9;yieldneg_StarData[i]=-9;eyieldneg_StarData[i]=0;
	}

    }
  finposSTAR.close();
  finnegSTAR.close();

  TGraphErrors *ppgposSTAR = new TGraphErrors(number,pTpos_StarData,yieldpos_StarData,EPT,eyieldpos_StarData);
  ppgposSTAR->SetMarkerColor(kBlue);
  ppgposSTAR->SetMarkerStyle(kFullStar);
  ppgposSTAR->SetMarkerSize(1.8);

  TGraphErrors *ppgnegSTAR = new TGraphErrors(number,pTneg_StarData,yieldneg_StarData,EPT,eyieldneg_StarData);
  ppgnegSTAR->SetMarkerColor(kBlue);
  ppgnegSTAR->SetMarkerStyle(kFullStar);
  ppgnegSTAR->SetMarkerSize(1.8);

  // ---


  // --- input data

  char fnameinposcb[100];
  char fnameinnegcb[100];

  sprintf(fnameinposcb,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegcb,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

  ifstream finposcb;
  ifstream finnegcb;

  finposcb.open(fnameinposcb);
  finnegcb.open(fnameinnegcb);

  float pT_poscb[100], yield_poscb[100], eyield_poscb[100];
  float pT_negcb[100], yield_negcb[100], eyield_negcb[100];

  for(int i=0; i<100; i++)
    {
      // poscb
      finposcb>>pT_poscb[i]>>yield_poscb[i]>>eyield_poscb[i];
      // negcb
      finnegcb>>pT_negcb[i]>>yield_negcb[i]>>eyield_negcb[i];
    }

  finposcb.close();
  finnegcb.close();



  // --- now input the rebinned data

  sprintf(fnameinposcb,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegcb,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

  finposcb.open(fnameinposcb);
  finnegcb.open(fnameinnegcb);

  float pTR_poscb[20], yieldR_poscb[20], eyieldR_poscb[20];
  float pTR_negcb[20], yieldR_negcb[20], eyieldR_negcb[20];

  for(int i=0; i<20; i++)
    {
      // poscb
      finposcb>>pTR_poscb[i]>>yieldR_poscb[i]>>eyieldR_poscb[i];
      // negcb
      finnegcb>>pTR_negcb[i]>>yieldR_negcb[i]>>eyieldR_negcb[i];
    }

  finposcb.close();
  finnegcb.close();





  // now do combined field

  // ---

  float pT[38], epT[38], yield[38], eyield[38];

  for(int i=0; i<38; i++)
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

      if(pT[i]>4.0&&(pid==1||pid==7)) // temp?
	{
	  yield[i] *= 1.2;
	  eyield[i] *= 1.2;
	}

      if(pid<=3&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
      if((pid==4||pid==5)&&(pT[i]<0.2||pT[i]>4.0))
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

  TGraphErrors *tge_poscb = new TGraphErrors(38,pT,yield,epT,eyield);
  tge_poscb->SetMarkerColor(kBlack);
  tge_poscb->SetMarkerStyle(20);

  TMultiGraph *tmg_poscb = new TMultiGraph();
  //  tmg_poscb->Add(tge_poscb);
  tmg_poscb->Add(ppgpos026);
  if(pid<=3) tmg_poscb->Add(pion080);
  //tmg_poscb->Add(ppgposSTAR);
  tmg_poscb->Add(tge_poscb);
  tmg_poscb->Add(ppgposSTAR);
  tmg_poscb->Draw("ap");
  tmg_poscb->SetMaximum(1e3);
  tmg_poscb->SetMinimum(1e-7);
  tmg_poscb->GetXaxis()->SetLimits(0.0,6.0);
  tmg_poscb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_poscb->GetXaxis()->CenterTitle();
  //tmg_poscb->GetYaxis()->SetTitle("Corrected Invariant Yield");
  tmg_poscb->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  tmg_poscb->GetYaxis()->CenterTitle();

  //TPaveText *tptP_poscb = new TPaveText(0.5, 5e-7, 1.5, 5e-6, "br");
  TPaveText *tptP_poscb = new TPaveText(0.5, 5e-7, 2.5, 1e-5, "br");
  tptP_poscb->SetFillColor(10);
  tptP_poscb->SetBorderSize(0);
  TText *textP_poscb = tptP_poscb->AddText(bigcentstring);
  tptP_poscb->Draw();

  TPaveText *tptP_poscb2 = new TPaveText(0.5, 1.2e3, 5.5, 6e3, "br");
  tptP_poscb2->SetFillColor(10);
  tptP_poscb2->SetBorderSize(0);
  TText *textP_poscb2 = tptP_poscb2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_poscb2->Draw();

  //TLegend *leg_poscb = new TLegend(0.68,0.68,0.88,0.88);
  TLegend *leg_poscb = new TLegend(0.58,0.58,0.88,0.88);
  leg_poscb->SetFillColor(kWhite);
  leg_poscb->SetBorderSize(0);
  if(pid<=3)
    {
      leg_poscb->AddEntry(tge_poscb,"#pi^{+}, Run7","p");
      leg_poscb->AddEntry(ppgpos026,"#pi^{+}, ppg026","p");
      leg_poscb->AddEntry(  pion080,"#pi^{0}, ppg080","p");
      leg_poscb->AddEntry(ppgposSTAR,"#pi^{+}, STAR","p");
    }
  if(pid==4||pid==5)
    {
      leg_poscb->AddEntry(tge_poscb,"K^{+}, Run7","p");
      leg_poscb->AddEntry(ppgpos026,"K^{+}, ppg026","p");
      if(centid==0) leg_poscb->AddEntry(ppgposSTAR,"K^{0}_{S}, STAR","p");
    }
  if(pid>=6)
    {
      leg_poscb->AddEntry(tge_poscb,"p, Run7","p");
      leg_poscb->AddEntry(ppgpos026,"p, ppg026","p");
      leg_poscb->AddEntry(ppgposSTAR,"p, STAR","p");
    }
  leg_poscb->Draw();

  char gifname_poscb[100];
  sprintf(gifname_poscb,"SpectraFigures/STAR_%s_poscb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_poscb[100];
  sprintf(epsname_poscb,"SpectraFigures/STAR_%s_poscb_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_poscb);
  c1->Print(epsname_poscb);






  for(int i=0; i<38; i++)
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

      if(pT[i]>4.0&&(pid==1||pid==7)) // temp?
	{
	  yield[i] *= 1.2;
	  eyield[i] *= 1.2;
	}

      if(pid<=3&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
      if((pid==4||pid==5)&&(pT[i]<0.2||pT[i]>4.0))
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

  TGraphErrors *tge_negcb = new TGraphErrors(38,pT,yield,epT,eyield);
  tge_negcb->SetMarkerColor(kBlack);
  tge_negcb->SetMarkerStyle(20);

  TMultiGraph *tmg_negcb = new TMultiGraph();
  //tmg_negcb->Add(tge_negcb);
  tmg_negcb->Add(ppgneg026);
  tmg_negcb->Add(ppgnegSTAR);
  if(pid<=3) tmg_negcb->Add(pion080);
  tmg_negcb->Add(tge_negcb);
  tmg_negcb->Draw("ap");
  tmg_negcb->SetMaximum(1e3);
  tmg_negcb->SetMinimum(1e-7);
  tmg_negcb->GetXaxis()->SetLimits(0.0,7.0);
  tmg_negcb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_negcb->GetXaxis()->CenterTitle();
  //tmg_negcb->GetYaxis()->SetTitle("Corrected Invariant Yield");
  tmg_negcb->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  tmg_negcb->GetYaxis()->CenterTitle();

  //TPaveText *tptP_negcb = new TPaveText(0.5, 5e-7, 1.5, 5e-6, "br");
  TPaveText *tptP_negcb = new TPaveText(0.5, 5e-7, 2.5, 1e-5, "br");
  tptP_negcb->SetFillColor(10);
  tptP_negcb->SetBorderSize(0);
  TText *textP_negcb = tptP_negcb->AddText(bigcentstring);
  tptP_negcb->Draw();

  TPaveText *tptP_negcb2 = new TPaveText(0.5, 1.2e3, 5.5, 6e3, "br");
  tptP_negcb2->SetFillColor(10);
  tptP_negcb2->SetBorderSize(0);
  TText *textP_negcb2 = tptP_negcb2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_negcb2->Draw();

  //TLegend *leg_negcb = new TLegend(0.68,0.68,0.88,0.88);
  TLegend *leg_negcb = new TLegend(0.58,0.58,0.88,0.88);
  leg_negcb->SetFillColor(kWhite);
  leg_negcb->SetBorderSize(0);
  if(pid<=3)
    {
      leg_negcb->AddEntry(tge_negcb,"#pi^{-}, Run7","p");
      leg_negcb->AddEntry(ppgneg026,"#pi^{-}, ppg026","p");
      leg_negcb->AddEntry(  pion080,"#pi^{0}, ppg080","p");
      leg_negcb->AddEntry(ppgnegSTAR,"#pi^{-}, STAR","p");
    }
  if(pid==4||pid==5)
    {
      leg_negcb->AddEntry(tge_negcb,"K^{-}, Run7","p");
      leg_negcb->AddEntry(ppgneg026,"K^{-}, ppg026","p");
      if(centid==0) leg_negcb->AddEntry(ppgnegSTAR,"K^{0}_{S}, STAR","p");
    }
  if(pid>=6)
    {
      leg_negcb->AddEntry(tge_negcb,"#bar{p}, Run7","p");
      leg_negcb->AddEntry(ppgneg026,"#bar{p}, ppg026","p");
    }
  leg_negcb->Draw();

  char gifname_negcb[100];
  sprintf(gifname_negcb,"SpectraFigures/STAR_%s_negcb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_negcb[100];
  sprintf(epsname_negcb,"SpectraFigures/STAR_%s_negcb_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_negcb);
  c1->Print(epsname_negcb);



}
