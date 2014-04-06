#include <stdio.h>

int main()
{
	double result;
	int num, i;
	printf("# Cards  Overhang\n");
	while(scanf("%d",&num) != EOF)
	{
		result = 0;
		for(i=1; i<=num; i++)
		{
			result += 1.0/(2*i);
		}
		printf("%5d%10.3f\n", num, result);
	}
	return 0;
}
