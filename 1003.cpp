#include <iostream>
#include <vector>
using namespace std;

const int inf = 99999999;
int n, m, c1, c2;
vector<int> dist,hand,path,tmppath;
vector<bool> visited;
vector< vector<int> > pre;
int cmap[501][501];
int maxhand = 0, cntpath = 0;

void dijkstra(){
	int mindist, idx;
	for (int i = 0; i < n; i++){
		mindist = inf;
		idx = -1;
		for (int j = 0; j < n; j++){
			if (!visited[j] && dist[j] < mindist){
				mindist = dist[j];
				idx = j;
			}
		}
		if (idx == -1) return;
		visited[idx] = true;
		for (int j = 0; j < n; j++){
			if (!visited[j]){
				if (dist[j]>dist[idx] + cmap[idx][j]){
					dist[j] = dist[idx] + cmap[idx][j];
					pre[j].clear();
					pre[j].push_back(idx);
				}
				else if (dist[j] == dist[idx] + cmap[idx][j]){
					pre[j].push_back(idx);
				}
			}
		}
	}
}

void dfs(int r){
	tmppath.push_back(r);
	if (r == c1){
		int tmphand = 0;
		for (int i = 0; i < tmppath.size(); i++){
			tmphand += hand[tmppath[i]];
		}
		if (tmphand > maxhand){
			maxhand = tmphand;
		}
		cntpath++;
		tmppath.pop_back();
		return;
	}
	for (int i = 0; i < pre[r].size(); i++){
		dfs(pre[r][i]);
	}
	tmppath.pop_back();
}

int main(){
	cin >> n >> m >> c1 >> c2;
	dist.assign(n, inf);
	hand.assign(n, 0);
	visited.assign(n, false);
	pre.resize(n);
	fill(cmap[0], cmap[0] + 501 * 501, inf);
	for (int i = 0; i < n; i++){
		cin >> hand[i];
	}
	int idx1, idx2, tmp;
	for (int i = 0; i < m; i++){
		cin >> idx1 >> idx2 >> tmp;
		cmap[idx1][idx2] = tmp;
		cmap[idx2][idx1] = tmp;
	}
	dist[c1] = 0;
	dijkstra();
	dfs(c2);
	cout << cntpath << ' ' << maxhand << endl;
	return 0;
}