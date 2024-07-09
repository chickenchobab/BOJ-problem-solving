#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define MAX 100

using namespace std;

typedef pair<pair<int, int>, int> p;
int n, m;
int map[1001][1001], punch[1001][1001];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void input(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    char ch;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> ch;
            if (!isdigit(ch)) cin >> ch;
            map[i][j] = ch - '0';
            punch[i][j] = MAX;
        }
    }
}

int bfs(){

    queue<p> q;
    punch[1][1] = 0;
    q.push({{1, 1}, 1});

    while (q.size()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int cnt = q.front().second;
        if (i == n && j == m) return cnt;
        q.pop();

        for (int d = 0; d < 4; d ++){
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
            
            if (map[ni][nj]){
                if (punch[i][j] == 1) continue;
                if (punch[ni][nj] <= punch[i][j] + 1) continue;
                punch[ni][nj] = punch[i][j] + 1;
                q.push({{ni, nj}, cnt + 1});
            }
            else {
                if (punch[ni][nj] <= punch[i][j]) continue;
                punch[ni][nj] = punch[i][j];
                q.push({{ni, nj}, cnt + 1});
            } 
        }
    }

    return -1;
}

// void show(){

//     for (int i = 1; i <= n; i ++){
//         for (int j = 1; j <= m; j ++){
//             cout << map[i][j] << ' ';
//         }
//         cout << '\n';
//     }

//     for (int i = 1; i <= n; i ++){
//         for (int j = 1; j <= m; j ++){
//             cout << "{" << punch[i][j][0] << "," << punch[i][j][1] << "} ";
//         }
//         cout << '\n';
//     }
// }

int main(){
    input();
    cout << bfs();
    return 0;
}