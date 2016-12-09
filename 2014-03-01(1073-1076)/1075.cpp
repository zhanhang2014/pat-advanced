#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rec{
	int id;
	int total=0;
	int ran;
	vector<int> grade;
	int full = 0;
	int pass = 0;
};
vector<Rec> rec(10001);
int fullgrade[6] = { 0 };

bool cmp(Rec a, Rec b){
	if (a.total != b.total){
		return a.total > b.total;
	}
	else if (a.full != b.full){
		return a.full > b.full;
	}
	else{
		return a.id < b.id;
	}
}

int main(){
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 1; i <= k; i++){
		cin >> fullgrade[i];
	}
	int uid, pid, score;
	for (int i = 0; i < m; i++){
		cin >> uid >> pid >> score;
		rec[uid].id = uid;
		if (rec[uid].grade.empty()) rec[uid].grade.assign(6, -1);
		if (rec[uid].grade[pid] == -1){
			if (score != -1){
				rec[uid].grade[pid] = score;
				rec[uid].pass++;
				rec[uid].total += score;
			}
		}
		else{
			if (score>rec[uid].grade[pid]){
				rec[uid].total -= rec[uid].grade[pid];
				rec[uid].grade[pid] = score;
				rec[uid].total += score;
			}
		}
		if (score == fullgrade[pid]) rec[uid].full++;
	}
	sort(rec.begin()+1, rec.begin()+n+1, cmp);
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (rec[i].pass != 0){
			rec[i].ran = i;
			if (rec[i].total == rec[i - 1].total) rec[i].ran = rec[i - 1].ran;
			printf("%d %05d %d", rec[i].ran, rec[i].id, rec[i].total);
			for (int j = 1; j <= k; j++){
				if (rec[i].grade[j] == -1) cout << " -";
				else cout << ' ' << rec[i].grade[j];
			} 
			cout << endl;
		}
	}
	return 0;
}