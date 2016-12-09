#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> seq(n);
	int sum = -1, subsum = 0, subleft = 0, subright = 0, idx = 0;
	for (int i = 0; i < n; i++){
		cin >> seq[i];
		subsum += seq[i];
		if (subsum > sum){
			sum = subsum;
			subleft = idx;
			subright = i;
		}
		else if(subsum<0){
			idx = i+1;
			subsum = 0;
		}
	}
	if (sum < 0){
		sum = 0;
		subleft = 0;
		subright = n - 1;
	}
	cout << sum << ' ' << seq[subleft] << ' ' << seq[subright] << endl;
	return 0;
}