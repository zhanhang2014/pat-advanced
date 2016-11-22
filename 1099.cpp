#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
  int value;
  int left=-1;
  int right=-1;
};
  
node tree[100];
int num[100],cnt=0;

void PreTraversal(int root){
  if(root==-1)
    return;
  PreTraversal(tree[root].left);
  tree[root].value=num[cnt++];
  PreTraversal(tree[root].right);
}

void LevelTraversal(int root){
  queue<int> que;
  que.push(root);
  while(!que.empty()){
    int index=que.front();
    que.pop();
    if(index!=root)
      cout<<" ";
    cout<<tree[index].value;
    if(tree[index].left!=-1)
      que.push(tree[index].left);
    if(tree[index].right!=-1)
      que.push(tree[index].right);
  }
}

int main(){
  int n;
  //input
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>tree[i].left>>tree[i].right;
  for(int i=0;i<n;i++)
    cin>>num[i];
  //algorithm
  sort(num,num+n);
  PreTraversal(0);
  //output
  LevelTraversal(0);
  return 0;
}