#include <iostream>
#include <string>
using namespace std;

string lower[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string higher[13] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void e2m(string s){
	int num;
	sscanf(s.c_str(), "%d", &num);
	cout << higher[num / 13];
	if (num / 13 && num % 13)
		cout << " " << lower[num % 13];
	else if (num % 13)
		cout << lower[num % 13];
	else if (num == 0)
		cout << lower[num % 13];
	cout << endl;
}

void m2e(string s){
	int num = 0;
	int len = s.length();
	if (len <= 4){
		for (int i = 0; i <= 12; i++){
			if (lower[i] == s) num += i;
			if (higher[i] == s) num += i*13;
		}
	}
	else{
		string sh = s.substr(0, 3);
		string sl = s.substr(4, 3);
		for (int i = 0; i <= 12; i++){
			if (sh == higher[i]) num += i*13;
			if (sl == lower[i]) num += i;
		}
	}
	cout << num << endl;
}

int main(){
	int n;
	cin >> n;
	getchar();
	string str;
	for (int i = 0; i < n; i++){
		getline(cin, str);
		if (str[0] >= '0' && str[0] <= '9') e2m(str);
		else m2e(str);
	}
	return 0;
}