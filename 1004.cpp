#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > tree;
vector<int> leaf;
int maxdepth = -1;

void dfs(int idx, int depth){
	if (tree[idx].size()==0){
		leaf[depth]++;
		maxdepth = max(maxdepth, depth);
		return;
	}
	for (int i = 0; i < tree[idx].size(); i++)
		dfs(tree[idx][i], depth + 1);
}

int main(){
	int n, m, k, node, c;
	cin >> n >> m;
	tree.resize(100);
	leaf.resize(100);
	for (int i = 0; i < m; i++){
		cin >> node >> k;
		for (int j = 0; j < k; j++){
			cin >> c;
			tree[node].push_back(c);
		}
	}
	dfs(1, 0);
	cout << leaf[0];
	for (int i = 1; i <= maxdepth; i++)
		cout << ' ' << leaf[i];
	return 0;
}