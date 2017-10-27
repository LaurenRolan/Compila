#include "astree.h"
#include <stdlib.h>
#include <stdio.h>

AST *astCreate(int type, HASH_NODE *symbol, AST* son0, AST* son1, AST* son2, AST* son3){
  AST *newnode;
  newnode = (AST*) calloc(1, sizeof(AST));
  newnode->type = type;
  newnode->symbol = *symbol;
  newnode->son[0] = son0;
  newnode->son[1] = son1;
  newnode->son[2] = son2;
  newnode->son[3] = son3;
  return newnode;
}

void nodePrint(AST *node){
  if(node){
    fprintf(stderr, "Node(");
    switch(node->type){
  	case AST_SYMBOL: fprintf(stderr, "SYMBOL, %s", node->symbol.text); break;
  	case AST_IF: fprintf(stderr, "IF THEN ELSE"); break;
	case AST_FOR: fprintf(stderr, "FOR"); break;
	case AST_WHILE: fprintf(stderr, "WHILE"); break;
	case AST_READ: fprintf(stderr, "READ"); break;
	case AST_RETURN: fprintf(stderr, "RETURN"); break;
	case AST_PRINT: fprintf(stderr, "PRINT"); break;
	case AST_LE: fprintf(stderr, "LESS-EQUAL"); break;
	case AST_GE: fprintf(stderr, "GREATER-EQUAL"); break; 
	case AST_EQ: fprintf(stderr, "EQUAL"); break;
	case AST_NE: fprintf(stderr, "NOT EQUAL"); break;
	case AST_AND: fprintf(stderr, "AND"); break;
	case AST_OR: fprintf(stderr, "OR"); break;
	case AST_ADD: fprintf(stderr, "ADD"); break;
	case AST_DIV: fprintf(stderr, "DIV"); break;
	case AST_SUB: fprintf(stderr, "SUB"); break;
	case AST_MUL: fprintf(stderr, "MUL"); break;
	case AST_ASS: fprintf(stderr, "ASS"); break;
	case AST_CMDL: fprintf(stderr, "CMDL"); break;
	case AST_BCK: fprintf(stderr, "BLOCK"); break;
	case AST_VEC: fprintf(stderr, "VECTOR"); break;
	case AST_FUN: fprintf(stderr, "FUNCTION"); break;
	case AST_PAR: fprintf(stderr, "PARENTESIS"); break;
	case AST_DEC: fprintf(stderr, "DECLARATION"); break;
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
    nodePrint(root);
    for(i = 0; root->son[i] && i < 4; i++){
      treePrint(root->son[i], level++);
    }
  }
}
