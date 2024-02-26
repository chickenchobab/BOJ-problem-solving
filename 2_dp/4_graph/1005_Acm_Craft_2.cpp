#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int t, n, k, a, b, w;
int time[1001], indegree[1001], dp[1001];
vector<int> edge[1001];

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
}

void input(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> time[i];
        edge[i].clear();
        indegree[i] = 0;
    }
    for (int i = 1; i <= k; i ++){
        cin >> a >> b;
        edge[a].push_back(b);
        indegree[b] ++;
    }
    cin >> w;
}

int toposort(int w){
    queue<int> q;

    for (int i = 1; i <= n; i ++){
        if (indegree[i] == 0) {
            dp[i] = time[i];
            q.push(i);
        }
    }

    while (q.size()){
        int u = q.front();
        q.pop();
        for (int v : edge[u]){
            dp[v] = max(dp[v], dp[u] + time[v]);
            if (-- indegree[v] == 0) q.push(v);
        }
    }

    return dp[w];
}

int main(){
    init();
    while (t --) {
        input();
        cout << toposort(w) << '\n';
    }
}