//Feito por 
//Lauren Silva Rolan Sampaio
//Nicolas Eymael da Silva
#ifndef TAC_HEADER
#define TAC_HEADER

#include "hash.h"
#include "astree.h"
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
