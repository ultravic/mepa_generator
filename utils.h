#ifndef stack__
#define stack__

#define STACK_SIZE 1000

#define VS 0
#define PROCEDIMENTO 1
#define FUNCAO 2
#define ROTULO 3
#define MAX 32
#define REFERENCIA 0
#define SIMPLES 1
#define VALOR 2

/* Estrutura de uma variavel
 * tipo: tipo da variavel
 * offset: deslocamento
 * passagem: utilizado quando parametro para funcao (por valor ou referencia)
 */
typedef struct {
	int type;
	int offset;
	int parameter;
} variable;

/*Estrutura de procedimentos e funcoes
 *tipo: tipo de retornode( exclusivo de funcoes)
 *qtdeParametros: numero de parametros
 *offset: deslocamento (exclusivo de funcoes)
 *rotulo: nome do rotulo gerado na saida
 */
typedef struct {
	int type;
	int num_param;
	int offset;
	variable *parameters;
	char label[MAX];
} function;

/*Estrutura de rotulos
 *rotulo: nome do rotulo gerado na saida
 */
typedef struct {
	char label[MAX];
} label;

/*
 Tipos de dados suportados pela tabela de simbolos
 */
union types {
	variable simple;
	function func;
	label lab;
};

/*Item da tabela de simbolos
 *nl: nivel lexico 
 *categoria: indica o tipo de dado (variavel, rotina ou rotulo)
 *nome: nome do item 
 *item: variavel/proc/func/rotulo
 **/
typedef struct node {
	int nvl_lex;
	int category;
	char name[MAX];
	union types item;
} node;

/*
* stack utilizada para tabela de simbolos
* capacidade: tamanho maximo da stack
* tamanho: tamanho atual da stack
* primeiro: pronteiro para o topo item da stack
*/
typedef struct {
	int capacity;
	int size;
	node *head;
} stack;


//cria uma stack
stack* newStack();

//emstack o nodepassado
void push(stack*, node*);

//desemstack e retorna o no
node* pop(stack*);

//cria uma variavel simples
node* newVariable(int, char*, int, int, int);

//encontra um item na stack
node* find(stack*, char*);

//imprime a tabela de simbolos
void printStack(stack*);

//Pra contagem de variaeis alocadas dentro do nivel lexico
int checkOffset(stack*, int);

//cria um rotulo
node* newLabel(int, int);

//remove os itens do nivel lexico mais alto
int popStack(stack*, int);

//cria um procedimento
node* newProcedure(char*, int);

// //cria uma funcao
// node* criaFuncao(int,char*,int);





// //preenche o campo tipo das variaveis
// void preencherTipo(stack*,int,int);




// int alterarTipos(stack*,int,int);
#endif
