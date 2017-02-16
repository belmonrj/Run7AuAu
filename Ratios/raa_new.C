void raa_new()
{

  // doit_file();
  // return;

  for(int i=0; i<5; i++)
    {
      doit_file(i,0,4,6);
      doit_file(i,1,4,7);
      doit_file(i,2,4,8);
      doit_file(i,3,4,9);
    }

}


void doit_file(int centid=0, int pionid=0, int kaonid=4, int protonid=6)
{

  int rebin=2;

  float Ncoll[5] = {960.2,609.5,300.8,94.2,14.8};
  float cross = 42; // 42mb is p+p total inelastic cross section at 200 GeV

  float ymin = 0.0;
  float xmin = 0.0;
  float ymax = 2.0;
  float xmax = 6.0;



  TLine *line = new TLine(xmin,1.0,xmax,1.0);

  TCanvas *c1 = new TCanvas("c1","",800,600);

  char centstring[5];
  if(centid==0) sprintf(centstring,"0010");
  else if(centid==1) sprintf(centstring,"1020");
  else if(centid==2) sprintf(centstring,"2040");
  else if(centid==3) sprintf(centstring,"4060");
  else if(centid==4) sprintf(centstring,"6092");
  else {cout<<"trouble"<<endl; return;}

  char bigcentstring[10];
  sprintf(bigcentstring,"MinBias"); // "default"
  if(centid==0) sprintf(bigcentstring,"0-10%%");
  if(centid==1) sprintf(bigcentstring,"10-20%%");
  if(centid==2) sprintf(bigcentstring,"20-40%%");
  if(centid==3) sprintf(bigcentstring,"40-60%%");
  if(centid==4) sprintf(bigcentstring,"60-92%%");

  char filename[100];
  ifstream fin;

  float pt[50], ept[50];
  float tmp;

  float pionpt[30], epionpt[30];
  float pionpos[30], epionpos[30];
  float pionneg[30], epionneg[30];

  // --------------- //
  // --- pionpos --- //
  // --------------- //
  sprintf(filename,"FinalFeed/ptpid_tofw_pos_%d_dis_cent%s.dat",pionid,centstring);
  fin.open(filename);
  for(int i=0; i<30; i++)
    {
      fin>>pionpt[i]>>pionpos[i]>>epionpos[i];
      if((float)pionpt[i]!=float(float(i)/10.0+0.05)&&i>0) // they're the same but this evaluates as false for i==0
	{
	  cout<<"trouble"<<endl;
	  cout<<"pt is "<<pt[i]<<" but pt is "<<i/10.0+0.05<<endl;
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
      fin>>pionpt[i]>>pionneg[i]>>epionneg[i];
      if((float)pionpt[i]!=float(float(i)/10.0+0.05)&&i>0) // they're the same but this evaluates as false for i==0
	{
	  cout<<"trouble"<<endl;
	  cout<<"pt is "<<pt[i]<<" but pt is "<<i/10.0+0.05<<endl;
	}
    }
  fin.close();

  // --- AND NOW THE TIME FOR REBINNING IS UPON US
  if(rebin==2)
    {
      for(int i=0; i<5; i++)
	{
	  int j = i+20;
	  int k1 = i*2+20;
	  int k2 = i*2+21;
	  pionpt[j] = (pionpt[k1]+pionpt[k2])/2.0;
	  pionpos[j] = (pionpos[k1]+pionpos[k2])/2.0;
	  pionneg[j] = (pionneg[k1]+pionneg[k2])/2.0;
	  epionpos[j] = sqrt(epionpos[k1]**2+epionpos[k2]**2)/2.0;
	  epionneg[j] = sqrt(epionneg[k1]**2+epionneg[k2]**2)/2.0;
	}
      for(int i=25; i<30; i++)
	{
	  pionpos[i] = -42;
	  pionneg[i] = -42;
	}
    }

  //cout<<"A"<<endl;

  float kaonpt[50], epionpt[50];
  float kaonpos[50], ekaonpos[50];
  float kaonneg[50], ekaonneg[50];

  // ----------------- //
  // --- kaonpos --- //
  // ----------------- //
  sprintf(filename,"FinalFeed/ptpid_tofw_pos_%d_dis_cent%s.dat",kaonid,centstring);
  fin.open(filename);
  for(int i=0; i<50; i++)
    {
      fin>>kaonpt[i]>>kaonpos[i]>>ekaonpos[i];
      if((float)kaonpt[i]!=float(float(i)/10.0+0.05)&&i>0) // they're the same but this evaluates as false for i==0
	{
	  cout<<"trouble"<<endl;
	  cout<<"pt is "<<pt[i]<<" but pt is "<<i/10.0+0.05<<endl;
	}
    }
  fin.close();

  // --------------- //
  // --- kaonneg --- //
  // --------------- //
  sprintf(filename,"FinalFeed/ptpid_tofw_neg_%d_dis_cent%s.dat",kaonid,centstring);
  fin.open(filename);
  for(int i=0; i<50; i++)
    {
      fin>>kaonpt[i]>>kaonneg[i]>>ekaonneg[i];
      if((float)kaonpt[i]!=float(float(i)/10.0+0.05)&&i>0) // they're the same but this evaluates as false for i==0
	{
	  cout<<"trouble"<<endl;
	  cout<<"pt is "<<pt[i]<<" but pt is "<<i/10.0+0.05<<endl;
	}
    }
  fin.close();

  //cout<<"B"<<endl;


  float protonpt[50], epionpt[50];
  float protonpos[50], eprotonpos[50];
  float protonneg[50], eprotonneg[50];

  // ----------------- //
  // --- protonpos --- //
  // ----------------- //
  sprintf(filename,"FinalFeed/ptpid_tofw_pos_%d_dis_cent%s.dat",protonid,centstring);
  fin.open(filename);
  for(int i=0; i<50; i++)
    {
      fin>>protonpt[i]>>protonpos[i]>>eprotonpos[i];
      if((float)protonpt[i]!=float(float(i)/10.0+0.05)&&i>0) // they're the same but this evaluates as false for i==0
	{
	  cout<<"trouble"<<endl;
	  cout<<"pt is "<<pt[i]<<" but pt is "<<i/10.0+0.05<<endl;
	}
    }
  fin.close();

  // ----------------- //
  // --- protonneg --- //
  // ----------------- //
  sprintf(filename,"FinalFeed/ptpid_tofw_neg_%d_dis_cent%s.dat",protonid,centstring);
  fin.open(filename);
  for(int i=0; i<50; i++)
    {
      fin>>protonpt[i]>>protonneg[i]>>eprotonneg[i];
      if((float)protonpt[i]!=float(float(i)/10.0+0.05)&&i>0) // they're the same but this evaluates as false for i==0
	{
	  cout<<"trouble"<<endl;
	  cout<<"pt is "<<pt[i]<<" but pt is "<<i/10.0+0.05<<endl;
	}
    }
  fin.close();

  // --- AND NOW THE TIME FOR REBINNING IS UPON US
  if(rebin==2)
    {
      for(int i=0; i<15; i++)
	{
	  int j = i+20;
	  int k1 = i*2+20;
	  int k2 = i*2+21;
	  protonpt[j] = (protonpt[k1]+protonpt[k2])/2.0;
	  protonpos[j] = (protonpos[k1]+protonpos[k2])/2.0;
	  protonneg[j] = (protonneg[k1]+protonneg[k2])/2.0;
	  eprotonpos[j] = sqrt(eprotonpos[k1]**2+eprotonpos[k2]**2)/2.0;
	  eprotonneg[j] = sqrt(eprotonneg[k1]**2+eprotonneg[k2]**2)/2.0;
	  //cout<<i<<" "<<j<<" "<<protonpt[j]<<" "<<endl;
	}
      for(int i=0; i<5; i++)
	{
	  int j = i+25;
	  int k1 = i*2+25;
	  int k2 = i*2+26;
	  protonpt[j] = (protonpt[k1]+protonpt[k2])/2.0;
	  protonpos[j] = (protonpos[k1]+protonpos[k2])/2.0;
	  protonneg[j] = (protonneg[k1]+protonneg[k2])/2.0;
	  eprotonpos[j] = sqrt(eprotonpos[k1]**2+eprotonpos[k2]**2)/2.0;
	  eprotonneg[j] = sqrt(eprotonneg[k1]**2+eprotonneg[k2]**2)/2.0;
	  //cout<<i<<" "<<j<<" "<<protonpt[j]<<" "<<endl;
	}
    }

  //cout<<"C"<<endl;


  //cout<<"oh man i'm so fucking tired!  that's all for now"<<endl;
  //return;



  float ptpion[34];
  float ptkaon[34];
  float ptproton[34];
  float eptpion[34]={0};
  float eptkaon[34]={0};
  float eptproton[34]={0};
  float ptratio[34];
  float eptratio[34]={0};
  float yieldpionpos[34],yieldpionneg[34];
  float eyieldpionpos[34],eyieldpionneg[34];
  float yieldkaonpos[34],yieldkaonneg[34];
  float eyieldkaonpos[34],eyieldkaonneg[34];
  float yieldprotonpos[34],yieldprotonneg[34];
  float eyieldprotonpos[34],eyieldprotonneg[34];
  float newratiopos[34],newrationeg[34];
  float enewratiopos[34],enewrationeg[34];


  //cout<<"D"<<endl;


  ifstream fin1;
  ifstream fin2;
  char fin1name[100];
  char fin2name[100];
  sprintf(fin1name,"ppg101/pospion.dat");
  sprintf(fin2name,"ppg101/negpion.dat");
  fin1.open(fin1name);
  fin2.open(fin2name);
  for(int i=0; i<27; i++)
    {
      fin1>>ptpion[i]>>yieldpionpos[i]>>eyieldpionpos[i]>>tmp>>tmp>>tmp>>tmp;
      fin2>>ptpion[i]>>yieldpionneg[i]>>eyieldpionneg[i]>>tmp>>tmp>>tmp>>tmp;
    }
  fin1.close();  
  fin2.close();
  // --- AND NOW THE TIME FOR REBINNING IS UPON US
  if(rebin==2)
    {
      for(int i=0; i<5; i++)
	{
	  int j = i+17;
	  int k1 = i*2+17;
	  int k2 = i*2+18;
	  ptpion[j] = (ptpion[k1]+ptpion[k2])/2.0;
	  yieldpionpos[j] = (yieldpionpos[k1]+yieldpionpos[k2])/2.0;
	  yieldpionneg[j] = (yieldpionneg[k1]+yieldpionneg[k2])/2.0;
	  eyieldpionpos[j] = sqrt(eyieldpionpos[k1]**2+eyieldpionpos[k2]**2)/2.0;
	  eyieldpionneg[j] = sqrt(eyieldpionneg[k1]**2+eyieldpionneg[k2]**2)/2.0;
	}
    }
  sprintf(fin1name,"ppg101/poskaon.dat");
  sprintf(fin2name,"ppg101/negkaon.dat");
  fin1.open(fin1name);
  fin2.open(fin2name);
  for(int i=0; i<16; i++)
    {
      fin1>>ptkaon[i]>>yieldkaonpos[i]>>eyieldkaonpos[i]>>tmp>>tmp>>tmp>>tmp;
      fin2>>ptkaon[i]>>yieldkaonneg[i]>>eyieldkaonneg[i]>>tmp>>tmp>>tmp>>tmp;
    }
  fin1.close();  
  fin2.close();
  sprintf(fin1name,"ppg101/posproton.dat");
  sprintf(fin2name,"ppg101/negproton.dat");
  fin1.open(fin1name);
  fin2.open(fin2name);
  for(int i=0; i<33; i++)
    {
      fin1>>ptproton[i]>>yieldprotonpos[i]>>eyieldprotonpos[i]>>tmp>>tmp>>tmp>>tmp;
      fin2>>ptproton[i]>>yieldprotonneg[i]>>eyieldprotonneg[i]>>tmp>>tmp>>tmp>>tmp;
    }
  fin1.close();  
  fin2.close();
  // --- AND NOW THE TIME FOR REBINNING IS UPON US
  if(rebin==2)
    {
      for(int i=0; i<10; i++)
	{
	  int j = i+15;
	  int k1 = i*2+15;
	  int k2 = i*2+16;
	  if(k2>33) break;
	  ptproton[j] = (ptproton[k1]+ptproton[k2])/2.0;
	  yieldprotonpos[j] = (yieldprotonpos[k1]+yieldprotonpos[k2])/2.0;
	  yieldprotonneg[j] = (yieldprotonneg[k1]+yieldprotonneg[k2])/2.0;
	  eyieldprotonpos[j] = sqrt(eyieldprotonpos[k1]**2+eyieldprotonpos[k2]**2)/2.0;
	  eyieldprotonneg[j] = sqrt(eyieldprotonneg[k1]**2+eyieldprotonneg[k2]**2)/2.0;
	  //cout<<i<<" "<<j<<" "<<ptproton[j]<<" "<<endl;
	}
    }


  //cout<<"E"<<endl;


  float pospionraa[27],epospionraa[27],esyspospionraa[27];
  float negpionraa[27],enegpionraa[27],esysnegpionraa[27];
  sprintf(filename,"regular/raa_%d_cent%s.txt",pionid,centstring);
  ofstream ftxt(filename);
  sprintf(filename,"regular/raa_%d_cent%s.tex",pionid,centstring);
  ofstream ftex(filename);
  for(int i=0; i<27; i++)
    {
      // float pt = float(i)/10.0+0.35;
      // if(pionpt[i+3]!=pt) {break;}
      // if(ptpion[i]!=pt) {break;}
      if(ptpion[i]!=pionpt[i+3])
	{
	  cout<<"trouble "<<i<<endl;
	  cout<<ptpion[i]<<endl;
	  cout<<pionpt[i+3]<<endl;
	}
      pospionraa[i] = pionpos[i+3]/yieldpionpos[i];
      epospionraa[i] = pospionraa[i]*sqrt((epionpos[i+3]/pionpos[i+3])**2+(eyieldpionpos[i]/yieldpionpos[i])**2);
      negpionraa[i] = pionneg[i+3]/yieldpionneg[i];
      enegpionraa[i] = negpionraa[i]*sqrt((epionneg[i+3]/pionneg[i+3])**2+(eyieldpionneg[i]/yieldpionneg[i])**2);
      pospionraa[i] /= Ncoll[centid];
      epospionraa[i] /= Ncoll[centid];
      negpionraa[i] /= Ncoll[centid];
      enegpionraa[i] /= Ncoll[centid];
      pospionraa[i] *= cross;
      epospionraa[i] *= cross;
      negpionraa[i] *= cross;
      enegpionraa[i] *= cross;
      esyspospionraa[i] = pospionraa[i]*0.1;
      esysnegpionraa[i] = negpionraa[i]*0.1;
      if(i<2) // remove low pT points...
	{
	  pospionraa[i] = -9;
	  negpionraa[i] = -9;
	  epospionraa[i] = 0;
	  enegpionraa[i] = 0;
	}
      ftxt<<ptpion[i]<<"\t"<<pospionraa[i]<<"\t"<<epospionraa[i]<<"\t"<<negpionraa[i]<<"\t"<<enegpionraa[i]<<endl;
      ftex<<ptpion[i]<<" & "<<pospionraa[i]<<" & "<<epospionraa[i]<<" & "<<negpionraa[i]<<" & "<<enegpionraa[i]<<" \\\\ "<<endl;
    }
  TGraphErrors *tge_pospionraa = new TGraphErrors(27,ptpion,pospionraa,eptpion,epospionraa);
  tge_pospionraa->SetMarkerColor(kRed);
  tge_pospionraa->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_negpionraa = new TGraphErrors(27,ptpion,negpionraa,eptpion,enegpionraa);
  tge_negpionraa->SetMarkerColor(kBlue);
  tge_negpionraa->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_syspospionraa = new TGraphErrors(27,ptpion,pospionraa,eptpion,esyspospionraa);
  TGraphErrors *tge_sysnegpionraa = new TGraphErrors(27,ptpion,negpionraa,eptpion,esysnegpionraa);

  //cout<<"F"<<endl;






  float A, dA, B, dB;
  float poskaonraa[16],eposkaonraa[16],esysposkaonraa[16];
  float negkaonraa[16],enegkaonraa[16],esysnegkaonraa[16];
  sprintf(filename,"regular/raa_%d_cent%s.txt",kaonid,centstring);
  ofstream ftxt(filename);
  sprintf(filename,"regular/raa_%d_cent%s.tex",kaonid,centstring);
  ofstream ftex(filename);
  for(int i=0; i<16; i++)
    {
      // float pt = float(i)/10.0+0.35;
      // if(kaonpt[i+3]!=pt) {break;}
      // if(ptkaon[i]!=pt) {break;}
      if(ptkaon[i]!=kaonpt[i+4]&&i<25)
	{
	  cout<<"kaon "<<i<<endl;
	  cout<<ptkaon[i]<<endl;
	  cout<<kaonpt[i+4]<<endl;
	}
      poskaonraa[i] = kaonpos[i+4]/yieldkaonpos[i];
      eposkaonraa[i] = poskaonraa[i]*sqrt((ekaonpos[i+4]/kaonpos[i+4])**2+(eyieldkaonpos[i]/yieldkaonpos[i])**2);
      negkaonraa[i] = kaonneg[i+4]/yieldkaonneg[i];
      enegkaonraa[i] = negkaonraa[i]*sqrt((ekaonneg[i+4]/kaonneg[i+4])**2+(eyieldkaonneg[i]/yieldkaonneg[i])**2);
      //cout<<ekaonpos[i+4]/kaonpos[i+4]<<" "<<eyieldkaonpos[i]/yieldkaonpos[i]<<endl;
      poskaonraa[i] /= Ncoll[centid];
      eposkaonraa[i] /= Ncoll[centid];
      negkaonraa[i] /= Ncoll[centid];
      enegkaonraa[i] /= Ncoll[centid];
      poskaonraa[i] *= cross;
      eposkaonraa[i] *= cross;
      negkaonraa[i] *= cross;
      enegkaonraa[i] *= cross;
      esysposkaonraa[i] = poskaonraa[i]*0.1;
      esysnegkaonraa[i] = negkaonraa[i]*0.1;
      if(ptkaon[i]<0.5)
	{
	  poskaonraa[i] = -9;
	  negkaonraa[i] = -9;
	  eposkaonraa[i] = 0;
	  enegkaonraa[i] = 0;
	}
      ftxt<<ptkaon[i]<<"\t"<<poskaonraa[i]<<"\t"<<eposkaonraa[i]<<"\t"<<negkaonraa[i]<<"\t"<<enegkaonraa[i]<<endl;
      ftex<<ptkaon[i]<<" & "<<poskaonraa[i]<<" & "<<eposkaonraa[i]<<" & "<<negkaonraa[i]<<" & "<<enegkaonraa[i]<<" \\\\ "<<endl;
    }
  TGraphErrors *tge_poskaonraa = new TGraphErrors(16,ptkaon,poskaonraa,eptkaon,eposkaonraa);
  tge_poskaonraa->SetMarkerColor(kRed);
  tge_poskaonraa->SetMarkerStyle(kOpenTriangleUp);
  TGraphErrors *tge_negkaonraa = new TGraphErrors(16,ptkaon,negkaonraa,eptkaon,enegkaonraa);
  tge_negkaonraa->SetMarkerColor(kBlue);
  tge_negkaonraa->SetMarkerStyle(kOpenTriangleUp);
  TGraphErrors *tge_sysposkaonraa = new TGraphErrors(16,ptkaon,poskaonraa,eptkaon,esysposkaonraa);
  TGraphErrors *tge_sysnegkaonraa = new TGraphErrors(16,ptkaon,negkaonraa,eptkaon,esysnegkaonraa);

  //cout<<"G"<<endl;




  //  float A, dA, B, dB; // shown above
  float posprotonraa[33],eposprotonraa[33],esysposprotonraa[33];
  float negprotonraa[33],enegprotonraa[33],esysnegprotonraa[33];
  sprintf(filename,"regular/raa_%d_cent%s.txt",protonid,centstring);
  ofstream ftxt(filename);
  sprintf(filename,"regular/raa_%d_cent%s.tex",protonid,centstring);
  ofstream ftex(filename);
  for(int i=0; i<33; i++)
    {
      // float pt = float(i)/10.0+0.35;
      // if(protonpt[i+3]!=pt) {break;}
      // if(ptproton[i]!=pt) {break;}
      if(ptproton[i]!=protonpt[i+5]&&i<25)
	{
	  cout<<"proton "<<i<<" ";
	  //cout<<"AAAAAAAAHHH "<<i<<endl;
	  cout<<ptproton[i]<<" ";
	  cout<<protonpt[i+5]<<endl;
	}
      if(i<25)
      	{
      	  posprotonraa[i] = protonpos[i+5]/yieldprotonpos[i];
      	  eposprotonraa[i] = posprotonraa[i]*sqrt((eprotonpos[i+5]/protonpos[i+5])**2+(eyieldprotonpos[i]/yieldprotonpos[i])**2);
      	  negprotonraa[i] = protonneg[i+5]/yieldprotonneg[i];
      	  enegprotonraa[i] = negprotonraa[i]*sqrt((eprotonneg[i+5]/protonneg[i+5])**2+(eyieldprotonneg[i]/yieldprotonneg[i])**2);
      	  //cout<<eprotonpos[i+5]/protonpos[i+5]<<" "<<eyieldprotonpos[i]/yieldprotonpos[i]<<endl;
      	}
      // else
      // 	{
      // 	  float pta = ((protonpt[i*2-20]+protonpt[i*2-19])/2.0);
      // 	  float ptb = ptproton[i];
      // 	  //cout<<"pta is "<<pta<<" and ptb is "<<ptb<<endl;
      // 	  A = ((protonpos[i*2-20]+protonpos[i*2-19])/2.0);
      // 	  dA = (sqrt(eprotonpos[i*2-20]**2+eprotonpos[i*2-19]**2)/2.0);
      // 	  B = yieldprotonpos[i];
      // 	  dB = eyieldprotonpos[i];
      // 	  posprotonraa[i] = A/B;
      // 	  eposprotonraa[i] = posprotonraa[i]*sqrt((dA/A)**2+(dB/B)**2);
      // 	  A = ((protonneg[i*2-20]+protonneg[i*2-19])/2.0);
      // 	  dA = (sqrt(eprotonneg[i*2-20]**2+eprotonneg[i*2-19]**2)/2.0);
      // 	  B = yieldprotonneg[i];
      // 	  dB = eyieldprotonneg[i];
      // 	  //cout<<dA/A<<" "<<dB/B<<endl; // NOTICE!
      // 	  negprotonraa[i] = A/B;
      // 	  enegprotonraa[i] = negprotonraa[i]*sqrt((dA/A)**2+(dB/B)**2);
      // 	}
      posprotonraa[i] /= Ncoll[centid];
      eposprotonraa[i] /= Ncoll[centid];
      negprotonraa[i] /= Ncoll[centid];
      enegprotonraa[i] /= Ncoll[centid];
      posprotonraa[i] *= cross;
      eposprotonraa[i] *= cross;
      negprotonraa[i] *= cross;
      enegprotonraa[i] *= cross;
      esysposprotonraa[i] = posprotonraa[i]*0.1;
      esysnegprotonraa[i] = negprotonraa[i]*0.1;
      ftxt<<ptproton[i]<<"\t"<<posprotonraa[i]<<"\t"<<eposprotonraa[i]<<"\t"<<negprotonraa[i]<<"\t"<<enegprotonraa[i]<<endl;
      ftex<<ptproton[i]<<" & "<<posprotonraa[i]<<" & "<<eposprotonraa[i]<<" & "<<negprotonraa[i]<<" & "<<enegprotonraa[i]<<" \\\\ "<<endl;
    }
  TGraphErrors *tge_posprotonraa = new TGraphErrors(24,ptproton,posprotonraa,eptproton,eposprotonraa);
  tge_posprotonraa->SetMarkerColor(kRed);
  tge_posprotonraa->SetMarkerStyle(kOpenSquare);
  TGraphErrors *tge_negprotonraa = new TGraphErrors(24,ptproton,negprotonraa,eptproton,enegprotonraa);
  tge_negprotonraa->SetMarkerColor(kBlue);
  tge_negprotonraa->SetMarkerStyle(kOpenSquare);
  TGraphErrors *tge_sysposprotonraa = new TGraphErrors(24,ptproton,posprotonraa,eptproton,esysposprotonraa);
  TGraphErrors *tge_sysnegprotonraa = new TGraphErrors(24,ptproton,negprotonraa,eptproton,esysnegprotonraa);


  //cout<<"H"<<endl;





  tge_syspospionraa->SetMarkerColor(kRed-10);
  tge_syspospionraa->SetMarkerStyle(1);
  tge_syspospionraa->SetLineColor(kRed-10);
  tge_syspospionraa->SetLineWidth(15);
  tge_sysnegpionraa->SetMarkerColor(kBlue-10);
  tge_sysnegpionraa->SetMarkerStyle(1);
  tge_sysnegpionraa->SetLineColor(kBlue-10);
  tge_sysnegpionraa->SetLineWidth(15);

  tge_sysposkaonraa->SetMarkerColor(kRed-10);
  tge_sysposkaonraa->SetMarkerStyle(1);
  tge_sysposkaonraa->SetLineColor(kRed-10);
  tge_sysposkaonraa->SetLineWidth(15);
  tge_sysnegkaonraa->SetMarkerColor(kBlue-10);
  tge_sysnegkaonraa->SetMarkerStyle(1);
  tge_sysnegkaonraa->SetLineColor(kBlue-10);
  tge_sysnegkaonraa->SetLineWidth(15);

  tge_sysposprotonraa->SetMarkerColor(kRed-10);
  tge_sysposprotonraa->SetMarkerStyle(1);
  tge_sysposprotonraa->SetLineColor(kRed-10);
  tge_sysposprotonraa->SetLineWidth(15);
  tge_sysnegprotonraa->SetMarkerColor(kBlue-10);
  tge_sysnegprotonraa->SetMarkerStyle(1);
  tge_sysnegprotonraa->SetLineColor(kBlue-10);
  tge_sysnegprotonraa->SetLineWidth(15);

  //cout<<"I"<<endl;








  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tge_syspospionraa);
  tmg->Add(tge_sysnegpionraa);
  tmg->Add(tge_sysposkaonraa);
  tmg->Add(tge_sysnegkaonraa);
  tmg->Add(tge_sysposprotonraa);
  tmg->Add(tge_sysnegprotonraa);
  tmg->Add(tge_pospionraa);
  tmg->Add(tge_negpionraa);
  tmg->Add(tge_poskaonraa);
  tmg->Add(tge_negkaonraa);
  tmg->Add(tge_posprotonraa);
  tmg->Add(tge_negprotonraa);
  tmg->Draw("apz");
  line->Draw();
  tmg->SetMaximum(ymax);
  tmg->SetMinimum(ymin);
  tmg->GetXaxis()->SetLimits(xmin,xmax);
  tmg->GetYaxis()->SetTitle("R_{AA}");
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetYaxis()->CenterTitle();
  tmg->GetXaxis()->CenterTitle();

  //cout<<"J"<<endl;

  TLegend *leg = new TLegend(0.68,0.68,0.88,0.88);
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->AddEntry(tge_pospionraa,"#pi^{+}","p");
  leg->AddEntry(tge_negpionraa,"#pi^{-}","p");
  leg->AddEntry(tge_poskaonraa,"K^{+}","p");
  leg->AddEntry(tge_negkaonraa,"K^{-}","p");
  leg->AddEntry(tge_posprotonraa,"p","p");
  leg->AddEntry(tge_negprotonraa,"#bar{p}","p");
  leg->Draw();

  //cout<<"K"<<endl;

  //TPaveText *tpt_coll = new TPaveText(xmin+0.5,ymax+0.01,xmax-0.5,ymax+0.16);
  TPaveText *tpt_coll = new TPaveText(xmin+0.5,ymax*1.01,xmax-0.5,ymax*1.1);
  tpt_coll->SetFillColor(kWhite);
  tpt_coll->SetBorderSize(0);
  tpt_coll->AddText("Au+Au  #sqrt{s_{NN}} = 200 GeV");
  tpt_coll->Draw();

  //TPaveText *tpt_cent = new TPaveText(xmin+0.25,ymax-0.4,xmin+1.5,ymax-0.2);
  TPaveText *tpt_cent = new TPaveText(xmax*0.05,ymax*0.82,xmax*0.3,ymax*0.95);
  tpt_cent->SetFillColor(kWhite);
  tpt_cent->SetBorderSize(0);
  tpt_cent->AddText(bigcentstring);
  tpt_cent->Draw();


  //cout<<"L"<<endl;


  char figname[100];
  sprintf(figname,"regular/raa_new_%d%d%d_cent%s.gif",pionid,kaonid,protonid,centstring);
  c1->Print(figname);
  sprintf(figname,"regular/raa_new_%d%d%d_cent%s.eps",pionid,kaonid,protonid,centstring);
  c1->Print(figname);

  c1->Clear();
  delete c1;

}
