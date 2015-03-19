#include <stdio.h>

int main(void)
{
	double lx, ly, ux, uy, cx, cy, r, R, w, W, L;
	int cases;
	scanf("%d", &cases);
	while(cases--) {
		scanf("%lf %lf %lf %lf %lf %lf %lf", &lx, &ly, &ux, &uy, &cx, &cy, &r);
		L = ux - lx;
		w = uy - ly;
		W = L*6.0 / 10.0;
		if(w == W) {
			
			double x, y;
			x = (lx*5.5 + ux*4.5)/10.0;
			y = (ly + uy) / 2.0;
			
			if(x == cx && y == cy) {
				R = L / 5.0;

				if(R == r) puts("YES");
				else puts("NO");
			}
			else puts("NO");
		}
		else puts("NO");
	}
	return 0;
}