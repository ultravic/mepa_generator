#ifndef __stack__
#define __stack__

#define STACK_SIZE 1000

#define PROCEDURE_TP 1
#define REFERENCE_TP 0
#define FUNCTION_TP 2
#define SIMPLE_TP 1
#define LABEL_TP 3
#define VALUE_TP 2
#define MAX 32
#define VS 0

// Base data types

typedef struct {
	int type;
	int offset;
	int parameter;
} variable;

typedef struct {
	char label[MAX];
} label;

typedef struct {
	int type;
	int num_param;
	int offset;
	variable *parameters;
	char label_f[MAX];
	char label[MAX];
} function;

union types {
	variable simple;
	function func;
	label lab;
};

typedef struct node {
	int nvl_lex;
	int category;
	char name[MAX];
	union types item;
} node;

typedef struct {
	int capacity;
	int size;
	node *head;
} stack;

// Utilitaries functions

stack* newStack();

void push(stack*, node*);

node* pop(stack*);

node* newVariable(int, char*, int, int, int);

node* find(stack*, char*);

void printStack(stack*);

int checkOffset(stack*, int);

node* newLabel(int, int);

int popStack(stack*, int);

node* newProcedure(char*, int);

node* newFunction(int, char*, int);

int switchType(stack*, int, int);

#endif
