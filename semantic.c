#include "semantic.h"

void semanticSetType(AST *node)
{
	int i;
	if(!node) return;

	//Processa a partir das folhas
	for(i = 0; i<MAX_SONS; ++i)
		semanticSetType(node->son[i]);

	//Processamento do nodo
	switch(node->type) 
	{
		case AST_DEC: if (node->symbol->type != SYMBOL_ID)
				{
					fprintf(stderr, "Semantic ERROR: identifier %s already declared.\n", node->symbol->text);
					exit(4); //Tirar depois
				}
				else 
				{
					node->symbol->type = SYMBOL_VAR;
					if(node->son[0]->type == AST_BYTE || node->son[0]->type == AST_SHORT || node->son[0]->type == AST_LONG)
						node->symbol->datatype = DATATYPE_INT;
					if(node->son[0]->type == AST_FLOAT || node->son[0]->type == AST_DOUBLE)
						node->symbol->datatype = DATATYPE_REAL;
				}
			break;
		case AST_DECV: if (node->symbol->type != SYMBOL_ID)
				{
					fprintf(stderr, "Semantic ERROR: identifier %s already declared.\n", node->symbol->text);
					exit(4); //Tirar depois
				}
				else 
				{
					node->symbol->type = SYMBOL_VEC;
					if(node->son[0]->type == AST_BYTE || node->son[0]->type == AST_SHORT || node->son[0]->type == AST_LONG)
						node->symbol->datatype = DATATYPE_INT;
					if(node->son[0]->type == AST_FLOAT || node->son[0]->type == AST_DOUBLE)
						node->symbol->datatype = DATATYPE_REAL;
				}
			break;
		case AST_DECF: if (node->symbol->type != SYMBOL_ID)
				{
					fprintf(stderr, "Semantic ERROR: identifier %s already declared.\n", node->symbol->text);
					exit(4); //Tirar depois
				}
				else 
				{
					node->symbol->type = SYMBOL_FUN;
					if(node->son[0]->type == AST_BYTE || node->son[0]->type == AST_SHORT || node->son[0]->type == AST_LONG)
						node->symbol->datatype = DATATYPE_INT;
					if(node->son[0]->type == AST_FLOAT || node->son[0]->type == AST_DOUBLE)
						node->symbol->datatype = DATATYPE_REAL;
				}
			break;
		default: break;
	}
}

void semanticCheckUndeclared(void)
{
	hashCheckUndeclared();
}

void semanticCheckUsage(AST *node)
{
	int i;
	if(!node) return;
	
	//Processa a partir das folhas
	for(i=0; i <MAX_SONS; ++i)
		semanticCheckUsage(node->son[i]);

	//Verifica o lado esquerdo (assign) e direito
	switch(node->type)
	{
		//Verifica lado esquerdo: escalar ou vetor
		case AST_ASS: if(node->symbol->type != SYMBOL_VAR)
			{
				fprintf(stderr, "Semantic ERROR: identifier %s must be scalar.\n", node->symbol->text);
				exit(4);
			}
			break;
		case AST_ASSV: if(node->symbol->type != SYMBOL_VEC)
			{
				fprintf(stderr, "Semantic ERROR: identifier %s must be vector.\n", node->symbol->text);
				exit(4);
			}
			break;
		//Verifica lado direito: vetor, escalar e função
		case AST_FUNC: if(node->symbol->type != SYMBOL_FUN)
			{
				fprintf(stderr, "Semantic ERROR: identifier %s must be a function.\n", node->symbol->text);
				exit(4);
			}
			break;
		case AST_VECT: if(node->symbol->type != SYMBOL_VEC)
			{
				fprintf(stderr, "Semantic ERROR: identifier %s must be a vector.\n", node->symbol->text);
				exit(4);
			}
			break; 
		case AST_SYMBOL: if(node->symbol->type != SYMBOL_VAR && node->symbol->type != SYMBOL_LIT_INT && node->symbol->type != SYMBOL_LIT_REAL && node->symbol->type != SYMBOL_LIT_CHAR)
			{
				fprintf(stderr, "Semantic ERROR: identifier %s must be scalar.\n", node->symbol->text);
				exit(4);
			}
			break;
		default: break;
	}
}

void semanticCheckOperands(AST *node)
{
	int i;
	if(!node) return;
	
	//Processa a partir das folhas
	for(i=0; i <MAX_SONS; ++i)
		semanticCheckOperands(node->son[i]);
	
	//Processa operadores aritméticos, lógicos e relacionais
	switch(node->type)
	{
		case AST_LE:
		case AST_GE:
		case AST_EQ: 
		case AST_NE:
		case AST_LES:
		case AST_GRE:
		case AST_ADD:
		case AST_SUB:
		case AST_DIV:
		case AST_MUL:
			switch(node->son[0]->type)
			{
				case AST_LE:
				case AST_GE:
				case AST_EQ: 
				case AST_NE:
				case AST_AND:
				case AST_OR:
				case AST_LES:
				case AST_GRE:
				case AST_NOT:
					fprintf(stderr, "Semantic ERROR: left operand cannot be relational/logic.\n");
					exit(4);
				default: break;
			}
			switch(node->son[1]->type)
			{
				case AST_LE:
				case AST_GE:
				case AST_EQ: 
				case AST_NE:
				case AST_AND:
				case AST_OR:
				case AST_LES:
				case AST_GRE:
				case AST_NOT:
					fprintf(stderr, "Semantic ERROR: left operand cannot be relational/logic.\n");
					exit(4);
				default: break;
			}
			break;
			
		case AST_AND:
		case AST_OR:
		case AST_NOT:
			switch(node->son[0]->type)
			{
				case AST_MUL:
				case AST_ADD:
				case AST_SUB: 
				case AST_DIV:
					fprintf(stderr, "Semantic ERROR: left operand cannot be arithmetic.\n");
					exit(4);
				default: break;
			}
			
			switch(node->son[0]->type)
			{
				case AST_MUL:
				case AST_ADD:
				case AST_SUB: 
				case AST_DIV:
					fprintf(stderr, "Semantic ERROR: left operand cannot be arithmetic.\n");
					exit(4);
				default: break;
			}
			break;
		default: break;
	}
	//Verificar assign (real para real, inteiro para inteiro)
}
