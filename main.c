#include <stdio.h>

int main(int argc, char **argv){
  if(argc < 2) {
    fprinf(stderr, "Missing file name.\n Call ./a.out file_name.\n");
    exit(1);
  }
  return 0;
}
