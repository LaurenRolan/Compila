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
void makeGEQ(TAC *tac, FILE *fout);
void makeLEQ(TAC *tac, FILE *fout);
void makeAss(TAC *tac, FILE *fout);
void makePrint(TAC *tac, FILE *fout);
void makeRead(TAC *tac, FILE *fout);
void makeWhile(TAC *tac, FILE *fout);
void makeIfElse(TAC *tac, FILE *fout);
//Fim dos protótipos internos
void asmGenerator (char *filename, TAC *code)
{
	FILE *fout;
	TAC *tac = code;
	if(!(fout = fopen(filename,, 'w')))
	{
		fprintf(stderr, "Unable to open ASM file.\n");
		exit(5);
	}
	for(tac = code; tac; tac = tac->next)
	{
		switch(tac->type)
		{
			case TAC_ADD: makeAdd(tac, fout); break;
			case TAC_SUB: makeSub(tac, fout); break;
			case TAC_DIV: makeDiv(tac, fout); break;
			case TAC_MUL: makeMul(tac, fout); break;
			case TAC_ASS: makeAss(tac, fout); break;
			case TAC_PRINT: 
			
		}
	}
}

void makeAdd(TAC* tac, FILE *fout)
{
	//Testar se é lit + lit, lit + var ou var + var
	fprintf(fout, "\nmovq\t %s(%%rip), %%rdx\n"
		"movq\t %s(%%rip), %%rax\n"
		"addq\t %%rdx, %%rax\n", tac->op1->text, tac->op2->text); break;
}
void makeSub(TAC *tac, FILE *fout)
{
	
}

void makeMul(TAC *tac, FILE *fout)
{
	
}

void makeDiv(TAC *tac, FILE *fout)
{
	
}

void makeOR(TAC *tac, FILE *fout)	
{
	
}
void makeAND(TAC *tac, FILE *fout)
{
	
}
void makeGRE(TAC *tac, FILE *fout)
{
	
}
void makeLES(TAC *tac, FILE *fout)
{
	
}
void makeGEQ(TAC *tac, FILE *fout)
{
	
}
void makeLEQ(TAC *tac, FILE *fout)
{
	
}

void makeAss(TAC *tac, FILE *fout)
{
	
}

void makePrint(TAC *tac, FILE *fout)
{
	fprintf(fout, "\nmovq\t %s(%%rip), %%rax\n"
		"movq\t %%rax, %%rsi\n"
		"movl\t$printable, %%edi\n"
		"movl\t$0, %%eax\n"
		"call\tprintf\n", tac->res->text); break;
}

void makeRead(TAC *tac, FILE *fout)
{
	
}

void makeWhile(TAC *tac, FILE *fout)
{
	
}
void makeIfElse(TAC *tac, FILE *fout)
{
	
}
