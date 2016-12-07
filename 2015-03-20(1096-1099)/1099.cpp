#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
  int id;
  int data;
  int left, right;
};
vector<Node> tree;
vector<int> inorder;
vector<int> data;

void intraversal(int root){
  if (root == -1) return;
  intraversal(tree[root].left);
  inorder.push_back(tree[root].id);
  intraversal(tree[root].right);
}

int main(){
  int n;
  cin >> n;
  tree.resize(n);
  data.resize(n);
  int l, r;
  for (int i = 0; i < n; i++){
    cin >> l >> r;
    tree[i].left = l;
    tree[i].right = r;
    tree[i].id = i;
  }
  for (int i = 0; i < n; i++){
    cin >> data[i];
  }
  intraversal(0);
  sort(data.begin(), data.end());
  for (int i = 0; i < n; i++){
    tree[inorder[i]].data = data[i];
  }
  queue<int> que;
  que.push(0);
  int cur;
  while (!que.empty()){
    cur = que.front();
    que.pop();
    if (cur != 0) cout << ' ';
    cout << tree[cur].data;
    if (tree[cur].left != -1) que.push(tree[cur].left);
    if (tree[cur].right != -1) que.push(tree[cur].right);
  }
  return 0;
}