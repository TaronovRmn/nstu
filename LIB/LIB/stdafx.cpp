// stdafx.cpp: исходный файл, содержащий только стандартные включаемые модули
// LIB.pch будет предкомпилированным заголовком
// stdafx.obj будет содержать предварительно откомпилированные сведения о типе

#include "stdafx.h"

// TODO: Установите ссылки на любые требующиеся дополнительные заголовки в файле STDAFX.H
// , а не в данном файле
#define _CRT_RAND_S
#include <limits.h>

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


///////////////////////////////////
int formS()//Форма текста без пробела для Nf текстовых фрагментов, записанных в файле inT.txt
		   //
		   //Входные массивы: inT.txt
		   //                 Ititle.txt
		   //                 code.txt - только если Sp!=0 и T!=0 в Ititle.txt
		   //Выходной массив: inS.txt
		   //
{
	char s[500000];
	char c, spaceZ;
	int sNN;

	int L, NA, T, Sp, Zs, Nspace, Nf, Nu, Tu;

	int i, x, lns;
	int i4;

	FILE *f, *f1, *f2, *f3;

	fopen_s(&f, "inT.txt", "r");
	fopen_s(&f1, "inS.txt", "w");
	fopen_s(&f2, "Ititle.txt", "r");

	fscanf_s(f, "%d\n", &Nf, 1);//Переменная главного цикла
	fprintf(f1, "%d\n", Nf);
	fscanf_s(f2, "%d %d %d %d %d %c\n", &i, &L, &NA, &T, &Sp, &Zs, 1);//Тип языка и наличие пробела


	spaceZ = ' '; //Знак пробела

	if (Sp != 0 && T != 0)//Для всех текстов с T!=0 знак пробела берется из code.txt всегда из _1_ замены при любом Nu>0
						  //Если Nu==0 знак пробела обычный: spaceZ=' ';
	{
		fopen_s(&f3, "code.txt", "r");
		fscanf_s(f3, "%d %d\n", &Nu, &Tu, 1);//Количество замен и тип в code.txt
		if (Nu>0)
		{
			//Заголовок замены 
			while ((c = fgetc(f3)) == '\n');   //Пустые строки перед заголовком и первый подчерк
			fscanf_s(f3, "%d\n", &sNN, 1);   //Номер замены
			fscanf_s(f3, "%c\n", &c, 1);     //второй подчерк
			fscanf_s(f3, "%c\n", &spaceZ, 1);//Знак пробела
		}
		fclose(f3);
	}

	//
	//Главный цикл
	//

	for (i4 = 0; i4<Nf; i4++)
	{
		//Чтение очередного текстового фрагмента

		Nspace = 0;

		//Заголовок фрагмента

		while ((c = fgetc(f)) == '\n'); //Пустые строки перед заголовком и первый подчерк
		fscanf_s(f, "%d\n", &sNN, 1); //Номер фрагмента
		fscanf_s(f, "%c\n", &c, 1);   //второй подчерк

									  //Текст фрагмента с учетом пробела
		lns = 0; i = 0;
		while ((c = fgetc(f)) != '\n')if (lns<500000)
			if (Sp == 0) { s[i] = c; lns = lns + 1; i++; }
			else
				if (c != spaceZ) { s[i] = c; lns = lns + 1; i++; }
				else Nspace++;


				fprintf(f1, "_%d_\n", sNN);
				for (x = 0; x<lns; x++)fprintf(f1, "%c", s[x]);
				fprintf(f1, "\n");

	}

	fclose(f1);
	fclose(f);

	return 0;

}
///////////////////////////////////
///////////////////////////////////
int formU()//Форма униграмм для Nf текстовых фрагментов, записанных в файле inT.txt
		   //Структура формы (всего Nf форм):
		   //_№_  - заголовок, № соответствует номеру исходного фрагмента
		   //М Н знак пробела   - М - число знаков в тексте, не считая пробел; Н - число пробелов в тексте; пробел определяется "знаком пробела"
		   //А Б В ... - М знаков текста, упорядоченных по убыванию числа появления в тексте
		   //Р1 Р2 ... - М целых чисел, представляющих число появления соответствующих знаков в тексте: Р1>=Р2>=...
		   //
		   //Входные массивы: inT.txt
		   //                 Ititle.txt
		   //                 code.txt - только если Sp!=0 и T!=0 в Ititle.txt
		   //Выходной массив: inU
		   //
{
	char s[500000];
	char mas[256];//массив встречающихся знаков
	int fr[256];  //число  встречающихся знаков
	char c, spaceZ;
	int sNN;

	int L, NA, T, Sp, Zs, Nspace, Nf, Nu, Tu;

	int i, j, k, t, t1, p, z, x, lns;
	int i4;

	FILE *f, *f1, *f2, *f3;

	fopen_s(&f, "inT.txt", "r");
	fopen_s(&f1, "inU.txt", "w");
	fopen_s(&f2, "Ititle.txt", "r");

	fscanf_s(f, "%d\n", &Nf, 1);//Переменная главного цикла
	fprintf(f1, "%d\n", Nf);
	fscanf_s(f2, "%d %d %d %d %d %c\n", &i, &L, &NA, &T, &Sp, &Zs, 1);//Тип языка и наличие пробела


	spaceZ = ' '; //Знак пробела

	if (Sp != 0 && T != 0)//Для всех текстов с T!=0 знак пробела берется из code.txt всегда из _1_ замены при любом Nu>0
						  //Если Nu==0 знак пробела обычный: spaceZ=' ';
	{
		fopen_s(&f3, "code.txt", "r");
		fscanf_s(f3, "%d %d\n", &Nu, &Tu, 1);//Количество замен и тип в code.txt
		if (Nu>0)
		{
			//Заголовок замены 
			while ((c = fgetc(f3)) == '\n');   //Пустые строки перед заголовком и первый подчерк
			fscanf_s(f3, "%d\n", &sNN, 1);   //Номер замены
			fscanf_s(f3, "%c\n", &c, 1);     //второй подчерк
			fscanf_s(f3, "%c\n", &spaceZ, 1);//Знак пробела
		}
		fclose(f3);
	}

	//
	//Главный цикл
	//

	for (i4 = 0; i4<Nf; i4++)
	{
		//Чтение очередного текстового фрагмента

		Nspace = 0;

		//Заголовок фрагмента

		while ((c = fgetc(f)) == '\n'); //Пустые строки перед заголовком и первый подчерк
		fscanf_s(f, "%d\n", &sNN, 1); //Номер фрагмента
		fscanf_s(f, "%c\n", &c, 1);   //второй подчерк

									  //Текст фрагмента с учетом пробела
		lns = 0; i = 0;
		while ((c = fgetc(f)) != '\n')if (lns<500000)
			if (Sp == 0) { s[i] = c; lns = lns + 1; i++; }
			else
				if (c != spaceZ) { s[i] = c; lns = lns + 1; i++; }
				else Nspace++;

				i = 0; t = 0;
				for (x = 0; x<256; x++) { mas[x] = 0; fr[x] = 0; }
				for (i = 0; i<lns; i++)
				{
					for (x = 0; x<256; x++) { if (mas[x] != s[i])z = 1; else { z = 0; break; } }
					if (z == 1) {
						k = 0; for (j = 0; j<lns; j++)if (s[i] == s[j])k++;
						t1 = t + 1;
						mas[t] = s[i];
						fr[t] = k;
						t++;
					}
				}

				//упорядочение массива

				do
				{
					p = 0;
					for (x = 0; x<t1; x++)if (fr[x]<fr[x + 1]) { p = fr[x + 1]; fr[x + 1] = fr[x]; fr[x] = p; c = mas[x + 1]; mas[x + 1] = mas[x]; mas[x] = c; }
				} while (p != 0);

				fprintf(f1, "_%d_\n", sNN);

				fprintf(f1, "%d\t%d\t%c\n", t1, Nspace, spaceZ);
				for (x = 0; x<t1; x++)fprintf(f1, "%c\t", mas[x]);
				fprintf(f1, "\n");
				for (x = 0; x<t1; x++)fprintf(f1, "%d\t", fr[x]);
				fprintf(f1, "\n");

	}

	fclose(f1);
	fclose(f);

	return 0;

}
///////////////////////////////////
///////////////////////////////////
int formB()//Форма биграмм для Nf текстовых фрагментов, записанных в файле inT.txt
		   //Структура формы (всего Nf форм):
		   //_№_  - заголовок, № соответствует номеру исходного фрагмента
		   //М Н знак пробела   - М - число знаков в тексте, не считая пробел; Н - число пробелов в тексте; пробел определяется "знаком пробела"
		   //А Б В ... - М знаков текста, упорядоченных по убыванию числа появления в тексте
		   //Р1 Р2 ... - М строк М целых чисел, представляющих число появления соответствующих знаков в тексте: Р1>=Р2>=...
		   //......... - М строк в соответствии со знаковой упорядоченностью столбцов
		   //
		   //Входные массивы: inT.txt
		   //                 Ititle.txt
		   //                 code.txt - только если Sp!=0 и T!=0 в Ititle.txt
		   //Выходной массив: inB.txt
		   //
{
	char s[500000];
	char mas[256];//массив встречающихся знаков
	int fr[256];  //число  встречающихся знаков
	char c, spaceZ;
	int sNN;
	int masP[5000], frP[2000];
	int frRT[256], masRT[256], frLT[256], masLT[256], fs1[256], fs2[256], Inorm[256];

	int L, NA, T, Sp, Zs, Nspace, Nf, Nu, Tu;

	int e, g, i, j, k, t, t1, p, z, x, lns;
	int i4;

	FILE *f, *f1, *f2, *f3;

	fopen_s(&f, "inT.txt", "r");
	fopen_s(&f1, "inB.txt", "w");
	fopen_s(&f2, "Ititle.txt", "r");

	fscanf_s(f, "%d\n", &Nf, 1);//Переменная главного цикла
	fprintf(f1, "%d\n", Nf);
	fscanf_s(f2, "%d %d %d %d %d %c\n", &i, &L, &NA, &T, &Sp, &Zs, 1);//Тип языка и наличие пробела


	spaceZ = ' '; //Знак пробела

	if (Sp != 0 && T != 0)//Для всех текстов с T!=0 знак пробела берется из code.txt всегда из _1_ замены при любом Nu>0
						  //Если Nu==0 знак пробела обычный: spaceZ=' ';
	{
		fopen_s(&f3, "code.txt", "r");
		fscanf_s(f3, "%d %d\n", &Nu, &Tu, 1);//Количество замен и тип в code.txt
		if (Nu>0)
		{
			//Заголовок замены 
			while ((c = fgetc(f3)) == '\n');   //Пустые строки перед заголовком и первый подчерк
			fscanf_s(f3, "%d\n", &sNN, 1);   //Номер замены
			fscanf_s(f3, "%c\n", &c, 1);     //второй подчерк
			fscanf_s(f3, "%c\n", &spaceZ, 1);//Знак пробела
		}
		fclose(f3);
	}

	//
	//Главный цикл
	//

	for (i4 = 0; i4<Nf; i4++)
	{
		//Чтение очередного текстового фрагмента

		Nspace = 0;

		//Заголовок фрагмента

		while ((c = fgetc(f)) == '\n'); //Пустые строки перед заголовком и первый подчерк
		fscanf_s(f, "%d\n", &sNN, 1); //Номер фрагмента
		fscanf_s(f, "%c\n", &c, 1);   //второй подчерк

									  //Текст фрагмента с учетом пробела
		lns = 0; i = 0;
		while ((c = fgetc(f)) != '\n')if (lns<500000)
			if (Sp == 0) { s[i] = c; lns = lns + 1; i++; }
			else
				if (c != spaceZ) { s[i] = c; lns = lns + 1; i++; }
				else Nspace++;

				i = 0; t = 0;
				for (x = 0; x<256; x++) { mas[x] = 0; fr[x] = 0; }
				for (i = 0; i<lns; i++)
				{
					for (x = 0; x<256; x++) { if (mas[x] != s[i])z = 1; else { z = 0; break; } }
					if (z == 1) {
						k = 0; for (j = 0; j<lns; j++)if (s[i] == s[j])k++;
						t1 = t + 1;
						mas[t] = s[i];
						fr[t] = k;
						t++;
					}
				}

				//упорядочение массива

				do
				{
					p = 0;
					for (x = 0; x<t1; x++)if (fr[x]<fr[x + 1]) { p = fr[x + 1]; fr[x + 1] = fr[x]; fr[x] = p; c = mas[x + 1]; mas[x + 1] = mas[x]; mas[x] = c; }
				} while (p != 0);


				//частота пар

				t = 0; g = 0;
				for (x = 0; x<5000; x = x + 1)masP[x] = 0;
				for (x = 0; x<2000; x = x + 1)frP[x] = 0;
				for (i = 0; i<lns - 1; i++)//
				{
					for (x = 0; x <= 2000; x = x + 2) { if (masP[x] != s[i])z = 1; else if (masP[x + 1] != s[i + 1])z = 1; else { z = 0; break; } }
					if (z == 1)
					{
						k = 0; for (j = 0; j<lns - 1; j++) { if ((s[i] == s[j]) && (s[i + 1] == s[j + 1]))k++; }
						if (k>0)
						{
							masP[t] = s[i];
							masP[t + 1] = s[i + 1];
							frP[g] = k;
							g = g + 1;
							t = t + 2;
						}
					}
				}

				//
				//биграммы таблица
				//
				fprintf(f1, "_%d_\n", sNN);
				fprintf(f1, "%d\t%d\t%c\n", t1, Nspace, spaceZ);
				for (x = 0; x<t1; x++)fprintf(f1, "%c\t", mas[x]);

				for (x = 0; x<256; x++) { fs1[x] = 0; fs2[x] = 0; }

				for (k = 0; k<t1; k++)
				{
					i = 0;
					for (x = 0; x <= 255; x++) { frRT[x] = 0; masRT[x] = spaceZ; }
					for (x = 0, e = 0; x<t; x = x + 2, e++)if (masP[x] == mas[k]) { masRT[i] = masP[x + 1]; frRT[i] = frP[e]; fs1[k] = fs1[k] + frRT[i]; i++; }
					for (x = 0; x <= 255; x++) { frLT[x] = 0; masLT[x] = spaceZ; }
					for (j = 0; j<t1; j++)
						for (x = 0; x <= i; x++)if (masRT[x] == mas[j]) { masLT[j] = masRT[x]; frLT[j] = frRT[x]; fs2[j] = fs2[j] + frLT[j]; }

					fprintf(f1, "\n");
					for (x = 0; x<t1; x++)Inorm[x] = frLT[x];
					for (x = 0; x<t1; x++)fprintf(f1, "%d\t", Inorm[x]);

				}
				fprintf(f1, "\n");
	}

	fclose(f1);
	fclose(f);

	return 0;
}
///////////////////////////////////
///////////////////////////////////formW()
int formW()//Словарная форма ("мешок слов") для Nf текстовых фрагментов, записанных в файле inT.txt
		   //Структура формы (всего Nw >= Nf форм):
		   //_№_  - заголовок, № соответствует номеру исходного фрагмента
		   //W1 W2 L MF - W1 - слов ВСЕГО,  W2 - всего РАЗНЫХ слов, L - количество длин слов, MF - максимальная частота слова 
		   //             в форме    
		   //Далее идут L групп следующей структуры:
		   //len w sf mf
		   //слово частота слово частота .... (всего w пар)
		   //
		   //          len - длина слов группы, w - количество слов группы, sf - суммарная частота слов группы
		   //          mf  - максимальная частота слова в группе
		   //
		   //Ограничения: максимальная длина слова <= 40, более длинные слова обрезаются по 40
		   //             максимальное количество слов в группе <= 2500
		   //             сумма длин всех W2 слов формы <= 180 000
		   //ПРИ НАРУШЕНИИ ОГРАНИЧЕНИЙ 2-3 производится вывод промежуточных словарных форма с одним и тем же номером 
		   //             исходного фрагмента, Nw++
		   //             Nw - количество выведенных словарных форма, Nw >= Nf исходных фрагментов
		   //        
		   //Входные массивы: inT.txt
		   //                 Ititle.txt
		   //                 code.txt - только если Sp!=0 и T!=0 в Ititle.txt
		   //Выходной массив: inW.txt
		   //Рабочий массив:  tmp.txt
		   //
		   //                 return 0 - все в порядке (при соблюдении ограничений)
		   //                 return 1 - при T != 0  Sp =  (пробел не определен)
		   //
{
	char c, spaceZ, MASpace[1001];
	int sNN, i4;
	int L, NA, T, Sp, Zs, Nf, Nu, Tu, Nw, LS;

	int countTexts = 0;
	char currentWord[40];
	char Words[180000];
	int i, j, t;
	int DL, LWA[40][5001];
	int countWords, countUniWords, maxLength;
	int z, c1, c2, c3, p, length;
	int itSt, x, sumFreq, MF;

	FILE *f, *f1, *f2, *f3, *f4;

	fopen_s(&f, "inT.txt", "r");
	fopen_s(&f1, "tmp.txt", "w");
	fopen_s(&f2, "Ititle.txt", "r");

	fscanf_s(f, "%d", &Nf, 1);   //Переменная главного цикла
	while ((c = fgetc(f)) != '\n');//Пропуск возможной дополнительной информации

	fscanf_s(f2, "%d %d %d %d %d %c\n", &i, &L, &NA, &T, &Sp, &Zs, 1);//Тип языка и наличие пробела

	fclose(f2);

	spaceZ = ' '; //Знак пробела
	for (i = 0; i<1000; i++)MASpace[i] = spaceZ;

	if (Sp != 0 && T != 0)//Для всех текстов с T!=0 и Sp!=0 знак пробела берется из code.txt
						  //Если Nu < количества фрагментов, то для остальных знак пробела обычный: spaceZ=' ';
						  //Если Nu==0 знак пробела обычный: spaceZ=' ';
	{
		fopen_s(&f3, "code.txt", "r");
		fscanf_s(f3, "%d %d\n", &Nu, &Tu, 1);//Количество замен и тип в code.txt
		if (Nu>0)
		{
			for (i = 0; i<Nu; i++)
			{
				//Заголовок замены 
				while ((c = fgetc(f3)) == '\n');   //Пустые строки перед заголовком и первый подчерк
				fscanf_s(f3, "%d\n", &sNN, 1);   //Номер замены
				fscanf_s(f3, "%c\n", &c, 1);     //второй подчерк
				fscanf_s(f3, "%c\n", &MASpace[i], 1);//Знак пробела
			}
		}
		fclose(f3);
	}

	if (T != 0 && Sp == 0)return 1; //Пробел не определен

	Nw = 0;
	//
	//Главный цикл
	//
	for (i4 = 0; i4<Nf; i4++)
	{
		//Чтение очередного текстового фрагмента


		for (j = 0; j<180000; j++)Words[j] = '\0';
		for (j = 0; j<40; j++)for (x = 0; x<5001; x++)LWA[j][x] = 0;

		spaceZ = MASpace[i4];

		//Заголовок фрагмента

		while ((c = fgetc(f)) == '\n'); //Пустые строки перед заголовком и первый подчерк
		fscanf_s(f, "%d\n", &sNN, 1); //Номер фрагмента
		fscanf_s(f, "%c\n", &c, 1);   //второй подчерк

									  //Текст фрагмента с учетом пробела
		countWords = 0; countUniWords = 0; maxLength = 0; DL = 0; t = 0; z = 0;

		while (t == 0)
		{
			i = 0; while ((c = fgetc(f)) != spaceZ) { if (c != '\n') { if (i<40) { currentWord[i] = c; i++; } } else { t = 1; break; } }

			length = i;
			if (i != 0)countWords++;

		BEG:

			c2 = 0;
			if (maxLength < length) maxLength = length;

			p = 0; c1 = 0; c3 = 0;
			c1 = length - 1;
			if (c1 >= 0 && LWA[c1][0]<2500 && z + length <= 180000)
			{
				if (LWA[c1][0] == 0)
				{
					DL++; LWA[c1][0] = 1; LWA[c1][1] = z; LWA[c1][2] = 1;
					for (j = 0; j<length; j++)Words[z + j] = currentWord[j];
					countUniWords++;
					z = z + length;
				}
				else
				{
					c2 = 2 * LWA[c1][0] + 1; p = 1; c3 = 0;
					for (itSt = 1; itSt<c2; itSt = itSt + 2)
					{
						for (int ii = 0; ii < length; ii++)
						{
							if (Words[LWA[c1][itSt] + ii] != currentWord[ii]) { c3 = 1; break; }
						}
						if (c3 == 0) { LWA[c1][itSt + 1]++; c3 = itSt; break; }
						else c3 = 0;
					}
				}
				if (p == 1 && c3 == 0)
				{
					c2 = 2 * LWA[c1][0] + 1; LWA[c1][0]++; LWA[c1][c2] = z; LWA[c1][c2 + 1] = 1;
					for (j = 0; j<length; j++)Words[z + j] = currentWord[j];
					countUniWords++;
					z = z + length;
				}
			}
			else
				if (c1 >= 0 && t == 0) {
					//////////////////////////////////////////////////////////////////
					//Промежуточный вывод
					Nw++;
					LS = length;
					for (length = maxLength; length > 0; length--)if (LWA[length - 1][0] != 0)
					{
						c1 = length - 1; c2 = 2 * LWA[c1][0] + 1; MF = 0;
						for (j = 2; j<c2; j = j + 2)if (LWA[c1][j] > MF) MF = LWA[c1][j];
					}

					fprintf(f1, "_%d_\n", sNN);
					fprintf(f1, "%d %d %d %d\n", countWords, countUniWords, DL, MF);

					int countThisLen, maxFreq;
					for (length = maxLength; length > 0; length--)if (LWA[length - 1][0] != 0)
					{
						maxFreq = 0; c1 = 0; sumFreq = 0; sumFreq = 0; c1 = length - 1;
						countThisLen = LWA[c1][0]; c2 = 2 * LWA[c1][0] + 1;
						for (j = 2; j<c2; j = j + 2) { sumFreq = sumFreq + LWA[c1][j]; if (LWA[c1][j] > maxFreq) maxFreq = LWA[c1][j]; }

						if (countThisLen != 0)
						{
							fprintf(f1, "%d %d %d %d\n", length, countThisLen, sumFreq, maxFreq);

							for (j = 1; j<c2; j = j + 2)
							{
								c3 = LWA[c1][j];
								for (x = 0; x<length; x++)fprintf(f1, "%c", Words[c3 + x]);
								fprintf(f1, " %d ", LWA[c1][j + 1]);
							}
							fprintf(f1, "\n");
						}
					}
					//
					for (j = 0; j<180000; j++)Words[j] = '\0';
					for (j = 0; j<40; j++)for (x = 0; x<5001; x++)LWA[j][x] = 0;

					length = LS;
					countWords = 1; countUniWords = 0; maxLength = 0; DL = 0;  z = 0;
					goto BEG;
				}
			//////////////////////////////////////////////////////////////////
		}

		//Заключительный вывод
		Nw++;
		for (length = maxLength; length > 0; length--)if (LWA[length - 1][0] != 0)
		{
			c1 = length - 1; c2 = 2 * LWA[c1][0] + 1; MF = 0;
			for (j = 2; j<c2; j = j + 2)if (LWA[c1][j] > MF) MF = LWA[c1][j];
		}

		fprintf(f1, "_%d_\n", sNN);
		fprintf(f1, "%d %d %d %d\n", countWords, countUniWords, DL, MF);

		int countThisLen, maxFreq;
		for (length = maxLength; length > 0; length--)if (LWA[length - 1][0] != 0)
		{
			maxFreq = 0; c1 = 0; sumFreq = 0; sumFreq = 0; c1 = length - 1;
			countThisLen = LWA[c1][0]; c2 = 2 * LWA[c1][0] + 1;
			for (j = 2; j<c2; j = j + 2) { sumFreq = sumFreq + LWA[c1][j]; if (LWA[c1][j] > maxFreq) maxFreq = LWA[c1][j]; }

			if (countThisLen != 0)
			{
				fprintf(f1, "%d %d %d %d\n", length, countThisLen, sumFreq, maxFreq);

				for (j = 1; j<c2; j = j + 2)
				{
					c3 = LWA[c1][j];
					for (x = 0; x<length; x++)fprintf(f1, "%c", Words[c3 + x]);
					fprintf(f1, " %d ", LWA[c1][j + 1]);
				}
				fprintf(f1, "\n");
			}
		}
	}

	fclose(f1);
	fclose(f);

	fopen_s(&f1, "inW.txt", "w");
	fopen_s(&f4, "tmp.txt", "r");
	fprintf(f1, "%d\n", Nw);
	while ((c = fgetc(f4)) != EOF)fprintf(f1, "%c", c);
	fclose(f4);
	fclose(f1);

	fopen_s(&f4, "tmp.txt", "w");
	c = ' '; fprintf(f4, "%c", c);
	fclose(f4);

	return 0;

}
///////////////////////////////////

///////////////////////////////////
int UPO()//Метод частотного упорядочивания    Переносит решение из формы inU в дерево решений ouR
		 //                                            Начальным решением может быть только корневая вершина (0),
		 //                                            поэтому формальных переменных нет
		 //                                            Работает для всех номеров языков и мощностей алфавита, в т.ч. L=NA=0
		 //                                            При NA=0 используется число знаков формы Na и только если Na=0
		 //                                            решение будет "пустым" (------   -SAB), даже если отмечен некоторый
		 //                                            знак пробела. Если NA!=0 и Na>NA, то Na=NA - лишние знаки из решения 
		 //                                            удаляются
		 //Входные массивы: inU.txt
		 //                 Ititle.txt
		 //                 ouR.txt
		 //Выходной массив: ouR.txt
		 //
{
	char mas[256];
	char c;
	int sNN, sNr;

	int L, NA, T, Sp, Zs, Nf, Na, NAt, Nfu, Nu, M;

	int i;
	int i4;

	FILE *f, *f1, *f2, *f3;

	fopen_s(&f, "inU.txt", "r");
	fopen_s(&f1, "ouR.txt", "r");
	fopen_s(&f2, "Ititle.txt", "r");
	fopen_s(&f3, "tmp.txt", "w");

	fscanf_s(f, "%d\n", &Nf, 1);//Переменная главного цикла
	fscanf_s(f1, "%d %d\n", &Nfu, &Nu, 1);


	fprintf(f3, "%d %d\n", Nf, Nu + 1);
	fscanf_s(f2, "%d %d %d %d %d %c\n", &i, &L, &NAt, &T, &Sp, &Zs, 1);//Тип языка и наличие пробела
	fclose(f2);

	//
	//Главный цикл
	//
	M = 0; NA = NAt;
	for (i4 = 0; i4<Nf; i4++)
	{
		//Чтение очередного текстового фрагмента

		//Заголовок фрагмента

		while ((c = fgetc(f)) == '\n'); //Пустые строки перед заголовком и первый подчерк
		fscanf_s(f, "%d\n", &sNN, 1); //Номер фрагмента
		fscanf_s(f, "%c\n", &c, 1);   //второй подчерк

									  //Текст фрагмента

		for (i = 0; i<NA; i++)mas[i] = Zs;

		fscanf_s(f, "%d", &Na, 1);//Число знаков

		while ((c = fgetc(f)) != '\n');
		i = 0;
		while (i<Na)
			while ((c = fgetc(f)) != '\t') { mas[i] = c; i++; }
		while ((c = fgetc(f)) != '\n');
		for (i = 0; i<Na; i++) fscanf_s(f, "%d ", &L, 1);


		//Подготовка к записи решения
		if (NA != 0 && Na>NA)Na = NA;
		if (NA == 0)NA = Na;

		fprintf(f3, "_%d_\n", sNN);
		//1. Копирование предыдущих решений

		//Заголовок фрагмента ouR
		while ((c = fgetc(f1)) == '\n'); //Пустые строки перед заголовком и первый подчерк
		fscanf_s(f1, "%d\n", &sNr, 1); //Номер фрагмента
		fscanf_s(f1, "%c\n", &c, 1);   //второй подчерк
									   //Существующие решения
		i = 0;
		while (i<Nu) { while ((c = fgetc(f1)) != '\n')fprintf(f3, "%c", c); fprintf(f3, "\n"); i++; }

		//2.  Запись нового решения
		for (i = 0; i<NA; i++)fprintf(f3, "%c", mas[i]);
		c = ' '; if (Na == 0)c = Zs;
		fprintf(f3, "\t%d\t%d\t%c[UPO]\n", Nu + 1, M, c);

	}

	fclose(f3);
	fclose(f1);
	fclose(f);

	fopen_s(&f1, "ouR.txt", "w");
	fopen_s(&f3, "tmp.txt", "r");
	while ((c = fgetc(f3)) != EOF)fprintf(f1, "%c", c);
	fclose(f3);
	fclose(f1);

	fopen_s(&f3, "tmp.txt", "w");
	c = ' '; fprintf(f1, "%c", c);
	fclose(f3);

	return 0;

}
///////////////////////////////////

