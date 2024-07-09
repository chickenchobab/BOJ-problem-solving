#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int dp[100001];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
}

int main(){
    input();
    
    for (int i = 1; i <= n; i ++){
        dp[i] = i;
        for (int j = 1, s = 1;  j <= i; s ++, j = s * s){
            dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }
    cout << dp[n];
}