#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m, ans;
//int map[51][51];
//int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
vector<pair<int, int>> house, all, selected;

void input(){
    fastio
    cin >> n >> m;
    int num;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> num;
            if (num == 1) house.push_back({i, j});
            else if (num == 2) all.push_back({i, j});
        }
    }
    ans = 50 * 50 * 13;
}

int check_distance(){
    
    int sum = 0;

    for (int h = 0; h < house.size(); h ++){
        int hi = house[h].first;
        int hj = house[h].second;
        int dist = 50 * 50 * 13;
        for (int s = 0; s < m; s ++){
            int si = selected[s].first;
            int sj = selected[s].second;
            dist = min(dist, abs(hi - si) + abs(hj - sj));
        }
        sum += dist;
    }
    
    return sum;
}

void select(int cur, int cnt){
    
    if (cnt == m) {
        ans = min(ans, check_distance());
        return;
    }

    for (int nxt = cur + 1; nxt < all.size(); nxt ++){   
        int i = all[nxt].first;
        int j = all[nxt].second;
        selected.push_back({i, j});
        select(nxt, cnt + 1);
        selected.pop_back();
    }
}

int main(){
    input();
    for (int cur = 0; cur < all.size(); cur ++){
        int i = all[cur].first;
        int j = all[cur].second;
        selected.push_back({i, j});
        select(cur, 1);
        selected.pop_back();
    }
    cout << ans;
    return 0;
}