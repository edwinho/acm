#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int num[1024],n,m;
vector<int> v;
bool flag;
void dfs(int len,int x,int sum){ // len为等式中元素个数，x为待检查的数，sum已加上的和
  if( sum > num[m-1])return;
  for( ;x<m;x++){
    if( len >= m-x)return;
    if( len == 0){              // 填满后，检查是否有相等
      for( int i=x;i<m;i++){
        if( sum == num[ i]){
          printf("%d",v[0]);
          for( int j=1;j<v.size();j++)
            printf( "+%d",v[ j]);
          printf( "=%d\n",sum);
          flag = true;
        }
      }
      return;                   // 输出完一个等式就要return,不然会重复
    }
    v.push_back( num[ x]);      // 每增加一个数，dfs一次
    dfs( len-1,x+1,sum+num[ x]);
    v.pop_back( );              // dfs完之后，弹出来
  }
}

int main( ){
  scanf("%d",&n);
  while(n--){
    scanf( "%d",&m);
    for( int i=0;i<m;i++)
      scanf( "%d",&num[i]);
    sort( num,num + m);         // 先排序，方便DFS
    flag = false;
    for( int j=2;j<m;j++){      // 在数组中找j个加数组成的等式
      v.clear();
      dfs( j,0,0);
    }
    if(!flag)
      printf("Can't find any equations.\n");
    printf( "\n");
  }
  return 0;
}
