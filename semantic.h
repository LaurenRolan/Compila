//Feito por 
//Lauren Silva Rolan Sampaio
//Nicolas Eymael da Silva
#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"

int propagateDataType(AST *node);
void semanticSetType(AST *node);
void semanticCheckUndeclared(void);
void semanticCheckUsage(AST *node);
void semanticCheckOperands(AST *node);

#endif
