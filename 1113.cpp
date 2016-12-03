#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> myset(n);
	for (int i = 0; i < n; i++) cin >> myset[i];
	sort(myset.begin(), myset.end());
	int len = myset.size();
	int sum = 0;
	for (int i = len - 1; i >= (len / 2); i--) sum += myset[i];
	for (int i = 0; i < (len / 2); i++) sum -= myset[i];
	if (len % 2) cout << 1;
	else cout << 0;
	cout << " " << sum << endl;
	return 0;
}