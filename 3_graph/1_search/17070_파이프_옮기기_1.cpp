#include <iostream>

using namespace std;

int n;
int map[17][17], di[] = {1, 0, 1}, dj[] = {1, 1, 0};
int ans;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> map[i][j];
        }
    }
}

bool valid(int i, int j){
    if (map[i][j]) return false;
    if (i < 1 || i > n || j < 1 || j > n) return false;
    return true;
}

void dfs(int i, int j, int dir){

    if (i == n && j == n) ans ++;

    for (int d = 0; d < 3; d ++){
        if ((dir == 1 && d == 2) || (dir == 2 && d == 1)) continue;
        int ni = i + di[d];
        int nj = j + dj[d];
        if (!valid(ni, nj)) continue;
        if (d == 0 && (map[i + 1][j] || map[i][j + 1])) continue;
        dfs(ni, nj, d);
    }
}

int main(){

    input();
    dfs(1, 2, 1);

    // show();
    cout << ans;
}