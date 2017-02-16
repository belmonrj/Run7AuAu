void feed()
{

  cout<<"hello!  now doing feeddown correction!"<<endl;

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

  // char sectorstring[10];
  // sprintf(sectorstring,"tofw"); // "default"
  // if(sector==0) sprintf(sectorstring,"tofw");
  // if(sector==1) sprintf(sectorstring,"tofw_w1");
  // if(sector==2) sprintf(sectorstring,"tofw_w2");

  // char centstring[10];
  // sprintf(centstring,"0088"); // "default"
  // if(centid==0) sprintf(centstring,"0020");
  // if(centid==1) sprintf(centstring,"2040");
  // if(centid==2) sprintf(centstring,"4060");
  // if(centid==3) sprintf(centstring,"6088");
  // if(centid==4) sprintf(centstring,"0088");






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

  sprintf(fnameinpospm,"Data/R2_ptpid_%s_pos_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegpm,"Data/R2_ptpid_%s_neg_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameinposmp,"Data/R2_ptpid_%s_pos_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegmp,"Data/R2_ptpid_%s_neg_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameinposcb,"Data/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameinnegcb,"Data/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

  finpospm.open(fnameinpospm);
  finnegpm.open(fnameinnegpm);
  finposmp.open(fnameinposmp);
  finnegmp.open(fnameinnegmp);
  finposcb.open(fnameinposcb);
  finnegcb.open(fnameinnegcb);

  float pTR2_pospm[100], yieldR2_pospm[100], eyieldR2_pospm[100];
  float pTR2_negpm[100], yieldR2_negpm[100], eyieldR2_negpm[100];
  float pTR2_posmp[100], yieldR2_posmp[100], eyieldR2_posmp[100];
  float pTR2_negmp[100], yieldR2_negmp[100], eyieldR2_negmp[100];
  float pTR2_poscb[100], yieldR2_poscb[100], eyieldR2_poscb[100];
  float pTR2_negcb[100], yieldR2_negcb[100], eyieldR2_negcb[100];

  for(int i=0; i<100; i++)
    {
      // pospm
      finpospm>>pTR2_pospm[i]>>yieldR2_pospm[i]>>eyieldR2_pospm[i];
      // negpm
      finnegpm>>pTR2_negpm[i]>>yieldR2_negpm[i]>>eyieldR2_negpm[i];
      // posmp
      finposmp>>pTR2_posmp[i]>>yieldR2_posmp[i]>>eyieldR2_posmp[i];
      // negmp
      finnegmp>>pTR2_negmp[i]>>yieldR2_negmp[i]>>eyieldR2_negmp[i];
      // poscb
      finposcb>>pTR2_poscb[i]>>yieldR2_poscb[i]>>eyieldR2_poscb[i];
      // negcb
      finnegcb>>pTR2_negcb[i]>>yieldR2_negcb[i]>>eyieldR2_negcb[i];
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

  float pTR5_pospm[100], yieldR5_pospm[100], eyieldR5_pospm[100];
  float pTR5_negpm[100], yieldR5_negpm[100], eyieldR5_negpm[100];
  float pTR5_posmp[100], yieldR5_posmp[100], eyieldR5_posmp[100];
  float pTR5_negmp[100], yieldR5_negmp[100], eyieldR5_negmp[100];
  float pTR5_poscb[100], yieldR5_poscb[100], eyieldR5_poscb[100];
  float pTR5_negcb[100], yieldR5_negcb[100], eyieldR5_negcb[100];

  for(int i=0; i<100; i++)
    {
      // pospm
      finpospm>>pTR5_pospm[i]>>yieldR5_pospm[i]>>eyieldR5_pospm[i];
      // negpm
      finnegpm>>pTR5_negpm[i]>>yieldR5_negpm[i]>>eyieldR5_negpm[i];
      // posmp
      finposmp>>pTR5_posmp[i]>>yieldR5_posmp[i]>>eyieldR5_posmp[i];
      // negmp
      finnegmp>>pTR5_negmp[i]>>yieldR5_negmp[i]>>eyieldR5_negmp[i];
      // poscb
      finposcb>>pTR5_poscb[i]>>yieldR5_poscb[i]>>eyieldR5_poscb[i];
      // negcb
      finnegcb>>pTR5_negcb[i]>>yieldR5_negcb[i]>>eyieldR5_negcb[i];
    }

  finpospm.close();
  finnegpm.close();
  finposmp.close();
  finnegmp.close();
  finposcb.close();
  finnegcb.close();

  // ---

  // --- now do feeddown correction --- //

  // parameters from fit
  TF1 *funfeedpr = new TF1("funfeedpr","expo(0)+pol0(2)",0.0,10.0);
  // funfeedpr->SetParameter(0,-0.84);
  // funfeedpr->SetParameter(1,-0.74);
  // funfeedpr->SetParameter(2, 0.08);
  TF1 *funfeedpb = new TF1("funfeedpb","expo(0)+pol0(2)",0.0,10.0);
  // funfeedpb->SetParameter(0,-0.67);
  // funfeedpb->SetParameter(1,-0.77);
  // funfeedpb->SetParameter(2, 0.09);

  funfeedpr->SetParameter(0,-0.68);//green
  funfeedpr->SetParameter(1,-0.75);
  funfeedpr->SetParameter(2, 0.07);
  // funfeedpb->SetParameter(0,-0.50);//green
  // funfeedpb->SetParameter(1,-0.82);
  // funfeedpb->SetParameter(2, 0.09);
  funfeedpb->SetParameter(0,-0.60); // blue
  funfeedpb->SetParameter(1,-0.85);
  funfeedpb->SetParameter(2, 0.08);

  // // parameters by eye (very similar)
  // TF1 *funfeedpr = new TF1("funfeedpr","expo(0)+pol0(2)",0.0,10.0);
  // funfeedpr->SetParameter(0,-0.77);
  // funfeedpr->SetParameter(1,-0.77);
  // funfeedpr->SetParameter(2, 0.08);
  // TF1 *funfeedpb = new TF1("funfeedpb","expo(0)+pol0(2)",0.0,10.0);
  // funfeedpb->SetParameter(0,-0.65);
  // funfeedpb->SetParameter(1,-0.77);
  // funfeedpb->SetParameter(2, 0.10);



  /* holy fucking shit
  //if(pid==4||pid==5)
  if(pid>=6)
    {
      for(int i=0; i<100; i++)
	{
	  //pospm
	  yield_pospm[i] *= 1.0 - funfeedpr->Eval(pT_pospm[i]);
	  eyield_pospm[i] *= 1.0 - funfeedpr->Eval(pT_pospm[i]);
	  //negpm
	  yield_negpm[i] *= 1.0 - funfeedpb->Eval(pT_negpm[i]);
	  eyield_negpm[i] *= 1.0 - funfeedpb->Eval(pT_negpm[i]);
	  //posmp
	  yield_posmp[i] *= 1.0 - funfeedpr->Eval(pT_posmp[i]);
	  eyield_posmp[i] *= 1.0 - funfeedpr->Eval(pT_posmp[i]);
	  //negmp
	  yield_negmp[i] *= 1.0 - funfeedpb->Eval(pT_negmp[i]);
	  eyield_negmp[i] *= 1.0 - funfeedpb->Eval(pT_negmp[i]);
	  //poscb
	  yield_poscb[i] *= 1.0 - funfeedpr->Eval(pT_poscb[i]);
	  eyield_poscb[i] *= 1.0 - funfeedpr->Eval(pT_poscb[i]);
	  //negcb
	  yield_negcb[i] *= 1.0 - funfeedpb->Eval(pT_negcb[i]);
	  eyield_negcb[i] *= 1.0 - funfeedpb->Eval(pT_negcb[i]);
	  // ---------------- //
	  // --- rebinned --- //
	  // ---------------- //
	  //pospm
	  yieldR2_pospm[i] *= 1.0 - funfeedpr->Eval(pTR2_pospm[i]);
	  eyieldR2_pospm[i] *= 1.0 - funfeedpr->Eval(pTR2_pospm[i]);
	  //negpm
	  yieldR2_negpm[i] *= 1.0 - funfeedpb->Eval(pTR2_negpm[i]);
	  eyieldR2_negpm[i] *= 1.0 - funfeedpb->Eval(pTR2_negpm[i]);
	  //posmp
	  yieldR2_posmp[i] *= 1.0 - funfeedpr->Eval(pTR2_posmp[i]);
	  eyieldR2_posmp[i] *= 1.0 - funfeedpr->Eval(pTR2_posmp[i]);
	  //negmp
	  yieldR2_negmp[i] *= 1.0 - funfeedpb->Eval(pTR2_negmp[i]);
	  eyieldR2_negmp[i] *= 1.0 - funfeedpb->Eval(pTR2_negmp[i]);
	  //poscb
	  yieldR2_poscb[i] *= 1.0 - funfeedpr->Eval(pTR2_poscb[i]);
	  eyieldR2_poscb[i] *= 1.0 - funfeedpr->Eval(pTR2_poscb[i]);
	  //negcb
	  yieldR2_negcb[i] *= 1.0 - funfeedpb->Eval(pTR2_negcb[i]);
	  eyieldR2_negcb[i] *= 1.0 - funfeedpb->Eval(pTR2_negcb[i]);
	  // ---------------- //
	  // --- rebinned --- //
	  // ---------------- //
	  //pospm
	  yieldR5_pospm[i] *= 1.0 - funfeedpr->Eval(pTR5_pospm[i]);
	  eyieldR5_pospm[i] *= 1.0 - funfeedpr->Eval(pTR5_pospm[i]);
	  //negpm
	  yieldR5_negpm[i] *= 1.0 - funfeedpb->Eval(pTR5_negpm[i]);
	  eyieldR5_negpm[i] *= 1.0 - funfeedpb->Eval(pTR5_negpm[i]);
	  //posmp
	  yieldR5_posmp[i] *= 1.0 - funfeedpr->Eval(pTR5_posmp[i]);
	  eyieldR5_posmp[i] *= 1.0 - funfeedpr->Eval(pTR5_posmp[i]);
	  //negmp
	  yieldR5_negmp[i] *= 1.0 - funfeedpb->Eval(pTR5_negmp[i]);
	  eyieldR5_negmp[i] *= 1.0 - funfeedpb->Eval(pTR5_negmp[i]);
	  //poscb
	  yieldR5_poscb[i] *= 1.0 - funfeedpr->Eval(pTR5_poscb[i]);
	  eyieldR5_poscb[i] *= 1.0 - funfeedpr->Eval(pTR5_poscb[i]);
	  //negcb
	  yieldR5_negcb[i] *= 1.0 - funfeedpb->Eval(pTR5_negcb[i]);
	  eyieldR5_negcb[i] *= 1.0 - funfeedpb->Eval(pTR5_negcb[i]);
	}
    }
  */ // matches holy fucking shit

  // COME BACK HERE FOR SOME CRAZY ASS MOTHERFUCKING SHIT
  float pbarK = 1.08;
  if(pid>=6)
    {
      for(int i=0; i<100; i++)
	{
	  //pospm
	  yield_pospm[i] *= 1.0 - funfeedpr->Eval(pT_pospm[i]);
	  eyield_pospm[i] *= 1.0 - funfeedpr->Eval(pT_pospm[i]);
	  //negpm
	  yield_negpm[i] *= 1.0 - pbarK*funfeedpr->Eval(pT_negpm[i]);
	  eyield_negpm[i] *= 1.0 - pbarK*funfeedpr->Eval(pT_negpm[i]);
	  //posmp
	  yield_posmp[i] *= 1.0 - funfeedpr->Eval(pT_posmp[i]);
	  eyield_posmp[i] *= 1.0 - funfeedpr->Eval(pT_posmp[i]);
	  //negmp
	  yield_negmp[i] *= 1.0 - pbarK*funfeedpr->Eval(pT_negmp[i]);
	  eyield_negmp[i] *= 1.0 - pbarK*funfeedpr->Eval(pT_negmp[i]);
	  //poscb
	  yield_poscb[i] *= 1.0 - funfeedpr->Eval(pT_poscb[i]);
	  eyield_poscb[i] *= 1.0 - funfeedpr->Eval(pT_poscb[i]);
	  //negcb
	  yield_negcb[i] *= 1.0 - pbarK*funfeedpr->Eval(pT_negcb[i]);
	  eyield_negcb[i] *= 1.0 - pbarK*funfeedpr->Eval(pT_negcb[i]);
	  // ---------------- //
	  // --- rebinned --- //
	  // ---------------- //
	  //pospm
	  yieldR2_pospm[i] *= 1.0 - funfeedpr->Eval(pTR2_pospm[i]);
	  eyieldR2_pospm[i] *= 1.0 - funfeedpr->Eval(pTR2_pospm[i]);
	  //negpm
	  yieldR2_negpm[i] *= 1.0 - pbarK*funfeedpr->Eval(pTR2_negpm[i]);
	  eyieldR2_negpm[i] *= 1.0 - pbarK*funfeedpr->Eval(pTR2_negpm[i]);
	  //posmp
	  yieldR2_posmp[i] *= 1.0 - funfeedpr->Eval(pTR2_posmp[i]);
	  eyieldR2_posmp[i] *= 1.0 - funfeedpr->Eval(pTR2_posmp[i]);
	  //negmp
	  yieldR2_negmp[i] *= 1.0 - pbarK*funfeedpr->Eval(pTR2_negmp[i]);
	  eyieldR2_negmp[i] *= 1.0 - pbarK*funfeedpr->Eval(pTR2_negmp[i]);
	  //poscb
	  yieldR2_poscb[i] *= 1.0 - funfeedpr->Eval(pTR2_poscb[i]);
	  eyieldR2_poscb[i] *= 1.0 - funfeedpr->Eval(pTR2_poscb[i]);
	  //negcb
	  yieldR2_negcb[i] *= 1.0 - pbarK*funfeedpr->Eval(pTR2_negcb[i]);
	  eyieldR2_negcb[i] *= 1.0 - pbarK*funfeedpr->Eval(pTR2_negcb[i]);
	  // ---------------- //
	  // --- rebinned --- //
	  // ---------------- //
	  //pospm
	  yieldR5_pospm[i] *= 1.0 - funfeedpr->Eval(pTR5_pospm[i]);
	  eyieldR5_pospm[i] *= 1.0 - funfeedpr->Eval(pTR5_pospm[i]);
	  //negpm
	  yieldR5_negpm[i] *= 1.0 - pbarK*funfeedpr->Eval(pTR5_negpm[i]);
	  eyieldR5_negpm[i] *= 1.0 - pbarK*funfeedpr->Eval(pTR5_negpm[i]);
	  //posmp
	  yieldR5_posmp[i] *= 1.0 - funfeedpr->Eval(pTR5_posmp[i]);
	  eyieldR5_posmp[i] *= 1.0 - funfeedpr->Eval(pTR5_posmp[i]);
	  //negmp
	  yieldR5_negmp[i] *= 1.0 - pbarK*funfeedpr->Eval(pTR5_negmp[i]);
	  eyieldR5_negmp[i] *= 1.0 - pbarK*funfeedpr->Eval(pTR5_negmp[i]);
	  //poscb
	  yieldR5_poscb[i] *= 1.0 - funfeedpr->Eval(pTR5_poscb[i]);
	  eyieldR5_poscb[i] *= 1.0 - funfeedpr->Eval(pTR5_poscb[i]);
	  //negcb
	  yieldR5_negcb[i] *= 1.0 - pbarK*funfeedpr->Eval(pTR5_negcb[i]);
	  eyieldR5_negcb[i] *= 1.0 - pbarK*funfeedpr->Eval(pTR5_negcb[i]);
	}
    }






  // --- output data

  char fnameoutpospm[100];
  char fnameoutnegpm[100];
  char fnameoutposmp[100];
  char fnameoutnegmp[100];
  char fnameoutposcb[100];
  char fnameoutnegcb[100];

  sprintf(fnameoutpospm,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegpm,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameoutposmp,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegmp,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameoutposcb,"Data/FinalFeed/ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegcb,"Data/FinalFeed/ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

  ofstream foutpospm;
  ofstream foutnegpm;
  ofstream foutposmp;
  ofstream foutnegmp;
  ofstream foutposcb;
  ofstream foutnegcb;

  foutpospm.open(fnameoutpospm);
  foutnegpm.open(fnameoutnegpm);
  foutposmp.open(fnameoutposmp);
  foutnegmp.open(fnameoutnegmp);
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);

  float pT_pospm[100], yield_pospm[100], eyield_pospm[100];
  float pT_negpm[100], yield_negpm[100], eyield_negpm[100];
  float pT_posmp[100], yield_posmp[100], eyield_posmp[100];
  float pT_negmp[100], yield_negmp[100], eyield_negmp[100];
  float pT_poscb[100], yield_poscb[100], eyield_poscb[100];
  float pT_negcb[100], yield_negcb[100], eyield_negcb[100];

  for(int i=0; i<100; i++)
    {
      // pospm
      foutpospm<<pT_pospm[i]<<"\t"<<yield_pospm[i]<<"\t"<<eyield_pospm[i]<<endl;
      // negpm
      foutnegpm<<pT_negpm[i]<<"\t"<<yield_negpm[i]<<"\t"<<eyield_negpm[i]<<endl;
      // posmp
      foutposmp<<pT_posmp[i]<<"\t"<<yield_posmp[i]<<"\t"<<eyield_posmp[i]<<endl;
      // negmp
      foutnegmp<<pT_negmp[i]<<"\t"<<yield_negmp[i]<<"\t"<<eyield_negmp[i]<<endl;
      // poscb
      foutposcb<<pT_poscb[i]<<"\t"<<yield_poscb[i]<<"\t"<<eyield_poscb[i]<<endl;
      // negcb
      foutnegcb<<pT_negcb[i]<<"\t"<<yield_negcb[i]<<"\t"<<eyield_negcb[i]<<endl;
    }

  foutpospm.close();
  foutnegpm.close();
  foutposmp.close();
  foutnegmp.close();
  foutposcb.close();
  foutnegcb.close();










  // --- now output the rebinned data

  sprintf(fnameoutpospm,"Data/FinalFeed/R2_ptpid_%s_pos_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegpm,"Data/FinalFeed/R2_ptpid_%s_neg_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameoutposmp,"Data/FinalFeed/R2_ptpid_%s_pos_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegmp,"Data/FinalFeed/R2_ptpid_%s_neg_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameoutposcb,"Data/FinalFeed/R2_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegcb,"Data/FinalFeed/R2_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

  foutpospm.open(fnameoutpospm);
  foutnegpm.open(fnameoutnegpm);
  foutposmp.open(fnameoutposmp);
  foutnegmp.open(fnameoutnegmp);
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);

  float pTR2_pospm[100], yieldR2_pospm[100], eyieldR2_pospm[100];
  float pTR2_negpm[100], yieldR2_negpm[100], eyieldR2_negpm[100];
  float pTR2_posmp[100], yieldR2_posmp[100], eyieldR2_posmp[100];
  float pTR2_negmp[100], yieldR2_negmp[100], eyieldR2_negmp[100];
  float pTR2_poscb[100], yieldR2_poscb[100], eyieldR2_poscb[100];
  float pTR2_negcb[100], yieldR2_negcb[100], eyieldR2_negcb[100];

  //for(int i=0; i<100; i++)
  for(int i=0; i<50; i++)
    {
      // pospm
      foutpospm<<pTR2_pospm[i]<<"\t"<<yieldR2_pospm[i]<<"\t"<<eyieldR2_pospm[i]<<endl;
      // negpm
      foutnegpm<<pTR2_negpm[i]<<"\t"<<yieldR2_negpm[i]<<"\t"<<eyieldR2_negpm[i]<<endl;
      // posmp
      foutposmp<<pTR2_posmp[i]<<"\t"<<yieldR2_posmp[i]<<"\t"<<eyieldR2_posmp[i]<<endl;
      // negmp
      foutnegmp<<pTR2_negmp[i]<<"\t"<<yieldR2_negmp[i]<<"\t"<<eyieldR2_negmp[i]<<endl;
      // poscb
      foutposcb<<pTR2_poscb[i]<<"\t"<<yieldR2_poscb[i]<<"\t"<<eyieldR2_poscb[i]<<endl;
      // negcb
      foutnegcb<<pTR2_negcb[i]<<"\t"<<yieldR2_negcb[i]<<"\t"<<eyieldR2_negcb[i]<<endl;
    }

  foutpospm.close();
  foutnegpm.close();
  foutposmp.close();
  foutnegmp.close();
  foutposcb.close();
  foutnegcb.close();














  // --- now output the rebinned data

  sprintf(fnameoutpospm,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegpm,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s_pm.dat",sectorstring,pid,centstring);
  sprintf(fnameoutposmp,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegmp,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s_mp.dat",sectorstring,pid,centstring);
  sprintf(fnameoutposcb,"Data/FinalFeed/R5_ptpid_%s_pos_%d_dis_cent%s.dat",sectorstring,pid,centstring);
  sprintf(fnameoutnegcb,"Data/FinalFeed/R5_ptpid_%s_neg_%d_dis_cent%s.dat",sectorstring,pid,centstring);

  foutpospm.open(fnameoutpospm);
  foutnegpm.open(fnameoutnegpm);
  foutposmp.open(fnameoutposmp);
  foutnegmp.open(fnameoutnegmp);
  foutposcb.open(fnameoutposcb);
  foutnegcb.open(fnameoutnegcb);

  float pTR5_pospm[100], yieldR5_pospm[100], eyieldR5_pospm[100];
  float pTR5_negpm[100], yieldR5_negpm[100], eyieldR5_negpm[100];
  float pTR5_posmp[100], yieldR5_posmp[100], eyieldR5_posmp[100];
  float pTR5_negmp[100], yieldR5_negmp[100], eyieldR5_negmp[100];
  float pTR5_poscb[100], yieldR5_poscb[100], eyieldR5_poscb[100];
  float pTR5_negcb[100], yieldR5_negcb[100], eyieldR5_negcb[100];

  //for(int i=0; i<100; i++)
  for(int i=0; i<20; i++)
    {
      // pospm
      foutpospm<<pTR5_pospm[i]<<"\t"<<yieldR5_pospm[i]<<"\t"<<eyieldR5_pospm[i]<<endl;
      // negpm
      foutnegpm<<pTR5_negpm[i]<<"\t"<<yieldR5_negpm[i]<<"\t"<<eyieldR5_negpm[i]<<endl;
      // posmp
      foutposmp<<pTR5_posmp[i]<<"\t"<<yieldR5_posmp[i]<<"\t"<<eyieldR5_posmp[i]<<endl;
      // negmp
      foutnegmp<<pTR5_negmp[i]<<"\t"<<yieldR5_negmp[i]<<"\t"<<eyieldR5_negmp[i]<<endl;
      // poscb
      foutposcb<<pTR5_poscb[i]<<"\t"<<yieldR5_poscb[i]<<"\t"<<eyieldR5_poscb[i]<<endl;
      // negcb
      foutnegcb<<pTR5_negcb[i]<<"\t"<<yieldR5_negcb[i]<<"\t"<<eyieldR5_negcb[i]<<endl;
    }

  foutpospm.close();
  foutnegpm.close();
  foutposmp.close();
  foutnegmp.close();
  foutposcb.close();
  foutnegcb.close();















}
