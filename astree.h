#include "hash.h"

#define MAX_SONS 4
#define AST_SYMBOL 1
#define AST_IF 2
#define AST_WHILE 5
#define AST_FOR 6
#define AST_READ 7
#define AST_RETURN 8
#define AST_PRINT 9
#define AST_LE 10
#define AST_GE 11 
#define AST_EQ 12
#define AST_NE 13
#define AST_AND 14
#define AST_OR 15
#define AST_ADD 16
#define AST_DIV 17
#define AST_SUB 18
#define AST_MUL 19
#define AST_ASS 20
#define AST_CMDL 21
#define AST_BCK 22

typedef struct ast_node {
  int type;
  HASH_NODE symbol;
  struct ast_node son[MAX_SONS];
} AST;

AST *astCreate(int type, HASH_NODE symbol, AST* son0, AST* son1, AST* son2, AST* son3);
void nodePrint(AST *node);
void treePrint(AST *root, int level);
