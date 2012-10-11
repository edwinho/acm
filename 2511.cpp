#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct{
  int satisfaction;
  int index;
}element;

bool operator<( element a,element b){
  if( a.satisfaction == b.satisfaction)
    return a.index > b.index;
  return a.satisfaction < b.satisfaction;
}

int main( ){
  priority_queue<element> q;
  element xka[1024];
  int n,m,k;
  int i;
  int temp[ 1024];
  double satisfaction;
  while(~scanf("%d %d %d",&n,&m,&k)){
    for( i=1;i<=m;i++){
      xka[ i].index = i;
      xka[ i].satisfaction = 0;
    }
    while( n--){
      for(i=1;i<=m;i++){
        scanf( "%lf",&satisfaction);
        xka[ i].satisfaction += satisfaction;
      }
    }
    for( i=1;i<=m;i++){
      q.push( xka[ i]);
    }
    for( i=1;i<=k;i++){
      xka[i] = q.top( );
      temp[i-1] = xka[i].index;
      q.pop( );
    }
    sort( temp,temp + k);       // 先排序，再倒序输出
    while( k--)
      printf( "%d%c",temp[k],k==0?'\n':' ');
    while( !q.empty())          // 每做完一次，清空队列
      q.pop();
  }
  return 0;
}
