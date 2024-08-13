#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> edge[10001];
int w[10001];

int max_size[10001][2];
vector<int> ans;

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> w[i];
    int a, b;
    for (int i = 1; i < n; i ++){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}

void dfs(int prv, int cur){
    
    max_size[cur][1] = w[cur];

    for (int nxt : edge[cur]){
        if (nxt == prv) continue;
        dfs(cur, nxt);
        max_size[cur][0] += max(max_size[nxt][0], max_size[nxt][1]);
        max_size[cur][1] += max_size[nxt][0];
    }
}

void collect_answer(int prv, int cur, int flag){
    if (flag) ans.push_back(cur);
    
    for (int nxt : edge[cur]){
        if (prv == nxt) continue;
        if (flag) 
            collect_answer(cur, nxt, 0);
        else 
            collect_answer(cur, nxt, max_size[nxt][1] > max_size[nxt][0]);
    }
}

int main(){
    input();
    
    dfs(0, 1);

    int sum = 0, flag = 0;
    if (max_size[1][1] > max_size[1][0]) {
        flag = 1;
        sum = max_size[1][1];
    }
    else {
        sum = max_size[1][0];
    }

    collect_answer(0, 1, flag);
    sort(ans.begin(), ans.end());

    cout << sum << '\n';
    for (int tmp : ans) cout << tmp << ' ';
}
