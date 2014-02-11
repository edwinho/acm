#include <stdio.h>

int main(void) {
	float num, sum=0;
	int i;
	for(i=0; i<12; i++)
	{
		scanf("%f", &num);
		sum += num;
	}
	printf("$%.2f\n", sum/12);
	return 0;
}
