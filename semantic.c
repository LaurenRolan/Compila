#include "semantic.h"


int getDataType(AST *node)
{
	int i, typeSon=0, allToReal = 0, allToBool = 0;

	//Processa a partir das folhas
	for(i = 0; i<MAX_SONS; ++i)
	{
		if(node->son[i])
			typeSon = getDataType(node->son[i]);
		if((node->type == AST_LES) || (node->type == AST_GRE) || (node->type ==AST_AND) || (node->type == AST_OR) || (node->type == AST_NE) || (node->type == AST_EQ) || (node->type == AST_LE) || (node->type == AST_GE) || (node->type ==AST_NOT))
			allToBool = 1;
		else
			if(dataTypeIsReal(typeSon) == OK)
				allToReal = 1;
	}
	//Seta todos para reais
	if(node->type == AST_FUNC)
		return node->symbol->datatype;
	if(allToBool == 1)
		return BOOLEAN_EXPRESSION;
	if(allToReal == 1)
		return DATATYPE_FLOAT; 
	if(node->symbol && node->symbol->datatype)
		return node->symbol->datatype;
	return typeSon;
}

void semanticCheckAll(AST *node)
{
	semanticError = 0;
	semanticSetType(node);
	linkOrigin(node, node);
	semanticCheckUndeclared(node);
	semanticCheckReturns(node, NULL);
	semanticCheckUsage(node);
	semanticCheckOperands(node);
	if(semanticError == 1)
		exit(4);
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
					if(node->son[0]->type == AST_BYTE)
						node->symbol->datatype = DATATYPE_BYTE;
					if(node->son[0]->type == AST_SHORT)
						node->symbol->datatype = DATATYPE_SHORT;
					if(node->son[0]->type == AST_LONG)
						node->symbol->datatype = DATATYPE_LONG;
					if(node->son[0]->type == AST_FLOAT)
						node->symbol->datatype = DATATYPE_FLOAT;
					if(node->son[0]->type == AST_DOUBLE)
						node->symbol->datatype = DATATYPE_DOUBLE;
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
					if(node->son[0]->type == AST_BYTE)
						node->symbol->datatype = DATATYPE_BYTE;
					if(node->son[0]->type == AST_SHORT)
						node->symbol->datatype = DATATYPE_SHORT;
					if(node->son[0]->type == AST_LONG)
						node->symbol->datatype = DATATYPE_LONG;
					if(node->son[0]->type == AST_FLOAT)
						node->symbol->datatype = DATATYPE_FLOAT;
					if(node->son[0]->type == AST_DOUBLE)
						node->symbol->datatype = DATATYPE_DOUBLE;
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
					if(node->son[0]->type == AST_BYTE)
						node->symbol->datatype = DATATYPE_BYTE;
					if(node->son[0]->type == AST_SHORT)
						node->symbol->datatype = DATATYPE_SHORT;
					if(node->son[0]->type == AST_LONG)
						node->symbol->datatype = DATATYPE_LONG;
					if(node->son[0]->type == AST_FLOAT)
						node->symbol->datatype = DATATYPE_FLOAT;
					if(node->son[0]->type == AST_DOUBLE)
						node->symbol->datatype = DATATYPE_DOUBLE;
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
					if(node->son[0]->type == AST_BYTE)
						node->symbol->datatype = DATATYPE_BYTE;
					if(node->son[0]->type == AST_SHORT)
						node->symbol->datatype = DATATYPE_SHORT;
					if(node->son[0]->type == AST_LONG)
						node->symbol->datatype = DATATYPE_LONG;
					if(node->son[0]->type == AST_FLOAT)
						node->symbol->datatype = DATATYPE_FLOAT;
					if(node->son[0]->type == AST_DOUBLE)
						node->symbol->datatype = DATATYPE_DOUBLE;
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
		//	if(node->son[0]){ // ACHO QUE ESSA PARTE COMENTADA AQUI EMBAIXO NAO PRECISA
		/*	if(node->son[0]->type == AST_FUNC)
			{
				if((node->symbol->datatype == DATATYPE_INT && node->son[0]->symbol->datatype== DATATYPE_REAL) || (node->symbol->datatype == DATATYPE_REAL && node->son[0]->symbol->datatype == DATATYPE_INT))
				{
					fprintf(stderr, "Semantic ERROR at line %d: identifier %s is receiving a wrong type.\n", node->lineNumber , node->symbol->text);
					semanticError = 1;
				}
			}
			//esse if de baixo dá problemas com VAR = FUNCAO, entao o if de cima é uma gambiarra pra arrumar isso
			else*/
			if((dataTypeIsInt(node->symbol->datatype) == OK && dataTypeIsReal(getDataType(node->son[0])) == OK) || (dataTypeIsReal(node->symbol->datatype) == OK && dataTypeIsInt(getDataType(node->son[0])) == OK))
			{
				fprintf(stderr, "Semantic ERROR at line %d: identifier %s is receiving a wrong type.\n", node->lineNumber , node->symbol->text);
				semanticError = 1;
			}
			break;
		case AST_ASSV: if(node->symbol->type != SYMBOL_VEC)
			{
				fprintf(stderr, "Semantic ERROR at line %d: identifier %s must be vector.\n", node->lineNumber, node->symbol->text);
				semanticError = 1;
			}
			if(dataTypeIsReal(node->son[0]->symbol->datatype) == OK)
			{
				fprintf(stderr, "Semantic ERROR at line %d: identifier %s must be an integer.\n", node->lineNumber, node->son[0]->symbol->text);
				semanticError = 1;
			}
			//	if(node->son[1]){ // ACHO QUE ESSA PARTE COMENTADA AQUI EMBAIXO NAO PRECISA
			/*if(node->son[1]->type == AST_FUNC)
			{
				if((node->symbol->datatype == DATATYPE_INT && node->son[1]->symbol->datatype== DATATYPE_REAL) || (node->symbol->datatype == DATATYPE_REAL && node->son[1]->symbol->datatype == DATATYPE_INT))
				{
					fprintf(stderr, "Semantic ERROR at line %d: identifier %s is receiving a wrong type.\n", node->lineNumber , node->symbol->text);
					semanticError = 1;
				}
			}
			//esse if de baixo dá problemas com VAR = FUNCAO, entao o if de cima é uma gambiarra pra arrumar isso
			else*/
			if((dataTypeIsInt(node->symbol->datatype) == OK && dataTypeIsReal(getDataType(node->son[1])) == OK) || (dataTypeIsReal(node->symbol->datatype) == OK && dataTypeIsInt(getDataType(node->son[1])) == OK))
			{
				fprintf(stderr, "Semantic ERROR at line %d: identifier %s is receiving a wrong type.\n", node->lineNumber , node->symbol->text);
				semanticError = 1;
			}
			break;
		//Verifica lado direito: vetor, escalar e função
		case AST_FUNC: if(node->symbol->type != SYMBOL_FUN)
			{
				fprintf(stderr, "Semantic ERROR at line %d: identifier %s must be a function.\n", node->lineNumber, node->symbol->text);
				semanticError = 1;
			}
			else
			{
				int flagList = 0;
				flagList = compareLists(node, node->origin);
				if(flagList == ERROR_MANYARGS)
				{
					fprintf(stderr, "Semantic ERROR at line %d: function call %s with too many arguments.\n", node->lineNumber, node->symbol->text);
					semanticError = 1;
				}
				else if(flagList == ERROR_FEWARGS)
				{
					fprintf(stderr, "Semantic ERROR at line %d: function call %s is missing arguments.\n", node->lineNumber, node->symbol->text);
					semanticError = 1;
				}
				else if(flagList == ERROR_BOOL)
				{
					fprintf(stderr, "Semantic ERROR at line %d: function call %s with boolean argument.\n", node->lineNumber, node->symbol->text);
					semanticError = 1;
				}
				else if(flagList == ERROR_TYPES)
				{
					fprintf(stderr, "Semantic ERROR at line %d: function call %s with incompatible types.\n", node->lineNumber, node->symbol->text);
					semanticError = 1;
				}
			}
			break;
		case AST_VECT: if(node->symbol->type != SYMBOL_VEC)
			{
				fprintf(stderr, "Semantic ERROR at line %d: identifier %s must be a vector.\n", node->lineNumber, node->symbol->text);
				semanticError = 1;
			}

			if(dataTypeIsInt(getDataType(node->son[0])) == OK)
			{
				fprintf(stderr, "Semantic ERROR at line %d: identifier %s must be an integer.\n", node->lineNumber, node->son[0]->symbol->text);
				semanticError = 1;
			}
			break;
		case AST_SYMBOL: if(node->symbol->type != SYMBOL_VAR && node->symbol->type != SYMBOL_LIT_INT && node->symbol->type != SYMBOL_LIT_REAL && node->symbol->type != SYMBOL_LIT_CHAR && node->symbol->type != SYMBOL_LIT_STRING)
			{
				if(node->symbol->type == SYMBOL_VEC)
					fprintf(stderr, "Semantic ERROR at line %d: identifier %s is a vector, use %s[index]\n", node->lineNumber, node->symbol->text, node->symbol->text);
				else
				{
					if(node->symbol->type == SYMBOL_FUN)
						fprintf(stderr, "Semantic ERROR at line %d: identifier %s is a function, use %s(arguments)\n", node->lineNumber, node->symbol->text, node->symbol->text);
					else
						fprintf(stderr, "Semantic ERROR at line %d: identifier %s ...How can I say?... It's creepy O.O\n", node->lineNumber, node->symbol->text); // acho que isso nao deve acontecer
				}
				semanticError = 1;
			}
			break;
		default: break;
	}
}

