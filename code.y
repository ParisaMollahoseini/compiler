%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
extern int yylex();
extern FILE* yyin;
FILE* datafile;

// Stack used to save the name of the register
// that th variable is stored in
char stack[30][10];
int stackSize=0;

char return_result[20];

// pushStack saves the register's name
void pushStack(char* reg)
{
	strcpy(stack[stackSize++], reg);
}

// popStack returns the register's name
char* popStack()
{
	char* a = (char*)malloc(sizeof(char)*10);
	strcpy(a , stack[stackSize-1]);
	stackSize--;
	return a;
}

struct function_names
{
	char name[10];
	char type[10];//void or int
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
	char current_func[20] ;//current scope
	char which_reg[3];
	char type[10];//char or int
	struct var* next;
};



struct var variables[100];
int count = 0 ,func_count = 0;


char current_func[20],founded_func[20];
int founded_func_num = 0;
char currtype[4] ;
int count_label = 0 ,int count_label_end =  0 ;

//struct func function_types[10000];
//int functions_count = 0;

int yyparse();
void yyerror(const char *s);


struct var* findvar_inscope(char var_name[10],char this_scope[10]);
struct var* findvar_WithFunc(struct var* first, char* funcName);
struct var* addvar(struct var** first, struct var** last, char* name, char *type);
void vardelete(struct var** first, struct var** last, char* func_name);
void freereg(char* reg_name);
int GetFreeRegister(char register);
struct var* findvar(struct var* first, char* name,char* curr_func);
_Bool isnumber(char* reg);
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
%nterm <sval> FTYPE
%nterm <sval> VTYPE
%nterm <ival> PARAMS
%nterm <sval> FUNC_CALL

%nterm <ival> ARGS_IN
%start PROGRAM

%%
PROGRAM: FTYPE ID {
	strcpy(current_func,$2);
	pushStack($2);

 }
 '('  PARAMS {
	 printf("see function : %s\n",current_func);

	 datafile = fopen("mips.txt", "a+");
	 fprintf(datafile, "%s:\n", current_func);
	 fprintf(datafile, "\taddi $sp, $sp , -32\n");
	 for(int w=0;w<8;w++)
	 {
		 fprintf(datafile, "\tsw $t%d, %d($sp)\n", w,w*4);
	 }

	 fclose(datafile);

	 printf("Param value : %d\n",$5);

	 fun_names[func_count].num = $5;
	 strcpy(fun_names[func_count].name,current_func);
	 strcpy(fun_names[func_count++].type, $1);
		}
		')'  '{'  STMTS  '}' {

		vardelete(&first,&last,popStack());


		datafile = fopen("mips.txt", "a+");
		for(int w=0;w<8;w++)
		{
			fprintf(datafile, "\tlw $t%d, %d($sp)\n", w,w*4);
		}
		fprintf(datafile, "\taddi $sp, $sp , 32\n");

		fprintf(datafile, "\tjr $ra\n");
		fclose(datafile);

		printf("delete variables after function\n");
	}
	PROGRAM |  ;

FTYPE: VOID {strcpy($$, "void");} | INT {strcpy($$,"int");};

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
	/* datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
	fclose(datafile); */
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
	/* datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
	fclose(datafile); */
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
	/* datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
	fclose(datafile); */
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
 	/* datafile = fopen("mips.txt", "a+");
 	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
 	fclose(datafile); */
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
 /* datafile = fopen("mips.txt", "a+");
 fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
 fclose(datafile); */
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
	/* datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
	fclose(datafile); */
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
		char this_scope[10];
		strcpy(this_scope,popStack());
		pushStack(this_scope);

	if(!findvar_inscope($2,this_scope)){
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
		char this_scope[10];
		strcpy(this_scope,popStack());
		pushStack(this_scope);

		if(!findvar_inscope($2,this_scope)){

		printf("declare and assign int %s = %d\n",$2,atoi($4));
	struct var *newvar = addvar(&first, &last,$2, $1);

	strcpy(newvar -> current_func ,current_func);

	char num[5];
	itoa(GetFreeRegister('t'),num,5);
	char buffer[10] = {'$', 't'};
	strcpy(newvar -> which_reg , strcat(buffer,num));

	datafile = fopen("mips.txt", "a+");
	if(isnumber($4))
	{

		printf("assign  %s = %d\n",$1,atoi($4));
		newvar -> intchar_union.value_int = atoi($4);
		fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_int);
	}
	else if(isalpha($4[0]))
	{
		printf("assign  %s = %c\n",$1,$4[0]);
		newvar -> intchar_union.value_char = $4[0];
		fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_char);

	}
	else
	{

		fprintf(datafile, "\tadd %s, $zero , %s \n", newvar->which_reg,$4);
	}
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
	strcpy(first -> current_func ,current_func);

		first->next = NULL;

		char num[5];
		itoa(GetFreeRegister('t'), num,10);
		char buffer[10] = {'$','t'};
		strcat(buffer, num);


