#include <iostream>
using namespace std;

int r, c;
char map[10001][505];
int di[3] = {-1, 0, 1};

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c;

    string str;
    for (int i = 1; i <= r; i ++){
        cin >> str;
        for (int j = 1; j <= c; j ++){
            map[i][j] = str[j - 1];
        } 
    } 
}
bool dfs(int i, int j){
    
    if (j == c) {
        return true;
    }
    map[i][j] = 'x';
    for (int d = 0; d < 3; d ++){
        int ni = i + di[d];
        if (ni < 1 || ni > r) continue;
        if (map[ni][j + 1] == 'x') continue;
        // cout << ni << ' ' << nj << '\n';
        if (dfs(ni, j + 1)) return true;
    }
    return false;
}

int main(){

    input();

    int ans = 0;
    for (int i = 1; i <= r; i ++){
        // cout << i << ' ' << 1 << '\n';
        ans += dfs(i, 1);
    }

    cout << ans;
}