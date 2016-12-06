#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Family{
    int root;
    int mem;
    double num;
    double area;
    Family(int r, int m, double n, double a){ root = r; mem = m; num = n; area = a; };
};
vector<Family> family;
int fa[10000];
double anum[10000] = { 0 };
double aarea[10000];
int member[10000] = { 0 };
bool exist[10000] = { false };
int n;

int findf(int x){
    while (x != fa[x]) x = fa[x];
    return x;
}

void Union(int x, int y){
    int fx = findf(x);
    int fy = findf(y);
    if (fx > fy) {
        fa[fx] = fy;
        return;
    }
    if (fx < fy) {
        fa[fy] = fx;
        return;
    }
}

bool cmp(Family a, Family b){
    if (a.area != b.area){
        return a.area > b.area;
    }
    else{
        return a.root < b.root;
    }
}

int main(){
    for (int i = 0; i < 10000; i++){
        fa[i] = i;
    }
    cin >> n;
    int id, fid, mid, m, c;
    for (int i = 0; i < n; i++){
        cin >> id >> fid >> mid >> m;
        exist[id] = true;
        if (fid != -1) {
            Union(id, fid);
            exist[fid] = true;
        }
        if (mid != -1) {
            Union(id, mid);
            exist[mid] = true;
        }
        for (int i = 0; i < m; i++){
            cin >> c;
            Union(id, c);
            exist[c] = true;
        }
        cin >> anum[id] >> aarea[id];
    }
    for (int i = 0; i < 10000; i++){
        if (exist[i]){
            int root = findf(i);
            if (i != root){
                anum[root] += anum[i];
                aarea[root] += aarea[i];
            }
            member[root]++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 10000; i++){
        if (member[i] != 0){
            family.push_back(Family(i,member[i],anum[i]/member[i],aarea[i]/member[i]));
            cnt++;
        }
    }
    cout << cnt << endl;
    sort(family.begin(), family.end(), cmp);
    for (int i = 0; i < cnt; i++){
        printf("%04d %d %.3lf %.3lf\n", family[i].root, family[i].mem, family[i].num, family[i].area);
    }
    return 0;
}