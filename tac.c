//Feito por
//Lauren Silva Rolan Sampaio
//Nicolas Eymael da Silva

#include "tac.h"
#include <stdio.h>
#include <stdlib.h>

//Protótipos internos
TAC* makeIfThenElse(TAC *code0, TAC *code1, TAC *code2);
TAC* makeWhile(TAC *code0, TAC *code1);
TAC *makePrint(AST *node);
TAC *makeArgs(AST *node, int order, HASH_NODE *funcHash);
TAC *makeParams(AST *node, int order, HASH_NODE *funcHash);
int isRight(int type);
void findWrite(TAC *current);
void findDoubleStore(TAC *current, TAC *origin);
//Fim dos protótipos internos

void findWrite(TAC *current)
{
	TAC *next, *before;
	int hasRead = 0;
	if(!current) return 0;
	do
	{
		if(current->type == TAC_ASS || current->type == TAC_ASSV)
		{
			next = current->next;
			do //Procura por leituras
			{
				if(isRight(next->type)) //Se é leitura
					if(next->op1 == current->res || next->op2 == current->res) //da variável
					{
						hasRead = 1;
						break;
					}
			}while((next = next->next));
			if(hasRead) current = current->next; //Achou leitura, vai pra próximo assign
			else //Não tem nenhuma leitura
			{
				before = current->prev;
				current->next->prev = before;
				before->next = current->next;
				free(current);
				current = before;
				if(!strncmp(before->res->text, "___variavelTemporaria_", 22))
				{
					before = current->prev;
					current->next->prev = before;
					before->next = current->next;
					free(current);
				}
				current = before->next;
			}
		}
		else current = current->next;
		hasRead = 0;
	}while(current);
}
void findDoubleStore(TAC *current, TAC *origin)
{
	TAC *next, *before, *var;
	int hasDoubleStore = 0, hasRead = 0;
	if(!current) return 0;
	do
	{
		if(current->type == TAC_ASS || current->type == TAC_ASSV)
		{
			next = current->next;
			do //Procura por novos ASSIGNS
			{
				if(isRight(next->type)) //Se é leitura
					if(next->op1 == current->res || next->op2 == current->res) //da variável
					{
						hasRead = 1;
						break;
					}
				if(next->type == TAC_ASS || next->type == TAC_ASSV) //Se é assign
					if(next->res == current->res) //da variável
					{
						hasDoubleStore = 1;
						break;
					}
			}while((next = next->next));
			if(hasRead) {
				fprintf(stderr, "\nTem leitura\n");
				current = current->next; //Achou leitura, vai pra próximo assign
			}
			else if(hasDoubleStore) //Tem um double e nenhuma leitura entre, deleta double
			{
				before = current->prev;
				current->next->prev = before;
				before->next = current->next;
				free(current);
				current = before;
				if(!strncmp(before->res->text, "___variavelTemporaria_", 22))
				{
					before = current->prev;
					current->next->prev = before;
					before->next = current->next;
					free(current);
				}
				current = before->next;
			}
		}
		else current = current->next;
		hasRead = 0;
		hasDoubleStore = 0;
	}while(current);
}

TAC *killTheDead(TAC *current)
{
	findWrite(current);
	findDoubleStore(current, 0);
	return current;
}

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
	switch (node->type)
	{
		case AST_SYMBOL: return tacCreate(TAC_SYMBOL, node->symbol, 0, 0);
		case AST_ADD: return tacJoin(tacJoin(code[0], code[1]),tacCreate(TAC_ADD, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0));
		case AST_SUB: return tacJoin(tacJoin(code[0], code[1]),tacCreate(TAC_SUB, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0));
		case AST_MUL: return tacJoin(tacJoin(code[0], code[1]),tacCreate(TAC_MUL, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0));
		case AST_DIV: return tacJoin(tacJoin(code[0], code[1]),tacCreate(TAC_DIV, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0));
		case AST_LE: return tacJoin(tacJoin(code[0], code[1]),tacCreate(TAC_LE, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0));
		case AST_GE: return tacJoin(tacJoin(code[0], code[1]),tacCreate(TAC_GE, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0));
		case AST_EQ: return tacJoin(tacJoin(code[0], code[1]),tacCreate(TAC_EQ, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0));
		case AST_NE: return tacJoin(tacJoin(code[0], code[1]),tacCreate(TAC_NE, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0));
		case AST_AND: return tacJoin(tacJoin(code[0], code[1]),tacCreate(TAC_AND, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0));
		case AST_OR: return tacJoin(tacJoin(code[0], code[1]),tacCreate(TAC_OR, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0));
		case AST_LES: return tacJoin(tacJoin(code[0], code[1]),tacCreate(TAC_LES, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0));
		case AST_GRE: return tacJoin(tacJoin(code[0], code[1]),tacCreate(TAC_GRE, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0));
		case AST_NOT: return tacJoin(tacJoin(code[0], code[1]),tacCreate(TAC_NOT, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0));
			
		case AST_ASS: return tacJoin(code[0], tacCreate(TAC_ASS, node->symbol, code[0]?code[0]->res:0, 0));
		case AST_ASSV: return tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_ASSV, node->symbol, code[0]?code[0]->res:0, code[1]?code[1]->res:0)); // será que precisa de TEMP = v[i]????
		
		case AST_IF: return makeIfThenElse(code[0], code[1], code[2]);
		case AST_WHILE: return makeWhile(code[0], code[1]);
		
		case AST_RETURN: return tacJoin(code[0], tacCreate(TAC_RETURN, code[0]?code[0]->res:0, 0, 0)); 
		case AST_READ: return tacCreate(TAC_READ, node->symbol, 0, 0);
			
		case AST_PRINT: return makePrint(node->son[0]);
		
		//acho que falta essas	
		case AST_DECF: return tacJoin(tacCreate(TAC_BEGIN, node->symbol, 0, 0), tacJoin(code[2], tacCreate(TAC_END, node->symbol, 0, 0)));
		//case AST_PARAM: return;
		case AST_VECT: return tacJoin(code[0], tacCreate(TAC_VECT, makeTemp(), node->symbol, code[0]?code[0]->res:0)); 
		case AST_FUNC: return tacJoin(makeArgs(node->son[0], 0, node->symbol), tacCreate(TAC_FUNC, makeTemp(), node->symbol, 0));

			
	}
	return tacJoin(tacJoin(tacJoin(code[0], code[1]), code[2]), code[3]);
}

