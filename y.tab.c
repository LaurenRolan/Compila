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
	int yylex();
	int yyerror(char *msg);
#line 26 "y.tab.c"

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
#define LIT_DOUBLE 282
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    3,    3,    3,    3,    3,    8,
    8,    8,    8,    8,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    9,    9,    9,    9,    4,    4,    4,
    5,    5,    7,    7,
};
static const YYINT yylen[] = {                            2,
    1,    3,    0,    5,    7,    3,    6,    7,    5,    8,
    2,    2,    2,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    0,    3,    3,    3,    3,    3,    3,
    3,    1,    0,    3,    3,    3,    1,    1,    1,    3,
    3,    0,    2,    0,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    0,    0,    0,    0,   20,   22,   23,   39,    0,   21,
   11,   38,   12,   13,    0,    0,    0,    0,    0,   37,
    0,    0,    0,    0,    0,   15,   16,   17,   18,   19,
    0,    0,    0,   14,    2,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   40,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   36,   34,   35,    9,    0,    4,    0,    0,    0,    0,
    0,    0,    0,    8,    0,    5,    0,   43,   10,    0,
   41,
};
static const YYINT yydgoto[] = {                          9,
   10,   11,   41,   30,   86,   31,   84,   22,   32,
};
static const YYINT yysindex[] = {                      -113,
  -29,  -27,  -17,  -40,  -40,  -40,   66, -113,    0,    0,
  -34,  -40,  -40,  -40,    0,    0,    0,    0,  -40,    0,
    0,    0,    0,    0,  -77,  -40,  -40,  -98, -113,    0,
   45,  -33,   51,   85,   57,    0,    0,    0,    0,    0,
  -43,   97,   14,    0,    0,  -40,  -40,  -40,  -40,  -40,
 -232,  -40,  -40,  -40,  -40,  -40, -113,  -40,    0,  -40,
 -242,  -11,  -33,  -33,  -33,  -33,  -33, -113,  -33,  -33,
    0,    0,    0,    0,   91,    0,  -57,  -40, -222,  -40,
 -111,   97, -113,    0,   63,    0,   12,    0,    0, -111,
    0,
};
static const YYINT yyrindex[] = {                        52,
    0,    0,    0,   -3,   -3,   -3,    0,  -67,    0,    0,
    0,  -26,  -26,   70,    0,    0,    0,    0,  -26,    0,
    0,    0,    0,    0,    0,   70,   76,    0,    1,    0,
    0,  -19,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    3,    0,    0,    0,  -39,  -39,  -39,  -39,  -39,
    0,  -39,  -39,  -39,  -39,  -39,    0,   70,    0,   -3,
    0,    0,  -13,   -4,    2,    8,   23,  -54,   32,   38,
    0,    0,    0,    0,    0,    0,    0,   70,    6,  -26,
  -25,   10,   11,    0,    0,    0,    0,    0,    0,  -25,
    0,
};
static const YYINT yygindex[] = {                         0,
    4,   19,    0,  105,  -12,  119,    0,  -52,  126,
};
#define YYTABLESIZE 372
static const YYINT yytable[] = {                         19,
    3,   24,   24,   24,    3,   24,   24,   24,   55,    8,
   12,   28,   13,   56,   24,   24,   24,   60,   24,   24,
   24,   32,   14,   32,   29,   32,   44,   30,   87,   30,
   68,   30,   45,   42,   77,   81,   31,   87,   31,   32,
   31,   83,   29,   90,   29,   30,   29,   61,   27,   78,
   27,    3,   27,   24,   31,   24,   52,    3,   53,    3,
   29,    6,    0,   28,   44,   28,   27,   28,    7,    3,
    0,   79,   25,   32,   25,   74,   25,   91,   26,   30,
   26,   28,   26,    0,    0,   51,   88,   52,   31,   53,
   25,   57,    0,   52,   29,   53,   26,   59,    0,   52,
   27,   53,    0,   89,    0,   52,   62,   53,   21,   23,
   24,   24,   24,    0,   24,   28,   24,   24,   24,    0,
   24,    0,   24,   25,   25,    3,   26,   52,   24,   53,
   26,   33,   34,   52,    0,   53,    0,   35,    0,   52,
    0,   53,    0,   58,   42,   43,    0,    0,    1,   80,
    0,    2,    3,    4,    5,    6,   27,    0,   71,   72,
   73,    0,    7,    0,   76,   15,   16,   17,   24,    0,
   20,   63,   64,   65,   66,   67,   75,   69,   70,   36,
   37,   38,   39,   40,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   82,    0,   85,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   24,   24,   24,   24,   24,   24,   15,   16,   17,   18,
   54,   20,    0,   24,   24,   24,   24,   24,   24,    0,
   32,   32,   32,   32,    0,   32,   30,   30,   30,   30,
    0,   30,    0,    0,    3,   31,   31,   31,   31,    0,
   31,   29,   29,   29,   29,    0,   29,   27,   27,   27,
   27,    0,   27,   46,   47,   48,   49,    0,   50,    0,
    0,    0,   28,   28,   28,   28,    0,   28,    0,    0,
    0,   25,   25,   25,   25,    0,   25,   26,   26,   26,
   26,    0,   26,    0,   46,   47,   48,   49,    0,   50,
   46,   47,   48,   49,    0,   50,   46,   47,   48,   49,
    0,   50,   46,   47,   48,   49,    0,   50,    0,   24,
   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,
   24,    0,    0,    0,   46,   47,   48,   49,    0,   50,
   46,   47,   48,   49,    0,   50,   46,   47,   48,   49,
    0,   50,
};
static const YYINT yycheck[] = {                         40,
    0,   41,   42,   43,   59,   45,   32,   47,   42,  123,
   40,    8,   40,   47,   41,   42,   43,   61,   45,   59,
   47,   41,   40,   43,   59,   45,  125,   41,   81,   43,
  263,   45,   29,   59,  277,   93,   41,   90,   43,   59,
   45,  264,   41,   32,   43,   59,   45,   91,   41,   61,
   43,    0,   45,   93,   59,   59,   43,  125,   45,   59,
   59,   59,   -1,   41,   59,   43,   59,   45,   59,   59,
   -1,   68,   41,   93,   43,   57,   45,   90,   41,   93,
   43,   59,   45,   -1,   -1,   41,   83,   43,   93,   45,
   59,   41,   -1,   43,   93,   45,   59,   41,   -1,   43,
   93,   45,   -1,   41,   -1,   43,   93,   45,    4,    5,
    6,   42,   43,   -1,   45,   93,   47,   42,   43,   -1,
   45,   -1,   47,   58,   93,  125,   61,   43,   59,   45,
   93,   13,   14,   43,   -1,   45,   -1,   19,   -1,   43,
   -1,   45,   -1,   59,   26,   27,   -1,   -1,  262,   59,
   -1,  265,  266,  267,  268,  269,   91,   -1,   54,   55,
   56,   -1,  276,   -1,   60,  277,  278,  279,   93,   -1,
  282,   46,   47,   48,   49,   50,   58,   52,   53,  257,
  258,  259,  260,  261,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   78,   -1,   80,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  264,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  270,  271,  272,  273,  274,  275,  277,  278,  279,  280,
  274,  282,   -1,  270,  271,  272,  273,  274,  275,   -1,
  270,  271,  272,  273,   -1,  275,  270,  271,  272,  273,
   -1,  275,   -1,   -1,  264,  270,  271,  272,  273,   -1,
  275,  270,  271,  272,  273,   -1,  275,  270,  271,  272,
  273,   -1,  275,  270,  271,  272,  273,   -1,  275,   -1,
   -1,   -1,  270,  271,  272,  273,   -1,  275,   -1,   -1,
   -1,  270,  271,  272,  273,   -1,  275,  270,  271,  272,
  273,   -1,  275,   -1,  270,  271,  272,  273,   -1,  275,
  270,  271,  272,  273,   -1,  275,  270,  271,  272,  273,
   -1,  275,  270,  271,  272,  273,   -1,  275,   -1,  270,
  271,  272,  273,  274,  275,  270,  271,  272,  273,  274,
  275,   -1,   -1,   -1,  270,  271,  272,  273,   -1,  275,
  270,  271,  272,  273,   -1,  275,  270,  271,  272,  273,
   -1,  275,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 282
#define YYUNDFTOKEN 294
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
"LIT_CHAR","LIT_STRING","TOKEN_ERROR","LIT_DOUBLE",0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
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
"literal : LIT_DOUBLE",
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
"expr :",
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
#line 97 "parser.y"
int yyerror(char *msg)
{
	exit(3);
}
#line 342 "y.tab.c"

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
