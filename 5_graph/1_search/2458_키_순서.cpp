#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
vector<int> edge[505][2];

int idx, cnt;
int visited[505];

void input(){
    fastio
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i ++){
        cin >> a >> b;
        edge[a][0].push_back(b);
        edge[b][1].push_back(a);
    }
}

void dfs(int cur){
    visited[cur] = 1;
    for (int nxt : edge[cur][idx]){
        if (visited[nxt]) continue;
        dfs(nxt);
        cnt ++;
    }
}

void reset(){
    for (int i = 1; i <= n; i ++)
    visited[i] = 0;
}

int main(){
    input();
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        cnt = 0;

        idx = 0;
        dfs(i);

        reset();

        idx = 1;
        dfs(i);

        reset();

        if (cnt == n - 1) ans ++;
    }

    cout << ans;
    return 0;
}