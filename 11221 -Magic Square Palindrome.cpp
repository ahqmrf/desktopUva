#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int cases;
	scanf("%d\n", &cases);
	for(int c = 1; c <= cases; c++) {
		string str;
		char ch;
		while(scanf("%c", &ch)== 1 && ch != '\n')
			if((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A'))
				str += ch;

		int len = str.length();
		int s = sqrt(len);
		string str2 = str;
		reverse(str2.begin(), str2.end());
		printf("Case #%d:\n", c);
		if(s * s != len || str != str2) puts("No magic :(");
		else printf("%d\n", s);
	}
	return 0;
}
