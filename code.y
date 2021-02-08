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
	char type[10];//char or int
	struct var* next;
};

struct var variables[100];
int count = 0 ,func_count = 0;
int a_num=0;

char current_func[20],founded_func[20];
int founded_func_num = 0;
char currtype[4] ;

int yyparse();
void yyerror(const char *s);

struct var* findvar_WithFunc(struct var* first, char* funcName);
struct var* addvar(struct var** first, struct var** last, char* name, char *type);
void vardelete(struct var** first, struct var** last, char* func_name);
void freereg(char* reg_name);
int GetFreeRegister(char register);
struct var* findvar(struct var* first, char* name,char* curr_func);
struct var* first ;
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



%left <ival> INTVAL
%left <cval> char_val
%left <cval> ','
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

%left VALUE_ID
%left <cval> EQ
%left COMMENT MULTI_COMMENT



%left <sval> CHAR
%left <sval> INT
%left BREAK CONTINUE
%left IF WHILE ELSEIF ELSE VOID FOR MAIN RETURN

%nterm <sval> EXP
%token <ival> NUM
%token <sval> ID
%nterm <sval> VTYPE
%nterm <ival> PARAMS
%nterm <ival> ARGS_IN
%start PROGRAM

%%
PROGRAM: FTYPE ID {
	strcpy(current_func,$2);
	a_num = 0;
 }
 '('  PARAMS {
	 printf("see function : %s\n",current_func);

	 datafile = fopen("mips.txt", "a+");
	 fprintf(datafile, "%s:\n", current_func);
	 fclose(datafile);

	 printf("Param value : %d\n",$5);

	 fun_names[func_count].num = $5;
	 strcpy(fun_names[func_count++].name,current_func);
		}')'  '{'  STMTS  '}'  {

		vardelete(&first,&last,current_func);
		printf("delete variables after function\n");
	}
	PROGRAM |  ;

FTYPE: VOID | INT;

PARAMS: {$$ = 0; printf("no parameters\n");} |
VTYPE   ID {


	struct var *newvar = addvar(&first, &last,$2, $1);
	strcpy(newvar -> current_func ,current_func);

	if(strcmp(newvar->type,"int")==0)
	{
			newvar->intchar_union.value_int = 0;
	}
	else
	{
			newvar->intchar_union.value_char = 0;
	}

	char num[5];
	itoa(GetFreeRegister('a'),num,5);
	char buffer[10] = {'$', 'a'};
	strcpy(newvar -> which_reg , strcat(buffer,num));
	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
	fclose(datafile);
		$$ = 1;
		printf("1 parameters %d\n",$$);
}
| THREE_ID ',' VTYPE  ID {


	struct var *newvar = addvar(&first, &last,$4, $3);
	strcpy(newvar -> current_func ,current_func);

	if(strcmp(newvar->type,"int")==0)
	{
			newvar->intchar_union.value_int = 0;
	}
	else
	{
			newvar->intchar_union.value_char = 0;
	}

	char num[5];
	itoa(GetFreeRegister('a'),num,5);
	char buffer[10] = {'$', 'a'};
	strcpy(newvar -> which_reg , strcat(buffer,num));
	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
	fclose(datafile);
	$$ = 2;
	printf("2 parameters\n");
} |
THREE_ID THREE_ID_COMMA ','  VTYPE   ID {


	struct var *newvar = addvar(&first, &last,$5, $4);
	strcpy(newvar -> current_func ,current_func);

	if(strcmp(newvar->type,"int")==0)
	{
			newvar->intchar_union.value_int = 0;
	}
	else
	{
			newvar->intchar_union.value_char = 0;
	}

	char num[5];
	itoa(GetFreeRegister('a'),num,5);
	char buffer[10] = {'$', 'a'};
	strcpy(newvar -> which_reg , strcat(buffer,num));
	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
	fclose(datafile);
	$$ = 3;
	printf("3 parameters\n");
} |
THREE_ID THREE_ID_COMMA THREE_ID_COMMA ','   VTYPE   ID {


	struct var *newvar = addvar(&first, &last,$6, $5);
 	strcpy(newvar -> current_func ,current_func);

 	if(strcmp(newvar->type,"int")==0)
 	{
 			newvar->intchar_union.value_int = 0;
 	}
 	else
 	{
 			newvar->intchar_union.value_char = 0;
 	}

 	char num[5];
 	itoa(GetFreeRegister('a'),num,5);
 	char buffer[10] = {'$', 'a'};
 	strcpy(newvar -> which_reg , strcat(buffer,num));
 	datafile = fopen("mips.txt", "a+");
 	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
 	fclose(datafile);
	$$ = 4;
	printf("4 parameters\n");
 } ;

VTYPE: CHAR | INT;


