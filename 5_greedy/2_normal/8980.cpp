#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, c, m;
typedef tuple<int, int, int> box;
box boxes[10001];
int quota[2002]; // the number of boxes to town

void input(){
    fastio
    cin >> n >> c >> m;
    int s, e, num;
    for (int i = 1; i <= m; i ++){
        cin >> s >> e >> num;
        boxes[i] = {s, e, num};
    }
}

void solve(){
    int load = 0, unload = 0;
    sort(boxes + 1, boxes + m + 1);

    int s, e, num;
    for (int i = 1; i <= m; i ++){
        
        tie(s, e, num) = boxes[i];

        for (int j = 1; j <= s; j ++){
            if (quota[j] == 0) continue;
            load -= quota[j];
            unload += quota[j];
            quota[j] = 0;
        }

        for (int j = n; j > e && num && load + num > c; j --){
            if (quota[j] == 0) continue;
            int l = min(load + num - c, min(num, quota[j]));
            quota[j] -= l;
            quota[e] += l;
            num -= l;
        }   
        
        int l = min(num, c - load);
        quota[e] += l;
        load += l;
    }

    unload += load;
    cout << unload;
}

int main(){
    input();
    solve();
    return 0;
}