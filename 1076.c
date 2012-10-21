/* 老师是建议我们用图的遍历来做，不过，我感觉贪心会更好。 */
#include <stdio.h>
#include <algorithm>
#define max 1001
using namespace std;

typedef struct{
  int start,end;
  int id;
}gene;

bool compare( gene x,gene y){
  return x.end < y.end;
}

int main( ){
  int n,i;
  gene exon[max];
  while( scanf( "%d",&n) && n!=0){
    for(i=0;i<n;i++){
      scanf("%d%d",&exon[i].start,&exon[i].end);
      exon[i].id = i+1;
    }
    sort( exon,exon + n, compare);
    int temp = exon[0].end;
    printf( "%d",exon[0].id);
    for( i=1;i<n;i++){
      if( exon[i].start > temp){
        printf( " %d",exon[i].id);
        temp = exon[i].end;
      }
    }
    printf( "\n");
  }
  return 0;
}