///////////////////////////////////
int MAP(int M) //Метод аппроксимации по Пирсону на основе эталонной таблицы биграмм enB.txt.
			   //                               Исходная информация должна быть представленая в форме Nf таблиц биграмм
			   //                               в файле inB.txt, симметрично упорядоченных по частоте появления знаков в тексте.
			   //                               Максимальное количество знаков 1 < NA <= 50, ограничений для Nf нет, Nf > 0.
			   //                               Номер языка L > 0. Упорядочение начального решения осуществляется по решению M
			   //                               из файла ouR, в котором уже есть Nu решений. 
			   //                               Если M <= 0, то применяется исходное упорядочение. Если M > Nu, то М=Nu.
			   //                               Если множества знаков решения M из ouR и знаков текущей таблицы биграмм различаются,
			   //                               то формируется пустое решение из одного замещающего знака Zs.
			   //Входные массивы: inB.txt
			   //                 Ititle.txt
			   //                 ouR.txt
			   //                 enB.txt
			   //Выходной массив: ouR.txt
			   //Рабочий массив:  tmp.txt
			   //
			   //return 0:   все в порядке
			   //return 1:   NA<2 или NE != NA  Ошибочный эталон, NE - число знаков эталона
			   //
{
	int Nf, Nfu, Nu, L, NAt, T, Sp;
	char c, Zs;
	int sNN, Na, NaC, NaP, Mn;

	char eJ[50], mJ[50], mas[50], xJ[50];//массив встречающихся символов <= 140

	int WTB[50][50], DG[50], tTB[50][50], tG[50];
	double FTB[50][50], fTB[50][50], fTB2[50][50];
	double SM1[50][50], SM2[50][50], R[50][50];
	double SSF[50], SSf[50], SCF[50], SCf[50];
	int IR[50][50], SA[50];

	int De, Dt, st;

	int i = 0, k = 1, j = 0, t = 0, p, x = 0, X = 0, X1 = 0, e = 0, lns = 0, lnt = 0, m = 0;
	int g1 = 0, g3 = 0, i4;
	double w, w1, w5;
	double eps;
	double DD1, DD2;

	FILE *f, *f1, *f2, *f3, *f4;

	fopen_s(&f, "inB.txt", "r");
	fopen_s(&f1, "ouR.txt", "r");
	fopen_s(&f2, "Ititle.txt", "r");
	fopen_s(&f3, "enB.txt", "r");
	fopen_s(&f4, "tmp.txt", "w");

	fscanf_s(f, "%d\n", &Nf, 1);          //Количество фрагментов. Переменная главного цикла i4
	fscanf_s(f1, "%d %d\n", &Nfu, &Nu, 1); //Количество решений


	fprintf(f4, "%d %d\n", Nf, Nu + 1);
	fscanf_s(f2, "%d %d %d %d %d %c\n", &i, &L, &NAt, &T, &Sp, &Zs, 1);//Тип языка, наличие пробела, замещающий знак Zs
	fclose(f2);


	eps = 0.001;          //Погрешность сравнения
						  //Начальная очистка массивов
	for (i = 0; i<50; i++)DG[i] = tG[i] = SA[i] = 0;
	for (i = 0; i<50; i++)for (j = 0; j<50; j++)
	{
		WTB[i][j] = tTB[i][j] = IR[i][j] = 0; fTB[i][j] = fTB2[i][j] = SM1[i][j] = SM2[i][j] = R[i][j] = 0.0;
	}

	//
	//ЭТАЛОН: ввод (симметрично упорядоченный по частоте знаков)
	//
	fscanf_s(f3, "%d", &Na, 1);    //Число знаков эталона

	if (NAt<2)  return 1;        //ERROR 1 Ошибочный эталон
	if (Na != NAt)return 1;        //ERROR 1 Ошибочный эталон

	while ((c = fgetc(f3)) != '\n'); //Знаки эталона
	i = 0; while ((c = fgetc(f3)) != '\n') { if (c != '\t'&& i<Na) { eJ[i] = c; i++; } }

	//Значения эталона
	for (j = 0; j<Na; j++)for (i = 0; i<Na; i++)
	{
		fscanf_s(f3, "%d", &WTB[j][i], 1); if (i == j) { DG[j] = WTB[j][i]; WTB[j][i] = 0; }
	}//TB, диаг=0

	 //
	 //ЭТАЛОН: нормировка
	 //
	w = 0.0; for (i = 0; i<NAt; i++)for (j = 0; j<31; j++)w = w + float(WTB[i][j]);
	De = 0;  for (i = 0; i<NAt; i++)De = De + DG[i];     w = w + float(De);

	for (i = 0; i<NAt; i++)for (j = 0; j<NAt; j++) FTB[i][j] = float(WTB[i][j]) / w;  //Нормировка

																					  //Корректировка номера начального решения
	Mn = M;
	if (Mn<0) Mn = 0;
	if (Mn>Nu)Mn = Nu;


	//
	//Главный цикл
	//


	for (i4 = 0; i4<Nf; i4++)
	{
		//Чтение очередной таблицы биграмм (симметрично упорядоченной по частоте появления знаков)

		NaP = 0; //Флаг пустого решения

				 //Заголовок фрагмента

		while ((c = fgetc(f)) == '\n'); //Пустые строки перед заголовком и первый подчерк
		fscanf_s(f, "%d\n", &sNN, 1); //Номер фрагмента
		fscanf_s(f, "%c\n", &c, 1);   //второй подчерк

									  //Заголовок локальной таблицы биграмм

		for (i = 0; i<NAt; i++) { mJ[i] = Zs; tG[i] = 0; }
		for (j = 0; j<NAt; j++)for (i = 0; i<NAt; i++) { tTB[j][i] = 0; fTB[j][i] = 0.0; } //Подготовка mJ и поля NAt x NAt

		fscanf_s(f, "%d", &Na, 1);             //Число знаков локальной таблицы биграмм

		NaC = 0; if (Na>NAt) { NaC = Na; Na = NAt; }  //Коррекция числа знаков, если их больше NAt.

		while ((c = fgetc(f)) != '\n');          //Знаки локальной таблицы биграмм
		i = 0; while ((c = fgetc(f)) != '\n') { if (c != '\t' && i<Na) { mJ[i] = c; i++; } }

		//Значения локальной Таблицы биграмм tTB с учетом возможной коррекции NaC
		for (j = 0; j<Na; j++) {
			for (i = 0; i<Na; i++)
			{
				fscanf_s(f, "%d", &tTB[j][i], 1); if (i == j) { tG[j] = tTB[j][i]; tTB[j][i] = 0; }
			} if (NaC>0)while ((c = fgetc(f)) != '\n');
		}//TB, диаг=0
		if (NaC>0)for (j = Na; j<NaC; j++)while ((c = fgetc(f)) != '\n'); else while ((c = fgetc(f)) != '\n');


		//
		//Переупорядочение таблицы биграмм tTB в соответствии с заданным начальным решением
		//
		//Чтение начального решения  M из (&f1,"ouR.txt","r") и копирование решений в  (&f4,"tmp.txt","w")
		if (Nu != 0)
		{
			//(&f1,"ouR.txt","r")
			//Заголовок фрагмента ouR
			while ((c = fgetc(f1)) == '\n'); //Пустые строки перед заголовком и первый подчерк
			fscanf_s(f1, "%d\n", &sNN, 1); //Номер фрагмента
			fscanf_s(f1, "%c\n", &c, 1);   //второй подчерк
			fprintf(f4, "_%d_\n", sNN);
			if (Mn != 0)
			{
				//Пропуск предыдущих решений
				for (i = 0; i<Mn - 1; i++) { while ((c = fgetc(f1)) != '\n')fprintf(f4, "%c", c); fprintf(f4, "\n"); }
				//Начальное решение NAt знаков.  
				i = 0;  while (i<NAt) { c = fgetc(f1); xJ[i] = c; i++; fprintf(f4, "%c", c); }
				while ((c = fgetc(f1)) != '\n')fprintf(f4, "%c", c); fprintf(f4, "\n");
			}
			//Пропуск оставшихся решений
			for (i = Mn; i<Nu; i++) { while ((c = fgetc(f1)) != '\n')fprintf(f4, "%c", c); fprintf(f4, "\n"); }
		}
		if (Mn != 0)
		{
			//Проверка решений на совпадение множеств знаков
			j = 0; for (i = 0; i<NAt; i++)for (x = 0; x<NAt; x++)if (xJ[i] != Zs && xJ[i] == mJ[x])j++;
			if (j != Na) { for (i = 0; i<NAt; i++)mJ[i] = Zs; NaP = 1; goto NEN; } //Пустое решение
																				   //Переупорядочивание локальной таблицы в соответствии с заданным начальным решением
			for (i = 0; i<NAt; i++)for (x = 0; x<NAt; x++) { if (xJ[i] != Zs && xJ[i] == mJ[x])for (j = 0; j<NAt; j++)fTB[j][i] = float(tTB[j][x]); }
			for (i = 0; i<NAt; i++)for (x = 0; x<NAt; x++) { if (xJ[i] != Zs && xJ[i] == mJ[x])for (j = 0; j<NAt; j++)tTB[i][j] = int(fTB[x][j]); }
			for (i = 0; i<NAt; i++)mJ[i] = xJ[i];
		}

		//
		// Метод АППРОКСИМАЦИИ 
		//***************************************************
		// Частотная нормировка
		//
		Dt = 0;
		for (i = 0; i<NAt; i++)Dt = Dt + tG[i];

		st = 0;

		for (i = 0; i<NAt; i++)mas[i] = mJ[i];

		w1 = 0.0;
		for (i = 0; i<NAt; i++)for (j = 0; j<NAt; j++)w1 = w1 + float(tTB[i][j]);  w1 = w1 + float(Dt);

		for (i = 0; i<NAt; i++)for (j = 0; j<NAt; j++)fTB[i][j] = float(tTB[i][j]) / w1;

		w5 = 0; k = NAt;
		for (i = 0; i<k; i++)
			for (j = 0; j<k; j++)w5 = w5 + fabs(FTB[i][j] - fTB[i][j]);

		w = w5;

		i = 0; p = 0; j = 1;

		DD1 = 0.0; k = NAt;
		for (i = 0; i<k; i++)
			for (j = 0; j<k; j++)DD1 = DD1 + fabs(FTB[i][j] - fTB[i][j]);


	CHOBA:

		for (j = 0; j<NAt; j++)SSF[j] = SCF[j] = SSf[j] = SCf[j] = 0;

		for (j = 0; j<NAt; j++)for (i = 0; i<NAt; i++)
		{
			SM1[j][i] = SM2[j][i] = 0;
			SSF[j] = SSF[j] + FTB[j][i]; SCF[j] = SCF[j] + FTB[i][j];
			SSf[j] = SSf[j] + fTB[j][i]; SCf[j] = SCf[j] + fTB[i][j];
		}

		for (p = 0; p<NAt; p++)
			for (j = 0; j<NAt; j++)
			{
				for (i = 0; i<NAt; i++)
				{
					if (FTB[j][i] + fTB[p][i] != 0)SM1[p][j] = SM1[p][j] + (FTB[j][i] - fTB[p][i])*(FTB[j][i] - fTB[p][i]) / (FTB[j][i] + fTB[p][i]);
					if (FTB[i][j] + fTB[i][p] != 0)SM2[p][j] = SM2[p][j] + (FTB[i][j] - fTB[i][p])*(FTB[i][j] - fTB[i][p]) / (FTB[i][j] + fTB[i][p]);
				}
				R[p][j] = (1 - SM1[p][j] / (SSF[j] + SSf[p])) + (1 - SM2[p][j] / (SCF[j] + SCf[p]));
			}

		//Сортировка
		for (j = 0; j<NAt; j++)
		{
			p = 1; for (i = 0; i<NAt; i++)IR[j][i] = i;
			while (p == 1)
			{
				p = 0; for (i = 1; i<NAt; i++)
					if (R[j][i]>R[j][i - 1] + eps)
					{
						w1 = R[j][i - 1]; R[j][i - 1] = R[j][i]; R[j][i] = w1; k = IR[j][i - 1]; IR[j][i - 1] = IR[j][i]; IR[j][i] = k; p = 1;
					}
			}
		}
		//Коллизии
		for (i = 0; i<NAt; i++)SA[i] = 0;

		p = 1;
		while (p>0)
		{
			p = 0;
			for (j = 0; j<NAt; j++)
			{
				m = j; k = IR[m][SA[m]];
				for (i = 0; i<NAt; i++)
					if (k == IR[i][SA[i]] && m != i)
					{
						p = 1; if (R[m][SA[m]]<R[i][SA[i]] - eps) { SA[m] = SA[m] + 1; m = i; }
						else SA[i] = SA[i] + 1;
					}
			}
		}

		//ПЕРЕСТАНОВКА
		m = 0;
		for (j = 0; j<NAt; j++) { k = IR[j][SA[j]]; mJ[k] = mas[j]; for (i = 0; i<NAt; i++)fTB2[k][i] = fTB[j][i]; if (k != j)m++; }
		for (j = 0; j<NAt; j++) { k = IR[j][SA[j]]; for (i = 0; i<NAt; i++)fTB[i][k] = fTB2[i][j]; }

		DD2 = 0.0; k = NAt;
		for (i = 0; i<k; i++)
			for (j = 0; j<k; j++)DD2 = DD2 + fabs(FTB[i][j] - fTB[i][j]);

		if (DD1 - DD2>-0.2 && st<20 && m != 0) { DD1 = DD2; for (j = 0; j<NAt; j++)mas[j] = mJ[j]; st++; goto CHOBA; }

		//Шаг назад
		for (j = 0; j<NAt; j++)mJ[j] = mas[j];



	NEN:
		//Вывод локального решения
		if (Nu == 0)fprintf(f4, "_%d_\n", sNN);
		//2.  Запись нового решения
		for (i = 0; i<NAt; i++)fprintf(f4, "%c", mJ[i]);
		c = ' '; if (NaP == 1)c = Zs; else if (Mn>0) c = '+';
		fprintf(f4, "\t%d\t%d\t%c[MAP]\n", Nu + 1, Mn, c);

	}

	//
	//выход 
	//
	fclose(f4);
	fclose(f1);
	fclose(f);

	fopen_s(&f1, "ouR.txt", "w");
	fopen_s(&f4, "tmp.txt", "r");
	while ((c = fgetc(f4)) != EOF)fprintf(f1, "%c", c);
	fclose(f4);
	fclose(f1);

	fopen_s(&f4, "tmp.txt", "w");
	c = ' '; fprintf(f4, "%c", c);
	fclose(f4);

	return 0;

}
///////////////////////////////////
///////////////////////////////////
int JAC(int M) //Метод Якобсена  двумерного упорядочивания на основе эталонной таблицы биграмм enB.txt.
			   //                               Исходная информация должна быть представленая в форме Nf таблиц биграмм
			   //                               в файле inB.txt, симметрично упорядоченных по частоте появления знаков в тексте.
			   //                               Максимальное количество знаков 1 < NA <=140, ограничений для Nf нет, Nf > 0.
			   //                               Номер языка L > 0. Упорядочение начального решения осуществляется по решению M
			   //                               из файла ouR, в котором уже есть Nu решений. 
			   //                               Если M <= 0, то применяется исходное упорядочение. Если M > Nu, то М=Nu.
			   //                               Если множества знаков решения M из ouR и знаков текущей таблицы биграмм различаются,
			   //                               то формируется пустое решение из одного замещающего знака Zs.
			   //Входные массивы: inB.txt
			   //                 Ititle.txt
			   //                 ouR.txt
			   //                 enB.txt
			   //Выходной массив: ouR.txt
			   //Рабочий массив:  tmp.txt
			   //
			   //return 0:   все в порядке
			   //return 1:   NA<2 или NE != NA  Ошибочный эталон, NE - число знаков эталона
			   //
{
	int Nf, Nfu, Nu, L, NAt, T, Sp;
	char c, Zs, ig;
	int sNN, Na, NaC, NaP, Mn;

	char eJ[140], mJ[140], xJ[140];//массив встречающихся символов <= 140

	int WTB[140][140], DG[140], tTB[140][140], tG[140];
	double FTB[140][140], fTB[140][140];

	int De, Dt;

	int i = 0, k = 1, j = 0, t = 0, p, x = 0, X = 0, X1 = 0, e = 0, lns = 0, lnt = 0, m = 0;
	int g1 = 0, g3 = 0, i4;
	double w, w1, w2, w3, w4, w6, w7, w8, w9, w10;
	double eps;

	FILE *f, *f1, *f2, *f3, *f4;

	fopen_s(&f, "inB.txt", "r");
	fopen_s(&f1, "ouR.txt", "r");
	fopen_s(&f2, "Ititle.txt", "r");
	fopen_s(&f3, "enB.txt", "r");
	fopen_s(&f4, "tmp.txt", "w");

	fscanf_s(f, "%d\n", &Nf, 1);          //Количество фрагментов. Переменная главного цикла i4
	fscanf_s(f1, "%d %d\n", &Nfu, &Nu, 1); //Количество решений


	fprintf(f4, "%d %d\n", Nf, Nu + 1);
	fscanf_s(f2, "%d %d %d %d %d %c\n", &i, &L, &NAt, &T, &Sp, &Zs, 1);//Тип языка, наличие пробела, замещающий знак Zs
	fclose(f2);


	eps = 0.00000001;          //Погрешность сравнения
							   //Начальная очистка массивов
	for (i = 0; i<140; i++)DG[i] = tG[i] = 0; for (i = 0; i<140; i++)for (j = 0; j<140; j++) { WTB[i][j] = 0; tTB[i][j] = 0; fTB[i][j] = 0; }

	//
	//ЭТАЛОН: ввод (симметрично упорядоченный по частоте знаков)
	//
	fscanf_s(f3, "%d", &Na, 1);    //Число знаков эталона

	if (NAt<2)  return 1;        //ERROR 1 Ошибочный эталон
	if (Na != NAt)return 1;        //ERROR 1 Ошибочный эталон

	while ((c = fgetc(f3)) != '\n'); //Знаки эталона
	i = 0; while ((c = fgetc(f3)) != '\n') { if (c != '\t'&& i<Na) { eJ[i] = c; i++; } }

	//Значения эталона
	for (j = 0; j<Na; j++)for (i = 0; i<Na; i++)
	{
		fscanf_s(f3, "%d", &WTB[j][i], 1); if (i == j) { DG[j] = WTB[j][i]; WTB[j][i] = 0; }
	}//TB, диаг=0

	 //
	 //ЭТАЛОН: нормировка
	 //
	w = 0.0; for (i = 0; i<NAt; i++)for (j = 0; j<31; j++)w = w + float(WTB[i][j]);
	De = 0;  for (i = 0; i<NAt; i++)De = De + DG[i];     w = w + float(De);

	for (i = 0; i<NAt; i++)for (j = 0; j<NAt; j++) FTB[i][j] = float(WTB[i][j]) / w;  //Нормировка

																					  //Корректировка номера начального решения
	Mn = M;
	if (Mn<0) Mn = 0;
	if (Mn>Nu)Mn = Nu;


	//
	//Главный цикл
	//


	for (i4 = 0; i4<Nf; i4++)
	{
		//Чтение очередной таблицы биграмм (симметрично упорядоченной по частоте появления знаков)

		NaP = 0; //Флаг пустого решения

				 //Заголовок фрагмента

		while ((c = fgetc(f)) == '\n'); //Пустые строки перед заголовком и первый подчерк
		fscanf_s(f, "%d\n", &sNN, 1); //Номер фрагмента
		fscanf_s(f, "%c\n", &c, 1);   //второй подчерк

									  //Заголовок локальной таблицы биграмм

		for (i = 0; i<NAt; i++) { mJ[i] = Zs; tG[i] = 0; }
		for (j = 0; j<NAt; j++)for (i = 0; i<NAt; i++) { tTB[j][i] = 0; fTB[j][i] = 0.0; } //Подготовка mJ и поля NAt x NAt

		fscanf_s(f, "%d", &Na, 1);             //Число знаков локальной таблицы биграмм

		NaC = 0; if (Na>NAt) { NaC = Na; Na = NAt; }  //Коррекция числа знаков, если их больше NAt.

		while ((c = fgetc(f)) != '\n');          //Знаки локальной таблицы биграмм
		i = 0; while ((c = fgetc(f)) != '\n') { if (c != '\t' && i<Na) { mJ[i] = c; i++; } }

		//Значения локальной Таблицы биграмм tTB с учетом возможной коррекции NaC
		for (j = 0; j<Na; j++) {
			for (i = 0; i<Na; i++)
			{
				fscanf_s(f, "%d", &tTB[j][i], 1); if (i == j) { tG[j] = tTB[j][i]; tTB[j][i] = 0; }
			} if (NaC>0)while ((c = fgetc(f)) != '\n');
		}//TB, диаг=0
		if (NaC>0)for (j = Na; j<NaC; j++)while ((c = fgetc(f)) != '\n'); else while ((c = fgetc(f)) != '\n');


		//
		//Переупорядочение таблицы биграмм tTB в соответствии с заданным начальным решением
		//
		//Чтение начального решения  M из (&f1,"ouR.txt","r") и копирование решений в  (&f4,"tmp.txt","w")
		if (Nu != 0)
		{
			//(&f1,"ouR.txt","r")
			//Заголовок фрагмента ouR
			while ((c = fgetc(f1)) == '\n'); //Пустые строки перед заголовком и первый подчерк
			fscanf_s(f1, "%d\n", &sNN, 1); //Номер фрагмента
			fscanf_s(f1, "%c\n", &c, 1);   //второй подчерк
			fprintf(f4, "_%d_\n", sNN);
			if (Mn != 0)
			{
				//Пропуск предыдущих решений
				for (i = 0; i<Mn - 1; i++) { while ((c = fgetc(f1)) != '\n')fprintf(f4, "%c", c); fprintf(f4, "\n"); }
				//Начальное решение NAt знаков.  
				i = 0;  while (i<NAt) { c = fgetc(f1); xJ[i] = c; i++; fprintf(f4, "%c", c); }
				while ((c = fgetc(f1)) != '\n')fprintf(f4, "%c", c); fprintf(f4, "\n");
			}
			//Пропуск оставшихся решений
			for (i = Mn; i<Nu; i++) { while ((c = fgetc(f1)) != '\n')fprintf(f4, "%c", c); fprintf(f4, "\n"); }
		}
		if (Mn != 0)
		{
			//Проверка решений на совпадение множеств знаков
			j = 0; for (i = 0; i<NAt; i++)for (x = 0; x<NAt; x++)if (xJ[i] != Zs && xJ[i] == mJ[x])j++;
			if (j != Na) { for (i = 0; i<NAt; i++)mJ[i] = Zs; NaP = 1; goto NEN; } //Пустое решение
																				   //Переупорядочивание локальной таблицы в соответствии с заданным начальным решением
			for (i = 0; i<NAt; i++)for (x = 0; x<NAt; x++) { if (xJ[i] != Zs && xJ[i] == mJ[x])for (j = 0; j<NAt; j++)fTB[j][i] = float(tTB[j][x]); }
			for (i = 0; i<NAt; i++)for (x = 0; x<NAt; x++) { if (xJ[i] != Zs && xJ[i] == mJ[x])for (j = 0; j<NAt; j++)tTB[i][j] = int(fTB[x][j]); }
			for (i = 0; i<NAt; i++)mJ[i] = xJ[i];
		}

		//
		// Метод Якобсена 
		//***************************************************
		// Частотная нормировка
		//
		Dt = 0;
		for (i = 0; i<NAt; i++)Dt = Dt + tG[i];

		k = NAt;
		w1 = 0.0;
		for (i = 0; i<NAt; i++)for (j = 0; j<NAt; j++)w1 = w1 + float(tTB[i][j]);  w1 = w1 + float(Dt);

		for (i = 0; i<NAt; i++)for (j = 0; j<NAt; j++)fTB[i][j] = float(tTB[i][j]) / w1;


		i = 0; p = 0; j = 1; X = X1 = 0;
		while (j<NAt)
		{
			while ((i + j)<NAt)
			{
				w1 = w2 = w3 = w4 = 0; X++; w8 = 0;
				for (x = 0; x<k; x++) { w1 = w1 + fabs(FTB[i][x] - fTB[i][x]) + fabs(FTB[x][i] - fTB[x][i]); }
				for (x = 0; x<k; x++) { w2 = w2 + fabs(FTB[i + j][x] - fTB[i + j][x]) + fabs(FTB[x][i + j] - fTB[x][i + j]); }


				w6 = fTB[i][i + j]; fTB[i][i + j] = 0.0;
				w7 = fTB[i + j][i]; fTB[i + j][i] = 0.0;
				w9 = FTB[i][i + j]; FTB[i][i + j] = 0.0;
				w10 = FTB[i + j][i]; FTB[i + j][i] = 0.0;

				for (x = 0; x<k; x++) { w3 = w3 + fabs(FTB[i][x] - fTB[i + j][x]) + fabs(FTB[x][i] - fTB[x][i + j]); }
				for (x = 0; x<k; x++) { w4 = w4 + fabs(FTB[i + j][x] - fTB[i][x]) + fabs(FTB[x][i + j] - fTB[x][i]); }

				fTB[i][i + j] = w6; w3 = w3 + fabs(w9 - w6) + fabs(w9 - w7);
				fTB[i + j][i] = w7; w4 = w4 + fabs(w10 - w7) + fabs(w10 - w6);
				FTB[i][i + j] = w9;
				FTB[i + j][i] = w10;

				w8 = w1 + w2 - w3 - w4;

				if (w8>0.0 + eps)
				{
					p = 1; w = w - w1 - w2 + w3 + w4; X1++;
					for (x = 0; x<k; x++) { w1 = fTB[i][x]; fTB[i][x] = fTB[i + j][x]; fTB[i + j][x] = w1; }
					for (x = 0; x<k; x++) { w1 = fTB[x][i]; fTB[x][i] = fTB[x][i + j]; fTB[x][i + j] = w1; }
					ig = mJ[i]; mJ[i] = mJ[i + j]; mJ[i + j] = ig;
					break;
				}
				i++;
			}
			i = 0; if (p == 1) { p = 0; j = 0; }
			j++;
		}

	NEN:
		//Вывод локального решения
		if (Nu == 0)fprintf(f4, "_%d_\n", sNN);
		//2.  Запись нового решения
		for (i = 0; i<NAt; i++)fprintf(f4, "%c", mJ[i]);
		c = ' '; if (NaP == 1)c = Zs; else if (Mn>0) c = '+';
		fprintf(f4, "\t%d\t%d\t%c[JAC]\n", Nu + 1, Mn, c);

	}

	//
	//выход 
	//
	fclose(f4);
	fclose(f1);
	fclose(f);

	fopen_s(&f1, "ouR.txt", "w");
	fopen_s(&f4, "tmp.txt", "r");
	while ((c = fgetc(f4)) != EOF)fprintf(f1, "%c", c);
	fclose(f4);
	fclose(f1);

	fopen_s(&f4, "tmp.txt", "w");
	c = ' '; fprintf(f4, "%c", c);
	fclose(f4);

	return 0;

}
///////////////////////////////////

//DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT
//Глобальные переменные DAT
int TB[31][31], WB[31][31];     //таблица биграмм
int G[31][8], G1[31], G2[31][3], VS[31][12], VT[31][12], PS[31][3], PT[31][3];
int X;
//
//Внутренняя процедура DAT
void SETreSETdataFIELD() {
	int n, m, j, i = 0;
	//Расчет поля данных
	// К и КБ
	for (j = 0; j<31; j++)
	{
		m = 0; n = 0;
		for (i = 0; i<31; i++) { n = n + TB[j][i]; if (TB[j][i]>0)m++; }
		VS[j][0] = n; VS[j][1] = m;
	}
	for (i = 0; i<31; i++)
	{
		m = 0; n = 0;
		for (j = 0; j<31; j++) { n = n + TB[j][i]; if (TB[j][i]>0)m++; }
		VT[i][0] = n; VT[i][1] = m;
	}



	for (j = 0; j<31; j++)
	{
		VS[j][4] = TB[j][0] + TB[j][1] + TB[j][2] + TB[j][3];
		VS[j][5] = TB[j][4] + TB[j][5] + TB[j][6];
		m = 0; n = 0;
		for (i = 4; i<18; i++) { n = n + TB[j][i]; if (TB[j][i]>0)m++; }// 14  // Н
		VS[j][6] = n;
		VS[j][8] = m;
		m = 0;
		for (i = 0; i<4; i++)if (TB[j][i]>0)m++;
		VS[j][7] = m;
	}

	for (j = 0; j<31; j++)
	{
		VT[j][4] = TB[0][j] + TB[1][j] + TB[2][j] + TB[3][j];
		VT[j][5] = TB[4][j] + TB[5][j] + TB[6][j];
		m = 0; n = 0;
		for (i = 4; i<18; i++) { n = n + TB[i][j]; if (TB[i][j]>0)m++; }// 14  // Н
		VT[j][6] = n;
		VT[j][8] = m;
		m = 0;
		for (i = 0; i<4; i++)if (TB[i][j]>0)m++;
		VT[j][7] = m;
	}

	for (j = 0; j<31; j++)
	{
		m = 0;
		for (i = 0; i<4; i++)if (TB[j][i]>m) { m = TB[j][i]; }
		VS[j][9] = m;
		for (i = 0; i<4; i++)if (TB[j][i]<m) { m = TB[j][i]; }
		VS[j][10] = m;
		m = 0;
		for (i = 4; i<14; i++)if (TB[j][i]>m) { m = TB[j][i]; }
		VS[j][11] = m;
		m = 0; n = 0;
		for (i = 0; i<31; i++)if (TB[j][i]>m) { m = TB[j][i]; n = i; }
		VS[j][2] = m;
		VS[j][3] = n;
	}

	for (j = 0; j<31; j++)
	{
		m = 0;
		for (i = 0; i<4; i++)if (TB[i][j]>m) { m = TB[i][j]; }
		VT[j][9] = m;
		for (i = 0; i<4; i++)if (TB[i][j]<m) { m = TB[i][j]; }
		VT[j][10] = m;
		m = 0;
		for (i = 4; i<14; i++)if (TB[i][j]>m) { m = TB[i][j]; }
		VT[j][11] = m;
		m = 0; n = 0;
		for (i = 0; i<31; i++)if (TB[i][j]>m) { m = TB[i][j]; n = i; }
		VT[j][2] = m;
		VT[j][3] = n;
	}

	//Общие
	for (j = 0; j<31; j++)
	{
		G[j][3] = VS[j][1] + VT[j][1];
		G[j][4] = VS[j][1] - VT[j][1];
		G[j][5] = VS[j][6] + VT[j][6];
		G[j][6] = VS[j][6] - VT[j][6];
		G[j][7] = VS[j][4] - VT[j][4];
	}

	for (j = 0; j<31; j++)
	{
		PS[j][0] = 2 * VS[j][4] - VS[j][0];
		PS[j][1] = VS[j][4] - VS[j][5];
		PS[j][2] = 2 * (VS[j][4] + VS[j][5]) - VS[j][0];
		PT[j][0] = 2 * VT[j][4] - VT[j][0];
		PT[j][1] = VT[j][4] - VT[j][5];
		PT[j][2] = 2 * (VT[j][4] + VT[j][5]) - VT[j][0];
	}
}
//Внутренняя процедура DAT
void PERESTANOVKA_1()// G1.1 предварительно
{
	int m, j, i;
	m = 0;
	for (j = 0; j<31; j++)if (G[j][0] == 1) { for (i = 0; i<31; i++)WB[m][i] = TB[j][i]; G2[m][0] = G[j][0]; G2[m][1] = G[j][1]; G2[m][2] = G[j][2]; m++; }
	for (j = 0; j<31; j++)if (G[j][0] != 1) { for (i = 0; i<31; i++)WB[m][i] = TB[j][i]; G2[m][0] = G[j][0]; G2[m][1] = G[j][1]; G2[m][2] = G[j][2]; m++; }
	m = 0;
	for (j = 0; j<31; j++)if (G[j][0] == 1) { for (i = 0; i<31; i++)TB[i][m] = WB[i][j]; m++; }
	for (j = 0; j<31; j++)if (G[j][0] != 1) { for (i = 0; i<31; i++)TB[i][m] = WB[i][j]; m++; }
	for (j = 0; j<31; j++) { G[j][0] = G2[j][0]; G[j][1] = G2[j][1]; G[j][2] = G2[j][2]; }
}
//Внутренняя процедура DAT
void PERESTANOVKA_2()// G1.R и G1.2 предварительно
{
	int n, m, j, i;
	for (j = 0; j<31; j++)if (G[j][0] == 22) { for (i = 0; i<31; i++)          WB[30][i] = TB[j][i]; G1[0] = j; G2[30][0] = G[j][0]; G2[30][1] = G[j][1]; G2[30][2] = G[j][2]; G[j][0] = 99; }// "Ь"
	else if (G[j][0] == 16) { for (i = 0; i<31; i++)     WB[29][i] = TB[j][i]; G1[1] = j; G2[29][0] = G[j][0]; G2[29][1] = G[j][1]; G2[29][2] = G[j][2]; G[j][0] = 99; }// "Ы"
	else if (G[j][0] == 21) { for (i = 0; i<31; i++)WB[28][i] = TB[j][i]; G1[2] = j; G2[28][0] = G[j][0]; G2[28][1] = G[j][1]; G2[28][2] = G[j][2]; G[j][0] = 99; }// "Й"
	n = 3;
	m = 27;
	for (j = 30; j >= 0; j--)if (G[j][0] == 32) { for (i = 0; i<31; i++)WB[m][i] = TB[j][i]; G1[n] = j; n++; G2[m][0] = G[j][0]; G2[m][1] = G[j][1]; G2[m][2] = G[j][2]; G[j][0] = 99; m--; }//G1.2
	X = n - 3;
	for (j = 30; j >= 0; j--)if (G[j][0] <99) { for (i = 0; i<31; i++)WB[m][i] = TB[j][i]; G1[n] = j; n++; G2[m][0] = G[j][0]; G2[m][1] = G[j][1]; G2[m][2] = G[j][2]; m--; }//остальные

	m = 0;
	for (j = 30; j >= 0; j--) { n = G1[m]; for (i = 0; i<31; i++)TB[i][j] = WB[i][n]; m++; }
	for (j = 0; j<31; j++) { G[j][0] = G2[j][0]; G[j][1] = G2[j][1]; G[j][2] = G2[j][2]; }
}
//Внутренняя процедура DAT
void PERESTANOVKA_3() // G2.1
{
	int m, j, i;
	for (j = 0; j<31; j++)G1[j] = 0;
	G1[0] = 0; G1[1] = 1; G1[2] = 2; G1[3] = 3;
	for (j = 0; j<31; j++)if (G[j][0] == 5) { for (i = 0; i<31; i++)           WB[4][i] = TB[j][i]; G1[4] = j; G2[4][0] = G[j][0]; G2[4][1] = G[j][1]; G2[4][2] = G[j][2]; G[j][0] = 99; }// "Н"
	else if (G[j][0] == 6) { for (i = 0; i<31; i++)      WB[5][i] = TB[j][i]; G1[5] = j; G2[5][0] = G[j][0]; G2[5][1] = G[j][1]; G2[5][2] = G[j][2]; G[j][0] = 99; }// "Т"
	else if (G[j][0] == 7) { for (i = 0; i<31; i++)WB[6][i] = TB[j][i]; G1[6] = j; G2[6][0] = G[j][0]; G2[6][1] = G[j][1]; G2[6][2] = G[j][2]; G[j][0] = 99; }// "С"
	else if (G[j][0] == 8) { for (i = 0; i<31; i++)WB[7][i] = TB[j][i]; G1[7] = j; G2[7][0] = G[j][0]; G2[7][1] = G[j][1]; G2[7][2] = G[j][2]; G[j][0] = 99; }// "В"
	else if (G[j][0] == 9) { for (i = 0; i<31; i++)WB[8][i] = TB[j][i]; G1[8] = j; G2[8][0] = G[j][0]; G2[8][1] = G[j][1]; G2[8][2] = G[j][2]; G[j][0] = 99; }// "Р"
	else if (G[j][0] == 10) { for (i = 0; i<31; i++)WB[9][i] = TB[j][i]; G1[9] = j; G2[9][0] = G[j][0]; G2[9][1] = G[j][1]; G2[9][2] = G[j][2]; G[j][0] = 99; }// "Л"
	else if (G[j][0] == 14) { for (i = 0; i<31; i++)WB[10][i] = TB[j][i]; G1[10] = j; G2[10][0] = G[j][0]; G2[10][1] = G[j][1]; G2[10][2] = G[j][2]; G[j][0] = 99; }// "П"

	for (j = 0; j<4; j++)for (i = 0; i<31; i++)WB[j][i] = TB[j][i];//4 первых
	m = 11;
	for (j = 4; j<31; j++)if (G[j][0]<99) { for (i = 0; i<31; i++)WB[m][i] = TB[j][i]; G1[m] = j;  G2[m][0] = G[j][0]; G2[m][1] = G[j][1]; G2[m][2] = G[j][2]; m++; }//остальные

	for (j = 0; j<31; j++) for (i = 0; i<31; i++)TB[i][j] = WB[i][G1[j]];
	for (j = 0; j<31; j++) { G[j][0] = G2[j][0]; G[j][1] = G2[j][1]; G[j][2] = G2[j][2]; }

}
//Внутренняя процедура DAT
void PERESTANOVKA_4()// G1.1 
{
	int n, j, i;
	for (j = 0; j<4; j++)if (G[j][0] == 1) { for (i = 0; i<31; i++)               WB[0][i] = TB[j][i]; G1[0] = j; G2[0][0] = G[j][0]; G2[0][1] = G[j][1]; G2[0][2] = G[j][2]; }// "О"
	else if (G[j][0] == 2) { for (i = 0; i<31; i++)          WB[1][i] = TB[j][i]; G1[1] = j; G2[1][0] = G[j][0]; G2[1][1] = G[j][1]; G2[1][2] = G[j][2]; }// "Е"
	else if (G[j][0] == 3) { for (i = 0; i<31; i++)     WB[2][i] = TB[j][i]; G1[2] = j; G2[2][0] = G[j][0]; G2[2][1] = G[j][1]; G2[2][2] = G[j][2]; }// "А"
	else if (G[j][0] == 4) { for (i = 0; i<31; i++)WB[3][i] = TB[j][i]; G1[3] = j; G2[3][0] = G[j][0]; G2[3][1] = G[j][1]; G2[3][2] = G[j][2]; }// "И"


	for (j = 4; j<31; j++)for (i = 0; i<31; i++)WB[j][i] = TB[j][i];//остальные

	for (j = 0; j<4; j++) { n = G1[j]; for (i = 0; i<31; i++)TB[i][j] = WB[i][n]; }
	for (j = 4; j<31; j++)for (i = 0; i<31; i++)TB[i][j] = WB[i][j];//остальные

	for (j = 0; j<4; j++) { G[j][0] = G2[j][0]; G[j][1] = G2[j][1]; G[j][2] = G2[j][2]; }
}
//Внутренняя процедура DAT
void PERESTANOVKA_5()// G1.2 "32" 
{
	int n, m, j, i;
	n = 0;
	for (j = 0; j<31; j++)G1[j] = 0;
	for (j = 11; j<28; j++)if (G[j][0] != 0) { n++; G1[j] = j; }
	if (n>0)
	{
		m = 28 - n;

		for (j = 11; j<28; j++)if (G[j][0] == 15) { for (i = 0; i<31; i++)WB[m][i] = TB[j][i]; G2[m][0] = G[j][0]; G2[m][1] = G[j][1]; G2[m][2] = G[j][2]; m++; }// "У"
		for (j = 11; j<28; j++)if (G[j][0] == 18) { for (i = 0; i<31; i++)WB[m][i] = TB[j][i]; G2[m][0] = G[j][0]; G2[m][1] = G[j][1]; G2[m][2] = G[j][2]; m++; }// "Я"
		for (j = 11; j<28; j++)if (G[j][0] == 27) { for (i = 0; i<31; i++)WB[m][i] = TB[j][i]; G2[m][0] = G[j][0]; G2[m][1] = G[j][1]; G2[m][2] = G[j][2]; m++; }// "Ю"
		for (j = 11; j<28; j++)if (G[j][0] == 30) { for (i = 0; i<31; i++)WB[m][i] = TB[j][i]; G2[m][0] = G[j][0]; G2[m][1] = G[j][1]; G2[m][2] = G[j][2]; m++; }// "Э"

		m = 0;
		for (j = 0; j<28; j++)
			if (G1[j] == 0)
			{
				for (i = 0; i<31; i++)WB[m][i] = TB[j][i];
				G2[m][0] = G[j][0]; G2[m][1] = G[j][1]; G2[m][2] = G[j][2]; m++;
			}
		for (j = 28; j<31; j++)for (i = 0; i<31; i++)WB[j][i] = TB[j][i];//последние три

		m = 28 - n;

		for (j = 11; j<28; j++)if (G[j][0] == 15) { for (i = 0; i<31; i++)TB[i][m] = WB[i][j]; m++; }// "У"
		for (j = 11; j<28; j++)if (G[j][0] == 18) { for (i = 0; i<31; i++)TB[i][m] = WB[i][j]; m++; }// "Я"
		for (j = 11; j<28; j++)if (G[j][0] == 27) { for (i = 0; i<31; i++)TB[i][m] = WB[i][j]; m++; }// "Ю"
		for (j = 11; j<28; j++)if (G[j][0] == 30) { for (i = 0; i<31; i++)TB[i][m] = WB[i][j]; m++; }// "Э"

		m = 0;
		for (j = 0; j<28; j++)if (G1[j] == 0) { for (i = 0; i<31; i++)TB[i][m] = WB[i][j]; m++; }
		for (j = 28; j<31; j++)for (i = 0; i<31; i++)TB[i][j] = WB[i][j];//последние три
		for (j = 0; j<28; j++) { G[j][0] = G2[j][0]; G[j][1] = G2[j][1]; G[j][2] = G2[j][2]; }
	}
}
//Внутренняя процедура DAT
void PERESTANOVKA_6()// G2.2 
{
	int n, j, i;
	for (j = 0; j<31; j++)G1[j] = 0;
	for (j = 11; j<28 - X; j++)
		if (G[j][0] == 11) { for (i = 0; i<31; i++)        WB[11][i] = TB[j][i]; G1[11] = j; G2[11][0] = G[j][0]; G2[11][1] = G[j][1]; G2[11][2] = G[j][2]; }// "К"
		else if (G[j][0] == 12) { for (i = 0; i<31; i++)  WB[12][i] = TB[j][i]; G1[12] = j; G2[12][0] = G[j][0]; G2[12][1] = G[j][1]; G2[12][2] = G[j][2]; }// "Д"
		else if (G[j][0] == 13) { for (i = 0; i<31; i++)WB[13][i] = TB[j][i]; G1[13] = j; G2[13][0] = G[j][0]; G2[13][1] = G[j][1]; G2[13][2] = G[j][2]; }// "М"
		n = 14;
		for (j = 11; j<28 - X; j++)
			if (G[j][0] == 0) { for (i = 0; i<31; i++) WB[n][i] = TB[j][i]; G1[n] = j; G2[n][0] = G[j][0]; G2[n][1] = G[j][1]; G2[n][2] = G[j][2]; n++; }
		for (j = 0; j<11; j++)   for (i = 0; i<31; i++)WB[j][i] = TB[j][i];//первые
		for (j = 28 - X; j<31; j++)for (i = 0; i<31; i++)WB[j][i] = TB[j][i];//последние

		for (j = 11; j<28 - X; j++) { n = G1[j]; for (i = 0; i<31; i++)TB[i][j] = WB[i][n]; }

		for (j = 0; j<11; j++)   for (i = 0; i<31; i++)TB[i][j] = WB[i][j];//первые
		for (j = 28 - X; j<31; j++)for (i = 0; i<31; i++)TB[i][j] = WB[i][j];//последние

		for (j = 11; j<28 - X; j++) { G[j][0] = G2[j][0]; G[j][1] = G2[j][1]; G[j][2] = G2[j][2]; }
}
//Внутренняя процедура DAT
void PERESTANOVKA_7()// G2.3 
{
	int j, i;
	for (j = 0; j<31; j++)G1[j] = 0;
	for (j = 14; j<28 - X; j++)
		if (G[j][0] == 17) { for (i = 0; i<31; i++)         WB[14][i] = TB[j][i]; G1[14] = j; G2[14][0] = G[j][0]; G2[14][1] = G[j][1]; G2[14][2] = G[j][2]; }// "З"
		else if (G[j][0] == 19) { for (i = 0; i<31; i++)   WB[15][i] = TB[j][i]; G1[15] = j; G2[15][0] = G[j][0]; G2[15][1] = G[j][1]; G2[15][2] = G[j][2]; }// "Г"
		else if (G[j][0] == 20) { for (i = 0; i<31; i++)  WB[16][i] = TB[j][i]; G1[16] = j; G2[16][0] = G[j][0]; G2[16][1] = G[j][1]; G2[16][2] = G[j][2]; }// "Б"
		else if (G[j][0] == 23) { for (i = 0; i<31; i++) WB[17][i] = TB[j][i]; G1[17] = j; G2[17][0] = G[j][0]; G2[17][1] = G[j][1]; G2[17][2] = G[j][2]; }// "Ч"
		else if (G[j][0] == 24) { for (i = 0; i<31; i++)WB[18][i] = TB[j][i]; G1[18] = j; G2[18][0] = G[j][0]; G2[18][1] = G[j][1]; G2[18][2] = G[j][2]; }// "X"  
		else if (G[j][0] == 25) { for (i = 0; i<31; i++)    WB[19][i] = TB[j][i]; G1[19] = j; G2[19][0] = G[j][0]; G2[19][1] = G[j][1]; G2[19][2] = G[j][2]; }// "Ш"   
		else if (G[j][0] == 26) { for (i = 0; i<31; i++)   WB[20][i] = TB[j][i]; G1[20] = j; G2[20][0] = G[j][0]; G2[20][1] = G[j][1]; G2[20][2] = G[j][2]; }// "Ж"
		else if (G[j][0] == 28) { for (i = 0; i<31; i++)  WB[21][i] = TB[j][i]; G1[21] = j; G2[21][0] = G[j][0]; G2[21][1] = G[j][1]; G2[21][2] = G[j][2]; }// "Ц"
		else if (G[j][0] == 29) { for (i = 0; i<31; i++) WB[22][i] = TB[j][i]; G1[22] = j; G2[22][0] = G[j][0]; G2[22][1] = G[j][1]; G2[22][2] = G[j][2]; }// "Щ"
		else if (G[j][0] == 31) { for (i = 0; i<31; i++)WB[23][i] = TB[j][i]; G1[23] = j; G2[23][0] = G[j][0]; G2[23][1] = G[j][1]; G2[23][2] = G[j][2]; }// "Щ" 

		for (j = 0; j<14; j++)   for (i = 0; i<31; i++)WB[j][i] = TB[j][i];//первые
		for (j = 28 - X; j<31; j++)for (i = 0; i<31; i++)WB[j][i] = TB[j][i];//последние

		for (j = 0; j<14; j++)   for (i = 0; i<31; i++)TB[i][j] = WB[i][j];//первые
		for (j = 28 - X; j<31; j++)for (i = 0; i<31; i++)TB[i][j] = WB[i][j];//последние

		for (j = 14; j<28 - X; j++) { G[j][0] = G2[j][0]; G[j][1] = G2[j][1]; G[j][2] = G2[j][2]; }
}




