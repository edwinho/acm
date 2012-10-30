#include <stdio.h>
#include <string.h>

int bag[102400],array[102400],count,sum;

bool DP()                       /* 01背包 */
{  
    int i,k;  
    for(i=0; i<count; i++)  
        for(k=sum; k>=array[i]; k--)  
            if( bag[k-array[i]] + array[i] > bag[k] )  
                bag[k] = bag[k-array[i]] + array[i];  
    return bag[sum] == sum ;  
} 

int main( ){
  int i,k,x,temp,n,test=0;
  bool flag;
  while(1){
    sum = 0;
    count = 0;
    for(i=1;i<=6;i++){
      scanf("%d",&n);
      sum += i*n;
      k = x = temp = 0;
      while(1){
        x = 1 << k++;
        if(temp+x > n)
          break;
        temp += x;
        array[count++] = x*i;
      }
      x = n-temp;
      if(x)
        array[count++] = x*i;
    }
    if(!sum)
      break;
    printf("Collection #%d:\n",++test);
    if(sum % 2){
      printf("Can't be divided.\n\n");
      continue;
    }

    sum >>= 1;
    memset(bag, 0, sizeof(bag));
    flag = DP();
    if(flag)
      printf("Can be divided.\n\n");
    else
      printf("Can't be divided.\n\n");
  }
  return 0;
}
