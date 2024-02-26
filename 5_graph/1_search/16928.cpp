#include <iostream>
#include <queue>

using namespace std;

int n, m;
int visited[101], teleport[101];

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= (n + m); i ++){
        cin >> a >> b;
        teleport[a] = b;
    }
}

int bfs(){
    queue<int> q;
    visited[1] = 1;
    q.push(1);

    while(q.size()){
        int u = q.front();
        q.pop();
        for (int d = 1; d <= 6; d ++){
            int v = u + d;
            if (v < 0 || v > 100) continue;
            if (teleport[v]) v = teleport[v];
            if (visited[v]) continue;
            visited[v] = visited[u] + 1;
            q.push(v);
        }
    }

    return visited[100] - visited[1];
}

int main(){
    input();
    cout << bfs();
}