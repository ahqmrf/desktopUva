#include <stdio.h>
#define int64 long long int

int main()
{
	int nod[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int dd, mm, yyyy, days, i;
	scanf("%d %d %d %d", &dd, &mm, &yyyy, &days);
	while(1) {
		if(!(yyyy%400) || (!(yyyy%4) && (yyyy%100))) i =366;
		else i= 365;
		if(days-i < 0) break;
		days -= i;
		yyyy++;
	}

	mm--;
	while(1) {
		i = nod[mm%12];

		if(mm%12 == 1) 
		{
			if(!(yyyy%400) || (!(yyyy%4) && (yyyy%100))) i++;
		}
		if(days - i < 0) break;
		days -= i; 
		mm++;
	}
	
	i = nod[mm%12];
	if(mm%12 == 1) {
		if(!(yyyy%400) || (!(yyyy%4) && (yyyy%100))) i++;
	}
	if(days > i - dd) {
		days -= (i-dd);
		mm++;
	}
	else days += dd;
	printf("%d %d %d\n", days, (mm%12)+1, yyyy);

	return 0;
}