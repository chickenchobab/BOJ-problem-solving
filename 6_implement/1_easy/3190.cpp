#include <iostream>
#include <algorithm>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, k, l;
bool map[101][101], body[101][101];

int tick, dir;
int turn[10001];
int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
typedef pair<int, int> p;
deque<p> snake;

void input(){
    fastio
    cin >> n >> k;
    int a, b, x;
    char c;
    for (int i = 0; i < k; i ++){
        cin >> a >> b;
        map[a][b] = 1;
    }
    cin >> l;
    for (int i = 0; i < l; i ++){
        cin >> x >> c;
        c == 'D'? turn[x] = 1 : turn[x] = 3;
    }
}

void solve(){
    int i, j, ni, nj;
    snake.push_back({1, 1});
    body[1][1] = 1;
    while (1){
        p head = snake.front();
        i = head.first, j = head.second;
        dir = (dir + turn[tick]) % 4;
        ni = i + di[dir], nj = j + dj[dir];

        if (ni < 1 || ni > n || nj < 1 || nj > n) break;
        if (body[ni][nj]) break;
        
        snake.push_front({ni, nj});
        body[ni][nj] = 1;
        if (map[ni][nj] == 0) {
            p tail = snake.back();
            i = tail.first, j = tail.second;
            body[i][j] = 0;
            snake.pop_back();
        }
        else 
            map[ni][nj] = 0;
        tick ++;
    }
    cout << tick + 1;
}

int main(){
    input();
    solve();
    return 0;
}