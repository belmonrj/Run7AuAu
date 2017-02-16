void pubratios()
{

  // cout<<"hello! unfortunately, this is nowhere near as much fun "<<endl
  //     <<"as the name of the macro would suggest but it will make some"<<endl
  //     <<"nice plots of the ratios of the Run7 spectra to the"<<endl
  //     <<"published Run2 and Run4 spectra for you."<<endl;

  cout<<"hello! now starting!"<<endl;

  //doit(0,0,0);
  //doit(0,2,0);

  //exit(1);

  for(int icent=0; icent<9; icent++)
    {
      for(int ipid=0; ipid<10; ipid++)
	{
	  for(int isec=0; isec<3; isec++)
	    {
	      doit(isec,ipid,icent);
	      //cout<<"doit("<<isec<<","<<ipid<<","<<icent<<");"<<endl;
	    }
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
  c1->SetGrid();
  //c1->SetLogy();



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

  // ---



  // --- ppg080 stuff

  float pT_ppg080[23], yield_ppg080[23], eyield_ppg080[23];
  float ept[23];
  char finname[30];
  sprintf(finname,"ppg080/pi0_cent%s.dat",centstring);
  for(int i=0; i<23; i++)
    {
      pT_ppg080[i]=i/2.0+0.25;
      ept[i]=0;
      yield_ppg080[i]=0;
      eyield_ppg080[i]=0;
    }
  ifstream fin080(finname);
  for(int i=0; i<21; i++)
    {
      fin080>>pT_ppg080[i+2]>>yield_ppg080[i+2]>>eyield_ppg080[i+2];
    }
  fin080.close();




  // --- ppg026 stuff

  float pTpos_ppg026[45], yieldpos_ppg026[45], eyieldpos_ppg026[45];
  float pTneg_ppg026[45], yieldneg_ppg026[45], eyieldneg_ppg026[45];
  float EPT[45];

  for(int i=0; i<7; i++)
    {
      pTpos_ppg026[i] = i/10.0+0.05;
      //epTpos_ppg026[i] = 0;
      yieldpos_ppg026[i] = 0;
      eyieldpos_ppg026[i] = 0;
      pTneg_ppg026[i] = i/10.0+0.05;
      //epTneg_ppg026[i] = 0;
      yieldneg_ppg026[i] = 0;
      eyieldneg_ppg026[i] = 0;
      EPT[i]=0;
    }

  int number = 1;
  int offset = 0;
  char finposname[30];
  char finnegname[30];
  if(pid<=3)
    {
      number = 28;
      offset = 2;
      sprintf(finposname,"ppg026/pospion_%s.dat",centstring);
      sprintf(finnegname,"ppg026/negpion_%s.dat",centstring);
    }
  else if(pid==4||pid==5)
    {
      number = 18;
      offset = 2;
      sprintf(finposname,"ppg026/poskaon_%s.dat",centstring);
      sprintf(finnegname,"ppg026/negkaon_%s.dat",centstring);
    }
  else if(pid>=6)
    {
      number = 39;
      offset = 6;
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
      EPT[i+offset]=0;
      finpos026>>pTpos_ppg026[i+offset]>>yieldpos_ppg026[i+offset]>>eyieldpos_ppg026[i+offset];
      finneg026>>pTneg_ppg026[i+offset]>>yieldneg_ppg026[i+offset]>>eyieldneg_ppg026[i+offset];
    }
  finpos026.close();
  finneg026.close();
  


  // ---



  // --- input data

  char fnameinpospm[100];
  char fnameinnegpm[100];
  char fnameinposmp[100];
  char fnameinnegmp[100];
  char fnameinposcb[100];
  char fnameinnegcb[100];

  sprintf(fnameinpospm,"Data/ptpid_%s_pos_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegpm,"Data/ptpid_%s_neg_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameinposmp,"Data/ptpid_%s_pos_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegmp,"Data/ptpid_%s_neg_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameinposcb,"Data/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegcb,"Data/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

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
    }

  finpospm.close();
  finnegpm.close();
  finposmp.close();
  finnegmp.close();
  finposcb.close();
  finnegcb.close();


  c1->Clear();

  // --- now input the rebinned data
  // --- perfect for the pi0

  sprintf(fnameinpospm,"Data/R5_ptpid_%s_pos_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegpm,"Data/R5_ptpid_%s_neg_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameinposmp,"Data/R5_ptpid_%s_pos_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegmp,"Data/R5_ptpid_%s_neg_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameinposcb,"Data/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegcb,"Data/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

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
    }

  finpospm.close();
  finnegpm.close();
  finposmp.close();
  finnegmp.close();
  finposcb.close();
  finnegcb.close();





  float pT[45], epT[45], ratio[45], eratio[45];
  float pTA[45], epTA[45], yieldA[45], eyieldA[45];
  float pTB[45], epTB[45], yieldB[45], eyieldB[45];

  int j;

  for(int i=0; i<45; i++)
    {
      // A
      j=i;
      pTA[i] = -9;
      epTA[i] = 0;
      yieldA[i] = -9;
      eyieldA[i] = 0;
      j=i;
      pTA[j] = pT_pospm[i];
      epTA[j] = 0;
      yieldA[j] = yield_pospm[i];
      eyieldA[j] = eyield_pospm[i];
      pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;

      pTB[i] = pTpos_ppg026[i];
      epTB[i] = 0;
      yieldB[i] = yieldpos_ppg026[i];
      eyieldB[i] = eyieldpos_ppg026[i];

      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	}
    } // end of for loop for rebinning

  TGraphErrors *tge_pospm = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  tge_pospm->SetMarkerColor(kBlue);
  tge_pospm->SetMarkerStyle(20);

  // ---

  for(int i=0; i<45; i++)
    {
      // A
      j=i;
      pTA[i] = -9;
      epTA[i] = 0;
      yieldA[i] = -9;
      eyieldA[i] = 0;
      j=i;
      pTA[j] = pT_negmp[i];
      epTA[j] = 0;
      yieldA[j] = yield_negmp[i];
      eyieldA[j] = eyield_negmp[i];

      pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;

      pTB[i] = pTpos_ppg026[i];
      epTB[i] = 0;
      yieldB[i] = yieldpos_ppg026[i];
      eyieldB[i] = eyieldpos_ppg026[i];

      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	}
    } // end of for loop for rebinning


  TGraphErrors *tge_negmp = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  tge_negmp->SetMarkerColor(kRed);
  tge_negmp->SetMarkerStyle(21);

  // ---

  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tge_pospm);
  tmg->Add(tge_negmp);
  tmg->Draw("ap");
  tmg->SetMaximum(2.0);
  tmg->SetMinimum(0.0);
  tmg->GetXaxis()->SetLimits(0.0,6.0);
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();
  tmg->GetYaxis()->SetTitle("Ratio");
  tmg->GetYaxis()->CenterTitle();

  TPaveText *tptP = new TPaveText(0.51, 0.1, 1.49, 0.3, "br");
  tptP->SetFillColor(10);
  tptP->SetBorderSize(0);
  TText *textP = tptP->AddText(bigcentstring);
  tptP->Draw();

  TPaveText *tptP2 = new TPaveText(0.5, 2.04, 5.5, 2.2, "br");
  tptP2->SetFillColor(10);
  tptP2->SetBorderSize(0);
  TText *textP2 = tptP2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP2->Draw();

  TLegend *leg = new TLegend(0.68,0.68,0.88,0.88);
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  if(pid<=3)
    {
      leg->AddEntry(tge_pospm,"#pi^{+}, +- field","p");
      leg->AddEntry(tge_negmp,"#pi^{-}, -+ field","p");
    }
  if(pid==4||pid==5)
    {
      leg->AddEntry(tge_pospm,"K^{+}, +- field","p");
      leg->AddEntry(tge_negmp,"K^{-}, -+ field","p");
    }
  if(pid>=6)
    {
      leg->AddEntry(tge_pospm,"p, +- field","p");
      leg->AddEntry(tge_negmp,"#bar{p}, -+ field","p");
    }
  leg->Draw();

  char gifname_good[100];
  sprintf(gifname_good,"RatioFigures/published_%s_goodchfi_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_good[100];
  sprintf(epsname_good,"RatioFigures/published_%s_goodchfi_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_good);
  c1->Print(epsname_good);

  // --- now bad

  for(int i=0; i<45; i++)
    {
      // A
      j=i;
      pTA[i] = -9;
      epTA[i] = 0;
      yieldA[i] = -9;
      eyieldA[i] = 0;
      j=i;
      pTA[j] = pT_posmp[i];
      epTA[j] = 0;
      yieldA[j] = yield_posmp[i];
      eyieldA[j] = eyield_posmp[i];

      pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;

      pTB[i] = pTpos_ppg026[i];
      epTB[i] = 0;
      yieldB[i] = yieldpos_ppg026[i];
      eyieldB[i] = eyieldpos_ppg026[i];

      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	}
    } // end of for loop for rebinning


  TGraphErrors *tge_posmp = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  tge_posmp->SetMarkerColor(kBlue);
  tge_posmp->SetMarkerStyle(20);

  // ---

  for(int i=0; i<45; i++)
    {
      // A
      j=i;
      pTA[i] = -9;
      epTA[i] = 0;
      yieldA[i] = -9;
      eyieldA[i] = 0;
      j=i;
      pTA[j] = pT_negpm[i];
      epTA[j] = 0;
      yieldA[j] = yield_negpm[i];
      eyieldA[j] = eyield_negpm[i];

      pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;

      pTB[i] = pTpos_ppg026[i];
      epTB[i] = 0;
      yieldB[i] = yieldpos_ppg026[i];
      eyieldB[i] = eyieldpos_ppg026[i];

      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	}
    } // end of for loop for rebinning


  TGraphErrors *tge_negpm = new TGraphErrors(number+offset,pT,ratio,epT,eratio);
  tge_negpm->SetMarkerColor(kRed);
  tge_negpm->SetMarkerStyle(21);

  // ---

  TMultiGraph *tmgb = new TMultiGraph();
  tmgb->Add(tge_posmp);
  tmgb->Add(tge_negpm);
  tmgb->Draw("ap");
  tmgb->SetMaximum(2.0);
  tmgb->SetMinimum(0.0);
  tmgb->GetXaxis()->SetLimits(0.0,6.0);
  tmgb->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgb->GetXaxis()->CenterTitle();
  tmgb->GetYaxis()->SetTitle("Ratio");
  tmgb->GetYaxis()->CenterTitle();

  TPaveText *tptP = new TPaveText(0.51, 0.1, 1.49, 0.3, "br");
  tptP->SetFillColor(10);
  tptP->SetBorderSize(0);
  TText *textP = tptP->AddText(bigcentstring);
  tptP->Draw();

  TPaveText *tptP2 = new TPaveText(0.5, 2.04, 5.5, 2.2, "br");
  tptP2->SetFillColor(10);
  tptP2->SetBorderSize(0);
  TText *textP2 = tptP2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP2->Draw();

  TLegend *legb = new TLegend(0.68,0.68,0.88,0.88);
  legb->SetFillColor(kWhite);
  legb->SetBorderSize(0);
  if(pid<=3)
    {
      legb->AddEntry(tge_posmp,"#pi^{+}, -+ field","p");
      legb->AddEntry(tge_negpm,"#pi^{-}, +- field","p");
    }
  if(pid==4||pid==5)
    {
      legb->AddEntry(tge_posmp,"K^{+}, -+ field","p");
      legb->AddEntry(tge_negpm,"K^{-}, +- field","p");
    }
  if(pid>=6)
    {
      legb->AddEntry(tge_posmp,"p, -+ field","p");
      legb->AddEntry(tge_negpm,"#bar{p}, +- field","p");
    }
  legb->Draw();

  char gifname_bad[100];
  sprintf(gifname_bad,"RatioFigures/published_%s_badchfi_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_bad[100];
  sprintf(epsname_bad,"RatioFigures/published_%s_badchfi_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_bad);
  c1->Print(epsname_bad);

  // ---
  // ---
  // ---

  // -------------------------- //
  // --- now doing pi0 part --- //
  // -------------------------- //

  if(pid>3) return;

  c1->Clear();

  for(int i=0; i<12; i++)
    {
      pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;

      pTA[i] = pTR_pospm[i];
      epTA[i] = 0;
      yieldA[i] = yieldR_pospm[i];
      eyieldA[i] = eyieldR_pospm[i];

      pTB[i] = pT_ppg080[i];
      epTB[i] = 0;
      yieldB[i] = yield_ppg080[i];
      eyieldB[i] = eyield_ppg080[i];

      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	}
      else
	{
	  pT[i] = pTA[i];
	  epT[i] = 0;
	  ratio[i] = -9;
	  eratio[i] = 0;
	}

      //cout<<pT_ppg080[i]<<"\t"<<yield_ppg080[i]<<endl;
      //cout<<pTB[i]<<"\t"<<yieldB[i]<<"\t"<<pTA[i]<<"\t"<<yieldA[i]<<endl;

    } // end of for loop to calculate ratio
  TGraphErrors *tge2_pospm = new TGraphErrors(12,pT,ratio,epT,eratio);
  tge2_pospm->SetMarkerColor(kBlue);
  tge2_pospm->SetMarkerStyle(20);






  for(int i=0; i<12; i++)
    {
      pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;

      pTA[i] = pTR_negmp[i];
      epTA[i] = 0;
      yieldA[i] = yieldR_negmp[i];
      eyieldA[i] = eyieldR_negmp[i];

      pTB[i] = pT_ppg080[i];
      epTB[i] = 0;
      yieldB[i] = yield_ppg080[i];
      eyieldB[i] = eyield_ppg080[i];

      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	}
    } // end of for loop to calculate ratio
  TGraphErrors *tge2_negmp = new TGraphErrors(12,pT,ratio,epT,eratio);
  tge2_negmp->SetMarkerColor(kRed);
  tge2_negmp->SetMarkerStyle(21);


  TMultiGraph *tmgG = new TMultiGraph();
  tmgG->Add(tge2_pospm);
  tmgG->Add(tge2_negmp);
  tmgG->Draw("ap");
  tmgG->SetMaximum(2.0);
  tmgG->SetMinimum(0.0);
  tmgG->GetXaxis()->SetLimits(0.0,6.0);
  tmgG->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgG->GetXaxis()->CenterTitle();
  tmgG->GetYaxis()->SetTitle("Ratio");
  tmgG->GetYaxis()->CenterTitle();

  TPaveText *tptP = new TPaveText(1.01, 0.1, 2.5, 0.3, "br");
  tptP->SetFillColor(10);
  tptP->SetBorderSize(0);
  TText *textP = tptP->AddText(bigcentstring);
  tptP->Draw();

  TPaveText *tptP2 = new TPaveText(0.5, 2.04, 5.5, 2.2, "br");
  tptP2->SetFillColor(10);
  tptP2->SetBorderSize(0);
  TText *textP2 = tptP2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP2->Draw();

  TLegend *legG = new TLegend(0.68,0.68,0.88,0.88);
  legG->SetFillColor(kWhite);
  legG->SetBorderSize(0);
  legG->AddEntry(tge2_pospm,"#pi^{+}, +- field","p");
  legG->AddEntry(tge2_negmp,"#pi^{-}, -+ field","p");
  legG->Draw();

  char gifname_good[100];
  sprintf(gifname_good,"RatioFigures/published_pi0_%s_goodchfi_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_good[100];
  sprintf(epsname_good,"RatioFigures/published_pi0_%s_goodchfi_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_good);
  c1->Print(epsname_good);






  c1->Clear();


  for(int i=0; i<12; i++)
    {
      pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;

      pTA[i] = pTR_posmp[i];
      epTA[i] = 0;
      yieldA[i] = yieldR_posmp[i];
      eyieldA[i] = eyieldR_posmp[i];

      pTB[i] = pT_ppg080[i];
      epTB[i] = 0;
      yieldB[i] = yield_ppg080[i];
      eyieldB[i] = eyield_ppg080[i];

      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	}
    } // end of for loop to calculate ratio
  TGraphErrors *tge2_posmp = new TGraphErrors(12,pT,ratio,epT,eratio);
  tge2_posmp->SetMarkerColor(kBlue);
  tge2_posmp->SetMarkerStyle(20);



  for(int i=0; i<12; i++)
    {
      pT[i] = pTA[i];
      epT[i] = 0;
      ratio[i] = -9;
      eratio[i] = 0;

      pTA[i] = pTR_negpm[i];
      epTA[i] = 0;
      yieldA[i] = yieldR_negpm[i];
      eyieldA[i] = eyieldR_negpm[i];

      pTB[i] = pT_ppg080[i];
      epTB[i] = 0;
      yieldB[i] = yield_ppg080[i];
      eyieldB[i] = eyield_ppg080[i];

      // now do ratio
      if(yieldA[i]>0&&yieldB[i]>0)
	{
	  pT[i] = (pTA[i]+pTB[i])/2.0;
	  epT[i] = 0;
	  ratio[i] = yieldA[i]/yieldB[i];
	  eratio[i] = ratio[i]*sqrt((eyieldA[i]/yieldA[i])**2+(eyieldB[i]/yieldB[i])**2);
	}
    } // end of for loop to calculate ratio
  TGraphErrors *tge2_negpm = new TGraphErrors(12,pT,ratio,epT,eratio);
  tge2_negpm->SetMarkerColor(kRed);
  tge2_negpm->SetMarkerStyle(21);



  TMultiGraph *tmgB = new TMultiGraph();
  tmgB->Add(tge2_posmp);
  tmgB->Add(tge2_negpm);
  tmgB->Draw("ap");
  tmgB->SetMaximum(2.0);
  tmgB->SetMinimum(0.0);
  tmgB->GetXaxis()->SetLimits(0.0,6.0);
  tmgB->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgB->GetXaxis()->CenterTitle();
  tmgB->GetYaxis()->SetTitle("Ratio");
  tmgB->GetYaxis()->CenterTitle();

  TPaveText *tptP = new TPaveText(1.01, 0.1, 2.5, 0.3, "br");
  tptP->SetFillColor(10);
  tptP->SetBorderSize(0);
  TText *textP = tptP->AddText(bigcentstring);
  tptP->Draw();

  TPaveText *tptP2 = new TPaveText(0.5, 2.04, 5.5, 2.2, "br");
  tptP2->SetFillColor(10);
  tptP2->SetBorderSize(0);
  TText *textP2 = tptP2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP2->Draw();

  TLegend *legB = new TLegend(0.68,0.68,0.88,0.88);
  legB->SetFillColor(kWhite);
  legB->SetBorderSize(0);
  legB->AddEntry(tge2_posmp,"#pi^{+}, -+ field","p");
  legB->AddEntry(tge2_negpm,"#pi^{-}, +- field","p");
  legB->Draw();

  char gifname_bad[100];
  sprintf(gifname_bad,"RatioFigures/published_pi0_%s_badchfi_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname_bad[100];
  sprintf(epsname_bad,"RatioFigures/published_pi0_%s_badchfi_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname_bad);
  c1->Print(epsname_bad);







}
