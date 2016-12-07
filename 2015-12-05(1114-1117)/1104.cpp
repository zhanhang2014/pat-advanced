#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<double> seg(n);
	double sum = 0;
	for (int i = 0; i < n; i++){
		scanf("%lf", &seg[i]);
	}
	for (int i = 0; i < n; i++){
		sum += seg[i] * (n - i)*(i + 1);
	}
	printf("%.2lf\n", sum);
	return 0;
}