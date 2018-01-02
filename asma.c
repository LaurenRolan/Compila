#include "asma.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorySerialNumber = 2;  //variavel global pra gerar labels internas

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
void makeAssV(TAC *tac, FILE *fout);
void makePrintASM(TAC *tac, FILE *fout);
void makeRead(TAC *tac, FILE *fout);
void makeReturn(TAC *tac, FILE *fout);

/*
void makeWhileASM(TAC *tac, FILE *fout);
void makeIfElse(TAC *tac, FILE *fout);
*/
void makeBegin(TAC *tac, FILE *fout);
void makeEnd(TAC *tac, FILE *fout);
void makeVect(TAC *tac, FILE *fout);
void makeFunc(TAC *tac, FILE *fout);
void makeJZ(TAC *tac, FILE *fout);
void makeJump(TAC *tac, FILE *fout);
void makeLabelASM(TAC *tac, FILE *fout);
void makeArg(TAC *tac, FILE *fout, AST *node);

//Fim dos protótipos internos
void asmGenerator (FILE *fout, TAC *code, AST *node)
{
	if(!code) return;
	
	TAC *tac = code;
	
	///////////// INICIALIZACOES
	fprintf(fout, "### VARIABLES ###\n");
	astDeclaration(node, fout);
	hashToAsm(fout);
	fprintf(fout, "\n\n### CÓDIGO ###\n");
	///////////////////////////////////
	
	for(tac = code; tac; tac = tac->next)
	{
		switch(tac->type)
		{
			case TAC_ADD: makeAdd(tac, fout); break;
			case TAC_SUB: makeSub(tac, fout); break;
			case TAC_DIV: makeDiv(tac, fout); break;
			case TAC_MUL: makeMul(tac, fout); break;
			
			case TAC_AND: makeAND(tac, fout); break;
			case TAC_OR: makeOR(tac, fout); break;
			
			//OBS: o assembly de cada uma dessas funcoes logicas está complementado
			//ou seja...no TAC_GREATER o assembly está como LESS||EQUAL
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
			case TAC_LABEL: makeLabelASM(tac, fout); break;
			case TAC_ARG: makeArg(tac, fout, node); break;
			default: fprintf(fout, "\n");
		}
	}
	fprintf(fout, "\n\n#FIM DO PROGRAMA\n");
	
	fclose(fout);
}

//Talvez os movq tenham que virar movl pros lit
void makeAdd(TAC* tac, FILE *fout)
{
	long resultado;
	fprintf(fout, "\n#TAC ADD");
	//Forma não otimizada: sem propagação de variáveis
	/*
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//lit + lit
		fprintf(fout, "\n\tmovq\t$%s, %%rdx\n"
			"\tmovq\t$%s, %%rax\n"
			"\taddq\t%%rdx, %%rax\n", tac->op1->text, tac->op2->text);
	*/
	//Forma otimizada: com propagação
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)
	{
		resultado = atoi(tac->op1->text) + atoi(tac->op2->text);
		fprintf(fout, "\n\tmovq\t$%ld, %%rax\n", resultado);
	}
	else if((tac->op1->type != SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT) || (tac->op1->type == SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT))//lit + var
				fprintf(fout, "\n\tmovq\t%s(%%rip), %%rax\n"
				"\taddq\t$%s, %%rax\n", ((tac->op1->type != SYMBOL_LIT_INT)?tac->op1->text:tac->op2->text), ((tac->op2->type == SYMBOL_LIT_INT)?tac->op2->text:tac->op1->text));
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//var + var
		fprintf(fout, "\n\tmovq\t%s(%%rip), %%rdx\n"
			"\tmovq\t%s(%%rip), %%rax\n"
			"\taddq\t%%rdx, %%rax\n", tac->op1->text, tac->op2->text);
	fprintf(fout, "\tmovq\t%%rax, %s(%%rip)\n", tac->res->text);
}	
void makeSub(TAC *tac, FILE *fout)
{
	long resultado;
	fprintf(fout, "\n#TAC SUB");
	//Forma não otimizada: sem propagação de variáveis
	/*
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//lit - lit
		fprintf(fout, "\n\tmovq\t$%s, %%rdx\n"
			"\tmovq\t$%s, %%rax\n"
			"\tsubq\t%%rax, %%rdx\n"
			"\tmovq\t%%rdx, %%rax\n", tac->op1->text, tac->op2->text);
	*/
	//Forma otimizada
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)
	{
		resultado = atoi(tac->op1->text) - atoi(tac->op2->text);
		fprintf(fout, "\n\tmovq\t$%ld, %%rax\n", resultado);
	}
	else if((tac->op1->type != SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT) || (tac->op1->type == SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT))//lit - var
				fprintf(fout, "\n\tmovq\t%s(%%rip), %%rax\n"
				"\tsubq\t$%s, %%rax\n", ((tac->op1->type != SYMBOL_LIT_INT)?tac->op1->text:tac->op2->text), ((tac->op2->type == SYMBOL_LIT_INT)?tac->op2->text:tac->op1->text));
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//var - var
		fprintf(fout, "\n\tmovq\t%s(%%rip), %%rdx\n"
			"\tmovq\t%s(%%rip), %%rax\n"
			"\tsubq\t%%rax, %%rdx\n"
			"\tmovq\t%%rdx, %%rax\n", tac->op1->text, tac->op2->text);
	fprintf(fout, "\tmovq\t%%rax, %s(%%rip)\n", tac->res->text);
}

