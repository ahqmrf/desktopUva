#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, area, x, s, m1, n1, m2, n2, m3, n3, r, ta, tb, tc;
	int cases;
	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%lf %lf %lf %lf %lf %lf %lf", &r, &m1, &n1, &m2, &n2, &m3, &n3);
		a = n1 * n3;
		b = m1 * n3;
		c = m1 * m3;
		ta = a + b;
		tb = b + c;
		tc = c + a;
		s = (ta + tb + tc) / 2;
		area = sqrt(s * (s - ta) * (s - tb) * (s - tc));
		x = r * s / area;
		printf("%.4lf\n", x * x * area);
	}
	return 0;
}