///////////////////////////////////
int DAT(int M) //Метод детерминированной идентификации
			   //                               Исходная информация должна быть представленая в форме Nf таблиц биграмм
			   //                               в файле inB.txt, симметрично упорядоченных по частоте появления знаков в тексте.
			   //                               Максимальное количество знаков 1 < NA <= 31, ограничений для Nf нет, Nf > 0.
			   //                               Номер языка L = 1 NAt = 31. Упорядочение начального решения осуществляется по решению M
			   //                               из файла ouR, в котором уже есть Nu решений. 
			   //                               Если M <= 0, то применяется исходное упорядочение. Если M > Nu, то М=Nu.
			   //                               Если множества знаков решения M из ouR и знаков текущей таблицы биграмм различаются,
			   //                               то формируется пустое решение из одного замещающего знака Zs.
			   //Входные массивы: inB.txt
			   //                 Ititle.txt
			   //                 ouR.txt
			   //                 
			   //Выходной массив: ouR.txt
			   //Рабочий массив:  tmp.txt
			   //
			   //return 0:   все в порядке
			   //return 1:   L != 1 или NAt != 31  Ошибочный язык, число знаков 
			   //
{
	char A[31], SP[32] = { "ОЕАИНТСВРЛПКДМЙЫЬУЯЮЭЗГБЧХШЖЦЩФ" };//алфавит - группы
	char EU[32] = { "ОЕАИНТСВРЛКДМПУЫЗЯГБЙЬХЧШЖЮЦЩЭФ" };//алфавит - частотное упорядочивание
	int  ES[31];                                    //SP[]-EU[] соответствие

	int T, C, R, D[15][15], nn1, n1;
	float F1[31], F2[31], nf, mf, nf1, nf2;

	int Nf, Nfu, Nu, L, NAt, TT, Sp;
	char c, Zs;
	int sNN, Na, NaC, NaP, Mn;

	char mJ[31], xJJ[31];//массив встречающихся символов <= 31

	int i = 0, k = 1, j = 0, t = 0, p, x = 0, X = 0, X1 = 0, e = 0, lns = 0, lns1, lnt = 0, m = 0;
	int g1 = 0, g3 = 0, i4;
	float Fnorm;
	double FF1[31], nfF, mm1;
	int U, Z, xJ, xZ, xN, xK;
	int n, m1;

	FILE *f, *f1, *f2, *f4;

	fopen_s(&f, "inB.txt", "r");
	fopen_s(&f1, "ouR.txt", "r");
	fopen_s(&f2, "Ititle.txt", "r");
	fopen_s(&f4, "tmp.txt", "w");

	fscanf_s(f, "%d\n", &Nf, 1);          //Количество фрагментов. Переменная главного цикла i4
	fscanf_s(f1, "%d %d\n", &Nfu, &Nu, 1); //Количество решений


	fprintf(f4, "%d %d\n", Nf, Nu + 1);
	fscanf_s(f2, "%d %d %d %d %d %c\n", &i, &L, &NAt, &TT, &Sp, &Zs, 1);//Тип языка, наличие пробела, замещающий знак Zs
	fclose(f2);

	if (L != 1 || NAt != 31) return 1;

	//Начальная очистка массивов
	for (i = 0; i<31; i++)for (j = 0; j<31; j++)TB[i][j] = WB[i][j] = 0;
	//Настройка под эталон
	for (i = 0; i<31; i++)for (j = 0; j<31; j++)if (SP[i] == EU[j])ES[i] = j;


	//Корректировка номера начального решения
	Mn = M;
	if (Mn<0) Mn = 0;
	if (Mn>Nu)Mn = Nu;


	//
	//Главный цикл
	//


	for (i4 = 0; i4<Nf; i4++)
	{
		//Чтение очередной таблицы биграмм (симметрично упорядоченной по частоте появления знаков)

		NaP = 0; //Флаг пустого решения

				 //Заголовок фрагмента

		while ((c = fgetc(f)) == '\n'); //Пустые строки перед заголовком и первый подчерк
		fscanf_s(f, "%d\n", &sNN, 1); //Номер фрагмента
		fscanf_s(f, "%c\n", &c, 1);   //второй подчерк

									  //Заголовок локальной таблицы биграмм

		for (i = 0; i<NAt; i++)mJ[i] = Zs;
		for (j = 0; j<NAt; j++)for (i = 0; i<NAt; i++)TB[j][i] = WB[j][i] = 0; //Подготовка mJ и поля NAt x NAt

		fscanf_s(f, "%d", &Na, 1);             //Число знаков локальной таблицы биграмм

		NaC = 0; if (Na>NAt) { NaC = Na; Na = NAt; }  //Коррекция числа знаков, если их больше NAt.

		while ((c = fgetc(f)) != '\n');          //Знаки локальной таблицы биграмм
		i = 0; while ((c = fgetc(f)) != '\n') { if (c != '\t' && i<Na) { mJ[i] = c; i++; } }

		//Значения локальной Таблицы биграмм TB с учетом возможной коррекции NaC
		lns = 0;
		for (j = 0; j<Na; j++) {
			for (i = 0; i<Na; i++) { fscanf_s(f, "%d", &TB[j][i], 1); lns = lns + TB[j][i]; } lns++;
			if (NaC>0)while ((c = fgetc(f)) != '\n');
		}
		if (NaC>0)for (j = Na; j<NaC; j++)while ((c = fgetc(f)) != '\n'); else while ((c = fgetc(f)) != '\n');



		//
		//Переупорядочение таблицы биграмм TB в соответствии с заданным начальным решением
		//
		//Чтение начального решения  M из (&f1,"ouR.txt","r") и копирование решений в  (&f4,"tmp.txt","w")
		if (Nu != 0)
		{
			//(&f1,"ouR.txt","r")
			//Заголовок фрагмента ouR
			while ((c = fgetc(f1)) == '\n'); //Пустые строки перед заголовком и первый подчерк
			fscanf_s(f1, "%d\n", &sNN, 1); //Номер фрагмента
			fscanf_s(f1, "%c\n", &c, 1);   //второй подчерк
			fprintf(f4, "_%d_\n", sNN);
			if (Mn != 0)
			{
				//Пропуск предыдущих решений
				for (i = 0; i<Mn - 1; i++) { while ((c = fgetc(f1)) != '\n')fprintf(f4, "%c", c); fprintf(f4, "\n"); }
				//Начальное решение NAt знаков.  
				i = 0;  while (i<NAt) { c = fgetc(f1); xJJ[i] = c; i++; fprintf(f4, "%c", c); }
				while ((c = fgetc(f1)) != '\n')fprintf(f4, "%c", c); fprintf(f4, "\n");
			}
			//Пропуск оставшихся решений
			for (i = Mn; i<Nu; i++) { while ((c = fgetc(f1)) != '\n')fprintf(f4, "%c", c); fprintf(f4, "\n"); }
		}
		if (Mn != 0)
		{
			//Проверка решений на совпадение множеств знаков
			j = 0; for (i = 0; i<NAt; i++)for (x = 0; x<NAt; x++)if (xJJ[i] != Zs && xJJ[i] == mJ[x])j++;
			if (j != Na) { for (i = 0; i<NAt; i++)mJ[i] = Zs; NaP = 1; goto NEN; } //Пустое решение
																				   //Переупорядочивание локальной таблицы в соответствии с заданным начальным решением
			for (i = 0; i<NAt; i++)for (x = 0; x<NAt; x++) { if (xJJ[i] != Zs && xJJ[i] == mJ[x])for (j = 0; j<NAt; j++)WB[j][i] = TB[j][x]; }
			for (i = 0; i<NAt; i++)for (x = 0; x<NAt; x++) { if (xJJ[i] != Zs && xJJ[i] == mJ[x])for (j = 0; j<NAt; j++)TB[i][j] = WB[x][j]; }
			for (i = 0; i<NAt; i++)mJ[i] = xJJ[i];
		}

		//Нормировка
		lns1 = lns;
		if (lns>10000)
		{
			lns1 = 0;
			for (i = 0; i<31; i++) for (j = 0; j<31; j++) { Fnorm = TB[i][j] * 10000 / float(lns); TB[i][j] = int(Fnorm); lns1 = lns1 + TB[i][j]; }
		}

		for (j = 0; j<31; j++) { G[j][2] = TB[j][j]; TB[j][j] = 0; G[j][0] = 0; G[j][1] = j; }//TB, диаг  ИС и текущий


																							  //
																							  // Метод 
																							  //***************************************************
																							  // 
																							  //
		SETreSETdataFIELD();
		//
		//первые 4 гласные

		for (j = 0; j<9; j++)if (PS[j][2]<0 || PT[j][2]<0) { G1[j] = G[j][3]; if (G[j][2] != 0)G1[j] = G1[j] + 1; }
		else G1[j] = 0;
		for (i = 0; i<9; i++)
		{
			n = 0;
			for (j = 1; j<9; j++)if (G1[j]>G1[j - 1]) { m = G1[j]; G1[j] = G1[j - 1]; G1[j - 1] = m; n = 1; }
			if (n == 0)break;
		}
		n = 0;
		for (j = 0; j<9; j++)
		{
			if (G[j][2] != 0)m = G[j][3] + 1; else m = G[j][3];
			if (m >= G1[3] && n<4 && (PS[j][2]<0 || PT[j][2]<0)) { G[j][0] = 1; n++; }
		}

		PERESTANOVKA_1();
		SETreSETdataFIELD();
		//
		//Й,Ь,Ы 
		//
		xJ = 0;
		for (j = 0; j<31; j++)F1[j] = 0;

		for (j = 4; j<31; j++)
			if (G[j][4]>0)
				F1[j] = -float(G[j][4])*float(G[j][7])*float(VS[j][7] + VT[j][7] * VT[j][7])
				/ float((VS[j][0] + G[j][2])*G[j][3]);

		nf = 0; i = 0;
		for (j = 0; j<31; j++)if (F1[j]>nf) { nf = F1[j]; i = j; }

		if (G[i][0] == 0) G[i][0] = 21; else { p = 0; for (j = 4; j<31; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 21; i = j; p = 1; } }
		xJ = i;

		m = 0; n = 0;

		for (j = 4; j<31; j++)F1[j] = 1;
		Z = 10000;
		for (j = 4; j<31; j++)if (VT[j][4]<Z) { Z = VT[j][4]; xZ = j; }
		m = xZ;
		Z = 10000;
		for (j = 4; j<31; j++)if (VT[j][4]<Z && j != m) { Z = VT[j][4]; xZ = j; }
		n = xZ;

		F1[0] = float(VT[m][2]) / float((VS[m][9] + 1)*(VT[m][1] + 1)*(VT[m][1] + 1)*(TB[m][xJ] + 1)*(TB[m][xJ] + 1));
		F1[1] = float(VT[n][2]) / float((VS[n][9] + 1)*(VT[n][1] + 1)*(VT[n][1] + 1)*(TB[n][xJ] + 1)*(TB[n][xJ] + 1));
		if (F1[0] >= F1[1])
		{
			if (G[m][0] == 0) G[m][0] = 22; else { p = 0; for (j = 4; j<31; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 22; p = 1; } }
			if (G[n][0] == 0) G[n][0] = 16; else { p = 0; for (j = 4; j<31; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 16; p = 1; } }
		}
		else
		{
			if (G[m][0] == 0) G[m][0] = 16; else { p = 0; for (j = 4; j<31; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 16; p = 1; } }
			if (G[n][0] == 0) G[n][0] = 22; else { p = 0; for (j = 4; j<31; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 22; p = 1; } }
		}



		PERESTANOVKA_2();
		SETreSETdataFIELD();
		//
		//
		//Т,С

		for (j = 0; j<15; j++)
		{
			m = TB[4 + j][30]; if (TB[4 + j][30]>10)m = 10;
			for (i = 0; i<15; i++)D[i][j] = TB[4 + j][4 + i] + m;
		}
		for (j = 0; j<15; j++)for (i = 0; i<15; i++)D[i][j] = D[i][j] + TB[4 + i][4 + j];

		nf = mf = 0; n = m = 0;
		for (j = 0; j<15; j++)
			for (i = 0; i<15; i++)
			{
				mf = float(D[i][j])*float((VS[4 + i][6] - VS[4 + i][11] + 1));
				if (nf<mf) { nf = mf; n = j; m = i; }
			}


		if (TB[4 + n][4 + m] >= TB[4 + m][4 + n]) { G[4 + n][0] = 7; G[4 + m][0] = 6; T = 4 + m; C = 4 + n; }
		else { G[4 + n][0] = 6; G[4 + m][0] = 7; T = 4 + n; C = 4 + m; }
		//
		//Н
		//
		for (j = 0; j<31; j++)G1[j] = 0;
		for (j = 4; j<31; j++)if (G[j][0] == 0)G1[j] = (VS[j][0] - G[j][5] - TB[j][30] + G[j][2]/*+TB[j][29]*/)*G[j][3];
		n = 0; m = 0;
		for (j = 0; j<31; j++)if (n<G1[j]) { n = G1[j]; m = j; }
		G[m][0] = 5;
		xN = m;
		//
		//Р
		//

		for (j = 0; j<31; j++) { FF1[j] = 0; F1[j] = 0; F2[j] = 0; }
		for (j = 4; j<20; j++)
			if (G[j][0] == 0)
			{
				n = 0; m = 0;
				for (i = 4; i<20; i++) { n = n + TB[j][i]; m = m + TB[i][j]; }

				xZ = 0; for (Z = 4; Z<20; Z++)if (TB[Z][j]>xZ)xZ = TB[Z][j];

				F1[j] = float((n - m) + TB[j][30] + G[j][2] * G[j][2] + 2 * TB[C][j] + TB[j][29] - xZ - TB[T][j] - 2 * VS[j][9]);
				if (TB[C][T]<2 * TB[C][j])F1[j] = F1[j] + 2 * VS[j][9];
				if (F1[j]<0)
				{
					F1[j] = F1[j] * fabs(F1[j])*xZ*xZ / float((TB[C][j] + 1));
					F2[j] = float(VS[j][8] * VT[j][8] * PS[j][0]);
					FF1[j] = F1[j] * F2[j];
				}
				else if (F1[j] == 0)FF1[j] = -double((TB[j][C] + 1)*(TB[j][C] + 1)*VS[j][8] * VT[j][8] * PS[j][0]); else FF1[j] = 0;
			}

		nfF = 0; m = 0;
		for (j = 4; j<14; j++)if (nfF>FF1[j]) { nfF = FF1[j]; m = j; }
		if (G[m][0] == 0) G[m][0] = 9; else { p = 0; for (j = 4; j<14; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 9; p = 1; m = j; } }
		R = m;

		//У,Я
		//У
		//
		X1 = 0;
		nf1 = 0; mf = 0; m = 0; nf2 = 0;
		for (j = 0; j<31; j++)F1[j] = 0;
		for (j = 4; j<28; j++)
			if (G[j][0] == 0 && PS[j][0]<0 && PT[j][0]<0 && (TB[j][29] + TB[j][30] == 0)/*&&(PS[j][1]<=0||PT[j][1]<=0)*/)
			{
				nf2 = 0; for (i = 20; i<28; i++)if (nf2<TB[j][i])nf2 = float(TB[j][i]);
				mf = float(TB[T][j] + 1);
				nf2 = (nf2*mf + float(TB[R][j] - TB[29][j] + 1))*VT[j][1]; F1[j] = nf2;
				if (nf1<nf2) { nf1 = nf2; m = j; }
			}
		if (G[m][0] == 0) G[m][0] = 15; else { p = 0; for (j = 4; j<28; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 15; m = j; p = 1; } }

		U = m;
		X1++;

		//
		//Я
		//
		nf = 0; m = 0; n = 0;
		for (j = 0; j<31; j++)F1[j] = 0;
		for (j = 4; j<28; j++)
			if (G[j][0] == 0 && VS[j][0] != 0 && PS[j][0]<0 && (TB[j][29] + TB[j][30] == 0) && (PS[j][1] <= 0 || PT[j][1] <= 0 || VS[j][4]>0))
				F1[j] = float(abs(PS[j][0])*(TB[C][j] + 1)*(TB[j][T] + 1)*VS[j][1] * VS[j][1]) / float(VS[j][0]);
		for (j = 4; j<28; j++)if (G[j][0] == 0)if (nf<F1[j]) { nf = F1[j]; m = j; }

		if (G[m][0] == 0) G[m][0] = 18; else { p = 0; for (j = 4; j<28; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 18; m = j; p = 1; } }

		n = m;
		X1++;


		if (VT[U][4] + TB[C][U]>VT[n][4] + TB[C][n]) { G[U][0] = 18; G[n][0] = 15; U = n; }
		else { G[U][0] = 15; G[n][0] = 18; }



		//
		//Ю,Э
		//
		nf = 0; mf = 0; m = 0; m1 = 0;
		for (j = 0; j<31; j++) { F1[j] = 0; F2[j] = 0; }
		for (j = 11; j<28; j++)
			if (G[j][0] == 0 && VS[j][0] != 0 && PS[j][0]<0 && (TB[j][29] + TB[j][30] == 0) && VS[j][0]>2)
			{
				nn1 = TB[j][T];    mm1 = 0; for (i = 20; i<28; i++)if (mm1<TB[j][i])mm1 = TB[j][i];
				if (nn1 == 0 && PS[j][0]<0)for (i = 20; i<28; i++)if (nn1<TB[j][i])nn1 = TB[j][i];
				if (VS[j][4] == 0) { nn1 = nn1 + 1; F2[j] = float(nn1); m1++; if (mm1 == 0.0)mm1 = 1.0; }
				F1[j] = float((mm1 + nn1)*abs(PS[j][0])) / float(VS[j][0] * (VS[j][4] + 1)*(TB[29][j] + 1));
			}

		//малый объем
			else if (VS[j][0] <= 2)F1[j] = float((TB[j][T] + 1)*abs(PS[j][0])) / float((VS[j][0] + 10)*(VS[j][4] + 1)*(TB[29][j] + 1));

			nf = 0; m = 0;
			for (j = 11; j<28; j++)if (G[j][0] == 0)if (nf<F1[j]) { nf = F1[j]; m = j; }

			n1 = 0;
			for (j = 0; j<31; j++) { F1[j] = 0; F2[j] = 0; }
			for (j = 11; j<28; j++)
				if (G[j][0] == 0 && VS[j][0] != 0 && PS[j][0]<0 && (TB[j][29] + TB[j][30] == 0) && VS[j][0]>2)
				{
					nn1 = TB[j][T];    mm1 = 0; for (i = 20; i<28; i++)if (mm1<TB[j][i])mm1 = TB[j][i];
					if (nn1 == 0 && PS[j][0]<0)for (i = 20; i<28; i++)if (nn1<TB[j][i])nn1 = TB[j][i];
					if (VS[j][4] == 0) { nn1 = nn1 + 1; F2[j] = float(nn1); n1++; if (mm1 == 0.0)mm1 = 1.0; }
					F1[j] = float((mm1 + nn1)*abs(PS[j][0])) / float(VS[j][0] * (VS[j][4] + 1)*(TB[29][j] + 1));
				}

			//малый объем
				else if (VS[j][0] <= 2)F1[j] = float((40 * TB[j][T] + 1)*abs(PS[j][0])) / float((VS[j][0] + 10)*(VS[j][4] + 1)*(TB[29][j] + 1));

				mf = 0; m1 = 0;
				for (j = 11; j<28; j++)if (G[j][0] == 0)if (mf<F1[j] && j != m) { mf = F1[j]; m1 = j; }

				{ nf1 = 0; nf2 = 0;
				for (j = 15; j<28; j++)if (nf1<nf1 + TB[m][j])nf1 = nf1 + float(TB[m][j]);
				for (j = 15; j<28; j++)if (nf2<nf2 + TB[m1][j])nf2 = nf2 + float(TB[m1][j]);
				if (2 * VS[m][4] + nf1>2 * VS[m1][4] + nf2) { nf1 = 2; nf2 = 1; }
				else if (2 * VS[m][4] + nf1<2 * VS[m1][4] + nf2) { nf1 = 1; nf2 = 2; }
				if (nf1 >= nf2)
				{
					if (G[m][0] == 0) G[m][0] = 27; else { p = 0; for (j = 4; j<28; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 27; p = 1; } }
					if (G[m1][0] == 0) G[m1][0] = 30; else { p = 0; for (j = 4; j<28; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 30; p = 1; } }
				}
				else
				{
					if (G[m][0] == 0) G[m][0] = 30; else { p = 0; for (j = 4; j<28; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 30; p = 1; } }
					if (G[m1][0] == 0) G[m1][0] = 27; else { p = 0; for (j = 4; j<28; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 27; p = 1; } }
				}

				X1 = X1 + 2;
				}

				X = X1;


				//
				//Л
				//

				nf = 0; m = 0;
				for (j = 28; j>4; j--)if (G[j][0] == 0 && nf<TB[j][30] * VS[j][0]) { nf = float(TB[j][30] * VS[j][0]); m = j; }

				if (G[m][0] == 0) G[m][0] = 10; else { p = 0; for (j = 28; j>4; j--) if (G[j][0] == 0 && p == 0) { G[j][0] = 10; p = 1; } }

				//
				//П
				//


				for (j = 0; j<31; j++) { F1[j] = 0; F2[j] = 0; }
				for (j = 4; j<28; j++)
					if (G[j][0] == 0)
						if (G[j][4]<0)
						{
							if ((VS[j][4] - VS[j][9]) != 0 && (TB[C][T])>4 * (TB[C][j] - TB[j][R]))
								F1[j] = float(VS[j][9] * VS[j][7] - VS[j][4]) / float((VS[j][7] - 1)*(VS[j][7] - 1));

							F1[j] = F1[j] * float((TB[j][R] + 1)*(TB[j][R] + 1)*VS[j][11] * (TB[T][j] + 1))
								/ float((VT[j][9] + 1)*(VT[j][9] + 1));
						}
				nf = 0; m = 0;
				for (j = 4; j<28; j++)if (nf<F1[j]) { nf = F1[j]; m = j; }
				if (G[m][0] == 0) G[m][0] = 14; else { p = 0; for (j = 4; j<28; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 14; p = 1; } }


				//
				//В 
				//

				for (j = 0; j<31; j++)F1[j] = 0;
				for (j = 4; j<14; j++)
					if (G[j][0] == 0)F1[j] = float(VT[j][4] * (TB[j][C] + TB[C][j] + 10 * TB[T][j] + 1));
				nf = 0; m = 0;
				for (j = 4; j<14; j++)if (nf<F1[j]) { nf = F1[j]; m = j; }
				if (G[m][0] == 0) G[m][0] = 8; else { p = 0; for (j = 4; j<28; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 8; p = 1; } }


				//
				//
				PERESTANOVKA_3();
				PERESTANOVKA_5();
				SETreSETdataFIELD();
				//
				for (j = 0; j<4; j++)G[j][0] = 0;
				//О
				//
				n = 0; m = 0;
				for (j = 0; j<4; j++)if (n<(TB[j][7] + TB[5][j] + 10 * (TB[10][j] - TB[29][j]))) { n = TB[j][7] + TB[5][j] + 10 * (TB[10][j] - TB[29][j]); m = j; }
				G[m][0] = 1;
				//
				//И
				//
				for (j = 0; j<31; j++)F1[j] = 0;
				for (j = 0; j<4; j++)
					if (G[j][0] == 0)F1[j] = float((TB[4][j] - TB[10][j])*VT[j][1] * VT[j][1] * VT[j][1] * G[j][2])
						/ float((TB[6][j] + 1)*(TB[j][8] + 1)*(TB[8][j] + TB[7][j] + 1)*(TB[8][j] + TB[7][j] + 1));

				nf = 0; m = 0;
				for (j = 0; j<4; j++)if (nf<F1[j]) { nf = F1[j]; m = j; }

				if (G[m][0] == 0) G[m][0] = 4; else { p = 0; for (j = 0; j<4; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 4; p = 1; } }


				//
				//А,Е
				//

				for (j = 0; j<31; j++)F1[j] = 0;

				for (j = 0; j<4; j++)
					if (G[j][0] == 0)F1[j] = float((TB[6][j] + TB[10][j])*(TB[0][j] + 2 * TB[29][j] + G[j][2] + 1));

				nf = 0; m = 0;
				for (j = 0; j<4; j++)if (nf<F1[j]) { nf = F1[j]; m = j; }

				if (nf == 0)
					for (j = 0; j<4; j++)
						if (G[j][0] == 0)
							if (TB[j][8]<TB[8][j])
								F1[j] = float((TB[j][4] + TB[6][j] - TB[4][j])*VT[j][1]) / float(VT[j][0]);
							else if (TB[j][4]<TB[4][j])
								F1[j] = float((TB[j][8] + TB[6][j] - TB[8][j])*VT[j][1]) / float(VT[j][0]);
							else  F1[j] = float((TB[6][j] + 1)*VT[j][1]) / float(VT[j][0]);

							nf = 0; m = 0;
							for (j = 0; j<4; j++)if (nf<F1[j]) { nf = F1[j]; m = j; }

							if (G[m][0] == 0) G[m][0] = 2; else { p = 0; for (j = 0; j<4; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 2; p = 1; } }

							n = 0;
							for (j = 0; j<4; j++)if (G[j][0] == 0) { n = j; }
							G[n][0] = 3;

							PERESTANOVKA_4();
							SETreSETdataFIELD();
							//
							//К
							//
							nf = 0; m = 0;
							for (j = 0; j<31; j++)F1[j] = 0;
							for (j = 11; j<28; j++)
								if (G[j][0] == 0 && TB[j][0] - TB[j][1]>0)
								{
									F1[j] = float((TB[j][0] - TB[j][1])*(TB[j][0] - TB[j][1])) / float(VS[j][0] * (TB[j][29] + 1));
									F1[j] = F1[j] * float(VS[j][7] * (1 + TB[j][8])*(1 + TB[6][j])*(1 + TB[6][j])*(1 + TB[j][5])*G[j][3]);
								}
							for (j = 11; j<28; j++)if (nf<F1[j]) { nf = F1[j]; m = j; }
							if (G[m][0] == 0) G[m][0] = 11; else { p = 0; for (j = 11; j<28; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 11; m = j; p = 1; } }
							xK = m;


							//пара Д,М
							//
							//Д
							//
							nf = 1000; m = 0; nf1 = 0; nf2 = 0; mf = 0;
							for (j = 0; j<31; j++) { F1[j] = 0; nf1 = nf1 + VS[j][0]; nf2 = nf2 + VS[j][1]; } nf1 = nf1 / 31; nf2 = nf2 / 31;
							for (j = 11; j<28; j++)if (G[j][0] == 0 && PS[j][2]>0)
							{
								F1[j] = (VS[j][0] - nf1) + 3 * (VS[j][1] - nf2); if (fabs(F1[j])<nf) { nf = fabs(F1[j]); m = j; }
							}

							n = m;
							if (G[n][0] == 0) G[n][0] = 12; else { p = 0; for (j = 11; j<28; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 12; n = j; p = 1; } }
							U = n;
							//
							//М
							//
							nf = 0; m = 0;
							for (j = 11; j<28; j++)F2[j] = 1000;
							for (j = 11; j<28; j++)
								if (G[j][0] == 0)
								{
									if (VS[j][4] == 0)nf = 1000; else nf = float(1 + 2 * float(4 * VS[j][9] - VS[j][4]) / float(VS[j][4]));

									if (VS[j][7] == 0)F2[j] = 1000;
									else F2[j] = nf / float(VS[j][7] * VT[j][7] * G[j][3] * VS[j][0] * VS[j][0]);
								}

							nf = 1000; m = 0;
							for (j = 11; j<28; j++)if (nf>F2[j]) { nf = F2[j]; m = j; }


							if (G[m][0] == 0) G[m][0] = 13; else { p = 0; for (j = 11; j<28; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 13; m = j; p = 1; } }
							Z = m;

							n = TB[29][U] + TB[U][29] + TB[U][10] + TB[U][xK] - TB[4][U] - TB[U][30] - TB[U][9];
							m = TB[29][Z] + TB[Z][29] + TB[Z][10] + TB[Z][xK] - TB[4][Z] - TB[Z][30] - TB[Z][9];

							if (n < m) { G[U][0] = 12; G[Z][0] = 13; }
							else { G[U][0] = 13; G[Z][0] = 12; }


							//
							PERESTANOVKA_6();
							SETreSETdataFIELD();
							//З Б Ч Х      Г
							//
							//З
							//
							for (j = 0; j<31; j++)F1[j] = 0;
							for (j = 14; j<28 - X; j++)
								if (G[j][0] == 0)
								{

									nf = float(3 * TB[2][j] + 3 * TB[j][2] + 10 * TB[j][13] + 15 * TB[j][7]);
									mf = float(2 * TB[j][0] + TB[j][1] + 5 * TB[29][j] + TB[j][29] + 10 * TB[j][5] + 10 * TB[6][j]);
									F1[j] = float(nf - mf);

								}

							nf = 0; m = 0;
							for (j = 14; j<28 - X; j++)if (nf<F1[j]) { nf = F1[j]; m = j; }

							if (G[m][0] == 0) G[m][0] = 17; else { p = 0; for (j = 14; j<28 - X; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 17; m = j; p = 1; } }


							//
							//Б
							//
							for (j = 0; j<31; j++)F1[j] = 0;
							nf1 = 0; n = 0;
							for (j = 14; j<28 - X; j++)if (G[j][0] == 0 && nf1<TB[j][29]) { nf1 = float(TB[j][29]); if (TB[j][29] != 0)n++; } nf1 = nf1 + 1;

							for (j = 14; j<28 - X; j++)
								if (G[j][0] == 0)
								{
									mf = 0; for (i = 19; i<28 - X; i++)if (mf<TB[j][i])mf = float(TB[j][i]); mf = mf + 1;
									if (TB[j][29] == 0 && TB[j][30] == 0 && TB[29][j] == 0 && TB[30][j] == 0)
									{
										nf = float((TB[24][j] + 1)) / float(TB[j][8] + 1); if (n == 1) nf = nf / float(TB[j][4] + 1);
									}
									else
									{
										nf = float((TB[j][29] * TB[j][29] + 1)*(TB[j][30] * TB[j][30] + 1)*(TB[j][25] * TB[j][25] + 1));
										if (n == 1) nf = nf*float((TB[j][29] * TB[j][29] * TB[j][29] + 1));
									}

									F1[j] = nf*mf*float((VS[j][9] + TB[0][j] + 1)*VT[j][1] * VS[j][1]) / float((TB[j][2] + 1));

								}
							nf = 0; m = 0;
							for (j = 14; j<28 - X; j++)if (nf<F1[j]) { nf = F1[j]; m = j; }

							if (G[m][0] == 0) G[m][0] = 20; else { p = 0; for (j = 14; j<28 - X; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 20; m = j; p = 1; } }

							X1 = m;

							//
							//Ч
							//
							for (j = 0; j<31; j++)F1[j] = 0;
							for (j = 14; j<28 - X; j++)
								if (G[j][0] == 0)
								{
									nf = float((TB[j][1] + TB[j][2] + 1)*(TB[j][1] + TB[j][2] + 1)) / float(2 * TB[j][0] + TB[j][3] + TB[4][j] + TB[j][12] + 1);
									nf1 = float((TB[j][5] + 1)*(TB[j][5] + 1)*(TB[j][5] + 1)*VS[j][1] * VT[j][1]) / float((TB[4][j] + 1)*(TB[12][j] + 1));
									F1[j] = nf*nf1;
								}
							nf = 0; m = 0;
							for (j = 14; j<28 - X; j++)if (nf<F1[j]) { nf = F1[j]; m = j; }

							if (G[m][0] == 0) G[m][0] = 23; else { p = 0; for (j = 14; j<28 - X; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 23; m = j; p = 1; } }

							//
							//X
							//
							for (j = 0; j<31; j++)F1[j] = -1000;
							for (j = 14; j<28 - X; j++)
								if (G[j][0] == 0)
									F1[j] = float(20 * TB[29][j] + 7 * TB[3][j] - TB[j][0] - 10 * TB[j][3] - 20 * TB[j][30]);

							nf = -1000; m = 0;
							for (j = 14; j<28 - X; j++)if (nf<F1[j]) { nf = F1[j]; m = j; }

							if (G[m][0] == 0) G[m][0] = 24; else { p = 0; for (j = 14; j<28 - X; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 24; m = j; p = 1; } }

							//
							// Ж Щ Ц Ш Ф
							//
							//Ж
							//
							for (j = 0; j<31; j++)F1[j] = -1000;
							for (j = 14; j<28 - X; j++)
								if (G[j][0] == 0)
								{
									nf = float(TB[0][j] + TB[j][1] + TB[j][2] + TB[j][4] + 10 * TB[j][12] + TB[24][j]);

									mf = float(4 * TB[j][0] + 4 * TB[j][30] + 10 * TB[j][9]);

									F1[j] = float(nf - mf);
								}
							nf = -1000; m = 0;
							for (j = 14; j<28 - X; j++)if (nf<F1[j]) { nf = F1[j]; m = j; }

							if (G[m][0] == 0) G[m][0] = 26; else { p = 0; for (j = 14; j<28 - X; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 26; m = j; p = 1; } }

							//
							//Щ
							//
							for (j = 0; j<31; j++)F1[j] = 0;
							for (j = 14; j<28 - X; j++)
								if (G[j][0] == 0)
								{
									nf = float(TB[24][j]); if (nf>TB[26][j])nf = float(TB[26][j]);
									F1[j] = float((nf + 1)*(TB[25][j] + 1)*(TB[26][j] + 1)*(TB[26][j] + 1)*(TB[X1][j] + 1));
									if (VS[j][1] == 1 && F1[j] == 0)F1[j] = 0;
									else
										F1[j] = float((TB[j][1] + TB[j][2] + 1)*(F1[j] + 1)*(F1[j] + 1)) / float((TB[j][0] + 1)*G[j][3] * VT[j][1] * VS[j][0]);

								}
							nf = 0; m = 0;
							for (j = 14; j<28 - X; j++)if (nf<F1[j]) { nf = F1[j]; m = j; }

							if (G[m][0] == 0) G[m][0] = 29; else { p = 0; for (j = 14; j<28 - X; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 29; m = j; p = 1; } }

							//
							//Ц
							//
							for (j = 0; j<31; j++)F1[j] = -1000;
							for (j = 14; j<28 - X; j++)
								if (G[j][0] == 0)
								{
									nf = float(TB[4][j]); if (2 * nf>TB[4][29])nf = 1;
									nf1 = TB[j][3] + 6 * TB[12][j] + 6 * nf + 2 * TB[j][29];

									mf = float(G[j][2] + 2 * TB[j][0] + TB[0][j] + TB[j][24] + TB[29][j] + 10 * TB[j][9] + 20 * TB[j][30]);

									F1[j] = float(nf1 - mf);
								}

							nf = -1000; m = 0;
							for (j = 14; j<28 - X; j++)if (nf<F1[j]) { nf = F1[j]; m = j; }

							if (G[m][0] == 0) G[m][0] = 28; else { p = 0; for (j = 14; j<28 - X; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 28; m = j; p = 1; } }

							//
							//Ш
							//
							for (j = 0; j<31; j++)F1[j] = 0;
							for (j = 14; j<28 - X; j++)
								if (G[j][0] == 0 && VS[j][1] != 1)
								{
									n1 = TB[j][1]; if (VS[j][0]>100 && 3 * n1>VS[j][0])n1 = 1;

									nf = float(TB[j][3]);
									nf1 = float((20 * TB[j][30] + 4 * TB[j][11] + 1));
									nf2 = float(10 * n1 + 32 * TB[24][j] + 10 * TB[25][j] + 10 * TB[26][j] + 10 * TB[29][j]);

									mf = float((TB[j][0] + TB[j][8] + 1)*(TB[4][j] + 1)*(TB[j][29] + 1)*(VS[j][0] + 10 * G[j][2]));

									F1[j] = float((nf1*nf + nf2 + 1)) / float(mf);
								}
							nf = 0; m = 0;
							for (j = 14; j<28 - X; j++)if (nf<F1[j]) { nf = F1[j]; m = j; }

							if (G[m][0] == 0) G[m][0] = 25; else { p = 0; for (j = 14; j<28 - X; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 25; m = j; p = 1; } }

							//
							//Г
							//
							for (j = 0; j<31; j++)F1[j] = 0;
							for (j = 14; j<28 - X; j++)
								if (G[j][0] == 0)
									F1[j] = float((TB[j][0] * TB[j][0] + 1)*(TB[j][12] + TB[j][8] + 1)*VT[j][1] * VT[j][4]) / float((VS[j][4] - TB[j][0] + TB[j][29] + 1)*VS[j][0]);

							nf = 0; m = 0;
							for (j = 14; j<28 - X; j++)if (nf<F1[j]) { nf = F1[j]; m = j; }

							if (G[m][0] == 0) G[m][0] = 19; else { p = 0; for (j = 14; j<28 - X; j++) if (G[j][0] == 0 && p == 0) { G[j][0] = 19; m = j; p = 1; } }


							//
							//Ф
							//
							for (j = 14; j<28 - X; j++) if (G[j][0] == 0)G[j][0] = 31;
							//


							PERESTANOVKA_7();
							SETreSETdataFIELD();


							for (i = 0; i<14; i++) { j = G[i][1]; n = ES[i]; A[n] = mJ[j]; }

							n1 = 14;
							for (i = 28; i<31; i++) { j = G[i][1]; n = ES[n1]; A[n] = mJ[j]; n1++; }
							n1 = 17;
							for (i = 28 - X; i<28; i++) { j = G[i][1]; n = ES[n1]; A[n] = mJ[j]; n1++; }
							n1 = 21;
							for (i = 14; i<19; i++) { j = G[i][1]; n = ES[n1]; A[n] = mJ[j]; n1++; }
							n1 = 26;
							for (i = 19; i<28 - X; i++) { j = G[i][1]; n = ES[n1]; A[n] = mJ[j]; n1++; }

							for (i = 0; i<31; i++)mJ[i] = A[i];




						NEN:
							//Вывод локального решения
							if (Nu == 0)fprintf(f4, "_%d_\n", sNN);
							//2.  Запись нового решения
							for (i = 0; i<NAt; i++)fprintf(f4, "%c", mJ[i]);
							c = ' '; if (NaP == 1)c = Zs; else if (Mn>0) c = '+';
							fprintf(f4, "\t%d\t%d\t%c[DAT]\n", Nu + 1, Mn, c);

	}

	//
	//выход 
	//
	fclose(f4);
	fclose(f1);
	fclose(f);

	fopen_s(&f1, "ouR.txt", "w");
	fopen_s(&f4, "tmp.txt", "r");
	while ((c = fgetc(f4)) != EOF)fprintf(f1, "%c", c);
	fclose(f4);
	fclose(f1);

	fopen_s(&f4, "tmp.txt", "w");
	c = ' '; fprintf(f4, "%c", c);
	fclose(f4);

	return 0;

}
///////////////////////////////////
//DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT DAT



