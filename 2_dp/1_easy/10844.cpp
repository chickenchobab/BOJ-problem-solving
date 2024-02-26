#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define div 1000000000

using namespace std;

int n;
int dp[101][10];

void input(){
    fastio
    cin >> n;
}

long long solve(){

    long long sum = 0;

    for (int i = 1; i <= 9; i ++) dp[1][i] = 1;

    for (int i = 2; i <= n; i ++){
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];
        for (int j = 1; j <= 8; j ++){
            dp[i][j] += (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % div;
        }
    }

    for (int i = 0; i <= 9; i ++) sum += dp[n][i];
    
    return sum % div;
}

int main(){
    input();
    cout << solve();
    return 0;
}