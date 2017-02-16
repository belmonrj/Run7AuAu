41a42,53
> float isPionANA_v1(float x, float m2tofw);
> float isKaonANA_v1(float x, float m2tofw);
> float isProtonANA_v1(float x, float m2tofw);
> 
> float isPionANA_v2(float x, float m2tofw);
> float isKaonANA_v2(float x, float m2tofw);
> float isProtonANA_v2(float x, float m2tofw);
> 
> float isPionANA_v3(float x, float m2tofw);
> float isKaonANA_v3(float x, float m2tofw);
> float isProtonANA_v3(float x, float m2tofw);
> 
578,620c590,632
<   // TH1F *ptpid_tofw_w1_pos_0_dis = new TH1F("ptpid_tofw_w1_pos_0_dis", "tofw w1 0 pos pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_pos_1_dis = new TH1F("ptpid_tofw_w1_pos_1_dis", "tofw w1 1 pos pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_pos_2_dis = new TH1F("ptpid_tofw_w1_pos_2_dis", "tofw w1 2 pos pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_pos_3_dis = new TH1F("ptpid_tofw_w1_pos_3_dis", "tofw w1 3 pos pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_pos_4_dis = new TH1F("ptpid_tofw_w1_pos_4_dis", "tofw w1 4 pos ka ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_pos_5_dis = new TH1F("ptpid_tofw_w1_pos_5_dis", "tofw w1 5 pos ka ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_pos_6_dis = new TH1F("ptpid_tofw_w1_pos_6_dis", "tofw w1 6 pos pr ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_pos_7_dis = new TH1F("ptpid_tofw_w1_pos_7_dis", "tofw w1 7 pos pr ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_pos_8_dis = new TH1F("ptpid_tofw_w1_pos_8_dis", "tofw w1 8 pos pr ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_pos_9_dis = new TH1F("ptpid_tofw_w1_pos_9_dis", "tofw w1 9 pos pr ", 100, 0.0, 10.0);
< 
<   // TH1F *ptpid_tofw_w1_neg_0_dis = new TH1F("ptpid_tofw_w1_neg_0_dis", "tofw w1 0 neg pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_neg_1_dis = new TH1F("ptpid_tofw_w1_neg_1_dis", "tofw w1 1 neg pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_neg_2_dis = new TH1F("ptpid_tofw_w1_neg_2_dis", "tofw w1 2 neg pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_neg_3_dis = new TH1F("ptpid_tofw_w1_neg_3_dis", "tofw w1 3 neg pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_neg_4_dis = new TH1F("ptpid_tofw_w1_neg_4_dis", "tofw w1 4 neg ka ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_neg_5_dis = new TH1F("ptpid_tofw_w1_neg_5_dis", "tofw w1 5 neg ka ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_neg_6_dis = new TH1F("ptpid_tofw_w1_neg_6_dis", "tofw w1 6 neg pr ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_neg_7_dis = new TH1F("ptpid_tofw_w1_neg_7_dis", "tofw w1 7 neg pr ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_neg_8_dis = new TH1F("ptpid_tofw_w1_neg_8_dis", "tofw w1 8 neg pr ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w1_neg_9_dis = new TH1F("ptpid_tofw_w1_neg_9_dis", "tofw w1 9 neg pr ", 100, 0.0, 10.0);
< 
<   // TH1F *ptpid_tofw_w2_pos_0_dis = new TH1F("ptpid_tofw_w2_pos_0_dis", "tofw w2 0 pos pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_pos_1_dis = new TH1F("ptpid_tofw_w2_pos_1_dis", "tofw w2 1 pos pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_pos_2_dis = new TH1F("ptpid_tofw_w2_pos_2_dis", "tofw w2 2 pos pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_pos_3_dis = new TH1F("ptpid_tofw_w2_pos_3_dis", "tofw w2 3 pos pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_pos_4_dis = new TH1F("ptpid_tofw_w2_pos_4_dis", "tofw w2 4 pos ka ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_pos_5_dis = new TH1F("ptpid_tofw_w2_pos_5_dis", "tofw w2 5 pos ka ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_pos_6_dis = new TH1F("ptpid_tofw_w2_pos_6_dis", "tofw w2 6 pos pr ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_pos_7_dis = new TH1F("ptpid_tofw_w2_pos_7_dis", "tofw w2 7 pos pr ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_pos_8_dis = new TH1F("ptpid_tofw_w2_pos_8_dis", "tofw w2 8 pos pr ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_pos_9_dis = new TH1F("ptpid_tofw_w2_pos_9_dis", "tofw w2 9 pos pr ", 100, 0.0, 10.0);
< 
<   // TH1F *ptpid_tofw_w2_neg_0_dis = new TH1F("ptpid_tofw_w2_neg_0_dis", "tofw w2 0 neg pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_neg_1_dis = new TH1F("ptpid_tofw_w2_neg_1_dis", "tofw w2 1 neg pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_neg_2_dis = new TH1F("ptpid_tofw_w2_neg_2_dis", "tofw w2 2 neg pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_neg_3_dis = new TH1F("ptpid_tofw_w2_neg_3_dis", "tofw w2 3 neg pi ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_neg_4_dis = new TH1F("ptpid_tofw_w2_neg_4_dis", "tofw w2 4 neg ka ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_neg_5_dis = new TH1F("ptpid_tofw_w2_neg_5_dis", "tofw w2 5 neg ka ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_neg_6_dis = new TH1F("ptpid_tofw_w2_neg_6_dis", "tofw w2 6 neg pr ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_neg_7_dis = new TH1F("ptpid_tofw_w2_neg_7_dis", "tofw w2 7 neg pr ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_neg_8_dis = new TH1F("ptpid_tofw_w2_neg_8_dis", "tofw w2 8 neg pr ", 100, 0.0, 10.0);
<   // TH1F *ptpid_tofw_w2_neg_9_dis = new TH1F("ptpid_tofw_w2_neg_9_dis", "tofw w2 9 neg pr ", 100, 0.0, 10.0);
---
>   TH1F *ptpid_tofw_w1_pos_0_dis = new TH1F("ptpid_tofw_w1_pos_0_dis", "tofw w1 0 pos pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_pos_1_dis = new TH1F("ptpid_tofw_w1_pos_1_dis", "tofw w1 1 pos pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_pos_2_dis = new TH1F("ptpid_tofw_w1_pos_2_dis", "tofw w1 2 pos pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_pos_3_dis = new TH1F("ptpid_tofw_w1_pos_3_dis", "tofw w1 3 pos pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_pos_4_dis = new TH1F("ptpid_tofw_w1_pos_4_dis", "tofw w1 4 pos ka ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_pos_5_dis = new TH1F("ptpid_tofw_w1_pos_5_dis", "tofw w1 5 pos ka ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_pos_6_dis = new TH1F("ptpid_tofw_w1_pos_6_dis", "tofw w1 6 pos pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_pos_7_dis = new TH1F("ptpid_tofw_w1_pos_7_dis", "tofw w1 7 pos pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_pos_8_dis = new TH1F("ptpid_tofw_w1_pos_8_dis", "tofw w1 8 pos pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_pos_9_dis = new TH1F("ptpid_tofw_w1_pos_9_dis", "tofw w1 9 pos pr ", 100, 0.0, 10.0);
> 
>   TH1F *ptpid_tofw_w1_neg_0_dis = new TH1F("ptpid_tofw_w1_neg_0_dis", "tofw w1 0 neg pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_neg_1_dis = new TH1F("ptpid_tofw_w1_neg_1_dis", "tofw w1 1 neg pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_neg_2_dis = new TH1F("ptpid_tofw_w1_neg_2_dis", "tofw w1 2 neg pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_neg_3_dis = new TH1F("ptpid_tofw_w1_neg_3_dis", "tofw w1 3 neg pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_neg_4_dis = new TH1F("ptpid_tofw_w1_neg_4_dis", "tofw w1 4 neg ka ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_neg_5_dis = new TH1F("ptpid_tofw_w1_neg_5_dis", "tofw w1 5 neg ka ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_neg_6_dis = new TH1F("ptpid_tofw_w1_neg_6_dis", "tofw w1 6 neg pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_neg_7_dis = new TH1F("ptpid_tofw_w1_neg_7_dis", "tofw w1 7 neg pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_neg_8_dis = new TH1F("ptpid_tofw_w1_neg_8_dis", "tofw w1 8 neg pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w1_neg_9_dis = new TH1F("ptpid_tofw_w1_neg_9_dis", "tofw w1 9 neg pr ", 100, 0.0, 10.0);
> 
>   TH1F *ptpid_tofw_w2_pos_0_dis = new TH1F("ptpid_tofw_w2_pos_0_dis", "tofw w2 0 pos pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_pos_1_dis = new TH1F("ptpid_tofw_w2_pos_1_dis", "tofw w2 1 pos pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_pos_2_dis = new TH1F("ptpid_tofw_w2_pos_2_dis", "tofw w2 2 pos pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_pos_3_dis = new TH1F("ptpid_tofw_w2_pos_3_dis", "tofw w2 3 pos pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_pos_4_dis = new TH1F("ptpid_tofw_w2_pos_4_dis", "tofw w2 4 pos ka ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_pos_5_dis = new TH1F("ptpid_tofw_w2_pos_5_dis", "tofw w2 5 pos ka ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_pos_6_dis = new TH1F("ptpid_tofw_w2_pos_6_dis", "tofw w2 6 pos pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_pos_7_dis = new TH1F("ptpid_tofw_w2_pos_7_dis", "tofw w2 7 pos pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_pos_8_dis = new TH1F("ptpid_tofw_w2_pos_8_dis", "tofw w2 8 pos pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_pos_9_dis = new TH1F("ptpid_tofw_w2_pos_9_dis", "tofw w2 9 pos pr ", 100, 0.0, 10.0);
> 
>   TH1F *ptpid_tofw_w2_neg_0_dis = new TH1F("ptpid_tofw_w2_neg_0_dis", "tofw w2 0 neg pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_neg_1_dis = new TH1F("ptpid_tofw_w2_neg_1_dis", "tofw w2 1 neg pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_neg_2_dis = new TH1F("ptpid_tofw_w2_neg_2_dis", "tofw w2 2 neg pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_neg_3_dis = new TH1F("ptpid_tofw_w2_neg_3_dis", "tofw w2 3 neg pi ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_neg_4_dis = new TH1F("ptpid_tofw_w2_neg_4_dis", "tofw w2 4 neg ka ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_neg_5_dis = new TH1F("ptpid_tofw_w2_neg_5_dis", "tofw w2 5 neg ka ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_neg_6_dis = new TH1F("ptpid_tofw_w2_neg_6_dis", "tofw w2 6 neg pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_neg_7_dis = new TH1F("ptpid_tofw_w2_neg_7_dis", "tofw w2 7 neg pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_neg_8_dis = new TH1F("ptpid_tofw_w2_neg_8_dis", "tofw w2 8 neg pr ", 100, 0.0, 10.0);
>   TH1F *ptpid_tofw_w2_neg_9_dis = new TH1F("ptpid_tofw_w2_neg_9_dis", "tofw w2 9 neg pr ", 100, 0.0, 10.0);
717,893c729,905
<   // TH1F *ptpid_tofw_w1_pos_0_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_pos_1_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_pos_2_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_pos_3_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_pos_4_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_pos_5_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_pos_6_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_pos_7_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_pos_8_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_pos_9_dis_cent[10];
< 
<   // TH1F *ptpid_tofw_w1_neg_0_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_neg_1_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_neg_2_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_neg_3_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_neg_4_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_neg_5_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_neg_6_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_neg_7_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_neg_8_dis_cent[10];
<   // TH1F *ptpid_tofw_w1_neg_9_dis_cent[10];
< 
<   // char name_ptpid_tofw_w1_pos_0_dis_cent[30];
<   // char name_ptpid_tofw_w1_pos_1_dis_cent[30];
<   // char name_ptpid_tofw_w1_pos_2_dis_cent[30];
<   // char name_ptpid_tofw_w1_pos_3_dis_cent[30];
<   // char name_ptpid_tofw_w1_pos_4_dis_cent[30];
<   // char name_ptpid_tofw_w1_pos_5_dis_cent[30];
<   // char name_ptpid_tofw_w1_pos_6_dis_cent[30];
<   // char name_ptpid_tofw_w1_pos_7_dis_cent[30];
<   // char name_ptpid_tofw_w1_pos_8_dis_cent[30];
<   // char name_ptpid_tofw_w1_pos_9_dis_cent[30];
< 
<   // char name_ptpid_tofw_w1_neg_0_dis_cent[30];
<   // char name_ptpid_tofw_w1_neg_1_dis_cent[30];
<   // char name_ptpid_tofw_w1_neg_2_dis_cent[30];
<   // char name_ptpid_tofw_w1_neg_3_dis_cent[30];
<   // char name_ptpid_tofw_w1_neg_4_dis_cent[30];
<   // char name_ptpid_tofw_w1_neg_5_dis_cent[30];
<   // char name_ptpid_tofw_w1_neg_6_dis_cent[30];
<   // char name_ptpid_tofw_w1_neg_7_dis_cent[30];
<   // char name_ptpid_tofw_w1_neg_8_dis_cent[30];
<   // char name_ptpid_tofw_w1_neg_9_dis_cent[30];
< 
<   // for(int i=0; i<9; i++)
<   //   {
<   //     sprintf(name_ptpid_tofw_w1_pos_0_dis_cent,"ptpid_tofw_w1_pos_0_dis_cent_%d",i);
<   //     ptpid_tofw_w1_pos_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_0_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_pos_1_dis_cent,"ptpid_tofw_w1_pos_1_dis_cent_%d",i);
<   //     ptpid_tofw_w1_pos_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_1_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_pos_2_dis_cent,"ptpid_tofw_w1_pos_2_dis_cent_%d",i);
<   //     ptpid_tofw_w1_pos_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_2_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_pos_3_dis_cent,"ptpid_tofw_w1_pos_3_dis_cent_%d",i);
<   //     ptpid_tofw_w1_pos_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_3_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_pos_4_dis_cent,"ptpid_tofw_w1_pos_4_dis_cent_%d",i);
<   //     ptpid_tofw_w1_pos_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_4_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_pos_5_dis_cent,"ptpid_tofw_w1_pos_5_dis_cent_%d",i);
<   //     ptpid_tofw_w1_pos_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_5_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_pos_6_dis_cent,"ptpid_tofw_w1_pos_6_dis_cent_%d",i);
<   //     ptpid_tofw_w1_pos_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_6_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_pos_7_dis_cent,"ptpid_tofw_w1_pos_7_dis_cent_%d",i);
<   //     ptpid_tofw_w1_pos_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_7_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_pos_8_dis_cent,"ptpid_tofw_w1_pos_8_dis_cent_%d",i);
<   //     ptpid_tofw_w1_pos_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_8_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_pos_9_dis_cent,"ptpid_tofw_w1_pos_9_dis_cent_%d",i);
<   //     ptpid_tofw_w1_pos_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_9_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_neg_0_dis_cent,"ptpid_tofw_w1_neg_0_dis_cent_%d",i);
<   //     ptpid_tofw_w1_neg_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_0_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_neg_1_dis_cent,"ptpid_tofw_w1_neg_1_dis_cent_%d",i);
<   //     ptpid_tofw_w1_neg_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_1_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_neg_2_dis_cent,"ptpid_tofw_w1_neg_2_dis_cent_%d",i);
<   //     ptpid_tofw_w1_neg_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_2_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_neg_3_dis_cent,"ptpid_tofw_w1_neg_3_dis_cent_%d",i);
<   //     ptpid_tofw_w1_neg_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_3_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_neg_4_dis_cent,"ptpid_tofw_w1_neg_4_dis_cent_%d",i);
<   //     ptpid_tofw_w1_neg_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_4_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_neg_5_dis_cent,"ptpid_tofw_w1_neg_5_dis_cent_%d",i);
<   //     ptpid_tofw_w1_neg_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_5_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_neg_6_dis_cent,"ptpid_tofw_w1_neg_6_dis_cent_%d",i);
<   //     ptpid_tofw_w1_neg_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_6_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_neg_7_dis_cent,"ptpid_tofw_w1_neg_7_dis_cent_%d",i);
<   //     ptpid_tofw_w1_neg_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_7_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_neg_8_dis_cent,"ptpid_tofw_w1_neg_8_dis_cent_%d",i);
<   //     ptpid_tofw_w1_neg_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_8_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w1_neg_9_dis_cent,"ptpid_tofw_w1_neg_9_dis_cent_%d",i);
<   //     ptpid_tofw_w1_neg_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_9_dis_cent, "...", 100, 0, 10.0);
<   //   }
< 
<   // // --- tofw w2 --- //
< 
<   // TH1F *ptpid_tofw_w2_pos_0_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_pos_1_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_pos_2_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_pos_3_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_pos_4_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_pos_5_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_pos_6_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_pos_7_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_pos_8_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_pos_9_dis_cent[10];
< 
<   // TH1F *ptpid_tofw_w2_neg_0_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_neg_1_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_neg_2_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_neg_3_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_neg_4_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_neg_5_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_neg_6_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_neg_7_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_neg_8_dis_cent[10];
<   // TH1F *ptpid_tofw_w2_neg_9_dis_cent[10];
< 
<   // char name_ptpid_tofw_w2_pos_0_dis_cent[30];
<   // char name_ptpid_tofw_w2_pos_1_dis_cent[30];
<   // char name_ptpid_tofw_w2_pos_2_dis_cent[30];
<   // char name_ptpid_tofw_w2_pos_3_dis_cent[30];
<   // char name_ptpid_tofw_w2_pos_4_dis_cent[30];
<   // char name_ptpid_tofw_w2_pos_5_dis_cent[30];
<   // char name_ptpid_tofw_w2_pos_6_dis_cent[30];
<   // char name_ptpid_tofw_w2_pos_7_dis_cent[30];
<   // char name_ptpid_tofw_w2_pos_8_dis_cent[30];
<   // char name_ptpid_tofw_w2_pos_9_dis_cent[30];
< 
<   // char name_ptpid_tofw_w2_neg_0_dis_cent[30];
<   // char name_ptpid_tofw_w2_neg_1_dis_cent[30];
<   // char name_ptpid_tofw_w2_neg_2_dis_cent[30];
<   // char name_ptpid_tofw_w2_neg_3_dis_cent[30];
<   // char name_ptpid_tofw_w2_neg_4_dis_cent[30];
<   // char name_ptpid_tofw_w2_neg_5_dis_cent[30];
<   // char name_ptpid_tofw_w2_neg_6_dis_cent[30];
<   // char name_ptpid_tofw_w2_neg_7_dis_cent[30];
<   // char name_ptpid_tofw_w2_neg_8_dis_cent[30];
<   // char name_ptpid_tofw_w2_neg_9_dis_cent[30];
< 
<   // for(int i=0; i<9; i++)
<   //   {
<   //     sprintf(name_ptpid_tofw_w2_pos_0_dis_cent,"ptpid_tofw_w2_pos_0_dis_cent_%d",i);
<   //     ptpid_tofw_w2_pos_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_0_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_pos_1_dis_cent,"ptpid_tofw_w2_pos_1_dis_cent_%d",i);
<   //     ptpid_tofw_w2_pos_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_1_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_pos_2_dis_cent,"ptpid_tofw_w2_pos_2_dis_cent_%d",i);
<   //     ptpid_tofw_w2_pos_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_2_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_pos_3_dis_cent,"ptpid_tofw_w2_pos_3_dis_cent_%d",i);
<   //     ptpid_tofw_w2_pos_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_3_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_pos_4_dis_cent,"ptpid_tofw_w2_pos_4_dis_cent_%d",i);
<   //     ptpid_tofw_w2_pos_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_4_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_pos_5_dis_cent,"ptpid_tofw_w2_pos_5_dis_cent_%d",i);
<   //     ptpid_tofw_w2_pos_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_5_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_pos_6_dis_cent,"ptpid_tofw_w2_pos_6_dis_cent_%d",i);
<   //     ptpid_tofw_w2_pos_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_6_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_pos_7_dis_cent,"ptpid_tofw_w2_pos_7_dis_cent_%d",i);
<   //     ptpid_tofw_w2_pos_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_7_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_pos_8_dis_cent,"ptpid_tofw_w2_pos_8_dis_cent_%d",i);
<   //     ptpid_tofw_w2_pos_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_8_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_pos_9_dis_cent,"ptpid_tofw_w2_pos_9_dis_cent_%d",i);
<   //     ptpid_tofw_w2_pos_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_9_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_neg_0_dis_cent,"ptpid_tofw_w2_neg_0_dis_cent_%d",i);
<   //     ptpid_tofw_w2_neg_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_0_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_neg_1_dis_cent,"ptpid_tofw_w2_neg_1_dis_cent_%d",i);
<   //     ptpid_tofw_w2_neg_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_1_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_neg_2_dis_cent,"ptpid_tofw_w2_neg_2_dis_cent_%d",i);
<   //     ptpid_tofw_w2_neg_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_2_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_neg_3_dis_cent,"ptpid_tofw_w2_neg_3_dis_cent_%d",i);
<   //     ptpid_tofw_w2_neg_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_3_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_neg_4_dis_cent,"ptpid_tofw_w2_neg_4_dis_cent_%d",i);
<   //     ptpid_tofw_w2_neg_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_4_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_neg_5_dis_cent,"ptpid_tofw_w2_neg_5_dis_cent_%d",i);
<   //     ptpid_tofw_w2_neg_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_5_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_neg_6_dis_cent,"ptpid_tofw_w2_neg_6_dis_cent_%d",i);
<   //     ptpid_tofw_w2_neg_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_6_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_neg_7_dis_cent,"ptpid_tofw_w2_neg_7_dis_cent_%d",i);
<   //     ptpid_tofw_w2_neg_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_7_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_neg_8_dis_cent,"ptpid_tofw_w2_neg_8_dis_cent_%d",i);
<   //     ptpid_tofw_w2_neg_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_8_dis_cent, "...", 100, 0, 10.0);
<   //     sprintf(name_ptpid_tofw_w2_neg_9_dis_cent,"ptpid_tofw_w2_neg_9_dis_cent_%d",i);
<   //     ptpid_tofw_w2_neg_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_9_dis_cent, "...", 100, 0, 10.0);
<   //   }
---
>   TH1F *ptpid_tofw_w1_pos_0_dis_cent[10];
>   TH1F *ptpid_tofw_w1_pos_1_dis_cent[10];
>   TH1F *ptpid_tofw_w1_pos_2_dis_cent[10];
>   TH1F *ptpid_tofw_w1_pos_3_dis_cent[10];
>   TH1F *ptpid_tofw_w1_pos_4_dis_cent[10];
>   TH1F *ptpid_tofw_w1_pos_5_dis_cent[10];
>   TH1F *ptpid_tofw_w1_pos_6_dis_cent[10];
>   TH1F *ptpid_tofw_w1_pos_7_dis_cent[10];
>   TH1F *ptpid_tofw_w1_pos_8_dis_cent[10];
>   TH1F *ptpid_tofw_w1_pos_9_dis_cent[10];
> 
>   TH1F *ptpid_tofw_w1_neg_0_dis_cent[10];
>   TH1F *ptpid_tofw_w1_neg_1_dis_cent[10];
>   TH1F *ptpid_tofw_w1_neg_2_dis_cent[10];
>   TH1F *ptpid_tofw_w1_neg_3_dis_cent[10];
>   TH1F *ptpid_tofw_w1_neg_4_dis_cent[10];
>   TH1F *ptpid_tofw_w1_neg_5_dis_cent[10];
>   TH1F *ptpid_tofw_w1_neg_6_dis_cent[10];
>   TH1F *ptpid_tofw_w1_neg_7_dis_cent[10];
>   TH1F *ptpid_tofw_w1_neg_8_dis_cent[10];
>   TH1F *ptpid_tofw_w1_neg_9_dis_cent[10];
> 
>   char name_ptpid_tofw_w1_pos_0_dis_cent[30];
>   char name_ptpid_tofw_w1_pos_1_dis_cent[30];
>   char name_ptpid_tofw_w1_pos_2_dis_cent[30];
>   char name_ptpid_tofw_w1_pos_3_dis_cent[30];
>   char name_ptpid_tofw_w1_pos_4_dis_cent[30];
>   char name_ptpid_tofw_w1_pos_5_dis_cent[30];
>   char name_ptpid_tofw_w1_pos_6_dis_cent[30];
>   char name_ptpid_tofw_w1_pos_7_dis_cent[30];
>   char name_ptpid_tofw_w1_pos_8_dis_cent[30];
>   char name_ptpid_tofw_w1_pos_9_dis_cent[30];
> 
>   char name_ptpid_tofw_w1_neg_0_dis_cent[30];
>   char name_ptpid_tofw_w1_neg_1_dis_cent[30];
>   char name_ptpid_tofw_w1_neg_2_dis_cent[30];
>   char name_ptpid_tofw_w1_neg_3_dis_cent[30];
>   char name_ptpid_tofw_w1_neg_4_dis_cent[30];
>   char name_ptpid_tofw_w1_neg_5_dis_cent[30];
>   char name_ptpid_tofw_w1_neg_6_dis_cent[30];
>   char name_ptpid_tofw_w1_neg_7_dis_cent[30];
>   char name_ptpid_tofw_w1_neg_8_dis_cent[30];
>   char name_ptpid_tofw_w1_neg_9_dis_cent[30];
> 
>   for(int i=0; i<9; i++)
>     {
>       sprintf(name_ptpid_tofw_w1_pos_0_dis_cent,"ptpid_tofw_w1_pos_0_dis_cent_%d",i);
>       ptpid_tofw_w1_pos_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_0_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_pos_1_dis_cent,"ptpid_tofw_w1_pos_1_dis_cent_%d",i);
>       ptpid_tofw_w1_pos_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_1_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_pos_2_dis_cent,"ptpid_tofw_w1_pos_2_dis_cent_%d",i);
>       ptpid_tofw_w1_pos_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_2_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_pos_3_dis_cent,"ptpid_tofw_w1_pos_3_dis_cent_%d",i);
>       ptpid_tofw_w1_pos_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_3_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_pos_4_dis_cent,"ptpid_tofw_w1_pos_4_dis_cent_%d",i);
>       ptpid_tofw_w1_pos_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_4_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_pos_5_dis_cent,"ptpid_tofw_w1_pos_5_dis_cent_%d",i);
>       ptpid_tofw_w1_pos_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_5_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_pos_6_dis_cent,"ptpid_tofw_w1_pos_6_dis_cent_%d",i);
>       ptpid_tofw_w1_pos_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_6_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_pos_7_dis_cent,"ptpid_tofw_w1_pos_7_dis_cent_%d",i);
>       ptpid_tofw_w1_pos_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_7_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_pos_8_dis_cent,"ptpid_tofw_w1_pos_8_dis_cent_%d",i);
>       ptpid_tofw_w1_pos_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_8_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_pos_9_dis_cent,"ptpid_tofw_w1_pos_9_dis_cent_%d",i);
>       ptpid_tofw_w1_pos_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_pos_9_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_neg_0_dis_cent,"ptpid_tofw_w1_neg_0_dis_cent_%d",i);
>       ptpid_tofw_w1_neg_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_0_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_neg_1_dis_cent,"ptpid_tofw_w1_neg_1_dis_cent_%d",i);
>       ptpid_tofw_w1_neg_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_1_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_neg_2_dis_cent,"ptpid_tofw_w1_neg_2_dis_cent_%d",i);
>       ptpid_tofw_w1_neg_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_2_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_neg_3_dis_cent,"ptpid_tofw_w1_neg_3_dis_cent_%d",i);
>       ptpid_tofw_w1_neg_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_3_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_neg_4_dis_cent,"ptpid_tofw_w1_neg_4_dis_cent_%d",i);
>       ptpid_tofw_w1_neg_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_4_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_neg_5_dis_cent,"ptpid_tofw_w1_neg_5_dis_cent_%d",i);
>       ptpid_tofw_w1_neg_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_5_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_neg_6_dis_cent,"ptpid_tofw_w1_neg_6_dis_cent_%d",i);
>       ptpid_tofw_w1_neg_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_6_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_neg_7_dis_cent,"ptpid_tofw_w1_neg_7_dis_cent_%d",i);
>       ptpid_tofw_w1_neg_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_7_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_neg_8_dis_cent,"ptpid_tofw_w1_neg_8_dis_cent_%d",i);
>       ptpid_tofw_w1_neg_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_8_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w1_neg_9_dis_cent,"ptpid_tofw_w1_neg_9_dis_cent_%d",i);
>       ptpid_tofw_w1_neg_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w1_neg_9_dis_cent, "...", 100, 0, 10.0);
>     }
> 
>   // --- tofw w2 --- //
> 
>   TH1F *ptpid_tofw_w2_pos_0_dis_cent[10];
>   TH1F *ptpid_tofw_w2_pos_1_dis_cent[10];
>   TH1F *ptpid_tofw_w2_pos_2_dis_cent[10];
>   TH1F *ptpid_tofw_w2_pos_3_dis_cent[10];
>   TH1F *ptpid_tofw_w2_pos_4_dis_cent[10];
>   TH1F *ptpid_tofw_w2_pos_5_dis_cent[10];
>   TH1F *ptpid_tofw_w2_pos_6_dis_cent[10];
>   TH1F *ptpid_tofw_w2_pos_7_dis_cent[10];
>   TH1F *ptpid_tofw_w2_pos_8_dis_cent[10];
>   TH1F *ptpid_tofw_w2_pos_9_dis_cent[10];
> 
>   TH1F *ptpid_tofw_w2_neg_0_dis_cent[10];
>   TH1F *ptpid_tofw_w2_neg_1_dis_cent[10];
>   TH1F *ptpid_tofw_w2_neg_2_dis_cent[10];
>   TH1F *ptpid_tofw_w2_neg_3_dis_cent[10];
>   TH1F *ptpid_tofw_w2_neg_4_dis_cent[10];
>   TH1F *ptpid_tofw_w2_neg_5_dis_cent[10];
>   TH1F *ptpid_tofw_w2_neg_6_dis_cent[10];
>   TH1F *ptpid_tofw_w2_neg_7_dis_cent[10];
>   TH1F *ptpid_tofw_w2_neg_8_dis_cent[10];
>   TH1F *ptpid_tofw_w2_neg_9_dis_cent[10];
> 
>   char name_ptpid_tofw_w2_pos_0_dis_cent[30];
>   char name_ptpid_tofw_w2_pos_1_dis_cent[30];
>   char name_ptpid_tofw_w2_pos_2_dis_cent[30];
>   char name_ptpid_tofw_w2_pos_3_dis_cent[30];
>   char name_ptpid_tofw_w2_pos_4_dis_cent[30];
>   char name_ptpid_tofw_w2_pos_5_dis_cent[30];
>   char name_ptpid_tofw_w2_pos_6_dis_cent[30];
>   char name_ptpid_tofw_w2_pos_7_dis_cent[30];
>   char name_ptpid_tofw_w2_pos_8_dis_cent[30];
>   char name_ptpid_tofw_w2_pos_9_dis_cent[30];
> 
>   char name_ptpid_tofw_w2_neg_0_dis_cent[30];
>   char name_ptpid_tofw_w2_neg_1_dis_cent[30];
>   char name_ptpid_tofw_w2_neg_2_dis_cent[30];
>   char name_ptpid_tofw_w2_neg_3_dis_cent[30];
>   char name_ptpid_tofw_w2_neg_4_dis_cent[30];
>   char name_ptpid_tofw_w2_neg_5_dis_cent[30];
>   char name_ptpid_tofw_w2_neg_6_dis_cent[30];
>   char name_ptpid_tofw_w2_neg_7_dis_cent[30];
>   char name_ptpid_tofw_w2_neg_8_dis_cent[30];
>   char name_ptpid_tofw_w2_neg_9_dis_cent[30];
> 
>   for(int i=0; i<9; i++)
>     {
>       sprintf(name_ptpid_tofw_w2_pos_0_dis_cent,"ptpid_tofw_w2_pos_0_dis_cent_%d",i);
>       ptpid_tofw_w2_pos_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_0_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_pos_1_dis_cent,"ptpid_tofw_w2_pos_1_dis_cent_%d",i);
>       ptpid_tofw_w2_pos_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_1_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_pos_2_dis_cent,"ptpid_tofw_w2_pos_2_dis_cent_%d",i);
>       ptpid_tofw_w2_pos_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_2_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_pos_3_dis_cent,"ptpid_tofw_w2_pos_3_dis_cent_%d",i);
>       ptpid_tofw_w2_pos_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_3_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_pos_4_dis_cent,"ptpid_tofw_w2_pos_4_dis_cent_%d",i);
>       ptpid_tofw_w2_pos_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_4_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_pos_5_dis_cent,"ptpid_tofw_w2_pos_5_dis_cent_%d",i);
>       ptpid_tofw_w2_pos_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_5_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_pos_6_dis_cent,"ptpid_tofw_w2_pos_6_dis_cent_%d",i);
>       ptpid_tofw_w2_pos_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_6_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_pos_7_dis_cent,"ptpid_tofw_w2_pos_7_dis_cent_%d",i);
>       ptpid_tofw_w2_pos_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_7_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_pos_8_dis_cent,"ptpid_tofw_w2_pos_8_dis_cent_%d",i);
>       ptpid_tofw_w2_pos_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_8_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_pos_9_dis_cent,"ptpid_tofw_w2_pos_9_dis_cent_%d",i);
>       ptpid_tofw_w2_pos_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_pos_9_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_neg_0_dis_cent,"ptpid_tofw_w2_neg_0_dis_cent_%d",i);
>       ptpid_tofw_w2_neg_0_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_0_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_neg_1_dis_cent,"ptpid_tofw_w2_neg_1_dis_cent_%d",i);
>       ptpid_tofw_w2_neg_1_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_1_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_neg_2_dis_cent,"ptpid_tofw_w2_neg_2_dis_cent_%d",i);
>       ptpid_tofw_w2_neg_2_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_2_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_neg_3_dis_cent,"ptpid_tofw_w2_neg_3_dis_cent_%d",i);
>       ptpid_tofw_w2_neg_3_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_3_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_neg_4_dis_cent,"ptpid_tofw_w2_neg_4_dis_cent_%d",i);
>       ptpid_tofw_w2_neg_4_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_4_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_neg_5_dis_cent,"ptpid_tofw_w2_neg_5_dis_cent_%d",i);
>       ptpid_tofw_w2_neg_5_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_5_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_neg_6_dis_cent,"ptpid_tofw_w2_neg_6_dis_cent_%d",i);
>       ptpid_tofw_w2_neg_6_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_6_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_neg_7_dis_cent,"ptpid_tofw_w2_neg_7_dis_cent_%d",i);
>       ptpid_tofw_w2_neg_7_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_7_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_neg_8_dis_cent,"ptpid_tofw_w2_neg_8_dis_cent_%d",i);
>       ptpid_tofw_w2_neg_8_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_8_dis_cent, "...", 100, 0, 10.0);
>       sprintf(name_ptpid_tofw_w2_neg_9_dis_cent,"ptpid_tofw_w2_neg_9_dis_cent_%d",i);
>       ptpid_tofw_w2_neg_9_dis_cent[i] = new TH1F(name_ptpid_tofw_w2_neg_9_dis_cent, "...", 100, 0, 10.0);
>     }
1297a1310,1360
>   TH1F *testpid_tofw_pionpos_0_dis = new TH1F("testpid_tofw_pionpos_0_dis", "tofw 0 pionpos", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_pionpos_1_dis = new TH1F("testpid_tofw_pionpos_1_dis", "tofw 1 pionpos", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_pionpos_2_dis = new TH1F("testpid_tofw_pionpos_2_dis", "tofw 2 pionpos", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_pionpos_3_dis = new TH1F("testpid_tofw_pionpos_3_dis", "tofw 3 pionpos", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_pionpos_4_dis = new TH1F("testpid_tofw_pionpos_4_dis", "tofw 4 pionpos", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_pionpos_5_dis = new TH1F("testpid_tofw_pionpos_5_dis", "tofw 5 pionpos", 100, 0.0, 10.0);
> 										        
>   TH1F *testpid_tofw_pionneg_0_dis = new TH1F("testpid_tofw_pionneg_0_dis", "tofw 0 pionneg", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_pionneg_1_dis = new TH1F("testpid_tofw_pionneg_1_dis", "tofw 1 pionneg", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_pionneg_2_dis = new TH1F("testpid_tofw_pionneg_2_dis", "tofw 2 pionneg", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_pionneg_3_dis = new TH1F("testpid_tofw_pionneg_3_dis", "tofw 3 pionneg", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_pionneg_4_dis = new TH1F("testpid_tofw_pionneg_4_dis", "tofw 4 pionneg", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_pionneg_5_dis = new TH1F("testpid_tofw_pionneg_5_dis", "tofw 5 pionneg", 100, 0.0, 10.0);
> 
>   TH1F *testpid_tofw_kaonpos_0_dis = new TH1F("testpid_tofw_kaonpos_0_dis", "tofw 0 kaonpos", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_kaonpos_1_dis = new TH1F("testpid_tofw_kaonpos_1_dis", "tofw 1 kaonpos", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_kaonpos_2_dis = new TH1F("testpid_tofw_kaonpos_2_dis", "tofw 2 kaonpos", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_kaonpos_3_dis = new TH1F("testpid_tofw_kaonpos_3_dis", "tofw 3 kaonpos", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_kaonpos_4_dis = new TH1F("testpid_tofw_kaonpos_4_dis", "tofw 4 kaonpos", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_kaonpos_5_dis = new TH1F("testpid_tofw_kaonpos_5_dis", "tofw 5 kaonpos", 100, 0.0, 10.0);
> 										        
>   TH1F *testpid_tofw_kaonneg_0_dis = new TH1F("testpid_tofw_kaonneg_0_dis", "tofw 0 kaonneg", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_kaonneg_1_dis = new TH1F("testpid_tofw_kaonneg_1_dis", "tofw 1 kaonneg", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_kaonneg_2_dis = new TH1F("testpid_tofw_kaonneg_2_dis", "tofw 2 kaonneg", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_kaonneg_3_dis = new TH1F("testpid_tofw_kaonneg_3_dis", "tofw 3 kaonneg", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_kaonneg_4_dis = new TH1F("testpid_tofw_kaonneg_4_dis", "tofw 4 kaonneg", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_kaonneg_5_dis = new TH1F("testpid_tofw_kaonneg_5_dis", "tofw 5 kaonneg", 100, 0.0, 10.0);
> 
>   TH1F *testpid_tofw_protonpos_0_dis = new TH1F("testpid_tofw_protonpos_0_dis", "tofw 0 protonpos", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_protonpos_1_dis = new TH1F("testpid_tofw_protonpos_1_dis", "tofw 1 protonpos", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_protonpos_2_dis = new TH1F("testpid_tofw_protonpos_2_dis", "tofw 2 protonpos", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_protonpos_3_dis = new TH1F("testpid_tofw_protonpos_3_dis", "tofw 3 protonpos", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_protonpos_4_dis = new TH1F("testpid_tofw_protonpos_4_dis", "tofw 4 protonpos", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_protonpos_5_dis = new TH1F("testpid_tofw_protonpos_5_dis", "tofw 5 protonpos", 100, 0.0, 10.0);
> 										        
>   TH1F *testpid_tofw_protonneg_0_dis = new TH1F("testpid_tofw_protonneg_0_dis", "tofw 0 protonneg", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_protonneg_1_dis = new TH1F("testpid_tofw_protonneg_1_dis", "tofw 1 protonneg", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_protonneg_2_dis = new TH1F("testpid_tofw_protonneg_2_dis", "tofw 2 protonneg", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_protonneg_3_dis = new TH1F("testpid_tofw_protonneg_3_dis", "tofw 3 protonneg", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_protonneg_4_dis = new TH1F("testpid_tofw_protonneg_4_dis", "tofw 4 protonneg", 100, 0.0, 10.0);
>   TH1F *testpid_tofw_protonneg_5_dis = new TH1F("testpid_tofw_protonneg_5_dis", "tofw 5 protonneg", 100, 0.0, 10.0);
> 
> 
>   TH1F *h_neve = new TH1F("h_neve","Number of events vs run number",848,0,848);
>   TH1F *h_numb = new TH1F("h_numb","Number of tracks vs run number",848,0,848);
>   TH1F *h_numpos = new TH1F("h_numpos","Number of tracks vs run number",848,0,848);
>   TH1F *h_numneg = new TH1F("h_numneg","Number of tracks vs run number",848,0,848);
>   TH1F *h_numbC = new TH1F("h_numbC","Number of tracks vs run number",848,0,848);
>   TH1F *h_numposC = new TH1F("h_numposC","Number of tracks vs run number",848,0,848);
>   TH1F *h_numnegC = new TH1F("h_numnegC","Number of tracks vs run number",848,0,858);
> 
1354,1356c1417,1420
< 	  //stringstream ss;
< 	  //ss<<run;
< 	  //int runindex = myMap[ss.str()]; 
---
> 	  stringstream ss;
> 	  ss<<run;
> 	  int runindex = myMap[ss.str()]; 
> 	  h_neve->Fill(runindex); // events per run histograms
1413a1478,1481
> 	      h_numb->Fill(runindex);
> 	      if(charge>0) h_numpos->Fill(runindex);
> 	      if(charge<0) h_numneg->Fill(runindex);
> 
1671a1740,1746
> 	      if(regular_cuts&&edge&&inner)
> 		{
> 		  h_numbC->Fill(runindex);
> 		  if(charge>0) h_numposC->Fill(runindex);
> 		  if(charge<0) h_numnegC->Fill(runindex);
> 		}
> 
1703,1705c1778,1780
< 	      bool isPi = (isPiLME>=-2&&isPiLME<=2);
< 	      bool isK = (isKLME>=-2&&isKLME<=2);
< 	      bool isP = (isPLME>=-2&&isPLME<=2);
---
> 	      // bool isPi = (isPiLME>=-2&&isPiLME<=2);
> 	      // bool isK = (isKLME>=-2&&isKLME<=2);
> 	      // bool isP = (isPLME>=-2&&isPLME<=2);
1794a1870,1954
> 	      float isPiNew = isPionLow(pT,m2tofw);
> 	      float isKNew = isKaonLow(pT,m2tofw);
> 	      float isPNew = isProtonLow(pT,m2tofw);
> 	      float isPiOld = isPionLME(pT,m2tofw);
> 	      float isKOld = isKaonLME(pT,m2tofw);
> 	      float isPOld = isProtonLME(pT,m2tofw);
> 	      float isPiAna1 = isPionANA_v1(pT,m2tofw);
> 	      float isKAna1 = isKaonANA_v1(pT,m2tofw);
> 	      float isPAna1 = isProtonANA_v1(pT,m2tofw);
> 	      float isPiAna2 = isPionANA_v2(pT,m2tofw);
> 	      float isKAna2 = isKaonANA_v2(pT,m2tofw);
> 	      float isPAna2 = isProtonANA_v2(pT,m2tofw);
> 	      float isPiAna3 = isPionANA_v3(pT,m2tofw);
> 	      float isKAna3 = isKaonANA_v3(pT,m2tofw);
> 	      float isPAna3 = isProtonANA_v3(pT,m2tofw);
> 
> 	      float isPi = isPiOld;
> 	      float isK = isKOld;
> 	      float isP = isPOld;
> 
> 	      bool piondis0 = isPiNew>=-2 && isPiNew<=2 && isKNew<=-2;
> 	      bool piondis1 = isPiOld>=-2 && isPiOld<=2 && isKOld<=-2;
> 	      bool piondis2 = isPiAna1>=-2 && isPiAna1<=2 && isKAna1<=-2;
> 	      bool piondis3 = isPiAna2>=-2 && isPiAna2<=2 && isKAna2<=-2;
> 	      bool piondis4 = isPiAna3>=-2 && isPiAna3<=2 && isKAna3<=-2;
> 	      bool piondis5 = true;
> 	      bool kaondis0 = isKNew>=-2 && isKNew<=2 && isPiNew>=2 && isPNew<=-2;
> 	      bool kaondis1 = isKOld>=-2 && isKOld<=2 && isPiOld>=2 && isPOld<=-2;
> 	      bool kaondis2 = isKAna1>=-2 && isKAna1<=2 && isPiAna1>=2 && isPAna1<=-2;
> 	      bool kaondis3 = isKAna2>=-2 && isKAna2<=2 && isPiAna2>=2 && isPAna2<=-2;
> 	      bool kaondis4 = isKAna3>=-2 && isKAna3<=2 && isPiAna3>=2 && isPAna3<=-2;
> 	      bool kaondis5 = true;
> 	      bool protondis0 = isPNew>=-2 && isPNew<=2 && isKNew>=2;
> 	      bool protondis1 = isPOld>=-2 && isPOld<=2 && isKOld>=2;
> 	      bool protondis2 = isPAna1>=-2 && isPAna1<=2 && isKAna1>=2;
> 	      bool protondis3 = isPAna2>=-2 && isPAna2<=2 && isKAna2>=2;
> 	      bool protondis4 = isPAna3>=-2 && isPAna3<=2 && isKAna3>=2;
> 	      bool protondis5 = true;
> 
> 	      if(regular_cuts&&edge&&inner)
> 		{
> 		  if(charge>0)
> 		    {
> 		      if(piondis0) testpid_tofw_pionpos_0_dis->Fill(pT);
> 		      if(piondis1) testpid_tofw_pionpos_1_dis->Fill(pT);
> 		      if(piondis2) testpid_tofw_pionpos_2_dis->Fill(pT);
> 		      if(piondis3) testpid_tofw_pionpos_3_dis->Fill(pT);
> 		      if(piondis4) testpid_tofw_pionpos_4_dis->Fill(pT);
> 		      if(piondis5) testpid_tofw_pionpos_5_dis->Fill(pT);
> 		      if(kaondis0) testpid_tofw_kaonpos_0_dis->Fill(pT);
> 		      if(kaondis1) testpid_tofw_kaonpos_1_dis->Fill(pT);
> 		      if(kaondis2) testpid_tofw_kaonpos_2_dis->Fill(pT);
> 		      if(kaondis3) testpid_tofw_kaonpos_3_dis->Fill(pT);
> 		      if(kaondis4) testpid_tofw_kaonpos_4_dis->Fill(pT);
> 		      if(kaondis5) testpid_tofw_kaonpos_5_dis->Fill(pT);
> 		      if(protondis0) testpid_tofw_protonpos_0_dis->Fill(pT);
> 		      if(protondis1) testpid_tofw_protonpos_1_dis->Fill(pT);
> 		      if(protondis2) testpid_tofw_protonpos_2_dis->Fill(pT);
> 		      if(protondis3) testpid_tofw_protonpos_3_dis->Fill(pT);
> 		      if(protondis4) testpid_tofw_protonpos_4_dis->Fill(pT);
> 		      if(protondis5) testpid_tofw_protonpos_5_dis->Fill(pT);
> 		    }
> 		  if(charge<0)
> 		    {
> 		      if(piondis0) testpid_tofw_pionneg_0_dis->Fill(pT);
> 		      if(piondis1) testpid_tofw_pionneg_1_dis->Fill(pT);
> 		      if(piondis2) testpid_tofw_pionneg_2_dis->Fill(pT);
> 		      if(piondis3) testpid_tofw_pionneg_3_dis->Fill(pT);
> 		      if(piondis4) testpid_tofw_pionneg_4_dis->Fill(pT);
> 		      if(piondis5) testpid_tofw_pionneg_5_dis->Fill(pT);
> 		      if(kaondis0) testpid_tofw_kaonneg_0_dis->Fill(pT);
> 		      if(kaondis1) testpid_tofw_kaonneg_1_dis->Fill(pT);
> 		      if(kaondis2) testpid_tofw_kaonneg_2_dis->Fill(pT);
> 		      if(kaondis3) testpid_tofw_kaonneg_3_dis->Fill(pT);
> 		      if(kaondis4) testpid_tofw_kaonneg_4_dis->Fill(pT);
> 		      if(kaondis5) testpid_tofw_kaonneg_5_dis->Fill(pT);
> 		      if(protondis0) testpid_tofw_protonneg_0_dis->Fill(pT);
> 		      if(protondis1) testpid_tofw_protonneg_1_dis->Fill(pT);
> 		      if(protondis2) testpid_tofw_protonneg_2_dis->Fill(pT);
> 		      if(protondis3) testpid_tofw_protonneg_3_dis->Fill(pT);
> 		      if(protondis4) testpid_tofw_protonneg_4_dis->Fill(pT);
> 		      if(protondis5) testpid_tofw_protonneg_5_dis->Fill(pT);
> 		    }
> 		}
> 
1796,1799c1956,1959
< 	      //bool w1pos = charge>0 && striptofw>=0 && striptofw<=255;
< 	      //bool w1neg = charge<0 && striptofw>=0 && striptofw<=255;
< 	      //bool w2pos = charge>0 && striptofw>=256 && striptofw<=511;
< 	      //bool w2neg = charge<0 && striptofw>=256 && striptofw<=511;
---
> 	      bool w1pos = charge>0 && striptofw>=0 && striptofw<=255;
> 	      bool w1neg = charge<0 && striptofw>=0 && striptofw<=255;
> 	      bool w2pos = charge>0 && striptofw>=256 && striptofw<=511;
> 	      bool w2neg = charge<0 && striptofw>=256 && striptofw<=511;
1804c1964
< 	      if(pT>=4.0) dis1 = dis0 && good_emc && ep>0.2;
---
> 	      if(pT>=3.0) dis1 = dis0 && good_emc && ep>0.2;
1809c1969
< 	      bool dis5 = isKLME>=-2 && isKLME<=2;
---
> 	      bool dis5 = isKLME>=-2 && isKLME<=2 && isPiLME>=2 && isPLME<=-2;
1813c1973
< 	      if(pT>=4.0) dis7 = dis6 && good_emc && ep>0.2;
---
> 	      if(pT>=3.0) dis7 = dis6 && good_emc && ep>0.2;
2785,2884c2945,3044
< 		  // if(w1pos)
< 		  //   {
< 		  //     //1-d
< 		  //     if(dis0) ptpid_tofw_w1_pos_0_dis->Fill(pT);
< 		  //     if(dis1) ptpid_tofw_w1_pos_1_dis->Fill(pT);
< 		  //     if(dis2) ptpid_tofw_w1_pos_2_dis->Fill(pT);
< 		  //     if(dis3) ptpid_tofw_w1_pos_3_dis->Fill(pT);
< 		  //     if(dis4) ptpid_tofw_w1_pos_4_dis->Fill(pT);
< 		  //     if(dis5) ptpid_tofw_w1_pos_5_dis->Fill(pT);
< 		  //     if(dis6) ptpid_tofw_w1_pos_6_dis->Fill(pT);
< 		  //     if(dis7) ptpid_tofw_w1_pos_7_dis->Fill(pT);
< 		  //     if(dis8) ptpid_tofw_w1_pos_8_dis->Fill(pT);
< 		  //     if(dis9) ptpid_tofw_w1_pos_9_dis->Fill(pT);
< 		  //     //1-d
< 		  //     if(dis0) ptpid_tofw_w1_pos_0_dis_cent[icent]->Fill(pT);
< 		  //     if(dis1) ptpid_tofw_w1_pos_1_dis_cent[icent]->Fill(pT);
< 		  //     if(dis2) ptpid_tofw_w1_pos_2_dis_cent[icent]->Fill(pT);
< 		  //     if(dis3) ptpid_tofw_w1_pos_3_dis_cent[icent]->Fill(pT);
< 		  //     if(dis4) ptpid_tofw_w1_pos_4_dis_cent[icent]->Fill(pT);
< 		  //     if(dis5) ptpid_tofw_w1_pos_5_dis_cent[icent]->Fill(pT);
< 		  //     if(dis6) ptpid_tofw_w1_pos_6_dis_cent[icent]->Fill(pT);
< 		  //     if(dis7) ptpid_tofw_w1_pos_7_dis_cent[icent]->Fill(pT);
< 		  //     if(dis8) ptpid_tofw_w1_pos_8_dis_cent[icent]->Fill(pT);
< 		  //     if(dis9) ptpid_tofw_w1_pos_9_dis_cent[icent]->Fill(pT);
< 		  //   }
< 		  // if(w1neg)
< 		  //   {
< 		  //     //1-d
< 		  //     if(dis0) ptpid_tofw_w1_neg_0_dis->Fill(pT);
< 		  //     if(dis1) ptpid_tofw_w1_neg_1_dis->Fill(pT);
< 		  //     if(dis2) ptpid_tofw_w1_neg_2_dis->Fill(pT);
< 		  //     if(dis3) ptpid_tofw_w1_neg_3_dis->Fill(pT);
< 		  //     if(dis4) ptpid_tofw_w1_neg_4_dis->Fill(pT);
< 		  //     if(dis5) ptpid_tofw_w1_neg_5_dis->Fill(pT);
< 		  //     if(dis6) ptpid_tofw_w1_neg_6_dis->Fill(pT);
< 		  //     if(dis7) ptpid_tofw_w1_neg_7_dis->Fill(pT);
< 		  //     if(dis8) ptpid_tofw_w1_neg_8_dis->Fill(pT);
< 		  //     if(dis9) ptpid_tofw_w1_neg_9_dis->Fill(pT);
< 		  //     //1-d
< 		  //     if(dis0) ptpid_tofw_w1_neg_0_dis_cent[icent]->Fill(pT);
< 		  //     if(dis1) ptpid_tofw_w1_neg_1_dis_cent[icent]->Fill(pT);
< 		  //     if(dis2) ptpid_tofw_w1_neg_2_dis_cent[icent]->Fill(pT);
< 		  //     if(dis3) ptpid_tofw_w1_neg_3_dis_cent[icent]->Fill(pT);
< 		  //     if(dis4) ptpid_tofw_w1_neg_4_dis_cent[icent]->Fill(pT);
< 		  //     if(dis5) ptpid_tofw_w1_neg_5_dis_cent[icent]->Fill(pT);
< 		  //     if(dis6) ptpid_tofw_w1_neg_6_dis_cent[icent]->Fill(pT);
< 		  //     if(dis7) ptpid_tofw_w1_neg_7_dis_cent[icent]->Fill(pT);
< 		  //     if(dis8) ptpid_tofw_w1_neg_8_dis_cent[icent]->Fill(pT);
< 		  //     if(dis9) ptpid_tofw_w1_neg_9_dis_cent[icent]->Fill(pT);
< 		  //   }
< 		  // if(w2pos)
< 		  //   {
< 		  //     //1-d
< 		  //     if(dis0) ptpid_tofw_w2_pos_0_dis->Fill(pT);
< 		  //     if(dis1) ptpid_tofw_w2_pos_1_dis->Fill(pT);
< 		  //     if(dis2) ptpid_tofw_w2_pos_2_dis->Fill(pT);
< 		  //     if(dis3) ptpid_tofw_w2_pos_3_dis->Fill(pT);
< 		  //     if(dis4) ptpid_tofw_w2_pos_4_dis->Fill(pT);
< 		  //     if(dis5) ptpid_tofw_w2_pos_5_dis->Fill(pT);
< 		  //     if(dis6) ptpid_tofw_w2_pos_6_dis->Fill(pT);
< 		  //     if(dis7) ptpid_tofw_w2_pos_7_dis->Fill(pT);
< 		  //     if(dis8) ptpid_tofw_w2_pos_8_dis->Fill(pT);
< 		  //     if(dis9) ptpid_tofw_w2_pos_9_dis->Fill(pT);
< 		  //     //1-d
< 		  //     if(dis0) ptpid_tofw_w2_pos_0_dis_cent[icent]->Fill(pT);
< 		  //     if(dis1) ptpid_tofw_w2_pos_1_dis_cent[icent]->Fill(pT);
< 		  //     if(dis2) ptpid_tofw_w2_pos_2_dis_cent[icent]->Fill(pT);
< 		  //     if(dis3) ptpid_tofw_w2_pos_3_dis_cent[icent]->Fill(pT);
< 		  //     if(dis4) ptpid_tofw_w2_pos_4_dis_cent[icent]->Fill(pT);
< 		  //     if(dis5) ptpid_tofw_w2_pos_5_dis_cent[icent]->Fill(pT);
< 		  //     if(dis6) ptpid_tofw_w2_pos_6_dis_cent[icent]->Fill(pT);
< 		  //     if(dis7) ptpid_tofw_w2_pos_7_dis_cent[icent]->Fill(pT);
< 		  //     if(dis8) ptpid_tofw_w2_pos_8_dis_cent[icent]->Fill(pT);
< 		  //     if(dis9) ptpid_tofw_w2_pos_9_dis_cent[icent]->Fill(pT);
< 		  //   }
< 		  // if(w2neg)
< 		  //   {
< 		  //     //1-d
< 		  //     if(dis0) ptpid_tofw_w2_neg_0_dis->Fill(pT);
< 		  //     if(dis1) ptpid_tofw_w2_neg_1_dis->Fill(pT);
< 		  //     if(dis2) ptpid_tofw_w2_neg_2_dis->Fill(pT);
< 		  //     if(dis3) ptpid_tofw_w2_neg_3_dis->Fill(pT);
< 		  //     if(dis4) ptpid_tofw_w2_neg_4_dis->Fill(pT);
< 		  //     if(dis5) ptpid_tofw_w2_neg_5_dis->Fill(pT);
< 		  //     if(dis6) ptpid_tofw_w2_neg_6_dis->Fill(pT);
< 		  //     if(dis7) ptpid_tofw_w2_neg_7_dis->Fill(pT);
< 		  //     if(dis8) ptpid_tofw_w2_neg_8_dis->Fill(pT);
< 		  //     if(dis9) ptpid_tofw_w2_neg_9_dis->Fill(pT);
< 		  //     //1-d
< 		  //     if(dis0) ptpid_tofw_w2_neg_0_dis_cent[icent]->Fill(pT);
< 		  //     if(dis1) ptpid_tofw_w2_neg_1_dis_cent[icent]->Fill(pT);
< 		  //     if(dis2) ptpid_tofw_w2_neg_2_dis_cent[icent]->Fill(pT);
< 		  //     if(dis3) ptpid_tofw_w2_neg_3_dis_cent[icent]->Fill(pT);
< 		  //     if(dis4) ptpid_tofw_w2_neg_4_dis_cent[icent]->Fill(pT);
< 		  //     if(dis5) ptpid_tofw_w2_neg_5_dis_cent[icent]->Fill(pT);
< 		  //     if(dis6) ptpid_tofw_w2_neg_6_dis_cent[icent]->Fill(pT);
< 		  //     if(dis7) ptpid_tofw_w2_neg_7_dis_cent[icent]->Fill(pT);
< 		  //     if(dis8) ptpid_tofw_w2_neg_8_dis_cent[icent]->Fill(pT);
< 		  //     if(dis9) ptpid_tofw_w2_neg_9_dis_cent[icent]->Fill(pT);
< 		  //   }
---
> 		  if(w1pos)
> 		    {
> 		      //1-d
> 		      if(dis0) ptpid_tofw_w1_pos_0_dis->Fill(pT);
> 		      if(dis1) ptpid_tofw_w1_pos_1_dis->Fill(pT);
> 		      if(dis2) ptpid_tofw_w1_pos_2_dis->Fill(pT);
> 		      if(dis3) ptpid_tofw_w1_pos_3_dis->Fill(pT);
> 		      if(dis4) ptpid_tofw_w1_pos_4_dis->Fill(pT);
> 		      if(dis5) ptpid_tofw_w1_pos_5_dis->Fill(pT);
> 		      if(dis6) ptpid_tofw_w1_pos_6_dis->Fill(pT);
> 		      if(dis7) ptpid_tofw_w1_pos_7_dis->Fill(pT);
> 		      if(dis8) ptpid_tofw_w1_pos_8_dis->Fill(pT);
> 		      if(dis9) ptpid_tofw_w1_pos_9_dis->Fill(pT);
> 		      //1-d
> 		      if(dis0) ptpid_tofw_w1_pos_0_dis_cent[icent]->Fill(pT);
> 		      if(dis1) ptpid_tofw_w1_pos_1_dis_cent[icent]->Fill(pT);
> 		      if(dis2) ptpid_tofw_w1_pos_2_dis_cent[icent]->Fill(pT);
> 		      if(dis3) ptpid_tofw_w1_pos_3_dis_cent[icent]->Fill(pT);
> 		      if(dis4) ptpid_tofw_w1_pos_4_dis_cent[icent]->Fill(pT);
> 		      if(dis5) ptpid_tofw_w1_pos_5_dis_cent[icent]->Fill(pT);
> 		      if(dis6) ptpid_tofw_w1_pos_6_dis_cent[icent]->Fill(pT);
> 		      if(dis7) ptpid_tofw_w1_pos_7_dis_cent[icent]->Fill(pT);
> 		      if(dis8) ptpid_tofw_w1_pos_8_dis_cent[icent]->Fill(pT);
> 		      if(dis9) ptpid_tofw_w1_pos_9_dis_cent[icent]->Fill(pT);
> 		    }
> 		  if(w1neg)
> 		    {
> 		      //1-d
> 		      if(dis0) ptpid_tofw_w1_neg_0_dis->Fill(pT);
> 		      if(dis1) ptpid_tofw_w1_neg_1_dis->Fill(pT);
> 		      if(dis2) ptpid_tofw_w1_neg_2_dis->Fill(pT);
> 		      if(dis3) ptpid_tofw_w1_neg_3_dis->Fill(pT);
> 		      if(dis4) ptpid_tofw_w1_neg_4_dis->Fill(pT);
> 		      if(dis5) ptpid_tofw_w1_neg_5_dis->Fill(pT);
> 		      if(dis6) ptpid_tofw_w1_neg_6_dis->Fill(pT);
> 		      if(dis7) ptpid_tofw_w1_neg_7_dis->Fill(pT);
> 		      if(dis8) ptpid_tofw_w1_neg_8_dis->Fill(pT);
> 		      if(dis9) ptpid_tofw_w1_neg_9_dis->Fill(pT);
> 		      //1-d
> 		      if(dis0) ptpid_tofw_w1_neg_0_dis_cent[icent]->Fill(pT);
> 		      if(dis1) ptpid_tofw_w1_neg_1_dis_cent[icent]->Fill(pT);
> 		      if(dis2) ptpid_tofw_w1_neg_2_dis_cent[icent]->Fill(pT);
> 		      if(dis3) ptpid_tofw_w1_neg_3_dis_cent[icent]->Fill(pT);
> 		      if(dis4) ptpid_tofw_w1_neg_4_dis_cent[icent]->Fill(pT);
> 		      if(dis5) ptpid_tofw_w1_neg_5_dis_cent[icent]->Fill(pT);
> 		      if(dis6) ptpid_tofw_w1_neg_6_dis_cent[icent]->Fill(pT);
> 		      if(dis7) ptpid_tofw_w1_neg_7_dis_cent[icent]->Fill(pT);
> 		      if(dis8) ptpid_tofw_w1_neg_8_dis_cent[icent]->Fill(pT);
> 		      if(dis9) ptpid_tofw_w1_neg_9_dis_cent[icent]->Fill(pT);
> 		    }
> 		  if(w2pos)
> 		    {
> 		      //1-d
> 		      if(dis0) ptpid_tofw_w2_pos_0_dis->Fill(pT);
> 		      if(dis1) ptpid_tofw_w2_pos_1_dis->Fill(pT);
> 		      if(dis2) ptpid_tofw_w2_pos_2_dis->Fill(pT);
> 		      if(dis3) ptpid_tofw_w2_pos_3_dis->Fill(pT);
> 		      if(dis4) ptpid_tofw_w2_pos_4_dis->Fill(pT);
> 		      if(dis5) ptpid_tofw_w2_pos_5_dis->Fill(pT);
> 		      if(dis6) ptpid_tofw_w2_pos_6_dis->Fill(pT);
> 		      if(dis7) ptpid_tofw_w2_pos_7_dis->Fill(pT);
> 		      if(dis8) ptpid_tofw_w2_pos_8_dis->Fill(pT);
> 		      if(dis9) ptpid_tofw_w2_pos_9_dis->Fill(pT);
> 		      //1-d
> 		      if(dis0) ptpid_tofw_w2_pos_0_dis_cent[icent]->Fill(pT);
> 		      if(dis1) ptpid_tofw_w2_pos_1_dis_cent[icent]->Fill(pT);
> 		      if(dis2) ptpid_tofw_w2_pos_2_dis_cent[icent]->Fill(pT);
> 		      if(dis3) ptpid_tofw_w2_pos_3_dis_cent[icent]->Fill(pT);
> 		      if(dis4) ptpid_tofw_w2_pos_4_dis_cent[icent]->Fill(pT);
> 		      if(dis5) ptpid_tofw_w2_pos_5_dis_cent[icent]->Fill(pT);
> 		      if(dis6) ptpid_tofw_w2_pos_6_dis_cent[icent]->Fill(pT);
> 		      if(dis7) ptpid_tofw_w2_pos_7_dis_cent[icent]->Fill(pT);
> 		      if(dis8) ptpid_tofw_w2_pos_8_dis_cent[icent]->Fill(pT);
> 		      if(dis9) ptpid_tofw_w2_pos_9_dis_cent[icent]->Fill(pT);
> 		    }
> 		  if(w2neg)
> 		    {
> 		      //1-d
> 		      if(dis0) ptpid_tofw_w2_neg_0_dis->Fill(pT);
> 		      if(dis1) ptpid_tofw_w2_neg_1_dis->Fill(pT);
> 		      if(dis2) ptpid_tofw_w2_neg_2_dis->Fill(pT);
> 		      if(dis3) ptpid_tofw_w2_neg_3_dis->Fill(pT);
> 		      if(dis4) ptpid_tofw_w2_neg_4_dis->Fill(pT);
> 		      if(dis5) ptpid_tofw_w2_neg_5_dis->Fill(pT);
> 		      if(dis6) ptpid_tofw_w2_neg_6_dis->Fill(pT);
> 		      if(dis7) ptpid_tofw_w2_neg_7_dis->Fill(pT);
> 		      if(dis8) ptpid_tofw_w2_neg_8_dis->Fill(pT);
> 		      if(dis9) ptpid_tofw_w2_neg_9_dis->Fill(pT);
> 		      //1-d
> 		      if(dis0) ptpid_tofw_w2_neg_0_dis_cent[icent]->Fill(pT);
> 		      if(dis1) ptpid_tofw_w2_neg_1_dis_cent[icent]->Fill(pT);
> 		      if(dis2) ptpid_tofw_w2_neg_2_dis_cent[icent]->Fill(pT);
> 		      if(dis3) ptpid_tofw_w2_neg_3_dis_cent[icent]->Fill(pT);
> 		      if(dis4) ptpid_tofw_w2_neg_4_dis_cent[icent]->Fill(pT);
> 		      if(dis5) ptpid_tofw_w2_neg_5_dis_cent[icent]->Fill(pT);
> 		      if(dis6) ptpid_tofw_w2_neg_6_dis_cent[icent]->Fill(pT);
> 		      if(dis7) ptpid_tofw_w2_neg_7_dis_cent[icent]->Fill(pT);
> 		      if(dis8) ptpid_tofw_w2_neg_8_dis_cent[icent]->Fill(pT);
> 		      if(dis9) ptpid_tofw_w2_neg_9_dis_cent[icent]->Fill(pT);
> 		    }
3008a3169,3431
> {
> 
>   float c_light =  29.9792458; //  speed of light in cm/ns
>   float L = 495.0; // distance to tofw
>   float K1 = 75.0; // field integral 
>   float par0 = 0.896; // angular resolution
>   float par1 = 0.992; // multiple scattering term
>   float par2 = 0.074; // timing resolution
> 
>   float m2 = mproton*mproton;
>   float pterm = -9999;
>   float tterm = -9999;
>   float varia = -9999;
>   float sigma = -9999;
> 
>   pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
>   pterm = pterm/(K1*K1);
>   tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
>   varia = 4*(pterm + tterm);
>   sigma = sqrt(varia);
> 
>   return (m2tofw-m2)/sigma;
> 
> }
> 
> 
> float isPionANA_v1(float x, float m2tofw)
> {
> 
>   float c_light =  29.9792458; //  speed of light in cm/ns
>   float L = 495.0; // distance to tofw
>   float K1 = 75.0; // field integral 
>   float par0 = 0.896; // angular resolution
>   float par1 = 0.992; // multiple scattering term
>   float par2 = 0.074; // timing resolution
> 
>   float a0 = 0.0123786;
>   float a1 = 0.00293974;
>   float a2 = -0.000321866;
>   float a3 = -0.0110238;
>   float a4 = 0.0352101;
>   float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);
>   //float m2 = mpion*mpion;
>   float m2 = mean; // why not?
>   float pterm = -9999;
>   float tterm = -9999;
>   float varia = -9999;
>   float sigma = -9999;
> 
>   pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
>   pterm = pterm/(K1*K1);
>   tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
>   varia = 4*(pterm + tterm);
>   sigma = sqrt(varia);
> 
>   return (m2tofw-m2)/sigma;
> 
> }
> 
> 
> 
> float isKaonANA_v1(float x, float m2tofw)
> {
>   
>   float c_light =  29.9792458; //  speed of light in cm/ns
>   float L = 495.0; // distance to tofw
>   float K1 = 75.0; // field integral 
>   float par0 = 0.896; // angular resolution
>   float par1 = 0.992; // multiple scattering term
>   float par2 = 0.074; // timing resolution
> 
>   float m2 = mkaon*mkaon;
>   float pterm = -9999;
>   float tterm = -9999;
>   float varia = -9999;
>   float sigma = -9999;
> 
>   pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
>   pterm = pterm/(K1*K1);
>   tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
>   varia = 4*(pterm + tterm);
>   sigma = sqrt(varia);
> 
>   return (m2tofw-m2)/sigma;
> 
> }
> 
> 
> 
> float isProtonANA_v1(float x, float m2tofw)
> {
> 
>   float c_light =  29.9792458; //  speed of light in cm/ns
>   float L = 495.0; // distance to tofw
>   float K1 = 75.0; // field integral 
>   float par0 = 0.896; // angular resolution
>   float par1 = 0.992; // multiple scattering term
>   float par2 = 0.074; // timing resolution
> 
>   float  a0    =       8.58341e-01;
>   float  a1    =      -2.89831e-02;
>   float  a2    =       1.68868e-02;
>   float  a3    =      -9.42405e-03;
>   float  a4    =       6.23467e-02;
>   float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);
>   //float m2 = mproton*mproton;
>   float m2 = mean; // why not?
>   float pterm = -9999;
>   float tterm = -9999;
>   float varia = -9999;
>   float sigma = -9999;
> 
>   pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
>   pterm = pterm/(K1*K1);
>   tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
>   varia = 4*(pterm + tterm);
>   sigma = sqrt(varia);
> 
>   return (m2tofw-m2)/sigma;
> 
> }
> 
> 
> float isPionANA_v2(float x, float m2tofw)
> {
> 
>   float c_light =  29.9792458; //  speed of light in cm/ns
>   float L = 495.0; // distance to tofw
>   float K1 = 75.0; // field integral 
>   float par0 = 0.896; // angular resolution
>   float par1 = 0.992; // multiple scattering term
>   float par2 = 0.084; // timing resolution
> 
>   float m2 = mpion*mpion;
>   float pterm = -9999;
>   float tterm = -9999;
>   float varia = -9999;
>   float sigma = -9999;
> 
>   pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
>   pterm = pterm/(K1*K1);
>   tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
>   varia = 4*(pterm + tterm);
>   sigma = sqrt(varia);
> 
>   return (m2tofw-m2)/sigma;
> 
> }
> 
> 
> 
> float isKaonANA_v2(float x, float m2tofw)
> {
>   
>   float c_light =  29.9792458; //  speed of light in cm/ns
>   float L = 495.0; // distance to tofw
>   float K1 = 75.0; // field integral 
>   float par0 = 0.896; // angular resolution
>   float par1 = 0.992; // multiple scattering term
>   float par2 = 0.084; // timing resolution
> 
>   float m2 = mkaon*mkaon;
>   float pterm = -9999;
>   float tterm = -9999;
>   float varia = -9999;
>   float sigma = -9999;
> 
>   pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
>   pterm = pterm/(K1*K1);
>   tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
>   varia = 4*(pterm + tterm);
>   sigma = sqrt(varia);
> 
>   return (m2tofw-m2)/sigma;
> 
> }
> 
> 
> 
> float isProtonANA_v2(float x, float m2tofw)
> {
> 
>   float c_light =  29.9792458; //  speed of light in cm/ns
>   float L = 495.0; // distance to tofw
>   float K1 = 75.0; // field integral 
>   float par0 = 0.896; // angular resolution
>   float par1 = 0.992; // multiple scattering term
>   float par2 = 0.084; // timing resolution
> 
>   float m2 = mproton*mproton;
>   float pterm = -9999;
>   float tterm = -9999;
>   float varia = -9999;
>   float sigma = -9999;
> 
>   pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
>   pterm = pterm/(K1*K1);
>   tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
>   varia = 4*(pterm + tterm);
>   sigma = sqrt(varia);
> 
>   return (m2tofw-m2)/sigma;
> 
> }
> 
> 
> float isPionANA_v3(float x, float m2tofw)
> {
> 
>   float c_light =  29.9792458; //  speed of light in cm/ns
>   float L = 495.0; // distance to tofw
>   float K1 = 75.0; // field integral 
>   float par0 = 0.896; // angular resolution
>   float par1 = 0.992; // multiple scattering term
>   float par2 = 0.074; // timing resolution
> 
>   float m2 = mpion*mpion;
>   float pterm = -9999;
>   float tterm = -9999;
>   float varia = -9999;
>   float sigma = -9999;
> 
>   pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
>   pterm = pterm/(K1*K1);
>   tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
>   varia = 4*(pterm + tterm);
>   sigma = sqrt(varia);
> 
>   return (m2tofw-m2)/sigma;
> 
> }
> 
> 
> 
> float isKaonANA_v3(float x, float m2tofw)
> {
>   
>   float c_light =  29.9792458; //  speed of light in cm/ns
>   float L = 495.0; // distance to tofw
>   float K1 = 75.0; // field integral 
>   float par0 = 0.896; // angular resolution
>   float par1 = 0.992; // multiple scattering term
>   float par2 = 0.074; // timing resolution
> 
>   float m2 = mkaon*mkaon;
>   float pterm = -9999;
>   float tterm = -9999;
>   float varia = -9999;
>   float sigma = -9999;
> 
>   pterm = pow((par0*m2*x),2) + pow((par1*m2),2)*((1+m2)/(x*x));
>   pterm = pterm/(K1*K1);
>   tterm = pow((par2*c_light/L),2)*(m2+x*x)*x*x;
>   varia = 4*(pterm + tterm);
>   sigma = sqrt(varia);
> 
>   return (m2tofw-m2)/sigma;
> 
> }
> 
> 
> 
> float isProtonANA_v3(float x, float m2tofw)
