//Nome: Jo�o Pedro de Paula Oliveira do Amaral
//TIA: 32049390

#include <iostream>
#include <string>
#include "StaticStack.h"
using namespace std;

int main()
{	
	setlocale(LC_ALL, "pt_BR");

	char reverse[MAX]{};
	string frase, space =  " ";

	cout << "Digite uma palavra ou frase (max de " << MAX << " caracteres sem contar os espa�os): ";
	getline(cin, frase);

	StaticStack stack = Create();

	for(int i = 0; i < frase.size(); ++i)
		if (frase[i] != space[0])
			Push(stack, (char)frase[i]);

	for (int i = 0; i < frase.size(); ++i)
		reverse[i] = stack.values[stack.count-1-i];

	int count = 0;
	for (int i = 0; i < stack.count; ++i)
	{
		if (stack.values[i] == reverse[i])
			count++;
	}

	if (count == stack.count)
		cout << "� um pal�mdromo!";
	else
		cout << "N�o � um pal�ndromo";
}