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
			case TAC_ADD: fprintf(fout, "\nmovq\t %s(%%rip), %%rdx\n"
					      "movq\t %s(%%rip), %%rax\n"
					      "addq\t %%rdx, %%rax\n", tac->op1->text, tac->op2->text); break;
			case TAC_PRINT: fprintf(fout, "\nmovq\t %s(%%rip), %%rax\n"
						"movq\t %%rax, %%rsi\n"
						"movl\t$printable, %%edi\n"
						"movl\t$0, %%eax\n"
						"call\tprintf\n", tac->res->text); break;
			
		}
	}
}
