//Feito por 
//Lauren Silva Rolan Sampaio
//Nicolas Eymael da Silva
#ifndef TAC_HEADER
#define TAC_HEADER

#include "hash.h"
#include "astree.h"

//Símbolo
#define TAC_SYMBOL 1

//Lógico-aritméticas
#define TAC_ADD 2
#define TAC_SUB 3
#define TAC_MUL 4
#define TAC_DIV 5
#define TAC_LE 6
#define TAC_GE 7
#define TAC_EQ 10
#define TAC_NE 11
#define TAC_AND 12
#define TAC_OR 13
#define TAC_LES 14
#define TAC_GRE 15
#define TAC_NOT 16

//Controle de fluxo e função
#define TAC_IF 17
#define TAC_WHILE 18
#define TAC_LABEL 19
#define TAC_READ 20
#define TAC_RETURN 21
#define TAC_PRINT 22
#define TAC_ELSE 23
#define TAC_BEGIN 24
#define TAC_END 25
#define TAC_JZ 26
#define TAC_JMP 27
#define TAC_CALL 28
#define TAC_ARG 29
#define TAC_FUNC 30

//Assign e vetor
#define TAC_ASS 31
#define TAC_ASSV 32
#define TAC_VECT 33

typedef struct struct_tac
{
	int type;
	HASH_NODE *res;
	HASH_NODE *op1;
	HASH_NODE *op2;
	struct struct_tac *prev;
	struct struct_tac *next;
} TAC;

TAC *tacCreate(int type, HASH_NODE *res, HASH_NODE *op1, HASH_NODE *op2);
TAC *tacGenerator(AST *node);
void tacPrintBack(TAC *last);
void tacPrintSingle(TAC *tac);
TAC *tacJoin(TAC *l1, TAC *l2);


#endif
