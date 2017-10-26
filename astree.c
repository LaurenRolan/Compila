#include "astree.h"

AST *astCreate(int type, HASH_NODE * symbol, AST* son0, AST* son1, AST* son2, AST* son3){
  AST *newnode;
  newnode = (AST*) calloc(1, sizeof(AST));
  newnode->type = type;
  newnode->symbol = symbol;
  newnode->son[0] = son0;
  newnode->son[1] = son1;
  newnode->son[2] = son2;
  newnode->son[3] = son3;
  retun newnode;
}

void nodePrint(AST *node){
  if(node){
    fprintf(stderr, "Node( ");
    switch(node->type){
  	AST_SYMBOL: fprintf(stderr, "SYMBOL, %s", node->symbol->text); break;
  	AST_IF: fprintf(stderr, "IF THEN ELSE"); break;
	AST_FOR: fprintf(stderr, "FOR"); break;
	AST_WHILE: fprintf(stderr, "WHILE"); break;
	AST_READ: fprintf(stderr, "READ"); break;
	AST_RETURN: fprintf(stderr, "RETURN"); break;
	AST_PRINT: fprintf(stderr, "PRINT"); break;
	AST_LE: fprintf(stderr, "LESS-EQUAL"); break;
	AST_GE: fprintf(stderr, "GREATER-EQUAL"); break; 
	AST_EQ: fprintf(stderr, "EQUAL"); break;
	AST_NE: fprintf(stderr, "NOT EQUAL"); break;
	AST_AND: fprintf(stderr, "AND"); break;
	AST_OR: fprintf(stderr, "OR"); break;
	AST_ADD: fprintf(stderr, "ADD"); break;
	AST_DIV: fprintf(stderr, "DIV"); break;
	AST_SUB: fprintf(stderr, "SUB"); break;
	AST_MUL: fprintf(stderr, "MUL"); break;
	AST_ASS: fprintf(stderr, "ASS"); break;
	AST_CMDL: fprintf(stderr, "CMDL"); break;
	AST_BCK: fprintf(stderr, "BLOCK"); break;
	AST_VEC: fprintf(stderr, "VECTOR"); break;
	AST_FUN: fprintf(stderr, "FUNCTION"); break;
	AST_PAR: fprintf(stderr, "PARENTESIS"); break;
      default: fprintf(stderr, "NOPE");
        break;
    }
    fprintf(stderr, ")\n");
  }
}

void treePrint(AST *root, int level){
  int j, i;
  if(root){
    for(j = 0; j < level; j++) fprintf(stderr, "|");
    switch(node->type) {
    	AST_SYMBOL: fprintf(stderr, "SYMBOL, %s\n", node->symbol->text); break;
  	AST_IF: fprintf(stderr, "IF THEN ELSE\n"); break;
	AST_FOR: fprintf(stderr, "FOR\n"); break;
	AST_WHILE: fprintf(stderr, "WHILE\n"); break;
	AST_READ: fprintf(stderr, "READ\n"); break;
	AST_RETURN: fprintf(stderr, "RETURN\n"); break;
	AST_PRINT: fprintf(stderr, "PRINT\n"); break;
	AST_LE: fprintf(stderr, "LESS-EQUAL\n"); break;
	AST_GE: fprintf(stderr, "GREATER-EQUAL\n"); break; 
	AST_EQ: fprintf(stderr, "EQUAL\n"); break;
	AST_NE: fprintf(stderr, "NOT EQUAL\n"); break;
	AST_AND: fprintf(stderr, "AND\n"); break;
	AST_OR: fprintf(stderr, "OR\n"); break;
	AST_ADD: fprintf(stderr, "ADD\n"); break;
	AST_DIV: fprintf(stderr, "DIV\n"); break;
	AST_SUB: fprintf(stderr, "SUB\n"); break;
	AST_MUL: fprintf(stderr, "MUL\n"); break;
	AST_ASS: fprintf(stderr, "ASS\n"); break;
	AST_CMDL: fprintf(stderr, "CMDL\n"); break;
	AST_BCK: fprintf(stderr, "BLOCK\n"); break;
	AST_VEC: fprintf(stderr, "VECTOR"); break;
	AST_FUN: fprintf(stderr, "FUNCTION"); break;
	AST_PAR: fprintf(stderr, "PARENTESIS"); break;
      default: fprintf(stderr, "NOPE\n");
        break;
    for(i = 0; root->son[i] && i < 4; i++){
      treePrint(son[i], level++);
    }
  }
}
