
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "code.y"

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
int count_label = 0 ;

//struct func function_types[10000];
//int functions_count = 0;

int yyparse();
void yyerror(const char *s);


struct var* findvar_inscope(char var_name[10],char this_scope[10]);
struct var* findvar_WithFunc(struct var* first, char* funcName);
struct var* findvar_withreg(char* reg, char* funcName);
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


/* Line 189 of yacc.c  */
#line 167 "code.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTVAL = 258,
     char_val = 259,
     COND_OR = 260,
     COND_AND = 261,
     LOG_OR = 262,
     LOG_XOR = 263,
     LOG_AND = 264,
     ISNOTEQ = 265,
     ISEQ = 266,
     ISHIGHERANDEQ = 267,
     ISHIGHER = 268,
     ISLOWERANDEQ = 269,
     ISLOWER = 270,
     NOT = 271,
     VALUE_ID = 272,
     EQ = 273,
     MULTI_COMMENT = 274,
     COMMENT = 275,
     CHAR = 276,
     INT = 277,
     CONTINUE = 278,
     BREAK = 279,
     RETURN = 280,
     MAIN = 281,
     FOR = 282,
     VOID = 283,
     ELSE = 284,
     ELSEIF = 285,
     WHILE = 286,
     IF = 287,
     NUM = 288,
     ID = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 97 "code.y"

	  int ival;
		char cval;
		char sval[10];
		//char plus,min,multi;



