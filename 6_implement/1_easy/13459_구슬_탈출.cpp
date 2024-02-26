#include <iostream>
#include <algorithm>

using namespace std;

int n, m, ri, rj, bi, bj, hi, hj;
char map[11][11];
int visited[11][11], di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void shake(int i, int j, int ii, int jj){

}

int main(){
    cin >> n >> m;

    char ch;    

    for (int i=1; i<=n; i++){
        
        for (int j=1; j<=m; j++){
            cin >> ch;
            if (ch == '\n') cin >> ch;

            map[i][j] = ch;
            visited[i][j] = 11;

            if (ch == 'R') {ri = i; rj = j;}
            else if(ch == 'B') {bi = i; bj = j;}
            else if(ch == 'O') {hi = i; hj = j;}
        }
    }
    
    visited[ri][rj] = 0;
    shake(ri, rj, bi, bj);

    visited[hi][hj] <= 10 ? cout << 1 : cout << 0;
    
}