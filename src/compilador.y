
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "src/compilador.h"
#include "utils/utils.h"

extern int yylex(void);
extern char *yytext;

int nvl_lex = 0;
int offset = 0;
int write = 0;
int call_flag = 0;
int type_rst = 0;
int is_bool = 0;

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
int i_index, j_index;;
int nl;

char str_tmp[32];

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES 
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token OR AND NOT MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL
%token IGUAL WRITE READ VEZES NUMERO MAIS MENOS
%token WHILE IF THEN ELSE DO DIV
%token PROCEDURE FUNCTION LABEL DIFERENTE GOTO
%token INTEGER BOOLEAN TRUE FALSE FORWARD

%%

program:   
            { 
                geraCodigo(NULL, "INPP"); 
            }
            PROGRAM IDENT 
            ABRE_PARENTESES ident_lists FECHA_PARENTESES PONTO_E_VIRGULA
            block PONTO 
            {
                geraCodigo(NULL, "PARA"); 
            }
;

block: 
            label_declaration
            var_declaration
            {
                geraRotulo(str_tmp);
                temporary_lab = newLabel(atoi(str_tmp), nvl_lex);

                strcpy(temporary_lab->item.lab.label, str_tmp);
                sprintf(str_tmp, "DSVS %s", temporary_lab->item.lab.label);

                geraCodigo(NULL, str_tmp);
                push(labels, temporary_lab);
            }
            routine_declaration
            {
                aux_lab = pop(labels);
                sprintf(str_tmp, "%s", aux_lab->item.lab.label);
                geraCodigo(str_tmp, "NADA");
                printStack(symbols_table);
            }
            comp_cmd
            {   
                offset = popStack(symbols_table, nvl_lex);
                
                if (offset) {
                    sprintf(str_tmp, "DMEM %d", offset);
                    geraCodigo(NULL, str_tmp);
                }

                if (symbols_table->size) {
                    temporary = &(symbols_table->head[symbols_table->size-1]);
                    if (temporary->category == PROCEDURE_TP || temporary->category == FUNCTION_TP) {
                        sprintf(str_tmp, "RTPR %d, %d", nvl_lex, temporary->item.func.num_param);	
                        geraCodigo(NULL, str_tmp);
                    }
                }
            }
;

label_declaration:
            |
            LABEL
            NUMERO
            {
                temporary = newLabel(atoi(yytext), nvl_lex);
                geraRotulo(temporary->item.lab.label);

                push(symbols_table, temporary);
                temporary = NULL;

            }
            label_declaration_lp
            PONTO_E_VIRGULA
;

label_declaration_lp:
            | VIRGULA NUMERO
            {
                temporary = newLabel(atoi(yytext), nvl_lex);
                geraRotulo(temporary->item.lab.label);
                
                push(symbols_table, temporary);
                temporary = NULL;
            }
            label_declaration_lp
;

var_declaration:  
            { 
                aux->size = 0;
                offset = 0;
            } 
            VAR vars
            |
;

vars: 
            var vars 
            | var
;

var:    
            ident_lists DOIS_PONTOS 
            {
                if (aux->size) {
                    sprintf(str_tmp, "AMEM %d", aux->size);
                    geraCodigo(NULL, str_tmp);
                }
                offset = aux->size;
                for (i_index = 0; i_index < aux->size; i_index++) {
                    push(symbols_table, &(aux->head[i_index]));
                }
                aux->size = 0;
            }
            type 
            PONTO_E_VIRGULA
;

type:   
            INTEGER
            {
                switchType(symbols_table, offset, 7);
            }
            | BOOLEAN
            {
                switchType(symbols_table, offset, 8);                    
            }
            | IDENT
            {
                switchType(symbols_table, offset, 1);
            }
;

ident_lists:	
            identificator
            {
                if (strcmp(yytext, "input") && strcmp(yytext, "output")) {
                    var_label = newVariable(1, yytext, nvl_lex, offset, SIMPLE_TP);
                    push(aux, var_label);
                    offset++;
                }
            }
            ident_lists_lp
;

