#include <iostream>

using namespace std;

typedef long long ll;
int n;
ll p;
ll mat[6][6], ans[6][6];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> mat[i][j];
            ans[i][j] = 0;
        }
        ans[i][i] = 1;
    }
}

void mul(ll des[6][6], ll src[6][6]){

    ll tmp[6][6];

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            ll sum = 0;
            for (int k = 1; k <= n; k ++){
                sum += (des[i][k] * src[k][j]);
            }
            tmp[i][j] = sum % 1000;
        }
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            des[i][j] = tmp[i][j];
        }
    }
}

void print(){
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    input();
    while (p){
        if (p % 2) mul(ans, mat);
        mul(mat, mat);
        p /= 2;
    }
    print();
}