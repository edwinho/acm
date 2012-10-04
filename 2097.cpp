#include <stdio.h>
#include <queue>
#include <string.h>
#include <iostream>
using namespace std;
int chessboard[ 9][ 9];
int visited[ 9][9][5];            // 记录探测过点的最小cost
int move[ 4][ 2] = {
  {1,0},{0,1},{-1,0},{0,-1}
};
int startX,startY,endX,endY;
struct point{
  int x,y;
  int state;
};
queue<point> q;
// 不同的state的cost值导致的最少值有所不同，所以都要保留
int bfs( ){
  point temp,next;
  int x,y,cost;
  while( !q.empty( )){
    temp = q.front( );
    q.pop( );
    for( int i=0;i<4;i++){
      x = temp.x + move[ i][ 0];
      y = temp.y + move[ i][ 1];
      if( x>0 && x<9 && y>0 && y<9){
        cost = temp.state*chessboard[x][y]+visited[temp.x][temp.y][temp.state];
        next.state = (temp.state*chessboard[x][y]%4)+1;
        next.x = x;
        next.y = y;
        if( visited[x][y][next.state]>cost){
          visited[x][y][next.state] = cost;
          q.push( next);
        }
      }
    }
  }
  cost = visited[ endX][ endY][ 1];
  for( int i=2;i<=4;i++)
    if(cost>visited[endX][endY][i])
      cost=visited[endX][endY][i];
  return cost;
}
int main( ){
  point p;
  while(scanf("%d %d %d %d",&startX,&startY,&endX,&endY)){
    if(startX==0 && startY==0 && endX==0 && endY==0)break;
    //    memset( visited,100000000,sizeof( visited));
    /* 上面这个语句不能将visited全部变为大数
       在网上看到：清为128之前的数就是一个大数16843009等，清128之后就是负数，清0就是0
       所以我猜测memset函数只对ASCII作用。
     */
    while( !q.empty( ))
      q.pop( );
    for( int i=1;i<9;i++)
      for( int j=1;j<9;j++)
        scanf( "%d",&chessboard[i][j]);
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            for(int k=1;k<=4;k++)
                visited[i][j][k]=65536;
        }
    }
    visited[startX][startY][ 1] = 0;
    chessboard[startX][startY] = 65536;
    p.x = startX;
    p.y = startY;
    p.state = 1;
    q.push( p);
    printf( "%d\n",bfs( ));
  }
  return 0;
}