ident_lists_lp:
            | VIRGULA identificator
            {
                if (strcmp(yytext, "input") && strcmp(yytext, "output")) {
                    var_label = newVariable(1, yytext, nvl_lex, offset, SIMPLE_TP);
                    push(aux, var_label);
                    offset++;
                }
            }
            ident_lists_lp
;

comp_cmd: 
            T_BEGIN cmd comp_cmd_loop T_END
;

comp_cmd_loop: 
            | PONTO_E_VIRGULA cmd comp_cmd_loop
; 

cmd:
            NUMERO
            {
                temporary = find(symbols_table, yytext);
                if (temporary) {
                    sprintf(str_tmp, "ENRT %d %d", nvl_lex, checkOffset(symbols_table, nvl_lex));
                    geraCodigo(temporary->item.lab.label, str_tmp);
                } else {
                    yyerror("label nao declarado.\n");
                    exit(1);
                }
            }
            DOIS_PONTOS unlabeled_cmd
            | unlabeled_cmd
;

unlabeled_cmd:
            | procedure_call
            | function_call
            | comp_cmd
            | cond_cmd 
            | loop_cmd
            | write
            | read
            | assignment
            | goto
;

cond_cmd:
            {
                is_bool = 0;
            }
            IF expression
            {
                if (!is_bool) {
                    yyerror("Resultado não booleano.");
                    exit(1);
                }
                geraRotulo(str_tmp);
                temporary_lab = newLabel(str_tmp, nl);

                strcpy(temporary_lab->item.lab.label, str_tmp);
                push(labels, temporary_lab);

                sprintf(str_tmp, "DSVF %s", temporary_lab->item.lab.label);
                geraCodigo(NULL, str_tmp);
            }
            THEN unlabeled_cmd
            {
                geraRotulo(str_tmp);
                temporary_lab = newLabel(str_tmp, nl);

                strcpy(temporary_lab->item.lab.label, str_tmp);
                sprintf(str_tmp, "DSVS %s", temporary_lab->item.lab.label);

                geraCodigo(NULL, str_tmp);
                aux_lab = pop(labels);

                sprintf(str_tmp, "%s", aux_lab->item.lab.label);
                geraCodigo(str_tmp, "NADA");
                push(labels, temporary_lab);
            } 
            cond_cmd_else
            {
                temporary = pop(labels);
                sprintf(str_tmp, "%s", temporary->item.lab.label);
                geraCodigo(str_tmp, "NADA");
            }
;

cond_cmd_else:
            | ELSE unlabeled_cmd
;

loop_cmd:
            {
                is_bool = 0;
            }
            WHILE
            {
                geraRotulo(str_tmp);
                temporary_lab = newLabel(str_tmp, nl);

                strcpy(temporary_lab->item.lab.label, str_tmp);
                sprintf(str_tmp, "NADA");

                geraCodigo(temporary_lab->item.lab.label, str_tmp);
                push(labels, temporary_lab);
            }
            expression
            {
                if (!is_bool) {
                    yyerror("Resultado não booleano.");
                    exit(1);
                }
                geraRotulo(str_tmp);
                temporary_lab = newLabel(str_tmp, nl);

                strcpy(temporary_lab->item.lab.label, str_tmp);
                sprintf(str_tmp, "DSVF %s", temporary_lab->item.lab.label);

                geraCodigo(NULL, str_tmp);
                push(labels, temporary_lab);
            }
            DO unlabeled_cmd
            {
                temporary_lab = pop(labels);
                aux_lab = pop(labels);

                sprintf(str_tmp, "DSVS %s", aux_lab->item.lab.label);
                geraCodigo(NULL, str_tmp);

                sprintf(str_tmp, "%s", temporary_lab->item.lab.label);
                geraCodigo(str_tmp, "NADA");
            }
;


write:
            WRITE
            {
                write = 1;
            }
            ABRE_PARENTESES expressions FECHA_PARENTESES
            {
                write = 0;
            }
;

read:
            READ
            ABRE_PARENTESES read_section FECHA_PARENTESES
;