strcpy(first -> which_reg , buffer);
last = first;
datafile = fopen("mips.txt", "a+");
if(isnumber($4))
{

	printf("assign  %s = %d\n",$1,atoi($4));
	first -> intchar_union.value_int = atoi($4);
	fprintf(datafile, "\taddi %s, $zero , %d \n", first->which_reg,first -> intchar_union.value_int);
}
else if(isalpha($4[0]))
{
	printf("assign  %s = %c\n",$1,$4[0]);
	first -> intchar_union.value_char = $4[0];
	fprintf(datafile, "\taddi %s, $zero , %d \n", first->which_reg,first -> intchar_union.value_char);

}
else
{

	fprintf(datafile, "\tadd %s, $zero , %s \n", first->which_reg,$4);
}fclose(datafile);
}
}'$' STMTS |
CHAR ID {
	if(first != NULL){
		char this_scope[10];
		strcpy(this_scope,popStack());
		pushStack(this_scope);

	if(!findvar_inscope($2,this_scope)){
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
		char this_scope[10];
		strcpy(this_scope,popStack());
		pushStack(this_scope);

	if(!findvar_inscope($2,this_scope)){
			printf("declare and assign char %s = %s\n",$2,$4);

		struct var *newvar = addvar(&first, &last,$2, $1);
		strcpy(newvar -> current_func ,current_func);
		strcpy(newvar -> type ,"char");///////////////////

		char num[5];
		itoa(GetFreeRegister('t'),num,5);
		char buffer[10] = {'$', 't'};
		strcpy(newvar -> which_reg , strcat(buffer,num));

		datafile = fopen("mips.txt", "a+");
		if(isnumber($4))
		{

			printf("assign  %s = %d\n",$1,atoi($4));
			newvar -> intchar_union.value_int = atoi($4);
			fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_int);
		}
		else if(isalpha($4[0]))
		{
			printf("assign  %s = %c\n",$1,$4[0]);
			newvar -> intchar_union.value_char = $4[0];
			fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_char);

		}
		else
		{

			fprintf(datafile, "\tadd %s, $zero , %s \n", newvar->which_reg,$4);
		}

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

	if(isnumber($4))
	{

		printf("assign  %s = %d\n",$1,atoi($4));
		first -> intchar_union.value_int = atoi($4);
		fprintf(datafile, "\taddi %s, $zero , %d \n", first->which_reg,first -> intchar_union.value_int);
	}
	else if(isalpha($4[0]))
	{
		printf("assign  %s = %c\n",$1,$4[0]);
		first -> intchar_union.value_char = $4[0];
		fprintf(datafile, "\taddi %s, $zero , %d \n", first->which_reg,first -> intchar_union.value_char);

	}
	else
	{

		fprintf(datafile, "\tadd %s, $zero , %s \n", first->which_reg,$4);
	}

	fclose(datafile);
	}
	}'$' STMTS;