int compareLists(AST* fcall, AST* fdec)
{
	int callType, decType;
	//fprintf(stderr, "\n\nfuncao: %s\n", fcall->symbol->text);
	fcall = fcall->son[0];	//aqui começa a lista de argumentos da chamada
	fdec = fdec->son[1];	//aqui começa a lista de parametros da declaracao
	//fprintf(stderr, "seg fault? \n");

	while(fcall != NULL)
	{
		//fprintf(stderr, "seg fault? 2 \n");
		if(fdec != NULL) // se tem um parametro na declaracao e um argumento na chamada...
		{
			//fprintf(stderr, "seg fault? 3 \n");
			if(fcall->son[0] != NULL)
				callType = getDataType(fcall->son[0]);
			if(fdec->son[0] != NULL)
				decType = getDataType(fdec->son[0]);
			if(((dataTypeIsReal(decType) == OK) && (dataTypeIsInt(callType)) == OK) || ((dataTypeIsInt(decType) == OK) && (dataTypeIsReal(callType) == OK)))
				return ERROR_TYPES;

			//NESSE ESPAÇO, SE PRECISAR, É PRA COMPARAR OS DATA TYPES DOS ARGSxPARAM

			if((getDataType(fcall) == BOOLEAN_EXPRESSION) || (getDataType(fdec) == BOOLEAN_EXPRESSION))
				return ERROR_BOOL;


			//continuar procurando
			fcall = fcall->son[1];
			fdec = fdec->son[1];

		}
		else  // nº arg > nº param
			return ERROR_MANYARGS;
	}
	if(fdec) // nº param > nº arg
		return ERROR_FEWARGS;
	else  // acabaram os parametros e os argumentos
		return OK;
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

void semanticCheckReturns(AST* nodeR, HASH_NODE *fdec)
{
	//fprintf(stderr, "print INICIO\n");
	
	int i;
	if(!nodeR) return;
	
	//fprintf(stderr, "print 1\n");
	
	if(nodeR->type == AST_DECF)
	{
		//fprintf(stderr, "print 2\n");
		fdec = nodeR->symbol;
		//fprintf(stderr, "print 3\n");
	}
	else if(nodeR->type == AST_RETURN)
		{
			//fprintf(stderr, "print 4\n");
			if((dataTypeIsInt(fdec->datatype) == OK && dataTypeIsReal(getDataType(nodeR->son[0])) == OK) || (dataTypeIsReal(fdec->datatype) == OK && dataTypeIsInt(getDataType(nodeR->son[0])) == OK))	
			{
				//fprintf(stderr, "print 5\n");
				fprintf(stderr, "Semantic ERROR at line %d: return from function %s has wrong type.\n", nodeR->lineNumber, fdec->text);
				semanticError = 1;
				//fprintf(stderr, "print 6\n");
			}
		}

	//fprintf(stderr, "print 7\n");
	for(i=0; i <MAX_SONS; ++i)
		semanticCheckReturns(nodeR->son[i],fdec);
	//fprintf(stderr, "print FIM\n");
}


int dataTypeIsReal(int tipo)
{
	if(tipo == DATATYPE_FLOAT || tipo == DATATYPE_DOUBLE)
		return OK;
	else
		return ERROR_TYPES;
}

int dataTypeIsInt(int tipo)
{
	if(tipo == DATATYPE_BYTE || tipo == DATATYPE_SHORT || tipo == DATATYPE_LONG)
		return OK;
	else
		return ERROR_TYPES;
}