THREE_ID :
VTYPE  ID {

 struct var *newvar = addvar(&first, &last,$2, $1);
 strcpy(newvar -> current_func ,current_func);

 if(strcmp(newvar->type,"int")==0)
 {
		 newvar->intchar_union.value_int = 0;
 }
 else
 {
		 newvar->intchar_union.value_char = 0;
 }

 char num[5];
 itoa(GetFreeRegister('a'),num,5);
 char buffer[10] = {'$', 'a'};
 strcpy(newvar -> which_reg , strcat(buffer,num));
 datafile = fopen("mips.txt", "a+");
 fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
 fclose(datafile);
};

THREE_ID_COMMA :
',' VTYPE  ID {

	struct var *newvar = addvar(&first, &last,$3, $2);
	strcpy(newvar -> current_func ,current_func);

	if(strcmp(newvar->type,"int")==0)
	{
			newvar->intchar_union.value_int = 0;
	}
	else
	{
			newvar->intchar_union.value_char = 0;
	}

	char num[5];
	itoa(GetFreeRegister('a'),num,5);
	char buffer[10] = {'$', 'a'};
	strcpy(newvar -> which_reg , strcat(buffer,num));
	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
	fclose(datafile);
};

STMTS: DECLARE_STMT |
ASSIGN_STMT |
WHILE_STMT |
IF_STMT |
FUNC_CALL |
RETURN_STMT |
;

