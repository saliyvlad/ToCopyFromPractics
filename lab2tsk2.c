#include <stdio.h>
// 1C = 33,8F
void main(){
	float a;
	char b;
	printf("%c",b);
	printf("Input temperature:");
	scanf("%f%c",&a,&b);
	if (b == 70 || b == 'f'){
	a = (a-32)*5/9;
	printf("output temparature:%fC\n", a);
}else if (b == 67){
	a = (a*9)/5+32;
	printf("output temparature:%fF\n",a);
}else printf("Output Error\n");
}
