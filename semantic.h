//Feito por 
//Lauren Silva Rolan Sampaio
//Nicolas Eymael da Silva
#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"

#define ERROR_TYPES -4
#define ERROR_BOOL -3
#define ERROR_FEWARGS -2
#define ERROR_MANYARGS -1
#define OK 0

void propagateDataType(AST *node, int datatype);
int getDataType(AST *node);
void semanticCheckAll(AST *node);
void semanticSetType(AST *node);
void semanticCheckUndeclared(AST *node);
void semanticCheckUsage(AST *node);
void semanticCheckOperands(AST *node);
int compareLists(AST* fcall, AST* fdec);
void semanticCheckReturns(AST* nodeR, HASH_NODE *fdec);
int semanticCheckInit(AST *node, int type);

int dataTypeIsReal(int tipo);
int dataTypeIsInt(int tipo);

int semanticError;

#endif
