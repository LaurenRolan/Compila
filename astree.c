#include "astree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

AST *astCreate(int type, HASH_NODE *symbol, AST* son0, AST* son1, AST* son2, AST* son3){
  AST *newnode;
  newnode = (AST*) malloc(sizeof(AST));
  newnode->type = type;
  if (symbol != NULL)
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
		case AST_MUL: fprintf(stderr, "MULT"); break;
		case AST_ASS: fprintf(stderr, "ATRIBUICAO, %s", node->symbol.text); break;
		case AST_CMDL: fprintf(stderr, "CMDL"); break;
		case AST_BLOCK: fprintf(stderr, "BLOCK"); break;
		case AST_VECT: fprintf(stderr, "VECTOR"); break;
		case AST_FUNC: fprintf(stderr, "FUNCTION"); break;
		case AST_PAR: fprintf(stderr, "PARENTESIS"); break;
		case AST_DEC: fprintf(stderr, "DECLARATION, %s", node->symbol.text); break;
		case AST_DECV: fprintf(stderr, "VECTOR DECLARATION, %s", node->symbol.text); break;
		case AST_DECF: fprintf(stderr, "FUNCTION DECLARATION, %s", node->symbol.text); break;
		case AST_LIST: fprintf(stderr, "LIST"); break;
		case AST_PARAM: fprintf(stderr, "PARAMETER, %s", node->symbol.text); break;
		case AST_BYTE: fprintf(stderr, "BYTE"); break;
		case AST_SHORT: fprintf(stderr, "SHORT"); break;
		case AST_LONG: fprintf(stderr, "LONG"); break;
		case AST_FLOAT: fprintf(stderr, "FLOAT"); break;
		case AST_DOUBLE: fprintf(stderr, "DOUBLE"); break;
		case AST_STMTL: fprintf(stderr, "STATEMENT LIST"); break;

      default: fprintf(stderr, "NOPE");
        break;
    }
    fprintf(stderr, ")\n");
  }
}

void treePrint(AST *root, int level){
  int j, i;
  if(root){
    for(j = 0; j < level; j++) 
	  fprintf(stderr, " | ");
    nodePrint(root);
    for(i = 0; root->son[i] && i < 4; i++){
	  if(root->type == AST_LIST || root->type == AST_CMDL || root->type == AST_STMTL)
      	 treePrint(root->son[i], level);
	  else
		 treePrint(root->son[i], level+1);
    }
  }
}

//---------------------------------------------------------------------

void nodeWrite(AST *node, FILE *fileout){
  if(node){
	fwrite("Node(", 5, 1, fileout);
    //fprintf(stderr, "Node(");
    switch(node->type){
		case AST_SYMBOL: fwrite("SYMBOL, ", 8, 1, fileout); fwrite(node->symbol.text, strlen(node->symbol.text), 1, fileout); break;
		case AST_IF: fwrite("IF THEN ELSE", 12, 1, fileout); break;
		case AST_FOR: fwrite("FOR", 3, 1, fileout); break;
		case AST_WHILE: fwrite("WHILE", 5, 1, fileout); break;
		case AST_READ: fwrite("READ", 4, 1, fileout); break;
		case AST_RETURN: fwrite("RETURN", 6, 1, fileout); break;
		case AST_PRINT: fwrite("PRINT", 5, 1, fileout); break;
		case AST_LE: fwrite("LESS-EQUAL", 10, 1, fileout); break;
		case AST_GE: fwrite("GREATER-EQUAL", 13, 1, fileout); break; 
		case AST_EQ: fwrite("EQUAL", 5, 1, fileout); break;
		case AST_NE: fwrite("NOT EQUAL", 9, 1, fileout); break;
		case AST_AND: fwrite("AND", 3, 1, fileout); break;
		case AST_OR: fwrite("OR", 2, 1, fileout); break;
		case AST_ADD: fwrite("ADD",3, 1, fileout); break;
		case AST_DIV: fwrite("DIV", 3, 1, fileout); break;
		case AST_SUB: fwrite("SUB", 3, 1, fileout); break;
		case AST_MUL: fwrite("MULT", 4, 1, fileout); break;	
		case AST_ASS: fwrite("ATRIBUICAO, ", 12, 1, fileout); fwrite(node->symbol.text, strlen(node->symbol.text), 1, fileout); break;
		case AST_CMDL: fwrite("CMDL", 4, 1, fileout); break;
		case AST_BLOCK: fwrite("BLOCK", 5, 1, fileout); break;
		case AST_VECT: fwrite("VECTOR", 6, 1, fileout); break;
		case AST_FUNC: fwrite("FUNCTION", 8, 1, fileout); break;
		case AST_PAR: fwrite("PARENTESIS", 10, 1, fileout); break;
		case AST_DEC: fwrite("DECLARATION, ", 13, 1, fileout); fwrite(node->symbol.text, strlen(node->symbol.text), 1, fileout); break;
		case AST_DECV: fwrite("VECTOR DECLARATION, ", 20, 1, fileout); fwrite(node->symbol.text, strlen(node->symbol.text), 1, fileout); break;										
		case AST_DECF: fwrite("FUNCTION DECLARATION, ", 22, 1, fileout); fwrite(node->symbol.text, strlen(node->symbol.text), 1, fileout); break;																
		case AST_LIST: fwrite("LIST", 4, 1, fileout); break;
		case AST_PARAM: fwrite("PARAMETER, ", 11, 1, fileout); fwrite(node->symbol.text, strlen(node->symbol.text), 1, fileout); break;
		case AST_BYTE: fwrite("BYTE", 4, 1, fileout); break;
		case AST_SHORT: fwrite("SHORT", 5, 1, fileout); break;
		case AST_LONG: fwrite("LONG", 4, 1, fileout); break;
		case AST_FLOAT: fwrite("FLOAT", 5, 1, fileout); break;
		case AST_DOUBLE: fwrite("DOUBLE", 6, 1, fileout); break;
		case AST_STMTL: fwrite("STATEMENT LIST", 14, 1, fileout); break;

      default: fwrite("NOPE", 4, 1, fileout);
        break;
    }
	//fwrite(stringao, sizeof(stringao), 1, fileout);
	fwrite(")\n", 2, 1, fileout);
   // fprintf(stderr, ")\n");
																   
																   
  }
}

void treeWrite(AST *root, int level, FILE *fileout){
  int j, i;
  if(root){
    for(j = 0; j < level; j++) 
	  fwrite(" | ", 3, 1, fileout);
    nodeWrite(root, fileout);
    for(i = 0; root->son[i] && i < 4; i++){
	  if(root->type == AST_LIST || root->type == AST_CMDL || root->type == AST_STMTL)
      	 treeWrite(root->son[i], level, fileout);
	  else
		 treeWrite(root->son[i], level+1, fileout);
    }
  }
}
