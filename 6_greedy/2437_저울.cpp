#include <iostream>
#include <algorithm>
#define MAX 100000
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int w[1001];

void input(){
    fastio
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> w[i];
}

int solve(){

    sort(w + 1, w + n + 1);

    int ans = 1;
    for (int i = 1; i <= n; i ++){
        if (w[i] > ans) return ans;
        ans += w[i];
    }

    return ans;

}

int main(){
    input();
    cout << solve();
    return 0;
}
