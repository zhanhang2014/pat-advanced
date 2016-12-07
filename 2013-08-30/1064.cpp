#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//init
int n;
vector<int> preOrder;

//function PreTraversal
//recrusivly get the CBT index
void PreTraversal(int root){
  if(root>n)
    return;
  PreTraversal(2*root);
  preOrder.push_back(root);
  PreTraversal(2*root+1);
}

int main(){
  int num[1001],level[1001];
  //input
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>num[i];
  //algorithm
  sort(num,num+n);
  PreTraversal(1);
  for(int i=0;i<n;i++)
    level[preOrder[i]]=num[i];
  //output
  for(int i=1;i<n;i++)
    cout<<level[i]<<" ";
  cout<<level[n];
  return 0;
}