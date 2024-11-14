#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
bool board[11][11];
bool onDiagAdd[22], onDiagSub[22];
int answer[2];

void input() {
    fastio
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> board[i][j];
        }
    }
}

bool isValid(int i, int j) {
    if (!board[i][j]) return false;
    return (!onDiagAdd[j + i - 1] && !onDiagSub[j - i + N]);
}

void placeBishop(int diagonal, int count, int color) {
    answer[color] = max(answer[color], count);

    if (diagonal >= 2 * N - 1) return;

    bool connected = false;

    if (diagonal < N) {
        for (int i = 0; i <= diagonal; ++i) {
            int r = i + 1;
            int c = diagonal - i + 1;
            if (!isValid(r, c)) continue;
            connected = true;

            onDiagAdd[r + c - 1] = 1;
            onDiagSub[c - r + N] = 1;
            placeBishop(diagonal + 2, count + 1, color);
            onDiagAdd[r + c - 1] = 0;
            onDiagSub[c - r + N] = 0;
        }
    } else {
        for (int i = diagonal - N + 1; i < N; ++i) {
            int r = i + 1;
            int c = diagonal - i + 1;
            if (!isValid(r, c)) continue;
            connected = true;

            onDiagAdd[r + c - 1] = 1;
            onDiagSub[c - r + N] = 1;
            placeBishop(diagonal + 2, count + 1, color);
            onDiagAdd[r + c - 1] = 0;
            onDiagSub[c - r + N] = 0;
        }
    }

    if (!connected) placeBishop(diagonal + 2, count, color);
}

void solve() {
    placeBishop(0, 0, 0); // Black squares
    placeBishop(1, 0, 1); // White squares
    cout << answer[0] + answer[1] << '\n';
}

int main() {
    input();
    solve();
    return 0;
}
