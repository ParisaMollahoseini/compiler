%{

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "code.tab.h"

%}

ints ([1-9])+([0-9])*


%%
"while"  {return WHILE;  printf("%s\n",yytext); }
"void" {return VOID;  printf("%s\n",yytext);}
"for" {return FOR;  printf("%s\n",yytext);}
"if" {return IF;  printf("%s\n",yytext);}
"else" {return ELSE;  printf("%s\n",yytext);}
"int" {strcpy(yylval.sval,yytext); printf("int\n"); return INT;}
"break" {return BREAK;  printf("%s\n",yytext);}
"continue" {return CONTINUE;  printf("%s\n",yytext);}
"return" {return RETURN;  printf("%s\n",yytext);}
"main" {return MAIN;  printf("%s\n",yytext);}
"char" {strcpy(yylval.sval,yytext); return CHAR;  printf("%s\n",yytext);}
"elseif" {return ELSEIF;  printf("%s\n",yytext);}
[A-Za-z"_"]+[0-9A-Za-z"_"]* {strcpy(yylval.sval,yytext); return ID;   printf("%s\n",yytext);}
"#".*"\n" {return COMMENT;  printf("%s\n",yytext);}
"#*".*"*#" {   return MULTI_COMMENT;  printf("%s\n",yytext);}
{ints} {yylval.ival = atoi(yytext); return INTVAL;  printf("%s\n",yytext);}
"*" {return '*';  printf("%s\n",yytext);}
"+" {return '+';  printf("%s\n",yytext);}
"-" {return '-';  printf("%s\n",yytext);}
"/" {return '/';  printf("%s\n",yytext);}

["'"][a-zA-Z]["'"] {return char_val;  printf("%s\n",yytext);}

"<" {return ISLOWER;  printf("%s\n",yytext);}
"<=" {return ISLOWERANDEQ;  printf("%s\n",yytext);}
">" {return ISHIGHER;  printf("%s\n",yytext);}
">=" {return ISHIGHERANDEQ;  printf("%s\n",yytext);}

"=" {return EQ;  printf("%s\n",yytext);}
"!=" {return ISNOTEQ;  printf("%s\n",yytext);}
"==" {return ISEQ;  printf("%s\n",yytext);}
\n {return ENTER;  printf("%s\n",yytext);}
"||" {return COND_OR;  printf("%s\n",yytext);}
"&&" {return COND_AND;  printf("%s\n",yytext);}
"|" {return LOG_OR;  printf("%s\n",yytext);}
"&" {return LOG_AND;  printf("%s\n",yytext);}
"^" {return LOG_XOR;  printf("%s\n",yytext);}
"!" {return NOT;  printf("%s\n",yytext);}
"(" {return '(';  printf("%s\n",yytext);}
")" {return ')';  printf("%s\n",yytext);}
"$" {return '$';  printf("%s\n",yytext);}
"[" {return '[';  printf("%s\n",yytext);}
"]" {return ']';  printf("%s\n",yytext);}
"," {return ',';  printf("%s\n",yytext);}
"{" {return '{';  printf("%s\n",yytext);}
"}" {return '}';  printf("%s\n",yytext);}
[ ] {}
%%


int yywrap(){}
