#include <iostream>
#include <string>
using namespace std;

string marslower[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct","nov", "dec" };
string marshigher[13] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy","lok", "mer", "jou" };

void e2m(string s){
	int len = s.length();
	int num = 0;
	for (int i = 0; i < len; i++)
		num = num * 10 + (s[i] - '0');
	cout << marshigher[num / 13];
	if ((num / 13) && (num % 13))
		cout << " " << marslower[num % 13];
	else if (num % 13)
		cout << marslower[num % 13];
	else if (num == 0)
		cout << marslower[num % 13];
}

void m2e(string s){
	int len = s.length();
	int num = 0;
	if (len <= 4){
		for (int i = 0; i <= 12; i++){
			if (s == marslower[i]){
				cout << i;
				return;
			}
			if (s == marshigher[i]){
				cout << i * 13;
				return;
			}
		}
	}
	else{
		string hs = s.substr(0, 3);
		string ls = s.substr(4, 3);
		for (int i = 1; i <= 12; i++){
			if (hs == marshigher[i]) num += i * 13;
			if (ls == marslower[i]) num += i;
		}
	}
	cout << num;
}

int main(){
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++){
		string s;
		getline(cin, s);
		if (s[0] >= '0'&&s[0] <= '9') e2m(s);
		else m2e(s);
		cout << endl;
	}
	system("pause");
	return 0;
}