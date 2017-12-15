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
void makeEQ(TAC *tac, FILE *fout);
void makeNOT(TAC *tac, FILE *fout);
void makeNE(TAC *tac, FILE *fout);
void makeAss(TAC *tac, FILE *fout);
void makeAssV(TAC *tac, FILE *fout);
void makePrintASM(TAC *tac, FILE *fout);
void makeRead(TAC *tac, FILE *fout);
void makeReturn(TAC *tac, FILE *fout);
/*acho que nao
void makeWhileASM(TAC *tac, FILE *fout);
void makeIfElse(TAC *tac, FILE *fout);
*/
void makeBegin(TAC *tac, FILE *fout);
void makeEnd(TAC *tac, FILE *fout);
void makeVect(TAC *tac, FILE *fout);
void makeFunc(TAC *tac, FILE *fout);
void makeJZ(TAC *tac, FILE *fout);
void makeJump(TAC *tac, FILE *fout);
void makeLABEL(TAC *tac, FILE *fout);
void makeArg(TAC *tac, FILE *fout);

//Fim dos protótipos internos
void asmGenerator (FILE *fout, TAC *code)
{
	if(!code) return;
	
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
			case TAC_EQ: makeEQ(tac, fout); break;
			case TAC_NOT: makeNOT(tac, fout); break;
			case TAC_NE: makeNE(tac, fout); break;
			
			case TAC_ASS: makeAss(tac, fout); break;
			case TAC_ASSV: makeAssV(tac, fout); break;
			
			case TAC_PRINT: makePrintASM(tac, fout); break;
			case TAC_READ: makeRead(tac, fout); break;
			case TAC_RETURN: makeReturn(tac, fout); break;
			/* acho que nao
			case TAC_WHILE: makeWhileASM(tac, fout); break;
			case TAC_IF: makeIfElse(tac, fout); break;
			*/
			case TAC_BEGIN: makeBegin(tac, fout); break;
			case TAC_END: makeEnd(tac, fout); break;
			case TAC_VECT: makeVect(tac, fout); break;
			case TAC_FUNC: makeFunc(tac, fout); break;
			
			case TAC_JZ: makeJZ(tac, fout); break;
			case TAC_JMP: makeJump(tac, fout); break;
			case TAC_LABEL: makeLABEL(tac, fout); break;
			case TAC_ARG: makeArg(tac, fout); break;
			default: fprintf(fout, "Deu ruim\n");
		}
	}
	fclose(fout);
}

void makeAdd(TAC* tac, FILE *fout)
{
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//lit + lit
		fprintf(fout, "\nmovq\t$%s, %%rdx\n"
			"movq\t$%s, %%rax\n"
			"addq\t%%rdx, %%rax\n", tac->op1->text, tac->op2->text);
	else if((tac->op1->type != SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT) || (tac->op1->type == SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT))//lit + var
		fprintf(fout, "\nmovq\t%s(%%rip), %%rax\n"
			"addq\t$%s, %%rax\n", ((tac->op1->type != SYMBOL_LIT_INT)?tac->op1->text:tac->op2->text), ((tac->op2->type == SYMBOL_LIT_INT)?tac->op2->text:tac->op1->text));
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//var + var
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
		fprintf(fout, "\nmovq\t$%s, %s(%%rip)\n", tac->op1->text, tac->res->text);
	else if(tac->op1->type != SYMBOL_LIT_INT) //Se for do tipo var <- var
		fprintf(fout, "\nmovq\t%s(%%rip), %%rax\n"
			"movq\t%%rax, %s(%%rip)\n", tac->op1->text, tac->res->text);
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

void makeBegin(TAC *tac, FILE *fout)
{
	return;
}
void makeEnd(TAC *tac, FILE *fout)
{
	return;
}
void makeVect(TAC *tac, FILE *fout)
{
	return;
}
void makeFunc(TAC *tac, FILE *fout)
{
	return;
}
void makeJZ(TAC *tac, FILE *fout)
{
	return;
}
void makeJump(TAC *tac, FILE *fout)
{
	return;
}
void makeLABEL(TAC *tac, FILE *fout)
{
	return;
}
void makeArg(TAC *tac, FILE *fout)
{
	return;
}
void makeEQ(TAC *tac, FILE *fout)
{
	return;
}
void makeNOT(TAC *tac, FILE *fout)
{
	return;
}
void makeAssV(TAC *tac, FILE *fout)
{
	return;
}
void makeReturn(TAC *tac, FILE *fout)
{
	return;
}
