//Feito por
//Lauren Silva Rolan Sampaio
//Nicolas Eymael da Silva

#include "tac.h"
#include <stdio.h>
#include <stdlib.h>

TAC *tacCreate(int type, HASH_NODE *res, HASH_NODE *op1, HASH_NODE *op2)
{
	TAC *newtac;
	newtac = (TAC*) calloc(1, sizeof(TAC));
	newtac->type = type;
	newtac->res = res;
	newtac->op1 = op1;
	newtac->op2 = op2;
	newtac->next = 0;
	newtac->prev = 0;
	return newtac;
}

TAC *tacGenerator(AST *node)
{
	int i;
	TAC *code[MAX_SONS];
	if(!node) return 0;
	
	//Gera filhos primeiro
	for(i=0; i<MAX_SONS; ++i)
		code[i] = tacGenerator(node->son[i]);
	switch(node->type)
	{
		case AST_SYMBOL: return tacCreate(TAC_SYMBOL, node->symbol, 0, 0);
		case AST_ADD: return tacJoin(tacJoin(code[0], code[1]),tacCreate(TAC_ADD, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0));
		case AST_ASS: return tacCreate(TAC_ASS, node->symbol, code[0]?code[0]->res:0, 0);
	}
	return tacJoin(tacJoin(tacJoin(code[0], code[1]), code[2]), code[3]);
}

void tacPrintBack(TAC *last)
{
	TAC *tac;
	for(tac = last; tac; tac = tac->next)
		tacPrintSingle(tac);
}

void tacPrintSingle(TAC *tac)
{
	if(!tac) return;
	fprintf(stderr, "TAC(");
	switch(tac->type)
	{
		case TAC_SYMBOL: fprintf(stderr, "TAC_SYMBOL"); break;
		case TAC_ADD: fprintf(stderr, "TAC_ADD"); break;
		case TAC_SUB: fprintf(stderr, "TAC_SUB"); break;
		case TAC_MUL: fprintf(stderr, "TAC_MUL"); break;
		case TAC_DIV: fprintf(stderr, "TAC_DIV"); break;
		case TAC_LE: fprintf(stderr, "TAC_LE"); break;
		case TAC_GE: fprintf(stderr, "TAC_GE"); break;
		default: fprintf(stderr, "UNKNOWN"); break;
	}
	if(tac->res) fprintf(stderr, ", %s", tac->res->text); else printf(stderr, ", null");
	if(tac->op1) fprintf(stderr, ", %s", tac->op1->text); else printf(stderr, ", null");
	if(tac->op2) fprintf(stderr, ", %s", tac->op2->text); else printf(stderr, ", null");
	fprintf(stderr, ")");
}

TAC *tacJoin(TAC *l1, TAC *l2)
{
	TAC *tac = l2;
	if(!l1) return l2;
	if(!l2) return l1;
	while(tac->prev) tac = tac->prev;
	tac->prev = l1;
	return l2;
}

