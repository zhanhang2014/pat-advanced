#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Person{
	string name;
	int height;
};

vector<Person> person;
int n, k;

void printrow(int start, int end){
	if ((end - start) % 2 == 0){
		for (int i = start+1; i <= end - 1; i += 2){
			cout << person[i].name << ' ';
		}
		cout << person[end].name;
		for (int i = end - 2; i >=start; i -= 2){
			cout << ' ' << person[i].name;
		}
	}
	else{
		for (int i = start; i <= end - 1; i += 2){
			cout << person[i].name << ' ';
		}
		cout << person[end].name;
		for (int i = end - 2; i >= start + 1; i -= 2){
			cout << ' ' << person[i].name;
		}
	}
	cout << endl;
}

bool cmp1(Person a, Person b){
	if (a.height != b.height){
		return a.height < b.height;
	}
	else return a.name > b.name;
}

int main(){
	cin >> n >> k;
	person.resize(n);
	for (int i = 0; i < n; i++){
		cin >> person[i].name >> person[i].height;
	}
	sort(person.begin(), person.end(), cmp1);
	int num = (n / k);
	int extra = n - (n / k*k);
	for (int i = k-1; i >= 0; i--){
		if (i == k - 1){
			printrow(i*num, (i + 1)*num-1 + extra);
		}
		else{
			printrow(i*num, (i + 1)*num - 1);
		}
	}
	return 0;
}