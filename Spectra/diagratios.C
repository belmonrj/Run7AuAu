void diagratios()
{

  cout<<"hello!  now drawing diagnostic ratios!"<<endl;

  // doitC(0,0,0);
  // doitC(0,2,0);
  // doitS(0,0);
  // doitS(2,0);

  // exit(1);

  // for(int icent=0; icent<9; icent++)
  //   {
  //     for(int ipid=0; ipid<10; ipid++)
  // 	{
  // 	  doitS(ipid,icent);
  // 	  for(int isec=0; isec<3; isec++)
  // 	    {
  // 	      doitC(isec,ipid,icent);
  // 	      //cout<<"doit("<<isec<<","<<ipid<<","<<icent<<");"<<endl;
  // 	    }
  // 	}
  //   }

  for(int ipid=0; ipid<10; ipid++)
    {
      doitS(ipid,0);
      for(int isec=0; isec<3; isec++)
	{
	  doitC(isec,ipid,0);
	  //cout<<"doit("<<isec<<","<<ipid<<","<<icent<<");"<<endl;
	}
    }



  
  
  cout<<"done!  have a nice day!"<<endl;

}

void doitC(int sector=0, int pid=0, int centid=0)
{

  // --- beginning of code

  gStyle->SetOptTitle(0);

  TCanvas *c1 = new TCanvas("c1","",800,600);
  c1->SetFillColor(kWhite);
  c1->SetFrameFillColor(kWhite);
  c1->SetBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->SetGridx();
  c1->SetGridy();
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



  // --- now input the rebinned data

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

  float pTR_pospm[100], yieldR_pospm[100], eyieldR_pospm[100];
  float pTR_negpm[100], yieldR_negpm[100], eyieldR_negpm[100];
  float pTR_posmp[100], yieldR_posmp[100], eyieldR_posmp[100];
  float pTR_negmp[100], yieldR_negmp[100], eyieldR_negmp[100];
  float pTR_poscb[100], yieldR_poscb[100], eyieldR_poscb[100];
  float pTR_negcb[100], yieldR_negcb[100], eyieldR_negcb[100];

  for(int i=0; i<100; i++)
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



  // --- now make tgrapherrorses

  float pT[36], epT[36], ratio[36], eratio[36];
  float pTA[36], epTA[36], yieldA[36], eyieldA[36];
  float pTB[36], epTB[36], yieldB[36], eyieldB[36];

  for(int i=0; i<36; i++)
    {
      // A
      pTA[i] = -9;
      epTA[i] = 0;
      yieldA[i] = -9;
      eyieldA[i] = 0;
      if(i<30)
	{
	  pTA[i] = pT_posmp[i];
	  epTA[i] = 0;
	  yieldA[i] = yield_posmp[i];
	  eyieldA[i] = eyield_posmp[i];
	}
      int k=i-24;
      if(i>29)
	{
	  pTA[i] = pTR_posmp[k];
	  epTA[i] = 0;
	  yieldA[i] = yieldR_posmp[k];
	  eyieldA[i] = eyieldR_posmp[k];
	}
      // B
      pTB[i] = -9;
      epTB[i] = 0;
      yieldB[i] = -9;
      eyieldB[i] = 0;
      if(i<30)
	{
	  pTB[i] = pT_pospm[i];
	  epTB[i] = 0;
	  yieldB[i] = yield_pospm[i];
	  eyieldB[i] = eyield_pospm[i];
	}
      int k=i-24;
      if(i>29)
	{
	  pTB[i] = pTR_pospm[k];
	  epTB[i] = 0;
	  yieldB[i] = yieldR_pospm[k];
	  eyieldB[i] = eyieldR_pospm[k];
	}
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
    }

  TGraphErrors *tge_posratio = new TGraphErrors(36,pT,ratio,epT,eratio);
  tge_posratio->SetMarkerColor(kRed);
  tge_posratio->SetMarkerStyle(20);

  // ---

  for(int i=0; i<36; i++)
    {
      // A
      pTA[i] = -9;
      epTA[i] = 0;
      yieldA[i] = -9;
      eyieldA[i] = 0;
      if(i<30)
	{
	  pTA[i] = pT_negpm[i];
	  epTA[i] = 0;
	  yieldA[i] = yield_negpm[i];
	  eyieldA[i] = eyield_negpm[i];
	}
      int k=i-24;
      if(i>29)
	{
	  pTA[i] = pTR_negpm[k];
	  epTA[i] = 0;
	  yieldA[i] = yieldR_negpm[k];
	  eyieldA[i] = eyieldR_negpm[k];
	}
      // B
      pTB[i] = -9;
      epTB[i] = 0;
      yieldB[i] = -9;
      eyieldB[i] = 0;
      if(i<30)
	{
	  pTB[i] = pT_negmp[i];
	  epTB[i] = 0;
	  yieldB[i] = yield_negmp[i];
	  eyieldB[i] = eyield_negmp[i];
	}
      int k=i-24;
      if(i>29)
	{
	  pTB[i] = pTR_negmp[k];
	  epTB[i] = 0;
	  yieldB[i] = yieldR_negmp[k];
	  eyieldB[i] = eyieldR_negmp[k];
	}
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
    }

  TGraphErrors *tge_negratio = new TGraphErrors(36,pT,ratio,epT,eratio);
  tge_negratio->SetMarkerColor(kBlue);
  tge_negratio->SetMarkerStyle(21);

  // ---





  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tge_posratio);
  tmg->Add(tge_negratio);
  tmg->Draw("ap");
  tmg->SetMaximum(2.0);
  tmg->SetMinimum(0.0);
  tmg->GetXaxis()->SetLimits(0.0,6.0);
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();
  tmg->GetYaxis()->SetTitle("Ratio");
  tmg->GetYaxis()->CenterTitle();

  TPaveText *tptP = new TPaveText(0.5, 0.1, 1.5, 0.3, "br");
  tptP->SetFillColor(10);
  tptP->SetBorderSize(0);
  TText *textP = tptP->AddText(bigcentstring);
  tptP->Draw();

  TPaveText *tptP2 = new TPaveText(0.5, 2.04, 5.5, 2.2, "br");
  tptP2->SetFillColor(10);
  tptP2->SetBorderSize(0);
  TText *textP2 = tptP2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP2->Draw();

  TLegend *leg  = new TLegend(0.68,0.68,0.88,0.88);
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  if(pid<=3)
    {
      leg->AddEntry(tge_posratio,"#pi^{+}, -+/+- field","p");
      leg->AddEntry(tge_negratio,"#pi^{-}, +-/-+ field","p");
    }
  if(pid==4||pid==5)
    {
      leg->AddEntry(tge_posratio,"K^{+}, -+/+- field","p");
      leg->AddEntry(tge_negratio,"K^{-}, +-/-+ field","p");
    }
  if(pid>=6)
    {
      leg->AddEntry(tge_posratio,"p, -+/+- field","p");
      leg->AddEntry(tge_negratio,"#bar{p}, +-/-+ field","p");
    }
  leg->Draw();

  char gifname[100];
  sprintf(gifname,"RatioFigures/chargefield_%s_%d_dis_cent%s.gif",sectorstring,pid,centstring);
  char epsname[100];
  sprintf(epsname,"RatioFigures/chargefield_%s_%d_dis_cent%s.eps",sectorstring,pid,centstring);

  c1->Print(gifname);
  c1->Print(epsname);



}




