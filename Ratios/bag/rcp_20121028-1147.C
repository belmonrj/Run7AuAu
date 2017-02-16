void rcp_new()
{

  doit_file(0,4,0,4,6);
  doit_file(0,4,1,4,7);
  doit_file(0,4,2,4,8);
  doit_file(0,4,3,4,9);

  doit_file(0,3,0,4,6);
  doit_file(0,3,1,4,7);
  doit_file(0,3,2,4,8);
  doit_file(0,3,3,4,9);

}



void doit_file(int centid1=0, int centid2=4, int pionid=0, int kaonid=4, int protonid=6)
{

  float ymin = 0.0;
  float xmin = 0.0;
  float ymax = 2.0;
  float xmax = 6.0;
  const int nbin = 44;
  if(nbin < (xmax-3.0)*2+30)
    {
      cout<<"incorrect number of bins"<<endl;
      cout<<"number of bins is "<<nbin<<" but number of bins needed is "<<(xmax-3.0)*2+30<<endl;
    }

  const float Ncoll[5] = {960.2,609.5,300.8,94.2,14.8};
  const float normal = Ncoll[centid1]/Ncoll[centid2]; // Run7 numbers
  char centstring1[5];
  if(centid1==0) sprintf(centstring1,"0010");
  else if(centid1==1) sprintf(centstring1,"1020");
  else if(centid1==2) sprintf(centstring1,"2040");
  else if(centid1==3) sprintf(centstring1,"4060");
  else if(centid1==4) sprintf(centstring1,"6092");
  else {cout<<"trouble"<<endl; return;}
  char centstring2[5];
  if(centid2==0) sprintf(centstring2,"0010");
  else if(centid2==1) sprintf(centstring2,"1020");
  else if(centid2==2) sprintf(centstring2,"2040");
  else if(centid2==3) sprintf(centstring2,"4060");
  else if(centid2==4) sprintf(centstring2,"6092");
  else {cout<<"trouble"<<endl; return;}

  TLine *line = new TLine(xmin,1.0,xmax,1.0);

  TCanvas *c1 = new TCanvas();

  TF1 *fun = new TF1("fun","pol0",0,10);
  fun->SetParameter(0,1);

  float tmp;

  char centstring_C[10];
  sprintf(centstring_C,"%s",centstring1);
  char centstring_P[10];
  sprintf(centstring_P,"%s",centstring2);

  char fnameinposcb_C[100];
  char fnameinnegcb_C[100];
  char fnameinposcb_P[100];
  char fnameinnegcb_P[100];

  float ept[nbin]={0};

  // ----------------------- //
  // ----------------------- //
  // ---                 --- //
  // --- first the pions --- //
  // ---                 --- //
  // ----------------------- //
  // ----------------------- //

  // ---------------------- //
  // --- do the central --- //
  // ---------------------- //
  sprintf(fnameinposcb_C,"FinalFeed/ptpid_tofw_pos_%d_dis_cent%s.dat",pionid,centstring_C);
  sprintf(fnameinnegcb_C,"FinalFeed/ptpid_tofw_neg_%d_dis_cent%s.dat",pionid,centstring_C);
  ifstream finposcb_C;
  ifstream finnegcb_C;
  finposcb_C.open(fnameinposcb_C);
  finnegcb_C.open(fnameinnegcb_C);
  float pT_poscb_C[nbin], yield_poscb_C[nbin], eyield_poscb_C[nbin];
  float pT_negcb_C[nbin], yield_negcb_C[nbin], eyield_negcb_C[nbin];
  for(int i=0; i<30; i++)
    {
      finposcb_C>>pT_poscb_C[i]>>yield_poscb_C[i]>>eyield_poscb_C[i];
      finnegcb_C>>pT_negcb_C[i]>>yield_negcb_C[i]>>eyield_negcb_C[i];
    }
  finposcb_C.close();
  finnegcb_C.close();
  sprintf(fnameinposcb_C,"FinalFeed/R5_ptpid_tofw_pos_%d_dis_cent%s.dat",pionid,centstring_C);
  sprintf(fnameinnegcb_C,"FinalFeed/R5_ptpid_tofw_neg_%d_dis_cent%s.dat",pionid,centstring_C);
  finposcb_C.open(fnameinposcb_C);
  finnegcb_C.open(fnameinnegcb_C);
  for(int i=0; i<nbin-24; i++)
    {
      if(i<6)
	{
	  finposcb_C>>tmp>>tmp>>tmp;
	  finnegcb_C>>tmp>>tmp>>tmp;
	}
      else
	{
	  finposcb_C>>pT_poscb_C[i+24]>>yield_poscb_C[i+24]>>eyield_poscb_C[i+24];
	  finnegcb_C>>pT_negcb_C[i+24]>>yield_negcb_C[i+24]>>eyield_negcb_C[i+24];
	}
    }
  finposcb_C.close();
  finnegcb_C.close();

  // ---------------------- //
  // --- now peripheral --- //
  // ---------------------- //
  sprintf(fnameinposcb_P,"FinalFeed/ptpid_tofw_pos_%d_dis_cent%s.dat",pionid,centstring_P);
  sprintf(fnameinnegcb_P,"FinalFeed/ptpid_tofw_neg_%d_dis_cent%s.dat",pionid,centstring_P);
  ifstream finposcb_P;
  ifstream finnegcb_P;
  finposcb_P.open(fnameinposcb_P);
  finnegcb_P.open(fnameinnegcb_P);
  float pT_poscb_P[nbin], yield_poscb_P[nbin], eyield_poscb_P[nbin];
  float pT_negcb_P[nbin], yield_negcb_P[nbin], eyield_negcb_P[nbin];
  for(int i=0; i<30; i++)
    {
      finposcb_P>>pT_poscb_P[i]>>yield_poscb_P[i]>>eyield_poscb_P[i];
      finnegcb_P>>pT_negcb_P[i]>>yield_negcb_P[i]>>eyield_negcb_P[i];
    }
  finposcb_P.close();
  finnegcb_P.close();
  sprintf(fnameinposcb_P,"FinalFeed/R5_ptpid_tofw_pos_%d_dis_cent%s.dat",pionid,centstring_P);
  sprintf(fnameinnegcb_P,"FinalFeed/R5_ptpid_tofw_neg_%d_dis_cent%s.dat",pionid,centstring_P);
  finposcb_P.open(fnameinposcb_P);
  finnegcb_P.open(fnameinnegcb_P);
  for(int i=0; i<nbin-24; i++)
    {
      if(i<6)
	{
	  finposcb_P>>tmp>>tmp>>tmp;
	  finnegcb_P>>tmp>>tmp>>tmp;
	}
      else
	{
	  finposcb_P>>pT_poscb_P[i+24]>>yield_poscb_P[i+24]>>eyield_poscb_P[i+24];
	  finnegcb_P>>pT_negcb_P[i+24]>>yield_negcb_P[i+24]>>eyield_negcb_P[i+24];
	}
    }
  finposcb_P.close();
  finnegcb_P.close();

  float pTpos[nbin], ratiopos[nbin], eratiopos[nbin], esysratiopos[nbin];
  float pTneg[nbin], rationeg[nbin], erationeg[nbin], esysrationeg[nbin];

  float pTpos_pion_nq[nbin], epTpos_pion_nq[nbin];
  float pTneg_pion_nq[nbin], epTneg_pion_nq[nbin];
  float ratiopos_pion_nq[nbin], eratiopos_pion_nq[nbin], esysratiopos_pion_nq[nbin];
  float rationeg_pion_nq[nbin], erationeg_pion_nq[nbin], esysrationeg_pion_nq[nbin];
  char filename[100];
  sprintf(filename,"regular/rcp_%d_c%d%d.txt",pionid,centid1,centid2);
  ofstream ftxt(filename);
  sprintf(filename,"regular/rcp_%d_c%d%d.tex",pionid,centid1,centid2);
  ofstream ftex(filename);
  for(int i=0; i<nbin; i++)
    {
      if(yield_poscb_P[i]>0&&yield_negcb_P[i]>0)
	{
	  pTpos[i] = pT_poscb_C[i];
	  ratiopos[i] = yield_poscb_C[i]/yield_poscb_P[i];
	  eratiopos[i] = yield_poscb_C[i]/yield_poscb_P[i]
	    *sqrt((eyield_poscb_C[i]/yield_poscb_C[i])**2+(eyield_poscb_P[i]/yield_poscb_P[i])**2);
	  pTneg[i] = pT_negcb_C[i];
	  rationeg[i] = yield_negcb_C[i]/yield_negcb_P[i];
	  erationeg[i] = yield_negcb_C[i]/yield_negcb_P[i]
	    *sqrt((eyield_negcb_C[i]/yield_negcb_C[i])**2+(eyield_negcb_P[i]/yield_negcb_P[i])**2);
	}
      else
	{
	  pTpos[i]=0;
	  pTneg[i]=0;
	  ratiopos[i]=-9;
	  rationeg[i]=-9;
	  eratiopos[i]=0;
	  erationeg[i]=0;
	}
      ratiopos[i] /= normal;
      rationeg[i] /= normal;
      eratiopos[i] /= normal;
      erationeg[i] /= normal;
      esysratiopos[i] = ratiopos[i]*0.1; // 10% sys uncert
      esysrationeg[i] = rationeg[i]*0.1; // 10% sys uncert
      // nq scaling?
      pTpos_pion_nq[i] = pTpos[i]/2.0;
      epTpos_pion_nq[i] = 0;
      ratiopos_pion_nq[i] = ratiopos[i]/2.0;
      eratiopos_pion_nq[i] = eratiopos[i]/2.0;
      esysratiopos_pion_nq[i] = esysratiopos[i]/2.0;
      pTneg_pion_nq[i] = pTneg[i]/2.0;
      epTneg_pion_nq[i] = 0;
      rationeg_pion_nq[i] = rationeg[i]/2.0;
      erationeg_pion_nq[i] = erationeg[i]/2.0;
      esysrationeg_pion_nq[i] = esysrationeg[i]/2.0;
      if(i<5)
	{
	  ratiopos[i] = -9;
	  rationeg[i] = -9;
	  eratiopos[i] = 0;
	  erationeg[i] = 0;
	}
      ftxt<<pTpos[i]<<"\t"<<ratiopos[i]<<"\t"<<eratiopos[i]<<"\t"<<rationeg[i]<<"\t"<<erationeg[i]<<endl;
      ftex<<pTpos[i]<<" & "<<ratiopos[i]<<" & "<<eratiopos[i]<<" & "<<rationeg[i]<<" & "<<erationeg[i]<<" \\\\ "<<endl;
    }

  TGraphErrors *tge_pospion = new TGraphErrors(nbin,pTpos,ratiopos,ept,eratiopos);
  TGraphErrors *tge_negpion = new TGraphErrors(nbin,pTneg,rationeg,ept,erationeg);
  TGraphErrors *tge_syspospion = new TGraphErrors(nbin,pTpos,ratiopos,ept,esysratiopos);
  TGraphErrors *tge_sysnegpion = new TGraphErrors(nbin,pTneg,rationeg,ept,esysrationeg);

  TGraphErrors *tge_pospion_nq = new TGraphErrors(nbin,pTpos_pion_nq,ratiopos,ept,eratiopos);
  TGraphErrors *tge_pospion_NQ = new TGraphErrors(nbin,pTpos_pion_nq,ratiopos_pion_nq,ept,eratiopos_pion_nq);
  TGraphErrors *tge_negpion_nq = new TGraphErrors(nbin,pTneg_pion_nq,rationeg,ept,erationeg);
  TGraphErrors *tge_negpion_NQ = new TGraphErrors(nbin,pTneg_pion_nq,rationeg_pion_nq,ept,erationeg_pion_nq);
  TGraphErrors *tge_syspospion_nq = new TGraphErrors(nbin,pTpos_pion_nq,ratiopos,ept,esysratiopos);
  TGraphErrors *tge_syspospion_NQ = new TGraphErrors(nbin,pTpos_pion_nq,ratiopos_pion_nq,ept,esysratiopos_pion_nq);
  TGraphErrors *tge_sysnegpion_nq = new TGraphErrors(nbin,pTneg_pion_nq,rationeg,ept,esysrationeg);
  TGraphErrors *tge_sysnegpion_NQ = new TGraphErrors(nbin,pTneg_pion_nq,rationeg_pion_nq,ept,esysrationeg_pion_nq);


  // --------------------- //
  // --------------------- //
  // ---               --- //
  // --- now the kaons --- //
  // ---               --- //
  // --------------------- //
  // --------------------- //

  // ---------------------- //
  // --- do the central --- //
  // ---------------------- //
  sprintf(fnameinposcb_C,"FinalFeed/ptpid_tofw_pos_%d_dis_cent%s.dat",kaonid,centstring_C);
  sprintf(fnameinnegcb_C,"FinalFeed/ptpid_tofw_neg_%d_dis_cent%s.dat",kaonid,centstring_C);
  finposcb_C.open(fnameinposcb_C);
  finnegcb_C.open(fnameinnegcb_C);
  for(int i=0; i<30; i++)
    {
      finposcb_C>>pT_poscb_C[i]>>yield_poscb_C[i]>>eyield_poscb_C[i];
      finnegcb_C>>pT_negcb_C[i]>>yield_negcb_C[i]>>eyield_negcb_C[i];
    }
  finposcb_C.close();
  finnegcb_C.close();
  sprintf(fnameinposcb_C,"FinalFeed/R5_ptpid_tofw_pos_%d_dis_cent%s.dat",kaonid,centstring_C);
  sprintf(fnameinnegcb_C,"FinalFeed/R5_ptpid_tofw_neg_%d_dis_cent%s.dat",kaonid,centstring_C);
  finposcb_C.open(fnameinposcb_C);
  finnegcb_C.open(fnameinnegcb_C);
  for(int i=0; i<nbin-24; i++)
    {
      if(i<6)
	{
	  finposcb_C>>tmp>>tmp>>tmp;
	  finnegcb_C>>tmp>>tmp>>tmp;
	}
      else
	{
	  finposcb_C>>pT_poscb_C[i+24]>>yield_poscb_C[i+24]>>eyield_poscb_C[i+24];
	  finnegcb_C>>pT_negcb_C[i+24]>>yield_negcb_C[i+24]>>eyield_negcb_C[i+24];
	}
    }
  finposcb_C.close();
  finnegcb_C.close();

  // ---------------------- //
  // --- now peripheral --- //
  // ---------------------- //
  sprintf(fnameinposcb_P,"FinalFeed/ptpid_tofw_pos_%d_dis_cent%s.dat",kaonid,centstring_P);
  sprintf(fnameinnegcb_P,"FinalFeed/ptpid_tofw_neg_%d_dis_cent%s.dat",kaonid,centstring_P);
  finposcb_P.open(fnameinposcb_P);
  finnegcb_P.open(fnameinnegcb_P);
  for(int i=0; i<30; i++)
    {
      finposcb_P>>pT_poscb_P[i]>>yield_poscb_P[i]>>eyield_poscb_P[i];
      finnegcb_P>>pT_negcb_P[i]>>yield_negcb_P[i]>>eyield_negcb_P[i];
    }
  finposcb_P.close();
  finnegcb_P.close();
  sprintf(fnameinposcb_P,"FinalFeed/R5_ptpid_tofw_pos_%d_dis_cent%s.dat",kaonid,centstring_P);
  sprintf(fnameinnegcb_P,"FinalFeed/R5_ptpid_tofw_neg_%d_dis_cent%s.dat",kaonid,centstring_P);
  finposcb_P.open(fnameinposcb_P);
  finnegcb_P.open(fnameinnegcb_P);
  for(int i=0; i<nbin-24; i++)
    {
      if(i<6)
	{
	  finposcb_P>>tmp>>tmp>>tmp;
	  finnegcb_P>>tmp>>tmp>>tmp;
	}
      else
	{
	  finposcb_P>>pT_poscb_P[i+24]>>yield_poscb_P[i+24]>>eyield_poscb_P[i+24];
	  finnegcb_P>>pT_negcb_P[i+24]>>yield_negcb_P[i+24]>>eyield_negcb_P[i+24];
	}
    }
  finposcb_P.close();
  finnegcb_P.close();

  float pTpos_kaon_nq[nbin], epTpos_kaon_nq[nbin];
  float pTneg_kaon_nq[nbin], epTneg_kaon_nq[nbin];
  float ratiopos_kaon_nq[nbin], eratiopos_kaon_nq[nbin], esysratiopos_kaon_nq[nbin];
  float rationeg_kaon_nq[nbin], erationeg_kaon_nq[nbin], esysrationeg_kaon_nq[nbin];
  sprintf(filename,"regular/rcp_%d_c%d%d.txt",kaonid,centid1,centid2);
  ofstream ftxt(filename);
  sprintf(filename,"regular/rcp_%d_c%d%d.tex",kaonid,centid1,centid2);
  ofstream ftex(filename);
  for(int i=0; i<nbin; i++)
    {
      if(yield_poscb_P[i]>0&&yield_negcb_P[i]>0)
	{
	  pTpos[i] = pT_poscb_C[i];
	  ratiopos[i] = yield_poscb_C[i]/yield_poscb_P[i];
	  eratiopos[i] = yield_poscb_C[i]/yield_poscb_P[i]
	    *sqrt((eyield_poscb_C[i]/yield_poscb_C[i])**2+(eyield_poscb_P[i]/yield_poscb_P[i])**2);
	  pTneg[i] = pT_negcb_C[i];
	  rationeg[i] = yield_negcb_C[i]/yield_negcb_P[i];
	  erationeg[i] = yield_negcb_C[i]/yield_negcb_P[i]
	    *sqrt((eyield_negcb_C[i]/yield_negcb_C[i])**2+(eyield_negcb_P[i]/yield_negcb_P[i])**2);
	}
      else
	{
	  pTpos[i]=0;
	  pTneg[i]=0;
	  ratiopos[i]=-9;
	  rationeg[i]=-9;
	  eratiopos[i]=0;
	  erationeg[i]=0;
	}
      ratiopos[i] /= normal;
      rationeg[i] /= normal;
      eratiopos[i] /= normal;
      erationeg[i] /= normal;
      esysratiopos[i] = ratiopos[i]*0.1; // 10% sys uncert
      esysrationeg[i] = rationeg[i]*0.1; // 10% sys uncert
      // nq scaling?
      pTpos_kaon_nq[i] = pTpos[i]/3.0;
      epTpos_kaon_nq[i] = 0;
      ratiopos_kaon_nq[i] = ratiopos[i]/3.0;
      eratiopos_kaon_nq[i] = eratiopos[i]/3.0;
      esysratiopos_kaon_nq[i] = esysratiopos[i]/3.0;
      pTneg_kaon_nq[i] = pTneg[i]/3.0;
      epTneg_kaon_nq[i] = 0;
      rationeg_kaon_nq[i] = rationeg[i]/3.0;
      erationeg_kaon_nq[i] = erationeg[i]/3.0;
      esysrationeg_kaon_nq[i] = esysrationeg[i]/3.0;
      if(pTpos[i]>4.0||pTpos[i]<0.5)
	{
	  ratiopos[i] = -9;
	  rationeg[i] = -9;
	  eratiopos[i] = 0;
	  erationeg[i] = 0;
	}
      ftxt<<pTpos[i]<<"\t"<<ratiopos[i]<<"\t"<<eratiopos[i]<<"\t"<<rationeg[i]<<"\t"<<erationeg[i]<<endl;
      ftex<<pTpos[i]<<" & "<<ratiopos[i]<<" & "<<eratiopos[i]<<" & "<<rationeg[i]<<" & "<<erationeg[i]<<" \\\\ "<<endl;
    }

  TGraphErrors *tge_poskaon = new TGraphErrors(nbin,pTpos,ratiopos,ept,eratiopos);
  TGraphErrors *tge_negkaon = new TGraphErrors(nbin,pTneg,rationeg,ept,erationeg);
  TGraphErrors *tge_sysposkaon = new TGraphErrors(nbin,pTpos,ratiopos,ept,esysratiopos);
  TGraphErrors *tge_sysnegkaon = new TGraphErrors(nbin,pTneg,rationeg,ept,esysrationeg);

  TGraphErrors *tge_poskaon_nq = new TGraphErrors(nbin,pTpos_kaon_nq,ratiopos,ept,eratiopos);
  TGraphErrors *tge_poskaon_NQ = new TGraphErrors(nbin,pTpos_kaon_nq,ratiopos_kaon_nq,ept,eratiopos_kaon_nq);
  TGraphErrors *tge_negkaon_nq = new TGraphErrors(nbin,pTneg_kaon_nq,rationeg,ept,erationeg);
  TGraphErrors *tge_negkaon_NQ = new TGraphErrors(nbin,pTneg_kaon_nq,rationeg_kaon_nq,ept,erationeg_kaon_nq);
  TGraphErrors *tge_sysposkaon_nq = new TGraphErrors(nbin,pTpos_kaon_nq,ratiopos,ept,esysratiopos);
  TGraphErrors *tge_sysposkaon_NQ = new TGraphErrors(nbin,pTpos_kaon_nq,ratiopos_kaon_nq,ept,esysratiopos_kaon_nq);
  TGraphErrors *tge_sysnegkaon_nq = new TGraphErrors(nbin,pTneg_kaon_nq,rationeg,ept,esysrationeg);
  TGraphErrors *tge_sysnegkaon_NQ = new TGraphErrors(nbin,pTneg_kaon_nq,rationeg_kaon_nq,ept,esysrationeg_kaon_nq);



  // ----------------------- //
  // ----------------------- //
  // ---                 --- //
  // --- now the protons --- //
  // ---                 --- //
  // ----------------------- //
  // ----------------------- //

  // ---------------------- //
  // --- do the central --- //
  // ---------------------- //
  sprintf(fnameinposcb_C,"FinalFeed/ptpid_tofw_pos_%d_dis_cent%s.dat",protonid,centstring_C);
  sprintf(fnameinnegcb_C,"FinalFeed/ptpid_tofw_neg_%d_dis_cent%s.dat",protonid,centstring_C);
  finposcb_C.open(fnameinposcb_C);
  finnegcb_C.open(fnameinnegcb_C);
  for(int i=0; i<30; i++)
    {
      finposcb_C>>pT_poscb_C[i]>>yield_poscb_C[i]>>eyield_poscb_C[i];
      finnegcb_C>>pT_negcb_C[i]>>yield_negcb_C[i]>>eyield_negcb_C[i];
    }
  finposcb_C.close();
  finnegcb_C.close();
  sprintf(fnameinposcb_C,"FinalFeed/R5_ptpid_tofw_pos_%d_dis_cent%s.dat",protonid,centstring_C);
  sprintf(fnameinnegcb_C,"FinalFeed/R5_ptpid_tofw_neg_%d_dis_cent%s.dat",protonid,centstring_C);
  finposcb_C.open(fnameinposcb_C);
  finnegcb_C.open(fnameinnegcb_C);
  for(int i=0; i<nbin-24; i++)
    {
      if(i<6)
	{
	  finposcb_C>>tmp>>tmp>>tmp;
	  finnegcb_C>>tmp>>tmp>>tmp;
	}
      else
	{
	  finposcb_C>>pT_poscb_C[i+24]>>yield_poscb_C[i+24]>>eyield_poscb_C[i+24];
	  finnegcb_C>>pT_negcb_C[i+24]>>yield_negcb_C[i+24]>>eyield_negcb_C[i+24];
	}
    }
  finposcb_C.close();
  finnegcb_C.close();

  // ---------------------- //
  // --- now peripheral --- //
  // ---------------------- //
  sprintf(fnameinposcb_P,"FinalFeed/ptpid_tofw_pos_%d_dis_cent%s.dat",protonid,centstring_P);
  sprintf(fnameinnegcb_P,"FinalFeed/ptpid_tofw_neg_%d_dis_cent%s.dat",protonid,centstring_P);
  finposcb_P.open(fnameinposcb_P);
  finnegcb_P.open(fnameinnegcb_P);
  for(int i=0; i<30; i++)
    {
      finposcb_P>>pT_poscb_P[i]>>yield_poscb_P[i]>>eyield_poscb_P[i];
      finnegcb_P>>pT_negcb_P[i]>>yield_negcb_P[i]>>eyield_negcb_P[i];
    }
  finposcb_P.close();
  finnegcb_P.close();
  sprintf(fnameinposcb_P,"FinalFeed/R5_ptpid_tofw_pos_%d_dis_cent%s.dat",protonid,centstring_P);
  sprintf(fnameinnegcb_P,"FinalFeed/R5_ptpid_tofw_neg_%d_dis_cent%s.dat",protonid,centstring_P);
  finposcb_P.open(fnameinposcb_P);
  finnegcb_P.open(fnameinnegcb_P);
  for(int i=0; i<nbin-24; i++)
    {
      if(i<6)
	{
	  finposcb_P>>tmp>>tmp>>tmp;
	  finnegcb_P>>tmp>>tmp>>tmp;
	}
      else
	{
	  finposcb_P>>pT_poscb_P[i+24]>>yield_poscb_P[i+24]>>eyield_poscb_P[i+24];
	  finnegcb_P>>pT_negcb_P[i+24]>>yield_negcb_P[i+24]>>eyield_negcb_P[i+24];
	}
    }
  finposcb_P.close();
  finnegcb_P.close();

  float pTpos_proton_nq[nbin], epTpos_proton_nq[nbin];
  float pTneg_proton_nq[nbin], epTneg_proton_nq[nbin];
  float ratiopos_proton_nq[nbin], eratiopos_proton_nq[nbin], esysratiopos_proton_nq[nbin];
  float rationeg_proton_nq[nbin], erationeg_proton_nq[nbin], esysrationeg_proton_nq[nbin];
  sprintf(filename,"regular/rcp_%d_c%d%d.txt",protonid,centid1,centid2);
  ofstream ftxt(filename);
  sprintf(filename,"regular/rcp_%d_c%d%d.tex",protonid,centid1,centid2);
  ofstream ftex(filename);
  for(int i=0; i<nbin; i++)
    {
      if(yield_poscb_P[i]>0&&yield_negcb_P[i]>0)
	{
	  pTpos[i] = pT_poscb_C[i];
	  ratiopos[i] = yield_poscb_C[i]/yield_poscb_P[i];
	  eratiopos[i] = yield_poscb_C[i]/yield_poscb_P[i]
	    *sqrt((eyield_poscb_C[i]/yield_poscb_C[i])**2+(eyield_poscb_P[i]/yield_poscb_P[i])**2);
	  pTneg[i] = pT_negcb_C[i];
	  rationeg[i] = yield_negcb_C[i]/yield_negcb_P[i];
	  erationeg[i] = yield_negcb_C[i]/yield_negcb_P[i]
	    *sqrt((eyield_negcb_C[i]/yield_negcb_C[i])**2+(eyield_negcb_P[i]/yield_negcb_P[i])**2);
	}
      else
	{
	  pTpos[i]=0;
	  pTneg[i]=0;
	  ratiopos[i]=-9;
	  rationeg[i]=-9;
	  eratiopos[i]=0;
	  erationeg[i]=0;
	}
      ratiopos[i] /= normal;
      rationeg[i] /= normal;
      eratiopos[i] /= normal;
      erationeg[i] /= normal;
      esysratiopos[i] = ratiopos[i]*0.1; // 10% sys uncert
      esysrationeg[i] = rationeg[i]*0.1; // 10% sys uncert
      // nq scaling?
      pTpos_proton_nq[i] = pTpos[i]/3.0;
      epTpos_proton_nq[i] = 0;
      ratiopos_proton_nq[i] = ratiopos[i]/3.0;
      eratiopos_proton_nq[i] = eratiopos[i]/3.0;
      esysratiopos_proton_nq[i] = esysratiopos[i]/3.0;
      pTneg_proton_nq[i] = pTneg[i]/3.0;
      epTneg_proton_nq[i] = 0;
      rationeg_proton_nq[i] = rationeg[i]/3.0;
      erationeg_proton_nq[i] = erationeg[i]/3.0;
      esysrationeg_proton_nq[i] = esysrationeg[i]/3.0;
      if(i<5)
	{
	  ratiopos[i] = -9;
	  rationeg[i] = -9;
	  eratiopos[i] = 0;
	  erationeg[i] = 0;
	}
      ftxt<<pTpos[i]<<"\t"<<ratiopos[i]<<"\t"<<eratiopos[i]<<"\t"<<rationeg[i]<<"\t"<<erationeg[i]<<endl;
      ftex<<pTpos[i]<<" & "<<ratiopos[i]<<" & "<<eratiopos[i]<<" & "<<rationeg[i]<<" & "<<erationeg[i]<<" \\\\ "<<endl;
    }

  TGraphErrors *tge_posproton = new TGraphErrors(nbin,pTpos,ratiopos,ept,eratiopos);
  TGraphErrors *tge_negproton = new TGraphErrors(nbin,pTneg,rationeg,ept,erationeg);
  TGraphErrors *tge_sysposproton = new TGraphErrors(nbin,pTpos,ratiopos,ept,esysratiopos);
  TGraphErrors *tge_sysnegproton = new TGraphErrors(nbin,pTneg,rationeg,ept,esysrationeg);

  TGraphErrors *tge_posproton_nq = new TGraphErrors(nbin,pTpos_proton_nq,ratiopos,ept,eratiopos);
  TGraphErrors *tge_posproton_NQ = new TGraphErrors(nbin,pTpos_proton_nq,ratiopos_proton_nq,ept,eratiopos_proton_nq);
  TGraphErrors *tge_negproton_nq = new TGraphErrors(nbin,pTneg_proton_nq,rationeg,ept,erationeg);
  TGraphErrors *tge_negproton_NQ = new TGraphErrors(nbin,pTneg_proton_nq,rationeg_proton_nq,ept,erationeg_proton_nq);
  TGraphErrors *tge_sysposproton_nq = new TGraphErrors(nbin,pTpos_proton_nq,ratiopos,ept,esysratiopos);
  TGraphErrors *tge_sysposproton_NQ = new TGraphErrors(nbin,pTpos_proton_nq,ratiopos_proton_nq,ept,esysratiopos_proton_nq);
  TGraphErrors *tge_sysnegproton_nq = new TGraphErrors(nbin,pTneg_proton_nq,rationeg,ept,esysrationeg);
  TGraphErrors *tge_sysnegproton_NQ = new TGraphErrors(nbin,pTneg_proton_nq,rationeg_proton_nq,ept,esysrationeg_proton_nq);




  tge_pospion->SetMarkerColor(kRed);
  tge_negpion->SetMarkerColor(kBlue);
  tge_poskaon->SetMarkerColor(kRed);
  tge_negkaon->SetMarkerColor(kBlue);
  tge_posproton->SetMarkerColor(kRed);
  tge_negproton->SetMarkerColor(kBlue);

  tge_pospion->SetMarkerStyle(kFullCircle);
  tge_negpion->SetMarkerStyle(kFullCircle);
  tge_poskaon->SetMarkerStyle(kFullTriangleUp);
  tge_negkaon->SetMarkerStyle(kFullTriangleUp);
  tge_posproton->SetMarkerStyle(kFullSquare);
  tge_negproton->SetMarkerStyle(kFullSquare);

  tge_syspospion->SetMarkerColor(kRed);
  tge_syspospion->SetMarkerStyle(1);
  tge_syspospion->SetLineColor(kRed-10);
  tge_syspospion->SetLineWidth(15);
  tge_sysnegpion->SetMarkerColor(kBlue);
  tge_sysnegpion->SetMarkerStyle(1);
  tge_sysnegpion->SetLineColor(kBlue-10);
  tge_sysnegpion->SetLineWidth(15);

  tge_sysposkaon->SetMarkerColor(kRed);
  tge_sysposkaon->SetMarkerStyle(1);
  tge_sysposkaon->SetLineColor(kRed-10);
  tge_sysposkaon->SetLineWidth(15);
  tge_sysnegkaon->SetMarkerColor(kBlue);
  tge_sysnegkaon->SetMarkerStyle(1);
  tge_sysnegkaon->SetLineColor(kBlue-10);
  tge_sysnegkaon->SetLineWidth(15);

  tge_sysposproton->SetMarkerColor(kRed);
  tge_sysposproton->SetMarkerStyle(1);
  tge_sysposproton->SetLineColor(kRed-10);
  tge_sysposproton->SetLineWidth(15);
  tge_sysnegproton->SetMarkerColor(kBlue);
  tge_sysnegproton->SetMarkerStyle(1);
  tge_sysnegproton->SetLineColor(kBlue-10);
  tge_sysnegproton->SetLineWidth(15);


  // ----------------------- //
  // --- do the plotting --- //
  // ----------------------- //

  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tge_syspospion);
  tmg->Add(tge_sysnegpion);
  tmg->Add(tge_sysposkaon);
  tmg->Add(tge_sysnegkaon);
  tmg->Add(tge_sysposproton);
  tmg->Add(tge_sysnegproton);
  tmg->Add(tge_pospion);
  tmg->Add(tge_negpion);
  tmg->Add(tge_poskaon);
  tmg->Add(tge_negkaon);
  tmg->Add(tge_posproton);
  tmg->Add(tge_negproton);
  tmg->Draw("apz");
  line->Draw("same");
  tmg->SetMaximum(ymax);
  tmg->SetMinimum(ymin);
  tmg->GetXaxis()->SetLimits(xmin,xmax);
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetYaxis()->SetTitle("R_{CP}");
  tmg->GetXaxis()->CenterTitle();
  tmg->GetYaxis()->CenterTitle();

  //TPaveText *tpt_coll = new TPaveText(xmin+0.5,ymax+0.01,xmax-0.5,ymax+0.16);
  TPaveText *tpt_coll = new TPaveText(xmin+0.5,ymax*1.01,xmax-0.5,ymax*1.1);
  tpt_coll->SetFillColor(kWhite);
  tpt_coll->SetBorderSize(0);
  tpt_coll->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tpt_coll->Draw();


  TLegend *leg = new TLegend(0.68,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pospion,"#pi^{+}","p");
  leg->AddEntry(tge_negpion,"#pi^{-}","p");
  leg->AddEntry(tge_poskaon,"K^{+}","p");
  leg->AddEntry(tge_negkaon,"K^{-}","p");
  leg->AddEntry(tge_posproton,"p","p");
  leg->AddEntry(tge_negproton,"#bar{p}","p");
  leg->Draw();

  char figname[100];
  sprintf(figname,"regular/rcp_%d%d%d_c%d%d.gif",pionid,kaonid,protonid,centid1,centid2);
  c1->Print(figname);
  sprintf(figname,"regular/rcp_%d%d%d_c%d%d.eps",pionid,kaonid,protonid,centid1,centid2);
  c1->Print(figname);

  c1->Clear();
  delete c1;

}




