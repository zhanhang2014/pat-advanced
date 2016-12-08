#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> origin, middle, sorted;

void downadjust(int low, int high){
	int i = low;
	int j = i * 2;
	while (j <= high){
		if (j + 1 <= high && middle[j] < middle[j + 1]) j = j + 1;
		if (middle[i] < middle[j]){
			swap(middle[i], middle[j]);
			i = j;
			j *= 2;
		}
		else break;
	}
}

int main(){
	int n;
	cin >> n;
	origin.resize(n+1);
	middle.resize(n+1);
	for (int i = 1; i <= n; i++) cin >> origin[i];
	for (int i = 1; i <= n; i++) cin >> middle[i];
	sorted = origin;
	sort(sorted.begin()+1, sorted.end());
	int p=0;
	bool isinsert = true;
	for (int i = 2; i <= n; i++){
		if (middle[i] >= middle[i-1]) p = i;
		else break;
	}
	for (int i = p+1; i <= n; i++){
		if (middle[i] != origin[i]){
			isinsert = false;
			break;
		}
	}
	if (isinsert){
		cout << "Insertion Sort\n";
		sort(middle.begin() + 1, middle.begin() + p + 2);
		cout << middle[1];
		for (int i = 2; i <= n; i++) cout << " " << middle[i];
		cout << endl;
	}
	else{
		cout << "Heap Sort\n";
		for (p = n; p > 1; p--){
			if (middle[p] < middle[p - 1]) break;
		}
		swap(middle[1], middle[p]);
		downadjust(1, p - 1);
		cout << middle[1];
		for (int i = 2; i <= n; i++) cout << " " << middle[i];
		cout << endl;
	}
	system("pause");
	return 0;
}