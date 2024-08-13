#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 15
using namespace std;

int n;
int dp[MAX + 1 + 1];

void input(){
    fastio
    cin >> n;
}

void solve(){
    int ans = 0;
    int t, p;
    for (int i = 1; i <= n; ++ i){
        cin >> t >> p;
        dp[i] = max(dp[i], dp[i - 1]);
        if (i + t <= n + 1){
            dp[i + t] = max(dp[i + t], dp[i] + p);
        }
    }
    for (int i = 1; i <= n + 1; ++ i){
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}