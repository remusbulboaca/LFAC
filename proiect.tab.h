/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 303 "proiect.y"
{
    int num;
    char* str;
}
/* Line 1529 of yacc.c.  */
#line 142 "proiect.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