void tacPrintBack(TAC *last)
{
	if(!last) return;
	TAC *tac;
	for(tac = last; tac; tac = tac->prev)
		tacPrintSingle(tac);
}
TAC *tacInvert (TAC *last)
{
	if(!last) return 0;
	TAC *tac, *newtac;
	for(tac = last; tac; tac = tac->prev)
		newtac = tac;
	return newtac;
}
void tacPrintInOrder(TAC *first)
{
	TAC* tac;
	if(!first) return;
	for(tac = first; tac; tac = tac->next)
		tacPrintSingle(tac);
}

void tacPrintSingle(TAC *tac)
{
	if(!tac || tac->type == TAC_SYMBOL) return;
	fprintf(stderr, "(");
	switch(tac->type)
	{
		case TAC_SYMBOL: fprintf(stderr, "TAC_SYMBOL"); break;
		case TAC_ADD: fprintf(stderr, "TAC_ADD"); break;
		case TAC_SUB: fprintf(stderr, "TAC_SUB"); break;
		case TAC_MUL: fprintf(stderr, "TAC_MUL"); break;
		case TAC_DIV: fprintf(stderr, "TAC_DIV"); break;
		case TAC_LE: fprintf(stderr, "TAC_LE"); break;
		case TAC_GE: fprintf(stderr, "TAC_GE"); break;
		case TAC_EQ: fprintf(stderr, "TAC_EQ"); break;
		case TAC_NE: fprintf(stderr, "TAC_NE"); break;
		case TAC_AND: fprintf(stderr, "TAC_AND"); break;
		case TAC_OR: fprintf(stderr, "TAC_OR"); break;
		case TAC_LES: fprintf(stderr, "TAC_LES"); break;
		case TAC_GRE: fprintf(stderr, "TAC_GRE"); break;
		case TAC_NOT: fprintf(stderr, "TAC_NOT"); break;
		case TAC_ASS: fprintf(stderr, "TAC_ASS"); break;
		case TAC_ASSV: fprintf(stderr, "TAC_ASSV"); break;
		case TAC_IF: fprintf(stderr, "TAC_IF"); break;
		case TAC_WHILE: fprintf(stderr, "TAC_WHILE"); break;
		case TAC_READ: fprintf(stderr, "TAC_READ"); break;
		case TAC_RETURN: fprintf(stderr, "TAC_RETURN"); break;
		case TAC_PRINT: fprintf(stderr, "TAC_PRINT"); break;
		case TAC_ELSE: fprintf(stderr, "TAC_ELSE"); break;
		case TAC_BEGIN: fprintf(stderr, "TAC_BEGIN"); break;
		case TAC_END: fprintf(stderr, "TAC_END"); break;
		case TAC_JZ: fprintf(stderr, "TAC_JZ"); break;
		case TAC_JMP: fprintf(stderr, "TAC_JMP"); break;
		case TAC_CALL: fprintf(stderr, "TAC_CALL"); break;
		case TAC_ARG: fprintf(stderr, "TAC_ARG"); break;
		case TAC_LABEL: fprintf(stderr, "TAC_LABEL"); break;
		case TAC_VECT: fprintf(stderr, "TAC_VECT"); break;
		case TAC_FUNC: fprintf(stderr, "TAC_FUNC"); break;
		case TAC_PARAM: fprintf(stderr, "TAC_PARAM"); break;
		default: fprintf(stderr, "UNKNOWN"); break;
	}
	if(tac->res) fprintf(stderr, ", %s", tac->res->text); else fprintf(stderr, ", null");
	if(tac->op1) fprintf(stderr, ", %s", tac->op1->text); else fprintf(stderr, ", null");
	if(tac->op2) fprintf(stderr, ", %s", tac->op2->text); else fprintf(stderr, ", null");
	fprintf(stderr, ")\n");
}