read_section:
            {
                sprintf(str_tmp, "LEIT");
                geraCodigo(NULL, str_tmp);
            }
            identificator
            {
                if (!temporary) {
                    yyerror("Variavel nao declarada.");
                    exit(1);
                }
                if (temporary->item.simple.parameter == REFERENCE_TP) {
                    sprintf(str_tmp, "ARMI %d, %d", temporary->nvl_lex, temporary->item.simple.offset);
                    geraCodigo(NULL, str_tmp);
                }
                else if (temporary->item.simple.parameter == VALUE_TP || temporary->item.simple.parameter == SIMPLE_TP) {
                    sprintf(str_tmp, "ARMZ %d, %d", temporary->nvl_lex, temporary->item.simple.offset);
                    geraCodigo(NULL, str_tmp);
                }
            }
            read_section_lp
;

read_section_lp:
            | VIRGULA read_section
;

expressions:
            expression
            {
                if (write) {
                    sprintf(str_tmp, "IMPR");
                    geraCodigo(NULL, str_tmp);
                }
            }
            expressions_loop
;

expressions_loop:
            | VIRGULA expression
            {
                if (write) {
                    sprintf(str_tmp, "IMPR");
                    geraCodigo(NULL, str_tmp);
                }
            }
            expressions_loop
;

expression:
            normal_expression
            { 
                if (proced || funct) count_param++;
            }
            | normal_expression IGUAL normal_expression 
            {
                if (proced || funct) count_param++; 
                sprintf(str_tmp, "CMIG");
                geraCodigo(NULL, str_tmp);
                if (temporary_var) {
                    if (temporary_var->category == VS) {
                        if (temporary_var->item.simple.type != 8) {
                            yyerror("Atribuição incorreta.");
                            exit(1);
                        }
                    }
                }
                is_bool++;
            }
            | normal_expression DIFERENTE normal_expression 
            {
                if (proced || funct) count_param++;
                sprintf(str_tmp, "CMDG");
                geraCodigo(NULL, str_tmp);
                if (temporary_var) {
                    if (temporary_var->category == VS) {
                        if (temporary_var->item.simple.type != 8) {
                            yyerror("Atribuição incorreta.");
                            exit(1);
                        }
                    }
                }
                is_bool++;
            }
            | normal_expression MENOR normal_expression 
            {
                if (proced || funct) count_param++; 
                sprintf(str_tmp, "CMME");
                geraCodigo(NULL, str_tmp);
                if (temporary_var) {
                    if (temporary_var->category == VS) {
                        if (temporary_var->item.simple.type != 8) {
                            yyerror("Atribuição incorreta.");
                            exit(1);
                        }
                    }
                }
                is_bool++;
            }
            | normal_expression MAIOR normal_expression 
            {
                if (proced || funct) count_param++; 
                sprintf(str_tmp, "CMMA");
                geraCodigo(NULL, str_tmp);
                if (temporary_var) {
                    if (temporary_var->category == VS) {
                        if (temporary_var->item.simple.type != 8) {
                            yyerror("Atribuição incorreta.");
                            exit(1);
                        }
                    }
                }
                is_bool++;
            }
            | normal_expression MAIOR_IGUAL normal_expression 
            {
                if (proced || funct) count_param++; 
                sprintf(str_tmp, "CMAG");
                geraCodigo(NULL, str_tmp);
                if (temporary_var) {
                    if (temporary_var->category == VS) {
                        if (temporary_var->item.simple.type != 8) {
                            yyerror("Atribuição incorreta.");
                            exit(1);
                        }
                    }
                }
                is_bool++;
            }
            | normal_expression MENOR_IGUAL normal_expression 
            {
                if (proced || funct) count_param++; 
                sprintf(str_tmp, "CMEG");
                geraCodigo(NULL, str_tmp);
                if (temporary_var) {
                    if (temporary_var->category == VS) {
                        if (temporary_var->item.simple.type != 8) {
                            yyerror("Atribuição incorreta.");
                            exit(1);
                        }
                    }
                }
                is_bool++;
            }
;
 
