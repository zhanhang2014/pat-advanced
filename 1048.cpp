#include <iostream>
using namespace std;

int n, m;
int coin[1001] = { 0 };

int main(){
	cin >> n >> m;
	int note;
	for (int i = 0; i < n; i++){
		scanf("%d", &note);
		coin[note]++;
	}
	for (int i = 1; i < 1001; i++){
		if (coin[i] != 0){
			coin[i]--;
			if (coin[m - i] != 0 && m>i){
				printf("%d %d", i, m - i);
				return 0;
			}
			coin[i]++;
		}
	}
	printf("No Solution\n");
	return 0;
}