void makeMul(TAC *tac, FILE *fout)
{
	long resultado;
	fprintf(fout, "\n#TAC MULT");
	//Forma não otimizada
	/*
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//lit * lit
		fprintf(fout, "\n\tmovq\t$%s, %%rdx\n"
			"\tmovq\t$%s, %%rax\n"
			"\timulq\t%%rdx, %%rax\n", tac->op1->text, tac->op2->text);
	*/
	//Forma otimizada
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)
	{
		resultado = atoi(tac->op1->text) * atoi(tac->op2->text);
		fprintf(fout, "\n\tmovq\t$%ld, %%rax\n", resultado);
	}
	else if((tac->op1->type != SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT) || (tac->op1->type == SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT))//lit * var
				fprintf(fout, "\n\tmovq\t%s(%%rip), %%rax\n"
				"\timulq\t$%s, %%rax\n", ((tac->op1->type != SYMBOL_LIT_INT)?tac->op1->text:tac->op2->text), ((tac->op2->type == SYMBOL_LIT_INT)?tac->op2->text:tac->op1->text));
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//var * var
		fprintf(fout, "\n\tmovq\t%s(%%rip), %%rdx\n"
			"\tmovq\t%s(%%rip), %%rax\n"
			"\timulq\t%%rdx, %%rax\n", tac->op1->text, tac->op2->text);
	fprintf(fout, "\tmovq\t%%rax, %s(%%rip)\n", tac->res->text);
}

void makeDiv(TAC *tac, FILE *fout)
{
	long resultado;
	fprintf(fout, "\n#TAC DIV");
	//Forma não otimizada
	/*
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//lit / lit
		fprintf(fout, "\n\tmovq\t$%s, %%rdx\n"
			"\tmovq\t$%s, %%rax\n"
			"\tcqto\n"
			"\tidivq\t%%rdi\n", tac->op1->text, tac->op2->text);
	*/
	//Forma otimizada
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)
	{
		resultado = atoi(tac->op1->text) / atoi(tac->op2->text);
		fprintf(fout, "\n\tmovq\t$%ld, %%rax\n", resultado);
	}
	else if((tac->op1->type != SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT) || (tac->op1->type == SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT))//lit / var
				fprintf(fout, "\n\tmovq\t%s(%%rip), %%rax\n"
				"\tmovl\t$%s, %%eax\n"
				"\tcqto\n"
				"\tidivq\t%%rdi\n", ((tac->op1->type != SYMBOL_LIT_INT)?tac->op1->text:tac->op2->text), ((tac->op2->type == SYMBOL_LIT_INT)?tac->op2->text:tac->op1->text));
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//var / var
		fprintf(fout, "\n\tmovq\t%s(%%rip), %%rdx\n"
			"\tmovq\t%s(%%rip), %%rsi\n"
			"\tcqto\n"
			"\tidivq\t%%rsi\n", tac->op1->text, tac->op2->text);
	fprintf(fout, "\tmovq\t%%rax, %s(%%rip)\n", tac->res->text);
}

