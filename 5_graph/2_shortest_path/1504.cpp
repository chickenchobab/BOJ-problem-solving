#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 222222222
int n, e, x, y, dx, dy, dxy;
typedef pair<int, int> p;
vector<p> edge[808];

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> e;
    int a, b, c;
    for (int i = 1; i <= e; i ++){
        cin >> a >> b >> c;
        edge[a].push_back({c, b});
        edge[b].push_back({c, a});
    }
    cin >> x >> y;
}

int dijkstra(int s, int f){
    int d[808];
    priority_queue<p, vector<p>, greater<p>> pq;

    for (int i = 1; i <= n; i ++) d[i] = MAX;
    d[s] = 0;
    pq.push({0, s});
    while (pq.size()){
        p u = pq.top();
        pq.pop();

        if (d[u.second] < u.first) continue;

        for (p v : edge[u.second]){
            int uv = v.first;
            if (d[v.second] > d[u.second] + uv){
                d[v.second] = d[u.second] + uv;
                pq.push({d[v.second], v.second});
            }
        }
    }
    if (s == 1) {
        dx = d[x], dy = d[y];
    }
    return d[f];
}

int main(){
    input();

    dijkstra(1, n);
    dxy = dijkstra(x, y);

    int ans = MAX;
    ans = min(ans, dx + dxy + dijkstra(y, n));
    ans = min(ans, dy + dxy + dijkstra(x, n));

    ans < MAX ? cout << ans : cout << -1;
}