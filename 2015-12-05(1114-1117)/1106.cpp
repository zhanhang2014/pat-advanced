#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int sup,depth;
	vector<int> ret;
};

vector<Node> node;
int n;
double p, r;

int main(){
	cin >> n >> p >> r;
	node.resize(n);
	int m, k;
	for (int i = 0; i < n; i++){
		cin >> m;
		for (int j = 0; j < m; j++){
			cin >> k;
			node[i].ret.push_back(k);
			node[k].sup = i;
		}
	}
	node[0].depth = 0;
	queue<int> que;
	que.push(0);
	int cur, minchain = n, len;
	vector<int> rets;
	while (!que.empty()){
		cur = que.front();
		que.pop();
		if (cur != 0) node[cur].depth = node[node[cur].sup].depth + 1;
		if (node[cur].ret.empty()){
			rets.push_back(cur);
			if (node[cur].depth < minchain) minchain = node[cur].depth;
			continue;
		}
		len = node[cur].ret.size();
		for (int i = 0; i < len; i++)
			que.push(node[cur].ret[i]);
	}
	len = rets.size();
	int cnt = 0;
	for (int i = 0; i < len; i++)
		if (node[rets[i]].depth == minchain) cnt++;
	while (minchain--)
		p *= (0.01*r + 1);
	printf("%.4lf %d\n", p, cnt);
	return 0;
}