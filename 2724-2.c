/* 用最小堆实现优先队列 */
#include <stdio.h>
#include <string.h>

int n;

struct node{
  int priority,parameter;
  char name[10];
}message[60001];

void swap(int a, int b){
  strcpy(message[0].name,message[a].name);
  message[0].parameter = message[a].parameter;
  message[0].priority = message[a].priority;

  strcpy(message[a].name,message[b].name);
  message[a].parameter = message[b].parameter;
  message[a].priority = message[b].priority;

  strcpy(message[b].name,message[0].name);
  message[b].parameter = message[0].parameter;
  message[b].priority = message[0].priority;
  
}

void down(int a){
  int parent, son;
  parent = a;
  while(parent <= n/2){
    son = parent << 1;
    if(son+1<=n && message[son].priority > message[son+1].priority)
      son++;
    if(message[parent].priority > message[son].priority)
      swap(parent, son);
    else
      break;
    parent = son;
  }
}

void up(int a){
  int parent, son;
  son = a;
  while(son > 1){
    parent = son >> 1;
    if(message[parent].priority > message[son].priority)
      swap(parent, son);
    else
      break;
    son = parent;
  }
}

void push(char* name,int x, int y){
  strcpy(message[n].name, name);
  message[n].parameter = x;
  message[n].priority = y;
  up(n);
}

void pop(){
  swap(1,n);
  n--;
  down(1);
}

int empty(){
  if(n)
    return 0;
  return 1;
}

int main( ){
  char str[4];

  while(scanf( "%s",str)!=EOF ){
    if( !strcmp( str,"GET")){
      if( empty( ))
        printf("EMPTY QUEUE!\n");
      else {
        printf("%s %d\n",message[1].name,message[1].parameter);  
        pop( );
      }
    }else {
      if( !strcmp( str,"PUT")){
        scanf("%s %d %d",message[0].name,&message[0].parameter,&message[0].priority);
        n++;
        push(message[0].name,message[0].parameter,message[0].priority);
      }
    }
  }
  return 0;
}
