a: long = 9;
b: long = 8;
c: long [5] 0 1 2 3 4;
resul: long [10];
soma: long = 0;
i: long = 0;

(long) funcao_soma (op1s: long, op2s: long)
{
	print	"Estou somando ", op1s, " com ", op2s, ":\n";
	return	op1s + op2s
}

(long) funcao_le (lido: long)
{
	print	"Estou lendo b: ";
	read > b;
	return	b;
}

(long) main()
{
		resul[0] = funcao_soma(a, c[1]);
		print	"A soma da ", resul[0], "\n";
		if(resul[0] >= 10) then
		{
			b = funcao_le(b);
			print "b tem o valor \t", b;
		}
		else
		{
			b = funcao_soma (a, c[2]);
			print "b tem o valor\t", b;
		};
			
		while (b > 1)
		{
			print	b, "\t";
			b = b - 1;
		}
}