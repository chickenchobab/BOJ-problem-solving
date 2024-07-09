#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
char map[501][501];

int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};
int dp[501][501];
bool visited[501][501];

void input(){
    fastio
    cin >> n >> m;
    string str;
    for (int i = 1; i <= n; i ++){
        cin >> str;
        for (int j = 1; j <= m; j ++){
            map[i][j] = str[j - 1];
        }
    }
}

int direction(char ch){
    if (ch == 'U') return 0;
    if (ch == 'R') return 1;
    if (ch == 'D') return 2;
    return 3;
}

int dfs(int i, int j){

    if (i < 1 || i > n || j < 1 || j > m) return 1;
    if (dp[i][j]) return dp[i][j];
    if (visited[i][j]) return dp[i][j] = -1;

    visited[i][j] = 1;

    int dir = direction(map[i][j]);
    int ni = i + di[dir], nj = j + dj[dir];
    return dp[i][j] = dfs(ni, nj);
}

int main(){
    input();

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (visited[i][j]) continue;
            dfs(i, j);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (dp[i][j] == 1) ans ++;
        }
    }
    cout << ans;

    return 0;
}