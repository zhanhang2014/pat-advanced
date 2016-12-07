#include <iostream>
#include <vector>
using namespace std;

struct Node{
	double data;
	vector<int> child;
};

vector<Node> node;
int n;
double p, r, ans = 0;

void dfs(int index, int depth){
	if (node[index].child.size() == 0){
		double pow = 1;
		for (int i = 0; i < depth; i++)
			pow *= (0.01*r + 1);
		ans += node[index].data*pow;
		return;
	}
	for (int i = 0; i < node[index].child.size(); i++)
		dfs(node[index].child[i], depth + 1);
}

int main(){
	cin >> n >> p >> r;
	node.resize(n);
	int k;
	for (int i = 0; i < n; i++){
		cin >> k;
		if (k == 0) cin >> node[i].data;
		else {
			node[i].child.resize(k);
			for (int j = 0; j < k; j++)
				cin >> node[i].child[j];
		}
	}
	dfs(0, 0);
	printf("%.1lf", ans*p);
	return 0;
}