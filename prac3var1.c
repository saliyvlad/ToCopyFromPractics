#include <stdio.h>
void main(){//Программа ищет наибольший общий делитель 
	int n1,n2;
	scanf("%d %d",&n1,&n2);
	for (int i=n1; !(n1%i==0 && n2 % i ==0); i--){
		printf("%d\n",i);
}
}
