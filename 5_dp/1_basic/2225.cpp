#include <iostream>
#include <algorithm>
#define DIV 1000000000
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
int N, K;
int dp[201][201];

void input(){
    fastio
    cin >> N >> K;
}

int decompSum(int i, int j){
    if (dp[i][j]) return dp[i][j];
    if (i == 1) return dp[i][j] = j;
    if (j == 1) return dp[i][j] = 1;
    return dp[i][j] = (decompSum(i - 1, j) + decompSum(i, j - 1)) % DIV;
}

void solve(){
    cout << decompSum(N, K);
}

int main(){
    input();
    solve();
    return 0;
}