%{
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector.h>
extern int yylex();
extern FILE* yyin;
FILE* datafile;



struct var
{
	char name[10];
	int num;
};

vector<var> variables;
int yyparse();
int findvar(char vname[10]);
void yyerror(const char *s);

char t_registers[10][4] = {"$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7","$t8","$t9"};
char s_registers[8][4] = {"$s0","$s1","$s2","$s3","$s4","$s5","$s6","$s7"};
char a_registers[4][4] = {"$a0","$a1","$a2","$a3"};


%}




%union{
	  int ival;
		char cval;
		char sval[10];
		//char plus,min,multi;
}



%token <ival> INTVAL
%token <sval> ID
%token ','
%token COND_OR
%token COND_AND
%token LOG_OR
%token LOG_XOR
%token LOG_AND
%token ISEQ ISNOTEQ
%token ISLOWER ISLOWERANDEQ ISHIGHER ISHIGHERANDEQ
%left <cval> '+' '-'
%left <cval> '*' '/'
%token '(' ')' '[' ']'
%token ENTER

%token <cval> EQ

//%token <ival> p
%token CHAR INT BREAK CONTINUE
%token IF WHILE ELSEIF ELSE VOID FOR MAIN RETURN


%%
PROGRAM: FTYPE ID
{
	 datafile = fopen("mips.txt", "a+");
	 fprintf(datafile, "%s:\n", $2);
	 fclose(datafile);
		}
'(' ARGS ')' '{' STMTS '}'  PROGRAM | ENTER

FTYPE: VOID | INT;

ARGS: VTYPE ID |
VTYPE ID ',' VTYPE ID |
VTYPE ID ',' VTYPE ID ',' VTYPE ID |
VTYPE ID ',' VTYPE ID ',' VTYPE ID ',' VTYPE ID;

VTYPE: CHAR | INT;

STMTS: DECLARE_STMT |
ASSIGN_STMT |
WHILE_STMT |
IF_STMT |
FUNC_CALL |
RETURN_STMT |
ENTER;
%%


int main()
{
		//FILE* file = fopen("w.txt","r");
		//yyin = file;
    yyparse();
    return 0;
}

void yyerror(const char *s)
{
	printf("-Error-");

}

int findvar(char vname[10])
{
	for(int i =0;i<count;i++)
	{
		if(strcmp(vname,var_arr[i].name)==0)
		{
			find_var = var_arr[i].num;
			return i;
		}
	}
return -1;


}
