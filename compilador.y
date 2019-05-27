
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "stack.h"

extern int yylex(void);
extern char *yytext;

int nvl_lex = 0;
int offset = 0;
int write = 0;
int call_flag = 0;

stack *aux;
stack *labels;
stack *parameters;

node *var_label;
node *temporary;
node *proced, *funct;
node *temporary_var;
node *temporary_lab;
node *aux_lab;

int count_param;
int i_index;
int nvl_lex;

char s[32];

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES 
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token OR AND NOT MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL
%token IGUAL WRITE READ SLASH VEZES NUMERO MAIS MENOS
%token PONTO_PONTO WHILE IF THEN ELSE DO DIV
%token PROCEDURE FUNCTION LABEL DIFERENTE

%%

programa:   
            { 
                geraCodigo(NULL, "INPP"); 
            }
            PROGRAM IDENT 
            ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
            bloco PONTO 
            {
                geraCodigo(NULL, "PARA"); 
            }
;

bloco: 
            parte_declara_vars
            {
                geraRotulo(s);
                temporary_lab = newLabel(atoi(s), nvl_lex);

                strcpy(temporary_lab->item.lab.label, s);
                sprintf(s, "DSVS %s", temporary_lab->item.lab.label);

                geraCodigo(NULL, s);
                push(labels, temporary_lab);
            }

            {
                aux_lab = pop(labels);
                sprintf(s, "%s", aux_lab->item.lab.label);
                geraCodigo(s, "NADA");
            }
            comando_composto
            {
                offset = popStack(symbols_table, nvl_lex);
                
                if (offset) {
                    sprintf(s,"DMEM %d", offset);
                    geraCodigo(NULL, s);
                }

                if (symbols_table->size) {
                    temporary = &(symbols_table->head[symbols_table->size-1]);
                    if (temporary->category == PROCEDIMENTO || temporary->category == FUNCAO) {
                        sprintf(s, "RTPR %d, %d", nvl_lex, temporary->item.func.num_param);	
                        geraCodigo(NULL, s);
                    }
                }
            }
;

parte_declara_vars:  
                    var 
;

var:        
            { 
                aux->size = 0;
                offset = 0;
            } 
            VAR declara_vars
            |
;

declara_vars: 
            declara_var declara_vars 
            | declara_var
;

declara_var:    
                lista_idents DOIS_PONTOS 
                tipo 
                { /* AMEM */
                    int type;
                    if (!strcmp(yytext, "integer")) {
                        type = 7;
                    } else {
                        type = 1;
                    }
                    
                }
                PONTO_E_VIRGULA
                {
                    if (aux->size) {
                        sprintf(s, "AMEM %d", aux->size);
                        geraCodigo(NULL, s);
                    }
                    offset = aux->size;
                    for (i_index = 0; i_index < aux->size; i_index++) {
                        push(symbols_table, &(aux->head[i_index]));
                    }
                    aux->size = 0;
                }
;

tipo:   
            IDENT
;

lista_idents:	
    identificador
    {
        if (strcmp(yytext, "input") && strcmp(yytext, "output")) {
            var_label = newVariable(1, yytext, nvl_lex, offset, SIMPLES);
            push(aux, var_label);
            offset++;
        }
    }
    lista_idents_lp
;

lista_idents_lp:
    | VIRGULA identificador
    {
        if (strcmp(yytext, "input") && strcmp(yytext, "output")) {
            var_label = newVariable(1, yytext, nvl_lex, offset, SIMPLES);
            push(aux, var_label);
            offset++;
        }
    }
    lista_idents_lp
;

comando_composto: T_BEGIN comando comando_composto_loop T_END
;

comando_composto_loop: 
                | PONTO_E_VIRGULA comando comando_composto_loop
; 

comando:
        NUMERO
        {
            temporary = find(symbols_table, yytext);
            if (temporary) {
                sprintf(s, "ENRT %d %d", nvl_lex, checkOffset(symbols_table, nvl_lex));
                geraCodigo(temporary->item.lab.label, s);
            } else {
                yyerror("label nao declarado.\n");
                exit(1);
            }
        }
        DOIS_PONTOS comando_sem_label
        | comando_sem_label
;

comando_sem_label:
            | comando_composto
            | comando_condicional 
            | comando_repetitivo
            | comando_escrita
            | comando_leitura
            | atribuicao 
;

