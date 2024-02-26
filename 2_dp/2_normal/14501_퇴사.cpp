#include <iostream>
#include <algorithm>

using namespace std;

int n, t[16], p[16];
int dp[17];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> t[i] >> p[i];
    }
}

int main(){

    int ans = 0;

    input();

    // for (int i = 1; i <= n + 1; i ++){
    //     for (int j = 1; j < i; j ++){
    //         if (t[j] > i - j) continue;
    //         dp[i] = max(dp[i], dp[j] + p[j]);
    //     }
    // }

    for (int i = 1; i <= n; i ++){
        dp[i + 1] = max(dp[i + 1], dp[i]);
        if (i + t[i] > n + 1) continue;
        dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
    }
    
    cout << dp[n + 1];
}