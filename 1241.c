#include <stdio.h>

int main()
{
	float a, b, c;
	int i = 1;
	while(1)
	{
		scanf("%f %f %f",&a ,&b, &c);
		if(a==0 && b==0 && c==0)
			break;
		printf("Triangle #%d\n", i++);
		if(a==-1)
		{
			a = c*c - b*b; 
			if(a >= 0)
				printf("a = %.3f\n\n", sqrt(a));
			else
				printf("Impossible.\n\n");
		}
		if(b==-1)
		{
			b = c*c - a*a;
			if(b >= 0)
				printf("b = %.3f\n\n", sqrt(b));
			else
				printf("Impossible.\n\n");
		}
		if(c==-1)
		{
			c = sqrt(a*a + b*b);
			printf("c = %.3f\n\n", c);
		}
	}
	return 0;
}
