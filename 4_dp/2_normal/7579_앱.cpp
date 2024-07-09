#include <iostream>
#include <algorithm>
#define MAX 10001
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int memory[101], cost[101];

int sum;
int dp[10001]; // max memory per cost

void input(){
    fastio
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> memory[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> cost[i];
    }
}

void solve(){

    int ans = 10001;

    for (int i = 1; i <= n; i ++) {
        for (int j = 10000; j >= cost[i]; j --) {
            dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
            if (dp[j] >= m) ans = min(ans, j);
        }
    }

    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}