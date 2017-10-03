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
    2,    2,    2,    2,    3,    3,    3,    3,    3,    8,
    8,    8,    8,    6,    6,    6,    6,    6,    6,    6,
    6,    9,    9,    9,    9,    4,    4,    4,    5,    5,
    7,    7,
};
static const YYINT yylen[] = {                            2,
    1,    3,    0,    5,    7,    3,    6,    7,    5,    8,
    2,    2,    2,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    0,    3,    3,    3,    3,    3,    3,    3,
    1,    3,    3,    3,    1,    1,    1,    3,    3,    0,
    2,    0,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    0,    0,    0,    0,   20,   21,   22,   37,    0,   11,
   36,   12,   13,    0,    0,    0,    0,    0,   35,    0,
    0,    0,    0,    0,   15,   16,   17,   18,   19,    0,
    0,    0,   14,    2,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   38,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   34,
   32,   33,    9,    0,    4,    0,    0,    0,    0,    0,
    0,    0,    8,    0,    5,    0,   41,   10,    0,   39,
};
static const YYINT yydgoto[] = {                          9,
   10,   11,   40,   29,   85,   30,   83,   21,   31,
};
static const YYINT yysindex[] = {                      -116,
  -30,  -23,   -5,  -40,  -40,  -40,   21, -116,    0,    0,
  -48,  -40,  -40,  -40,    0,    0,    0,    0,  -40,    0,
    0,    0,    0,  -96,  -40,  -40,  -99, -116,    0,   29,
  -14,   35,   73,   42,    0,    0,    0,    0,    0,  -52,
   91,   79,    0,    0,  -40,  -40,  -40,  -40,  -40, -233,
  -40,  -40,  -40,  -40,  -40, -116,  -40,    0,  -40, -246,
  -20,  -14,  -14,  -14,  -14,  -14, -116,  -14,  -14,    0,
    0,    0,    0,   85,    0,  -46,  -40, -219,  -40, -140,
   91, -116,    0,   48,    0,   20,    0,    0, -140,    0,
};
static const YYINT yyrindex[] = {                        64,
    0,    0,    0,   -1,   -1,   -1,    0,  -57,    0,    0,
    0,  -29,  -29,   55,    0,    0,    0,    0,  -29,    0,
    0,    0,    0,    0,   55,   63,    0,    1,    0,    0,
  -22,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   14,    0,    0,    0,  -39,  -39,  -39,  -39,  -39,    0,
  -39,  -39,  -39,  -39,  -39,    0,   55,    0,   -1,    0,
    0,  -16,   -9,   -3,    3,   10,  -54,   16,   22,    0,
    0,    0,    0,    0,    0,    0,   55,   33,  -29,  -10,
   36,   40,    0,    0,    0,    0,    0,    0,  -10,    0,
};
static const YYINT yygindex[] = {                         0,
   58,   32,    0,  115,    5,  129,    0,  -65,  130,
};
#define YYTABLESIZE 366
static const YYINT yytable[] = {                         19,
    3,   23,   23,   23,    3,   23,    8,   23,   59,   12,
   28,   23,   23,   23,   86,   23,   13,   23,   31,   23,
   31,   23,   31,   86,   29,   43,   29,   54,   29,   67,
   76,   30,   55,   30,   14,   30,   31,   28,   60,   28,
   77,   28,   29,   26,   82,   26,   80,   26,   40,   30,
   27,   89,   27,   23,   27,   28,   24,   23,   24,    3,
   24,   26,   25,    3,   25,   27,   25,    3,   27,   50,
   31,   51,    6,   52,   24,   56,   29,   51,   24,   52,
   25,   25,   58,   30,   51,   44,   52,   73,   88,   28,
   51,   42,   52,   90,    7,   26,   23,   23,    3,   23,
    0,   23,   27,    0,   23,   23,    0,   23,   24,   23,
    0,   26,    0,   23,   25,   51,    0,   52,   20,   22,
   23,   51,    0,   52,   78,    3,    0,   51,    0,   52,
    0,   57,    0,   51,    0,   52,   15,   16,   17,   87,
    0,   32,   33,   79,    0,    1,    0,   34,    2,    3,
    4,    5,    6,   41,   42,   23,    0,    0,    0,    7,
   35,   36,   37,   38,   39,    0,    0,   70,   71,   72,
    0,   61,    0,   75,   62,   63,   64,   65,   66,    0,
   68,   69,    0,    0,    0,   74,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   81,    0,   84,    0,    3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   23,   23,   23,   23,   23,   23,   15,   16,   17,   18,
   23,   23,   23,   23,   23,   23,    0,   31,   31,   31,
   31,    0,   31,   29,   29,   29,   29,    0,   29,   53,
   30,   30,   30,   30,    3,   30,   28,   28,   28,   28,
    0,   28,   26,   26,   26,   26,    0,   26,    0,   27,
   27,   27,   27,    0,   27,   24,   24,   24,   24,    0,
   24,   25,   25,   25,   25,    0,   25,    0,   45,   46,
   47,   48,    0,   49,   45,   46,   47,   48,    0,   49,
    0,   45,   46,   47,   48,    0,   49,   45,   46,   47,
   48,    0,   49,    0,   23,   23,   23,   23,   23,   23,
    0,    0,   23,   23,   23,   23,   23,   23,    0,    0,
    0,    0,   45,   46,   47,   48,    0,   49,   45,   46,
   47,   48,    0,   49,   45,   46,   47,   48,    0,   49,
   45,   46,   47,   48,    0,   49,
};
static const YYINT yycheck[] = {                         40,
    0,   41,   42,   43,   59,   45,  123,   47,   61,   40,
   59,   41,   42,   43,   80,   45,   40,   47,   41,   59,
   43,   32,   45,   89,   41,  125,   43,   42,   45,  263,
  277,   41,   47,   43,   40,   45,   59,   41,   91,   43,
   61,   45,   59,   41,  264,   43,   93,   45,   59,   59,
   41,   32,   43,   93,   45,   59,   41,   59,   43,   59,
   45,   59,   41,    0,   43,    8,   45,  125,   59,   41,
   93,   43,   59,   45,   59,   41,   93,   43,   58,   45,
   59,   61,   41,   93,   43,   28,   45,   56,   41,   93,
   43,   59,   45,   89,   59,   93,   42,   43,   59,   45,
   -1,   47,   93,   -1,   42,   43,   -1,   45,   93,   47,
   -1,   91,   -1,   59,   93,   43,   -1,   45,    4,    5,
    6,   43,   -1,   45,   67,  125,   -1,   43,   -1,   45,
   -1,   59,   -1,   43,   -1,   45,  277,  278,  279,   82,
   -1,   13,   14,   59,   -1,  262,   -1,   19,  265,  266,
  267,  268,  269,   25,   26,   93,   -1,   -1,   -1,  276,
  257,  258,  259,  260,  261,   -1,   -1,   53,   54,   55,
   -1,   93,   -1,   59,   45,   46,   47,   48,   49,   -1,
   51,   52,   -1,   -1,   -1,   57,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   77,   -1,   79,   -1,  264,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  270,  271,  272,  273,  274,  275,  277,  278,  279,  280,
  270,  271,  272,  273,  274,  275,   -1,  270,  271,  272,
  273,   -1,  275,  270,  271,  272,  273,   -1,  275,  274,
  270,  271,  272,  273,  264,  275,  270,  271,  272,  273,
   -1,  275,  270,  271,  272,  273,   -1,  275,   -1,  270,
  271,  272,  273,   -1,  275,  270,  271,  272,  273,   -1,
  275,  270,  271,  272,  273,   -1,  275,   -1,  270,  271,
  272,  273,   -1,  275,  270,  271,  272,  273,   -1,  275,
   -1,  270,  271,  272,  273,   -1,  275,  270,  271,  272,
  273,   -1,  275,   -1,  270,  271,  272,  273,  274,  275,
   -1,   -1,  270,  271,  272,  273,  274,  275,   -1,   -1,
   -1,   -1,  270,  271,  272,  273,   -1,  275,  270,  271,
  272,  273,   -1,  275,  270,  271,  272,  273,   -1,  275,
  270,  271,  272,  273,   -1,  275,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 281
#define YYUNDFTOKEN 293
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"' '",0,0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,
"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_BYTE","KW_SHORT","KW_LONG","KW_FLOAT",
"KW_DOUBLE","KW_IF","KW_THEN","KW_ELSE","KW_WHILE","KW_FOR","KW_READ",
"KW_RETURN","KW_PRINT","OPERATOR_LE","OPERATOR_GE","OPERATOR_EQ","OPERATOR_NE",
"OPERATOR_AND","OPERATOR_OR","TK_IDENTIFIER","LIT_INTEGER","LIT_REAL",
"LIT_CHAR","LIT_STRING","TOKEN_ERROR",0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : stmts",
"stmts : stmt ';' stmts",
"stmts :",
"stmt : TK_IDENTIFIER ':' type '=' factor",
"stmt : TK_IDENTIFIER ':' type '[' LIT_INTEGER ']' optinit",
"stmt : TK_IDENTIFIER '=' expr",
"stmt : TK_IDENTIFIER '[' expr ']' '=' expr",
"stmt : KW_IF '(' expr ')' KW_THEN stmts optelse",
"stmt : KW_WHILE '(' expr ')' stmt",
"stmt : KW_FOR '(' expr ';' expr ';' expr ')'",
"stmt : KW_READ factor",
"stmt : KW_RETURN factor",
"stmt : KW_PRINT factor",
"stmt : '{' stmts '}'",
"type : KW_BYTE",
"type : KW_SHORT",
"type : KW_LONG",
"type : KW_FLOAT",
"type : KW_DOUBLE",
"literal : LIT_INTEGER",
"literal : LIT_REAL",
"literal : LIT_CHAR",
"literal :",
"expr : expr '+' term",
"expr : expr '-' term",
"expr : expr OPERATOR_NE term",
"expr : expr OPERATOR_OR term",
"expr : expr OPERATOR_EQ term",
"expr : expr OPERATOR_LE term",
"expr : expr OPERATOR_GE term",
"expr : term",
"term : term '*' factor",
"term : term '/' factor",
"term : term OPERATOR_AND factor",
"term : factor",
"factor : literal",
"factor : LIT_STRING",
"factor : '(' expr ')'",
"optinit : literal ' ' optinit",
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
