/* 堆实现优先队列 */
#include <stdio.h>

int n = 0;

struct argus{
  int id;
  int period;
  int inti_period;
}query[3001];

void swap(int a, int b){
  query[0].id = query[a].id;
  query[0].period = query[a].period;
  query[0].inti_period = query[a].inti_period;

  query[a].id = query[b].id;
  query[a].period = query[b].period;
  query[a].inti_period = query[b].inti_period;

  query[b].id = query[0].id;
  query[b].period = query[0].period;
  query[b].inti_period = query[0].inti_period;
  
}

void down(int a){
  int parent, son;
  parent = a;
  while(parent <= n/2){
    son = parent << 1;
    if(son+1<=n && query[son].period > query[son+1].period)
      son++;
    /* 左右孩子比较:period相同比较id大小 */
    if(son+1<=n && query[son].period == query[son+1].period && query[son].id > query[son+1].id)
      son++;
    if(query[parent].period > query[son].period)
      swap(parent, son);
    
    else{
      /* period相等时比较id大小 */
      if(query[parent].period==query[son].period && query[parent].id>query[son].id){

        swap(parent, son);
      }
      else
        break;
    }
    
    parent = son;
  }
}

void up(int a){
  int parent, son;
  son = a;
  while(son > 1){
    parent = son >> 1;
    if(query[parent].period > query[son].period)
      swap(parent, son);
    else{
      /* period相等时比较id大小 */
      if(query[parent].period==query[son].period && query[parent].id>query[son].id){

        swap(parent, son);
      }
      else
        break;
    }

    son = parent;
  }
}

void push(int i, int j, int k){
  n++;
  query[n].id = i;
  query[n].period = j;
  query[n].inti_period = k;
  
  up(n);
}

void pop(){
  swap(1,n);
  n--;
  down(1);
}


int main( ){
  int id,period,inti,k;
  char str[10];
  while( scanf("%s",str) && str[0]!='#'){
    scanf( "%d %d",&id,&period);
    push(id, period, period);
  }
  scanf( "%d",&k);
  while( k--){
    printf("%d\n",query[1].id);
    id = query[1].id;
    period = query[1].period + query[1].inti_period;
    inti = query[1].inti_period;
    pop();
    push(id, period, inti);
  }
  return 0;
}
