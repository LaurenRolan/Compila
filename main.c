#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  FILE *fh;
  if(argc < 2) {
    fprintf(stderr, "Missing file name.\n Call ./a.out file_name.\n");
    exit(1);
  }

  if ((fh = fopen(argv[1], "r")))
        yyin = fh;
  yylex();
  return 0;
}
