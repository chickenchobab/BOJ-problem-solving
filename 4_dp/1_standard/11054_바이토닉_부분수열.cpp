#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1001], dp1[1001], dp2[1001];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> arr[i];
        dp1[i] = dp2[i] = 1;
    }
}

int main(){
    input();

    int ans = 0;

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j < i; j ++){
            if (arr[j] >= arr[i]) continue;
            dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }

    for (int i = n; i >= 1; i --){
        for (int j = n; j > i; j --){
            if (arr[j] >= arr[i]) continue;
            dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }

    for (int i = 1; i <= n; i ++){
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }

    cout << ans;
}