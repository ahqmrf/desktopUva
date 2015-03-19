#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <list>
#include <queue>

using namespace std;

long long int leapYearCount (long long int year)
{
	long long int count = ((year/4) + (year/400) - (year/100));
	return count;
}

int main (void)
{
	int cases, case_no = 0;
	string blankLine;
	cin >> cases;
	getline(cin, blankLine);
	while(cases--){
		char date1[50], date2[50];
		gets(date1);
		gets(date2);
		int day;
		long long int year;
		char month[15], comma;
		long long int startingYear, endingYear;
		sscanf(date1,"%s %d %c %lld", month, &day, &comma, &year);
		if(!strcmp(month,"January")) startingYear = year;
		else if(!strcmp(month,"February")) startingYear = year;
		else startingYear = year+1;

		sscanf(date2,"%s %d %c %lld", month, &day, &comma, &year);
		if(!strcmp(month,"January")) endingYear = year - 1;
		else if(!strcmp(month,"February") && day<29) endingYear = year - 1;
		else endingYear = year;

		long long int count1 = leapYearCount(startingYear-1);
		long long int count2 = leapYearCount(endingYear-1);
		if(!(endingYear%400) || (!(endingYear%4) && (endingYear%100))) count2++;

		printf("Case %d: %lld\n", ++case_no, count2-count1);

	}

	return 0;
}

