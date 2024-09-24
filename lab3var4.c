#include <stdio.h>
void main(){
	int n,a;
	for (a=16, n=2; n<a && a%n!=0; n++);
{
	if (n==a) puts("1");
	else puts("0");
}
}
