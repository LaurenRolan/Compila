// UFRGS - Compiladores - Marcelo Johann - 2017/2



a: long=0;
b: long=111;
c: long=333;

(long) main(n : long, k : long)
  {

  b = 2;
  if(b || 1) then
	  print "oi1\n";
  print "tchau1\n", (2);
  
  c = funcao();
  print (c), "\n";
  
  }
  
 (long) funcao()
 {
  while(a<4)
  {
	  print (a), "\n";
	  a = a+1;
  };
  
  a = 1+2+3+4;
  print (a), "\n";
  
  return (a);
 }


/*

long a = 222;
long b = 111;
long c = 0;
long x = 333;
long nicolas = 0;


long func()
{
	if(a){
	printf("OI EU SOU GOKU");
	return c+x;}
	
	if(!a){
	printf("nao");
	return a+b;}
}

long main()
{
if(c && a)
	printf("oi1\n");

else
printf("tchau1\n");

c = func();

}

*/

