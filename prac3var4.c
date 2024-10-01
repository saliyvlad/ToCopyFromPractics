#include <stdio.h>
void main(){//Программа вычисляет простое число  
	int a,n;
	for (a=5,n = 2; n<a && a%n!=0;n++);
{	
	if (n==a) puts("1");
	else puts("0");
}
}
