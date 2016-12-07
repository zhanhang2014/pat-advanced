#include <cstdio>
#include <vector>
using namespace std;

vector<int> ans;
int unique = 1;
vector<int> pre, post;

void setIn(int prel, int prer, int postl, int postr) {
	if (prel == prer) {
		ans.push_back(pre[prel]);
		return;
	}
	if (pre[prel] == post[postr]) {
		int x = prel + 1;
		while (pre[x] != post[postr - 1]) x++;
		if (x - prel > 1) {
			setIn(prel + 1, x - 1, postl, postl + x - prel - 2);
			ans.push_back(post[postr]);
			setIn(x, prer, postl + x - prel - 2 + 1, postr - 1);
		}
		else {
			unique = 0;
			ans.push_back(post[postr]);
			setIn(x, prer, postl + x - prel - 2 + 1, postr - 1);
		}
	}
}

int main() {
	int n = 0;
	scanf("%d", &n);
	pre.resize(n);
	post.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	setIn(0, n - 1, 0, n - 1);
	printf("%s\n", unique ? "Yes" : "No");
	printf("%d", ans[0]);
	for (int i = 1; i < ans.size(); i++) {
		printf(" %d", ans[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

#include <cstdio>
#include <vector>
using namespace std;

vector<int> ans;
int unique = 1;
vector<int> pre, post;

void setIn(int prel, int prer, int postl, int postr) {
	if (postl == postr) {
		ans.push_back(pre[prel]);
		return;
	}
	if (pre[prel] == post[postr]) {
		int x = postl;
		while (post[x] != pre[prel + 1]) x++;
		if (postr - x > 1) {
			setIn(prel + 1, prel + x - postl+1, postl, x);
			ans.push_back(post[postr]);
			setIn(prel + x - postl + 2, prer, x + 1, postr - 1);
		}
		else {
			unique = 0;
			setIn(prel + 1, prel + x - postl + 1, postl, x);
			ans.push_back(post[postr]);
		}
	}
}

int main() {
	int n = 0;
	scanf("%d", &n);
	pre.resize(n);
	post.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	setIn(0, n - 1, 0, n - 1);
	printf("%s\n", unique ? "Yes" : "No");
	printf("%d", ans[0]);
	for (int i = 1; i < ans.size(); i++) {
		printf(" %d", ans[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}