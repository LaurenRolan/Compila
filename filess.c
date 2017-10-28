void nodeWrite(AST *node, FILE *fileout){
  char stringao[50] = "/0";
  if(node){
	strcpy(stringao, "Node(");
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
	fwrite(stringao, sizeof(stringao), 1, fileout);
    fprintf(stderr, ")\n");
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