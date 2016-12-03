#include <iostream>
#include <string>
using namespace std;

bool exist[256] = { false };
bool good[256] = { false };
bool stucked[256] = { false };

int main(){
	int n;
	string s;
	cin >> n;
	getchar();
	cin >> s;
	int len = s.length();
	char pre = '#';
	int cnt = 0;
	for (int i = 0; i < len; i++){
		exist[s[i]] = true;
		if (s[i] == pre) {
			cnt++;
			if (cnt == n){
				stucked[pre] = true;
				cnt = 0;
			}
		}
		else {
			if (cnt != 0) good[pre] = true;
			pre = s[i];
			cnt = 1;
		}
	}
	for (int i = 0; i < 256; i++){
		if (exist[i]){
			if (stucked[i] && !good[i]) cout << char(i);
		}
	}
	cout << endl;
	for (int i = 0; i < len; i++){
		cout << s[i];
		if (stucked[s[i]] && !good[s[i]]) i += n - 1;
	}
	return 0;
}