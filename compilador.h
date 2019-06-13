/* -------------------------------------------------------------------
 *            Arquivo: compilaodr.h
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [15/03/2012, 08h:22m]
 *
 * -------------------------------------------------------------------
 *
 * Tipos, prot�tipos e vai�veis globais do compilador
 *
 * ------------------------------------------------------------------- */

#include "utils.h"
#define TAM_TOKEN 16

typedef enum simbolos { 
  simb_program, 
  simb_var, 
  simb_begin, 
  simb_end, 
  simb_identificador, 
  simb_numero,
  simb_ponto, 
  simb_virgula, 
  simb_ponto_e_virgula, 
  simb_dois_pontos,
  simb_atribuicao, 
  simb_abre_parenteses, 
  simb_fecha_parenteses, 
  simb_menor,
  simb_menor_igual,
  simb_maior,
  simb_maior_igual,
  simb_igual,
  simb_diferente,
  simb_mais,
  simb_menos,
  simb_vezes,
  simb_or,
  simb_and,
  simb_not,
  simb_div, 
  simb_while,
  simb_write,
  simb_read,
  simb_then,
  simb_function,
  simb_goto,
  simb_if,
  simb_label,
  simb_procedure,
  simb_do,
  simb_else,
  simb_boolean,
  simb_true,
  simb_false,
  simb_integer,
  simb_forward
} simbolos;



/* -------------------------------------------------------------------
 * vari�veis globais
 * ------------------------------------------------------------------- */

extern simbolos simbolo, relacao;
extern char token[TAM_TOKEN];
extern int nvl_lex;
extern int desloc;
extern int nl;
extern int contador_rotulo;
stack* symbols_table;

simbolos simbolo, relacao;
char token[TAM_TOKEN];



