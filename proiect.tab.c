/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MAIN = 258,
     CONST = 259,
     TYPE = 260,
     IF = 261,
     STRINGTYPE = 262,
     ELSE = 263,
     WHILE = 264,
     FOR = 265,
     PRINT = 266,
     CLASS = 267,
     PLSEQ = 268,
     MINEQ = 269,
     MULEQ = 270,
     DIVEQ = 271,
     INCR = 272,
     DECR = 273,
     AND = 274,
     OR = 275,
     EQEQ = 276,
     NOTEQ = 277,
     GTEQ = 278,
     LSEQ = 279,
     GT = 280,
     LS = 281,
     NOT = 282,
     EQ = 283,
     AOPEN = 284,
     ACLOSE = 285,
     POPEN = 286,
     PCLOSE = 287,
     BOPEN = 288,
     BCLOSE = 289,
     SEMICOLON = 290,
     COMMA = 291,
     PLS = 292,
     MIN = 293,
     MUL = 294,
     DIV = 295,
     DOT = 296,
     STRING = 297,
     ID = 298,
     NUMBER = 299
   };
#endif
/* Tokens.  */
#define MAIN 258
#define CONST 259
#define TYPE 260
#define IF 261
#define STRINGTYPE 262
#define ELSE 263
#define WHILE 264
#define FOR 265
#define PRINT 266
#define CLASS 267
#define PLSEQ 268
#define MINEQ 269
#define MULEQ 270
#define DIVEQ 271
#define INCR 272
#define DECR 273
#define AND 274
#define OR 275
#define EQEQ 276
#define NOTEQ 277
#define GTEQ 278
#define LSEQ 279
#define GT 280
#define LS 281
#define NOT 282
#define EQ 283
#define AOPEN 284
#define ACLOSE 285
#define POPEN 286
#define PCLOSE 287
#define BOPEN 288
#define BCLOSE 289
#define SEMICOLON 290
#define COMMA 291
#define PLS 292
#define MIN 293
#define MUL 294
#define DIV 295
#define DOT 296
#define STRING 297
#define ID 298
#define NUMBER 299




/* Copy the first part of user declarations.  */
#line 1 "proiect.y"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern FILE* yyin;
extern char* yytext;
int yylineno;

int yylex();
void yyerror(const char *s);
struct variable
{
    int value;
    char* name;
    char* type;
    _Bool value_present;
    _Bool is_const;
};
struct variable variables[256];
int k = 0; int kvechi = 0;

struct function
{
    char* type;
    char* name;
    char* args;
};
struct function functions[256];
int q = 0; int qvechi = 0;

int expr[256], n;

void Adaugare(int a)
{
    expr[n++] = a;
}

void Print()
{
    for (int i = 0; i < n; ++i)
    {
        printf ("Valoarea exprresiei cu numarul %d este %d\n", i + 1, expr[i]);
    }
}

int already_declared(char* name)
{
    for (int i = 0; i < k; ++i)
    {
        if (strcmp(variables[i].name, name) == 0) return i;
    }
    return -1;
}

void declare_without_init(char* type, char* name, _Bool is_const)
{
    if (already_declared(name) != -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s is already declared", name);
        
        exit(0);
    }
    if (is_const == 1)
    {
        char buffer[256];
        sprintf(buffer, "Cannot declare const variable %s without initialization", name);
        
        exit(0);
    }
    variables[k].type = strdup(type);
    variables[k].name = strdup(name);
    variables[k].value_present = 0;
    variables[k].is_const = 0;
    ++k;
}

void declare_with_init_value(char* type, char* name, int value, _Bool is_const)
{
    if (already_declared(name) != -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s is already declared", name);
        
        exit(0);
    }
    variables[k].type = strdup(type);
    variables[k].name = strdup(name);
    variables[k].value = value;
    variables[k].value_present = 1;
    variables[k].is_const= is_const;
    ++k;
}

