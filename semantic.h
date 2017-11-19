//Feito por 
//Lauren Silva Rolan Sampaio
//Nicolas Eymael da Silva
#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"

#define ERRO -1
#define OK 0

void propagateDataType(AST *node, int datatype);
int getDataType(AST *node);
void semanticCheckAll(AST *node);
void semanticSetType(AST *node);
void semanticCheckUndeclared(AST *node);
void semanticCheckUsage(AST *node);
void semanticCheckOperands(AST *node);
int compareLists(AST* fcall, AST* fdec);

int semanticError;

#endif
