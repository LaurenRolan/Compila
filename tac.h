//Feito por 
//Lauren Silva Rolan Sampaio
//Nicolas Eymael da Silva
#ifndef TAC_HEADER
#define TAC_HEADER

#include "hash.h"
#include "astree.h"

#define TAC_SYMBOL 1
#define TAC_ADD 2
#define TAC_SUB 3
#define TAC_MUL 4
#define TAC_DIV 5
#define TAC_ASS 50
#define TAC_ASSV 51

//Esses eu não sei se precisa
#define TAC_LE 6
#define TAC_GE 7
#define TAC_EQ 10
#define TAC_NE 11
#define TAC_AND 12
#define TAC_OR 13
#define TAC_LES 14
#define TAC_GRE 15
#define TAC_NOT 16


typedef struct struct_tac
{
	int type;
	HASH_NODE *res;
	HASH_NODE *op1;
	HASH_NODE *op2;
	struct struct_tac *prev;
	struct struct_tac *next;
} TAC;

TAC *tacCreate(int type, HASH_NODE *res, HASH_NODE *op1, HASH_NODE *op2);
TAC *tacGenerator(AST *node);
void tacPrintBack(TAC *last);
void tacPrintSingle(TAC *tac);
TAC *tacJoin(TAC *l1, TAC *l2);

#endif
