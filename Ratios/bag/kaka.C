void kaka()
{
  for(int i=0; i<5; i++)
    {
      doit_file(i,4);
    }
}


void doit_file(int centid=0, int kaonid=6)
{

  float ymin = 0.0;
  float xmin = 0.0;
  float ymax = 2.0;
  //float xmax = 5.0;
  float xmax = 4.0;
  const int nbin = 40;
  if(nbin < (xmax-3.0)*2+30)
    {
      cout<<"incorrect number of bins"<<endl;
      cout<<"number of bins is "<<nbin<<" but number of bins needed is "<<(xmax-3.0)*2+30<<endl;
    }

  TLine *line = new TLine(xmin,0.95,xmax,0.95);

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
  float kaonpos[nbin], ekaonpos[nbin];
  float kaonneg[nbin], ekaonneg[nbin];
  float tmp;



  // --------------- //
  // --- kaonpos --- //
  // --------------- //
  sprintf(filename,"FinalFeed/ptpid_tofw_pos_%d_dis_cent%s.dat",kaonid,centstring);
  fin.open(filename);
  for(int i=0; i<30; i++)
    {
      fin>>pt[i]>>kaonpos[i]>>ekaonpos[i];
      if((float)pt[i]!=float(float(i)/10.0+0.05)&&i>0) // they're the same but this evaluates as false
	{
	  cout<<"you gonna die"<<endl;
	  cout<<"pt is "<<pt[i]<<" but pt is "<<i/10.0+0.05<<endl;
	}
    }
  fin.close();
  sprintf(filename,"FinalFeed/R5_ptpid_tofw_pos_%d_dis_cent%s.dat",kaonid,centstring);
  fin.open(filename);
  for(int i=0; i<nbin-24; i++)
    {
      if(i<6) fin>>tmp>>tmp>>tmp;
      else
	{
	  fin>>pt[i+24]>>kaonpos[i+24]>>ekaonpos[i+24];
	  if((float)pt[i+24]!=float(i)/2.0+0.25)
	    {
	      cout<<"you gonna die"<<endl;
	      cout<<"pt is "<<pt[i+24]<<" but pt is "<<i/2.0+0.25<<endl;
	    }
	}
    }
  fin.close();

  // --------------- //
  // --- kaonneg --- //
  // --------------- //
  sprintf(filename,"FinalFeed/ptpid_tofw_neg_%d_dis_cent%s.dat",kaonid,centstring);
  fin.open(filename);
  for(int i=0; i<30; i++)
    {
      fin>>pt[i]>>kaonneg[i]>>ekaonneg[i];
      if((float)pt[i]!=float(float(i)/10.0+0.05)&&i>0) // they're the same but this evaluates as false
	{
	  cout<<"you gonna die"<<endl;
	  cout<<"pt is "<<pt[i]<<" but pt is "<<i/10.0+0.05<<endl;
	}
    }
  fin.close();
  sprintf(filename,"FinalFeed/R5_ptpid_tofw_neg_%d_dis_cent%s.dat",kaonid,centstring);
  fin.open(filename);
  for(int i=0; i<nbin-24; i++)
    {
      if(i<6) fin>>tmp>>tmp>>tmp;
      else
	{
	  fin>>pt[i+24]>>kaonneg[i+24]>>ekaonneg[i+24];
	  if((float)pt[i+24]!=float(i)/2.0+0.25)
	    {
	      cout<<"you gonna die"<<endl;
	      cout<<"pt is "<<pt[i+24]<<" but pt is "<<i/2.0+0.25<<endl;
	    }
	}
    }
  fin.close();



  float ratio[nbin], eratio[nbin], esysratio[nbin];
  float A, dA, B, dB;
  sprintf(filename,"regular/kaka_%d_cent%s.txt",kaonid,centstring);
  ofstream ftxt(filename);
  sprintf(filename,"regular/kaka_%d_cent%s.tex",kaonid,centstring);
  ofstream ftex(filename);
  for(int i=0; i<nbin; i++)
    {
      // pos
      A = kaonpos[i];
      dA = ekaonpos[i];
      B = kaonneg[i];
      dB = ekaonneg[i];
      ratio[i] = B/A;
      eratio[i] = B/A*sqrt((dA/A)**2+(dB/B)**2);
      esysratio[i] = 0.1*(B/A);
      if(A<=0||B<=0||dA<=0||dB<=0||pt[i]>4.0)
	{
	  ratio[i] = -9;
	  eratio[i] = 0;
	}
      ftxt<<pt[i]<<"\t"<<ratio[i]<<"\t"<<eratio[i]<<endl;
      ftex<<pt[i]<<" & "<<ratio[i]<<" & "<<eratio[i]<<" \\\\ "<<endl;
    }
  ftxt.close();  
  ftex.close();  
  
  
  for(int i=0; i<nbin; i++) ept[i]=0;  // yeah
  
  
  TGraphErrors *tge_pos = new TGraphErrors(nbin,pt,ratio,ept,eratio);
  tge_pos->SetMarkerColor(kRed);
  tge_pos->SetMarkerStyle(kFullSquare);

  TGraphErrors *tge_syspos = new TGraphErrors(nbin,pt,ratio,ept,esysratio);
  tge_syspos->SetMarkerColor(kRed);
  tge_syspos->SetMarkerStyle(1);
  tge_syspos->SetLineColor(kRed-10);
  tge_syspos->SetLineWidth(15);

  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tge_syspos);
  tmg->Add(tge_pos);
  tmg->Draw("apz");
  line->Draw("same");
  tmg->SetMaximum(ymax);
  tmg->SetMinimum(ymin);
  tmg->GetXaxis()->SetLimits(xmin,xmax);
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();
  tmg->GetYaxis()->SetTitle("K^{-}/K^{+} ratio");
  tmg->GetYaxis()->CenterTitle();

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

  //TLegend *leg = new TLegend(0.68,0.68,0.88,0.88);
  //TLegend *leg = new TLegend(0.12,0.18,0.48,0.38);
  TLegend *leg = new TLegend(0.18,0.18,0.38,0.38);
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->AddEntry(tge_pos,"K^{-}/K^{+}","p");
  leg->Draw();

  char figname[100];
  sprintf(figname,"regular/kaka_%d_cent%s.gif",kaonid,centstring);
  c1->Print(figname);
  sprintf(figname,"regular/kaka_%d_cent%s.eps",kaonid,centstring);
  c1->Print(figname);


  c1->Clear();
  // tmg->Clear();
  // tmg->Delete();



  // ----------------- //
  // --- Run2 part --- //
  // ----------------- //

  float ptkaon[34];
  float ptkaon[34];
  float eptkaon[34]={0};
  float eptkaon[34]={0};
  float ptratio[34];
  float eptratio[34]={0};
  float yieldkaonpos[34],yieldkaonneg[34];
  float eyieldkaonpos[34],eyieldkaonneg[34];
  float newratio[34],newrationeg[34];
  float enewratio[34],enewrationeg[34];

  float A, dA, B, dB;

  ifstream fin1;
  ifstream fin2;
  char fin1name[100];
  char fin2name[100];
  sprintf(fin1name,"ppg026/poskaon_%s.dat",centstring);
  sprintf(fin2name,"ppg026/negkaon_%s.dat",centstring);
  fin1.open(fin1name);
  fin2.open(fin2name);
  for(int i=0; i<18; i++)
    {
      fin1>>ptkaon[i]>>yieldkaonpos[i]>>eyieldkaonpos[i];
      fin2>>ptkaon[i]>>yieldkaonneg[i]>>eyieldkaonneg[i];
    }
  fin1.close();  
  fin2.close();

  for(int i=0; i<18; i++)
    {
      //positive ratio
      A = yieldkaonneg[i];
      dA = eyieldkaonneg[i];
      B = yieldkaonpos[i];
      dB = eyieldkaonpos[i];
      newratio[i] = A/B;
      enewratio[i] = (A/B)*sqrt((dA/A)**2+(dB/B)**2);
    }

  TGraphErrors *tposppg = new TGraphErrors(18,ptkaon,newratio,eptkaon,enewratio);
  tposppg->SetMarkerStyle(25);
  tposppg->SetMarkerColor(2);

  // ------------------------ //
  // --- end of Run2 part --- //
  // ------------------------ //


  TMultiGraph *tmg2 = new TMultiGraph();
  tmg2->Add(tge_syspos);
  tmg2->Add(tge_pos);
  tmg2->Add(tposppg);
  tmg2->Draw("apz");
  line->Draw("same");
  tmg2->SetMaximum(ymax);
  tmg2->SetMinimum(ymin);
  tmg2->GetXaxis()->SetLimits(xmin,xmax);
  tmg2->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg2->GetXaxis()->CenterTitle();
  tmg2->GetYaxis()->SetTitle("K^{-}/K^{+} ratio");
  tmg2->GetYaxis()->CenterTitle();

  tpt_cent->Draw();
  tpt_coll->Draw();

  //TLegend *leg2 = new TLegend(0.68,0.68,0.88,0.88);
  //TLegend *leg2 = new TLegend(0.18,0.18,0.38,0.38);
  TLegend *leg2 = new TLegend(0.12,0.18,0.48,0.38);
  leg2->SetFillColor(kWhite);
  leg2->SetBorderSize(0);
  leg2->AddEntry(tge_pos,"K^{-}/K^{+}","p");
  leg2->AddEntry(tposppg,"K^{-}/K^{+} Run2","p");
  leg2->Draw();

  sprintf(figname,"regular/kaka_ppg_%d_cent%s.gif",kaonid,centstring);
  c1->Print(figname);
  sprintf(figname,"regular/kaka_ppg_%d_cent%s.eps",kaonid,centstring);
  c1->Print(figname);




  c1->Clear();
  delete c1; // new
  return;    // new


  float ptstar[29], eptstar[29];
  float posyiestar[29], eposyiestar[29];
  float negyiestar[29], enegyiestar[29];
  float starratio[29], estarratio[29];
  float ps1, ps2;

  char starposname[50];
  char starnegname[50];
  sprintf(starposname,"StarData/pp_star_%s.dat",starcentstring);
  sprintf(starnegname,"StarData/pm_star_%s.dat",starcentstring);
  ifstream finstarpos(starposname);
  ifstream finstarneg(starnegname);
  for(int i=0; i<29; i++)
    {
      finstarpos>>ps1>>posyiestar[i]>>eposyiestar[i];
      finstarneg>>ps2>>negyiestar[i]>>enegyiestar[i];
      if(ps1!=ps2) {cout<<"big trouble"<<endl;break;}
      ptstar[i] = ps1;
      eptstar[i] = 0;
      starratio[i] = negyiestar[i]/posyiestar[i];
      estarratio[i] = starratio[i]*sqrt((eposyiestar[i]/posyiestar[i])**2+(enegyiestar[i]/negyiestar[i])**2);
    }
  TGraphErrors *tge_star = new TGraphErrors(29,ptstar,starratio,eptstar,estarratio);
  tge_star->SetMarkerStyle(kFullStar);
  tge_star->SetMarkerColor(kBlack);
  tge_star->SetMarkerSize(1.5);


  TMultiGraph *tmg3 = new TMultiGraph();
  tmg3->Add(tge_syspos);
  tmg3->Add(tge_pos);
  tmg3->Add(tge_star);
  tmg3->Draw("apz");
  line->Draw("same");
  tmg3->SetMaximum(ymax);
  tmg3->SetMinimum(ymin);
  tmg3->GetXaxis()->SetLimits(xmin,xmax);
  tmg3->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg3->GetXaxis()->CenterTitle();
  tmg3->GetYaxis()->SetTitle("K^{-}/K^{+} ratio");
  tmg3->GetYaxis()->CenterTitle();

  tpt_cent->Draw();
  tpt_coll->Draw();

  TLegend *leg3 = new TLegend(0.12,0.18,0.48,0.38);
  leg3->SetFillColor(kWhite);
  leg3->SetBorderSize(0);
  leg3->AddEntry(tge_pos,"K^{-}/K^{+}","p");
  leg3->AddEntry(tge_star,"K^{-}/K^{+} STAR","p");
  leg3->Draw();

  sprintf(figname,"regular/kaka_star_%d_cent%s.gif",kaonid,centstring);
  c1->Print(figname);
  sprintf(figname,"regular/kaka_star_%d_cent%s.eps",kaonid,centstring);
  c1->Print(figname);

  c1->Clear();
  delete c1;


}
