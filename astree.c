#include "astree.h"

AST *astCreate(int type, HASH_NODE symbol, AST* son0, AST* son1, AST* son2, AST* son3){
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

void astPrint(AST *node){
  if(node){
    fprintf(stderr, "AST( ");
    switch(node->type){
      default: fprintf(stderr, "NOPE");
        break;
    }
  }
}