void doitS(int pid=0, int centid=0)
{

  // --- beginning of code

  gStyle->SetOptTitle(0);

  TCanvas *c1 = new TCanvas("c1","",800,600);
  c1->SetFillColor(kWhite);
  c1->SetFrameFillColor(kWhite);
  c1->SetBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->SetGridx();
  c1->SetGridy();
  //c1->SetLogy();



  // --- strings for filenames

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






  // --- input data

  char fnameinpospm[100];
  char fnameinnegpm[100];
  char fnameinposmp[100];
  char fnameinnegmp[100];
  char fnameinposcb[100];
  char fnameinnegcb[100];

  ifstream finpospm;
  ifstream finnegpm;
  ifstream finposmp;
  ifstream finnegmp;
  ifstream finposcb;
  ifstream finnegcb;

  sprintf(fnameinpospm,"Data/ptpid_tofw_w1_pos_%d_dis_cent%s_pm.dat",pid,centstring);
  sprintf(fnameinnegpm,"Data/ptpid_tofw_w1_neg_%d_dis_cent%s_pm.dat",pid,centstring);
  sprintf(fnameinposmp,"Data/ptpid_tofw_w1_pos_%d_dis_cent%s_mp.dat",pid,centstring);
  sprintf(fnameinnegmp,"Data/ptpid_tofw_w1_neg_%d_dis_cent%s_mp.dat",pid,centstring);
  sprintf(fnameinposcb,"Data/ptpid_tofw_w1_pos_%d_dis_cent%s.dat",pid,centstring);
  sprintf(fnameinnegcb,"Data/ptpid_tofw_w1_neg_%d_dis_cent%s.dat",pid,centstring);

  finpospm.open(fnameinpospm);
  finnegpm.open(fnameinnegpm);
  finposmp.open(fnameinposmp);
  finnegmp.open(fnameinnegmp);
  finposcb.open(fnameinposcb);
  finnegcb.open(fnameinnegcb);

  float pT_w1_pospm[100], yield_w1_pospm[100], eyield_w1_pospm[100];
  float pT_w1_negpm[100], yield_w1_negpm[100], eyield_w1_negpm[100];
  float pT_w1_posmp[100], yield_w1_posmp[100], eyield_w1_posmp[100];
  float pT_w1_negmp[100], yield_w1_negmp[100], eyield_w1_negmp[100];
  float pT_w1_poscb[100], yield_w1_poscb[100], eyield_w1_poscb[100];
  float pT_w1_negcb[100], yield_w1_negcb[100], eyield_w1_negcb[100];

  for(int i=0; i<100; i++)
    {
      // pospm
      finpospm>>pT_w1_pospm[i]>>yield_w1_pospm[i]>>eyield_w1_pospm[i];
      // negpm
      finnegpm>>pT_w1_negpm[i]>>yield_w1_negpm[i]>>eyield_w1_negpm[i];
      // posmp
      finposmp>>pT_w1_posmp[i]>>yield_w1_posmp[i]>>eyield_w1_posmp[i];
      // negmp
      finnegmp>>pT_w1_negmp[i]>>yield_w1_negmp[i]>>eyield_w1_negmp[i];
      // poscb
      finposcb>>pT_w1_poscb[i]>>yield_w1_poscb[i]>>eyield_w1_poscb[i];
      // negcb
      finnegcb>>pT_w1_negcb[i]>>yield_w1_negcb[i]>>eyield_w1_negcb[i];
    }

  finpospm.close();
  finnegpm.close();
  finposmp.close();
  finnegmp.close();
  finposcb.close();
  finnegcb.close();

  sprintf(fnameinpospm,"Data/ptpid_tofw_w2_pos_%d_dis_cent%s_pm.dat",pid,centstring);
  sprintf(fnameinnegpm,"Data/ptpid_tofw_w2_neg_%d_dis_cent%s_pm.dat",pid,centstring);
  sprintf(fnameinposmp,"Data/ptpid_tofw_w2_pos_%d_dis_cent%s_mp.dat",pid,centstring);
  sprintf(fnameinnegmp,"Data/ptpid_tofw_w2_neg_%d_dis_cent%s_mp.dat",pid,centstring);
  sprintf(fnameinposcb,"Data/ptpid_tofw_w2_pos_%d_dis_cent%s.dat",pid,centstring);
  sprintf(fnameinnegcb,"Data/ptpid_tofw_w2_neg_%d_dis_cent%s.dat",pid,centstring);

  finpospm.open(fnameinpospm);
  finnegpm.open(fnameinnegpm);
  finposmp.open(fnameinposmp);
  finnegmp.open(fnameinnegmp);
  finposcb.open(fnameinposcb);
  finnegcb.open(fnameinnegcb);

  float pT_w2_pospm[100], yield_w2_pospm[100], eyield_w2_pospm[100];
  float pT_w2_negpm[100], yield_w2_negpm[100], eyield_w2_negpm[100];
  float pT_w2_posmp[100], yield_w2_posmp[100], eyield_w2_posmp[100];
  float pT_w2_negmp[100], yield_w2_negmp[100], eyield_w2_negmp[100];
  float pT_w2_poscb[100], yield_w2_poscb[100], eyield_w2_poscb[100];
  float pT_w2_negcb[100], yield_w2_negcb[100], eyield_w2_negcb[100];

  for(int i=0; i<100; i++)
    {
      // pospm
      finpospm>>pT_w2_pospm[i]>>yield_w2_pospm[i]>>eyield_w2_pospm[i];
      // negpm
      finnegpm>>pT_w2_negpm[i]>>yield_w2_negpm[i]>>eyield_w2_negpm[i];
      // posmp
      finposmp>>pT_w2_posmp[i]>>yield_w2_posmp[i]>>eyield_w2_posmp[i];
      // negmp
      finnegmp>>pT_w2_negmp[i]>>yield_w2_negmp[i]>>eyield_w2_negmp[i];
      // poscb
      finposcb>>pT_w2_poscb[i]>>yield_w2_poscb[i]>>eyield_w2_poscb[i];
      // negcb
      finnegcb>>pT_w2_negcb[i]>>yield_w2_negcb[i]>>eyield_w2_negcb[i];
    }

  finpospm.close();
  finnegpm.close();
  finposmp.close();
  finnegmp.close();
  finposcb.close();
  finnegcb.close();



  // --- now input the rebinned data

  sprintf(fnameinpospm,"Data/R5_ptpid_tofw_w1_pos_%d_dis_cent%s_pm.dat",pid,centstring);
  sprintf(fnameinnegpm,"Data/R5_ptpid_tofw_w1_neg_%d_dis_cent%s_pm.dat",pid,centstring);
  sprintf(fnameinposmp,"Data/R5_ptpid_tofw_w1_pos_%d_dis_cent%s_mp.dat",pid,centstring);
  sprintf(fnameinnegmp,"Data/R5_ptpid_tofw_w1_neg_%d_dis_cent%s_mp.dat",pid,centstring);
  sprintf(fnameinposcb,"Data/R5_ptpid_tofw_w1_pos_%d_dis_cent%s.dat",pid,centstring);
  sprintf(fnameinnegcb,"Data/R5_ptpid_tofw_w1_neg_%d_dis_cent%s.dat",pid,centstring);

  finpospm.open(fnameinpospm);
  finnegpm.open(fnameinnegpm);
  finposmp.open(fnameinposmp);
  finnegmp.open(fnameinnegmp);
  finposcb.open(fnameinposcb);
  finnegcb.open(fnameinnegcb);

  float pTR_w1_pospm[100], yieldR_w1_pospm[100], eyieldR_w1_pospm[100];
  float pTR_w1_negpm[100], yieldR_w1_negpm[100], eyieldR_w1_negpm[100];
  float pTR_w1_posmp[100], yieldR_w1_posmp[100], eyieldR_w1_posmp[100];
  float pTR_w1_negmp[100], yieldR_w1_negmp[100], eyieldR_w1_negmp[100];
  float pTR_w1_poscb[100], yieldR_w1_poscb[100], eyieldR_w1_poscb[100];
  float pTR_w1_negcb[100], yieldR_w1_negcb[100], eyieldR_w1_negcb[100];

  for(int i=0; i<100; i++)
    {
      // pospm
      finpospm>>pTR_w1_pospm[i]>>yieldR_w1_pospm[i]>>eyieldR_w1_pospm[i];
      // negpm
      finnegpm>>pTR_w1_negpm[i]>>yieldR_w1_negpm[i]>>eyieldR_w1_negpm[i];
      // posmp
      finposmp>>pTR_w1_posmp[i]>>yieldR_w1_posmp[i]>>eyieldR_w1_posmp[i];
      // negmp
      finnegmp>>pTR_w1_negmp[i]>>yieldR_w1_negmp[i]>>eyieldR_w1_negmp[i];
      // poscb
      finposcb>>pTR_w1_poscb[i]>>yieldR_w1_poscb[i]>>eyieldR_w1_poscb[i];
      // negcb
      finnegcb>>pTR_w1_negcb[i]>>yieldR_w1_negcb[i]>>eyieldR_w1_negcb[i];
    }

  finpospm.close();
  finnegpm.close();
  finposmp.close();
  finnegmp.close();
  finposcb.close();
  finnegcb.close();

  sprintf(fnameinpospm,"Data/R5_ptpid_tofw_w2_pos_%d_dis_cent%s_pm.dat",pid,centstring);
  sprintf(fnameinnegpm,"Data/R5_ptpid_tofw_w2_neg_%d_dis_cent%s_pm.dat",pid,centstring);
  sprintf(fnameinposmp,"Data/R5_ptpid_tofw_w2_pos_%d_dis_cent%s_mp.dat",pid,centstring);
  sprintf(fnameinnegmp,"Data/R5_ptpid_tofw_w2_neg_%d_dis_cent%s_mp.dat",pid,centstring);
  sprintf(fnameinposcb,"Data/R5_ptpid_tofw_w2_pos_%d_dis_cent%s.dat",pid,centstring);
  sprintf(fnameinnegcb,"Data/R5_ptpid_tofw_w2_neg_%d_dis_cent%s.dat",pid,centstring);

  finpospm.open(fnameinpospm);
  finnegpm.open(fnameinnegpm);
  finposmp.open(fnameinposmp);
  finnegmp.open(fnameinnegmp);
  finposcb.open(fnameinposcb);
  finnegcb.open(fnameinnegcb);

  float pTR_w2_pospm[100], yieldR_w2_pospm[100], eyieldR_w2_pospm[100];
  float pTR_w2_negpm[100], yieldR_w2_negpm[100], eyieldR_w2_negpm[100];
  float pTR_w2_posmp[100], yieldR_w2_posmp[100], eyieldR_w2_posmp[100];
  float pTR_w2_negmp[100], yieldR_w2_negmp[100], eyieldR_w2_negmp[100];
  float pTR_w2_poscb[100], yieldR_w2_poscb[100], eyieldR_w2_poscb[100];
  float pTR_w2_negcb[100], yieldR_w2_negcb[100], eyieldR_w2_negcb[100];

  for(int i=0; i<100; i++)
    {
      // pospm
      finpospm>>pTR_w2_pospm[i]>>yieldR_w2_pospm[i]>>eyieldR_w2_pospm[i];
      // negpm
      finnegpm>>pTR_w2_negpm[i]>>yieldR_w2_negpm[i]>>eyieldR_w2_negpm[i];
      // posmp
      finposmp>>pTR_w2_posmp[i]>>yieldR_w2_posmp[i]>>eyieldR_w2_posmp[i];
      // negmp
      finnegmp>>pTR_w2_negmp[i]>>yieldR_w2_negmp[i]>>eyieldR_w2_negmp[i];
      // poscb
      finposcb>>pTR_w2_poscb[i]>>yieldR_w2_poscb[i]>>eyieldR_w2_poscb[i];
      // negcb
      finnegcb>>pTR_w2_negcb[i]>>yieldR_w2_negcb[i]>>eyieldR_w2_negcb[i];
    }

  finpospm.close();
  finnegpm.close();
  finposmp.close();
  finnegmp.close();
  finposcb.close();
  finnegcb.close();



  // --- now make tgrapherrorses

  float pT[36], epT[36], ratio[36], eratio[36];
  float pTA[36], epTA[36], yieldA[36], eyieldA[36];
  float pTB[36], epTB[36], yieldB[36], eyieldB[36];

  for(int i=0; i<36; i++)
    {
      // A
      pTA[i] = -9;
      epTA[i] = 0;
      yieldA[i] = -9;
      eyieldA[i] = 0;
      if(i<30)
	{
	  pTA[i] = pT_w1_pospm[i];
	  epTA[i] = 0;
	  yieldA[i] = yield_w1_pospm[i];
	  eyieldA[i] = eyield_w1_pospm[i];
	}
      int k=i-24;
      if(i>29)
	{
	  pTA[i] = pTR_w1_pospm[k];
	  epTA[i] = 0;
	  yieldA[i] = yieldR_w1_pospm[k];
	  eyieldA[i] = eyieldR_w1_pospm[k];
	}
      // B
      pTB[i] = -9;
      epTB[i] = 0;
      yieldB[i] = -9;
      eyieldB[i] = 0;
      if(i<30)
	{
	  pTB[i] = pT_w2_pospm[i];
	  epTB[i] = 0;
	  yieldB[i] = yield_w2_pospm[i];
	  eyieldB[i] = eyield_w2_pospm[i];
	}
      int k=i-24;
      if(i>29)
	{
	  pTB[i] = pTR_w2_pospm[k];
	  epTB[i] = 0;
	  yieldB[i] = yieldR_w2_pospm[k];
	  eyieldB[i] = eyieldR_w2_pospm[k];
	}
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
    }

  TGraphErrors *tge_pospmratio = new TGraphErrors(36,pT,ratio,epT,eratio);
  tge_pospmratio->SetMarkerColor(kRed);
  tge_pospmratio->SetMarkerStyle(20);

  // ---

  for(int i=0; i<36; i++)
    {
      // A
      pTA[i] = -9;
      epTA[i] = 0;
      yieldA[i] = -9;
      eyieldA[i] = 0;
      if(i<30)
	{
	  pTA[i] = pT_w1_negpm[i];
	  epTA[i] = 0;
	  yieldA[i] = yield_w1_negpm[i];
	  eyieldA[i] = eyield_w1_negpm[i];
	}
      int k=i-24;
      if(i>29)
	{
	  pTA[i] = pTR_w1_negpm[k];
	  epTA[i] = 0;
	  yieldA[i] = yieldR_w1_negpm[k];
	  eyieldA[i] = eyieldR_w1_negpm[k];
	}
      // B
      pTB[i] = -9;
      epTB[i] = 0;
      yieldB[i] = -9;
      eyieldB[i] = 0;
      if(i<30)
	{
	  pTB[i] = pT_w2_negpm[i];
	  epTB[i] = 0;
	  yieldB[i] = yield_w2_negpm[i];
	  eyieldB[i] = eyield_w2_negpm[i];
	}
      int k=i-24;
      if(i>29)
	{
	  pTB[i] = pTR_w2_negpm[k];
	  epTB[i] = 0;
	  yieldB[i] = yieldR_w2_negpm[k];
	  eyieldB[i] = eyieldR_w2_negpm[k];
	}
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
    }

  TGraphErrors *tge_negpmratio = new TGraphErrors(36,pT,ratio,epT,eratio);
  tge_negpmratio->SetMarkerColor(kBlue);
  tge_negpmratio->SetMarkerStyle(21);

  // ---





  TMultiGraph *tmg_pm = new TMultiGraph();
  tmg_pm->Add(tge_pospmratio);
  tmg_pm->Add(tge_negpmratio);
  tmg_pm->Draw("ap");
  tmg_pm->SetMaximum(2.0);
  tmg_pm->SetMinimum(0.0);
  tmg_pm->GetXaxis()->SetLimits(0.0,6.0);
  tmg_pm->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_pm->GetXaxis()->CenterTitle();
  tmg_pm->GetYaxis()->SetTitle("Ratio");
  tmg_pm->GetYaxis()->CenterTitle();

  TPaveText *tptP_pm = new TPaveText(0.5, 0.1, 1.5, 0.3, "br");
  tptP_pm->SetFillColor(10);
  tptP_pm->SetBorderSize(0);
  TText *textP_pm = tptP_pm->AddText(bigcentstring);
  tptP_pm->Draw();

  TPaveText *tptP_pm2 = new TPaveText(0.5, 2.04, 5.5, 2.2, "br");
  tptP_pm2->SetFillColor(10);
  tptP_pm2->SetBorderSize(0);
  TText *textP_pm2 = tptP_pm2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_pm2->Draw();

  TLegend *leg_pm  = new TLegend(0.58,0.72,0.88,0.88);
  leg_pm->SetFillColor(kWhite);
  leg_pm->SetBorderSize(0);
  if(pid<=3)
    {
      leg_pm->AddEntry(tge_pospmratio,"#pi^{+}, w1/w2, +- field","p");
      leg_pm->AddEntry(tge_negpmratio,"#pi^{-}, w1/w2, +- field","p");
    }
  if(pid==4||pid==5)
    {
      leg_pm->AddEntry(tge_pospmratio,"K^{+}, w1/w2, +- field","p");
      leg_pm->AddEntry(tge_negpmratio,"K^{-}, w1/w2, +- field","p");
    }
  if(pid>=6)
    {
      leg_pm->AddEntry(tge_pospmratio,"p, w1/w2, +- field","p");
      leg_pm->AddEntry(tge_negpmratio,"#bar{p}, w1/w2, +- field","p");
    }
  leg_pm->Draw();

  char gifname_pm[100];
  sprintf(gifname_pm,"RatioFigures/sector_pm_%d_dis_cent%s.gif",pid,centstring);
  char epsname_pm[100];
  sprintf(epsname_pm,"RatioFigures/sector_pm_%d_dis_cent%s.eps",pid,centstring);

  c1->Print(gifname_pm);
  c1->Print(epsname_pm);








  for(int i=0; i<36; i++)
    {
      // A
      pTA[i] = -9;
      epTA[i] = 0;
      yieldA[i] = -9;
      eyieldA[i] = 0;
      if(i<30)
	{
	  pTA[i] = pT_w1_posmp[i];
	  epTA[i] = 0;
	  yieldA[i] = yield_w1_posmp[i];
	  eyieldA[i] = eyield_w1_posmp[i];
	}
      int k=i-24;
      if(i>29)
	{
	  pTA[i] = pTR_w1_posmp[k];
	  epTA[i] = 0;
	  yieldA[i] = yieldR_w1_posmp[k];
	  eyieldA[i] = eyieldR_w1_posmp[k];
	}
      // B
      pTB[i] = -9;
      epTB[i] = 0;
      yieldB[i] = -9;
      eyieldB[i] = 0;
      if(i<30)
	{
	  pTB[i] = pT_w2_posmp[i];
	  epTB[i] = 0;
	  yieldB[i] = yield_w2_posmp[i];
	  eyieldB[i] = eyield_w2_posmp[i];
	}
      int k=i-24;
      if(i>29)
	{
	  pTB[i] = pTR_w2_posmp[k];
	  epTB[i] = 0;
	  yieldB[i] = yieldR_w2_posmp[k];
	  eyieldB[i] = eyieldR_w2_posmp[k];
	}
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
    }

  TGraphErrors *tge_posmpratio = new TGraphErrors(36,pT,ratio,epT,eratio);
  tge_posmpratio->SetMarkerColor(kRed);
  tge_posmpratio->SetMarkerStyle(20);

  // ---

  for(int i=0; i<36; i++)
    {
      // A
      pTA[i] = -9;
      epTA[i] = 0;
      yieldA[i] = -9;
      eyieldA[i] = 0;
      if(i<30)
	{
	  pTA[i] = pT_w1_negmp[i];
	  epTA[i] = 0;
	  yieldA[i] = yield_w1_negmp[i];
	  eyieldA[i] = eyield_w1_negmp[i];
	}
      int k=i-24;
      if(i>29)
	{
	  pTA[i] = pTR_w1_negmp[k];
	  epTA[i] = 0;
	  yieldA[i] = yieldR_w1_negmp[k];
	  eyieldA[i] = eyieldR_w1_negmp[k];
	}
      // B
      pTB[i] = -9;
      epTB[i] = 0;
      yieldB[i] = -9;
      eyieldB[i] = 0;
      if(i<30)
	{
	  pTB[i] = pT_w2_negmp[i];
	  epTB[i] = 0;
	  yieldB[i] = yield_w2_negmp[i];
	  eyieldB[i] = eyield_w2_negmp[i];
	}
      int k=i-24;
      if(i>29)
	{
	  pTB[i] = pTR_w2_negmp[k];
	  epTB[i] = 0;
	  yieldB[i] = yieldR_w2_negmp[k];
	  eyieldB[i] = eyieldR_w2_negmp[k];
	}
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
    }

  TGraphErrors *tge_negmpratio = new TGraphErrors(36,pT,ratio,epT,eratio);
  tge_negmpratio->SetMarkerColor(kBlue);
  tge_negmpratio->SetMarkerStyle(21);

  // ---





  TMultiGraph *tmg_mp = new TMultiGraph();
  tmg_mp->Add(tge_posmpratio);
  tmg_mp->Add(tge_negmpratio);
  tmg_mp->Draw("ap");
  tmg_mp->SetMaximum(2.0);
  tmg_mp->SetMinimum(0.0);
  tmg_mp->GetXaxis()->SetLimits(0.0,6.0);
  tmg_mp->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_mp->GetXaxis()->CenterTitle();
  tmg_mp->GetYaxis()->SetTitle("Ratio");
  tmg_mp->GetYaxis()->CenterTitle();

  TPaveText *tptP_mp = new TPaveText(0.5, 0.1, 1.5, 0.3, "br");
  tptP_mp->SetFillColor(10);
  tptP_mp->SetBorderSize(0);
  TText *textP_mp = tptP_mp->AddText(bigcentstring);
  tptP_mp->Draw();

  TPaveText *tptP_mp2 = new TPaveText(0.5, 2.04, 5.5, 2.2, "br");
  tptP_mp2->SetFillColor(10);
  tptP_mp2->SetBorderSize(0);
  TText *textP_mp2 = tptP_mp2->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tptP_mp2->Draw();

  TLegend *leg_mp  = new TLegend(0.58,0.72,0.88,0.88);
  leg_mp->SetFillColor(kWhite);
  leg_mp->SetBorderSize(0);
  if(pid<=3)
    {
      leg_mp->AddEntry(tge_posmpratio,"#pi^{+}, w1/w2, -+ field","p");
      leg_mp->AddEntry(tge_negmpratio,"#pi^{-}, w1/w2, -+ field","p");
    }
  if(pid==4||pid==5)
    {
      leg_mp->AddEntry(tge_posmpratio,"K^{+}, w1/w2, -+ field","p");
      leg_mp->AddEntry(tge_negmpratio,"K^{-}, w1/w2, -+ field","p");
    }
  if(pid>=6)
    {
      leg_mp->AddEntry(tge_posmpratio,"p, w1/w2, -+ field","p");
      leg_mp->AddEntry(tge_negmpratio,"#bar{p}, w1/w2, -+ field","p");
    }
  leg_mp->Draw();

  char gifname_mp[100]; 
  sprintf(gifname_mp,"RatioFigures/sector_mp_%d_dis_cent%s.gif",pid,centstring);
  char epsname_mp[100];
  sprintf(epsname_mp,"RatioFigures/sector_mp_%d_dis_cent%s.eps",pid,centstring);

  c1->Print(gifname_mp);
  c1->Print(epsname_mp);



}