IDS: | ',' ID {
		if(first != NULL){

			char this_scope[10];
			strcpy(this_scope,popStack());
			pushStack(this_scope);

		if(!findvar_inscope($2,this_scope)){
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

		if(first != NULL)
		{
			char this_scope[10];
			strcpy(this_scope,popStack());
			pushStack(this_scope);

		if(findvar_inscope($1,this_scope)){

	struct var *newvar = findvar_inscope($1,this_scope);
		datafile = fopen("mips.txt", "a+");
		printf("type is %s...\n",newvar->type);
		if(isnumber($3))
		{

			printf("assign  %s = %d\n",$1,atoi($3));
			newvar -> intchar_union.value_int = atoi($3);
			fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_int);
		}
		else if(isalpha($3[0]))
		{
			printf("assign  %s = %c\n",$1,$3[0]);
			newvar -> intchar_union.value_char = $3[0];
			fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_char);

		}
		else
		{
			fprintf(datafile, "\tadd %s, $zero , %s \n", newvar->which_reg,$3);
		}

	/* if(strcmp(newvar -> type ,"char")==0)
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

	} */

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
	}
} STMTS;

//VAR_VALUE: EXP | char_val;

WHILE_STMT: WHILE {printf("while begin\n");} '(' EXP  ')' '{' STMTS '}' {printf("while end\n");} STMTS;

IF_STMT: IF {
	char buff[10];
	sprintf(buff,"%d",count_label);
	pushStack(strcat("if",buff));
	printf("if %d begin\n",count_label);
	}
	'(' EXP ')' {
		datafile = fopen("mips.txt", "a+");
		fprintf(datafile, "\tbeq %s,$zero,else%d\n",$4,count_label);
		fclose(datafile);
		}
'{' STMTS  '}' {
	datafile = fopen("mips.txt", "a+");
	popStack();
	fprintf(datafile, "\tj afterif%d:\n",count_label_end);
	fprintf(datafile, "\telse%d:\n",count_label++);
	fclose(datafile);
}
	ELSEIF_STMT ELSE_STMT {
		printf("if end\n");
		datafile = fopen("mips.txt", "a+");
 	 fprintf(datafile, "\tafterif%d:\n",count_label_end++);
 	 fclose(datafile);
		} STMTS;

ELSEIF_STMT: ELSEIF {
	char buff[10];
	sprintf(buff,"%d",count_label);
	pushStack(strcat("elseif",buff));
	printf("else if %d begin\n",count_label);
	}
 '(' EXP ')' {
	 datafile = fopen("mips.txt", "a+");
	 fprintf(datafile, "\tbeq %s,$zero,elseif%d\n",$4,count_label);
	 fclose(datafile);
	 }
	 '{' STMTS '}' {
		 popStack();
	 	datafile = fopen("mips.txt", "a+");
		fprintf(datafile, "\tj afterif%d:\n",count_label_end);
	 	fprintf(datafile, "\telseif%d:\n",count_label++);
	 	fclose(datafile);
	 } ELSEIF_STMT | ;

ELSE_STMT: ELSE {
	char buff[10];
	sprintf(buff,"%d",count_label);
	pushStack(strcat("else",buff));
	printf("else begin\n");
	}
	'{' STMTS  '}' {
		popStack();
		printf("else end\n");
		} | ;

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
		pushStack($1);
		strcpy(founded_func,$1);
		founded_func_num = fun_names[flag].num;
	}
}
'(' ARGS_IN ')' '$' {
		char buff[20];
	  datafile = fopen("mips.txt", "a+");
		sprintf(buff,"jal %s",founded_func);
		fprintf(datafile, "\t%s\n",buff);
		fclose(datafile);

		popStack();
		strcpy(current_func,popStack());
		pushStack(current_func);

	}
	STMTS {
		int i = 0;
		for (; i < func_count; i++)
		{
			if (strcmp(fun_names[i].name, $1) == 0)
				break;
		}

		if (strcmp(fun_names[i].type, "void") == 0)
			strcpy($$, "void");
		else
			strcpy($$, "int");
		};

ARGS_IN: {
	if(founded_func_num != 0 )
	{
		char error[50] = "wrong number of arguments for function  ...";
				strcat(error,founded_func);
				yyerror(error);
				YYERROR;

	}
	$$=0; printf("no args passed\n");
	} |
