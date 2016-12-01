#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int cmap[1001][1001];
vector<bool> visited;

void dfs(int r){
	visited[r] = true;
	for (int i = 1; i <= n; i++){
		if (visited[i] == false && cmap[r][i] == 1) dfs(i);
	}
}

int main(){
	cin >> n >> m >> k;
	int c1, c2;
	for (int i = 0; i < m; i++){
		cin >> c1 >> c2;
		cmap[c1][c2] = 1;
		cmap[c2][c1] = 1;
	}
	for (int i = 0; i < k; i++){
		visited.assign(n + 1, false);
		cin >> c1;
		int cnt = 0;
		visited[c1] = true;
		for (int j = 1; j <= n; j++){
			if (!visited[j]){
				dfs(j);
				cnt++;
			}
		}
		cout << cnt-1 << endl;
	}
	return 0;
}