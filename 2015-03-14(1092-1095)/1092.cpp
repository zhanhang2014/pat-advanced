#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	string sell, want;
	cin >> sell >> want;
	int exist[256] = { 0 };
	int sell_len = sell.length();
	for (int i = 0; i < sell.length(); i++) exist[sell[i]]++;
	int more = 0, less = 0;
	int want_length = want.length();
	for (int i = 0; i < want_length; i++) exist[want[i]]--;
	for (int i = 0; i < 256; i++){
		if (exist[i]>0) more += exist[i];
		if (exist[i] < 0) less -= exist[i];
	}
	if (less > 0) cout << "No " << less << endl;
	else cout << "Yes " << more << endl;
	return 0;
}