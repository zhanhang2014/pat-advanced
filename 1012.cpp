#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct Stu{
	long long id;
	int grade[4],ran[4];
};
vector<Stu> stu;
map<long long, int> exist;
int idx = 0;
char Courses[4] = { 'A', 'C', 'M', 'E' };

bool cmp(Stu a,Stu b){
	return a.grade[idx] > b.grade[idx];
}

int main(){
	int n, m;
	cin >> n >> m;
	stu.resize(n);
	for (int i = 0; i < n; i++){
		cin >> stu[i].id >> stu[i].grade[1] >> stu[i].grade[2] >> stu[i].grade[3];
		stu[i].grade[0] = int(0.5 + double(stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0);
	}
	for (idx = 0; idx < 4; idx++){
		sort(stu.begin(), stu.end(), cmp);
		stu[0].ran[idx] = 1;
		for (int i = 1; i < n; i++){
			stu[i].ran[idx] = i + 1;
			if (stu[i].grade[idx] == stu[i - 1].grade[idx])
				stu[i].ran[idx] = stu[i - 1].ran[idx];
		}
	}
	for (int i = 0; i < n; i++){
		exist[stu[i].id] = i;
	}
	long long q;
	for (int i = 0; i < m; i++){
		cin >> q;
		if (exist.find(q) == exist.end()){
			cout << "N/A" << endl;
		}
		else{
			int index = exist[q];
			int r = stu[index].ran[0];
			char c = Courses[0];
			for (int j = 1; j < 4; j++){
				if (stu[index].ran[j] < r){
					r = stu[index].ran[j];
					c = Courses[j];
				}
			}
			cout << r << ' ' << c << endl;
		}
	}
	return 0;
}