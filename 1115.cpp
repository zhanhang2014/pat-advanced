#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int v;
	node *left, *right;
};
int cnt[1001] = { 0 };
int maxdepth = -1;

node *buildtree(node *root, int v){
	if (root == NULL){
		root = new node();
		root->v = v;
		root->left = NULL;
		root->right = NULL;
	}
	else if (v <= root->v) root->left = buildtree(root->left, v);
	else root->right = buildtree(root->right, v);
	return root;
}

void dfs(node *root, int depth){
	if (root == NULL){
		maxdepth = max(maxdepth, depth);
		return;
	}
	cnt[depth]++;
	dfs(root->left, depth + 1);
	dfs(root->right, depth + 1);
}

int main(){
	int n, k;
	cin >> n;
	node *root = NULL;
	for (int i = 0; i < n; i++){
		cin >> k;
		root = buildtree(root, k);
	}
	dfs(root, 0);
	cout << cnt[maxdepth - 1] << " + " << cnt[maxdepth - 2] << " = " << cnt[maxdepth - 1] + cnt[maxdepth - 2] << endl;
	return 0;
}