#include <stdio.h>

int main() {
	int cases, allowed = 0;
	double length, width, depth, weight;
	scanf("%d", &cases);
	while(cases--) {
		scanf("%lf%lf%lf%lf", &length, &width, &depth, &weight);
		if((length + width + depth <= 125 || (length <= 56 && width <= 45 && depth <= 25)) && weight <= 7) {
			puts("1");
			allowed++;
		}
		else puts("0");
	}
	printf("%d\n", allowed);
	return 0;
}