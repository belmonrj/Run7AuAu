void centbin()
{


  for(int ipid=0; ipid<10; ipid++)
    {
      doit(ipid,0);
      doit(ipid,1);
      doit(ipid,2);
      doitP(ipid);

      doit_NF(ipid,0);
      doit_NF(ipid,1);
      doit_NF(ipid,2);
      doitP_NF(ipid);
    }



}




void doitP(int pid=0)
{



  char sectorstring[10];
  sprintf(sectorstring,"tofw");

  // char centstring[10];
  char centstring1[10];
  char centstring2[10];
  char centstring3[10];
  char centstringP[10];

  sprintf(centstring1,"6070");
  sprintf(centstring2,"7080");
  sprintf(centstring3,"8092");
  sprintf(centstringP,"6092");




  // --- first centrality

  char fnameinposcb1[100];
  char fnameinnegcb1[100];
  sprintf(fnameinposcb1,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  ifstream finposcb1;
  ifstream finnegcb1;
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pT_poscb1[100], yield_poscb1[100], eyield_poscb1[100];
  float pT_negcb1[100], yield_negcb1[100], eyield_negcb1[100];
  for(int i=0; i<100; i++)
    {
      // poscb1
      finposcb1>>pT_poscb1[i]>>yield_poscb1[i]>>eyield_poscb1[i];
      // negcb1
      finnegcb1>>pT_negcb1[i]>>yield_negcb1[i]>>eyield_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();

  // --- second centrality
  char fnameinposcb2[100];
  char fnameinnegcb2[100];
  sprintf(fnameinposcb2,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  ifstream finposcb2;
  ifstream finnegcb2;
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pT_poscb2[100], yield_poscb2[100], eyield_poscb2[100];
  float pT_negcb2[100], yield_negcb2[100], eyield_negcb2[100];
  for(int i=0; i<100; i++)
    {
      // poscb2
      finposcb2>>pT_poscb2[i]>>yield_poscb2[i]>>eyield_poscb2[i];
      // negcb2
      finnegcb2>>pT_negcb2[i]>>yield_negcb2[i]>>eyield_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();

  // --- third centrality
  char fnameinposcb3[100];
  char fnameinnegcb3[100];
  sprintf(fnameinposcb3,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameinnegcb3,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  ifstream finposcb3;
  ifstream finnegcb3;
  finposcb3.open(fnameinposcb3);
  finnegcb3.open(fnameinnegcb3);
  float pT_poscb3[100], yield_poscb3[100], eyield_poscb3[100];
  float pT_negcb3[100], yield_negcb3[100], eyield_negcb3[100];
  for(int i=0; i<100; i++)
    {
      // poscb3
      finposcb3>>pT_poscb3[i]>>yield_poscb3[i]>>eyield_poscb3[i];
      // negcb3
      finnegcb3>>pT_negcb3[i]>>yield_negcb3[i]>>eyield_negcb3[i];
    }
  finposcb3.close();
  finnegcb3.close();



  // --- now input the rebinned data --- R2 --- //
  sprintf(fnameinposcb1,"Data/FinalFeed/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"Data/FinalFeed/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pTR2_poscb1[50], yieldR2_poscb1[50], eyieldR2_poscb1[50];
  float pTR2_negcb1[50], yieldR2_negcb1[50], eyieldR2_negcb1[50];
  for(int i=0; i<50; i++)
    {
      // poscb1
      finposcb1>>pTR2_poscb1[i]>>yieldR2_poscb1[i]>>eyieldR2_poscb1[i];
      // negcb1
      finnegcb1>>pTR2_negcb1[i]>>yieldR2_negcb1[i]>>eyieldR2_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb2,"Data/FinalFeed/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"Data/FinalFeed/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pTR2_poscb2[50], yieldR2_poscb2[50], eyieldR2_poscb2[50];
  float pTR2_negcb2[50], yieldR2_negcb2[50], eyieldR2_negcb2[50];
  for(int i=0; i<50; i++)
    {
      // poscb2
      finposcb2>>pTR2_poscb2[i]>>yieldR2_poscb2[i]>>eyieldR2_poscb2[i];
      // negcb2
      finnegcb2>>pTR2_negcb2[i]>>yieldR2_negcb2[i]>>eyieldR2_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb3,"Data/FinalFeed/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameinnegcb3,"Data/FinalFeed/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  finposcb3.open(fnameinposcb3);
  finnegcb3.open(fnameinnegcb3);
  float pTR2_poscb3[50], yieldR2_poscb3[50], eyieldR2_poscb3[50];
  float pTR2_negcb3[50], yieldR2_negcb3[50], eyieldR2_negcb3[50];
  for(int i=0; i<50; i++)
    {
      // poscb3
      finposcb3>>pTR2_poscb3[i]>>yieldR2_poscb3[i]>>eyieldR2_poscb3[i];
      // negcb3
      finnegcb3>>pTR2_negcb3[i]>>yieldR2_negcb3[i]>>eyieldR2_negcb3[i];
    }
  finposcb3.close();
  finnegcb3.close();




  // --- now input the rebinned data --- R5 --- //
  sprintf(fnameinposcb2,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pTR5_poscb2[20], yieldR5_poscb2[20], eyieldR5_poscb2[20];
  float pTR5_negcb2[20], yieldR5_negcb2[20], eyieldR5_negcb2[20];
  for(int i=0; i<20; i++)
    {
      // poscb2
      finposcb2>>pTR5_poscb2[i]>>yieldR5_poscb2[i]>>eyieldR5_poscb2[i];
      // negcb2
      finnegcb2>>pTR5_negcb2[i]>>yieldR5_negcb2[i]>>eyieldR5_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb1,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pTR5_poscb1[20], yieldR5_poscb1[20], eyieldR5_poscb1[20];
  float pTR5_negcb1[20], yieldR5_negcb1[20], eyieldR5_negcb1[20];
  for(int i=0; i<20; i++)
    {
      // poscb1
      finposcb1>>pTR5_poscb1[i]>>yieldR5_poscb1[i]>>eyieldR5_poscb1[i];
      // negcb1
      finnegcb1>>pTR5_negcb1[i]>>yieldR5_negcb1[i]>>eyieldR5_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb3,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameinnegcb3,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  finposcb3.open(fnameinposcb3);
  finnegcb3.open(fnameinnegcb3);
  float pTR5_poscb3[20], yieldR5_poscb3[20], eyieldR5_poscb3[20];
  float pTR5_negcb3[20], yieldR5_negcb3[20], eyieldR5_negcb3[20];
  for(int i=0; i<20; i++)
    {
      // poscb3
      finposcb3>>pTR5_poscb3[i]>>yieldR5_poscb3[i]>>eyieldR5_poscb3[i];
      // negcb3
      finnegcb3>>pTR5_negcb3[i]>>yieldR5_negcb3[i]>>eyieldR5_negcb3[i];
    }
  finposcb3.close();
  finnegcb3.close();

  // ------------------------- //
  // ------------------------- //
  // ------------------------- //

  // --- now do the output --- //

  // ------------------------- //
  // ------------------------- //
  // ------------------------- //

  char fnameoutposcb[100];
  char fnameoutnegcb[100];
  sprintf(fnameoutposcb,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  sprintf(fnameoutnegcb,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  ofstream foutposcb;
  ofstream foutnegcb;
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pT_poscb[100], yield_poscb[100], eyield_poscb[100];
  float pT_negcb[100], yield_negcb[100], eyield_negcb[100];
  for(int i=0; i<100; i++)
    {
      // poscb
      pT_poscb[i] = (pT_poscb1[i]+pT_poscb2[i]+pT_poscb3[i])/3.0;
      yield_poscb[i] = (yield_poscb1[i]+yield_poscb2[i]+yield_poscb3[i])/3.0;
      eyield_poscb[i] = sqrt(eyield_poscb1[i]**2+eyield_poscb2[i]**2+eyield_poscb3[i]**2)/3.0;
      foutposcb<<pT_poscb[i]<<"\t"<<yield_poscb[i]<<"\t"<<eyield_poscb[i]<<endl;
      // negcb
      pT_negcb[i] = (pT_negcb1[i]+pT_negcb2[i]+pT_negcb3[i])/3.0;
      yield_negcb[i] = (yield_negcb1[i]+yield_negcb2[i]+yield_negcb3[i])/3.0;
      eyield_negcb[i] = sqrt(eyield_negcb1[i]**2+eyield_negcb2[i]**2+eyield_negcb3[i]**2)/3.0;
      foutnegcb<<pT_negcb[i]<<"\t"<<yield_negcb[i]<<"\t"<<eyield_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();

  // --- now output the rebinned data --- R2 --- //
  sprintf(fnameoutposcb,"Data/FinalFeed/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  sprintf(fnameoutnegcb,"Data/FinalFeed/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pTR2_poscb[50], yieldR2_poscb[50], eyieldR2_poscb[50];
  float pTR2_negcb[50], yieldR2_negcb[50], eyieldR2_negcb[50];
  for(int i=0; i<50; i++)
    {
      // poscb
      pTR2_poscb[i] = (pTR2_poscb1[i]+pTR2_poscb2[i]+pTR2_poscb3[i])/3.0;
      yieldR2_poscb[i] = (yieldR2_poscb1[i]+yieldR2_poscb2[i]+yieldR2_poscb3[i])/3.0;
      eyieldR2_poscb[i] = sqrt(eyieldR2_poscb1[i]**2+eyieldR2_poscb2[i]**2+eyieldR2_poscb3[i]**2)/3.0;
      foutposcb<<pTR2_poscb[i]<<"\t"<<yieldR2_poscb[i]<<"\t"<<eyieldR2_poscb[i]<<endl;
      // negcb
      pTR2_negcb[i] = (pTR2_negcb1[i]+pTR2_negcb2[i]+pTR2_negcb3[i])/3.0;
      yieldR2_negcb[i] = (yieldR2_negcb1[i]+yieldR2_negcb2[i]+yieldR2_negcb3[i])/3.0;
      eyieldR2_negcb[i] = sqrt(eyieldR2_negcb1[i]**2+eyieldR2_negcb2[i]**2+eyieldR2_negcb3[i]**2)/3.0;
      foutnegcb<<pTR2_negcb[i]<<"\t"<<yieldR2_negcb[i]<<"\t"<<eyieldR2_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();

  // --- now output the rebinned data --- R5 --- //
  sprintf(fnameoutposcb,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  sprintf(fnameoutnegcb,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pTR5_poscb[20], yieldR5_poscb[20], eyieldR5_poscb[20];
  float pTR5_negcb[20], yieldR5_negcb[20], eyieldR5_negcb[20];
  for(int i=0; i<20; i++)
    {
      // poscb
      pTR5_poscb[i] = (pTR5_poscb1[i]+pTR5_poscb2[i]+pTR5_poscb3[i])/3.0;
      yieldR5_poscb[i] = (yieldR5_poscb1[i]+yieldR5_poscb2[i]+yieldR5_poscb3[i])/3.0;
      eyieldR5_poscb[i] = sqrt(eyieldR5_poscb1[i]**2+eyieldR5_poscb2[i]**2+eyieldR5_poscb3[i]**2)/3.0;
      foutposcb<<pTR5_poscb[i]<<"\t"<<yieldR5_poscb[i]<<"\t"<<eyieldR5_poscb[i]<<endl;
      // negcb
      pTR5_negcb[i] = (pTR5_negcb1[i]+pTR5_negcb2[i]+pTR5_negcb3[i])/3.0;
      yieldR5_negcb[i] = (yieldR5_negcb1[i]+yieldR5_negcb2[i]+yieldR5_negcb3[i])/3.0;
      eyieldR5_negcb[i] = sqrt(eyieldR5_negcb1[i]**2+eyieldR5_negcb2[i]**2+eyieldR5_negcb3[i]**2)/3.0;
      foutnegcb<<pTR5_negcb[i]<<"\t"<<yieldR5_negcb[i]<<"\t"<<eyieldR5_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();


} // doitP







void doit(int pid=0, int centid=0)
{



  char sectorstring[10];
  sprintf(sectorstring,"tofw");

  // char centstring[10];
  char centstring1[10];
  char centstring2[10];
  char centstring3[10];

  if(centid==0)
    {
      sprintf(centstring1,"2030");
      sprintf(centstring2,"3040");
      sprintf(centstring3,"2040");
    }

  if(centid==1)
    {
      sprintf(centstring1,"4050");
      sprintf(centstring2,"5060");
      sprintf(centstring3,"4060");
    }

  if(centid==2)
    {
      sprintf(centstring1,"6070");
      sprintf(centstring2,"7080");
      sprintf(centstring3,"6080");
    }




  // --- first centrality

  char fnameinposcb1[100];
  char fnameinnegcb1[100];
  sprintf(fnameinposcb1,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  ifstream finposcb1;
  ifstream finnegcb1;
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pT_poscb1[100], yield_poscb1[100], eyield_poscb1[100];
  float pT_negcb1[100], yield_negcb1[100], eyield_negcb1[100];
  for(int i=0; i<100; i++)
    {
      // poscb1
      finposcb1>>pT_poscb1[i]>>yield_poscb1[i]>>eyield_poscb1[i];
      // negcb1
      finnegcb1>>pT_negcb1[i]>>yield_negcb1[i]>>eyield_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();

  // --- second centrality
  char fnameinposcb2[100];
  char fnameinnegcb2[100];
  sprintf(fnameinposcb2,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  ifstream finposcb2;
  ifstream finnegcb2;
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pT_poscb2[100], yield_poscb2[100], eyield_poscb2[100];
  float pT_negcb2[100], yield_negcb2[100], eyield_negcb2[100];
  for(int i=0; i<100; i++)
    {
      // poscb2
      finposcb2>>pT_poscb2[i]>>yield_poscb2[i]>>eyield_poscb2[i];
      // negcb2
      finnegcb2>>pT_negcb2[i]>>yield_negcb2[i]>>eyield_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();



  // --- now input the rebinned data --- R2 --- //
  sprintf(fnameinposcb1,"Data/FinalFeed/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"Data/FinalFeed/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pTR2_poscb1[50], yieldR2_poscb1[50], eyieldR2_poscb1[50];
  float pTR2_negcb1[50], yieldR2_negcb1[50], eyieldR2_negcb1[50];
  for(int i=0; i<50; i++)
    {
      // poscb1
      finposcb1>>pTR2_poscb1[i]>>yieldR2_poscb1[i]>>eyieldR2_poscb1[i];
      // negcb1
      finnegcb1>>pTR2_negcb1[i]>>yieldR2_negcb1[i]>>eyieldR2_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb2,"Data/FinalFeed/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"Data/FinalFeed/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pTR2_poscb2[50], yieldR2_poscb2[50], eyieldR2_poscb2[50];
  float pTR2_negcb2[50], yieldR2_negcb2[50], eyieldR2_negcb2[50];
  for(int i=0; i<50; i++)
    {
      // poscb2
      finposcb2>>pTR2_poscb2[i]>>yieldR2_poscb2[i]>>eyieldR2_poscb2[i];
      // negcb2
      finnegcb2>>pTR2_negcb2[i]>>yieldR2_negcb2[i]>>eyieldR2_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();

  // --- now input the rebinned data --- R5 --- //
  sprintf(fnameinposcb1,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pTR5_poscb1[20], yieldR5_poscb1[20], eyieldR5_poscb1[20];
  float pTR5_negcb1[20], yieldR5_negcb1[20], eyieldR5_negcb1[20];
  for(int i=0; i<20; i++)
    {
      // poscb1
      finposcb1>>pTR5_poscb1[i]>>yieldR5_poscb1[i]>>eyieldR5_poscb1[i];
      // negcb1
      finnegcb1>>pTR5_negcb1[i]>>yieldR5_negcb1[i]>>eyieldR5_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb2,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pTR5_poscb2[20], yieldR5_poscb2[20], eyieldR5_poscb2[20];
  float pTR5_negcb2[20], yieldR5_negcb2[20], eyieldR5_negcb2[20];
  for(int i=0; i<20; i++)
    {
      // poscb2
      finposcb2>>pTR5_poscb2[i]>>yieldR5_poscb2[i]>>eyieldR5_poscb2[i];
      // negcb2
      finnegcb2>>pTR5_negcb2[i]>>yieldR5_negcb2[i]>>eyieldR5_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();

  // ------------------------- //
  // ------------------------- //
  // ------------------------- //

  // --- now do the output --- //

  // ------------------------- //
  // ------------------------- //
  // ------------------------- //

  char fnameoutposcb[100];
  char fnameoutnegcb[100];
  sprintf(fnameoutposcb,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameoutnegcb,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  ofstream foutposcb;
  ofstream foutnegcb;
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pT_poscb[100], yield_poscb[100], eyield_poscb[100];
  float pT_negcb[100], yield_negcb[100], eyield_negcb[100];
  for(int i=0; i<100; i++)
    {
      // poscb
      pT_poscb[i] = (pT_poscb1[i]+pT_poscb2[i])/2.0;
      yield_poscb[i] = (yield_poscb1[i]+yield_poscb2[i])/2.0;
      eyield_poscb[i] = sqrt(eyield_poscb1[i]**2+eyield_poscb2[i]**2)/2.0;
      foutposcb<<pT_poscb[i]<<"\t"<<yield_poscb[i]<<"\t"<<eyield_poscb[i]<<endl;
      // negcb
      pT_negcb[i] = (pT_negcb1[i]+pT_negcb2[i])/2.0;
      yield_negcb[i] = (yield_negcb1[i]+yield_negcb2[i])/2.0;
      eyield_negcb[i] = sqrt(eyield_negcb1[i]**2+eyield_negcb2[i]**2)/2.0;
      foutnegcb<<pT_negcb[i]<<"\t"<<yield_negcb[i]<<"\t"<<eyield_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();



  // --- now output the rebinned data --- R2 --- //
  sprintf(fnameoutposcb,"Data/FinalFeed/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameoutnegcb,"Data/FinalFeed/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pTR2_poscb[50], yieldR2_poscb[50], eyieldR2_poscb[50];
  float pTR2_negcb[50], yieldR2_negcb[50], eyieldR2_negcb[50];
  for(int i=0; i<50; i++)
    {
      // poscb
      pTR2_poscb[i] = (pTR2_poscb1[i]+pTR2_poscb2[i])/2.0;
      yieldR2_poscb[i] = (yieldR2_poscb1[i]+yieldR2_poscb2[i])/2.0;
      eyieldR2_poscb[i] = sqrt(eyieldR2_poscb1[i]**2+eyieldR2_poscb2[i]**2)/2.0;
      foutposcb<<pTR2_poscb[i]<<"\t"<<yieldR2_poscb[i]<<"\t"<<eyieldR2_poscb[i]<<endl;
      // negcb
      pTR2_negcb[i] = (pTR2_negcb1[i]+pTR2_negcb2[i])/2.0;
      yieldR2_negcb[i] = (yieldR2_negcb1[i]+yieldR2_negcb2[i])/2.0;
      eyieldR2_negcb[i] = sqrt(eyieldR2_negcb1[i]**2+eyieldR2_negcb2[i]**2)/2.0;
      foutnegcb<<pTR2_negcb[i]<<"\t"<<yieldR2_negcb[i]<<"\t"<<eyieldR2_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();



  // --- now output the rebinned data --- R5 --- //
  sprintf(fnameoutposcb,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameoutnegcb,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pTR5_poscb[20], yieldR5_poscb[20], eyieldR5_poscb[20];
  float pTR5_negcb[20], yieldR5_negcb[20], eyieldR5_negcb[20];
  for(int i=0; i<20; i++)
    {
      // poscb
      pTR5_poscb[i] = (pTR5_poscb1[i]+pTR5_poscb2[i])/2.0;
      yieldR5_poscb[i] = (yieldR5_poscb1[i]+yieldR5_poscb2[i])/2.0;
      eyieldR5_poscb[i] = sqrt(eyieldR5_poscb1[i]**2+eyieldR5_poscb2[i]**2)/2.0;
      foutposcb<<pTR5_poscb[i]<<"\t"<<yieldR5_poscb[i]<<"\t"<<eyieldR5_poscb[i]<<endl;
      // negcb
      pTR5_negcb[i] = (pTR5_negcb1[i]+pTR5_negcb2[i])/2.0;
      yieldR5_negcb[i] = (yieldR5_negcb1[i]+yieldR5_negcb2[i])/2.0;
      eyieldR5_negcb[i] = sqrt(eyieldR5_negcb1[i]**2+eyieldR5_negcb2[i]**2)/2.0;
      foutnegcb<<pTR5_negcb[i]<<"\t"<<yieldR5_negcb[i]<<"\t"<<eyieldR5_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();



}







void doitP_NF(int pid=0)
{



  char sectorstring[10];
  sprintf(sectorstring,"tofw");

  // char centstring[10];
  char centstring1[10];
  char centstring2[10];
  char centstring3[10];
  char centstringP[10];

  sprintf(centstring1,"6070");
  sprintf(centstring2,"7080");
  sprintf(centstring3,"8092");
  sprintf(centstringP,"6092");




  // --- first centrality

  char fnameinposcb1[100];
  char fnameinnegcb1[100];
  sprintf(fnameinposcb1,"Data/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"Data/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  ifstream finposcb1;
  ifstream finnegcb1;
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pT_poscb1[100], yield_poscb1[100], eyield_poscb1[100];
  float pT_negcb1[100], yield_negcb1[100], eyield_negcb1[100];
  for(int i=0; i<100; i++)
    {
      // poscb1
      finposcb1>>pT_poscb1[i]>>yield_poscb1[i]>>eyield_poscb1[i];
      // negcb1
      finnegcb1>>pT_negcb1[i]>>yield_negcb1[i]>>eyield_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();

  // --- second centrality
  char fnameinposcb2[100];
  char fnameinnegcb2[100];
  sprintf(fnameinposcb2,"Data/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"Data/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  ifstream finposcb2;
  ifstream finnegcb2;
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pT_poscb2[100], yield_poscb2[100], eyield_poscb2[100];
  float pT_negcb2[100], yield_negcb2[100], eyield_negcb2[100];
  for(int i=0; i<100; i++)
    {
      // poscb2
      finposcb2>>pT_poscb2[i]>>yield_poscb2[i]>>eyield_poscb2[i];
      // negcb2
      finnegcb2>>pT_negcb2[i]>>yield_negcb2[i]>>eyield_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();

  // --- third centrality
  char fnameinposcb3[100];
  char fnameinnegcb3[100];
  sprintf(fnameinposcb3,"Data/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameinnegcb3,"Data/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  ifstream finposcb3;
  ifstream finnegcb3;
  finposcb3.open(fnameinposcb3);
  finnegcb3.open(fnameinnegcb3);
  float pT_poscb3[100], yield_poscb3[100], eyield_poscb3[100];
  float pT_negcb3[100], yield_negcb3[100], eyield_negcb3[100];
  for(int i=0; i<100; i++)
    {
      // poscb3
      finposcb3>>pT_poscb3[i]>>yield_poscb3[i]>>eyield_poscb3[i];
      // negcb3
      finnegcb3>>pT_negcb3[i]>>yield_negcb3[i]>>eyield_negcb3[i];
    }
  finposcb3.close();
  finnegcb3.close();



  // --- now input the rebinned data --- R2 --- //
  sprintf(fnameinposcb1,"Data/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"Data/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pTR2_poscb1[50], yieldR2_poscb1[50], eyieldR2_poscb1[50];
  float pTR2_negcb1[50], yieldR2_negcb1[50], eyieldR2_negcb1[50];
  for(int i=0; i<50; i++)
    {
      // poscb1
      finposcb1>>pTR2_poscb1[i]>>yieldR2_poscb1[i]>>eyieldR2_poscb1[i];
      // negcb1
      finnegcb1>>pTR2_negcb1[i]>>yieldR2_negcb1[i]>>eyieldR2_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb2,"Data/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"Data/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pTR2_poscb2[50], yieldR2_poscb2[50], eyieldR2_poscb2[50];
  float pTR2_negcb2[50], yieldR2_negcb2[50], eyieldR2_negcb2[50];
  for(int i=0; i<50; i++)
    {
      // poscb2
      finposcb2>>pTR2_poscb2[i]>>yieldR2_poscb2[i]>>eyieldR2_poscb2[i];
      // negcb2
      finnegcb2>>pTR2_negcb2[i]>>yieldR2_negcb2[i]>>eyieldR2_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb3,"Data/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameinnegcb3,"Data/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  finposcb3.open(fnameinposcb3);
  finnegcb3.open(fnameinnegcb3);
  float pTR2_poscb3[50], yieldR2_poscb3[50], eyieldR2_poscb3[50];
  float pTR2_negcb3[50], yieldR2_negcb3[50], eyieldR2_negcb3[50];
  for(int i=0; i<50; i++)
    {
      // poscb3
      finposcb3>>pTR2_poscb3[i]>>yieldR2_poscb3[i]>>eyieldR2_poscb3[i];
      // negcb3
      finnegcb3>>pTR2_negcb3[i]>>yieldR2_negcb3[i]>>eyieldR2_negcb3[i];
    }
  finposcb3.close();
  finnegcb3.close();




  // --- now input the rebinned data --- R5 --- //
  sprintf(fnameinposcb2,"Data/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"Data/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pTR5_poscb2[20], yieldR5_poscb2[20], eyieldR5_poscb2[20];
  float pTR5_negcb2[20], yieldR5_negcb2[20], eyieldR5_negcb2[20];
  for(int i=0; i<20; i++)
    {
      // poscb2
      finposcb2>>pTR5_poscb2[i]>>yieldR5_poscb2[i]>>eyieldR5_poscb2[i];
      // negcb2
      finnegcb2>>pTR5_negcb2[i]>>yieldR5_negcb2[i]>>eyieldR5_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb1,"Data/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"Data/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pTR5_poscb1[20], yieldR5_poscb1[20], eyieldR5_poscb1[20];
  float pTR5_negcb1[20], yieldR5_negcb1[20], eyieldR5_negcb1[20];
  for(int i=0; i<20; i++)
    {
      // poscb1
      finposcb1>>pTR5_poscb1[i]>>yieldR5_poscb1[i]>>eyieldR5_poscb1[i];
      // negcb1
      finnegcb1>>pTR5_negcb1[i]>>yieldR5_negcb1[i]>>eyieldR5_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb3,"Data/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameinnegcb3,"Data/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  finposcb3.open(fnameinposcb3);
  finnegcb3.open(fnameinnegcb3);
  float pTR5_poscb3[20], yieldR5_poscb3[20], eyieldR5_poscb3[20];
  float pTR5_negcb3[20], yieldR5_negcb3[20], eyieldR5_negcb3[20];
  for(int i=0; i<20; i++)
    {
      // poscb3
      finposcb3>>pTR5_poscb3[i]>>yieldR5_poscb3[i]>>eyieldR5_poscb3[i];
      // negcb3
      finnegcb3>>pTR5_negcb3[i]>>yieldR5_negcb3[i]>>eyieldR5_negcb3[i];
    }
  finposcb3.close();
  finnegcb3.close();

  // ------------------------- //
  // ------------------------- //
  // ------------------------- //

  // --- now do the output --- //

  // ------------------------- //
  // ------------------------- //
  // ------------------------- //

  char fnameoutposcb[100];
  char fnameoutnegcb[100];
  sprintf(fnameoutposcb,"Data/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  sprintf(fnameoutnegcb,"Data/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  ofstream foutposcb;
  ofstream foutnegcb;
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pT_poscb[100], yield_poscb[100], eyield_poscb[100];
  float pT_negcb[100], yield_negcb[100], eyield_negcb[100];
  for(int i=0; i<100; i++)
    {
      // poscb
      pT_poscb[i] = (pT_poscb1[i]+pT_poscb2[i]+pT_poscb3[i])/3.0;
      yield_poscb[i] = (yield_poscb1[i]+yield_poscb2[i]+yield_poscb3[i])/3.0;
      eyield_poscb[i] = sqrt(eyield_poscb1[i]**2+eyield_poscb2[i]**2+eyield_poscb3[i]**2)/3.0;
      foutposcb<<pT_poscb[i]<<"\t"<<yield_poscb[i]<<"\t"<<eyield_poscb[i]<<endl;
      // negcb
      pT_negcb[i] = (pT_negcb1[i]+pT_negcb2[i]+pT_negcb3[i])/3.0;
      yield_negcb[i] = (yield_negcb1[i]+yield_negcb2[i]+yield_negcb3[i])/3.0;
      eyield_negcb[i] = sqrt(eyield_negcb1[i]**2+eyield_negcb2[i]**2+eyield_negcb3[i]**2)/3.0;
      foutnegcb<<pT_negcb[i]<<"\t"<<yield_negcb[i]<<"\t"<<eyield_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();

  // --- now output the rebinned data --- R2 --- //
  sprintf(fnameoutposcb,"Data/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  sprintf(fnameoutnegcb,"Data/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pTR2_poscb[50], yieldR2_poscb[50], eyieldR2_poscb[50];
  float pTR2_negcb[50], yieldR2_negcb[50], eyieldR2_negcb[50];
  for(int i=0; i<50; i++)
    {
      // poscb
      pTR2_poscb[i] = (pTR2_poscb1[i]+pTR2_poscb2[i]+pTR2_poscb3[i])/3.0;
      yieldR2_poscb[i] = (yieldR2_poscb1[i]+yieldR2_poscb2[i]+yieldR2_poscb3[i])/3.0;
      eyieldR2_poscb[i] = sqrt(eyieldR2_poscb1[i]**2+eyieldR2_poscb2[i]**2+eyieldR2_poscb3[i]**2)/3.0;
      foutposcb<<pTR2_poscb[i]<<"\t"<<yieldR2_poscb[i]<<"\t"<<eyieldR2_poscb[i]<<endl;
      // negcb
      pTR2_negcb[i] = (pTR2_negcb1[i]+pTR2_negcb2[i]+pTR2_negcb3[i])/3.0;
      yieldR2_negcb[i] = (yieldR2_negcb1[i]+yieldR2_negcb2[i]+yieldR2_negcb3[i])/3.0;
      eyieldR2_negcb[i] = sqrt(eyieldR2_negcb1[i]**2+eyieldR2_negcb2[i]**2+eyieldR2_negcb3[i]**2)/3.0;
      foutnegcb<<pTR2_negcb[i]<<"\t"<<yieldR2_negcb[i]<<"\t"<<eyieldR2_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();

  // --- now output the rebinned data --- R5 --- //
  sprintf(fnameoutposcb,"Data/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  sprintf(fnameoutnegcb,"Data/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstringP);
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pTR5_poscb[20], yieldR5_poscb[20], eyieldR5_poscb[20];
  float pTR5_negcb[20], yieldR5_negcb[20], eyieldR5_negcb[20];
  for(int i=0; i<20; i++)
    {
      // poscb
      pTR5_poscb[i] = (pTR5_poscb1[i]+pTR5_poscb2[i]+pTR5_poscb3[i])/3.0;
      yieldR5_poscb[i] = (yieldR5_poscb1[i]+yieldR5_poscb2[i]+yieldR5_poscb3[i])/3.0;
      eyieldR5_poscb[i] = sqrt(eyieldR5_poscb1[i]**2+eyieldR5_poscb2[i]**2+eyieldR5_poscb3[i]**2)/3.0;
      foutposcb<<pTR5_poscb[i]<<"\t"<<yieldR5_poscb[i]<<"\t"<<eyieldR5_poscb[i]<<endl;
      // negcb
      pTR5_negcb[i] = (pTR5_negcb1[i]+pTR5_negcb2[i]+pTR5_negcb3[i])/3.0;
      yieldR5_negcb[i] = (yieldR5_negcb1[i]+yieldR5_negcb2[i]+yieldR5_negcb3[i])/3.0;
      eyieldR5_negcb[i] = sqrt(eyieldR5_negcb1[i]**2+eyieldR5_negcb2[i]**2+eyieldR5_negcb3[i]**2)/3.0;
      foutnegcb<<pTR5_negcb[i]<<"\t"<<yieldR5_negcb[i]<<"\t"<<eyieldR5_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();


} // doitP







void doit_NF(int pid=0, int centid=0)
{



  char sectorstring[10];
  sprintf(sectorstring,"tofw");

  // char centstring[10];
  char centstring1[10];
  char centstring2[10];
  char centstring3[10];

  if(centid==0)
    {
      sprintf(centstring1,"2030");
      sprintf(centstring2,"3040");
      sprintf(centstring3,"2040");
    }

  if(centid==1)
    {
      sprintf(centstring1,"4050");
      sprintf(centstring2,"5060");
      sprintf(centstring3,"4060");
    }

  if(centid==2)
    {
      sprintf(centstring1,"6070");
      sprintf(centstring2,"7080");
      sprintf(centstring3,"6080");
    }




  // --- first centrality

  char fnameinposcb1[100];
  char fnameinnegcb1[100];
  sprintf(fnameinposcb1,"Data/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"Data/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  ifstream finposcb1;
  ifstream finnegcb1;
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pT_poscb1[100], yield_poscb1[100], eyield_poscb1[100];
  float pT_negcb1[100], yield_negcb1[100], eyield_negcb1[100];
  for(int i=0; i<100; i++)
    {
      // poscb1
      finposcb1>>pT_poscb1[i]>>yield_poscb1[i]>>eyield_poscb1[i];
      // negcb1
      finnegcb1>>pT_negcb1[i]>>yield_negcb1[i]>>eyield_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();

  // --- second centrality
  char fnameinposcb2[100];
  char fnameinnegcb2[100];
  sprintf(fnameinposcb2,"Data/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"Data/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  ifstream finposcb2;
  ifstream finnegcb2;
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pT_poscb2[100], yield_poscb2[100], eyield_poscb2[100];
  float pT_negcb2[100], yield_negcb2[100], eyield_negcb2[100];
  for(int i=0; i<100; i++)
    {
      // poscb2
      finposcb2>>pT_poscb2[i]>>yield_poscb2[i]>>eyield_poscb2[i];
      // negcb2
      finnegcb2>>pT_negcb2[i]>>yield_negcb2[i]>>eyield_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();



  // --- now input the rebinned data --- R2 --- //
  sprintf(fnameinposcb1,"Data/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"Data/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pTR2_poscb1[50], yieldR2_poscb1[50], eyieldR2_poscb1[50];
  float pTR2_negcb1[50], yieldR2_negcb1[50], eyieldR2_negcb1[50];
  for(int i=0; i<50; i++)
    {
      // poscb1
      finposcb1>>pTR2_poscb1[i]>>yieldR2_poscb1[i]>>eyieldR2_poscb1[i];
      // negcb1
      finnegcb1>>pTR2_negcb1[i]>>yieldR2_negcb1[i]>>eyieldR2_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb2,"Data/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"Data/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pTR2_poscb2[50], yieldR2_poscb2[50], eyieldR2_poscb2[50];
  float pTR2_negcb2[50], yieldR2_negcb2[50], eyieldR2_negcb2[50];
  for(int i=0; i<50; i++)
    {
      // poscb2
      finposcb2>>pTR2_poscb2[i]>>yieldR2_poscb2[i]>>eyieldR2_poscb2[i];
      // negcb2
      finnegcb2>>pTR2_negcb2[i]>>yieldR2_negcb2[i]>>eyieldR2_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();

  // --- now input the rebinned data --- R5 --- //
  sprintf(fnameinposcb1,"Data/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  sprintf(fnameinnegcb1,"Data/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring1);
  finposcb1.open(fnameinposcb1);
  finnegcb1.open(fnameinnegcb1);
  float pTR5_poscb1[20], yieldR5_poscb1[20], eyieldR5_poscb1[20];
  float pTR5_negcb1[20], yieldR5_negcb1[20], eyieldR5_negcb1[20];
  for(int i=0; i<20; i++)
    {
      // poscb1
      finposcb1>>pTR5_poscb1[i]>>yieldR5_poscb1[i]>>eyieldR5_poscb1[i];
      // negcb1
      finnegcb1>>pTR5_negcb1[i]>>yieldR5_negcb1[i]>>eyieldR5_negcb1[i];
    }
  finposcb1.close();
  finnegcb1.close();

  // --- now input the rebinned data
  sprintf(fnameinposcb2,"Data/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  sprintf(fnameinnegcb2,"Data/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring2);
  finposcb2.open(fnameinposcb2);
  finnegcb2.open(fnameinnegcb2);
  float pTR5_poscb2[20], yieldR5_poscb2[20], eyieldR5_poscb2[20];
  float pTR5_negcb2[20], yieldR5_negcb2[20], eyieldR5_negcb2[20];
  for(int i=0; i<20; i++)
    {
      // poscb2
      finposcb2>>pTR5_poscb2[i]>>yieldR5_poscb2[i]>>eyieldR5_poscb2[i];
      // negcb2
      finnegcb2>>pTR5_negcb2[i]>>yieldR5_negcb2[i]>>eyieldR5_negcb2[i];
    }
  finposcb2.close();
  finnegcb2.close();

  // ------------------------- //
  // ------------------------- //
  // ------------------------- //

  // --- now do the output --- //

  // ------------------------- //
  // ------------------------- //
  // ------------------------- //

  char fnameoutposcb[100];
  char fnameoutnegcb[100];
  sprintf(fnameoutposcb,"Data/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameoutnegcb,"Data/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  ofstream foutposcb;
  ofstream foutnegcb;
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pT_poscb[100], yield_poscb[100], eyield_poscb[100];
  float pT_negcb[100], yield_negcb[100], eyield_negcb[100];
  for(int i=0; i<100; i++)
    {
      // poscb
      pT_poscb[i] = (pT_poscb1[i]+pT_poscb2[i])/2.0;
      yield_poscb[i] = (yield_poscb1[i]+yield_poscb2[i])/2.0;
      eyield_poscb[i] = sqrt(eyield_poscb1[i]**2+eyield_poscb2[i]**2)/2.0;
      foutposcb<<pT_poscb[i]<<"\t"<<yield_poscb[i]<<"\t"<<eyield_poscb[i]<<endl;
      // negcb
      pT_negcb[i] = (pT_negcb1[i]+pT_negcb2[i])/2.0;
      yield_negcb[i] = (yield_negcb1[i]+yield_negcb2[i])/2.0;
      eyield_negcb[i] = sqrt(eyield_negcb1[i]**2+eyield_negcb2[i]**2)/2.0;
      foutnegcb<<pT_negcb[i]<<"\t"<<yield_negcb[i]<<"\t"<<eyield_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();



  // --- now output the rebinned data --- R2 --- //
  sprintf(fnameoutposcb,"Data/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameoutnegcb,"Data/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pTR2_poscb[50], yieldR2_poscb[50], eyieldR2_poscb[50];
  float pTR2_negcb[50], yieldR2_negcb[50], eyieldR2_negcb[50];
  for(int i=0; i<50; i++)
    {
      // poscb
      pTR2_poscb[i] = (pTR2_poscb1[i]+pTR2_poscb2[i])/2.0;
      yieldR2_poscb[i] = (yieldR2_poscb1[i]+yieldR2_poscb2[i])/2.0;
      eyieldR2_poscb[i] = sqrt(eyieldR2_poscb1[i]**2+eyieldR2_poscb2[i]**2)/2.0;
      foutposcb<<pTR2_poscb[i]<<"\t"<<yieldR2_poscb[i]<<"\t"<<eyieldR2_poscb[i]<<endl;
      // negcb
      pTR2_negcb[i] = (pTR2_negcb1[i]+pTR2_negcb2[i])/2.0;
      yieldR2_negcb[i] = (yieldR2_negcb1[i]+yieldR2_negcb2[i])/2.0;
      eyieldR2_negcb[i] = sqrt(eyieldR2_negcb1[i]**2+eyieldR2_negcb2[i]**2)/2.0;
      foutnegcb<<pTR2_negcb[i]<<"\t"<<yieldR2_negcb[i]<<"\t"<<eyieldR2_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();



  // --- now output the rebinned data --- R5 --- //
  sprintf(fnameoutposcb,"Data/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  sprintf(fnameoutnegcb,"Data/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring3);
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);
  float pTR5_poscb[20], yieldR5_poscb[20], eyieldR5_poscb[20];
  float pTR5_negcb[20], yieldR5_negcb[20], eyieldR5_negcb[20];
  for(int i=0; i<20; i++)
    {
      // poscb
      pTR5_poscb[i] = (pTR5_poscb1[i]+pTR5_poscb2[i])/2.0;
      yieldR5_poscb[i] = (yieldR5_poscb1[i]+yieldR5_poscb2[i])/2.0;
      eyieldR5_poscb[i] = sqrt(eyieldR5_poscb1[i]**2+eyieldR5_poscb2[i]**2)/2.0;
      foutposcb<<pTR5_poscb[i]<<"\t"<<yieldR5_poscb[i]<<"\t"<<eyieldR5_poscb[i]<<endl;
      // negcb
      pTR5_negcb[i] = (pTR5_negcb1[i]+pTR5_negcb2[i])/2.0;
      yieldR5_negcb[i] = (yieldR5_negcb1[i]+yieldR5_negcb2[i])/2.0;
      eyieldR5_negcb[i] = sqrt(eyieldR5_negcb1[i]**2+eyieldR5_negcb2[i]**2)/2.0;
      foutnegcb<<pTR5_negcb[i]<<"\t"<<yieldR5_negcb[i]<<"\t"<<eyieldR5_negcb[i]<<endl;
    }
  foutposcb.close();
  foutnegcb.close();



}




