#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){
  FILE *fh;
  int var=8;
  if(argc < 2) {
    fprintf(stderr, "Missing file name.\n Call ./a.out file_name.\n");
    exit(1);
  }
  

  if ((fh = fopen(argv[1], "r")))
  {
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
    
  }
  
  else fprintf(stderr,"nao deu");
  
  printf("\n");
  hashPrint();
	
  return 0;
}