void declare_with_init_variable(char* type, char* name, char* variable, _Bool is_const)
{
    if (already_declared(name) != -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s is already declared", name);
        
        exit(0);
    }
    int position = already_declared(variable);
    if (position == -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s cannot be initialised with the undeclared variable %s", name, variable);
        
        exit(0);
    }
    if (strcmp(type, variables[position].type) != 0)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s is not of the same type with variable %s", name, variables[position].name);
        
        exit(0);
    }
    if (variables[position].value_present == 0)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s cannot be initialised with the uninitialised variable %s", name, variables[position].name);
        
        exit(0);
    }
    variables[k].type = strdup(type);
    variables[k].name = strdup(name);
    variables[k].value = variables[position].value;
    variables[k].value_present = 1;
    variables[k].is_const = is_const;
    ++k;
}

int return_variable_value(char* name)
{
    int position = already_declared(name);
    if (position == -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s was not declared", name);
        
        exit(0);
    }
    if (variables[position].value_present == 0)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s does not have any value", name);
        
        exit(0);
    }
    return variables[position].value;
}

void assign_value(char* name, int value)
{
    int position = already_declared(name);
    if (position == -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s was not declared", name);
        
        exit(0);
    }
    if (variables[position].is_const == 1)
    {
        char buffer[256];
        sprintf(buffer, "Cannot assign value to const variable %s", name);
        
        exit(0);
    }
    variables[position].value = value;
    variables[position].value_present = 1;
}

void increment_decrement(char* name, char* operator)
{
    int position = already_declared(name);
    if (position == -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s was not declared", name);
        
        exit(0);
    }
    if (variables[position].value_present == 0)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s does not have any value", name);
        
        exit(0);
    }
    if (variables[position].is_const == 1)
    {
        char buffer[256];
        sprintf(buffer, "Cannot assign value to const variable %s", name);
        
        exit(0);
    }
    if (strcmp(operator, "++") == 0) variables[position].value++;
    if (strcmp(operator, "--") == 0) variables[position].value--;
}

void assign_number_with_operator(char* name, int value, char* operator)
{
    int position = already_declared(name);
    if (position == -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s was not declared", name);
        
        exit(0);
    }
    if (variables[position].value_present == 0)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s does not have any value", name);
        
        exit(0);
    }
    if (variables[position].is_const == 1)
    {
        char buffer[256];
        sprintf(buffer, "Cannot assign value to const variable %s", name);
        
        exit(0);
    }
    if (strcmp(operator, "+=") == 0) variables[position].value += value;
    if (strcmp(operator, "-=") == 0) variables[position].value -= value;
    if (strcmp(operator, "*=") == 0) variables[position].value *= value;
    if (strcmp(operator, "/=") == 0) variables[position].value /= value;
}

int function_already_declared(char* name, char* args)
{
    for (int i = 0; i < q; ++i)
    {
        if ((strcmp(functions[i].name, name) == 0) && (strcmp(functions[i].args, args) == 0)) return i;
    }
    return -1;
}

void declare_function (char* type, char* name, char* args)
{
    if (strlen(args) >= 2) args[strlen(args) - 2] = 0;
    if (function_already_declared(name, args) != -1)
    {
        char buffer[256];
        sprintf(buffer, "Cannot redeclare function %s with the same signature", name);
        exit(0);
    }
    functions[q].type = type;
    functions[q].name = name;
    functions[q].args = args;
    ++q;
}

char* get_return_type (char* name, char* args)
{
    if (strlen(args) >= 2) args[strlen(args) - 2] = 0;
    int position = function_already_declared(name, args);
    if (position == -1)
    {
        char buffer[256];
        sprintf(buffer, "Function %s you are trying to call has not been declared", name);
        
        exit(0);
    }
    char* type = malloc(256);
    strcpy(type, functions[position].type);
    return type;
}

