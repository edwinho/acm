#include<stdio.h>
#include<memory.h>

<<<<<<< HEAD
int result[51], source[51];

void P2I(int n)
{
    int count, i, j;
    for(i=1; i<=n; i++)
    {
        count = 0;
        for(j=1; j<=n; j++)
        {
            if(source[j] > i)
                count++;
            else if(source[j] == i)
                break;
        }
        result[i] == count;
    }
=======
int source[51], result[51];

void P2I(int n)
{
	int count, i, j;
	for(i=1; i<=n; i++)
	{
		count = 0;
		for(j=1; j<=n; j++)
		{
			if(source[j] > i)
				count++;
			else if(source[j] == i)
				break;
		}
		result[i] = count;
	}
	for(i=1; i<n; i++)
		printf("%d ", result[i]);
	printf("%d\n", result[n]);
>>>>>>> 8e54d4b01b7b5605db6b48a8b32bfb43b375dc0b
}

void I2P(int n)
{
<<<<<<< HEAD
    int count, i, j;
    for(i=1; i<=n; i++)
    {
        count = 0;
        for(j=1; j<=n; j++)
        {
            if(result[j] == 0)
                count++;
            if(count > source[i])
            {
                result[j] = i;
                break;
            }
        }
    }
=======
	memset(result, 0, sizeof(int)*51);
	int count, i, j;
	for(i=1; i<=n; i++)
	{
		count = 0;
		for(j=1; j<=n; j++)
		{
			if(result[j] == 0)
				count++;
			if(count > source[i])
			{
				result[j] = i;
				break;
			}
		}
	}
	for(i=1; i<n; i++)
		printf("%d ", result[i]);
	printf("%d\n", result[n]);
>>>>>>> 8e54d4b01b7b5605db6b48a8b32bfb43b375dc0b
}

int main()
{
<<<<<<< HEAD
    int n, i, j;
    char type;
    while(1)
    {
        memset(result, 0, sizeof(int)*51 );
        memset(source, 0, sizeof(int)*51 );
        scanf("%d", &n);
        if(n != 0)
        {
            scanf("%c", &type);
            for(i=1; i<=n; i++)
                scanf("%d", &source[i]);
            if(type == 'P')
                P2I(n);
            else if(type == 'I')
                I2P(n);
        }
        else
            break;
        for(i=1; i<n; i++)
            printf("%d ",result[i]);
        printf("%d\n", result[n]);
    }
}
=======
	int n, i;
	char type;
	while(1)
	{
		scanf("%d", &n);
		if(n != 0)
		{
			scanf("%c", &type);
			for(i=1; i<=n; i++)
				scanf("%d", &source[i]);
			if(type == 'P')
				P2I(n);
			else if(type == 'I')
				I2P(n);
		}
		else
			break;	
	}
	return 0;
}
>>>>>>> 8e54d4b01b7b5605db6b48a8b32bfb43b375dc0b
