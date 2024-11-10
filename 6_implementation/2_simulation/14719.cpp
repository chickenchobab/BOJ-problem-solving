#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int H, W;
int block[505];

void input(){
    fastio
    cin >> H >> W;
    for (int i = 1; i <= W; i ++){
        cin >> block[i];
    }
}

void solve(){
    int sum = 0;
    for (int i = 1; i <= H; ++ i){
        int left, right;
        bool blocked = 0;
        for (int j = 1; j <= W; j ++){
            if (blocked){
                if (block[j] >= i){
                    right = j;
                    sum += right - left - 1;
                    blocked = 0;
                }
            }
            if (block[j] >= i){
                blocked = 1;
                left = j;
            }
        }
    }
    cout << sum;
}

int main(){
    input();
    solve();
    return 0;
}