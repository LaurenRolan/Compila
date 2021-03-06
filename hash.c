//Feito por Lauren Silva Rolan Sampaio
// e Nicolas Eymael da Silva
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

HASH_NODE *Table[HASH_SIZE];

void hashToAsm(FILE *fout)
{
	int i;
	HASH_NODE *node;
	
	fprintf(fout, "\n### TEMP VARS ###\n");
	for(i=0; i<HASH_SIZE; ++i)
		for(node=Table[i]; node; node = node->next)
			if(node->type == SYMBOL_VAR && node->datatype == 0)
				fprintf(fout, "\t.data\n"
						"%s:\n"
						"\t.quad\t0\n", node->text);
	
	fprintf(fout, "\n### STRINGS ###\n");
	fprintf(fout, "\nstringgod:"
			"\t\t#nosso compilador só lida com variaveis do tipo LONG por enquanto\n"
			"\t.string\t\"%%ld\"\n");	
	for(i=0; i<HASH_SIZE; ++i)
		for(node=Table[i]; node; node = node->next)
			if(node->type == SYMBOL_LIT_STRING)
				fprintf(fout, "\nstring%d:\n"
					"\t.string\t%s\n", i, node->text);
}

HASH_NODE *makeLabel(void)
{
	static int factorySerialNumber = 0;
	char nameBuffer[256];
	sprintf(nameBuffer, "___Label_%d___", factorySerialNumber++);
	return hashInsert(SYMBOL_LABEL, nameBuffer);
}

HASH_NODE *makeTemp(void)
{
	static int factorySerialNumber = 0;
	char nameBuffer[256];
	sprintf(nameBuffer, "___variavelTemporaria_%d___", factorySerialNumber++);
	return hashInsert(SYMBOL_VAR, nameBuffer);
}

HASH_NODE *makeNumber(int number)
{
	char nameBuffer[256];
	sprintf(nameBuffer, "%d", number);
	return hashInsert(SYMBOL_VAR, nameBuffer);
}

void hashCheckUndeclared(char *text, int lineNumber)
{
  int i;
  HASH_NODE *node;
  for(i=0; i<HASH_SIZE; ++i)
    for(node = Table[i]; node; node = node->next)
      if(node->type == SYMBOL_ID && (strcmp(text,node->text)==0))
		fprintf(stderr, "Identifier %s at line %d is not declared.\n", node->text, lineNumber); //Adicionar linha  
}

void hashInit(void)
{
  int i;
  for(i=0; i < HASH_SIZE; ++i)
    Table[i]=NULL;
}

int hashAddress(char *text) 
{
  int address = 1;
  int i;
  for(i=0; i<strlen(text); ++i)
    address = (address + text[i])%HASH_SIZE + 1;
  return address - 1;
}

int typeToDatatype(int type)
{
	switch(type)
	{
		case SYMBOL_LIT_INT: 
		case SYMBOL_LIT_CHAR: return DATATYPE_BYTE;
		case SYMBOL_LIT_REAL: return DATATYPE_FLOAT;
		default: return 0;
	}
}

HASH_NODE *hashInsert(int type, char *text)
{
  HASH_NODE *newnode;
  int address;
  if((newnode = hashFind(text)) != NULL)
	return newnode; 
  address = hashAddress(text);
  newnode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));
  newnode->type = type;
  newnode->datatype = typeToDatatype(type);
  newnode->text = calloc(strlen(text)+1, sizeof(char));
  strcpy(newnode->text, text);
  newnode->next = Table[address];
  Table[address] = newnode;
  return newnode;
}

void hashPrint(void)
{
  int i;
  HASH_NODE *node;
  for(i=0; i<HASH_SIZE; ++i)
    for(node=Table[i]; node; node = node->next)
		{
		printf("Table[%d] has %s of datatype = %d and ", i, node->text, node->datatype);
		switch(node->type)
			{
			case SYMBOL_LIT_INT: printf("type = LIT_INT.\n"); break;
			case SYMBOL_LIT_REAL: printf("type = LIT_REAL.\n"); break;
			case SYMBOL_LIT_CHAR: printf("type = LIT_CHAR.\n"); break;
			case SYMBOL_LIT_STRING: printf("type = LIT_STRING.\n"); break;
			case SYMBOL_ID: printf("type = ID.\n"); break;
			case SYMBOL_FUN: printf("type = FUNC.\n"); break;
			case SYMBOL_VEC: printf("type = VECT.\n"); break;
			case SYMBOL_VAR: printf("type = VAR.\n"); break;
			case SYMBOL_LABEL: printf("type = LABEL.\n"); break;
			}
		}
}

HASH_NODE * hashFind(char *text)
{
  HASH_NODE *node;
  int address;
  address = hashAddress(text);
  for(node=Table[address]; node!=NULL; node = node->next)
  {
    if(!(strcmp(text, node->text)))
       return node;
  }
  return NULL;
}
