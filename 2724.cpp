#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

struct node{
  int priority,parameter,num;
  char message[ 16];

  bool operator<( const node &a)const{
    if( priority != a.priority)return priority > a.priority;
    else return num>a.num;
    /*
      priority_queue不保证对于相同优先级的消息先入队列的排前面，
      所以根据入队列的顺序另外给消息一个编号，如果优先级相同则比较编号。
    */
  }
  void print( ){
    printf( "%s %d\n",message,parameter);
  }
};

int main( ){
  char str[4];
  priority_queue<node> p;
  node temp;
  int num = 0;
  while(scanf( "%s",str)!=EOF ){
    if( !strcmp( str,"GET")){
      if( p.empty( ))
        printf( "EMPTY QUEUE!\n");
      else {
        temp = p.top( );
        temp.print( );
        p.pop( );
      }
    }else {
      if( !strcmp( str,"PUT")){
        scanf("%s %d %d",temp.message,&temp.parameter,&temp.priority);
        temp.num = num++;
        p.push(temp);
      }
    }
  }
  return 0;
}
