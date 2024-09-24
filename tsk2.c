#include <stdio.h>

void main(){
	signed int max_int = 2147483647;
	printf("%d \n",max_int);
	printf("%d \n",max_int+1);
	unsigned int max_int2 = 4294967295;
        printf("%d \n",max_int2);
        printf("%d \n",max_int2+1);
	char min_char = -128;
        printf("%d \n",min_char);
        printf("%d \n",min_char-1);

}
