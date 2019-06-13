#ifndef _stack_c_
#define _stack_c_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "../src/compilador.h"

//-----------------------------------------------------

void checkStack(stack *stk) {
	if (!stk) {    
		printf("Pilha nao alocada\n");
		exit(1);
	}
}

//-----------------------------------------------------

void push(stack *stk, node *nd) {
	if (stk->size+1 >= stk->capacity) {
		stk->capacity *= 2;
		stk->head = (node*)realloc(stk->head, stk->capacity*sizeof(node));
	}
	stk->head[stk->size] = *nd;
	stk->size++;
}

//-----------------------------------------------------

node* pop(stack *stk) {
	checkStack(stk);
	if (stk->size == 0) return stk->head;

	node *aux = &(stk->head[stk->size-1]);
	stk->size--;

	return aux;
}

//-----------------------------------------------------

node* find(stack *stk, char* name)
{
   int index;
   int jndex = stk->size;

   for (index = jndex - 1; index >= 0; index--)
      if (!(strcmp(name, stk->head[index].name)))
			return &(stk->head[index]);

   return NULL;
}

//-----------------------------------------------------

node* newVariable(int type, char* token, int nvl_lex, int offset, int ref) 
{
	node *aux = (node*)malloc(sizeof(node));
	
	aux->nvl_lex = nvl_lex;
	aux->category = VS;
	
	strcpy(aux->name, token);
	
	aux->item.simple.offset = offset;
	aux->item.simple.type = type;
	aux->item.simple.parameter = ref;

	return aux;
}

//-----------------------------------------------------

void printStack(stack *stk)
{
	int index;
	int jndex;
	node aux;

	for (index = 0; index < stk->size; index++) {
		aux = stk->head[index];
		printf("%s %d %d \t", aux.name, aux.category, aux.nvl_lex);

		if (stk->head[index].category == VS)
			printf("offset: %d\tpassagem: %d\t tipo: %d", aux.item.simple.offset, aux.item.simple.parameter, aux.item.simple.type);
		if (stk->head[index].category == FUNCTION_TP) {
			printf("offset: %d\tparams: %d", aux.item.func.offset, aux.item.func.num_param);
			for (jndex = 0; jndex < aux.item.func.num_param; jndex++)
				printf("\tp%d: %d", jndex, aux.item.func.parameters[jndex].parameter);
		}
		printf("\n");
	}
}

//-----------------------------------------------------

int checkOffset(stack *stk, int nvl_lex)
{
	int count = 0;
	int index = stk->size - 1;
	node aux;

	while (1) {
		aux = stk->head[index];

		if (aux.nvl_lex < nvl_lex) break;
		if (aux.category == VS && aux.item.simple.parameter == SIMPLE_TP)
			count++;

		index--;
	}

	return count;
}

//-----------------------------------------------------

stack *newStack()
{
	stack *stk = (stack*)malloc(sizeof(stack));
	stk->head = (node*)malloc(sizeof(node)*STACK_SIZE);

	stk->size = 0;
	stk->capacity = STACK_SIZE;

	return stk;
}

//-----------------------------------------------------

node* newLabel(int label, int nvl_lex)
{
	node *aux = (node*)malloc(sizeof(node));
	char convert[MAX];

	aux->nvl_lex = nvl_lex;
	aux->category = LABEL_TP;

	sprintf(convert, "%d", label);
	strcpy(aux->name, convert);

	return aux;
}

//-----------------------------------------------------

int popStack(stack *stk, int nvl_lex)
{
	node* temporary = stk->head;
	node* aux;
	int count = 0;
	int nvl = nvl_lex;

	while (stk->size) {
		if (temporary[stk->size-1].category == FUNCTION_TP || temporary[stk->size-1].category == PROCEDURE_TP) {
			if (temporary[stk->size-1].nvl_lex > nvl)
				aux = pop(stk);
			else
				break;
		} else {
			if (temporary[stk->size-1].nvl_lex == nvl) {
				aux =pop(stk);
				if (aux->category == VS && aux->item.simple.parameter == SIMPLE_TP)
					count++;
			} else
				break;
		}
	}
	return count;
}

//-----------------------------------------------------

node* newProcedure(char* token, int nvl_lex)
{
	node *aux = (node*)malloc(sizeof(node));

	aux->nvl_lex = nvl_lex;
	aux->category = PROCEDURE_TP;

	strcpy(aux->name, token);

	return aux;
}

//-----------------------------------------------------

node* newFunction(int type, char* token, int nvl_lex)
{
	node *aux = (node*)malloc(sizeof(node));

	aux->nvl_lex = nvl_lex;
	aux->category = FUNCTION_TP;

	strcpy(aux->name, token);

	return aux;
}

//-----------------------------------------------------

int switchType(stack *stk, int offset, int type)
{
	int index;
	int count = 0;

	for (index = stk->size - 1; index >= stk->size - offset; index--) {
		if (stk->head[index].category == VS) {
			stk->head[index].item.simple.type = type;
			count++;
		}
	}

	return count;
}

#endif