///////////////////////////////////
int reduce() //Модуль выделения фрагментов с заданными свойствами и/или номерами
			 //            Реализовано выделение фрагментов по количеству используемых знаков алфавита Nz
			 //            Тип редукции =1 Второе число в строке - значение редукции
			 //            Значение редукции = 0 - исходный файл input.txt копируется в inT.txt без изменения
			 //            Значение редукции = 1 - из input.txt переносятся в inT.txt фрагменты, для которых Nz=NA
			 //            Значение редукции = 2 - из input.txt переносятся в inT.txt фрагменты, для которых Nz<NA
			 //            При наличии нескольких строк редукции одного типа применяется последняя
			 //            Предварительно с помощью программы получения исходной статистики должен быть получен файл saT.txt
			 //            для фрагментов исходного файла input.txt.
			 //Входные массивы: input.txt
			 //                 Ititle.txt
			 //                 saT.txt
			 //Выходной массив: inT.txt
			 //Рабочий массив:  tmp.txt
			 //
			 //return 0:   все в порядке
			 //
{
	//char s[500000];
	char c;
	int sNN;

	int L, NA, T, Sp, Zs, Nf;

	int i, Nz, Kf, NR, Rt, Rt1;
	int i4;

	FILE *f, *f1, *f2, *f4;


	fopen_s(&f, "input.txt", "r");

	fopen_s(&f1, "saT.txt", "r");
	fopen_s(&f2, "Ititle.txt", "r");
	fopen_s(&f4, "tmp.txt", "w");

	fscanf_s(f, "%d\n", &Nf, 1);//Переменная главного цикла

	fscanf_s(f2, "%d %d %d %d %d %c\n", &i, &L, &NA, &T, &Sp, &Zs, 1);//Тип языка и наличие пробела

	NR = Rt = Rt1 = 0;
	fscanf_s(f2, "%d\n", &NR); //Количество строк редукции
	for (i = 0; i<NR; i++)
	{
		fscanf_s(f2, "%d", &Rt);
		if (Rt == 1)fscanf_s(f2, "%d", &Rt1);
		while ((c = fgetc(f2)) != '\n');
	} //Значение редукции
	fclose(f2);

	if (NR != 0 && Rt1 != 0)
	{
		Kf = 0;
		//
		//Главный цикл
		//

		for (i4 = 0; i4<Nf; i4++)
		{
			//Чтение очередного текстового фрагмента

			//Заголовок фрагмента

			while ((c = fgetc(f)) == '\n'); //Пустые строки перед заголовком и первый подчерк
			fscanf_s(f, "%d\n", &sNN, 1); //Номер фрагмента
			fscanf_s(f, "%c\n", &c, 1);   //второй подчерк

										  //Текст фрагмента с учетом пробела
										  //i=0;           
										  //while((c=fgetc(f))!='\n')if(i<500000){s[i]=c;i++;} 
										  //lns=i;


			while ((c = fgetc(f1)) != 'Z'); c = fgetc(f1);//Количество знаков текста Nz из saT
			fscanf_s(f1, "%d", &Nz, 1);
			while ((c = fgetc(f1)) != '\n');

			if ((Rt1 == 1 && Nz == NA) || (Rt1 == 2 && Nz<NA))
			{
				fprintf(f4, "_%d_\n", sNN);
				while ((c = fgetc(f)) != '\n')fprintf(f4, "%c", c);
				fprintf(f4, "\n");
				Kf++;
			}
			else while ((c = fgetc(f)) != '\n');
		}

		fclose(f4);
		fclose(f1);
		fclose(f);

		fopen_s(&f, "inT.txt", "w");
		fopen_s(&f4, "tmp.txt", "r");
		fprintf(f, "%d\n", Kf);
		while ((c = fgetc(f4)) != EOF)fprintf(f, "%c", c);
		fclose(f4);
		fclose(f);

		fopen_s(&f4, "tmp.txt", "w");
		c = ' '; fprintf(f4, "%c", c);
		fclose(f4);

	}
	return 0;
}
///////////////////////////////////
///////////////////////////////////
int repeat(int NA) //проверка повторов
				   //
				   //входные массивы: euS.txt
				   //                 VAR.txt
				   //
{
	char Zs, s[124], c;
	int NS, i, j, jj, k, zp, ES[10000], EV[1000], m;

	FILE *f1, *f2, *f3;

	fopen_s(&f1, "enS.txt", "r");
	fopen_s(&f2, "Var.txt", "r");

	fscanf_s(f1, "%d\n", &NS, 1);//Количество множеств
	k = 0;
	for (i = 0; i<NS; i++)
	{
		for (j = 0; j<124; j++)s[j] = 0;
		for (j = 0; j<NA; j++)fscanf_s(f1, "%c\n", &s[j], 1);
		m = 0;
		for (j = 0; j<NA; j++)if (m == 0) { Zs = s[j]; s[j] = 'Ё'; for (jj = 0; jj<NA; jj++)if (Zs == s[jj])m = 1; s[j] = Zs; }
		if (m == 1) { ES[k] = i; k++; }
	}

	fscanf_s(f2, "%d\n", &NS, 1);//Количество вариантов
	zp = 0;
	for (i = 0; i<NS; i++)
	{
		for (j = 0; j<124; j++)s[j] = 0;
		j = 0; while ((c = fgetc(f2)) != '\n') { s[j] = c; j++; }
		//for(j=0;j<NA+1;j++)fscanf_s(f2,"%c\n",&s[j],1);
		m = 0;
		for (j = 0; j<NA + 1; j++)if (m == 0) { Zs = s[j]; s[j] = 'Ё'; for (jj = 0; jj<NA + 1; jj++)if (Zs == s[jj])m = 1; s[j] = Zs; }
		if (m == 1) { EV[zp] = i; zp++; }
	}

	fclose(f1);
	fclose(f2);

	if (k != 0 || zp != 0)
	{
		fopen_s(&f3, "ERR.txt", "w");
		fprintf(f3, " EUS\n");
		for (i = 0; i<k; i++)fprintf(f3, "%d\n", ES[i] + 1);
		fprintf(f3, " VAR\n");
		for (i = 0; i<zp; i++)fprintf(f3, "%d\n", EV[i] + 1);
		fclose(f3);
		return 1;
	}
	else return 0;
}
///////////////////////////////////
///////////////////////////////////
int generateS(int NK) //Генератор NK множеств знаков мощности NA не полностью пересекающихся друг с другом
					  //
					  //входные массивы: ASet.txt
					  //                 Ititle.txt
					  //выходной массив: enS.txt
					  //
{
	int L, T, NA, Sp;
	char Zs;
	char Space[125];//массив знаков
	int NS;

	unsigned int number, num, IK[125];
	char s[124000];

	errno_t err;

	int i, j, k = 0, m, p, zp;

	FILE *f, *f1, *f2;

	fopen_s(&f, "ASet.txt", "r");
	fopen_s(&f2, "Ititle.txt", "r");
	fopen_s(&f1, "enS.txt", "w");

	fscanf_s(f2, "%d %d %d %d %d %c\n", &i, &L, &NA, &T, &Sp, &Zs, 1);//Номер языка и мощность
	fclose(f2);

	fscanf_s(f, "%d %c\n", &NS, &Zs, 1);//Количество знаков

	if (NS>125)NS = 125;
	for (i = 0; i<NS; i++)fscanf_s(f, "%c\n", &Space[i], 1);//Чтение знаков
	fclose(f);

	for (j = 0; j<124000; j++)s[j] = 0;

	// Get NK x NA random integers in the range [ 1,NS ]

	k = 0;
	while (k<NK)
	{
		i = 0;
		for (j = 0; j<NA; j++)IK[j] = 0;
		while (i<NA)
		{
			err = rand_s(&number); if (err != 0)return 1;
			num = (unsigned int)((double)number / ((double)UINT_MAX + 1) * float(NS)) + 1;
			p = 0;
			for (j = 0; j<NA; j++)if (num == IK[j]) { p = 1; break; }
			if (p == 0) { IK[i] = num; i++; }
		}

		p = 0; zp = 0;
		for (i = 0; i<k; i = i + NA) { for (j = 0; j<NA; j++)if (IK[j] == s[i + j])p++; if (p>zp)zp = p; }
		if (zp != NA) { i = NA*k; for (j = 0; j<NA; j++)s[i + j] = IK[j]; k++; }

	}


	fprintf(f1, "%d\n", k);
	m = 0;
	for (i = 0; i<NK; i++) { for (j = 0; j<NA; j++)fprintf(f1, "%c", Space[s[m + j] - 1]); fprintf(f1, "\n"); m = m + NA; }

	fclose(f1);
	return 0;
}
///////////////////////////////////
///////////////////////////////////
int generateK(int NV, int R, char spaceZ, char MV[])
//Случайная выборка NV множеств из euS и дополнение их пробелом в режиме R
//
//В режиме R=0 множества замен выбираются из euS без перестановки и дополняются спереди знаком пробела spaceZ
//В режиме R=1 множества замен дополнительно переставляются случайным образом и случайно выбранный после перестановки
//             знак ставится на первое место (пробела) с заменой в своей бывшей позиции на знак  spaceZ
//
//входные массивы:       ASet.txt
//                       Ititle.txt
//                       enS.txt
//Формальные переменные: NV
//                       R
//                       spaceZ
//                       MV[NV*(NA+1)]
//
//RETUN 0 - все в порядке
//RETUN 1 - ошибка генератора случайгых чисел
//RETUN 2 - знак spaceZ принадлежит множеству ASet.txt
//
{
	int L, T, NA, Sp;
	char Zs;
	char Space[125];//массив знаков

	int NK, NS;

	unsigned int number, num, VK[1000], IK[125];
	char s[124000];
	unsigned int z[124000];

	errno_t  err;

	int i, j, k = 0, m, p, w, ii, jj, pp, kk, zp, flagS;

	FILE *f, *f1, *f2;

	fopen_s(&f, "ASet.txt", "r");
	fopen_s(&f2, "Ititle.txt", "r");
	fopen_s(&f1, "enS.txt", "r");

	fscanf_s(f2, "%d %d %d %d %d %c\n", &i, &L, &NA, &T, &Sp, &Zs, 1);//Номер языка и мощность
	fclose(f2);

	fscanf_s(f, "%d %c\n", &NS, &Zs, 1);//Количество знаков

	fscanf_s(f1, "%d\n", &NK, 1);//Количество множеств

	if (NS>125)NS = 125;
	for (i = 0; i<NS; i++)fscanf_s(f, "%c\n", &Space[i], 1);//Чтение знаков
	fclose(f);

	//Проверка знака пробела
	flagS = 0;
	for (i = 0; i<NS; i++)if (spaceZ == Space[i]) { flagS = 1; break; }

	if (flagS == 0)
	{
		for (j = 0; j<124000; j++)s[j] = 0;
		for (i = 0; i<124000; i = i + NA)for (j = 0; j<NA; j++)fscanf_s(f1, "%c\n", &s[i + j], 1);
		fclose(f1);

		for (j = 0; j<1000; j++)VK[j] = 0;

		// Get NV random integers in the range [ 1,NK ]

		i = 0; kk = 0;
		while (i<NV)
		{
			err = rand_s(&number); if (err != 0)return 1;
			num = (unsigned int)((double)number / ((double)UINT_MAX + 1) * float(NK)) + 1;
			p = 0;
			for (j = 0; j<NV; j++)if (num == VK[j]) { p = 1; break; }
			if (p == 0) { VK[i] = num; i++; }

			if (R != 0)
			{
				ii = 0;
				for (jj = 0; jj<NA; jj++)IK[jj] = 0;
				while (ii<NA)
				{
					err = rand_s(&number); if (err != 0)return 1;
					num = (unsigned int)((double)number / ((double)UINT_MAX + 1) * float(NA)) + 1;
					pp = 0;
					for (jj = 0; jj<NA; jj++)if (num == IK[jj]) { pp = 1; break; }
					if (pp == 0) { IK[ii] = num; ii++; }
				}
				pp = 0; zp = 0;
				for (ii = 0; ii<kk; ii = ii + NA) { for (jj = 0; jj<NA; jj++)if (IK[jj] == z[ii + jj])pp++; if (pp>zp)zp = pp; }
				if (zp != NA) { ii = NA*kk; for (jj = 0; jj<NA; jj++)z[ii + jj] = IK[jj]; kk++; }

			}
		}
		if (R == 0)
		{
			m = 0;
			for (i = 0; i<NV; i++)
			{
				MV[m] = spaceZ; w = (VK[i] - 1)*NA;
				for (j = 0; j<NA; j++)MV[m + j + 1] = s[w + j];
				m = m + NA + 1;
			}
		}
		else
		{
			m = 0;
			for (i = 0; i<NV; i++)
			{
				w = (VK[i] - 1)*NA; ii = i*NA;
				for (j = 0; j<NA; j++)MV[m + j + 1] = s[w + z[ii + j] - 1];
				err = rand_s(&number); if (err != 0)return 1;
				num = (unsigned int)((double)number / ((double)UINT_MAX + 1) * float(NA)) + 1;
				pp = MV[m + num];
				MV[m + num] = spaceZ; MV[m] = pp;
				m = m + NA + 1;
			}
		}
		return 0;
	}
	else return 2;
}
///////////////////////////////////
int pereBOR(int N, int M[], int NA, char U[], char ZP[], char uJ[], char Zs)//Подготовка массивов заданий для перебираемых
																			//                                                                      знаков опорного решения
																			//
																			//       int N     - количество перебираемых знаков - 3 или 4
																			//       int M[]   - номер позиции -1 перебираемых знаков в опорном решении U[]
																			//       int NA    - количество знаков опорного решения U[] (мощность алфавита)
																			//       char U[]  - опорное решение, размер решения NA
																			//       char ZP[] - знаки варианта перебора, всего N знаков на один вариант
																			//                   Всего вариантов 6, если N=3 и 24 - если N=4. Первый вариант - всегда начальный
																			//       char uJ[] - задание на операцию для каждого варианта, размер задания NA
																			//                   Задание соответствует последовательности знаков варианта ZP[]
																			//                   Знаки решения U[], не входящие в знаки варианта ZP[], представляются замещающим знаком Zs.
																			//                   Задание для начального варианта всегда содержит только замещающий знак Zs.
																			//       char Zs   - замещающий знак
																			//
																			//    Входные массивы:  нет
																			//    Выходные массивы: нет
																			//
																			//    return 0 - все в порядке
																			//    return 1 - неверное число   перебираемых знаков 
																			//    return 2 - неверные позиции перебираемых знаков
																			//
{
	int i, j, n, m, x;
	if (N<3 || N>4) return 1; //Неверное число знаков
	for (i = 0; i<N; i++)if (M[i]<0 || M[i]>NA - 1)return 2; //неверные позиции знаков
	for (i = 0; i<N; i++)for (j = 0; j<N; j++)if (i != j && M[i] == M[j])return 2; //неверные позиции знаков
	x = 1; while (x == 1) { x = 0; for (i = 1; i<N; i++)if (M[i]<M[i - 1]) { m = M[i - 1]; M[i - 1] = M[i]; M[i] = m; x = 1; } }//Упорядочивание позиций
	if (N == 3) n = NA * 6; else n = NA * 24;
	x = 0;
	for (i = 0; i<n; i++)uJ[i] = Zs;
	m = 0;
	for (i = 0; i<N; i++)ZP[i] = U[M[i]];
	m = m + N;
	if (N == 3)
	{
		ZP[m] = ZP[0]; ZP[m + 1] = ZP[2]; ZP[m + 2] = ZP[1]; m = m + N;
		ZP[m] = ZP[1]; ZP[m + 1] = ZP[0]; ZP[m + 2] = ZP[2]; m = m + N;
		ZP[m] = ZP[1]; ZP[m + 1] = ZP[2]; ZP[m + 2] = ZP[0]; m = m + N;
		ZP[m] = ZP[2]; ZP[m + 1] = ZP[0]; ZP[m + 2] = ZP[1]; m = m + N;
		ZP[m] = ZP[2]; ZP[m + 1] = ZP[1]; ZP[m + 2] = ZP[0]; m = m + N;
	}
	else
	{
		ZP[m] = ZP[0]; ZP[m + 1] = ZP[1]; ZP[m + 2] = ZP[3]; ZP[m + 3] = ZP[2]; m = m + N;
		ZP[m] = ZP[0]; ZP[m + 1] = ZP[2]; ZP[m + 2] = ZP[1]; ZP[m + 3] = ZP[3]; m = m + N;
		ZP[m] = ZP[0]; ZP[m + 1] = ZP[2]; ZP[m + 2] = ZP[3]; ZP[m + 3] = ZP[1]; m = m + N;
		ZP[m] = ZP[0]; ZP[m + 1] = ZP[3]; ZP[m + 2] = ZP[1]; ZP[m + 3] = ZP[2]; m = m + N;
		ZP[m] = ZP[0]; ZP[m + 1] = ZP[3]; ZP[m + 2] = ZP[2]; ZP[m + 3] = ZP[1]; m = m + N;

		ZP[m] = ZP[1]; ZP[m + 1] = ZP[0]; ZP[m + 2] = ZP[3]; ZP[m + 3] = ZP[2]; m = m + N;
		ZP[m] = ZP[1]; ZP[m + 1] = ZP[0]; ZP[m + 2] = ZP[2]; ZP[m + 3] = ZP[3]; m = m + N;
		ZP[m] = ZP[1]; ZP[m + 1] = ZP[2]; ZP[m + 2] = ZP[0]; ZP[m + 3] = ZP[3]; m = m + N;
		ZP[m] = ZP[1]; ZP[m + 1] = ZP[2]; ZP[m + 2] = ZP[3]; ZP[m + 3] = ZP[0]; m = m + N;
		ZP[m] = ZP[1]; ZP[m + 1] = ZP[3]; ZP[m + 2] = ZP[0]; ZP[m + 3] = ZP[2]; m = m + N;
		ZP[m] = ZP[1]; ZP[m + 1] = ZP[3]; ZP[m + 2] = ZP[2]; ZP[m + 3] = ZP[0]; m = m + N;

		ZP[m] = ZP[2]; ZP[m + 1] = ZP[0]; ZP[m + 2] = ZP[3]; ZP[m + 3] = ZP[1]; m = m + N;
		ZP[m] = ZP[2]; ZP[m + 1] = ZP[0]; ZP[m + 2] = ZP[1]; ZP[m + 3] = ZP[3]; m = m + N;
		ZP[m] = ZP[2]; ZP[m + 1] = ZP[1]; ZP[m + 2] = ZP[0]; ZP[m + 3] = ZP[3]; m = m + N;
		ZP[m] = ZP[2]; ZP[m + 1] = ZP[1]; ZP[m + 2] = ZP[3]; ZP[m + 3] = ZP[0]; m = m + N;
		ZP[m] = ZP[2]; ZP[m + 1] = ZP[3]; ZP[m + 2] = ZP[0]; ZP[m + 3] = ZP[1]; m = m + N;
		ZP[m] = ZP[2]; ZP[m + 1] = ZP[3]; ZP[m + 2] = ZP[1]; ZP[m + 3] = ZP[0]; m = m + N;

		ZP[m] = ZP[3]; ZP[m + 1] = ZP[0]; ZP[m + 2] = ZP[2]; ZP[m + 3] = ZP[1]; m = m + N;
		ZP[m] = ZP[3]; ZP[m + 1] = ZP[0]; ZP[m + 2] = ZP[1]; ZP[m + 3] = ZP[2]; m = m + N;
		ZP[m] = ZP[3]; ZP[m + 1] = ZP[1]; ZP[m + 2] = ZP[0]; ZP[m + 3] = ZP[2]; m = m + N;
		ZP[m] = ZP[3]; ZP[m + 1] = ZP[1]; ZP[m + 2] = ZP[2]; ZP[m + 3] = ZP[0]; m = m + N;
		ZP[m] = ZP[3]; ZP[m + 1] = ZP[2]; ZP[m + 2] = ZP[0]; ZP[m + 3] = ZP[1]; m = m + N;
		ZP[m] = ZP[3]; ZP[m + 1] = ZP[2]; ZP[m + 2] = ZP[1]; ZP[m + 3] = ZP[0]; m = m + N;
	}
	x = NA;
	if (N == 3) n = N * 6; else n = N * 24;
	for (i = N; i<n; i = i + N) { for (j = 0; j<N; j++)uJ[x + M[j]] = ZP[i + j]; x = x + NA; }
	return 0;
}

int newU(int NA, char R[], char U[], char uJ[], char Zs)//Формирование нового решения из опорного по заданию
														//
														//       int NA    - количество знаков опорного решения U[] (мощность алфавита)
														//       char U[]  - опорное решение, размер решения NA
														//       char R[]  - задание на операцию, размер задания NA
														//                   Знаки задания R[], не входящие в знаки U[], и повторяющиеся знаки (кроме первого)
														//                   представляются замещающим знаком Zs.
														//       char uJ[] - знаки решения U[], не входящие в R[], последовательно слева направо заменяют
														//                   замещающие знаки Zs в R[], результат - вклюая знаки R[] -  помещается в uJ[].
														//                   Размер нового решения uJ[] - NA.
														//       char Zs   - замещающий знак
														//
														//    Входные массивы:  нет
														//    Выходные массивы: нет
														//
														//    return 0 - решение сформировано по исходному    заданию
														//    return 1 - решение сформировано по исправленому заданию
														//
{
	char eJ[50];
	int i, j, p, m, x;
	m = 0;
	//Убираем знаки задания R, которых нет в решении U 
	for (i = 0; i<NA; i++) { p = 0; for (j = 0; j<NA; j++)if (R[i] != Zs && R[i] == U[j]) { p = 1; break; } if (p == 0) { R[i] = Zs; m = 1; } }
	//Убираем повторяющиеся знаки задания R
	for (i = 0; i<NA; i++)for (j = i + 1; j<NA; j++)if (R[i] != Zs && R[i] == R[j]) { R[j] = Zs; m = 1; }
	//Убираем знаки задания R из решения U
	x = 0;
	for (i = 0; i<NA; i++) { p = 0; for (j = 0; j<NA; j++)if (R[j] != Zs && R[j] == U[i]) { p = 1; break; } if (p == 0) { eJ[x] = U[i]; x++; } }
	//Формируем новое решение uJ
	x = 0;
	for (i = 0; i<NA; i++)if (R[i] != Zs)uJ[i] = R[i]; else { uJ[i] = eJ[x]; x++; }
	return m;
}
///////////////////////////////////
int OPR(int M, int N, char R[]) //Модуль применения залания на операцию к заданному опорному решению
								//                              для всех фрагметов дерева ouR.txt  и записи нового решения [О N] в ouR.txt
								//                             
								//      int M     - номер опорного решения. ВНИМАНИЕ: в ouR.txt должно быть хотя бы одно решение !!!
								//      int N     - номер операции, если N<0 то N=0, если N>99 то N=99
								//      char R[]  - задание на операцию
								//                  Размеры опроного решения и задания - NA из файла Ititle.txt
								//                  Если в задании используются знаки, отсутствующие в опорном решении или повторяющиеся,
								//                  то эти знаки игнорируются.
								//                  Тогда если в задании нет совпадающих с опроным решением знаков, то опорное решение
								//                  копируется в новое решение
								//                  Если в задании используются все знаки опорног решения, то задание копируется в ouR.txt
								//
								//Внешние функции: int newU(int NA,char R[],char U[],char uJ[],char Zs)
								//
								//Входные массивы: 
								//                 Ititle.txt
								//                 ouR.txt
								//                 
								//Выходной массив: ouR.txt
								//Рабочий массив:  tmp.txt
								//
								//return 0:   все в порядке
								//
								//
{
	int Nfu, Nu, L, NA, T, Sp;
	char c, Zs;
	int sNN, NaP, Mn;
	int i, i4, N1;

	char mJ[50], xJ[50];//массив встречающихся символов <= 140

	FILE *f1, *f2, *f4;

	fopen_s(&f1, "ouR.txt", "r");
	fopen_s(&f2, "Ititle.txt", "r");

	fopen_s(&f4, "tmp.txt", "w");

	fscanf_s(f1, "%d %d\n", &Nfu, &Nu, 1); //Количество фрагментов (Переменная главного цикла i4). Количество решений 

	fprintf(f4, "%d %d\n", Nfu, Nu + 1);
	fscanf_s(f2, "%d %d %d %d %d %c\n", &i, &L, &NA, &T, &Sp, &Zs, 1);//Тип языка, наличие пробела, замещающий знак Zs
	fclose(f2);

	//Корректировка номера начального решения и операции
	Mn = M;
	if (Mn<1) Mn = 1;
	if (Mn>Nu)Mn = Nu;
	N1 = N;
	if (N1<0) N1 = 0;
	if (N1>99)N1 = 99;
	//
	//Главный цикл
	//

	for (i4 = 0; i4<Nfu; i4++)
	{
		//Чтение очередной группы решений

		NaP = 0; //Флаг пустого решения

				 //
				 //Чтение начального решения  M из (&f1,"ouR.txt","r") и копирование решений в  (&f4,"tmp.txt","w")
		if (Nu != 0)
		{
			//(&f1,"ouR.txt","r")
			//Заголовок фрагмента ouR
			while ((c = fgetc(f1)) == '\n'); //Пустые строки перед заголовком и первый подчерк
			fscanf_s(f1, "%d\n", &sNN, 1); //Номер фрагмента
			fscanf_s(f1, "%c\n", &c, 1);   //второй подчерк
			fprintf(f4, "_%d_\n", sNN);
			if (Mn != 0)
			{
				//Пропуск предыдущих решений
				for (i = 0; i<Mn - 1; i++) { while ((c = fgetc(f1)) != '\n')fprintf(f4, "%c", c); fprintf(f4, "\n"); }
				//Начальное решение NAt знаков.  
				i = 0;  while (i<NA) { c = fgetc(f1); xJ[i] = c; i++; fprintf(f4, "%c", c); }
				while ((c = fgetc(f1)) != '\n')fprintf(f4, "%c", c); fprintf(f4, "\n");
			}
			//Пропуск оставшихся решений
			for (i = Mn; i<Nu; i++) { while ((c = fgetc(f1)) != '\n')fprintf(f4, "%c", c); fprintf(f4, "\n"); }
		}

		newU(NA, R, xJ, mJ, Zs);

		//Вывод локального решения
		if (Nu == 0)fprintf(f4, "_%d_\n", sNN);
		//2.  Запись нового решения
		for (i = 0; i<NA; i++)fprintf(f4, "%c", mJ[i]);
		c = ' '; if (NaP == 1)c = Zs; else if (Mn>0) c = '+';
		fprintf(f4, "\t%d\t%d\t%c[O%2d]\n", Nu + 1, Mn, c, N1);

	}

	//
	//выход 
	//
	fclose(f4);
	fclose(f1);


	fopen_s(&f1, "ouR.txt", "w");
	fopen_s(&f4, "tmp.txt", "r");
	while ((c = fgetc(f4)) != EOF)fprintf(f1, "%c", c);
	fclose(f4);
	fclose(f1);

	fopen_s(&f4, "tmp.txt", "w");
	c = ' '; fprintf(f4, "%c", c);
	fclose(f4);

	return 0;

}
///////////////////////////////////

