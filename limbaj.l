%{
#include <stdio.h>
#include "y.tab.h"
#include <bits/stdc++.h>

using namespace std;

//extern int yylval;
%}
option noyywrap


tipInteger "int"
tipFloat "float"
tipChar "char"
tipString "string"
tipBoolean "bool"
tipArray "array"
tipObiect "obiect"
tipFunctie "functie"

nrInt ([1-9][0-9]*)|[0-9]
nrFloat {nrInt}"."[0-9]+
string \"[a-zA-Z0-9 _]+\"
char \'[a-zA-Z0-9 _]\'

id [a-zA-Z_][a-zA-Z0-9_]*

%%

{tipBoolean}     {yylval.strval = strdup(yytext); return TIP_BOOL;}
{tipInteger}     {yylval.strval = strdup(yytext); return TIP_INT;}
{tipFloat}   {yylval.strval = strdup(yytext); return TIP_FLOAT;}
{tipString}       {yylval.strval = strdup(yytext); return TIP_STRING;}
{tipChar}   {yylval.strval = strdup(yytext); return TIP_CHAR;}
{tipArray}     {yylval.strval = strdup(yytext); return TIP_ARRAY;}
{tipObiect}     {
                    char* s; 
                    s = new char[100]; 
                    stringstream ss; 
                    ss << yylineno; 
                    string aux;
                    ss >> aux; 
                    strcpy(s, aux.c_str()); 
                    yylval.strval = strdup(s); 
                    return TIP_OBIECT;
                }

{tipFunction}    {
                    char* s; 
                    s = new char[100]; 
                    stringstream ss; 
                    ss << yylineno; 
                    string aux;
                    ss >> aux; 
                    strcpy(s, aux.c_str()); 
                    yylval.strval = strdup(s);
                    return TIP_FUNCTION;
                }

{nrInt}         {yylval.strval = strdup(yytext); return NR_INT;}
{nrFloat}       {yylval.strval = strdup(yytext); return NR_FLOAT;}
{string}        {yylval.strval = strdup(yytext); return STRING;}
{char}          {yylval.strval = strdup(yytext); return CHAR;}
"const"         {yylval.strval = strdup(yytext); return CONST;}
"main"          {yylval.strval = strdup(yytext); return MAIN;}
"||"            {yylval.strval = strdup(yytext); return OR;}
"&&"            {yylval.strval = strdup(yytext); return AND;}
"!"             {yylval.strval = strdup(yytext); return NOT;}
"true"          {yylval.strval = strdup(yytext); return TRUE;}
"false"         {yylval.strval = strdup(yytext); return FALSE;}
"=="            {yylval.strval = strdup(yytext); return EQEQ;}
"!="            {yylval.strval = strdup(yytext); return NOTEQ;}
">="            {yylval.strval = strdup(yytext); return GTEQ;}
"<="            {yylval.strval = strdup(yytext); return LSEQ;}
"++"            {yylval.str = strdup(yytext); return INCR;}
"--"            {yylval.str = strdup(yytext); return DECR;}
"+="            {yylval.str = strdup(yytext); return PLSEQ;}
"-="            {yylval.str = strdup(yytext); return MINEQ;}
"*="            {yylval.str = strdup(yytext); return MULEQ;}
"/="            {yylval.str = strdup(yytext); return DIVEQ;}
"{"             {yylval.strval = strdup(yytext);return AOPEN;}
"}"             {yylval.strval = strdup(yytext);return ACLOSE;}
"("             {yylval.strval = strdup(yytext);return POPEN;}
")"             {yylval.strval = strdup(yytext);return PCLOSE;}
"["             {yylval.strval = strdup(yytext);return BOPEN;}
"]"             {yylval.strval = strdup(yytext);return BCLOSE;}
";"             {return SEMICOLON;}
","             {return COMMA;}
"+"             {return PLS;}
"-"             {return MIN;}
"*"             {return MUL;}
"/"             {return DIV;}
"."             {return DOT;}
"if"            {yylval.strval = strdup(yytext); return IF;}
"else"          {yylval.strval = strdup(yytext); return ELSE;}
"for"           {yylval.strval = strdup(yytext); return FOR;}
"while"         {yylval.strval = strdup(yytext); return WHILE;}
"begin"         {yylval.strval = strdup(yytext); return BEGIN;}
"end"           {yylval.strval = strdup(yytext); return END;}
"in"            {yylval.strval = strdup(yytext); return IN;}
"pas"           {yylval.strval = strdup(yytext); return PAS;}
"cout"          {yylval.strval = strdup(yytext); return COUT;}
"Eval"          {yylval.strval = strdup(yytext); return EVAL;}

"return"        {yylval.strval = strdup(yytext); return RETURN;}

{id} {
                    char* s; 
                    s = new char[100 + strlen(yytext)]; 
                    stringstream ss; 
                    ss << yylineno; 
                    string aux;
                    ss >> aux;
                    aux += " ";
                    strcpy(s, aux.c_str()); 
                    strcat(s, yytext);
                    yylval.strval = strdup(s);
                    return ID;
                }

[ \t] ;
\n {yylineno++;}
. {return yytext[0];}