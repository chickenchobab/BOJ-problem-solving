#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    const int div = 1000000007;
    
    cin >> n >> m;
    
    long long dp[300] = {0};
    dp[0] = 1; // Initialize dp[0] to 1
    
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1]; // Initialize dp[i] with the previous value
        if (i >= m) {
            dp[i] = (dp[i] + dp[i - m]) % div; // Update dp[i] using the previous m values
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
