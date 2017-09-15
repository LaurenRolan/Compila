#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  if(argc < 2) {
    fprintf(stderr, "Missing file name.\n Call ./a.out file_name.\n");
    exit(1);
  }
  return 0;
}
