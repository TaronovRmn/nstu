#include "C:/Users/taron/source/repos/nstu/LIB/LIB/stdafx.h" //��������� ���������� LIB.lib

#include <time.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <clocale> 
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>







using namespace std;

/*
//������ ��������� � ���������� LIB.lib

///////////////////////////////////
int formS()//����� ������ ��� ������� ��� Nf ��������� ����������, ���������� � ����� inT.txt
//
//������� �������: inT.txt
//                 Ititle.txt
//                 code.txt - ������ ���� Sp!=0 � T!=0 � Ititle.txt
//�������� ������: inS.txt
//
{
char s[500000];
char c,spaceZ;
int sNN;

int L,NA,T,Sp,Zs,Nspace,Nf,Nu,Tu;

int i,x,lns;
int i4;

FILE *f,*f1,*f2,*f3;

fopen_s(&f, "inT.txt","r");
fopen_s(&f1,"inS.txt","w");
fopen_s(&f2,"Ititle.txt","r");

fscanf_s(f,"%d\n",&Nf,1);//���������� �������� �����
fprintf(f1,"%d\n",Nf);
fscanf_s(f2,"%d %d %d %d %d %c\n",&i,&L,&NA,&T,&Sp,&Zs,1);//��� ����� � ������� �������


spaceZ=' '; //���� �������

if(Sp!=0 && T!=0)//��� ���� ������� � T!=0 ���� ������� ������� �� code.txt ������ �� _1_ ������ ��� ����� Nu>0
//���� Nu==0 ���� ������� �������: spaceZ=' ';
{
fopen_s(&f3,"code.txt","r");
fscanf_s(f3,"%d %d\n",&Nu,&Tu,1);//���������� ����� � ��� � code.txt
if(Nu>0)
{
//��������� ������
while((c=fgetc(f3))=='\n');   //������ ������ ����� ���������� � ������ �������
fscanf_s(f3,"%d\n",&sNN,1);   //����� ������
fscanf_s(f3,"%c\n",&c,1);     //������ �������
fscanf_s(f3,"%c\n",&spaceZ,1);//���� �������
}
fclose(f3);
}

//
//������� ����
//

for(i4=0;i4<Nf;i4++)
{
//������ ���������� ���������� ���������

Nspace=0;

//��������� ���������

while((c=fgetc(f))=='\n'); //������ ������ ����� ���������� � ������ �������
fscanf_s(f,"%d\n",&sNN,1); //����� ���������
fscanf_s(f,"%c\n",&c,1);   //������ �������

//����� ��������� � ������ �������
lns=0;i=0;
while((c=fgetc(f))!='\n')if(lns<500000)
if(Sp==0){s[i]=c;lns=lns+1;i++;} else
if(c!=spaceZ){s[i]=c;lns=lns+1;i++;}else Nspace++;


fprintf(f1,"_%d_\n",sNN);
for(x=0;x<lns;x++)fprintf(f1,"%c",s[x]);
fprintf(f1,"\n");

}

fclose(f1);
fclose(f);

return 0;

}
///////////////////////////////////
///////////////////////////////////
int formU()//����� �������� ��� Nf ��������� ����������, ���������� � ����� inT.txt
//��������� ����� (����� Nf ����):
//_�_  - ���������, � ������������� ������ ��������� ���������
//� � ���� �������   - � - ����� ������ � ������, �� ������ ������; � - ����� �������� � ������; ������ ������������ "������ �������"
//� � � ... - � ������ ������, ������������� �� �������� ����� ��������� � ������
//�1 �2 ... - � ����� �����, �������������� ����� ��������� ��������������� ������ � ������: �1>=�2>=...
//
//������� �������: inT.txt
//                 Ititle.txt
//                 code.txt - ������ ���� Sp!=0 � T!=0 � Ititle.txt
//�������� ������: inU
//
{
char s[500000];
char mas[256];//������ ������������� ������
int fr[256];  //�����  ������������� ������
char c,spaceZ;
int sNN;

int L,NA,T,Sp,Zs,Nspace,Nf,Nu,Tu;

int i,j,k,t,t1,p,z,x,lns;
int i4;

FILE *f,*f1,*f2,*f3;

fopen_s(&f, "inT.txt","r");
fopen_s(&f1,"inU.txt","w");
fopen_s(&f2,"Ititle.txt","r");

fscanf_s(f,"%d\n",&Nf,1);//���������� �������� �����
fprintf(f1,"%d\n",Nf);
fscanf_s(f2,"%d %d %d %d %d %c\n",&i,&L,&NA,&T,&Sp,&Zs,1);//��� ����� � ������� �������


spaceZ=' '; //���� �������

if(Sp!=0 && T!=0)//��� ���� ������� � T!=0 ���� ������� ������� �� code.txt ������ �� _1_ ������ ��� ����� Nu>0
//���� Nu==0 ���� ������� �������: spaceZ=' ';
{
fopen_s(&f3,"code.txt","r");
fscanf_s(f3,"%d %d\n",&Nu,&Tu,1);//���������� ����� � ��� � code.txt
if(Nu>0)
{
//��������� ������
while((c=fgetc(f3))=='\n');   //������ ������ ����� ���������� � ������ �������
fscanf_s(f3,"%d\n",&sNN,1);   //����� ������
fscanf_s(f3,"%c\n",&c,1);     //������ �������
fscanf_s(f3,"%c\n",&spaceZ,1);//���� �������
}
fclose(f3);
}

//
//������� ����
//

for(i4=0;i4<Nf;i4++)
{
//������ ���������� ���������� ���������

Nspace=0;

//��������� ���������

while((c=fgetc(f))=='\n'); //������ ������ ����� ���������� � ������ �������
fscanf_s(f,"%d\n",&sNN,1); //����� ���������
fscanf_s(f,"%c\n",&c,1);   //������ �������

//����� ��������� � ������ �������
lns=0;i=0;
while((c=fgetc(f))!='\n')if(lns<500000)
if(Sp==0){s[i]=c;lns=lns+1;i++;} else
if(c!=spaceZ){s[i]=c;lns=lns+1;i++;}else Nspace++;

i=0;t=0;
for(x=0;x<256;x++){mas[x]=0;fr[x]=0;}
for(i=0;i<lns;i++)
{ for(x=0;x<256;x++){if(mas[x]!=s[i])z=1; else {z=0;break;}}
if (z==1){k=0;for(j=0;j<lns;j++)if(s[i]==s[j])k++;
t1=t+1;
mas[t]=s[i];
fr[t]=k;
t++;
}
}

//������������ �������

do
{p=0;
for(x=0;x<t1;x++)if(fr[x]<fr[x+1]){p=fr[x+1];fr[x+1]=fr[x];fr[x]=p;c=mas[x+1];mas[x+1]=mas[x];mas[x]=c;}
}while (p!=0);

fprintf(f1,"_%d_\n",sNN);

fprintf(f1,"%d\t%d\t%c\n",t1,Nspace,spaceZ);
for(x=0;x<t1;x++)fprintf(f1,"%c\t",mas[x]);
fprintf(f1,"\n");
for(x=0;x<t1;x++)fprintf(f1,"%d\t",fr[x]);
fprintf(f1,"\n");

}

fclose(f1);
fclose(f);

return 0;

}
///////////////////////////////////
///////////////////////////////////
int formB()//����� ������� ��� Nf ��������� ����������, ���������� � ����� inT.txt
//��������� ����� (����� Nf ����):
//_�_  - ���������, � ������������� ������ ��������� ���������
//� � ���� �������   - � - ����� ������ � ������, �� ������ ������; � - ����� �������� � ������; ������ ������������ "������ �������"
//� � � ... - � ������ ������, ������������� �� �������� ����� ��������� � ������
//�1 �2 ... - � ����� � ����� �����, �������������� ����� ��������� ��������������� ������ � ������: �1>=�2>=...
//......... - � ����� � ������������ �� �������� ���������������� ��������
//
//������� �������: inT.txt
//                 Ititle.txt
//                 code.txt - ������ ���� Sp!=0 � T!=0 � Ititle.txt
//�������� ������: inB.txt
//
{
char s[500000];
char mas[256];//������ ������������� ������
int fr[256];  //�����  ������������� ������
char c,spaceZ;
int sNN;
int masP[5000],frP[2000];
int frRT[256],masRT[256],frLT[256],masLT[256],fs1[256],fs2[256],Inorm[256];

int L,NA,T,Sp,Zs,Nspace,Nf,Nu,Tu;

int e,g,i,j,k,t,t1,p,z,x,lns;
int i4;

FILE *f,*f1,*f2,*f3;

fopen_s(&f, "inT.txt","r");
fopen_s(&f1,"inB.txt","w");
fopen_s(&f2,"Ititle.txt","r");

fscanf_s(f,"%d\n",&Nf,1);//���������� �������� �����
fprintf(f1,"%d\n",Nf);
fscanf_s(f2,"%d %d %d %d %d %c\n",&i,&L,&NA,&T,&Sp,&Zs,1);//��� ����� � ������� �������


spaceZ=' '; //���� �������

if(Sp!=0 && T!=0)//��� ���� ������� � T!=0 ���� ������� ������� �� code.txt ������ �� _1_ ������ ��� ����� Nu>0
//���� Nu==0 ���� ������� �������: spaceZ=' ';
{
fopen_s(&f3,"code.txt","r");
fscanf_s(f3,"%d %d\n",&Nu,&Tu,1);//���������� ����� � ��� � code.txt
if(Nu>0)
{
//��������� ������
while((c=fgetc(f3))=='\n');   //������ ������ ����� ���������� � ������ �������
fscanf_s(f3,"%d\n",&sNN,1);   //����� ������
fscanf_s(f3,"%c\n",&c,1);     //������ �������
fscanf_s(f3,"%c\n",&spaceZ,1);//���� �������
}
fclose(f3);
}

//
//������� ����
//

for(i4=0;i4<Nf;i4++)
{
//������ ���������� ���������� ���������

Nspace=0;

//��������� ���������

while((c=fgetc(f))=='\n'); //������ ������ ����� ���������� � ������ �������
fscanf_s(f,"%d\n",&sNN,1); //����� ���������
fscanf_s(f,"%c\n",&c,1);   //������ �������

//����� ��������� � ������ �������
lns=0;i=0;
while((c=fgetc(f))!='\n')if(lns<500000)
if(Sp==0){s[i]=c;lns=lns+1;i++;} else
if(c!=spaceZ){s[i]=c;lns=lns+1;i++;}else Nspace++;

i=0;t=0;
for(x=0;x<256;x++){mas[x]=0;fr[x]=0;}
for(i=0;i<lns;i++)
{ for(x=0;x<256;x++){if(mas[x]!=s[i])z=1; else {z=0;break;}}
if (z==1){k=0;for(j=0;j<lns;j++)if(s[i]==s[j])k++;
t1=t+1;
mas[t]=s[i];
fr[t]=k;
t++;
}
}

//������������ �������

do
{p=0;
for(x=0;x<t1;x++)if(fr[x]<fr[x+1]){p=fr[x+1];fr[x+1]=fr[x];fr[x]=p;c=mas[x+1];mas[x+1]=mas[x];mas[x]=c;}
}while (p!=0);


//������� ���

t=0;g=0;
for(x=0;x<5000;x=x+1)masP[x]=0;
for(x=0;x<2000;x=x+1)frP[x]=0;
for(i=0;i<lns-1;i++)//
{ for(x=0;x<=2000;x=x+2){if(masP[x]!=s[i])z=1; else if(masP[x+1]!=s[i+1])z=1; else{z=0;break;}}
if(z==1)
{
k=0;for(j=0;j<lns-1;j++){if((s[i]==s[j])&&(s[i+1]==s[j+1]))k++;}
if (k>0)
{
masP[t]=s[i];
masP[t+1]=s[i+1];
frP[g]=k;
g=g+1;
t=t+2;
}
}
}

//
//�������� �������
//
fprintf(f1,"_%d_\n",sNN);
fprintf(f1,"%d\t%d\t%c\n",t1,Nspace,spaceZ);
for(x=0;x<t1;x++)fprintf(f1,"%c\t",mas[x]);

for(x=0;x<256;x++){fs1[x]=0;fs2[x]=0;}

for(k=0;k<t1;k++)
{
i=0;
for(x=0;x<=255;x++){frRT[x]=0;masRT[x]=spaceZ;}
for(x=0,e=0;x<t;x=x+2,e++)if(masP[x]==mas[k]){masRT[i]=masP[x+1];frRT[i]=frP[e];fs1[k]=fs1[k]+frRT[i];i++;}
for(x=0;x<=255;x++){frLT[x]=0;masLT[x]=spaceZ;}
for(j=0;j<t1;j++)
for(x=0;x<=i;x++)if(masRT[x]==mas[j]){masLT[j]=masRT[x];frLT[j]=frRT[x];fs2[j]=fs2[j]+frLT[j];}

fprintf(f1,"\n");
for(x=0;x<t1;x++)Inorm[x]=frLT[x];
for(x=0;x<t1;x++)fprintf(f1,"%d\t",Inorm[x]);

}
fprintf(f1,"\n");
}

fclose(f1);
fclose(f);

return 0;
}
///////////////////////////////////


///////////////////////////////////
int UPO()//����� ���������� ��������������    ��������� ������� �� ����� inU � ������ ������� ouR
//                                            ��������� �������� ����� ���� ������ �������� ������� (0),
//                                            ������� ���������� ���������� ���
//                                            �������� ��� ���� ������� ������ � ��������� ��������, � �.�. L=NA=0
//                                            ��� NA=0 ������������ ����� ������ ����� Na � ������ ���� Na=0
//                                            ������� ����� "������" (------   -SAB), ���� ���� ������� ���������
//                                            ���� �������. ���� NA!=0 � Na>NA, �� Na=NA - ������ ����� �� �������
//                                            ���������
//������� �������: inU.txt
//                 Ititle.txt
//                 ouR.txt
//�������� ������: ouR.txt
//
{
char mas[256];
char c;
int sNN,sNr;

int L,NA,T,Sp,Zs,Nf,Na,NAt,Nfu,Nu,M;

int i;
int i4;

FILE *f,*f1,*f2,*f3;

fopen_s(&f, "inU.txt","r");
fopen_s(&f1,"ouR.txt","r");
fopen_s(&f2,"Ititle.txt","r");
fopen_s(&f3,"tmp.txt","w");

fscanf_s(f,"%d\n",&Nf,1);//���������� �������� �����
fscanf_s(f1,"%d %d\n",&Nfu,&Nu,1);


fprintf(f3,"%d %d\n",Nf,Nu+1);
fscanf_s(f2,"%d %d %d %d %d %c\n",&i,&L,&NAt,&T,&Sp,&Zs,1);//��� ����� � ������� �������
fclose(f2);

//
//������� ����
//
M=0; NA=NAt;
for(i4=0;i4<Nf;i4++)
{
//������ ���������� ���������� ���������

//��������� ���������

while((c=fgetc(f))=='\n'); //������ ������ ����� ���������� � ������ �������
fscanf_s(f,"%d\n",&sNN,1); //����� ���������
fscanf_s(f,"%c\n",&c,1);   //������ �������

//����� ���������

for(i=0;i<NA;i++)mas[i]=Zs;

fscanf_s(f,"%d",&Na,1);//����� ������

while((c=fgetc(f))!='\n');
i=0;
while(i<Na)
while((c=fgetc(f))!='\t'){mas[i]=c;i++;}
while((c=fgetc(f))!='\n');
for(i=0;i<Na;i++) fscanf_s(f,"%d ",&L,1);


//���������� � ������ �������
if(NA!=0 && Na>NA)Na=NA;
if(NA==0)NA=Na;

fprintf(f3,"_%d_\n",sNN);
//1. ����������� ���������� �������

//��������� ��������� ouR
while((c=fgetc(f1))=='\n'); //������ ������ ����� ���������� � ������ �������
fscanf_s(f1,"%d\n",&sNr,1); //����� ���������
fscanf_s(f1,"%c\n",&c,1);   //������ �������
//������������ �������
i=0;
while(i<Nu){while((c=fgetc(f1))!='\n')fprintf(f3,"%c",c);fprintf(f3,"\n");i++;}

//2.  ������ ������ �������
for(i=0;i<NA;i++)fprintf(f3,"%c",mas[i]);
c=' ';if(Na==0)c=Zs;
fprintf(f3,"\t%d\t%d\t%c[UPO]\n",Nu+1,M,c);

}

fclose(f3);
fclose(f1);
fclose(f);

fopen_s(&f1,"ouR.txt","w");
fopen_s(&f3,"tmp.txt","r");
while((c=fgetc(f3))!=EOF)fprintf(f1,"%c",c);
fclose(f3);
fclose(f1);

fopen_s(&f3,"tmp.txt","w");
c=' ';fprintf(f1,"%c",c);
fclose(f3);

return 0;

}
///////////////////////////////////

///////////////////////////////////
int MAP(int M) //����� ������������� �� ������� �� ������ ��������� ������� ������� enB.txt.
//                               �������� ���������� ������ ���� ������������� � ����� Nf ������ �������
//                               � ����� inB.txt, ����������� ������������� �� ������� ��������� ������ � ������.
//                               ������������ ���������� ������ 1 < NA <= 50, ����������� ��� Nf ���, Nf > 0.
//                               ����� ����� L > 0. ������������ ���������� ������� �������������� �� ������� M
//                               �� ����� ouR, � ������� ��� ���� Nu �������.
//                               ���� M <= 0, �� ����������� �������� ������������. ���� M > Nu, �� �=Nu.
//                               ���� ��������� ������ ������� M �� ouR � ������ ������� ������� ������� �����������,
//                               �� ����������� ������ ������� �� ������ ����������� ����� Zs.
//������� �������: inB.txt
//                 Ititle.txt
//                 ouR.txt
//                 enB.txt
//�������� ������: ouR.txt
//������� ������:  tmp.txt
//
//return 0:   ��� � �������
//return 1:   NA<2 ��� NE != NA  ��������� ������, NE - ����� ������ �������
//
{
int Nf,Nfu,Nu,L,NAt,T,Sp;
char c,Zs;
int sNN,Na,NaC,NaP,Mn;

char eJ[50],mJ[50],mas[50],xJ[50];//������ ������������� �������� <= 140

int WTB[50][50],DG[50],tTB[50][50],tG[50];
double FTB[50][50],fTB[50][50],fTB2[50][50];
double SM1[50][50],SM2[50][50],R[50][50];
double SSF[50],SSf[50],SCF[50],SCf[50];
int IR[50][50],SA[50];

int De,Dt,st;

int i=0,k=1, j=0,t=0,p,x=0,X=0,X1=0,e=0,lns=0,lnt=0,m=0;
int g1=0,g3=0,i4;
double w,w1,w5;
double eps;
double DD1,DD2;

FILE *f,*f1,*f2,*f3,*f4;

fopen_s(&f,"inB.txt","r");
fopen_s(&f1,"ouR.txt","r");
fopen_s(&f2,"Ititle.txt","r");
fopen_s(&f3,"enB.txt","r");
fopen_s(&f4,"tmp.txt","w");

fscanf_s(f,"%d\n",&Nf,1);          //���������� ����������. ���������� �������� ����� i4
fscanf_s(f1,"%d %d\n",&Nfu,&Nu,1); //���������� �������


fprintf(f4,"%d %d\n",Nf,Nu+1);
fscanf_s(f2,"%d %d %d %d %d %c\n",&i,&L,&NAt,&T,&Sp,&Zs,1);//��� �����, ������� �������, ���������� ���� Zs
fclose(f2);


eps=0.001;          //����������� ���������
//��������� ������� ��������
for(i=0;i<50;i++)DG[i]=tG[i]=SA[i]=0;
for(i=0;i<50;i++)for(j=0;j<50;j++)
{WTB[i][j]=tTB[i][j]=IR[i][j]=0; fTB[i][j]=fTB2[i][j]=SM1[i][j]=SM2[i][j]=R[i][j]=0.0;}

//
//������: ���� (����������� ������������� �� ������� ������)
//
fscanf_s(f3,"%d",&Na,1);    //����� ������ �������

if(NAt<2)  return 1;        //ERROR 1 ��������� ������
if(Na!=NAt)return 1;        //ERROR 1 ��������� ������

while((c=fgetc(f3))!='\n'); //����� �������
i=0; while((c=fgetc(f3))!='\n'){if(c!='\t'&& i<Na){eJ[i]=c;i++;}}

//�������� �������
for(j=0;j<Na;j++)for(i=0;i<Na;i++)
{fscanf_s(f3,"%d",&WTB[j][i],1);if(i==j){DG[j]=WTB[j][i];WTB[j][i]=0;}}//TB, ����=0

//
//������: ����������
//
w=0.0; for(i=0;i<NAt;i++)for(j=0;j<31;j++)w=w+float(WTB[i][j]);
De=0;  for(i=0;i<NAt;i++)De=De+DG[i];     w=w+float(De);

for(i=0;i<NAt;i++)for(j=0;j<NAt;j++) FTB[i][j]=float(WTB[i][j])/w;  //����������

//������������� ������ ���������� �������
Mn=M;
if(Mn<0) Mn=0;
if(Mn>Nu)Mn=Nu;


//
//������� ����
//


for(i4=0;i4<Nf;i4++)
{
//������ ��������� ������� ������� (����������� ������������� �� ������� ��������� ������)

NaP=0; //���� ������� �������

//��������� ���������

while((c=fgetc(f))=='\n'); //������ ������ ����� ���������� � ������ �������
fscanf_s(f,"%d\n",&sNN,1); //����� ���������
fscanf_s(f,"%c\n",&c,1);   //������ �������

//��������� ��������� ������� �������

for(i=0;i<NAt;i++){mJ[i]=Zs;tG[i]=0;}
for(j=0;j<NAt;j++)for(i=0;i<NAt;i++){tTB[j][i]=0;fTB[j][i]=0.0;} //���������� mJ � ���� NAt x NAt

fscanf_s(f,"%d",&Na,1);             //����� ������ ��������� ������� �������

NaC=0; if(Na>NAt){NaC=Na; Na=NAt;}  //��������� ����� ������, ���� �� ������ NAt.

while((c=fgetc(f))!='\n');          //����� ��������� ������� �������
i=0; while((c=fgetc(f))!='\n'){if(c!='\t' && i<Na){mJ[i]=c;i++;}}

//�������� ��������� ������� ������� tTB � ������ ��������� ��������� NaC
for(j=0;j<Na;j++){for(i=0;i<Na;i++)
{fscanf_s(f,"%d",&tTB[j][i],1);if(i==j){tG[j]=tTB[j][i];tTB[j][i]=0;}} if(NaC>0)while((c=fgetc(f))!='\n');}//TB, ����=0
if(NaC>0)for(j=Na;j<NaC;j++)while((c=fgetc(f))!='\n');else while((c=fgetc(f))!='\n');


//
//���������������� ������� ������� tTB � ������������ � �������� ��������� ��������
//
//������ ���������� �������  M �� (&f1,"ouR.txt","r") � ����������� ������� �  (&f4,"tmp.txt","w")
if(Nu!=0)
{
//(&f1,"ouR.txt","r")
//��������� ��������� ouR
while((c=fgetc(f1))=='\n'); //������ ������ ����� ���������� � ������ �������
fscanf_s(f1,"%d\n",&sNN,1); //����� ���������
fscanf_s(f1,"%c\n",&c,1);   //������ �������
fprintf(f4,"_%d_\n",sNN);
if(Mn!=0)
{
//������� ���������� �������
for(i=0;i<Mn-1;i++){while((c=fgetc(f1))!='\n')fprintf(f4,"%c",c);fprintf(f4,"\n");}
//��������� ������� NAt ������.
i=0;  while(i<NAt){c=fgetc(f1);xJ[i]=c;i++;fprintf(f4,"%c",c);}
while((c=fgetc(f1))!='\n')fprintf(f4,"%c",c);fprintf(f4,"\n");
}
//������� ���������� �������
for(i=Mn;i<Nu;i++){while((c=fgetc(f1))!='\n')fprintf(f4,"%c",c);fprintf(f4,"\n");}
}
if(Mn!=0)
{
//�������� ������� �� ���������� �������� ������
j=0;for(i=0;i<NAt;i++)for(x=0;x<NAt;x++)if(xJ[i]!=Zs && xJ[i]==mJ[x])j++;
if(j!=Na){for(i=0;i<NAt;i++)mJ[i]=Zs; NaP=1; goto NEN;} //������ �������
//������������������ ��������� ������� � ������������ � �������� ��������� ��������
for(i=0;i<NAt;i++)for(x=0;x<NAt;x++){if(xJ[i]!=Zs && xJ[i]==mJ[x])for(j=0;j<NAt;j++)fTB[j][i]=float(tTB[j][x]);}
for(i=0;i<NAt;i++)for(x=0;x<NAt;x++){if(xJ[i]!=Zs && xJ[i]==mJ[x])for(j=0;j<NAt;j++)tTB[i][j]=int(fTB[x][j]);}
for(i=0;i<NAt;i++)mJ[i]=xJ[i];
}

//
// ����� �������������
//***************************************************
// ��������� ����������
//
Dt=0;
for(i=0;i<NAt;i++)Dt=Dt+tG[i];

st=0;

for(i=0;i<NAt;i++)mas[i]=mJ[i];

w1=0.0;
for(i=0;i<NAt;i++)for(j=0;j<NAt;j++)w1=w1+float(tTB[i][j]);  w1=w1+float(Dt);

for(i=0;i<NAt;i++)for(j=0;j<NAt;j++)fTB[i][j]=float(tTB[i][j])/w1;

w5=0;k=NAt;
for(i=0;i<k;i++)
for(j=0;j<k;j++)w5=w5+fabs(FTB[i][j]-fTB[i][j]);

w=w5;

i=0;p=0;j=1;

DD1=0.0;k=NAt;
for(i=0;i<k;i++)
for(j=0;j<k;j++)DD1=DD1+fabs(FTB[i][j]-fTB[i][j]);


CHOBA:

for(j=0;j<NAt;j++)SSF[j]=SCF[j]=SSf[j]=SCf[j]=0;

for(j=0;j<NAt;j++)for(i=0;i<NAt;i++)
{
SM1[j][i]=SM2[j][i]=0;
SSF[j]=SSF[j]+FTB[j][i];SCF[j]=SCF[j]+FTB[i][j];
SSf[j]=SSf[j]+fTB[j][i];SCf[j]=SCf[j]+fTB[i][j];
}

for(p=0;p<NAt;p++)
for(j=0;j<NAt;j++)
{
for(i=0;i<NAt;i++)
{
if(FTB[j][i]+fTB[p][i]!=0)SM1[p][j]=SM1[p][j]+(FTB[j][i]-fTB[p][i])*(FTB[j][i]-fTB[p][i])/(FTB[j][i]+fTB[p][i]);
if(FTB[i][j]+fTB[i][p]!=0)SM2[p][j]=SM2[p][j]+(FTB[i][j]-fTB[i][p])*(FTB[i][j]-fTB[i][p])/(FTB[i][j]+fTB[i][p]);
}
R[p][j]=(1-SM1[p][j]/(SSF[j]+SSf[p]))+(1-SM2[p][j]/(SCF[j]+SCf[p]));
}

//����������
for(j=0;j<NAt;j++)
{p=1;for(i=0;i<NAt;i++)IR[j][i]=i;
while(p==1)
{
p=0;for(i=1;i<NAt;i++)
if(R[j][i]>R[j][i-1]+eps)
{w1=R[j][i-1];R[j][i-1]=R[j][i];R[j][i]=w1;k=IR[j][i-1];IR[j][i-1]=IR[j][i];IR[j][i]=k;p=1;}
}
}
//��������
for(i=0;i<NAt;i++)SA[i]=0;

p=1;
while(p>0)
{p=0;
for(j=0;j<NAt;j++)
{
m=j;k=IR[m][SA[m]];
for(i=0;i<NAt;i++)
if(k==IR[i][SA[i]] && m!=i)
{p=1;if(R[m][SA[m]]<R[i][SA[i]]-eps){SA[m]=SA[m]+1;m=i;}else SA[i]=SA[i]+1;}
}
}

//������������
m=0;
for(j=0;j<NAt;j++){k=IR[j][SA[j]];mJ[k]=mas[j];for(i=0;i<NAt;i++)fTB2[k][i]=fTB[j][i];if(k!=j)m++;}
for(j=0;j<NAt;j++){k=IR[j][SA[j]];for(i=0;i<NAt;i++)fTB[i][k]=fTB2[i][j];}

DD2=0.0;k=NAt;
for(i=0;i<k;i++)
for(j=0;j<k;j++)DD2=DD2+fabs(FTB[i][j]-fTB[i][j]);

if(DD1-DD2>-0.2 && st<20 && m!=0){DD1=DD2;for(j=0;j<NAt;j++)mas[j]=mJ[j];st++; goto CHOBA;}

//��� �����
for(j=0;j<NAt;j++)mJ[j]=mas[j];



NEN:
//����� ���������� �������
if(Nu==0)fprintf(f4,"_%d_\n",sNN);
//2.  ������ ������ �������
for(i=0;i<NAt;i++)fprintf(f4,"%c",mJ[i]);
c=' ';if(NaP==1)c=Zs;else if(Mn>0) c='+';
fprintf(f4,"\t%d\t%d\t%c[MAP]\n",Nu+1,Mn,c);

}

//
//�����
//
fclose(f4);
fclose(f1);
fclose(f);

fopen_s(&f1,"ouR.txt","w");
fopen_s(&f4,"tmp.txt","r");
while((c=fgetc(f4))!=EOF)fprintf(f1,"%c",c);
fclose(f4);
fclose(f1);

fopen_s(&f4,"tmp.txt","w");
c=' ';fprintf(f4,"%c",c);
fclose(f4);

return 0;

}
///////////////////////////////////
///////////////////////////////////
int JAC(int M) //����� ��������  ���������� �������������� �� ������ ��������� ������� ������� enB.txt.
//                               �������� ���������� ������ ���� ������������� � ����� Nf ������ �������
//                               � ����� inB.txt, ����������� ������������� �� ������� ��������� ������ � ������.
//                               ������������ ���������� ������ 1 < NA <=140, ����������� ��� Nf ���, Nf > 0.
//                               ����� ����� L > 0. ������������ ���������� ������� �������������� �� ������� M
//                               �� ����� ouR, � ������� ��� ���� Nu �������.
//                               ���� M <= 0, �� ����������� �������� ������������. ���� M > Nu, �� �=Nu.
//                               ���� ��������� ������ ������� M �� ouR � ������ ������� ������� ������� �����������,
//                               �� ����������� ������ ������� �� ������ ����������� ����� Zs.
//������� �������: inB.txt
//                 Ititle.txt
//                 ouR.txt
//                 enB.txt
//�������� ������: ouR.txt
//������� ������:  tmp.txt
//
//return 0:   ��� � �������
//return 1:   NA<2 ��� NE != NA  ��������� ������, NE - ����� ������ �������
//
{
int Nf,Nfu,Nu,L,NAt,T,Sp;
char c,Zs,ig;
int sNN,Na,NaC,NaP,Mn;

char eJ[140],mJ[140],xJ[140];//������ ������������� �������� <= 140

int WTB[140][140],DG[140],tTB[140][140],tG[140];
double FTB[140][140],fTB[140][140];

int De,Dt;

int i=0,k=1, j=0,t=0,p,x=0,X=0,X1=0,e=0,lns=0,lnt=0,m=0;
int g1=0,g3=0,i4;
double w,w1,w2,w3,w4,w6,w7,w8,w9,w10;
double eps;

FILE *f,*f1,*f2,*f3,*f4;

fopen_s(&f,"inB.txt","r");
fopen_s(&f1,"ouR.txt","r");
fopen_s(&f2,"Ititle.txt","r");
fopen_s(&f3,"enB.txt","r");
fopen_s(&f4,"tmp.txt","w");

fscanf_s(f,"%d\n",&Nf,1);          //���������� ����������. ���������� �������� ����� i4
fscanf_s(f1,"%d %d\n",&Nfu,&Nu,1); //���������� �������


fprintf(f4,"%d %d\n",Nf,Nu+1);
fscanf_s(f2,"%d %d %d %d %d %c\n",&i,&L,&NAt,&T,&Sp,&Zs,1);//��� �����, ������� �������, ���������� ���� Zs
fclose(f2);


eps=0.00000001;          //����������� ���������
//��������� ������� ��������
for(i=0;i<140;i++)DG[i]=tG[i]=0; for(i=0;i<140;i++)for(j=0;j<140;j++){WTB[i][j]=0;tTB[i][j]=0;fTB[i][j]=0;}

//
//������: ���� (����������� ������������� �� ������� ������)
//
fscanf_s(f3,"%d",&Na,1);    //����� ������ �������

if(NAt<2)  return 1;        //ERROR 1 ��������� ������
if(Na!=NAt)return 1;        //ERROR 1 ��������� ������

while((c=fgetc(f3))!='\n'); //����� �������
i=0; while((c=fgetc(f3))!='\n'){if(c!='\t'&& i<Na){eJ[i]=c;i++;}}

//�������� �������
for(j=0;j<Na;j++)for(i=0;i<Na;i++)
{fscanf_s(f3,"%d",&WTB[j][i],1);if(i==j){DG[j]=WTB[j][i];WTB[j][i]=0;}}//TB, ����=0

//
//������: ����������
//
w=0.0; for(i=0;i<NAt;i++)for(j=0;j<31;j++)w=w+float(WTB[i][j]);
De=0;  for(i=0;i<NAt;i++)De=De+DG[i];     w=w+float(De);

for(i=0;i<NAt;i++)for(j=0;j<NAt;j++) FTB[i][j]=float(WTB[i][j])/w;  //����������

//������������� ������ ���������� �������
Mn=M;
if(Mn<0) Mn=0;
if(Mn>Nu)Mn=Nu;


//
//������� ����
//


for(i4=0;i4<Nf;i4++)
{
//������ ��������� ������� ������� (����������� ������������� �� ������� ��������� ������)

NaP=0; //���� ������� �������

//��������� ���������

while((c=fgetc(f))=='\n'); //������ ������ ����� ���������� � ������ �������
fscanf_s(f,"%d\n",&sNN,1); //����� ���������
fscanf_s(f,"%c\n",&c,1);   //������ �������

//��������� ��������� ������� �������

for(i=0;i<NAt;i++){mJ[i]=Zs;tG[i]=0;}
for(j=0;j<NAt;j++)for(i=0;i<NAt;i++){tTB[j][i]=0;fTB[j][i]=0.0;} //���������� mJ � ���� NAt x NAt

fscanf_s(f,"%d",&Na,1);             //����� ������ ��������� ������� �������

NaC=0; if(Na>NAt){NaC=Na; Na=NAt;}  //��������� ����� ������, ���� �� ������ NAt.

while((c=fgetc(f))!='\n');          //����� ��������� ������� �������
i=0; while((c=fgetc(f))!='\n'){if(c!='\t' && i<Na){mJ[i]=c;i++;}}

//�������� ��������� ������� ������� tTB � ������ ��������� ��������� NaC
for(j=0;j<Na;j++){for(i=0;i<Na;i++)
{fscanf_s(f,"%d",&tTB[j][i],1);if(i==j){tG[j]=tTB[j][i];tTB[j][i]=0;}} if(NaC>0)while((c=fgetc(f))!='\n');}//TB, ����=0
if(NaC>0)for(j=Na;j<NaC;j++)while((c=fgetc(f))!='\n');else while((c=fgetc(f))!='\n');


//
//���������������� ������� ������� tTB � ������������ � �������� ��������� ��������
//
//������ ���������� �������  M �� (&f1,"ouR.txt","r") � ����������� ������� �  (&f4,"tmp.txt","w")
if(Nu!=0)
{
//(&f1,"ouR.txt","r")
//��������� ��������� ouR
while((c=fgetc(f1))=='\n'); //������ ������ ����� ���������� � ������ �������
fscanf_s(f1,"%d\n",&sNN,1); //����� ���������
fscanf_s(f1,"%c\n",&c,1);   //������ �������
fprintf(f4,"_%d_\n",sNN);
if(Mn!=0)
{
//������� ���������� �������
for(i=0;i<Mn-1;i++){while((c=fgetc(f1))!='\n')fprintf(f4,"%c",c);fprintf(f4,"\n");}
//��������� ������� NAt ������.
i=0;  while(i<NAt){c=fgetc(f1);xJ[i]=c;i++;fprintf(f4,"%c",c);}
while((c=fgetc(f1))!='\n')fprintf(f4,"%c",c);fprintf(f4,"\n");
}
//������� ���������� �������
for(i=Mn;i<Nu;i++){while((c=fgetc(f1))!='\n')fprintf(f4,"%c",c);fprintf(f4,"\n");}
}
if(Mn!=0)
{
//�������� ������� �� ���������� �������� ������
j=0;for(i=0;i<NAt;i++)for(x=0;x<NAt;x++)if(xJ[i]!=Zs && xJ[i]==mJ[x])j++;
if(j!=Na){for(i=0;i<NAt;i++)mJ[i]=Zs; NaP=1; goto NEN;} //������ �������
//������������������ ��������� ������� � ������������ � �������� ��������� ��������
for(i=0;i<NAt;i++)for(x=0;x<NAt;x++){if(xJ[i]!=Zs && xJ[i]==mJ[x])for(j=0;j<NAt;j++)fTB[j][i]=float(tTB[j][x]);}
for(i=0;i<NAt;i++)for(x=0;x<NAt;x++){if(xJ[i]!=Zs && xJ[i]==mJ[x])for(j=0;j<NAt;j++)tTB[i][j]=int(fTB[x][j]);}
for(i=0;i<NAt;i++)mJ[i]=xJ[i];
}

//
// ����� ��������
//***************************************************
// ��������� ����������
//
Dt=0;
for(i=0;i<NAt;i++)Dt=Dt+tG[i];

k=NAt;
w1=0.0;
for(i=0;i<NAt;i++)for(j=0;j<NAt;j++)w1=w1+float(tTB[i][j]);  w1=w1+float(Dt);

for(i=0;i<NAt;i++)for(j=0;j<NAt;j++)fTB[i][j]=float(tTB[i][j])/w1;


i=0;p=0;j=1;X=X1=0;
while (j<NAt)
{
while((i+j)<NAt)
{w1=w2=w3=w4=0; X++;w8=0;
for(x=0;x<k;x++){w1=w1+fabs(FTB[i][x]-fTB[i][x])+fabs(FTB[x][i]-fTB[x][i]);}
for(x=0;x<k;x++){w2=w2+fabs(FTB[i+j][x]-fTB[i+j][x])+fabs(FTB[x][i+j]-fTB[x][i+j]);}


w6=fTB[i][i+j]; fTB[i][i+j]=0.0;
w7=fTB[i+j][i]; fTB[i+j][i]=0.0;
w9=FTB[i][i+j]; FTB[i][i+j]=0.0;
w10=FTB[i+j][i];FTB[i+j][i]=0.0;

for(x=0;x<k;x++) {w3=w3+fabs(FTB[i][x]-fTB[i+j][x])+fabs(FTB[x][i]-fTB[x][i+j]);}
for(x=0;x<k;x++) {w4=w4+fabs(FTB[i+j][x]-fTB[i][x])+fabs(FTB[x][i+j]-fTB[x][i]);}

fTB[i][i+j]=w6; w3=w3+fabs(w9-w6)+fabs(w9-w7);
fTB[i+j][i]=w7; w4=w4+fabs(w10-w7)+fabs(w10-w6);
FTB[i][i+j]=w9;
FTB[i+j][i]=w10;

w8=w1+w2-w3-w4;

if(w8>0.0+eps)
{p=1;w=w-w1-w2+w3+w4; X1++;
for(x=0;x<k;x++){w1=fTB[i][x];fTB[i][x]=fTB[i+j][x];fTB[i+j][x]=w1;}
for(x=0;x<k;x++){w1=fTB[x][i];fTB[x][i]=fTB[x][i+j];fTB[x][i+j]=w1;}
ig=mJ[i];mJ[i]=mJ[i+j];mJ[i+j]=ig;
break;
}
i++;
}
i=0;if(p==1){p=0;j=0;}
j++;
}

NEN:
//����� ���������� �������
if(Nu==0)fprintf(f4,"_%d_\n",sNN);
//2.  ������ ������ �������
for(i=0;i<NAt;i++)fprintf(f4,"%c",mJ[i]);
c=' ';if(NaP==1)c=Zs;else if(Mn>0) c='+';
fprintf(f4,"\t%d\t%d\t%c[JAC]\n",Nu+1,Mn,c);

}

//
//�����
//
fclose(f4);
fclose(f1);
fclose(f);

fopen_s(&f1,"ouR.txt","w");
fopen_s(&f4,"tmp.txt","r");
while((c=fgetc(f4))!=EOF)fprintf(f1,"%c",c);
fclose(f4);
fclose(f1);

fopen_s(&f4,"tmp.txt","w");
c=' ';fprintf(f4,"%c",c);
fclose(f4);

return 0;

}
///////////////////////////////////
///////////////////////////////////
int reduce() //������ ��������� ���������� � ��������� ���������� �/��� ��������
//            ����������� ��������� ���������� �� ���������� ������������ ������ �������� Nz
//            ��� �������� =1 ������ ����� � ������ - �������� ��������
//            �������� �������� = 0 - �������� ���� input.txt ���������� � inT.txt ��� ���������
//            �������� �������� = 1 - �� input.txt ����������� � inT.txt ���������, ��� ������� Nz=NA
//            �������� �������� = 2 - �� input.txt ����������� � inT.txt ���������, ��� ������� Nz<NA
//            ��� ������� ���������� ����� �������� ������ ���� ����������� ���������
//            �������������� � ������� ��������� ��������� �������� ���������� ������ ���� ������� ���� saT.txt
//            ��� ���������� ��������� ����� input.txt.
//������� �������: input.txt
//                 Ititle.txt
//                 saT.txt
//�������� ������: inT.txt
//������� ������:  tmp.txt
//
//return 0:   ��� � �������
//
{
char s[500000];
char c;
int sNN;

int L,NA,T,Sp,Zs,Nf;

int i,x,lns,Nz,Kf,NR,Rt,Rt1;
int i4;

FILE *f,*f1,*f2,*f3,*f4;

fopen_s(&f, "input.txt","r");
fopen_s(&f1,"saT.txt","r");
fopen_s(&f2,"Ititle.txt","r");
fopen_s(&f3,"inT.txt","w");
fopen_s(&f4,"tmp.txt","w");

fscanf_s(f,"%d\n",&Nf,1);//���������� �������� �����

fscanf_s(f2,"%d %d %d %d %d %c\n",&i,&L,&NA,&T,&Sp,&Zs,1);//��� ����� � ������� �������

NR=Rt=Rt1=0;
fscanf_s(f2,"%d\n",&NR); //���������� ����� ��������
for(i=0;i<NR;i++){fscanf_s(f2,"%d",&Rt);
if(Rt==1)fscanf_s(f2,"%d",&Rt1);
while((c=fgetc(f2))!='\n');} //�������� ��������
fclose(f2);

if(NR==0) //����������� �������� ����� input.txt � inT.txt ��� ���������.
{
fprintf(f3,"%d\n",Nf);
while((c=fgetc(f))!=EOF)fprintf(f3,"%c",c);
fclose(f4);
fclose(f3);
fclose(f1);
fclose(f);
return 0;
}
else
if(Rt1==0)
{        //����������� �������� ����� input.txt � inT.txt ��� ���������.
fprintf(f3,"%d\n",Nf);
while((c=fgetc(f))!=EOF)fprintf(f3,"%c",c);
fclose(f4);
fclose(f3);
fclose(f1);
fclose(f);
return 0;
}
else
{

Kf=0;
//
//������� ����
//

for(i4=0;i4<Nf;i4++)
{
//������ ���������� ���������� ���������

//��������� ���������

while((c=fgetc(f))=='\n'); //������ ������ ����� ���������� � ������ �������
fscanf_s(f,"%d\n",&sNN,1); //����� ���������
fscanf_s(f,"%c\n",&c,1);   //������ �������

//����� ��������� � ������ �������
i=0;
while((c=fgetc(f))!='\n')if(i<500000){s[i]=c;i++;}
lns=i;

while((c=fgetc(f1))!='Z'); c=fgetc(f1);//���������� ������ ������ Nz �� saR
fscanf_s(f1,"%d",&Nz,1);
while((c=fgetc(f1))!='\n');

if((Rt1==1 && Nz==NA) || (Rt1==2 && Nz<NA))
{
fprintf(f4,"_%d_\n",sNN);
for(x=0;x<lns;x++)fprintf(f4,"%c",s[x]);
fprintf(f4,"\n");
Kf++;
}

}

fclose(f4);
fclose(f1);
fclose(f);

fopen_s(&f4,"tmp.txt","r");
fprintf(f3,"%d\n",Kf);
while((c=fgetc(f4))!=EOF)fprintf(f3,"%c",c);
fclose(f4);
fclose(f3);

fopen_s(&f4,"tmp.txt","w");
c=' ';fprintf(f4,"%c",c);
fclose(f4);

return 0;
}
}

///////////////////////////////////
int staR(int N,int M[])//������ �������������� ��������� �����������.
//
//������ ������� M[N] �������� ������ ������� ��� ��������� �� ����� ouR.txt,   N <=10.
//���� ����� <1, �� ����� ����������� ������ 1. ��� ������, ����������� ���������� ������� � ouR.txt,
//���������� �� ����� ���������� �������. ��������� ������� �������������� � ������� ����������� �������.
//�������������� ������ �������� ������ ���� �=0 ��� ������ L>0 � NA <= 45, �� ����� 1000 ����������
//�� ���� ���, Nf <= 1000. ���� ���������� ����� ����� � ����� enS Ns=0, �� ����� ����� ����������
//������������� ������� ������� ���������� �� ����� inS ��� ��������� �����.
//
//�����.
//������������ � ����� enS � ������ ������ ����� ������ ������� ����� ������:Ns N0 Nd
//Ns - ���������� ����� �����, N0 - ��������� ��������, Nd - ����������
//
//����������� ��� ����� �����: 0 <= Ns=0 <= 1000. ���� Ns > 1000, �� ����������� Ns=1000.
//��� ������� �������� ����� ���������� ��� ��������� ����������, ����������� ������������ ��������������
//������� ��������, ������������ ��� ��������� ������ � ���� �������� ����� �����
//
//������.
//������������ � ����� enS ����� ������� �����: ����������� ����� Ng � ������� ������ ������ � ��������� ������.
//
//� ����� ������ 0 <= Ng <= NA.���� Ng > NA, �� ����������� Ng = NA.
//���� ���������� ����� � enS Ng=0, �� �������� ���������� �� ������� �� ���������, ���������� ���������������
//��������� ��� ������� ������� ��������� ��� ��� ����� ������ (Ng = 1) �� ���� ������ ��������.
//���� ���������� ������ � ������� ������, ��� ������ ��������, �� ���������� �������������� (��������� �� �������)
//������, ������� �������� ����������� � ������� ����� �������� �� enU - ��� ��� ������� ��������������� �������,
//��� � � �������� ���������� �� �������.
//
//��� ����� ���������� � ������� ����� �������� ��������� ������ �1-�4 �� ���������� � �������� ����������
//
//������� �������: ouR.txt
//                 Ititle.txt
//                 inU.txt
//                 enU.txt
//                 enS.txt
//�������� ������: saR.txt
//������� ������:  tmp.txt
//
//return 0:   ��� � �������
//return 1:   T!=0
//return 2:   L==0
//return 3:   NA > 45
//return 4:   Nf > 1000
//
{
char eJJ[45],eJ[45],mJ[45],SA[45],TW[45];//Na <= 45
char c,Zs;
char NameMod[8];
int ML[10],NMW;
int sNN,NmM;

int L,T,Sp,Nf,Na,NAt,Nfu,Nu,Nfs;

int gV[45],pT[45];//Na <= 45
int i,j,m,m2;
int i4;
int Unum;
int sT,sNB,sNE,gN,qZ,SgN;
int R1,R2;

//����
int Stat[1000][95],StatF[1000][3],BfStat[95];//����� ����� <= 45
short int StatG[1000][90];//2*Na, Na <= 45
char WJ[1000][45]; //Na <= 45
int  hJ[1000][46]; //Na+1
double StatR[1000][20];
double StatO3[1000];
int StF,eRR,O4Y;
int SC[1000],nSC,lns1;//����� <= 1000 �����
int e1,e2,e3,e4,e5;
int g=0,g1=0,g3=0,k,p,lns,x;
double w,w1,w2,w3,w4,w5,w6,w7;
double v,v1,v2,v3;
//

FILE *f,*f1,*f2,*f3,*f4,*f5,*f7;

fopen_s(&f, "enU.txt","r");
fopen_s(&f2,"Ititle.txt","r");
fopen_s(&f4,"enS.txt","r");


Nf=N;

fscanf_s(f2,"%d %d %d %d %d %c\n",&i,&L,&NAt,&T,&Sp,&Zs,1);//��� ����� � ������� �������
fclose(f2);

//������
fscanf_s(f,"%d",&Na,1);//����� ������
while((c=fgetc(f))!='\n');
i=0;
while(i<Na)
while((c=fgetc(f))!='\t'){eJJ[i]=c;i++;}

fscanf_s(f4,"%d %d %d\n",&sT,&sNB,&sNE,1);
fscanf_s(f4,"%d\n",&gN,1);
for(i=0;i<Na;i++)gV[i]=0;
i=0;x=0;
while(i<gN)
{while((c=fgetc(f4))!='\n'){x++;for(j=0;j<Na;j++)if(c==eJJ[j]){gV[j]=i+1;break;}} i++;}

//��������� ��� ��������� ���������� ������ � ������� (�������������� ������)
if(gN>0 && x<Na){gN++;for(j=0;j<Na;j++)if(gV[j]==0)gV[j]=gN;}
//��������� ��� �������� ���������� �����
SgN=1;if(gN==0){SgN=0;gN=1;for(i=0;i<Na;i++)gV[i]=1;}

//����������� � ������������ ������� ������� ������� �[N]
NMW=N; if(NMW>10)NMW=10; for(i=0;i<NMW;i++)ML[i]=M[i];
j=1;while(j!=0){j=0;for(i=1;i<NMW;i++)if(ML[i]<ML[i-1]){m=ML[i-1];ML[i-1]=ML[i];ML[i]=m;j=1;}}

for(i=0;i<3;i++)for(j=0;j<1000;j++)StatF[j][i]=0;          //����: ��������� �������
nSC=sT;  if(nSC>1000)nSC=1000;                             //����: ���������� ���������� ����� �����
if(nSC>0){SC[0]=sNB;for(i=1;i<nSC;i++)SC[i]=SC[i-1]+sNE;} //����: ���������� ����� ����� � �����������

//
// ������� ���� �������
//

for(Unum=0;Unum<NMW;Unum++)
{
fopen_s(&f1,"ouR.txt","r");
fopen_s(&f5,"tmp.txt","w");

if(Unum==0){fopen_s(&f7,"inU.txt","r");fscanf_s(f7,"%d",&Nfs,1);}
if(Unum>0)fopen_s(&f3,"saR.txt","r");

fscanf_s(f1,"%d %d\n",&Nfu,&Nu,1);


//************************************************************************************

StF=Nfu;                   //����: �����  ����������

//�������� �������� �����������
if(T!=0)    return 1;
if(L==0)    return 2;
if(NAt>45)  return 3;
if(Nfu>1000)return 4;

//������������� ������ �������
if(ML[Unum]<1)ML[Unum]=1;
if(ML[Unum]>Nu)ML[Unum]=Nu;


fprintf(f5,"%d %d\n",Nfu,Unum+1);
//************************************************************************************
eRR=0;                     //����: ����� ��������� ����������

for(i=0;i<95;i++)for(j=0;j<1000;j++)Stat[j][i] =0;  //����: ��������� �������
for(i=0;i<90;i++)for(j=0;j<1000;j++)StatG[j][i]=0;
for(i=0;i<20;i++)for(j=0;j<1000;j++)StatR[j][i]=0.0;

//
//���� ������� ����������
//

for(i4=0;i4<Nfu;i4++)
{
//������ ��������� ����� inU � ������������ ����� ��������� StatF[0], ������� �������� StatF[1]
//                                          � ������ hJ[Na] ������ WJ[Na] �������� �������
if(Unum==0)
{
//(&f7,"inS.txt","r")
//��������� ��������� inU
while((c=fgetc(f7))=='\n'); //������ ������ ����� ���������� � ������ �������
fscanf_s(f7,"%d\n",&sNN,1); //����� ���������
fscanf_s(f7,"%c\n",&c,1);   //������ �������
fscanf_s(f7,"%d",&qZ,1);    //����� ������
while((c=fgetc(f7))!='\n');

//������������ ������� ������� qZ ������.  ����� ��������� ����� ���������, ������� ����� ���������
i=0;  while(i<qZ)while((c=fgetc(f7))!='\t'){WJ[i4][i]=c;i++;} while((c=fgetc(f7))!='\n');
//����� ��������� ������� ����� ����� ������� � �� ����� - ������� ����� M
lns=0; for(i=0;i<qZ;i++){fscanf_s(f7,"%d",&hJ[i4][i+1],1);lns=lns+hJ[i4][i+1];}
hJ[i4][0]=qZ;
while((c=fgetc(f7))!='\n');

//�������� ������� �� ��������� � ����� ��������� �� �������� ������ M
lns1=lns; if(nSC>0)for(i=0;i<nSC;i++)if(lns<=SC[i]){lns1=SC[i];break;}
StatF[i4][0]=lns1;StatF[i4][1]=1;if(qZ<Na)StatF[i4][1]=0;
StatF[i4][2]=lns;
}

//������ ���������� ������� �� ������ M[]�� (&f1,"ouR.txt","r") � ������� � �������� ��������� �� (&f6,"saT.txt","r")

//(&f1,"ouR.txt","r")
//��������� ��������� ouR
while((c=fgetc(f1))=='\n'); //������ ������ ����� ���������� � ������ �������
fscanf_s(f1,"%d\n",&sNN,1); //����� ���������
fscanf_s(f1,"%c\n",&c,1);   //������ �������

//������� ���������� �������
for(i=0;i<ML[Unum]-1;i++)while((c=fgetc(f1))!='\n');

//������� ������� Na ������.  ����� ��������� ����� ���������, ������� ����� ���������
i=0;  while(i<Na)while((c=fgetc(f1))!='\t'){mJ[i]=c;i++;}

//��� �������� �������
i=0;  while((c=fgetc(f1))!='[');while((c=fgetc(f1))!=']'){NameMod[i]=c;i++;} NmM=i;

//������� ���������� �������
for(i=ML[Unum]-1;i<Nu;i++)while((c=fgetc(f1))!='\n');

//��������� ������� �� �������
for(i=0;i<Na;i++){eJ[i]=eJJ[i];x=0;for(j=0;j<Na;j++)if(eJ[i]==mJ[j])x=1;if(x==0)eJ[i]=Zs;}

//
//����� ������� � ����������� ��������������� ��������� ��� �������� ���������
//
//����� ������� (���� ���) � �������� ������� �� �������� ����� �����
//                 � (&f5,"tmp.txt","w") � ���������� ����������� ������ �� (&f3,"saR.txt","r")
if(Unum==0)
{
//(&f5,"tmp.txt","w")
fprintf(f5,"_%d_ M=%d\n",sNN,lns);
for(j=0;j<gN;j++){for(i=0;i<Na;i++)if(gV[i]==j+1)fprintf(f5,"%c",eJ[i]);fprintf(f5,"  ");}
fprintf(f5,"\n");
for(j=0;j<gN;j++){for(i=0;i<Na;i++)if(gV[i]==j+1)fprintf(f5,"%c",mJ[i]);fprintf(f5,"  ");}
fprintf(f5,"\n");
}
else
{
//(&f3,"saR.txt","r") -> (&f5,"tmp.txt","w")
fscanf_s(f3,"%d %d\n",&R1,&R2,1);
R1=Unum+1;
//����������� ����������� saR � tmp
for(i=0;i<2*R1;i++){while((c=fgetc(f3))!='\n')fprintf(f5,"%c",c);fprintf(f5,"\n");}
//������� �������
for(j=0;j<gN;j++){for(i=0;i<Na;i++)if(gV[i]==j+1)fprintf(f5,"%c",mJ[i]);fprintf(f5,"  ");}
fprintf(f5,"\n");
}

//��������� ������� � ��������
for(i=0;i<Na;i++)SA[i]=TW[i]=0; m=m2=0; x=0;
for(i=0;i<Na;i++)if(mJ[i]!=eJ[i])
{
SA[i]=1;m++; if(eJ[i]==Zs){TW[i]=1;m2++;}
if(mJ[i]!=Zs)for(j=0;j<hJ[i4][0];j++)if(mJ[i]==WJ[i4][j])x=x+hJ[i4][j+1];
}
m=m-m2;
//���������� ����������� ��������� ��� �������� ��������� � ����� ���������� ��������� �� �������� ����� �����
if(m!=0)
{
Stat[eRR][0]=StatF[i4][0]; Stat[eRR][1]=m; Stat[eRR][2]=m2;Stat[eRR][3]=hJ[i4][0];
for(j=0;j<gN;j++){Stat[eRR][4+j]=0;Stat[eRR][4+Na+j]=0;}
StatO3[eRR]=double(x)/double(StatF[i4][2]);
for(j=0;j<gN;j++)
{
g=0;
for(i=0;i<Na;i++)
if(gV[i]==j+1)
if(SA[i]!=0)
{
fprintf(f5,"-");g=1;
for(x=0;x<Na;x++)if(mJ[i]!=Zs && mJ[i]==eJ[x] && gV[i]!=gV[x]){Stat[eRR][4+Na+j]=1;break;}
}
else fprintf(f5," ");
Stat[eRR][4+j]=g;fprintf(f5,"  ");
}

if(m2==0)fprintf(f5," ----%d\n",m);else fprintf(f5," ----%d   %d\n",m,m2);

eRR++;

}
else  fprintf(f5,"\n");

} //i4 - end ����� ����������

//
//�������� ����������
//
//����� �������� ���������� �������� ������� �� ������� Nfu ����������
//

if(Unum!=0)while((c=fgetc(f3))!=EOF)fprintf(f5,"%c",c);//���������� �����

fprintf(f5,"\nSolution=%d\t[",M[Unum]);
for(i=0;i<NmM;i++)fprintf(f5,"%c",NameMod[i]);
fprintf(f5,"]\tL=%d\tNA=%d\tT=%d",L,NAt,T);
fprintf(f5,"\tTexT=%d\tERR=%d\n\n",StF,eRR);
//�������������� ������� ���������� Stat � StatO3 �� ����������� ������ �
j=1;
while(j>0)
{
j=0;
for(i=0;i<eRR-1;i++)
if(Stat[i+1][0]<Stat[i][0])
{
for(k=0;k<95;k++)BfStat[k]=Stat[i][k];
for(k=0;k<95;k++)Stat[i][k]=Stat[i+1][k];
for(k=0;k<95;k++)Stat[i+1][k]=BfStat[k];
w=StatO3[i];StatO3[i]=StatO3[i+1];StatO3[i+1]=w;
j=1;
}
}

//������������ ��������� ���������� StatR �� �������� ����� ���������
k=0;p=0;
while(p<eRR)
{
m=Stat[p][0];g1=g3=Stat[p][1]; j=g=0; e1=e4=e5=0;e2=e3=Stat[p][2];v1=v2=double(Stat[p][1])/double(Stat[p][3]);
v=w=w4=w5=0.0; w6=w7=0.5;w1=w3=StatO3[p]; for(x=0;x<gN;x++){StatG[k][x]=0;StatG[k][Na+x]=0;}

for(i=0;i<eRR;i++)
if(m==Stat[i][0])
{
v3=double(Stat[i][1])/double(Stat[i][3]);
v=v+v3; w=w+StatO3[i]; if(StatO3[i]<w1)w1=StatO3[i];if(StatO3[i]>w3)w3=StatO3[i];
if(Stat[i][3]<Na)
{
e4++;
if(Stat[i][2]!=0)
{
e5++; e1=e1+Stat[i][2];
if(2*Stat[i][3]>Na)w5=double(Stat[i][2])/double(Na-Stat[i][3]); else w5=double(Stat[i][2])/double(Stat[i][3]);
w4=w4+w5;
if(w5<w6)w6=w5;if(w5>w7)w7=w5;
}
}
for(x=0;x<gN;x++)StatG[k][x]=StatG[k][x]+Stat[i][4+x];          //����� �� �������
for(x=0;x<gN;x++)StatG[k][Na+x]=StatG[k][Na+x]+Stat[i][4+Na+x]; //����� �� �������
if(v3<v1)v1=v3;if(v3>v2)v2=v3;
g++;
}

StatR[k][0]=double(m);   //����� ����� ��� ������ ���������, ���� ����� �� ������
//   StatR[k][1]
StatR[k][2]=double(g);   //���������� ��������� ����������, ���������� � ����� �����
StatR[k][3]=v;           //��������� ������������� ������ �2
StatR[k][4]=v1;          //�����������  ������������� ������ �2
StatR[k][5]=v2;          //������������ ������������� ������ �2
StatR[k][8]=w;           //��������� �������� �3
StatR[k][9]=w1;          //�����������  ������ �3
StatR[k][10]=w3;         //������������ ������ �3
//   StatR[k][11]
StatR[k][12]=w4;         //��������� ��������  �4�
StatR[k][13]=w6;         //�����������  ������ �4�
StatR[k][14]=w7;         //������������ ������ �4�
StatR[k][15]=double(e4); //���-�� ���������� � �������� ���������
StatR[k][16]=double(e5); //���-�� ���������� � ������� �4
StatR[k][17]=double(e1); //��������� ��������  �4

p=p+g;k++;               //k- ���������� �������������� ����� �����
}
for(i=0;i<k;i++)if(StatR[i][2]!=0)StatR[i][3]=StatR[i][3]/StatR[i][2];     //������� ������ �2H
for(i=0;i<k;i++)if(StatR[i][2]!=0)StatR[i][8]=StatR[i][8]/StatR[i][2];     //������� ������ �3
for(i=0;i<k;i++)if(StatR[i][16]!=0)StatR[i][12]=StatR[i][12]/StatR[i][16]; //������� ������ �4�
for(i=0;i<k;i++)if(StatR[i][16]!=0)StatR[i][17]=StatR[i][17]/StatR[i][16]; //������� ������ �4
for(i=0;i<k;i++)if(StatR[i][15]!=0)StatR[i][15]=StatR[i][16]/StatR[i][15]; //A �4

g3=0;
for(i=0;i<k;i++)
{
g=g1=0;w=w1=w2=0.0;
m=int(StatR[i][0]);
for(j=0;j<eRR;j++)
if(m==Stat[j][0])
{
v3=double(Stat[j][1])/double(Stat[j][3]);
w=w+(v3-StatR[i][3])*(v3-StatR[i][3]);
w1=w1+(StatO3[j]-StatR[i][8])*(StatO3[j]-StatR[i][8]);

if(Stat[j][3]<Na)
if(Stat[j][2]!=0)
{
if(2*Stat[j][3]>Na)w5=double(Stat[j][2])/double(Na-Stat[j][3]); else w5=double(Stat[j][2])/double(Stat[j][3]);
w2=w2+(w5-StatR[i][12])*(w5-StatR[i][12]);
}
}
if(StatR[i][2]!=0)StatR[i][6]=sqrtf(float(w/StatR[i][2]));     //����������� ���������� ������� ������ �2
if(StatR[i][2]!=0)StatR[i][11]=sqrtf(float(w1/StatR[i][2]));   //����������� ���������� ������� ������ �3
if(StatR[i][16]!=0)StatR[i][18]=sqrtf(float(w2/StatR[i][16])); //����������� ���������� ������� ������ �4
}

//����� ���������� ���������� � ������ ����� ����� � ���������� ���������� � ������ ���������
for(i=0;i<k;i++)
{
m=int(StatR[i][0]);StatR[i][1]=StatR[i][7]=0.0;
for(j=0;j<Nfu;j++)
if(m==StatF[j][0]){StatR[i][1]=StatR[i][1]++;StatR[i][7]=StatR[i][7]+double(StatF[j][1]);}
}
//������� ������ �4
O4Y=0;for(i=0;i<k;i++)if(StatR[i][16]!=0.0)O4Y=1;



fprintf(f5," N\tK\tNA\tO1H\tO2H\tO2Hmin\tO2Hmax\tSD O2H\t\tO3H\tO3Hmin\tO3Hmax\tSD O3H");

if(O4Y==1)fprintf(f5,"\tN O4\t �4\tA  O4\tB  O4H\tO4Hmin\tO4Hmax\tSD O4H");

fprintf(f5,"\n");

for(i=0;i<k;i++)
{
m=int(StatR[i][0]);g=int(StatR[i][1]);w4=StatR[i][2]/StatR[i][1];w=StatR[i][3];w1=StatR[i][4];w2=StatR[i][5];w3=StatR[i][6];
p=int(StatR[i][7]);

fprintf(f5," %d\t%d\t%d\t%4.2f\t%6.4f\t%6.4f\t%6.4f\t%6.4f",m,g,p,w4,w,w1,w2,w3);

w=StatR[i][8];w1=StatR[i][9];w2=StatR[i][10];w3=StatR[i][11];

fprintf(f5,"\t\t%6.4f\t%6.4f\t%6.4f\t%6.4f",w,w1,w2,w3);

if(O4Y==1)
{
w=StatR[i][12];w1=StatR[i][13];w2=StatR[i][14];w3=StatR[i][18];w4=StatR[i][15];w7=StatR[i][17];j=int(StatR[i][16]);

fprintf(f5,"\t%4d\t%6.3f\t%6.4f\t%6.4f\t%6.4f\t%6.4f\t%6.4f",j,w7,w4,w,w1,w2,w3);
}

fprintf(f5,"\n");
}

//������� ������
if(SgN>0)
{
fprintf(f5,"\n N\tK");
for(j=0;j<gN;j++){p=0;fprintf(f5,"\t");for(i=0;i<Na;i++)if(gV[i]==j+1){fprintf(f5,"%c",eJJ[i]);p++;} pT[j]=p/8;}

if(gN>1)
{fprintf(f5,"\t");for(j=0;j<gN;j++){fprintf(f5,"\t");for(i=0;i<Na;i++)if(gV[i]==j+1)fprintf(f5,"%c",eJJ[i]);}}

fprintf(f5,"\n");

for(i=0;i<k;i++)
{
fprintf(f5," %d\t%d",int(StatR[i][0]),int(StatR[i][1]));
for(x=0;x<gN;x++){if(x>0)for(p=1;p<pT[x-1]+1;p++)fprintf(f5,"\t");fprintf(f5,"\t%d",StatG[i][x]);}

if(gN>1)
{for(p=0;p<pT[gN-1]+1;p++)fprintf(f5,"\t"); for(x=0;x<gN;x++){if(x>0)for(p=1;p<pT[x-1]+1;p++)fprintf(f5,"\t");fprintf(f5,"\t%d",StatG[i][Na+x]);}}

fprintf(f5,"\n");
}
}
fclose(f1);
fclose(f5);

if(Unum==0)fclose(f7);

if(Unum>0)fclose(f3);

fopen_s(&f3,"saR.txt","w");
fopen_s(&f5,"tmp.txt","r");
while((c=fgetc(f5))!=EOF)fprintf(f3,"%c",c);
fclose(f3);
fclose(f5);

fopen_s(&f5,"tmp.txt","w");
c='\n';fprintf(f1,"%c",c);
fclose(f5);

//************************************************************************************
}// Unum - end ����� �������

return 0;
}

//������ ��������� � ���������� LIB.lib
*/
/*
struct text_info
{
	int lower_array[50];
	int upper_array[50];  // ������� ��� �������� ������������� ������� ������� ��������
	int space_num;
	int symbol_num;
	double rel_space;
	int symbol_alphabet;
	int bigrams_array[50][50];
	int digrams_first_array[50][50];
	int digrams_second_array[50][50];
	int bigrams_num;
	int bigrams_numalt;
	int digram_first_num;
	int digram_second_num;
	char alphabet[50];
	char space_symbol;
	double coincidence_index;
	double conjugation_index; // ������ ���������� B � D
	double distinguish_index; // ������ ��������� D1 � D2
	int scale_point; // ����� �����
};

int staT(int NinFile)//������ �������������� ��������� ��������� ���������� (�������)
					 //
					 //       int NinFile - ��������� ������� ���� ��� ���������
					 //                     NinFile==0 -input.txt   NinFile==1 -inT.txt
					 //                     ����  NinFile!=0 ��� NinFile!=1 �� ����������� NinFile==0
					 //
					 //�������������� ������ �������� ������ ���� �=0 ��� ������ L>0 � NA <= 45, �� ����� 1000 ����������
					 //�� ���� ���, Nf <= 1000. 
					 //
					 //��� ����������� ����� ������� ����� �������������� ���� code.txt ���� � ��� ������ ����������,
					 //��� � �������� �����, �� ��� ������ ���������� �����������.
					 //
					 //�����.
					 //������������ � ����� enQ � ������ ������ ����� ������ ������� ����� ������:Ns N0 Nd
					 //Ns - ���������� ����� �����, N0 - ��������� ��������, Nd - ����������
					 //
					 //����������� ��� ����� �����: 0 <= Ns <= 1000. ���� Ns > 1000, �� ����������� Ns=1000.
					 //��� ������� �������� ����� ���������� ��� ��������� ����������, ����������� ������������ ��������������
					 //������� ��������, ������������ ��� ��������� ������ � ���� �������� ����� �����
					 //
					 //���� Ns=0, �� ����� ����� ������������ ������������ �������������� �������� ��������� ���������� 
					 //           �� ����� inS ��� ��������� �����.
					 //���� N0==0 � Nd !=0, �� ������������ ����� �����  N0=Nd.
					 //���� N0==0 � Nd ==0, �� ���������� ������� �� ����� ����������� ������� �������� Ns=0. 
					 //���� Ns!=0 � N0 !=0 � Nd ==0, �� ����������� ������������ ����� ����� N0.             
					 //
					 //������� ���������: struct text_info
					 //
					 //������� �������: inT.txt ��� input.txt   - � ����������� �� �������� ��������� NinFile
					 //                 Ititle.txt
					 //                 enQ.txt
					 //                 code.txt
					 //�������� ������: saT.txt
					 //
					 //
					 //return 0:   ��� � �������
					 //return 1:   
					 //

{
	int language_type; // ��� �����: �-1� - ���� ������ �� ���������, �0� - �������, �1� - ����������
	int cardinality; // �������� ��������
	int text_type; // ��� ������: 0 � ��������, 1 � ������, 2 � �������, 3 � ����������
	int space_presence; // ������� �������: �-1� - ������� ������� �� ����������, �0� - ���, �1� -����
	int error = 0; // ���������� ������ ����: NA < Z
	int SymbolN = 0, StrNum = 1;
	int fragment_num;

	ifstream in;
	ifstream title;
	ofstream out;
	string str, strtitle;
	title.open("Ititle.txt");

	if (NinFile == 1)in.open("inT.txt"); else in.open("input.txt");

	out.open("saT.txt");

	if (in.eof())
	{
		out.close();
		in.close();
		return 1;
	}

	getline(in, str);
	fragment_num = stoi(str);

	if (fragment_num > 1000)fragment_num = 1000;
	if (fragment_num <= 0)return 1;

	int count = -1;

	text_info *data = new text_info[1000];

	getline(title, strtitle, ' '); // ����� �����
	getline(title, strtitle, ' '); // ����� �����
	language_type = stoi(strtitle);
	getline(title, strtitle, ' '); // �������� ��������
	cardinality = stoi(strtitle);
	if (cardinality == 0)
	{
		cin.get();
		out.close();
		title.close();
		in.close();
		return 1;
	}
	else
	{
		getline(title, strtitle, ' '); // ��� ������
		text_type = stoi(strtitle);
		getline(title, strtitle, ' '); // ������� �������
		space_presence = stoi(strtitle);

		title.close();

		//string lower;
		//string upper;

		if (text_type > 0)
		{
			ifstream code;
			string strcode;
			code.open("code.txt");

			int Nc, Typec;
			getline(code, strcode, ' ');
			Nc = stoi(strcode);
			getline(code, strcode);
			Typec = stoi(strcode);

			if (fragment_num > Nc) // ���� ���������� ������, ��� � code
			{
				while (getline(code, strcode)) // ��������� ��, ��� ����
				{
					if (strcode[0] == '\n')
						continue;
					if (strcode[0] == '_')
					{
						count++;
						getline(code, strcode);
						data[count].space_symbol = strcode[0];
					}
				}
				for (count = count + 1; count < fragment_num; count++) // ���������� ���������
				{
					data[count].space_symbol = data[(fragment_num%count)].space_symbol;
				}
			}
			else // ���������� �� ������, ��� � code - ��������� � ������� �����
			{
				while (getline(code, strcode))
				{
					if (strcode[0] == '\n')
						continue;
					if (strcode[0] == '_')
					{
						count++;
						getline(code, strcode);
						data[count].space_symbol = strcode[0];
					}
				}
			}
			code.close();
		}
		////////������������� ������������ ����� �������
		else for (; count < fragment_num; count++) // ���������� ���������
		{
			data[count].space_symbol = ' ';
		}
		////////
		count = -1;
		string strWithoutSpace;

		for (int y = 0; y < fragment_num; y++)
		{
			getline(in, str, '_'); // ����� ���������� ���������
			getline(in, str); // ����� ��������, ��� ����� ��������� �� �����
			getline(in, str); // ���� ������

			count++;
			// ������������ �������� ������
			data[count].scale_point = 0;
			data[count].space_num = 0;
			data[count].rel_space = 0;
			data[count].symbol_num = 0;
			data[count].bigrams_num = 0;
			data[count].digram_second_num = 0;
			data[count].digram_first_num = 0;
			data[count].symbol_alphabet = 0;
			data[count].coincidence_index = 0;
			data[count].bigrams_numalt = 0;
			for (int i = 0; i<50; i++)
				data[count].upper_array[i] = 0;
			for (int i = 0; i<50; i++)
				data[count].lower_array[i] = 0;
			for (int i = 0; i<33; i++)
				for (int j = 0; j<33; j++)
				{
					data[count].bigrams_array[i][j] = 0;
					data[count].digrams_second_array[i][j] = 0;
					data[count].digrams_first_array[i][j] = 0;
				}

			strWithoutSpace = str;
			int m = 0;
			for (int i = 0; i < int(str.length()); i++)
			{
				if (str[i] == data[count].space_symbol)
				{
					data[count].space_num++;
				}
				else
				{
					data[count].symbol_num++;
					strWithoutSpace[m] = str[i]; //  ������ � ������ ��� �������
					m++;
				}
			}

			if (m != 0)
				strWithoutSpace.resize(m); // �������� ������ ��������


										   // ������������ ������� ��������
			int SymbolPresence = 0;
			SymbolN = 0;
			data[count].alphabet[SymbolN] = strWithoutSpace[0];
			for (int j = 1; j < int(strWithoutSpace.length()); j++)
			{
				SymbolPresence = 0;
				for (int i = 0; i <= SymbolN; i++)
				{
					if (strWithoutSpace[j] == data[count].alphabet[i]) // �������� �� ����� �������, ��� �� ����� ������ ���
						break;
					else
						SymbolPresence++;
				}
				if (SymbolPresence > SymbolN)
				{
					SymbolN++;
					data[count].alphabet[SymbolN] = strWithoutSpace[j];
				}
			};

			data[count].symbol_alphabet = SymbolN + 1;

			// ������ �������, �������, ��������
			for (int i = 0; i < int(strWithoutSpace.length()); i++)
				for (int j = 0; j <= data[count].symbol_alphabet; j++)
					if (strWithoutSpace[i] == data[count].alphabet[j])
					{
						data[count].upper_array[j]++;
						for (int k = 0; k <= data[count].symbol_alphabet; k++)
							if (strWithoutSpace[i + 1] == data[count].alphabet[k])
							{
								data[count].bigrams_array[j][k]++;
								if ((i % 2) != 0)
									data[count].digrams_second_array[j][k]++;
								else
									data[count].digrams_first_array[j][k]++;
								break;
							}
					}
		}

		// ������� ����������
		for (int i = 0; i < fragment_num; i++)
		{
			// ������� ��������
			for (int j = 0; j < data[i].symbol_alphabet; j++)
				for (int k = 0; k < data[i].symbol_alphabet; k++)
					if ((data[i].digrams_second_array[j][k] != 0) || (data[i].digrams_first_array[j][k] != 0))
						data[i].bigrams_numalt++;
			// ������� ������������� ������� �������
			data[i].rel_space = (double)data[i].space_num / (data[i].symbol_num + data[i].space_num);

			// ������� ������� ����������
			for (int j = 0; j < data[i].symbol_alphabet; j++)
				if (data[i].upper_array[j] != 0)
					data[i].coincidence_index = data[i].coincidence_index + data[i].upper_array[j] * (data[i].upper_array[j] - 1);
			data[i].coincidence_index = data[i].coincidence_index / data[i].symbol_num;
			data[i].coincidence_index = data[i].coincidence_index / (data[i].symbol_num - 1);

			// ������� ������������ �������
			for (int k = 0; k < data[i].symbol_alphabet; k++)
				for (int j = 0; j < data[i].symbol_alphabet; j++)
					if (data[i].bigrams_array[k][j] > 0)
						data[i].bigrams_num++;

			// ������� ������������ ������� 1
			for (int k = 0; k < data[i].symbol_alphabet; k++)
				for (int j = 0; j < data[i].symbol_alphabet; j++)
					if (data[i].digrams_first_array[k][j] > 0)
						data[i].digram_first_num++;

			// ������� ����������� ������� 2
			for (int k = 0; k < data[i].symbol_alphabet; k++)
				for (int j = 0; j < data[i].symbol_alphabet; j++)
					if (data[i].digrams_second_array[k][j] > 0)
						data[i].digram_second_num++;

			// ������� ������� ���������� B � D � ������� ��������� D1 � D2
			if (data[i].digram_second_num > data[i].digram_first_num)
			{
				data[i].conjugation_index = 1 - (double)data[i].digram_first_num / data[i].bigrams_num;
				data[i].distinguish_index = (double)data[i].digram_first_num / data[i].digram_second_num;
			}
			else
			{
				data[i].conjugation_index = 1 - (double)data[i].digram_second_num / data[i].bigrams_num;
				data[i].distinguish_index = (double)data[i].digram_second_num / data[i].digram_first_num;
			}
		}

		// ����� ���������� �� ������� ���������
		out << fragment_num << "\n";

		for (int i = 0; i < fragment_num; i++)
		{
			out << "_" << i + 1 << "_" << "\t";
			out << "N=" << data[i].space_num + data[i].symbol_num << "\t";  // ����� �������� � ���������

			if (data[i].symbol_num > 99999)
			{
				out << "M=" << data[i].symbol_num << "\t";  // �������� ��� ����� �������
				out << "S=" << data[i].space_num << "\t";
			} // ���������� ��������
			else
			{
				out << "M=" << data[i].symbol_num << "\t\t";  // �������� ��� ����� �������
				out << "S=" << data[i].space_num << "\t";
			} // ���������� ��������
			out << "Z=" << data[i].symbol_alphabet << "\t"; // ���������� ������������ ������ ��������
			out << "B=" << data[i].bigrams_num << "\t"; // ���������� �������
			out << "D1=" << data[i].digram_first_num << "\t"; // ���������� ������� 1
			out << "D2=" << data[i].digram_second_num << "\t"; // ���������� ������� 2
			out.precision(4);
			out << fixed << "C=" << data[i].conjugation_index << "\t"; // ������ ����������
			out << fixed << "D=" << data[i].distinguish_index << "\t"; // ������ ���������
			out << fixed << "X=" << data[i].coincidence_index << "\t"; // ������ ����������
			if (cardinality < data[i].symbol_alphabet)
			{
				error++;
				out << "----";
			}
			out << "\n\n";
		}
		int Size[1000];
		ifstream sample;
		string strsample;

		int StartSize = 0, Steps = 0, StepSize = 0, EndSize = 0;
		sample.open("enQ.txt");

		getline(sample, strsample, ' ');
		Steps = stoi(strsample);
		getline(sample, strsample, ' ');
		StartSize = stoi(strsample);
		getline(sample, strsample, ' ');
		StepSize = stoi(strsample);

		if (StartSize == 0 && Steps != 0 && StepSize != 0)StartSize = StepSize; //����� ����� ��� ������� ��������� ��������
		if (StartSize == 0 && Steps != 0 && StepSize == 0)Steps = 0;            //������� �� ����� ����������� ������� ��������

		EndSize = StartSize + (Steps - 1) * StepSize;

		Size[0] = StartSize;

		// ������� �� ����������� �� ������ �����
		int FragmentNumber[1000]; // ����� ���������� � ������ ����� �����

		double MinBigramNumber[1000], MaxBigramNumber[1000]; // ����������� ����� �������, ������������ ����� �������
		double AverBigramNumber[1000], StandDevBigramNumber[1000]; // ������� ����� ������� � ��� �� ���������

		int FullFragments[1000]; // ����� ����������, ������������ ��� ����� ��������

		double MinSymbolAlphabet[1000], MaxSymbolAlphabet[1000]; // ����������� ����� ������������ ������ ��������, ������������ �����
		double AverSymbolAlphabet[1000], StandDevSymbolAlphabet[1000]; // ������� ����� ������������ ������ �������� � ���

		int MinSpaceNumber[1000], MaxSpaceNumber[1000]; // ����������� � ������������ ����� ��������
		double AverSpaceNumber[1000], StandDevSpaceNumber[1000]; // ������� ����� �������� � ��� �� ��������

		double MinSpaceRel[1000], MaxSpaceRel[1000]; // ����������� � ������������ ����� �������� (�����.)
		double AverSpaceRel[1000], StandDevSpaceRel[1000]; // ������� ����� �������� (�������.) � ��� �� ��������

		int MinFirstDigramNumber[1000], MaxFirstDigramNumber[1000]; // ����� ������� (1)
		double AverFirstDigramNumber[1000], StandDevFirstDigramNumber[1000]; // ������� ����� ������� (1) � ���

		int MinSecondDigramNumber[1000], MaxSecondDigramNumber[1000]; // ����� ������� (2)
		double AverSecondDigramNumber[1000], StandDevSecondDigramNumber[1000]; // ������� ����� ������� (2) � ���

		double MinCoincidenceIndex[1000], MaxCoincidenceIndex[1000]; // ����������� � ������������ ����� ������� ����������
		double AverCoincidenceIndex[1000], StandDevCoincidenceIndex[1000]; // ������� ������ ���������� � ���

		double MinConjugationIndex[1000], MaxConjugationIndex[1000]; // ����������� � ������������ ������ ����������
		double AverConjugationIndex[1000], StandDevConjugationIndex[1000]; // ������� ������ ���������� � ���

		double MinDistinguishIndex[1000], MaxDistinguishIndex[1000]; // ����������� � ������������ ������ ���������
		double AverDistinguishIndex[1000], StandDevDistinguishIndex[1000]; // ������� ������ ��������� � ���

		for (int i = 0; i < fragment_num; i++)
		{

			FragmentNumber[i] = 0;
			FullFragments[i] = 0;

			MinBigramNumber[i] = 2000;
			MaxBigramNumber[i] = 0;
			AverBigramNumber[i] = 0;
			StandDevBigramNumber[i] = 0;

			MinSymbolAlphabet[i] = 33;
			MaxSymbolAlphabet[i] = 0;
			AverSymbolAlphabet[i] = 0;
			StandDevSymbolAlphabet[i] = 0;

			MinSpaceNumber[i] = 1000000;
			MaxSpaceNumber[i] = 0;
			AverSpaceNumber[i] = 0;
			StandDevSpaceNumber[i] = 0;

			MinSpaceRel[i] = 1;
			MaxSpaceRel[i] = 0;
			AverSpaceRel[i] = 0;
			StandDevSpaceRel[i] = 0;

			MinFirstDigramNumber[i] = 2000;
			MaxFirstDigramNumber[i] = 0;
			AverFirstDigramNumber[i] = 0;
			StandDevFirstDigramNumber[i] = 0;

			MinSecondDigramNumber[i] = 2000;
			MaxSecondDigramNumber[i] = 0;
			AverSecondDigramNumber[i] = 0;
			StandDevSecondDigramNumber[i] = 0;

			MinCoincidenceIndex[i] = 1;
			MaxCoincidenceIndex[i] = 0;
			AverCoincidenceIndex[i] = 0;
			StandDevCoincidenceIndex[i] = 0;

			MinConjugationIndex[i] = 1;
			MaxConjugationIndex[i] = 0;
			AverConjugationIndex[i] = 0;
			StandDevConjugationIndex[i] = 0;

			MinDistinguishIndex[i] = 1;
			MaxDistinguishIndex[i] = 0;
			AverDistinguishIndex[i] = 0;
			StandDevDistinguishIndex[i] = 0;
		}

		// ��������� ���������� � ������ �����
		if (Steps == 0) // ������ ������: ���������� ����� = 0 => ������� ����� ���� ���������� = ����� �����
			for (int i = 0; i < fragment_num; i++)
				data[i].scale_point = data[i].symbol_num;
		// ������ ������: ���������� ����� = 1 => ��������� �������� = ������������ �����, ������ ��������� ������ ���� �����
		// ������ ������: ���������� = 0 => ��������� �������� = ������������ �����, ������ ��������� ������ ���� �����
		if ((Steps == 1) || (StepSize == 0))
			for (int i = 0; i < fragment_num; i++)
				data[i].scale_point = data[i].symbol_num;

		// ��������� ������
		// ������ ����, ��� ������
		if ((Steps != 1) && (StepSize != 0) && (Steps != 0))
		{

			for (int i = 0; i < fragment_num; i++)
				if (data[i].symbol_num + data[i].space_num <= StartSize)
					data[i].scale_point = StartSize;
			for (StartSize; StartSize <= EndSize; StartSize = StartSize + StepSize)
				for (int i = 0; i < fragment_num; i++)
					if ((data[i].symbol_num + data[i].space_num <= StartSize + StepSize) && (data[i].symbol_num + data[i].space_num > StartSize))
						data[i].scale_point = StartSize + StepSize;
		}

		// �������������� �������
		int TempMinScalePoint = 0;
		text_info TempData;
		bool Compare = true;

		do
		{
			Compare = true;
			for (int i = 0; i < fragment_num - 1; i++)
				if (data[i].scale_point > data[i + 1].scale_point)
				{
					TempData = data[i + 1];
					// ��������������
					data[i + 1] = data[i];
					data[i] = TempData;
					Compare = false;
				}
		} while (Compare == false);

		if ((Steps == 1) || (StepSize == 0)) // ������ � ������ ������
			Size[0] = StartSize;
		else // ���������
		{
			count = 1;
			Size[0] = data[0].scale_point;
			for (int i = 0; i < fragment_num; i++)
				if (Size[count - 1] != data[i].scale_point)
				{
					Size[count] = data[i].scale_point;
					count++;
				}
		}

		for (int j = 0; j < fragment_num; j++)
		{
			for (int i = 0; i < fragment_num; i++)
			{
				if (Size[j] == data[i].scale_point && data[i].scale_point != 0)
				{
					FragmentNumber[j]++;

					// ������������ ����� ��������: ����������, �����������, ������, ��� (����)
					if (data[i].symbol_alphabet == 31)
						FullFragments[j]++;
					// ����������
					if (data[i].symbol_alphabet < MinSymbolAlphabet[j])
						MinSymbolAlphabet[j] = double(data[i].symbol_alphabet);
					// �����������
					if (data[i].symbol_alphabet > MaxSymbolAlphabet[j])
						MaxSymbolAlphabet[j] = double(data[i].symbol_alphabet);
					// ������
					AverSymbolAlphabet[j] = AverSymbolAlphabet[j] + data[i].symbol_alphabet;

					// ���������� �������: �����������, ������������, �������
					// �����������
					if (data[i].bigrams_num < MinBigramNumber[j])
						MinBigramNumber[j] = double(data[i].bigrams_num);
					// ������������
					if (data[i].bigrams_num > MaxBigramNumber[j])
						MaxBigramNumber[j] = double(data[i].bigrams_num);
					// �������
					AverBigramNumber[j] = AverBigramNumber[j] + data[i].bigrams_num;

					// ���������� ��������
					// ����������
					if (data[i].space_num < MinSpaceNumber[j])
						MinSpaceNumber[j] = data[i].space_num;
					// �����������
					if (data[i].space_num > MaxSpaceNumber[j])
						MaxSpaceNumber[j] = data[i].space_num;
					// ������
					AverSpaceNumber[j] = AverSpaceNumber[j] + data[i].space_num;

					// ���������� �������� - �������������
					// ����������
					if (data[i].rel_space < MinSpaceRel[j])
						MinSpaceRel[j] = data[i].rel_space;
					// �����������
					if (data[i].rel_space > MaxSpaceRel[j])
						MaxSpaceRel[j] = data[i].rel_space;
					// ������
					AverSpaceRel[j] = AverSpaceRel[j] + data[i].rel_space;

					// ���������� ������� (1)
					// ����������
					if (data[i].digram_first_num < MinFirstDigramNumber[j])
						MinFirstDigramNumber[j] = data[i].digram_first_num;
					// �����������
					if (data[i].digram_first_num > MaxFirstDigramNumber[j])
						MaxFirstDigramNumber[j] = data[i].digram_first_num;
					// ������
					AverFirstDigramNumber[j] = AverFirstDigramNumber[j] + data[i].digram_first_num;

					// ���������� ������� (2)
					// ����������
					if (data[i].digram_second_num < MinSecondDigramNumber[j])
						MinSecondDigramNumber[j] = data[i].digram_second_num;
					// �����������
					if (data[i].digram_second_num > MaxSecondDigramNumber[j])
						MaxSecondDigramNumber[j] = data[i].digram_second_num;
					// ������
					AverSecondDigramNumber[j] = AverSecondDigramNumber[j] + data[i].digram_second_num;

					// ������ ����������
					// ����������
					if (data[i].coincidence_index < MinCoincidenceIndex[j])
						MinCoincidenceIndex[j] = data[i].coincidence_index;
					// �����������
					if (data[i].coincidence_index > MaxCoincidenceIndex[j])
						MaxCoincidenceIndex[j] = data[i].coincidence_index;
					// ������
					AverCoincidenceIndex[j] = AverCoincidenceIndex[j] + data[i].coincidence_index;

					// ������ ����������
					// ����������
					if (data[i].conjugation_index < MinConjugationIndex[j])
						MinConjugationIndex[j] = data[i].conjugation_index;
					// �����������
					if (data[i].conjugation_index > MaxConjugationIndex[j])
						MaxConjugationIndex[j] = data[i].conjugation_index;
					// ������
					AverConjugationIndex[j] = AverConjugationIndex[j] + data[i].conjugation_index;

					// ������ ���������
					// ����������
					if (data[i].distinguish_index < MinDistinguishIndex[j])
						MinDistinguishIndex[j] = data[i].distinguish_index;
					// �����������
					if (data[i].distinguish_index > MaxDistinguishIndex[j])
						MaxDistinguishIndex[j] = data[i].distinguish_index;
					// ������
					AverDistinguishIndex[j] = AverDistinguishIndex[j] + data[i].distinguish_index;
				}
			}

			// ������� �� ���������� � �����
			if (FragmentNumber[j] != 0)
			{
				AverSymbolAlphabet[j] = AverSymbolAlphabet[j] / FragmentNumber[j];
				AverBigramNumber[j] = AverBigramNumber[j] / FragmentNumber[j];
				AverSpaceNumber[j] = AverSpaceNumber[j] / FragmentNumber[j];
				AverSpaceRel[j] = AverSpaceRel[j] / FragmentNumber[j];
				AverFirstDigramNumber[j] = AverFirstDigramNumber[j] / FragmentNumber[j];
				AverSecondDigramNumber[j] = AverSecondDigramNumber[j] / FragmentNumber[j];
				AverCoincidenceIndex[j] = AverCoincidenceIndex[j] / FragmentNumber[j];
				AverConjugationIndex[j] = AverConjugationIndex[j] / FragmentNumber[j];
				AverDistinguishIndex[j] = AverDistinguishIndex[j] / FragmentNumber[j];

				// ��� �� ����������
				for (int i = 0; i < fragment_num; i++)
				{
					if (Size[j] == data[i].scale_point)
					{
						StandDevSymbolAlphabet[j] = StandDevSymbolAlphabet[j] + (data[i].symbol_alphabet - AverSymbolAlphabet[j])*(data[i].symbol_alphabet - AverSymbolAlphabet[j]);
						StandDevBigramNumber[j] = StandDevBigramNumber[j] + (data[i].bigrams_num - AverBigramNumber[j])*(data[i].bigrams_num - AverBigramNumber[j]);
						StandDevSpaceNumber[j] = StandDevSpaceNumber[j] + (data[i].space_num - AverSpaceNumber[j])*(data[i].space_num - AverSpaceNumber[j]);
						StandDevSpaceRel[j] = StandDevSpaceRel[j] + (data[i].rel_space - AverSpaceRel[j])*(data[i].rel_space - AverSpaceRel[j]);
						StandDevFirstDigramNumber[j] = StandDevFirstDigramNumber[j] + (data[i].digram_first_num - AverFirstDigramNumber[j])*(data[i].digram_first_num - AverFirstDigramNumber[j]);
						StandDevSecondDigramNumber[j] = StandDevSecondDigramNumber[j] + (data[i].digram_second_num - AverSecondDigramNumber[j])*(data[i].digram_second_num - AverSecondDigramNumber[j]);
						StandDevCoincidenceIndex[j] = StandDevCoincidenceIndex[j] + (data[i].coincidence_index - AverCoincidenceIndex[j])*(data[i].coincidence_index - AverCoincidenceIndex[j]);
						StandDevConjugationIndex[j] = StandDevConjugationIndex[j] + (data[i].conjugation_index - AverConjugationIndex[j])*(data[i].conjugation_index - AverConjugationIndex[j]);
						StandDevDistinguishIndex[j] = StandDevDistinguishIndex[j] + (data[i].distinguish_index - AverDistinguishIndex[j])*(data[i].distinguish_index - AverDistinguishIndex[j]);
					}
				}
				if (StandDevSymbolAlphabet[j] != 0)
					StandDevSymbolAlphabet[j] = sqrt(StandDevSymbolAlphabet[j] / FragmentNumber[j]);
				StandDevBigramNumber[j] = sqrt(StandDevBigramNumber[j] / FragmentNumber[j]);
				if (StandDevSpaceNumber[j] != 0)
					StandDevSpaceNumber[j] = sqrt(StandDevSpaceNumber[j] / FragmentNumber[j]);
				StandDevSpaceRel[j] = sqrt(StandDevSpaceRel[j] / FragmentNumber[j]);
				StandDevFirstDigramNumber[j] = sqrt(StandDevFirstDigramNumber[j] / FragmentNumber[j]);
				StandDevSecondDigramNumber[j] = sqrt(StandDevSecondDigramNumber[j] / FragmentNumber[j]);
				StandDevCoincidenceIndex[j] = sqrt(StandDevCoincidenceIndex[j] / FragmentNumber[j]);
				StandDevConjugationIndex[j] = StandDevConjugationIndex[j] / FragmentNumber[j];
				StandDevDistinguishIndex[j] = StandDevDistinguishIndex[j] / FragmentNumber[j];
			}
		}

		int TotalFullFragments = 0;
		for (int j = 0; j < fragment_num; j++)
		{
			TotalFullFragments = TotalFullFragments + FullFragments[j];
		}
		out << "L=" << language_type << "\t";
		out << "NA=" << cardinality << "\t";
		out << "T=" << text_type << "\t";
		out << "Text=" << fragment_num << "\t";
		if (error != 0)
			out << "Err=" << error;
		out << "\n" << "N\tK\tNA\t" <<
			"S ��\tS min\tS max\tS S.D.\t" <<
			"Z ��\tZ min\tZ max\tZ S.D.\t" <<
			"B ��\tB min\tB max\tB S.D.\t" <<
			"C ��\tC min\tC max\tC S.D.\t" <<
			"D ��\tD min\tD max\tD S.D.\t" <<
			"X cp\tX min\tX max\tX S.D.\n";
		// ����� �������� �������
		for (int j = 0; j < fragment_num; j++)
			if (FragmentNumber[j] != 0) // �����, ���� � ����� ����� ������� ���� ���� ��������
			{
				// ������������ ��������
				AverSymbolAlphabet[j] = AverSymbolAlphabet[j] / cardinality;
				MinSymbolAlphabet[j] = MinSymbolAlphabet[j] / cardinality;
				MaxSymbolAlphabet[j] = MaxSymbolAlphabet[j] / cardinality;
				StandDevSymbolAlphabet[j] = StandDevSymbolAlphabet[j] / cardinality;
				AverBigramNumber[j] = AverBigramNumber[j] / (cardinality*cardinality);
				MinBigramNumber[j] = MinBigramNumber[j] / (cardinality*cardinality);
				MaxBigramNumber[j] = MaxBigramNumber[j] / (cardinality*cardinality);
				StandDevBigramNumber[j] = StandDevBigramNumber[j] / (cardinality*cardinality);

				out << Size[j] << "\t" << FragmentNumber[j] << "\t" << FullFragments[j] << "\t";
				out.precision(4);
				out << fixed << AverSpaceRel[j] << "\t" << MinSpaceRel[j] << "\t" << MaxSpaceRel[j] << "\t" << fixed << StandDevSpaceRel[j] << "\t"
					<< fixed << AverSymbolAlphabet[j] << "\t" << MinSymbolAlphabet[j] << "\t" << MaxSymbolAlphabet[j] << "\t" << fixed << StandDevSymbolAlphabet[j] << "\t";
				out.precision(3);
				out << fixed << AverBigramNumber[j] << "\t" << MinBigramNumber[j] << "\t" << MaxBigramNumber[j] << "\t" << fixed << StandDevBigramNumber[j] << "\t";
				out.precision(4);
				out << fixed << AverConjugationIndex[j] << "\t" << MinConjugationIndex[j] << "\t" << MaxConjugationIndex[j] << "\t" << fixed << StandDevConjugationIndex[j] << "\t"
					<< fixed << AverDistinguishIndex[j] << "\t" << MinDistinguishIndex[j] << "\t" << MaxDistinguishIndex[j] << "\t" << fixed << StandDevDistinguishIndex[j] << "\t"
					<< fixed << AverCoincidenceIndex[j] << "\t" << MinCoincidenceIndex[j] << "\t" << MaxCoincidenceIndex[j] << "\t" << fixed << StandDevCoincidenceIndex[j] << "\n";
			}

		out.close();
		in.close();
		return 0;
	}
}
*////////////////////////////////////////////////////
//#include <time.h>

