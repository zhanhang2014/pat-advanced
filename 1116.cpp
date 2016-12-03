#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n,k;
map<int, int> ran;
vector<int> que;
vector<bool> checked;

bool isPrime(int x){
	for (int i = 2; i < x / 2; i++)
		if (x%i == 0) return false;
	return true;
}

int main(){
	cin >> n;
	int tmp;
	for (int i = 1; i <= n; i++){
		cin >> tmp;
		ran[tmp] = i;
	}
	cin >> k;
	que.resize(k);
	checked.assign(k + 1, false);
	for (int i = 0; i < k; i++){
		cin >> tmp;
		if (ran.find(tmp) != ran.end()){
			if (!checked[ran[tmp]]){
				if (ran[tmp] == 1){
					printf("%04d: Mystery Award\n", tmp);
					checked[ran[tmp]] = true;
				}
				else if (isPrime(ran[tmp])){
					printf("%04d: Minion\n", tmp);
					checked[ran[tmp]] = true;
				}
				else{
					printf("%04d: Chocolate\n", tmp);
					checked[ran[tmp]] = true;
				}
			}
			else{
				printf("%04d: Checked\n", tmp);
			}
		}
		else{
			printf("%04d: Are you kidding?\n", tmp);
		}
	}
	return 0;
}