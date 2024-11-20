#include <iostream>
#include <algorithm>
#define MAX 10000001
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int cost[1001];

int dp[2][1001][3];

void input(){
    fastio
    cin >> n >> m;
    for (int j = 1; j <= m; j ++){
        for (int d = 0; d < 3; d ++){
            dp[1][j][d] = MAX;
        }
    }
}

void set_table(){
    for (int j = 1; j <= m; j ++){
        for (int d = 0; d < 3; d ++){
            dp[0][j][d] = dp[1][j][d];
            dp[1][j][d] = MAX;
        }
    }
}

void solve(){

    int ans = MAX;

    for (int i = 1; i <= n; i ++){

        for (int j = 1; j <= m; j ++) cin >> cost[j];

        for (int j = 1; j <= m; j ++) {
            if (j < m) dp[1][j][0] = min(dp[0][j + 1][1], dp[0][j + 1][2]) + cost[j];
            if (j > 1) dp[1][j][2] = min(dp[0][j - 1][1], dp[0][j - 1][0]) + cost[j];
            dp[1][j][1] = min(dp[0][j][0], dp[0][j][2]) + cost[j];
        }

        set_table();
    }

    for (int j = 1; j <= m; j ++){
        for (int d = 0; d < 3; d ++){
            ans = min(ans, dp[0][j][d]);
        }
    }
    
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}