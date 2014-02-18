#include <stdio.h>

int main(void)
{
	double e = 2.5, t = 2;
	int n, i;
	printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");
	for(i=3; i<=9; i++)
	{
		t *= i;
		e += 1/t;
		printf("%d %.9lf\n", i, e);
	}
	return 0;
}