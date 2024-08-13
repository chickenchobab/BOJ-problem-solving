#include <iostream>
#include <algorithm>
#define DIV 1000000000
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
int n, k;
int dp[201][201];

void input(){
    fastio
    cin >> n >> k;
}

int solve(int i, int j){
    if (dp[i][j]) return dp[i][j];
    if (i == 1) return dp[i][j] = j;
    if (j == 1) return dp[i][j] = 1;
    return dp[i][j] = (solve1(i - 1, j) + solve1(i, j - 1)) % DIV;
}

int main(){
    input();

    solve(n, k);
    cout << dp[n][k];
    
    return 0;
}