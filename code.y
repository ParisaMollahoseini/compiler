%{
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector.h>
extern int yylex();
extern FILE* yyin;
FILE* datafile;

struct function_names
{
	char name[10];
	int num = 0 ;//arg nums
};
struct function_names fun_names[100];

union intchar
{
	int value_int;
	char value_char;
};

struct var
{
	union intchar intchar_union;
	char name[10];
	char current_func[20] ;
	char which_reg[3];
	char type[5];//char or int
	struct var* next;
};

struct var variables[100];
int count = 0 ,func_count = 0;

char current_func;
char currtype[4] ;

int yyparse();
void yyerror(const char *s);

struct var* addvar(struct var** first, struct var** last, char* name, char type);
void vardelete(struct var** first, struct var** last, char* func_name);
void freereg(char* reg_name);
int GetFreeRegister(char register);
struct var* findvar(struct var* first, char* name,char* curr_func);
struct var* first;
struct var* last;

char t_reg[10][4] = {"$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7","$t8","$t9"};
_Bool t_state[10] = {0,0,0,0,0,0,0,0,0,0};

char a_reg[4][4] = {"$a0","$a1","$a2","$a3"};
_Bool a_state[4] = {0,0,0,0};
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
%token VALUE_ID
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
	 strcpy(current_func,$2);
	 fun_names[func_count].num = $4;
	 strcpy(fun_names[func_count++].name,current_func);
		}
'(' PARAMS ')' '{' STMTS '}' {

		vardelete(first,last,current_func);
	}
	} PROGRAM | ENTER

FTYPE: VOID | INT;

PARAMS:{$$ = 0}|
VTYPE ID {$$ = 1}|
VTYPE ID ',' VTYPE ID {$$ = 2}|
VTYPE ID ',' VTYPE ID ',' VTYPE ID {$$ = 3}|
VTYPE ID ',' VTYPE ID ',' VTYPE ID ',' VTYPE ID {$$ = 4};

VTYPE: CHAR | INT;

STMTS: DECLARE_STMT |
ASSIGN_STMT |
WHILE_STMT |
IF_STMT |
FUNC_CALL |
RETURN_STMT |
ENTER;

