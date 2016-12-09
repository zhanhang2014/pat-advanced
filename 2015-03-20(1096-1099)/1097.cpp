#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rec{
	int addr;
	int key;
	int next;
	int rank_num = 200002;
};
vector<Rec> rec(100001);
vector<bool> accur(100001, false);

bool cmp(Rec a, Rec b){
	return a.rank_num < b.rank_num;
}

int main(){
	int start, n;
	cin >> start >> n;
	int caddr, ckey, cnext;
	for (int i = 0; i < n; i++){
		cin >> caddr >> ckey >> cnext;
		rec[caddr].addr = caddr;
		rec[caddr].key = ckey;
		rec[caddr].next = cnext;
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = start; i != -1; i = rec[i].next){
		if (!accur[abs(rec[i].key)]){
			accur[abs(rec[i].key)] = true;
			rec[i].rank_num = cnt1++;
		}
		else{
			rec[i].rank_num = cnt2 + 100001;
			cnt2++;
		}
	}
	sort(rec.begin(), rec.end(), cmp);
	int cnt = cnt1 + cnt2;
	for (int i = 0; i < cnt; i++){
		if (i != cnt1 - 1 && i != cnt - 1){
			printf("%05d %d %05d\n", rec[i].addr, rec[i].key, rec[i + 1].addr);
		}
		else{
			printf("%05d %d -1\n", rec[i].addr, rec[i].key);
		}
	}
	return 0;
}