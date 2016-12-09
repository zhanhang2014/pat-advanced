#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Seq{
	int addr;
	int data;
	int next;
	int rank_num = 0;
};
vector<Seq> seq(100001);
vector<Seq> ans;

bool cmp(Seq a, Seq b){
	return a.rank_num > b.rank_num;
}

int main(){
	int start, n, k;
	cin >> start >> n >> k;
	int taddr, tdata, tnext;
	for (int i = 0; i < n; i++){
		cin >> taddr >> tdata >> tnext;
		seq[taddr].addr = taddr;
		seq[taddr].data = tdata;
		seq[taddr].next = tnext;
	}
	int cnt = 0;
	for (int i = start; i != -1; i = seq[i].next){
		seq[i].rank_num = cnt++;
		ans.push_back(seq[i]);
	}
	for (int i = 0; i + k < n; i += k){
		sort(ans.begin() + i*k, ans.begin() + i*k + k, cmp);
	}
	for (int i = 0; i < n; i++){
		if (i < n - 1){
			printf("%05d %d %05d\n", ans[i].addr, ans[i].data, ans[i + 1].addr);
		}
		else{
			printf("%05d %d -1\n", ans[i].addr, ans[i].data);
		}
	}
	system("pause");
	return 0;
}