DECLARE_STMT: VTYPE ID {

	if(!findvar(&first,$2,curr_func)){
		strcpy(currtype,$1);
	struct var *newvar = addvar(&first, &last,$2, $1);
	newvar -> current_func = current_func;
	newvar -> which_reg = strcat("t",itos(GetFreeRegister('t'));
}
else
{
	char error[30] = "replicate variable ";
				strcat(error, $2);
				yyerror(error);
				YYERROR;
}
}
IDS STMTS |
INT ID EQ EXP {
	if(!findvar(&first,$2,curr_func)){
	struct var *newvar = addvar(&first, &last,$2, $1);
	newvar -> current_func = current_func;
	newvar -> which_reg = strcat("t",itos(GetFreeRegister('t'));
	newvar -> intchar_union.value_int = $4;
}
else
{
	char error[30] = "replicate variable ";
				strcat(error, $2);
				yyerror(error);
				YYERROR;
}
}'$' STMTS |
CHAR ID EQ char_val {
	if(!findvar(&first,$2,curr_func)){
	struct var *newvar = addvar(&first, &last,$2, $1);
	newvar -> current_func = current_func;
	newvar -> which_reg = strcat("t",itos(GetFreeRegister('t'));
	newvar -> intchar_union.value_char = $4;
}
else
{
	char error[30] = "replicate variable ";
				strcat(error, $2);
				yyerror(error);
				YYERROR;
}}'$' STMTS;

IDS: '$' | ',' ID {
	if(!findvar(&first,$2,curr_func)){
	struct var *newvar = addvar(&first, &last,$2, currtype);
	newvar -> current_func = current_func;
	newvar -> which_reg = strcat("t",itos(GetFreeRegister('t'));
}
else
{
	char error[30] = "replicate variable ";
				strcat(error, $2);
				yyerror(error);
				YYERROR;

}IDS;

ASSIGN_STMT: ID EQ EXP '$' {
	struct var v1 ;
	strcpy(v1.current_func,current_func);
	v1.name = $2;
	v1.type = $1;
	v1.value_int = $3;
	variables[count++] = v1;//define var in simbol table

} STMTS;

VAR_VALUE: EXP | char_val;

WHILE_STMT: WHILE '(' EXP  ')' '{' STMTS '}' STMTS;

IF_STMT: IF '(' EXP ')' '{' STMTS  '}' ELSEIF_STMT ELSE_STMT STMTS;

ELSEIF_STMT: ELSEIF '(' EXP ')' '{' STMTS '}' ELSEIF | ENTER;

ELSE_STMT: ELSE '{' STMTS  '}' | ENTER;

FUNC_CALL: ID '(' ARGS_IN ')' '$' STMTS;

ARGS_IN: |
EXP ',' EXP ',' EXP ',' EXP {$$ =4;} |
EXP ',' EXP ',' EXP {$$ =3;} |
EXP ',' EXP {$$ =2;} |
EXP;

RETURN_STMT: RETURN EXP '$' STMTS;

EXP: EXP BLT EXP |
EXP BLE EXP |
EXP BGT EXP |
EXP BGE EXP |
EXP ISNOTEQ EXP	|
EXP ISEQ EXP |
EXP '+' EXP |
EXP '-' EXP |
EXP '*' EXP |
EXP '/' EXP |
EXP COND_AND EXP |
EXP COND_OR EXP |
EXP LOG_OR EXP |
EXP LOG_AND EXP |
EXP LOG_XOR EXP |
NOT EXP	|
'(' EXP ')' |
ints |
char_val |
'-' EXP |
identif |
FUNC_CALL;

ident:	ID;
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

void vardelete(struct var** first, struct var** last, char* func_name){
	struct var* prev;

	for(struct var* t = *first; t; t = t->next){

		if(strcmp(t->current_func, func_name) == 0){
			freereg(t->which_reg)
			if(t == *first && t == *last){
				*first = *last = NULL;
			}
			else if(t == *first){
				*first = (*first)->next;
			}
			else if(t == *last){
				*last = prev;
				(*last)->next = NULL;
			}
			else{
				prev->next = t->next;
			}

		}
		else
			prev = t;
	}
}
void freereg(char* reg_name){
	char RegType = reg_name[1];
	char RegNo = reg_name[2];
	switch(RegType){
		case 't':
			t_state[RegNo-'0'] = 0;
			break;
		case 'a':
			a_state[RegNo-'0'] = 0;
			break;

	}
}
int GetFreeRegister(char register){
	switch(register){
		case 't':
				for(int i=0; i<=9; i++){
					if(t_state[i] == 0){
						t_state[i] = 1;
						return i;
					}
				}
				break;
		case 'a':
				for(int i=0; i<=3; i++){
					if(a_state[i] == 0){
						a_state[i] = 1;
						return i;
					}
				}
				break;
	}
}
struct var* addvar(struct var** first, struct var** last, char* name, char type[5]){

	struct var* _new = (struct var*)malloc(sizeof(struct var));
	_new->name = (char*)malloc(sizeof(char)* (strlen(name)+1));
	strcpy(_new->name ,name);
	if(strcmp(type,"INT"))
		strcpy(_new->type,"int");
	else
		strcpy(_new->type,"char");

	if(*first){
		_new->next = *first;
		*first = _new;
	}
	else{
		*first = *last = _new;
		_new->next = NULL;
	}
	return _new;
}
struct var* findvar(struct var* first, char* name,char* curr_func){
	for(struct var* t = first; t; t = t->next){
		if(strcmp(t->name, name) == 0 && strcmp(t->current_func,curr_func)==0)
			return t;
	}
	return NULL;
}