///////////////////////////////////
int staR(int N, int M[])//Модуль статистической обработки результатов.
						//
						//Вектор решений M[N] содержит номера решений для обработки из файла ouR.txt,   N <=10. 
						//Если номер <1, то номер принимается равным 1. Все номера, превышающие количество решений в ouR.txt,
						//заменяются на номер последнего решения. Обработка решений осуществляется в порядке возрастания номеров.
						//Обрабатываются только открытые тексты типа Т=0 для языков L>0 и NA <= 45, не более 1000 фрагментов
						//за один раз, Nf <= 1000. Если количество точек шкалы в файле enS Ns=0, то точки шкалы определяют
						//упорядоченные плотные размеры фрагментов по форме inS для исходного файла.
						//
						//Шкала.
						//Определяются в файле enS в первой строке тремя целыми числами через пробел:Ns N0 Nd
						//Ns - количество точек шкалы, N0 - начальное значение, Nd - приращение
						//
						//Ограничение для точек шкалы: 0 <= Ns=0 <= 1000. Если Ns > 1000, то принимается Ns=1000.
						//При наличии заданной шкалы результаты для различных фрагментов, вычисленные относительно индивидуальных
						//плотных размеров, объединяются для ближайшей сверху к этим размерам точки шкалы
						//
						//Группы.
						//Определяются в файле enS после задания шкалы: количеством групп Ng и знаками каждой группы в отдельной строке.
						//
						//В общем случае 0 <= Ng <= NA.Если Ng > NA, то принимается Ng = NA.
						//Если количество групп в enS Ng=0, то итоговая статистика по группам не выводится, результаты индивидуального
						//сравнения для каждого решения выводятся как для одной группы (Ng = 1) из всех знаков алфавита.
						//Если количество знаков в группах меньше, чем знаков алфавита, то образуется дополнительная (последняя по порядку)
						//группа, которая содержит пропущенные в группах знаки алфавита из enU - как для каждого индивидуального решения,
						//так и в итоговой статистике по группам.
						//
						//При любом количестве и составе групп итоговая статитика ошибок О1-О4 не изменяется и остается одинаковой
						//
						//Входные массивы: ouR.txt
						//                 Ititle.txt
						//                 inU.txt
						//                 enU.txt
						//                 enQ.txt
						//Выходной массив: saR.txt
						//Рабочий массив:  tmp.txt
						//
						//return 0:   все в порядке
						//return 1:   T!=0
						//return 2:   L==0   
						//return 3:   NA > 45
						//return 4:   Nf > 1000
						//
{
	char eJJ[45], eJ[45], mJ[45], SA[45], TW[45];//Na <= 45
	char c, Zs;
	char NameMod[8];
	int ML[10], NMW;
	int sNN, NmM;

	int L, T, Sp, Nf, Na, NAt, Nfu, Nu, Nfs;

	int gV[45], pT[45];//Na <= 45
	int i, j, m, m2;
	int i4;
	int Unum;
	int sT, sNB, sNE, gN, qZ, SgN;
	int R1, R2;

	//СТАТ
	int Stat[1000][95], StatF[1000][3], BfStat[95];//Чмсло групп <= 45
	short int StatG[1000][90];//2*Na, Na <= 45
	char WJ[1000][45]; //Na <= 45
	int  hJ[1000][46]; //Na+1
	double StatR[1000][20];
	double StatO3[1000];
	int StF, eRR, O4Y;
	int SC[1000], nSC, lns1;//шкала <= 1000 точек
	int e1, e2, e3, e4, e5;
	int g = 0, g1 = 0, g3 = 0, k, p, lns, x;
	double w, w1, w2, w3, w4, w5, w6, w7;
	double v, v1, v2, v3;
	//

	FILE *f, *f1, *f2, *f3, *f4, *f5, *f7;

	fopen_s(&f, "enU.txt", "r");
	fopen_s(&f2, "Ititle.txt", "r");
	fopen_s(&f4, "enQ.txt", "r");


	Nf = N;

	fscanf_s(f2, "%d %d %d %d %d %c\n", &i, &L, &NAt, &T, &Sp, &Zs, 1);//Тип языка и наличие пробела
	fclose(f2);

	//Эталон
	fscanf_s(f, "%d", &Na, 1);//Число знаков
	while ((c = fgetc(f)) != '\n');
	i = 0;
	while (i<Na)
		while ((c = fgetc(f)) != '\t') { eJJ[i] = c; i++; }

	fscanf_s(f4, "%d %d %d\n", &sT, &sNB, &sNE, 1);
	fscanf_s(f4, "%d\n", &gN, 1);
	for (i = 0; i<Na; i++)gV[i] = 0;
	i = 0; x = 0;
	while (i<gN)
	{
		while ((c = fgetc(f4)) != '\n') { x++; for (j = 0; j<Na; j++)if (c == eJJ[j]) { gV[j] = i + 1; break; } } i++;
	}

	//Настройка для неполного количества знаков в группах (дополнительная группа)
	if (gN>0 && x<Na) { gN++; for (j = 0; j<Na; j++)if (gV[j] == 0)gV[j] = gN; }
	//Настройка для нулевого количества групп
	SgN = 1; if (gN == 0) { SgN = 0; gN = 1; for (i = 0; i<Na; i++)gV[i] = 1; }

	//Копирование и Упорядочение вектора номеров решений М[N]
	NMW = N; if (NMW>10)NMW = 10; for (i = 0; i<NMW; i++)ML[i] = M[i];
	j = 1; while (j != 0) { j = 0; for (i = 1; i<NMW; i++)if (ML[i]<ML[i - 1]) { m = ML[i - 1]; ML[i - 1] = ML[i]; ML[i] = m; j = 1; } }

	for (i = 0; i<3; i++)for (j = 0; j<1000; j++)StatF[j][i] = 0;          //СТАТ: начальная очистка
	nSC = sT;  if (nSC>1000)nSC = 1000;                             //СТАТ: подготовка количества точек шкалы
	if (nSC>0) { SC[0] = sNB; for (i = 1; i<nSC; i++)SC[i] = SC[i - 1] + sNE; } //СТАТ: подготовка точек шкалы с приращением

																				//
																				// Главный цикл РЕШЕНИЙ
																				//

	for (Unum = 0; Unum<NMW; Unum++)
	{
		fopen_s(&f1, "ouR.txt", "r");
		fopen_s(&f5, "tmp.txt", "w");

		if (Unum == 0) { fopen_s(&f7, "inU.txt", "r"); fscanf_s(f7, "%d", &Nfs, 1); }
		if (Unum>0)fopen_s(&f3, "saR.txt", "r");

		fscanf_s(f1, "%d %d\n", &Nfu, &Nu, 1);


		//************************************************************************************

		StF = Nfu;                   //СТАТ: число  фрагментов

									 //Проверка основных ограничений
		if (T != 0)    return 1;
		if (L == 0)    return 2;
		if (NAt>45)  return 3;
		if (Nfu>1000)return 4;

		//Корректировка номера решения
		if (ML[Unum]<1)ML[Unum] = 1;
		if (ML[Unum]>Nu)ML[Unum] = Nu;


		fprintf(f5, "%d %d\n", Nfu, Unum + 1);
		//************************************************************************************
		eRR = 0;                     //СТАТ: число ошибочных фрагментов

		for (i = 0; i<95; i++)for (j = 0; j<1000; j++)Stat[j][i] = 0;  //СТАТ: начальная очистка
		for (i = 0; i<90; i++)for (j = 0; j<1000; j++)StatG[j][i] = 0;
		for (i = 0; i<20; i++)for (j = 0; j<1000; j++)StatR[j][i] = 0.0;

		//
		//Цикл ВЫБОРКИ фрагментов
		//

		for (i4 = 0; i4<Nfu; i4++)
		{
			//Чтение частотной формы inU и формирование длины фрагмента StatF[0], полноты алфавита StatF[1]
			//                                          и частот hJ[Na] знаков WJ[Na] текущего решения
			if (Unum == 0)
			{
				//(&f7,"inU.txt","r")
				//Заголовок фрагмента inU
				while ((c = fgetc(f7)) == '\n'); //Пустые строки перед заголовком и первый подчерк
				fscanf_s(f7, "%d\n", &sNN, 1); //Номер фрагмента
				fscanf_s(f7, "%c\n", &c, 1);   //второй подчерк
				fscanf_s(f7, "%d", &qZ, 1);    //Число знаков
				while ((c = fgetc(f7)) != '\n');

				//Упорядоченое Текущее решение qZ знаков.  Может содержать знаки табуляции, которые будут исключены
				i = 0;  while (i<qZ)while ((c = fgetc(f7)) != '\t') { WJ[i4][i] = c; i++; } while ((c = fgetc(f7)) != '\n');
				//Число появления каждого знака кроме пробела и их сумма - плотный объем M 
				lns = 0; for (i = 0; i<qZ; i++) { fscanf_s(f7, "%d", &hJ[i4][i + 1], 1); lns = lns + hJ[i4][i + 1]; }
				hJ[i4][0] = qZ;
				while ((c = fgetc(f7)) != '\n');

				//Фиксация решения по отношению к шкале измерения по плотному объему M  
				lns1 = lns; if (nSC>0)for (i = 0; i<nSC; i++)if (lns <= SC[i]) { lns1 = SC[i]; break; }
				StatF[i4][0] = lns1; StatF[i4][1] = 1; if (qZ<Na)StatF[i4][1] = 0;
				StatF[i4][2] = lns;
			}

			//Чтение очередного решения из списка M[]из (&f1,"ouR.txt","r") и размера М текущего фрагмента из (&f6,"saT.txt","r")

			//(&f1,"ouR.txt","r")
			//Заголовок фрагмента ouR
			while ((c = fgetc(f1)) == '\n'); //Пустые строки перед заголовком и первый подчерк
			fscanf_s(f1, "%d\n", &sNN, 1); //Номер фрагмента
			fscanf_s(f1, "%c\n", &c, 1);   //второй подчерк

										   //Пропуск предыдущих решений
			for (i = 0; i<ML[Unum] - 1; i++)while ((c = fgetc(f1)) != '\n');

			//Текущее решение Na знаков.  Может содержать знаки табуляции, которые будут исключены
			i = 0;  while (i<Na)while ((c = fgetc(f1)) != '\t') { mJ[i] = c; i++; }

			//Имя текущего решения
			i = 0;  while ((c = fgetc(f1)) != '['); while ((c = fgetc(f1)) != ']') { NameMod[i] = c; i++; } NmM = i;

			//Пропуск оставшихся решений
			for (i = ML[Unum] - 1; i<Nu; i++)while ((c = fgetc(f1)) != '\n');

			//Коррекция эталона по решению
			for (i = 0; i<Na; i++) { eJ[i] = eJJ[i]; x = 0; for (j = 0; j<Na; j++)if (eJ[i] == mJ[j])x = 1; if (x == 0)eJ[i] = Zs; }

			//
			//Вывод решения и результатов индивидуального сравнения для текущего фрагмента
			//
			//Вывод эталона (один раз) и текущего решения по заданной шкале групп
			//                 в (&f5,"tmp.txt","w") с сохраненем предыдущего вывода из (&f3,"saR.txt","r")
			if (Unum == 0)
			{
				//(&f5,"tmp.txt","w")
				fprintf(f5, "_%d_ M=%d\n", sNN, lns);
				for (j = 0; j<gN; j++) { for (i = 0; i<Na; i++)if (gV[i] == j + 1)fprintf(f5, "%c", eJ[i]); fprintf(f5, "  "); }
				fprintf(f5, "\n");
				for (j = 0; j<gN; j++) { for (i = 0; i<Na; i++)if (gV[i] == j + 1)fprintf(f5, "%c", mJ[i]); fprintf(f5, "  "); }
				fprintf(f5, "\n");
			}
			else
			{
				//(&f3,"saR.txt","r") -> (&f5,"tmp.txt","w")
				fscanf_s(f3, "%d %d\n", &R1, &R2, 1);
				R1 = Unum + 1;
				//Копирование результатов saR в tmp
				for (i = 0; i<2 * R1; i++) { while ((c = fgetc(f3)) != '\n')fprintf(f5, "%c", c); fprintf(f5, "\n"); }
				//Текущее решение
				for (j = 0; j<gN; j++) { for (i = 0; i<Na; i++)if (gV[i] == j + 1)fprintf(f5, "%c", mJ[i]); fprintf(f5, "  "); }
				fprintf(f5, "\n");
			}

			//Сравнение решения с эталоном
			for (i = 0; i<Na; i++)SA[i] = TW[i] = 0; m = m2 = 0; x = 0;
			for (i = 0; i<Na; i++)if (mJ[i] != eJ[i])
			{
				SA[i] = 1; m++; if (eJ[i] == Zs) { TW[i] = 1; m2++; }
				if (mJ[i] != Zs)for (j = 0; j<hJ[i4][0]; j++)if (mJ[i] == WJ[i4][j])x = x + hJ[i4][j + 1];
			}
			m = m - m2;
			if (m == 0 && m2 != 0)m = m2;
			//Сохранение результатов сравнения для итоговой обработки и вывод результата сравнения по заданной шкале групп
			if (m != 0)
			{
				Stat[eRR][0] = StatF[i4][0]; Stat[eRR][1] = m; Stat[eRR][2] = m2; Stat[eRR][3] = hJ[i4][0];
				for (j = 0; j<gN; j++) { Stat[eRR][4 + j] = 0; Stat[eRR][4 + Na + j] = 0; }
				StatO3[eRR] = double(x) / double(StatF[i4][2]);
				for (j = 0; j<gN; j++)
				{
					g = 0;
					for (i = 0; i<Na; i++)
						if (gV[i] == j + 1)
							if (SA[i] != 0)
							{
								fprintf(f5, "-"); g = 1;
								for (x = 0; x<Na; x++)if (mJ[i] != Zs && mJ[i] == eJ[x] && gV[i] != gV[x]) { Stat[eRR][4 + Na + j] = 1; break; }
							}
							else fprintf(f5, " ");
							Stat[eRR][4 + j] = g; fprintf(f5, "  ");
				}

				if (m2 == 0)fprintf(f5, " ----%d\n", m); else fprintf(f5, " ----%d   %d\n", m, m2);

				eRR++;

			}
			else  fprintf(f5, "\n");

		} //i4 - end цикла фрагментов

		  //
		  //Итоговая статистика
		  //
		  //Вывод итоговой статистики текущего решения по выборке Nfu фрагментов
		  //

		if (Unum != 0)while ((c = fgetc(f3)) != EOF)fprintf(f5, "%c", c);//Предыдущие итоги

		fprintf(f5, "\nSolution=%d\t[", M[Unum]);
		for (i = 0; i<NmM; i++)fprintf(f5, "%c", NameMod[i]);
		fprintf(f5, "]\tL=%d\tNA=%d\tT=%d", L, NAt, T);
		fprintf(f5, "\tTexT=%d\tERR=%d\n\n", StF, eRR);
		//Упорядочивание массива статистики Stat и StatO3 по возрастанию объема М
		j = 1;
		while (j>0)
		{
			j = 0;
			for (i = 0; i<eRR - 1; i++)
				if (Stat[i + 1][0]<Stat[i][0])
				{
					for (k = 0; k<95; k++)BfStat[k] = Stat[i][k];
					for (k = 0; k<95; k++)Stat[i][k] = Stat[i + 1][k];
					for (k = 0; k<95; k++)Stat[i + 1][k] = BfStat[k];
					w = StatO3[i]; StatO3[i] = StatO3[i + 1]; StatO3[i + 1] = w;
					j = 1;
				}
		}

		//Формирование групповой статистики StatR по заданной шкале измерения
		k = 0; p = 0;
		while (p<eRR)
		{
			m = Stat[p][0]; g1 = g3 = Stat[p][1]; j = g = 0; e1 = e4 = e5 = 0; e2 = e3 = Stat[p][2]; v1 = v2 = double(Stat[p][1]) / double(Stat[p][3]);
			v = w = w4 = w5 = 0.0; w6 = w7 = 0.5; w1 = w3 = StatO3[p]; for (x = 0; x<gN; x++) { StatG[k][x] = 0; StatG[k][Na + x] = 0; }

			for (i = 0; i<eRR; i++)
				if (m == Stat[i][0])
				{
					v3 = double(Stat[i][1]) / double(Stat[i][3]);
					v = v + v3; w = w + StatO3[i]; if (StatO3[i]<w1)w1 = StatO3[i]; if (StatO3[i]>w3)w3 = StatO3[i];
					if (Stat[i][3]<Na)
					{
						e4++;
						if (Stat[i][2] != 0)
						{
							e5++; e1 = e1 + Stat[i][2];
							if (2 * Stat[i][3]>Na)w5 = double(Stat[i][2]) / double(Na - Stat[i][3]); else w5 = double(Stat[i][2]) / double(Stat[i][3]);
							w4 = w4 + w5;
							if (w5<w6)w6 = w5; if (w5>w7)w7 = w5;
						}
					}
					for (x = 0; x<gN; x++)StatG[k][x] = StatG[k][x] + Stat[i][4 + x];          //Суммы по группам
					for (x = 0; x<gN; x++)StatG[k][Na + x] = StatG[k][Na + x] + Stat[i][4 + Na + x]; //Суммы по группам
					if (v3<v1)v1 = v3; if (v3>v2)v2 = v3;
					g++;
				}

			StatR[k][0] = double(m);   //Точка шкалы или размер фрагмента, если шкала не задана
									   //   StatR[k][1]
			StatR[k][2] = double(g);   //Количество ошибочных фрагментов, отнесенных к точке шкалы
			StatR[k][3] = v;           //Суммарная нормированная ошибка О2
			StatR[k][4] = v1;          //Минимальная  нормированная ошибка О2
			StatR[k][5] = v2;          //Максимальная нормированная ошибка О2
			StatR[k][8] = w;           //Суммарное значение О3
			StatR[k][9] = w1;          //Минимальная  ошибка О3
			StatR[k][10] = w3;         //Максимальная ошибка О3
									   //   StatR[k][11]
			StatR[k][12] = w4;         //Суммарное значение  О4н
			StatR[k][13] = w6;         //Минимальная  ошибка О4н
			StatR[k][14] = w7;         //Максимальная ошибка О4н
			StatR[k][15] = double(e4); //Кол-во фрагментов с неполным алфавитом
			StatR[k][16] = double(e5); //Кол-во фрагментов с ошибкой О4
			StatR[k][17] = double(e1); //Суммарное значение  О4

			p = p + g; k++;               //k- количество сформированных точек шкалы
		}
		for (i = 0; i<k; i++)if (StatR[i][2] != 0)StatR[i][3] = StatR[i][3] / StatR[i][2];     //Средняя ошибка О2H
		for (i = 0; i<k; i++)if (StatR[i][2] != 0)StatR[i][8] = StatR[i][8] / StatR[i][2];     //Средняя ошибка О3
		for (i = 0; i<k; i++)if (StatR[i][16] != 0)StatR[i][12] = StatR[i][12] / StatR[i][16]; //Средняя ошибка О4н
		for (i = 0; i<k; i++)if (StatR[i][16] != 0)StatR[i][17] = StatR[i][17] / StatR[i][16]; //Средняя ошибка О4
		for (i = 0; i<k; i++)if (StatR[i][15] != 0)StatR[i][15] = StatR[i][16] / StatR[i][15]; //A О4

		g3 = 0;
		for (i = 0; i<k; i++)
		{
			g = g1 = 0; w = w1 = w2 = 0.0;
			m = int(StatR[i][0]);
			for (j = 0; j<eRR; j++)
				if (m == Stat[j][0])
				{
					v3 = double(Stat[j][1]) / double(Stat[j][3]);
					w = w + (v3 - StatR[i][3])*(v3 - StatR[i][3]);
					w1 = w1 + (StatO3[j] - StatR[i][8])*(StatO3[j] - StatR[i][8]);

					if (Stat[j][3]<Na)
						if (Stat[j][2] != 0)
						{
							if (2 * Stat[j][3]>Na)w5 = double(Stat[j][2]) / double(Na - Stat[j][3]); else w5 = double(Stat[j][2]) / double(Stat[j][3]);
							w2 = w2 + (w5 - StatR[i][12])*(w5 - StatR[i][12]);
						}
				}
			if (StatR[i][2] != 0)StatR[i][6] = sqrtf(float(w / StatR[i][2]));     //Стандартное отклонение средней ошибки О2
			if (StatR[i][2] != 0)StatR[i][11] = sqrtf(float(w1 / StatR[i][2]));   //Стандартное отклонение средней ошибки О3
			if (StatR[i][16] != 0)StatR[i][18] = sqrtf(float(w2 / StatR[i][16])); //Стандартное отклонение средней ошибки О4
		}

		//Общее количество фрагментов в данной точке шкалы и количество фрагментов с полным алфавитом
		for (i = 0; i<k; i++)
		{
			m = int(StatR[i][0]); StatR[i][1] = StatR[i][7] = 0.0;
			for (j = 0; j<Nfu; j++)
				if (m == StatF[j][0]) { StatR[i][1] = StatR[i][1]++; StatR[i][7] = StatR[i][7] + double(StatF[j][1]); }
		}
		//Наличие ошибки О4
		O4Y = 0; for (i = 0; i<k; i++)if (StatR[i][16] != 0.0)O4Y = 1;



		fprintf(f5, " N\tK\tNA\tO1H\tO2H\tO2Hmin\tO2Hmax\tSD O2H\t\tO3H\tO3Hmin\tO3Hmax\tSD O3H");

		if (O4Y == 1)fprintf(f5, "\tN O4\t О4\tA  O4\tB  O4H\tO4Hmin\tO4Hmax\tSD O4H");

		fprintf(f5, "\n");

		for (i = 0; i<k; i++)
		{
			m = int(StatR[i][0]); g = int(StatR[i][1]); w4 = StatR[i][2] / StatR[i][1]; w = StatR[i][3]; w1 = StatR[i][4]; w2 = StatR[i][5]; w3 = StatR[i][6];
			p = int(StatR[i][7]);

			fprintf(f5, " %d\t%d\t%d\t%4.2f\t%6.4f\t%6.4f\t%6.4f\t%6.4f", m, g, p, w4, w, w1, w2, w3);

			w = StatR[i][8]; w1 = StatR[i][9]; w2 = StatR[i][10]; w3 = StatR[i][11];

			fprintf(f5, "\t\t%6.4f\t%6.4f\t%6.4f\t%6.4f", w, w1, w2, w3);

			if (O4Y == 1)
			{
				w = StatR[i][12]; w1 = StatR[i][13]; w2 = StatR[i][14]; w3 = StatR[i][18]; w4 = StatR[i][15]; w7 = StatR[i][17]; j = int(StatR[i][16]);

				fprintf(f5, "\t%4d\t%6.3f\t%6.4f\t%6.4f\t%6.4f\t%6.4f\t%6.4f", j, w7, w4, w, w1, w2, w3);
			}

			fprintf(f5, "\n");
		}

		//Текущие группы
		if (SgN>0)
		{
			fprintf(f5, "\n N\tK");
			for (j = 0; j<gN; j++) { p = 0; fprintf(f5, "\t"); for (i = 0; i<Na; i++)if (gV[i] == j + 1) { fprintf(f5, "%c", eJJ[i]); p++; } pT[j] = p / 8; }

			if (gN>1)
			{
				fprintf(f5, "\t"); for (j = 0; j<gN; j++) { fprintf(f5, "\t"); for (i = 0; i<Na; i++)if (gV[i] == j + 1)fprintf(f5, "%c", eJJ[i]); }
			}

			fprintf(f5, "\n");

			for (i = 0; i<k; i++)
			{
				fprintf(f5, " %d\t%d", int(StatR[i][0]), int(StatR[i][1]));
				for (x = 0; x<gN; x++) { if (x>0)for (p = 1; p<pT[x - 1] + 1; p++)fprintf(f5, "\t"); fprintf(f5, "\t%d", StatG[i][x]); }

				if (gN>1)
				{
					for (p = 0; p<pT[gN - 1] + 1; p++)fprintf(f5, "\t"); for (x = 0; x<gN; x++) { if (x>0)for (p = 1; p<pT[x - 1] + 1; p++)fprintf(f5, "\t"); fprintf(f5, "\t%d", StatG[i][Na + x]); }
				}

				fprintf(f5, "\n");
			}
		}
		fclose(f1);
		fclose(f5);

		if (Unum == 0)fclose(f7);

		if (Unum>0)fclose(f3);

		fopen_s(&f3, "saR.txt", "w");
		fopen_s(&f5, "tmp.txt", "r");
		while ((c = fgetc(f5)) != EOF)fprintf(f3, "%c", c);
		fclose(f3);
		fclose(f5);

		fopen_s(&f5, "tmp.txt", "w");
		c = '\n'; fprintf(f1, "%c", c);
		fclose(f5);

		//************************************************************************************
	}// Unum - end цикла решений

	return 0;
}

struct text_info
{
	int lower_array[50];
	int upper_array[50];  // Массивы для подсчёта встречаемости каждого символа алфавита
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
	double conjugation_index; // Индекс сопряжения B и D
	double distinguish_index; // Индекс отличения D1 и D2
	int scale_point; // Точка шкалы
};

int staT(int NinFile)//Модуль статистической обработки текстовых фрагментов (текстов)
					 //
					 //       int NinFile - указывает входной файл для обработки
					 //                     NinFile==0 -input.txt   NinFile==1 -inT.txt
					 //                     Если  NinFile!=0 или NinFile!=1 то принимается NinFile==0
					 //
					 //Обрабатываются только открытые тексты типа Т=0 для языков L>0 и NA <= 45, не более 1000 фрагментов
					 //за один раз, Nf <= 1000.
					 //
					 //Для определения знака пробела может использоваться файл code.txt Если в нем меньше фрагментов,
					 //чем в исходном файле, то они начнут циклически повторяться.
					 //
					 //Шкала.
					 //Определяются в файле enQ в первой строке тремя целыми числами через пробел:Ns N0 Nd
					 //Ns - количество точек шкалы, N0 - начальное значение, Nd - приращение
					 //
					 //Ограничение для точек шкалы: 0 <= Ns <= 1000. Если Ns > 1000, то принимается Ns=1000.
					 //При наличии заданной шкалы результаты для различных фрагментов, вычисленные относительно индивидуальных
					 //плотных размеров, объединяются для ближайшей сверху к этим размерам точки шкалы
					 //
					 //Если Ns=0, то точки шкалы определяются фактическими упорядоченными плотными размерами фрагментов
					 //           по форме inS для исходного файла.
					 //Если N0==0 и Nd !=0, то производится сдвиг шкалы  N0=Nd.
					 //Если N0==0 и Nd ==0, то происходит переход на шкалу фактических плотных размеров Ns=0.
					 //Если Ns!=0 и N0 !=0 и Nd ==0, то фиксируется единственная точка шкалы N0.
					 //
					 //Внешние структуры: struct text_info
					 //
					 //Входные массивы: inT.txt или input.txt   - в зависимости от значения параметра NinFile
					 //                 Ititle.txt
					 //                 enQ.txt
					 //                 code.txt
					 //Выходной массив: saT.txt
					 //
					 //
					 //return 0:   все в порядке
					 //return 1:
					 //

