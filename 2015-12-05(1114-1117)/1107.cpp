#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> onehob;
vector<int> fa;
vector<int> member;

int findf(int x){
	while (x != fa[x]) x = fa[x];
	return x;
}

void Union(int x, int y){
	int fx = findf(x);
	int fy = findf(y);
	if (fx != fy) fa[fx] = fy;
}

int main(){
	cin >> n;
	fa.resize(1001);
	onehob.resize(n);
	member.assign(1001, 0);
	for (int i = 0; i < 1001; i++){
		fa[i] = i;
	}
	int m, h1, h2;
	for (int i = 0; i < n; i++){
		cin >> m;
		getchar();
		cin >> h1;
		onehob[i] = h1;
		for (int j = 1; j < m; j++){
			cin >> h2;
			Union(h2, h1);
		}
	}
	for (int i = 0; i < n; i++){
		int root = findf(onehob[i]);
		member[root]++;
	}
	sort(member.begin(), member.end());
	int cnt = 0;
	for (int i = 1000; i >= 0; i--){
		if (member[i] == 0) break;
		cnt++;
	}
	cout << cnt << endl;
	for (int i = 1000; i > 1000 - cnt; i--){
		cout << member[i];
		if (i != 1001 - cnt) cout << ' ';
	}
	cout << endl;
	return 0;
}