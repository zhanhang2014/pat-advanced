#include <iostream>
#include <string>
using namespace std;

double num, sum = 0;

bool legal(string s){
	int len = s.length();
	int pos = 0;
	int pnum = 0;
	if (s[0] == '-') pos++;
	if (!(s[pos] >= '0' && s[pos] <= '9')) return false;
	for (int i = pos + 1; i < len - 1; i++){
		if (s[i] == '.'){
			pnum++;
			if (pnum > 1) return false;
			if (len - 1 - i > 2) return false;
		}
		else if (!(s[i] >= '0'&&s[i] <= '9')) return false;
	}
	sscanf(s.c_str(), "%lf", &num);
	if (num > 1000 || num < -1000) return false;
	return true;
}

int main(){
	int n;
	cin >> n;
	getchar();
	string str;
	int cnt = 0;
	for (int i = 0; i < n; i++){
		cin >> str;
		if (legal(str)){
			sscanf(str.c_str(), "%lf", &num);
			sum += num;
			cnt++;
		}
		else
			cout << "ERROR: " << str << " is not a legal number" << endl;
	}
	if (cnt == 0)
		cout << "The average of 0 numbers is Undefined" << endl;
	else if (cnt == 1)
		printf("The average of 1 number is %.2lf\n", sum);
	else
		printf("The average of %d numbers is %.2lf\n",cnt, sum/cnt);
	return 0;
}