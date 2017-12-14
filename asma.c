#include "asma.h"
#include <stdio.h>
#include <stdlib.h>

void asmGenerator (char *filename, TAC *code)
{
	FILE *fout;
	TAC *tac = code;
	if(!(fout = fopen(filename,, 'w')))
	{
		fprintf(stderr, "Unable to open ASM file.\n");
		exit(5);
	}
	for(tac = code; tac; tac = tac->next)
	{
		switch(tac->type)
		{
			case TAC_ADD: fprintf(fout, ""); break;
			
		}
	}
}
