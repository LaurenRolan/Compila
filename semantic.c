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
		default: fprintf(stderr, "ERRO em semanticSetType.\n");
	}
}

void semanticCheckUndeclared(void)
{
	return;
}

void semanticCheckUsage(AST *node)
{
	return;
}

void semanticCheckOperands(AST *node)
{
	return;
}
