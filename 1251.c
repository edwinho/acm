#include <stdio.h>

int main()
{
    int n, hi[101];
    int i=1, j, total, k, avg;
    while(scanf("%d", &n) && n!=0)
    {
        total = 0;
        k = 0;
        for(j=0; j<n; j++)
        {
            scanf("%d", &hi[j]);
            total += hi[j];
        }
        avg = total/n;
        for(j=0; j<n; j++)
        {
            if(avg < hi[j])
                k += (hi[j]-avg);
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",i++,k);
    }
    return 0;
}
