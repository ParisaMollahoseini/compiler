
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


/* Line 189 of yacc.c  */
#line 150 "code.tab.c"

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
     ENTER = 272,
     SPC = 273,
     VALUE_ID = 274,
     EQ = 275,
     MULTI_COMMENT = 276,
     COMMENT = 277,
     CHAR = 278,
     INT = 279,
     CONTINUE = 280,
     BREAK = 281,
     RETURN = 282,
     MAIN = 283,
     FOR = 284,
     VOID = 285,
     ELSE = 286,
     ELSEIF = 287,
     WHILE = 288,
     IF = 289,
     NUM = 290,
     ID = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 80 "code.y"

	  int ival;
		char cval;
		char sval[10];
		//char plus,min,multi;



/* Line 214 of yacc.c  */
#line 231 "code.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 243 "code.tab.c"

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
#define YYLAST   318

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

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
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    24,    26,    28,    30,    31,
      35,    45,    61,    82,    84,    86,    88,    90,    92,    94,
      96,    98,   100,   101,   108,   109,   117,   118,   125,   126,
     134,   135,   136,   141,   142,   149,   150,   151,   162,   163,
     164,   177,   178,   179,   190,   192,   193,   199,   201,   208,
     209,   217,   223,   227,   229,   234,   238,   242,   246,   250,
     254,   258,   260,   264,   268,   272,   276,   280,   283,   287,
     289
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    -1,    -1,    56,    28,    46,    28,    22,
      28,    51,    54,    23,    28,    47,    28,    58,    28,    48,
      28,    55,    53,    -1,    27,    -1,    40,    -1,    34,    -1,
      -1,    57,    28,    46,    -1,    57,    28,    46,    28,     5,
      28,    57,    28,    46,    -1,    57,    28,    46,    28,     5,
      28,    57,    28,    46,    28,     5,    28,    57,    28,    46,
      -1,    57,    28,    46,     5,    28,    57,    28,    46,    28,
       5,    28,    57,    28,    46,    28,     5,    28,    57,    28,
      46,    -1,    33,    -1,    34,    -1,    59,    -1,    66,    -1,
      68,    -1,    71,    -1,    79,    -1,    80,    -1,    27,    -1,
      -1,    34,    46,    60,    64,    26,    58,    -1,    -1,    34,
      46,    30,    50,    61,    26,    58,    -1,    -1,    33,    46,
      62,    64,    26,    58,    -1,    -1,    33,    46,    30,     4,
      63,    26,    58,    -1,    -1,    -1,     5,    46,    65,    64,
      -1,    -1,    46,    30,    50,    26,    67,    58,    -1,    -1,
      -1,    43,    69,    22,    50,    23,    47,    58,    48,    70,
      58,    -1,    -1,    -1,    44,    72,    22,    50,    23,    47,
      58,    48,    74,    77,    73,    58,    -1,    -1,    -1,    42,
      75,    22,    50,    23,    47,    58,    48,    76,    42,    -1,
      27,    -1,    -1,    41,    78,    47,    58,    48,    -1,    27,
      -1,    46,    22,    52,    23,    26,    58,    -1,    -1,    50,
       5,    50,     5,    50,     5,    50,    -1,    50,     5,    50,
       5,    50,    -1,    50,     5,    50,    -1,    50,    -1,    37,
      50,    26,    58,    -1,    50,    12,    50,    -1,    50,    11,
      50,    -1,    50,    17,    50,    -1,    50,    18,    50,    -1,
      50,    19,    50,    -1,    50,    20,    50,    -1,     3,    -1,
      50,     7,    50,    -1,    50,     6,    50,    -1,    50,     8,
      50,    -1,    50,    10,    50,    -1,    50,     9,    50,    -1,
      21,    50,    -1,    22,    50,    23,    -1,     4,    -1,    18,
      50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   135,   125,   140,   142,   142,   144,   145,
     146,   147,   148,   150,   150,   152,   153,   154,   155,   156,
     157,   158,   160,   160,   185,   185,   208,   208,   233,   233,
     257,   257,   257,   279,   279,   310,   310,   310,   312,   312,
     312,   314,   314,   314,   314,   316,   316,   316,   318,   320,
     321,   322,   323,   324,   326,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343
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
  "'*'", "'/'", "NOT", "'('", "')'", "'['", "']'", "'$'", "ENTER", "SPC",
  "VALUE_ID", "EQ", "MULTI_COMMENT", "COMMENT", "CHAR", "INT", "CONTINUE",
  "BREAK", "RETURN", "MAIN", "FOR", "VOID", "ELSE", "ELSEIF", "WHILE",
  "IF", "NUM", "ID", "'{'", "'}'", "$accept", "EXP", "PARAMS", "ARGS_IN",
  "PROGRAM", "$@1", "$@2", "FTYPE", "VTYPE", "STMTS", "DECLARE_STMT",
  "$@3", "$@4", "$@5", "$@6", "IDS", "$@7", "ASSIGN_STMT", "$@8",
  "WHILE_STMT", "$@9", "$@10", "IF_STMT", "$@11", "$@12", "ELSEIF_STMT",
  "$@13", "$@14", "ELSE_STMT", "$@15", "FUNC_CALL", "RETURN_STMT", 0
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
     285,   286,   287,   288,   289,   290,   291,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    54,    55,    53,    53,    56,    56,    51,    51,
      51,    51,    51,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    60,    59,    61,    59,    62,    59,    63,    59,
      64,    65,    64,    67,    66,    69,    70,    68,    72,    73,
      71,    75,    76,    74,    74,    78,    77,    77,    79,    52,
      52,    52,    52,    52,    80,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,    18,     1,     1,     1,     0,     3,
       9,    15,    20,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     0,     7,     0,     6,     0,     7,
       0,     0,     4,     0,     6,     0,     0,    10,     0,     0,
      12,     0,     0,    10,     1,     0,     5,     1,     6,     0,
       7,     5,     3,     1,     4,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     2,     3,     1,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     7,     6,     0,     0,     1,     0,     0,     0,
       0,     8,    13,    14,     2,     0,     0,     0,     0,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,    35,    38,     0,     0,    15,    16,    17,
      18,    19,    20,     0,     0,    26,    22,    61,    69,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       0,    30,     0,    30,    70,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     0,    10,    28,     0,     0,
      24,     0,    68,    63,    62,    64,    66,    65,    56,    55,
      57,    58,    59,    60,    54,     0,     0,     0,     0,    33,
       3,     0,     0,     0,    31,     0,     0,     0,     0,     0,
      52,     0,     0,     0,     0,     0,     0,    30,    27,     0,
      23,     0,     0,     0,    48,    34,     4,     0,     0,    29,
      32,    25,     0,     0,    51,     0,     0,    36,     0,     0,
       0,     0,     0,    44,    41,     0,    50,     0,    11,    37,
       0,    47,    45,    39,     0,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,     0,     0,    46,    12,     0,
      42,     0,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    52,    14,    82,     4,    16,   123,     5,    15,    36,
      37,    63,   116,    61,   113,    89,   127,    38,   122,    39,
      53,   152,    40,    54,   167,   155,   160,   181,   163,   166,
      41,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -69
