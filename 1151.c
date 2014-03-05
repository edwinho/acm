#include <stdio.h>


int main()
{
    int ncase, n;
    char str[1000], word[50];
    int strlength, wordlength, i, j;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d", &n);
        char c;
        scanf("%c", &c);
        while(n--)
        {
            strlength = 0;
            while(scanf("%c",&str[strlength]) != EOF && str[strlength] != '\n')
                strlength++;
            j = 0;
            for(i=0; i<strlength; i++)
            {
                word[j++] = str[i];
                if(word[j-1] == ' ')
                {
                    j--;
                    while(j)
                        printf("%c", word[--j]);
                    printf(" ");
                    j = 0;
                }
            }
            while(j)
                printf("%c",word[--j]);
            printf("\n");
        }
        if(ncase != 0)
            printf("\n");
    }
    return 0;
}
