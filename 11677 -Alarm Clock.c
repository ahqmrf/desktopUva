#include<stdio.h>
int main (void)
{
	int H1, M1, H2, M2;
	while(scanf("%d%d%d%d", &H1, &M1, &H2, &M2) == 4)
	{
		if(H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0) break;
		int minutes;
		if(H2 == 0) H2 = 24;
		if(M2 >= M1) minutes = M2 - M1;
		else
		{
			M2 += 60;
			H2--;
			minutes = M2 - M1;
		}
		if(H2 >= H1)
		{
			minutes += ((H2 - H1) * 60);
		}

		else
		{
			H2 += 24;
			minutes += ((H2 - H1) * 60);
		}

		printf("%d\n", minutes);
	}

	return 0;

}