/* Line 214 of yacc.c  */
#line 246 "code.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 258 "code.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   256

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    26,     2,     2,     2,
      22,    23,    19,    17,     5,    18,     2,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    24,     2,    25,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    21,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,     6,    19,    20,    22,    24,
      25,    28,    33,    39,    46,    48,    50,    53,    57,    59,
      61,    63,    65,    67,    69,    70,    71,    78,    79,    87,
      88,    95,    96,   104,   105,   106,   111,   112,   119,   120,
     121,   132,   133,   134,   135,   136,   151,   152,   153,   164,
     165,   166,   172,   173,   174,   175,   184,   185,   186,   187,
     199,   200,   208,   214,   218,   220,   221,   227,   231,   235,
     239,   243,   245,   249,   253,   257,   261,   265,   268,   272,
     274,   276
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    -1,    -1,    -1,    49,    44,    55,    22,
      51,    56,    23,    45,    60,    46,    57,    54,    -1,    -1,
      38,    -1,    32,    -1,    -1,    50,    44,    -1,    58,     5,
      50,    44,    -1,    58,    59,     5,    50,    44,    -1,    58,
      59,    59,     5,    50,    44,    -1,    31,    -1,    32,    -1,
      50,    44,    -1,     5,    50,    44,    -1,    61,    -1,    68,
      -1,    70,    -1,    73,    -1,    52,    -1,    88,    -1,    -1,
      -1,    32,    44,    62,    66,    26,    60,    -1,    -1,    32,
      44,    28,    48,    63,    26,    60,    -1,    -1,    31,    44,
      64,    66,    26,    60,    -1,    -1,    31,    44,    28,    48,
      65,    26,    60,    -1,    -1,    -1,     5,    44,    67,    66,
      -1,    -1,    44,    28,    48,    26,    69,    60,    -1,    -1,
      -1,    41,    71,    22,    48,    23,    45,    60,    46,    72,
      60,    -1,    -1,    -1,    -1,    -1,    42,    74,    22,    48,
      23,    75,    45,    60,    46,    76,    78,    81,    77,    60,
      -1,    -1,    -1,    40,    79,    22,    48,    23,    45,    60,
      46,    80,    40,    -1,    -1,    -1,    39,    82,    45,    60,
      46,    -1,    -1,    -1,    -1,    44,    83,    22,    53,    23,
      26,    84,    60,    -1,    -1,    -1,    -1,    44,    28,    44,
      85,    22,    53,    23,    26,    86,    87,    60,    -1,    -1,
      48,     5,    48,     5,    48,     5,    48,    -1,    48,     5,
      48,     5,    48,    -1,    48,     5,    48,    -1,    48,    -1,
      -1,    35,    48,    26,    89,    60,    -1,    48,    12,    48,
      -1,    48,    11,    48,    -1,    48,    17,    48,    -1,    48,
      18,    48,    -1,     3,    -1,    48,     7,    48,    -1,    48,
       6,    48,    -1,    48,     8,    48,    -1,    48,    10,    48,
      -1,    48,     9,    48,    -1,    21,    48,    -1,    22,    48,
      23,    -1,     4,    -1,    44,    -1,    18,    48,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   145,   145,   150,   169,   145,   186,   188,   188,   190,
     191,   216,   241,   266,   292,   292,   296,   320,   343,   344,
     345,   346,   347,   348,   348,   351,   351,   412,   412,   503,
     503,   560,   560,   657,   657,   657,   712,   712,   783,   783,
     783,   785,   789,   794,   799,   785,   801,   801,   801,   801,
     803,   803,   803,   805,   828,   805,   853,   876,   888,   853,
     947,   958,  1011,  1056,  1094,  1122,  1122,  1178,  1262,  1263,
    1280,  1299,  1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,
    1319,  1346
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTVAL", "char_val", "','", "COND_OR",
  "COND_AND", "LOG_OR", "LOG_XOR", "LOG_AND", "ISNOTEQ", "ISEQ",
  "ISHIGHERANDEQ", "ISHIGHER", "ISLOWERANDEQ", "ISLOWER", "'+'", "'-'",
  "'*'", "'/'", "NOT", "'('", "')'", "'['", "']'", "'$'", "VALUE_ID", "EQ",
  "MULTI_COMMENT", "COMMENT", "CHAR", "INT", "CONTINUE", "BREAK", "RETURN",
  "MAIN", "FOR", "VOID", "ELSE", "ELSEIF", "WHILE", "IF", "NUM", "ID",
  "'{'", "'}'", "$accept", "EXP", "FTYPE", "VTYPE", "PARAMS", "FUNC_CALL",
  "ARGS_IN", "PROGRAM", "$@1", "$@2", "$@3", "THREE_ID", "THREE_ID_COMMA",
  "STMTS", "DECLARE_STMT", "$@4", "$@5", "$@6", "$@7", "IDS", "$@8",
  "ASSIGN_STMT", "$@9", "WHILE_STMT", "$@10", "$@11", "IF_STMT", "$@12",
  "$@13", "$@14", "$@15", "ELSEIF_STMT", "$@16", "$@17", "ELSE_STMT",
  "$@18", "$@19", "$@20", "$@21", "$@22", "$@23", "RETURN_STMT", "$@24", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,    44,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,    43,    45,    42,
      47,   271,    40,    41,    91,    93,    36,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    55,    56,    57,    54,    54,    49,    49,    51,
      51,    51,    51,    51,    50,    50,    58,    59,    60,    60,
      60,    60,    60,    60,    60,    62,    61,    63,    61,    64,
      61,    65,    61,    66,    67,    66,    69,    68,    71,    72,
      70,    74,    75,    76,    77,    73,    79,    80,    78,    78,
      82,    81,    81,    83,    84,    52,    85,    86,    87,    52,
      53,    53,    53,    53,    53,    89,    88,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,    12,     0,     1,     1,     0,
       2,     4,     5,     6,     1,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     0,     0,     6,     0,     7,     0,
       6,     0,     7,     0,     0,     4,     0,     6,     0,     0,
      10,     0,     0,     0,     0,    14,     0,     0,    10,     0,
       0,     5,     0,     0,     0,     8,     0,     0,     0,    11,
       0,     7,     5,     3,     1,     0,     5,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     8,     7,     0,     0,     2,     1,     0,     9,    14,
      15,     0,     3,     0,    10,     0,     0,     0,     0,     0,
       0,     0,    24,    11,     0,     0,     0,     0,     0,    38,
      41,    53,    22,     0,    18,    19,    20,    21,    23,    12,
       0,    29,    25,    71,    79,     0,     0,     0,    80,     0,
       0,     0,     0,     0,     4,    13,     0,    33,     0,    33,
      81,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,     0,     0,    80,     0,    60,     6,    31,
       0,     0,    27,     0,    78,    73,    72,    74,    76,    75,
      68,    67,    69,    70,    24,     0,     0,     0,    36,    64,
       0,     5,     0,    34,    24,     0,    24,    66,     0,    42,
      60,    24,     0,     0,    24,    33,    30,    24,    26,    24,
       0,     0,    37,    63,    54,    32,    35,    28,     0,    24,
       0,     0,    24,    39,     0,    57,    62,    55,    24,    43,
      58,     0,    40,    49,    24,    61,    46,    52,    59,     0,
      50,    44,     0,     0,    24,     0,    24,    45,     0,     0,
      24,    51,     0,    47,     0,    48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    99,     3,    11,    12,    32,   100,     4,     7,    15,
      78,    13,    17,    33,    34,    59,   105,    57,   102,    81,
     115,    35,   111,    36,    50,   138,    37,    51,   120,   143,
     154,   147,   149,   164,   151,   153,    53,   132,    97,   140,
     144,    38,    94
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -59
static const yytype_int16 yypact[] =
{
     -22,   -59,   -59,   -35,    13,   -59,   -59,     1,   -11,   -59,
     -59,   -17,   -59,    26,    29,    24,   -11,    53,    20,    19,
     -11,    61,    18,    71,    33,   -11,    41,    42,     4,   -59,
     -59,    40,   -59,    32,   -59,   -59,   -59,   -59,   -59,    71,
      45,    62,    65,   -59,   -59,     4,     4,     4,   -59,    90,
      69,    73,    11,    83,   -59,   -59,     4,   104,     4,   104,
     -59,   -59,   124,     4,     4,     4,     4,     4,     4,     4,
       4,     4,   -59,     4,     4,    89,   111,     4,   -22,   238,
      68,    88,   238,    99,   -59,    63,    -6,   146,   128,   162,
      34,    34,   -59,   -59,    18,   142,   160,    93,   -59,   197,
     103,   -59,   101,   -59,    18,   117,    18,   -59,   116,   -59,
       4,    18,     4,   118,    18,   104,   -59,    18,   -59,    18,
     130,   139,   -59,   211,   -59,   -59,   -59,   -59,   135,    18,
     150,     4,    18,   -59,   136,   -59,   225,   -59,    18,   -59,
     -59,     4,   -59,   151,    18,   238,   -59,   153,   -59,   171,
     -59,   -59,     4,   149,    18,   178,    18,   -59,   152,   154,
      18,   -59,   164,   -59,   158,   -59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -28,   -59,    67,   -59,   -59,   102,   121,   -59,   -59,
     -59,   -59,   194,   -50,   -59,   -59,   -59,   -59,   -59,   -58,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -57
static const yytype_int16 yytable[] =
{
      49,    83,    65,    66,    67,    68,    69,    43,    44,     5,
       1,    70,    71,     6,    43,    44,     2,    60,    61,    62,
       9,    10,    45,     8,    76,    46,    47,    14,    79,    45,
      82,    16,    46,    47,   -16,    85,    86,    87,    88,    89,
      90,    91,    92,    93,   107,    95,    96,    18,    48,    26,
      27,    70,    71,    28,   116,    75,   118,   126,    20,    29,
      30,   122,    31,    23,   125,    22,    25,   127,    52,   128,
      64,    65,    66,    67,    68,    69,   -17,    39,    54,   134,
      70,    71,   137,    19,   123,    41,    42,    24,   142,    55,
      56,    73,    40,    58,   148,    74,    63,    64,    65,    66,
      67,    68,    69,   136,   157,    77,   159,    70,    71,    80,
     162,   -56,   103,   145,   104,   110,    72,    63,    64,    65,
      66,    67,    68,    69,   155,   106,   113,   114,    70,    71,
      63,    64,    65,    66,    67,    68,    69,    98,    67,    68,
      69,    70,    71,   117,   124,    70,    71,    84,    63,    64,
      65,    66,    67,    68,    69,    66,    67,    68,    69,    70,
      71,   119,   130,    70,    71,   108,    63,    64,    65,    66,
      67,    68,    69,    68,    69,   129,   135,    70,    71,    70,
      71,   133,   139,   109,    63,    64,    65,    66,    67,    68,
      69,   146,   150,   152,   156,    70,    71,   160,   165,   101,
     161,   158,   112,    63,    64,    65,    66,    67,    68,    69,
     163,    21,   121,     0,    70,    71,   131,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,     0,    70,    71,
     141,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,    70,    71,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,    70,    71
};

static const yytype_int16 yycheck[] =
{
      28,    59,     8,     9,    10,    11,    12,     3,     4,    44,
      32,    17,    18,     0,     3,     4,    38,    45,    46,    47,
      31,    32,    18,    22,    52,    21,    22,    44,    56,    18,
      58,     5,    21,    22,     5,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    94,    73,    74,    23,    44,    31,
      32,    17,    18,    35,   104,    44,   106,   115,     5,    41,
      42,   111,    44,    44,   114,    45,     5,   117,    28,   119,
       7,     8,     9,    10,    11,    12,     5,    44,    46,   129,
      17,    18,   132,    16,   112,    44,    44,    20,   138,    44,
      28,    22,    25,    28,   144,    22,     6,     7,     8,     9,
      10,    11,    12,   131,   154,    22,   156,    17,    18,     5,
     160,    22,    44,   141,    26,    22,    26,     6,     7,     8,
       9,    10,    11,    12,   152,    26,    23,    26,    17,    18,
       6,     7,     8,     9,    10,    11,    12,    26,    10,    11,
      12,    17,    18,    26,    26,    17,    18,    23,     6,     7,
       8,     9,    10,    11,    12,     9,    10,    11,    12,    17,
      18,    45,    23,    17,    18,    23,     6,     7,     8,     9,
      10,    11,    12,    11,    12,    45,    26,    17,    18,    17,
      18,    46,    46,    23,     6,     7,     8,     9,    10,    11,
      12,    40,    39,    22,    45,    17,    18,    45,    40,    78,
      46,    23,     5,     6,     7,     8,     9,    10,    11,    12,
      46,    17,   110,    -1,    17,    18,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,    18,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    17,    18,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    17,    18
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    38,    49,    54,    44,     0,    55,    22,    31,
      32,    50,    51,    58,    44,    56,     5,    59,    23,    50,
       5,    59,    45,    44,    50,     5,    31,    32,    35,    41,
      42,    44,    52,    60,    61,    68,    70,    73,    88,    44,
      50,    44,    44,     3,     4,    18,    21,    22,    44,    48,
      71,    74,    28,    83,    46,    44,    28,    64,    28,    62,
      48,    48,    48,     6,     7,     8,     9,    10,    11,    12,
      17,    18,    26,    22,    22,    44,    48,    22,    57,    48,
       5,    66,    48,    66,    23,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    89,    48,    48,    85,    26,    48,
      53,    54,    65,    44,    26,    63,    26,    60,    23,    23,
      22,    69,     5,    23,    26,    67,    60,    26,    60,    45,
      75,    53,    60,    48,    26,    60,    66,    60,    60,    45,
      23,     5,    84,    46,    60,    26,    48,    60,    72,    46,
      86,     5,    60,    76,    87,    48,    40,    78,    60,    79,
      39,    81,    22,    82,    77,    48,    45,    60,    23,    60,
      45,    46,    60,    46,    80,    40
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 145 "code.y"
    {
	strcpy(current_func,(yyvsp[(2) - (2)].sval));
	pushStack((yyvsp[(2) - (2)].sval));

 ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 150 "code.y"
    {
	 printf("see function : %s\n",current_func);

	 datafile = fopen("mips.txt", "a+");
	 fprintf(datafile, "%s:\n", current_func);
	 fprintf(datafile, "\taddi $sp, $sp , -32\n");
	 for(int w=0;w<8;w++)
	 {
		 fprintf(datafile, "\tsw $t%d, %d($sp)\n", w,w*4);
	 }

	 fclose(datafile);

	 printf("Param value : %d\n",(yyvsp[(5) - (5)].ival));

	 fun_names[func_count].num = (yyvsp[(5) - (5)].ival);
	 strcpy(fun_names[func_count].name,current_func);
	 strcpy(fun_names[func_count++].type, (yyvsp[(1) - (5)].sval));
		;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 169 "code.y"
    {

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
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 188 "code.y"
    {strcpy((yyval.sval), "void");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 188 "code.y"
    {strcpy((yyval.sval),"int");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 190 "code.y"
    {(yyval.ival) = 0; printf("no parameters\n");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 191 "code.y"
    {

	printf("jooooooooooooooo %s\n", (yyvsp[(1) - (2)].sval));
	struct var *newvar = addvar(&first, &last,(yyvsp[(2) - (2)].sval), (yyvsp[(1) - (2)].sval));
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
		(yyval.ival) = 1;
		printf("1 parameters %d\n",(yyval.ival));
;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 216 "code.y"
    {


	struct var *newvar = addvar(&first, &last,(yyvsp[(4) - (4)].sval), (yyvsp[(3) - (4)].sval));
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
	(yyval.ival) = 2;
	printf("2 parameters\n");
;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 241 "code.y"
    {


	struct var *newvar = addvar(&first, &last,(yyvsp[(5) - (5)].sval), (yyvsp[(4) - (5)].sval));
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
	(yyval.ival) = 3;
	printf("3 parameters\n");
;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 266 "code.y"
    {


	struct var *newvar = addvar(&first, &last,(yyvsp[(6) - (6)].sval), (yyvsp[(5) - (6)].sval));
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
	(yyval.ival) = 4;
	printf("4 parameters\n");
 ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 292 "code.y"
    {strcpy((yyval.sval), "char");;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 292 "code.y"
    { strcpy((yyval.sval), "int");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 296 "code.y"
    {

 struct var *newvar = addvar(&first, &last,(yyvsp[(2) - (2)].sval), (yyvsp[(1) - (2)].sval));
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
;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 320 "code.y"
    {

	struct var *newvar = addvar(&first, &last,(yyvsp[(3) - (3)].sval), (yyvsp[(2) - (3)].sval));
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
;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 351 "code.y"
    {
	if(first != NULL){
		char this_scope[10];
		strcpy(this_scope,popStack());
		pushStack(this_scope);

	if(!findvar_inscope((yyvsp[(2) - (2)].sval),this_scope)){
		printf("declare %s %s\n",(yyvsp[(1) - (2)].sval),(yyvsp[(2) - (2)].sval));


		strcpy(currtype,(yyvsp[(1) - (2)].sval));
	struct var *newvar = addvar(&first, &last,(yyvsp[(2) - (2)].sval), (yyvsp[(1) - (2)].sval));

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
				strcat(error, (yyvsp[(2) - (2)].sval));
				yyerror(error);
				YYERROR;
}
}
else{
	printf("declare %s %s\n",(yyvsp[(1) - (2)].sval),(yyvsp[(2) - (2)].sval));


	first = (struct var*)malloc(sizeof(struct var));
	last = (struct var*)malloc(sizeof(struct var));

	strcpy(first->name ,(yyvsp[(2) - (2)].sval));
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
;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 412 "code.y"
    {
	if(first != NULL){
		char this_scope[10];
		strcpy(this_scope,popStack());
		pushStack(this_scope);

		if(!findvar_inscope((yyvsp[(2) - (4)].sval),this_scope)){

		printf("declare and assign int %s = %d\n",(yyvsp[(2) - (4)].sval),atoi((yyvsp[(4) - (4)].sval)));
	struct var *newvar = addvar(&first, &last,(yyvsp[(2) - (4)].sval), (yyvsp[(1) - (4)].sval));

	strcpy(newvar -> current_func ,current_func);

	char num[5];
	itoa(GetFreeRegister('t'),num,5);
	char buffer[10] = {'$', 't'};
	strcpy(newvar -> which_reg , strcat(buffer,num));

	datafile = fopen("mips.txt", "a+");
	if(isnumber((yyvsp[(4) - (4)].sval)))
	{

		printf("assign  %s = %d\n",(yyvsp[(1) - (4)].sval),atoi((yyvsp[(4) - (4)].sval)));
		newvar -> intchar_union.value_int = atoi((yyvsp[(4) - (4)].sval));
		fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_int);
	}
	else if(isalpha((yyvsp[(4) - (4)].sval)[0]))
	{
		printf("assign  %s = %c\n",(yyvsp[(1) - (4)].sval),(yyvsp[(4) - (4)].sval)[0]);
		newvar -> intchar_union.value_char = (yyvsp[(4) - (4)].sval)[0];
		fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_char);

	}
	else
	{

		fprintf(datafile, "\tadd %s, $zero , %s \n", newvar->which_reg,(yyvsp[(4) - (4)].sval));
	}
	fclose(datafile);
}
else
{
	char error[30] = "replicate variable ";
				strcat(error, (yyvsp[(2) - (4)].sval));
				yyerror(error);
				YYERROR;
}
}
else{
	printf("declare and assign int %s = %d\n",(yyvsp[(2) - (4)].sval),atoi((yyvsp[(4) - (4)].sval)));


	first = (struct var*)malloc(sizeof(struct var));
	last = (struct var*)malloc(sizeof(struct var));

	strcpy(first->name ,(yyvsp[(2) - (4)].sval));
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
if(isnumber((yyvsp[(4) - (4)].sval)))
{

	printf("assign  %s = %d\n",(yyvsp[(1) - (4)].sval),atoi((yyvsp[(4) - (4)].sval)));
	first -> intchar_union.value_int = atoi((yyvsp[(4) - (4)].sval));
	fprintf(datafile, "\taddi %s, $zero , %d \n", first->which_reg,first -> intchar_union.value_int);
}
else if(isalpha((yyvsp[(4) - (4)].sval)[0]))
{
	printf("assign  %s = %c\n",(yyvsp[(1) - (4)].sval),(yyvsp[(4) - (4)].sval)[0]);
	first -> intchar_union.value_char = (yyvsp[(4) - (4)].sval)[0];
	fprintf(datafile, "\taddi %s, $zero , %d \n", first->which_reg,first -> intchar_union.value_char);

}
else
{

	fprintf(datafile, "\tadd %s, $zero , %s \n", first->which_reg,(yyvsp[(4) - (4)].sval));
}fclose(datafile);
}
;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 503 "code.y"
    {
	if(first != NULL){
		char this_scope[10];
		strcpy(this_scope,popStack());
		pushStack(this_scope);

	if(!findvar_inscope((yyvsp[(2) - (2)].sval),this_scope)){
		printf("declare %s %s\n","char",(yyvsp[(2) - (2)].sval));

		strcpy(currtype,(yyvsp[(1) - (2)].sval));
	struct var *newvar = addvar(&first, &last,(yyvsp[(2) - (2)].sval), (yyvsp[(1) - (2)].sval));
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
				strcat(error, (yyvsp[(2) - (2)].sval));
				yyerror(error);
				YYERROR;
}
}
else{
	printf("declare char %s\n","char",(yyvsp[(2) - (2)].sval));


	first = (struct var*)malloc(sizeof(struct var));
	last = (struct var*)malloc(sizeof(struct var));

	strcpy(first->name ,(yyvsp[(2) - (2)].sval));
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
;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 560 "code.y"
    {
	if(first != NULL){
		char this_scope[10];
		strcpy(this_scope,popStack());
		pushStack(this_scope);

	if(!findvar_inscope((yyvsp[(2) - (4)].sval),this_scope)){
			printf("declare and assign char %s = %s\n",(yyvsp[(2) - (4)].sval),(yyvsp[(4) - (4)].sval));

		struct var *newvar = addvar(&first, &last,(yyvsp[(2) - (4)].sval), (yyvsp[(1) - (4)].sval));
		strcpy(newvar -> current_func ,current_func);
		strcpy(newvar -> type ,"char");///////////////////

		char num[5];
		itoa(GetFreeRegister('t'),num,5);
		char buffer[10] = {'$', 't'};
		strcpy(newvar -> which_reg , strcat(buffer,num));

		datafile = fopen("mips.txt", "a+");
		if(isnumber((yyvsp[(4) - (4)].sval)))
		{

			printf("assign  %s = %d\n",(yyvsp[(1) - (4)].sval),atoi((yyvsp[(4) - (4)].sval)));
			newvar -> intchar_union.value_int = atoi((yyvsp[(4) - (4)].sval));
			fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_int);
		}
		else if(isalpha((yyvsp[(4) - (4)].sval)[0]))
		{
			printf("assign  %s = %c\n",(yyvsp[(1) - (4)].sval),(yyvsp[(4) - (4)].sval)[0]);
			newvar -> intchar_union.value_char = (yyvsp[(4) - (4)].sval)[0];
			fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_char);

		}
		else
		{

			fprintf(datafile, "\tadd %s, $zero , %s \n", newvar->which_reg,(yyvsp[(4) - (4)].sval));
		}

		fclose(datafile);
	}
	else
	{
		char error[30] = "replicate variable ";
					strcat(error, (yyvsp[(2) - (4)].sval));
					yyerror(error);
					YYERROR;
	}
	}
	else{
		printf("fisrt declare and assign char %s = %s\n",(yyvsp[(2) - (4)].sval),(yyvsp[(4) - (4)].sval));


		first = (struct var*)malloc(sizeof(struct var));
		last = (struct var*)malloc(sizeof(struct var));
		strcpy(first->name ,(yyvsp[(2) - (4)].sval));
		char buff3[2] ;
		strcpy(buff3,(yyvsp[(4) - (4)].sval));
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

	if(isnumber((yyvsp[(4) - (4)].sval)))
	{

		printf("assign  %s = %d\n",(yyvsp[(1) - (4)].sval),atoi((yyvsp[(4) - (4)].sval)));
		first -> intchar_union.value_int = atoi((yyvsp[(4) - (4)].sval));
		fprintf(datafile, "\taddi %s, $zero , %d \n", first->which_reg,first -> intchar_union.value_int);
	}
	else if(isalpha((yyvsp[(4) - (4)].sval)[0]))
	{
		printf("assign  %s = %c\n",(yyvsp[(1) - (4)].sval),(yyvsp[(4) - (4)].sval)[0]);
		first -> intchar_union.value_char = (yyvsp[(4) - (4)].sval)[0];
		fprintf(datafile, "\taddi %s, $zero , %d \n", first->which_reg,first -> intchar_union.value_char);

	}
	else
	{

		fprintf(datafile, "\tadd %s, $zero , %s \n", first->which_reg,(yyvsp[(4) - (4)].sval));
	}

	fclose(datafile);
	}
	;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 657 "code.y"
    {
		if(first != NULL){

			char this_scope[10];
			strcpy(this_scope,popStack());
			pushStack(this_scope);

		if(!findvar_inscope((yyvsp[(2) - (2)].sval),this_scope)){
		printf("declare more id %s %s\n",currtype,(yyvsp[(2) - (2)].sval));
	struct var *newvar = addvar(&first, &last,(yyvsp[(2) - (2)].sval), currtype);
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
				strcat(error, (yyvsp[(2) - (2)].sval));
				yyerror(error);
				YYERROR;

}}
else{
	printf("declare more id %s %s\n",currtype,(yyvsp[(2) - (2)].sval));


	first = (struct var*)malloc(sizeof(struct var));
	last = (struct var*)malloc(sizeof(struct var));

	strcpy(first->name ,(yyvsp[(2) - (2)].sval));
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
};}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 712 "code.y"
    {

		if(first != NULL)
		{
			char this_scope[10];
			strcpy(this_scope,popStack());
			pushStack(this_scope);

		if(findvar_inscope((yyvsp[(1) - (4)].sval),this_scope)){

	struct var *newvar = findvar_inscope((yyvsp[(1) - (4)].sval),this_scope);
		datafile = fopen("mips.txt", "a+");
		printf("type is %s...\n",newvar->type);
		if(isnumber((yyvsp[(3) - (4)].sval)))
		{

			printf("assign  %s = %d\n",(yyvsp[(1) - (4)].sval),atoi((yyvsp[(3) - (4)].sval)));
			newvar -> intchar_union.value_int = atoi((yyvsp[(3) - (4)].sval));
			fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_int);
		}
		else if(isalpha((yyvsp[(3) - (4)].sval)[0]))
		{
			printf("assign  %s = %c\n",(yyvsp[(1) - (4)].sval),(yyvsp[(3) - (4)].sval)[0]);
			newvar -> intchar_union.value_char = (yyvsp[(3) - (4)].sval)[0];
			fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_char);

		}
		else
		{
			fprintf(datafile, "\tadd %s, $zero , %s \n", newvar->which_reg,(yyvsp[(3) - (4)].sval));
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
				strcat(error, (yyvsp[(1) - (4)].sval));
				yyerror(error);
				YYERROR;

}
}
else
{
	char error[30] = "no such variable exists ...";
				strcat(error, (yyvsp[(1) - (4)].sval));
				yyerror(error);
				YYERROR;
	}
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 783 "code.y"
    {printf("while begin\n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 783 "code.y"
    {printf("while end\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 785 "code.y"
    {
	pushStack("if");
	printf("if begin\n");
	;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 789 "code.y"
    {
		datafile = fopen("mips.txt", "a+");
		fprintf(datafile, "\tbeq %s,$zero,else%d\n",(yyvsp[(4) - (5)].sval),count_label);
		fclose(datafile);
		;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 794 "code.y"
    {
	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\telse%d:\n",count_label++);
	fclose(datafile);
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 799 "code.y"
    {printf("if end\n");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 801 "code.y"
    {printf("elseif begin\n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 801 "code.y"
    {printf("elseif end\n");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 803 "code.y"
    {printf("else begin\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 803 "code.y"
    {printf("else end\n");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 805 "code.y"
    {
	int flag = -1 ;
	for(int i=0;i<func_count;i++)
	{
		if(strcmp((yyvsp[(1) - (1)].sval),fun_names[i].name)==0)
		{
			flag = i;
		}
	}
	if(flag == -1 )
	{
		char error[30] = "no such function exists ...";
					strcat(error, (yyvsp[(1) - (1)].sval));
					yyerror(error);
					YYERROR;
	}
	else
	{
		pushStack((yyvsp[(1) - (1)].sval));
		strcpy(founded_func,(yyvsp[(1) - (1)].sval));
		founded_func_num = fun_names[flag].num;
	}
;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 828 "code.y"
    {
		char buff[20];
	  datafile = fopen("mips.txt", "a+");
		sprintf(buff,"jal %s",founded_func);
		fprintf(datafile, "\t%s\n",buff);
		fclose(datafile);

		popStack();
		strcpy(current_func,popStack());
		pushStack(current_func);

	;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 840 "code.y"
    {
		int i = 0;
		for (; i < func_count; i++)
		{
			if (strcmp(fun_names[i].name, (yyvsp[(1) - (8)].sval)) == 0)
				break;
		}

		if (strcmp(fun_names[i].type, "void") == 0)
			strcpy((yyval.sval), "void");
		else
			strcpy((yyval.sval), "int");
		;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 853 "code.y"
    {
	int flag = -1 ;
	for(int i=0;i<func_count;i++)
	{
		if(strcmp((yyvsp[(3) - (3)].sval),fun_names[i].name)==0)
		{
			flag = i;
		}
	}
	if(flag == -1 )
	{
		char error[30] = "no such function exists ...";
					strcat(error, (yyvsp[(3) - (3)].sval));
					yyerror(error);
					YYERROR;
	}
	else
	{
		pushStack((yyvsp[(3) - (3)].sval));
		strcpy(founded_func,(yyvsp[(3) - (3)].sval));
		founded_func_num = fun_names[flag].num;
	}
;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 876 "code.y"
    {
		char buff[20];
	  datafile = fopen("mips.txt", "a+");
		sprintf(buff,"jal %s",founded_func);
		fprintf(datafile, "\t%s\n",buff);
		fclose(datafile);

		popStack();
		strcpy(current_func,popStack());
		pushStack(current_func);

	;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 888 "code.y"
    {
		
	int i = 0;
		for (; i < func_count; i++)
		{
			if (strcmp(fun_names[i].name, (yyvsp[(3) - (9)].sval)) == 0)
				break;
		}

		if (strcmp(fun_names[i].type, "void") == 0)
		
	{
		char error[40] = "void function has no return value ...";
		yyerror(error);
		YYERROR;
	}
	else
	{
		if (findvar(first,(yyvsp[(1) - (9)].sval), current_func))
		{
			struct var* this_var = findvar(first,(yyvsp[(1) - (9)].sval), current_func);
		//printf("%s\n", return_result);
		char this_scope[10];
		strcpy(this_scope,popStack());
		pushStack(this_scope);


		struct var *newvar = findvar_inscope((yyvsp[(1) - (9)].sval),this_scope);
		char buff[20];
		
		sprintf(buff,"move %s, $v0", newvar->which_reg);

		datafile = fopen("mips.txt", "a+");
		fprintf(datafile, "\t%s\n",buff);
		fclose(datafile);
		}
		else
		{
			char error[40] = "id not defined ...";
			yyerror(error);
			YYERROR;
		}
	}
	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 931 "code.y"
    {
		int i = 0;
		for (; i < func_count; i++)
		{
			if (strcmp(fun_names[i].name, (yyvsp[(1) - (11)].sval)) == 0)
				break;
		}

		if (strcmp(fun_names[i].type, "void") == 0)
			strcpy((yyval.sval), "void");
		else
			strcpy((yyval.sval), "int");

;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 947 "code.y"
    {
	if(founded_func_num != 0 )
	{
		char error[50] = "wrong number of arguments for function  ...";
				strcat(error,founded_func);
				yyerror(error);
				YYERROR;

	}
	(yyval.ival)=0; printf("no args passed\n");
	;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 958 "code.y"
    {
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
	if(isnumber((yyvsp[(1) - (7)].sval)))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",atoi((yyvsp[(1) - (7)].sval)));
		else if(isalpha((yyvsp[(1) - (7)].sval)[0]))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",(yyvsp[(1) - (7)].sval)[0]);
		else
		sprintf(buff,"add %s,%s,%s","$a0","$zero",(yyvsp[(1) - (7)].sval));
		fprintf(datafile, "\t%s\n",buff);

		//a1
		if(isnumber((yyvsp[(3) - (7)].sval)))
			sprintf(buff,"addi %s,%s,%d","$a1","$zero",atoi((yyvsp[(3) - (7)].sval)));
			else if(isalpha((yyvsp[(3) - (7)].sval)[0]))
			sprintf(buff,"addi %s,%s,%d","$a1","$zero",(yyvsp[(3) - (7)].sval)[0]);
			else
			sprintf(buff,"add %s,%s,%s","$a1","$zero",(yyvsp[(3) - (7)].sval));
			fprintf(datafile, "\t%s\n",buff);

			//a2
			if(isnumber((yyvsp[(5) - (7)].sval)))
				sprintf(buff,"addi %s,%s,%d","$a2","$zero",atoi((yyvsp[(5) - (7)].sval)));
				else if(isalpha((yyvsp[(5) - (7)].sval)[0]))
				sprintf(buff,"addi %s,%s,%d","$a2","$zero",(yyvsp[(5) - (7)].sval)[0]);
				else
				sprintf(buff,"add %s,%s,%s","$a2","$zero",(yyvsp[(5) - (7)].sval));
				fprintf(datafile, "\t%s\n",buff);

				//a3
				if(isnumber((yyvsp[(7) - (7)].sval)))
					sprintf(buff,"addi %s,%s,%d","$a3","$zero",atoi((yyvsp[(7) - (7)].sval)));
					else if(isalpha((yyvsp[(7) - (7)].sval)[0]))
					sprintf(buff,"addi %s,%s,%d","$a3","$zero",(yyvsp[(7) - (7)].sval)[0]);
					else
					sprintf(buff,"add %s,%s,%s","$a3","$zero",(yyvsp[(7) - (7)].sval));
					fprintf(datafile, "\t%s\n",buff);


	fclose(datafile);

	(yyval.ival)=4; printf("4 args passed\n");
;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1011 "code.y"
    {
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
	if(isnumber((yyvsp[(1) - (5)].sval)))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",atoi((yyvsp[(1) - (5)].sval)));
		else if(isalpha((yyvsp[(1) - (5)].sval)[0]))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",(yyvsp[(1) - (5)].sval)[0]);
		else
		sprintf(buff,"add %s,%s,%s","$a0","$zero",(yyvsp[(1) - (5)].sval));
		fprintf(datafile, "\t%s\n",buff);

		//a1
		if(isnumber((yyvsp[(3) - (5)].sval)))
			sprintf(buff,"addi %s,%s,%d","$a1","$zero",atoi((yyvsp[(3) - (5)].sval)));
			else if(isalpha((yyvsp[(3) - (5)].sval)[0]))
			sprintf(buff,"addi %s,%s,%d","$a1","$zero",(yyvsp[(3) - (5)].sval)[0]);
			else
			sprintf(buff,"add %s,%s,%s","$a1","$zero",(yyvsp[(3) - (5)].sval));
			fprintf(datafile, "\t%s\n",buff);

			//a2
			if(isnumber((yyvsp[(5) - (5)].sval)))
				sprintf(buff,"addi %s,%s,%d","$a2","$zero",atoi((yyvsp[(5) - (5)].sval)));
				else if(isalpha((yyvsp[(5) - (5)].sval)[0]))
				sprintf(buff,"addi %s,%s,%d","$a2","$zero",(yyvsp[(5) - (5)].sval)[0]);
				else
				sprintf(buff,"add %s,%s,%s","$a2","$zero",(yyvsp[(5) - (5)].sval));
				fprintf(datafile, "\t%s\n",buff);



	fclose(datafile);

	(yyval.ival)=3; printf("3 args passed\n");
;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1056 "code.y"
    {
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
	if(isnumber((yyvsp[(1) - (3)].sval)))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",atoi((yyvsp[(1) - (3)].sval)));
		else if(isalpha((yyvsp[(1) - (3)].sval)[0]))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",(yyvsp[(1) - (3)].sval)[0]);
		else
		sprintf(buff,"add %s,%s,%s","$a0","$zero",(yyvsp[(1) - (3)].sval));
		fprintf(datafile, "\t%s\n",buff);

		//a1
		if(isnumber((yyvsp[(3) - (3)].sval)))
			sprintf(buff,"addi %s,%s,%d","$a1","$zero",atoi((yyvsp[(3) - (3)].sval)));
			else if(isalpha((yyvsp[(3) - (3)].sval)[0]))
			sprintf(buff,"addi %s,%s,%d","$a1","$zero",(yyvsp[(3) - (3)].sval)[0]);
			else
			sprintf(buff,"add %s,%s,%s","$a1","$zero",(yyvsp[(3) - (3)].sval));
			fprintf(datafile, "\t%s\n",buff);





	fclose(datafile);

	(yyval.ival)=2; printf("2 args passed\n");
;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1094 "code.y"
    {
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
	if(isnumber((yyvsp[(1) - (1)].sval)))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",atoi((yyvsp[(1) - (1)].sval)));
		else if(isalpha((yyvsp[(1) - (1)].sval)[0]))
		sprintf(buff,"addi %s,%s,%d","$a0","$zero",(yyvsp[(1) - (1)].sval)[0]);
		else
		sprintf(buff,"add %s,%s,%s","$a0","$zero",(yyvsp[(1) - (1)].sval));
		fprintf(datafile, "\t%s\n",buff);



	fclose(datafile);

	(yyval.ival)=1; printf("1 args passed\n");
;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1122 "code.y"
    {
	printf("return\n");
	if (isnumber((yyvsp[(2) - (3)].sval)) || isalpha((yyvsp[(2) - (3)].sval)[0]))
	{
		char num[5];
		itoa(GetFreeRegister('t'), num,5);
		char buffer[10] = {'$','t'};
		strcat(buffer, num);
		char buff[50];
		if (isalpha((yyvsp[(2) - (3)].sval)[0]))
			sprintf(buff,"addi %s, $zero, %d",buffer,(yyvsp[(2) - (3)].sval)[0]);
		else
			sprintf(buff,"addi %s, $zero, %s",buffer,(yyvsp[(2) - (3)].sval));
		datafile = fopen("mips.txt", "a+");
		fprintf(datafile, "\t%s\n",buff);
		fclose(datafile);

		sprintf(buff,"move $v0, %s",buffer);
		freereg(buffer);
		datafile = fopen("mips.txt", "a+");
		fprintf(datafile, "\t%s\n",buff);
		fclose(datafile);
				
		
		sprintf(return_result,"%s", (yyvsp[(2) - (3)].sval));


	}
	else{
	char buff[20];
	sprintf(buff,"move $v0, %s",(yyvsp[(2) - (3)].sval));

	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\t%s\n",buff);
	
	char fscope[30];
	strcpy(fscope, popStack());
	pushStack(fscope);

	struct var* res_var = findvar_withreg((yyvsp[(2) - (3)].sval),current_func);
	printf("jeeee\n%sjeeee\n", (yyvsp[(2) - (3)].sval));
	//printf("jeeee\n%s %d %s jeeee\n", res_var->name,  res_var->intchar_union.value_int, res_var->type);
 	/*if ( strcmp(res_var->type, "int") == 0 )
			sprintf(return_result, "%s", res_var->intchar_union.value_int);
	else
			sprintf(return_result, "%c", res_var->intchar_union.value_char);
	

	
	
	sprintf(return_result,"%d", res_var->intchar_union.value_int);
	*/
	fclose(datafile);
	}
;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1178 "code.y"
    {
	printf("equality condition\n");
	if (isnumber((yyvsp[(1) - (3)].sval)) || isalpha((yyvsp[(1) - (3)].sval)[0]) || isnumber((yyvsp[(3) - (3)].sval)) || isalpha((yyvsp[(3) - (3)].sval)[0]))
	{
		char buffer1[10] = {'$','t'};
		char buffer2[10] = {'$','t'};
		char buffer3[10] = {'$', 't'};
		int new_buffer1 = 0;
		int new_buffer2 = 0;
		if (isnumber((yyvsp[(1) - (3)].sval)) || isalpha((yyvsp[(1) - (3)].sval)[0]))
		{
			new_buffer1 = 1;
		char num[5];
		itoa(GetFreeRegister('t'), num,5);

		strcat(buffer1, num);
		char buff[50];
		if (isalpha((yyvsp[(1) - (3)].sval)[0]))
			sprintf(buff,"addi %s, $zero, %d",buffer1,(yyvsp[(1) - (3)].sval)[0]);
		else
			sprintf(buff,"addi %s, $zero, %s",buffer1,(yyvsp[(1) - (3)].sval));
		datafile = fopen("mips.txt", "a+");
		fprintf(datafile, "\t%s\n",buff);
		fclose(datafile);
		}
		else
			sprintf(buffer1, "%s", (yyvsp[(1) - (3)].sval));

		if (isnumber((yyvsp[(3) - (3)].sval)) || isalpha((yyvsp[(3) - (3)].sval)[0]))
		{
			new_buffer2 = 1;
			char num[5];
			itoa(GetFreeRegister('t'), num,5);
			strcat(buffer2, num);
			char buff[50];
			if (isalpha((yyvsp[(3) - (3)].sval)[0]))
				sprintf(buff,"addi %s, $zero, %d",buffer2,(yyvsp[(3) - (3)].sval)[0]);
			else
				sprintf(buff,"addi %s, $zero, %s",buffer2,(yyvsp[(3) - (3)].sval));
			datafile = fopen("mips.txt", "a+");
			fprintf(datafile, "\t%s\n",buff);
			fclose(datafile);
		}
		else
			sprintf(buffer2, "%s", (yyvsp[(3) - (3)].sval));

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

		sprintf((yyval.sval),"%s",buffer3);
	}
	else{
	char num[5];
	itoa(GetFreeRegister('t'), num,5);
	char buffer[10] = {'$','t'};
	strcat(buffer, num);

	char buff[20];
	sprintf(buff,"sub %s,%s,%s",buffer,(yyvsp[(1) - (3)].sval),(yyvsp[(3) - (3)].sval));

	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\t%s\n",buff);
	fclose(datafile);


	sprintf((yyval.sval),"%s",buffer);

	}

;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1262 "code.y"
    {printf("notequality\n"); sprintf((yyval.sval),"%d",(yyvsp[(1) - (3)].sval) != (yyvsp[(3) - (3)].sval));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1263 "code.y"
    {
	char num[5];
	itoa(GetFreeRegister('t'), num,5);
	char buffer[10] = {'$','t'};
	strcat(buffer, num);

	printf("addition\n");
	char buff[20];
	sprintf(buff,"addi %s,%s,%s",buffer,(yyvsp[(1) - (3)].sval),(yyvsp[(3) - (3)].sval));

	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\t%s\n",buff);
	fclose(datafile);


	strcpy((yyval.sval),buffer);
;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1280 "code.y"
    {
		char num[5];
		itoa(GetFreeRegister('t'), num,5);
		char buffer[10] = {'$','t'};
		strcat(buffer, num);

		printf("subtraction\n");
		char buff[20];
		sprintf(buff,"sub %s,%s,%s",buffer,(yyvsp[(1) - (3)].sval),(yyvsp[(3) - (3)].sval));

		datafile = fopen("mips.txt", "a+");
		fprintf(datafile, "\t%s\n",buff);
		fclose(datafile);

		char buff2[10];
		sprintf(buff2,"%d",atoi((yyvsp[(1) - (3)].sval)) + atoi((yyvsp[(3) - (3)].sval)));
		strcpy((yyval.sval),buff2);

	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1299 "code.y"
    {
	printf("int literal\n");
	char buff[10];
	sprintf(buff,"%d",(yyvsp[(1) - (1)].ival));
	 strcpy((yyval.sval) , buff);
	;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1305 "code.y"
    {printf("conditional and\n");  sprintf((yyval.sval),"%d",(yyvsp[(1) - (3)].sval) && (yyvsp[(3) - (3)].sval));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1306 "code.y"
    {printf("nonditional or\n"); sprintf((yyval.sval),"%d",(yyvsp[(1) - (3)].sval) || (yyvsp[(3) - (3)].sval));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1307 "code.y"
    {printf("logical or\n"); sprintf((yyval.sval),"%d",atoi((yyvsp[(1) - (3)].sval)) | atoi((yyvsp[(3) - (3)].sval)));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1308 "code.y"
    {printf("logical and\n"); sprintf((yyval.sval),"%d",atoi((yyvsp[(1) - (3)].sval)) & atoi((yyvsp[(3) - (3)].sval)));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1309 "code.y"
    {printf("logical xor\n"); sprintf((yyval.sval),"%d",atoi((yyvsp[(1) - (3)].sval)) ^ atoi((yyvsp[(3) - (3)].sval)));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1310 "code.y"
    {printf("logical not\n"); sprintf((yyval.sval),"%d", !(yyvsp[(2) - (2)].sval));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1311 "code.y"
    {printf("parantheses\n");  sprintf((yyval.sval),"%d",(yyvsp[(2) - (3)].sval));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1312 "code.y"
    {
	printf("character literal\n");
	char buff[2];
	buff[0] = (yyvsp[(1) - (1)].cval);
	buff[1] = '\0';
	strcpy((yyval.sval),buff);
	;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1319 "code.y"
    {
	printf("id literal\n");
	if(first != NULL){
if(findvar(first,(yyvsp[(1) - (1)].sval),current_func)){

struct var *newvar = findvar(first,(yyvsp[(1) - (1)].sval),current_func);

	strcpy((yyval.sval) , newvar ->which_reg);

}
else
{
char error[30] = "no such variable exists ...";
			strcat(error, (yyvsp[(1) - (1)].sval));
			yyerror(error);
			YYERROR;

}
}
else
{
char error[30] = "no such variable exists ...";
			strcat(error, (yyvsp[(1) - (1)].sval));
			yyerror(error);
			YYERROR;
}
;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1346 "code.y"
    {printf("negative num\n"); sprintf((yyval.sval),"%d", -atoi((yyvsp[(2) - (2)].sval)));;}
    break;



/* Line 1455 of yacc.c  */
#line 3140 "code.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1349 "code.y"



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
struct var* findvar_withreg(char* reg, char* funcName)
{
	if (first == NULL)
		return NULL;
	
	for(struct var* t = first; t; t = t->next){
		if(strcmp(t->current_func,funcName)==0 && strcmp(t->which_reg, reg) == 0)
			return t;
	}
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

