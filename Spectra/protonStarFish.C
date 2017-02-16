void protonStarFish()
{

  cout<<"hello!  now drawing spectra!"<<endl;


  // doit(0,8,0);
  // exit(0);

  for(int icent=0; icent<5; icent++)
    {
      for(int ipid=6; ipid<10; ipid++)
	{
	  //if(ipid!=8) continue;
	  doit(0,ipid,icent);
	}
    }



  cout<<"done!  have a nice day!"<<endl;

}

void doit(int sector=0, int partid=0, int centid=0)
{

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

  pid = partid; // is this right?





  // ---



  // --- STAR stuff

  float pTpos_StarData[39], yieldpos_StarData[39], eyieldpos_StarData[39];
  float pTneg_StarData[39], yieldneg_StarData[39], eyieldneg_StarData[39];
  float EPT[39];

  int number = 1;
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
      //number = 25;
      number = 26;
      sprintf(finposnameS,"StarData/pr_star_%s.dat",starcentstring);
      sprintf(finnegnameS,"StarData/pb_starnf_%s.dat",starcentstring);
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

  float pT[40], epT[40], yield[40], eyield[40];

  for(int i=0; i<40; i++)
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

      if(pid>=6&&pT[i]<0.5)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
    }

  TGraphErrors *tge_poscb = new TGraphErrors(40,pT,yield,epT,eyield);
  tge_poscb->SetMarkerColor(kBlack);
  tge_poscb->SetMarkerStyle(20);


  // fun->SetParameter(0,1000);
  // fun->SetParameter(1,0.8);
  // fun->SetParameter(2,-10.0);

  TF1 *funpl7 = new TF1("funpl7","[0]*(1+[1]*x)^[2]",3.0,8.0);
  TF1 *funplS = new TF1("funplS","[0]*(1+[1]*x)^[2]",3.0,8.0);
  funpl7->SetLineColor(kBlack);
  funplS->SetLineColor(kBlue);

  funpl7->SetParameter(0,10000);
  funpl7->SetParameter(1,0.8);
  funpl7->SetParameter(2,-10.0);
  funplS->SetParameter(0,10000);
  funplS->SetParameter(1,0.8);
  funplS->SetParameter(2,-10.0);


  TF1 *fun7 = new TF1("fun7","expo",3.0,8.0);
  TF1 *funS = new TF1("funS","expo",3.0,8.0);
  fun7->SetLineColor(kBlack);
  funS->SetLineColor(kBlue);



  TMultiGraph *tmg_poscb = new TMultiGraph();
  //  tmg_poscb->Add(tge_poscb);
  tmg_poscb->Add(ppgposSTAR);
  tmg_poscb->Add(tge_poscb);
  tmg_poscb->Draw("ap");
  // tge_poscb->Fit(fun7,"","",1.0,7.0;
  // ppgposSTAR->Fit(funS,"","",1.0,7.0);
  tge_poscb->Fit(funpl7,"","",3.0,7.0);
  float scale = funpl7->GetParameter(0);
  // if(centid<4) funplS->SetParLimits(0,0.9*scale,1.1*scale);
  // if(centid==4) funplS->SetParLimits(0,0.4*scale,1.0*scale);
  funplS->SetParLimits(0,0.5*scale,1.5*scale);
  ppgposSTAR->Fit(funplS,"","",3.0,8.0);
  funpl7->Draw("same");
  tmg_poscb->SetMaximum(1e2);
  tmg_poscb->SetMinimum(1e-8);
  tmg_poscb->GetXaxis()->SetLimits(0.0,8.0);
  tmg_poscb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_poscb->GetXaxis()->CenterTitle();
  //tmg_poscb->GetYaxis()->SetTitle("Corrected Invariant Yield");
  tmg_poscb->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  tmg_poscb->GetYaxis()->CenterTitle();

  //TPaveText *tptP_poscb = new TPaveText(0.5, 5e-7, 1.5, 5e-6, "br");
  //TPaveText *tptP_poscb = new TPaveText(0.5, 5e-7, 2.5, 1e-5, "br");
  TPaveText *tptP_poscb = new TPaveText(0.5, 5e-8, 2.5, 1e-6, "br");
  tptP_poscb->SetFillColor(10);
  tptP_poscb->SetBorderSize(0);
  TText *textP_poscb = tptP_poscb->AddText(bigcentstring);
  tptP_poscb->Draw();

  //TPaveText *tptP_poscb2 = new TPaveText(0.5, 1.2e3, 5.5, 6e3, "br");
  TPaveText *tptP_poscb2 = new TPaveText(0.5, 1.2e2, 7.5, 6e2, "br");
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
  TPaveText *tpt_fit = new TPaveText(2.5,5e0,7.9,5e1);
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
  TPaveText *tpt_fit2 = new TPaveText(2.5,5e-1,7.9,5e0);
  tpt_fit2->SetFillColor(kWhite);
  tpt_fit2->SetBorderSize(0);
  tpt_fit2->AddText(fitinf);
  tpt_fit2->SetTextColor(kBlue);
  tpt_fit2->Draw();

  TPaveText *tpt_fit3 = new TPaveText(5.5,9e-2,7.5,5e-1);
  tpt_fit3->SetFillColor(kWhite);
  tpt_fit3->SetBorderSize(0);
  tpt_fit3->AddText(fitfun);
  tpt_fit3->SetTextColor(kBlack);
  tpt_fit3->Draw();

  TLegend *leg_poscb = new TLegend(0.68,0.68,0.88,0.88);
  //TLegend *leg_poscb = new TLegend(0.58,0.58,0.88,0.88);
  leg_poscb->SetFillColor(kWhite);
  leg_poscb->SetBorderSize(0);
  leg_poscb->AddEntry(tge_poscb,"p, Run7","p");
  leg_poscb->AddEntry(ppgposSTAR,"p, STAR","p");
  //leg_poscb->Draw(); // don't draw to make room for fit info

  char gifname_poscb[100];
  sprintf(gifname_poscb,"SpectraFigures/protonStarFish_%s_poscb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_poscb[100];
  sprintf(epsname_poscb,"SpectraFigures/protonStarFish_%s_poscb_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_poscb);
  c1->Print(epsname_poscb);



  float ratio7[40], eratio7[40];
  float ratioS[40], eratioS[40];



  for(int i=0; i<40; i++)
    {
      ratio7[i] = yield[i]/(funpl7->Eval(pT[i]));
      ratioS[i] = yield[i]/(funplS->Eval(pT[i]));
      eratio7[i] = ratio7[i]*(eyield[i]/yield[i]);
      eratioS[i] = ratioS[i]*(eyield[i]/yield[i]);
    }
  TGraphErrors *tge_posra7 = new TGraphErrors(40,pT,ratio7,epT,eratio7);
  tge_posra7->SetMarkerColor(kBlack);
  tge_posra7->SetMarkerStyle(20);
  TGraphErrors *tge_posraS = new TGraphErrors(40,pT,ratioS,epT,eratioS);
  tge_posraS->SetMarkerColor(kBlue);
  tge_posraS->SetMarkerStyle(20);

  c1->Clear();
  c1->SetLogy(0);

  TMultiGraph *tmgpos = new TMultiGraph();
  tmgpos->Add(tge_posra7);
  //tmgpos->Add(tge_posraS);
  tmgpos->Draw("ap");
  TLine *line = new TLine(3.0,1.0,howhigh,1.0);
  line->Draw();
  tmgpos->SetMaximum(2.0);
  tmgpos->SetMinimum(0.0);
  tmgpos->GetXaxis()->SetLimits(3.0,howhigh);
  tmgpos->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgpos->GetXaxis()->CenterTitle();
  tmgpos->GetYaxis()->SetTitle("ratio yield/fit");
  tmgpos->GetYaxis()->CenterTitle();

  //TLegend *legpos = new TLegend(0.68,0.68,0.88,0.88);
  TLegend *legpos = new TLegend(0.18,0.68,0.38,0.88);
  legpos->SetFillColor(kWhite);
  legpos->SetBorderSize(0);
  legpos->AddEntry(tge_posra7,"run7 fit","p");
  //legpos->AddEntry(tge_posraS,"STAR fit","p");
  legpos->Draw();

  sprintf(gifname_poscb,"RatioFigures/protonStarFish_%s_poscb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  sprintf(epsname_poscb,"RatioFigures/protonStarFish_%s_poscb_%d_dis_cent%s.eps",sectorstring,pid,centstring);
  c1->Print(gifname_poscb);
  c1->Print(epsname_poscb);








  c1->Clear();
  c1->SetLogy(1);



  for(int i=0; i<40; i++)
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

      if(pid>=6&&pT[i]<0.5)
	{
	  yield[i]=-9;
	  eyield[i]=0;
	}
    }

  TGraphErrors *tge_negcb = new TGraphErrors(40,pT,yield,epT,eyield);
  tge_negcb->SetMarkerColor(kBlack);
  tge_negcb->SetMarkerStyle(20);

  TMultiGraph *tmg_negcb = new TMultiGraph();
  //tmg_negcb->Add(tge_negcb);
  tmg_negcb->Add(ppgnegSTAR);
  tmg_negcb->Add(tge_negcb);
  tmg_negcb->Draw("ap");
  tge_negcb->Fit(funpl7,"","",3.0,7.0);
  scale = funpl7->GetParameter(0);
  // if(centid<4) funplS->SetParLimits(0,0.9*scale,1.1*scale);
  // if(centid==4) funplS->SetParLimits(0,0.4*scale,1.0*scale);
  funplS->SetParLimits(0,0.5*scale,1.5*scale);
  ppgnegSTAR->Fit(funplS,"","",3.0,8.0);
  funpl7->Draw("same");
  tmg_negcb->SetMaximum(1e2);
  tmg_negcb->SetMinimum(1e-8);
  tmg_negcb->GetXaxis()->SetLimits(0.0,8.0);
  tmg_negcb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_negcb->GetXaxis()->CenterTitle();
  //tmg_negcb->GetYaxis()->SetTitle("Corrected Invariant Yield");
  tmg_negcb->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  tmg_negcb->GetYaxis()->CenterTitle();

  //TPaveText *tptP_negcb = new TPaveText(0.5, 5e-7, 1.5, 5e-6, "br");
  //TPaveText *tptP_negcb = new TPaveText(0.5, 5e-7, 2.5, 1e-5, "br");
  TPaveText *tptP_negcb = new TPaveText(0.5, 5e-8, 2.5, 1e-6, "br");
  tptP_negcb->SetFillColor(10);
  tptP_negcb->SetBorderSize(0);
  TText *textP_negcb = tptP_negcb->AddText(bigcentstring);
  tptP_negcb->Draw();

  TPaveText *tptP_negcb2 = new TPaveText(0.5, 1.2e2, 7.5, 6e2, "br");
  tptP_negcb2->SetFillColor(10);
  tptP_negcb2->SetBorderSize(0);
  TText *textP_negcb2 = tptP_negcb2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_negcb2->Draw();

  p0 = funpl7->GetParameter(0);
  p1 = funpl7->GetParameter(1);
  p2 = funpl7->GetParameter(2);
  //sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %1.2e, p_{2} = %1.2e",p0,p1,p2);
  sprintf(fitinf,"p_{0} = %1.2e, p_{1} = %2.2f, p_{2} = %2.2f",p0,p1,p2);
  tpt_fit = new TPaveText(2.5,5e0,7.9,5e1);
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
  tpt_fit2 = new TPaveText(2.5,5e-1,7.9,5e0);
  tpt_fit2->SetFillColor(kWhite);
  tpt_fit2->SetBorderSize(0);
  tpt_fit2->AddText(fitinf);
  tpt_fit2->SetTextColor(kBlue);
  tpt_fit2->Draw();

  tpt_fit3 = new TPaveText(5.5,9e-2,7.5,5e-1);
  tpt_fit3->SetFillColor(kWhite);
  tpt_fit3->SetBorderSize(0);
  tpt_fit3->AddText(fitfun);
  tpt_fit3->SetTextColor(kBlack);
  tpt_fit3->Draw();

  TLegend *leg_negcb = new TLegend(0.68,0.68,0.88,0.88);
  //TLegend *leg_negcb = new TLegend(0.58,0.58,0.88,0.88);
  leg_negcb->SetFillColor(kWhite);
  leg_negcb->SetBorderSize(0);
  leg_negcb->AddEntry(tge_negcb,"#bar{p}, Run7","p");
  leg_negcb->AddEntry(ppgnegSTAR,"p, STAR","p");
  //leg_negcb->Draw();


  char gifname_negcb[100];
  sprintf(gifname_negcb,"SpectraFigures/protonStarFish_%s_negcb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_negcb[100];
  sprintf(epsname_negcb,"SpectraFigures/protonStarFish_%s_negcb_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_negcb);
  c1->Print(epsname_negcb);






  for(int i=0; i<40; i++)
    {
      ratio7[i] = yield[i]/(funpl7->Eval(pT[i]));
      ratioS[i] = yield[i]/(funplS->Eval(pT[i]));
      eratio7[i] = ratio7[i]*(eyield[i]/yield[i]);
      eratioS[i] = ratioS[i]*(eyield[i]/yield[i]);
    }
  TGraphErrors *tge_negra7 = new TGraphErrors(40,pT,ratio7,epT,eratio7);
  tge_negra7->SetMarkerColor(kBlack);
  tge_negra7->SetMarkerStyle(20);
  TGraphErrors *tge_negraS = new TGraphErrors(40,pT,ratioS,epT,eratioS);
  tge_negraS->SetMarkerColor(kBlue);
  tge_negraS->SetMarkerStyle(20);

  c1->Clear();
  c1->SetLogy(0);

  TMultiGraph *tmgneg = new TMultiGraph();
  tmgneg->Add(tge_negra7);
  //tmgneg->Add(tge_negraS);
  tmgneg->Draw("ap");
  TLine *line = new TLine(3.0,1.0,howhigh,1.0);
  line->Draw();
  tmgneg->SetMaximum(2.0);
  tmgneg->SetMinimum(0.0);
  tmgneg->GetXaxis()->SetLimits(3.0,howhigh);
  tmgneg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgneg->GetXaxis()->CenterTitle();
  tmgneg->GetYaxis()->SetTitle("ratio yield/fit");
  tmgneg->GetYaxis()->CenterTitle();

  //TLegend *legneg = new TLegend(0.68,0.68,0.88,0.88);
  TLegend *legneg = new TLegend(0.18,0.68,0.38,0.88);
  legneg->SetFillColor(kWhite);
  legneg->SetBorderSize(0);
  legneg->AddEntry(tge_negra7,"run7 fit","p");
  //legneg->AddEntry(tge_negraS,"STAR fit","p");
  legneg->Draw();

  sprintf(gifname_negcb,"RatioFigures/protonStarFish_%s_negcb_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  sprintf(epsname_negcb,"RatioFigures/protonStarFish_%s_negcb_%d_dis_cent%s.eps",sectorstring,pid,centstring);
  c1->Print(gifname_negcb);
  c1->Print(epsname_negcb);



}
