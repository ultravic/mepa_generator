/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "compilador.y" /* yacc.c:337  */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "utils.h"

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
int nl;

char s[32];


#line 105 "compilador.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "compilador.tab.h".  */
#ifndef YY_YY_COMPILADOR_TAB_H_INCLUDED
# define YY_YY_COMPILADOR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM = 258,
    ABRE_PARENTESES = 259,
    FECHA_PARENTESES = 260,
    VIRGULA = 261,
    PONTO_E_VIRGULA = 262,
    DOIS_PONTOS = 263,
    PONTO = 264,
    T_BEGIN = 265,
    T_END = 266,
    VAR = 267,
    IDENT = 268,
    ATRIBUICAO = 269,
    OR = 270,
    AND = 271,
    NOT = 272,
    MAIOR = 273,
    MENOR = 274,
    MAIOR_IGUAL = 275,
    MENOR_IGUAL = 276,
    IGUAL = 277,
    WRITE = 278,
    READ = 279,
    SLASH = 280,
    VEZES = 281,
    NUMERO = 282,
    MAIS = 283,
    MENOS = 284,
    PONTO_PONTO = 285,
    WHILE = 286,
    IF = 287,
    THEN = 288,
    ELSE = 289,
    DO = 290,
    DIV = 291,
    PROCEDURE = 292,
    FUNCTION = 293,
    LABEL = 294,
    DIFERENTE = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   190

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

#define YYUNDEFTOK  2
#define YYMAXUTOK   295

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    52,    66,    77,    64,   101,   102,   108,
     106,   120,   122,   121,   133,   137,   137,   142,   146,   147,
     153,   151,   177,   182,   181,   192,   194,   193,   204,   207,
     208,   213,   212,   224,   227,   228,   229,   230,   231,   232,
     233,   234,   239,   250,   238,   272,   273,   278,   289,   277,
     315,   314,   325,   330,   335,   330,   352,   353,   358,   357,
     367,   369,   368,   378,   379,   383,   387,   393,   399,   405,
     411,   417,   426,   427,   429,   428,   436,   438,   437,   443,
     442,   449,   448,   457,   460,   462,   461,   467,   466,   471,
     479,   514,   519,   520,   528,   527,   553,   555,   555,   568,
     569,   572,   573,   578,   588,   577,   618,   617,   635,   639,
     640,   644,   647,   648,   653,   652,   663,   662,   676,   680,
     687
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA", "DOIS_PONTOS", "PONTO",
  "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO", "OR", "AND", "NOT",
  "MAIOR", "MENOR", "MAIOR_IGUAL", "MENOR_IGUAL", "IGUAL", "WRITE", "READ",
  "SLASH", "VEZES", "NUMERO", "MAIS", "MENOS", "PONTO_PONTO", "WHILE",
  "IF", "THEN", "ELSE", "DO", "DIV", "PROCEDURE", "FUNCTION", "LABEL",
  "DIFERENTE", "$accept", "programa", "$@1", "bloco", "$@2", "$@3",
  "parte_declara_rotulos_opt", "parte_declara_rotulos", "$@4",
  "parte_declara_rotulos_loop", "$@5", "parte_declara_vars", "var", "$@6",
  "declara_vars", "declara_var", "$@7", "tipo", "lista_idents", "$@8",
  "lista_idents_lp", "$@9", "comando_composto", "comando_composto_loop",
  "comando", "$@10", "comando_sem_label", "comando_condicional", "$@11",
  "$@12", "comando_condicional_else", "comando_repetitivo", "$@13", "$@14",
  "comando_escrita", "$@15", "comando_leitura", "comando_leitura_1",
  "$@16", "$@17", "comando_leitura_1_loop", "lista_expressoes", "$@18",
  "lista_expressoes_loop", "$@19", "lista_expressoes_opt", "expressao",
  "expressao_simples", "$@20", "expressao_simples_loop", "$@21", "$@22",
  "$@23", "termo", "termo_loop", "$@24", "$@25", "fator", "atribuicao",
  "$@26", "parte_declara_subrotinas_opt", "$@27",
  "parte_declara_subrotinas", "parte_declara_subrotinas_loop",
  "declaracao_procedimento", "$@28", "$@29", "chamada_procedimento",
  "$@30", "declaracao_funcao", "parametros_formais_opt",
  "parametros_formais", "parametros_formais_loop",
  "secao_parametros_formais", "$@31", "$@32", "variavel", "identificador",
  "numero", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -166

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-166)))

