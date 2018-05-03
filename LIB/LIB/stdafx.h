// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // »сключите редко используемые компоненты из заголовков Windows


// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы
int formS();
int formU();
int formB();
int formW();
int UPO();
int MAP(int M);
int JAC(int M);
int DAT(int M);
int reduce();
int repeat(int NA);
int generateS(int NK);
int generateK(int NV, int R, char spaceZ, char MV[]);
int pereBOR(int N, int M[], int NA, char U[], char ZP[], char uJ[], char Zs);
int newU(int NA, char R[], char U[], char uJ[], char Zs);
int OPR(int M, int N, char R[]);
int staR(int N, int M[]);
int staT(int NinFile);
int normaT();
int schema(int NSH, int KTX, int NTX[], int RTA, int AF);
int frag(int NSH);