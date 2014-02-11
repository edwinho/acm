#include <stdio.h>

int main(void) {
	int num, i, m, n;
	double sum;
	scanf("%d",&num);
	for(i=1; i<=num; i++)
	{
		scanf("%d %d", &m, &n);
		if(m%2 && n%2)
		{
			sum = m*n + 0.41;
		}
		else
		{
			sum = m*n;
		}
		printf("Scenario #%d:\n", i);
		printf("%.2f\n\n", sum);
	}
	return 0;
}