void Enumerate(char* scope)
{
    FILE* f = fopen("symbol_table.txt", "a");
    fprintf(f, "In %s au fost declarate variabilele: ", scope);
    for (int i = kvechi; i < k; ++i) fprintf (f, "%s ", variables[i].name);
    kvechi = k;
    fprintf(f, "\n");
    fprintf(f, "In %s au fost declarate functiile: ", scope);
    for (int i = qvechi; i < q; ++i) fprintf (f, "%s ", functions[i].name);
    qvechi = q;
    fprintf (f, "\n\n");
    fclose(f);
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 303 "proiect.y"
{
    int num;
    char* str;
}
/* Line 193 of yacc.c.  */
#line 479 "proiect.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 492 "proiect.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   313

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  200

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    12,    15,    17,    21,    23,
      26,    33,    39,    41,    44,    49,    53,    60,    66,    73,
      79,    84,    88,    92,    98,   102,   107,   112,   115,   119,
     122,   126,   128,   132,   135,   142,   152,   163,   171,   182,
     194,   205,   217,   224,   232,   235,   237,   239,   243,   247,
     251,   255,   259,   263,   266,   270,   274,   278,   280,   282,
     284,   287,   291,   295,   298,   301,   304,   307,   311,   315,
     319,   323,   325,   330,   334,   335,   339,   343,   347,   351,
     355,   357,   362,   366,   368,   373,   375,   377
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    49,    51,    54,    -1,    51,
      54,    -1,    49,    54,    -1,    54,    -1,     5,     3,    55,
      -1,    50,    -1,    49,    50,    -1,    12,    43,    29,    51,
      30,    35,    -1,    12,    43,    29,    30,    35,    -1,    52,
      -1,    51,    52,    -1,     4,     5,    43,    35,    -1,     5,
      43,    35,    -1,     4,     5,    43,    28,    44,    35,    -1,
       5,    43,    28,    44,    35,    -1,     4,     5,    43,    28,
      43,    35,    -1,     5,    43,    28,    43,    35,    -1,     5,
      43,    53,    35,    -1,     5,    43,    55,    -1,     7,    43,
      35,    -1,     7,    43,    28,    42,    35,    -1,    33,    44,
      34,    -1,    53,    33,    44,    34,    -1,    48,    29,    57,
      30,    -1,    31,    32,    -1,    31,    56,    32,    -1,     5,
      43,    -1,    56,    36,    56,    -1,    58,    -1,    29,    58,
      30,    -1,    57,    58,    -1,     6,    31,    59,    32,    62,
      35,    -1,     6,    31,    59,    32,    62,    35,     8,    62,
      35,    -1,     6,    31,    59,    32,    62,    35,     8,    29,
      61,    30,    -1,     6,    31,    59,    32,    29,    61,    30,
      -1,     6,    31,    59,    32,    29,    61,    30,     8,    62,
      35,    -1,     6,    31,    59,    32,    29,    61,    30,     8,
      29,    61,    30,    -1,    10,    31,    62,    35,    59,    35,
      62,    32,    62,    35,    -1,    10,    31,    62,    35,    59,
      35,    62,    32,    29,    61,    30,    -1,     9,    31,    59,
      32,    62,    35,    -1,     9,    31,    59,    32,    29,    61,
      30,    -1,    62,    35,    -1,    52,    -1,    60,    -1,    60,
      26,    60,    -1,    60,    25,    60,    -1,    60,    24,    60,
      -1,    60,    23,    60,    -1,    60,    21,    60,    -1,    60,
      22,    60,    -1,    27,    60,    -1,    59,    19,    59,    -1,
      59,    20,    59,    -1,    31,    59,    32,    -1,    43,    -1,
      44,    -1,    64,    -1,    62,    35,    -1,    61,    62,    35,
      -1,    43,    28,    63,    -1,    43,    17,    -1,    43,    18,
      -1,    17,    43,    -1,    18,    43,    -1,    43,    13,    63,
      -1,    43,    14,    63,    -1,    43,    15,    63,    -1,    43,
      16,    63,    -1,    64,    -1,    11,    31,    63,    32,    -1,
      62,    36,    62,    -1,    -1,    63,    37,    63,    -1,    63,
      38,    63,    -1,    63,    39,    63,    -1,    63,    40,    63,
      -1,    31,    63,    32,    -1,    44,    -1,    43,    33,    44,
      34,    -1,    43,    41,    43,    -1,    43,    -1,    43,    31,
      65,    32,    -1,    63,    -1,    64,    -1,    65,    36,    65,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   313,   313,   317,   318,   319,   320,   323,   326,   327,
     330,   331,   333,   334,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   349,   350,   352,   355,   356,   359,
     360,   363,   364,   365,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   395,   396,   397,
     400,   401,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   430,   433,   434,   435
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "CONST", "TYPE", "IF",
  "STRINGTYPE", "ELSE", "WHILE", "FOR", "PRINT", "CLASS", "PLSEQ", "MINEQ",
  "MULEQ", "DIVEQ", "INCR", "DECR", "AND", "OR", "EQEQ", "NOTEQ", "GTEQ",
  "LSEQ", "GT", "LS", "NOT", "EQ", "AOPEN", "ACLOSE", "POPEN", "PCLOSE",
  "BOPEN", "BCLOSE", "SEMICOLON", "COMMA", "PLS", "MIN", "MUL", "DIV",
  "DOT", "STRING", "ID", "NUMBER", "$accept", "correct", "program",
  "inceput_main", "classes", "class", "declarations", "declaration",
  "dimensions", "main", "args", "parameters", "blocks", "block",
  "condition", "operand", "statements", "statement", "exprr",
  "function_call", "call_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    47,    47,    48,    49,    49,
      50,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    53,    54,    55,    55,    56,
      56,    57,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    64,    65,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     2,     1,     3,     1,     2,
       6,     5,     1,     2,     4,     3,     6,     5,     6,     5,
       4,     3,     3,     5,     3,     4,     4,     2,     3,     2,
       3,     1,     3,     2,     6,     9,    10,     7,    10,    11,
      10,    11,     6,     7,     2,     1,     1,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     1,     1,     1,
       2,     3,     3,     2,     2,     2,     2,     3,     3,     3,
       3,     1,     4,     3,     0,     3,     3,     3,     3,     3,
       1,     4,     3,     1,     4,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     0,     0,     8,
       0,    12,     6,     0,     0,     0,     0,     0,     1,    74,
       9,     0,     5,    13,     4,     0,     0,     7,     0,     0,
      15,     0,    21,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,    45,    74,    31,     0,    71,
       3,     0,    14,     0,    27,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,    74,     0,    65,    66,
       0,     0,     0,     0,     0,    63,    64,     0,     0,    26,
      33,    44,    74,     0,     0,    29,    28,     0,    19,    17,
      24,     0,    23,    11,     0,     0,     0,    57,    58,     0,
      46,    59,     0,     0,     0,    83,    80,     0,    32,    67,
      68,    69,    70,    62,    83,    85,    86,     0,    73,    18,
      16,    30,    25,    10,    53,     0,     0,     0,    74,     0,
       0,     0,     0,     0,     0,    74,     0,     0,     0,     0,
      72,     0,     0,     0,     0,    84,     0,    56,    54,    55,
      74,     0,    51,    52,    50,    49,    48,    47,    74,     0,
       0,    79,     0,    82,    75,    76,    77,    78,    87,    74,
       0,    34,    74,    42,    74,    81,    37,     0,    60,    74,
      43,     0,    74,    61,    74,     0,    74,    74,     0,    74,
      35,    74,     0,    74,    38,    36,    74,    40,    39,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    10,    11,    31,    12,
      27,    55,    46,    47,    99,   100,   169,   170,   115,    49,
     117
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -79
static const yytype_int16 yypact[] =
{
     244,    23,     7,   -34,    -2,    62,   -79,    54,   244,   -79,
     254,   -79,   -79,    50,    65,   229,    31,    75,   -79,    81,
     -79,   254,   -79,   -79,   -79,   157,    26,   -79,   191,    94,
     -79,   176,   -79,   107,   -79,    90,   113,   145,   172,   174,
     188,   179,   184,   123,   200,   -79,    96,   -79,   126,   -79,
     -79,   196,   -79,   193,   -79,   -13,   153,   228,   207,   221,
     -79,   250,   263,   118,    -1,    -1,   183,   121,   -79,   -79,
     220,   121,   121,   121,   121,   -79,   -79,   121,   189,   -79,
     -79,   -79,   183,   264,   265,   -79,   -79,   275,   -79,   -79,
     -79,   267,   -79,   -79,   268,   233,    -1,   271,   -79,   127,
     245,   -79,   205,   243,   121,    40,   -79,   206,   -79,   235,
     235,   235,   235,   235,   104,   235,   -79,    85,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   210,    -1,    -1,     3,   233,
     233,   233,   233,   233,   233,   125,    -1,   215,   260,   262,
     -79,   121,   121,   121,   121,   -79,   189,   -79,   -79,   287,
     183,   246,   -79,   -79,   -79,   -79,   -79,   -79,   183,   248,
      25,   -79,   273,   -79,   247,   247,   -79,   -79,   -79,    18,
     253,   300,   101,   -79,   183,   -79,   301,   255,   -79,   140,
     -79,   170,   161,   -79,   183,   257,   164,   183,   259,   169,
     -79,   183,   261,   178,   -79,   -79,   180,   -79,   -79,   -79
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   -79,   -79,   -79,   302,     4,    -6,   -79,   163,
     296,   225,   -79,   -21,   -47,   -78,   -76,   -19,   -66,   -62,
     167
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      48,   107,   101,   101,    23,   109,   110,   111,   112,    16,
      14,   113,    21,    45,    40,    23,   116,   124,   102,    86,
      41,    42,    70,    87,    48,    80,    95,    48,    13,    40,
      96,    53,   150,   101,   101,    41,    42,    45,   137,    63,
      45,    17,    97,    98,   126,   127,    44,   103,   176,   125,
      15,   152,   153,   154,   155,   156,   157,    23,    54,    33,
     174,    44,    18,   118,   101,   101,    34,   101,   101,   101,
     101,   101,   101,   138,   101,   164,   165,   166,   167,   148,
     149,   139,   172,    19,   116,     1,    36,    37,     3,   160,
      38,    39,    40,    25,     1,    36,    26,     3,    41,    42,
       1,    36,    37,     3,    35,    38,    39,    40,   189,   151,
      43,   193,    40,    41,    42,   196,   159,   145,    41,    42,
      62,   146,     1,    36,    44,     3,    79,     1,    36,    37,
       3,   180,    38,    39,    40,    78,    40,   138,    58,    44,
      41,    42,    41,    42,    44,   139,   126,   127,    94,    61,
     177,    40,   104,   177,   158,   181,    15,    41,    42,   128,
     185,    81,    82,   188,   105,   106,    44,   192,    44,   184,
     177,    22,    40,    24,   177,    40,    64,   177,    41,    42,
      40,    41,    42,    44,    50,    51,    41,    42,    88,    40,
     187,    40,    52,   191,    40,    41,    42,    41,    42,   195,
      41,    42,   186,    65,    44,    66,    82,    44,   198,    59,
     199,    60,    44,    71,    72,    73,    74,    75,    76,    67,
     104,    44,    68,    44,   126,   127,    44,    69,    77,   126,
     127,    78,   114,   106,    56,    57,    85,   135,   140,    83,
      84,    90,   147,   141,   142,   143,   144,   161,     1,     2,
     108,     3,   141,   142,   143,   144,     4,    28,     1,     2,
      26,     3,    29,    89,    30,    91,   129,   130,   131,   132,
     133,   134,   141,   142,   143,   144,    97,    98,   136,    82,
      53,   171,    82,   173,    82,    92,   143,   144,   178,    82,
     183,    82,   190,    82,   194,    82,   197,    82,    93,   119,
     120,   122,    78,   123,   162,   163,   126,   175,   179,   182,
      20,    32,   121,   168
};

static const yytype_uint8 yycheck[] =
{
      19,    67,    64,    65,    10,    71,    72,    73,    74,    43,
       3,    77,     8,    19,    11,    21,    78,    95,    65,    32,
      17,    18,    43,    36,    43,    46,    27,    46,     5,    11,
      31,     5,    29,    95,    96,    17,    18,    43,   104,    35,
      46,    43,    43,    44,    19,    20,    43,    66,    30,    96,
      43,   129,   130,   131,   132,   133,   134,    63,    32,    28,
      35,    43,     0,    82,   126,   127,    35,   129,   130,   131,
     132,   133,   134,    33,   136,   141,   142,   143,   144,   126,
     127,    41,   158,    29,   146,     4,     5,     6,     7,   136,
       9,    10,    11,    43,     4,     5,    31,     7,    17,    18,
       4,     5,     6,     7,    29,     9,    10,    11,   184,   128,
      29,   187,    11,    17,    18,   191,   135,    32,    17,    18,
      30,    36,     4,     5,    43,     7,    30,     4,     5,     6,
       7,    30,     9,    10,    11,    31,    11,    33,    44,    43,
      17,    18,    17,    18,    43,    41,    19,    20,    30,    42,
     169,    11,    31,   172,    29,   174,    43,    17,    18,    32,
     179,    35,    36,   182,    43,    44,    43,   186,    43,    29,
     189,     8,    11,    10,   193,    11,    31,   196,    17,    18,
      11,    17,    18,    43,    21,    28,    17,    18,    35,    11,
      29,    11,    35,    29,    11,    17,    18,    17,    18,    30,
      17,    18,    32,    31,    43,    31,    36,    43,    30,    33,
      30,    35,    43,    13,    14,    15,    16,    17,    18,    31,
      31,    43,    43,    43,    19,    20,    43,    43,    28,    19,
      20,    31,    43,    44,    43,    44,    43,    32,    32,    43,
      44,    34,    32,    37,    38,    39,    40,    32,     4,     5,
      30,     7,    37,    38,    39,    40,    12,    28,     4,     5,
      31,     7,    33,    35,    35,    44,    21,    22,    23,    24,
      25,    26,    37,    38,    39,    40,    43,    44,    35,    36,
       5,    35,    36,    35,    36,    35,    39,    40,    35,    36,
      35,    36,    35,    36,    35,    36,    35,    36,    35,    35,
      35,    34,    31,    35,    44,    43,    19,    34,     8,     8,
       8,    15,    87,   146
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     7,    12,    46,    47,    48,    49,    50,
      51,    52,    54,     5,     3,    43,    43,    43,     0,    29,
      50,    51,    54,    52,    54,    43,    31,    55,    28,    33,
      35,    53,    55,    28,    35,    29,     5,     6,     9,    10,
      11,    17,    18,    29,    43,    52,    57,    58,    62,    64,
      54,    28,    35,     5,    32,    56,    43,    44,    44,    33,
      35,    42,    30,    51,    31,    31,    31,    31,    43,    43,
      58,    13,    14,    15,    16,    17,    18,    28,    31,    30,
      58,    35,    36,    43,    44,    43,    32,    36,    35,    35,
      34,    44,    35,    35,    30,    27,    31,    43,    44,    59,
      60,    64,    59,    62,    31,    43,    44,    63,    30,    63,
      63,    63,    63,    63,    43,    63,    64,    65,    62,    35,
      35,    56,    34,    35,    60,    59,    19,    20,    32,    21,
      22,    23,    24,    25,    26,    32,    35,    63,    33,    41,
      32,    37,    38,    39,    40,    32,    36,    32,    59,    59,
      29,    62,    60,    60,    60,    60,    60,    60,    29,    62,
      59,    32,    44,    43,    63,    63,    63,    63,    65,    61,
      62,    35,    61,    35,    35,    34,    30,    62,    35,     8,
      30,    62,     8,    35,    29,    62,    32,    29,    62,    61,
      35,    29,    62,    61,    35,    30,    61,    35,    30,    30
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
	    /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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
#line 313 "proiect.y"
    {printf("Program corect sintactic si semantic.\n"); Print();;}
    break;

  case 7:
#line 323 "proiect.y"
    {Enumerate("global");;}
    break;

  case 10:
#line 330 "proiect.y"
    {Enumerate((yyvsp[(2) - (6)].str));;}
    break;

  case 11:
#line 331 "proiect.y"
    {Enumerate((yyvsp[(2) - (5)].str));;}
    break;

  case 14:
#line 337 "proiect.y"
    {declare_without_init((yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str), 1);;}
    break;

  case 15:
#line 338 "proiect.y"
    {declare_without_init((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), 0);;}
    break;

  case 16:
#line 339 "proiect.y"
    {declare_with_init_value((yyvsp[(2) - (6)].str), (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].num), 1);;}
    break;

  case 17:
#line 340 "proiect.y"
    {declare_with_init_value((yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].num), 0);;}
    break;

  case 18:
