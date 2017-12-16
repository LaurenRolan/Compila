#include "astree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Internal protoypes

void printValues(FILE *fout, AST *node);

//

void astDeclaration(AST *node, FILE *fout)
{
	int i = 0;
	AST *nodeAux;
	
	if(node){
		switch(node->type)
		{
			case AST_DEC: 
					fprintf(fout, "\t.data\n"
						"%s:\n"
						"\t.quad\t%s\n", node->symbol->text, node->son[1]->symbol->text);
					break;
			case AST_DECV:
				if(node->son[2]) //Se foi inicializado
				{
					fprintf(fout, "\t.data\n"
							"\n\t.size\t%s, %d\n"
							"%s:\n", node->symbol->text, atoi(node->son[1]->symbol->text)*8, node->symbol->text);
							printValues(fout, node->son[2]);
				}
				else fprintf(fout, "\n\t.comm\t%s,%d,32", node->symbol->text, atoi(node->son[1]->symbol->text)*8);
				break;
			case AST_DECF: 
					if(node->son[1])
					{	
						nodeAux = node->son[1];
						while(nodeAux != NULL)
						{
							if(nodeAux->son[0])
								fprintf(fout, 	"\t.data\n"
												"%s:\n"
												"\t.quad\t0\n", nodeAux->son[0]->symbol->text);
							nodeAux = nodeAux->son[1];
						}
					}
					break;
		}
		while(i < 4){
			if(node->son[i]) {
				astDeclaration(node->son[i], fout);
			}
			i++;
		}
	}
}

void linkOrigin(AST *node, AST *root)
{
	int i;
	AST *assign;
	if(node)
	{
		
		if(node->type == AST_DECF)
		{
			while((assign = searchForAssign(root, node->symbol->text)) != NULL)
				assign->origin = node;
		}
		for(i=0; i < MAX_SONS; i++)
			if(node->son[i])
				linkOrigin(node->son[i], root);
	}
}

AST *searchForAssign(AST *node, char *name)
{
	int i;
	AST *assign;
	if(node)
	{
		if(node->type == AST_FUNC && node->origin == NULL)
			if(strcmp(node->symbol->text, name) == 0)
				return node;
		for(i=0; i < MAX_SONS; i++)
			if(node->son[i]) {
				assign = searchForAssign(node->son[i], name);
				if(assign) 
					return assign;
			}
	}
	return NULL;
}

AST *astCreate(int type, HASH_NODE *symbol, AST* son0, AST* son1, AST* son2, AST* son3, int lineNumber){
	AST *newnode;
  	newnode = (AST*) malloc(sizeof(AST));
  	newnode->type = type;
  	if (symbol != NULL)
		newnode->symbol = symbol;
  	newnode->son[0] = son0;
	newnode->son[1] = son1;
	newnode->son[2] = son2;
	newnode->son[3] = son3;
	newnode->lineNumber = lineNumber;
	newnode->origin = NULL;
	return newnode;
}