void makeOR(TAC *tac, FILE *fout)	
{
	fprintf(fout, "\n#TAC OR");
	
	char nameBuffer1[256], nameBuffer2[256], nameBuffer3[256];
	sprintf(nameBuffer1, ".LogicLabel__%d", factorySerialNumber++);
	sprintf(nameBuffer2, ".LogicLabel__%d", factorySerialNumber++);
	sprintf(nameBuffer3, ".LogicLabel__%d", factorySerialNumber++);
	
	
	
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//lit + lit
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//var + lit
		fprintf(fout,	"\n\tmovq\t%s(%%rip), %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//lit + var
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
		
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//var + var
		fprintf(fout, "\n\tmovq\t%s(%%rip), %%rdx\n"
			"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
	
	fprintf(fout, 	"\ttestq\t%%rdx, %%rdx\n"
					"\tjne\t%s\n"	
					"\ttestq\t%%rax, %%rax\n"
					"\tje\t%s\n"
					"%s:\n"
					"\tmovq\t$1, %s(%%rip)\n"	// coisas mutcho lokas (resumidamente, 0 e 1 servem como booleano)
					"\tjmp\t%s\n"
					"%s:\n"
					"\tmovq\t$0, %s(%%rip)\n"
					"%s:\n", nameBuffer1, nameBuffer2, nameBuffer1, tac->res->text, nameBuffer3, nameBuffer2, tac->res->text, nameBuffer3);
}
void makeAND(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#TAC AND");
	
	char nameBuffer1[256], nameBuffer2[256];
	sprintf(nameBuffer1, ".LogicLabel__%d", factorySerialNumber++);
	sprintf(nameBuffer2, ".LogicLabel__%d", factorySerialNumber++);
	
	
	
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//lit + lit
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//var + lit
		fprintf(fout,	"\n\tmovq\t%s(%%rip), %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//lit + var
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
		
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//var + var
		fprintf(fout, "\n\tmovq\t%s(%%rip), %%rdx\n"
			"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
	
	fprintf(fout, 	"\ttestq\t%%rdx, %%rdx\n"
					"\tje\t%s\n"	
					"\ttestq\t%%rax, %%rax\n"
					"\tje\t%s\n"
					"\tmovq\t$1, %s(%%rip)\n"	// coisas mutcho lokas (resumidamente, 0 e 1 servem como booleano)
					"\tjmp\t%s\n"
					"%s:\n"
					"\tmovq\t$0, %s(%%rip)\n"
					"%s:\n", nameBuffer1, nameBuffer1,tac->res->text, nameBuffer2, nameBuffer1, tac->res->text, nameBuffer2);
}
void makeGRE(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#TAC GRE");
	
	char nameBuffer1[256], nameBuffer2[256];
	sprintf(nameBuffer1, ".LogicLabel__%d", factorySerialNumber++);
	sprintf(nameBuffer2, ".LogicLabel__%d", factorySerialNumber++);
	
	
	
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//lit + lit
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//var + lit
		fprintf(fout,	"\n\tmovq\t%s(%%rip), %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//lit + var
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
		
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//var + var
		fprintf(fout, "\n\tmovq\t%s(%%rip), %%rdx\n"
			"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
	
	fprintf(fout, 	"\tcmpq\t%%rax, %%rdx\n"
					"\tjle\t%s\n"	
					"\tmovq\t$1, %s(%%rip)\n"	// coisas mutcho lokas (resumidamente, 0 e 1 servem como booleano)
					"\tjmp\t%s\n"
					"%s:\n"
					"\tmovq\t$0, %s(%%rip)\n"
					"%s:\n", nameBuffer1, tac->res->text, nameBuffer2, nameBuffer1, tac->res->text, nameBuffer2);
}
void makeLES(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#TAC LES");
	
	char nameBuffer1[256], nameBuffer2[256];
	sprintf(nameBuffer1, ".LogicLabel__%d", factorySerialNumber++);
	sprintf(nameBuffer2, ".LogicLabel__%d", factorySerialNumber++);
	
	
	
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//lit + lit
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//var + lit
		fprintf(fout,	"\n\tmovq\t%s(%%rip), %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//lit + var
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
		
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//var + var
		fprintf(fout, "\n\tmovq\t%s(%%rip), %%rdx\n"
			"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
	
	fprintf(fout, 	"\tcmpq\t%%rax, %%rdx\n"
					"\tjge\t%s\n"	
					"\tmovq\t$1, %s(%%rip)\n"	// coisas mutcho lokas (resumidamente, 0 e 1 servem como booleano)
					"\tjmp\t%s\n"
					"%s:\n"
					"\tmovq\t$0, %s(%%rip)\n"
					"%s:\n", nameBuffer1, tac->res->text, nameBuffer2, nameBuffer1, tac->res->text, nameBuffer2);
	
}
void makeNE(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#TAC NE");
	
	char nameBuffer1[256], nameBuffer2[256];
	sprintf(nameBuffer1, ".LogicLabel__%d", factorySerialNumber++);
	sprintf(nameBuffer2, ".LogicLabel__%d", factorySerialNumber++);
	
	
	
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//lit + lit
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//var + lit
		fprintf(fout,	"\n\tmovq\t%s(%%rip), %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//lit + var
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
		
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//var + var
		fprintf(fout, "\n\tmovq\t%s(%%rip), %%rdx\n"
			"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
	
	fprintf(fout, 	"\tcmpq\t%%rax, %%rdx\n"
					"\tje\t%s\n"	
					"\tmovq\t$1, %s(%%rip)\n"	// coisas mutcho lokas (resumidamente, 0 e 1 servem como booleano)
					"\tjmp\t%s\n"
					"%s:\n"
					"\tmovq\t$0, %s(%%rip)\n"
					"%s:\n", nameBuffer1, tac->res->text, nameBuffer2, nameBuffer1, tac->res->text, nameBuffer2);
}
void makeGE(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#TAC GE");
	
	char nameBuffer1[256], nameBuffer2[256];
	sprintf(nameBuffer1, ".LogicLabel__%d", factorySerialNumber++);
	sprintf(nameBuffer2, ".LogicLabel__%d", factorySerialNumber++);
	
	
	
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//lit + lit
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//var + lit
		fprintf(fout,	"\n\tmovq\t%s(%%rip), %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//lit + var
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
		
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//var + var
		fprintf(fout, "\n\tmovq\t%s(%%rip), %%rdx\n"
			"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
	
	fprintf(fout, 	"\tcmpq\t%%rax, %%rdx\n"
					"\tjl\t%s\n"	
					"\tmovq\t$1, %s(%%rip)\n"	// coisas mutcho lokas (resumidamente, 0 e 1 servem como booleano)
					"\tjmp\t%s\n"
					"%s:\n"
					"\tmovq\t$0, %s(%%rip)\n"
					"%s:\n", nameBuffer1, tac->res->text, nameBuffer2, nameBuffer1, tac->res->text, nameBuffer2);
}
void makeLE(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#TAC LE");
	
	char nameBuffer1[256], nameBuffer2[256];
	sprintf(nameBuffer1, ".LogicLabel__%d", factorySerialNumber++);
	sprintf(nameBuffer2, ".LogicLabel__%d", factorySerialNumber++);
	
	
	
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//lit + lit
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//var + lit
		fprintf(fout,	"\n\tmovq\t%s(%%rip), %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//lit + var
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
		
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//var + var
		fprintf(fout, "\n\tmovq\t%s(%%rip), %%rdx\n"
			"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
	
	fprintf(fout, 	"\tcmpq\t%%rax, %%rdx\n"
					"\tjg\t%s\n"	
					"\tmovq\t$1, %s(%%rip)\n"	// coisas mutcho lokas (resumidamente, 0 e 1 servem como booleano)
					"\tjmp\t%s\n"
					"%s:\n"
					"\tmovq\t$0, %s(%%rip)\n"
					"%s:\n", nameBuffer1, tac->res->text, nameBuffer2, nameBuffer1, tac->res->text, nameBuffer2);
}

void makeAss(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#TAC ASS");
	if(tac->op1->type == SYMBOL_LIT_INT) //Se for do tipo var <- lit_int
		fprintf(fout, "\n\tmovq\t$%s, %s(%%rip)\n", tac->op1->text, tac->res->text);
	else if(tac->op1->type != SYMBOL_LIT_INT) //Se for do tipo var <- var
	{
		if((strncmp((tac->op1)?tac->op1->text:"", "___variavelTemporaria_", 22)) && (strncmp((tac->op2)?tac->op2->text:"", "___variavelTemporaria_", 22)))
			fprintf(fout, "\n\tmovq\t%s(%%rip), %%rax\n", tac->op1->text);
		fprintf(fout, "\n\tmovq\t%%rax, %s(%%rip)\n", tac->res->text);
	}
}

void makePrintASM(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#TAC PRINT");
	//Caso queira imprimir apenas uma string
	if(tac->res->type == SYMBOL_LIT_STRING)
		fprintf(fout, "\n\tmovl\t$string%d, %%edi\n"
			"\tcall\tputs\n", hashAddress(tac->res->text));
	//Caso queira imprimir apenas uma variável
	else
		fprintf(fout, "\n\tmovq\t%s(%%rip), %%rax\n"
			"\tmovq\t%%rax, %%rsi\n"
			"\tmovl\t$stringgod, %%edi\n"
			"\tcall	printf\n", tac->res->text);
}

void makeRead(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#TAC READ");
	fprintf(fout, "\n\tmovl\t$%s, %%esi\n"
			"\tmovl\t$stringgod, %%edi\n"
			"\tcall\t__isoc99_scanf\n", tac->res->text);
}

void makeBegin(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n\t.text\n"
		"\t.globl\t%s\n"
		"%s:\n"
		"\tpushq\t%%rbp\n"
		"\tmovq\t%%rsp, %%rbp\n", tac->res->text, tac->res->text);
}
void makeEnd(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n\tpopq\t%%rbp\n"
			"\tret\n");
}
void makeVect(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#VECTOR");
	fprintf(fout, "\n\tmovq\t%s+%d(%%rip), %%r10\n"
			"\tmovq\t %%r10, %s(%%rip)\n", tac->op1->text, (atoi(tac->op2->text)*8), tac->res->text);
}
void makeFunc(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#TAC FUNCALL");
	fprintf(fout, "\n\tmovl\t$0, %%eax"
					"\n\tcall\t%s", tac->op1->text);
	fprintf(fout, "\n\tmovq\t%%rax, %s(%%rip)\n", tac->res->text);
}
void makeJZ(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#TAC JZ");
	
	fprintf(fout, 	"\n\tmovq\t%s(%%rip), %%rax\n"
					"\n\tmovq\t$0, %%rdx\n"	
					"\n\tcmpq\t%%rax, %%rdx\n"
					"\tjz\t%s\n", tac->op1->text, tac->res->text);
}
void makeJump(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#TAC JMP");
	fprintf(fout, "\n\tjmp\t%s\n", tac->res->text);
}
void makeLabelASM(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n%s:", tac->res->text);
}
void makeArg(TAC *tac, FILE *fout, AST *node)
{
	int i = 0,j = 0, argNumber = 0;
	HASH_NODE *hashNode;
	AST *nodeAux;
	
	if(!node) return;
	
	hashNode = hashFind(tac->res->text); //PEGA A FUNCAO NA HASH
	
	while(i < 4)	// RECURSAO
	{
		if(node->son[i]) 
			makeArg(tac, fout, node->son[i]);
		i++;
	}
	
	if(node->type == AST_DECF)	// ACHOU UMA DECLARACAO DE FUNCAO
	{
		if(strcmp(node->symbol->text, hashNode->text) == 0) // ACHOU A DECLARACAO DE FUNCAO CERTA (IGUAL A DA HASH)
		{
			nodeAux = node->son[1];	// INICIO DA LISTA DE PARAMETROS
			argNumber = atoi(tac->op2->text);
			
			for(j=0; j<argNumber; j++)	//PERCORRE A LISTA ATE ACHAR O PARAMETRO CERTO
				nodeAux = nodeAux->son[1];

			nodeAux = nodeAux->son[0]; // NODE AUX = PARAMETRO CERTO
			
			// AGORA É IGUAL A UM TAC_ASS
			fprintf(fout, "\n#TAC ARG");
			if(tac->op1->type == SYMBOL_LIT_INT) //Se for do tipo var <- lit_int
				fprintf(fout, "\n\tmovq\t$%s, %s(%%rip)\n", tac->op1->text, nodeAux->symbol->text);
			else if(tac->op1->type != SYMBOL_LIT_INT) //Se for do tipo var <- var
			{
				//if((strncmp((tac->op1)?tac->op1->text:"", "___variavelTemporaria_", 22)) && (strncmp((tac->op2)?tac->op2->text:"", "___variavelTemporaria_", 22)))
					fprintf(fout, "\n\tmovq\t%s(%%rip), %%rax\n", tac->op1->text);
				fprintf(fout, "\n\tmovq\t%%rax, %s(%%rip)\n", nodeAux->symbol->text);
			}
		}
	}
}

void makeEQ(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#TAC EQ");
	
	char nameBuffer1[256], nameBuffer2[256];
	sprintf(nameBuffer1, ".LogicLabel__%d", factorySerialNumber++);
	sprintf(nameBuffer2, ".LogicLabel__%d", factorySerialNumber++);
	
	
	
	if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//lit + lit
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type == SYMBOL_LIT_INT)//var + lit
		fprintf(fout,	"\n\tmovq\t%s(%%rip), %%rdx\n"
						"\tmovq\t$%s, %%rax\n", tac->op1->text, tac->op2->text);
	else if(tac->op1->type == SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//lit + var
		fprintf(fout, 	"\n\tmovq\t$%s, %%rdx\n"
						"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
		
	else if(tac->op1->type != SYMBOL_LIT_INT && tac->op2->type != SYMBOL_LIT_INT)//var + var
		fprintf(fout, "\n\tmovq\t%s(%%rip), %%rdx\n"
			"\tmovq\t%s(%%rip), %%rax\n", tac->op1->text, tac->op2->text);
	
	fprintf(fout, 	"\tcmpq\t%%rax, %%rdx\n"
					"\tjne\t%s\n"	
					"\tmovq\t$1, %s(%%rip)\n"	// coisas mutcho lokas (resumidamente, 0 e 1 servem como booleano)
					"\tjmp\t%s\n"
					"%s:\n"
					"\tmovq\t$0, %s(%%rip)\n"
					"%s:\n", nameBuffer1, tac->res->text, nameBuffer2, nameBuffer1, tac->res->text, nameBuffer2);
}
void makeNOT(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#TAC NOT");
	
	char nameBuffer1[256], nameBuffer2[256];
	sprintf(nameBuffer1, ".LogicLabel__%d", factorySerialNumber++);
	sprintf(nameBuffer2, ".LogicLabel__%d", factorySerialNumber++);
	
	
	if(tac->op1->type == SYMBOL_LIT_INT)//lit
		fprintf(fout, 	"\n\tmovq\t$%s, %%rax\n", tac->op1->text);
	else //var
		fprintf(fout,	"\n\tmovq\t%s(%%rip), %%rax\n", tac->op1->text);
	
	fprintf(fout, 	"\ttestq\t%%rax, %%rax\n"
					"\tjne\t%s\n"	
					"\tmovq\t$1, %s(%%rip)\n"	// coisas mutcho lokas (resumidamente, 0 e 1 servem como booleano)
					"\tjmp\t%s\n"
					"%s:\n"
					"\tmovq\t$0, %s(%%rip)\n"
					"%s:\n", nameBuffer1, tac->res->text, nameBuffer2, nameBuffer1, tac->res->text, nameBuffer2);
}
void makeAssV(TAC *tac, FILE *fout)
{
	fprintf(stderr, "Res: %s\tOp1: %s\tOp2: %s\n", tac->res->text, tac->op1->text, tac->op2->text);
	fprintf(fout, "\n#VEC ASS");
	if(tac->op2->type == SYMBOL_LIT_INT) //Se for do tipo var <- lit_int
		fprintf(fout, "\n\tmovq\t$%s, %%rax\n"
				"\tmovq\t%%rax, %s+%d(%%rip)", tac->op2->text, tac->res->text, (atoi(tac->op1->text)*8));
	else if(tac->op2->type != SYMBOL_LIT_INT) //Se for do tipo var <- var
	{
		if((strncmp((tac->op1)?tac->op1->text:"", "___variavelTemporaria_", 22)) && (strncmp((tac->op2)?tac->op2->text:"", "___variavelTemporaria_", 22)))
			fprintf(fout, "\n\tmovq\t%s(%%rip), %%rax\n", tac->op2->text);
		fprintf(fout, "\n\tmovq\t%%rax, %s+%d(%%rip)\n", tac->res->text, (atoi(tac->op1->text)*8));
	}
}
void makeReturn(TAC *tac, FILE *fout)
{
	fprintf(fout, "\n#TAC RETURN");
	
	fprintf(fout, 	"\n\tmovq\t%s(%%rip), %%rax\n"
					"\n\tpopq\t%%rbp\n"
					"\tret\n", tac->res->text);
	
}