void main()
//������ (8):                    //������ ��������� � ���������� LIB.lib, ������������ ���� "C:\Users\kotov.NSTU\Desktop\LIB\LIB\LIB\stdafx.h"
//
//       int formS()             //����� ������ ��� ������� ��� Nf ��������� ����������, ���������� � ����� inT.txt
//       int formU()             //����� �������� ��� Nf ��������� ����������, ���������� � ����� inT.txt
//       int formB()             //����� ������� ��� Nf ��������� ����������, ���������� � ����� inT.txt
//       int UPO()               //����� ���������� ��������������
//       int MAP(int M)          //����� ������������� �� ������� �� ������ ��������� ������� ������� enB.txt.
//       int JAC(int M)          //����� ��������  ���������� �������������� �� ������ ��������� ������� ������� enB.txt.
//       int reduce()            //������ ��������� ���������� � ��������� ���������� �/��� �������� �� input.txt � inT.txt
//       int staR(int N,int M[]) //������ �������������� ��������� �����������.
{
	setlocale(LC_CTYPE, "Russian");
	int M[8];
	/*
    time_t BB,EE;
	//staT(0);
	//reduce();
	//staT(1);
	//formU();
	//formB();
	time(&BB);
	UPO();
	time(&EE);
	printf_s("%d\n",EE-BB);
	JAC(0);//JAC(1);JAC(10);
    time(&BB);
    printf_s("%d\n",BB-EE);
	DAT(0);
	time(&EE);
	printf_s("%d\n", EE - BB);
	MAP(0);
	time(&BB);
	printf_s("%d\n", BB - EE);
	MAP(2);
	DAT(2);
	JAC(6);
	MAP(7);
	M[0] = 1; M[1] = 2; M[2] = 3; M[3] = 4; M[4] = 5; M[5] = 6; M[6] = 7; M[7] = 8;
	staR(8, M);
	*/
	M[0] = 4; M[1] = 11; M[2] = 12;  M[3] = 13; M[4] = 14;
	staR(3, M);
	printf_s("������� ����� �������");
	_getch();
	
}