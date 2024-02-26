#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, k, a, b, w;
int time[1001];
vector<int> edge[1001];

int dp[1001];

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
}

void input(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> time[i];
        edge[i].clear();
        dp[i] = -1;
    }
    for (int i = 1; i <= k; i ++){
        cin >> a >> b;
        edge[b].push_back(a);
    }
    cin >> w;
}

int dfs(int cur){

    if (dp[cur] != -1) return dp[cur];

    int mx = 0;
    for (int nxt : edge[cur]){
        mx = max(mx, dfs(nxt));
    }

    return dp[cur] = mx + time[cur];
}

int main(){
    init();
    while (t --) {
        input();
        cout << dfs(w) << '\n';
    }
}