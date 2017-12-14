#include "asma.h"
#include <stdio.h>
#include <stdlib.h>

//Protótipos internos
void makeAdd(TAC *tac, FILE *fout);
void makeSub(TAC *tac, FILE *fout);
void makeMul(TAC *tac, FILE *fout);
void makeDiv(TAC *tac, FILE *fout);
void makeAss(TAC *tac, FILE *fout);
void makeOR(TAC *tac, FILE *fout);
void makeAND(TAC *tac, FILE *fout);
void makeGRE(TAC *tac, FILE *fout);
void makeLES(TAC *tac, FILE *fout);
void makeGE(TAC *tac, FILE *fout);
void makeLE(TAC *tac, FILE *fout);
void makeNE(TAC *tac, FILE *fout);
void makeAss(TAC *tac, FILE *fout);
void makePrintASM(TAC *tac, FILE *fout);
void makeRead(TAC *tac, FILE *fout);
void makeWhileASM(TAC *tac, FILE *fout);
void makeIfElse(TAC *tac, FILE *fout);
//Fim dos protótipos internos
void asmGenerator (FILE *fout, TAC *code)
{
	TAC *tac = code;
	fprintf(stderr, "Oi, crianças. A mamãe voltou.\n");
	for(tac = code; tac; tac = tac->next)
	{
		fprintf(stderr, "Entro aqui para tac->type = %d\n", tac->type);
		switch(tac->type)
		{
			case TAC_ADD: makeAdd(tac, fout); break;
			case TAC_SUB: makeSub(tac, fout); break;
			case TAC_DIV: makeDiv(tac, fout); break;
			case TAC_MUL: makeMul(tac, fout); break;
			case TAC_AND: makeAND(tac, fout); break;
			case TAC_OR: makeOR(tac, fout); break;
			case TAC_LES: makeLES(tac, fout); break;
			case TAC_GRE: makeGRE(tac, fout); break;
			case TAC_LE: makeLE(tac, fout); break;
			case TAC_GE: makeGE(tac, fout); break;
			case TAC_NE: makeNE(tac, fout); break;
			case TAC_ASS: makeAss(tac, fout); break;
			case TAC_PRINT: makePrintASM(tac, fout); break;
			case TAC_READ: makeRead(tac, fout); break;
			case TAC_WHILE: makeWhileASM(tac, fout); break;
			case TAC_IF: makeIfElse(tac, fout); break;
			default: fprintf(fout, "Deu ruim\n");
		}
	}
	fclose(fout);
}

void makeAdd(TAC* tac, FILE *fout)
{
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//lit + lit
		fprintf(fout, "\nmovq\n$%s, %%rdx\n"
			"movq\t$%s, %%rax\n"
			"addq\t%%rdx, %%rax\n", tac->op1->text, tac->op2->text);
	if((tac->op1->type == SYMBOL_ID && tac->op2->type == SYMBOL_LIT_INT) || (tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_ID))//lit + var
		fprintf(fout, "\nmovq\t%s(%%rip), %%rax\n"
			"addq\t$%s, %%rax\n", ((tac->op1->type == SYMBOL_ID)?tac->op1->text:tac->op2->text), ((tac->op2->type == SYMBOL_LIT_INT)?tac->op2->text:tac->op1->text));
	if(tac->op1->type == SYMBOL_ID && tac->op2->type == SYMBOL_ID)//var + var
		fprintf(fout, "movq\t%s(%%rip), %%rdx\n"
			"movq\t%s(%%rip), %%rax\n"
			"addq\t%%rdx, %%rax\n", tac->op1->text, tac->op2->text);
}	
void makeSub(TAC *tac, FILE *fout)
{
	return;
}

void makeMul(TAC *tac, FILE *fout)
{
	return;
}

void makeDiv(TAC *tac, FILE *fout)
{
	return;
}

void makeOR(TAC *tac, FILE *fout)	
{
	return;
}
void makeAND(TAC *tac, FILE *fout)
{
	return;
}
void makeGRE(TAC *tac, FILE *fout)
{
	return;
}
void makeLES(TAC *tac, FILE *fout)
{
	return;
}
void makeNE(TAC *tac, FILE *fout)
{
	return;
}
void makeGE(TAC *tac, FILE *fout)
{
	return;
}
void makeLE(TAC *tac, FILE *fout)
{
	return;
}

void makeAss(TAC *tac, FILE *fout)
{
	if(tac->op1->type == SYMBOL_LIT_INT) //Se for do tipo var <- lit_int
		fprintf(fout, "movq\t$%s, %s(%%rip)\n", tac->op1->text, tac->res->text);
	if(tac->op1->type == SYMBOL_ID) //Se for do tipo var <- var
		fprintf(fout, "movq\t%s(%%rip), %%rax"
			"movq\t%%rax, %s(%%rip)", tac->op1->text, tac->res->text);
}

void makePrintASM(TAC *tac, FILE *fout)
{
	return;
}

void makeRead(TAC *tac, FILE *fout)
{
	return;
}

void makeWhileASM(TAC *tac, FILE *fout)
{
	return;
}
void makeIfElse(TAC *tac, FILE *fout)
{
	return;
}