#define YYTABLE_NINF -119

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -166,     9,    36,  -166,    27,    38,    33,  -166,    42,  -166,
      48,    51,    17,    33,  -166,    34,    53,    55,  -166,  -166,
    -166,  -166,  -166,  -166,    56,    51,    64,    62,    33,  -166,
      49,    68,  -166,    41,  -166,    33,    71,  -166,  -166,    70,
      33,  -166,    76,    77,  -166,    72,    64,    50,  -166,  -166,
      -2,    -2,  -166,  -166,  -166,  -166,    83,  -166,  -166,     4,
    -166,    81,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
      75,    96,  -166,  -166,  -166,    94,    98,  -166,    99,     4,
       4,    10,  -166,    10,    10,  -166,    74,    15,     2,  -166,
    -166,  -166,    50,    92,    90,   102,     0,   103,  -166,  -166,
       4,   104,    33,    95,  -166,   106,  -166,    15,  -166,    79,
       4,     4,     4,     4,     4,     4,    10,    10,    10,  -166,
      10,    10,    10,  -166,    81,  -166,     4,     4,  -166,    33,
    -166,   108,  -166,   111,  -166,  -166,  -166,  -166,    78,  -166,
    -166,    15,    95,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,   112,  -166,   113,
       0,   115,    17,  -166,   128,   129,    95,  -166,  -166,    15,
      15,    15,     2,     2,  -166,   130,    72,   108,  -166,  -166,
       4,  -166,  -166,  -166,  -166,   105,  -166,  -166,  -166,  -166,
    -166,    72,  -166,  -166,  -166,  -166,    95,  -166,  -166,   128,
    -166,  -166
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,   119,     0,    23,
       0,    25,     7,     0,    24,     0,     0,    17,     8,    26,
       9,     3,     4,    14,     0,    25,    11,    97,     0,    27,
       0,     0,     5,   108,    16,    19,     0,    12,    10,     0,
       0,    98,     0,     0,    18,     0,    11,    34,     6,   103,
     101,   101,    22,    20,    13,    50,     0,    31,    47,     0,
      36,    29,    33,    37,    38,    39,    40,    41,    35,    94,
     106,   109,   102,    99,   100,     0,     0,    53,     0,     0,
       0,     0,   120,     0,     0,    42,    65,    76,    84,    90,
     118,    91,    34,     0,     0,    63,     0,     0,   110,    21,
       0,     0,     0,    34,    48,     0,    93,    76,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
       0,     0,     0,    83,    29,    28,     0,     0,   107,     0,
     114,   112,   104,     0,    58,    52,    54,    32,     0,    92,
      73,    76,    34,    69,    68,    70,    71,    66,    67,    81,
      77,    79,    89,    85,    87,    30,    95,     0,   116,     0,
       0,     0,     7,    51,    60,    56,    34,    75,    43,    76,
      76,    76,    84,    84,    64,     0,     0,   112,   111,   105,
       0,    59,    53,    55,    49,    45,    82,    78,    80,    86,
      88,     0,   115,   113,    61,    57,    34,    44,   117,    60,
      46,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,   -25,  -166,  -166,  -166,  -166,  -166,    97,
    -166,  -166,  -166,  -166,   107,  -166,  -166,  -165,    -5,  -166,
     116,  -166,   101,    20,    54,  -166,   -97,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,   -37,  -166,  -166,
    -166,    21,  -166,   -52,  -166,  -166,   -55,    18,  -166,  -105,
    -166,  -166,  -166,   -64,  -157,  -166,  -166,   -71,  -166,  -166,
    -166,  -166,   117,   100,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,   -28,    -7,  -166,  -166,   -44,    -6,  -166
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    16,    27,    39,    17,    18,    26,    31,
      46,    22,    23,    24,    34,    35,    75,    53,    36,    11,
      14,    25,    60,    93,    61,    78,    62,    63,   109,   185,
     197,    64,    79,   138,    65,    76,    66,   101,   102,   165,
     183,   133,   164,   181,   199,   128,   134,    86,   141,   119,
     170,   171,   169,    87,   123,   172,   173,    88,    67,    94,
      32,    33,    72,    73,    42,    71,   162,    68,    95,    43,
      97,    98,   161,   131,   159,   175,    89,    90,    91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,     8,   140,    69,    85,  -108,   137,    19,    80,     3,
     106,   192,   129,     7,    80,   189,   190,     7,   120,   107,
     108,    81,     9,     7,   104,   105,   198,    81,   121,     9,
     116,    82,    83,    84,    49,    40,   167,    82,   122,     4,
       5,    70,     6,   117,   118,   168,     7,    10,    69,   152,
     153,   154,   149,   150,   151,    12,    15,    13,   136,    69,
      47,    20,    21,     7,   186,   187,   188,   -15,    28,   184,
      30,   156,   -96,    55,    56,    38,    37,    57,    40,    45,
      47,    58,    59,    50,    51,    52,    70,    77,    92,  -118,
       9,   130,   110,   111,   112,   113,   114,    70,    69,   200,
      96,    99,   100,   125,   126,    47,   127,   103,     7,   135,
     132,   139,   142,   166,   115,   160,   163,   174,    55,    56,
     178,   176,    69,     9,   158,   194,    58,    59,   143,   144,
     145,   146,   147,   148,   180,   182,    70,   179,   191,   196,
      48,    29,    44,    54,   155,   195,   124,   201,   157,   193,
      41,    74,    69,   177,     9,   130,     0,     0,     0,     0,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70
};

