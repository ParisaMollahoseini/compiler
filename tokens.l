%{

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "code.tab.h"

%}

ints ([1-9])+([0-9])*


%%
"while"  {return WHILE;}
"void" {return VOID;}
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
{ints} {yylval.ival = atoi(yytext); return INTVAL;}
"*" {return '*';}
"+" {return '+';}
"-" {return '-';}
"/" {return '/';}

["'"][a-zA-Z]["'"] {return char_val;}

"<" {return ISLOWER;}
"<=" {return ISLOWERANDEQ;}
">" {return ISHIGHER;}
">=" {return ISHIGHERANDEQ;}

"=" {return EQ;}
"!=" {return ISNOTEQ}
"==" {return ISEQ;}
\n {return ENTER;}
"||" {return COND_OR;}
"&&" {return COND_AND;}
"|" {return LOG_OR;}
"&" {return LOG_AND;}
"^" {return LOG_XOR;}
"!" {return NOT;}
"(" {return '(';}
")" {return ')';}
"$" {return '$';}
"[" {return '[';}
"]" {return ']';}
"," {return ',';}
"{" {return '{';}
"}" {return '}';}
[ ] {}
%%


int yywrap(){}