static const yytype_int16 yypact[] =
{
       8,   -69,   -69,   -69,    16,   -22,   -69,   -28,     5,    19,
      23,   -21,   -69,   -69,   -69,    29,    37,    21,    40,     6,
      15,    42,    77,    55,   -21,    62,   106,    63,   -21,   -69,
      46,    47,    34,   -69,   -69,   -13,    66,   -69,   -69,   -69,
     -69,   -69,   -69,    61,    81,    80,    82,   -69,   -69,    34,
      34,    34,    69,    89,    91,    34,    34,    67,    88,    79,
     122,   123,    34,   123,    20,   -69,   147,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,   106,    34,
      34,   220,   104,   112,   107,   129,   108,   -69,    95,   111,
     267,   116,   -69,   281,   294,   298,    86,    54,    26,    26,
      20,    20,   -69,   -69,   -69,   165,   183,    34,   119,   -69,
     -69,   118,   142,   125,   -69,   106,   134,   106,   101,   114,
     236,   106,   106,     8,   -21,   135,   106,   123,   -69,   106,
     -69,   106,   106,    34,   -69,   -69,   -69,   140,   -21,   -69,
     -69,   -69,   121,   130,   252,   133,   152,   -69,   -12,    34,
     153,   141,   106,   -69,   -69,     9,   267,   157,   -69,   -69,
     164,   -69,   -69,   -69,   168,    34,   150,   106,   -21,   201,
     106,   -69,   170,   158,   151,   169,   106,   -69,   -69,   156,
     -69,   172,   -69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -48,   -69,   -69,    93,   -69,   -69,   -69,   -24,   -68,
     -69,   -69,   -69,   -69,   -69,   -58,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      27,    64,    65,    66,    44,    91,     7,    81,    83,    55,
     104,    21,    12,    13,    90,   153,     6,    56,     8,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     154,   105,   106,     9,    22,     1,   161,    47,    48,    76,
      77,    10,     2,    74,    75,    76,    77,   128,     3,   130,
     162,    11,    49,   134,   135,    50,    51,    17,   139,   120,
      18,   141,    23,   142,   143,    72,    73,    19,    20,   140,
      24,    74,    75,    76,    77,    67,    68,    69,    70,    71,
      72,    73,    25,    26,   159,   144,    74,    75,    76,    77,
      28,    43,    45,    46,    57,    78,    71,    72,    73,   171,
     137,   156,   174,    74,    75,    76,    77,    58,   179,    59,
      60,    79,    62,    80,   146,    84,    85,   169,    67,    68,
      69,    70,    71,    72,    73,    86,    87,   108,    88,    74,
      75,    76,    77,    29,   111,   110,   112,   115,   109,    30,
      31,   114,   117,    32,   172,   121,   124,   125,   131,    33,
      34,   126,    35,    67,    68,    69,    70,    71,    72,    73,
     129,   132,   164,   138,    74,    75,    76,    77,   145,   147,
      92,    67,    68,    69,    70,    71,    72,    73,   148,   150,
     151,   157,    74,    75,    76,    77,   165,   158,   118,    67,
      68,    69,    70,    71,    72,    73,   168,   170,   175,   177,
      74,    75,    76,    77,   180,   176,   119,    67,    68,    69,
      70,    71,    72,    73,   182,   178,   136,     0,    74,    75,
      76,    77,     0,     0,   173,   107,    67,    68,    69,    70,
      71,    72,    73,     0,     0,     0,     0,    74,    75,    76,
      77,   133,    67,    68,    69,    70,    71,    72,    73,     0,
       0,     0,     0,    74,    75,    76,    77,   149,    67,    68,
      69,    70,    71,    72,    73,     0,     0,     0,     0,    74,
      75,    76,    77,    67,    68,    69,    70,    71,    72,    73,
       0,     0,     0,     0,    74,    75,    76,    77,    68,    69,
      70,    71,    72,    73,     0,     0,     0,     0,    74,    75,
      76,    77,    69,    70,    71,    72,    73,    70,    71,    72,
      73,    74,    75,    76,    77,    74,    75,    76,    77
};

