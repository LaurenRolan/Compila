#ifndef ASTREE_HEADER
# define ASTREE_HEADER

#include "hash.h"

#define MAX_SONS 4
#define AST_SYMBOL 1
#define AST_IF 2
#define AST_WHILE 3
#define AST_FOR 4
#define AST_READ 5
#define AST_RETURN 6
#define AST_PRINT 7
#define AST_LE 8
#define AST_GE 9 
#define AST_EQ 10
#define AST_NE 11
#define AST_AND 12
#define AST_OR 13
#define AST_LES 14
#define AST_GRE 15
#define AST_NOT 16
#define AST_ADD 17
#define AST_DIV 18
#define AST_SUB 19
#define AST_MUL 20
#define AST_ASS 21
#define AST_CMDL 22
#define AST_BCK 23
#define AST_VEC 24
#define AST_FUN 25
#define AST_PAR 26
#define AST_DEC 27

typedef struct ast_node {
  int type;
  HASH_NODE symbol;
  struct ast_node *son[MAX_SONS];
} AST;

AST *astCreate(int type, HASH_NODE * symbol, AST* son0, AST* son1, AST* son2, AST* son3);
void nodePrint(AST *node);
void treePrint(AST *root, int level);

#endif
