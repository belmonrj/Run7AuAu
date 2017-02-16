30c30
< 
---
> const float pi = 3.141592653589793;
38,40c38,40
< float isPionNew(float x, float m2tofw);
< float isKaonNew(float x, float m2tofw);
< float isProtonNew(float x, float m2tofw);
---
> float isPionANA(float x, float m2tofw);
> float isKaonANA(float x, float m2tofw);
> float isProtonANA(float x, float m2tofw);
45a46,53
> float isPionLME(float x, float m2tofw);
> float isKaonLME(float x, float m2tofw);
> float isProtonLME(float x, float m2tofw);
> 
> float isPionPDI(float x, float m2tofw);
> //float isKaonPDI(float x, float m2tofw);
> //float isProtonPDI(float x, float m2tofw);
> 
54a63
> bool GoodEMC(float emcz, float emcphi);
57a67
> bool SysGoodEMC(float emcz, float emcphi);
110,114c120,124
<       cerr<<"Wrong number of input arguments"<<endl;
<       cerr<<"This program takes 0 or 2 arguments"<<endl;
<       cerr<<"With 0 arguments it prompts the user for the file list and output root file"<<endl;
<       cerr<<"With 2 arguments the first is the file list and the second is the output root file"<<endl;
<       exit(1);
---
>       cout<<"Wrong number of input arguments"<<endl;
>       cout<<"This program takes 0 or 2 arguments"<<endl;
>       cout<<"With 0 arguments it prompts the user for the file list and output root file"<<endl;
>       cout<<"With 2 arguments the first is the file list and the second is the output root file"<<endl;
>       return 1;
134a145,147
>   TH1F *hhcent = new TH1F("hhcent","cent",100,0,100); // doesn't work, event bias
>   TH1F *hhbbcz = new TH1F("hhbbcz","bbcz",100,-50,50);
> 
200a214,218
> 
>   // ------------------ //
>   // --- background --- //
>   // ------------------ //
> 
203d220
<   //
206d222
<   //
209d224
<   //
212d226
<   //
215d228
<   //
218,229d230
<   //
<   TH2F *bkgrd_tofwsdphi_pT_back_pos_cent5 = new TH2F("bkgrd_tofwsdphi_pT_back_pos_cent5","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_back_neg_cent5 = new TH2F("bkgrd_tofwsdphi_pT_back_neg_cent5","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   //
<   TH2F *bkgrd_tofwsdphi_pT_back_pos_cent6 = new TH2F("bkgrd_tofwsdphi_pT_back_pos_cent6","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_back_neg_cent6 = new TH2F("bkgrd_tofwsdphi_pT_back_neg_cent6","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   //
<   TH2F *bkgrd_tofwsdphi_pT_back_pos_cent7 = new TH2F("bkgrd_tofwsdphi_pT_back_pos_cent7","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_back_neg_cent7 = new TH2F("bkgrd_tofwsdphi_pT_back_neg_cent7","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   //
<   TH2F *bkgrd_tofwsdphi_pT_back_pos_cent8 = new TH2F("bkgrd_tofwsdphi_pT_back_pos_cent8","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_back_neg_cent8 = new TH2F("bkgrd_tofwsdphi_pT_back_neg_cent8","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
230a232,256
>   TH2F *bkgrd_tofwsdphi_pT_fore_pos = new TH2F("bkgrd_tofwsdphi_pT_fore_pos","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_fore_neg = new TH2F("bkgrd_tofwsdphi_pT_fore_neg","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_fore_pos_cent0 = new TH2F("bkgrd_tofwsdphi_pT_fore_pos_cent0","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_fore_neg_cent0 = new TH2F("bkgrd_tofwsdphi_pT_fore_neg_cent0","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_fore_pos_cent1 = new TH2F("bkgrd_tofwsdphi_pT_fore_pos_cent1","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_fore_neg_cent1 = new TH2F("bkgrd_tofwsdphi_pT_fore_neg_cent1","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_fore_pos_cent2 = new TH2F("bkgrd_tofwsdphi_pT_fore_pos_cent2","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_fore_neg_cent2 = new TH2F("bkgrd_tofwsdphi_pT_fore_neg_cent2","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_fore_pos_cent3 = new TH2F("bkgrd_tofwsdphi_pT_fore_pos_cent3","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_fore_neg_cent3 = new TH2F("bkgrd_tofwsdphi_pT_fore_neg_cent3","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_fore_pos_cent4 = new TH2F("bkgrd_tofwsdphi_pT_fore_pos_cent4","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_fore_neg_cent4 = new TH2F("bkgrd_tofwsdphi_pT_fore_neg_cent4","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
> 
>   TH2F *bkgrd_tofwsdphi_pT_foep_pos = new TH2F("bkgrd_tofwsdphi_pT_foep_pos","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_foep_neg = new TH2F("bkgrd_tofwsdphi_pT_foep_neg","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_foep_pos_cent0 = new TH2F("bkgrd_tofwsdphi_pT_foep_pos_cent0","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_foep_neg_cent0 = new TH2F("bkgrd_tofwsdphi_pT_foep_neg_cent0","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_foep_pos_cent1 = new TH2F("bkgrd_tofwsdphi_pT_foep_pos_cent1","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_foep_neg_cent1 = new TH2F("bkgrd_tofwsdphi_pT_foep_neg_cent1","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_foep_pos_cent2 = new TH2F("bkgrd_tofwsdphi_pT_foep_pos_cent2","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_foep_neg_cent2 = new TH2F("bkgrd_tofwsdphi_pT_foep_neg_cent2","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_foep_pos_cent3 = new TH2F("bkgrd_tofwsdphi_pT_foep_pos_cent3","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_foep_neg_cent3 = new TH2F("bkgrd_tofwsdphi_pT_foep_neg_cent3","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_foep_pos_cent4 = new TH2F("bkgrd_tofwsdphi_pT_foep_pos_cent4","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
>   TH2F *bkgrd_tofwsdphi_pT_foep_neg_cent4 = new TH2F("bkgrd_tofwsdphi_pT_foep_neg_cent4","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
274,301d299
<   //
<   TH2F *bkgrd_tofwsdphi_pT_pion_pos_cent5 = new TH2F("bkgrd_tofwsdphi_pT_pion_pos_cent5","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_pion_neg_cent5 = new TH2F("bkgrd_tofwsdphi_pT_pion_neg_cent5","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_kaon_pos_cent5 = new TH2F("bkgrd_tofwsdphi_pT_kaon_pos_cent5","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_kaon_neg_cent5 = new TH2F("bkgrd_tofwsdphi_pT_kaon_neg_cent5","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_prot_pos_cent5 = new TH2F("bkgrd_tofwsdphi_pT_prot_pos_cent5","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_prot_neg_cent5 = new TH2F("bkgrd_tofwsdphi_pT_prot_neg_cent5","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   //
<   TH2F *bkgrd_tofwsdphi_pT_pion_pos_cent6 = new TH2F("bkgrd_tofwsdphi_pT_pion_pos_cent6","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_pion_neg_cent6 = new TH2F("bkgrd_tofwsdphi_pT_pion_neg_cent6","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_kaon_pos_cent6 = new TH2F("bkgrd_tofwsdphi_pT_kaon_pos_cent6","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_kaon_neg_cent6 = new TH2F("bkgrd_tofwsdphi_pT_kaon_neg_cent6","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_prot_pos_cent6 = new TH2F("bkgrd_tofwsdphi_pT_prot_pos_cent6","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_prot_neg_cent6 = new TH2F("bkgrd_tofwsdphi_pT_prot_neg_cent6","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   //
<   TH2F *bkgrd_tofwsdphi_pT_pion_pos_cent7 = new TH2F("bkgrd_tofwsdphi_pT_pion_pos_cent7","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_pion_neg_cent7 = new TH2F("bkgrd_tofwsdphi_pT_pion_neg_cent7","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_kaon_pos_cent7 = new TH2F("bkgrd_tofwsdphi_pT_kaon_pos_cent7","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_kaon_neg_cent7 = new TH2F("bkgrd_tofwsdphi_pT_kaon_neg_cent7","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_prot_pos_cent7 = new TH2F("bkgrd_tofwsdphi_pT_prot_pos_cent7","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_prot_neg_cent7 = new TH2F("bkgrd_tofwsdphi_pT_prot_neg_cent7","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   //
<   TH2F *bkgrd_tofwsdphi_pT_pion_pos_cent8 = new TH2F("bkgrd_tofwsdphi_pT_pion_pos_cent8","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_pion_neg_cent8 = new TH2F("bkgrd_tofwsdphi_pT_pion_neg_cent8","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_kaon_pos_cent8 = new TH2F("bkgrd_tofwsdphi_pT_kaon_pos_cent8","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_kaon_neg_cent8 = new TH2F("bkgrd_tofwsdphi_pT_kaon_neg_cent8","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_prot_pos_cent8 = new TH2F("bkgrd_tofwsdphi_pT_prot_pos_cent8","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
<   TH2F *bkgrd_tofwsdphi_pT_prot_neg_cent8 = new TH2F("bkgrd_tofwsdphi_pT_prot_neg_cent8","tofwsdphi vs pT", 100, 0, 10, 100, -5.0, 5.0);
373c371,374
<   TH2F *TOFWZedPhiNewNewDis  = new TH2F("TOFWZedPhiNewNewDis", "TOFW phi vs zed w/ all FC", 400, -200, 200, 500, -0.3, 0.7);
---
>   //TH2F *TOFWZedPhiNewNewDis  = new TH2F("TOFWZedPhiNewNewDis", "TOFW phi vs zed w/ all FC", 400, -200, 200, 500, -0.3, 0.7); // unused for now
>   //
>   TH2F *EMCZedPhiDis  = new TH2F("EMCZedPhiDis", "EMC phi vs zed w/o FC", 400, -200, 200, 500, -0.3, 0.7);
>   TH2F *EMCZedPhiNewDis  = new TH2F("EMCZedPhiNewDis", "EMC phi vs zed w/ FC",400, -200, 200, 500, -0.3, 0.7);
442a444,458
>   TH2F *m2pTdis_epc_pos = new TH2F("m2pTdis_epc_pos","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
>   TH2F *m2pTdis_epc_neg = new TH2F("m2pTdis_epc_neg","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
> 
>   TH2F *m2pTdis_epc_pos_cent0 = new TH2F("m2pTdis_epc_pos_cent0","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
>   TH2F *m2pTdis_epc_pos_cent1 = new TH2F("m2pTdis_epc_pos_cent1","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
>   TH2F *m2pTdis_epc_pos_cent2 = new TH2F("m2pTdis_epc_pos_cent2","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
>   TH2F *m2pTdis_epc_pos_cent3 = new TH2F("m2pTdis_epc_pos_cent3","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
>   TH2F *m2pTdis_epc_pos_cent4 = new TH2F("m2pTdis_epc_pos_cent4","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
> 
>   TH2F *m2pTdis_epc_neg_cent0 = new TH2F("m2pTdis_epc_neg_cent0","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
>   TH2F *m2pTdis_epc_neg_cent1 = new TH2F("m2pTdis_epc_neg_cent1","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
>   TH2F *m2pTdis_epc_neg_cent2 = new TH2F("m2pTdis_epc_neg_cent2","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
>   TH2F *m2pTdis_epc_neg_cent3 = new TH2F("m2pTdis_epc_neg_cent3","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
>   TH2F *m2pTdis_epc_neg_cent4 = new TH2F("m2pTdis_epc_neg_cent4","m2 vs pT", 100, 0.0, 10.0, 300, -1.0, 2.0);
> 
567a584,588
>   TH1F *ptpid_tofw_pos_2_dis_cent0010 = new TH1F("ptpid_tofw_pos_2_dis_cent0010", "tofw 2 pos pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_pos_2_dis_cent1020 = new TH1F("ptpid_tofw_pos_2_dis_cent1020", "tofw 2 pos pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_pos_2_dis_cent2040 = new TH1F("ptpid_tofw_pos_2_dis_cent2040", "tofw 2 pos pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_pos_2_dis_cent4060 = new TH1F("ptpid_tofw_pos_2_dis_cent4060", "tofw 2 pos pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_pos_2_dis_cent6092 = new TH1F("ptpid_tofw_pos_2_dis_cent6092", "tofw 2 pos pi ", 100, 0.0, 10.0);
577a599,603
>   TH1F *ptpid_tofw_pos_8_dis_cent0010 = new TH1F("ptpid_tofw_pos_8_dis_cent0010", "tofw 8 pos pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_pos_8_dis_cent1020 = new TH1F("ptpid_tofw_pos_8_dis_cent1020", "tofw 8 pos pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_pos_8_dis_cent2040 = new TH1F("ptpid_tofw_pos_8_dis_cent2040", "tofw 8 pos pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_pos_8_dis_cent4060 = new TH1F("ptpid_tofw_pos_8_dis_cent4060", "tofw 8 pos pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_pos_8_dis_cent6092 = new TH1F("ptpid_tofw_pos_8_dis_cent6092", "tofw 8 pos pr ", 100, 0.0, 10.0);
583a610,614
>   TH1F *ptpid_tofw_neg_2_dis_cent0010 = new TH1F("ptpid_tofw_neg_2_dis_cent0010", "tofw 2 neg pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_neg_2_dis_cent1020 = new TH1F("ptpid_tofw_neg_2_dis_cent1020", "tofw 2 neg pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_neg_2_dis_cent2040 = new TH1F("ptpid_tofw_neg_2_dis_cent2040", "tofw 2 neg pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_neg_2_dis_cent4060 = new TH1F("ptpid_tofw_neg_2_dis_cent4060", "tofw 2 neg pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_neg_2_dis_cent6092 = new TH1F("ptpid_tofw_neg_2_dis_cent6092", "tofw 2 neg pi ", 100, 0.0, 10.0);
593a625,629
>   TH1F *ptpid_tofw_neg_8_dis_cent0010 = new TH1F("ptpid_tofw_neg_8_dis_cent0010", "tofw 8 neg pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_neg_8_dis_cent1020 = new TH1F("ptpid_tofw_neg_8_dis_cent1020", "tofw 8 neg pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_neg_8_dis_cent2040 = new TH1F("ptpid_tofw_neg_8_dis_cent2040", "tofw 8 neg pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_neg_8_dis_cent4060 = new TH1F("ptpid_tofw_neg_8_dis_cent4060", "tofw 8 neg pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_neg_8_dis_cent6092 = new TH1F("ptpid_tofw_neg_8_dis_cent6092", "tofw 8 neg pr ", 100, 0.0, 10.0);
952c988,1552
<   // --- Done with Histograms ---------------------
---
> 
>   // --- first X
>   TH2F *hh_X_ecorept_pospion_centMB = new TH2F("hh_X_ecorept_pospion_centMB","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_negpion_centMB = new TH2F("hh_X_ecorept_negpion_centMB","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_posproton_centMB = new TH2F("hh_X_ecorept_posproton_centMB","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_negproton_centMB = new TH2F("hh_X_ecorept_negproton_centMB","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_pospion_cent0010 = new TH2F("hh_X_ecorept_pospion_cent0010","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_negpion_cent0010 = new TH2F("hh_X_ecorept_negpion_cent0010","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_posproton_cent0010 = new TH2F("hh_X_ecorept_posproton_cent0010","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_negproton_cent0010 = new TH2F("hh_X_ecorept_negproton_cent0010","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_pospion_cent1020 = new TH2F("hh_X_ecorept_pospion_cent1020","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_negpion_cent1020 = new TH2F("hh_X_ecorept_negpion_cent1020","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_posproton_cent1020 = new TH2F("hh_X_ecorept_posproton_cent1020","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_negproton_cent1020 = new TH2F("hh_X_ecorept_negproton_cent1020","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_pospion_cent2040 = new TH2F("hh_X_ecorept_pospion_cent2040","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_negpion_cent2040 = new TH2F("hh_X_ecorept_negpion_cent2040","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_posproton_cent2040 = new TH2F("hh_X_ecorept_posproton_cent2040","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_negproton_cent2040 = new TH2F("hh_X_ecorept_negproton_cent2040","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_pospion_cent4060 = new TH2F("hh_X_ecorept_pospion_cent4060","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_negpion_cent4060 = new TH2F("hh_X_ecorept_negpion_cent4060","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_posproton_cent4060 = new TH2F("hh_X_ecorept_posproton_cent4060","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_negproton_cent4060 = new TH2F("hh_X_ecorept_negproton_cent4060","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_pospion_cent6092 = new TH2F("hh_X_ecorept_pospion_cent6092","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_negpion_cent6092 = new TH2F("hh_X_ecorept_negpion_cent6092","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_posproton_cent6092 = new TH2F("hh_X_ecorept_posproton_cent6092","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_X_ecorept_negproton_cent6092 = new TH2F("hh_X_ecorept_negproton_cent6092","...",50,0.0,5.0,100,0.0,5.0);
>   // --- then Y
>   TH2F *hh_Y_ecorept_pospion_centMB = new TH2F("hh_Y_ecorept_pospion_centMB","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_negpion_centMB = new TH2F("hh_Y_ecorept_negpion_centMB","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_posproton_centMB = new TH2F("hh_Y_ecorept_posproton_centMB","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_negproton_centMB = new TH2F("hh_Y_ecorept_negproton_centMB","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_pospion_cent0010 = new TH2F("hh_Y_ecorept_pospion_cent0010","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_negpion_cent0010 = new TH2F("hh_Y_ecorept_negpion_cent0010","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_posproton_cent0010 = new TH2F("hh_Y_ecorept_posproton_cent0010","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_negproton_cent0010 = new TH2F("hh_Y_ecorept_negproton_cent0010","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_pospion_cent1020 = new TH2F("hh_Y_ecorept_pospion_cent1020","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_negpion_cent1020 = new TH2F("hh_Y_ecorept_negpion_cent1020","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_posproton_cent1020 = new TH2F("hh_Y_ecorept_posproton_cent1020","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_negproton_cent1020 = new TH2F("hh_Y_ecorept_negproton_cent1020","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_pospion_cent2040 = new TH2F("hh_Y_ecorept_pospion_cent2040","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_negpion_cent2040 = new TH2F("hh_Y_ecorept_negpion_cent2040","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_posproton_cent2040 = new TH2F("hh_Y_ecorept_posproton_cent2040","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_negproton_cent2040 = new TH2F("hh_Y_ecorept_negproton_cent2040","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_pospion_cent4060 = new TH2F("hh_Y_ecorept_pospion_cent4060","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_negpion_cent4060 = new TH2F("hh_Y_ecorept_negpion_cent4060","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_posproton_cent4060 = new TH2F("hh_Y_ecorept_posproton_cent4060","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_negproton_cent4060 = new TH2F("hh_Y_ecorept_negproton_cent4060","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_pospion_cent6092 = new TH2F("hh_Y_ecorept_pospion_cent6092","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_negpion_cent6092 = new TH2F("hh_Y_ecorept_negpion_cent6092","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_posproton_cent6092 = new TH2F("hh_Y_ecorept_posproton_cent6092","...",50,0.0,5.0,100,0.0,5.0);
>   TH2F *hh_Y_ecorept_negproton_cent6092 = new TH2F("hh_Y_ecorept_negproton_cent6092","...",50,0.0,5.0,100,0.0,5.0);
> 
> 
>   //
>   TH1F *hh_X_spectpt_pospion_centMB = new TH1F("hh_X_spectpt_pospion_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_negpion_centMB = new TH1F("hh_X_spectpt_negpion_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_pospion_centMB = new TH1F("hh_X_specept_pospion_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_negpion_centMB = new TH1F("hh_X_specept_negpion_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_pospion_cent0010 = new TH1F("hh_X_spectpt_pospion_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_negpion_cent0010 = new TH1F("hh_X_spectpt_negpion_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_pospion_cent0010 = new TH1F("hh_X_specept_pospion_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_negpion_cent0010 = new TH1F("hh_X_specept_negpion_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_pospion_cent1020 = new TH1F("hh_X_spectpt_pospion_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_negpion_cent1020 = new TH1F("hh_X_spectpt_negpion_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_pospion_cent1020 = new TH1F("hh_X_specept_pospion_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_negpion_cent1020 = new TH1F("hh_X_specept_negpion_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_pospion_cent2040 = new TH1F("hh_X_spectpt_pospion_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_negpion_cent2040 = new TH1F("hh_X_spectpt_negpion_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_pospion_cent2040 = new TH1F("hh_X_specept_pospion_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_negpion_cent2040 = new TH1F("hh_X_specept_negpion_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_pospion_cent4060 = new TH1F("hh_X_spectpt_pospion_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_negpion_cent4060 = new TH1F("hh_X_spectpt_negpion_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_pospion_cent4060 = new TH1F("hh_X_specept_pospion_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_negpion_cent4060 = new TH1F("hh_X_specept_negpion_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_pospion_cent6092 = new TH1F("hh_X_spectpt_pospion_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_negpion_cent6092 = new TH1F("hh_X_spectpt_negpion_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_pospion_cent6092 = new TH1F("hh_X_specept_pospion_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_negpion_cent6092 = new TH1F("hh_X_specept_negpion_cent6092", "...", 100, 0.0, 10.0);
>   //
>   TH1F *hh_X_spectpt_posproton_centMB = new TH1F("hh_X_spectpt_posproton_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_negproton_centMB = new TH1F("hh_X_spectpt_negproton_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_posproton_centMB = new TH1F("hh_X_specept_posproton_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_negproton_centMB = new TH1F("hh_X_specept_negproton_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_posproton_cent0010 = new TH1F("hh_X_spectpt_posproton_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_negproton_cent0010 = new TH1F("hh_X_spectpt_negproton_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_posproton_cent0010 = new TH1F("hh_X_specept_posproton_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_negproton_cent0010 = new TH1F("hh_X_specept_negproton_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_posproton_cent1020 = new TH1F("hh_X_spectpt_posproton_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_negproton_cent1020 = new TH1F("hh_X_spectpt_negproton_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_posproton_cent1020 = new TH1F("hh_X_specept_posproton_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_negproton_cent1020 = new TH1F("hh_X_specept_negproton_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_posproton_cent2040 = new TH1F("hh_X_spectpt_posproton_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_negproton_cent2040 = new TH1F("hh_X_spectpt_negproton_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_posproton_cent2040 = new TH1F("hh_X_specept_posproton_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_negproton_cent2040 = new TH1F("hh_X_specept_negproton_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_posproton_cent4060 = new TH1F("hh_X_spectpt_posproton_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_negproton_cent4060 = new TH1F("hh_X_spectpt_negproton_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_posproton_cent4060 = new TH1F("hh_X_specept_posproton_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_negproton_cent4060 = new TH1F("hh_X_specept_negproton_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_posproton_cent6092 = new TH1F("hh_X_spectpt_posproton_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_spectpt_negproton_cent6092 = new TH1F("hh_X_spectpt_negproton_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_posproton_cent6092 = new TH1F("hh_X_specept_posproton_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hh_X_specept_negproton_cent6092 = new TH1F("hh_X_specept_negproton_cent6092", "...", 100, 0.0, 10.0);
> 
>   // now Y
> 
>   //
>   TH1F *hh_Y_spectpt_pospion_centMB = new TH1F("hh_Y_spectpt_pospion_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_negpion_centMB = new TH1F("hh_Y_spectpt_negpion_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_pospion_centMB = new TH1F("hh_Y_specept_pospion_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_negpion_centMB = new TH1F("hh_Y_specept_negpion_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_pospion_cent0010 = new TH1F("hh_Y_spectpt_pospion_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_negpion_cent0010 = new TH1F("hh_Y_spectpt_negpion_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_pospion_cent0010 = new TH1F("hh_Y_specept_pospion_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_negpion_cent0010 = new TH1F("hh_Y_specept_negpion_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_pospion_cent1020 = new TH1F("hh_Y_spectpt_pospion_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_negpion_cent1020 = new TH1F("hh_Y_spectpt_negpion_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_pospion_cent1020 = new TH1F("hh_Y_specept_pospion_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_negpion_cent1020 = new TH1F("hh_Y_specept_negpion_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_pospion_cent2040 = new TH1F("hh_Y_spectpt_pospion_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_negpion_cent2040 = new TH1F("hh_Y_spectpt_negpion_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_pospion_cent2040 = new TH1F("hh_Y_specept_pospion_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_negpion_cent2040 = new TH1F("hh_Y_specept_negpion_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_pospion_cent4060 = new TH1F("hh_Y_spectpt_pospion_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_negpion_cent4060 = new TH1F("hh_Y_spectpt_negpion_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_pospion_cent4060 = new TH1F("hh_Y_specept_pospion_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_negpion_cent4060 = new TH1F("hh_Y_specept_negpion_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_pospion_cent6092 = new TH1F("hh_Y_spectpt_pospion_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_negpion_cent6092 = new TH1F("hh_Y_spectpt_negpion_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_pospion_cent6092 = new TH1F("hh_Y_specept_pospion_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_negpion_cent6092 = new TH1F("hh_Y_specept_negpion_cent6092", "...", 100, 0.0, 10.0);
>   //
>   TH1F *hh_Y_spectpt_posproton_centMB = new TH1F("hh_Y_spectpt_posproton_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_negproton_centMB = new TH1F("hh_Y_spectpt_negproton_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_posproton_centMB = new TH1F("hh_Y_specept_posproton_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_negproton_centMB = new TH1F("hh_Y_specept_negproton_centMB", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_posproton_cent0010 = new TH1F("hh_Y_spectpt_posproton_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_negproton_cent0010 = new TH1F("hh_Y_spectpt_negproton_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_posproton_cent0010 = new TH1F("hh_Y_specept_posproton_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_negproton_cent0010 = new TH1F("hh_Y_specept_negproton_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_posproton_cent1020 = new TH1F("hh_Y_spectpt_posproton_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_negproton_cent1020 = new TH1F("hh_Y_spectpt_negproton_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_posproton_cent1020 = new TH1F("hh_Y_specept_posproton_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_negproton_cent1020 = new TH1F("hh_Y_specept_negproton_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_posproton_cent2040 = new TH1F("hh_Y_spectpt_posproton_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_negproton_cent2040 = new TH1F("hh_Y_spectpt_negproton_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_posproton_cent2040 = new TH1F("hh_Y_specept_posproton_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_negproton_cent2040 = new TH1F("hh_Y_specept_negproton_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_posproton_cent4060 = new TH1F("hh_Y_spectpt_posproton_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_negproton_cent4060 = new TH1F("hh_Y_spectpt_negproton_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_posproton_cent4060 = new TH1F("hh_Y_specept_posproton_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_negproton_cent4060 = new TH1F("hh_Y_specept_negproton_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_posproton_cent6092 = new TH1F("hh_Y_spectpt_posproton_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_spectpt_negproton_cent6092 = new TH1F("hh_Y_spectpt_negproton_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_posproton_cent6092 = new TH1F("hh_Y_specept_posproton_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hh_Y_specept_negproton_cent6092 = new TH1F("hh_Y_specept_negproton_cent6092", "...", 100, 0.0, 10.0);
> 
> 
> 
> 
>   // ------------------------------------------ //
>   // --- begin extra special pid histograms --- //
>   // ------------------------------------------ //
> 
>   // --- pion
> 
>   TH1F *hhptpid_tofw_pospion_0_dis_cent0010 = new TH1F("hhptpid_tofw_pospion_0_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_0_dis_cent1020 = new TH1F("hhptpid_tofw_pospion_0_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_0_dis_cent2040 = new TH1F("hhptpid_tofw_pospion_0_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_0_dis_cent4060 = new TH1F("hhptpid_tofw_pospion_0_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_0_dis_cent6092 = new TH1F("hhptpid_tofw_pospion_0_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_0_dis_cent0010 = new TH1F("hhptpid_tofw_negpion_0_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_0_dis_cent1020 = new TH1F("hhptpid_tofw_negpion_0_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_0_dis_cent2040 = new TH1F("hhptpid_tofw_negpion_0_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_0_dis_cent4060 = new TH1F("hhptpid_tofw_negpion_0_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_0_dis_cent6092 = new TH1F("hhptpid_tofw_negpion_0_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_0_dis_cent0010 = new TH1F("hhptpid_tfec_pospion_0_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_0_dis_cent1020 = new TH1F("hhptpid_tfec_pospion_0_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_0_dis_cent2040 = new TH1F("hhptpid_tfec_pospion_0_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_0_dis_cent4060 = new TH1F("hhptpid_tfec_pospion_0_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_0_dis_cent6092 = new TH1F("hhptpid_tfec_pospion_0_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_0_dis_cent0010 = new TH1F("hhptpid_tfec_negpion_0_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_0_dis_cent1020 = new TH1F("hhptpid_tfec_negpion_0_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_0_dis_cent2040 = new TH1F("hhptpid_tfec_negpion_0_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_0_dis_cent4060 = new TH1F("hhptpid_tfec_negpion_0_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_0_dis_cent6092 = new TH1F("hhptpid_tfec_negpion_0_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   TH1F *hhptpid_tofw_pospion_1_dis_cent0010 = new TH1F("hhptpid_tofw_pospion_1_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_1_dis_cent1020 = new TH1F("hhptpid_tofw_pospion_1_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_1_dis_cent2040 = new TH1F("hhptpid_tofw_pospion_1_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_1_dis_cent4060 = new TH1F("hhptpid_tofw_pospion_1_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_1_dis_cent6092 = new TH1F("hhptpid_tofw_pospion_1_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_1_dis_cent0010 = new TH1F("hhptpid_tofw_negpion_1_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_1_dis_cent1020 = new TH1F("hhptpid_tofw_negpion_1_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_1_dis_cent2040 = new TH1F("hhptpid_tofw_negpion_1_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_1_dis_cent4060 = new TH1F("hhptpid_tofw_negpion_1_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_1_dis_cent6092 = new TH1F("hhptpid_tofw_negpion_1_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_1_dis_cent0010 = new TH1F("hhptpid_tfec_pospion_1_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_1_dis_cent1020 = new TH1F("hhptpid_tfec_pospion_1_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_1_dis_cent2040 = new TH1F("hhptpid_tfec_pospion_1_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_1_dis_cent4060 = new TH1F("hhptpid_tfec_pospion_1_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_1_dis_cent6092 = new TH1F("hhptpid_tfec_pospion_1_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_1_dis_cent0010 = new TH1F("hhptpid_tfec_negpion_1_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_1_dis_cent1020 = new TH1F("hhptpid_tfec_negpion_1_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_1_dis_cent2040 = new TH1F("hhptpid_tfec_negpion_1_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_1_dis_cent4060 = new TH1F("hhptpid_tfec_negpion_1_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_1_dis_cent6092 = new TH1F("hhptpid_tfec_negpion_1_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   TH1F *hhptpid_tofw_pospion_2_dis_cent0010 = new TH1F("hhptpid_tofw_pospion_2_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_2_dis_cent1020 = new TH1F("hhptpid_tofw_pospion_2_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_2_dis_cent2040 = new TH1F("hhptpid_tofw_pospion_2_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_2_dis_cent4060 = new TH1F("hhptpid_tofw_pospion_2_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_2_dis_cent6092 = new TH1F("hhptpid_tofw_pospion_2_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_2_dis_cent0010 = new TH1F("hhptpid_tofw_negpion_2_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_2_dis_cent1020 = new TH1F("hhptpid_tofw_negpion_2_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_2_dis_cent2040 = new TH1F("hhptpid_tofw_negpion_2_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_2_dis_cent4060 = new TH1F("hhptpid_tofw_negpion_2_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_2_dis_cent6092 = new TH1F("hhptpid_tofw_negpion_2_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_2_dis_cent0010 = new TH1F("hhptpid_tfec_pospion_2_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_2_dis_cent1020 = new TH1F("hhptpid_tfec_pospion_2_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_2_dis_cent2040 = new TH1F("hhptpid_tfec_pospion_2_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_2_dis_cent4060 = new TH1F("hhptpid_tfec_pospion_2_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_2_dis_cent6092 = new TH1F("hhptpid_tfec_pospion_2_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_2_dis_cent0010 = new TH1F("hhptpid_tfec_negpion_2_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_2_dis_cent1020 = new TH1F("hhptpid_tfec_negpion_2_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_2_dis_cent2040 = new TH1F("hhptpid_tfec_negpion_2_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_2_dis_cent4060 = new TH1F("hhptpid_tfec_negpion_2_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_2_dis_cent6092 = new TH1F("hhptpid_tfec_negpion_2_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   TH1F *hhptpid_tofw_pospion_3_dis_cent0010 = new TH1F("hhptpid_tofw_pospion_3_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_3_dis_cent1020 = new TH1F("hhptpid_tofw_pospion_3_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_3_dis_cent2040 = new TH1F("hhptpid_tofw_pospion_3_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_3_dis_cent4060 = new TH1F("hhptpid_tofw_pospion_3_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_3_dis_cent6092 = new TH1F("hhptpid_tofw_pospion_3_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_3_dis_cent0010 = new TH1F("hhptpid_tofw_negpion_3_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_3_dis_cent1020 = new TH1F("hhptpid_tofw_negpion_3_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_3_dis_cent2040 = new TH1F("hhptpid_tofw_negpion_3_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_3_dis_cent4060 = new TH1F("hhptpid_tofw_negpion_3_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_3_dis_cent6092 = new TH1F("hhptpid_tofw_negpion_3_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_3_dis_cent0010 = new TH1F("hhptpid_tfec_pospion_3_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_3_dis_cent1020 = new TH1F("hhptpid_tfec_pospion_3_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_3_dis_cent2040 = new TH1F("hhptpid_tfec_pospion_3_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_3_dis_cent4060 = new TH1F("hhptpid_tfec_pospion_3_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_3_dis_cent6092 = new TH1F("hhptpid_tfec_pospion_3_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_3_dis_cent0010 = new TH1F("hhptpid_tfec_negpion_3_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_3_dis_cent1020 = new TH1F("hhptpid_tfec_negpion_3_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_3_dis_cent2040 = new TH1F("hhptpid_tfec_negpion_3_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_3_dis_cent4060 = new TH1F("hhptpid_tfec_negpion_3_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_3_dis_cent6092 = new TH1F("hhptpid_tfec_negpion_3_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   TH1F *hhptpid_tofw_pospion_4_dis_cent0010 = new TH1F("hhptpid_tofw_pospion_4_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_4_dis_cent1020 = new TH1F("hhptpid_tofw_pospion_4_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_4_dis_cent2040 = new TH1F("hhptpid_tofw_pospion_4_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_4_dis_cent4060 = new TH1F("hhptpid_tofw_pospion_4_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_4_dis_cent6092 = new TH1F("hhptpid_tofw_pospion_4_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_4_dis_cent0010 = new TH1F("hhptpid_tofw_negpion_4_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_4_dis_cent1020 = new TH1F("hhptpid_tofw_negpion_4_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_4_dis_cent2040 = new TH1F("hhptpid_tofw_negpion_4_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_4_dis_cent4060 = new TH1F("hhptpid_tofw_negpion_4_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_4_dis_cent6092 = new TH1F("hhptpid_tofw_negpion_4_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_4_dis_cent0010 = new TH1F("hhptpid_tfec_pospion_4_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_4_dis_cent1020 = new TH1F("hhptpid_tfec_pospion_4_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_4_dis_cent2040 = new TH1F("hhptpid_tfec_pospion_4_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_4_dis_cent4060 = new TH1F("hhptpid_tfec_pospion_4_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_4_dis_cent6092 = new TH1F("hhptpid_tfec_pospion_4_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_4_dis_cent0010 = new TH1F("hhptpid_tfec_negpion_4_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_4_dis_cent1020 = new TH1F("hhptpid_tfec_negpion_4_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_4_dis_cent2040 = new TH1F("hhptpid_tfec_negpion_4_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_4_dis_cent4060 = new TH1F("hhptpid_tfec_negpion_4_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_4_dis_cent6092 = new TH1F("hhptpid_tfec_negpion_4_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   TH1F *hhptpid_tofw_pospion_5_dis_cent0010 = new TH1F("hhptpid_tofw_pospion_5_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_5_dis_cent1020 = new TH1F("hhptpid_tofw_pospion_5_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_5_dis_cent2040 = new TH1F("hhptpid_tofw_pospion_5_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_5_dis_cent4060 = new TH1F("hhptpid_tofw_pospion_5_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_pospion_5_dis_cent6092 = new TH1F("hhptpid_tofw_pospion_5_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_5_dis_cent0010 = new TH1F("hhptpid_tofw_negpion_5_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_5_dis_cent1020 = new TH1F("hhptpid_tofw_negpion_5_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_5_dis_cent2040 = new TH1F("hhptpid_tofw_negpion_5_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_5_dis_cent4060 = new TH1F("hhptpid_tofw_negpion_5_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negpion_5_dis_cent6092 = new TH1F("hhptpid_tofw_negpion_5_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_5_dis_cent0010 = new TH1F("hhptpid_tfec_pospion_5_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_5_dis_cent1020 = new TH1F("hhptpid_tfec_pospion_5_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_5_dis_cent2040 = new TH1F("hhptpid_tfec_pospion_5_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_5_dis_cent4060 = new TH1F("hhptpid_tfec_pospion_5_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_pospion_5_dis_cent6092 = new TH1F("hhptpid_tfec_pospion_5_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_5_dis_cent0010 = new TH1F("hhptpid_tfec_negpion_5_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_5_dis_cent1020 = new TH1F("hhptpid_tfec_negpion_5_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_5_dis_cent2040 = new TH1F("hhptpid_tfec_negpion_5_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_5_dis_cent4060 = new TH1F("hhptpid_tfec_negpion_5_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negpion_5_dis_cent6092 = new TH1F("hhptpid_tfec_negpion_5_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   // --- kaon
> 
>   TH1F *hhptpid_tofw_poskaon_0_dis_cent0010 = new TH1F("hhptpid_tofw_poskaon_0_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_0_dis_cent1020 = new TH1F("hhptpid_tofw_poskaon_0_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_0_dis_cent2040 = new TH1F("hhptpid_tofw_poskaon_0_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_0_dis_cent4060 = new TH1F("hhptpid_tofw_poskaon_0_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_0_dis_cent6092 = new TH1F("hhptpid_tofw_poskaon_0_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_0_dis_cent0010 = new TH1F("hhptpid_tofw_negkaon_0_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_0_dis_cent1020 = new TH1F("hhptpid_tofw_negkaon_0_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_0_dis_cent2040 = new TH1F("hhptpid_tofw_negkaon_0_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_0_dis_cent4060 = new TH1F("hhptpid_tofw_negkaon_0_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_0_dis_cent6092 = new TH1F("hhptpid_tofw_negkaon_0_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_0_dis_cent0010 = new TH1F("hhptpid_tfec_poskaon_0_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_0_dis_cent1020 = new TH1F("hhptpid_tfec_poskaon_0_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_0_dis_cent2040 = new TH1F("hhptpid_tfec_poskaon_0_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_0_dis_cent4060 = new TH1F("hhptpid_tfec_poskaon_0_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_0_dis_cent6092 = new TH1F("hhptpid_tfec_poskaon_0_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_0_dis_cent0010 = new TH1F("hhptpid_tfec_negkaon_0_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_0_dis_cent1020 = new TH1F("hhptpid_tfec_negkaon_0_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_0_dis_cent2040 = new TH1F("hhptpid_tfec_negkaon_0_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_0_dis_cent4060 = new TH1F("hhptpid_tfec_negkaon_0_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_0_dis_cent6092 = new TH1F("hhptpid_tfec_negkaon_0_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   TH1F *hhptpid_tofw_poskaon_1_dis_cent0010 = new TH1F("hhptpid_tofw_poskaon_1_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_1_dis_cent1020 = new TH1F("hhptpid_tofw_poskaon_1_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_1_dis_cent2040 = new TH1F("hhptpid_tofw_poskaon_1_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_1_dis_cent4060 = new TH1F("hhptpid_tofw_poskaon_1_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_1_dis_cent6092 = new TH1F("hhptpid_tofw_poskaon_1_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_1_dis_cent0010 = new TH1F("hhptpid_tofw_negkaon_1_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_1_dis_cent1020 = new TH1F("hhptpid_tofw_negkaon_1_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_1_dis_cent2040 = new TH1F("hhptpid_tofw_negkaon_1_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_1_dis_cent4060 = new TH1F("hhptpid_tofw_negkaon_1_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_1_dis_cent6092 = new TH1F("hhptpid_tofw_negkaon_1_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_1_dis_cent0010 = new TH1F("hhptpid_tfec_poskaon_1_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_1_dis_cent1020 = new TH1F("hhptpid_tfec_poskaon_1_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_1_dis_cent2040 = new TH1F("hhptpid_tfec_poskaon_1_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_1_dis_cent4060 = new TH1F("hhptpid_tfec_poskaon_1_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_1_dis_cent6092 = new TH1F("hhptpid_tfec_poskaon_1_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_1_dis_cent0010 = new TH1F("hhptpid_tfec_negkaon_1_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_1_dis_cent1020 = new TH1F("hhptpid_tfec_negkaon_1_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_1_dis_cent2040 = new TH1F("hhptpid_tfec_negkaon_1_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_1_dis_cent4060 = new TH1F("hhptpid_tfec_negkaon_1_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_1_dis_cent6092 = new TH1F("hhptpid_tfec_negkaon_1_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   TH1F *hhptpid_tofw_poskaon_2_dis_cent0010 = new TH1F("hhptpid_tofw_poskaon_2_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_2_dis_cent1020 = new TH1F("hhptpid_tofw_poskaon_2_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_2_dis_cent2040 = new TH1F("hhptpid_tofw_poskaon_2_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_2_dis_cent4060 = new TH1F("hhptpid_tofw_poskaon_2_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_2_dis_cent6092 = new TH1F("hhptpid_tofw_poskaon_2_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_2_dis_cent0010 = new TH1F("hhptpid_tofw_negkaon_2_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_2_dis_cent1020 = new TH1F("hhptpid_tofw_negkaon_2_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_2_dis_cent2040 = new TH1F("hhptpid_tofw_negkaon_2_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_2_dis_cent4060 = new TH1F("hhptpid_tofw_negkaon_2_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_2_dis_cent6092 = new TH1F("hhptpid_tofw_negkaon_2_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_2_dis_cent0010 = new TH1F("hhptpid_tfec_poskaon_2_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_2_dis_cent1020 = new TH1F("hhptpid_tfec_poskaon_2_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_2_dis_cent2040 = new TH1F("hhptpid_tfec_poskaon_2_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_2_dis_cent4060 = new TH1F("hhptpid_tfec_poskaon_2_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_2_dis_cent6092 = new TH1F("hhptpid_tfec_poskaon_2_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_2_dis_cent0010 = new TH1F("hhptpid_tfec_negkaon_2_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_2_dis_cent1020 = new TH1F("hhptpid_tfec_negkaon_2_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_2_dis_cent2040 = new TH1F("hhptpid_tfec_negkaon_2_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_2_dis_cent4060 = new TH1F("hhptpid_tfec_negkaon_2_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_2_dis_cent6092 = new TH1F("hhptpid_tfec_negkaon_2_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   TH1F *hhptpid_tofw_poskaon_3_dis_cent0010 = new TH1F("hhptpid_tofw_poskaon_3_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_3_dis_cent1020 = new TH1F("hhptpid_tofw_poskaon_3_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_3_dis_cent2040 = new TH1F("hhptpid_tofw_poskaon_3_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_3_dis_cent4060 = new TH1F("hhptpid_tofw_poskaon_3_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_3_dis_cent6092 = new TH1F("hhptpid_tofw_poskaon_3_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_3_dis_cent0010 = new TH1F("hhptpid_tofw_negkaon_3_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_3_dis_cent1020 = new TH1F("hhptpid_tofw_negkaon_3_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_3_dis_cent2040 = new TH1F("hhptpid_tofw_negkaon_3_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_3_dis_cent4060 = new TH1F("hhptpid_tofw_negkaon_3_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_3_dis_cent6092 = new TH1F("hhptpid_tofw_negkaon_3_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_3_dis_cent0010 = new TH1F("hhptpid_tfec_poskaon_3_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_3_dis_cent1020 = new TH1F("hhptpid_tfec_poskaon_3_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_3_dis_cent2040 = new TH1F("hhptpid_tfec_poskaon_3_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_3_dis_cent4060 = new TH1F("hhptpid_tfec_poskaon_3_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_3_dis_cent6092 = new TH1F("hhptpid_tfec_poskaon_3_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_3_dis_cent0010 = new TH1F("hhptpid_tfec_negkaon_3_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_3_dis_cent1020 = new TH1F("hhptpid_tfec_negkaon_3_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_3_dis_cent2040 = new TH1F("hhptpid_tfec_negkaon_3_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_3_dis_cent4060 = new TH1F("hhptpid_tfec_negkaon_3_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_3_dis_cent6092 = new TH1F("hhptpid_tfec_negkaon_3_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   TH1F *hhptpid_tofw_poskaon_4_dis_cent0010 = new TH1F("hhptpid_tofw_poskaon_4_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_4_dis_cent1020 = new TH1F("hhptpid_tofw_poskaon_4_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_4_dis_cent2040 = new TH1F("hhptpid_tofw_poskaon_4_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_4_dis_cent4060 = new TH1F("hhptpid_tofw_poskaon_4_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_4_dis_cent6092 = new TH1F("hhptpid_tofw_poskaon_4_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_4_dis_cent0010 = new TH1F("hhptpid_tofw_negkaon_4_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_4_dis_cent1020 = new TH1F("hhptpid_tofw_negkaon_4_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_4_dis_cent2040 = new TH1F("hhptpid_tofw_negkaon_4_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_4_dis_cent4060 = new TH1F("hhptpid_tofw_negkaon_4_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_4_dis_cent6092 = new TH1F("hhptpid_tofw_negkaon_4_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_4_dis_cent0010 = new TH1F("hhptpid_tfec_poskaon_4_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_4_dis_cent1020 = new TH1F("hhptpid_tfec_poskaon_4_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_4_dis_cent2040 = new TH1F("hhptpid_tfec_poskaon_4_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_4_dis_cent4060 = new TH1F("hhptpid_tfec_poskaon_4_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_4_dis_cent6092 = new TH1F("hhptpid_tfec_poskaon_4_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_4_dis_cent0010 = new TH1F("hhptpid_tfec_negkaon_4_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_4_dis_cent1020 = new TH1F("hhptpid_tfec_negkaon_4_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_4_dis_cent2040 = new TH1F("hhptpid_tfec_negkaon_4_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_4_dis_cent4060 = new TH1F("hhptpid_tfec_negkaon_4_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_4_dis_cent6092 = new TH1F("hhptpid_tfec_negkaon_4_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   TH1F *hhptpid_tofw_poskaon_5_dis_cent0010 = new TH1F("hhptpid_tofw_poskaon_5_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_5_dis_cent1020 = new TH1F("hhptpid_tofw_poskaon_5_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_5_dis_cent2040 = new TH1F("hhptpid_tofw_poskaon_5_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_5_dis_cent4060 = new TH1F("hhptpid_tofw_poskaon_5_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_poskaon_5_dis_cent6092 = new TH1F("hhptpid_tofw_poskaon_5_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_5_dis_cent0010 = new TH1F("hhptpid_tofw_negkaon_5_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_5_dis_cent1020 = new TH1F("hhptpid_tofw_negkaon_5_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_5_dis_cent2040 = new TH1F("hhptpid_tofw_negkaon_5_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_5_dis_cent4060 = new TH1F("hhptpid_tofw_negkaon_5_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negkaon_5_dis_cent6092 = new TH1F("hhptpid_tofw_negkaon_5_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_5_dis_cent0010 = new TH1F("hhptpid_tfec_poskaon_5_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_5_dis_cent1020 = new TH1F("hhptpid_tfec_poskaon_5_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_5_dis_cent2040 = new TH1F("hhptpid_tfec_poskaon_5_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_5_dis_cent4060 = new TH1F("hhptpid_tfec_poskaon_5_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_poskaon_5_dis_cent6092 = new TH1F("hhptpid_tfec_poskaon_5_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_5_dis_cent0010 = new TH1F("hhptpid_tfec_negkaon_5_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_5_dis_cent1020 = new TH1F("hhptpid_tfec_negkaon_5_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_5_dis_cent2040 = new TH1F("hhptpid_tfec_negkaon_5_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_5_dis_cent4060 = new TH1F("hhptpid_tfec_negkaon_5_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negkaon_5_dis_cent6092 = new TH1F("hhptpid_tfec_negkaon_5_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   // --- proton
> 
>   TH1F *hhptpid_tofw_posproton_0_dis_cent0010 = new TH1F("hhptpid_tofw_posproton_0_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_0_dis_cent1020 = new TH1F("hhptpid_tofw_posproton_0_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_0_dis_cent2040 = new TH1F("hhptpid_tofw_posproton_0_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_0_dis_cent4060 = new TH1F("hhptpid_tofw_posproton_0_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_0_dis_cent6092 = new TH1F("hhptpid_tofw_posproton_0_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_0_dis_cent0010 = new TH1F("hhptpid_tofw_negproton_0_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_0_dis_cent1020 = new TH1F("hhptpid_tofw_negproton_0_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_0_dis_cent2040 = new TH1F("hhptpid_tofw_negproton_0_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_0_dis_cent4060 = new TH1F("hhptpid_tofw_negproton_0_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_0_dis_cent6092 = new TH1F("hhptpid_tofw_negproton_0_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_0_dis_cent0010 = new TH1F("hhptpid_tfec_posproton_0_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_0_dis_cent1020 = new TH1F("hhptpid_tfec_posproton_0_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_0_dis_cent2040 = new TH1F("hhptpid_tfec_posproton_0_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_0_dis_cent4060 = new TH1F("hhptpid_tfec_posproton_0_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_0_dis_cent6092 = new TH1F("hhptpid_tfec_posproton_0_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_0_dis_cent0010 = new TH1F("hhptpid_tfec_negproton_0_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_0_dis_cent1020 = new TH1F("hhptpid_tfec_negproton_0_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_0_dis_cent2040 = new TH1F("hhptpid_tfec_negproton_0_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_0_dis_cent4060 = new TH1F("hhptpid_tfec_negproton_0_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_0_dis_cent6092 = new TH1F("hhptpid_tfec_negproton_0_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   TH1F *hhptpid_tofw_posproton_1_dis_cent0010 = new TH1F("hhptpid_tofw_posproton_1_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_1_dis_cent1020 = new TH1F("hhptpid_tofw_posproton_1_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_1_dis_cent2040 = new TH1F("hhptpid_tofw_posproton_1_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_1_dis_cent4060 = new TH1F("hhptpid_tofw_posproton_1_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_1_dis_cent6092 = new TH1F("hhptpid_tofw_posproton_1_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_1_dis_cent0010 = new TH1F("hhptpid_tofw_negproton_1_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_1_dis_cent1020 = new TH1F("hhptpid_tofw_negproton_1_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_1_dis_cent2040 = new TH1F("hhptpid_tofw_negproton_1_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_1_dis_cent4060 = new TH1F("hhptpid_tofw_negproton_1_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_1_dis_cent6092 = new TH1F("hhptpid_tofw_negproton_1_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_1_dis_cent0010 = new TH1F("hhptpid_tfec_posproton_1_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_1_dis_cent1020 = new TH1F("hhptpid_tfec_posproton_1_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_1_dis_cent2040 = new TH1F("hhptpid_tfec_posproton_1_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_1_dis_cent4060 = new TH1F("hhptpid_tfec_posproton_1_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_1_dis_cent6092 = new TH1F("hhptpid_tfec_posproton_1_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_1_dis_cent0010 = new TH1F("hhptpid_tfec_negproton_1_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_1_dis_cent1020 = new TH1F("hhptpid_tfec_negproton_1_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_1_dis_cent2040 = new TH1F("hhptpid_tfec_negproton_1_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_1_dis_cent4060 = new TH1F("hhptpid_tfec_negproton_1_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_1_dis_cent6092 = new TH1F("hhptpid_tfec_negproton_1_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   TH1F *hhptpid_tofw_posproton_2_dis_cent0010 = new TH1F("hhptpid_tofw_posproton_2_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_2_dis_cent1020 = new TH1F("hhptpid_tofw_posproton_2_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_2_dis_cent2040 = new TH1F("hhptpid_tofw_posproton_2_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_2_dis_cent4060 = new TH1F("hhptpid_tofw_posproton_2_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_2_dis_cent6092 = new TH1F("hhptpid_tofw_posproton_2_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_2_dis_cent0010 = new TH1F("hhptpid_tofw_negproton_2_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_2_dis_cent1020 = new TH1F("hhptpid_tofw_negproton_2_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_2_dis_cent2040 = new TH1F("hhptpid_tofw_negproton_2_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_2_dis_cent4060 = new TH1F("hhptpid_tofw_negproton_2_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_2_dis_cent6092 = new TH1F("hhptpid_tofw_negproton_2_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_2_dis_cent0010 = new TH1F("hhptpid_tfec_posproton_2_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_2_dis_cent1020 = new TH1F("hhptpid_tfec_posproton_2_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_2_dis_cent2040 = new TH1F("hhptpid_tfec_posproton_2_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_2_dis_cent4060 = new TH1F("hhptpid_tfec_posproton_2_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_2_dis_cent6092 = new TH1F("hhptpid_tfec_posproton_2_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_2_dis_cent0010 = new TH1F("hhptpid_tfec_negproton_2_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_2_dis_cent1020 = new TH1F("hhptpid_tfec_negproton_2_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_2_dis_cent2040 = new TH1F("hhptpid_tfec_negproton_2_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_2_dis_cent4060 = new TH1F("hhptpid_tfec_negproton_2_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_2_dis_cent6092 = new TH1F("hhptpid_tfec_negproton_2_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   TH1F *hhptpid_tofw_posproton_3_dis_cent0010 = new TH1F("hhptpid_tofw_posproton_3_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_3_dis_cent1020 = new TH1F("hhptpid_tofw_posproton_3_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_3_dis_cent2040 = new TH1F("hhptpid_tofw_posproton_3_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_3_dis_cent4060 = new TH1F("hhptpid_tofw_posproton_3_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_3_dis_cent6092 = new TH1F("hhptpid_tofw_posproton_3_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_3_dis_cent0010 = new TH1F("hhptpid_tofw_negproton_3_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_3_dis_cent1020 = new TH1F("hhptpid_tofw_negproton_3_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_3_dis_cent2040 = new TH1F("hhptpid_tofw_negproton_3_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_3_dis_cent4060 = new TH1F("hhptpid_tofw_negproton_3_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_3_dis_cent6092 = new TH1F("hhptpid_tofw_negproton_3_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_3_dis_cent0010 = new TH1F("hhptpid_tfec_posproton_3_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_3_dis_cent1020 = new TH1F("hhptpid_tfec_posproton_3_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_3_dis_cent2040 = new TH1F("hhptpid_tfec_posproton_3_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_3_dis_cent4060 = new TH1F("hhptpid_tfec_posproton_3_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_3_dis_cent6092 = new TH1F("hhptpid_tfec_posproton_3_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_3_dis_cent0010 = new TH1F("hhptpid_tfec_negproton_3_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_3_dis_cent1020 = new TH1F("hhptpid_tfec_negproton_3_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_3_dis_cent2040 = new TH1F("hhptpid_tfec_negproton_3_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_3_dis_cent4060 = new TH1F("hhptpid_tfec_negproton_3_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_3_dis_cent6092 = new TH1F("hhptpid_tfec_negproton_3_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   TH1F *hhptpid_tofw_posproton_4_dis_cent0010 = new TH1F("hhptpid_tofw_posproton_4_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_4_dis_cent1020 = new TH1F("hhptpid_tofw_posproton_4_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_4_dis_cent2040 = new TH1F("hhptpid_tofw_posproton_4_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_4_dis_cent4060 = new TH1F("hhptpid_tofw_posproton_4_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_4_dis_cent6092 = new TH1F("hhptpid_tofw_posproton_4_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_4_dis_cent0010 = new TH1F("hhptpid_tofw_negproton_4_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_4_dis_cent1020 = new TH1F("hhptpid_tofw_negproton_4_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_4_dis_cent2040 = new TH1F("hhptpid_tofw_negproton_4_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_4_dis_cent4060 = new TH1F("hhptpid_tofw_negproton_4_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_4_dis_cent6092 = new TH1F("hhptpid_tofw_negproton_4_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_4_dis_cent0010 = new TH1F("hhptpid_tfec_posproton_4_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_4_dis_cent1020 = new TH1F("hhptpid_tfec_posproton_4_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_4_dis_cent2040 = new TH1F("hhptpid_tfec_posproton_4_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_4_dis_cent4060 = new TH1F("hhptpid_tfec_posproton_4_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_4_dis_cent6092 = new TH1F("hhptpid_tfec_posproton_4_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_4_dis_cent0010 = new TH1F("hhptpid_tfec_negproton_4_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_4_dis_cent1020 = new TH1F("hhptpid_tfec_negproton_4_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_4_dis_cent2040 = new TH1F("hhptpid_tfec_negproton_4_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_4_dis_cent4060 = new TH1F("hhptpid_tfec_negproton_4_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_4_dis_cent6092 = new TH1F("hhptpid_tfec_negproton_4_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   TH1F *hhptpid_tofw_posproton_5_dis_cent0010 = new TH1F("hhptpid_tofw_posproton_5_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_5_dis_cent1020 = new TH1F("hhptpid_tofw_posproton_5_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_5_dis_cent2040 = new TH1F("hhptpid_tofw_posproton_5_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_5_dis_cent4060 = new TH1F("hhptpid_tofw_posproton_5_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_posproton_5_dis_cent6092 = new TH1F("hhptpid_tofw_posproton_5_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_5_dis_cent0010 = new TH1F("hhptpid_tofw_negproton_5_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_5_dis_cent1020 = new TH1F("hhptpid_tofw_negproton_5_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_5_dis_cent2040 = new TH1F("hhptpid_tofw_negproton_5_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_5_dis_cent4060 = new TH1F("hhptpid_tofw_negproton_5_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tofw_negproton_5_dis_cent6092 = new TH1F("hhptpid_tofw_negproton_5_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_5_dis_cent0010 = new TH1F("hhptpid_tfec_posproton_5_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_5_dis_cent1020 = new TH1F("hhptpid_tfec_posproton_5_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_5_dis_cent2040 = new TH1F("hhptpid_tfec_posproton_5_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_5_dis_cent4060 = new TH1F("hhptpid_tfec_posproton_5_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_posproton_5_dis_cent6092 = new TH1F("hhptpid_tfec_posproton_5_dis_cent6092", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_5_dis_cent0010 = new TH1F("hhptpid_tfec_negproton_5_dis_cent0010", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_5_dis_cent1020 = new TH1F("hhptpid_tfec_negproton_5_dis_cent1020", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_5_dis_cent2040 = new TH1F("hhptpid_tfec_negproton_5_dis_cent2040", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_5_dis_cent4060 = new TH1F("hhptpid_tfec_negproton_5_dis_cent4060", "...", 100, 0.0, 10.0);
>   TH1F *hhptpid_tfec_negproton_5_dis_cent6092 = new TH1F("hhptpid_tfec_negproton_5_dis_cent6092", "...", 100, 0.0, 10.0);
> 
>   // ---
> 
>   TH2F *sigma_tofw_bk_nn_pos = new TH2F("sigma_tofw_bk_nn_pos","radial sigma vs pT", 100, 0, 10, 100, 0, 10);
>   TH2F *sigma_tofw_bk_nn_neg = new TH2F("sigma_tofw_bk_nn_neg","radial sigma vs pT", 100, 0, 10, 100, 0, 10);
>   TH2F *sigma_tofw_si_nn_pos = new TH2F("sigma_tofw_si_nn_pos","radial sigma vs pT", 100, 0, 10, 100, 0, 10);
>   TH2F *sigma_tofw_si_nn_neg = new TH2F("sigma_tofw_si_nn_neg","radial sigma vs pT", 100, 0, 10, 100, 0, 10);
>   TH2F *sigma_tofw_sj_nn_pos = new TH2F("sigma_tofw_sj_nn_pos","radial sigma vs pT", 100, 0, 10, 100, 0, 10);
>   TH2F *sigma_tofw_sj_nn_neg = new TH2F("sigma_tofw_sj_nn_neg","radial sigma vs pT", 100, 0, 10, 100, 0, 10);
>   TH2F *sigma_tofw_fr_nn_pos = new TH2F("sigma_tofw_fr_nn_pos","radial sigma vs pT", 100, 0, 10, 100, 0, 10);
>   TH2F *sigma_tofw_fr_nn_neg = new TH2F("sigma_tofw_fr_nn_neg","radial sigma vs pT", 100, 0, 10, 100, 0, 10);
> 
> 
> 
>   // ---------------------------- //
>   // --- Done with Histograms --- //
>   // ---------------------------- //
> 
960c1560
<   if(!inFile)
---
>   if(!fin)
963c1563
<       exit(0);
---
>       return 1;
976d1575
< 	  //exit(0);
986d1584
< 	  //exit(0); 
1011c1609
< 	  //float bbcz = ktree->bbcz;
---
> 	  float bbcz = ktree->bbcz;
1015a1614,1616
> 	  hhcent->Fill(cent);
> 	  hhbbcz->Fill(bbcz);
> 
1102a1704
> 	      float sigma_tofw = sqrt(tofwsdz*tofwsdz+tofwsdphi*tofwsdphi);// NEW!!!
1180,1184c1782,1788
< 	      float ppc1x   = ktree->HadronTracks_ppc1x[itrk];
< 	      float ppc1y   = ktree->HadronTracks_ppc1y[itrk];
< 	      float ppc1z   = ktree->HadronTracks_ppc1z[itrk];
< 	      float pc1z    = ppc1z;
< 	      float pc1phi  = atan2(ppc1y,ppc1x);  
---
> 	      // float ppc1x   = ktree->HadronTracks_ppc1x[itrk];
> 	      // float ppc1y   = ktree->HadronTracks_ppc1y[itrk];
> 	      // float ppc1z   = ktree->HadronTracks_ppc1z[itrk];
> 	      // float pc1z    = ppc1z;
> 	      // float pc1phi  = atan2(ppc1y,ppc1x);  
> 	      float pc1z    = ktree->HadronTracks_pc1z[itrk]; // NEW
> 	      float pc1phi  = ktree->HadronTracks_pc1phi[itrk]; // NEW
1198c1802
< 	      // float pc2z    = ppc2z -pc2dz;
---
> 	      // float pc2z    = ppc2z - pc2dz;
1199a1804,1805
> 	      // float pc2z    = ktree->HadronTracks_pc2z[itrk]; // NEW
> 	      // float pc2phi  = ktree->HadronTracks_pc2phi[itrk]; // NEW
1207,1213c1813,1822
< 	      float ppc3x   = ktree->HadronTracks_ppc3x[itrk];
< 	      float ppc3y   = ktree->HadronTracks_ppc3y[itrk];
< 	      float ppc3z   = ktree->HadronTracks_ppc3z[itrk];
< 	      float pc3dz   = ktree->HadronTracks_pc3dz[itrk];
< 	      float pc3dphi = ktree->HadronTracks_pc3dphi[itrk];
< 	      float pc3z    = ppc3z - pc3dz;
< 	      float pc3phi  = atan2(ppc3y,ppc3x) - pc3dphi;
---
> 	      // float ppc3x   = ktree->HadronTracks_ppc3x[itrk];
> 	      // float ppc3y   = ktree->HadronTracks_ppc3y[itrk];
> 	      // float ppc3z   = ktree->HadronTracks_ppc3z[itrk];
> 	      // float pc3dz   = ktree->HadronTracks_pc3dz[itrk];
> 	      // float pc3dphi = ktree->HadronTracks_pc3dphi[itrk];
> 	      // float pc3z    = ppc3z - pc3dz;
> 	      // float pc3phi  = atan2(ppc3y,ppc3x) - pc3dphi;
> 	      float pc3z    = ktree->HadronTracks_pc3z[itrk]; // NEW
> 	      float pc3phi  = ktree->HadronTracks_pc3phi[itrk]; // NEW
> 	      //pc3phi = pi/2 - pc3phi; // TEMP!
1222,1228c1831,1840
< 	      float ptofwx   = ktree->HadronTracks_ptofwx[itrk];
< 	      float ptofwy   = ktree->HadronTracks_ptofwy[itrk];
< 	      float ptofwz   = ktree->HadronTracks_ptofwz[itrk];
< 	      float tofwdz   = ktree->HadronTracks_tofwdz[itrk];
< 	      float tofwdphi = ktree->HadronTracks_tofwdphi[itrk];
< 	      float tofwz    = ptofwz - tofwdz;
< 	      float tofwphi  = atan2(ptofwy,ptofwx) - tofwdphi;
---
> 	      // float ptofwx   = ktree->HadronTracks_ptofwx[itrk];
> 	      // float ptofwy   = ktree->HadronTracks_ptofwy[itrk];
> 	      // float ptofwz   = ktree->HadronTracks_ptofwz[itrk];
> 	      // float tofwdz   = ktree->HadronTracks_tofwdz[itrk];
> 	      // float tofwdphi = ktree->HadronTracks_tofwdphi[itrk];
> 	      // float tofwz    = ptofwz - tofwdz;
> 	      // float tofwphi  = atan2(ptofwy,ptofwx) - tofwdphi;
> 	      float tofwz    = ktree->HadronTracks_tofwz[itrk]; // NEW
> 	      float tofwphi  = ktree->HadronTracks_tofwphi[itrk]; // NEW
> 	      tofwphi = pi/2 - tofwphi; // TEMP!
1233c1845
< 	      float beta     = pltofw/ttofw/phbeta;
---
> 	      //float beta     = pltofw/ttofw/phbeta; // unused for now
1236c1848
< 	      bool adc_beta  = qtofw>(20*((float)pow(beta,(float)-2.7)));
---
> 	      //bool adc_beta  = qtofw>(20*((float)pow(beta,(float)-2.7))); // unused for now
1242a1855,1881
> 	      // --- EMC && RICH
> 
> 	      float emcz      = ktree->HadronTracks_emcz[itrk];
> 	      float emcphi    = ktree->HadronTracks_emcphi[itrk];
> 	      //emcphi = pi/2 - emcphi;
> 	      float emcsdz      = ktree->HadronTracks_emcsdz[itrk];
> 	      float emcsdphi    = ktree->HadronTracks_emcsdphi[itrk];
> 	      int warnmap       = ktree->HadronTracks_warnmap[itrk];
> 	      int deadmap       = ktree->HadronTracks_deadmap[itrk];
> 	      bool emc_matching = fabs(emcsdphi)<2.0 && fabs(emcsdz)<2.0;
> 	      float ecore = ktree->HadronTracks_ecore[itrk];
> 	      float ecent = ktree->HadronTracks_ecent[itrk];
> 	      float emce  = ktree->HadronTracks_emce[itrk];
> 	      //float ep = ecore/mom;
> 	      //float ep = ecent/mom; // how long has this been here?
> 	      float ep = ecore/pT; // NEW
> 	      bool goodemc = GoodEMC(emcz,emcphi);
> 	      //bool sysgoodemc = SysGoodEMC(emcz,emcphi); // unused for now
> 	      bool good_emc = emc_matching && goodemc && deadmap==0 && warnmap==0; // dead and warn redundant?
> 	      if(emc_matching&&deadmap==0&&warnmap==0) EMCZedPhiDis->Fill(emcz,emcphi);
> 	      if(emc_matching&&good_emc) EMCZedPhiNewDis->Fill(emcz,emcphi);
> 	      // COME BACK HERE!!!
> 	      //float n0 = ktree->HadronTracks_n0[itrk]; // GONE
> 	      //bool DeadMap = ((tofwphi>0.535&&tofwz<-113) || (tofwphi>0.453&&tofwphi<0.505 && tofwz>-102&&tofwz<-76));
> 
> 	      // ---
> 
1251a1891
> 	      // CUTS ARE DEFINTED HERE!
1258a1899
> 
1357,1363d1997
< 	      // already declared above...
< 	      // bool regular_cuts = tfw_matching && pc3_matching && good_pc1 && good_pc3 && good_adc;
< 	      // bool syst_tfwmatch = pc3_matching && good_pc1 && good_pc3 && good_adc;	
< 	      // bool syst_pc3match = tfw_matching && good_pc1 && good_pc3 && good_adc;
< 	      // bool syst_pc3fiducial = tfw_matching && pc3_matching && good_pc1 && good_adc;
< 	      // bool syst_pc1fiducial = tfw_matching && pc3_matching && good_pc3 && good_adc;
< 	      // bool syst_goodadc = tfw_matching && pc3_matching && good_pc1 && good_pc3;
1369,1371c2003,2005
< 	      float isPiNew = isPionNew(pT,m2tofw);
< 	      float isKNew  = isKaonNew(pT,m2tofw);
< 	      float isPNew  = isProtonNew(pT,m2tofw);
---
> 	      float isPiANA = isPionANA(pT,m2tofw);
> 	      float isKANA  = isKaonANA(pT,m2tofw);
> 	      float isPANA  = isProtonANA(pT,m2tofw);
1377,1379c2011,2024
< 	      bool isPi = (isPiLow>=-2&&isPiLow<=2);
< 	      bool isK = (isKLow>=-2&&isKLow<=2);
< 	      bool isP = (isPLow>=-2&&isPLow<=2);
---
> 	      float isPiLME = isPionLME(pT,m2tofw);
> 	      float isKLME  = isKaonLME(pT,m2tofw);
> 	      float isPLME  = isProtonLME(pT,m2tofw);
> 
> 	      float isPiPDI = isPionPDI(pT,m2tofw);// only one that's different
> 	      float isKPDI  = isKaonLME(pT,m2tofw);// LME
> 	      float isPPDI  = isProtonLME(pT,m2tofw);// LME
> 
> 	      //isPiLME /= 0.85; // SUPER TEMP
> 	      //isPiANA /= 0.85; // SUPER TEMP
> 
> 	      bool isPi = (isPiLME>=-2&&isPiLME<=2);
> 	      bool isK = (isKLME>=-2&&isKLME<=2);
> 	      bool isP = (isPLME>=-2&&isPLME<=2);
1390,1425c2035,2070
< 		  if(cent> 0&&cent<=10&&charge>0) isPi_dis_pos_cent0010->Fill(pT,isPiLow);//important
< 		  if(cent> 0&&cent<=10&&charge<0) isPi_dis_neg_cent0010->Fill(pT,isPiLow);//important
< 		  if(cent>10&&cent<=20&&charge>0) isPi_dis_pos_cent1020->Fill(pT,isPiLow);//important
< 		  if(cent>10&&cent<=20&&charge<0) isPi_dis_neg_cent1020->Fill(pT,isPiLow);//important
< 		  if(cent>20&&cent<=40&&charge>0) isPi_dis_pos_cent2040->Fill(pT,isPiLow);//important
< 		  if(cent>20&&cent<=40&&charge<0) isPi_dis_neg_cent2040->Fill(pT,isPiLow);//important
< 		  if(cent>40&&cent<=60&&charge>0) isPi_dis_pos_cent4060->Fill(pT,isPiLow);//important
< 		  if(cent>40&&cent<=60&&charge<0) isPi_dis_neg_cent4060->Fill(pT,isPiLow);//important
< 		  if(cent>60&&cent<=92&&charge>0) isPi_dis_pos_cent6092->Fill(pT,isPiLow);//important
< 		  if(cent>60&&cent<=92&&charge<0) isPi_dis_neg_cent6092->Fill(pT,isPiLow);//important
< 		  if(cent> 0&&cent<=10&&charge>0) isK_dis_pos_cent0010->Fill(pT,isKLow);//important
< 		  if(cent> 0&&cent<=10&&charge<0) isK_dis_neg_cent0010->Fill(pT,isKLow);//important
< 		  if(cent>10&&cent<=20&&charge>0) isK_dis_pos_cent1020->Fill(pT,isKLow);//important
< 		  if(cent>10&&cent<=20&&charge<0) isK_dis_neg_cent1020->Fill(pT,isKLow);//important
< 		  if(cent>20&&cent<=40&&charge>0) isK_dis_pos_cent2040->Fill(pT,isKLow);//important
< 		  if(cent>20&&cent<=40&&charge<0) isK_dis_neg_cent2040->Fill(pT,isKLow);//important
< 		  if(cent>40&&cent<=60&&charge>0) isK_dis_pos_cent4060->Fill(pT,isKLow);//important
< 		  if(cent>40&&cent<=60&&charge<0) isK_dis_neg_cent4060->Fill(pT,isKLow);//important
< 		  if(cent>60&&cent<=92&&charge>0) isK_dis_pos_cent6092->Fill(pT,isKLow);//important
< 		  if(cent>60&&cent<=92&&charge<0) isK_dis_neg_cent6092->Fill(pT,isKLow);//important
< 		  if(cent> 0&&cent<=10&&charge>0) isP_dis_pos_cent0010->Fill(pT,isPLow);//important
< 		  if(cent> 0&&cent<=10&&charge<0) isP_dis_neg_cent0010->Fill(pT,isPLow);//important
< 		  if(cent>10&&cent<=20&&charge>0) isP_dis_pos_cent1020->Fill(pT,isPLow);//important
< 		  if(cent>10&&cent<=20&&charge<0) isP_dis_neg_cent1020->Fill(pT,isPLow);//important
< 		  if(cent>20&&cent<=40&&charge>0) isP_dis_pos_cent2040->Fill(pT,isPLow);//important
< 		  if(cent>20&&cent<=40&&charge<0) isP_dis_neg_cent2040->Fill(pT,isPLow);//important
< 		  if(cent>40&&cent<=60&&charge>0) isP_dis_pos_cent4060->Fill(pT,isPLow);//important
< 		  if(cent>40&&cent<=60&&charge<0) isP_dis_neg_cent4060->Fill(pT,isPLow);//important
< 		  if(cent>60&&cent<=92&&charge>0) isP_dis_pos_cent6092->Fill(pT,isPLow);//important
< 		  if(cent>60&&cent<=92&&charge<0) isP_dis_neg_cent6092->Fill(pT,isPLow);//important
< 		  if(charge>0) isPi_dis_pos->Fill(pT,isPiLow);//important
< 		  if(charge<0) isPi_dis_neg->Fill(pT,isPiLow);//important
< 		  if(charge>0) isK_dis_pos->Fill(pT,isKLow);
< 		  if(charge<0) isK_dis_neg->Fill(pT,isKLow);
< 		  if(charge>0) isP_dis_pos->Fill(pT,isPLow);
< 		  if(charge<0) isP_dis_neg->Fill(pT,isPLow);
---
> 		  if(cent> 0&&cent<=10&&charge>0) isPi_dis_pos_cent0010->Fill(pT,isPiLME);//important
> 		  if(cent> 0&&cent<=10&&charge<0) isPi_dis_neg_cent0010->Fill(pT,isPiLME);//important
> 		  if(cent>10&&cent<=20&&charge>0) isPi_dis_pos_cent1020->Fill(pT,isPiLME);//important
> 		  if(cent>10&&cent<=20&&charge<0) isPi_dis_neg_cent1020->Fill(pT,isPiLME);//important
> 		  if(cent>20&&cent<=40&&charge>0) isPi_dis_pos_cent2040->Fill(pT,isPiLME);//important
> 		  if(cent>20&&cent<=40&&charge<0) isPi_dis_neg_cent2040->Fill(pT,isPiLME);//important
> 		  if(cent>40&&cent<=60&&charge>0) isPi_dis_pos_cent4060->Fill(pT,isPiLME);//important
> 		  if(cent>40&&cent<=60&&charge<0) isPi_dis_neg_cent4060->Fill(pT,isPiLME);//important
> 		  if(cent>60&&cent<=92&&charge>0) isPi_dis_pos_cent6092->Fill(pT,isPiLME);//important
> 		  if(cent>60&&cent<=92&&charge<0) isPi_dis_neg_cent6092->Fill(pT,isPiLME);//important
> 		  if(cent> 0&&cent<=10&&charge>0) isK_dis_pos_cent0010->Fill(pT,isKLME);//important
> 		  if(cent> 0&&cent<=10&&charge<0) isK_dis_neg_cent0010->Fill(pT,isKLME);//important
> 		  if(cent>10&&cent<=20&&charge>0) isK_dis_pos_cent1020->Fill(pT,isKLME);//important
> 		  if(cent>10&&cent<=20&&charge<0) isK_dis_neg_cent1020->Fill(pT,isKLME);//important
> 		  if(cent>20&&cent<=40&&charge>0) isK_dis_pos_cent2040->Fill(pT,isKLME);//important
> 		  if(cent>20&&cent<=40&&charge<0) isK_dis_neg_cent2040->Fill(pT,isKLME);//important
> 		  if(cent>40&&cent<=60&&charge>0) isK_dis_pos_cent4060->Fill(pT,isKLME);//important
> 		  if(cent>40&&cent<=60&&charge<0) isK_dis_neg_cent4060->Fill(pT,isKLME);//important
> 		  if(cent>60&&cent<=92&&charge>0) isK_dis_pos_cent6092->Fill(pT,isKLME);//important
> 		  if(cent>60&&cent<=92&&charge<0) isK_dis_neg_cent6092->Fill(pT,isKLME);//important
> 		  if(cent> 0&&cent<=10&&charge>0) isP_dis_pos_cent0010->Fill(pT,isPLME);//important
> 		  if(cent> 0&&cent<=10&&charge<0) isP_dis_neg_cent0010->Fill(pT,isPLME);//important
> 		  if(cent>10&&cent<=20&&charge>0) isP_dis_pos_cent1020->Fill(pT,isPLME);//important
> 		  if(cent>10&&cent<=20&&charge<0) isP_dis_neg_cent1020->Fill(pT,isPLME);//important
> 		  if(cent>20&&cent<=40&&charge>0) isP_dis_pos_cent2040->Fill(pT,isPLME);//important
> 		  if(cent>20&&cent<=40&&charge<0) isP_dis_neg_cent2040->Fill(pT,isPLME);//important
> 		  if(cent>40&&cent<=60&&charge>0) isP_dis_pos_cent4060->Fill(pT,isPLME);//important
> 		  if(cent>40&&cent<=60&&charge<0) isP_dis_neg_cent4060->Fill(pT,isPLME);//important
> 		  if(cent>60&&cent<=92&&charge>0) isP_dis_pos_cent6092->Fill(pT,isPLME);//important
> 		  if(cent>60&&cent<=92&&charge<0) isP_dis_neg_cent6092->Fill(pT,isPLME);//important
> 		  if(charge>0) isPi_dis_pos->Fill(pT,isPiLME);//important
> 		  if(charge<0) isPi_dis_neg->Fill(pT,isPiLME);//important
> 		  if(charge>0) isK_dis_pos->Fill(pT,isKLME);
> 		  if(charge<0) isK_dis_neg->Fill(pT,isKLME);
> 		  if(charge>0) isP_dis_pos->Fill(pT,isPLME);
> 		  if(charge<0) isP_dis_neg->Fill(pT,isPLME);
1437a2083,2098
> 		  // ep cut
> 		  if(ecore/pT>0.2)
> 		    {
> 		      if(charge>0) m2pTdis_epc_pos->Fill(pT,m2tofw);
> 		      if(charge<0) m2pTdis_epc_neg->Fill(pT,m2tofw);
> 		      if(charge>0&&ICENT==0) m2pTdis_epc_pos_cent0->Fill(pT,m2tofw);
> 		      if(charge<0&&ICENT==0) m2pTdis_epc_neg_cent0->Fill(pT,m2tofw);
> 		      if(charge>0&&ICENT==1) m2pTdis_epc_pos_cent1->Fill(pT,m2tofw);
> 		      if(charge<0&&ICENT==1) m2pTdis_epc_neg_cent1->Fill(pT,m2tofw);
> 		      if(charge>0&&ICENT==2) m2pTdis_epc_pos_cent2->Fill(pT,m2tofw);
> 		      if(charge<0&&ICENT==2) m2pTdis_epc_neg_cent2->Fill(pT,m2tofw);
> 		      if(charge>0&&ICENT==3) m2pTdis_epc_pos_cent3->Fill(pT,m2tofw);
> 		      if(charge<0&&ICENT==3) m2pTdis_epc_neg_cent3->Fill(pT,m2tofw);
> 		      if(charge>0&&ICENT==4) m2pTdis_epc_pos_cent4->Fill(pT,m2tofw);
> 		      if(charge<0&&ICENT==4) m2pTdis_epc_neg_cent4->Fill(pT,m2tofw);
> 		    }
1440,1450d2100
< 	      // --- EMC && RICH
< 
< 	      //float emcsdz      = ktree->HadronTracks_emcsdz[itrk];
< 	      //float emcsdphi    = ktree->HadronTracks_emcsdphi[itrk];
< 	      //bool emc_matching = fabs(emcsdphi)<2.0 && fabs(emcsdz)<2.0;
< 	      float ecore = ktree->HadronTracks_ecore[itrk];
< 	      //float ecent = ktree->HadronTracks_ecent[itrk];
< 	      float ep = ecore/mom;
< 	      float n0 = ktree->HadronTracks_n0[itrk];
< 	      bool DeadMap = ((tofwphi>0.535&&tofwz<-113) ||
< 			       (tofwphi>0.453&&tofwphi<0.505 && tofwz>-102&&tofwz<-76));
1471,1474c2121,2124
< 	      // bool dis0 = isPiLow>=-2 && isPiLow<=2 && isKLow<=-2;
< 	      // bool dis1 = isPiNew>=-2 && isPiNew<=2 && isKNew<=-2;
< 	      // bool dis2 = isPiLow>=-2 && isPiLow<=2;
< 	      // bool dis3 = isPiNew>=-2 && isPiNew<=2;
---
> 	      // bool dis0 = isPiLME>=-2 && isPiLME<=2 && isKLME<=-2 && good_emc;
> 	      // bool dis1 = isPiANA>=-2 && isPiANA<=2 && isKANA<=-2 && good_emc;
> 	      // bool dis2 = dis0 && ep>0.2;
> 	      // bool dis3 = dis1 && ep>0.2;
1476,1477c2126,2127
< 	      // bool dis4 = isKLow>=-2 && isKLow<=2 && isPiLow>=2 && isPLow<=-2;
< 	      // bool dis5 = isKNew>=-2 && isKNew<=2 && isPiNew>=2 && isPNew<=-2;
---
> 	      // bool dis4 = isKLME>=-2 && isKLME<=2 && isPiLME>=2 && isPLME<=-2;
> 	      // bool dis5 = isKANA>=-2 && isKANA<=2 && isPiANA>=2 && isPANA<=-2;
1479,1482c2129,2132
< 	      // bool dis6 = isPLow>=-2 && isPLow<=2 && isKLow>=2;
< 	      // bool dis7 = isPNew>=-2 && isPNew<=2 && isKNew>=2;
< 	      // bool dis8 = isPLow>=-2 && isPLow<=2;
< 	      // bool dis9 = isPNew>=-2 && isPNew<=2;
---
> 	      // bool dis6 = isPLME>=-2 && isPLME<=2 && isKLME>=2 && good_emc;
> 	      // bool dis7 = isPANA>=-2 && isPANA<=2 && isKANA>=2 && good_emc;
> 	      // bool dis8 = dis6 && ep>0.2;
> 	      // bool dis9 = dis7 && ep>0.2;
1485,1490c2135,2138
< 	      bool dis0 = isPiLow>=-2 && isPiLow<=2 && isKLow<=-2;
< 	      bool dis1 = isPiLow>=-2 && isPiLow<=2 && isKLow<=-2 && ep>0.2 && !DeadMap;
< 	      //bool dis2 = isPiLow>=-2 && isPiLow<=2 && isKLow<=-2 && ep>0.2 && n0<0;
< 	      //bool dis3 = isPiLow>=-2 && isPiLow<=2 && ep>0.2;
< 	      bool dis2 = isPiLow>=-2 && isPiLow<=2;
< 	      bool dis3 = isPiLow>=-2 && isPiLow<=2 && ep>0.2 && !DeadMap;
---
> 	      bool dis0 = isPiLME>=-2 && isPiLME<=2 && isKLME<=-2;
> 	      bool dis1 = isPiLow>=-2 && isPiLow<=2 && isKLow<=-2;
> 	      bool dis2 = dis0 && good_emc && ep>0.2;
> 	      bool dis3 = dis1 && good_emc && ep>0.2;
1492,1493c2140,2141
< 	      bool dis4 = isKLow>=-2 && isKLow<=2 && isPiLow>=2 && isPLow<=-2;
< 	      bool dis5 = isKLow>=-2 && isKLow<=2 && isPiLow>=2 && isPLow<=-2 && ep>0.2 && !DeadMap;
---
> 	      bool dis4 = isKLME>=-2 && isKLME<=2 && isPiLME>=2 && isPLME<=-2;
> 	      bool dis5 = isKLow>=-2 && isKLow<=2 && isPiLow>=2 && isPLow<=-2;
1495,1519c2143,2327
< 	      bool dis6 = isPLow>=-2 && isPLow<=2 && isKLow>=2;
< 	      bool dis7 = isPLow>=-2 && isPLow<=2 && isKLow>=2 && ep>0.2 && !DeadMap;
< 	      bool dis8 = isPLow>=-2 && isPLow<=2;
< 	      bool dis9 = isPLow>=-2 && isPLow<=2 && ep>0.2 && !DeadMap;
< 
< 	      bool piA = isPiLow>=-1.5 && isPiLow<=1.5 && isKLow<=-2;
< 	      bool kaA = isKLow>=-1.5 && isKLow<=1.5 && isPiLow>=2 && isPLow<=-2;
< 	      bool prA = isPLow>=-1.5 && isPLow<=1.5 && isKLow>=2;
< 	      bool piB = isPiLow>=-2 && isPiLow<=2 && isKLow<=-2.5;
< 	      bool kaB = isKLow>=-2 && isKLow<=2 && isPiLow>=2.5 && isPLow<=-2.5;
< 	      bool prB = isPLow>=-2 && isPLow<=2 && isKLow>=2.5;
< 
< 	      // bool piA = isPiLow>=-3 && isPiLow<=3 && isKLow<=-3;
< 	      // bool kaA = isKLow>=-3 && isKLow<=3 && isPiLow>=3 && isPLow<=-3;
< 	      // bool prA = isPLow>=-3 && isPLow<=3 && isKLow>=3;
< 	      // bool piB = isPiLow>=-1 && isPiLow<=1 && isKLow<=-1;
< 	      // bool kaB = isKLow>=-1 && isKLow<=1 && isPiLow>=1 && isPLow<=-1;
< 	      // bool prB = isPLow>=-1 && isPLow<=1 && isKLow>=1;
< 
< 	      // bool regular_cuts = tfw_matching && pc3_matching && good_pc1 && good_pc3 && good_adc;
< 	      // bool syst_tfwmatch = pc3_matching && good_pc1 && good_pc3 && good_adc;	
< 	      // bool syst_pc3match = tfw_matching && good_pc1 && good_pc3 && good_adc;
< 	      // bool syst_pc3fiducial = tfw_matching && pc3_matching && good_pc1 && good_adc;
< 	      // bool syst_pc1fiducial = tfw_matching && pc3_matching && good_pc3 && good_adc;
< 	      // bool syst_goodadc = tfw_matching && pc3_matching && good_pc1 && good_pc3;
---
> 	      bool dis6 = isPLME>=-2 && isPLME<=2 && isKLME>=2;
> 	      bool dis7 = isPLow>=-2 && isPLow<=2 && isKLow>=2;
> 	      bool dis8 = dis6 && good_emc && ep>0.2;
> 	      bool dis9 = dis7 && good_emc && ep>0.2;
> 
> 	      // Shengli
> 
> 	      //pion
> 	      if(charge>0&&dis0) hh_X_ecorept_pospion_centMB->Fill(pT,ecore); // new
> 	      if(charge<0&&dis0) hh_X_ecorept_negpion_centMB->Fill(pT,ecore); // new
> 	      if(cent> 0&&cent<=10&&charge>0&&dis0) hh_X_ecorept_pospion_cent0010->Fill(pT,ecore); // new
> 	      if(cent> 0&&cent<=10&&charge<0&&dis0) hh_X_ecorept_negpion_cent0010->Fill(pT,ecore); // new
> 	      if(cent>10&&cent<=20&&charge>0&&dis0) hh_X_ecorept_pospion_cent1020->Fill(pT,ecore); // new
> 	      if(cent>10&&cent<=20&&charge<0&&dis0) hh_X_ecorept_negpion_cent1020->Fill(pT,ecore); // new
> 	      if(cent>20&&cent<=40&&charge>0&&dis0) hh_X_ecorept_pospion_cent2040->Fill(pT,ecore); // new
> 	      if(cent>20&&cent<=40&&charge<0&&dis0) hh_X_ecorept_negpion_cent2040->Fill(pT,ecore); // new
> 	      if(cent>40&&cent<=60&&charge>0&&dis0) hh_X_ecorept_pospion_cent4060->Fill(pT,ecore); // new
> 	      if(cent>40&&cent<=60&&charge<0&&dis0) hh_X_ecorept_negpion_cent4060->Fill(pT,ecore); // new
> 	      if(cent>60&&cent<=92&&charge>0&&dis0) hh_X_ecorept_pospion_cent6092->Fill(pT,ecore); // new
> 	      if(cent>60&&cent<=92&&charge<0&&dis0) hh_X_ecorept_negpion_cent6092->Fill(pT,ecore); // new
> 	      //
> 	      if(charge>0&&dis0) hh_X_spectpt_pospion_centMB->Fill(pT);
> 	      if(charge<0&&dis0) hh_X_spectpt_negpion_centMB->Fill(pT);
> 	      if(cent> 0&&cent<=10&&charge>0&&dis0) hh_X_spectpt_pospion_cent0010->Fill(pT);
> 	      if(cent> 0&&cent<=10&&charge<0&&dis0) hh_X_spectpt_negpion_cent0010->Fill(pT);
> 	      if(cent>10&&cent<=20&&charge>0&&dis0) hh_X_spectpt_pospion_cent1020->Fill(pT);
> 	      if(cent>10&&cent<=20&&charge<0&&dis0) hh_X_spectpt_negpion_cent1020->Fill(pT);
> 	      if(cent>20&&cent<=40&&charge>0&&dis0) hh_X_spectpt_pospion_cent2040->Fill(pT);
> 	      if(cent>20&&cent<=40&&charge<0&&dis0) hh_X_spectpt_negpion_cent2040->Fill(pT);
> 	      if(cent>40&&cent<=60&&charge>0&&dis0) hh_X_spectpt_pospion_cent4060->Fill(pT);
> 	      if(cent>40&&cent<=60&&charge<0&&dis0) hh_X_spectpt_negpion_cent4060->Fill(pT);
> 	      if(cent>60&&cent<=92&&charge>0&&dis0) hh_X_spectpt_pospion_cent6092->Fill(pT);
> 	      if(cent>60&&cent<=92&&charge<0&&dis0) hh_X_spectpt_negpion_cent6092->Fill(pT);
> 	      //
> 	      if(charge>0&&dis0&&ecore/pT>0.2) hh_X_specept_pospion_centMB->Fill(pT);
> 	      if(charge<0&&dis0&&ecore/pT>0.2) hh_X_specept_negpion_centMB->Fill(pT);
> 	      if(cent> 0&&cent<=10&&charge>0&&dis0&&ecore/pT>0.2) hh_X_specept_pospion_cent0010->Fill(pT);
> 	      if(cent> 0&&cent<=10&&charge<0&&dis0&&ecore/pT>0.2) hh_X_specept_negpion_cent0010->Fill(pT);
> 	      if(cent>10&&cent<=20&&charge>0&&dis0&&ecore/pT>0.2) hh_X_specept_pospion_cent1020->Fill(pT);
> 	      if(cent>10&&cent<=20&&charge<0&&dis0&&ecore/pT>0.2) hh_X_specept_negpion_cent1020->Fill(pT);
> 	      if(cent>20&&cent<=40&&charge>0&&dis0&&ecore/pT>0.2) hh_X_specept_pospion_cent2040->Fill(pT);
> 	      if(cent>20&&cent<=40&&charge<0&&dis0&&ecore/pT>0.2) hh_X_specept_negpion_cent2040->Fill(pT);
> 	      if(cent>40&&cent<=60&&charge>0&&dis0&&ecore/pT>0.2) hh_X_specept_pospion_cent4060->Fill(pT);
> 	      if(cent>40&&cent<=60&&charge<0&&dis0&&ecore/pT>0.2) hh_X_specept_negpion_cent4060->Fill(pT);
> 	      if(cent>60&&cent<=92&&charge>0&&dis0&&ecore/pT>0.2) hh_X_specept_pospion_cent6092->Fill(pT);
> 	      if(cent>60&&cent<=92&&charge<0&&dis0&&ecore/pT>0.2) hh_X_specept_negpion_cent6092->Fill(pT);
> 
> 	      //proton
> 	      if(charge>0&&dis6) hh_X_ecorept_posproton_centMB->Fill(pT,ecore); // new
> 	      if(charge<0&&dis6) hh_X_ecorept_negproton_centMB->Fill(pT,ecore); // new
> 	      if(cent> 0&&cent<=10&&charge>0&&dis6) hh_X_ecorept_posproton_cent0010->Fill(pT,ecore); // new
> 	      if(cent> 0&&cent<=10&&charge<0&&dis6) hh_X_ecorept_negproton_cent0010->Fill(pT,ecore); // new
> 	      if(cent>10&&cent<=20&&charge>0&&dis6) hh_X_ecorept_posproton_cent1020->Fill(pT,ecore); // new
> 	      if(cent>10&&cent<=20&&charge<0&&dis6) hh_X_ecorept_negproton_cent1020->Fill(pT,ecore); // new
> 	      if(cent>20&&cent<=40&&charge>0&&dis6) hh_X_ecorept_posproton_cent2040->Fill(pT,ecore); // new
> 	      if(cent>20&&cent<=40&&charge<0&&dis6) hh_X_ecorept_negproton_cent2040->Fill(pT,ecore); // new
> 	      if(cent>40&&cent<=60&&charge>0&&dis6) hh_X_ecorept_posproton_cent4060->Fill(pT,ecore); // new
> 	      if(cent>40&&cent<=60&&charge<0&&dis6) hh_X_ecorept_negproton_cent4060->Fill(pT,ecore); // new
> 	      if(cent>60&&cent<=92&&charge>0&&dis6) hh_X_ecorept_posproton_cent6092->Fill(pT,ecore); // new
> 	      if(cent>60&&cent<=92&&charge<0&&dis6) hh_X_ecorept_negproton_cent6092->Fill(pT,ecore); // new
> 	      //
> 	      if(charge>0&&dis6) hh_X_spectpt_posproton_centMB->Fill(pT);
> 	      if(charge<0&&dis6) hh_X_spectpt_negproton_centMB->Fill(pT);
> 	      if(cent> 0&&cent<=10&&charge>0&&dis6) hh_X_spectpt_posproton_cent0010->Fill(pT);
> 	      if(cent> 0&&cent<=10&&charge<0&&dis6) hh_X_spectpt_negproton_cent0010->Fill(pT);
> 	      if(cent>10&&cent<=20&&charge>0&&dis6) hh_X_spectpt_posproton_cent1020->Fill(pT);
> 	      if(cent>10&&cent<=20&&charge<0&&dis6) hh_X_spectpt_negproton_cent1020->Fill(pT);
> 	      if(cent>20&&cent<=40&&charge>0&&dis6) hh_X_spectpt_posproton_cent2040->Fill(pT);
> 	      if(cent>20&&cent<=40&&charge<0&&dis6) hh_X_spectpt_negproton_cent2040->Fill(pT);
> 	      if(cent>40&&cent<=60&&charge>0&&dis6) hh_X_spectpt_posproton_cent4060->Fill(pT);
> 	      if(cent>40&&cent<=60&&charge<0&&dis6) hh_X_spectpt_negproton_cent4060->Fill(pT);
> 	      if(cent>60&&cent<=92&&charge>0&&dis6) hh_X_spectpt_posproton_cent6092->Fill(pT);
> 	      if(cent>60&&cent<=92&&charge<0&&dis6) hh_X_spectpt_negproton_cent6092->Fill(pT);
> 	      //
> 	      if(charge>0&&dis6&&ecore/pT>0.2) hh_X_specept_posproton_centMB->Fill(pT);
> 	      if(charge<0&&dis6&&ecore/pT>0.2) hh_X_specept_negproton_centMB->Fill(pT);
> 	      if(cent> 0&&cent<=10&&charge>0&&dis6&&ecore/pT>0.2) hh_X_specept_posproton_cent0010->Fill(pT);
> 	      if(cent> 0&&cent<=10&&charge<0&&dis6&&ecore/pT>0.2) hh_X_specept_negproton_cent0010->Fill(pT);
> 	      if(cent>10&&cent<=20&&charge>0&&dis6&&ecore/pT>0.2) hh_X_specept_posproton_cent1020->Fill(pT);
> 	      if(cent>10&&cent<=20&&charge<0&&dis6&&ecore/pT>0.2) hh_X_specept_negproton_cent1020->Fill(pT);
> 	      if(cent>20&&cent<=40&&charge>0&&dis6&&ecore/pT>0.2) hh_X_specept_posproton_cent2040->Fill(pT);
> 	      if(cent>20&&cent<=40&&charge<0&&dis6&&ecore/pT>0.2) hh_X_specept_negproton_cent2040->Fill(pT);
> 	      if(cent>40&&cent<=60&&charge>0&&dis6&&ecore/pT>0.2) hh_X_specept_posproton_cent4060->Fill(pT);
> 	      if(cent>40&&cent<=60&&charge<0&&dis6&&ecore/pT>0.2) hh_X_specept_negproton_cent4060->Fill(pT);
> 	      if(cent>60&&cent<=92&&charge>0&&dis6&&ecore/pT>0.2) hh_X_specept_posproton_cent6092->Fill(pT);
> 	      if(cent>60&&cent<=92&&charge<0&&dis6&&ecore/pT>0.2) hh_X_specept_negproton_cent6092->Fill(pT);
> 
> 	      // --- now do the same thing with all cuts
> 	      if(regular_cuts&&edge&&inner) // ok
> 		{
> 		  //pion
> 		  if(charge>0&&dis0) hh_Y_ecorept_pospion_centMB->Fill(pT,ecore); // new
> 		  if(charge<0&&dis0) hh_Y_ecorept_negpion_centMB->Fill(pT,ecore); // new
> 		  if(cent> 0&&cent<=10&&charge>0&&dis0) hh_Y_ecorept_pospion_cent0010->Fill(pT,ecore); // new
> 		  if(cent> 0&&cent<=10&&charge<0&&dis0) hh_Y_ecorept_negpion_cent0010->Fill(pT,ecore); // new
> 		  if(cent>10&&cent<=20&&charge>0&&dis0) hh_Y_ecorept_pospion_cent1020->Fill(pT,ecore); // new
> 		  if(cent>10&&cent<=20&&charge<0&&dis0) hh_Y_ecorept_negpion_cent1020->Fill(pT,ecore); // new
> 		  if(cent>20&&cent<=40&&charge>0&&dis0) hh_Y_ecorept_pospion_cent2040->Fill(pT,ecore); // new
> 		  if(cent>20&&cent<=40&&charge<0&&dis0) hh_Y_ecorept_negpion_cent2040->Fill(pT,ecore); // new
> 		  if(cent>40&&cent<=60&&charge>0&&dis0) hh_Y_ecorept_pospion_cent4060->Fill(pT,ecore); // new
> 		  if(cent>40&&cent<=60&&charge<0&&dis0) hh_Y_ecorept_negpion_cent4060->Fill(pT,ecore); // new
> 		  if(cent>60&&cent<=92&&charge>0&&dis0) hh_Y_ecorept_pospion_cent6092->Fill(pT,ecore); // new
> 		  if(cent>60&&cent<=92&&charge<0&&dis0) hh_Y_ecorept_negpion_cent6092->Fill(pT,ecore); // new
> 		  //
> 		  if(charge>0&&dis0) hh_Y_spectpt_pospion_centMB->Fill(pT);
> 		  if(charge<0&&dis0) hh_Y_spectpt_negpion_centMB->Fill(pT);
> 		  if(cent> 0&&cent<=10&&charge>0&&dis0) hh_Y_spectpt_pospion_cent0010->Fill(pT);
> 		  if(cent> 0&&cent<=10&&charge<0&&dis0) hh_Y_spectpt_negpion_cent0010->Fill(pT);
> 		  if(cent>10&&cent<=20&&charge>0&&dis0) hh_Y_spectpt_pospion_cent1020->Fill(pT);
> 		  if(cent>10&&cent<=20&&charge<0&&dis0) hh_Y_spectpt_negpion_cent1020->Fill(pT);
> 		  if(cent>20&&cent<=40&&charge>0&&dis0) hh_Y_spectpt_pospion_cent2040->Fill(pT);
> 		  if(cent>20&&cent<=40&&charge<0&&dis0) hh_Y_spectpt_negpion_cent2040->Fill(pT);
> 		  if(cent>40&&cent<=60&&charge>0&&dis0) hh_Y_spectpt_pospion_cent4060->Fill(pT);
> 		  if(cent>40&&cent<=60&&charge<0&&dis0) hh_Y_spectpt_negpion_cent4060->Fill(pT);
> 		  if(cent>60&&cent<=92&&charge>0&&dis0) hh_Y_spectpt_pospion_cent6092->Fill(pT);
> 		  if(cent>60&&cent<=92&&charge<0&&dis0) hh_Y_spectpt_negpion_cent6092->Fill(pT);
> 		  //
> 		  if(charge>0&&dis0&&ecore/pT>0.2) hh_Y_specept_pospion_centMB->Fill(pT);
> 		  if(charge<0&&dis0&&ecore/pT>0.2) hh_Y_specept_negpion_centMB->Fill(pT);
> 		  if(cent> 0&&cent<=10&&charge>0&&dis0&&ecore/pT>0.2) hh_Y_specept_pospion_cent0010->Fill(pT);
> 		  if(cent> 0&&cent<=10&&charge<0&&dis0&&ecore/pT>0.2) hh_Y_specept_negpion_cent0010->Fill(pT);
> 		  if(cent>10&&cent<=20&&charge>0&&dis0&&ecore/pT>0.2) hh_Y_specept_pospion_cent1020->Fill(pT);
> 		  if(cent>10&&cent<=20&&charge<0&&dis0&&ecore/pT>0.2) hh_Y_specept_negpion_cent1020->Fill(pT);
> 		  if(cent>20&&cent<=40&&charge>0&&dis0&&ecore/pT>0.2) hh_Y_specept_pospion_cent2040->Fill(pT);
> 		  if(cent>20&&cent<=40&&charge<0&&dis0&&ecore/pT>0.2) hh_Y_specept_negpion_cent2040->Fill(pT);
> 		  if(cent>40&&cent<=60&&charge>0&&dis0&&ecore/pT>0.2) hh_Y_specept_pospion_cent4060->Fill(pT);
> 		  if(cent>40&&cent<=60&&charge<0&&dis0&&ecore/pT>0.2) hh_Y_specept_negpion_cent4060->Fill(pT);
> 		  if(cent>60&&cent<=92&&charge>0&&dis0&&ecore/pT>0.2) hh_Y_specept_pospion_cent6092->Fill(pT);
> 		  if(cent>60&&cent<=92&&charge<0&&dis0&&ecore/pT>0.2) hh_Y_specept_negpion_cent6092->Fill(pT);
> 		  //proton
> 		  if(charge>0&&dis6) hh_Y_ecorept_posproton_centMB->Fill(pT,ecore); // new
> 		  if(charge<0&&dis6) hh_Y_ecorept_negproton_centMB->Fill(pT,ecore); // new
> 		  if(cent> 0&&cent<=10&&charge>0&&dis6) hh_Y_ecorept_posproton_cent0010->Fill(pT,ecore); // new
> 		  if(cent> 0&&cent<=10&&charge<0&&dis6) hh_Y_ecorept_negproton_cent0010->Fill(pT,ecore); // new
> 		  if(cent>10&&cent<=20&&charge>0&&dis6) hh_Y_ecorept_posproton_cent1020->Fill(pT,ecore); // new
> 		  if(cent>10&&cent<=20&&charge<0&&dis6) hh_Y_ecorept_negproton_cent1020->Fill(pT,ecore); // new
> 		  if(cent>20&&cent<=40&&charge>0&&dis6) hh_Y_ecorept_posproton_cent2040->Fill(pT,ecore); // new
> 		  if(cent>20&&cent<=40&&charge<0&&dis6) hh_Y_ecorept_negproton_cent2040->Fill(pT,ecore); // new
> 		  if(cent>40&&cent<=60&&charge>0&&dis6) hh_Y_ecorept_posproton_cent4060->Fill(pT,ecore); // new
> 		  if(cent>40&&cent<=60&&charge<0&&dis6) hh_Y_ecorept_negproton_cent4060->Fill(pT,ecore); // new
> 		  if(cent>60&&cent<=92&&charge>0&&dis6) hh_Y_ecorept_posproton_cent6092->Fill(pT,ecore); // new
> 		  if(cent>60&&cent<=92&&charge<0&&dis6) hh_Y_ecorept_negproton_cent6092->Fill(pT,ecore); // new
> 		  //
> 		  if(charge>0&&dis6) hh_Y_spectpt_posproton_centMB->Fill(pT);
> 		  if(charge<0&&dis6) hh_Y_spectpt_negproton_centMB->Fill(pT);
> 		  if(cent> 0&&cent<=10&&charge>0&&dis6) hh_Y_spectpt_posproton_cent0010->Fill(pT);
> 		  if(cent> 0&&cent<=10&&charge<0&&dis6) hh_Y_spectpt_negproton_cent0010->Fill(pT);
> 		  if(cent>10&&cent<=20&&charge>0&&dis6) hh_Y_spectpt_posproton_cent1020->Fill(pT);
> 		  if(cent>10&&cent<=20&&charge<0&&dis6) hh_Y_spectpt_negproton_cent1020->Fill(pT);
> 		  if(cent>20&&cent<=40&&charge>0&&dis6) hh_Y_spectpt_posproton_cent2040->Fill(pT);
> 		  if(cent>20&&cent<=40&&charge<0&&dis6) hh_Y_spectpt_negproton_cent2040->Fill(pT);
> 		  if(cent>40&&cent<=60&&charge>0&&dis6) hh_Y_spectpt_posproton_cent4060->Fill(pT);
> 		  if(cent>40&&cent<=60&&charge<0&&dis6) hh_Y_spectpt_negproton_cent4060->Fill(pT);
> 		  if(cent>60&&cent<=92&&charge>0&&dis6) hh_Y_spectpt_posproton_cent6092->Fill(pT);
> 		  if(cent>60&&cent<=92&&charge<0&&dis6) hh_Y_spectpt_negproton_cent6092->Fill(pT);
> 		  //
> 		  if(charge>0&&dis6&&ecore/pT>0.2) hh_Y_specept_posproton_centMB->Fill(pT);
> 		  if(charge<0&&dis6&&ecore/pT>0.2) hh_Y_specept_negproton_centMB->Fill(pT);
> 		  if(cent> 0&&cent<=10&&charge>0&&dis6&&ecore/pT>0.2) hh_Y_specept_posproton_cent0010->Fill(pT);
> 		  if(cent> 0&&cent<=10&&charge<0&&dis6&&ecore/pT>0.2) hh_Y_specept_negproton_cent0010->Fill(pT);
> 		  if(cent>10&&cent<=20&&charge>0&&dis6&&ecore/pT>0.2) hh_Y_specept_posproton_cent1020->Fill(pT);
> 		  if(cent>10&&cent<=20&&charge<0&&dis6&&ecore/pT>0.2) hh_Y_specept_negproton_cent1020->Fill(pT);
> 		  if(cent>20&&cent<=40&&charge>0&&dis6&&ecore/pT>0.2) hh_Y_specept_posproton_cent2040->Fill(pT);
> 		  if(cent>20&&cent<=40&&charge<0&&dis6&&ecore/pT>0.2) hh_Y_specept_negproton_cent2040->Fill(pT);
> 		  if(cent>40&&cent<=60&&charge>0&&dis6&&ecore/pT>0.2) hh_Y_specept_posproton_cent4060->Fill(pT);
> 		  if(cent>40&&cent<=60&&charge<0&&dis6&&ecore/pT>0.2) hh_Y_specept_negproton_cent4060->Fill(pT);
> 		  if(cent>60&&cent<=92&&charge>0&&dis6&&ecore/pT>0.2) hh_Y_specept_posproton_cent6092->Fill(pT);
> 		  if(cent>60&&cent<=92&&charge<0&&dis6&&ecore/pT>0.2) hh_Y_specept_negproton_cent6092->Fill(pT);
> 		}
> 	      
> 	      
> 	      bool piA = isPiLME>=-1.5 && isPiLME<=1.5 && isKLME<=-2;
> 	      bool kaA = isKLME>=-1.5 && isKLME<=1.5 && isPiLME>=2 && isPLME<=-2;
> 	      bool prA = isPLME>=-1.5 && isPLME<=1.5 && isKLME>=2;
> 	      bool piB = isPiLME>=-2 && isPiLME<=2 && isKLME<=-2.5;
> 	      bool kaB = isKLME>=-2 && isKLME<=2 && isPiLME>=2.5 && isPLME<=-2.5;
> 	      bool prB = isPLME>=-2 && isPLME<=2 && isKLME>=2.5;
> 
> 	      // bool piA = isPiLME>=-3 && isPiLME<=3 && isKLME<=-3;
> 	      // bool kaA = isKLME>=-3 && isKLME<=3 && isPiLME>=3 && isPLME<=-3;
> 	      // bool prA = isPLME>=-3 && isPLME<=3 && isKLME>=3;
> 	      // bool piB = isPiLME>=-1 && isPiLME<=1 && isKLME<=-1;
> 	      // bool kaB = isKLME>=-1 && isKLME<=1 && isPiLME>=1 && isPLME<=-1;
> 	      // bool prB = isPLME>=-1 && isPLME<=1 && isKLME>=1;
> 
1530a2339,2812
> 	      // ------------------------------------------ //
> 	      // --- new pid experimentation histograms --- //
> 	      // ------------------------------------------ //
> 	      
> 	      // pions
> 	      bool distofwpion0 = isPiLME>=-2 && isPiLME<=2 && isKLME<=-2 ;
> 	      bool distofwpion1 = isPiLME>=-2 && isPiLME<=0 ;
> 	      bool distofwpion2 = isPiLow>=-2 && isPiLow<=0 ;
> 	      bool distofwpion3 = isPiPDI>=-2 && isPiPDI<=2 && isKPDI<=-2 ; // real only (LME in sim)
> 	      bool distofwpion4 = isPiPDI>=-2 && isPiPDI<=2 && isKPDI<=-2 ; // sim and real
> 	      bool distofwpion5 = isPiLME>=-2 && isPiLME<=2 ;
> 	      //kaons
> 	      bool distofwkaon0 = isKLME>=-2 && isKLME<=2 && isPiLME>=2 && isPLME<=-2 ;
> 	      bool distofwkaon1 = isKLow>=-2 && isKLow<=2 && isPiLow>=2 && isPLow<=-2 ;
> 	      bool distofwkaon2 = isKANA>=-2 && isKANA<=2 && isPiANA>=2 && isPANA<=-2 ;
> 	      bool distofwkaon3 = isKPDI>=-2 && isKPDI<=2 && isPiPDI>=2 && isPPDI<=-2 ; // real only (LME in sim)
> 	      bool distofwkaon4 = isKPDI>=-2 && isKPDI<=2 && isPiPDI>=2 && isPPDI<=-2 ; // sim and real
> 	      bool distofwkaon5 = isKLow>=-2 && isKLow<=2 ;
> 	      // protons
> 	      bool distofwproton0 = isPLME>=-2 && isPLME<=2 && isKLME>=2 ;
> 	      bool distofwproton1 = isPLME>= 0 && isPLME<=2 ;
> 	      bool distofwproton2 = isPLow>= 0 && isPLow<=2 ;
> 	      bool distofwproton3 = isPPDI>=-2 && isPPDI<=2 && isKPDI>=2 ; // real only (LME in sim)
> 	      bool distofwproton4 = isPPDI>=-2 && isPPDI<=2 && isKPDI>=2 ; // sim and real
> 	      bool distofwproton5 = isPLow>=-2 && isPLow<=2 ;
> 
> 	      // emc stuff
> 	      bool tfecpion = isPiLME>=-2 && isPiLME<=2 && isKLME<=-2 && good_emc;
> 	      bool tfeckaon = isKLME>=-2 && isKLME<=2 && isPiLME>=2 && isPLME<=-2 && good_emc;
> 	      bool tfecproton = isPLME>=-2 && isPLME<=2 && isKLME>=2 && good_emc;
> 	      bool distfec1 = ecore/pT>0.2;                    
> 	      bool distfec2 = ecore>0.3;
> 	      bool distfec3 = ecore>0.5;
> 	      bool distfec4 = ecore>1.0;                       
> 	      bool distfec5 = ecent/ecore<0.55; // compactness cut, see e.g. AN330
> 	      //pions
> 	      bool distfecpion0 = tfecpion;
> 	      bool distfecpion1 = tfecpion && distfec1;
> 	      bool distfecpion2 = tfecpion && distfec2;
> 	      bool distfecpion3 = tfecpion && distfec3;
> 	      bool distfecpion4 = tfecpion && distfec4;
> 	      bool distfecpion5 = tfecpion && distfec5;
> 	      //kaons
> 	      bool distfeckaon0 = tfeckaon;            
> 	      bool distfeckaon1 = tfeckaon && distfec1;
> 	      bool distfeckaon2 = tfeckaon && distfec2;
> 	      bool distfeckaon3 = tfeckaon && distfec3;
> 	      bool distfeckaon4 = tfeckaon && distfec4;
> 	      bool distfeckaon5 = tfeckaon && distfec5;
> 	      // protons
> 	      bool distfecproton0 = tfecproton;            
> 	      bool distfecproton1 = tfecproton && distfec1;
> 	      bool distfecproton2 = tfecproton && distfec2;
> 	      bool distfecproton3 = tfecproton && distfec3;
> 	      bool distfecproton4 = tfecproton && distfec4;
> 	      bool distfecproton5 = tfecproton && distfec5;
> 
> 	      //if(regular_cuts&&edge&&inner) // new, test
> 	      if(regular_cuts&&good_dcfc)
> 		{
> 		  if(charge>0)
> 		    {
> 		      //now pion
> 		      //dis0
> 		      if(distofwpion0&&cent> 0&&cent<=10) hhptpid_tofw_pospion_0_dis_cent0010->Fill(pT);
> 		      if(distofwpion0&&cent>10&&cent<=20) hhptpid_tofw_pospion_0_dis_cent1020->Fill(pT);
> 		      if(distofwpion0&&cent>20&&cent<=40) hhptpid_tofw_pospion_0_dis_cent2040->Fill(pT);
> 		      if(distofwpion0&&cent>40&&cent<=60) hhptpid_tofw_pospion_0_dis_cent4060->Fill(pT);
> 		      if(distofwpion0&&cent>60&&cent<=92) hhptpid_tofw_pospion_0_dis_cent6092->Fill(pT);
> 		      if(distfecpion0&&cent> 0&&cent<=10) hhptpid_tfec_pospion_0_dis_cent0010->Fill(pT);
> 		      if(distfecpion0&&cent>10&&cent<=20) hhptpid_tfec_pospion_0_dis_cent1020->Fill(pT);
> 		      if(distfecpion0&&cent>20&&cent<=40) hhptpid_tfec_pospion_0_dis_cent2040->Fill(pT);
> 		      if(distfecpion0&&cent>40&&cent<=60) hhptpid_tfec_pospion_0_dis_cent4060->Fill(pT);
> 		      if(distfecpion0&&cent>60&&cent<=92) hhptpid_tfec_pospion_0_dis_cent6092->Fill(pT);
> 		      //dis1
> 		      if(distofwpion1&&cent> 0&&cent<=10) hhptpid_tofw_pospion_1_dis_cent0010->Fill(pT);
> 		      if(distofwpion1&&cent>10&&cent<=20) hhptpid_tofw_pospion_1_dis_cent1020->Fill(pT);
> 		      if(distofwpion1&&cent>20&&cent<=40) hhptpid_tofw_pospion_1_dis_cent2040->Fill(pT);
> 		      if(distofwpion1&&cent>40&&cent<=60) hhptpid_tofw_pospion_1_dis_cent4060->Fill(pT);
> 		      if(distofwpion1&&cent>60&&cent<=92) hhptpid_tofw_pospion_1_dis_cent6092->Fill(pT);
> 		      if(distfecpion1&&cent> 0&&cent<=10) hhptpid_tfec_pospion_1_dis_cent0010->Fill(pT);
> 		      if(distfecpion1&&cent>10&&cent<=20) hhptpid_tfec_pospion_1_dis_cent1020->Fill(pT);
> 		      if(distfecpion1&&cent>20&&cent<=40) hhptpid_tfec_pospion_1_dis_cent2040->Fill(pT);
> 		      if(distfecpion1&&cent>40&&cent<=60) hhptpid_tfec_pospion_1_dis_cent4060->Fill(pT);
> 		      if(distfecpion1&&cent>60&&cent<=92) hhptpid_tfec_pospion_1_dis_cent6092->Fill(pT);
> 		      //dis2
> 		      if(distofwpion2&&cent> 0&&cent<=10) hhptpid_tofw_pospion_2_dis_cent0010->Fill(pT);
> 		      if(distofwpion2&&cent>10&&cent<=20) hhptpid_tofw_pospion_2_dis_cent1020->Fill(pT);
> 		      if(distofwpion2&&cent>20&&cent<=40) hhptpid_tofw_pospion_2_dis_cent2040->Fill(pT);
> 		      if(distofwpion2&&cent>40&&cent<=60) hhptpid_tofw_pospion_2_dis_cent4060->Fill(pT);
> 		      if(distofwpion2&&cent>60&&cent<=92) hhptpid_tofw_pospion_2_dis_cent6092->Fill(pT);
> 		      if(distfecpion2&&cent> 0&&cent<=10) hhptpid_tfec_pospion_2_dis_cent0010->Fill(pT);
> 		      if(distfecpion2&&cent>10&&cent<=20) hhptpid_tfec_pospion_2_dis_cent1020->Fill(pT);
> 		      if(distfecpion2&&cent>20&&cent<=40) hhptpid_tfec_pospion_2_dis_cent2040->Fill(pT);
> 		      if(distfecpion2&&cent>40&&cent<=60) hhptpid_tfec_pospion_2_dis_cent4060->Fill(pT);
> 		      if(distfecpion2&&cent>60&&cent<=92) hhptpid_tfec_pospion_2_dis_cent6092->Fill(pT);
> 		      //dis3
> 		      if(distofwpion3&&cent> 0&&cent<=10) hhptpid_tofw_pospion_3_dis_cent0010->Fill(pT);
> 		      if(distofwpion3&&cent>10&&cent<=20) hhptpid_tofw_pospion_3_dis_cent1020->Fill(pT);
> 		      if(distofwpion3&&cent>20&&cent<=40) hhptpid_tofw_pospion_3_dis_cent2040->Fill(pT);
> 		      if(distofwpion3&&cent>40&&cent<=60) hhptpid_tofw_pospion_3_dis_cent4060->Fill(pT);
> 		      if(distofwpion3&&cent>60&&cent<=92) hhptpid_tofw_pospion_3_dis_cent6092->Fill(pT);
> 		      if(distfecpion3&&cent> 0&&cent<=10) hhptpid_tfec_pospion_3_dis_cent0010->Fill(pT);
> 		      if(distfecpion3&&cent>10&&cent<=20) hhptpid_tfec_pospion_3_dis_cent1020->Fill(pT);
> 		      if(distfecpion3&&cent>20&&cent<=40) hhptpid_tfec_pospion_3_dis_cent2040->Fill(pT);
> 		      if(distfecpion3&&cent>40&&cent<=60) hhptpid_tfec_pospion_3_dis_cent4060->Fill(pT);
> 		      if(distfecpion3&&cent>60&&cent<=92) hhptpid_tfec_pospion_3_dis_cent6092->Fill(pT);
> 		      //dis4
> 		      if(distofwpion4&&cent> 0&&cent<=10) hhptpid_tofw_pospion_4_dis_cent0010->Fill(pT);
> 		      if(distofwpion4&&cent>10&&cent<=20) hhptpid_tofw_pospion_4_dis_cent1020->Fill(pT);
> 		      if(distofwpion4&&cent>20&&cent<=40) hhptpid_tofw_pospion_4_dis_cent2040->Fill(pT);
> 		      if(distofwpion4&&cent>40&&cent<=60) hhptpid_tofw_pospion_4_dis_cent4060->Fill(pT);
> 		      if(distofwpion4&&cent>60&&cent<=92) hhptpid_tofw_pospion_4_dis_cent6092->Fill(pT);
> 		      if(distfecpion4&&cent> 0&&cent<=10) hhptpid_tfec_pospion_4_dis_cent0010->Fill(pT);
> 		      if(distfecpion4&&cent>10&&cent<=20) hhptpid_tfec_pospion_4_dis_cent1020->Fill(pT);
> 		      if(distfecpion4&&cent>20&&cent<=40) hhptpid_tfec_pospion_4_dis_cent2040->Fill(pT);
> 		      if(distfecpion4&&cent>40&&cent<=60) hhptpid_tfec_pospion_4_dis_cent4060->Fill(pT);
> 		      if(distfecpion4&&cent>60&&cent<=92) hhptpid_tfec_pospion_4_dis_cent6092->Fill(pT);
> 		      //dis5
> 		      if(distofwpion5&&cent> 0&&cent<=10) hhptpid_tofw_pospion_5_dis_cent0010->Fill(pT);
> 		      if(distofwpion5&&cent>10&&cent<=20) hhptpid_tofw_pospion_5_dis_cent1020->Fill(pT);
> 		      if(distofwpion5&&cent>20&&cent<=40) hhptpid_tofw_pospion_5_dis_cent2040->Fill(pT);
> 		      if(distofwpion5&&cent>40&&cent<=60) hhptpid_tofw_pospion_5_dis_cent4060->Fill(pT);
> 		      if(distofwpion5&&cent>60&&cent<=92) hhptpid_tofw_pospion_5_dis_cent6092->Fill(pT);
> 		      if(distfecpion5&&cent> 0&&cent<=10) hhptpid_tfec_pospion_5_dis_cent0010->Fill(pT);
> 		      if(distfecpion5&&cent>10&&cent<=20) hhptpid_tfec_pospion_5_dis_cent1020->Fill(pT);
> 		      if(distfecpion5&&cent>20&&cent<=40) hhptpid_tfec_pospion_5_dis_cent2040->Fill(pT);
> 		      if(distfecpion5&&cent>40&&cent<=60) hhptpid_tfec_pospion_5_dis_cent4060->Fill(pT);
> 		      if(distfecpion5&&cent>60&&cent<=92) hhptpid_tfec_pospion_5_dis_cent6092->Fill(pT);
> 		      //nowkaon
> 		      //dis0
> 		      if(distofwkaon0&&cent> 0&&cent<=10) hhptpid_tofw_poskaon_0_dis_cent0010->Fill(pT);
> 		      if(distofwkaon0&&cent>10&&cent<=20) hhptpid_tofw_poskaon_0_dis_cent1020->Fill(pT);
> 		      if(distofwkaon0&&cent>20&&cent<=40) hhptpid_tofw_poskaon_0_dis_cent2040->Fill(pT);
> 		      if(distofwkaon0&&cent>40&&cent<=60) hhptpid_tofw_poskaon_0_dis_cent4060->Fill(pT);
> 		      if(distofwkaon0&&cent>60&&cent<=92) hhptpid_tofw_poskaon_0_dis_cent6092->Fill(pT);
> 		      if(distfeckaon0&&cent> 0&&cent<=10) hhptpid_tfec_poskaon_0_dis_cent0010->Fill(pT);
> 		      if(distfeckaon0&&cent>10&&cent<=20) hhptpid_tfec_poskaon_0_dis_cent1020->Fill(pT);
> 		      if(distfeckaon0&&cent>20&&cent<=40) hhptpid_tfec_poskaon_0_dis_cent2040->Fill(pT);
> 		      if(distfeckaon0&&cent>40&&cent<=60) hhptpid_tfec_poskaon_0_dis_cent4060->Fill(pT);
> 		      if(distfeckaon0&&cent>60&&cent<=92) hhptpid_tfec_poskaon_0_dis_cent6092->Fill(pT);
> 		      //dis1
> 		      if(distofwkaon1&&cent> 0&&cent<=10) hhptpid_tofw_poskaon_1_dis_cent0010->Fill(pT);
> 		      if(distofwkaon1&&cent>10&&cent<=20) hhptpid_tofw_poskaon_1_dis_cent1020->Fill(pT);
> 		      if(distofwkaon1&&cent>20&&cent<=40) hhptpid_tofw_poskaon_1_dis_cent2040->Fill(pT);
> 		      if(distofwkaon1&&cent>40&&cent<=60) hhptpid_tofw_poskaon_1_dis_cent4060->Fill(pT);
> 		      if(distofwkaon1&&cent>60&&cent<=92) hhptpid_tofw_poskaon_1_dis_cent6092->Fill(pT);
> 		      if(distfeckaon1&&cent> 0&&cent<=10) hhptpid_tfec_poskaon_1_dis_cent0010->Fill(pT);
> 		      if(distfeckaon1&&cent>10&&cent<=20) hhptpid_tfec_poskaon_1_dis_cent1020->Fill(pT);
> 		      if(distfeckaon1&&cent>20&&cent<=40) hhptpid_tfec_poskaon_1_dis_cent2040->Fill(pT);
> 		      if(distfeckaon1&&cent>40&&cent<=60) hhptpid_tfec_poskaon_1_dis_cent4060->Fill(pT);
> 		      if(distfeckaon1&&cent>60&&cent<=92) hhptpid_tfec_poskaon_1_dis_cent6092->Fill(pT);
> 		      //dis2
> 		      if(distofwkaon2&&cent> 0&&cent<=10) hhptpid_tofw_poskaon_2_dis_cent0010->Fill(pT);
> 		      if(distofwkaon2&&cent>10&&cent<=20) hhptpid_tofw_poskaon_2_dis_cent1020->Fill(pT);
> 		      if(distofwkaon2&&cent>20&&cent<=40) hhptpid_tofw_poskaon_2_dis_cent2040->Fill(pT);
> 		      if(distofwkaon2&&cent>40&&cent<=60) hhptpid_tofw_poskaon_2_dis_cent4060->Fill(pT);
> 		      if(distofwkaon2&&cent>60&&cent<=92) hhptpid_tofw_poskaon_2_dis_cent6092->Fill(pT);
> 		      if(distfeckaon2&&cent> 0&&cent<=10) hhptpid_tfec_poskaon_2_dis_cent0010->Fill(pT);
> 		      if(distfeckaon2&&cent>10&&cent<=20) hhptpid_tfec_poskaon_2_dis_cent1020->Fill(pT);
> 		      if(distfeckaon2&&cent>20&&cent<=40) hhptpid_tfec_poskaon_2_dis_cent2040->Fill(pT);
> 		      if(distfeckaon2&&cent>40&&cent<=60) hhptpid_tfec_poskaon_2_dis_cent4060->Fill(pT);
> 		      if(distfeckaon2&&cent>60&&cent<=92) hhptpid_tfec_poskaon_2_dis_cent6092->Fill(pT);
> 		      //dis3
> 		      if(distofwkaon3&&cent> 0&&cent<=10) hhptpid_tofw_poskaon_3_dis_cent0010->Fill(pT);
> 		      if(distofwkaon3&&cent>10&&cent<=20) hhptpid_tofw_poskaon_3_dis_cent1020->Fill(pT);
> 		      if(distofwkaon3&&cent>20&&cent<=40) hhptpid_tofw_poskaon_3_dis_cent2040->Fill(pT);
> 		      if(distofwkaon3&&cent>40&&cent<=60) hhptpid_tofw_poskaon_3_dis_cent4060->Fill(pT);
> 		      if(distofwkaon3&&cent>60&&cent<=92) hhptpid_tofw_poskaon_3_dis_cent6092->Fill(pT);
> 		      if(distfeckaon3&&cent> 0&&cent<=10) hhptpid_tfec_poskaon_3_dis_cent0010->Fill(pT);
> 		      if(distfeckaon3&&cent>10&&cent<=20) hhptpid_tfec_poskaon_3_dis_cent1020->Fill(pT);
> 		      if(distfeckaon3&&cent>20&&cent<=40) hhptpid_tfec_poskaon_3_dis_cent2040->Fill(pT);
> 		      if(distfeckaon3&&cent>40&&cent<=60) hhptpid_tfec_poskaon_3_dis_cent4060->Fill(pT);
> 		      if(distfeckaon3&&cent>60&&cent<=92) hhptpid_tfec_poskaon_3_dis_cent6092->Fill(pT);
> 		      //dis4
> 		      if(distofwkaon4&&cent> 0&&cent<=10) hhptpid_tofw_poskaon_4_dis_cent0010->Fill(pT);
> 		      if(distofwkaon4&&cent>10&&cent<=20) hhptpid_tofw_poskaon_4_dis_cent1020->Fill(pT);
> 		      if(distofwkaon4&&cent>20&&cent<=40) hhptpid_tofw_poskaon_4_dis_cent2040->Fill(pT);
> 		      if(distofwkaon4&&cent>40&&cent<=60) hhptpid_tofw_poskaon_4_dis_cent4060->Fill(pT);
> 		      if(distofwkaon4&&cent>60&&cent<=92) hhptpid_tofw_poskaon_4_dis_cent6092->Fill(pT);
> 		      if(distfeckaon4&&cent> 0&&cent<=10) hhptpid_tfec_poskaon_4_dis_cent0010->Fill(pT);
> 		      if(distfeckaon4&&cent>10&&cent<=20) hhptpid_tfec_poskaon_4_dis_cent1020->Fill(pT);
> 		      if(distfeckaon4&&cent>20&&cent<=40) hhptpid_tfec_poskaon_4_dis_cent2040->Fill(pT);
> 		      if(distfeckaon4&&cent>40&&cent<=60) hhptpid_tfec_poskaon_4_dis_cent4060->Fill(pT);
> 		      if(distfeckaon4&&cent>60&&cent<=92) hhptpid_tfec_poskaon_4_dis_cent6092->Fill(pT);
> 		      //dis5
> 		      if(distofwkaon5&&cent> 0&&cent<=10) hhptpid_tofw_poskaon_5_dis_cent0010->Fill(pT);
> 		      if(distofwkaon5&&cent>10&&cent<=20) hhptpid_tofw_poskaon_5_dis_cent1020->Fill(pT);
> 		      if(distofwkaon5&&cent>20&&cent<=40) hhptpid_tofw_poskaon_5_dis_cent2040->Fill(pT);
> 		      if(distofwkaon5&&cent>40&&cent<=60) hhptpid_tofw_poskaon_5_dis_cent4060->Fill(pT);
> 		      if(distofwkaon5&&cent>60&&cent<=92) hhptpid_tofw_poskaon_5_dis_cent6092->Fill(pT);
> 		      if(distfeckaon5&&cent> 0&&cent<=10) hhptpid_tfec_poskaon_5_dis_cent0010->Fill(pT);
> 		      if(distfeckaon5&&cent>10&&cent<=20) hhptpid_tfec_poskaon_5_dis_cent1020->Fill(pT);
> 		      if(distfeckaon5&&cent>20&&cent<=40) hhptpid_tfec_poskaon_5_dis_cent2040->Fill(pT);
> 		      if(distfeckaon5&&cent>40&&cent<=60) hhptpid_tfec_poskaon_5_dis_cent4060->Fill(pT);
> 		      if(distfeckaon5&&cent>60&&cent<=92) hhptpid_tfec_poskaon_5_dis_cent6092->Fill(pT);
> 		      //nowproton
> 		      //dis0
> 		      if(distofwproton0&&cent> 0&&cent<=10) hhptpid_tofw_posproton_0_dis_cent0010->Fill(pT);
> 		      if(distofwproton0&&cent>10&&cent<=20) hhptpid_tofw_posproton_0_dis_cent1020->Fill(pT);
> 		      if(distofwproton0&&cent>20&&cent<=40) hhptpid_tofw_posproton_0_dis_cent2040->Fill(pT);
> 		      if(distofwproton0&&cent>40&&cent<=60) hhptpid_tofw_posproton_0_dis_cent4060->Fill(pT);
> 		      if(distofwproton0&&cent>60&&cent<=92) hhptpid_tofw_posproton_0_dis_cent6092->Fill(pT);
> 		      if(distfecproton0&&cent> 0&&cent<=10) hhptpid_tfec_posproton_0_dis_cent0010->Fill(pT);
> 		      if(distfecproton0&&cent>10&&cent<=20) hhptpid_tfec_posproton_0_dis_cent1020->Fill(pT);
> 		      if(distfecproton0&&cent>20&&cent<=40) hhptpid_tfec_posproton_0_dis_cent2040->Fill(pT);
> 		      if(distfecproton0&&cent>40&&cent<=60) hhptpid_tfec_posproton_0_dis_cent4060->Fill(pT);
> 		      if(distfecproton0&&cent>60&&cent<=92) hhptpid_tfec_posproton_0_dis_cent6092->Fill(pT);
> 		      //dis1
> 		      if(distofwproton1&&cent> 0&&cent<=10) hhptpid_tofw_posproton_1_dis_cent0010->Fill(pT);
> 		      if(distofwproton1&&cent>10&&cent<=20) hhptpid_tofw_posproton_1_dis_cent1020->Fill(pT);
> 		      if(distofwproton1&&cent>20&&cent<=40) hhptpid_tofw_posproton_1_dis_cent2040->Fill(pT);
> 		      if(distofwproton1&&cent>40&&cent<=60) hhptpid_tofw_posproton_1_dis_cent4060->Fill(pT);
> 		      if(distofwproton1&&cent>60&&cent<=92) hhptpid_tofw_posproton_1_dis_cent6092->Fill(pT);
> 		      if(distfecproton1&&cent> 0&&cent<=10) hhptpid_tfec_posproton_1_dis_cent0010->Fill(pT);
> 		      if(distfecproton1&&cent>10&&cent<=20) hhptpid_tfec_posproton_1_dis_cent1020->Fill(pT);
> 		      if(distfecproton1&&cent>20&&cent<=40) hhptpid_tfec_posproton_1_dis_cent2040->Fill(pT);
> 		      if(distfecproton1&&cent>40&&cent<=60) hhptpid_tfec_posproton_1_dis_cent4060->Fill(pT);
> 		      if(distfecproton1&&cent>60&&cent<=92) hhptpid_tfec_posproton_1_dis_cent6092->Fill(pT);
> 		      //dis2
> 		      if(distofwproton2&&cent> 0&&cent<=10) hhptpid_tofw_posproton_2_dis_cent0010->Fill(pT);
> 		      if(distofwproton2&&cent>10&&cent<=20) hhptpid_tofw_posproton_2_dis_cent1020->Fill(pT);
> 		      if(distofwproton2&&cent>20&&cent<=40) hhptpid_tofw_posproton_2_dis_cent2040->Fill(pT);
> 		      if(distofwproton2&&cent>40&&cent<=60) hhptpid_tofw_posproton_2_dis_cent4060->Fill(pT);
> 		      if(distofwproton2&&cent>60&&cent<=92) hhptpid_tofw_posproton_2_dis_cent6092->Fill(pT);
> 		      if(distfecproton2&&cent> 0&&cent<=10) hhptpid_tfec_posproton_2_dis_cent0010->Fill(pT);
> 		      if(distfecproton2&&cent>10&&cent<=20) hhptpid_tfec_posproton_2_dis_cent1020->Fill(pT);
> 		      if(distfecproton2&&cent>20&&cent<=40) hhptpid_tfec_posproton_2_dis_cent2040->Fill(pT);
> 		      if(distfecproton2&&cent>40&&cent<=60) hhptpid_tfec_posproton_2_dis_cent4060->Fill(pT);
> 		      if(distfecproton2&&cent>60&&cent<=92) hhptpid_tfec_posproton_2_dis_cent6092->Fill(pT);
> 		      //dis3
> 		      if(distofwproton3&&cent> 0&&cent<=10) hhptpid_tofw_posproton_3_dis_cent0010->Fill(pT);
> 		      if(distofwproton3&&cent>10&&cent<=20) hhptpid_tofw_posproton_3_dis_cent1020->Fill(pT);
> 		      if(distofwproton3&&cent>20&&cent<=40) hhptpid_tofw_posproton_3_dis_cent2040->Fill(pT);
> 		      if(distofwproton3&&cent>40&&cent<=60) hhptpid_tofw_posproton_3_dis_cent4060->Fill(pT);
> 		      if(distofwproton3&&cent>60&&cent<=92) hhptpid_tofw_posproton_3_dis_cent6092->Fill(pT);
> 		      if(distfecproton3&&cent> 0&&cent<=10) hhptpid_tfec_posproton_3_dis_cent0010->Fill(pT);
> 		      if(distfecproton3&&cent>10&&cent<=20) hhptpid_tfec_posproton_3_dis_cent1020->Fill(pT);
> 		      if(distfecproton3&&cent>20&&cent<=40) hhptpid_tfec_posproton_3_dis_cent2040->Fill(pT);
> 		      if(distfecproton3&&cent>40&&cent<=60) hhptpid_tfec_posproton_3_dis_cent4060->Fill(pT);
> 		      if(distfecproton3&&cent>60&&cent<=92) hhptpid_tfec_posproton_3_dis_cent6092->Fill(pT);
> 		      //dis4
> 		      if(distofwproton4&&cent> 0&&cent<=10) hhptpid_tofw_posproton_4_dis_cent0010->Fill(pT);
> 		      if(distofwproton4&&cent>10&&cent<=20) hhptpid_tofw_posproton_4_dis_cent1020->Fill(pT);
> 		      if(distofwproton4&&cent>20&&cent<=40) hhptpid_tofw_posproton_4_dis_cent2040->Fill(pT);
> 		      if(distofwproton4&&cent>40&&cent<=60) hhptpid_tofw_posproton_4_dis_cent4060->Fill(pT);
> 		      if(distofwproton4&&cent>60&&cent<=92) hhptpid_tofw_posproton_4_dis_cent6092->Fill(pT);
> 		      if(distfecproton4&&cent> 0&&cent<=10) hhptpid_tfec_posproton_4_dis_cent0010->Fill(pT);
> 		      if(distfecproton4&&cent>10&&cent<=20) hhptpid_tfec_posproton_4_dis_cent1020->Fill(pT);
> 		      if(distfecproton4&&cent>20&&cent<=40) hhptpid_tfec_posproton_4_dis_cent2040->Fill(pT);
> 		      if(distfecproton4&&cent>40&&cent<=60) hhptpid_tfec_posproton_4_dis_cent4060->Fill(pT);
> 		      if(distfecproton4&&cent>60&&cent<=92) hhptpid_tfec_posproton_4_dis_cent6092->Fill(pT);
> 		      //dis5
> 		      if(distofwproton5&&cent> 0&&cent<=10) hhptpid_tofw_posproton_5_dis_cent0010->Fill(pT);
> 		      if(distofwproton5&&cent>10&&cent<=20) hhptpid_tofw_posproton_5_dis_cent1020->Fill(pT);
> 		      if(distofwproton5&&cent>20&&cent<=40) hhptpid_tofw_posproton_5_dis_cent2040->Fill(pT);
> 		      if(distofwproton5&&cent>40&&cent<=60) hhptpid_tofw_posproton_5_dis_cent4060->Fill(pT);
> 		      if(distofwproton5&&cent>60&&cent<=92) hhptpid_tofw_posproton_5_dis_cent6092->Fill(pT);
> 		      if(distfecproton5&&cent> 0&&cent<=10) hhptpid_tfec_posproton_5_dis_cent0010->Fill(pT);
> 		      if(distfecproton5&&cent>10&&cent<=20) hhptpid_tfec_posproton_5_dis_cent1020->Fill(pT);
> 		      if(distfecproton5&&cent>20&&cent<=40) hhptpid_tfec_posproton_5_dis_cent2040->Fill(pT);
> 		      if(distfecproton5&&cent>40&&cent<=60) hhptpid_tfec_posproton_5_dis_cent4060->Fill(pT);
> 		      if(distfecproton5&&cent>60&&cent<=92) hhptpid_tfec_posproton_5_dis_cent6092->Fill(pT);
> 		    }//pos
> 		  if(charge<0)
> 		    {
> 		      //now pion
> 		      //dis0
> 		      if(distofwpion0&&cent> 0&&cent<=10) hhptpid_tofw_negpion_0_dis_cent0010->Fill(pT);
> 		      if(distofwpion0&&cent>10&&cent<=20) hhptpid_tofw_negpion_0_dis_cent1020->Fill(pT);
> 		      if(distofwpion0&&cent>20&&cent<=40) hhptpid_tofw_negpion_0_dis_cent2040->Fill(pT);
> 		      if(distofwpion0&&cent>40&&cent<=60) hhptpid_tofw_negpion_0_dis_cent4060->Fill(pT);
> 		      if(distofwpion0&&cent>60&&cent<=92) hhptpid_tofw_negpion_0_dis_cent6092->Fill(pT);
> 		      if(distfecpion0&&cent> 0&&cent<=10) hhptpid_tfec_negpion_0_dis_cent0010->Fill(pT);
> 		      if(distfecpion0&&cent>10&&cent<=20) hhptpid_tfec_negpion_0_dis_cent1020->Fill(pT);
> 		      if(distfecpion0&&cent>20&&cent<=40) hhptpid_tfec_negpion_0_dis_cent2040->Fill(pT);
> 		      if(distfecpion0&&cent>40&&cent<=60) hhptpid_tfec_negpion_0_dis_cent4060->Fill(pT);
> 		      if(distfecpion0&&cent>60&&cent<=92) hhptpid_tfec_negpion_0_dis_cent6092->Fill(pT);
> 		      //dis1
> 		      if(distofwpion1&&cent> 0&&cent<=10) hhptpid_tofw_negpion_1_dis_cent0010->Fill(pT);
> 		      if(distofwpion1&&cent>10&&cent<=20) hhptpid_tofw_negpion_1_dis_cent1020->Fill(pT);
> 		      if(distofwpion1&&cent>20&&cent<=40) hhptpid_tofw_negpion_1_dis_cent2040->Fill(pT);
> 		      if(distofwpion1&&cent>40&&cent<=60) hhptpid_tofw_negpion_1_dis_cent4060->Fill(pT);
> 		      if(distofwpion1&&cent>60&&cent<=92) hhptpid_tofw_negpion_1_dis_cent6092->Fill(pT);
> 		      if(distfecpion1&&cent> 0&&cent<=10) hhptpid_tfec_negpion_1_dis_cent0010->Fill(pT);
> 		      if(distfecpion1&&cent>10&&cent<=20) hhptpid_tfec_negpion_1_dis_cent1020->Fill(pT);
> 		      if(distfecpion1&&cent>20&&cent<=40) hhptpid_tfec_negpion_1_dis_cent2040->Fill(pT);
> 		      if(distfecpion1&&cent>40&&cent<=60) hhptpid_tfec_negpion_1_dis_cent4060->Fill(pT);
> 		      if(distfecpion1&&cent>60&&cent<=92) hhptpid_tfec_negpion_1_dis_cent6092->Fill(pT);
> 		      //dis2
> 		      if(distofwpion2&&cent> 0&&cent<=10) hhptpid_tofw_negpion_2_dis_cent0010->Fill(pT);
> 		      if(distofwpion2&&cent>10&&cent<=20) hhptpid_tofw_negpion_2_dis_cent1020->Fill(pT);
> 		      if(distofwpion2&&cent>20&&cent<=40) hhptpid_tofw_negpion_2_dis_cent2040->Fill(pT);
> 		      if(distofwpion2&&cent>40&&cent<=60) hhptpid_tofw_negpion_2_dis_cent4060->Fill(pT);
> 		      if(distofwpion2&&cent>60&&cent<=92) hhptpid_tofw_negpion_2_dis_cent6092->Fill(pT);
> 		      if(distfecpion2&&cent> 0&&cent<=10) hhptpid_tfec_negpion_2_dis_cent0010->Fill(pT);
> 		      if(distfecpion2&&cent>10&&cent<=20) hhptpid_tfec_negpion_2_dis_cent1020->Fill(pT);
> 		      if(distfecpion2&&cent>20&&cent<=40) hhptpid_tfec_negpion_2_dis_cent2040->Fill(pT);
> 		      if(distfecpion2&&cent>40&&cent<=60) hhptpid_tfec_negpion_2_dis_cent4060->Fill(pT);
> 		      if(distfecpion2&&cent>60&&cent<=92) hhptpid_tfec_negpion_2_dis_cent6092->Fill(pT);
> 		      //dis3
> 		      if(distofwpion3&&cent> 0&&cent<=10) hhptpid_tofw_negpion_3_dis_cent0010->Fill(pT);
> 		      if(distofwpion3&&cent>10&&cent<=20) hhptpid_tofw_negpion_3_dis_cent1020->Fill(pT);
> 		      if(distofwpion3&&cent>20&&cent<=40) hhptpid_tofw_negpion_3_dis_cent2040->Fill(pT);
> 		      if(distofwpion3&&cent>40&&cent<=60) hhptpid_tofw_negpion_3_dis_cent4060->Fill(pT);
> 		      if(distofwpion3&&cent>60&&cent<=92) hhptpid_tofw_negpion_3_dis_cent6092->Fill(pT);
> 		      if(distfecpion3&&cent> 0&&cent<=10) hhptpid_tfec_negpion_3_dis_cent0010->Fill(pT);
> 		      if(distfecpion3&&cent>10&&cent<=20) hhptpid_tfec_negpion_3_dis_cent1020->Fill(pT);
> 		      if(distfecpion3&&cent>20&&cent<=40) hhptpid_tfec_negpion_3_dis_cent2040->Fill(pT);
> 		      if(distfecpion3&&cent>40&&cent<=60) hhptpid_tfec_negpion_3_dis_cent4060->Fill(pT);
> 		      if(distfecpion3&&cent>60&&cent<=92) hhptpid_tfec_negpion_3_dis_cent6092->Fill(pT);
> 		      //dis4
> 		      if(distofwpion4&&cent> 0&&cent<=10) hhptpid_tofw_negpion_4_dis_cent0010->Fill(pT);
> 		      if(distofwpion4&&cent>10&&cent<=20) hhptpid_tofw_negpion_4_dis_cent1020->Fill(pT);
> 		      if(distofwpion4&&cent>20&&cent<=40) hhptpid_tofw_negpion_4_dis_cent2040->Fill(pT);
> 		      if(distofwpion4&&cent>40&&cent<=60) hhptpid_tofw_negpion_4_dis_cent4060->Fill(pT);
> 		      if(distofwpion4&&cent>60&&cent<=92) hhptpid_tofw_negpion_4_dis_cent6092->Fill(pT);
> 		      if(distfecpion4&&cent> 0&&cent<=10) hhptpid_tfec_negpion_4_dis_cent0010->Fill(pT);
> 		      if(distfecpion4&&cent>10&&cent<=20) hhptpid_tfec_negpion_4_dis_cent1020->Fill(pT);
> 		      if(distfecpion4&&cent>20&&cent<=40) hhptpid_tfec_negpion_4_dis_cent2040->Fill(pT);
> 		      if(distfecpion4&&cent>40&&cent<=60) hhptpid_tfec_negpion_4_dis_cent4060->Fill(pT);
> 		      if(distfecpion4&&cent>60&&cent<=92) hhptpid_tfec_negpion_4_dis_cent6092->Fill(pT);
> 		      //dis5
> 		      if(distofwpion5&&cent> 0&&cent<=10) hhptpid_tofw_negpion_5_dis_cent0010->Fill(pT);
> 		      if(distofwpion5&&cent>10&&cent<=20) hhptpid_tofw_negpion_5_dis_cent1020->Fill(pT);
> 		      if(distofwpion5&&cent>20&&cent<=40) hhptpid_tofw_negpion_5_dis_cent2040->Fill(pT);
> 		      if(distofwpion5&&cent>40&&cent<=60) hhptpid_tofw_negpion_5_dis_cent4060->Fill(pT);
> 		      if(distofwpion5&&cent>60&&cent<=92) hhptpid_tofw_negpion_5_dis_cent6092->Fill(pT);
> 		      if(distfecpion5&&cent> 0&&cent<=10) hhptpid_tfec_negpion_5_dis_cent0010->Fill(pT);
> 		      if(distfecpion5&&cent>10&&cent<=20) hhptpid_tfec_negpion_5_dis_cent1020->Fill(pT);
> 		      if(distfecpion5&&cent>20&&cent<=40) hhptpid_tfec_negpion_5_dis_cent2040->Fill(pT);
> 		      if(distfecpion5&&cent>40&&cent<=60) hhptpid_tfec_negpion_5_dis_cent4060->Fill(pT);
> 		      if(distfecpion5&&cent>60&&cent<=92) hhptpid_tfec_negpion_5_dis_cent6092->Fill(pT);
> 		      //nowkaon
> 		      //dis0
> 		      if(distofwkaon0&&cent> 0&&cent<=10) hhptpid_tofw_negkaon_0_dis_cent0010->Fill(pT);
> 		      if(distofwkaon0&&cent>10&&cent<=20) hhptpid_tofw_negkaon_0_dis_cent1020->Fill(pT);
> 		      if(distofwkaon0&&cent>20&&cent<=40) hhptpid_tofw_negkaon_0_dis_cent2040->Fill(pT);
> 		      if(distofwkaon0&&cent>40&&cent<=60) hhptpid_tofw_negkaon_0_dis_cent4060->Fill(pT);
> 		      if(distofwkaon0&&cent>60&&cent<=92) hhptpid_tofw_negkaon_0_dis_cent6092->Fill(pT);
> 		      if(distfeckaon0&&cent> 0&&cent<=10) hhptpid_tfec_negkaon_0_dis_cent0010->Fill(pT);
> 		      if(distfeckaon0&&cent>10&&cent<=20) hhptpid_tfec_negkaon_0_dis_cent1020->Fill(pT);
> 		      if(distfeckaon0&&cent>20&&cent<=40) hhptpid_tfec_negkaon_0_dis_cent2040->Fill(pT);
> 		      if(distfeckaon0&&cent>40&&cent<=60) hhptpid_tfec_negkaon_0_dis_cent4060->Fill(pT);
> 		      if(distfeckaon0&&cent>60&&cent<=92) hhptpid_tfec_negkaon_0_dis_cent6092->Fill(pT);
> 		      //dis1
> 		      if(distofwkaon1&&cent> 0&&cent<=10) hhptpid_tofw_negkaon_1_dis_cent0010->Fill(pT);
> 		      if(distofwkaon1&&cent>10&&cent<=20) hhptpid_tofw_negkaon_1_dis_cent1020->Fill(pT);
> 		      if(distofwkaon1&&cent>20&&cent<=40) hhptpid_tofw_negkaon_1_dis_cent2040->Fill(pT);
> 		      if(distofwkaon1&&cent>40&&cent<=60) hhptpid_tofw_negkaon_1_dis_cent4060->Fill(pT);
> 		      if(distofwkaon1&&cent>60&&cent<=92) hhptpid_tofw_negkaon_1_dis_cent6092->Fill(pT);
> 		      if(distfeckaon1&&cent> 0&&cent<=10) hhptpid_tfec_negkaon_1_dis_cent0010->Fill(pT);
> 		      if(distfeckaon1&&cent>10&&cent<=20) hhptpid_tfec_negkaon_1_dis_cent1020->Fill(pT);
> 		      if(distfeckaon1&&cent>20&&cent<=40) hhptpid_tfec_negkaon_1_dis_cent2040->Fill(pT);
> 		      if(distfeckaon1&&cent>40&&cent<=60) hhptpid_tfec_negkaon_1_dis_cent4060->Fill(pT);
> 		      if(distfeckaon1&&cent>60&&cent<=92) hhptpid_tfec_negkaon_1_dis_cent6092->Fill(pT);
> 		      //dis2
> 		      if(distofwkaon2&&cent> 0&&cent<=10) hhptpid_tofw_negkaon_2_dis_cent0010->Fill(pT);
> 		      if(distofwkaon2&&cent>10&&cent<=20) hhptpid_tofw_negkaon_2_dis_cent1020->Fill(pT);
> 		      if(distofwkaon2&&cent>20&&cent<=40) hhptpid_tofw_negkaon_2_dis_cent2040->Fill(pT);
> 		      if(distofwkaon2&&cent>40&&cent<=60) hhptpid_tofw_negkaon_2_dis_cent4060->Fill(pT);
> 		      if(distofwkaon2&&cent>60&&cent<=92) hhptpid_tofw_negkaon_2_dis_cent6092->Fill(pT);
> 		      if(distfeckaon2&&cent> 0&&cent<=10) hhptpid_tfec_negkaon_2_dis_cent0010->Fill(pT);
> 		      if(distfeckaon2&&cent>10&&cent<=20) hhptpid_tfec_negkaon_2_dis_cent1020->Fill(pT);
> 		      if(distfeckaon2&&cent>20&&cent<=40) hhptpid_tfec_negkaon_2_dis_cent2040->Fill(pT);
> 		      if(distfeckaon2&&cent>40&&cent<=60) hhptpid_tfec_negkaon_2_dis_cent4060->Fill(pT);
> 		      if(distfeckaon2&&cent>60&&cent<=92) hhptpid_tfec_negkaon_2_dis_cent6092->Fill(pT);
> 		      //dis3
> 		      if(distofwkaon3&&cent> 0&&cent<=10) hhptpid_tofw_negkaon_3_dis_cent0010->Fill(pT);
> 		      if(distofwkaon3&&cent>10&&cent<=20) hhptpid_tofw_negkaon_3_dis_cent1020->Fill(pT);
> 		      if(distofwkaon3&&cent>20&&cent<=40) hhptpid_tofw_negkaon_3_dis_cent2040->Fill(pT);
> 		      if(distofwkaon3&&cent>40&&cent<=60) hhptpid_tofw_negkaon_3_dis_cent4060->Fill(pT);
> 		      if(distofwkaon3&&cent>60&&cent<=92) hhptpid_tofw_negkaon_3_dis_cent6092->Fill(pT);
> 		      if(distfeckaon3&&cent> 0&&cent<=10) hhptpid_tfec_negkaon_3_dis_cent0010->Fill(pT);
> 		      if(distfeckaon3&&cent>10&&cent<=20) hhptpid_tfec_negkaon_3_dis_cent1020->Fill(pT);
> 		      if(distfeckaon3&&cent>20&&cent<=40) hhptpid_tfec_negkaon_3_dis_cent2040->Fill(pT);
> 		      if(distfeckaon3&&cent>40&&cent<=60) hhptpid_tfec_negkaon_3_dis_cent4060->Fill(pT);
> 		      if(distfeckaon3&&cent>60&&cent<=92) hhptpid_tfec_negkaon_3_dis_cent6092->Fill(pT);
> 		      //dis4
> 		      if(distofwkaon4&&cent> 0&&cent<=10) hhptpid_tofw_negkaon_4_dis_cent0010->Fill(pT);
> 		      if(distofwkaon4&&cent>10&&cent<=20) hhptpid_tofw_negkaon_4_dis_cent1020->Fill(pT);
> 		      if(distofwkaon4&&cent>20&&cent<=40) hhptpid_tofw_negkaon_4_dis_cent2040->Fill(pT);
> 		      if(distofwkaon4&&cent>40&&cent<=60) hhptpid_tofw_negkaon_4_dis_cent4060->Fill(pT);
> 		      if(distofwkaon4&&cent>60&&cent<=92) hhptpid_tofw_negkaon_4_dis_cent6092->Fill(pT);
> 		      if(distfeckaon4&&cent> 0&&cent<=10) hhptpid_tfec_negkaon_4_dis_cent0010->Fill(pT);
> 		      if(distfeckaon4&&cent>10&&cent<=20) hhptpid_tfec_negkaon_4_dis_cent1020->Fill(pT);
> 		      if(distfeckaon4&&cent>20&&cent<=40) hhptpid_tfec_negkaon_4_dis_cent2040->Fill(pT);
> 		      if(distfeckaon4&&cent>40&&cent<=60) hhptpid_tfec_negkaon_4_dis_cent4060->Fill(pT);
> 		      if(distfeckaon4&&cent>60&&cent<=92) hhptpid_tfec_negkaon_4_dis_cent6092->Fill(pT);
> 		      //dis5
> 		      if(distofwkaon5&&cent> 0&&cent<=10) hhptpid_tofw_negkaon_5_dis_cent0010->Fill(pT);
> 		      if(distofwkaon5&&cent>10&&cent<=20) hhptpid_tofw_negkaon_5_dis_cent1020->Fill(pT);
> 		      if(distofwkaon5&&cent>20&&cent<=40) hhptpid_tofw_negkaon_5_dis_cent2040->Fill(pT);
> 		      if(distofwkaon5&&cent>40&&cent<=60) hhptpid_tofw_negkaon_5_dis_cent4060->Fill(pT);
> 		      if(distofwkaon5&&cent>60&&cent<=92) hhptpid_tofw_negkaon_5_dis_cent6092->Fill(pT);
> 		      if(distfeckaon5&&cent> 0&&cent<=10) hhptpid_tfec_negkaon_5_dis_cent0010->Fill(pT);
> 		      if(distfeckaon5&&cent>10&&cent<=20) hhptpid_tfec_negkaon_5_dis_cent1020->Fill(pT);
> 		      if(distfeckaon5&&cent>20&&cent<=40) hhptpid_tfec_negkaon_5_dis_cent2040->Fill(pT);
> 		      if(distfeckaon5&&cent>40&&cent<=60) hhptpid_tfec_negkaon_5_dis_cent4060->Fill(pT);
> 		      if(distfeckaon5&&cent>60&&cent<=92) hhptpid_tfec_negkaon_5_dis_cent6092->Fill(pT);
> 		      //nowproton
> 		      //dis0
> 		      if(distofwproton0&&cent> 0&&cent<=10) hhptpid_tofw_negproton_0_dis_cent0010->Fill(pT);
> 		      if(distofwproton0&&cent>10&&cent<=20) hhptpid_tofw_negproton_0_dis_cent1020->Fill(pT);
> 		      if(distofwproton0&&cent>20&&cent<=40) hhptpid_tofw_negproton_0_dis_cent2040->Fill(pT);
> 		      if(distofwproton0&&cent>40&&cent<=60) hhptpid_tofw_negproton_0_dis_cent4060->Fill(pT);
> 		      if(distofwproton0&&cent>60&&cent<=92) hhptpid_tofw_negproton_0_dis_cent6092->Fill(pT);
> 		      if(distfecproton0&&cent> 0&&cent<=10) hhptpid_tfec_negproton_0_dis_cent0010->Fill(pT);
> 		      if(distfecproton0&&cent>10&&cent<=20) hhptpid_tfec_negproton_0_dis_cent1020->Fill(pT);
> 		      if(distfecproton0&&cent>20&&cent<=40) hhptpid_tfec_negproton_0_dis_cent2040->Fill(pT);
> 		      if(distfecproton0&&cent>40&&cent<=60) hhptpid_tfec_negproton_0_dis_cent4060->Fill(pT);
> 		      if(distfecproton0&&cent>60&&cent<=92) hhptpid_tfec_negproton_0_dis_cent6092->Fill(pT);
> 		      //dis1
> 		      if(distofwproton1&&cent> 0&&cent<=10) hhptpid_tofw_negproton_1_dis_cent0010->Fill(pT);
> 		      if(distofwproton1&&cent>10&&cent<=20) hhptpid_tofw_negproton_1_dis_cent1020->Fill(pT);
> 		      if(distofwproton1&&cent>20&&cent<=40) hhptpid_tofw_negproton_1_dis_cent2040->Fill(pT);
> 		      if(distofwproton1&&cent>40&&cent<=60) hhptpid_tofw_negproton_1_dis_cent4060->Fill(pT);
> 		      if(distofwproton1&&cent>60&&cent<=92) hhptpid_tofw_negproton_1_dis_cent6092->Fill(pT);
> 		      if(distfecproton1&&cent> 0&&cent<=10) hhptpid_tfec_negproton_1_dis_cent0010->Fill(pT);
> 		      if(distfecproton1&&cent>10&&cent<=20) hhptpid_tfec_negproton_1_dis_cent1020->Fill(pT);
> 		      if(distfecproton1&&cent>20&&cent<=40) hhptpid_tfec_negproton_1_dis_cent2040->Fill(pT);
> 		      if(distfecproton1&&cent>40&&cent<=60) hhptpid_tfec_negproton_1_dis_cent4060->Fill(pT);
> 		      if(distfecproton1&&cent>60&&cent<=92) hhptpid_tfec_negproton_1_dis_cent6092->Fill(pT);
> 		      //dis2
> 		      if(distofwproton2&&cent> 0&&cent<=10) hhptpid_tofw_negproton_2_dis_cent0010->Fill(pT);
> 		      if(distofwproton2&&cent>10&&cent<=20) hhptpid_tofw_negproton_2_dis_cent1020->Fill(pT);
> 		      if(distofwproton2&&cent>20&&cent<=40) hhptpid_tofw_negproton_2_dis_cent2040->Fill(pT);
> 		      if(distofwproton2&&cent>40&&cent<=60) hhptpid_tofw_negproton_2_dis_cent4060->Fill(pT);
> 		      if(distofwproton2&&cent>60&&cent<=92) hhptpid_tofw_negproton_2_dis_cent6092->Fill(pT);
> 		      if(distfecproton2&&cent> 0&&cent<=10) hhptpid_tfec_negproton_2_dis_cent0010->Fill(pT);
> 		      if(distfecproton2&&cent>10&&cent<=20) hhptpid_tfec_negproton_2_dis_cent1020->Fill(pT);
> 		      if(distfecproton2&&cent>20&&cent<=40) hhptpid_tfec_negproton_2_dis_cent2040->Fill(pT);
> 		      if(distfecproton2&&cent>40&&cent<=60) hhptpid_tfec_negproton_2_dis_cent4060->Fill(pT);
> 		      if(distfecproton2&&cent>60&&cent<=92) hhptpid_tfec_negproton_2_dis_cent6092->Fill(pT);
> 		      //dis3
> 		      if(distofwproton3&&cent> 0&&cent<=10) hhptpid_tofw_negproton_3_dis_cent0010->Fill(pT);
> 		      if(distofwproton3&&cent>10&&cent<=20) hhptpid_tofw_negproton_3_dis_cent1020->Fill(pT);
> 		      if(distofwproton3&&cent>20&&cent<=40) hhptpid_tofw_negproton_3_dis_cent2040->Fill(pT);
> 		      if(distofwproton3&&cent>40&&cent<=60) hhptpid_tofw_negproton_3_dis_cent4060->Fill(pT);
> 		      if(distofwproton3&&cent>60&&cent<=92) hhptpid_tofw_negproton_3_dis_cent6092->Fill(pT);
> 		      if(distfecproton3&&cent> 0&&cent<=10) hhptpid_tfec_negproton_3_dis_cent0010->Fill(pT);
> 		      if(distfecproton3&&cent>10&&cent<=20) hhptpid_tfec_negproton_3_dis_cent1020->Fill(pT);
> 		      if(distfecproton3&&cent>20&&cent<=40) hhptpid_tfec_negproton_3_dis_cent2040->Fill(pT);
> 		      if(distfecproton3&&cent>40&&cent<=60) hhptpid_tfec_negproton_3_dis_cent4060->Fill(pT);
> 		      if(distfecproton3&&cent>60&&cent<=92) hhptpid_tfec_negproton_3_dis_cent6092->Fill(pT);
> 		      //dis4
> 		      if(distofwproton4&&cent> 0&&cent<=10) hhptpid_tofw_negproton_4_dis_cent0010->Fill(pT);
> 		      if(distofwproton4&&cent>10&&cent<=20) hhptpid_tofw_negproton_4_dis_cent1020->Fill(pT);
> 		      if(distofwproton4&&cent>20&&cent<=40) hhptpid_tofw_negproton_4_dis_cent2040->Fill(pT);
> 		      if(distofwproton4&&cent>40&&cent<=60) hhptpid_tofw_negproton_4_dis_cent4060->Fill(pT);
> 		      if(distofwproton4&&cent>60&&cent<=92) hhptpid_tofw_negproton_4_dis_cent6092->Fill(pT);
> 		      if(distfecproton4&&cent> 0&&cent<=10) hhptpid_tfec_negproton_4_dis_cent0010->Fill(pT);
> 		      if(distfecproton4&&cent>10&&cent<=20) hhptpid_tfec_negproton_4_dis_cent1020->Fill(pT);
> 		      if(distfecproton4&&cent>20&&cent<=40) hhptpid_tfec_negproton_4_dis_cent2040->Fill(pT);
> 		      if(distfecproton4&&cent>40&&cent<=60) hhptpid_tfec_negproton_4_dis_cent4060->Fill(pT);
> 		      if(distfecproton4&&cent>60&&cent<=92) hhptpid_tfec_negproton_4_dis_cent6092->Fill(pT);
> 		      //dis5
> 		      if(distofwproton5&&cent> 0&&cent<=10) hhptpid_tofw_negproton_5_dis_cent0010->Fill(pT);
> 		      if(distofwproton5&&cent>10&&cent<=20) hhptpid_tofw_negproton_5_dis_cent1020->Fill(pT);
> 		      if(distofwproton5&&cent>20&&cent<=40) hhptpid_tofw_negproton_5_dis_cent2040->Fill(pT);
> 		      if(distofwproton5&&cent>40&&cent<=60) hhptpid_tofw_negproton_5_dis_cent4060->Fill(pT);
> 		      if(distofwproton5&&cent>60&&cent<=92) hhptpid_tofw_negproton_5_dis_cent6092->Fill(pT);
> 		      if(distfecproton5&&cent> 0&&cent<=10) hhptpid_tfec_negproton_5_dis_cent0010->Fill(pT);
> 		      if(distfecproton5&&cent>10&&cent<=20) hhptpid_tfec_negproton_5_dis_cent1020->Fill(pT);
> 		      if(distfecproton5&&cent>20&&cent<=40) hhptpid_tfec_negproton_5_dis_cent2040->Fill(pT);
> 		      if(distfecproton5&&cent>40&&cent<=60) hhptpid_tfec_negproton_5_dis_cent4060->Fill(pT);
> 		      if(distfecproton5&&cent>60&&cent<=92) hhptpid_tfec_negproton_5_dis_cent6092->Fill(pT);
> 		    }//neg
> 		}//new,test
> 
> 	      // --------------------------------------- //
> 	      // --- end experimental pid histograms --- //
> 	      // --------------------------------------- //
> 
1535c2817,2818
< 	      if(regular_cuts)
---
> 	      //if(regular_cuts)
> 	      if(regular_cuts&&edge&&inner) // new, test
1539c2822
< 		      if(dis0&&cent>0&&cent<=10) ptpid_tofw_pos_0_dis_cent0010->Fill(pT);
---
> 		      if(dis0&&cent> 0&&cent<=10) ptpid_tofw_pos_0_dis_cent0010->Fill(pT);
1544c2827,2832
< 		      if(dis4&&cent>0&&cent<=10) ptpid_tofw_pos_4_dis_cent0010->Fill(pT);
---
> 		      if(dis2&&cent> 0&&cent<=10) ptpid_tofw_pos_2_dis_cent0010->Fill(pT);
> 		      if(dis2&&cent>10&&cent<=20) ptpid_tofw_pos_2_dis_cent1020->Fill(pT);
> 		      if(dis2&&cent>20&&cent<=40) ptpid_tofw_pos_2_dis_cent2040->Fill(pT);
> 		      if(dis2&&cent>40&&cent<=60) ptpid_tofw_pos_2_dis_cent4060->Fill(pT);
> 		      if(dis2&&cent>60&&cent<=92) ptpid_tofw_pos_2_dis_cent6092->Fill(pT);
> 		      if(dis4&&cent> 0&&cent<=10) ptpid_tofw_pos_4_dis_cent0010->Fill(pT);
1549c2837
< 		      if(dis6&&cent>0&&cent<=10) ptpid_tofw_pos_6_dis_cent0010->Fill(pT);
---
> 		      if(dis6&&cent> 0&&cent<=10) ptpid_tofw_pos_6_dis_cent0010->Fill(pT);
1553a2842,2846
> 		      if(dis8&&cent> 0&&cent<=10) ptpid_tofw_pos_8_dis_cent0010->Fill(pT);
> 		      if(dis8&&cent>10&&cent<=20) ptpid_tofw_pos_8_dis_cent1020->Fill(pT);
> 		      if(dis8&&cent>20&&cent<=40) ptpid_tofw_pos_8_dis_cent2040->Fill(pT);
> 		      if(dis8&&cent>40&&cent<=60) ptpid_tofw_pos_8_dis_cent4060->Fill(pT);
> 		      if(dis8&&cent>60&&cent<=92) ptpid_tofw_pos_8_dis_cent6092->Fill(pT);
1557c2850
< 		      if(dis0&&cent>0&&cent<=10) ptpid_tofw_neg_0_dis_cent0010->Fill(pT);
---
> 		      if(dis0&&cent> 0&&cent<=10) ptpid_tofw_neg_0_dis_cent0010->Fill(pT);
1562c2855,2860
< 		      if(dis4&&cent>0&&cent<=10) ptpid_tofw_neg_4_dis_cent0010->Fill(pT);
---
> 		      if(dis2&&cent> 0&&cent<=10) ptpid_tofw_neg_2_dis_cent0010->Fill(pT);
> 		      if(dis2&&cent>10&&cent<=20) ptpid_tofw_neg_2_dis_cent1020->Fill(pT);
> 		      if(dis2&&cent>20&&cent<=40) ptpid_tofw_neg_2_dis_cent2040->Fill(pT);
> 		      if(dis2&&cent>40&&cent<=60) ptpid_tofw_neg_2_dis_cent4060->Fill(pT);
> 		      if(dis2&&cent>60&&cent<=92) ptpid_tofw_neg_2_dis_cent6092->Fill(pT);
> 		      if(dis4&&cent> 0&&cent<=10) ptpid_tofw_neg_4_dis_cent0010->Fill(pT);
1567c2865
< 		      if(dis6&&cent>0&&cent<=10) ptpid_tofw_neg_6_dis_cent0010->Fill(pT);
---
> 		      if(dis6&&cent> 0&&cent<=10) ptpid_tofw_neg_6_dis_cent0010->Fill(pT);
1571a2870,2874
> 		      if(dis8&&cent> 0&&cent<=10) ptpid_tofw_neg_8_dis_cent0010->Fill(pT);
> 		      if(dis8&&cent>10&&cent<=20) ptpid_tofw_neg_8_dis_cent1020->Fill(pT);
> 		      if(dis8&&cent>20&&cent<=40) ptpid_tofw_neg_8_dis_cent2040->Fill(pT);
> 		      if(dis8&&cent>40&&cent<=60) ptpid_tofw_neg_8_dis_cent4060->Fill(pT);
> 		      if(dis8&&cent>60&&cent<=92) ptpid_tofw_neg_8_dis_cent6092->Fill(pT);
1578a2882
> 	      //back
1582,1590c2886,2890
< 		  if(icent==0) bkgrd_tofwsdphi_pT_back_pos_cent0->Fill(pT,tofwsdphi);
< 		  if(icent==1) bkgrd_tofwsdphi_pT_back_pos_cent1->Fill(pT,tofwsdphi);
< 		  if(icent==2) bkgrd_tofwsdphi_pT_back_pos_cent2->Fill(pT,tofwsdphi);
< 		  if(icent==3) bkgrd_tofwsdphi_pT_back_pos_cent3->Fill(pT,tofwsdphi);
< 		  if(icent==4) bkgrd_tofwsdphi_pT_back_pos_cent4->Fill(pT,tofwsdphi);
< 		  if(icent==5) bkgrd_tofwsdphi_pT_back_pos_cent5->Fill(pT,tofwsdphi);
< 		  if(icent==6) bkgrd_tofwsdphi_pT_back_pos_cent6->Fill(pT,tofwsdphi);
< 		  if(icent==7) bkgrd_tofwsdphi_pT_back_pos_cent7->Fill(pT,tofwsdphi);
< 		  if(icent==8) bkgrd_tofwsdphi_pT_back_pos_cent8->Fill(pT,tofwsdphi);
---
> 		  if(ICENT==0) bkgrd_tofwsdphi_pT_back_pos_cent0->Fill(pT,tofwsdphi);
> 		  if(ICENT==1) bkgrd_tofwsdphi_pT_back_pos_cent1->Fill(pT,tofwsdphi);
> 		  if(ICENT==2) bkgrd_tofwsdphi_pT_back_pos_cent2->Fill(pT,tofwsdphi);
> 		  if(ICENT==3) bkgrd_tofwsdphi_pT_back_pos_cent3->Fill(pT,tofwsdphi);
> 		  if(ICENT==4) bkgrd_tofwsdphi_pT_back_pos_cent4->Fill(pT,tofwsdphi);
1595,1603c2895,2919
< 		  if(icent==0) bkgrd_tofwsdphi_pT_back_neg_cent0->Fill(pT,tofwsdphi);
< 		  if(icent==1) bkgrd_tofwsdphi_pT_back_neg_cent1->Fill(pT,tofwsdphi);
< 		  if(icent==2) bkgrd_tofwsdphi_pT_back_neg_cent2->Fill(pT,tofwsdphi);
< 		  if(icent==3) bkgrd_tofwsdphi_pT_back_neg_cent3->Fill(pT,tofwsdphi);
< 		  if(icent==4) bkgrd_tofwsdphi_pT_back_neg_cent4->Fill(pT,tofwsdphi);
< 		  if(icent==5) bkgrd_tofwsdphi_pT_back_neg_cent5->Fill(pT,tofwsdphi);
< 		  if(icent==6) bkgrd_tofwsdphi_pT_back_neg_cent6->Fill(pT,tofwsdphi);
< 		  if(icent==7) bkgrd_tofwsdphi_pT_back_neg_cent7->Fill(pT,tofwsdphi);
< 		  if(icent==8) bkgrd_tofwsdphi_pT_back_neg_cent8->Fill(pT,tofwsdphi);
---
> 		  if(ICENT==0) bkgrd_tofwsdphi_pT_back_neg_cent0->Fill(pT,tofwsdphi);
> 		  if(ICENT==1) bkgrd_tofwsdphi_pT_back_neg_cent1->Fill(pT,tofwsdphi);
> 		  if(ICENT==2) bkgrd_tofwsdphi_pT_back_neg_cent2->Fill(pT,tofwsdphi);
> 		  if(ICENT==3) bkgrd_tofwsdphi_pT_back_neg_cent3->Fill(pT,tofwsdphi);
> 		  if(ICENT==4) bkgrd_tofwsdphi_pT_back_neg_cent4->Fill(pT,tofwsdphi);
> 		}
> 
> 	      //fore
> 	      if(fabs(tofwsdz)<3.0)
> 		{
> 		  bkgrd_tofwsdphi_pT_fore_pos->Fill(pT,tofwsdphi);
> 		  if(ICENT==0) bkgrd_tofwsdphi_pT_fore_pos_cent0->Fill(pT,tofwsdphi);
> 		  if(ICENT==1) bkgrd_tofwsdphi_pT_fore_pos_cent1->Fill(pT,tofwsdphi);
> 		  if(ICENT==2) bkgrd_tofwsdphi_pT_fore_pos_cent2->Fill(pT,tofwsdphi);
> 		  if(ICENT==3) bkgrd_tofwsdphi_pT_fore_pos_cent3->Fill(pT,tofwsdphi);
> 		  if(ICENT==4) bkgrd_tofwsdphi_pT_fore_pos_cent4->Fill(pT,tofwsdphi);
> 		}
> 	      if(fabs(tofwsdz)<3.0)
> 		{
> 		  bkgrd_tofwsdphi_pT_fore_neg->Fill(pT,tofwsdphi);
> 		  if(ICENT==0) bkgrd_tofwsdphi_pT_fore_neg_cent0->Fill(pT,tofwsdphi);
> 		  if(ICENT==1) bkgrd_tofwsdphi_pT_fore_neg_cent1->Fill(pT,tofwsdphi);
> 		  if(ICENT==2) bkgrd_tofwsdphi_pT_fore_neg_cent2->Fill(pT,tofwsdphi);
> 		  if(ICENT==3) bkgrd_tofwsdphi_pT_fore_neg_cent3->Fill(pT,tofwsdphi);
> 		  if(ICENT==4) bkgrd_tofwsdphi_pT_fore_neg_cent4->Fill(pT,tofwsdphi);
1605a2922,2945
> 	      //foep
> 	      if(fabs(tofwsdz)<3.0&&ecore/pT>0.2)
> 		{
> 		  bkgrd_tofwsdphi_pT_foep_pos->Fill(pT,tofwsdphi);
> 		  if(ICENT==0) bkgrd_tofwsdphi_pT_foep_pos_cent0->Fill(pT,tofwsdphi);
> 		  if(ICENT==1) bkgrd_tofwsdphi_pT_foep_pos_cent1->Fill(pT,tofwsdphi);
> 		  if(ICENT==2) bkgrd_tofwsdphi_pT_foep_pos_cent2->Fill(pT,tofwsdphi);
> 		  if(ICENT==3) bkgrd_tofwsdphi_pT_foep_pos_cent3->Fill(pT,tofwsdphi);
> 		  if(ICENT==4) bkgrd_tofwsdphi_pT_foep_pos_cent4->Fill(pT,tofwsdphi);
> 		}
> 	      if(fabs(tofwsdz)<3.0&&ecore/pT>0.2)
> 		{
> 		  bkgrd_tofwsdphi_pT_foep_neg->Fill(pT,tofwsdphi);
> 		  if(ICENT==0) bkgrd_tofwsdphi_pT_foep_neg_cent0->Fill(pT,tofwsdphi);
> 		  if(ICENT==1) bkgrd_tofwsdphi_pT_foep_neg_cent1->Fill(pT,tofwsdphi);
> 		  if(ICENT==2) bkgrd_tofwsdphi_pT_foep_neg_cent2->Fill(pT,tofwsdphi);
> 		  if(ICENT==3) bkgrd_tofwsdphi_pT_foep_neg_cent3->Fill(pT,tofwsdphi);
> 		  if(ICENT==4) bkgrd_tofwsdphi_pT_foep_neg_cent4->Fill(pT,tofwsdphi);
> 		}
> 
> 	      bool backpi = dis0;
> 	      bool backka = dis4;
> 	      bool backpr = dis6;
> 
1612,1621c2952,2955
< 			  if(dis3) {bkgrd_tofwsdphi_pT_pion_pos->Fill(pT,tofwsdphi);}
< 			  if(dis4) {bkgrd_tofwsdphi_pT_kaon_pos->Fill(pT,tofwsdphi);}
< 			  if(dis9) {bkgrd_tofwsdphi_pT_prot_pos->Fill(pT,tofwsdphi);}
< 			  if(icent==0)
< 			    {
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_pos_cent0->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_pos_cent0->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_pos_cent0->Fill(pT,tofwsdphi);}
< 			    }
< 			  if(icent==1)
---
> 			  if(backpi) {bkgrd_tofwsdphi_pT_pion_pos->Fill(pT,tofwsdphi);}
> 			  if(backka) {bkgrd_tofwsdphi_pT_kaon_pos->Fill(pT,tofwsdphi);}
> 			  if(backpr) {bkgrd_tofwsdphi_pT_prot_pos->Fill(pT,tofwsdphi);}
> 			  if(ICENT==0)
1623,1625c2957,2959
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_pos_cent1->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_pos_cent1->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_pos_cent1->Fill(pT,tofwsdphi);}
---
> 			      if(backpi) {bkgrd_tofwsdphi_pT_pion_pos_cent0->Fill(pT,tofwsdphi);}
> 			      if(backka) {bkgrd_tofwsdphi_pT_kaon_pos_cent0->Fill(pT,tofwsdphi);}
> 			      if(backpr) {bkgrd_tofwsdphi_pT_prot_pos_cent0->Fill(pT,tofwsdphi);}
1627c2961
< 			  if(icent==2)
---
> 			  if(ICENT==1)
1629,1631c2963,2965
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_pos_cent2->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_pos_cent2->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_pos_cent2->Fill(pT,tofwsdphi);}
---
> 			      if(backpi) {bkgrd_tofwsdphi_pT_pion_pos_cent1->Fill(pT,tofwsdphi);}
> 			      if(backka) {bkgrd_tofwsdphi_pT_kaon_pos_cent1->Fill(pT,tofwsdphi);}
> 			      if(backpr) {bkgrd_tofwsdphi_pT_prot_pos_cent1->Fill(pT,tofwsdphi);}
1633c2967
< 			  if(icent==3)
---
> 			  if(ICENT==2)
1635,1637c2969,2971
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_pos_cent3->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_pos_cent3->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_pos_cent3->Fill(pT,tofwsdphi);}
---
> 			      if(backpi) {bkgrd_tofwsdphi_pT_pion_pos_cent2->Fill(pT,tofwsdphi);}
> 			      if(backka) {bkgrd_tofwsdphi_pT_kaon_pos_cent2->Fill(pT,tofwsdphi);}
> 			      if(backpr) {bkgrd_tofwsdphi_pT_prot_pos_cent2->Fill(pT,tofwsdphi);}
1639c2973
< 			  if(icent==4)
---
> 			  if(ICENT==3)
1641,1643c2975,2977
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_pos_cent4->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_pos_cent4->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_pos_cent4->Fill(pT,tofwsdphi);}
---
> 			      if(backpi) {bkgrd_tofwsdphi_pT_pion_pos_cent3->Fill(pT,tofwsdphi);}
> 			      if(backka) {bkgrd_tofwsdphi_pT_kaon_pos_cent3->Fill(pT,tofwsdphi);}
> 			      if(backpr) {bkgrd_tofwsdphi_pT_prot_pos_cent3->Fill(pT,tofwsdphi);}
1645c2979
< 			  if(icent==5)
---
> 			  if(ICENT==4)
1647,1649c2981,2983
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_pos_cent5->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_pos_cent5->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_pos_cent5->Fill(pT,tofwsdphi);}
---
> 			      if(backpi) {bkgrd_tofwsdphi_pT_pion_pos_cent4->Fill(pT,tofwsdphi);}
> 			      if(backka) {bkgrd_tofwsdphi_pT_kaon_pos_cent4->Fill(pT,tofwsdphi);}
> 			      if(backpr) {bkgrd_tofwsdphi_pT_prot_pos_cent4->Fill(pT,tofwsdphi);}
1651,1669c2985
< 			  if(icent==6)
< 			    {
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_pos_cent6->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_pos_cent6->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_pos_cent6->Fill(pT,tofwsdphi);}
< 			    }
< 			  if(icent==7)
< 			    {
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_pos_cent7->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_pos_cent7->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_pos_cent7->Fill(pT,tofwsdphi);}
< 			    }
< 			  if(icent==8)
< 			    {
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_pos_cent8->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_pos_cent8->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_pos_cent8->Fill(pT,tofwsdphi);}
< 			    }
< 			}		  
---
> 			}
1675,1702c2991,2994
< 			  if(dis3) {bkgrd_tofwsdphi_pT_pion_neg->Fill(pT,tofwsdphi);}
< 			  if(dis4) {bkgrd_tofwsdphi_pT_kaon_neg->Fill(pT,tofwsdphi);}
< 			  if(dis9) {bkgrd_tofwsdphi_pT_prot_neg->Fill(pT,tofwsdphi);}
< 			  if(icent==0)
< 			    {
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_neg_cent0->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_neg_cent0->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_neg_cent0->Fill(pT,tofwsdphi);}
< 			    }
< 			  if(icent==1)
< 			    {
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_neg_cent1->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_neg_cent1->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_neg_cent1->Fill(pT,tofwsdphi);}
< 			    }
< 			  if(icent==2)
< 			    {
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_neg_cent2->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_neg_cent2->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_neg_cent2->Fill(pT,tofwsdphi);}
< 			    }
< 			  if(icent==3)
< 			    {
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_neg_cent3->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_neg_cent3->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_neg_cent3->Fill(pT,tofwsdphi);}
< 			    }
< 			  if(icent==4)
---
> 			  if(backpi) {bkgrd_tofwsdphi_pT_pion_neg->Fill(pT,tofwsdphi);}
> 			  if(backka) {bkgrd_tofwsdphi_pT_kaon_neg->Fill(pT,tofwsdphi);}
> 			  if(backpr) {bkgrd_tofwsdphi_pT_prot_neg->Fill(pT,tofwsdphi);}
> 			  if(ICENT==0)
1704,1706c2996,2998
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_neg_cent4->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_neg_cent4->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_neg_cent4->Fill(pT,tofwsdphi);}
---
> 			      if(backpi) {bkgrd_tofwsdphi_pT_pion_neg_cent0->Fill(pT,tofwsdphi);}
> 			      if(backka) {bkgrd_tofwsdphi_pT_kaon_neg_cent0->Fill(pT,tofwsdphi);}
> 			      if(backpr) {bkgrd_tofwsdphi_pT_prot_neg_cent0->Fill(pT,tofwsdphi);}
1708c3000
< 			  if(icent==5)
---
> 			  if(ICENT==1)
1710,1712c3002,3004
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_neg_cent5->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_neg_cent5->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_neg_cent5->Fill(pT,tofwsdphi);}
---
> 			      if(backpi) {bkgrd_tofwsdphi_pT_pion_neg_cent1->Fill(pT,tofwsdphi);}
> 			      if(backka) {bkgrd_tofwsdphi_pT_kaon_neg_cent1->Fill(pT,tofwsdphi);}
> 			      if(backpr) {bkgrd_tofwsdphi_pT_prot_neg_cent1->Fill(pT,tofwsdphi);}
1714c3006
< 			  if(icent==6)
---
> 			  if(ICENT==2)
1716,1718c3008,3010
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_neg_cent6->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_neg_cent6->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_neg_cent6->Fill(pT,tofwsdphi);}
---
> 			      if(backpi) {bkgrd_tofwsdphi_pT_pion_neg_cent2->Fill(pT,tofwsdphi);}
> 			      if(backka) {bkgrd_tofwsdphi_pT_kaon_neg_cent2->Fill(pT,tofwsdphi);}
> 			      if(backpr) {bkgrd_tofwsdphi_pT_prot_neg_cent2->Fill(pT,tofwsdphi);}
1720c3012
< 			  if(icent==7)
---
> 			  if(ICENT==3)
1722,1724c3014,3016
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_neg_cent7->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_neg_cent7->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_neg_cent7->Fill(pT,tofwsdphi);}
---
> 			      if(backpi) {bkgrd_tofwsdphi_pT_pion_neg_cent3->Fill(pT,tofwsdphi);}
> 			      if(backka) {bkgrd_tofwsdphi_pT_kaon_neg_cent3->Fill(pT,tofwsdphi);}
> 			      if(backpr) {bkgrd_tofwsdphi_pT_prot_neg_cent3->Fill(pT,tofwsdphi);}
1726c3018
< 			  if(icent==8)
---
> 			  if(ICENT==4)
1728,1730c3020,3022
< 			      if(dis3) {bkgrd_tofwsdphi_pT_pion_neg_cent8->Fill(pT,tofwsdphi);}
< 			      if(dis4) {bkgrd_tofwsdphi_pT_kaon_neg_cent8->Fill(pT,tofwsdphi);}
< 			      if(dis9) {bkgrd_tofwsdphi_pT_prot_neg_cent8->Fill(pT,tofwsdphi);}
---
> 			      if(backpi) {bkgrd_tofwsdphi_pT_pion_neg_cent4->Fill(pT,tofwsdphi);}
> 			      if(backka) {bkgrd_tofwsdphi_pT_kaon_neg_cent4->Fill(pT,tofwsdphi);}
> 			      if(backpr) {bkgrd_tofwsdphi_pT_prot_neg_cent4->Fill(pT,tofwsdphi);}
2155a3448,3492
> 	      // ------------------------------------ //
> 	      // --- new special background study --- //
> 	      // ------------------------------------ //
> 
> 	      bool pion1 = fabs(isPiLME)<2.0;
> 	      bool pion = dis0;
> 
> 	      if(charge>0&&sigma_tofw<10)
> 		{
> 		  sigma_tofw_fr_nn_pos->Fill(pT,sigma_tofw);
> 		  if(pion1)
> 		    {
> 		      sigma_tofw_si_nn_pos->Fill(pT,sigma_tofw);
> 		    }
> 		  if(pion)
> 		    {
> 		      sigma_tofw_sj_nn_pos->Fill(pT,sigma_tofw);
> 		    }
> 		  if(ecore/pT>0.2)
> 		    {
> 		      sigma_tofw_bk_nn_pos->Fill(pT,sigma_tofw);
> 		    }
> 		}
> 
> 
> 	      if(charge<0&&sigma_tofw<10)
> 		{
> 		  sigma_tofw_fr_nn_neg->Fill(pT,sigma_tofw);
> 		  if(pion1)
> 		    {
> 		      sigma_tofw_si_nn_neg->Fill(pT,sigma_tofw);
> 		    }
> 		  if(pion)
> 		    {
> 		      sigma_tofw_sj_nn_neg->Fill(pT,sigma_tofw);
> 		    }
> 		  if(ecore/pT>0.2)
> 		    {
> 		      sigma_tofw_bk_nn_neg->Fill(pT,sigma_tofw);
> 		    }
> 		}
> 
> 
> 
> 
2221c3558
< float isPionNew(float x, float m2tofw)
---
> float isPionANA(float x, float m2tofw)
2249c3586
< float isKaonNew(float x, float m2tofw)
---
> float isKaonANA(float x, float m2tofw)
2277c3614
< float isProtonNew(float x, float m2tofw)
---
> float isProtonANA(float x, float m2tofw)
2304c3641
< float isPionLow(float x, float m2tofw)
---
> float isPionLME(float x, float m2tofw)
2338c3675
< float isKaonLow(float x, float m2tofw)
---
> float isKaonLME(float x, float m2tofw)
2356c3693
< float isProtonLow(float x, float m2tofw)
---
> float isProtonLME(float x, float m2tofw)
2380a3718,3837
> 
> 
> 
> 
> 
> 
> float isPionLow(float x, float m2tofw)
> {
> 
>   // this mean is more radical
>   // consider going with less radical
>   // float a0 = 0.0123786;
>   // float a1 = 0.00293974;
>   // float a2 = -0.000321866;
>   // float a3 = -0.0110238;
>   // float a4 = 0.0352101;
>   // float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);
> 
>   float mean = mpion*mpion;
> 
>   // based on simulation
>   // new
>   float  p0   =       -2.32986e-02;
>   float  p1   =       -1.30028e-03;
>   float  p2   =       -8.26991e-06;
>   float  p3   =        5.56826e-02;
>   float  p4   =       -1.16173e-01;
>   float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
>   // new
>   // float  p0   =       -4.32359e-02;
>   // float  p1   =        6.44942e-03;
>   // float  p2   =       -8.09058e-04;
>   // float  p3   =        3.91918e-02;
>   // float  p4   =       -5.68094e-02;
>   // float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
>   
>   return (m2tofw - mean)/sigma;
> 
> }
> 
> 
> 
> float isKaonLow(float x, float m2tofw)
> {
>   
>   float  p0   =        1.17930e-02;
>   float  p1   =       -1.54666e-02;
>   float  p2   =        2.48918e-03;
>   float  p3   =        6.50247e-02;
>   float  p4   =       -1.61286e-01;
>   float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
> 
>   float mean = mkaon*mkaon; // mean is very stable
> 
>   return (m2tofw - mean)/sigma;
> 
> }
> 
> 
> 
> float isProtonLow(float x, float m2tofw)
> {
> 
>   // float  a0    =       8.58341e-01;
>   // float  a1    =      -2.89831e-02;
>   // float  a2    =       1.68868e-02;
>   // float  a3    =      -9.42405e-03;
>   // float  a4    =       6.23467e-02;
>   // float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);
> 
>   float mean = mproton*mproton;
> 
>   float  p0    =      -6.19317e-03;  
>   float  p1    =       9.01921e-03;
>   float  p2    =       6.82347e-04;
>   float  p3    =       6.07866e-02;
>   float  p4    =      -1.32903e-01;
>   float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
> 
>   return (m2tofw - mean)/sigma;
> 
> }
> 
> 
> 
> 
> float isPionPDI(float x, float m2tofw)
> {
> 
>   // this mean is more radical
>   // consider going with less radical
>   float a0 = 0.0123786;
>   float a1 = 0.00293974;
>   float a2 = -0.000321866;
>   float a3 = -0.0110238;
>   float a4 = 0.0352101;
>   float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);
> 
>   // based on simulation
>   // new
>   // float  p0   =       -2.32986e-02;
>   // float  p1   =       -1.30028e-03;
>   // float  p2   =       -8.26991e-06;
>   // float  p3   =        5.56826e-02;
>   // float  p4   =       -1.16173e-01;
>   // float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
>   // from fit to real data
>   // new
>   float  p0   =       -4.32359e-02;
>   float  p1   =        6.44942e-03;
>   float  p2   =       -8.09058e-04;
>   float  p3   =        3.91918e-02;
>   float  p4   =       -5.68094e-02;
>   float sigma = p0+p1/x+p2/x/x+p3*exp(sqrt(x))+p4*sqrt(x);
>   
>   return (m2tofw - mean)/sigma;
> 
> }
> 
> 
2486a3944,3980
> bool GoodEMC(float emcz, float emcphi)
> {
> 
>   float zed = emcz;
>   float phi = emcphi;
> 
>   if(zed<-120&&phi>0.535) return false;//w2
>   if(zed>130&&zed<150&&phi>0.472&&phi<0.508) return false;//w2
>   if(zed>20&&zed<45&&phi>0.486&&phi<0.536) return false;//w2
>   if(zed>-100&&zed<-80&&phi>0.450&&phi<0.506) return false;//w2
>   if(zed>-125&&zed<-100&&phi>0.470&&phi<0.506) return false;//w2
>   if(zed>-155&&zed<-135&&phi>0.016&&phi<0.058) return false;//w1
> 
> 
>   return true;
> 
> }
> bool SysGoodEMC(float emcz, float emcphi)
> {
> 
>   float zed = emcz;
>   float phi = emcphi;
> 
>   if(zed<-120&&phi>0.535) return false;//w2
>   if(zed>128&&zed<150&&phi>0.472&&phi<0.513) return false;//w2
>   if(zed>18&&zed<45&&phi>0.486&&phi<0.541) return false;//w2
>   if(zed>-102&&zed<-80&&phi>0.450&&phi<0.511) return false;//w2
>   if(zed>-127&&zed<-100&&phi>0.470&&phi<0.511) return false;//w2
>   if(zed>-157&&zed<-135&&phi>0.016&&phi<0.063) return false;//w1
> 
> 
>   return true;
> 
> }
> 
> 
> 
2494c3988
<       cerr << "Couldn't open file\n";
---
>       cerr<<"Couldn't open file"<<endl;
2502c3996
<       //cout << s << '\n';
---
>       //cout<<s<<endl;
2850c4344
<   float sline = 25.0;
---
>   //float sline = 25.0; // unused in this routine
2878c4372
<   float sline = 25.0;
---
>   //float sline = 25.0; // unused this routine
2907,2910c4401,4405
< 
<   float slope = 1.72; // 1.72 is latest and greatest, Monday 10/25/1010
<   float sline = 25.0;
<   float slire = 8.1;
---
>   // 1.72 is latest and greatest, Monday 10/25/1010
>   // none of these used in this routine
>   //float slope = 1.72;
>   //float sline = 25.0;
>   //float slire = 8.1;
2978,2981c4473,4477
< 
<   float slope = 1.72; // 1.72 is latest and greatest, Monday 10/25/1010
<   float sline = 25.0;
<   float slire = 8.1;
---
>   // 1.72 is latest and greatest, Monday 10/25/1010
>   // none of these used in this routine
>   //float slope = 1.72;
>   //float sline = 25.0;
>   //float slire = 8.1;
