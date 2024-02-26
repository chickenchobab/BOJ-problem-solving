#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int edge[501][501];

void input(){
    fastio
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i ++){
        cin >> a >> b;
        edge[a][b] = 1;
    }
}

void floyd_warshall(){

    for (int s = 1; s <= n; s ++){
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= n; j ++){
                if (!edge[i][s] || !edge[s][j]) continue;
                edge[i][j] = 1;
            }
        }
    }
}

bool check(int num){
    int in = 0, out = 0;

    for (int i = 1; i <= n; i ++){
        if (edge[i][num]) in ++;
        if (edge[num][i]) out ++;
    }

    return (in + out == n - 1);
}

int main(){
    input();

    floyd_warshall();
    
    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        cnt += check(i);
    }
    cout << cnt;

    return 0;
}