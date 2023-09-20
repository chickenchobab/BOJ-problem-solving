#include <iostream>
using namespace std;
#include <tuple>

int dp[20001][21];
int N, T, D, P;
tuple<int, int, int> t[21];
pair<int, int> mx;

int main(void) {
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> T >> D >> P;
        t[i] = {T, D, P};
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= 20001; ++j) {
            if (j - get<0>(t[i]) >= 0 && j <= get<1>(t[i]) + 24) {
                int score;
                if (j > get<1>(t[i])) score = get<2>(t[i]) / 2;
                else score = get<2>(t[i]);

                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - get<0>(t[i])] + score);
            } else dp[i][j] = dp[i - 1][j];
            if (mx.first < dp[i][j]) {
                mx = {dp[i][j], j};
            }
        }
    }
    cout << mx.first << " " << mx.second;
    return 0;
}