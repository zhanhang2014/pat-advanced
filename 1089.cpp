#include <iostream>
#include <algorithm>
using namespace std;

int a[101], b[101];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	int p1, p2;
	for (p1 = 0; b[p1] <= b[p1 + 1] && p1 < n - 1; p1++);
	for (p2 = p1 + 1; a[p2] == b[p2] && p2<n; p2++);
	if (p2 == n){
		cout << "Insertion Sort" << endl;
		sort(a, a + p1 + 2);
	}
	else{
		cout << "Merge Sort" << endl;
		int k=1;
		bool flag=true;
		while (flag){
			flag = false;
			for (int i = 0; i < n; i++)
				if (a[i] != b[i]) flag = true;
			k *= 2;
			for (int i = 0; i < n / k; i++)
				sort(a + i*k, a + (i + 1)*k);
			for (int i = n / k*k; i < n; i++)
				sort(a + n/k*k, a + n);
		}
	}
	for (int i = 0; i < n - 1; i++) cout << a[i] << ' ';
	cout << a[n - 1] << endl;
	return 0;
}