#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
char classroom[12][12];
int dp[10][1 << 10];

// linear search와 state에 대한 shift 연산으로도 가능함.

bool haveZeroBit(int mask, int col){
  return !(mask & (1 << col)) || !(mask & (1 << (col - 1)));
}

bool isValid(int mask){
  for (int col = 1; col < M; ++col)
    if (!haveZeroBit(mask, col))
      return false;
  return true;
}

void createPresets(unordered_set<int> &presets){
  int fullMask = (1 << M);
  for (int mask = 0; mask < fullMask; ++mask)
    if (isValid(mask))
      presets.insert(mask);
}

int countSeats(int row, int cur){
  int cnt = 0;
  for (int col = 0; col < M; ++col){
    if (!(cur & (1 << col)))
      continue;
    if (classroom[row][col] == 'x')
      return 0;
    ++cnt;
  }
  return cnt;
}

int countSeatsNotToCheat(int row, int prv, int cur){
  int cnt = 0;
  for (int col = 0; col < M; ++col){
    if (!(cur & (1 << col)))
      continue;
    if (classroom[row][col] == 'x')
      return 0;
    if ((col > 0 && prv & (1 << (col - 1))) || (col < M - 1 && prv & (1 << (col + 1))))
      continue;
    ++cnt;
  }
  return cnt;
}

void solve(){
  int answer = 0;
  unordered_set<int> presets;

  createPresets(presets);

  for (int bitset : presets){
    dp[0][bitset] = countSeats(0, bitset);
    answer = max(answer, dp[0][bitset]);
  }

  for (int r = 1; r < N; ++r){
    for (int prv : presets){
      for (int cur : presets){
        dp[r][cur] = max(dp[r][cur], dp[r - 1][prv] + countSeatsNotToCheat(r, prv, cur));
        answer = max(answer, dp[r][cur]);
      }
    }
  }

  cout << answer << '\n';
}

void init(){
  cin >> N >> M;
  for (int r = 0; r < N; ++r)
    for (int c = 0; c < M; ++c)
      cin >> classroom[r][c];
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < (1 << M); ++j)
      dp[i][j] = 0;
}

int main(){
  fastio
  int C;
  cin >> C;
  while (C--){
    init();
    solve();
  }
  return 0;
}