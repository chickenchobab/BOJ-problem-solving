#include <iostream>

using namespace std;

int n, m;
char map[11][11];

int main(){
    cin >> n >> m;

    char ch;    

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> ch;
            if (ch == '\n') cin >> ch;
            map[i][j] = ch;
        }
    }

    
}