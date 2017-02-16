void piondrawppg()
{




  for(int icent=0; icent<12; icent++)
    {
      for(int ipid=0; ipid<4; ipid++)
	{
	  if(icent>1&&icent<9) continue;
	  doit(0,ipid,icent);
	}
    }
  
  


  cout<<"done!  have a nice day!"<<endl;

}

void doit(int sector=0, int pid=0, int centid=0)
{

  float howhigh = 7.0;



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



  // ---



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



  // --- ppg054 stuff

  float pT_ppg054[21], yield_ppg054[21], eyield_ppg054[21];
  float ept[21];
  char finname[30];
  sprintf(finname,"ppg054/ppg054_cent%s.dat",centstring);
  ifstream fin054(finname);
  for(int i=0; i<21; i++)
    {
      ept[i]=0;
      fin054>>pT_ppg054[i]>>yield_ppg054[i]>>eyield_ppg054[i];
    }
  fin054.close();

  TGraphErrors *pion054 = new TGraphErrors(16,pT_ppg054,yield_ppg054,ept,eyield_ppg054);
  pion054->SetMarkerColor(kMagenta+2);
  pion054->SetMarkerStyle(20);



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
      if(i<5||((pid==4||pid==5)&&i>39))
	{
	  yield_poscb[i] = -9;
	  yield_negcb[i] = -9;
	}
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
      if(i<1||((pid==4||pid==5)&&i>7))
	{
	  yieldR_poscb[i] = -9;
	  yieldR_negcb[i] = -9;
	}
    }

  finposcb.close();
  finnegcb.close();






  // now do combined field

  float pT[38], epT[38], yield[38], eyield[38];

  // ---

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

      if(pid<=3&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
    }

  TGraphErrors *tge_poscb = new TGraphErrors(38,pT,yield,epT,eyield);
  tge_poscb->SetMarkerColor(kBlack);
  tge_poscb->SetMarkerStyle(20);

  c1->Clear();

  TMultiGraph *tmg_poscb = new TMultiGraph();
  tmg_poscb->Add(ppgpos026);
  tmg_poscb->Add(pion080);
  tmg_poscb->Add(pion054);
  tmg_poscb->Add(tge_poscb);
  tmg_poscb->Draw("ap");
  tmg_poscb->SetMaximum(1e3);
  tmg_poscb->SetMinimum(1e-7);
  tmg_poscb->GetXaxis()->SetLimits(0.0,howhigh);
  tmg_poscb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_poscb->GetXaxis()->CenterTitle();
  //tmg_poscb->GetYaxis()->SetTitle("Corrected Invariant Yield");
  tmg_poscb->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  tmg_poscb->GetYaxis()->CenterTitle();

  //TPaveText *tptP_poscb = new TPaveText(0.5, 5e-7, 1.5, 5e-6, "br");
  TPaveText *tptP_poscb = new TPaveText(0.5, 1e-6, 2.5, 3e-5, "br");
  tptP_poscb->SetFillColor(10);
  tptP_poscb->SetBorderSize(0);
  TText *textP_poscb = tptP_poscb->AddText(bigcentstring);
  tptP_poscb->Draw();

  TPaveText *tptP_poscb2 = new TPaveText(0.5, 1.2e3, 5.5, 6e3, "br");
  tptP_poscb2->SetFillColor(10);
  tptP_poscb2->SetBorderSize(0);
  TText *textP_poscb2 = tptP_poscb2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_poscb2->Draw();

  TLegend *leg _poscb = new TLegend(0.58,0.58,0.88,0.88);
  leg_poscb->SetFillColor(kWhite);
  leg_poscb->SetBorderSize(0);
  leg_poscb->AddEntry(tge_poscb,"#pi^{+}, Run7","p");
  leg_poscb->AddEntry(ppgpos026,"#pi^{+}, ppg026","p");
  leg_poscb->AddEntry(pion054,"#pi^{0}, ppg054","p");
  leg_poscb->AddEntry(pion080,"#pi^{0}, ppg080","p");
  leg_poscb->Draw();

  char gifname_poscb[100];
  sprintf(gifname_poscb,"SpectraFigures/PionSingle_%s_poscb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_poscb[100];
  sprintf(epsname_poscb,"SpectraFigures/PionSingle_%s_poscb_%d_dis_cent%s.eps",sectorstring,pid,centstring);

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

      if(pid<=3&&pT[i]<0.2)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
    }

  TGraphErrors *tge_negcb = new TGraphErrors(38,pT,yield,epT,eyield);
  tge_negcb->SetMarkerColor(kBlack);
  tge_negcb->SetMarkerStyle(20);

  c1->Clear();

  TMultiGraph *tmg_negcb = new TMultiGraph();
  tmg_negcb->Add(ppgneg026);
  tmg_negcb->Add(pion080);
  tmg_negcb->Add(pion054);
  tmg_negcb->Add(tge_negcb);
  tmg_negcb->Draw("ap");
  tmg_negcb->SetMaximum(1e3);
  tmg_negcb->SetMinimum(1e-7);
  tmg_negcb->GetXaxis()->SetLimits(0.0,howhigh);
  tmg_negcb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_negcb->GetXaxis()->CenterTitle();
  //tmg_negcb->GetYaxis()->SetTitle("Corrected Invariant Yield");
  tmg_negcb->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  tmg_negcb->GetYaxis()->CenterTitle();

  //TPaveText *tptP_negcb = new TPaveText(0.5, 5e-7, 1.5, 5e-6, "br");
  TPaveText *tptP_negcb = new TPaveText(0.5, 1e-6, 2.5, 3e-5, "br");
  tptP_negcb->SetFillColor(10);
  tptP_negcb->SetBorderSize(0);
  TText *textP_negcb = tptP_negcb->AddText(bigcentstring);
  tptP_negcb->Draw();

  TPaveText *tptP_negcb2 = new TPaveText(0.5, 1.2e3, 5.5, 6e3, "br");
  tptP_negcb2->SetFillColor(10);
  tptP_negcb2->SetBorderSize(0);
  TText *textP_negcb2 = tptP_negcb2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_negcb2->Draw();

  TLegend *leg _negcb = new TLegend(0.58,0.58,0.88,0.88);
  leg_negcb->SetFillColor(kWhite);
  leg_negcb->SetBorderSize(0);
  leg_negcb->AddEntry(tge_negcb,"#pi^{-}, Run7","p");
  leg_negcb->AddEntry(ppgneg026,"#pi^{-}, ppg026","p");
  leg_negcb->AddEntry(pion054,"#pi^{0}, ppg054","p");
  leg_negcb->AddEntry(pion080,"#pi^{0}, ppg080","p");
  leg_negcb->Draw();

  char gifname_negcb[100];
  sprintf(gifname_negcb,"SpectraFigures/PionSingle_%s_negcb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_negcb[100];
  sprintf(epsname_negcb,"SpectraFigures/PionSingle_%s_negcb_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_negcb);
  c1->Print(epsname_negcb);



}
