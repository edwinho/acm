#include <stdio.h>
#include <queue>
#include <string.h>
#include <iostream>
using namespace std;
struct point{
  int x,y,z;
  int time;
};
char dungeon[30][30][30];       // 地牢
bool visited[30][30][30];       // 记录走过的点
int move[ 6][ 3] = {
  {1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}
};
queue<point> q;
int l,r,c;
int bfs( ){
  point temp,next;
  int x,y,z,t;
  while( !q.empty( )){
    temp = q.front( );
    q.pop( );
    t = temp.time;
    for( int i=0;i<6;i++){
      x = temp.x + move[i][0];
      y = temp.y + move[i][1];
      z = temp.z + move[i][2];
      if(visited[x][y][z]==0 && x>=0 && x<l && y>=0 && y<r && z>=0 && z<c){
        next.x = x;
        next.y = y;
        next.z = z;
        visited[x][y][z] = 1;
        if( dungeon[x][y][z] == 'E'){
          return t+1;
        }
        if( dungeon[x][y][z] == '.'){
          next.time = t+1;
          q.push( next);
        }
      }
    }
  }
  return -1;
}

int main( ){
  int totalTime;
  point p;
  while( scanf( "%d %d %d",&l,&r,&c)){
    if( l==0 && r==0 && c ==0) break;
    memset(dungeon,0,sizeof( dungeon)); // 初始化
    memset(visited,0,sizeof( visited));
    while( !q.empty( ))
      q.pop( );
    for( int i=0;i<l;i++){
      for( int j=0;j<r;j++){
        scanf( "%s",dungeon[ i][ j]);
      }
      // printf("\n");
    }
    for( int i=0;i<l;i++)
      for( int j=0;j<r;j++)
        for( int k=0;k<c;k++)
          if( dungeon[i][j][k]=='S'){
            p.x = i;
            p.y = j;
            p.z = k;
            p.time = 0;
            visited[i][j][k] = 1; // 标记开始位置为走过
            q.push( p);
            k=c;j=r;i=l;// 要逃的只有自己，读到一个'S'时即可跳出所有循环
          }
    totalTime = bfs( );
    if( totalTime != -1)
      printf("Escaped in %d minute(s).\n",totalTime);
    else
      printf( "Trapped!\n");
  }
  return 0;
}
