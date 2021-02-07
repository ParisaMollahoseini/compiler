%{
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
extern int yylex();
extern FILE* yyin;
FILE* datafile;

// Stack used to save the name of the register
// that th variable is stored in
char stack[30][8];
int stackSize;

// pushStack saves the register's name
void pushStack(char* reg)
{
	strcpy(stack[stackSize++], reg);
}

// popStack returns the register's name
char* popStack()
{
	char* a = (char*)malloc(sizeof(char)*8);
	strcpy(a , stack[stackSize-1]);
	stackSize--;
	return a;
}

struct function_names
{
	char name[10];
	int num ;//arg nums
	char return_func[5];
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

char current_func[20];
char currtype[4] ;

int yyparse();
void yyerror(const char *s);

struct var* addvar(struct var** first, struct var** last, char* name, char type[5]);
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




%left ','
%left COND_OR
%left COND_AND
%left LOG_OR
%left LOG_XOR
%left LOG_AND
%left ISEQ ISNOTEQ
%left ISLOWER ISLOWERANDEQ ISHIGHER ISHIGHERANDEQ
%left <cval> '+' '-'
%left <cval> '*' '/'
%left NOT
%left '(' ')' '[' ']'
%left '$'
%left ENTER
%left VALUE_ID
%left <cval> EQ
%left COMMENT MULTI_COMMENT

//%type <ival> EXP PARAMS ARGS_IN FUNC_CALL
%left <ival> INTVAL
%left <sval> ID
%left <cval> char_val
%type <ival> PARAMS
%type <sval> VTYPE FTYPE

%left <sval> CHAR
%left <sval> INT VOID
%left BREAK CONTINUE
%left IF WHILE ELSEIF ELSE FOR MAIN RETURN


%%
PROGRAM: FTYPE ID
'(' PARAMS {
	 printf("see function : %s\n",$2);

	 datafile = fopen("mips.txt", "a+");
	 fprintf(datafile, "%s:\n", $2);
	 fclose(datafile);
	 strcpy(current_func,$2);
	 strcpy(fun_names[func_count].return_func , $1);
	 fun_names[func_count].num = $4;
	 strcpy(fun_names[func_count++].name,current_func);
		}')' '{' STMTS '}' {

		vardelete(&first,&last,current_func);
		printf("delete variables after function\n");
	}
	PROGRAM | ENTER

FTYPE: VOID | INT;

PARAMS:{$$ = 0; printf("no parameters\n");}|
VTYPE ID {$$ = 1; printf("1 parameters\n");}|
VTYPE ID ',' VTYPE ID {$$ = 2; printf("2 parameters\n");}|
VTYPE ID ',' VTYPE ID ',' VTYPE ID {$$ = 3; printf("3 parameters\n");}|
VTYPE ID ',' VTYPE ID ',' VTYPE ID ',' VTYPE ID {$$ = 4; printf("4 parameters\n");};

VTYPE: CHAR | INT;

STMTS: DECLARE_STMT;

DECLARE_STMT: VTYPE ID {
	if(!findvar(first,$2,current_func)){
		printf("declare %s %s\n",$1,$2);

		strcpy(currtype,$1);
	struct var *newvar = addvar(&first, &last,$2, $1);
  strcpy(newvar -> current_func , current_func);

	char buffer[10];
	itoa(GetFreeRegister('t'),buffer,10);
	strcpy(newvar -> which_reg , strcat("$t",buffer));

	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
	fclose(datafile);
}
else
{
	char error[30] = "replicate variable ";
				strcat(error, $2);
				yyerror(error);
				YYERROR;
}
}
IDS '$' STMTS |
CHAR ID EQ char_val {
	if(!findvar(first,$2,current_func)){
		printf("declare and assign char %s = %s\n",$2,$4);

	struct var *newvar = addvar(&first, &last,$2, $1);
	strcpy(newvar -> current_func ,current_func);

	char buffer[10];
	itoa(GetFreeRegister('t'),buffer,10);
	strcpy(newvar -> which_reg , strcat("$t",buffer));

	newvar -> intchar_union.value_char = $4;
	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
	fclose(datafile);
}
else
{
	char error[30] = "replicate variable ";
				strcat(error, $2);
				yyerror(error);
				YYERROR;
}}'$' STMTS;

IDS: | ',' ID {
	if(!findvar(first,$2,current_func)){
		printf("declare more id %s %s\n",currtype,$2);
	struct var *newvar = addvar(&first, &last,$2, currtype);
	strcpy(newvar -> current_func ,current_func);

	char buffer[10];
	itoa(GetFreeRegister('t'),buffer,10);
	strcpy(newvar -> which_reg , strcat("$t",buffer));
	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
	fclose(datafile);
}
else
{
	char error[30] = "replicate variable ";
				strcat(error, $2);
				yyerror(error);
				YYERROR;

}}IDS;


%%


int main()
{
		FILE* file = fopen("test.txt","r");
		yyin = file;
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
			freereg(t->which_reg);
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
int GetFreeRegister(char reg){
	switch (reg){
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
	strcpy(_new->name ,name);

		strcpy(_new->type,type);

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
