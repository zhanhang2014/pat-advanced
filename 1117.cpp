#include <iostream>
#include <vector>
using namespace std;

vector<int> dist;

int main(){
  int n;
  cin >> n;
  dist.resize(n+1);
  for (int i = 1; i <= n; i++)
    cin >> dist[i];
  for (int i = n; i >= 1; i--){
    int cnt = 0;
    for (int j = 1; j <= n; j++)
      if (dist[j] > i) cnt++;
    if (cnt >= i){
      cout << i<<endl;
      return 0;
    }
  }
  cout << '0' << endl;
  return 0;
}