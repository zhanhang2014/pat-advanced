#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

vector<int> inorder, preorder, postorder;

void buildpost(int root, int start, int end){
	if (start > end) return;
	int rt = start;
	while (rt < end && inorder[rt] != preorder[root]) rt++;
	buildpost(root + 1, start, rt - 1);
	buildpost(root + (rt - start) + 1, rt + 1, end);
	postorder.push_back(preorder[root]);
}

int main(){
	int n;
	cin >> n;
	string op;
	int tmp;
	stack<int> sta;
	for (int i = 0; i < 2 * n; i++){
		cin >> op;
		if (op.length()==4){
			cin >> tmp;
			preorder.push_back(tmp);
			sta.push(tmp);
		}
		else{
			tmp = sta.top();
			sta.pop();
			inorder.push_back(tmp);
		}
	}
	buildpost(0, 0, n - 1);
	for (int i = 0; i < n - 1; i++) cout << postorder[i] << " ";
	cout << postorder[n - 1] << endl;
	return 0;
}