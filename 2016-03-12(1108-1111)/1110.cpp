#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Node{
	int left, right;
};
vector<Node> node;
vector<bool> child;

int main(){
	int n, root;
	cin >> n;
	node.resize(n);
	child.assign(n, false);
	string sl,sr;
	int tmp;
	for (int i = 0; i < n; i++){
		cin >> sl >> sr;
		if (sl[0] == '-'){
			node[i].left = -1;
		}
		else{
			sscanf(sl.c_str(), "%d", &tmp);
			node[i].left = tmp;
			child[tmp] = true;
		}
		if (sr[0] == '-'){
			node[i].right = -1;
		}
		else{
			sscanf(sr.c_str(), "%d", &tmp);
			node[i].right = tmp;
			child[tmp] = true;

		}
	}
	for (int i = 0; i < n; i++){
		if (child[i] == false) root = i;
	}
	queue<int> que;
	int cnt = 0;
	int lastnode;
	que.push(root);
	while (!que.empty()){
		int cur = que.front();
		que.pop();
		if (cur != -1){
			cnt++;
			lastnode = cur;
		}
		else{
			if (cnt == n){
				cout << "YES " << lastnode << endl;
				break;
			}
			else{
				cout << "NO " << root << endl;
				break;
			}
		}
		que.push(node[cur].left);
		que.push(node[cur].right);
	}
	return 0;
}