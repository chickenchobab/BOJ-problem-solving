#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int map[9][9];

typedef pair<int, int> p;
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
int visited[9][9];
int ans;

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> map[i][j];
        }
    }
}

int index(int i, int j){
    return (i - 1) * m + j;
}

void dfs(int i, int j){
    visited[i][j] = 1;
    for (int d = 0; d < 4; d ++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
        if (visited[ni][nj] || map[ni][nj]) continue;
        dfs(ni, nj);
    }
}

int count_safe_area(){

    int cnt = 0;

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            visited[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (map[i][j] == 2) dfs(i, j);
        }
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (map[i][j] == 0 && visited[i][j] == 0) cnt ++;
        }
    }
    
    return cnt;
}

void build(int i, int j, int cnt){
    if (cnt == 3) {
        ans = max(ans, count_safe_area());
        return;
    }

    for (int ni = 1; ni <= n; ni ++){
        for (int nj = 1; nj <= m; nj ++){
            if (index(ni, nj) <= index(i, j)) continue;
            if (map[ni][nj] != 0) continue;
            map[ni][nj] = 1;
            build(ni, nj, cnt + 1);
            map[ni][nj] = 0;
        }
    }
}

int main(){
    input();
    
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (map[i][j] != 0) continue;
            map[i][j] = 1;
            build(i, j, 1);
            map[i][j] = 0;
        }
    }

    cout << ans;

}