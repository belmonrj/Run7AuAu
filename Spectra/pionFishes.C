void pionFishes()
{


  // doit(0,2,0);
  // exit(0);

  for(int icent=0; icent<5; icent++)
    {
      for(int ipid=0; ipid<4; ipid++)
	{
	  //if(ipid!=2) continue;
	  doit(0,ipid,icent);
	}
    }
  
  


  cout<<"done!  have a nice day!"<<endl;

}

void doit(int sector=0, int pid=0, int centid=0)
{

  //bool debug = true;
  bool debug = false;

  float howhigh = 8.0;



  // --- beginning of code

  gStyle->SetOptFit(0);
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
  else exit(0);

  char centstring[10];
  sprintf(centstring,"0092"); // "default"
  if(centid==0) sprintf(centstring,"0010");
  if(centid==1) sprintf(centstring,"1020");
  if(centid==2) sprintf(centstring,"2040");
  if(centid==3) sprintf(centstring,"4060");
  if(centid==4) sprintf(centstring,"6092");//this comparison doesn't work at all

  char bigcentstring[50];
  sprintf(bigcentstring,"MinBias"); // "default"
  if(centid==0) sprintf(bigcentstring,"0-10%%");
  if(centid==1) sprintf(bigcentstring,"10-20%%");
  if(centid==2) sprintf(bigcentstring,"20-40%%");
  if(centid==3) sprintf(bigcentstring,"40-60%%");
  if(centid==4) sprintf(bigcentstring,"60-92%%");




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
  pion080->SetMarkerColor(kRed);
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
  //pion054->SetMarkerColor(kMagenta+2);
  pion054->SetMarkerColor(kRed);
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
      if(debug&&i>29)
	{
	  //cout<<pT_poscb[i]<<"\t"<<yield_poscb[i]<<"\t"<<endl;
	  cout<<pT<<"\t"<<yield[i]<<"\t"<<endl;
	}
    }

  TGraphErrors *tge_poscb = new TGraphErrors(38,pT,yield,epT,eyield);
  tge_poscb->SetMarkerColor(kBlack);
  tge_poscb->SetMarkerStyle(20);




  TF1 *funpl7 = new TF1("funpl7","[0]*(1+[1]*x)^[2]",1.0,8.0);
  TF1 *funplS = new TF1("funplS","[0]*(1+[1]*x)^[2]",1.0,8.0);
  funpl7->SetLineColor(kBlack);
  funplS->SetLineColor(kRed);

  funpl7->SetParameter(0,10000);
  funpl7->SetParameter(1,0.8);
  funpl7->SetParameter(2,-10.0);
  funplS->SetParameter(0,10000);
  funplS->SetParameter(1,0.8);
  funplS->SetParameter(2,-10.0);


  TMultiGraph *tmg_poscb = new TMultiGraph();
  //tmg_poscb->Add(ppgpos026);
  tmg_poscb->Add(pion054);
  tmg_poscb->Add(tge_poscb);
  tmg_poscb->Draw("ap");
  //tge_poscb->Fit(funpl7,"","",1.0,7.0);
  pion054->Fit(funplS,"","",1.0,8.0);
  float scale = funplS->GetParameter(0);
  funpl7->SetParLimits(0,0.9*scale,1.1*scale);
  //funpl7->FixParameter(2,funplS->GetParameter(2));
  tge_poscb->Fit(funpl7,"","",1.0,6.0);
  funplS->Draw("same");
  funpl7->Draw("same");
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

  TPaveText *tptP_poscb2 = new TPaveText(0.5, 1.2e3, howhigh-0.5, 6e3, "br");
  tptP_poscb2->SetFillColor(10);
  tptP_poscb2->SetBorderSize(0);
  TText *textP_poscb2 = tptP_poscb2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_poscb2->Draw();

  char fitfun[100];
  sprintf(fitfun,"p_{0}(1+p_{1}p_{T})^{p_{2}}");
  char fitinf[100];
  float p0 = funpl7->GetParameter(0);
  float p1 = funpl7->GetParameter(1);
  float p2 = funpl7->GetParameter(2);
  //sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %1.2e, p_{2} = %1.2e",p0,p1,p2);
  sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %2.2f, p_{2} = %2.2f",p0,p1,p2);
  TPaveText *tpt_fit = new TPaveText(2.5,9e0,7.9,9e1);
  tpt_fit->SetFillColor(kWhite);
  tpt_fit->SetBorderSize(0);
  tpt_fit->AddText(fitinf);
  tpt_fit->SetTextColor(kBlack);
  tpt_fit->Draw();

  p0 = funplS->GetParameter(0);
  p1 = funplS->GetParameter(1);
  p2 = funplS->GetParameter(2);
  //sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %1.2e, p_{2} = %1.2e",p0,p1,p2);
  sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %2.2f, p_{2} = %2.2f",p0,p1,p2);
  TPaveText *tpt_fit2 = new TPaveText(2.5,9e-1,7.9,9e0);
  tpt_fit2->SetFillColor(kWhite);
  tpt_fit2->SetBorderSize(0);
  tpt_fit2->AddText(fitinf);
  tpt_fit2->SetTextColor(kRed);
  tpt_fit2->Draw();

  TPaveText *tpt_fit3 = new TPaveText(5.5,9e-2,7.5,5e-1);
  tpt_fit3->SetFillColor(kWhite);
  tpt_fit3->SetBorderSize(0);
  tpt_fit3->AddText(fitfun);
  tpt_fit3->SetTextColor(kBlack);
  tpt_fit3->Draw();

  TLegend *leg_poscb = new TLegend(0.58,0.58,0.88,0.88);
  leg_poscb->SetFillColor(kWhite);
  leg_poscb->SetBorderSize(0);
  leg_poscb->AddEntry(tge_poscb,"#pi^{+}, Run7","p");
  //leg_poscb->AddEntry(ppgpos026,"#pi^{+}, ppg026","p");
  leg_poscb->AddEntry(pion054,"#pi^{0}, ppg054","p");
  //leg_poscb->Draw();

  char gifname_poscb[100];
  sprintf(gifname_poscb,"SpectraFigures/PionFishesPPG054_%s_poscb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_poscb[100];
  sprintf(epsname_poscb,"SpectraFigures/PionFishesPPG054_%s_poscb_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_poscb);
  c1->Print(epsname_poscb);



  float ratio7[38], eratio7[38];
  float ratioS[38], eratioS[38];



  for(int i=0; i<38; i++)
    {
      if(debug&&i>29)
	{
	  cout<<pT[i]<<"\t"<<yield[i]<<"\t"<<funpl7->Eval(pT[i])<<"\t"<<yield[i]/funpl7->Eval(pT[i])<<endl;
	}
      ratio7[i] = yield[i]/(funpl7->Eval(pT[i]));
      ratioS[i] = yield[i]/(funplS->Eval(pT[i]));
      eratio7[i] = ratio7[i]*(eyield[i]/yield[i]);
      eratioS[i] = ratioS[i]*(eyield[i]/yield[i]);
    }
  TGraphErrors *tge_posra7 = new TGraphErrors(38,pT,ratio7,epT,eratio7);
  tge_posra7->SetMarkerColor(kBlack);
  tge_posra7->SetMarkerStyle(20);
  TGraphErrors *tge_posraS = new TGraphErrors(38,pT,ratioS,epT,eratioS);
  tge_posraS->SetMarkerColor(kRed);
  tge_posraS->SetMarkerStyle(20);

  c1->Clear();
  c1->SetLogy(0);

  TMultiGraph *tmgpos = new TMultiGraph();
  tmgpos->Add(tge_posra7);
  tmgpos->Add(tge_posraS);
  tmgpos->Draw("ap");
  TLine *line = new TLine(0.0,1.0,howhigh,1.0);
  line->Draw();
  tmgpos->SetMaximum(2.0);
  tmgpos->SetMinimum(0.0);
  tmgpos->GetXaxis()->SetLimits(0.0,howhigh);
  tmgpos->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgpos->GetXaxis()->CenterTitle();
  tmgpos->GetYaxis()->SetTitle("ratio yield/fit");
  tmgpos->GetYaxis()->CenterTitle();

  //TLegend *legpos = new TLegend(0.68,0.68,0.88,0.88);
  TLegend *legpos = new TLegend(0.18,0.68,0.38,0.88);
  legpos->SetFillColor(kWhite);
  legpos->SetBorderSize(0);
  legpos->AddEntry(tge_posra7,"run7 fit","p");
  legpos->AddEntry(tge_posraS,"#pi^{0} fit","p");
  legpos->Draw();

  sprintf(gifname_poscb,"RatioFigures/PionFishesPPG054_%s_poscb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  sprintf(epsname_poscb,"RatioFigures/PionFishesPPG054_%s_poscb_%d_dis_cent%s.eps",sectorstring,pid,centstring);
  c1->Print(gifname_poscb);
  c1->Print(epsname_poscb);








  c1->Clear();
  c1->SetLogy(1);

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

  TMultiGraph *tmg_negcb = new TMultiGraph();
  //tmg_negcb->Add(ppgneg026);
  tmg_negcb->Add(pion054);
  tmg_negcb->Add(tge_negcb);
  tmg_negcb->Draw("ap");
  funpl7->SetParLimits(0,0.9*scale,1.1*scale);
  //funpl7->FixParameter(2,funplS->GetParameter(2));
  tge_negcb->Fit(funpl7,"","",1.0,6.0);
  funplS->Draw("same");
  funpl7->Draw("same");
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

  TPaveText *tptP_negcb2 = new TPaveText(0.5, 1.2e3, howhigh-0.5, 6e3, "br");
  tptP_negcb2->SetFillColor(10);
  tptP_negcb2->SetBorderSize(0);
  TText *textP_negcb2 = tptP_negcb2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_negcb2->Draw();

  p0 = funpl7->GetParameter(0);
  p1 = funpl7->GetParameter(1);
  p2 = funpl7->GetParameter(2);
  //sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %1.2e, p_{2} = %1.2e",p0,p1,p2);
  sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %2.2f, p_{2} = %2.2f",p0,p1,p2);
  tpt_fit = new TPaveText(2.5,9e0,7.9,9e1);
  tpt_fit->SetFillColor(kWhite);
  tpt_fit->SetBorderSize(0);
  tpt_fit->AddText(fitinf);
  tpt_fit->SetTextColor(kBlack);
  tpt_fit->Draw();

  p0 = funplS->GetParameter(0);
  p1 = funplS->GetParameter(1);
  p2 = funplS->GetParameter(2);
  //sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %1.2e, p_{2} = %1.2e",p0,p1,p2);
  sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %2.2f, p_{2} = %2.2f",p0,p1,p2);
  tpt_fit2 = new TPaveText(2.5,9e-1,7.9,9e0);
  tpt_fit2->SetFillColor(kWhite);
  tpt_fit2->SetBorderSize(0);
  tpt_fit2->AddText(fitinf);
  tpt_fit2->SetTextColor(kRed);
  tpt_fit2->Draw();

  tpt_fit3 = new TPaveText(5.5,9e-2,7.5,5e-1);
  tpt_fit3->SetFillColor(kWhite);
  tpt_fit3->SetBorderSize(0);
  tpt_fit3->AddText(fitfun);
  tpt_fit3->SetTextColor(kBlack);
  tpt_fit3->Draw();

  TLegend *leg_negcb = new TLegend(0.58,0.58,0.88,0.88);
  leg_negcb->SetFillColor(kWhite);
  leg_negcb->SetBorderSize(0);
  leg_negcb->AddEntry(tge_negcb,"#pi^{-}, Run7","p");
  //leg_negcb->AddEntry(ppgneg026,"#pi^{-}, ppg026","p");
  leg_negcb->AddEntry(pion054,"#pi^{0}, ppg054","p");
  //leg_negcb->Draw();

  char gifname_negcb[100];
  sprintf(gifname_negcb,"SpectraFigures/PionFishesPPG054_%s_negcb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_negcb[100];
  sprintf(epsname_negcb,"SpectraFigures/PionFishesPPG054_%s_negcb_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_negcb);
  c1->Print(epsname_negcb);




  for(int i=0; i<38; i++)
    {
      ratio7[i] = yield[i]/(funpl7->Eval(pT[i]));
      ratioS[i] = yield[i]/(funplS->Eval(pT[i]));
      eratio7[i] = ratio7[i]*(eyield[i]/yield[i]);
      eratioS[i] = ratioS[i]*(eyield[i]/yield[i]);
    }
  TGraphErrors *tge_negra7 = new TGraphErrors(38,pT,ratio7,epT,eratio7);
  tge_negra7->SetMarkerColor(kBlack);
  tge_negra7->SetMarkerStyle(20);
  TGraphErrors *tge_negraS = new TGraphErrors(38,pT,ratioS,epT,eratioS);
  tge_negraS->SetMarkerColor(kRed);
  tge_negraS->SetMarkerStyle(20);

  c1->Clear();
  c1->SetLogy(0);

  TMultiGraph *tmgneg = new TMultiGraph();
  tmgneg->Add(tge_negra7);
  tmgneg->Add(tge_negraS);
  tmgneg->Draw("ap");
  TLine *line = new TLine(0.0,1.0,howhigh,1.0);
  line->Draw();
  tmgneg->SetMaximum(2.0);
  tmgneg->SetMinimum(0.0);
  tmgneg->GetXaxis()->SetLimits(0.0,howhigh);
  tmgneg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgneg->GetXaxis()->CenterTitle();
  tmgneg->GetYaxis()->SetTitle("ratio yield/fit");
  tmgneg->GetYaxis()->CenterTitle();

  //TLegend *legneg = new TLegend(0.68,0.68,0.88,0.88);
  TLegend *legneg = new TLegend(0.18,0.68,0.38,0.88);
  legneg->SetFillColor(kWhite);
  legneg->SetBorderSize(0);
  legneg->AddEntry(tge_negra7,"run7 fit","p");
  legneg->AddEntry(tge_negraS,"#pi^{0} fit","p");
  legneg->Draw();

  sprintf(gifname_negcb,"RatioFigures/PionFishesPPG054_%s_negcb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  sprintf(epsname_negcb,"RatioFigures/PionFishesPPG054_%s_negcb_%d_dis_cent%s.eps",sectorstring,pid,centstring);
  c1->Print(gifname_negcb);
  c1->Print(epsname_negcb);



  continue;












  TMultiGraph *tmg_poscbX = new TMultiGraph();
  //tmg_poscbX->Add(ppgpos026);
  tmg_poscbX->Add(pion080);
  tmg_poscbX->Add(tge_poscb);
  tmg_poscbX->Draw("ap");
  //tge_poscb->Fit(funpl7,"","",1.0,7.0);
  pion080->Fit(funplS,"","",1.0,8.0);
  float scale = funplS->GetParameter(0);
  funpl7->SetParLimits(0,0.9*scale,1.1*scale);
  //funpl7->FixParameter(2,funplS->GetParameter(2));
  tge_poscb->Fit(funpl7,"","",0.5,6.0);
  funplS->Draw("same");
  funpl7->Draw("same");
  tmg_poscbX->SetMaximum(1e3);
  tmg_poscbX->SetMinimum(1e-7);
  tmg_poscbX->GetXaxis()->SetLimits(0.0,howhigh);
  tmg_poscbX->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_poscbX->GetXaxis()->CenterTitle();
  //tmg_poscbX->GetYaxis()->SetTitle("Corrected Invariant Yield");
  tmg_poscbX->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  tmg_poscbX->GetYaxis()->CenterTitle();

  //TPaveText *tptP_poscbX = new TPaveText(0.5, 5e-7, 1.5, 5e-6, "br");
  TPaveText *tptP_poscbX = new TPaveText(0.5, 1e-6, 2.5, 3e-5, "br");
  tptP_poscbX->SetFillColor(10);
  tptP_poscbX->SetBorderSize(0);
  TText *textP_poscbX = tptP_poscbX->AddText(bigcentstring);
  tptP_poscbX->Draw();

  TPaveText *tptP_poscbX2 = new TPaveText(0.5, 1.2e3, howhigh-0.5, 6e3, "br");
  tptP_poscbX2->SetFillColor(10);
  tptP_poscbX2->SetBorderSize(0);
  TText *textP_poscbX2 = tptP_poscbX2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_poscbX2->Draw();

  char fitfun[100];
  sprintf(fitfun,"p_{0}(1+p_{1}p_{T})^{p_{2}}");
  char fitinf[100];
  float p0 = funpl7->GetParameter(0);
  float p1 = funpl7->GetParameter(1);
  float p2 = funpl7->GetParameter(2);
  //sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %1.2e, p_{2} = %1.2e",p0,p1,p2);
  sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %2.2f, p_{2} = %2.2f",p0,p1,p2);
  TPaveText *tpt_fitX = new TPaveText(2.5,9e0,7.9,9e1);
  tpt_fitX->SetFillColor(kWhite);
  tpt_fitX->SetBorderSize(0);
  tpt_fitX->AddText(fitinf);
  tpt_fitX->SetTextColor(kBlack);
  tpt_fitX->Draw();

  p0 = funplS->GetParameter(0);
  p1 = funplS->GetParameter(1);
  p2 = funplS->GetParameter(2);
  //sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %1.2e, p_{2} = %1.2e",p0,p1,p2);
  sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %2.2f, p_{2} = %2.2f",p0,p1,p2);
  TPaveText *tpt_fitX2 = new TPaveText(2.5,9e-1,7.9,9e0);
  tpt_fitX2->SetFillColor(kWhite);
  tpt_fitX2->SetBorderSize(0);
  tpt_fitX2->AddText(fitinf);
  tpt_fitX2->SetTextColor(kRed);
  tpt_fitX2->Draw();

  TPaveText *tpt_fitX3 = new TPaveText(5.5,9e-2,7.5,5e-1);
  tpt_fitX3->SetFillColor(kWhite);
  tpt_fitX3->SetBorderSize(0);
  tpt_fitX3->AddText(fitfun);
  tpt_fitX3->SetTextColor(kBlack);
  tpt_fitX3->Draw();

  TLegend *leg_poscbX = new TLegend(0.58,0.58,0.88,0.88);
  leg_poscbX->SetFillColor(kWhite);
  leg_poscbX->SetBorderSize(0);
  leg_poscbX->AddEntry(tge_poscb,"#pi^{+}, Run7","p");
  //leg_poscbX->AddEntry(ppgpos026,"#pi^{+}, ppg026","p");
  leg_poscbX->AddEntry(pion080,"#pi^{0}, ppg080","p");
  //leg_poscbX->Draw();

  char gifname_poscbX[100];
  sprintf(gifname_poscbX,"SpectraFigures/PionFishesPPG080_%s_poscb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_poscbX[100];
  sprintf(epsname_poscbX,"SpectraFigures/PionFishesPPG080_%s_poscb_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_poscbX);
  c1->Print(epsname_poscbX);




  TMultiGraph *tmg_negcbX = new TMultiGraph();
  //tmg_negcbX->Add(ppgneg026);
  tmg_negcbX->Add(pion080);
  tmg_negcbX->Add(tge_negcb);
  tmg_negcbX->Draw("ap");
  //tge_negcb->Fit(funpl7,"","",1.0,7.0);
  pion080->Fit(funplS,"","",1.0,8.0);
  float scale = funplS->GetParameter(0);
  funpl7->SetParLimits(0,0.9*scale,1.1*scale);
  //funpl7->FixParameter(2,funplS->GetParameter(2));
  tge_negcb->Fit(funpl7,"","",0.5,6.0);
  funplS->Draw("same");
  funpl7->Draw("same");
  tmg_negcbX->SetMaximum(1e3);
  tmg_negcbX->SetMinimum(1e-7);
  tmg_negcbX->GetXaxis()->SetLimits(0.0,howhigh);
  tmg_negcbX->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_negcbX->GetXaxis()->CenterTitle();
  //tmg_negcbX->GetYaxis()->SetTitle("Corrected Invariant Yield");
  tmg_negcbX->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  tmg_negcbX->GetYaxis()->CenterTitle();

  //TPaveText *tptP_negcbX = new TPaveText(0.5, 5e-7, 1.5, 5e-6, "br");
  TPaveText *tptP_negcbX = new TPaveText(0.5, 1e-6, 2.5, 3e-5, "br");
  tptP_negcbX->SetFillColor(10);
  tptP_negcbX->SetBorderSize(0);
  TText *textP_negcbX = tptP_negcbX->AddText(bigcentstring);
  tptP_negcbX->Draw();

  TPaveText *tptP_negcbX2 = new TPaveText(0.5, 1.2e3, howhigh-0.5, 6e3, "br");
  tptP_negcbX2->SetFillColor(10);
  tptP_negcbX2->SetBorderSize(0);
  TText *textP_negcbX2 = tptP_negcbX2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_negcbX2->Draw();

  //char fitfun[100];
  sprintf(fitfun,"p_{0}(1+p_{1}p_{T})^{p_{2}}");
  //char fitinf[100];
  p0 = funpl7->GetParameter(0);
  p1 = funpl7->GetParameter(1);
  p2 = funpl7->GetParameter(2);
  //sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %1.2e, p_{2} = %1.2e",p0,p1,p2);
  sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %2.2f, p_{2} = %2.2f",p0,p1,p2);
  TPaveText *tpt_fitX = new TPaveText(2.5,9e0,7.9,9e1);
  tpt_fitX->SetFillColor(kWhite);
  tpt_fitX->SetBorderSize(0);
  tpt_fitX->AddText(fitinf);
  tpt_fitX->SetTextColor(kBlack);
  tpt_fitX->Draw();

  p0 = funplS->GetParameter(0);
  p1 = funplS->GetParameter(1);
  p2 = funplS->GetParameter(2);
  //sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %1.2e, p_{2} = %1.2e",p0,p1,p2);
  sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %2.2f, p_{2} = %2.2f",p0,p1,p2);
  TPaveText *tpt_fitX2 = new TPaveText(2.5,9e-1,7.9,9e0);
  tpt_fitX2->SetFillColor(kWhite);
  tpt_fitX2->SetBorderSize(0);
  tpt_fitX2->AddText(fitinf);
  tpt_fitX2->SetTextColor(kRed);
  tpt_fitX2->Draw();

  TPaveText *tpt_fitX3 = new TPaveText(5.5,9e-2,7.5,5e-1);
  tpt_fitX3->SetFillColor(kWhite);
  tpt_fitX3->SetBorderSize(0);
  tpt_fitX3->AddText(fitfun);
  tpt_fitX3->SetTextColor(kBlack);
  tpt_fitX3->Draw();

  TLegend *leg_negcbX = new TLegend(0.58,0.58,0.88,0.88);
  leg_negcbX->SetFillColor(kWhite);
  leg_negcbX->SetBorderSize(0);
  leg_negcbX->AddEntry(tge_negcb,"#pi^{+}, Run7","p");
  //leg_negcbX->AddEntry(ppgneg026,"#pi^{+}, ppg026","p");
  leg_negcbX->AddEntry(pion080,"#pi^{0}, ppg080","p");
  //leg_negcbX->Draw();

  char gifname_negcbX[100];
  sprintf(gifname_negcbX,"SpectraFigures/PionFishesPPG080_%s_negcb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_negcbX[100];
  sprintf(epsname_negcbX,"SpectraFigures/PionFishesPPG080_%s_negcb_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_negcbX);
  c1->Print(epsname_negcbX);


}
