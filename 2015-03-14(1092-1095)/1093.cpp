#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	int len = s.length();
	long long p = 0, pa = 0, pat = 0;
	for (int i = 0; i < len; i++){
		if (s[i] == 'P') p++;
		if (s[i] == 'A') pa+=p;
		if (s[i] == 'T') pat+=pa;
	}
	cout << pat % 1000000007 << endl;
	return 0;
}