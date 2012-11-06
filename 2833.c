/* 用树记录各个元素之间的友谊关系，树根记录整棵树的元素个数 */

#include <stdio.h>
#define N 100002

struct node{
  int n;     //朋友数量
  int parent;
}friends[N];

void init(int i){
  while(i>0){
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
  int a, b, count, x, y;
  char ch;
  count = 1;
  while(scanf("%d %d",&a, &b)!=EOF && a){
    init(a);
    if(count != 1)
      printf("\n");
    printf("Case %d:\n",count++);
    while(b--){
      getchar();
      scanf("%c",&ch);
      if(ch == 'M'){
        scanf("%d %d",&x, &y);
        merge(x,y);
        continue;
      }
      if(ch == 'Q'){
        int tmp;
        scanf("%d",&x);
        tmp = find(x);
        printf("%d\n",friends[tmp].n);
      }
    }
  }
  return 0;
}