normal_expression:
            term normal_expression_lp
            | MAIS term normal_expression_lp
            | MENOS term 
            {
                sprintf(str_tmp, "INVR");
                geraCodigo(NULL, str_tmp);
            }
            normal_expression_lp
;

normal_expression_lp:
            | MAIS term 
            {
                sprintf(str_tmp, "SOMA");
                geraCodigo(NULL, str_tmp);
            } normal_expression_lp
            | MENOS term 
            {
                sprintf(str_tmp, "SUBT");
                geraCodigo(NULL, str_tmp);
            }
            normal_expression_lp 
            | OR term 
            {
                sprintf(str_tmp, "DISJ");
                geraCodigo(NULL, str_tmp);
                is_bool++;
            }
            normal_expression_lp
;

term: 
            element term_lp
;

term_lp:
            | VEZES element 
            {
                sprintf(str_tmp, "MULT");
                geraCodigo(NULL, str_tmp);
            } term_lp
            | DIV element 
            {
                sprintf(str_tmp, "DIVI");
                geraCodigo(NULL, str_tmp);
            } term_lp
            | AND element 
            {
                sprintf(str_tmp, "CONJ");
                geraCodigo(NULL, str_tmp);
                is_bool++;
            }
;

element: 
            identificator
            {

                if (temporary) {
                    if ((proced) && count_param >= proced->item.func.num_param) {
                        yyerror("Procedimento chamado com numero invalido de count_param.");
                        exit(1);
                    }
                    if ((funct) && count_param > funct->item.func.num_param) {
                        printf("esperado: %d, %d encontrados\n\n", funct->item.func.num_param, count_param);
                        exit(1);
                    }
                    if ((proced) && proced->item.func.parameters[(proced->item.func.num_param - 1) - count_param].parameter == REFERENCE_TP) {
                        if (temporary->item.simple.parameter == REFERENCE_TP) {
                            sprintf(str_tmp, "CRVL %d, %d", temporary->nvl_lex, temporary->item.simple.offset);
                            geraCodigo(NULL, str_tmp);
                        } else {
                            sprintf(str_tmp, "CREN %d, %d", temporary->nvl_lex, temporary->item.simple.offset);
                            geraCodigo(NULL, str_tmp);
                        }
                    } else {                        
                        if ((funct) && funct->item.func.parameters[count_param].parameter == REFERENCE_TP) {
                            if (call_flag) {
                                sprintf(str_tmp, "CREN %d, %d", temporary->nvl_lex, temporary->item.simple.offset);
                                geraCodigo(NULL, str_tmp);
                            } else {
                                sprintf(str_tmp, "CRVL %d, %d", temporary->nvl_lex, temporary->item.simple.offset);
                                geraCodigo(NULL, str_tmp);
                            }
                        } else {
                            if (temporary->item.simple.parameter == REFERENCE_TP) {
                                sprintf(str_tmp, "CRVI %d, %d", temporary->nvl_lex, temporary->item.simple.offset);
                                geraCodigo(NULL, str_tmp);
                            } else {
                                sprintf(str_tmp, "CRVL %d, %d", temporary->nvl_lex, temporary->item.simple.offset);
                                geraCodigo(NULL, str_tmp);
                            }
                        }
                    }
                }
            }          
            | NUMERO 
            {
                sprintf(str_tmp, "CRCT %s", yytext);
                geraCodigo(NULL, str_tmp);
            }
            | TRUE
            {
                sprintf(str_tmp, "CRCT 1");
                geraCodigo(NULL, str_tmp);
            }
            | FALSE
            {
                sprintf(str_tmp, "CRCT 0");
                geraCodigo(NULL, str_tmp);
            }
            | function_call
            | ABRE_PARENTESES expression FECHA_PARENTESES
            | NOT element 
            {
                geraCodigo(NULL, "NEGA");
            }
            |
;

