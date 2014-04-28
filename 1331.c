#include<stdio.h>

int main()
{
    int a, b, c, d;
    for(a=5; a<=200; a++)
    {
        for(b=2; b<=a-3; b++)
        {
            for(c=b+1; c<=a-2; c++)
            {
                for(d=c+1; d<=a-1; d++)
                {
                    if(a*a*a == b*b*b+c*c*c+d*d*d)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
                }
            }
        }
    }

    return 0;
}
