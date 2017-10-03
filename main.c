//Feito por Lauren Silva Rolan Sampaio
// e Nicolas Eymael da Silva
#include <stdio.h>
#include <stdlib.h>
extern int yyparse(void);

int main(int argc, char **argv){
  //FILE *fh;
  //int var=8;
  if(argc < 2) {
    fprintf(stderr, "Missing file name.\n Call ./a.out file_name.\n");
    exit(1);
  }
  

  if ((yyin = fopen(argv[1], "r")))
  {
	/*
        yyin = fh;
      initMe();
	  
		while(isRunning() && (var=yylex()))
		{
			if(var!=0)
      {
        fprintf(stderr,"O retorno eh %d : lineNumber = %d :     ",var, getLineNumber());
        printf("%s\n",yytext);
      }
	
		}
    */
	yyparse();
  }
  
  else fprintf(stderr,"nao deu");
  
  printf("\n");
  hashPrint();
  //fclose(fh);
	
  return 0;
}
