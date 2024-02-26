#include <iostream>
#include <algorithm>
#define LEN (64)

using namespace std;

typedef long long ll;
int n;
ll num_with_len[LEN];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
}

void solve(){
    ll num;
    for (int i = 0; i < n; i ++){
        cin >> num;
        for (int j = LEN - 1; j >= 0; j --){
            if (((num >> j) & 1) == 0) continue;

            // 비트가 같으면 훗날을 위해 XOR한다
            if (num_with_len[j]) num ^= num_with_len[j]; 
            else {
                num_with_len[j] = num; 
                break;
            }
        }
    }
    num = 0;
    for (int i = LEN - 1; i >= 0; i --){
        num = max(num, num ^ num_with_len[i]);
    }
    cout << num;
}

int main(){
    input();
    solve();
}