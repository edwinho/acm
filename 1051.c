#include <stdio.h>

int main()
{
	char character[4] = {'.', '!', 'X', '#'};
	int n, day;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &day);
		int i, j;
		int DNA[16], dish1[20][20], dish2[20][20];
		for(i=0; i<16; i++)
		{
			scanf("%d", &DNA[i]);
		}
		for(i=0; i<20; i++)
		{
			for(j=0; j<20; j++)
			{
				scanf("%d", &dish1[i][j]);
			}
		}
		int sum;
		while(day--)
		{
			for(i=0; i<20; i++)
			{
				for(j=0; j<20; j++)
				{
					sum = dish1[i][j];
					if(i-1 >= 0)
						sum += dish1[i-1][j];
					if(j-1 >= 0)
						sum += dish1[i][j-1];
					if(i+1 < 20)
						sum += dish1[i+1][j];
					if(j+1 < 20)
						sum += dish1[i][j+1];
					dish2[i][j] = dish1[i][j] + DNA[sum];
					if(dish2[i][j] > 3)
						dish2[i][j] = 3;
					if(dish2[i][j] < 0)
						dish2[i][j] = 0;
				}
			}
			for(i=0; i<20; i++)
			{
				for(j=0; j<20; j++)
				{
					dish1[i][j] = dish2[i][j];
				}
			}
		}

		for(i=0; i<20; i++)
		{
			for(j=0; j<20; j++)
			{
				printf("%c", character[ dish1[i][j] ]);
			}
			printf("\n");
		}
		if(n != 0)
			printf("\n");
	}
	return 0;
}
