%{

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "cal.tab.h"

%}

floats ([0-9])+[.]([0-9])+
ints ([1-9])+([0-9])*


%%
"while"  {return WHILE;}
"void" {return VOID;}
"int" {return INT;}
"for" {return FOR;}
"if" {return IF;}
"else" {return ELSE;}
"int" {return INT;}
"break" {return BREAK;}
"continue" {return CONTINUE;}
"return" {return RETURN;}
"main" {return MAIN;}
"char" {return CHAR;}
"elseif" {return ELSEIF;}
[A-Za-z"_"]+[0-9A-Za-z"_"]* {strcpy(yylval.sval,yytext); return ID; }
"#".*"\n" {return COMMENT;}
"#*".*"*#" {   return MULTI_COMMENT}
"#*" {return MULTI_COMMENT}
{floats} {yylval.fval = atof(yytext); return FLOAT;}
{ints} {yylval.ival = atoi(yytext); return INT;}
"*" {return '*';}
"+" {return '+';}
"-" {return '-';}
"/" {return '/';}
"=" {return EQ;}
\n {return ENTER;}
"(" {return '(';}
")" {return ')';}
[ ] {}
%%


int yywrap(){}
