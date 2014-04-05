#include <stdio.h>
#include <string.h>

#define MAX(a,b) (a>b)?a:b

int main()
{
    int num[101], num1[101], num2[101];
    char str1[101], str2[101];
    int i, j, len1, len2, len;
    while(~scanf("%s%s", str1, str2))
    {
        memset(num, 0, sizeof(num));
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        len1 = strlen(str1);
        len2 = strlen(str2);

        /*转换为20进制*/
        for(i=0; i<len1; i++)
        {
            if(str1[i]>='0' && str1[i]<='9')
                num1[len1-i] = str1[i] - '0';
            else
                num1[len1-i] = str1[i]-'a'+10;
        }
        for(i=0; i<len2; i++)
        {
            if(str2[i]>='0' && str2[i]<='9')
                num2[len2-i] = str2[i] - '0';
            else
                num2[len2-i] = str2[i]-'a'+10;
        }

        /*求和*/
        len = MAX(len1, len2);
        for(i=1; i<len+1; i++)
        {
            num[i] = num[i-1]/20 + num1[i] + num2[i];
            num[i-1] = num[i-1] % 20;
        }

        /*处理002+003这种情况*/
        for(i=len+1; i>1; i--)
        {
            if(num[i])
                break;
        }

        for(j=i; j>0; j--)
        {
            if(num[j] <= 9)
                printf("%d",num[j]);
            else
                printf("%c",num[j]-10+'a');

        }
        printf("\n");
    }

    return 0;
}
