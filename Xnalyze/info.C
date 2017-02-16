30c30
< const float pi = 3.141592653589793;
---
> 
38,40c38,40
< float isPionANA(float x, float m2tofw);
< float isKaonANA(float x, float m2tofw);
< float isProtonANA(float x, float m2tofw);
---
> float isPionNew(float x, float m2tofw);
> float isKaonNew(float x, float m2tofw);
> float isProtonNew(float x, float m2tofw);
46,53d45
< float isPionLME(float x, float m2tofw);
< float isKaonLME(float x, float m2tofw);
< float isProtonLME(float x, float m2tofw);
< 
< float isPionPDI(float x, float m2tofw);
< //float isKaonPDI(float x, float m2tofw);
< //float isProtonPDI(float x, float m2tofw);
< 
63d54
< bool GoodEMC(float emcz, float emcphi);
67d57
< bool SysGoodEMC(float emcz, float emcphi);
120,124c110,114
<       cout<<"Wrong number of input arguments"<<endl;
<       cout<<"This program takes 0 or 2 arguments"<<endl;
<       cout<<"With 0 arguments it prompts the user for the file list and output root file"<<endl;
<       cout<<"With 2 arguments the first is the file list and the second is the output root file"<<endl;
<       return 1;
---
>       cerr<<"Wrong number of input arguments"<<endl;
>       cerr<<"This program takes 0 or 2 arguments"<<endl;
>       cerr<<"With 0 arguments it prompts the user for the file list and output root file"<<endl;
>       cerr<<"With 2 arguments the first is the file list and the second is the output root file"<<endl;
>       exit(1);
145,147d134
<   TH1F *hhcent = new TH1F("hhcent","cent",100,0,100); // doesn't work, event bias
<   TH1F *hhbbcz = new TH1F("hhbbcz","bbcz",100,-50,50);
< 
216d202
< 
286,289c272
<   //TH2F *TOFWZedPhiNewNewDis  = new TH2F("TOFWZedPhiNewNewDis", "TOFW phi vs zed w/ all FC", 400, -200, 200, 500, -0.3, 0.7); // unused for now
<   //
<   TH2F *EMCZedPhiDis  = new TH2F("EMCZedPhiDis", "EMC phi vs zed w/o FC", 400, -200, 200, 500, -0.3, 0.7);
<   TH2F *EMCZedPhiNewDis  = new TH2F("EMCZedPhiNewDis", "EMC phi vs zed w/ FC",400, -200, 200, 500, -0.3, 0.7);
---
>   TH2F *TOFWZedPhiNewNewDis  = new TH2F("TOFWZedPhiNewNewDis", "TOFW phi vs zed w/ all FC", 400, -200, 200, 500, -0.3, 0.7);
359,373d341
<   TH2F *m2pTdis_epc_pos = new TH2F("m2pTdis_epc_pos","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
<   TH2F *m2pTdis_epc_neg = new TH2F("m2pTdis_epc_neg","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
< 
<   TH2F *m2pTdis_epc_pos_cent0 = new TH2F("m2pTdis_epc_pos_cent0","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
<   TH2F *m2pTdis_epc_pos_cent1 = new TH2F("m2pTdis_epc_pos_cent1","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
<   TH2F *m2pTdis_epc_pos_cent2 = new TH2F("m2pTdis_epc_pos_cent2","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
<   TH2F *m2pTdis_epc_pos_cent3 = new TH2F("m2pTdis_epc_pos_cent3","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
<   TH2F *m2pTdis_epc_pos_cent4 = new TH2F("m2pTdis_epc_pos_cent4","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
< 
<   TH2F *m2pTdis_epc_neg_cent0 = new TH2F("m2pTdis_epc_neg_cent0","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
<   TH2F *m2pTdis_epc_neg_cent1 = new TH2F("m2pTdis_epc_neg_cent1","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
<   TH2F *m2pTdis_epc_neg_cent2 = new TH2F("m2pTdis_epc_neg_cent2","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
<   TH2F *m2pTdis_epc_neg_cent3 = new TH2F("m2pTdis_epc_neg_cent3","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
<   TH2F *m2pTdis_epc_neg_cent4 = new TH2F("m2pTdis_epc_neg_cent4","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
< 
489a458
>   // ------------------------------------ //
847,1013c816
< 
<   // --- first X
<   TH2F *hh_X_ecorept_pospion_centMB = new TH2F("hh_X_ecorept_pospion_centMB","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_negpion_centMB = new TH2F("hh_X_ecorept_negpion_centMB","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_posproton_centMB = new TH2F("hh_X_ecorept_posproton_centMB","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_negproton_centMB = new TH2F("hh_X_ecorept_negproton_centMB","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_pospion_cent0010 = new TH2F("hh_X_ecorept_pospion_cent0010","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_negpion_cent0010 = new TH2F("hh_X_ecorept_negpion_cent0010","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_posproton_cent0010 = new TH2F("hh_X_ecorept_posproton_cent0010","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_negproton_cent0010 = new TH2F("hh_X_ecorept_negproton_cent0010","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_pospion_cent1020 = new TH2F("hh_X_ecorept_pospion_cent1020","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_negpion_cent1020 = new TH2F("hh_X_ecorept_negpion_cent1020","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_posproton_cent1020 = new TH2F("hh_X_ecorept_posproton_cent1020","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_negproton_cent1020 = new TH2F("hh_X_ecorept_negproton_cent1020","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_pospion_cent2040 = new TH2F("hh_X_ecorept_pospion_cent2040","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_negpion_cent2040 = new TH2F("hh_X_ecorept_negpion_cent2040","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_posproton_cent2040 = new TH2F("hh_X_ecorept_posproton_cent2040","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_negproton_cent2040 = new TH2F("hh_X_ecorept_negproton_cent2040","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_pospion_cent4060 = new TH2F("hh_X_ecorept_pospion_cent4060","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_negpion_cent4060 = new TH2F("hh_X_ecorept_negpion_cent4060","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_posproton_cent4060 = new TH2F("hh_X_ecorept_posproton_cent4060","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_negproton_cent4060 = new TH2F("hh_X_ecorept_negproton_cent4060","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_pospion_cent6092 = new TH2F("hh_X_ecorept_pospion_cent6092","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_negpion_cent6092 = new TH2F("hh_X_ecorept_negpion_cent6092","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_posproton_cent6092 = new TH2F("hh_X_ecorept_posproton_cent6092","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_X_ecorept_negproton_cent6092 = new TH2F("hh_X_ecorept_negproton_cent6092","...",50,0.0,5.0,100,0.0,5.0);
<   // --- then Y
<   TH2F *hh_Y_ecorept_pospion_centMB = new TH2F("hh_Y_ecorept_pospion_centMB","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_negpion_centMB = new TH2F("hh_Y_ecorept_negpion_centMB","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_posproton_centMB = new TH2F("hh_Y_ecorept_posproton_centMB","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_negproton_centMB = new TH2F("hh_Y_ecorept_negproton_centMB","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_pospion_cent0010 = new TH2F("hh_Y_ecorept_pospion_cent0010","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_negpion_cent0010 = new TH2F("hh_Y_ecorept_negpion_cent0010","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_posproton_cent0010 = new TH2F("hh_Y_ecorept_posproton_cent0010","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_negproton_cent0010 = new TH2F("hh_Y_ecorept_negproton_cent0010","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_pospion_cent1020 = new TH2F("hh_Y_ecorept_pospion_cent1020","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_negpion_cent1020 = new TH2F("hh_Y_ecorept_negpion_cent1020","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_posproton_cent1020 = new TH2F("hh_Y_ecorept_posproton_cent1020","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_negproton_cent1020 = new TH2F("hh_Y_ecorept_negproton_cent1020","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_pospion_cent2040 = new TH2F("hh_Y_ecorept_pospion_cent2040","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_negpion_cent2040 = new TH2F("hh_Y_ecorept_negpion_cent2040","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_posproton_cent2040 = new TH2F("hh_Y_ecorept_posproton_cent2040","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_negproton_cent2040 = new TH2F("hh_Y_ecorept_negproton_cent2040","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_pospion_cent4060 = new TH2F("hh_Y_ecorept_pospion_cent4060","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_negpion_cent4060 = new TH2F("hh_Y_ecorept_negpion_cent4060","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_posproton_cent4060 = new TH2F("hh_Y_ecorept_posproton_cent4060","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_negproton_cent4060 = new TH2F("hh_Y_ecorept_negproton_cent4060","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_pospion_cent6092 = new TH2F("hh_Y_ecorept_pospion_cent6092","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_negpion_cent6092 = new TH2F("hh_Y_ecorept_negpion_cent6092","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_posproton_cent6092 = new TH2F("hh_Y_ecorept_posproton_cent6092","...",50,0.0,5.0,100,0.0,5.0);
<   TH2F *hh_Y_ecorept_negproton_cent6092 = new TH2F("hh_Y_ecorept_negproton_cent6092","...",50,0.0,5.0,100,0.0,5.0);
< 
< 
<   //
<   TH1F *hh_X_spectpt_pospion_centMB = new TH1F("hh_X_spectpt_pospion_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_negpion_centMB = new TH1F("hh_X_spectpt_negpion_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_pospion_centMB = new TH1F("hh_X_specept_pospion_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_negpion_centMB = new TH1F("hh_X_specept_negpion_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_pospion_cent0010 = new TH1F("hh_X_spectpt_pospion_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_negpion_cent0010 = new TH1F("hh_X_spectpt_negpion_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_pospion_cent0010 = new TH1F("hh_X_specept_pospion_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_negpion_cent0010 = new TH1F("hh_X_specept_negpion_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_pospion_cent1020 = new TH1F("hh_X_spectpt_pospion_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_negpion_cent1020 = new TH1F("hh_X_spectpt_negpion_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_pospion_cent1020 = new TH1F("hh_X_specept_pospion_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_negpion_cent1020 = new TH1F("hh_X_specept_negpion_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_pospion_cent2040 = new TH1F("hh_X_spectpt_pospion_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_negpion_cent2040 = new TH1F("hh_X_spectpt_negpion_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_pospion_cent2040 = new TH1F("hh_X_specept_pospion_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_negpion_cent2040 = new TH1F("hh_X_specept_negpion_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_pospion_cent4060 = new TH1F("hh_X_spectpt_pospion_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_negpion_cent4060 = new TH1F("hh_X_spectpt_negpion_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_pospion_cent4060 = new TH1F("hh_X_specept_pospion_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_negpion_cent4060 = new TH1F("hh_X_specept_negpion_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_pospion_cent6092 = new TH1F("hh_X_spectpt_pospion_cent6092", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_negpion_cent6092 = new TH1F("hh_X_spectpt_negpion_cent6092", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_pospion_cent6092 = new TH1F("hh_X_specept_pospion_cent6092", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_negpion_cent6092 = new TH1F("hh_X_specept_negpion_cent6092", "...", 100, 0.0, 10.0);
<   //
<   TH1F *hh_X_spectpt_posproton_centMB = new TH1F("hh_X_spectpt_posproton_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_negproton_centMB = new TH1F("hh_X_spectpt_negproton_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_posproton_centMB = new TH1F("hh_X_specept_posproton_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_negproton_centMB = new TH1F("hh_X_specept_negproton_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_posproton_cent0010 = new TH1F("hh_X_spectpt_posproton_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_negproton_cent0010 = new TH1F("hh_X_spectpt_negproton_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_posproton_cent0010 = new TH1F("hh_X_specept_posproton_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_negproton_cent0010 = new TH1F("hh_X_specept_negproton_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_posproton_cent1020 = new TH1F("hh_X_spectpt_posproton_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_negproton_cent1020 = new TH1F("hh_X_spectpt_negproton_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_posproton_cent1020 = new TH1F("hh_X_specept_posproton_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_negproton_cent1020 = new TH1F("hh_X_specept_negproton_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_posproton_cent2040 = new TH1F("hh_X_spectpt_posproton_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_negproton_cent2040 = new TH1F("hh_X_spectpt_negproton_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_posproton_cent2040 = new TH1F("hh_X_specept_posproton_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_negproton_cent2040 = new TH1F("hh_X_specept_negproton_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_posproton_cent4060 = new TH1F("hh_X_spectpt_posproton_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_negproton_cent4060 = new TH1F("hh_X_spectpt_negproton_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_posproton_cent4060 = new TH1F("hh_X_specept_posproton_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_negproton_cent4060 = new TH1F("hh_X_specept_negproton_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_posproton_cent6092 = new TH1F("hh_X_spectpt_posproton_cent6092", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_spectpt_negproton_cent6092 = new TH1F("hh_X_spectpt_negproton_cent6092", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_posproton_cent6092 = new TH1F("hh_X_specept_posproton_cent6092", "...", 100, 0.0, 10.0);
<   TH1F *hh_X_specept_negproton_cent6092 = new TH1F("hh_X_specept_negproton_cent6092", "...", 100, 0.0, 10.0);
< 
<   // now Y
< 
<   //
<   TH1F *hh_Y_spectpt_pospion_centMB = new TH1F("hh_Y_spectpt_pospion_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_negpion_centMB = new TH1F("hh_Y_spectpt_negpion_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_pospion_centMB = new TH1F("hh_Y_specept_pospion_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_negpion_centMB = new TH1F("hh_Y_specept_negpion_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_pospion_cent0010 = new TH1F("hh_Y_spectpt_pospion_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_negpion_cent0010 = new TH1F("hh_Y_spectpt_negpion_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_pospion_cent0010 = new TH1F("hh_Y_specept_pospion_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_negpion_cent0010 = new TH1F("hh_Y_specept_negpion_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_pospion_cent1020 = new TH1F("hh_Y_spectpt_pospion_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_negpion_cent1020 = new TH1F("hh_Y_spectpt_negpion_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_pospion_cent1020 = new TH1F("hh_Y_specept_pospion_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_negpion_cent1020 = new TH1F("hh_Y_specept_negpion_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_pospion_cent2040 = new TH1F("hh_Y_spectpt_pospion_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_negpion_cent2040 = new TH1F("hh_Y_spectpt_negpion_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_pospion_cent2040 = new TH1F("hh_Y_specept_pospion_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_negpion_cent2040 = new TH1F("hh_Y_specept_negpion_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_pospion_cent4060 = new TH1F("hh_Y_spectpt_pospion_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_negpion_cent4060 = new TH1F("hh_Y_spectpt_negpion_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_pospion_cent4060 = new TH1F("hh_Y_specept_pospion_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_negpion_cent4060 = new TH1F("hh_Y_specept_negpion_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_pospion_cent6092 = new TH1F("hh_Y_spectpt_pospion_cent6092", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_negpion_cent6092 = new TH1F("hh_Y_spectpt_negpion_cent6092", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_pospion_cent6092 = new TH1F("hh_Y_specept_pospion_cent6092", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_negpion_cent6092 = new TH1F("hh_Y_specept_negpion_cent6092", "...", 100, 0.0, 10.0);
<   //
<   TH1F *hh_Y_spectpt_posproton_centMB = new TH1F("hh_Y_spectpt_posproton_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_negproton_centMB = new TH1F("hh_Y_spectpt_negproton_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_posproton_centMB = new TH1F("hh_Y_specept_posproton_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_negproton_centMB = new TH1F("hh_Y_specept_negproton_centMB", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_posproton_cent0010 = new TH1F("hh_Y_spectpt_posproton_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_negproton_cent0010 = new TH1F("hh_Y_spectpt_negproton_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_posproton_cent0010 = new TH1F("hh_Y_specept_posproton_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_negproton_cent0010 = new TH1F("hh_Y_specept_negproton_cent0010", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_posproton_cent1020 = new TH1F("hh_Y_spectpt_posproton_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_negproton_cent1020 = new TH1F("hh_Y_spectpt_negproton_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_posproton_cent1020 = new TH1F("hh_Y_specept_posproton_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_negproton_cent1020 = new TH1F("hh_Y_specept_negproton_cent1020", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_posproton_cent2040 = new TH1F("hh_Y_spectpt_posproton_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_negproton_cent2040 = new TH1F("hh_Y_spectpt_negproton_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_posproton_cent2040 = new TH1F("hh_Y_specept_posproton_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_negproton_cent2040 = new TH1F("hh_Y_specept_negproton_cent2040", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_posproton_cent4060 = new TH1F("hh_Y_spectpt_posproton_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_negproton_cent4060 = new TH1F("hh_Y_spectpt_negproton_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_posproton_cent4060 = new TH1F("hh_Y_specept_posproton_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_negproton_cent4060 = new TH1F("hh_Y_specept_negproton_cent4060", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_posproton_cent6092 = new TH1F("hh_Y_spectpt_posproton_cent6092", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_spectpt_negproton_cent6092 = new TH1F("hh_Y_spectpt_negproton_cent6092", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_posproton_cent6092 = new TH1F("hh_Y_specept_posproton_cent6092", "...", 100, 0.0, 10.0);
<   TH1F *hh_Y_specept_negproton_cent6092 = new TH1F("hh_Y_specept_negproton_cent6092", "...", 100, 0.0, 10.0);
< 
< 
< 
< 
< 
< 
< 
<   // ---------------------------- //
<   // --- Done with Histograms --- //
<   // ---------------------------- //
< 
---
>   // --- Done with Histograms ---------------------
1021c824
<   if(!fin)
---
>   if(!inFile)
1024c827
<       return 1;
---
>       exit(0);
1036a840
> 	  //exit(0);
1045a850
> 	  //exit(0); 
1070c875
< 	  float bbcz = ktree->bbcz;
---
> 	  //float bbcz = ktree->bbcz;
1075,1077d879
< 	  hhcent->Fill(cent);
< 	  hhbbcz->Fill(bbcz);
< 
1165d966
< 	      float sigma_tofw = sqrt(tofwsdz*tofwsdz+tofwsdphi*tofwsdphi);// NEW!!!
1243,1249c1044,1048
< 	      // float ppc1x   = ktree->HadronTracks_ppc1x[itrk];
< 	      // float ppc1y   = ktree->HadronTracks_ppc1y[itrk];
< 	      // float ppc1z   = ktree->HadronTracks_ppc1z[itrk];
< 	      // float pc1z    = ppc1z;
< 	      // float pc1phi  = atan2(ppc1y,ppc1x);  
< 	      float pc1z    = ktree->HadronTracks_pc1z[itrk]; // NEW
< 	      float pc1phi  = ktree->HadronTracks_pc1phi[itrk]; // NEW
---
> 	      float ppc1x   = ktree->HadronTracks_ppc1x[itrk];
> 	      float ppc1y   = ktree->HadronTracks_ppc1y[itrk];
> 	      float ppc1z   = ktree->HadronTracks_ppc1z[itrk];
> 	      float pc1z    = ppc1z;
> 	      float pc1phi  = atan2(ppc1y,ppc1x);  
1263c1062
< 	      // float pc2z    = ppc2z - pc2dz;
---
> 	      // float pc2z    = ppc2z -pc2dz;
1265,1266d1063
< 	      // float pc2z    = ktree->HadronTracks_pc2z[itrk]; // NEW
< 	      // float pc2phi  = ktree->HadronTracks_pc2phi[itrk]; // NEW
1274,1283c1071,1077
< 	      // float ppc3x   = ktree->HadronTracks_ppc3x[itrk];
< 	      // float ppc3y   = ktree->HadronTracks_ppc3y[itrk];
< 	      // float ppc3z   = ktree->HadronTracks_ppc3z[itrk];
< 	      // float pc3dz   = ktree->HadronTracks_pc3dz[itrk];
< 	      // float pc3dphi = ktree->HadronTracks_pc3dphi[itrk];
< 	      // float pc3z    = ppc3z - pc3dz;
< 	      // float pc3phi  = atan2(ppc3y,ppc3x) - pc3dphi;
< 	      float pc3z    = ktree->HadronTracks_pc3z[itrk]; // NEW
< 	      float pc3phi  = ktree->HadronTracks_pc3phi[itrk]; // NEW
< 	      //pc3phi = pi/2 - pc3phi; // TEMP!
---
> 	      float ppc3x   = ktree->HadronTracks_ppc3x[itrk];
> 	      float ppc3y   = ktree->HadronTracks_ppc3y[itrk];
> 	      float ppc3z   = ktree->HadronTracks_ppc3z[itrk];
> 	      float pc3dz   = ktree->HadronTracks_pc3dz[itrk];
> 	      float pc3dphi = ktree->HadronTracks_pc3dphi[itrk];
> 	      float pc3z    = ppc3z - pc3dz;
> 	      float pc3phi  = atan2(ppc3y,ppc3x) - pc3dphi;
1292,1301c1086,1092
< 	      // float ptofwx   = ktree->HadronTracks_ptofwx[itrk];
< 	      // float ptofwy   = ktree->HadronTracks_ptofwy[itrk];
< 	      // float ptofwz   = ktree->HadronTracks_ptofwz[itrk];
< 	      // float tofwdz   = ktree->HadronTracks_tofwdz[itrk];
< 	      // float tofwdphi = ktree->HadronTracks_tofwdphi[itrk];
< 	      // float tofwz    = ptofwz - tofwdz;
< 	      // float tofwphi  = atan2(ptofwy,ptofwx) - tofwdphi;
< 	      float tofwz    = ktree->HadronTracks_tofwz[itrk]; // NEW
< 	      float tofwphi  = ktree->HadronTracks_tofwphi[itrk]; // NEW
< 	      tofwphi = pi/2 - tofwphi; // TEMP!
---
> 	      float ptofwx   = ktree->HadronTracks_ptofwx[itrk];
> 	      float ptofwy   = ktree->HadronTracks_ptofwy[itrk];
> 	      float ptofwz   = ktree->HadronTracks_ptofwz[itrk];
> 	      float tofwdz   = ktree->HadronTracks_tofwdz[itrk];
> 	      float tofwdphi = ktree->HadronTracks_tofwdphi[itrk];
> 	      float tofwz    = ptofwz - tofwdz;
> 	      float tofwphi  = atan2(ptofwy,ptofwx) - tofwdphi;
1306c1097
< 	      //float beta     = pltofw/ttofw/phbeta; // unused for now
---
> 	      float beta     = pltofw/ttofw/phbeta;
1309c1100
< 	      //bool adc_beta  = qtofw>(20*((float)pow(beta,(float)-2.7))); // unused for now
---
> 	      bool adc_beta  = qtofw>(20*((float)pow(beta,(float)-2.7)));
1316,1342d1106
< 	      // --- EMC && RICH
< 
< 	      float emcz      = ktree->HadronTracks_emcz[itrk];
< 	      float emcphi    = ktree->HadronTracks_emcphi[itrk];
< 	      //emcphi = pi/2 - emcphi;
< 	      float emcsdz      = ktree->HadronTracks_emcsdz[itrk];
< 	      float emcsdphi    = ktree->HadronTracks_emcsdphi[itrk];
< 	      int warnmap       = ktree->HadronTracks_warnmap[itrk];
< 	      int deadmap       = ktree->HadronTracks_deadmap[itrk];
< 	      bool emc_matching = fabs(emcsdphi)<2.0 && fabs(emcsdz)<2.0;
< 	      float ecore = ktree->HadronTracks_ecore[itrk];
< 	      float ecent = ktree->HadronTracks_ecent[itrk];
< 	      float emce  = ktree->HadronTracks_emce[itrk];
< 	      //float ep = ecore/mom;
< 	      //float ep = ecent/mom; // how long has this been here?
< 	      float ep = ecore/pT; // NEW
< 	      bool goodemc = GoodEMC(emcz,emcphi);
< 	      //bool sysgoodemc = SysGoodEMC(emcz,emcphi); // unused for now
< 	      bool good_emc = emc_matching && goodemc && deadmap==0 && warnmap==0; // dead and warn redundant?
< 	      if(emc_matching&&deadmap==0&&warnmap==0) EMCZedPhiDis->Fill(emcz,emcphi);
< 	      if(emc_matching&&good_emc) EMCZedPhiNewDis->Fill(emcz,emcphi);
< 	      // COME BACK HERE!!!
< 	      //float n0 = ktree->HadronTracks_n0[itrk]; // GONE
< 	      //bool DeadMap = ((tofwphi>0.535&&tofwz<-113) || (tofwphi>0.453&&tofwphi<0.505 && tofwz>-102&&tofwz<-76));
< 
< 	      // ---
< 
1352d1115
< 	      // CUTS ARE DEFINTED HERE!
1360d1122
< 
1458a1221,1227
> 	      // already declared above...
> 	      // bool regular_cuts = tfw_matching && pc3_matching && good_pc1 && good_pc3 && good_adc;
> 	      // bool syst_tfwmatch = pc3_matching && good_pc1 && good_pc3 && good_adc;	
> 	      // bool syst_pc3match = tfw_matching && good_pc1 && good_pc3 && good_adc;
> 	      // bool syst_pc3fiducial = tfw_matching && pc3_matching && good_pc1 && good_adc;
> 	      // bool syst_pc1fiducial = tfw_matching && pc3_matching && good_pc3 && good_adc;
> 	      // bool syst_goodadc = tfw_matching && pc3_matching && good_pc1 && good_pc3;
1464,1466c1233,1235
< 	      float isPiANA = isPionANA(pT,m2tofw);
< 	      float isKANA  = isKaonANA(pT,m2tofw);
< 	      float isPANA  = isProtonANA(pT,m2tofw);
---
> 	      float isPiNew = isPionNew(pT,m2tofw);
> 	      float isKNew  = isKaonNew(pT,m2tofw);
> 	      float isPNew  = isProtonNew(pT,m2tofw);
1472,1485c1241,1243
< 	      float isPiLME = isPionLME(pT,m2tofw);
< 	      float isKLME  = isKaonLME(pT,m2tofw);
< 	      float isPLME  = isProtonLME(pT,m2tofw);
< 
< 	      float isPiPDI = isPionPDI(pT,m2tofw);// only one that's different
< 	      float isKPDI  = isKaonLME(pT,m2tofw);// LME
< 	      float isPPDI  = isProtonLME(pT,m2tofw);// LME
< 
< 	      //isPiLME /= 0.85; // SUPER TEMP
< 	      //isPiANA /= 0.85; // SUPER TEMP
< 
< 	      bool isPi = (isPiLME>=-2&&isPiLME<=2);
< 	      bool isK = (isKLME>=-2&&isKLME<=2);
< 	      bool isP = (isPLME>=-2&&isPLME<=2);
---
> 	      bool isPi = (isPiLow>=-2&&isPiLow<=2);
> 	      bool isK = (isKLow>=-2&&isKLow<=2);
> 	      bool isP = (isPLow>=-2&&isPLow<=2);
1496,1531c1254,1289
< 		  if(cent> 0&&cent<=10&&charge>0) isPi_dis_pos_cent0010->Fill(pT,isPiLME);//important
< 		  if(cent> 0&&cent<=10&&charge<0) isPi_dis_neg_cent0010->Fill(pT,isPiLME);//important
< 		  if(cent>10&&cent<=20&&charge>0) isPi_dis_pos_cent1020->Fill(pT,isPiLME);//important
< 		  if(cent>10&&cent<=20&&charge<0) isPi_dis_neg_cent1020->Fill(pT,isPiLME);//important
< 		  if(cent>20&&cent<=40&&charge>0) isPi_dis_pos_cent2040->Fill(pT,isPiLME);//important
< 		  if(cent>20&&cent<=40&&charge<0) isPi_dis_neg_cent2040->Fill(pT,isPiLME);//important
< 		  if(cent>40&&cent<=60&&charge>0) isPi_dis_pos_cent4060->Fill(pT,isPiLME);//important
< 		  if(cent>40&&cent<=60&&charge<0) isPi_dis_neg_cent4060->Fill(pT,isPiLME);//important
< 		  if(cent>60&&cent<=92&&charge>0) isPi_dis_pos_cent6092->Fill(pT,isPiLME);//important
< 		  if(cent>60&&cent<=92&&charge<0) isPi_dis_neg_cent6092->Fill(pT,isPiLME);//important
< 		  if(cent> 0&&cent<=10&&charge>0) isK_dis_pos_cent0010->Fill(pT,isKLME);//important
< 		  if(cent> 0&&cent<=10&&charge<0) isK_dis_neg_cent0010->Fill(pT,isKLME);//important
< 		  if(cent>10&&cent<=20&&charge>0) isK_dis_pos_cent1020->Fill(pT,isKLME);//important
< 		  if(cent>10&&cent<=20&&charge<0) isK_dis_neg_cent1020->Fill(pT,isKLME);//important
< 		  if(cent>20&&cent<=40&&charge>0) isK_dis_pos_cent2040->Fill(pT,isKLME);//important
< 		  if(cent>20&&cent<=40&&charge<0) isK_dis_neg_cent2040->Fill(pT,isKLME);//important
< 		  if(cent>40&&cent<=60&&charge>0) isK_dis_pos_cent4060->Fill(pT,isKLME);//important
< 		  if(cent>40&&cent<=60&&charge<0) isK_dis_neg_cent4060->Fill(pT,isKLME);//important
< 		  if(cent>60&&cent<=92&&charge>0) isK_dis_pos_cent6092->Fill(pT,isKLME);//important
< 		  if(cent>60&&cent<=92&&charge<0) isK_dis_neg_cent6092->Fill(pT,isKLME);//important
< 		  if(cent> 0&&cent<=10&&charge>0) isP_dis_pos_cent0010->Fill(pT,isPLME);//important
< 		  if(cent> 0&&cent<=10&&charge<0) isP_dis_neg_cent0010->Fill(pT,isPLME);//important
< 		  if(cent>10&&cent<=20&&charge>0) isP_dis_pos_cent1020->Fill(pT,isPLME);//important
< 		  if(cent>10&&cent<=20&&charge<0) isP_dis_neg_cent1020->Fill(pT,isPLME);//important
< 		  if(cent>20&&cent<=40&&charge>0) isP_dis_pos_cent2040->Fill(pT,isPLME);//important
< 		  if(cent>20&&cent<=40&&charge<0) isP_dis_neg_cent2040->Fill(pT,isPLME);//important
< 		  if(cent>40&&cent<=60&&charge>0) isP_dis_pos_cent4060->Fill(pT,isPLME);//important
< 		  if(cent>40&&cent<=60&&charge<0) isP_dis_neg_cent4060->Fill(pT,isPLME);//important
< 		  if(cent>60&&cent<=92&&charge>0) isP_dis_pos_cent6092->Fill(pT,isPLME);//important
< 		  if(cent>60&&cent<=92&&charge<0) isP_dis_neg_cent6092->Fill(pT,isPLME);//important
< 		  if(charge>0) isPi_dis_pos->Fill(pT,isPiLME);//important
< 		  if(charge<0) isPi_dis_neg->Fill(pT,isPiLME);//important
< 		  if(charge>0) isK_dis_pos->Fill(pT,isKLME);
< 		  if(charge<0) isK_dis_neg->Fill(pT,isKLME);
< 		  if(charge>0) isP_dis_pos->Fill(pT,isPLME);
< 		  if(charge<0) isP_dis_neg->Fill(pT,isPLME);
---
> 		  if(cent> 0&&cent<=10&&charge>0) isPi_dis_pos_cent0010->Fill(pT,isPiLow);//important
> 		  if(cent> 0&&cent<=10&&charge<0) isPi_dis_neg_cent0010->Fill(pT,isPiLow);//important
> 		  if(cent>10&&cent<=20&&charge>0) isPi_dis_pos_cent1020->Fill(pT,isPiLow);//important
> 		  if(cent>10&&cent<=20&&charge<0) isPi_dis_neg_cent1020->Fill(pT,isPiLow);//important
> 		  if(cent>20&&cent<=40&&charge>0) isPi_dis_pos_cent2040->Fill(pT,isPiLow);//important
> 		  if(cent>20&&cent<=40&&charge<0) isPi_dis_neg_cent2040->Fill(pT,isPiLow);//important
> 		  if(cent>40&&cent<=60&&charge>0) isPi_dis_pos_cent4060->Fill(pT,isPiLow);//important
> 		  if(cent>40&&cent<=60&&charge<0) isPi_dis_neg_cent4060->Fill(pT,isPiLow);//important
> 		  if(cent>60&&cent<=92&&charge>0) isPi_dis_pos_cent6092->Fill(pT,isPiLow);//important
> 		  if(cent>60&&cent<=92&&charge<0) isPi_dis_neg_cent6092->Fill(pT,isPiLow);//important
> 		  if(cent> 0&&cent<=10&&charge>0) isK_dis_pos_cent0010->Fill(pT,isKLow);//important
> 		  if(cent> 0&&cent<=10&&charge<0) isK_dis_neg_cent0010->Fill(pT,isKLow);//important
> 		  if(cent>10&&cent<=20&&charge>0) isK_dis_pos_cent1020->Fill(pT,isKLow);//important
> 		  if(cent>10&&cent<=20&&charge<0) isK_dis_neg_cent1020->Fill(pT,isKLow);//important
> 		  if(cent>20&&cent<=40&&charge>0) isK_dis_pos_cent2040->Fill(pT,isKLow);//important
> 		  if(cent>20&&cent<=40&&charge<0) isK_dis_neg_cent2040->Fill(pT,isKLow);//important
> 		  if(cent>40&&cent<=60&&charge>0) isK_dis_pos_cent4060->Fill(pT,isKLow);//important
> 		  if(cent>40&&cent<=60&&charge<0) isK_dis_neg_cent4060->Fill(pT,isKLow);//important
> 		  if(cent>60&&cent<=92&&charge>0) isK_dis_pos_cent6092->Fill(pT,isKLow);//important
> 		  if(cent>60&&cent<=92&&charge<0) isK_dis_neg_cent6092->Fill(pT,isKLow);//important
> 		  if(cent> 0&&cent<=10&&charge>0) isP_dis_pos_cent0010->Fill(pT,isPLow);//important
> 		  if(cent> 0&&cent<=10&&charge<0) isP_dis_neg_cent0010->Fill(pT,isPLow);//important
> 		  if(cent>10&&cent<=20&&charge>0) isP_dis_pos_cent1020->Fill(pT,isPLow);//important
> 		  if(cent>10&&cent<=20&&charge<0) isP_dis_neg_cent1020->Fill(pT,isPLow);//important
> 		  if(cent>20&&cent<=40&&charge>0) isP_dis_pos_cent2040->Fill(pT,isPLow);//important
> 		  if(cent>20&&cent<=40&&charge<0) isP_dis_neg_cent2040->Fill(pT,isPLow);//important
> 		  if(cent>40&&cent<=60&&charge>0) isP_dis_pos_cent4060->Fill(pT,isPLow);//important
> 		  if(cent>40&&cent<=60&&charge<0) isP_dis_neg_cent4060->Fill(pT,isPLow);//important
> 		  if(cent>60&&cent<=92&&charge>0) isP_dis_pos_cent6092->Fill(pT,isPLow);//important
> 		  if(cent>60&&cent<=92&&charge<0) isP_dis_neg_cent6092->Fill(pT,isPLow);//important
> 		  if(charge>0) isPi_dis_pos->Fill(pT,isPiLow);//important
> 		  if(charge<0) isPi_dis_neg->Fill(pT,isPiLow);//important
> 		  if(charge>0) isK_dis_pos->Fill(pT,isKLow);
> 		  if(charge<0) isK_dis_neg->Fill(pT,isKLow);
> 		  if(charge>0) isP_dis_pos->Fill(pT,isPLow);
> 		  if(charge<0) isP_dis_neg->Fill(pT,isPLow);
1544,1559d1301
< 		  // ep cut
< 		  if(ecore/pT>0.2)
< 		    {
< 		      if(charge>0) m2pTdis_epc_pos->Fill(pT,m2tofw);
< 		      if(charge<0) m2pTdis_epc_neg->Fill(pT,m2tofw);
< 		      if(charge>0&&ICENT==0) m2pTdis_epc_pos_cent0->Fill(pT,m2tofw);
< 		      if(charge<0&&ICENT==0) m2pTdis_epc_neg_cent0->Fill(pT,m2tofw);
< 		      if(charge>0&&ICENT==1) m2pTdis_epc_pos_cent1->Fill(pT,m2tofw);
< 		      if(charge<0&&ICENT==1) m2pTdis_epc_neg_cent1->Fill(pT,m2tofw);
< 		      if(charge>0&&ICENT==2) m2pTdis_epc_pos_cent2->Fill(pT,m2tofw);
< 		      if(charge<0&&ICENT==2) m2pTdis_epc_neg_cent2->Fill(pT,m2tofw);
< 		      if(charge>0&&ICENT==3) m2pTdis_epc_pos_cent3->Fill(pT,m2tofw);
< 		      if(charge<0&&ICENT==3) m2pTdis_epc_neg_cent3->Fill(pT,m2tofw);
< 		      if(charge>0&&ICENT==4) m2pTdis_epc_pos_cent4->Fill(pT,m2tofw);
< 		      if(charge<0&&ICENT==4) m2pTdis_epc_neg_cent4->Fill(pT,m2tofw);
< 		    }
1561a1304,1314
> 	      // --- EMC && RICH
> 
> 	      //float emcsdz      = ktree->HadronTracks_emcsdz[itrk];
> 	      //float emcsdphi    = ktree->HadronTracks_emcsdphi[itrk];
> 	      //bool emc_matching = fabs(emcsdphi)<2.0 && fabs(emcsdz)<2.0;
> 	      float ecore = ktree->HadronTracks_ecore[itrk];
> 	      //float ecent = ktree->HadronTracks_ecent[itrk];
> 	      float ep = ecore/mom;
> 	      float n0 = ktree->HadronTracks_n0[itrk];
> 	      bool DeadMap = ((tofwphi>0.535&&tofwz<-113) ||
> 			       (tofwphi>0.453&&tofwphi<0.505 && tofwz>-102&&tofwz<-76));
1582,1585c1335,1338
< 	      // bool dis0 = isPiLME>=-2 && isPiLME<=2 && isKLME<=-2 && good_emc;
< 	      // bool dis1 = isPiANA>=-2 && isPiANA<=2 && isKANA<=-2 && good_emc;
< 	      // bool dis2 = dis0 && ep>0.2;
< 	      // bool dis3 = dis1 && ep>0.2;
---
> 	      // bool dis0 = isPiLow>=-2 && isPiLow<=2 && isKLow<=-2;
> 	      // bool dis1 = isPiNew>=-2 && isPiNew<=2 && isKNew<=-2;
> 	      // bool dis2 = isPiLow>=-2 && isPiLow<=2;
> 	      // bool dis3 = isPiNew>=-2 && isPiNew<=2;
1587,1588c1340,1341
< 	      // bool dis4 = isKLME>=-2 && isKLME<=2 && isPiLME>=2 && isPLME<=-2;
< 	      // bool dis5 = isKANA>=-2 && isKANA<=2 && isPiANA>=2 && isPANA<=-2;
---
> 	      // bool dis4 = isKLow>=-2 && isKLow<=2 && isPiLow>=2 && isPLow<=-2;
> 	      // bool dis5 = isKNew>=-2 && isKNew<=2 && isPiNew>=2 && isPNew<=-2;
1590,1593c1343,1346
< 	      // bool dis6 = isPLME>=-2 && isPLME<=2 && isKLME>=2 && good_emc;
< 	      // bool dis7 = isPANA>=-2 && isPANA<=2 && isKANA>=2 && good_emc;
< 	      // bool dis8 = dis6 && ep>0.2;
< 	      // bool dis9 = dis7 && ep>0.2;
---
> 	      // bool dis6 = isPLow>=-2 && isPLow<=2 && isKLow>=2;
> 	      // bool dis7 = isPNew>=-2 && isPNew<=2 && isKNew>=2;
> 	      // bool dis8 = isPLow>=-2 && isPLow<=2;
> 	      // bool dis9 = isPNew>=-2 && isPNew<=2;
1596,1599c1349,1354
< 	      bool dis0 = isPiLME>=-2 && isPiLME<=2 && isKLME<=-2;
< 	      bool dis1 = isPiLow>=-2 && isPiLow<=2 && isKLow<=-2;
< 	      bool dis2 = dis0 && good_emc && ep>0.2;
< 	      bool dis3 = dis1 && good_emc && ep>0.2;
---
> 	      bool dis0 = isPiLow>=-2 && isPiLow<=2 && isKLow<=-2;
> 	      bool dis1 = isPiLow>=-2 && isPiLow<=2 && isKLow<=-2 && ep>0.2 && !DeadMap;
> 	      //bool dis2 = isPiLow>=-2 && isPiLow<=2 && isKLow<=-2 && ep>0.2 && n0<0;
> 	      //bool dis3 = isPiLow>=-2 && isPiLow<=2 && ep>0.2;
> 	      bool dis2 = isPiLow>=-2 && isPiLow<=2;
> 	      bool dis3 = isPiLow>=-2 && isPiLow<=2 && ep>0.2 && !DeadMap;
1601,1602c1356,1357
< 	      bool dis4 = isKLME>=-2 && isKLME<=2 && isPiLME>=2 && isPLME<=-2;
< 	      bool dis5 = isKLow>=-2 && isKLow<=2 && isPiLow>=2 && isPLow<=-2;
---
> 	      bool dis4 = isKLow>=-2 && isKLow<=2 && isPiLow>=2 && isPLow<=-2;
> 	      bool dis5 = isKLow>=-2 && isKLow<=2 && isPiLow>=2 && isPLow<=-2 && ep>0.2 && !DeadMap;
1604,1788c1359,1383
< 	      bool dis6 = isPLME>=-2 && isPLME<=2 && isKLME>=2;
< 	      bool dis7 = isPLow>=-2 && isPLow<=2 && isKLow>=2;
< 	      bool dis8 = dis6 && good_emc && ep>0.2;
< 	      bool dis9 = dis7 && good_emc && ep>0.2;
< 
< 	      // Shengli
< 
< 	      //pion
< 	      if(charge>0&&dis0) hh_X_ecorept_pospion_centMB->Fill(pT,ecore); // new
< 	      if(charge<0&&dis0) hh_X_ecorept_negpion_centMB->Fill(pT,ecore); // new
< 	      if(cent> 0&&cent<=10&&charge>0&&dis0) hh_X_ecorept_pospion_cent0010->Fill(pT,ecore); // new
< 	      if(cent> 0&&cent<=10&&charge<0&&dis0) hh_X_ecorept_negpion_cent0010->Fill(pT,ecore); // new
< 	      if(cent>10&&cent<=20&&charge>0&&dis0) hh_X_ecorept_pospion_cent1020->Fill(pT,ecore); // new
< 	      if(cent>10&&cent<=20&&charge<0&&dis0) hh_X_ecorept_negpion_cent1020->Fill(pT,ecore); // new
< 	      if(cent>20&&cent<=40&&charge>0&&dis0) hh_X_ecorept_pospion_cent2040->Fill(pT,ecore); // new
< 	      if(cent>20&&cent<=40&&charge<0&&dis0) hh_X_ecorept_negpion_cent2040->Fill(pT,ecore); // new
< 	      if(cent>40&&cent<=60&&charge>0&&dis0) hh_X_ecorept_pospion_cent4060->Fill(pT,ecore); // new
< 	      if(cent>40&&cent<=60&&charge<0&&dis0) hh_X_ecorept_negpion_cent4060->Fill(pT,ecore); // new
< 	      if(cent>60&&cent<=92&&charge>0&&dis0) hh_X_ecorept_pospion_cent6092->Fill(pT,ecore); // new
< 	      if(cent>60&&cent<=92&&charge<0&&dis0) hh_X_ecorept_negpion_cent6092->Fill(pT,ecore); // new
< 	      //
< 	      if(charge>0&&dis0) hh_X_spectpt_pospion_centMB->Fill(pT);
< 	      if(charge<0&&dis0) hh_X_spectpt_negpion_centMB->Fill(pT);
< 	      if(cent> 0&&cent<=10&&charge>0&&dis0) hh_X_spectpt_pospion_cent0010->Fill(pT);
< 	      if(cent> 0&&cent<=10&&charge<0&&dis0) hh_X_spectpt_negpion_cent0010->Fill(pT);
< 	      if(cent>10&&cent<=20&&charge>0&&dis0) hh_X_spectpt_pospion_cent1020->Fill(pT);
< 	      if(cent>10&&cent<=20&&charge<0&&dis0) hh_X_spectpt_negpion_cent1020->Fill(pT);
< 	      if(cent>20&&cent<=40&&charge>0&&dis0) hh_X_spectpt_pospion_cent2040->Fill(pT);
< 	      if(cent>20&&cent<=40&&charge<0&&dis0) hh_X_spectpt_negpion_cent2040->Fill(pT);
< 	      if(cent>40&&cent<=60&&charge>0&&dis0) hh_X_spectpt_pospion_cent4060->Fill(pT);
< 	      if(cent>40&&cent<=60&&charge<0&&dis0) hh_X_spectpt_negpion_cent4060->Fill(pT);
< 	      if(cent>60&&cent<=92&&charge>0&&dis0) hh_X_spectpt_pospion_cent6092->Fill(pT);
< 	      if(cent>60&&cent<=92&&charge<0&&dis0) hh_X_spectpt_negpion_cent6092->Fill(pT);
< 	      //
< 	      if(charge>0&&dis0&&ecore/pT>0.2) hh_X_specept_pospion_centMB->Fill(pT);
< 	      if(charge<0&&dis0&&ecore/pT>0.2) hh_X_specept_negpion_centMB->Fill(pT);
< 	      if(cent> 0&&cent<=10&&charge>0&&dis0&&ecore/pT>0.2) hh_X_specept_pospion_cent0010->Fill(pT);
< 	      if(cent> 0&&cent<=10&&charge<0&&dis0&&ecore/pT>0.2) hh_X_specept_negpion_cent0010->Fill(pT);
< 	      if(cent>10&&cent<=20&&charge>0&&dis0&&ecore/pT>0.2) hh_X_specept_pospion_cent1020->Fill(pT);
< 	      if(cent>10&&cent<=20&&charge<0&&dis0&&ecore/pT>0.2) hh_X_specept_negpion_cent1020->Fill(pT);
< 	      if(cent>20&&cent<=40&&charge>0&&dis0&&ecore/pT>0.2) hh_X_specept_pospion_cent2040->Fill(pT);
< 	      if(cent>20&&cent<=40&&charge<0&&dis0&&ecore/pT>0.2) hh_X_specept_negpion_cent2040->Fill(pT);
< 	      if(cent>40&&cent<=60&&charge>0&&dis0&&ecore/pT>0.2) hh_X_specept_pospion_cent4060->Fill(pT);
< 	      if(cent>40&&cent<=60&&charge<0&&dis0&&ecore/pT>0.2) hh_X_specept_negpion_cent4060->Fill(pT);
< 	      if(cent>60&&cent<=92&&charge>0&&dis0&&ecore/pT>0.2) hh_X_specept_pospion_cent6092->Fill(pT);
< 	      if(cent>60&&cent<=92&&charge<0&&dis0&&ecore/pT>0.2) hh_X_specept_negpion_cent6092->Fill(pT);
< 
< 	      //proton
< 	      if(charge>0&&dis6) hh_X_ecorept_posproton_centMB->Fill(pT,ecore); // new
< 	      if(charge<0&&dis6) hh_X_ecorept_negproton_centMB->Fill(pT,ecore); // new
< 	      if(cent> 0&&cent<=10&&charge>0&&dis6) hh_X_ecorept_posproton_cent0010->Fill(pT,ecore); // new
< 	      if(cent> 0&&cent<=10&&charge<0&&dis6) hh_X_ecorept_negproton_cent0010->Fill(pT,ecore); // new
< 	      if(cent>10&&cent<=20&&charge>0&&dis6) hh_X_ecorept_posproton_cent1020->Fill(pT,ecore); // new
< 	      if(cent>10&&cent<=20&&charge<0&&dis6) hh_X_ecorept_negproton_cent1020->Fill(pT,ecore); // new
< 	      if(cent>20&&cent<=40&&charge>0&&dis6) hh_X_ecorept_posproton_cent2040->Fill(pT,ecore); // new
< 	      if(cent>20&&cent<=40&&charge<0&&dis6) hh_X_ecorept_negproton_cent2040->Fill(pT,ecore); // new
< 	      if(cent>40&&cent<=60&&charge>0&&dis6) hh_X_ecorept_posproton_cent4060->Fill(pT,ecore); // new
< 	      if(cent>40&&cent<=60&&charge<0&&dis6) hh_X_ecorept_negproton_cent4060->Fill(pT,ecore); // new
< 	      if(cent>60&&cent<=92&&charge>0&&dis6) hh_X_ecorept_posproton_cent6092->Fill(pT,ecore); // new
< 	      if(cent>60&&cent<=92&&charge<0&&dis6) hh_X_ecorept_negproton_cent6092->Fill(pT,ecore); // new
< 	      //
< 	      if(charge>0&&dis6) hh_X_spectpt_posproton_centMB->Fill(pT);
< 	      if(charge<0&&dis6) hh_X_spectpt_negproton_centMB->Fill(pT);
< 	      if(cent> 0&&cent<=10&&charge>0&&dis6) hh_X_spectpt_posproton_cent0010->Fill(pT);
< 	      if(cent> 0&&cent<=10&&charge<0&&dis6) hh_X_spectpt_negproton_cent0010->Fill(pT);
< 	      if(cent>10&&cent<=20&&charge>0&&dis6) hh_X_spectpt_posproton_cent1020->Fill(pT);
< 	      if(cent>10&&cent<=20&&charge<0&&dis6) hh_X_spectpt_negproton_cent1020->Fill(pT);
< 	      if(cent>20&&cent<=40&&charge>0&&dis6) hh_X_spectpt_posproton_cent2040->Fill(pT);
< 	      if(cent>20&&cent<=40&&charge<0&&dis6) hh_X_spectpt_negproton_cent2040->Fill(pT);
< 	      if(cent>40&&cent<=60&&charge>0&&dis6) hh_X_spectpt_posproton_cent4060->Fill(pT);
< 	      if(cent>40&&cent<=60&&charge<0&&dis6) hh_X_spectpt_negproton_cent4060->Fill(pT);
< 	      if(cent>60&&cent<=92&&charge>0&&dis6) hh_X_spectpt_posproton_cent6092->Fill(pT);
< 	      if(cent>60&&cent<=92&&charge<0&&dis6) hh_X_spectpt_negproton_cent6092->Fill(pT);
< 	      //
< 	      if(charge>0&&dis6&&ecore/pT>0.2) hh_X_specept_posproton_centMB->Fill(pT);
< 	      if(charge<0&&dis6&&ecore/pT>0.2) hh_X_specept_negproton_centMB->Fill(pT);
< 	      if(cent> 0&&cent<=10&&charge>0&&dis6&&ecore/pT>0.2) hh_X_specept_posproton_cent0010->Fill(pT);
< 	      if(cent> 0&&cent<=10&&charge<0&&dis6&&ecore/pT>0.2) hh_X_specept_negproton_cent0010->Fill(pT);
< 	      if(cent>10&&cent<=20&&charge>0&&dis6&&ecore/pT>0.2) hh_X_specept_posproton_cent1020->Fill(pT);
< 	      if(cent>10&&cent<=20&&charge<0&&dis6&&ecore/pT>0.2) hh_X_specept_negproton_cent1020->Fill(pT);
< 	      if(cent>20&&cent<=40&&charge>0&&dis6&&ecore/pT>0.2) hh_X_specept_posproton_cent2040->Fill(pT);
< 	      if(cent>20&&cent<=40&&charge<0&&dis6&&ecore/pT>0.2) hh_X_specept_negproton_cent2040->Fill(pT);
< 	      if(cent>40&&cent<=60&&charge>0&&dis6&&ecore/pT>0.2) hh_X_specept_posproton_cent4060->Fill(pT);
< 	      if(cent>40&&cent<=60&&charge<0&&dis6&&ecore/pT>0.2) hh_X_specept_negproton_cent4060->Fill(pT);
< 	      if(cent>60&&cent<=92&&charge>0&&dis6&&ecore/pT>0.2) hh_X_specept_posproton_cent6092->Fill(pT);
< 	      if(cent>60&&cent<=92&&charge<0&&dis6&&ecore/pT>0.2) hh_X_specept_negproton_cent6092->Fill(pT);
< 
< 	      // --- now do the same thing with all cuts
< 	      if(regular_cuts&&edge&&inner) // ok
< 		{
< 		  //pion
< 		  if(charge>0&&dis0) hh_Y_ecorept_pospion_centMB->Fill(pT,ecore); // new
< 		  if(charge<0&&dis0) hh_Y_ecorept_negpion_centMB->Fill(pT,ecore); // new
< 		  if(cent> 0&&cent<=10&&charge>0&&dis0) hh_Y_ecorept_pospion_cent0010->Fill(pT,ecore); // new
< 		  if(cent> 0&&cent<=10&&charge<0&&dis0) hh_Y_ecorept_negpion_cent0010->Fill(pT,ecore); // new
< 		  if(cent>10&&cent<=20&&charge>0&&dis0) hh_Y_ecorept_pospion_cent1020->Fill(pT,ecore); // new
< 		  if(cent>10&&cent<=20&&charge<0&&dis0) hh_Y_ecorept_negpion_cent1020->Fill(pT,ecore); // new
< 		  if(cent>20&&cent<=40&&charge>0&&dis0) hh_Y_ecorept_pospion_cent2040->Fill(pT,ecore); // new
< 		  if(cent>20&&cent<=40&&charge<0&&dis0) hh_Y_ecorept_negpion_cent2040->Fill(pT,ecore); // new
< 		  if(cent>40&&cent<=60&&charge>0&&dis0) hh_Y_ecorept_pospion_cent4060->Fill(pT,ecore); // new
< 		  if(cent>40&&cent<=60&&charge<0&&dis0) hh_Y_ecorept_negpion_cent4060->Fill(pT,ecore); // new
< 		  if(cent>60&&cent<=92&&charge>0&&dis0) hh_Y_ecorept_pospion_cent6092->Fill(pT,ecore); // new
< 		  if(cent>60&&cent<=92&&charge<0&&dis0) hh_Y_ecorept_negpion_cent6092->Fill(pT,ecore); // new
< 		  //
< 		  if(charge>0&&dis0) hh_Y_spectpt_pospion_centMB->Fill(pT);
< 		  if(charge<0&&dis0) hh_Y_spectpt_negpion_centMB->Fill(pT);
< 		  if(cent> 0&&cent<=10&&charge>0&&dis0) hh_Y_spectpt_pospion_cent0010->Fill(pT);
< 		  if(cent> 0&&cent<=10&&charge<0&&dis0) hh_Y_spectpt_negpion_cent0010->Fill(pT);
< 		  if(cent>10&&cent<=20&&charge>0&&dis0) hh_Y_spectpt_pospion_cent1020->Fill(pT);
< 		  if(cent>10&&cent<=20&&charge<0&&dis0) hh_Y_spectpt_negpion_cent1020->Fill(pT);
< 		  if(cent>20&&cent<=40&&charge>0&&dis0) hh_Y_spectpt_pospion_cent2040->Fill(pT);
< 		  if(cent>20&&cent<=40&&charge<0&&dis0) hh_Y_spectpt_negpion_cent2040->Fill(pT);
< 		  if(cent>40&&cent<=60&&charge>0&&dis0) hh_Y_spectpt_pospion_cent4060->Fill(pT);
< 		  if(cent>40&&cent<=60&&charge<0&&dis0) hh_Y_spectpt_negpion_cent4060->Fill(pT);
< 		  if(cent>60&&cent<=92&&charge>0&&dis0) hh_Y_spectpt_pospion_cent6092->Fill(pT);
< 		  if(cent>60&&cent<=92&&charge<0&&dis0) hh_Y_spectpt_negpion_cent6092->Fill(pT);
< 		  //
< 		  if(charge>0&&dis0&&ecore/pT>0.2) hh_Y_specept_pospion_centMB->Fill(pT);
< 		  if(charge<0&&dis0&&ecore/pT>0.2) hh_Y_specept_negpion_centMB->Fill(pT);
< 		  if(cent> 0&&cent<=10&&charge>0&&dis0&&ecore/pT>0.2) hh_Y_specept_pospion_cent0010->Fill(pT);
< 		  if(cent> 0&&cent<=10&&charge<0&&dis0&&ecore/pT>0.2) hh_Y_specept_negpion_cent0010->Fill(pT);
< 		  if(cent>10&&cent<=20&&charge>0&&dis0&&ecore/pT>0.2) hh_Y_specept_pospion_cent1020->Fill(pT);
< 		  if(cent>10&&cent<=20&&charge<0&&dis0&&ecore/pT>0.2) hh_Y_specept_negpion_cent1020->Fill(pT);
< 		  if(cent>20&&cent<=40&&charge>0&&dis0&&ecore/pT>0.2) hh_Y_specept_pospion_cent2040->Fill(pT);
< 		  if(cent>20&&cent<=40&&charge<0&&dis0&&ecore/pT>0.2) hh_Y_specept_negpion_cent2040->Fill(pT);
< 		  if(cent>40&&cent<=60&&charge>0&&dis0&&ecore/pT>0.2) hh_Y_specept_pospion_cent4060->Fill(pT);
< 		  if(cent>40&&cent<=60&&charge<0&&dis0&&ecore/pT>0.2) hh_Y_specept_negpion_cent4060->Fill(pT);
< 		  if(cent>60&&cent<=92&&charge>0&&dis0&&ecore/pT>0.2) hh_Y_specept_pospion_cent6092->Fill(pT);
< 		  if(cent>60&&cent<=92&&charge<0&&dis0&&ecore/pT>0.2) hh_Y_specept_negpion_cent6092->Fill(pT);
< 		  //proton
< 		  if(charge>0&&dis6) hh_Y_ecorept_posproton_centMB->Fill(pT,ecore); // new
< 		  if(charge<0&&dis6) hh_Y_ecorept_negproton_centMB->Fill(pT,ecore); // new
< 		  if(cent> 0&&cent<=10&&charge>0&&dis6) hh_Y_ecorept_posproton_cent0010->Fill(pT,ecore); // new
< 		  if(cent> 0&&cent<=10&&charge<0&&dis6) hh_Y_ecorept_negproton_cent0010->Fill(pT,ecore); // new
< 		  if(cent>10&&cent<=20&&charge>0&&dis6) hh_Y_ecorept_posproton_cent1020->Fill(pT,ecore); // new
< 		  if(cent>10&&cent<=20&&charge<0&&dis6) hh_Y_ecorept_negproton_cent1020->Fill(pT,ecore); // new
< 		  if(cent>20&&cent<=40&&charge>0&&dis6) hh_Y_ecorept_posproton_cent2040->Fill(pT,ecore); // new
< 		  if(cent>20&&cent<=40&&charge<0&&dis6) hh_Y_ecorept_negproton_cent2040->Fill(pT,ecore); // new
< 		  if(cent>40&&cent<=60&&charge>0&&dis6) hh_Y_ecorept_posproton_cent4060->Fill(pT,ecore); // new
< 		  if(cent>40&&cent<=60&&charge<0&&dis6) hh_Y_ecorept_negproton_cent4060->Fill(pT,ecore); // new
< 		  if(cent>60&&cent<=92&&charge>0&&dis6) hh_Y_ecorept_posproton_cent6092->Fill(pT,ecore); // new
< 		  if(cent>60&&cent<=92&&charge<0&&dis6) hh_Y_ecorept_negproton_cent6092->Fill(pT,ecore); // new
< 		  //
< 		  if(charge>0&&dis6) hh_Y_spectpt_posproton_centMB->Fill(pT);
< 		  if(charge<0&&dis6) hh_Y_spectpt_negproton_centMB->Fill(pT);
< 		  if(cent> 0&&cent<=10&&charge>0&&dis6) hh_Y_spectpt_posproton_cent0010->Fill(pT);
< 		  if(cent> 0&&cent<=10&&charge<0&&dis6) hh_Y_spectpt_negproton_cent0010->Fill(pT);
< 		  if(cent>10&&cent<=20&&charge>0&&dis6) hh_Y_spectpt_posproton_cent1020->Fill(pT);
< 		  if(cent>10&&cent<=20&&charge<0&&dis6) hh_Y_spectpt_negproton_cent1020->Fill(pT);
< 		  if(cent>20&&cent<=40&&charge>0&&dis6) hh_Y_spectpt_posproton_cent2040->Fill(pT);
< 		  if(cent>20&&cent<=40&&charge<0&&dis6) hh_Y_spectpt_negproton_cent2040->Fill(pT);
< 		  if(cent>40&&cent<=60&&charge>0&&dis6) hh_Y_spectpt_posproton_cent4060->Fill(pT);
< 		  if(cent>40&&cent<=60&&charge<0&&dis6) hh_Y_spectpt_negproton_cent4060->Fill(pT);
< 		  if(cent>60&&cent<=92&&charge>0&&dis6) hh_Y_spectpt_posproton_cent6092->Fill(pT);
< 		  if(cent>60&&cent<=92&&charge<0&&dis6) hh_Y_spectpt_negproton_cent6092->Fill(pT);
< 		  //
< 		  if(charge>0&&dis6&&ecore/pT>0.2) hh_Y_specept_posproton_centMB->Fill(pT);
< 		  if(charge<0&&dis6&&ecore/pT>0.2) hh_Y_specept_negproton_centMB->Fill(pT);
< 		  if(cent> 0&&cent<=10&&charge>0&&dis6&&ecore/pT>0.2) hh_Y_specept_posproton_cent0010->Fill(pT);
< 		  if(cent> 0&&cent<=10&&charge<0&&dis6&&ecore/pT>0.2) hh_Y_specept_negproton_cent0010->Fill(pT);
< 		  if(cent>10&&cent<=20&&charge>0&&dis6&&ecore/pT>0.2) hh_Y_specept_posproton_cent1020->Fill(pT);
< 		  if(cent>10&&cent<=20&&charge<0&&dis6&&ecore/pT>0.2) hh_Y_specept_negproton_cent1020->Fill(pT);
< 		  if(cent>20&&cent<=40&&charge>0&&dis6&&ecore/pT>0.2) hh_Y_specept_posproton_cent2040->Fill(pT);
< 		  if(cent>20&&cent<=40&&charge<0&&dis6&&ecore/pT>0.2) hh_Y_specept_negproton_cent2040->Fill(pT);
< 		  if(cent>40&&cent<=60&&charge>0&&dis6&&ecore/pT>0.2) hh_Y_specept_posproton_cent4060->Fill(pT);
< 		  if(cent>40&&cent<=60&&charge<0&&dis6&&ecore/pT>0.2) hh_Y_specept_negproton_cent4060->Fill(pT);
< 		  if(cent>60&&cent<=92&&charge>0&&dis6&&ecore/pT>0.2) hh_Y_specept_posproton_cent6092->Fill(pT);
< 		  if(cent>60&&cent<=92&&charge<0&&dis6&&ecore/pT>0.2) hh_Y_specept_negproton_cent6092->Fill(pT);
< 		}
< 	      
< 	      
< 	      bool piA = isPiLME>=-1.5 && isPiLME<=1.5 && isKLME<=-2;
< 	      bool kaA = isKLME>=-1.5 && isKLME<=1.5 && isPiLME>=2 && isPLME<=-2;
< 	      bool prA = isPLME>=-1.5 && isPLME<=1.5 && isKLME>=2;
< 	      bool piB = isPiLME>=-2 && isPiLME<=2 && isKLME<=-2.5;
< 	      bool kaB = isKLME>=-2 && isKLME<=2 && isPiLME>=2.5 && isPLME<=-2.5;
< 	      bool prB = isPLME>=-2 && isPLME<=2 && isKLME>=2.5;
< 
< 	      // bool piA = isPiLME>=-3 && isPiLME<=3 && isKLME<=-3;
< 	      // bool kaA = isKLME>=-3 && isKLME<=3 && isPiLME>=3 && isPLME<=-3;
< 	      // bool prA = isPLME>=-3 && isPLME<=3 && isKLME>=3;
< 	      // bool piB = isPiLME>=-1 && isPiLME<=1 && isKLME<=-1;
< 	      // bool kaB = isKLME>=-1 && isKLME<=1 && isPiLME>=1 && isPLME<=-1;
< 	      // bool prB = isPLME>=-1 && isPLME<=1 && isKLME>=1;
< 
---
> 	      bool dis6 = isPLow>=-2 && isPLow<=2 && isKLow>=2;
> 	      bool dis7 = isPLow>=-2 && isPLow<=2 && isKLow>=2 && ep>0.2 && !DeadMap;
> 	      bool dis8 = isPLow>=-2 && isPLow<=2;
> 	      bool dis9 = isPLow>=-2 && isPLow<=2 && ep>0.2 && !DeadMap;
> 
> 	      bool piA = isPiLow>=-1.5 && isPiLow<=1.5 && isKLow<=-2;
> 	      bool kaA = isKLow>=-1.5 && isKLow<=1.5 && isPiLow>=2 && isPLow<=-2;
> 	      bool prA = isPLow>=-1.5 && isPLow<=1.5 && isKLow>=2;
> 	      bool piB = isPiLow>=-2 && isPiLow<=2 && isKLow<=-2.5;
> 	      bool kaB = isKLow>=-2 && isKLow<=2 && isPiLow>=2.5 && isPLow<=-2.5;
> 	      bool prB = isPLow>=-2 && isPLow<=2 && isKLow>=2.5;
> 
> 	      // bool piA = isPiLow>=-3 && isPiLow<=3 && isKLow<=-3;
> 	      // bool kaA = isKLow>=-3 && isKLow<=3 && isPiLow>=3 && isPLow<=-3;
> 	      // bool prA = isPLow>=-3 && isPLow<=3 && isKLow>=3;
> 	      // bool piB = isPiLow>=-1 && isPiLow<=1 && isKLow<=-1;
> 	      // bool kaB = isKLow>=-1 && isKLow<=1 && isPiLow>=1 && isPLow<=-1;
> 	      // bool prB = isPLow>=-1 && isPLow<=1 && isKLow>=1;
> 
> 	      // bool regular_cuts = tfw_matching && pc3_matching && good_pc1 && good_pc3 && good_adc;
> 	      // bool syst_tfwmatch = pc3_matching && good_pc1 && good_pc3 && good_adc;	
> 	      // bool syst_pc3match = tfw_matching && good_pc1 && good_pc3 && good_adc;
> 	      // bool syst_pc3fiducial = tfw_matching && pc3_matching && good_pc1 && good_adc;
> 	      // bool syst_pc1fiducial = tfw_matching && pc3_matching && good_pc3 && good_adc;
> 	      // bool syst_goodadc = tfw_matching && pc3_matching && good_pc1 && good_pc3;
1800,1861d1394
< 	      // ------------------------------------------ //
< 	      // --- new pid experimentation histograms --- //
< 	      // ------------------------------------------ //
< 	      
< 	      // pions
< 	      bool distofwpion0 = isPiLME>=-2 && isPiLME<=2 && isKLME<=-2 ;
< 	      bool distofwpion1 = isPiLME>=-2 && isPiLME<=0 ;
< 	      bool distofwpion2 = isPiLow>=-2 && isPiLow<=0 ;
< 	      bool distofwpion3 = isPiPDI>=-2 && isPiPDI<=2 && isKPDI<=-2 ; // real only (LME in sim)
< 	      bool distofwpion4 = isPiPDI>=-2 && isPiPDI<=2 && isKPDI<=-2 ; // sim and real
< 	      bool distofwpion5 = isPiLME>=-2 && isPiLME<=2 ;
< 	      //kaons
< 	      bool distofwkaon0 = isKLME>=-2 && isKLME<=2 && isPiLME>=2 && isPLME<=-2 ;
< 	      bool distofwkaon1 = isKLow>=-2 && isKLow<=2 && isPiLow>=2 && isPLow<=-2 ;
< 	      bool distofwkaon2 = isKANA>=-2 && isKANA<=2 && isPiANA>=2 && isPANA<=-2 ;
< 	      bool distofwkaon3 = isKPDI>=-2 && isKPDI<=2 && isPiPDI>=2 && isPPDI<=-2 ; // real only (LME in sim)
< 	      bool distofwkaon4 = isKPDI>=-2 && isKPDI<=2 && isPiPDI>=2 && isPPDI<=-2 ; // sim and real
< 	      bool distofwkaon5 = isKLow>=-2 && isKLow<=2 ;
< 	      // protons
< 	      bool distofwproton0 = isPLME>=-2 && isPLME<=2 && isKLME>=2 ;
< 	      bool distofwproton1 = isPLME>= 0 && isPLME<=2 ;
< 	      bool distofwproton2 = isPLow>= 0 && isPLow<=2 ;
< 	      bool distofwproton3 = isPPDI>=-2 && isPPDI<=2 && isKPDI>=2 ; // real only (LME in sim)
< 	      bool distofwproton4 = isPPDI>=-2 && isPPDI<=2 && isKPDI>=2 ; // sim and real
< 	      bool distofwproton5 = isPLow>=-2 && isPLow<=2 ;
< 
< 	      // emc stuff
< 	      bool tfecpion = isPiLME>=-2 && isPiLME<=2 && isKLME<=-2 && good_emc;
< 	      bool tfeckaon = isKLME>=-2 && isKLME<=2 && isPiLME>=2 && isPLME<=-2 && good_emc;
< 	      bool tfecproton = isPLME>=-2 && isPLME<=2 && isKLME>=2 && good_emc;
< 	      bool distfec1 = ecore/pT>0.2;                    
< 	      bool distfec2 = ecore>0.3;
< 	      bool distfec3 = ecore>0.5;
< 	      bool distfec4 = ecore>1.0;                       
< 	      bool distfec5 = ecent/ecore<0.55; // compactness cut, see e.g. AN330
< 	      //pions
< 	      bool distfecpion0 = tfecpion;
< 	      bool distfecpion1 = tfecpion && distfec1;
< 	      bool distfecpion2 = tfecpion && distfec2;
< 	      bool distfecpion3 = tfecpion && distfec3;
< 	      bool distfecpion4 = tfecpion && distfec4;
< 	      bool distfecpion5 = tfecpion && distfec5;
< 	      //kaons
< 	      bool distfeckaon0 = tfeckaon;            
< 	      bool distfeckaon1 = tfeckaon && distfec1;
< 	      bool distfeckaon2 = tfeckaon && distfec2;
< 	      bool distfeckaon3 = tfeckaon && distfec3;
< 	      bool distfeckaon4 = tfeckaon && distfec4;
< 	      bool distfeckaon5 = tfeckaon && distfec5;
< 	      // protons
< 	      bool distfecproton0 = tfecproton;            
< 	      bool distfecproton1 = tfecproton && distfec1;
< 	      bool distfecproton2 = tfecproton && distfec2;
< 	      bool distfecproton3 = tfecproton && distfec3;
< 	      bool distfecproton4 = tfecproton && distfec4;
< 	      bool distfecproton5 = tfecproton && distfec5;
< 
< 
< 	      // --------------------------------------- //
< 	      // --- end experimental pid histograms --- //
< 	      // --------------------------------------- //
< 
2283,2285d1815
< 
< 
< 
2351c1881
< float isPionANA(float x, float m2tofw)
---
> float isPionNew(float x, float m2tofw)
2379c1909
< float isKaonANA(float x, float m2tofw)
---
> float isKaonNew(float x, float m2tofw)
2407c1937
< float isProtonANA(float x, float m2tofw)
---
> float isProtonNew(float x, float m2tofw)
2434c1964
< float isPionLME(float x, float m2tofw)
---
> float isPionLow(float x, float m2tofw)
2468c1998
< float isKaonLME(float x, float m2tofw)
---
> float isKaonLow(float x, float m2tofw)
2486c2016
< float isProtonLME(float x, float m2tofw)
---
> float isProtonLow(float x, float m2tofw)
2511,2630d2040
< 
< 
< 
< 
< 
< 
< float isPionLow(float x, float m2tofw)
< {
< 
<   // this mean is more radical
<   // consider going with less radical
<   // float a0 = 0.0123786;
<   // float a1 = 0.00293974;
<   // float a2 = -0.000321866;
<   // float a3 = -0.0110238;
<   // float a4 = 0.0352101;
<   // float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);
< 
<   float mean = mpion*mpion;
< 
<   // based on simulation
<   // new
<   float  p0   =       -2.32986e-02;
<   float  p1   =       -1.30028e-03;
<   float  p2   =       -8.26991e-06;
<   float  p3   =        5.56826e-02;
<   float  p4   =       -1.16173e-01;
<   float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
<   // new
<   // float  p0   =       -4.32359e-02;
<   // float  p1   =        6.44942e-03;
<   // float  p2   =       -8.09058e-04;
<   // float  p3   =        3.91918e-02;
<   // float  p4   =       -5.68094e-02;
<   // float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
<   
<   return (m2tofw - mean)/sigma;
< 
< }
< 
< 
< 
< float isKaonLow(float x, float m2tofw)
< {
<   
<   float  p0   =        1.17930e-02;
<   float  p1   =       -1.54666e-02;
<   float  p2   =        2.48918e-03;
<   float  p3   =        6.50247e-02;
<   float  p4   =       -1.61286e-01;
<   float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
< 
<   float mean = mkaon*mkaon; // mean is very stable
< 
<   return (m2tofw - mean)/sigma;
< 
< }
< 
< 
< 
< float isProtonLow(float x, float m2tofw)
< {
< 
<   // float  a0    =       8.58341e-01;
<   // float  a1    =      -2.89831e-02;
<   // float  a2    =       1.68868e-02;
<   // float  a3    =      -9.42405e-03;
<   // float  a4    =       6.23467e-02;
<   // float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);
< 
<   float mean = mproton*mproton;
< 
<   float  p0    =      -6.19317e-03;  
<   float  p1    =       9.01921e-03;
<   float  p2    =       6.82347e-04;
<   float  p3    =       6.07866e-02;
<   float  p4    =      -1.32903e-01;
<   float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
< 
<   return (m2tofw - mean)/sigma;
< 
< }
< 
< 
< 
< 
< float isPionPDI(float x, float m2tofw)
< {
< 
<   // this mean is more radical
<   // consider going with less radical
<   float a0 = 0.0123786;
<   float a1 = 0.00293974;
<   float a2 = -0.000321866;
<   float a3 = -0.0110238;
<   float a4 = 0.0352101;
<   float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);
< 
<   // based on simulation
<   // new
<   // float  p0   =       -2.32986e-02;
<   // float  p1   =       -1.30028e-03;
<   // float  p2   =       -8.26991e-06;
<   // float  p3   =        5.56826e-02;
<   // float  p4   =       -1.16173e-01;
<   // float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
<   // from fit to real data
<   // new
<   float  p0   =       -4.32359e-02;
<   float  p1   =        6.44942e-03;
<   float  p2   =       -8.09058e-04;
<   float  p3   =        3.91918e-02;
<   float  p4   =       -5.68094e-02;
<   float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
<   
<   return (m2tofw - mean)/sigma;
< 
< }
< 
< 
2737,2773d2146
< bool GoodEMC(float emcz, float emcphi)
< {
< 
<   float zed = emcz;
<   float phi = emcphi;
< 
<   if(zed<-120&&phi>0.535) return false;//w2
<   if(zed>130&&zed<150&&phi>0.472&&phi<0.508) return false;//w2
<   if(zed>20&&zed<45&&phi>0.486&&phi<0.536) return false;//w2
<   if(zed>-100&&zed<-80&&phi>0.450&&phi<0.506) return false;//w2
<   if(zed>-125&&zed<-100&&phi>0.470&&phi<0.506) return false;//w2
<   if(zed>-155&&zed<-135&&phi>0.016&&phi<0.058) return false;//w1
< 
< 
<   return true;
< 
< }
< bool SysGoodEMC(float emcz, float emcphi)
< {
< 
<   float zed = emcz;
<   float phi = emcphi;
< 
<   if(zed<-120&&phi>0.535) return false;//w2
<   if(zed>128&&zed<150&&phi>0.472&&phi<0.513) return false;//w2
<   if(zed>18&&zed<45&&phi>0.486&&phi<0.541) return false;//w2
<   if(zed>-102&&zed<-80&&phi>0.450&&phi<0.511) return false;//w2
<   if(zed>-127&&zed<-100&&phi>0.470&&phi<0.511) return false;//w2
<   if(zed>-157&&zed<-135&&phi>0.016&&phi<0.063) return false;//w1
< 
< 
<   return true;
< 
< }
< 
< 
< 
2781c2154
<       cerr<<"Couldn't open file"<<endl;
---
>       cerr << "Couldn't open file\n";
2789c2162
<       //cout<<s<<endl;
---
>       //cout << s << '\n';
3137c2510
<   //float sline = 25.0; // unused in this routine
---
>   float sline = 25.0;
3165c2538
<   //float sline = 25.0; // unused this routine
---
>   float sline = 25.0;
3194,3198c2567,2570
<   // 1.72 is latest and greatest, Monday 10/25/1010
<   // none of these used in this routine
<   //float slope = 1.72;
<   //float sline = 25.0;
<   //float slire = 8.1;
---
> 
>   float slope = 1.72; // 1.72 is latest and greatest, Monday 10/25/1010
>   float sline = 25.0;
>   float slire = 8.1;
3266,3270c2638,2641
<   // 1.72 is latest and greatest, Monday 10/25/1010
<   // none of these used in this routine
<   //float slope = 1.72;
<   //float sline = 25.0;
<   //float slire = 8.1;
---
> 
>   float slope = 1.72; // 1.72 is latest and greatest, Monday 10/25/1010
>   float sline = 25.0;
>   float slire = 8.1;
