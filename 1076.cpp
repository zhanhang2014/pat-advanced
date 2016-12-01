#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int lv;
	vector<int> fans;
};

int n, l;
vector<Node> node;
vector<bool> visited;

void bfs(int f){
	node[f].lv = 0;
	visited.assign(n + 1, false);
	queue<int> que;
	que.push(f);
	visited[f] = true;
	int cnt = 0;
	while (!que.empty()){
		int cur = que.front();
		que.pop();
		for (int i = 0; i < node[cur].fans.size(); i++){
			int idx = node[cur].fans[i];
			if (!visited[idx] && node[cur].lv < l){
				visited[idx] = true;
				node[idx].lv = node[cur].lv + 1;
				que.push(idx);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}

int main(){
	int num, f;
	cin >> n >> l;
	node.resize(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> num;
		for (int j = 0; j < num; j++){
			cin >> f;
			node[f].fans.push_back(i);
		}
	}
	cin >> num;
	for (int i = 0; i < num; i++){
		cin >> f;
		bfs(f);
	}
	return 0;
}