#include "semantic.h"

int getDataType(AST *node)
{
	int i, typeSon=0, allToReal = 0;
	
	//Processa a partir das folhas
	for(i = 0; i<MAX_SONS; ++i)
	{
		if(node->son[i]) typeSon = getDataType(node->son[i]);
		if(typeSon == DATATYPE_REAL) allToReal = 1;
	}
	//Seta todos para reais
	if(allToReal == 1) return DATATYPE_REAL;//propagateDataType(node, DATATYPE_REAL);
	if(node->symbol && node->symbol->datatype) return node->symbol->datatype;
	return typeSon;
}

void propagateDataType(AST *node, int datatype)
{
	int i;
	if(!node) return;

	for(i = 0; i<MAX_SONS; ++i) //diferenciar vetor
		if((node->type != AST_ASSV && node->type != AST_VECT) || i != 0) if(node->son[i]) propagateDataType(node->son[i], datatype);
	if(node->symbol && node->symbol->datatype)
		node->symbol->datatype = datatype;
}

void semanticCheckAll(AST *node)
{
	semanticError = 0;
	semanticSetType(node);
	semanticCheckUndeclared(node);
	semanticCheckUsage(node);
	semanticCheckOperands(node);
	//if(semanticError == 1)
	//	exit(4);
}


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
					fprintf(stderr, "Semantic ERROR at line %d: identifier %s already declared.\n", node->lineNumber, node->symbol->text);
					semanticError = 1;
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
					fprintf(stderr, "Semantic ERROR at line %d: identifier %s already declared.\n", node->lineNumber, node->symbol->text);
					semanticError = 1;
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
					fprintf(stderr, "Semantic ERROR at line %d: identifier %s already declared.\n", node->lineNumber, node->symbol->text);
					semanticError = 1;
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
		case AST_PARAM: if (node->symbol->type != SYMBOL_ID)
				{
					fprintf(stderr, "Semantic ERROR at line %d: identifier %s already declared.\n", node->lineNumber, node->symbol->text);
					semanticError = 1;
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
		default: break;
	}
}

void semanticCheckUndeclared(AST *node)
{
	int i = 0;
	//fprintf(stderr, "1\n");
  	if(node){
		//fprintf(stderr, "2\n");
		if(node->symbol)
        	hashCheckUndeclared(node->symbol->text, node->lineNumber);
		//fprintf(stderr, "3\n");
    	while(i < 4){
			//fprintf(stderr, "4\n");
	 		if(node->son[i])
				semanticCheckUndeclared(node->son[i]);
			i++;
    	}
 	 }
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
				fprintf(stderr, "Semantic ERROR at line %d: identifier %s must be scalar.\n", node->lineNumber , node->symbol->text);
				semanticError = 1;
			}
			else
			{
				if(node->symbol->datatype == DATATYPE_INT && getDataType(node)== DATATYPE_REAL) semanticError = 1;
			}
			break;
		case AST_ASSV: if(node->symbol->type != SYMBOL_VEC)
			{
				fprintf(stderr, "Semantic ERROR at line %d: identifier %s must be vector.\n", node->lineNumber, node->symbol->text);
				semanticError = 1;
			}
			else if(node->symbol->datatype == DATATYPE_INT && getDataType(node) == DATATYPE_REAL) semanticError = 1;
			if(node->son[0]->symbol->datatype == DATATYPE_REAL)
			{
				fprintf(stderr, "Semantic ERROR at line %d: identifier %s must be an integer.\n", node->lineNumber, node->son[0]->symbol->text);
				semanticError = 1;
			}
			break;
		//Verifica lado direito: vetor, escalar e função
		case AST_FUNC: if(node->symbol->type != SYMBOL_FUN)
			{
				fprintf(stderr, "Semantic ERROR at line %d: identifier %s must be a function.\n", node->lineNumber, node->symbol->text);
				semanticError = 1;
			}
			break;
		case AST_VECT: if(node->symbol->type != SYMBOL_VEC)
			{
				fprintf(stderr, "Semantic ERROR at line %d: identifier %s must be a vector.\n", node->lineNumber, node->symbol->text);
				semanticError = 1;
			}
			
			if(getDataType(node->son[0]) == DATATYPE_REAL)
			{
				fprintf(stderr, "Semantic ERROR at line %d: identifier %s must be an integer.\n", node->lineNumber, node->son[0]->symbol->text);
				semanticError = 1;
			}
			break; 
		case AST_SYMBOL: if(node->symbol->type != SYMBOL_VAR && node->symbol->type != SYMBOL_LIT_INT && node->symbol->type != SYMBOL_LIT_REAL && node->symbol->type != SYMBOL_LIT_CHAR && node->symbol->type != SYMBOL_LIT_STRING)
			{
				fprintf(stderr, "Semantic ERROR at line %d: identifier %s ...How can I say?... It's creepy O.O\n", node->lineNumber, node->symbol->text);
				
				semanticError = 1;
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
		case AST_ASS:
		case AST_ASSV:
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
			if(node->son[0])
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
						fprintf(stderr, "Semantic ERROR at line %d: left operand cannot be relational/logic.\n", node->lineNumber);
						semanticError = 1;
					default: break;
				}
			if(node->son[1])		
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
						fprintf(stderr, "Semantic ERROR at line %d: right operand cannot be relational/logic.\n", node->lineNumber);
						semanticError = 1;
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
					fprintf(stderr, "Semantic ERROR at line %d: left operand cannot be arithmetic.\n", node->lineNumber);
					semanticError = 1;
				default: break;
			}
			if(node->son[1])
				switch(node->son[1]->type)
				{
					case AST_MUL:
					case AST_ADD:
					case AST_SUB: 
					case AST_DIV:
						fprintf(stderr, "Semantic ERROR at line %d: right operand cannot be arithmetic.\n", node->lineNumber);
						semanticError = 1;
					default: break;
				}
			break;
		default: break;
	}
	//Verificar assign (real para real, inteiro para inteiro)
}
