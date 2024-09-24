#include <stdio.h>

void main(){
	int a = 555;
	printf("|%0d|\n",a);

	printf("|%10d|\n",a);
        printf("|%-10d|\n\n",a);
	printf("Words:%10d\n",59);
        printf("Letters:%8d\n",1004);
        printf("Digits:%9d\n",8);
	float f = 0.1;
	float b = 0.2;
	printf("a = %.7f;  ",f);
	printf("b = %.7f\n",b);
	printf("a + b = %.8f\n",f+b);

}
