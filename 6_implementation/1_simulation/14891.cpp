#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

bool gear[4][8];
int k;
int startIdx[4];

void input(){
    fastio
    string str;
    for (int i = 0; i < 4; i ++){
        cin >> str;
        for (int j = 0; j < 8; j ++){
            gear[i][j] = str[j] - '0';
        }
    }
    cin >> k;
}

void rotate(int g, int d, int dir){
    if (g != 3 && dir != 1){
        if (gear[g][(startIdx[g] + 2) % 8] != gear[g + 1][(startIdx[g + 1] + 6) % 8])
            rotate(g + 1, -d, 2);
    }
    if (g != 0 && dir != 2) {
        if (gear[g][(startIdx[g] + 6) % 8] != gear[g - 1][(startIdx[g - 1] + 2) % 8])
            rotate(g - 1, -d, 1);
    }

    if (d == 1)  startIdx[g] = (startIdx[g] + 8 - 1) % 8;
    else startIdx[g] = (startIdx[g] + 1) % 8;
}

int getGrade(){
    int sum = 0;
    sum += gear[0][startIdx[0]];
    sum += 2 * gear[1][startIdx[1]];
    sum += 4 * gear[2][startIdx[2]];
    sum += 8 * gear[3][startIdx[3]];
    return sum;
}

int main(){
    input();
    int g, d;
    while (k --){
        cin >> g >> d;
        rotate(g - 1, d, 0);
    }
    cout << getGrade();
    return 0;
}