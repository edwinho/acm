#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define max 516
char map[max][max];
int pos;
char bin[max*max];

struct quadtree{
  char value[3];
  quadtree *q[4];
  bool operator == (const quadtree& p) const{
	if(strcmp(value,"1")==0 || strcmp(value,p.value)!=0)
      return 0;
	else  
      return 1;
  }
};

quadtree *root;

quadtree *DFS(int r,int c,int s){
  // char value[3];
  int i;
  bool f=1;
  quadtree *temp=new quadtree;
  // value值为 “00”,“01”,“1“ 00表示全0,01表示全1,1表示混合点
  if(s==1){
    temp->value[0]='0';
    temp->value[1]='0'+map[r][c];
    temp->value[2]=0;
    return temp;
  }
  s/=2;
  temp->q[0]=DFS(r,c,s);
  temp->q[1]=DFS(r,c+s,s);
  temp->q[2]=DFS(r+s,c,s);
  temp->q[3]=DFS(r+s,c+s,s);
  for(i=1;i<4;i++)
  {
    if(!(*temp->q[0]==*temp->q[i])) {
      f=0;
      break;
    }
  } //不用合并
  if( f ){
    strcpy(temp->value,temp->q[0]->value); // 合并
    for(i=0;i<4;i++){
      delete temp->q[i];
      temp->q[i]=0;
    }
  }
  else {
    strcpy(temp->value,"1");
  } // 不合并
  return temp;
}

void out(char *s, int len){
    int t = 0;
    for(int i=0;i<len;i++){
        t *= 2;
        t += s[i] -'0';
    }
    printf("%X", t);
}

void output(){
    pos = 0;
    queue <quadtree *> q;
    q.push(root);
    int t;
    quadtree *p;
    // 生成01串
    while(!q.empty()){
        p = q.front();
        q.pop();
        t = strlen(p->value);
        strcpy(bin + pos, p->value);
        pos += t;
        if(p->value[0] == '0'){
            delete p;
            continue;
        }
        for(int i=0;i<4;i++){
            q.push(p->q[i]);
        }
        delete p;
    }
    bin[pos] = 0;
    // 输出生成的串
    t = pos % 4;
    if(t ){
        out(bin, t);
    }
    while(t < pos){
        out(bin + t, 4);
        t += 4;
    }
    printf("\n");
}

int main(){
  int test, n;
  scanf("%d", &test);
  while(test--){
    scanf("%d", &n);
    int i, j;
    for(i=0; i<n; i++)
      for(j=0; j<n; j++)
        scanf("%d", &map[i][j]);
    root = DFS(0,0,n);
    output();
    
  }
  return 0;
}
