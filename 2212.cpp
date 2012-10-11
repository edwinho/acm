#include <stdio.h>
#include <queue>
using namespace std;

typedef struct{
  int id;
  int period;
  int inti_period;
}argus;

bool operator<( argus a,argus b){
  if( a.period == b.period)
    return a.id > b.id;
  return a.period > b.period;
}
int main( ){
  priority_queue<argus> q;
  argus query;
  int id,period,k;
  char str[10];
  while( scanf("%s",str) && str[0]!='#'){
    scanf( "%d %d",&id,&period);
    query.id = id;
    query.period = period;
    query.inti_period = period;
    q.push( query);
  }
  scanf( "%d",&k);
  while( k--){
    query = q.top( );
    q.pop( );
    printf("%d\n",query.id);
    query.period += query.inti_period;
    q.push( query);
  }
  return 0;
}