EXP ',' EXP ',' EXP ',' EXP {
	if(founded_func_num != 4 )
	{
		char error[50] = "wrong number of arguments for function  ...";
				strcat(error,founded_func);
				yyerror(error);
				YYERROR;

	}
	datafile = fopen("mips.txt", "a+");

	char buff[20];
	//a0
	if(isnumber($1))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",atoi($1));
		else if(isalpha($1[0]))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",$1[0]);
		else
		sprintf(buff,"add %s,%s,%s","$a0","$zero",$1);
		fprintf(datafile, "\t%s\n",buff);

		//a1
		if(isnumber($3))
			sprintf(buff,"addi %s,%s,%d","$a1","$zero",atoi($3));
			else if(isalpha($3[0]))
			sprintf(buff,"addi %s,%s,%d","$a1","$zero",$3[0]);
			else
			sprintf(buff,"add %s,%s,%s","$a1","$zero",$3);
			fprintf(datafile, "\t%s\n",buff);

			//a2
			if(isnumber($5))
				sprintf(buff,"addi %s,%s,%d","$a2","$zero",atoi($5));
				else if(isalpha($5[0]))
				sprintf(buff,"addi %s,%s,%d","$a2","$zero",$5[0]);
				else
				sprintf(buff,"add %s,%s,%s","$a2","$zero",$5);
				fprintf(datafile, "\t%s\n",buff);

				//a3
				if(isnumber($7))
					sprintf(buff,"addi %s,%s,%d","$a3","$zero",atoi($7));
					else if(isalpha($7[0]))
					sprintf(buff,"addi %s,%s,%d","$a3","$zero",$7[0]);
					else
					sprintf(buff,"add %s,%s,%s","$a3","$zero",$7);
					fprintf(datafile, "\t%s\n",buff);


	fclose(datafile);

	$$=4; printf("4 args passed\n");
}|
EXP ',' EXP ',' EXP  {
	if(founded_func_num != 3 )
	{
		char error[50] = "wrong number of arguments for function  ...";
				strcat(error, founded_func);
				yyerror(error);
				YYERROR;

	}
	datafile = fopen("mips.txt", "a+");

	char buff[20];
	//a0
	if(isnumber($1))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",atoi($1));
		else if(isalpha($1[0]))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",$1[0]);
		else
		sprintf(buff,"add %s,%s,%s","$a0","$zero",$1);
		fprintf(datafile, "\t%s\n",buff);

		//a1
		if(isnumber($3))
			sprintf(buff,"addi %s,%s,%d","$a1","$zero",atoi($3));
			else if(isalpha($3[0]))
			sprintf(buff,"addi %s,%s,%d","$a1","$zero",$3[0]);
			else
			sprintf(buff,"add %s,%s,%s","$a1","$zero",$3);
			fprintf(datafile, "\t%s\n",buff);

			//a2
			if(isnumber($5))
				sprintf(buff,"addi %s,%s,%d","$a2","$zero",atoi($5));
				else if(isalpha($5[0]))
				sprintf(buff,"addi %s,%s,%d","$a2","$zero",$5[0]);
				else
				sprintf(buff,"add %s,%s,%s","$a2","$zero",$5);
				fprintf(datafile, "\t%s\n",buff);



	fclose(datafile);

	$$=3; printf("3 args passed\n");
}|
EXP ',' EXP  {
	if(founded_func_num != 2 )
	{
		char error[50] = "wrong number of arguments for function  ...";
				strcat(error, founded_func);
				yyerror(error);
				YYERROR;

	}
	datafile = fopen("mips.txt", "a+");

	char buff[20];
	//a0
	if(isnumber($1))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",atoi($1));
		else if(isalpha($1[0]))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",$1[0]);
		else
		sprintf(buff,"add %s,%s,%s","$a0","$zero",$1);
		fprintf(datafile, "\t%s\n",buff);

		//a1
		if(isnumber($3))
			sprintf(buff,"addi %s,%s,%d","$a1","$zero",atoi($3));
			else if(isalpha($3[0]))
			sprintf(buff,"addi %s,%s,%d","$a1","$zero",$3[0]);
			else
			sprintf(buff,"add %s,%s,%s","$a1","$zero",$3);
			fprintf(datafile, "\t%s\n",buff);





	fclose(datafile);

	$$=2; printf("2 args passed\n");
}|
EXP  {
	if(founded_func_num != 1 )
	{
		char error[50] = "wrong number of arguments for function  ...";
				strcat(error, founded_func);
				yyerror(error);
				YYERROR;

	}
	datafile = fopen("mips.txt", "a+");

	char buff[20];
	//a0
	if(isnumber($1))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",atoi($1));
		else if(isalpha($1[0]))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",$1[0]);
		else
		sprintf(buff,"add %s,%s,%s","$a0","$zero",$1);
		fprintf(datafile, "\t%s\n",buff);



	fclose(datafile);

	$$=1; printf("1 args passed\n");
};

RETURN_STMT: RETURN EXP '$' {
	printf("return\n");
	if (isnumber($2) || isalpha($2[0]))
	{
		char num[5];
		itoa(GetFreeRegister('t'), num,5);
		char buffer[10] = {'$','t'};
		strcat(buffer, num);
		char buff[50];
		if (isalpha($2[0]))
			sprintf(buff,"addi %s, $zero, %d",buffer,$2[0]);
		else
			sprintf(buff,"addi %s, $zero, %s",buffer,$2);
		datafile = fopen("mips.txt", "a+");
		fprintf(datafile, "\t%s\n",buff);
		fclose(datafile);

		sprintf(buff,"move $v0, %s",buffer);
		freereg(buffer);
		datafile = fopen("mips.txt", "a+");
		fprintf(datafile, "\t%s\n",buff);
		fclose(datafile);

		sprintf(return_result,"%s", $2);


	}
	else{
	char buff[20];
	sprintf(buff,"move $v0, %s",$2);

	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\t%s\n",buff);
	sprintf(return_result,"%s", $2);
	fclose(datafile);
	}
} STMTS ;

