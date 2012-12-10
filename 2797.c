/* 最短路径 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define len 102

double v[len][len];

void max(int i, int j, int k){
  double temp;
  if(v[i][k]!=0 && v[k][j]!=0){
    /* 权值为0的边是不存在 */
    temp = v[i][k] * v[k][j];
    if(temp > v[i][j]){
      v[i][j] = temp;
    }
  }
}

int main(){
  
  int i, j, x, n, m;
  double k;
  
  while(scanf("%d",&n) && n!=0){

    memset(v,0,sizeof(v));
    scanf("%d",&m);

    /* 用邻接矩阵保存每条街及其逃生概率 */
    for(x=0;x<m;x++){
      scanf("%d %d %lf",&i,&j,&k);
      v[i][j] = k/100;
      v[j][i] = k/100;
    }

    /* Floyd算法 */
    for(k=1;k<=n;k++)
      for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
          max(i, j, k);

    printf("%.6f percent\n",v[1][n]*100);
  }
  
  return 0;
}
