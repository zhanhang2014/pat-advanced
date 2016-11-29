#include <iostream>
#include <vector>
using namespace std;

const int inf = 99999999;
int n, m, s, d;
vector<int> dist, cost, shortest, shortpath, tmppath, fastpath;
vector<int> visited;
vector< vector<int> > fastest;
int cmap[501][501], tcost[501][501];
int minnode=inf;

void findshortest(){
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
			if (!visited[j] && cmap[idx][j] < inf){
				if (dist[j]>dist[idx] + cmap[idx][j]){
					dist[j] = dist[idx] + cmap[idx][j];
					cost[j] = cost[idx] + tcost[idx][j];
					shortest[j] = idx;
				}
				else if (dist[j] == dist[idx] + cmap[idx][j]){
					if (cost[j]>cost[idx] + tcost[idx][j]){
						cost[j] = cost[idx] + tcost[idx][j];
						shortest[j] = idx;
					}
				}
			}
		}
	}
}

void findfastest(){
	int mincost, idx;
	for (int i = 0; i < n; i++){
		mincost = inf;
		idx = -1;
		for (int j = 0; j < n; j++){
			if (!visited[j] && cost[j] < mincost){
				mincost = cost[j];
				idx = j;
			}
		}
		if (idx == -1) return;
		visited[idx] = true;
		for (int j = 0; j < n; j++){
			if (!visited[j] && tcost[idx][j] < inf){
				if (cost[j]>cost[idx] + tcost[idx][j]){
					cost[j] = cost[idx] + tcost[idx][j];
					fastest[j].clear();
					fastest[j].push_back(idx);
				}
				else if (cost[j]==cost[idx] + tcost[idx][j]){
					fastest[j].push_back(idx);
				}
			}
		}
	}
}

void dfsshort(int r){
	shortpath.push_back(r);
	if (r == s) return;
	dfsshort(shortest[r]);
}

void dfsfast(int r){
	tmppath.push_back(r);
	if (r == s){
		if (tmppath.size() < minnode){
			minnode = tmppath.size();
			fastpath = tmppath;
		}
		tmppath.pop_back();
		return;
	}
	for (int i = 0; i < fastest[r].size(); i++){
		dfsfast(fastest[r][i]);
	}
	tmppath.pop_back();
}

int main(){
	cin >> n >> m;
	dist.assign(n, inf);
	cost.assign(n, inf);
	shortest.resize(n);
	fastest.resize(n);
	visited.assign(n, false);
	fill(cmap[0], cmap[0] + 501 * 501, inf);
	fill(tcost[0], tcost[0] + 501 * 501, inf);
	int v1,v2,oneway, length, time;
	for (int i = 0; i < m; i++){
		cin >> v1 >> v2 >> oneway >> length >> time;
		cmap[v1][v2] = length;
		tcost[v1][v2] = time;
		if (oneway == 0){
			cmap[v2][v1] = length;
			tcost[v2][v1] = time;
		}
	}
	cin >> s >> d;
	dist[s] = 0;
	cost[s] = 0;
	findshortest();
	cost.assign(n, inf);
	visited.assign(n, false);
	cost[s] = 0;
	findfastest();
	dfsshort(d);
	dfsfast(d);
	cout << "Distance = " << dist[d];
	if (shortpath == fastpath){
		cout << "; ";
	}
	else{
		cout << ": ";
		for (int i = shortpath.size() - 1; i >= 0; i--){
			cout << shortpath[i];
			if (i != 0) cout << " -> ";
		}
		cout << endl;
	}
	cout << "Time = " << cost[d] << ": ";
	for (int i = fastpath.size() - 1; i >= 0; i--){
		cout << fastpath[i];
		if (i != 0) cout << " -> ";
	}
	return 0;
}
