#include <iostream>

using namespace std;

int n, k;
int coin[11];

void input(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> coin[i];
    }
}

int main(){

    input();

    // 동전의 배수관계
    int cnt = 0;
    for (int i = n; i >= 1; i --){
        cnt += (k / coin[i]);
        k %= coin[i];
    }

    cout << cnt;

}