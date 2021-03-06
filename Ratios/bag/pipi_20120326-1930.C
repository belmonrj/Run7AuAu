void pipi()
{
  for(int i=0; i<5; i++)
    {
      doit_file(i,0);
      doit_file(i,2);
    }
}


void doit_file(int centid=0, int pionid=6)
{

  TLine *line = new TLine(0.0,1.0,6.0,1.0);

  TCanvas *c1 = new TCanvas("c1","",800,600);

  char centstring[5];
  if(centid==0) sprintf(centstring,"0010");
  else if(centid==1) sprintf(centstring,"1020");
  else if(centid==2) sprintf(centstring,"2040");
  else if(centid==3) sprintf(centstring,"4060");
  else if(centid==4) sprintf(centstring,"6092");
  else {cout<<"you gonna die"<<endl; return;}


  char filename[100];
  ifstream fin;

  float pt[36], ept[36];
  float pionpos[36], epionpos[36];
  float pionneg[36], epionneg[36];
  float tmp;



  // --------------- //
  // --- pionpos --- //
  // --------------- //
  sprintf(filename,"../Spectra/Data/FinalFeed/ptpid_tofw_pos_%d_dis_cent%s.dat",pionid,centstring);
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
  sprintf(filename,"../Spectra/Data/FinalFeed/R5_ptpid_tofw_pos_%d_dis_cent%s.dat",pionid,centstring);
  fin.open(filename);
  for(int i=0; i<12; i++)
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
  sprintf(filename,"../Spectra/Data/FinalFeed/ptpid_tofw_neg_%d_dis_cent%s.dat",pionid,centstring);
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
  sprintf(filename,"../Spectra/Data/FinalFeed/R5_ptpid_tofw_neg_%d_dis_cent%s.dat",pionid,centstring);
  fin.open(filename);
  for(int i=0; i<12; i++)
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



  float ratio[36], eratio[36], esysratio[36];

  float A, dA, B, dB;

  for(int i=0; i<36; i++)
    {
      // pos
      A = pionpos[i];
      dA = epionpos[i];
      B = pionneg[i];
      dB = epionneg[i];
      ratio[i] = B/A;
      eratio[i] = B/A*sqrt((dA/A)**2+(dB/B)**2);
      esysratio[i] = 0.1*(B/A);
    }
  
  
  for(int i=0; i<36; i++) ept[i]=0;  // yeah
  
  
  TGraphErrors *tge_pos = new TGraphErrors(36,pt,ratio,ept,eratio);
  tge_pos->SetMarkerColor(kRed);
  tge_pos->SetMarkerStyle(kFullSquare);

  TGraphErrors *tge_syspos = new TGraphErrors(36,pt,ratio,ept,esysratio);
  tge_syspos->SetMarkerColor(kRed);
  tge_syspos->SetMarkerStyle(1);
  tge_syspos->SetLineColor(kRed-10);
  tge_syspos->SetLineWidth(15);

  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tge_syspos);
  tmg->Add(tge_pos);
  tmg->Draw("apz");
  line->Draw("same");
  //tmg->SetMaximum(1.4);
  tmg->SetMaximum(1.6); // 1.4 is fine but this is for comparisons...
  tmg->SetMinimum(0.0);
  tmg->GetXaxis()->SetLimits(0.0,6.0);
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();
  tmg->GetYaxis()->SetTitle("#pi^{-}/#pi^{+} ratio");
  tmg->GetYaxis()->CenterTitle();

  //TLegend *leg = new TLegend(0.68,0.68,0.88,0.88);
  TLegend *leg = new TLegend(0.18,0.18,0.38,0.38);
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->AddEntry(tge_pos,"#pi^{-}/#pi^{+}","p");
  leg->Draw();

  char figname[100];
  sprintf(figname,"regular/pipi_%d_cent%s.gif",pionid,centstring);
  c1->Print(figname);
  sprintf(figname,"regular/pipi_%d_cent%s.eps",pionid,centstring);
  c1->Print(figname);


  c1->Clear();
  // tmg->Clear();
  // tmg->Delete();



  // ----------------- //
  // --- Run2 part --- //
  // ----------------- //

  float ptpion[34];
  float ptpion[34];
  float eptpion[34]={0};
  float eptpion[34]={0};
  float ptratio[34];
  float eptratio[34]={0};
  float yieldpionpos[34],yieldpionneg[34];
  float eyieldpionpos[34],eyieldpionneg[34];
  float newratio[34],newrationeg[34];
  float enewratio[34],enewrationeg[34];

  float A, dA, B, dB;

  ifstream fin1;
  ifstream fin2;
  char fin1name[100];
  char fin2name[100];
  sprintf(fin1name,"../Spectra/ppg026/pospion_%s.dat",centstring);
  sprintf(fin2name,"../Spectra/ppg026/negpion_%s.dat",centstring);
  fin1.open(fin1name);
  fin2.open(fin2name);
  for(int i=0; i<28; i++)
    {
      fin1>>ptpion[i]>>yieldpionpos[i]>>eyieldpionpos[i];
      fin2>>ptpion[i]>>yieldpionneg[i]>>eyieldpionneg[i];
    }
  fin1.close();  
  fin2.close();

  for(int i=0; i<34; i++)
    {
      //positive ratio
      A = yieldpionneg[i];
      dA = eyieldpionneg[i];
      B = yieldpionpos[i];
      dB = eyieldpionpos[i];
      newratio[i] = A/B;
      enewratio[i] = (A/B)*sqrt((dA/A)**2+(dB/B)**2);
    }

  TGraphErrors *tposppg = new TGraphErrors(28,ptpion,newratio,eptpion,enewratio);
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
  //tmg2->SetMaximum(1.4);
  tmg2->SetMaximum(1.6); // 1.4 is fine but this is for comparisons...
  tmg2->SetMinimum(0.0);
  tmg2->GetXaxis()->SetLimits(0.0,6.0);
  tmg2->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg2->GetXaxis()->CenterTitle();
  tmg2->GetYaxis()->SetTitle("#pi^{-}/#pi^{+} ratio");
  tmg2->GetYaxis()->CenterTitle();

  //TLegend *leg2 = new TLegend(0.68,0.68,0.88,0.88);
  TLegend *leg2 = new TLegend(0.18,0.18,0.38,0.38);
  leg2->SetFillColor(kWhite);
  leg2->SetBorderSize(0);
  leg2->AddEntry(tge_pos,"#pi^{-}/#pi^{+}","p");
  leg2->AddEntry(tposppg,"#pi^{-}/#pi^{+} Run2","p");
  leg2->Draw();

  sprintf(figname,"regular/pipi_ppg_%d_cent%s.gif",pionid,centstring);
  c1->Print(figname);
  sprintf(figname,"regular/pipi_ppg_%d_cent%s.eps",pionid,centstring);
  c1->Print(figname);







  c1->Clear();
  //c1->Delete();
  delete c1;


}