EXP: EXP ISEQ EXP {
	printf("equality condition\n");
	if (isnumber($1) || isalpha($1[0]) || isnumber($3) || isalpha($3[0]))
	{
		char buffer1[10] = {'$','t'};
		char buffer2[10] = {'$','t'};
		char buffer3[10] = {'$', 't'};
		int new_buffer1 = 0;
		int new_buffer2 = 0;
		if (isnumber($1) || isalpha($1[0]))
		{
			new_buffer1 = 1;
		char num[5];
		itoa(GetFreeRegister('t'), num,5);

		strcat(buffer1, num);
		char buff[50];
		if (isalpha($1[0]))
			sprintf(buff,"addi %s, $zero, %d",buffer1,$1[0]);
		else
			sprintf(buff,"addi %s, $zero, %s",buffer1,$1);
		datafile = fopen("mips.txt", "a+");
		fprintf(datafile, "\t%s\n",buff);
		fclose(datafile);
		}
		else
			sprintf(buffer1, "%s", $1);

		if (isnumber($3) || isalpha($3[0]))
		{
			new_buffer2 = 1;
			char num[5];
			itoa(GetFreeRegister('t'), num,5);
			strcat(buffer2, num);
			char buff[50];
			if (isalpha($3[0]))
				sprintf(buff,"addi %s, $zero, %d",buffer2,$3[0]);
			else
				sprintf(buff,"addi %s, $zero, %s",buffer2,$3);
			datafile = fopen("mips.txt", "a+");
			fprintf(datafile, "\t%s\n",buff);
			fclose(datafile);
		}
		else
			sprintf(buffer2, "%s", $3);

		char num[5];
		itoa(GetFreeRegister('t'), num,5);
		strcat(buffer3, num);

		char buff[20];
		sprintf(buff,"sub %s,%s,%s",buffer3,buffer1,buffer2);
		if (new_buffer1)
		freereg(buffer1);
		if (new_buffer2)
		freereg(buffer2);
		datafile = fopen("mips.txt", "a+");



		fprintf(datafile, "\t%s\n",buff);
		fclose(datafile);

		sprintf($$,"%s",buffer3);
	}
	else{
	char num[5];
	itoa(GetFreeRegister('t'), num,5);
	char buffer[10] = {'$','t'};
	strcat(buffer, num);

	char buff[20];
	sprintf(buff,"sub %s,%s,%s",buffer,$1,$3);

	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\t%s\n",buff);
	fclose(datafile);


	sprintf($$,"%s",buffer);

	}

} |
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


	strcpy($$,buffer);
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
| '-' EXP {printf("negative num\n"); sprintf($$,"%d", -atoi($2));}
| FUNC_CALL  {

	if (strcmp($1, "void") == 0)
	{
		char error[40] = "void function has no return value ...";
		yyerror(error);
		YYERROR;
	}
	else
	{
		printf("%s\n", return_result);
		char buff[20];
		sprintf(buff,"addi %s,%s,%s","$s0","$zero",return_result);

		datafile = fopen("mips.txt", "a+");
		fprintf(datafile, "\t%s\n",buff);
		fclose(datafile);
		sprintf($$, "%s" , return_result);
	}
} ;


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
struct var* findvar_inscope(char var_name[10],char this_scope[10])
{
	///
	int size = 0 , sizeofStack = stackSize;
	char scope[sizeofStack][10];
	for(int k=0 ; k<func_count; k++)
	{
		if(strcmp(fun_names[k].name,this_scope)==0)
		{
			size = 1;
			strcpy(this_scope,fun_names[k].name);
			break;
		}
	}
	if(size == 0 )
	{
		for(int k=0;k<sizeofStack;k++)
		{
			strcpy(scope[k],popStack());
			//find func
			for(int q=0 ; q<func_count; q++)
			{
				if(strcmp(fun_names[q].name,scope[k])==0)
				{
					size = k+1 ;
					break;
				}
			}
			if(size != 0)
			{
				break;
			}
			//find func
		}
		///
		for(int k=0;k<size;k++)
		{
			if(findvar(first,var_name,scope[k]))
				{
					for(int k1=size-1;k1>=0;k1--)
					{
						pushStack(scope[k1]);
					}
					return findvar(first,var_name,scope[k]);
				}
		}
		for(int k=size-1;k>=0;k--)
		{
			pushStack(scope[k]);
		}
		return NULL;
		///

	}
	else
	{
		if(findvar(first,var_name,this_scope))
			{
				return findvar(first,var_name,this_scope);
			}
			else
			{
				return NULL;
			}
	}


	///
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
_Bool isnumber(char* reg){
	if(reg[0] == '-' || (reg[0] >= '0' && reg[0] <= '9')){

		for(int i=1; i<strlen(reg); i++){
			if(!(reg[i] >= '0' && reg[i] <= '9'))
				return 0;
		}

		return 1;
	}
	return 0;
}