#line 341 "proiect.y"
    {declare_with_init_variable((yyvsp[(2) - (6)].str), (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].str), 1);;}
    break;

  case 19:
#line 342 "proiect.y"
    {declare_with_init_variable((yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].str), 0);;}
    break;

  case 21:
#line 344 "proiect.y"
    {declare_function((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));;}
    break;

  case 26:
#line 352 "proiect.y"
    {Enumerate("main");;}
    break;

  case 27:
#line 355 "proiect.y"
    {(yyval.str) = malloc(256); (yyval.str)[0] = 0;;}
    break;

  case 28:
#line 356 "proiect.y"
    {(yyval.str) = (yyvsp[(2) - (3)].str);;}
    break;

  case 29:
#line 359 "proiect.y"
    {(yyval.str) = (yyvsp[(1) - (2)].str); strcat((yyval.str), ", ");;}
    break;

  case 30:
#line 360 "proiect.y"
    {(yyval.str) = (yyvsp[(1) - (3)].str); strcat((yyval.str), (yyvsp[(3) - (3)].str));;}
    break;

  case 62:
#line 404 "proiect.y"
    {assign_value((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].num));;}
    break;

  case 63:
#line 405 "proiect.y"
    {increment_decrement((yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str));;}
    break;

  case 64:
#line 406 "proiect.y"
    {increment_decrement((yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str));;}
    break;

  case 65:
