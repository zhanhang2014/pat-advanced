#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > fans;
int n, l;

void forwardcnt(int t){
  vector<bool> visited(n + 1, false);
  queue<int> que;
  int cnt = 0, level = 0;
  visited[t] = true;
  que.push(t);
  int sz = que.size(),cur;
  while ((!que.empty()) && (level < l)){
    for (int i = 0; i < sz; i++){
      cur = que.front();
      que.pop();
      for (int j = 0; j < fans[cur].size(); j++){
        if (!visited[fans[cur][j]]){
          visited[fans[cur][j]] = true;
          que.push(fans[cur][j]);
          cnt++;
        }
      }
    }
    sz = que.size();
    level++;
  }
  cout << cnt << endl;
}

int main(){
  cin >> n >> l;
  fans.resize(n+1);
  int fn, f;
  for (int i = 1; i <= n; i++){
    cin >> fn;
    for (int j = 0; j < fn; j++){
      cin >> f;
      fans[f].push_back(i);
    }
  }
  cin >> fn;
  for (int i = 0; i < fn; i++){
    cin >> f;
    forwardcnt(f);
  }
  return 0;
}