void nodePrint(AST *node){
  if(node){
    fprintf(stderr, "Node(");
    switch(node->type){
		case AST_SYMBOL: fprintf(stderr, "SYMBOL, %s", node->symbol->text); break;
		case AST_IF: fprintf(stderr, "IF THEN ELSE"); break;
		case AST_WHILE: fprintf(stderr, "WHILE"); break;
		case AST_READ: fprintf(stderr, "READ"); break;
		case AST_RETURN: fprintf(stderr, "RETURN"); break;
		case AST_PRINT: fprintf(stderr, "PRINT"); break;
		case AST_LE: fprintf(stderr, "LESS-EQUAL"); break;
		case AST_LES: fprintf(stderr, "LESS"); break;
		case AST_GE: fprintf(stderr, "GREATER-EQUAL"); break; 
		case AST_GRE: fprintf(stderr, "GREATER"); break;
		case AST_EQ: fprintf(stderr, "EQUAL"); break;
		case AST_NE: fprintf(stderr, "NOT EQUAL"); break;
		case AST_AND: fprintf(stderr, "AND"); break;
		case AST_OR: fprintf(stderr, "OR"); break;
		case AST_ADD: fprintf(stderr, "ADD"); break;
		case AST_DIV: fprintf(stderr, "DIV"); break;
		case AST_SUB: fprintf(stderr, "SUB"); break;
		case AST_MUL: fprintf(stderr, "MULT"); break;
		case AST_ASS: fprintf(stderr, "ASSIGN SCALAR, %s", node->symbol->text); break;
		case AST_ASSV: fprintf(stderr, "ASSIGN VECTOR, %s", node->symbol->text); break;
		case AST_CMDL: fprintf(stderr, "CMDL"); break;
		case AST_BLOCK: fprintf(stderr, "BLOCK"); break;
		case AST_VECT: fprintf(stderr, "VECTOR"); break;
		case AST_FUNC: fprintf(stderr, "FUNCTION, %s", node->symbol->text); break;
		case AST_PAR: fprintf(stderr, "PARENTESIS"); break;
		case AST_DEC: fprintf(stderr, "DECLARATION, %s", node->symbol->text); break;
		case AST_DECV: fprintf(stderr, "VECTOR DECLARATION, %s", node->symbol->text); break;
		case AST_DECF: fprintf(stderr, "FUNCTION DECLARATION, %s", node->symbol->text); break;
		case AST_LIST: fprintf(stderr, "LIST"); break;
		case AST_VECTLIST: fprintf(stderr, "VECTOR LIST"); break;
		case AST_PARAM: fprintf(stderr, "PARAMETER, %s", node->symbol->text); break;
		case AST_BYTE: fprintf(stderr, "BYTE"); break;
		case AST_SHORT: fprintf(stderr, "SHORT"); break;
		case AST_LONG: fprintf(stderr, "LONG"); break;
		case AST_FLOAT: fprintf(stderr, "FLOAT"); break;
		case AST_DOUBLE: fprintf(stderr, "DOUBLE"); break;
		case AST_STMTL: fprintf(stderr, "STATEMENT LIST"); break;
		case AST_NOT: fprintf(stderr, "NOT"); break;
		case AST_OPTCMDL: fprintf(stderr, "OPTCMDL"); break;
		case AST_OPTLIST: fprintf(stderr, "OPTLIST"); break;
		case AST_ELSE: fprintf(stderr, "ELSE"); break;

      default: fprintf(stderr, "NOPE");
        break;
    }
	if(node->symbol)
    	fprintf(stderr, ")....dado = %d\n", node->symbol->datatype);
	 else
		 fprintf(stderr, ")\n");
  }
}

void treePrint(AST *root, int level){
  int j, i = 0;
  if(root){
    for(j = 0; j < level; j++) 
	  fprintf(stderr, " | ");
    nodePrint(root);
    while(i < 4){
		if(root->son[i]) {
			treePrint(root->son[i], level+1);
		}
		i++;
    }
  }
}

//---------------------------------------------------------------------

