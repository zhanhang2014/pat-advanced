#include <iostream>
#include <string>
using namespace std;

bool exist[256] = { false };
bool bad[256] = { false };
bool good[256] = { false };
int cnt = 0;
char pre = '#';

int main(){
	int n;
	cin >> n;
	string str;
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++){
		exist[str[i]] = true;
		if (str[i] != pre){
			if (cnt>0) good[pre] = true;
			pre = str[i];
			cnt = 1;
		}
		else{
			cnt++;
			if (cnt == n){
				bad[pre] = true;
				cnt = 0;
				pre = '#';
			}
		}
	}
	for (int i = 0; i < 256; i++){
		if (exist[i]){
			if (bad[i] && !good[i]) cout << char(i);
		}
	}
	cout << endl;
	for (int i = 0; i < len; i++){
		cout << str[i];
		if (bad[str[i]] && !good[str[i]]) i += n - 1;
	}
	cout << endl;
	return 0;
}