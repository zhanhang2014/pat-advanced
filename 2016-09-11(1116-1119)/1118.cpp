#include <iostream>
#include <algorithm>
using namespace std;

int fa[10001] = { 0 }, cnt[10001] = { 0 };
int n, q;

int findf(int x){
	int a = x;
	while (x != fa[x]) x = fa[x];
	return x;
}

void Union(int a, int b){
	int faa = findf(a);
	int fab = findf(b);
	if (faa != fab) fa[faa] = fab;
}

int main(){
	for (int i = 1; i < 10001; i++){
		fa[i] = i;
	}
	cin >> n;
	int b1, b2;
	int treen=0, birdn=0;
	for (int i = 0; i < n; i++){
		cin >> q >> b1;
		birdn = max(birdn, b1);
		for (int j = 1; j < q; j++){
			cin >> b2;
			birdn = max(birdn, b2);
			Union(b1, b2);
		}
	}
	for (int i = 1; i <= birdn; i++){
		int root = findf(i);
		cnt[root]++;
	}
	for (int i = 1; i <= birdn; i++){
		if (cnt[i] != 0) treen++;
	}
	cout << treen << " " << birdn << endl;
	cin >> q;
	for (int i = 0; i < q; i++){
		cin >> b1 >> b2;
		if (findf(b1) == findf(b2)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}