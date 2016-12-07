#include <map>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int n, k;
const int inf = 999999999;
int cmap[202][201];
vector<int> happy, dist, temppath, path;
vector<bool> visited;
vector< vector<int> > pre;
map<string, int> cityidx;
map<int, string> idxcity;
int maxvalue = 0, cntpath = 0, maxavg;

void dijkstra(){
    for (int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; j++) {
            if (visited[j] == false && dist[j] < minn) {
                u = j;
                minn = dist[j];
            }
        }
        if (u == -1) break;
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (visited[v] == false && cmap[u][v] != inf) {
                if (dist[u] + cmap[u][v] < dist[v]) {
                    dist[v] = dist[u] + cmap[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (dist[v] == dist[u] + cmap[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void dfs(int v) {
    temppath.push_back(v);
    if (v == 0) {
        int value = 0;
        for (int i = 0; i < temppath.size(); i++) {
            value += happy[temppath[i]];
        }
        int tempavg = value / (temppath.size() - 1);
        if (value > maxvalue) {
            maxvalue = value;
            maxavg = tempavg;
            path = temppath;
        }
        else if (value == maxvalue && tempavg > maxavg) {
            maxavg = tempavg;
            path = temppath;
        }
        temppath.pop_back();
        cntpath++;
        return;
    }
    for (int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}

int main() {
    string s;
    cin >> n >> k >> s;
    fill(cmap[0], cmap[0] + 201 * 201, inf);
    pre.resize(n);
    dist.assign(n, inf);
    happy.assign(n, 0);
    visited.assign(n, false);
    cityidx[s] = 0;
    idxcity[0] = s;
    for (int i = 1; i < n; i++) {
        cin >> s >> happy[i];
        cityidx[s] = i;
        idxcity[i] = s;
    }
    string sa, sb;
    int temp;
    for (int i = 0; i < k; i++) {
        cin >> sa >> sb >> temp;
        cmap[cityidx[sa]][cityidx[sb]] = temp;
        cmap[cityidx[sb]][cityidx[sa]] = temp;
    }
    dist[0] = 0;
    dijkstra();
    int rom = cityidx["ROM"];
    dfs(rom);
    printf("%d %d %d %d\n", cntpath, dist[rom], maxvalue, maxavg);
    for (int i = path.size() - 1; i >= 1; i--) {
        cout << idxcity[path[i]] << "->";
    }
    cout << "ROM";
    return 0;
}