#line 407 "proiect.y"
    {increment_decrement((yyvsp[(2) - (2)].str), (yyvsp[(1) - (2)].str));;}
    break;

  case 66:
#line 408 "proiect.y"
    {increment_decrement((yyvsp[(2) - (2)].str), (yyvsp[(1) - (2)].str));;}
    break;

  case 67:
#line 409 "proiect.y"
    {assign_number_with_operator((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].num), (yyvsp[(2) - (3)].str));;}
    break;

  case 68:
#line 410 "proiect.y"
    {assign_number_with_operator((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].num), (yyvsp[(2) - (3)].str));;}
    break;

  case 69:
#line 411 "proiect.y"
    {assign_number_with_operator((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].num), (yyvsp[(2) - (3)].str));;}
    break;

  case 70:
#line 412 "proiect.y"
    {assign_number_with_operator((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].num), (yyvsp[(2) - (3)].str));;}
    break;

  case 72:
#line 414 "proiect.y"
    {Adaugare((yyvsp[(3) - (4)].num));;}
    break;

  case 75:
#line 419 "proiect.y"
    {(yyval.num) = (yyvsp[(1) - (3)].num) + (yyvsp[(3) - (3)].num);;}
    break;

  case 76:
#line 420 "proiect.y"
    {(yyval.num) = (yyvsp[(1) - (3)].num) - (yyvsp[(3) - (3)].num);;}
    break;

  case 77:
