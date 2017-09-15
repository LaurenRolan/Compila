#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void hashInit(void)
{
  int i;
  for(i=0; i < HASH_SIZE; ++i)
    Table[i]=0;
}

int hashAddress(char *text) 
{
  int address = 1;
  int i;
  for(i=0; i<strlen(text); ++i)
    address = (address + text[i])%HASH_SIZE + 1;
  return address - 1;
}

HASH_NODE *hashInsert(int type, char *text)
{
  HASH_NODE *newnode;
  int address;
  
  address = hashAddress(text);
  newnode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));
  newnode->type = type;
  newnode->text = calloc(strlen(text)+1, sizeof(char));
  strcpy(newnode->text, text);
  newnode->next = Table(address);
  Table[address] = newnode;
  return newnode;
}

void hashPrint(void)
{
  int i;
  HASH_NODE *node;
  for(i=0; i<HASH_SIZE; ++i)
    for(node=Table[i]; node; node = node->next)
      printf("Table[%d] has %s\n", i, node->text);
}

HASH_NODE * hashFind(char *text)
{
  HASH_NODE *node;
  int address;
  address = hashAddress(text);
  for(node=Table[address]; node; node->next)
  {
    if(!(strcmp(text, node->text))
       return node;
  }
  return null;
}
