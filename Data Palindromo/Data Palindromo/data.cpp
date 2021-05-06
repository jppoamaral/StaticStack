//Nome: João Pedro de Paula Oliveira do Amaral
//TIA: 32049390

#include <iostream>
#include <string>
#include "StaticStack.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "pt_BR");
	string sdate;
	char slash = '/';
	char reverse[MAX];
	cout << "Digite uma data no modelo DD/MM/AAAA: ";
	cin >> sdate;

	StaticStack date = Create();
	for (int i = 0; i < sdate.size(); ++i)
		if (sdate[i] != slash)
			Push(date, (char)sdate[i]);

	for (int i = 0; i < MAX; ++i)
		reverse[i] = date.values[MAX-1-i];

	int count = 0;
	for (int i = 0; i < MAX; ++i)
		if (date.values[i] == reverse[i])
			count++;
	if (count == MAX)
		cout << "Essa é uma data palíndroma!";
	else
		cout << "Essa data nãó é palíndroma!";
}