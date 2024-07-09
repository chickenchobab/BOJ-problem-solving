#include <iostream>
#include <cstdio>

using namespace std;

int n;
double mat[7][7];
double ans[7];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> mat[i][j];
        }
        cin >> ans[i];
    }
}

void gaussian_elimination(){

    for (int i = 1; i <= n; i ++){
        double div = mat[i][i];
        for (int j = i; j <= n; j ++){
            mat[i][j] /= div;
        }
        ans[i] /= div;
        for (int j = 1; j <= n; j ++){
            if (i == j) continue;
            double mul = mat[j][i];
            for (int k = 1; k <= n; k ++){
                mat[j][k] -= (mul * mat[i][k]);
            }
            ans[j] -= (mul * ans[i]);
        }
    }
}

void print(){
    for (int i = 1; i <= n; i ++){
        cout << ans[i] << ' ';
    }
}

int main(){
    input();
    gaussian_elimination();
    print();
}