#line 421 "proiect.y"
    {(yyval.num) = (yyvsp[(1) - (3)].num) * (yyvsp[(3) - (3)].num);;}
    break;

  case 78:
#line 422 "proiect.y"
    {(yyval.num) = (yyvsp[(1) - (3)].num) / (yyvsp[(3) - (3)].num);;}
    break;

  case 79:
#line 423 "proiect.y"
    {(yyval.num) = (yyvsp[(2) - (3)].num);;}
    break;

  case 80:
#line 424 "proiect.y"
    {(yyval.num) = (yyvsp[(1) - (1)].num);;}
    break;

  case 81:
#line 425 "proiect.y"
    {(yyval.num) = 0;;}
    break;

  case 82:
#line 426 "proiect.y"
    {(yyval.num) = 0;;}
    break;

  case 83:
#line 427 "proiect.y"
    {(yyval.num) = return_variable_value((yyvsp[(1) - (1)].str));;}
    break;

  case 84:
#line 430 "proiect.y"
    {(yyval.str) = get_return_type ((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].str));;}
    break;

  case 85:
#line 433 "proiect.y"
    {(yyval.str) = malloc (256); strcpy((yyval.str), "int, ");;}
    break;

  case 86:
#line 434 "proiect.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str); strcat((yyval.str), ", ");;}
    break;

  case 87:
#line 435 "proiect.y"
    {(yyval.str) = (yyvsp[(1) - (3)].str); strcat((yyval.str), (yyvsp[(3) - (3)].str));;}
    break;


/* Line 1267 of yacc.c.  */
#line 2075 "proiect.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 438 "proiect.y"




int main(int argc, char** argv)
{
    if (argc > 1) yyin = fopen(argv[1], "r");
    FILE* f = fopen("symbol_table.txt", "w");
    fclose(f);
    yyparse();
    f = fopen("symbol_table.txt", "a");
    fprintf(f, "Functiile declarate sunt:\n");
    for (int i = 0; i < q; ++i)
    {
        fprintf(f, "[%s] %s (%s)\n", functions[i].type, functions[i].name, functions[i].args);
    }
    fclose(f);
} 
