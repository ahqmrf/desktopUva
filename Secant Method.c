#include <stdio.h>
#include <math.h>

#define f(x) (sin((x))+3*cos((x))-2)

int main()
{
	double x0 = 0, x1 = 1.5;
	
	while(1)
	{
		double x2 = ((x0*f(x1)-x1*f(x0))/(f(x1)-f(x0)));
		printf("%4.5lf %4.5lf %4.5lf %4.5lf %4.5lf %4.5lf\n", x0, f(x0), x1, f(x1), x2, f(x2));
		if(fabs(x1-x2) < 0.1e-3) break;
		x0 = x1, x1 = x2;
	}
	return 0;
}