#include <stdio.h>
#include <string.h>
#include <memory.h>

int main()
{
    char num[101];
    int result[101];
    int n, length, i, j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        memset(result, 0, sizeof(int)*101);
        while(1)
        {
            scanf("%s", num);
            length = strlen(num);
            if(length==1 && num[0]=='0')
            {
                break;
            }
            else
            {
                for(j=0; j<length; j++)
                {
                    //求和，并将大整数逆序
                    result[j] += num[length-1-j] - '0';
                }
            }
        }
        //求进位
        for(j=0; j<100; j++)
        {
            result[j+1] += result[j]/10;
            result[j] = result[j]%10;
        }

        //输出
        for(j=100; j>=0; j--)
        {
            if(result[j] != 0)
            {
                int k;
                for(k=j; k>=0; k--)
                    printf("%d",result[k]);
                printf("\n");
                break;
            }
        }
        if(i != n-1)
            printf("\n");
    }


    return 0;
}
