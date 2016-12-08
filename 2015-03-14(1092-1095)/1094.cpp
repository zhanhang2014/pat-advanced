#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	int id;
	vector<int> child;
};
vector<Node> node;
vector<int> gen;
vector<bool> isleave;
int maxdepth = 0;

void dfs(int root, int depth){
	gen[depth]++;
	maxdepth = max(maxdepth, depth);
	if (isleave[root]) return;
	for (int i = 0; i < node[root].child.size(); i++){
		dfs(node[root].child[i], depth+1);
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	node.resize(n + 1);
	gen.assign(n + 1, 0);
	isleave.assign(n + 1, true);
	int r, k, c;
	for (int i = 0; i < m; i++){
		cin >> r >> k;
		isleave[r] = false;
		for (int j = 0; j < k; j++){
			cin >> c;
			node[r].child.push_back(c);
		}
	}
	if (n == 1) {
		cout << "1 1\n";
		return 0;
	}
	dfs(1, 0);
	int large = 0, dp = 0;
	for (int i = 1; i <= maxdepth; i++){
		if (gen[i]>large){
			large = gen[i];
			dp = i;
		}
	}
	cout << large << ' ' << dp+1 << endl;
	return 0;
}