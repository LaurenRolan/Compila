//Feito por 
//Lauren Silva Rolan Sampaio
//Nicolas Eymael da Silva
#include <stdio.h>
#include <stdlib.h>
#include "astree.h"

extern int yyparse(FILE *fileout);

int main(int argc, char **argv){
	
  	FILE *fileout;
	
  	if(argc < 3) {
    		fprintf(stderr, "Missing file name.\n Call ./etapa4 <FileInput> <FileOutput>.\n");
    		exit(1);
  	}
  

  	if ((yyin = fopen(argv[1], "r")) && (fileout = fopen(argv[2], "w")))
  	{
		yyparse(fileout);
  	}
  
  	else
  	{
	     	fprintf(stderr,"nao deu");
	     	exit(2);
  	}

  	printf("\n");
	
  	fclose(yyin);
	fclose(fileout);
	
	hashPrint();
	
	return 0;
}
