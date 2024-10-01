#include <stdio.h>
void main(){//Программа вычисляет факториал 
	int a,b,c=1;
	scanf("%d %d",&a,&b);
	for (int n = a; n%a!=0||n%b!=0;n++){
		c *=n;
}
printf("%d\n",c*b);
}
