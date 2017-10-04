/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
	#include <stdlib.h>
	#include <stdio.h>
	int yyparse();
	int yylex();
	int yyerror(char *msg);
#line 27 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define KW_BYTE 257
#define KW_SHORT 258
#define KW_LONG 259
#define KW_FLOAT 260
#define KW_DOUBLE 261
#define KW_IF 262
#define KW_THEN 263
#define KW_ELSE 264
#define KW_WHILE 265
#define KW_FOR 266
#define KW_READ 267
#define KW_RETURN 268
#define KW_PRINT 269
#define OPERATOR_LE 270
#define OPERATOR_GE 271
#define OPERATOR_EQ 272
#define OPERATOR_NE 273
#define OPERATOR_AND 274
#define OPERATOR_OR 275
#define TK_IDENTIFIER 276
#define LIT_INTEGER 277
#define LIT_REAL 278
#define LIT_CHAR 279
#define LIT_STRING 280
#define TOKEN_ERROR 281
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    3,    3,    3,    3,    3,
    7,    7,    7,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    5,
    5,    6,    6,
};
static const YYINT yylen[] = {                            2,
    1,    3,    0,    5,    7,    3,    6,    7,    7,    5,
    8,    2,    2,    2,    3,    1,    1,    1,    1,    1,
    1,    1,    1,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    1,    1,    1,    4,    3,    0,    2,
    0,    2,    0,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1,    0,    0,    0,    0,    0,   21,   22,   23,   35,
    0,    0,   34,    0,    0,    0,    0,    0,   16,   17,
   18,   19,   20,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   15,    2,    0,    0,    0,
    0,   38,    0,    0,    0,    0,    0,    0,    0,    0,
   26,   27,    0,    0,    0,    0,    0,   10,    0,   37,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    9,    0,    5,    0,    8,   42,   11,   40,
};
static const YYINT yydgoto[] = {                         10,
   11,   12,   34,   22,   93,   91,   23,
};
static const YYINT yysindex[] = {                       -35,
  -15,   -5,    4,  -40,  -40,  -40,  -55, -155,  -35,    0,
    0,  -43,  -40,  -40,  -40,  -64,    0,    0,    0,    0,
  -40,  119,    0,  119,  119, -155,  -40,  -40,    0,    0,
    0,    0,    0,    8,  -67,  -35,  -13,   -2,   69,  -40,
    5,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,
  -40,  -54,  119,   75, -215,    0,    0, -196,  -35,  -40,
   87,    0,   49,   49,   49,   49,  127,  127,  -24,  -24,
    0,    0,  -40, -207,   17,   36,  -35,    0,   93,    0,
  119,  -10,  -40,   39, -180,  -40, -269,  119,  -35,  -35,
    0,   12,    0, -269,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                        86,
    0,    0,    0,  101,  101,  101,    0,    0,  -27,    0,
    0,    0,   21,   21,  101,  -28,    0,    0,    0,    0,
   21,   31,    0,   38,   41,    0,  101,  112,    0,    0,
    0,    0,    0,    0,    0,    1,    0,    0,    0,  112,
    0,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
  -21,    0,   51,    0,    0,    0,    0,    0,    0,  101,
    0,    0,   40,   48,   54,   60,   -8,   15,   28,   34,
    0,    0,  101,    0,    0,    0,  -57,    0,    0,    0,
   56,    0,  101,    0,   64,   21,   65,   66,    0,   72,
    0,    0,    0,   65,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   73,  -47,  111,  390,   45,    0,  -83,
};
#define YYTABLESIZE 476
static const YYINT yytable[] = {                         21,
    3,    3,   26,   94,    8,   27,   73,   17,   18,   19,
   94,   78,   36,   36,   36,   36,   36,   50,   36,   39,
   39,   39,   51,   39,   13,   39,   40,   58,   50,   48,
   36,   49,   28,   51,   14,   28,   74,   39,   59,   50,
   48,   95,   49,   15,   51,   62,   50,   48,   55,   49,
   28,   51,   97,   50,   48,   29,   49,   56,   51,    3,
   76,   39,   39,   39,   36,   39,   77,   39,   24,   82,
   24,   39,   24,   29,   25,   84,   25,   83,   25,   89,
   32,   35,   87,   90,   28,    3,   24,    9,   33,   12,
   50,   48,   25,   49,   31,   51,   13,    3,   32,   14,
   30,   29,   30,   31,   32,   33,   33,   29,   57,    6,
   50,   48,   31,   49,    4,   51,   50,   48,   30,   49,
   24,   51,   43,   41,    7,    3,   25,   60,   50,   48,
    3,   49,   32,   51,   50,   48,   52,   49,   98,   51,
   33,    0,   39,   39,    0,   39,   31,   39,    0,   85,
    0,   86,   30,   39,   39,    0,   39,    0,   39,   39,
   50,   48,   96,   49,    0,   51,    0,   75,   50,   48,
    0,   49,    0,   51,    0,    0,    0,    0,    0,   80,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   39,    0,    3,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    1,    0,    0,    2,
    3,    4,    5,    6,    0,   16,   17,   18,   19,   20,
    7,   36,   36,   36,   36,   36,   36,    0,   39,   39,
   39,   39,   39,   39,    0,    0,   42,   43,   44,   45,
   46,   47,    0,    0,    3,   28,   28,   42,   43,   44,
   45,   46,   47,    0,   42,   43,   44,   45,   46,   47,
    0,   42,   43,   44,   45,   46,   47,    0,   29,   29,
   39,   39,   39,   39,   39,   39,    0,   24,   24,   24,
   24,   24,   24,   25,   25,   25,   25,   25,   25,   32,
   32,   32,   32,   32,   32,    0,    0,   33,   33,   33,
   33,   33,   33,   31,   31,   31,   31,   31,   31,   30,
   30,   30,   30,   30,   30,    0,    0,    0,   42,   43,
   44,   45,   46,   47,   42,   43,   44,   45,   46,   47,
    0,    0,    0,    0,    0,    0,   42,   43,   44,   45,
   46,   47,   42,   43,   44,   45,   46,   47,    0,    0,
   39,   39,   39,   39,   39,   39,    0,    0,    0,    0,
    0,   39,   39,   39,   39,   39,   39,    0,   42,   43,
   44,   45,   46,   47,   24,   25,   42,   43,   44,   45,
    0,    0,   37,   38,   39,    0,    0,    0,    0,    0,
   41,    0,    0,    0,    0,    0,   53,   54,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   61,
    0,   63,   64,   65,   66,   67,   68,   69,   70,   71,
   72,    0,    0,    0,    0,    0,    0,    0,    0,   79,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   81,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   88,    0,    0,   92,
};
static const YYINT yycheck[] = {                         40,
    0,   59,   58,   87,   40,   61,   61,  277,  278,  279,
   94,   59,   41,   42,   43,   59,   45,   42,   47,   41,
   42,   43,   47,   45,   40,   47,   91,   41,   42,   43,
   59,   45,   41,   47,   40,   91,   91,   59,   41,   42,
   43,   89,   45,   40,   47,   41,   42,   43,   41,   45,
   59,   47,   41,   42,   43,   41,   45,  125,   47,   59,
  276,   41,   42,   43,   93,   45,  263,   47,   41,  277,
   43,   93,   45,   59,   41,   40,   43,   61,   45,   41,
   41,    9,   93,  264,   93,    0,   59,  123,   41,   59,
   42,   43,   59,   45,   41,   47,   59,  125,   59,   59,
   41,  257,  258,  259,  260,  261,   59,   93,   36,   59,
   42,   43,   59,   45,   59,   47,   42,   43,   59,   45,
   93,   47,   59,   59,   59,  125,   93,   59,   42,   43,
   59,   45,   93,   47,   42,   43,   26,   45,   94,   47,
   93,   -1,   42,   43,   -1,   45,   93,   47,   -1,   77,
   -1,   59,   93,   42,   43,   -1,   45,   -1,   47,   59,
   42,   43,   90,   45,   -1,   47,   -1,   93,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   93,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   93,   -1,  264,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  262,   -1,   -1,  265,
  266,  267,  268,  269,   -1,  276,  277,  278,  279,  280,
  276,  270,  271,  272,  273,  274,  275,   -1,  270,  271,
  272,  273,  274,  275,   -1,   -1,  270,  271,  272,  273,
  274,  275,   -1,   -1,  264,  274,  275,  270,  271,  272,
  273,  274,  275,   -1,  270,  271,  272,  273,  274,  275,
   -1,  270,  271,  272,  273,  274,  275,   -1,  274,  275,
  270,  271,  272,  273,  274,  275,   -1,  270,  271,  272,
  273,  274,  275,  270,  271,  272,  273,  274,  275,  270,
  271,  272,  273,  274,  275,   -1,   -1,  270,  271,  272,
  273,  274,  275,  270,  271,  272,  273,  274,  275,  270,
  271,  272,  273,  274,  275,   -1,   -1,   -1,  270,  271,
  272,  273,  274,  275,  270,  271,  272,  273,  274,  275,
   -1,   -1,   -1,   -1,   -1,   -1,  270,  271,  272,  273,
  274,  275,  270,  271,  272,  273,  274,  275,   -1,   -1,
  270,  271,  272,  273,  274,  275,   -1,   -1,   -1,   -1,
   -1,  270,  271,  272,  273,  274,  275,   -1,  270,  271,
  272,  273,  274,  275,    5,    6,  270,  271,  272,  273,
   -1,   -1,   13,   14,   15,   -1,   -1,   -1,   -1,   -1,
   21,   -1,   -1,   -1,   -1,   -1,   27,   28,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,
   -1,   42,   43,   44,   45,   46,   47,   48,   49,   50,
   51,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   73,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   83,   -1,   -1,   86,
};
#define YYFINAL 10
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 281
#define YYUNDFTOKEN 291
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,
"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_BYTE","KW_SHORT","KW_LONG","KW_FLOAT",
"KW_DOUBLE","KW_IF","KW_THEN","KW_ELSE","KW_WHILE","KW_FOR","KW_READ",
"KW_RETURN","KW_PRINT","OPERATOR_LE","OPERATOR_GE","OPERATOR_EQ","OPERATOR_NE",
"OPERATOR_AND","OPERATOR_OR","TK_IDENTIFIER","LIT_INTEGER","LIT_REAL",
"LIT_CHAR","LIT_STRING","TOKEN_ERROR",0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : stmts",
"stmts : stmt ';' stmts",
"stmts :",
"stmt : TK_IDENTIFIER ':' type '=' expr",
"stmt : TK_IDENTIFIER ':' type '[' LIT_INTEGER ']' optinit",
"stmt : TK_IDENTIFIER '=' expr",
"stmt : TK_IDENTIFIER '[' expr ']' '=' expr",
"stmt : '(' type ')' TK_IDENTIFIER '(' ')' stmt",
"stmt : KW_IF '(' expr ')' KW_THEN stmts optelse",
"stmt : KW_WHILE '(' expr ')' stmt",
"stmt : KW_FOR '(' expr ';' expr ';' expr ')'",
"stmt : KW_READ expr",
"stmt : KW_RETURN expr",
"stmt : KW_PRINT expr",
"stmt : '{' stmts '}'",
"type : KW_BYTE",
"type : KW_SHORT",
"type : KW_LONG",
"type : KW_FLOAT",
"type : KW_DOUBLE",
"literal : LIT_INTEGER",
"literal : LIT_REAL",
"literal : LIT_CHAR",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr OPERATOR_AND expr",
"expr : expr OPERATOR_OR expr",
"expr : expr OPERATOR_NE expr",
"expr : expr OPERATOR_EQ expr",
"expr : expr OPERATOR_LE expr",
"expr : expr OPERATOR_GE expr",
"expr : literal",
"expr : LIT_STRING",
"expr : TK_IDENTIFIER",
"expr : TK_IDENTIFIER '[' expr ']'",
"expr : '(' expr ')'",
"expr :",
"optinit : literal optinit",
"optinit :",
"optelse : KW_ELSE stmts",
"optelse :",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
