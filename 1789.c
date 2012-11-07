#include <stdio.h>
#define N 30005

struct node{
  int n;
  int parent;
}friends[N];

void init(int i){
  i--;
  while(i>=0){
    friends[i].n = 1;
    friends[i].parent = -1;
    i--;
  }
}

int find(int x){
  while(friends[x].parent > 0){
    x = friends[x].parent;
  }
  return x;
}

void merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y)
    return;
  if(friends[x].n < friends[y].n){
    friends[x].parent = y;
    friends[y].n += friends[x].n;
  }
  else{
    friends[y].parent = x;
    friends[x].n += friends[y].n;
  }
}

int main(){
  int a, b, group, member;
  while(scanf("%d %d",&a, &b)){
    if(!a && !b)
      break;
    init(a);
    while(b--){
      scanf("%d",&group);
      int head;
      scanf("%d",&head);
      while(--group){
        scanf("%d",&member);
        merge(head,member);
      }
    }
    printf("%d\n",friends[find(0)].n);
  }
  return 0;
}