{
	int language_type; // Тип языка: «-1» - язык текста не определен, «0» - русский, «1» - английский
	int cardinality; // Мощность алфавита
	int text_type; // Тип текста: 0 – открытый, 1 – резерв, 2 – учебный, 3 – прикладной
	int space_presence; // Наличие пробела: «-1» - наличие пробела не определено, «0» - нет, «1» -есть
	int error = 0; // Количество ошибок типа: NA < Z
	int SymbolN = 0, StrNum = 1;
	int fragment_num;

	ifstream in;
	ifstream title;
	ofstream Bout;
	string str, strtitle;

	if (title.fail())return 1; else title.open("Ititle.txt");
	if (NinFile == 1)in.open("inT.txt"); else in.open("input.txt");

	Bout.open("saT.txt");

	if (in.eof())
	{
		Bout.close();
		in.close();
		return 1;
	}

	getline(in, str);
	fragment_num = stoi(str);

	if (fragment_num > 1000)fragment_num = 1000;
	if (fragment_num <= 0)return 1;

	int count = -1;

	text_info *data = new text_info[1000];

	getline(title, strtitle, ' '); // Номер схемы
	getline(title, strtitle, ' '); // Номер языка
	language_type = stoi(strtitle);
	getline(title, strtitle, ' '); // Мощность алфавита
	cardinality = stoi(strtitle);

	if (cardinality == 0)
	{
		cin.get();
		Bout.close();
		title.close();
		in.close();
		return 1;
	}
	else
	{
		getline(title, strtitle, ' '); // Тип текста
		text_type = stoi(strtitle);
		getline(title, strtitle, ' '); // Наличие пробела
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

			if (fragment_num > Nc) // Если фрагментов больше, чем в code
			{
				while (getline(code, strcode)) // Считываем всё, что есть
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
				for (count = count + 1; count < fragment_num; count++) // Циклически повторяем
				{
					data[count].space_symbol = data[(fragment_num%count)].space_symbol;
				}
			}
			else // Фрагментов не больше, чем в code - считываем в обычном режим
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
		////////инициализация стандартного знака пробела
		else for (; count < fragment_num; count++) // Циклически повторяем
		{
			data[count].space_symbol = ' ';
		}
		////////
		count = -1;
		string strWithoutSpace;

		for (int y = 0; y < fragment_num; y++)
		{
			getline(in, str, '_'); // Поиск следующего фрагмента
			getline(in, str); // Нашли фрагмент, его номер считываем до конца
			getline(in, str); // Сама строка

			count++;
			// Присваивание значений класса
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
			for (int i = 0; i < 50; i++)
				data[count].upper_array[i] = 0;
			for (int i = 0; i < 50; i++)
				data[count].lower_array[i] = 0;
			for (int i = 0; i < 33; i++)
				for (int j = 0; j < 33; j++)
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
					strWithoutSpace[m] = str[i]; //  Запись в строку без пробела
					m++;
				}
			}

			if (m != 0)
				strWithoutSpace.resize(m); // Удаление лишних символов


										   // Формирование массива символов
			int SymbolPresence = 0;
			SymbolN = 0;
			data[count].alphabet[SymbolN] = strWithoutSpace[0];
			for (int j = 1; j < int(strWithoutSpace.length()); j++)
			{
				SymbolPresence = 0;
				for (int i = 0; i <= SymbolN; i++)
				{
					if (strWithoutSpace[j] == data[count].alphabet[i]) // Проверка по всему массиву, был ли такой символ уже
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

			// Массив диграмм, биграмм, символов
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

		// Подсчёт статистики
		for (int i = 0; i < fragment_num; i++)
		{
			// Подсчёт биграммы
			for (int j = 0; j < data[i].symbol_alphabet; j++)
				for (int k = 0; k < data[i].symbol_alphabet; k++)
					if ((data[i].digrams_second_array[j][k] != 0) || (data[i].digrams_first_array[j][k] != 0))
						data[i].bigrams_numalt++;
			// Подсчёт относительной частоты пробела
			data[i].rel_space = (double)data[i].space_num / (data[i].symbol_num + data[i].space_num);

			// Подсчёт индекса совпадений
			for (int j = 0; j < data[i].symbol_alphabet; j++)
				if (data[i].upper_array[j] != 0)
					data[i].coincidence_index = data[i].coincidence_index + data[i].upper_array[j] * (data[i].upper_array[j] - 1);
			data[i].coincidence_index = data[i].coincidence_index / data[i].symbol_num;
			data[i].coincidence_index = data[i].coincidence_index / (data[i].symbol_num - 1);

			// Подсчёт используемых биграмм
			for (int k = 0; k < data[i].symbol_alphabet; k++)
				for (int j = 0; j < data[i].symbol_alphabet; j++)
					if (data[i].bigrams_array[k][j] > 0)
						data[i].bigrams_num++;

			// Подсчёт используемых диграмм 1
			for (int k = 0; k < data[i].symbol_alphabet; k++)
				for (int j = 0; j < data[i].symbol_alphabet; j++)
					if (data[i].digrams_first_array[k][j] > 0)
						data[i].digram_first_num++;

			// Подсчёт использумых диграмм 2
			for (int k = 0; k < data[i].symbol_alphabet; k++)
				for (int j = 0; j < data[i].symbol_alphabet; j++)
					if (data[i].digrams_second_array[k][j] > 0)
						data[i].digram_second_num++;

			// Подсчёт индекса сопряжения B и D и индекса отличения D1 и D2
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

		// Вывод статистики по каждому фрагменту
		Bout << fragment_num << "\n";

		for (int i = 0; i < fragment_num; i++)
		{
			Bout << "_" << i + 1 << "_" << "\t";
			Bout << "N=" << data[i].space_num + data[i].symbol_num << "\t";  // Всего символов в фрагменте

			if (data[i].symbol_num > 99999)
			{
				Bout << "M=" << data[i].symbol_num << "\t";  // Символов без учёта пробела
				Bout << "S=" << data[i].space_num << "\t";
			} // Количество пробелов
			else
			{
				Bout << "M=" << data[i].symbol_num << "\t\t";  // Символов без учёта пробела
				Bout << "S=" << data[i].space_num << "\t";
			} // Количество пробелов
			Bout << "Z=" << data[i].symbol_alphabet << "\t"; // Количество используемых знаков алфавита
			Bout << "B=" << data[i].bigrams_num << "\t"; // Количество биграмм
			Bout << "D1=" << data[i].digram_first_num << "\t"; // Количество диграмм 1
			Bout << "D2=" << data[i].digram_second_num << "\t"; // Количество диграмм 2
			Bout.precision(4);
			Bout << fixed << "C=" << data[i].conjugation_index << "\t"; // Индекс сопряжения
			Bout << fixed << "D=" << data[i].distinguish_index << "\t"; // Индекс отличения
			Bout << fixed << "X=" << data[i].coincidence_index << "\t"; // Индекс совпадения
			if (cardinality < data[i].symbol_alphabet)
			{
				error++;
				Bout << "----";
			}
			Bout << "\n\n";
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

		if (StartSize == 0 && Steps != 0 && StepSize != 0)StartSize = StepSize; //Сдвиг шкалы при нулевом начальном значении
		if (StartSize == 0 && Steps != 0 && StepSize == 0)Steps = 0;            //Переход на шкалу фактических плотных размеров

		EndSize = StartSize + (Steps - 1) * StepSize;

		Size[0] = StartSize;

		// Массивы со статистикой по точкам шкалы
		int FragmentNumber[1000]; // Число фрагментов в каждой точке шкалы

		double MinBigramNumber[1000], MaxBigramNumber[1000]; // Минимальное число биграмм, максимальное число биграмм
		double AverBigramNumber[1000], StandDevBigramNumber[1000]; // Среднее число биграмм и СКО по биграммам

		int FullFragments[1000]; // Число фрагментов, использующих все знаки алфавита

		double MinSymbolAlphabet[1000], MaxSymbolAlphabet[1000]; // Минимальное число используемых знаков алфавита, максимальное число
		double AverSymbolAlphabet[1000], StandDevSymbolAlphabet[1000]; // Среднее число используемых знаков алфавита и СКО

		int MinSpaceNumber[1000], MaxSpaceNumber[1000]; // Минимальное и максимальное число пробелов
		double AverSpaceNumber[1000], StandDevSpaceNumber[1000]; // Среднее число пробелов и СКО по пробелам

		double MinSpaceRel[1000], MaxSpaceRel[1000]; // Минимальное и максимальное число пробелов (относ.)
		double AverSpaceRel[1000], StandDevSpaceRel[1000]; // Среднее число пробелов (относит.) и СКО по пробелам

		int MinFirstDigramNumber[1000], MaxFirstDigramNumber[1000]; // Число диграмм (1)
		double AverFirstDigramNumber[1000], StandDevFirstDigramNumber[1000]; // Среднее число диграмм (1) и СКО

		int MinSecondDigramNumber[1000], MaxSecondDigramNumber[1000]; // Число диграмм (2)
		double AverSecondDigramNumber[1000], StandDevSecondDigramNumber[1000]; // Среднее число диграмм (2) и СКО

		double MinCoincidenceIndex[1000], MaxCoincidenceIndex[1000]; // Минимальное и максимальное число индекса совпадений
		double AverCoincidenceIndex[1000], StandDevCoincidenceIndex[1000]; // Средний индекс совпадений и СКО

		double MinConjugationIndex[1000], MaxConjugationIndex[1000]; // Минимальный и максимальный индекс сопряжений
		double AverConjugationIndex[1000], StandDevConjugationIndex[1000]; // Средний индекс сопряжений и СКО

		double MinDistinguishIndex[1000], MaxDistinguishIndex[1000]; // Минимальный и максимальный индекс отличений
		double AverDistinguishIndex[1000], StandDevDistinguishIndex[1000]; // Средний индекс отличений и СКО

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

		// Отнесение фрагментов к точкам шкалы
		if (Steps == 0) // Первый случай: количество шагов = 0 => плотные длины всех фрагментов = точки шкалы
			for (int i = 0; i < fragment_num; i++)
				data[i].scale_point = data[i].symbol_num;
		// Второй случай: количество шагов = 1 => начальное значение = единственная точка, ищутся фрагменты только этой длины
		// Третий случай: приращение = 0 => начальное значение = единственная точка, ищутся фрагменты только этой длины
		if ((Steps == 1) || (StepSize == 0))
			for (int i = 0; i < fragment_num; i++)
				data[i].scale_point = data[i].symbol_num;

		// Остальные случаи
		// Запись всех, кто меньше
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

		// Упорядочивание массива
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
					// Переназначение
					data[i + 1] = data[i];
					data[i] = TempData;
					Compare = false;
				}
		} while (Compare == false);

		if ((Steps == 1) || (StepSize == 0)) // Второй и третий случаи
			Size[0] = StartSize;
		else // Остальные
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

					// Используемые знаки алфавита: минимально, максимально, средне, ско (ниже)
					if (data[i].symbol_alphabet == cardinality)
						FullFragments[j]++;
					// Минимально
					if (data[i].symbol_alphabet < MinSymbolAlphabet[j])
						MinSymbolAlphabet[j] = double(data[i].symbol_alphabet);
					// Максимально
					if (data[i].symbol_alphabet > MaxSymbolAlphabet[j])
						MaxSymbolAlphabet[j] = double(data[i].symbol_alphabet);
					// Средне
					AverSymbolAlphabet[j] = AverSymbolAlphabet[j] + data[i].symbol_alphabet;

					// Количество биграмм: минимальное, максимальное, среднее
					// Минимальное
					if (data[i].bigrams_num < MinBigramNumber[j])
						MinBigramNumber[j] = double(data[i].bigrams_num);
					// Максимальное
					if (data[i].bigrams_num > MaxBigramNumber[j])
						MaxBigramNumber[j] = double(data[i].bigrams_num);
					// Среднее
					AverBigramNumber[j] = AverBigramNumber[j] + data[i].bigrams_num;

					// Количество пробелов
					// Минимально
					if (data[i].space_num < MinSpaceNumber[j])
						MinSpaceNumber[j] = data[i].space_num;
					// Максимально
					if (data[i].space_num > MaxSpaceNumber[j])
						MaxSpaceNumber[j] = data[i].space_num;
					// Средне
					AverSpaceNumber[j] = AverSpaceNumber[j] + data[i].space_num;

					// Количество пробелов - относительное
					// Минимально
					if (data[i].rel_space < MinSpaceRel[j])
						MinSpaceRel[j] = data[i].rel_space;
					// Максимально
					if (data[i].rel_space > MaxSpaceRel[j])
						MaxSpaceRel[j] = data[i].rel_space;
					// Средне
					AverSpaceRel[j] = AverSpaceRel[j] + data[i].rel_space;

					// Количество диграмм (1)
					// Минимально
					if (data[i].digram_first_num < MinFirstDigramNumber[j])
						MinFirstDigramNumber[j] = data[i].digram_first_num;
					// Максимально
					if (data[i].digram_first_num > MaxFirstDigramNumber[j])
						MaxFirstDigramNumber[j] = data[i].digram_first_num;
					// Средне
					AverFirstDigramNumber[j] = AverFirstDigramNumber[j] + data[i].digram_first_num;

					// Количество диграмм (2)
					// Минимально
					if (data[i].digram_second_num < MinSecondDigramNumber[j])
						MinSecondDigramNumber[j] = data[i].digram_second_num;
					// Максимально
					if (data[i].digram_second_num > MaxSecondDigramNumber[j])
						MaxSecondDigramNumber[j] = data[i].digram_second_num;
					// Средне
					AverSecondDigramNumber[j] = AverSecondDigramNumber[j] + data[i].digram_second_num;

					// Индекс совпадений
					// Минимально
					if (data[i].coincidence_index < MinCoincidenceIndex[j])
						MinCoincidenceIndex[j] = data[i].coincidence_index;
					// Максимально
					if (data[i].coincidence_index > MaxCoincidenceIndex[j])
						MaxCoincidenceIndex[j] = data[i].coincidence_index;
					// Средне
					AverCoincidenceIndex[j] = AverCoincidenceIndex[j] + data[i].coincidence_index;

					// Индекс сопряжений
					// Минимально
					if (data[i].conjugation_index < MinConjugationIndex[j])
						MinConjugationIndex[j] = data[i].conjugation_index;
					// Максимально
					if (data[i].conjugation_index > MaxConjugationIndex[j])
						MaxConjugationIndex[j] = data[i].conjugation_index;
					// Средне
					AverConjugationIndex[j] = AverConjugationIndex[j] + data[i].conjugation_index;

					// Индекс отличений
					// Минимально
					if (data[i].distinguish_index < MinDistinguishIndex[j])
						MinDistinguishIndex[j] = data[i].distinguish_index;
					// Максимально
					if (data[i].distinguish_index > MaxDistinguishIndex[j])
						MaxDistinguishIndex[j] = data[i].distinguish_index;
					// Средне
					AverDistinguishIndex[j] = AverDistinguishIndex[j] + data[i].distinguish_index;
				}
			}

			// Среднее по статистике в итоге
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

				// СКО по статистике
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
		Bout << "L=" << language_type << "\t";
		Bout << "NA=" << cardinality << "\t";
		Bout << "T=" << text_type << "\t";
		Bout << "Text=" << fragment_num << "\t";
		if (error != 0)
			Bout << "Err=" << error;
		Bout << "\n" << "N\tK\tNA\t" <<
			"S ср\tS min\tS max\tS S.D.\t" <<
			"Z ср\tZ min\tZ max\tZ S.D.\t" <<
			"B ср\tB min\tB max\tB S.D.\t" <<
			"C ср\tC min\tC max\tC S.D.\t" <<
			"D ср\tD min\tD max\tD S.D.\t" <<
			"X cp\tX min\tX max\tX S.D.\n";
		// Вывод итоговой таблицы
		for (int j = 0; j < fragment_num; j++)
			if (FragmentNumber[j] != 0) // Вывод, если в точке шкалы нашёлся хоть один фрагмент
			{
				// Нормирование значений
				AverSymbolAlphabet[j] = AverSymbolAlphabet[j] / cardinality;
				MinSymbolAlphabet[j] = MinSymbolAlphabet[j] / cardinality;
				MaxSymbolAlphabet[j] = MaxSymbolAlphabet[j] / cardinality;
				StandDevSymbolAlphabet[j] = StandDevSymbolAlphabet[j] / cardinality;
				AverBigramNumber[j] = AverBigramNumber[j] / (cardinality*cardinality);
				MinBigramNumber[j] = MinBigramNumber[j] / (cardinality*cardinality);
				MaxBigramNumber[j] = MaxBigramNumber[j] / (cardinality*cardinality);
				StandDevBigramNumber[j] = StandDevBigramNumber[j] / (cardinality*cardinality);

				Bout << Size[j] << "\t" << FragmentNumber[j] << "\t" << FullFragments[j] << "\t";
				Bout.precision(4);
				Bout << fixed << AverSpaceRel[j] << "\t" << MinSpaceRel[j] << "\t" << MaxSpaceRel[j] << "\t" << fixed << StandDevSpaceRel[j] << "\t"
					<< fixed << AverSymbolAlphabet[j] << "\t" << MinSymbolAlphabet[j] << "\t" << MaxSymbolAlphabet[j] << "\t" << fixed << StandDevSymbolAlphabet[j] << "\t";
				Bout.precision(3);
				Bout << fixed << AverBigramNumber[j] << "\t" << MinBigramNumber[j] << "\t" << MaxBigramNumber[j] << "\t" << fixed << StandDevBigramNumber[j] << "\t";
				Bout.precision(4);
				Bout << fixed << AverConjugationIndex[j] << "\t" << MinConjugationIndex[j] << "\t" << MaxConjugationIndex[j] << "\t" << fixed << StandDevConjugationIndex[j] << "\t"
					<< fixed << AverDistinguishIndex[j] << "\t" << MinDistinguishIndex[j] << "\t" << MaxDistinguishIndex[j] << "\t" << fixed << StandDevDistinguishIndex[j] << "\t"
					<< fixed << AverCoincidenceIndex[j] << "\t" << MinCoincidenceIndex[j] << "\t" << MaxCoincidenceIndex[j] << "\t" << fixed << StandDevCoincidenceIndex[j] << "\n";
			}

		Bout.close();
		in.close();
		return 0;
	}
	return 0;

}
////////////////////////////////////////////////////
int normaT()//Нормализатор текстов.
			//
			//В файле ctlg.txt NC нумерованных строк с полным именем каталогов в формате: N пробел имя каталога
			// N   - номер каталога и может повторяться, тогда берется  имя из последней строки для строк с одинаковыми номерами
			//       имя не может быть пустым или пробелом размер имени <=100 знаков
			// N=1 - имя каталога с исходными файлами для нормализации. Эти файлы изменяются в результате форматной нормализации
			// N=2 - имя каталога с нормализованными файлами. Они нормализуются не только форматно, но и лексически.
			//Пример:
			//2
			//1 C:\Users\User\Desktop\sourcT\
			//2 C:\Users\User\Desktop\normaT\
//
// Каталоги находятся в файлах 0.txt и содержат не более 500 файлов
// Структра файла 0.txt для исходных файлов:
// Nf  Nt  ND          Nf - количество файлов 1 <= Nf <= 1000
//                     Nt - тип выборки номеров
//                     ND - смещение номеров нормализованных файлов, позволяет дополнять каталог нормализованных
//                          текстов. Если ND <0, то ND=0.
//Далее, в зависимости от значения Nt, строка:
// i1 i2 ..... iN      - имена файлов через пробел, не менее Nf имен (Nt==0)
//или N1 N2            - номер первого файла, все последующие вычисляются рекуррентно N(i)=N(i-1)+N2, N(0)=N1 (Nt!=0)
//
// Имена i1 i2 ..... iN  всегда цифровые: 1.txt, 2.txt и т.д. Для исходных файлов порядок следования имен 
//                       в каталоге значения не имеет
//
// Структра файла 0.txt для нормализованных файлов:
// Nfn  L                   Nfn - количество файлов 1 <= Nfn <= 500, может отличаться от Nf, если каталог пополнился
//                          L   - средний размер нормализованного файла.
//                                Первоначальные значения для вновь формируемого каталога Nfn =0 L=0.
// i1 +d1 i2 +d2 ..... iN+dN    - имена файлов через пробел + их длина, не менее Nfn имен
//                                имена нормализованных файлов в каталоге всегда упорядочены по возрастанию имен
//
// Если нужно обработать не все файлы, то можно сохранить старые каталоги, а в новых оставить только те файлы
// которые подлежат обработке. Если в каталоге нормализованных файлов файл с таким именен уже существует, то он
// будет заменен. Если такого имени в каталоге нет, то каталог будет пополнен (с сохранением упорядоченности).
//
//Процесс нормализации управлется файлом enL.txt Его содержание:
//
//NA NS FRT ABR S1 FW
//Строка1 из NA знаков - результата нормализации
//Строки2-NS из NA знаков, встречающихся в тексте, которые будут заменяться на соответствующий по позиции знак 
//                         из Строка1.  Должно выполняться ограничение NA*NS <= 1500 знаков
//N1 N2 - количества заменяемых однобуквенных и двухбуквенных слов соответственно
//СтрокA из N1   знаков
//СтрокB из 2*N2 знаков
//
//Если N1=0, то в тексте не будут оставленo однобуквенных слов. Если N1>=NA, то в тексте будут оставлены все
//           встретившиеся однобуквенные слова. В остальных случаях будут оставлены только те слова, которые 
//           определены в строкА.
//Если N2<0, то в тексте не будут оставленo двухбуквенных слов. Если N2=0, то в тексте будут оставлены все
//           встретившиеся однобуквенные слова. В остальных случаях будут оставлены только те слова, которые 
//           определены в строкВ. В строкВ может быть определено не более 200 знаков, т.е. 100 двухбуквенных слов.
//
//Если FRT=0,  то нормализация форматирования не производится. Полезно, если повторно нормализуется ранее 
//             нормализованный по форматированию файл. ВРЕМЯ ОБРАБОТКИ СНИЖАЕТСЯ В ДВА РАЗА.
//             ЗАПИСЬ НОВОГО ФАЙЛА НА МЕСТО ИСХОДНОГО НЕ ПРОИЗВОДИТСЯ.
//     FRT=1 - производится нормализация форматирования файла, описанная ниже в блоке 1 и нормализованный
//             по форматированию файл записывается на место исходного. Если FRT !=0 или FRT !=1, то принимается FRT=1
//     ФBR   - может иметь любое значение, функция не раелизована.
//Если SW1=0,  то в тексте остаются все однобуквенные цепочки, когда соответствующие слова идут подряд лруг за другом
//     SW1=1 - однобуквенные цепочки удаляются кроме перввых двух букв в цепочке (если они соответствует СтрокA)
//             Если SW1 !=0 или SW1 !=1, то принимается SW1=1
//     FW    - вещественное с точкой. Определяет отношение количества разных букв в слове к его длине. В тестве
//             остаются только слова, имеющие значение такого отгошения не менее заданного. Значение FW должно
//             находиться в диапазоне 0.0 - 1.0. Если FW <0, то FW=0.0, если FW >1, то FW=1.0
//
//Текст в нормализованном файле формируется из последовательных строк (фрагментов, страниц) размером <=500000 знаков.
//В заголовке файла указывается общее количество таких фрагментов и общее количество знаков в файле.
//На следующей строке указывается номер фрагмента в формате _N_ 
//Со следующей строки идет текст фрагмента - и так для всех строк (страниц, фрагментов) текста.
//
//Входные файлы: ctlg.txt
//                enL.txt
//               файлы из папки, определенной в ctlg.txt и файла каталога 0.txt из этих папок
//Рабочий файл:   tmp.txt
//Выходные файлы:файлы из папок, определенных в ctlg.txt и файлах каталога 0.txt из этих папок
//
//               return 0 - все в порядке
//               return 1 - не указан каталог (каталоги)
//
{
	char c, c0;
	char Lm[1500];  //массив встречающихся символов NA*NS
	char C1[32], C2[200];
	char s[500000];
	char sw[100], aw[100], pw[100], IA[50];

	char F0[10] = "0.txt";
	char F1[10] = ".txt";

	char CC[11] = "0123456789";
	char NB[11];

	char ssT, srT[100];
	char nnT, nmT[100];

	int nsF, SF[1000], STC, DNC;
	int ntF, TF[1000][2];

	int i4, IC;
	int FRT, ABR, SW1;
	float FW;
	int NA, NK, NW, NC, NT, n, fg, zt, NN, cT, NW2, NRZ;


	int i, k, j, t, z, x, e, lns, lnt, m, g, g1, g3, p, p1, p2;
	float g2;
	double RAZ;

	FILE*f, *f1, *f2, *f3, *f4;
	//
	//Определяем папки исходных и нормализованных текстов и соответствующие каталоги в файлах 0.txt
	//
	fopen_s(&f4, "ctlg.txt", "r"); //файл с полным именем (путь) папки исходных (NT=1) и нормализованных (NT=2) текстов 

	fscanf_s(f4, "%d\n", &NC, 1); if (NC<2)return 1; //не указан каталог (каталоги)
	t = m = 0;
	for (x = 0; x<NC; x++)
	{
		fscanf_s(f4, "%d\n", &NT, 1);
		if (NT == 1)
		{
			i = 0; while ((c = fgetc(f4)) != '\n') { srT[i] = c; i++; }
			ssT = i;
			j = 0; while (F0[j] != '\0') { srT[i] = F0[j]; i++; j++; }
			srT[i] = '\0';

			fopen_s(&f, srT, "r");                          //чтение каталога исходных текстов
			fscanf_s(f, "%d %d %d\n", &nsF, &STC, &DNC, 1); if (DNC<0)DNC = 0;

			if (STC == 0) for (i = 0; i<nsF; i++)fscanf_s(f, "%d", &SF[i], 1);
			else
			{
				fscanf_s(f, "%d %d\n", &k, &g1, 1); g3 = k - g1; for (i = 0; i<nsF; i++)SF[i] = g3 = g3 + g1;
			}

			fclose(f);
			t = 1;
		}
		else
		{
			if (NT == 2)
			{
				i = 0; while ((c = fgetc(f4)) != '\n') { nmT[i] = c; i++; }
				nnT = i;
				j = 0; while (F0[j] != '\0') { nmT[i] = F0[j]; i++; j++; }
				nmT[i] = '\0';

				fopen_s(&f, nmT, "r");                         //чтение каталога нормализованных текстов
				fscanf_s(f, "%d %d\n", &ntF, &NRZ, 1);
				for (i = 0; i<ntF; i++)fscanf_s(f, "%d %d", &TF[i][0], &TF[i][1], 1);
				fclose(f);
				m = 1;
			}
			else while ((c = fgetc(f4)) != '\n');              //Пропуск строк
		}
	}
	fclose(f4); //Закрыть ctlg.txt

	if (t != 1 || m != 1)return 1; //не указан каталог (каталоги)


								   //
								   // Главный цикл i4 по числу nsF заданных в каталоге исходных текстов файлов
								   //

	t = m = 0;
	fopen_s(&f2, "enL.txt", "r");

	fscanf_s(f2, "%d %d %d %d %d %f\n", &NA, &NK, &FRT, &ABR, &SW1, &FW, 1);     //Чтение enL.txt

	if (FRT<0 || FRT>1)FRT = 1;
	if (SW1<0 || SW1>1)SW1 = 1;
	if (FW<0.0)FW = 0.0;
	if (FW>1.0)FW = 1.0;

	i = 0;
	for (j = 0; j<NK; j++)while ((c = fgetc(f2)) != '\n') { Lm[i] = c; i++; }
	lnt = i + 1;
	fscanf_s(f2, "%d %d\n", &NW, &NW2, 1);       //количества однобуквенные и двубуквенные слов
	i = 0;
	if (NW != 0 && NW != NA)while ((c = fgetc(f2)) != '\n') { if (i<NW)C1[i] = c; i++; }
	i = 0; p = 2 * NW2;
	if (NW2>0)while ((c = fgetc(f2)) != '\n') { if (i<p)C2[i] = c; i++; }

	fclose(f2);


	for (i4 = 0; i4<nsF; i4++)
	{

		//Номер текста из integer в char + полный путь к файлу
		//Исходный
		p = 0; IC = SF[i4]; for (i = 0; i<10; i++) { z = IC % 10; if (z>0)p = i; NB[i] = CC[z]; IC = IC / 10; }
		i = ssT; for (z = 0; z<p + 1; z++)srT[i + z] = NB[p - z];
		for (z = 0; z<5; z++)srT[i + p + z + 1] = F1[z];
		//Нормализованный
		p = 0; IC = SF[i4] + DNC; for (i = 0; i<10; i++) { z = IC % 10; if (z>0)p = i; NB[i] = CC[z]; IC = IC / 10; }
		j = nnT; for (z = 0; z<p + 1; z++)nmT[j + z] = NB[p - z];
		for (z = 0; z<5; z++)nmT[j + p + z + 1] = F1[z];


		if (FRT == 1)
		{
			//1
			//Блок нормализации формата
			//Склеивание: исключаем из слов дефисы и переносы, склеивая части, разделенные этими знаками. Заменяем "я" на "Я"
			//Убираем идущие подряд или через пробел точки, оставляя первую. Убираем табуляцию и переносы строк.
			//Устанавливаем конец строки перед концом файла
			//

			//Добавляем в конец файла конец строки. Конец файла определяем по 50-кратному повторению 'я'
			//Убираем знаки табуляции '\t' и '¬'
			//Заменяем в тексте 'я'на 'Я'
			//
			fopen_s(&f, srT, "r");
			fopen_s(&f1, "tmp.txt", "w");

			j = 0; i = 0; x = 0; NN = 500000;

		NBG:
			while ((c = fgetc(f)) != 'я'&& i<NN)
			{
				if (c != '\n')
				{
					if (c0 == '-'&& c == ' ') continue;
					else
						if ((c0 == '.' || cT == 1) && c == '.') continue;
						else
						{
							if (c == '.') cT = 1; else if (c != ' ') cT = 0; if (c == '\t')c = ' '; c0 = c;
							if (c != '-'&& c != '¬') { s[i] = c; i++; }
						}
				}
				else if (c0 != '-'&& c0 != '¬') { s[i] = ' '; i++; }
			}

			lns = i;

			if (c != 'я'&& i == NN)
			{
				for (j = 0; j<NN; j++)fputc(s[j], f1);
				if (c == '\t')c = ' ';
				if (c == '\n'&& c0 != '-'&& c0 != '¬')c = ' '; c0 = c;
				if (c != '-'&& c != '¬'&& c != '\n') { s[0] = c; i = 1; }
				else i = 0; goto NBG;
			}

			if (c == 'я')
			{
				i = 1; IA[0] = 'Я'; x = 1; c0 = c;
				for (j = 1; j<50; j++)
				{
					c = fgetc(f); if (c == 'я') { i++; c = 'Я'; }
					if (c == '\t')c = ' ';
					if (c == '\n'&& c0 != '-'&& c0 != '¬')c = ' '; c0 = c;
					if (c != '-'&& c != '¬'&& c != '\n') { IA[x] = c; x++; }
				}
				if (i != j)
				{
					if (lns + x <= NN) { for (j = 0; j<x; j++)s[lns + j] = IA[j]; i = lns + x; goto NBG; }
					else { for (j = 0; j<lns; j++)fputc(s[j], f1); for (j = 0; j<x; j++)s[j] = IA[j]; i = x; goto NBG; }
				}
				else { for (j = 0; j<lns; j++)fputc(s[j], f1); c = '\n'; fputc(c, f1); goto ENFL; }
			}
		ENFL:
			fclose(f);
			fclose(f1);

			//
			//Переписываем tmp.txt в исходный 
			//
			fopen_s(&f1, "tmp.txt", "r");
			fopen_s(&f, srT, "w");
			while ((c = fgetc(f1)) != EOF)fputc(c, f);
			fclose(f);
			fclose(f1);


			//
			/////////////////////////// БЛОК 1 ЗАКОНЧЕН
		}


		//2
		//Блок лингвистической нормализации с использованием файла enL.txt
		//Убираются следующие друг за другом однознаковые слова кроме первого
		//Остются только однознаковые слова, определенные в enL.txt
		//Убираются повторяющиеся слова любой длины кроме первого
		//Убираются слова, имеющие разнообразие букв меньше заданного
		//

		fopen_s(&f, srT, "r");
		fopen_s(&f1, "tmp.txt", "w");

		lns = 0; j = 0; m = 0; n = 0; x = 0; p = 0; p2 = 0;
		fg = 1; zt = 0;
		c0 = ' ';
		while ((c = fgetc(f)) != EOF)
		{
			z = 0; for (i = NA; i<NA*NK; i++)if (c == Lm[i]) { j = i%NA; sw[m] = Lm[j]; z = 1; m++; break; }

			if (m != 0 && z == 0)
			{
				e = 1; aw[0] = sw[0];
				for (i = 0; i<m; i++) { z = 0; for (j = 0; j<e; j++)if (sw[i] == aw[j]) { z = 1; break; } if (z == 0) { aw[e] = sw[i]; e++; } }
				g2 = float(e) / float(m);

				//Однознаковые слова: оставляем только  слова языка
				if (m == 1)if (NW>0 && NW<NA) { z = 0; for (j = 0; j<NW; j++)if (sw[0] == C1[j]) { z = 1; break; } if (z == 0)g2 = 0.0; }
				else { if (NW == 0)g2 = 0.0; if (NW == NA)g2 = 1.0; }
				//Двухзнаковые слова: оставляем только  слова языка
				if (m == 2)if (NW2>0) { z = 0; p1 = 2 * NW2; for (j = 0; j<p1; j = j + 2)if (sw[0] == C2[j] && sw[1] == C2[j + 1]) { z = 1; break; } if (z == 0)g2 = 0.0; }
				else { if (NW2<0)g2 = 0.0; if (NW2 == 0)g2 = 1.0; }


				//Убираем следующие друг за другом слова единичной длины кроме первых двух
				if (m>1)p2 = 0;
				if (SW1 == 1 && x != 0 && m == 1)p2++;
				if (SW1 == 1 && x != 0 && m == 1 && p == 1 && p2>2)g2 = 0.0;

				//Убираем повторяющиеся друг за другом одинаковые слова любой длины кроме первого
				if (x != 0 && g2 != 0.0 && p == m)
				{
					z = 0; for (j = 0; j<m; j++)if (pw[j] != sw[j]) { z = 1; break; } if (z == 0)g2 = 0.0;
				}
				//Убираем слова, имеющие разнообразие букв меньше заданного
				if (g2 >= FW)
				{
					if (x + m<NN)
					{
						for (i = 0; i<m; i++) { s[x] = sw[i]; x++; pw[i] = sw[i]; }
						s[x] = ' '; x++; n = 1; p = m;
					}
					else
					{
						fprintf_s(f1, "_%d_\n", fg);
						for (i = 0; i<x; i++)
						{
							fputc(s[i], f1);  //печатаем в файл tmp.txt очередной фрагмент
						}
						fprintf_s(f1, "\n");
						fg++; zt = zt + x;
						x = 0;
						for (i = 0; i<m; i++) { s[x] = sw[i]; x++; pw[i] = sw[i]; }
						s[x] = ' '; x++; n = 1; p = m;
					}
				}
				m = 0;
			}
		}

		x--;

		fprintf_s(f1, "_%d_\n", fg);

		zt = zt + x;

		for (i = 0; i<x; i++)
		{
			fputc(s[i], f1);//печатаем в файл tmp.txt
		}
		fprintf_s(f1, "\n");

		fclose(f);
		fclose(f1);


		fopen_s(&f1, "tmp.txt", "r");
		fopen_s(&f3, nmT, "w");
		fprintf(f3, "%d %d\n", fg, zt);
		while ((c = fgetc(f1)) != EOF)fprintf(f3, "%c", c);
		fclose(f3);
		fclose(f1);

		fopen_s(&f1, "tmp.txt", "w");
		c = ' '; fprintf(f1, "%c", c);
		fclose(f1);

		p = 0; for (i = 0; i<ntF; i++)if (SF[i4] + DNC == TF[i][0]) { p = 1; TF[i4][1] = zt; }
		if (p == 0) { TF[ntF][0] = SF[i4] + DNC; TF[ntF][1] = zt; ntF++; }

	}

	p = 1; while (p == 1)
	{
		p = 0; for (j = 1; j<ntF; j++)
			if (TF[j - 1][0]>TF[j][0])
			{
				z = TF[j - 1][0]; g = TF[j - 1][1]; TF[j - 1][0] = TF[j][0]; TF[j - 1][1] = TF[j][1]; TF[j][0] = z; TF[j][1] = g; p = 1;
			}
	}

	RAZ = double(TF[0][1]); for (j = 1; j<ntF; j++)RAZ = RAZ + double(TF[j][1]);

	j = nnT; for (z = 0; z<6; z++)nmT[j + z] = F0[z];
	fopen_s(&f3, nmT, "w");
	RAZ = RAZ / double(ntF);
	NRZ = int(RAZ);
	fprintf(f3, "%d %d\n", ntF, NRZ);
	for (i = 0; i<ntF; i++)fprintf(f3, "%d +%d ", TF[i][0], TF[i][1]);
	fprintf(f3, "\n");
	fclose(f3);

	return 0;
}
////////////////
////////////////
int schema(int NSH, int KTX, int NTX[], int RTA, int AF)//Формирование схемы выборки фрагментов текстов
														//
														//       int NSH   - номер схемы > 0.
														//       int TTX   - тип выборки текстов: TTX==0 - по списку NTX[]; в остальных случаях случайный
														//                                        тогда в список NTX[] помещаются номера выбранных файлов, всего KTX
														//                   Если в каталоге файлов файлов меньше, чем KTX, то TTX игнорируется
														//       int KTX  -  количество и тип выборки текстов схемы.
														//                   Если KTX ==0, то все тексты текущего каталога.
														//                   Если KTX < 0, то случайным образом выбирается abs(KTX) текстов текщего каталога,
														//                   их номера заносятся в список NTX[]. Если abs(KTX) >= числу тектов текущего каталога, то
														//                   выбираются все тексты, список NTX[] не формируется.
														//                   Если KTX > 0, то в схему выбируются все файлы каталога, номера которых указаны в списке NTX[].
														//                   Если KTX > 1000, то KTX=1000, т.е. обрабатываются только первые 1000 номеров списка.
														//|                  Если KTX < 0 и abs(KTX) >= числа файлов каталога, то KTX=0.
														//       int NTX[] - массив с номерами текстов схемы
														//       int RTA   - способ формирования начальных адресов схемы:
														//                   RTA ==0 - все фрагменты имеют случайный адрес начала
														//                   RTA ==1 - фрагменты вложены друг в друга по возрастанию адреса
														//                   RTA ==2 - фрагменты вложены друг в друга по убыванию адреса
														//                   Если RTA <0 или RTA > 2, то принимается RTA =0.
														//       int AF    - AF <=0  - начальный адрес случаен (для RTA ==0 может быть любым, в том числе >0)
														//                 - AF > 0  - для RTA ==1 и RTA ==2 задает фиксированный адрес начала
														//
														//В файле ctlg.txt NC нумерованных строк с полным именем каталогов в формате: N пробел имя каталога
														// N   - номер каталога и может повторяться, тогда берется  имя из последней строки для строк с одинаковыми номерами
														//       имя не может быть пустым или пробелом размер имени <=100 знаков
														// N=2 - имя каталога с исходными нормализованными файлами для схемы. 
														// N=3 - имя каталога с существующими схемами.
														//ПРИМЕР
														//2
														//2 C:\Users\User\Desktop\normaT\
														//3 C:\Users\User\Desktop\Schema\
