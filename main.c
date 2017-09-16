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
	  
		while(var != 0)
		{
			var=yylex();
      if(var!=0)
			  fprintf(stderr,"O retorno eh %d\n",var);
		}
  }
  else fprintf(stderr,"nao deu");
	
  return 0;
}