void nodeWrite(AST *node, FILE *fileout){
  if(node){
	fwrite("Node(", 5, 1, fileout);
    switch(node->type){
		case AST_SYMBOL: fwrite("SYMBOL, ", 8, 1, fileout); fwrite(node->symbol->text, strlen(node->symbol->text), 1, fileout); break;
		case AST_IF: fwrite("IF THEN ELSE", 12, 1, fileout); break;
		case AST_WHILE: fwrite("WHILE", 5, 1, fileout); break;
		case AST_READ: fwrite("READ", 4, 1, fileout); break;
		case AST_RETURN: fwrite("RETURN", 6, 1, fileout); break;
		case AST_PRINT: fwrite("PRINT", 5, 1, fileout); break;
		case AST_LE: fwrite("LESS-EQUAL", 10, 1, fileout); break;
		case AST_LES: fwrite("LESS", 4, 1, fileout); break;
		case AST_GRE: fwrite("GREATER", 7, 1, fileout); break; 
		case AST_GE: fwrite("GREATER-EQUAL", 13, 1, fileout); break; 
		case AST_EQ: fwrite("EQUAL", 5, 1, fileout); break;
		case AST_NE: fwrite("NOT EQUAL", 9, 1, fileout); break;
		case AST_AND: fwrite("AND", 3, 1, fileout); break;
		case AST_OR: fwrite("OR", 2, 1, fileout); break;
		case AST_ADD: fwrite("ADD",3, 1, fileout); break;
		case AST_DIV: fwrite("DIV", 3, 1, fileout); break;
		case AST_SUB: fwrite("SUB", 3, 1, fileout); break;
		case AST_MUL: fwrite("MULT", 4, 1, fileout); break;	
		case AST_ASS: fwrite("ATRIBUICAO, ", 12, 1, fileout); fwrite(node->symbol->text, strlen(node->symbol->text), 1, fileout); break;
		case AST_CMDL: fwrite("CMDL", 4, 1, fileout); break;
		case AST_BLOCK: fwrite("BLOCK", 5, 1, fileout); break;
		case AST_VECT: fwrite("VECTOR", 6, 1, fileout); break;
		case AST_FUNC: fwrite("FUNCTION", 8, 1, fileout); break;
		case AST_PAR: fwrite("PARENTESIS", 10, 1, fileout); break;
		case AST_DEC: fwrite("DECLARATION, ", 13, 1, fileout); fwrite(node->symbol->text, strlen(node->symbol->text), 1, fileout); break;
		case AST_DECV: fwrite("VECTOR DECLARATION, ", 20, 1, fileout); fwrite(node->symbol->text, strlen(node->symbol->text), 1, fileout); break;										
		case AST_DECF: fwrite("FUNCTION DECLARATION, ", 22, 1, fileout); fwrite(node->symbol->text, strlen(node->symbol->text), 1, fileout); break;																
		case AST_LIST: fwrite("LIST", 4, 1, fileout); break;
		case AST_VECTLIST: fwrite("VECTOR LIST", 11, 1, fileout); break;
		case AST_PARAM: fwrite("PARAMETER, ", 11, 1, fileout); fwrite(node->symbol->text, strlen(node->symbol->text), 1, fileout); break;
		case AST_BYTE: fwrite("BYTE", 4, 1, fileout); break;
		case AST_SHORT: fwrite("SHORT", 5, 1, fileout); break;
		case AST_LONG: fwrite("LONG", 4, 1, fileout); break;
		case AST_FLOAT: fwrite("FLOAT", 5, 1, fileout); break;
		case AST_DOUBLE: fwrite("DOUBLE", 6, 1, fileout); break;
		case AST_STMTL: fwrite("STATEMENT LIST", 14, 1, fileout); break;
		case AST_NOT: fwrite("NOT", 3, 1, fileout); break;
		case AST_OPTCMDL: fwrite("OPTCMDL", 7, 1, fileout); break;
		case AST_OPTLIST: fwrite("OPTLIST", 7, 1, fileout); break;
		case AST_ELSE: fwrite("ELSE", 4, 1, fileout); break;

      default: fwrite("NOPE", 4, 1, fileout);
        break;
    }
	fwrite(")\n", 2, 1, fileout);																   
																   
  }
}

void treeWrite(AST *root, int level, FILE *fileout){
  int j, i = 0;
  if(root){
    for(j = 0; j < level; j++) 
	   fwrite(" | ", 3, 1, fileout);
    nodeWrite(root, fileout);
    while(i < 4){
	 if(root->son[i]) {
			treeWrite(root->son[i], level+1, fileout);
	}
	i++;
    }
  }
}

//---------------------------------------------------------------------------------------