DECLARE_STMT: INT ID {
	if(first != NULL){
	if(!findvar(first,$2,current_func)){
		printf("declare %s %s\n",$1,$2);


		strcpy(currtype,$1);
	struct var *newvar = addvar(&first, &last,$2, $1);

  strcpy(newvar -> current_func , current_func);

	char num[5];
	itoa(GetFreeRegister('t'),num,5);
	char buffer[10] = {'$', 't'};
	strcpy(newvar -> which_reg , strcat(buffer,num));

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
else{
	printf("declare %s %s\n",$1,$2);


	first = (struct var*)malloc(sizeof(struct var));
	last = (struct var*)malloc(sizeof(struct var));

	strcpy(first->name ,$2);
	strcpy(first->type,"int");

	strcpy(first -> current_func ,current_func);

		first->next = NULL;

		char num[5];
		itoa(GetFreeRegister('t'), num,10);
		char buffer[10] = {'$','t'};
		strcat(buffer, num);


strcpy(first -> which_reg , buffer);
last = first;
datafile = fopen("mips.txt", "a+");
fprintf(datafile, "\taddi %s, $zero , %d \n", first->which_reg,0);
fclose(datafile);
}
}
IDS '$' STMTS |
INT ID EQ EXP {
	if(first != NULL){

	if(!findvar(first,$2,current_func)){

		printf("declare and assign int %s = %d\n",$2,atoi($4));
	struct var *newvar = addvar(&first, &last,$2, $1);

	strcpy(newvar -> current_func ,current_func);

	char num[5];
	itoa(GetFreeRegister('t'),num,5);
	char buffer[10] = {'$', 't'};
	strcpy(newvar -> which_reg , strcat(buffer,num));

	newvar -> intchar_union.value_int = atoi($4);
	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,atoi($4));
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
else{
	printf("declare and assign int %s = %d\n",$2,atoi($4));


	first = (struct var*)malloc(sizeof(struct var));
	last = (struct var*)malloc(sizeof(struct var));

	strcpy(first->name ,$2);
	strcpy(first->type,"int");
	first->intchar_union.value_int = atoi($4);
	strcpy(first -> current_func ,current_func);

		first->next = NULL;

		char num[5];
		itoa(GetFreeRegister('t'), num,10);
		char buffer[10] = {'$','t'};
		strcat(buffer, num);


strcpy(first -> which_reg , buffer);
last = first;
datafile = fopen("mips.txt", "a+");
fprintf(datafile, "\taddi %s, $zero , %d \n", first->which_reg,first -> intchar_union.value_int);
fclose(datafile);
}
}'$' STMTS |
CHAR ID {
	if(first != NULL){
	if(!findvar(first,$2,current_func)){
		printf("declare %s %s\n","char",$2);

		strcpy(currtype,$1);
	struct var *newvar = addvar(&first, &last,$2, $1);
  strcpy(newvar -> current_func , current_func);

	char num[5];
	itoa(GetFreeRegister('t'),num,5);
	char buffer[10] = {'$' , 't'};
	strcpy(newvar -> which_reg , strcat(buffer,num));

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
else{
	printf("declare char %s\n","char",$2);


	first = (struct var*)malloc(sizeof(struct var));
	last = (struct var*)malloc(sizeof(struct var));

	strcpy(first->name ,$2);
	strcpy(first->type,"char");
	strcpy(first -> current_func ,current_func);

		first->next = NULL;

		char num[5];
		itoa(GetFreeRegister('t'), num,10);
		char buffer[10] = {'$','t'};
		strcat(buffer, num);


strcpy(first -> which_reg , buffer);
last = first;
datafile = fopen("mips.txt", "a+");
fprintf(datafile, "\taddi %s, $zero , %d \n", first->which_reg,0);
fclose(datafile);
}
}
IDS '$' STMTS |
CHAR ID EQ EXP {
	if(first != NULL){
		if(!findvar(first,$2,current_func)){
			printf("declare and assign char %s = %s\n",$2,$4);

		struct var *newvar = addvar(&first, &last,$2, $1);
		strcpy(newvar -> current_func ,current_func);
		strcpy(newvar -> type ,"char");///////////////////

		char num[5];
		itoa(GetFreeRegister('t'),num,5);
		char buffer[10] = {'$', 't'};
		strcpy(newvar -> which_reg , strcat(buffer,num));

		char buff3[2] ;
		strcpy(buff3,$4);
		newvar -> intchar_union.value_char = buff3[0];

		datafile = fopen("mips.txt", "a+");
		fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_char);
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
	else{
		printf("fisrt declare and assign char %s = %s\n",$2,$4);


		first = (struct var*)malloc(sizeof(struct var));
		last = (struct var*)malloc(sizeof(struct var));
		strcpy(first->name ,$2);
		char buff3[2] ;
		strcpy(buff3,$4);
		first->intchar_union.value_char = buff3[0];
		strcpy(first->type,"char");
		strcpy(first -> current_func ,current_func);

			first->next = NULL;

			char num[5];
			itoa(GetFreeRegister('t'), num,10);
			char buffer[10] = {'$','t'};
			strcat(buffer, num);


	strcpy(first -> which_reg , buffer);
	last = first;
	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\taddi %s, $zero , %d \n", first->which_reg,first -> intchar_union.value_char);
	fclose(datafile);
	}
	}'$' STMTS;

IDS: | ',' ID {
		if(first != NULL){
	if(!findvar(first,$2,current_func)){
		printf("declare more id %s %s\n",currtype,$2);
	struct var *newvar = addvar(&first, &last,$2, currtype);
	strcpy(newvar -> current_func ,current_func);

	char num[5];
	itoa(GetFreeRegister('t'),num,5);
	char buffer[10] = {'$', 't'};
	strcpy(newvar -> which_reg , strcat(buffer,num));
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

}}
else{
	printf("declare more id %s %s\n",currtype,$2);


	first = (struct var*)malloc(sizeof(struct var));
	last = (struct var*)malloc(sizeof(struct var));

	strcpy(first->name ,$2);
	strcpy(first->type,currtype);

	strcpy(first -> current_func ,current_func);

		first->next = NULL;

		char num[5];
		itoa(GetFreeRegister('t'), num,5);
		char buffer[10] = {'$','t'};
		strcat(buffer, num);


strcpy(first -> which_reg , buffer);
last = first;
datafile = fopen("mips.txt", "a+");
fprintf(datafile, "\taddi %s, $zero , %d \n", first->which_reg,0);
fclose(datafile);
}}IDS;

ASSIGN_STMT: ID EQ EXP '$' {
		if(first != NULL){
	if(findvar(first,$1,current_func)){

	struct var *newvar = findvar(first,$1,current_func);
		datafile = fopen("mips.txt", "a+");
		printf("type is %s...\n",newvar->type);
	if(strcmp(newvar -> type ,"char")==0)
	{
		printf("assign  %s = %s\n",$1,$3);
		char buff3[2] ;
		strcpy(buff3,$3);
		newvar -> intchar_union.value_char = buff3[0];
		fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_char);

	}
	else
	{
		printf("assign  %s = %d\n",$1,atoi($3));
		newvar -> intchar_union.value_int = atoi($3);
		fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_int);

	}

	fclose(datafile);
}
else
{
	char error[30] = "no such variable exists ...";
				strcat(error, $1);
				yyerror(error);
				YYERROR;

}
}
else
{
	char error[30] = "no such variable exists ...";
				strcat(error, $1);
				yyerror(error);
				YYERROR;
	}} STMTS;

//VAR_VALUE: EXP | char_val;

WHILE_STMT: WHILE {printf("while begin\n");} '(' EXP  ')' '{' STMTS '}' {printf("while end\n");} STMTS;

IF_STMT: IF {printf("if begin\n");} '(' EXP ')' '{' STMTS  '}' ELSEIF_STMT ELSE_STMT {printf("if end\n");} STMTS;

ELSEIF_STMT: ELSEIF {printf("elseif begin\n");} '(' EXP ')' '{' STMTS '}' {printf("elseif end\n");} ELSEIF | ;

ELSE_STMT: ELSE {printf("else begin\n");} '{' STMTS  '}' {printf("else end\n");} | ;

FUNC_CALL: ID {
	int flag = -1 ;
	for(int i=0;i<func_count;i++)
	{
		if(strcmp($1,fun_names[i].name)==0)
		{
			flag = i;
		}
	}
	if(flag == -1 )
	{
		char error[30] = "no such function exists ...";
					strcat(error, $1);
					yyerror(error);
					YYERROR;
	}
	else
	{
		strcpy(founded_func,$1);
		founded_func_num = fun_names[flag].num;
	}
}
'(' ARGS_IN ')' '$' STMTS;

ARGS_IN: {$$=0; printf("no args passed\n");} |
EXP ',' EXP ',' EXP ',' EXP {$$=4; printf("4 args passed\n");};

RETURN_STMT: RETURN EXP '$' STMTS;

EXP: EXP ISEQ EXP {printf("equality\n"); sprintf($$,"%d",$1 == $3);} |
EXP ISNOTEQ EXP {printf("notequality\n"); sprintf($$,"%d",$1 != $3);} |
EXP '+' EXP {
	char num[5];
	itoa(GetFreeRegister('t'), num,5);
	char buffer[10] = {'$','t'};
	strcat(buffer, num);

	printf("addition\n");
	char buff[20];
	sprintf(buff,"addi %s,%s,%s",buffer,$1,$3);

	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\t%s\n",buff);
	fclose(datafile);

	char buff2[10];
	sprintf(buff2,"%d",atoi($1) + atoi($3));
	strcpy($$,buff2);
}
| EXP '-' EXP {
		char num[5];
		itoa(GetFreeRegister('t'), num,5);
		char buffer[10] = {'$','t'};
		strcat(buffer, num);

		printf("subtraction\n");
		char buff[20];
		sprintf(buff,"sub %s,%s,%s",buffer,$1,$3);

		datafile = fopen("mips.txt", "a+");
		fprintf(datafile, "\t%s\n",buff);
		fclose(datafile);

		char buff2[10];
		sprintf(buff2,"%d",atoi($1) + atoi($3));
		strcpy($$,buff2);

	} |
INTVAL {
	printf("int literal\n");
	char buff[10];
	sprintf(buff,"%d",$1);
	 strcpy($$ , buff);
	}  |
EXP COND_AND EXP {printf("conditional and\n");  sprintf($$,"%d",$1 && $3);} |
EXP COND_OR EXP {printf("nonditional or\n"); sprintf($$,"%d",$1 || $3);} |
EXP LOG_OR EXP {printf("logical or\n"); sprintf($$,"%d",atoi($1) | atoi($3));} |
EXP LOG_AND EXP {printf("logical and\n"); sprintf($$,"%d",atoi($1) & atoi($3));} |
EXP LOG_XOR EXP {printf("logical xor\n"); sprintf($$,"%d",atoi($1) ^ atoi($3));} |
NOT EXP {printf("logical not\n"); sprintf($$,"%d", !$2);} |
'(' EXP ')' {printf("parantheses\n");  sprintf($$,"%d",$2);} |
char_val {
	printf("character literal\n");
	char buff[2];
	buff[0] = $1;
	buff[1] = '\0';
	strcpy($$,buff);
	} |
ID {
	printf("id literal\n");
	if(first != NULL){
if(findvar(first,$1,current_func)){

struct var *newvar = findvar(first,$1,current_func);

	strcpy($$ , newvar ->which_reg);

}
else
{
char error[30] = "no such variable exists ...";
			strcat(error, $1);
			yyerror(error);
			YYERROR;

}
}
else
{
char error[30] = "no such variable exists ...";
			strcat(error, $1);
			yyerror(error);
			YYERROR;
}
}
| '-' EXP {printf("negative num\n"); sprintf($$,"%d", -atoi($2));} ;


%%


int main()
{
	  FILE* file1 = fopen("mips.txt","w");
		fclose(file1);
		FILE* file = fopen("input.txt","r");
		yyin = file;
    yyparse();
    return 0;
}

void yyerror(const char *s)
{
	printf("-Error- %s",s);

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
struct var* addvar(struct var** first, struct var** last, char* name, char *type){

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

	if(first == NULL)
		return NULL;

	for(struct var* t = first; t; t = t->next){
		if(strcmp(t->name, name) == 0 && strcmp(t->current_func,curr_func)==0)
			return t;
	}

	return NULL;
}
struct var* findvar_WithFunc(struct var* first, char* funcName){

	if(first == NULL)
		return NULL;

	for(struct var* t = first; t; t = t->next){
		if(strcmp(t->current_func,funcName)==0)
			return t;
	}

	return NULL;
}