//
// Каталоги находятся в файлах 0.txt и содержат не более 1000 файлов
//
// Структра файла 0.txt для нормализованных файлов:
// Nfn  L                   Nfn - количество файлов 1 <= Nfn <= 500, может отличаться от Nf, если каталог пополнился
//                          L   - средний размер нормализованного файла.
//                                Первоначальные значения для вновь формируемого каталога Nfn =0 L=0.
// i1 +d1 i2 +d2 ..... iN+dN    - имена файлов через пробел + их длина, не менее Nfn имен
//                                имена нормализованных файлов в каталоге всегда упорядочены по возрастанию имен
//
// Если нужно обработать не все файлы, то можно сохранить старые каталоги, а в новых оставить только те файлы
// которые подлежат обработке. Если в каталоге нормализованных файлов файл с таким именен уже существует, то он
// будет заменен. Если такого имени в каталоге нет, то каталог будет пополнен (с сохранением упорядоченности).
//
//Процесс формирования схемы управлется файлом enQ.txt Его содержание:
//
//N1 N2 N3       N1 - количество формируемых фрагментов <= 100    N2 - начальный размер фрагмента  N3 -приращение размера 
//
//
//Ограничение для точек шкалы:
//1 <= N1 <= 1000. Если N1 > 1000, то принимается Ns=1000, N1 <= 0, то N1=1.
//N2<1 и N3==0, то фрагменты не заданы.
//Если N3==0, то N1=1
//Если N2<1,  то N2=N3.
//
//
//Входные файлы: ctlg.txt
//                enQ.txt
//               файлы из папки, определенной в ctlg.txt и файла каталога 0.txt из этих папок
//
//Выходные файлы:файл схемы в папке схем, определенных в ctlg.txt и файл каталога схем 0.txt из этой папки
//
//               return 0 - все в порядке
//               return 1 - не указан каталог (каталоги)
//               return 2 - Текстов нет
//               return 3 - фрагменты не заданы.
//
{

	char c;
	char F0[10] = "0.txt";
	char F1[10] = ".txt";

	char CC[11] = "0123456789";
	char NB[11];

	char ssT, srT[100];
	char nnT, nmT[100];

	int nsF, SF[1000];
	int ntF, TF[1000][2];
	int ADR[1000];
	int N1, N2, N3, DT, NR, RT, KX, TX;

	int i4, IC;

	int NS;
	unsigned int number, num;

	int NC, NT, NRZ;

	int i, j, t, z, x, m, p, xKT;
	float g2 = 0.0;

	errno_t err;

	FILE*f, *f4;
	//
	//Определяем папки исходных и нормализованных текстов и соответствующие каталоги в файлах 0.txt
	//
	fopen_s(&f4, "ctlg.txt", "r"); //файл с полным именем (путь) папки исходных (NT=1) и нормализованных (NT=2) текстов 

	fscanf_s(f4, "%d\n", &NC, 1); if (NC<2)return 1; //не указан каталог (каталоги)
	t = m = 0;
	for (x = 0; x<NC; x++)
	{
		fscanf_s(f4, "%d\n", &NT, 1);
		if (NT == 3)
		{
			i = 0; while ((c = fgetc(f4)) != '\n') { srT[i] = c; i++; }
			ssT = i;
			j = 0; while (F0[j] != '\0') { srT[i] = F0[j]; i++; j++; }
			srT[i] = '\0';

			fopen_s(&f, srT, "r");                          //чтение каталога схем
			fscanf_s(f, "%d ", &nsF, 1);
			for (i = 0; i<nsF; i++)fscanf_s(f, "%d", &SF[i], 1);
			fclose(f);
			t = 1;
		}
		else
		{
			if (NT == 2)
			{
				i = 0; while ((c = fgetc(f4)) != '\n') { nmT[i] = c; i++; }
				nnT = i;
				j = 0; while (F0[j] != '\0') { nmT[i] = F0[j]; i++; j++; }
				nmT[i] = '\0';

				fopen_s(&f, nmT, "r");                         //чтение каталога нормализованных текстов
				fscanf_s(f, "%d %d\n", &ntF, &NRZ, 1);
				for (i = 0; i<ntF; i++)fscanf_s(f, "%d %d", &TF[i][0], &TF[i][1], 1);
				fclose(f);
				m = 1;
			}
			else while ((c = fgetc(f4)) != '\n');              //Пропуск строк
		}
	}
	fclose(f4); //Закрыть ctlg.txt

	if (t != 1 || m != 1)return 1;      //не указан каталог (каталоги)

	if (ntF == 0) return 2;        //Текстов нет
	KX = KTX;
	if (KX<0 && abs(KX) >= ntF)KX = 0; if (KX>1000)KX = 1000;
	if (KX>0)
	{
		xKT = 0; for (i = 0; i<ntF; i++) { p = 0; for (j = 0; j<KX; j++)if (TF[i][0] == NTX[j]) { p = 1; xKT++; break; } if (p == 0)TF[i][1] = 0; }
		if (xKT == 0) return 2;
	} //Текстов нет
	if (KX == 0)xKT = ntF;

	if (KX<0) //Подготовка списка случайных номеров текстов без повторения из каталога
	{
		TX = abs(KX); NS = ntF; i = 0;
		while (i<TX)
		{
			p = 0; if (NS>1) // Get random integers in the range [ 1,NS ]
			{
				err = rand_s(&number); if (err != 0)return 1;
				num = (unsigned int)((double)number / ((double)UINT_MAX + 1) * float(NS)) + 1;
				for (j = 0; j<i; j++)if (TF[num - 1][0] == NTX[j]) { p = 1; break; }
				if (p == 0) { NTX[i] = TF[num - 1][0]; i++; }
			}
		}
		KX = TX;
		xKT = 0; for (x = 0; x<ntF; x++) {
			p = 0; for (j = 0; j<KX; j++)if (TF[x][0] == NTX[j]) { p = 1; xKT++; break; } if (p == 0)TF[x][1] = 0;
			if (xKT == 0) return 2;
		} //Текстов нет
	}


	t = m = 0;
	fopen_s(&f, "enQ.txt", "r");

	fscanf_s(f, "%d %d %d\n", &N1, &N2, &N3, 1);     //Чтение enQ.txt

	NR = N1;
	if (N1<1)return 3;            //фрагменты не заданы.         
	if (N1>1000)NR = N1 = 1000;
	if (N2<1 && N3 == 0)return 3;   //фрагменты не заданы. 
	if (N2<1) N2 = N3;
	if (N3 == 0)NR = N1 = 1;


	fclose(f);

	//Открыть файл схемы Номер  из integer в char + полный путь к файлу
	p = 0; IC = NSH; for (i = 0; i<10; i++) { z = IC % 10; if (z>0)p = i; NB[i] = CC[z]; IC = IC / 10; }
	i = ssT; for (z = 0; z<p + 1; z++)srT[i + z] = NB[p - z];
	for (z = 0; z<5; z++)srT[i + p + z + 1] = F1[z];

	fopen_s(&f, srT, "w");

	fprintf_s(f, "%d %d\n", xKT, NR);

	for (i = 0; i<ntF; i++)if (TF[i][1] != 0)fprintf_s(f, "%d ", TF[i][0]);
	fprintf_s(f, "\n");

	//
	// Главный цикл i4 по числу nsF заданных в каталоге исходных текстов файлов
	//
	RT = RTA;
	for (i = 0; i<1000; i++)ADR[i] = 0;
	if (RT<0 || RT>2)RT = 0;
	if (N3<0)N3 = (-1)*N3;
	NRZ = N2; DT = N3; x = 0;
	if (RT == 2) { NRZ = N2 + (N1 - 1)*N3; DT = -N3; x = N3; }

	for (i4 = 0; i4<NR; i4++)
	{
		fprintf_s(f, "%d ", NRZ);
		for (i = 0; i<ntF; i++)
			if (TF[i][1] != 0)
			{
				if (RT == 0 || i4 == 0)
				{
					if (AF<1 || RT == 0)
					{
						NS = TF[i][1] - NRZ;
						if (NS>1) // Get random integers in the range [ 1,NS ]
						{
							err = rand_s(&number); if (err != 0)return 1;
							num = (unsigned int)((double)number / ((double)UINT_MAX + 1) * float(NS)) + 1;
						}
						else { if (NS<0)num = 0; else num = 1; }
					}
					else { NS = TF[i][1] - (AF - 1) - NRZ; if (NS<0)num = 0; else num = AF; }
					if (num != 0)ADR[i] = num;
					fprintf_s(f, "%d ", num);
				}
				else
				{
					if (RT == 1)
					{
						num = 0; if (ADR[i] != 0 && (TF[i][1] - (ADR[i] - 1) - NRZ) >= 0)num = ADR[i];
						fprintf_s(f, "%d ", num);
					}
					else
					{
						num = 0; if (ADR[i] != 0 && (TF[i][1] - (ADR[i] - 1) - NRZ) >= 0) { num = ADR[i] + x; ADR[i] = ADR[i] + x; }
						else
						{
							if (AF<1)
							{
								NS = TF[i][1] - NRZ;
								if (NS>1) // Get random integers in the range [ 1,NS ]
								{
									err = rand_s(&number); if (err != 0)return 1;
									num = (unsigned int)((double)number / ((double)UINT_MAX + 1) * float(NS)) + 1;
								}
								else { if (NS<0)num = 0; else num = 1; }
							}
							else { NS = TF[i][1] - (AF - 1) - NRZ; if (NS<0)num = 0; else num = AF; }
							if (num != 0)ADR[i] = num;
						}
						fprintf_s(f, "%d ", num);
					}
				}
			}
		fprintf_s(f, "\n");
		NRZ = NRZ + DT;
	}

	fclose(f);


	//Открыть файл каталога схем
	p = 0; IC = 0; for (i = 0; i<10; i++) { z = IC % 10; if (z>0)p = i; NB[i] = CC[z]; IC = IC / 10; }
	i = ssT; for (z = 0; z<p + 1; z++)srT[i + z] = NB[p - z];
	for (z = 0; z<5; z++)srT[i + p + z + 1] = F1[z];

	fopen_s(&f, srT, "w");

	p = 0; for (i = 0; i<nsF; i++)if (NSH == SF[i]) { p = 1; break; }
	if (p == 0) { SF[nsF] = NSH; nsF++; }

	p = 1; while (p == 1)
	{
		p = 0; for (j = 1; j<nsF; j++)
			if (SF[j - 1]>SF[j])
			{
				z = SF[j - 1]; SF[j - 1] = SF[j]; SF[j] = z; p = 1;
			}
	}

	fprintf(f, "%d\n", nsF);
	for (i = 0; i<nsF; i++)fprintf(f, "%d ", SF[i]);
	fprintf(f, "\n");
	fclose(f);

	return 0;
}
////////////////
int frag(int NSH)//Формирование выборки текстовых фрагментов по заданной схеме 
				 //
				 //       int NSH - номер схемы > 0.
				 //
				 //В файле ctlg.txt NC нумерованных строк с полным именем каталогов в формате: N пробел имя каталога
				 // N   - номер каталога и может повторяться, тогда берется  имя из последней строки для строк с одинаковыми номерами
				 //       имя не может быть пустым или пробелом размер имени <=100 знаков
				 // N=2 - имя каталога с исходными нормализованными файлами для схемы. 
				 // N=3 - имя каталога с существующими схемами.
				 //ПРИМЕР
				 //2
				 //2 C:\Users\User\Desktop\normaT\
				 //3 C:\Users\User\Desktop\Schema\
//4 C:\Users\User\Desktop\Tfrag\
//
// Каталоги находятся в файлах 0.txt и содержат не более 1000 файлов
//
// Структура файла 0.txt для нормализованных файлов:
// Nfn  L                   Nfn - количество файлов 1 <= Nfn <= 500, может отличаться от Nf, если каталог пополнился
//                          L   - средний размер нормализованного файла.
//                                Первоначальные значения для вновь формируемого каталога Nfn =0 L=0.
// i1 +d1 i2 +d2 ..... iN+dN    - имена файлов через пробел + их длина, не менее Nfn имен
//                                имена нормализованных файлов в каталоге всегда упорядочены по возрастанию имен
//
// Если нужно обработать не все файлы, то можно сохранить старые каталоги, а в новых оставить только те файлы
// которые подлежат обработке. Если в каталоге нормализованных файлов файл с таким именен уже существует, то он
// будет заменен. Если такого имени в каталоге нет, то каталог будет пополнен (с сохранением упорядоченности).
//
//Номер файла выборки соответствует номеру схемы. Если такой файл уже есть, то он замещается новым
//
//Входные файлы: ctlg.txt
//               файлы из папки, определенной в ctlg.txt и файла каталога 0.txt из этих папок
//  
//Выходные файлы:файлы из папок, определенных в ctlg.txt и файлах каталога 0.txt из этих папок
//
//               return 0 - все в порядке
//               return 1 - не указан каталог (каталоги)
//               return 2 - форирование выборки невозможно
//
{

	char c;
	char F0[10] = "0.txt";
	char F1[10] = ".txt";

	char CC[11] = "0123456789";
	char NB[11];

	char ssT, srT[100];
	char nnT, nmT[100];
	char ggT, gfT[100];

	int SHE[100][1000], DL[100], NGF[1000];

	int nsF, SF[1000];
	int ngT, GT[1000];
	int ntF, TF[1000][2];

	int IC, NS, NC, NT, NRZ, NR;

	int i, j, t, z, x, e, m, p, xKT;


	FILE*f, *f4;

	//
	//Определяем папки исходных и нормализованных текстов и соответствующие каталоги в файлах 0.txt
	//
	fopen_s(&f4, "ctlg.txt", "r"); //файл с полным именем (путь) папки исходных (NT=1) и нормализованных (NT=2) текстов 

	fscanf_s(f4, "%d\n", &NC, 1); if (NC<2)return 1; //не указан каталог (каталоги)
	t = m = z = 0;
	for (x = 0; x<NC; x++)
	{
		fscanf_s(f4, "%d\n", &NT, 1);
		if (NT == 3)
		{
			i = 0; while ((c = fgetc(f4)) != '\n') { srT[i] = c; i++; }
			ssT = i;
			j = 0; while (F0[j] != '\0') { srT[i] = F0[j]; i++; j++; }
			srT[i] = '\0';

			fopen_s(&f, srT, "r");                          //чтение каталога схем
			fscanf_s(f, "%d ", &nsF, 1);
			for (i = 0; i<nsF; i++)fscanf_s(f, "%d", &SF[i], 1);
			fclose(f);
			t = 1;
		}
		else
		{
			if (NT == 2)
			{
				i = 0; while ((c = fgetc(f4)) != '\n') { nmT[i] = c; i++; }
				nnT = i;
				j = 0; while (F0[j] != '\0') { nmT[i] = F0[j]; i++; j++; }
				nmT[i] = '\0';

				fopen_s(&f, nmT, "r");                         //чтение каталога нормализованных текстов
				fscanf_s(f, "%d %d\n", &ntF, &NRZ, 1);
				for (i = 0; i<ntF; i++)fscanf_s(f, "%d %d", &TF[i][0], &TF[i][1], 1);
				fclose(f);
				m = 1;
			}
			else
			{
				if (NT == 4)
				{
					i = 0; while ((c = fgetc(f4)) != '\n') { gfT[i] = c; i++; }
					ggT = i;
					j = 0; while (F0[j] != '\0') { gfT[i] = F0[j]; i++; j++; }
					gfT[i] = '\0';

					fopen_s(&f, gfT, "r");                          //чтение каталога фрагментов
					fscanf_s(f, "%d ", &ngT, 1);
					for (i = 0; i<nsF; i++)fscanf_s(f, "%d", &GT[i], 1);
					fclose(f);
					z = 1;
				}
				else while ((c = fgetc(f4)) != '\n');              //Пропуск строк
			}
		}
	}
	fclose(f4); //Закрыть ctlg.txt

	if (t != 1 || m != 1 || z != 1)return 1;      //не указан каталог (каталоги)


												  //Открыть файл схемы Номер  из integer в char + полный путь к файлу
	p = 0; IC = NSH; for (i = 0; i<10; i++) { z = IC % 10; if (z>0)p = i; NB[i] = CC[z]; IC = IC / 10; }
	i = ssT; for (z = 0; z<p + 1; z++)srT[i + z] = NB[p - z];
	for (z = 0; z<5; z++)srT[i + p + z + 1] = F1[z];

	fopen_s(&f, srT, "r");

	fscanf_s(f, "%d %d\n", &xKT, &NR, 1);

	for (i = 0; i<xKT; i++)fscanf_s(f, "%d ", &NGF[i], 1);
	//while((c=fgetc(f))!='\n');
	for (j = 0; j<NR; j++)
	{
		fscanf_s(f, "%d ", &DL[j], 1);
		for (i = 0; i<xKT; i++)fscanf_s(f, "%d ", &SHE[j][i], 1);
		//while((c=fgetc(f))!='\n');
	}



	//fopen_s(&f,nmT,"r");

	//Открыть файл фрагментов из схемы Номер  из integer в char + полный путь к файлу
	p = 0; IC = NSH; for (i = 0; i<10; i++) { z = IC % 10; if (z>0)p = i; NB[i] = CC[z]; IC = IC / 10; }
	i = ggT; for (z = 0; z<p + 1; z++)gfT[i + z] = NB[p - z];
	for (z = 0; z<5; z++)gfT[i + p + z + 1] = F1[z];

	fopen_s(&f4, gfT, "w");

	p = 0; for (i = 0; i<xKT; i++) { e = NR; for (j = 0; j<NR; j++)if (SHE[j][i] == 0) { e--; p++; } if (e == 0)NGF[i] = 0; }
	for (i = 0; i<xKT; i++)
		if (NGF[i] != 0)
		{
			e = 0; for (j = 0; j<ntF; j++)if (TF[j][0] == NGF[i]) { e = 1; z = j; break; }
			if (e == 1)
			{
				m = 0; for (j = 0; j<NR; j++)if (SHE[j][i] != 0 && (SHE[j][i] + DL[j])>TF[z][1]) { SHE[j][i] = 0; m++; }
				p = p + m; m = 0; for (j = 0; j<NR; j++)if (SHE[j][i] != 0)m = 1; if (m == 0)NGF[i] = 0;
			}
			if (e == 0) { NGF[i] = 0; for (j = 0; j<NR; j++)if (SHE[j][i] != 0) { SHE[j][i] = 0; p++; } }
		}


	NS = xKT*NR - p;
	if (NS <= 0) return 2; //Форирование выборки невозможно

	fprintf_s(f4, "%d\n", NS);

	NC = 1;
	for (x = 0; x<xKT; x++)
	{
		//Открыть нормализованный файл из схемы Номер  из integer в char + полный путь к файлу
		p = 0; IC = NGF[x];
		if (IC != 0)
		{
			for (i = 0; i<10; i++) { z = IC % 10; if (z>0)p = i; NB[i] = CC[z]; IC = IC / 10; }
			i = nnT; for (z = 0; z<p + 1; z++)nmT[i + z] = NB[p - z];
			for (z = 0; z<5; z++)nmT[i + p + z + 1] = F1[z];

			for (j = 0; j<NR; j++)
				if (SHE[j][x]>0)
				{
					fopen_s(&f, nmT, "r");
					fscanf_s(f, "%d %d\n", &e, &p, 1);
					fprintf_s(f4, "_%d_\n", NC);
					i = p = 0; while (i<SHE[j][x]) { c = fgetc(f); if (c == '_')if (p == 0)p = 1; else p = 0; if (c != '\n'&& c != '_'&&p == 0)i++; }
					i = p = 0; while (i<DL[j]) { c = fgetc(f); if (c == '_')if (p == 0)p = 1; else p = 0; if (c != '\n'&& c != '_'&&p == 0) { fputc(c, f4); i++; } }
					fprintf_s(f4, "\n");
					fclose(f);
					NC++;
				}
		}
	}

	fclose(f4);

	return 0;
}
////////////////
