#include <iostream>
#include <vector>
using namespace std;

vector<int> postorder, inorder, levelorder;

void buildlevel(int index, int root, int start, int end){
	if (start > end) return;
	int rt = start;
	while (rt < end && inorder[rt] != postorder[root]) rt++;
	levelorder[index] = postorder[root];
	buildlevel(2 * index + 1, root - (end - rt + 1), start, rt - 1);
	buildlevel(2 * index + 2, root - 1, rt + 1, end);
}

int main(){
	int n;
	cin >> n;
	postorder.resize(n);
	inorder.resize(n);
	levelorder.assign(65535, -1);
	for (int i = 0; i < n; i++) cin >> postorder[i];
	for (int i = 0; i < n; i++) cin >> inorder[i];
	buildlevel(0, n - 1, 0, n - 1);
	for (int i = 0,cnt=0; cnt<n; i++){
		if (levelorder[i] != -1){
			cout << levelorder[i];
			cnt++;
			if (cnt != n) cout << ' ';
		}
	}
	cout << endl;
	return 0;
}