assignment:  
            identificator
            {
                temporary_var = temporary;
            }
            ATRIBUICAO expression
            {
                if (!temporary_var) {
                    yyerror("Variavel nao declarada.");
                    exit(1);
                }
            
                if (temporary_var->category == FUNCTION_TP) {
                    sprintf(str_tmp, "ARMZ %d, %d" , temporary_var->nvl_lex, temporary_var->item.func.offset);
                    geraCodigo(NULL, str_tmp);
                } else {
                    if (temporary_var->item.simple.parameter == REFERENCE_TP) {
                        sprintf(str_tmp, "ARMI %d, %d", temporary_var->nvl_lex, temporary_var->item.simple.offset);
                        geraCodigo(NULL, str_tmp);
                    } else {
                        sprintf(str_tmp, "ARMZ %d, %d" , temporary_var->nvl_lex, temporary_var->item.simple.offset);
                        geraCodigo(NULL, str_tmp);
                    }
                }
                temporary_var = NULL;
                type_rst = 0;
            }
;

routine_declaration:
            |
            {
                nl++;
                nvl_lex++;
                offset = 0;
            }
            routine_declaration_lp
            {
                nl--;
                nvl_lex--;
            }
;

routine_declaration_lp:
            procedure_declaration PONTO_E_VIRGULA routine_declaration_lp
            | function_declaration PONTO_E_VIRGULA routine_declaration_lp
            | 
;

procedure_declaration:
            PROCEDURE identificator
            {
                temporary = find(symbols_table, yytext);

                if (!temporary) {
                    proced = newProcedure(yytext, nvl_lex);
                    
                    geraRotulo(str_tmp);
                    strcpy(proced->item.func.label, str_tmp);

                    geraRotulo(str_tmp);
                    strcpy(proced->item.func.label_f, str_tmp);

                    sprintf(str_tmp, "ENPR %d", nvl_lex);
                    geraCodigo(proced->item.func.label, str_tmp);
                } else {
                    proced = temporary;
                    geraCodigo(proced->item.func.label_f, "NADA");
                }
            }
            parameters PONTO_E_VIRGULA
            {
                proced->item.func.num_param = parameters->size;
                offset = - 4;
                i_index = parameters->size - 1;
                proced->item.func.parameters = (variable*)malloc(sizeof(variable)*parameters->size);

                push(symbols_table, proced);
                
                i_index = 0;
                while (parameters->size) {
                    temporary = pop(parameters);

                    temporary->item.simple.offset = offset;
                    temporary->item.simple.offset = - 4;
                    push(symbols_table, newVariable(0, temporary->name, nvl_lex, offset, temporary->item.simple.parameter));
                    offset--;
                    proced->item.func.parameters[i_index] = temporary->item.simple;
                    
                    i_index++;
                }
            }
            forward
;

forward:
            FORWARD
            {
                sprintf(str_tmp, "DSVS %s", proced->item.func.label_f);

                geraCodigo(NULL, str_tmp);

                parameters->size = 0;
                offset = 0;
                proced = NULL;
            }
            | 
            {
                parameters->size = 0;
                offset = 0;
                proced = NULL;
            } 
            block
;

procedure_call:
            identificator
            {
                if (!temporary) {
                    yyerror("Procedimento nao declarado.");
                    exit(1);
                }
                proced = temporary;
                parameters->size = 0;
                count_param = 0;
            }
            ABRE_PARENTESES expressions
            {
                sprintf(str_tmp, "CHPR %s, %d", proced->item.func.label, nvl_lex);
                geraCodigo(NULL, str_tmp);
                proced = NULL;
            }
            FECHA_PARENTESES
            |
            identificator
            {
                if (!temporary) {
                    yyerror("Procedimento nao declarado.");
                    exit(1);
                }
                proced = temporary;
                parameters->size = 0;
                count_param = 0;

                sprintf(str_tmp, "CHPR %s, %d", proced->item.func.label, nvl_lex);
                geraCodigo(NULL, str_tmp);
                proced = NULL;
            }
;