TAC *tacJoin(TAC *l1, TAC *l2)
{
	TAC *tac = l2;
	if(!l1) return l2;
	if(!l2) return l1;
	while(tac->prev) tac = tac->prev;
	tac->prev = l1;
	l1->next = tac;
	return l2;
}

TAC *makeIfThenElse(TAC *code0, TAC *code1, TAC *code2)
{
	TAC *JzTac = 0;
	TAC *LabelElseTac = 0;
	TAC *JmpEndTac = 0;
	TAC *LabelEndTac = 0;
	HASH_NODE *newLabelElse = 0;
	HASH_NODE *newLabelEnd = 0;

	newLabelEnd = makeLabel();

	if(code2) //Caso tenha else
	{
		newLabelElse = makeLabel();
		//Caso o if seja falso, pula PARA o else
		JzTac = tacCreate(TAC_JZ, newLabelElse, code0?code0->res:0, 0);	
		LabelElseTac = tacCreate(TAC_LABEL, newLabelElse, 0, 0);
	
		//Ao terminar o if, pula SOBRE o else
		JmpEndTac = tacCreate(TAC_JMP, newLabelEnd, code1?code1->res:0, 0);
		LabelEndTac = tacCreate(TAC_LABEL, newLabelEnd, 0, 0);

		//Ordem: code0 -> JZ -> code1 -> Jmp -> LElse -> code2 -> LEnd 
		return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(code0, JzTac), code1), JmpEndTac), LabelElseTac), code2), LabelEndTac);
	}

	//Caso não tenha else
	JzTac = tacCreate(TAC_JZ, newLabelEnd, code0?code0->res:0, 0);
	LabelEndTac = tacCreate(TAC_LABEL, newLabelEnd, 0, 0);
	
	//Ordem: code0 -> Jz -> code1 -> LEnd
	return tacJoin(tacJoin(tacJoin(code0, JzTac), code1), LabelEndTac);	
}

TAC *makeWhile(TAC *code0, TAC *code1)
{
	TAC *newJz = 0;
	TAC *newJmp = 0;
	TAC *newLabelWhileTac = 0;
	TAC *newLabelEndTac = 0;
	HASH_NODE *newLabelWhile = 0;
	HASH_NODE *newLabelEnd = 0;

	newLabelWhile = makeLabel();
	newLabelEnd = makeLabel();

	//Continuidade do loop
	newJmp = tacCreate(TAC_JMP, newLabelWhile, code0?code0->res:0, 0);
	newLabelWhileTac = tacCreate(TAC_LABEL, newLabelWhile, 0, 0);

	//Saída do loop
	newJz = tacCreate(TAC_JZ, newLabelEnd, code0?code0->res:0, 0);
	newLabelEndTac = tacCreate(TAC_LABEL, newLabelEnd, 0, 0);

	//Ordem: LWhile -> code0 -> JZ -> code1 -> JMP -> LEnd
	return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(newLabelWhileTac, code0), newJz), code1), newJmp), newLabelEndTac);
}

TAC *makePrint(AST *node)
{	
	TAC *code0 = 0;
	TAC *codeFinal = 0;
	
	if(!node) return 0;
	if(node->son[1])
		codeFinal = makePrint(node->son[1]);
	
	code0 = tacGenerator(node->son[0]);
	
	return tacJoin(code0, tacJoin(tacCreate(TAC_PRINT, code0?code0->res:0, 0, 0), codeFinal)); 
}

TAC *makeArgs(AST *node, int order, HASH_NODE *funcHash)
{	
	TAC *code0 = 0;
	TAC *codeFinal = 0;
	
	if(!node) return 0;
	if(node->son[1])
		codeFinal = makeArgs(node->son[1], order+1, funcHash);
	
	code0 = tacGenerator(node->son[0]);
	
	return tacJoin(code0, tacJoin(tacCreate(TAC_ARG, funcHash,code0?code0->res:0, makeNumber(order)), codeFinal)); 	
}

int isRight(int type)
{
	switch(type)
	{
		case TAC_SYMBOL:
		case TAC_ADD: 
		case TAC_SUB: 
		case TAC_MUL: 
		case TAC_DIV: 
		case TAC_LE: 
		case TAC_GE: 
		case TAC_EQ: 
		case TAC_NE: 
		case TAC_AND: 
		case TAC_OR: 
		case TAC_LES: 
		case TAC_GRE: 
		case TAC_NOT: 
		case TAC_VECT:
		case TAC_PARAM:
		case TAC_READ:
		case TAC_RETURN: 
		case TAC_PRINT:
		case TAC_CALL:
			return 1;
			break;
		default: return 0;
	}
}

