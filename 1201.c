#include<stdio.h>
#include<memory.h>

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
}

void I2P(int n)
{
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
}

int main()
{
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
