/* 最短路径 */
#include <stdio.h>

#define len 21
#define MAX 65535

int v[len][len];

void max(int i, int j, int k){
  int temp;
  temp = v[i][k] + v[k][j];
  if(temp < v[i][j])
    v[i][j] = temp;

}

int main(){
  
  int i, j, k, x, y, n, m;
  int count = 1;
  
  while(scanf("%d",&n) != EOF){

    /* 用邻接矩阵储存这个图 */
    for(i=0; i<len; i++)
      for(j=0; j<len; j++)
        v[i][j] = MAX;
    
    for(i=0; i<n; i++){
      scanf("%d",&m);
      v[1][m] = 1;
      v[m][1] = 1;
    }
    for(i=2; i<20; i++){
      scanf("%d",&n);
      for(j=0; j<n; j++){
        scanf("%d",&m);
        v[i][m] = 1;
        v[m][i] = 1;
      }
    }
    
    /* Floyd算法 */
    for(k=1;k<=20;k++)
      for(i=1;i<=20;i++)
        for(j=1;j<=20;j++)
          max(i, j, k);

    scanf("%d",&n);
    printf("Test Set #%d\n",count++);
    for(i=0; i<n; i++){
      scanf("%d%d",&x,&y);
      printf("%d to %d: %d\n",x,y,v[x][y]);
    }
    printf("\n");
    
  }
  
  return 0;
}
