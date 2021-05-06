#include "StaticStack.h"
#include <string>

//Create()
//Cria e retorna uma pilha vazia.
//
//Pré - condição : N / A.
//Pós - condição : Uma nova pilha vazia é criada.
// sintaxe de funções:
// <retorno> <nome>(<parâmetros, caso aplicável>);
StaticStack Create()
{
	//struct StaticStack
	//{
	//	int current; // Topo da pilha.
	//	char values[STATIC_STACK_CAPACITY]; // Dados da pilha.
	//};

	StaticStack stack = { 0, { 0 } };
	return stack;
}

bool Push(StaticStack& stack, char elem)
{
	if (stack.count == STATIC_STACK_CAPACITY)
	{
		return false;
	}

	stack.values[stack.count] = elem;
	++stack.count;

	return true;
}

char Pop(StaticStack& stack)
{
	if (IsEmpty(stack))
	{
		return '\0';
	}

	char temp = stack.values[stack.count - 1];
	stack.values[stack.count - 1] = '\0';
	--stack.count;

	return temp;
}

char Top(const StaticStack& stack)
{
	if (IsEmpty(stack))
	{
		return '\0';
	}

	return stack.values[stack.count - 1];
}

int Size(const StaticStack& stack)
{
	return sizeof(stack.values) / sizeof(stack.values[0]);
}

int Count(const StaticStack& stack)
{
	return stack.count;
}

bool IsEmpty(const StaticStack& stack)
{
	return stack.count == 0;
}

bool Clear(StaticStack& stack)
{
	while (!IsEmpty(stack))
	{
		Pop(stack);
	}

	return IsEmpty(stack);
}
