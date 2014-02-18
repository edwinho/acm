#include <stdio.h>
#include <math.h>
int main(void) {
	int n, i, t;
	float x, y, z;
	float pi = 3.1415926;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		scanf("%f %f", &x, &y);
		z = x*x + y*y;
		z = M_PI * z / 2;
		if((int)z % 50)
		{
			z += 50;
		}
		t = z / 50;
		printf("Property %d: This property will begin eroding in year %d.\n", i, t);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
