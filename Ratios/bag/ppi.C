void ppi()
{

  for(int i=0; i<5; i++)
    {
      doit_file(i,0,6);
      doit_file(i,1,7);
      doit_file(i,2,8);
      doit_file(i,3,9);
    }
}



void doit_file(int centid=0, int pionid=0, int protonid=6)
{

  float ymin = 0.0;
  float xmin = 0.0;
  float ymax = 1.4;
  float xmax = 6.0;
  const int nbin = 40;
  if(nbin < (xmax-3.0)*2+30)
    {
      cout<<"incorrect number of bins"<<endl;
      cout<<"number of bins is "<<nbin<<" but number of bins needed is "<<(xmax-3.0)*2+30<<endl;
    }



  TCanvas *c1 = new TCanvas("c1","",800,600);

  char centstring[5];
  if(centid==0) sprintf(centstring,"0010");
  else if(centid==1) sprintf(centstring,"1020");
  else if(centid==2) sprintf(centstring,"2040");
  else if(centid==3) sprintf(centstring,"4060");
  else if(centid==4) sprintf(centstring,"6092");
  else {cout<<"you gonna die"<<endl; return;}

  char starcentstring[5];
  if(centid<4) strcpy(starcentstring,centstring);
  else if(centid==4) sprintf(starcentstring,"6080");
  else {cout<<"you gonna die"<<endl; return;}

  char bigcentstring[10];
  sprintf(bigcentstring,"MinBias"); // "default"
  if(centid==0) sprintf(bigcentstring,"0-10%%");
  if(centid==1) sprintf(bigcentstring,"10-20%%");
  if(centid==2) sprintf(bigcentstring,"20-40%%");
  if(centid==3) sprintf(bigcentstring,"40-60%%");
  if(centid==4) sprintf(bigcentstring,"60-92%%");

  char filename[100];
  ifstream fin;

  float pt[nbin], ept[nbin];
  float pionpos[nbin], epionpos[nbin];
  float protonpos[nbin], eprotonpos[nbin];
  float pionneg[nbin], epionneg[nbin];
  float protonneg[nbin], eprotonneg[nbin];
  float tmp;

  // --------------- //
  // --- pionpos --- //
  // --------------- //
  sprintf(filename,"FinalFeed/ptpid_tofw_pos_%d_dis_cent%s.dat",pionid,centstring);
  fin.open(filename);
  for(int i=0; i<30; i++)
    {
      fin>>pt[i]>>pionpos[i]>>epionpos[i];
      if((float)pt[i]!=float(float(i)/10.0+0.05)&&i>0) // they're the same but this evaluates as false
	{
	  cout<<"you gonna die"<<endl;
	  cout<<"pt is "<<pt[i]<<" but pt is "<<i/10.0+0.05<<endl;
	}
    }
  fin.close();
  sprintf(filename,"FinalFeed/R5_ptpid_tofw_pos_%d_dis_cent%s.dat",pionid,centstring);
  fin.open(filename);
  for(int i=0; i<nbin-24; i++)
    {
      if(i<6) fin>>tmp>>tmp>>tmp;
      else
	{
	  fin>>pt[i+24]>>pionpos[i+24]>>epionpos[i+24];
	  if((float)pt[i+24]!=float(i)/2.0+0.25)
	    {
	      cout<<"you gonna die"<<endl;
	      cout<<"pt is "<<pt[i+24]<<" but pt is "<<i/2.0+0.25<<endl;
	    }
	}
    }
  fin.close();

  // --------------- //
  // --- pionneg --- //
  // --------------- //
  sprintf(filename,"FinalFeed/ptpid_tofw_neg_%d_dis_cent%s.dat",pionid,centstring);
  fin.open(filename);
  for(int i=0; i<30; i++)
    {
      fin>>pt[i]>>pionneg[i]>>epionneg[i];
      if((float)pt[i]!=float(float(i)/10.0+0.05)&&i>0) // they're the same but this evaluates as false
	{
	  cout<<"you gonna die"<<endl;
	  cout<<"pt is "<<pt[i]<<" but pt is "<<i/10.0+0.05<<endl;
	}
    }
  fin.close();
  sprintf(filename,"FinalFeed/R5_ptpid_tofw_neg_%d_dis_cent%s.dat",pionid,centstring);
  fin.open(filename);
  for(int i=0; i<nbin-24; i++)
    {
      if(i<6) fin>>tmp>>tmp>>tmp;
      else
	{
	  fin>>pt[i+24]>>pionneg[i+24]>>epionneg[i+24];
	  if((float)pt[i+24]!=float(i)/2.0+0.25)
	    {
	      cout<<"you gonna die"<<endl;
	      cout<<"pt is "<<pt[i+24]<<" but pt is "<<i/2.0+0.25<<endl;
	    }
	}
    }
  fin.close();


  // ----------------- //
  // --- protonpos --- //
  // ----------------- //
  sprintf(filename,"FinalFeed/ptpid_tofw_pos_%d_dis_cent%s.dat",protonid,centstring);
  fin.open(filename);
  for(int i=0; i<30; i++)
    {
      fin>>pt[i]>>protonpos[i]>>eprotonpos[i];
      if((float)pt[i]!=float(float(i)/10.0+0.05)&&i>0) // they're the same but this evaluates as false
	{
	  cout<<"you gonna die"<<endl;
	  cout<<"pt is "<<pt[i]<<" but pt is "<<i/10.0+0.05<<endl;
	}
    }
  fin.close();
  sprintf(filename,"FinalFeed/R5_ptpid_tofw_pos_%d_dis_cent%s.dat",protonid,centstring);
  fin.open(filename);
  for(int i=0; i<nbin-24; i++)
    {
      if(i<6) fin>>tmp>>tmp>>tmp;
      else
	{
	  fin>>pt[i+24]>>protonpos[i+24]>>eprotonpos[i+24];
	  if((float)pt[i+24]!=float(i)/2.0+0.25)
	    {
	      cout<<"you gonna die"<<endl;
	      cout<<"pt is "<<pt[i+24]<<" but pt is "<<i/2.0+0.25<<endl;
	    }
	}
    }
  fin.close();

  // ----------------- //
  // --- protonneg --- //
  // ----------------- //
  sprintf(filename,"FinalFeed/ptpid_tofw_neg_%d_dis_cent%s.dat",protonid,centstring);
  fin.open(filename);
  for(int i=0; i<30; i++)
    {
      fin>>pt[i]>>protonneg[i]>>eprotonneg[i];
      if((float)pt[i]!=float(float(i)/10.0+0.05)&&i>0) // they're the same but this evaluates as false
	{
	  cout<<"you gonna die"<<endl;
	  cout<<"pt is "<<pt[i]<<" but pt is "<<i/10.0+0.05<<endl;
	}
    }
  fin.close();
  sprintf(filename,"FinalFeed/R5_ptpid_tofw_neg_%d_dis_cent%s.dat",protonid,centstring);
  fin.open(filename);
  for(int i=0; i<nbin-24; i++)
    {
      if(i<6) fin>>tmp>>tmp>>tmp;
      else
	{
	  fin>>pt[i+24]>>protonneg[i+24]>>eprotonneg[i+24];
	  if((float)pt[i+24]!=float(i)/2.0+0.25)
	    {
	      cout<<"you gonna die"<<endl;
	      cout<<"pt is "<<pt[i+24]<<" but pt is "<<i/2.0+0.25<<endl;
	    }
	}
    }
  fin.close();



  float ratiopos[nbin], eratiopos[nbin], esysratiopos[nbin];
  float rationeg[nbin], erationeg[nbin], esysrationeg[nbin];
  float A, dA, B, dB;
  sprintf(filename,"regular/ppi_%d%d_cent%s.txt",pionid,protonid,centstring);
  ofstream ftxt(filename);
  sprintf(filename,"regular/ppi_%d%d_cent%s.tex",pionid,protonid,centstring);
  ofstream ftex(filename);
  for(int i=0; i<nbin; i++)
    {
      // pos
      A = pionpos[i];
      dA = epionpos[i];
      B = protonpos[i];
      dB = eprotonpos[i];
      ratiopos[i] = B/A;
      eratiopos[i] = B/A*sqrt((dA/A)**2+(dB/B)**2);
      esysratiopos[i] = 0.1*(B/A);
      // neg
      A = pionneg[i];
      dA = epionneg[i];
      B = protonneg[i];
      dB = eprotonneg[i];
      rationeg[i] = B/A;
      erationeg[i] = B/A*sqrt((dA/A)**2+(dB/B)**2);
      esysrationeg[i] = 0.1*(B/A);
      if(i<5){ratiopos[i]=-9;rationeg[i]=-9;eratiopos[i]=0;erationeg[i]=0;}
      ftxt<<pt[i]<<"\t"<<ratiopos[i]<<"\t"<<eratiopos[i]<<"\t"<<rationeg[i]<<"\t"<<erationeg[i]<<endl;
      ftex<<pt[i]<<" & "<<ratiopos[i]<<" & "<<eratiopos[i]<<" & "<<rationeg[i]<<" & "<<erationeg[i]<<" \\\\ "<<endl;
    }
  
  
  for(int i=0; i<nbin; i++) ept[i]=0;  // yeah
  
  
  TGraphErrors *tge_pos = new TGraphErrors(nbin,pt,ratiopos,ept,eratiopos);
  tge_pos->SetMarkerColor(kRed);
  tge_pos->SetMarkerStyle(kFullSquare);
  TGraphErrors *tge_neg = new TGraphErrors(nbin,pt,rationeg,ept,erationeg);
  tge_neg->SetMarkerColor(kBlue);
  tge_neg->SetMarkerStyle(kFullSquare);

  TGraphErrors *tge_syspos = new TGraphErrors(nbin,pt,ratiopos,ept,esysratiopos);
  tge_syspos->SetMarkerColor(kRed);
  tge_syspos->SetMarkerStyle(1);
  tge_syspos->SetLineColor(kRed-10);
  tge_syspos->SetLineWidth(15);
  TGraphErrors *tge_sysneg = new TGraphErrors(nbin,pt,rationeg,ept,esysrationeg);
  tge_sysneg->SetMarkerColor(kBlue);
  tge_sysneg->SetMarkerStyle(1);
  tge_sysneg->SetLineColor(kBlue-10);
  tge_sysneg->SetLineWidth(15);

  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tge_sysneg);
  tmg->Add(tge_syspos);
  tmg->Add(tge_neg);
  tmg->Add(tge_pos);
  tmg->Draw("apz");
  //tmg->SetMaximum(1.4);
  tmg->SetMaximum(ymax); // 1.4 is fine but this is for comparisons...
  tmg->SetMinimum(ymin);
  tmg->GetXaxis()->SetLimits(xmin,xmax);
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();
  tmg->GetYaxis()->SetTitle("p/#pi ratio");
  tmg->GetYaxis()->CenterTitle();

  TLegend *leg = new TLegend(0.68,0.68,0.88,0.88);
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->AddEntry(tge_pos,"p/#pi^{+}","p");
  leg->AddEntry(tge_neg,"#bar{p}/#pi^{-}","p");
  leg->Draw();

  //TPaveText *tpt_coll = new TPaveText(xmin+0.5,ymax+0.01,xmax-0.5,ymax+0.16);
  TPaveText *tpt_coll = new TPaveText(xmin+0.5,ymax*1.01,xmax-0.5,ymax*1.1);
  tpt_coll->SetFillColor(kWhite);
  tpt_coll->SetBorderSize(0);
  tpt_coll->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tpt_coll->Draw();

  //TPaveText *tpt_cent = new TPaveText(xmin+0.25,ymax-0.4,xmin+1.5,ymax-0.2);
  TPaveText *tpt_cent = new TPaveText(xmax*0.1,ymax*0.75,xmax*0.4,ymax*0.88);
  tpt_cent->SetFillColor(kWhite);
  tpt_cent->SetBorderSize(0);
  tpt_cent->AddText(bigcentstring);
  tpt_cent->Draw();

  char figname[100];
  sprintf(figname,"regular/ppi_%d%d_cent%s.gif",pionid,protonid,centstring);
  c1->Print(figname);
  sprintf(figname,"regular/ppi_%d%d_cent%s.eps",pionid,protonid,centstring);
  c1->Print(figname);


  c1->Clear();
  // tmg->Clear();
  // tmg->Delete();



  // ----------------- //
  // --- Run2 part --- //
  // ----------------- //

  float ptpion[34];
  float ptproton[34];
  float eptpion[34]={0};
  float eptproton[34]={0};
  float ptratio[34];
  float eptratio[34]={0};
  float yieldpionpos[34],yieldpionneg[34];
  float eyieldpionpos[34],eyieldpionneg[34];
  float yieldprotonpos[34],yieldprotonneg[34];
  float eyieldprotonpos[34],eyieldprotonneg[34];
  float newratiopos[34],newrationeg[34];
  float enewratiopos[34],enewrationeg[34];

  float A, dA, B, dB;

  ifstream fin1;
  ifstream fin2;
  char fin1name[200];
  char fin2name[200];
  sprintf(fin1name,"ppg026/pospion_%s.dat",centstring);
  sprintf(fin2name,"ppg026/negpion_%s.dat",centstring);
  fin1.open(fin1name);
  fin2.open(fin2name);
  for(int i=0; i<28; i++)
    {
      fin1>>ptpion[i]>>yieldpionpos[i]>>eyieldpionpos[i];
      fin2>>ptpion[i]>>yieldpionneg[i]>>eyieldpionneg[i];
    }
  fin1.close();  
  fin2.close();
  sprintf(fin1name,"ppg026/posproton_%s.dat",centstring);
  sprintf(fin2name,"ppg026/negproton_%s.dat",centstring);
  fin1.open(fin1name);
  fin2.open(fin2name);
  for(int i=0; i<34; i++)
    {
      fin1>>ptproton[i]>>yieldprotonpos[i]>>eyieldprotonpos[i];
      fin2>>ptproton[i]>>yieldprotonneg[i]>>eyieldprotonneg[i];
    }
  fin1.close();  
  fin2.close();

  for(int i=0; i<24; i++)
    {
      //positive ratio
      A = yieldprotonpos[i];
      dA = eyieldprotonpos[i];
      B = yieldpionpos[i+4];
      dB = eyieldpionpos[i+4];
      newratiopos[i] = A/B;
      enewratiopos[i] = (A/B)*sqrt((dA/A)**2+(dB/B)**2);
      //cout<<"A = "<<A<<" dA = "<<dA<<" B = "<<B<<" dB = "<<dB<<endl;
      //cout<<"ptproton is "<<ptproton[i]<<endl;
      //cout<<"ptpion is "<<ptpion[i+4]<<endl;
      //negative ratio
      A = yieldprotonneg[i];
      dA = eyieldprotonneg[i];
      B = yieldpionneg[i+4];
      dB = eyieldpionneg[i+4];
      newrationeg[i] = A/B;
      enewrationeg[i] = (A/B)*sqrt((dA/A)**2+(dB/B)**2);
    }

  TGraphErrors *tposppg = new TGraphErrors(24,ptproton,newratiopos,eptproton,enewratiopos);
  tposppg->SetMarkerStyle(25);
  tposppg->SetMarkerColor(2);

  TGraphErrors *tnegppg = new TGraphErrors(24,ptproton,newrationeg,eptproton,enewrationeg);
  tnegppg->SetMarkerStyle(25);
  tnegppg->SetMarkerColor(4);

  // ------------------------ //
  // --- end of Run2 part --- //
  // ------------------------ //


  TMultiGraph *tmg2 = new TMultiGraph();
  tmg2->Add(tge_sysneg);
  tmg2->Add(tge_syspos);
  tmg2->Add(tge_neg);
  tmg2->Add(tge_pos);
  tmg2->Add(tnegppg);
  tmg2->Add(tposppg);
  tmg2->Draw("apz");
  //tmg2->SetMaximum(1.4);
  tmg2->SetMaximum(ymax); // 1.4 is fine but this is for comparisons...
  tmg2->SetMinimum(ymin);
  tmg2->GetXaxis()->SetLimits(xmin,xmax);
  tmg2->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg2->GetXaxis()->CenterTitle();
  tmg2->GetYaxis()->SetTitle("p/#pi ratio");
  tmg2->GetYaxis()->CenterTitle();

  TLegend *leg2 = new TLegend(0.68,0.68,0.88,0.88);
  leg2->SetFillColor(kWhite);
  leg2->SetBorderSize(0);
  leg2->AddEntry(tge_pos,"p/#pi^{+}","p");
  leg2->AddEntry(tge_neg,"#bar{p}/#pi^{-}","p");
  leg2->AddEntry(tposppg,"p/#pi^{+} Run2","p");
  leg2->AddEntry(tnegppg,"#bar{p}/#pi^{-} Run2","p");
  leg2->Draw();

  tpt_coll->Draw();
  tpt_cent->Draw();

  sprintf(figname,"regular/ppi_ppg_%d%d_cent%s.gif",pionid,protonid,centstring);
  c1->Print(figname);
  sprintf(figname,"regular/ppi_ppg_%d%d_cent%s.eps",pionid,protonid,centstring);
  c1->Print(figname);


  c1->Clear();



  // come back here for star

  float ptstar[29], eptstar[29];
  float protonyiestar[29], eprotonyiestar[29];
  float pionyiestar[29], epionyiestar[29];
  float starratio[29], estarratio[29];
  float ps1, ps2;

  char starprotonname[50];
  char starpionname[50];
  sprintf(starprotonname,"StarData/pr_star_%s.dat",starcentstring);
  sprintf(starpionname,"StarData/pp_star_%s.dat",starcentstring);
  ifstream finstarproton(starprotonname);
  ifstream finstarpion(starpionname);
  float tmp;
  finstarpion>>tmp>>tmp>>tmp>>tmp>>tmp>>tmp;
  for(int i=0; i<26; i++)
    {
      finstarproton>>ps1>>protonyiestar[i]>>eprotonyiestar[i];
      finstarpion>>ps2>>pionyiestar[i]>>epionyiestar[i];
      if(fabs(ps1-ps2)>0.02&&ps1<7.0) {cout<<"big trouble"<<" "<<ps1<<" "<<ps2<<endl;break;}
      ptstar[i] = ps1;
      eptstar[i] = 0;
      starratio[i] = protonyiestar[i]/pionyiestar[i];
      //cout<<pionyiestar[i]<<" "<<protonyiestar[i]<<" "<<starratio[i]<<" "<<endl;
      estarratio[i] = starratio[i]*sqrt((eprotonyiestar[i]/protonyiestar[i])**2+(epionyiestar[i]/pionyiestar[i])**2);
    }
  finstarpion.close();
  finstarproton.close();
  //TGraphErrors *tge_star = new TGraphErrors(26,ptstar,starratio,eptstar,estarratio);
  TGraphErrors *tge_star = new TGraphErrors(23,ptstar,starratio,eptstar,estarratio);
  tge_star->SetMarkerStyle(kFullStar);
  tge_star->SetMarkerColor(kBlack);
  tge_star->SetMarkerSize(1.5);




  TMultiGraph *tmg3 = new TMultiGraph();
  tmg3->Add(tge_syspos);
  tmg3->Add(tge_pos);
  tmg3->Add(tge_star);
  tmg3->Draw("apz");
  //tmg3->SetMaximum(1.4);
  tmg3->SetMaximum(ymax); // 1.4 is fine but this is for comparisons...
  tmg3->SetMinimum(ymin);
  tmg3->GetXaxis()->SetLimits(xmin,xmax);
  tmg3->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg3->GetXaxis()->CenterTitle();
  tmg3->GetYaxis()->SetTitle("p/#pi ratio");
  tmg3->GetYaxis()->CenterTitle();

  TLegend *leg3 = new TLegend(0.68,0.68,0.88,0.88);
  leg3->SetFillColor(kWhite);
  leg3->SetBorderSize(0);
  leg3->AddEntry(tge_pos,"p/#pi^{+}","p");
  leg3->AddEntry(tge_star,"p/#pi^{+} STAR","p");
  leg3->Draw();

  tpt_coll->Draw();
  tpt_cent->Draw();

  sprintf(figname,"regular/ppi_star_%d%d_cent%s.gif",pionid,protonid,centstring);
  c1->Print(figname);
  sprintf(figname,"regular/ppi_star_%d%d_cent%s.eps",pionid,protonid,centstring);
  c1->Print(figname);


  c1->Clear();

  //sprintf(fin1name,"ppg026/pospion_%s.dat",centstring);
  //sprintf(fin2name,"ppg026/negpion_%s.dat",centstring);


  const int nspc = 6;
  float specpt[nspc];
  float especpt[nspc];
  float specpipos, specpineg, specprpos, specprneg;
  float especpipos, especpineg, especprpos, especprneg;

  float specratpos[nspc];
  float especratpos[nspc];
  float specratneg[nspc];
  float especratneg[nspc];

  if(pionid==0) sprintf(fin1name,"../HTMerge/Plotting/Data/corrected_R_yields_pos_cent%s.dat",centstring);
  else sprintf(fin1name,"../HTMerge/Plotting/Data/corrected_S_yields_pos_cent%s.dat",centstring);
  if(pionid==0) sprintf(fin2name,"../HTMerge/Plotting/Data/corrected_R_yields_neg_cent%s.dat",centstring);
  else sprintf(fin2name,"../HTMerge/Plotting/Data/corrected_S_yields_neg_cent%s.dat",centstring);
  ifstream fspec1(fin1name);
  ifstream fspec2(fin2name);
  for(int i=0; i<nspc; i++)
    {
      especpt[i] = 0;
      fspec1>>specpt[i]>>specpipos>>especpipos>>specprpos>>especprpos;
      fspec2>>specpt[i]>>specpineg>>especpineg>>specprneg>>especprneg;
      specratpos[i] = specprpos/specpipos;
      especratpos[i] = specprpos/specpipos*sqrt((especpipos/specpipos)**2+(especpipos/specpipos)**2);
      specratneg[i] = specprneg/specpineg;
      especratneg[i] = specprneg/specpineg*sqrt((especpineg/specpineg)**2+(especpineg/specpineg)**2);
      //cout<<specpt[i]<<" "<<specpipos<<" "<<specprpos<<" "<<specratpos[i]<<endl;
    }

  TGraphErrors *tge_specpos = new TGraphErrors(nspc,specpt,specratpos,especpt,especratpos);
  tge_specpos->SetMarkerStyle(kOpenTriangleUp);
  tge_specpos->SetMarkerColor(kBlack);
  TGraphErrors *tge_specneg = new TGraphErrors(nspc,specpt,specratneg,especpt,especratneg);
  tge_specneg->SetMarkerStyle(kOpenTriangleDown);
  tge_specneg->SetMarkerColor(kBlack);




  TMultiGraph *tmg4 = new TMultiGraph();
  tmg4->Add(tge_sysneg);
  tmg4->Add(tge_syspos);
  tmg4->Add(tge_neg);
  tmg4->Add(tge_pos);
  tmg4->Add(tge_specpos);
  tmg4->Add(tge_specneg);
  tmg4->Draw("apz");
  //tmg4->SetMaximum(1.4);
  tmg4->SetMaximum(ymax); // 1.4 is fine but this is for comparisons...
  tmg4->SetMinimum(ymin);
  tmg4->GetXaxis()->SetLimits(xmin,xmax);
  tmg4->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg4->GetXaxis()->CenterTitle();
  tmg4->GetYaxis()->SetTitle("p/#pi ratio");
  tmg4->GetYaxis()->CenterTitle();

  TLegend *leg4 = new TLegend(0.68,0.68,0.88,0.88);
  leg4->SetFillColor(kWhite);
  leg4->SetBorderSize(0);
  leg4->AddEntry(tge_pos,"p/#pi^{+}","p");
  leg4->AddEntry(tge_neg,"#bar{p}/#pi^{-}","p");
  leg4->AddEntry(tge_specpos,"p/#pi^{+}","p");
  leg4->AddEntry(tge_specneg,"#bar{p}/#pi^{-}","p");
  // leg4->AddEntry(tposppg,"p/#pi^{+} Run2","p");
  // leg4->AddEntry(tnegppg,"#bar{p}/#pi^{-} Run2","p");
  leg4->Draw();

  tpt_coll->Draw();
  tpt_cent->Draw();

  sprintf(figname,"special/ppi_spec_%d%d_cent%s.gif",pionid,protonid,centstring);
  c1->Print(figname);
  sprintf(figname,"special/ppi_spec_%d%d_cent%s.eps",pionid,protonid,centstring);
  c1->Print(figname);



  c1->Clear();
  delete c1;


}