static const yytype_int16 yycheck[] =
{
       6,     6,   107,    47,    59,     7,   103,    13,     4,     0,
      81,   176,    12,    13,     4,   172,   173,    13,    16,    83,
      84,    17,    28,    13,    79,    80,   191,    17,    26,    35,
      15,    27,    28,    29,    40,    37,   141,    27,    36,     3,
      13,    47,     4,    28,    29,   142,    13,     5,    92,   120,
     121,   122,   116,   117,   118,     7,    39,     6,   102,   103,
      10,    27,     9,    13,   169,   170,   171,    12,    12,   166,
       6,   126,    10,    23,    24,     7,    27,    27,    37,     8,
      10,    31,    32,     7,     7,    13,    92,     4,     7,    14,
      96,    96,    18,    19,    20,    21,    22,   103,   142,   196,
       4,     7,     4,    11,    14,    10,     4,     8,    13,     5,
       7,     5,    33,    35,    40,     7,     5,     5,    23,    24,
       5,     8,   166,   129,   129,   180,    31,    32,   110,   111,
     112,   113,   114,   115,     6,     6,   142,   162,     8,    34,
      39,    25,    35,    46,   124,   182,    92,   199,   127,   177,
      33,    51,   196,   160,   160,   160,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,     0,     3,    13,     4,    13,    59,   118,
       5,    60,     7,     6,    61,    39,    44,    47,    48,   118,
      27,     9,    52,    53,    54,    62,    49,    45,    12,    61,
       6,    50,   101,   102,    55,    56,    59,    27,     7,    46,
      37,   103,   105,   110,    55,     8,    51,    10,    63,   118,
       7,     7,    13,    58,    50,    23,    24,    27,    31,    32,
      63,    65,    67,    68,    72,    75,    77,    99,   108,   117,
     118,   106,   103,   104,   104,    57,    76,     4,    66,    73,
       4,    17,    27,    28,    29,    87,    88,    94,    98,   117,
     118,   119,     7,    64,   100,   109,     4,   111,   112,     7,
       4,    78,    79,     8,    87,    87,    98,    94,    94,    69,
      18,    19,    20,    21,    22,    40,    15,    28,    29,    90,
      16,    26,    36,    95,    65,    11,    14,     4,    86,    12,
      59,   114,     7,    82,    87,     5,   117,    67,    74,     5,
      90,    89,    33,    88,    88,    88,    88,    88,    88,    94,
      94,    94,    98,    98,    98,    64,    87,    82,    59,   115,
       7,   113,   107,     5,    83,    80,    35,    90,    67,    93,
      91,    92,    96,    97,     5,   116,     8,   114,     5,    44,
       6,    84,     6,    81,    67,    70,    90,    90,    90,    95,
      95,     8,    58,   113,    87,    78,    34,    71,    58,    85,
      67,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    43,    42,    45,    46,    44,    47,    47,    49,
      48,    50,    51,    50,    52,    54,    53,    53,    55,    55,
      57,    56,    58,    60,    59,    61,    62,    61,    63,    64,
      64,    66,    65,    65,    67,    67,    67,    67,    67,    67,
      67,    67,    69,    70,    68,    71,    71,    73,    74,    72,
      76,    75,    77,    79,    80,    78,    81,    81,    83,    82,
      84,    85,    84,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    88,    88,    89,    88,    90,    91,    90,    92,
      90,    93,    90,    94,    95,    96,    95,    97,    95,    95,
      98,    98,    98,    98,   100,    99,   101,   102,   101,   103,
     103,   104,   104,   106,   107,   105,   109,   108,   110,   111,
     111,   112,   113,   113,   115,   114,   116,   114,   117,   118,
     119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     9,     0,     0,     6,     0,     1,     0,
       5,     0,     0,     4,     1,     0,     3,     0,     2,     1,
       0,     5,     1,     0,     3,     0,     0,     4,     4,     0,
       3,     0,     4,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     0,     0,     7,     0,     2,     0,     0,     6,
       0,     5,     4,     0,     0,     4,     0,     2,     0,     3,
       0,     0,     4,     0,     3,     1,     3,     3,     3,     3,
       3,     3,     2,     3,     0,     4,     0,     0,     4,     0,
       4,     0,     4,     2,     0,     0,     4,     0,     4,     2,
       1,     1,     3,     2,     0,     4,     0,     0,     2,     3,
       3,     0,     1,     0,     0,     7,     0,     3,     0,     0,
       1,     4,     0,     3,     0,     4,     0,     5,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 52 "compilador.y" /* yacc.c:1652  */
    { 
                geraCodigo(NULL, "INPP"); 
            }
#line 1444 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 58 "compilador.y" /* yacc.c:1652  */
    {
                geraCodigo(NULL, "PARA"); 
            }
#line 1452 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 66 "compilador.y" /* yacc.c:1652  */
    {
                geraRotulo(s);
                temporary_lab = newLabel(atoi(s), nvl_lex);

                strcpy(temporary_lab->item.lab.label, s);
                sprintf(s, "DSVS %s", temporary_lab->item.lab.label);

                geraCodigo(NULL, s);
                push(labels, temporary_lab);
            }
#line 1467 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 77 "compilador.y" /* yacc.c:1652  */
    {
                aux_lab = pop(labels);
                sprintf(s, "%s", aux_lab->item.lab.label);
                geraCodigo(s, "NADA");
            }
#line 1477 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 83 "compilador.y" /* yacc.c:1652  */
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
#line 1498 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 108 "compilador.y" /* yacc.c:1652  */
    {
                temporary = newLabel(atoi(yytext), nvl_lex);
                geraRotulo(temporary->item.lab.label);

                push(symbols_table, temporary);
                temporary = NULL;

            }
#line 1511 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 122 "compilador.y" /* yacc.c:1652  */
    {
                temporary = newLabel(atoi(yytext), nvl_lex);
                geraRotulo(temporary->item.lab.label);
                
                push(symbols_table, temporary);
                temporary = NULL;
            }
#line 1523 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 137 "compilador.y" /* yacc.c:1652  */
    { 
                aux->size = 0;
                offset = 0;
            }
#line 1532 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 153 "compilador.y" /* yacc.c:1652  */
    { /* AMEM */
                    int type;
                    if (!strcmp(yytext, "integer")) {
                        type = 7;
                    } else {
                        type = 1;
                    }
                    
                }
#line 1546 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 163 "compilador.y" /* yacc.c:1652  */
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
#line 1562 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 182 "compilador.y" /* yacc.c:1652  */
    {
        if (strcmp(yytext, "input") && strcmp(yytext, "output")) {
            var_label = newVariable(1, yytext, nvl_lex, offset, SIMPLES);
            push(aux, var_label);
            offset++;
        }
    }
#line 1574 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 194 "compilador.y" /* yacc.c:1652  */
    {
        if (strcmp(yytext, "input") && strcmp(yytext, "output")) {
            var_label = newVariable(1, yytext, nvl_lex, offset, SIMPLES);
            push(aux, var_label);
            offset++;
        }
    }
#line 1586 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 213 "compilador.y" /* yacc.c:1652  */
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
#line 1601 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 239 "compilador.y" /* yacc.c:1652  */
    {
                geraRotulo(s);
                temporary_lab = newLabel(s, nl);

                strcpy(temporary_lab->item.lab.label, s);
                push(labels, temporary_lab);

                sprintf(s, "DSVF %s", temporary_lab->item.lab.label);
                geraCodigo(NULL, s);
            }
#line 1616 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 250 "compilador.y" /* yacc.c:1652  */
    {
                geraRotulo(s);
                temporary_lab = newLabel(s, nl);

                strcpy(temporary_lab->item.lab.label, s);
                sprintf(s, "DSVS %s", temporary_lab->item.lab.label);

                geraCodigo(NULL, s);
                aux_lab = pop(labels);

                sprintf(s, "%s", aux_lab->item.lab.label);
                geraCodigo(s, "NADA");
                push(labels, temporary_lab);
            }
#line 1635 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 265 "compilador.y" /* yacc.c:1652  */
    {
                temporary = pop(labels);
                sprintf(s, "%s", temporary->item.lab.label);
                geraCodigo(s, "NADA");
            }
#line 1645 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 278 "compilador.y" /* yacc.c:1652  */
    {
                geraRotulo(s);
                temporary_lab = newLabel(s, nl);

                strcpy(temporary_lab->item.lab.label, s);
                sprintf(s, "NADA");

                geraCodigo(temporary_lab->item.lab.label, s);
                push(labels, temporary_lab);
            }
#line 1660 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 289 "compilador.y" /* yacc.c:1652  */
    {
                geraRotulo(s);
                temporary_lab = newLabel(s, nl);

                strcpy(temporary_lab->item.lab.label, s);
                sprintf(s, "DSVF %s", temporary_lab->item.lab.label);

                geraCodigo(NULL, s);
                push(labels, temporary_lab);
            }
#line 1675 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 300 "compilador.y" /* yacc.c:1652  */
    {
                temporary_lab = pop(labels);
                aux_lab = pop(labels);

                sprintf(s, "DSVS %s", aux_lab->item.lab.label);
                geraCodigo(NULL, s);

                sprintf(s, "%s", temporary_lab->item.lab.label);
                geraCodigo(s, "NADA");
            }
#line 1690 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 315 "compilador.y" /* yacc.c:1652  */
    {
                    write = 1;
                }
#line 1698 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 319 "compilador.y" /* yacc.c:1652  */
    {
                    write = 0;
                }
#line 1706 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 330 "compilador.y" /* yacc.c:1652  */
    {
                sprintf(s, "LEIT");
                geraCodigo(NULL, s);
            }
#line 1715 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 335 "compilador.y" /* yacc.c:1652  */
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
#line 1734 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 358 "compilador.y" /* yacc.c:1652  */
    {
                if (write) {
                    sprintf(s, "IMPR");
                    geraCodigo(NULL, s);
                }
            }
#line 1745 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 369 "compilador.y" /* yacc.c:1652  */
    {
                if (write) {
                    sprintf(s, "IMPR");
                    geraCodigo(NULL, s);
                }
            }
#line 1756 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 384 "compilador.y" /* yacc.c:1652  */
    { 
                if (proced || funct) count_param++; 
            }
#line 1764 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 388 "compilador.y" /* yacc.c:1652  */
    {
                if (proced || funct) count_param++; 
                sprintf(s, "CMIG");
                geraCodigo(NULL, s);
            }
#line 1774 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 394 "compilador.y" /* yacc.c:1652  */
    {
                if (proced || funct) count_param++; 
                sprintf(s, "CMDG");
                geraCodigo(NULL, s);
            }
#line 1784 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 400 "compilador.y" /* yacc.c:1652  */
    {
                if (proced || funct) count_param++; 
                sprintf(s, "CMME");
                geraCodigo(NULL, s);
            }
#line 1794 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 406 "compilador.y" /* yacc.c:1652  */
    {
                if (proced || funct) count_param++; 
                sprintf(s, "CMMA");
                geraCodigo(NULL, s);
            }
#line 1804 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 412 "compilador.y" /* yacc.c:1652  */
    {
                if (proced || funct) count_param++; 
                sprintf(s, "CMAG");
                geraCodigo(NULL, s);
            }
#line 1814 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 418 "compilador.y" /* yacc.c:1652  */
    {
                if (proced || funct) count_param++; 
                sprintf(s, "CMEG");
                geraCodigo(NULL, s);
            }
#line 1824 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 429 "compilador.y" /* yacc.c:1652  */
    {
                sprintf(s, "INVR");
                geraCodigo(NULL, s);
            }
#line 1833 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 438 "compilador.y" /* yacc.c:1652  */
    {
                sprintf(s, "SOMA");
                geraCodigo(NULL, s);
            }
#line 1842 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 443 "compilador.y" /* yacc.c:1652  */
    {
                sprintf(s, "SUBT");
                geraCodigo(NULL, s);
            }
#line 1851 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 449 "compilador.y" /* yacc.c:1652  */
    {
                sprintf(s, "DISJ");
                geraCodigo(NULL, s);
            }
#line 1860 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 462 "compilador.y" /* yacc.c:1652  */
    {
                sprintf(s, "MULT");
                geraCodigo(NULL, s);
            }
#line 1869 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 467 "compilador.y" /* yacc.c:1652  */
    {
                sprintf(s, "DIVI");
                geraCodigo(NULL, s);
            }
#line 1878 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 472 "compilador.y" /* yacc.c:1652  */
    {
                sprintf(s, "CONJ");
                geraCodigo(NULL, s);
            }
#line 1887 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 480 "compilador.y" /* yacc.c:1652  */
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
#line 1926 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 515 "compilador.y" /* yacc.c:1652  */
    {
                sprintf(s, "CRCT %s", yytext);
                geraCodigo(NULL, s);
            }
#line 1935 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 93:
#line 521 "compilador.y" /* yacc.c:1652  */
    {
                geraCodigo(NULL, "NEGA");
            }
#line 1943 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 94:
#line 528 "compilador.y" /* yacc.c:1652  */
    {
                temporary_var = temporary;
            }
#line 1951 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 532 "compilador.y" /* yacc.c:1652  */
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
#line 1975 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 97:
#line 555 "compilador.y" /* yacc.c:1652  */
    {
                nl++;
                nvl_lex++;
                offset = 0;
            }
#line 1985 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 98:
#line 561 "compilador.y" /* yacc.c:1652  */
    {
                nl--;
                nvl_lex--;
            }
#line 1994 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 103:
#line 578 "compilador.y" /* yacc.c:1652  */
    {
                proced = newProcedure(yytext, nvl_lex);
                
                geraRotulo(s);
                strcpy(proced->item.func.label, s);

                sprintf(s, "ENPR %d", nvl_lex);
                geraCodigo(proced->item.func.label, s);
            }
#line 2008 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 104:
#line 588 "compilador.y" /* yacc.c:1652  */
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
                parameters->size = 0;
                offset = 0;
                proced = NULL;
            }
