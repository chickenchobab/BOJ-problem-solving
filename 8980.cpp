#include <iostream>
#include <algorithm>
#include <tuple>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, c, m;
tuple<int, int, int> boxes[2000];

void input(){
    fastio
    cin >> n >> c >> m;
    int a, b, s;
    for (int i = 0; i < m; i ++){
        cin >> a >> b >> s;
        boxes[i] = {a, b, s};
    }
}

int main(){
    input();

    return 0;
}