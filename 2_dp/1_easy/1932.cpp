#include <iostream>

using namespace std;

int n;
int dp[501][501];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= i; j ++){
            cin >> dp[i][j];
        }
    }
}

int main(){
    input();

    int ans = 0;

    for (int i = 2; i <= n; i ++){

        dp[i][1] += dp[i - 1][1];

        for (int j = 2; j < i; j ++){
            dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
        }

        dp[i][i] += dp[i - 1][i - 1];
    }

    for (int i = 1; i <= n; i ++){
        ans = max(ans, dp[n][i]);
    }

    cout << ans;
}