#line 2038 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 106:
#line 618 "compilador.y" /* yacc.c:1652  */
    {
                if (!temporary) {
                    yyerror("Procedimento nao declarado.");
                    exit(1);
                }
                proced = temporary;
                parameters->size = 0;
                count_param = 0;
            }
#line 2052 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 107:
#line 628 "compilador.y" /* yacc.c:1652  */
    {
                sprintf(s, "CHPR %s, %d", proced->item.func.label, nvl_lex);
                geraCodigo(NULL, s);
                proced = NULL;
            }
#line 2062 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 114:
#line 653 "compilador.y" /* yacc.c:1652  */
    {
                for (i_index = 0; i_index < aux->size; i_index++) {
                    temporary = &(aux->head[i_index]);
                    temporary->item.simple.parameter = VALOR;
                    push(parameters, temporary);
                }
                aux->size = 0;
            }
#line 2075 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 116:
#line 663 "compilador.y" /* yacc.c:1652  */
    {
                for (i_index = 0; i_index < aux->size; i_index++) {
                    temporary = &(aux->head[i_index]);
                    temporary->item.simple.parameter = REFERENCIA;
                    temporary->nvl_lex = nvl_lex;
                    push(parameters, temporary);
                }
                aux->size = 0;
            }
#line 2089 "compilador.tab.c" /* yacc.c:1652  */
    break;

  case 119:
#line 681 "compilador.y" /* yacc.c:1652  */
    {
            temporary = find(symbols_table, yytext);
        }
#line 2097 "compilador.tab.c" /* yacc.c:1652  */
    break;


#line 2101 "compilador.tab.c" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 690 "compilador.y" /* yacc.c:1918  */


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

