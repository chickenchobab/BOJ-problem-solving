#include <iostream>
#include <algorithm>
#define MAX 123456789
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int t;
int n;
int files[505];

int dp[505][505];

void input(){
    fastio
    cin >> t;
}

int sum(int i, int j){
    return files[j] - files[i - 1];
}

void solve(){
    cin >> n;

    int file;
    for (int i = 1; i <= n; i ++){
        cin >> file;
        files[i] = files[i - 1] + file;
    }

    for (int l = 2; l <= n; l ++){
        for (int s = 1; s <= n - (l - 1); s ++){
            int e = s + l - 1;
            dp[s][e] = MAX;
            for (int m = s; m < e; m ++){
                dp[s][e] = min(dp[s][e], dp[s][m] + dp[m + 1][e] + sum(s, e));
            }
        }
    }

    cout << dp[1][n] << '\n';
}

int main(){
    input();
    while (t --){
        solve();
    }
    return 0;
}