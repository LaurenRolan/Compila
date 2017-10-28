//Feito por Lauren Silva Rolan Sampaio
// e Nicolas Eymael da Silva
#include <stdio.h>
#include <stdlib.h>
#include "astree.h"

extern int yyparse(FILE *fileout);

int main(int argc, char **argv){
	
  FILE *fileout;
	
  if(argc < 3) {
    fprintf(stderr, "Missing file name.\n Call ./a.out file_INPUT file_OUTPUT.\n");
    exit(1);
  }
  

  if ((yyin = fopen(argv[1], "r")) && (fileout = fopen(argv[2], "w")))
  {
	yyparse(fileout);
  }
  
  else fprintf(stderr,"nao deu");
  
  printf("\n");
  //hashPrint();
	
  return 0;
}
