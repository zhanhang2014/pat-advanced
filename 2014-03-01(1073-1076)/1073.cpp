#include <iostream>
#include <string>
using namespace std;

int main(){
	string str, ans;
	cin >> str;
	int len = str.length();
	int idx = str.find('E');
	string e = str.substr(idx + 2, len - idx - 2);
	int expn;
	sscanf(e.c_str(), "%d", &expn);
	if (str[0] == '-') ans += "-";
	if (str[idx + 1] == '-'){
		ans += "0.";
		for (int i = 0; i < expn - 1;i++){
			ans += "0";
		}
		ans += str[1];
		ans += str.substr(3, idx - 3);
	}
	else{
		if (expn >= idx - 3){
			ans += str[1];
			ans += str.substr(3, idx - 3);
			for (int i = 0; i < expn - idx + 3; i++) ans += "0";
		}
		else{
			ans += str[1];
			ans += str.substr(3, expn);
			ans += ".";
			ans += str.substr(expn + 3, idx - 3 - expn);
		}
	}
	cout << ans << endl;
	return 0;
}