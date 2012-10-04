#include <iostream>
#include <queue>
using namespace std;
#include <stdio.h>
typedef struct point{
  int x,y;
  int count;
}point;
queue<point>q;
int map[9][9];  //棋盘大小
int b_x,b_y;  //终点坐标
int move[8][2] = {
  {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}
};  //可能移动的方向
//用广度优先遍历搜索最短路径
int bfs(point s){
  map[ s.x][ s.y] = 1;
  int x,y;
  point head,tail;
  q.push( s);
  while( !q.empty( )){
    head = q.front( );
    q.pop( );
    if( head.x== b_x && head.y == b_y)
      return head.count;
    for( int i=0;i<8;i++){
      x = head.x + move[ i][ 0];
      y = head.y + move[ i][ 1];
      if( x>0&&x<9&&y>0&&y<9&&map[ x][ y]==0){
        tail.x=x;
        tail.y=y;
        tail.count = head.count+1; //不能用++，否则会影响count的值
        q.push( tail);
        map[ x][ y] = 1;
      }
    }
  }

}
int main( ){
  char a[3],b[3];  //起点，终点
  int a_x,a_y;  //起点坐标
  point head;
  while( scanf("%s %s",a,b) != EOF){
    a_x = a[0]-'a'+1;
    a_y = a[1]-'0';
    b_x = b[0]-'a'+1;
    b_y = b[1]-'0';
    head.count = 0;
    head.x = a_x;
    head.y = a_y;
    //标记棋盘上未走过的点为0
    for( int i=0;i<9;i++)
      for( int j=0;j<9;j++)
        map[ i][ j] = 0;
    //清空上次队列中剩余的元素
    while( !q.empty( ))
      q.pop( );
    int moves = bfs( head);
    printf( "To get from %s to %s takes %d knight moves.\n",a,b,moves);
  }
  return 0;
}
