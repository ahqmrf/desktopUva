#include <cstdio> 
long sumofDigit(long bal, long sal, long balsal)
{
	if (bal == 0) return 0; 
	long m = bal % 10; 
	return bal / 10 * 45 * sal + m * balsal+ m * (m - 1)/2 * sal + sumofDigit(bal / 10, sal* 10, balsal+ m * sal);	
} 

int main(){
	long x,y; 
	while(scanf("%ld %ld",&x,&y)==2){ 
		if(x==0 &&y==0) return 0; 
		printf("%ld\n",sumofDigit(y,1,1)-sumofDigit(x-1,1,1)); 
	} 
	return 0; 
}