void treeToCode(AST *node, FILE *fileout){
	if(node == NULL) return;
	switch(node->type){
		case AST_STMTL: if(node->son[0] != NULL) treeToCode(node->son[0], fileout);
						if(node->son[1] !=NULL)
							treeToCode(node->son[1], fileout);
						break;
		case AST_DEC: 	fwrite(node->symbol->text, strlen(node->symbol->text), 1, fileout);
					 	fwrite(" : ", 3, 1, fileout);
						treeToCode(node->son[0], fileout);
						fwrite(" = ", 3, 1, fileout);
						treeToCode(node->son[1], fileout);
						fwrite(";\n", 2, 1, fileout);
						break;
		case AST_DECV: 	fwrite(node->symbol->text, strlen(node->symbol->text), 1, fileout);
						fwrite(" : ", 3, 1, fileout);
						treeToCode(node->son[0], fileout);
						fwrite(" [", 2, 1, fileout);
						treeToCode(node->son[1], fileout);
						fwrite("] ", 2, 1, fileout);
						if(node->son[2] != NULL)
							treeToCode(node->son[2], fileout);
						fwrite(";\n", 2, 1, fileout);
						break;
		case AST_VECTLIST:	treeToCode(node->son[0], fileout);
							if(node->son[1] !=NULL){
								fwrite(" ", 1, 1, fileout);
								treeToCode(node->son[1], fileout);
							}	
							break;
		case AST_DECF:	fwrite("(", 1, 1, fileout);
						treeToCode(node->son[0], fileout);
						fwrite(") ", 2, 1, fileout);
						fwrite(node->symbol->text, strlen(node->symbol->text), 1, fileout);
						fwrite(" (", 2, 1, fileout);
						if(node->son[1] != NULL) treeToCode(node->son[1], fileout);
						fwrite(") {\n", 4, 1, fileout);
						if(node->son[2] != NULL) treeToCode(node->son[2], fileout);
						fwrite("\n}\n\n", 4, 1, fileout);
						break;
		case AST_SYMBOL:fwrite(node->symbol->text, strlen(node->symbol->text), 1, fileout);
						break;
		case AST_BYTE: 	fwrite("byte", 4, 1, fileout);
						break;
		case AST_SHORT: fwrite("short", 5, 1, fileout);
						break;
		case AST_LONG: 	fwrite("long", 4, 1, fileout);
						break;
		case AST_FLOAT: fwrite("float", 5, 1, fileout);
						break;
		case AST_DOUBLE:	fwrite("double", 6, 1, fileout);
							break;
		case AST_LIST:	treeToCode(node->son[0], fileout);
						if(node->son[1] !=NULL)
							treeToCode(node->son[1], fileout);
						break;
		case AST_OPTLIST:	fwrite(", ", 2, 1, fileout);
							treeToCode(node->son[0], fileout);
							if(node->son[1] !=NULL)
								treeToCode(node->son[1], fileout);
							break;
		case AST_CMDL:	if(node->son[0] !=NULL)
							treeToCode(node->son[0], fileout);
						if(node->son[1] !=NULL)
							treeToCode(node->son[1], fileout);
						break;
		case AST_OPTCMDL:	fwrite(";\n", 2, 1, fileout);
							if(node->son[0] !=NULL)
								treeToCode(node->son[0], fileout);
							if(node->son[1] != NULL)
								treeToCode(node->son[1], fileout);
							break;
		case AST_BLOCK: fwrite("{\n", 2, 1, fileout);
						treeToCode(node->son[0], fileout);
						fwrite("\n}", 2, 1, fileout);
						break;
		case AST_ASS:	fwrite(node->symbol->text, strlen(node->symbol->text), 1, fileout);
						if(node->son[1] != NULL){
							fwrite("[", 1, 1, fileout);
							treeToCode(node->son[1], fileout);
							fwrite("]", 1, 1, fileout);
						}
						fwrite(" = ", 3, 1, fileout);
						treeToCode(node->son[0], fileout);
						break;			
		case AST_IF:	fwrite("if (", 4, 1, fileout);
						treeToCode(node->son[0], fileout);
						fwrite(") then\n", 7, 1, fileout);
						if(node->son[1] != NULL)
							treeToCode(node->son[1], fileout);
						if(node->son[2] != NULL)
							treeToCode(node->son[2], fileout);
						break;
		case AST_ELSE:	 	fwrite("\nelse\n", 6, 1, fileout);
							if(node->son[0] != NULL)
								treeToCode(node->son[0], fileout);
							break;
		case AST_WHILE: fwrite("while(", 6, 1, fileout);
						treeToCode(node->son[0], fileout);
						fwrite(") ", 2, 1, fileout);
						if(node->son[1] != NULL) treeToCode(node->son[1], fileout);
						break;
		case AST_READ: 	fwrite("read > ", 7, 1, fileout);
						fwrite(node->symbol->text, strlen(node->symbol->text), 1, fileout);
						break;
		case AST_RETURN:	fwrite("return ", 7, 1, fileout);
							treeToCode(node->son[0], fileout);
							break;
		case AST_PRINT: 	fwrite("print\t", 6, 1, fileout);
							treeToCode(node->son[0], fileout);
							break;
		case AST_ADD:	treeToCode(node->son[0], fileout);
						fwrite(" + ",3, 1, fileout);
						treeToCode(node->son[1], fileout);
						break;
		case AST_SUB:	treeToCode(node->son[0], fileout);
						fwrite(" - ",3, 1, fileout);
						treeToCode(node->son[1], fileout);
						break;
		case AST_MUL:	treeToCode(node->son[0], fileout);
						fwrite(" * ",3, 1, fileout);
						treeToCode(node->son[1], fileout);
						break;
		case AST_DIV: 	treeToCode(node->son[0], fileout);
						fwrite(" / ",3, 1, fileout);
						treeToCode(node->son[1], fileout);
						break;
		case AST_LES:	treeToCode(node->son[0], fileout);
						fwrite(" < ",3, 1, fileout);
						treeToCode(node->son[1], fileout);
						break;
		case AST_GRE: 	treeToCode(node->son[0], fileout);
						fwrite(" > ",3, 1, fileout);
						treeToCode(node->son[1], fileout);
						break;
		case AST_AND:	treeToCode(node->son[0], fileout);
						fwrite(" && ",4, 1, fileout);
						treeToCode(node->son[1], fileout);
						break;
		case AST_OR: 	treeToCode(node->son[0], fileout);
						fwrite(" || ",4, 1, fileout);
						treeToCode(node->son[1], fileout);
						break;
		case AST_NE: 	treeToCode(node->son[0], fileout);
						fwrite(" != ",4, 1, fileout);
						treeToCode(node->son[1], fileout);
						break;
		case AST_EQ:	treeToCode(node->son[0], fileout);
						fwrite(" == ",4, 1, fileout);
						treeToCode(node->son[1], fileout);
						break;
		case AST_LE:	treeToCode(node->son[0], fileout);
						fwrite(" <= ",4, 1, fileout);
						treeToCode(node->son[1], fileout);
						break;
		case AST_GE:	treeToCode(node->son[0], fileout);
						fwrite(" >= ",4, 1, fileout);
						treeToCode(node->son[1], fileout);
						break;
		case AST_VECT:	fwrite(node->symbol->text, strlen(node->symbol->text), 1, fileout);
						fwrite("[", 1, 1, fileout);
						treeToCode(node->son[0], fileout);
						fwrite("]",1,1,fileout);
						break;
		case AST_PAR: 	fwrite("(", 1, 1, fileout);
						treeToCode(node->son[0], fileout);
						fwrite(")",1,1,fileout);
						break;	
		case AST_FUNC:	fwrite(node->symbol->text, strlen(node->symbol->text), 1, fileout);
						fwrite("(", 1, 1, fileout);
						if(node->son[0] != NULL) treeToCode(node->son[0], fileout);
						fwrite(")",1,1,fileout);
						break;
		case AST_NOT:	fwrite("!", 1, 1, fileout);
						treeToCode(node->son[0], fileout);
						break;									
		case AST_PARAM: fwrite(node->symbol->text, strlen(node->symbol->text), 1, fileout);
						fwrite(" : ", 3, 1, fileout);
						treeToCode(node->son[0], fileout);
						break;
							   
      	default:
	        break;
    }
	
}
	

void printValues(FILE *fout, AST *node)
{
	if(node)
		fprintf(fout, "\t.quad\t%s\n", node->son[0]->symbol->text);
	if(node->son[1])
		printValues(fout, node->son[1]);
}

//EOF