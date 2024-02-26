#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int t;
long long dp[1 << 6 + 1][10];

void input(){
    fastio
    cin >> t;
}

void set_table(int n){

    for (int i = 0; i <= 9; i ++) dp[1][i] = 1;
    for (int i = 1; i <= n; i ++) dp[i][0] = 1;

    for (int i = 2; i <= n; i ++){
        for (int j = 1; j <= 9; j ++){
            dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]);
        }  
    }
}

int main(){

    input();

    set_table(64);

    int q;
    while (t --) {
        cin >> q;
        long long ans = 0;
        for (int i = 0; i < 10; i ++){
            ans += dp[q][i];
        }
        cout << ans << '\n';
    }
    return 0;
}