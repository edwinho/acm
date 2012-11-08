#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define max 128
int map[max][max];

struct node{
  int squadtree;
  int quadtree;
  int value;
  
  node (): squadtree(1),quadtree(1){
  for(int i=0;i<4;i++)
    p[i] = 0;
  }
  node *p[4];
  bool operator != (const node& q) const{
    /* 判断四个子区域是否为全色 */
	if(value == 2 || value != q.value)
      return 1;
	else  
      return 0;
  }
  bool operator == (const node& q) const{
    /* 判断两棵子树是否相同 */
    if(this == &q)
      return 1;
    if(value != q.value)
      return 0;
    for(int i=0;i<4;i++){
      if( !(*p[i] == *q.p[i]))
        return 0;
    }
    return 1;
  }
};

node *root;
vector <node*> v;               /* 保存所有非叶子树 */

node *check_subtree(node *t){   /* 检查有没有一样的子树 */
  for(int i=0;i<v.size();i++){
    if(*v[i] == *t){
      delete t;
      return v[i];
    }
  }
  v.push_back(t);
  return t;
}

node *DFS(int r,int c,int s){
  bool flag=1;
  node *temp=new node();
  int i;
  
  if(s==1){
    temp->value = map[r][c];
    return temp;
  }
  s/=2;
  temp->p[0]=DFS(r,c,s);
  temp->p[1]=DFS(r,c+s,s);
  temp->p[2]=DFS(r+s,c,s);
  temp->p[3]=DFS(r+s,c+s,s);
  for(i=1;i<4;i++)
  {
    if(*temp->p[0]!=*temp->p[i]) {
      flag=0;
      break;
    }
  } //不用合并
  if( flag ){
    temp->value = temp->p[0]->value;        // 合并
    for(i=0;i<4;i++){
      delete (temp->p[i]);
      temp->p[i]=0;
    }
  }
  else {
    temp->value = 2;
    for(int i=0;i<4;i++){
      temp->quadtree += temp->p[i]->quadtree;
      temp->squadtree += temp->p[i]->squadtree;

      temp->p[i]->squadtree = 0;
      /* 压缩后清零，防止重复加 */
    }
    temp = check_subtree(temp);
  } // 不合并
  return temp;
}

void reset_vector(){
  for(int i=0;i<v.size();i++)
    delete v[i];
  v.clear();
}

int main(){
  int a, b, n;
  while(scanf("%d%d",&a, &b)){
    if(!a && !b)
      break;
    int i, j;
    n = 1;
    char ch;
    while(n<a || n<b){
      n <<= 1;                  /* 矩阵边长要为2的幂 */
    }
    for(i=0; i<n; i++)
      for(j=0; j<n; j++){
        if(i<a && j<b){
          scanf(" %c", &ch);
          /* 如果用"%d"，程序会认为整行01字符为一个整数
           * 所以用" %c"，加了这个空格，程序就会每一个01字符读一次
           */
          map[i][j] = ch - '0';
        }
        
        else
          map[i][j] = 0;
      }
    
    root = DFS(0,0,n);
    printf("%d %d\n",root->quadtree,root->squadtree);

    reset_vector();
  }
  return 0;
}
