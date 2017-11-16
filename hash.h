//Feito por 
//Lauren Silva Rolan Sampaio
//Nicolas Eymael da Silva
#ifndef HASH_HEADER
#define HASH_HEADER

#define HASH_SIZE 256


#define SYMBOL_LIT_INT 1
#define SYMBOL_LIT_REAL 2
#define SYMBOL_LIT_CHAR 3
#define SYMBOL_LIT_STRING 4

//Natureza
#define SYMBOL_ID 5
#define SYMBOL_FUN 6
#define SYMBOL_VEC 7
#define SYMBOL_VAR 8

//Datatype
#define DATATYPE_INT 1
#define DATATYPE_REAL 2

typedef struct node {
  struct node *next;
  char *text;
  int type;
  int datatype;
}HASH_NODE;


int typeToDatatype(int type);
void hashInit(void);
int hashAddress(char *text);
HASH_NODE *hashInsert(int type, char *text);
void hashPrint(void);
HASH_NODE * hashFind(char *text);
void hashCheckUndeclared(void);
#endif
