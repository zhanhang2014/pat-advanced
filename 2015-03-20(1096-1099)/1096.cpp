#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	long long n;
	cin >> n;
	vector<int> factor;
	vector<int> out;
	int re;
	int m = sqrt(n);
	for (int i = 2; i <= m; i++){
		re = n;
		factor.clear();
		for (int j = i; re>0; j++){
			if (re%j == 0){
				factor.push_back(j);
				re /= j;
			}
			else{
				if (out.size() < factor.size()){
					out = factor;
				}
				break;
			}
		}
	}
	int len = out.size();
	if (len == 0){
		printf("1\n%d", n);
		return 0;
	}
	printf("%d\n%d", len, out[0]);
	for (int i = 1; i < len; i++) {
		printf("*%d", out[i]);
	}
	printf("\n");
	return 0;
}