#include <stdio.h>
void main(){//Программа находит проводит проверку на простое число
	int a,n=2;
	scanf("%d",&a);
	for (int n = 2; n<=a;n++){
	if(a%n==0) break;
	else{
	if ((n+1)==a) puts("1");
	else puts("0");
}
}
}
