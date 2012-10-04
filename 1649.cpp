#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <queue>
#define max 1000 //一个足够大的值
struct point{
  int x,y;
  int time;
  bool guard;//记录是否为guard
};
//移动方向上下左右
int move[ 4][ 2] = {
  {-1,0},{0,1},{1,0},{0,-1}
};
char map[ max][ max];//监狱
bool flag[max][max];//记录走过的格
queue<point> q;
int n,m;

int bfs( ){
  point temp,next;
  int a,b,t;
  
  while(!q.empty( ) ){
    temp = q.front( );
    q.pop( );
    t = temp.time;
    //如果是guard，要放入队列两次
    if( map[temp.x][temp.y]=='x'&& temp.guard==1){
      temp.guard = 0;
      q.push( temp);
    }
    else {
      for( int i=0;i<4;i++){
        a = temp.x + move[ i][ 0];
        b = temp.y + move[ i][ 1];
        if(flag[a][b]==0 && a>=0 && a<n && b>=0 && b<m){
          next.x = a;
          next.y = b;
          flag[ a][ b] = 1;
          switch(map[ a][ b]){
          case 'a':return t+1;
            break;
          case '.':
            next.time = t+1;
            q.push( next);
            break;
          case 'x':
            next.time = t+2;
            next.guard = 1;
            
            q.push( next);
            break;
          case '#':
            break;
          }
        }
      }//for
    }
  }//while
  return -1;
}

int main( ){
  point r;
  int totalTime;
  while(~scanf( "%d %d",&n,&m) ){
    memset( map,0,sizeof( map));
    memset( flag,0,sizeof( flag));
    //将map清零
    while( !q.empty( ))
      q.pop( );
    for( int i=0;i<n;i++)
      scanf( "%s",map[ i]);
    for( int x=0;x<n;x++)
      for( int y=0;y<m;y++)
        //请angel的每个friend先放入队列中
        if( map[x][y] == 'r'){
          r.x = x;
          r.y = y;
          r.time = 0;
          q.push(r);
        }
    totalTime = bfs( );
    if( totalTime != -1)
      printf( "%d\n",totalTime);
    else
      printf( "Poor ANGEL has to stay in the prison all his life.\n");
  }
  return 0;
}
