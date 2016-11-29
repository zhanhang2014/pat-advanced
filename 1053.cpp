#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	int w;
	vector<int> child;
};

vector<Node> node;
vector<int> path;
int target;

bool cmp(int a, int b){
	return node[a].w > node[b].w;
}

void dfs(int index,int num,int sum){
	if (sum > target) return;
	if (sum == target){
		if (node[index].child.size() != 0) return;
		for (int i = 0; i < num; i++){
			printf("%d", node[path[i]].w);
			if (i != num - 1) printf(" ");
			else printf("\n");
		}
		return;
	}
	for (int i = 0; i < node[index].child.size(); i++){
		int idx = node[index].child[i];
		path[num] = idx;
		dfs(idx, num + 1, sum + node[idx].w);
	}
}

int main(){
	int n, m, sr, sz;
	cin >> n >> m >> target;
	node.resize(n);
	path.resize(n);
	for (int i = 0; i < n; i++)
		cin >> node[i].w;
	for (int i = 0; i < m; i++){
		cin >> sr >> sz;
		node[sr].child.resize(sz);
		for (int j = 0; j < sz; j++)
			cin >> node[sr].child[j];
		sort(node[sr].child.begin(), node[sr].child.end(), cmp);
	}
	dfs(0,1,node[0].w);
	return 0;
}