static const yytype_int16 yycheck[] =
{
      24,    49,    50,    51,    28,    63,    28,    55,    56,    22,
      78,     5,    33,    34,    62,    27,     0,    30,    46,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      42,    79,    80,    28,    28,    27,    27,     3,     4,    19,
      20,    22,    34,    17,    18,    19,    20,   115,    40,   117,
      41,    28,    18,   121,   122,    21,    22,    28,   126,   107,
      23,   129,    47,   131,   132,    11,    12,    46,    28,   127,
      28,    17,    18,    19,    20,     6,     7,     8,     9,    10,
      11,    12,     5,    28,   152,   133,    17,    18,    19,    20,
      28,    28,    46,    46,    28,    26,    10,    11,    12,   167,
     124,   149,   170,    17,    18,    19,    20,    46,   176,    28,
      30,    22,    30,    22,   138,    48,    28,   165,     6,     7,
       8,     9,    10,    11,    12,    46,     4,    23,     5,    17,
      18,    19,    20,    27,     5,    28,    28,    26,    26,    33,
      34,    46,    26,    37,   168,    26,    28,     5,    47,    43,
      44,    26,    46,     6,     7,     8,     9,    10,    11,    12,
      26,    47,     5,    28,    17,    18,    19,    20,    28,    48,
      23,     6,     7,     8,     9,    10,    11,    12,    48,    46,
      28,    28,    17,    18,    19,    20,    22,    46,    23,     6,
       7,     8,     9,    10,    11,    12,    28,    47,    28,    48,
      17,    18,    19,    20,    48,    47,    23,     6,     7,     8,
       9,    10,    11,    12,    42,    46,   123,    -1,    17,    18,
      19,    20,    -1,    -1,    23,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,     7,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,     8,     9,    10,    11,    12,     9,    10,    11,
      12,    17,    18,    19,    20,    17,    18,    19,    20
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    34,    40,    53,    56,     0,    28,    46,    28,
      22,    28,    33,    34,    51,    57,    54,    28,    23,    46,
      28,     5,    28,    47,    28,     5,    28,    57,    28,    27,
      33,    34,    37,    43,    44,    46,    58,    59,    66,    68,
      71,    79,    80,    28,    57,    46,    46,     3,     4,    18,
      21,    22,    50,    69,    72,    22,    30,    28,    46,    28,
      30,    62,    30,    60,    50,    50,    50,     6,     7,     8,
       9,    10,    11,    12,    17,    18,    19,    20,    26,    22,
      22,    50,    52,    50,    48,    28,    46,     4,     5,    64,
      50,    64,    23,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    58,    50,    50,     5,    23,    26,
      28,     5,    28,    63,    46,    26,    61,    26,    23,    23,
      50,    26,    67,    55,    28,     5,    26,    65,    58,    26,
      58,    47,    47,     5,    58,    58,    53,    57,    28,    58,
      64,    58,    58,    58,    50,    28,    57,    48,    48,     5,
      46,    28,    70,    27,    42,    74,    50,    28,    46,    58,
      75,    27,    41,    77,     5,    22,    78,    73,    28,    50,
      47,    58,    57,    23,    58,    28,    47,    48,    46,    58,
      48,    76,    42
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
#line 126 "code.y"
    {
	 printf("see function : %s\n",(yyvsp[(3) - (7)].sval));

	 datafile = fopen("mips.txt", "a+");
	 fprintf(datafile, "%s:\n", (yyvsp[(3) - (7)].sval));
	 fclose(datafile);
	 strcpy(current_func,(yyvsp[(3) - (7)].sval));
	 fun_names[func_count].num = (yyvsp[(7) - (7)].ival);
	 strcpy(fun_names[func_count++].name,current_func);
		;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 135 "code.y"
    {

		vardelete(&first,&last,current_func);
		printf("delete variables after function\n");
	;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 144 "code.y"
    {(yyval.ival) = 0; printf("no parameters\n");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 145 "code.y"
    {(yyval.ival) = 1; printf("1 parameters\n");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 146 "code.y"
    {(yyval.ival) = 2; printf("2 parameters\n");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 147 "code.y"
    {(yyval.ival) = 3; printf("3 parameters\n");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 148 "code.y"
    {(yyval.ival) = 4; printf("4 parameters\n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 160 "code.y"
    {
	if(!findvar(first,(yyvsp[(2) - (2)].sval),current_func)){
		printf("declare %s %s\n",(yyvsp[(1) - (2)].sval),(yyvsp[(2) - (2)].sval));

		strcpy(currtype,(yyvsp[(1) - (2)].sval));
	struct var *newvar = addvar(&first, &last,(yyvsp[(2) - (2)].sval), (yyvsp[(1) - (2)].sval));
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
				strcat(error, (yyvsp[(2) - (2)].sval));
				yyerror(error);
				YYERROR;
}
;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 185 "code.y"
    {
	if(!findvar(first,(yyvsp[(2) - (4)].sval),current_func)){
		printf("declare and assign int %s = %s\n",(yyvsp[(2) - (4)].sval),(yyvsp[(4) - (4)].ival));
	struct var *newvar = addvar(&first, &last,(yyvsp[(2) - (4)].sval), (yyvsp[(1) - (4)].sval));
	strcpy(newvar -> current_func ,current_func);

	char buffer[10];
	itoa(GetFreeRegister('t'),buffer,10);
	strcpy(newvar -> which_reg , strcat("$t",buffer));

	newvar -> intchar_union.value_int = (yyvsp[(4) - (4)].ival);
	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
	fclose(datafile);
}
else
{
	char error[30] = "replicate variable ";
				strcat(error, (yyvsp[(2) - (4)].sval));
				yyerror(error);
				YYERROR;
}
;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 208 "code.y"
    {
	if(!findvar(first,(yyvsp[(2) - (2)].sval),current_func)){
		printf("declare %s %s\n",(yyvsp[(1) - (2)].sval),(yyvsp[(2) - (2)].sval));

		strcpy(currtype,(yyvsp[(1) - (2)].sval));
	struct var *newvar = addvar(&first, &last,(yyvsp[(2) - (2)].sval), (yyvsp[(1) - (2)].sval));
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
				strcat(error, (yyvsp[(2) - (2)].sval));
				yyerror(error);
				YYERROR;
}
;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 233 "code.y"
    {
	if(!findvar(first,(yyvsp[(2) - (4)].sval),current_func)){
		printf("declare and assign char %s = %s\n",(yyvsp[(2) - (4)].sval),(yyvsp[(4) - (4)].cval));

	struct var *newvar = addvar(&first, &last,(yyvsp[(2) - (4)].sval), (yyvsp[(1) - (4)].sval));
	strcpy(newvar -> current_func ,current_func);

	char buffer[10];
	itoa(GetFreeRegister('t'),buffer,10);
	strcpy(newvar -> which_reg , strcat("$t",buffer));

	newvar -> intchar_union.value_char = (yyvsp[(4) - (4)].cval);
	datafile = fopen("mips.txt", "a+");
	fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,0);
	fclose(datafile);
}
else
{
	char error[30] = "replicate variable ";
				strcat(error, (yyvsp[(2) - (4)].sval));
				yyerror(error);
				YYERROR;
};}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 257 "code.y"
    {
	if(!findvar(first,(yyvsp[(2) - (2)].sval),current_func)){
		printf("declare more id %s %s\n",currtype,(yyvsp[(2) - (2)].sval));
	struct var *newvar = addvar(&first, &last,(yyvsp[(2) - (2)].sval), currtype);
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
				strcat(error, (yyvsp[(2) - (2)].sval));
				yyerror(error);
				YYERROR;

};}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 279 "code.y"
    {
	if(findvar(first,(yyvsp[(1) - (4)].sval),current_func)){
		printf("assign  %s = %s\n",(yyvsp[(1) - (4)].sval),(yyvsp[(3) - (4)].ival));
	struct var *newvar = findvar(first,(yyvsp[(1) - (4)].sval),current_func);
		datafile = fopen("mips.txt", "a+");
	if(strcmp(newvar -> type ,"char")==0)
	{
		newvar -> intchar_union.value_char = (yyvsp[(3) - (4)].ival);
		fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_int);

	}
	else
	{
		newvar -> intchar_union.value_int = (yyvsp[(3) - (4)].ival);
		fprintf(datafile, "\taddi %s, $zero , %d \n", newvar->which_reg,newvar -> intchar_union.value_int);

	}

	fclose(datafile);
}
else
{
	char error[30] = "no such variable exists ...";
				strcat(error, (yyvsp[(1) - (4)].sval));
				yyerror(error);
				YYERROR;

};}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 310 "code.y"
    {printf("while begin\n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 310 "code.y"
    {printf("while end\n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 312 "code.y"
    {printf("if begin\n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 312 "code.y"
    {printf("if end\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 314 "code.y"
    {printf("elseif begin\n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 314 "code.y"
    {printf("elseif end\n");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 316 "code.y"
    {printf("else begin\n");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 316 "code.y"
    {printf("else end\n");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 320 "code.y"
    {printf("no args passed\n");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 321 "code.y"
    {(yyval.ival) =4; printf("4 args passed\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 322 "code.y"
    {(yyval.ival) =3; printf("3 args passed\n");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 323 "code.y"
    {(yyval.ival) =2; printf("2 args passed\n");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 324 "code.y"
    {printf("1 arg passed\n");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 328 "code.y"
    {printf("equality\n");  (yyval.ival)= (yyvsp[(1) - (3)].ival) == (yyvsp[(3) - (3)].ival);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 329 "code.y"
    {printf("notequality\n");  (yyval.ival)= (yyvsp[(1) - (3)].ival) != (yyvsp[(3) - (3)].ival);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 330 "code.y"
    {printf("addition\n");  (yyval.ival)= (yyvsp[(1) - (3)].ival) + (yyvsp[(3) - (3)].ival);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 331 "code.y"
    {printf("subtraction\n");  (yyval.ival)= (yyvsp[(1) - (3)].ival) - (yyvsp[(3) - (3)].ival);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 332 "code.y"
    {printf("multiply\n");  (yyval.ival)= (yyvsp[(1) - (3)].ival) * (yyvsp[(3) - (3)].ival);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 333 "code.y"
    {printf("division\n");  (yyval.ival)= (yyvsp[(1) - (3)].ival) / (yyvsp[(3) - (3)].ival);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 334 "code.y"
    {printf("int literal\n"); (yyval.ival)= (yyvsp[(1) - (1)].ival);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 335 "code.y"
    {printf("conditional and\n");  (yyval.ival)= (yyvsp[(1) - (3)].ival) && (yyvsp[(3) - (3)].ival);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 336 "code.y"
    {printf("nonditional or\n"); (yyval.ival)= (yyvsp[(1) - (3)].ival) || (yyvsp[(3) - (3)].ival);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 337 "code.y"
    {printf("logical or\n"); (yyval.ival)= (yyvsp[(1) - (3)].ival) | (yyvsp[(3) - (3)].ival);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 338 "code.y"
    {printf("logical and\n"); (yyval.ival)= (yyvsp[(1) - (3)].ival) & (yyvsp[(3) - (3)].ival);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 339 "code.y"
    {printf("logical xor\n"); (yyval.ival)= (yyvsp[(1) - (3)].ival) ^ (yyvsp[(3) - (3)].ival);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 340 "code.y"
    {printf("logical not\n"); (yyval.ival)= !(yyvsp[(2) - (2)].ival);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 341 "code.y"
    {printf("parantheses\n");  (yyval.ival)= (yyvsp[(2) - (3)].ival);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 342 "code.y"
    {printf("character literal\n"); (yyval.ival)= (yyvsp[(1) - (1)].cval);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 343 "code.y"
    {printf("negative num\n"); (yyval.ival)= -(yyvsp[(2) - (2)].ival);;}
    break;



/* Line 1455 of yacc.c  */
#line 2060 "code.tab.c"
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
#line 346 "code.y"



int main()
{
		FILE* file = fopen("input.txt","r");
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

