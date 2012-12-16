#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 101
#define MAX 65536

struct node{
  double x, y;
}city[N];

double map[N][N];

double len(int x, int y){
  return sqrt((city[x].x-city[y].x)*(city[x].x-city[y].x)
              +(city[x].y-city[y].y)*(city[x].y-city[y].y));
  
}

double prim(int n){
  int flag[N];
  double dist[N];
  int i, j, state;
  double min, sum;
  state = 1;
  memset(flag, 0, sizeof(flag));
  for(i=1;i<=n;i++)
    dist[i] = MAX;
  flag[1] = 1;
  dist[state] = 0;
  sum = 0;
  for(i=1; i<n; i++){
    for(j=1; j<=n; j++)
      if(!flag[j] && dist[j]>map[state][j])
        dist[j] = map[state][j];

    min = MAX;
    for(j=1; j<=n; j++)
      if(!flag[j] && min>dist[j]){
        min = dist[j];
        state = j;
      }
    flag[state] = 1;
    sum += dist[state];
  }
  return sum;
}

int main(){
  int n;
  int count = 1;
  while(scanf("%d",&n) && n!=0){
    if(count>1)
      printf("\n");
    
    int i, j;
    for(i=1; i<=n; i++)
      scanf("%lf%lf",&city[i].x, &city[i].y);
    for(i=1; i<=n; i++)
      for(j=1; j<=n; j++)
        map[i][j] = (i==j?0:len(i,j));
    
    printf("Case #%d:\n",count++);
    printf("The minimal distance is: %.2lf\n",prim(n)); 
  }
  return 0;
}