comando_condicional:
            IF expressao
            {
                geraRotulo(s);
                temporary_lab = newLabel(s, nvl_lex);

                strcpy(temporary_lab->item.lab.label, s);
                push(labels, temporary_lab);

                sprintf(s, "DSVF %s", temporary_lab->item.lab.label);
                geraCodigo(NULL, s);
            }
            THEN comando_sem_label
            {
                geraRotulo(s);
                temporary_lab = newLabel(s, nvl_lex);

                strcpy(temporary_lab->item.lab.label, s);
                sprintf(s, "DSVS %s", temporary_lab->item.lab.label);

                geraCodigo(NULL, s);
                aux_lab = pop(labels);

                sprintf(s, "%s", aux_lab->item.lab.label);
                geraCodigo(s, "NADA");
                push(labels, temporary_lab);
            } 
            comando_condicional_else
            {
                temporary = pop(labels);
                sprintf(s, "%s", temporary->item.lab.label);
                geraCodigo(s, "NADA");
            }
;

comando_condicional_else:
            | ELSE comando_sem_label
;

comando_repetitivo:
            WHILE
            {
                geraRotulo(s);
                temporary_lab = newLabel(s, nvl_lex);

                strcpy(temporary_lab->item.lab.label, s);
                sprintf(s, "NADA");

                geraCodigo(temporary_lab->item.lab.label, s);
                push(labels, temporary_lab);
            }
            expressao
            {
                geraRotulo(s);
                temporary_lab = newLabel(s, nvl_lex);

                strcpy(temporary_lab->item.lab.label, s);
                sprintf(s, "DSVF %s", temporary_lab->item.lab.label);

                geraCodigo(NULL, s);
                push(labels, temporary_lab);
            }
            DO comando_sem_label
            {
                temporary_lab = pop(labels);
                aux_lab = pop(labels);

                sprintf(s, "DSVS %s", aux_lab->item.lab.label);
                geraCodigo(NULL, s);

                sprintf(s, "%s", temporary_lab->item.lab.label);
                geraCodigo(s, "NADA");
            }
;


comando_escrita:
                WRITE
                {
                    write = 1;
                }
                ABRE_PARENTESES lista_expressoes FECHA_PARENTESES
                {
                    write = 0;
                }
;

comando_leitura:
                READ
                ABRE_PARENTESES comando_leitura_1 FECHA_PARENTESES
;

comando_leitura_1:
            {
                sprintf(s, "LEIT");
                geraCodigo(NULL, s);
            }
            variavel
            {
                if (!temporary) {
                    yyerror("Variavel nao declarada.");
                    exit(1);
                }
                if (temporary->item.simple.parameter == REFERENCIA) {
                    sprintf(s, "ARMI %d, %d", temporary->nvl_lex, temporary->item.simple.offset);
                    geraCodigo(NULL, s);
                }
                else if (temporary->item.simple.parameter == VALOR || temporary->item.simple.parameter == SIMPLES) {
                    sprintf(s, "ARMZ %d, %d", temporary->nvl_lex, temporary->item.simple.offset);
                    geraCodigo(NULL, s);
                }
            }
            comando_leitura_1_loop
;

comando_leitura_1_loop:
            | VIRGULA comando_leitura_1
;

lista_expressoes:
            expressao
            {
                if (write) {
                    sprintf(s, "IMPR");
                    geraCodigo(NULL, s);
                }
            }
            lista_expressoes_loop
;

lista_expressoes_loop:
            | VIRGULA expressao
            {
                if (write) {
                    sprintf(s, "IMPR");
                    geraCodigo(NULL, s);
                }
            }
            lista_expressoes_loop
;

expressao:
            expressao_simples
            { 
                if (proced || funct) count_param++; 
            }
            | expressao_simples IGUAL expressao_simples 
            {
                if (proced || funct) count_param++; 
                sprintf(s, "CMIG");
                geraCodigo(NULL, s);
            }
            | expressao_simples DIFERENTE expressao_simples 
            {
                if (proced || funct) count_param++; 
                sprintf(s, "CMDG");
                geraCodigo(NULL, s);
            }
            | expressao_simples MENOR expressao_simples 
            {
                if (proced || funct) count_param++; 
                sprintf(s, "CMME");
                geraCodigo(NULL, s);
            }
            | expressao_simples MAIOR expressao_simples 
            {
                if (proced || funct) count_param++; 
                sprintf(s, "CMMA");
                geraCodigo(NULL, s);
            }
            | expressao_simples MAIOR_IGUAL expressao_simples 
            {
                if (proced || funct) count_param++; 
                sprintf(s, "CMAG");
                geraCodigo(NULL, s);
            }
            | expressao_simples MENOR_IGUAL expressao_simples 
            {
                if (proced || funct) count_param++; 
                sprintf(s, "CMEG");
                geraCodigo(NULL, s);
            }
;
 
