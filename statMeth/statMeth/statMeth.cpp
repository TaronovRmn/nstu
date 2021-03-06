// statMeth.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string const IN_FILE_NAME = "saR.txt";
string const OUT_FILE_NAME = "res.txt";

struct sol
{
	int errs = 0;
};
struct meth
{
	int better = 0;
	int worse = 0;
	int right = 0;
	int wrong = 0;
};

int search_errs(string &str)
{
	auto it = std::find_if(str.begin(), str.end(), isdigit);

	if (it != str.end()) return std::atoi(str.c_str() + (it - str.begin()));
	return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream fin(IN_FILE_NAME, ios::in); 
	if (!fin.is_open())
		return 1;

	ofstream fout(OUT_FILE_NAME, ios::out);

	int n_frags = 0, n_sols = 0;

	fin >> n_frags >> n_sols;
	vector<meth> methods;
	for (int it_sols = 0; it_sols < n_sols - 1; ++it_sols) methods.push_back(meth());

	string line;
	getline(fin, line);
	meth pref;
	for (int it_frags = 0; it_frags < n_frags; ++it_frags)
	{
		
		getline(fin, line); //_1_ M=8804
		getline(fin, line); // ETH
		
		getline(fin, line); //abc
		getline(fin, line); //errs
		sol eth;
		eth.errs = search_errs(line);
		if (eth.errs != 0) pref.wrong++;
		else pref.right++;

		for (int it_sols = 0; it_sols < n_sols - 1; ++it_sols)
		{
			sol sol;
			getline(fin, line); //abc
			getline(fin, line); //errs
			sol.errs = search_errs(line);
			if (sol.errs != 0) methods[it_sols].wrong++;
			else methods[it_sols].right++;
			if (sol.errs < eth.errs) methods[it_sols].better++;
			else if (sol.errs > eth.errs) methods[it_sols].worse++;
		}
		

		
	}
	fout << "Reference method right: " << pref.right << " wrong: " << pref.wrong << endl;
	for (int it_sols = 0; it_sols < n_sols - 1; ++it_sols)
	{
		fout << "Method: " << it_sols << " Right: " << methods[it_sols].right << " Wrong: " << methods[it_sols].wrong << " Better: " << methods[it_sols].better << " Worse: " << methods[it_sols].worse << endl;
	}

	fin.close();
	fout.close();
    return 0;
}

