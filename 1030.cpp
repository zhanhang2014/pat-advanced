#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int mx = 501;
const int intmax = 99999999;
int map[mx][mx], cost[mx][mx];
vector<int> pre,dist,costsum;
vector<bool> visited;
stack<int> path;
int n, m, s, d;

void dijkstra(){
	int mindist, idx;
	for (int i = 0; i < n; i++){
		mindist = intmax;
		for (int j = 0; j < n; j++){
			if ((!visited[j]) && (dist[j] < mindist)){
				mindist = dist[j];
				idx = j;
			}
		}
		visited[idx] = true;
		if (idx == d) return;
		for (int j = 0; j < n; j++){
			if (!visited[j]){
				if (dist[j]>(dist[idx] + map[idx][j])){
					dist[j] = dist[idx] + map[idx][j];
					costsum[j] = costsum[idx] + cost[idx][j];
					pre[j] = idx;
				}
				else if (dist[j] == (dist[idx] + map[idx][j])){
					if (costsum[j] > (costsum[idx] + cost[idx][j])){
						costsum[j] = costsum[idx] + cost[idx][j];
						pre[j] = idx;
					}
				}
			}
		}
	}
}

int main(){
	cin >> n >> m >> s >> d;
	pre.assign(n, -1);
	dist.assign(n, intmax);
	costsum.assign(n, intmax);
	visited.assign(n, false);
	fill(map[0], map[0] + mx*mx, intmax);
	fill(cost[0], cost[0] + mx*mx, intmax);
	int c1, c2;
	for (int i = 0; i < m; i++){
		cin >> c1 >> c2;
		cin >> map[c1][c2] >> cost[c1][c2];
		map[c2][c1] = map[c1][c2];
		cost[c2][c1] = cost[c1][c2];
	}
	for (int i = 0; i < n; i++){
		dist[i] = map[s][i];
		costsum[i] = cost[s][i];
	}
	visited[s] = true;
	dijkstra();
	int p = pre[d];
	while (p != -1){
		path.push(p);
		p = pre[p];
	}
	cout << s;
	while (!path.empty()){
		cout << ' ' << path.top();
		path.pop();
	}
	cout << ' ' << d << ' ' << dist[d] << ' ' << costsum[d] << endl;
	return 0;
}