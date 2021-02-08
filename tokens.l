%{

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "code.tab.h"

%}

ints ([1-9])+([0-9])*


%%
[ \t]* { }
[\n]* {}
"while"  {  printf("%s\n",yytext); return WHILE;}
"void" {  printf("%s\n",yytext); return VOID; }
"for" {  printf("%s\n",yytext); return FOR; }
"elseif" {  printf("%s\n",yytext); return ELSEIF;  }

"if" {  printf("%s\n",yytext); return IF; }
"else" {  printf("%s\n",yytext); return ELSE; }
"int" {strcpy(yylval.sval,yytext); printf("int\n"); return INT;}
"break" {  printf("%s\n",yytext); return BREAK;  }
"continue" {  printf("%s\n",yytext); return CONTINUE; }
"return" {  printf("%s\n",yytext); return RETURN;  }
"main" {  printf("%s\n",yytext); return MAIN;  }
"char" {strcpy(yylval.sval,yytext);  printf("%s\n",yytext);  return CHAR; }
[A-Za-z"_"]+[0-9A-Za-z"_"]* { printf("%s\n",yytext);strcpy(yylval.sval,yytext);   return ID; }
"#".*"\n" {  printf("%s\n",yytext);}
"#*".*"*#" {   printf("%s\n",yytext);     }
{ints} {yylval.ival = atoi(yytext);  printf("integer token %d\n",atoi(yytext));  return INTVAL; }
"*" {  printf("%s\n",yytext); return '*'; }
"+" {  printf("%s\n",yytext); return '+';  }
"-" {  printf("%s\n",yytext); return '-';  }
"/" {  printf("%s\n",yytext); return '/'; }

["'"][a-zA-Z]["'"] {  printf("%c\n",yytext[1]); yylval.cval = yytext[1] ; return char_val;  }

"<" {  printf("%s\n",yytext); return ISLOWER; }
"<=" {  printf("%s\n",yytext); return ISLOWERANDEQ;}
">" {  printf("%s\n",yytext); return ISHIGHER;  }
">=" {  printf("%s\n",yytext); return ISHIGHERANDEQ;  }

"=" {  printf("%s\n",yytext); return EQ; }
"!=" {  printf("%s\n",yytext); return ISNOTEQ; }
"==" {  printf("%s\n",yytext); return ISEQ; }

"||" {  printf("%s\n",yytext); return COND_OR;}
"&&" {  printf("%s\n",yytext); return COND_AND; }
"|" {  printf("%s\n",yytext); return LOG_OR; }
"&" {  printf("%s\n",yytext); return LOG_AND;  }
"^" {  printf("%s\n",yytext); return LOG_XOR; }
"!" {  printf("%s\n",yytext); return NOT; }
"(" {  printf("%s\n",yytext); return '('; }
")" {  printf("%s\n",yytext); return ')'; }
"$" {  printf("%s\n",yytext); return '$'; }
"[" {  printf("%s\n",yytext); return '[';  }
"]" {  printf("%s\n",yytext); return ']'; }
"," {  printf("%s\n",yytext); return ','; }
"{" {  printf("%s\n",yytext); return '{';  }
"}" {  printf("%s\n",yytext); return '}'; }

%%


int yywrap(){}