function_declaration: 
            FUNCTION identificator
            {
                temporary = find(symbols_table, yytext);

                if (!temporary) {
                    funct = newFunction(0, yytext, nvl_lex);
                    geraRotulo(str_tmp);
                    strcpy(funct->item.func.label, str_tmp);

                    geraRotulo(str_tmp);
                    strcpy(funct->item.func.label_f, str_tmp);

                    sprintf(str_tmp,"ENPR %d", nvl_lex);
                    geraCodigo(funct->item.func.label, str_tmp);
                } else {
                    funct = temporary;
                    geraCodigo(funct->item.func.label_f, "NADA");
                }
            }
            parameters 
            {
                funct->item.func.num_param = parameters->size;
                offset = - 4;
                i_index = parameters->size - 1;
                funct->item.func.parameters = (variable*)malloc(sizeof(variable)*parameters->size);
                push(symbols_table, funct);
                
                while (parameters->size) {
                    temporary = pop(parameters);
                    temporary->item.simple.offset = offset;
                    push(symbols_table, newVariable(0, temporary->name, nvl_lex, offset, temporary->item.simple.parameter));
                    offset--;
                    funct->item.func.parameters[i_index] = temporary->item.simple;
                    i_index--;
                }
                parameters->size = 0;
                offset = 0;
            }
            DOIS_PONTOS type
            {
                int j;
                if (!strcmp(yytext, "boolean")) {
                    for (j = symbols_table->size - 1; j >= 0; j--) {
                        if (symbols_table->head[j].category == FUNCTION_TP) {
                            symbols_table->head[j].item.func.offset = - 4 - symbols_table->head[j].item.func.num_param;
                            symbols_table->head[j].item.func.type = 8;
                            break;
                        }
                    }
                } else {
                    for (j = symbols_table->size - 1; j >= 0; j--) {
                        if (symbols_table->head[j].category == FUNCTION_TP) {
                            symbols_table->head[j].item.func.offset = - 4 - symbols_table->head[j].item.func.num_param;
                            symbols_table->head[j].item.func.type = 7;
                            break;
                        }
                    }
                }
            } PONTO_E_VIRGULA 
            foward_func
;

foward_func:
            FORWARD
            {
                sprintf(str_tmp, "DSVS %s", funct->item.func.label_f);

                geraCodigo(NULL, str_tmp);

                parameters->size = 0;
                offset = 0;
            }
            | block
;

function_call:
            identificator
            {
                call_flag = 1;
                if (!temporary) {
                    yyerror("funcao nao declarada.");
                    exit(1);
                }
                geraCodigo(NULL, "AMEM 1");
                funct = temporary;
                parameters->size = 0;
                count_param = 0;
            }
            ABRE_PARENTESES expressions
            { 	
                sprintf(str_tmp, "CHPR %s, %d", funct->item.func.label, nvl_lex);
                geraCodigo(NULL, str_tmp);
                funct = NULL;
                call_flag = 0;
            }
            FECHA_PARENTESES
;

parameters:
            | ABRE_PARENTESES parameters_section parameters_lp FECHA_PARENTESES
;

parameters_lp:
            | PONTO_E_VIRGULA parameters_section parameters_lp
;

parameters_section: 
            ident_lists
            {
                for (i_index = 0; i_index < aux->size; i_index++) {
                    temporary = &(aux->head[i_index]);
                    temporary->item.simple.parameter = VALUE_TP;
                    push(parameters, temporary);
                }
                aux->size = 0;
            }
            DOIS_PONTOS type
            | VAR ident_lists
            {
                for (i_index = 0; i_index < aux->size; i_index++) {
                    temporary = &(aux->head[i_index]);
                    temporary->item.simple.parameter = REFERENCE_TP;
                    temporary->nvl_lex = nvl_lex;
                    push(parameters, temporary);
                }
                aux->size = 0;
            }
            DOIS_PONTOS type
;

goto: 
            GOTO NUMERO
            {
                temporary = find(symbols_table, yytext);
                if (temporary) {
                    sprintf(str_tmp, "DSVR %s, %d, %d", temporary->item.lab.label, temporary->nvl_lex, nvl_lex);
                    geraCodigo(NULL, str_tmp);
                } else {
                    yyerror("Label nao declarado.");
                    exit(1);
                }
            }
;

identificator:
            IDENT
            {
                temporary = find(symbols_table, yytext);
            }
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

    return 0;
}

