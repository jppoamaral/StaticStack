//Nome: João Pedro de Paula Oliveira do Amaral
//TIA: 32049390

#include <iostream>
#include <string>
#include <algorithm>
#include "StaticStack.h"
using namespace std;

int findBracket(char bracket, char brackets[])
{
	int idx, i;
	
	for (i = 0; i < MAX; i++)
		if (bracket == brackets[i])
			idx = i;

	return idx;
}
int main()
{
	setlocale(LC_ALL, "pt_BR");
	char brackets[MAX]{ '{', '[', '<', '(', 
						'}', ']', '>', ')' };
	string s;
	int index[MAX]{}, i, j;
	cout << "Digite uma expressão: ";
	cin >> s;

	StaticStack symbols = Create();
	for (i = 0; i < s.size(); i++)
		for (j = 0; j < MAX; j++)
			if (s[i] == brackets[j])
				Push(symbols, (char)s[i]);

	for (i = 0; i < symbols.count; i++)
		index[i] = findBracket(symbols.values[i], brackets);

	i = 0;
	j = MAX - 1;
	while (i < 4)
		if (brackets[index[i]] == brackets[index[j]-4])
		{
			i++;
			j--;
		}
		else
		{
			cout << "Error ! ! !";
			return 0;
		}
	cout << "OK";
}