expressao_simples:
            termo expressao_simples_loop
            | MAIS termo expressao_simples_loop
            | MENOS termo 
            {
                sprintf(s, "INVR");
                geraCodigo(NULL, s);
            }
            expressao_simples_loop
;

expressao_simples_loop:
            | MAIS termo 
            {
                sprintf(s, "SOMA");
                geraCodigo(NULL, s);
            } expressao_simples_loop
            | MENOS termo 
            {
                sprintf(s, "SUBT");
                geraCodigo(NULL, s);
            }
            expressao_simples_loop 
            | OR termo 
            {
                sprintf(s, "DISJ");
                geraCodigo(NULL, s);
            }
            expressao_simples_loop
;

termo: 
            fator termo_loop
;

termo_loop:
            | VEZES fator 
            {
                sprintf(s, "MULT");
                geraCodigo(NULL, s);
            } termo_loop
            | DIV fator 
            {
                sprintf(s, "DIVI");
                geraCodigo(NULL, s);
            } termo_loop
            | AND fator 
            {
                sprintf(s, "CONJ");
                geraCodigo(NULL, s);
            }
;

fator: 
            variavel
            { 
                if (temporary) {
                    if ((proced) && count_param >= proced->item.func.num_param ) {
                        yyerror("Procedimento chamado com numero invalido de count_param.");
                        exit(1);
                    }
                    if ((funct) && count_param > funct->item.func.num_param ) {
                        printf("esperado: %d, %d encontrados\n\n",funct->item.func.num_param,count_param);
                        exit(1);
                    }
                    if ((proced) && proced->item.func.parameters[count_param].parameter == REFERENCIA) {
                        sprintf(s, "CREN %d, %d", temporary->nvl_lex, temporary->item.simple.offset);
                        geraCodigo(NULL, s);
                    } else {
                        if ((funct) && funct->item.func.parameters[count_param].parameter == REFERENCIA) {
                            if (call_flag) {
                                sprintf(s, "CREN %d, %d", temporary->nvl_lex, temporary->item.simple.offset);
                                geraCodigo(NULL, s);
                            } else {
                                sprintf(s, "CRVL %d, %d", temporary->nvl_lex, temporary->item.simple.offset);
                                geraCodigo(NULL, s);
                            }
                        } else { 
                            if (temporary->item.simple.parameter == REFERENCIA) {
                                sprintf(s, "CRVI %d, %d", temporary->nvl_lex, temporary->item.simple.offset);
                                geraCodigo(NULL, s);
                            } else {
                                sprintf(s, "CRVL %d, %d", temporary->nvl_lex, temporary->item.simple.offset);
                                geraCodigo(NULL, s);
                            }
                        }
                    }
                }
            }
            | numero 
            {
                sprintf(s, "CRCT %s", yytext);
                geraCodigo(NULL, s);
            }
            | ABRE_PARENTESES expressao FECHA_PARENTESES
            | NOT fator 
            {
                geraCodigo(NULL, "NEGA");
            }
;

atribuicao:  
            variavel
            {
                temporary_var = temporary;
            }
            ATRIBUICAO expressao
            {
                if (!temporary_var) {
                    yyerror("Variavel nao declarada.");
                    exit(1);
                }

                if (temporary_var->category == FUNCAO) {
                    sprintf(s, "ARMZ %d, %d" , temporary_var->nvl_lex, temporary_var->item.func.offset);
                    geraCodigo(NULL, s);
                } else {
                    if (temporary_var->item.simple.parameter == REFERENCIA) {
                        sprintf(s, "ARMI %d, %d", temporary_var->nvl_lex, temporary_var->item.simple.offset);
                        geraCodigo(NULL, s);
                    } else {
                        sprintf(s, "ARMZ %d, %d" , temporary_var->nvl_lex, temporary_var->item.simple.offset);
                        geraCodigo(NULL, s);
                    }
                }
            }
;

variavel:
        identificador
;

identificador:
        IDENT
        {
            temporary = find(symbols_table, yytext);
        }
;

numero:
        NUMERO
;

%%

int main (int argc, char** argv) {
    FILE *fp;
    extern FILE *yyin;

    if (argc<2 || argc>2) {
        printf("usage compilador <arq>a %d\n", argc);
        return(-1);
    }

    fp=fopen (argv[1], "r");
    if (fp == NULL) {
        printf("usage compilador <arq>b\n");
        return(-1);
    }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de S�mbolos
 * ------------------------------------------------------------------- */

    symbols_table = newStack();
    aux = newStack();
    labels = newStack();
    parameters = newStack();

    yyin=fp;
    yyparse();
    fclose(fp);

    printStack(symbols_table);

    return 0;
}

