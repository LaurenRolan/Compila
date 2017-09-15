%{
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

%}
%%


%%

#include "main.c"

yywrap(){
  return 1;
}
