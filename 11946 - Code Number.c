#include <stdio.h>

int main()
{
	char ch;
	int cases;
	char original[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,";
	char encoded[] =  "48CD3F6H1JKLMN09QR57UVWXY2 .,";
	int loop;
	char in[130];
	for(loop = 0; loop < 29; loop++)
		in[encoded[loop]] = original[loop];


	scanf("%d\n", &cases);
	while(cases--)
	{
		int enter = 0;
		while(scanf("%c", &ch))
		{
			if(ch == '\n') enter++;
			if(enter == 2) break;
			
			if(ch == '\n' && enter == 1) puts("");
			else
			{	
				printf("%c", in[ch]);
				enter = 0;
			}
		}
		if(cases) puts("");
	}
	return 0;
}