#include <stdio.h>

void main(){
	for ( int a,b,n=a; (n%a!=0 || n%b!=0); n++){
	if (a%b == 0) printf("%d", n);
}	 	
}

