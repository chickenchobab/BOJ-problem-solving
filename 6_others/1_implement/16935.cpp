#include <iostream>
// #include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M, R;
int A[101][101], B[101][101];

void input(){
  fastio
  cin >> N >> M >> R;
  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= M; ++j){
      cin >> A[i][j];
    }
  }
}

void copyState(int from[101][101], int to[101][101]){
  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= M; ++j){
      to[i][j] = from[i][j];
    }
  }
}

void mirrorUpDown(){

  copyState(A, B);
  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= M; ++j){
      A[i][j] = B[N + 1 - i][j];
    }
  }
}

void mirrorLeftRight(){

  copyState(A, B);
  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= M; ++j){
      A[i][j] = B[i][M + 1 - j];
    }
  }
}

void rotate(){
  copyState(A, B);
  swap(N, M);
  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= M; ++j){
      A[i][j] = B[M + 1 - j][i];
    }
  }
}

void rotateCCW(){
  copyState(A, B);
  swap(N, M);
  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= M; ++j){
      A[i][j] = B[j][N + 1 - i];
    }
  }
}

void rotateSubarr(){
  copyState(A, B);
  int H = N / 2, W = M / 2;
  for (int i = 1; i <= H; ++i){
    for (int j = 1; j <= W; ++j){
      A[i][j] = B[i + H][j];
    }
  }
  for (int i = H + 1; i <= N; ++i){
    for (int j = 1; j <= W; ++j){
      A[i][j] = B[i][j + W];
    }
  }
  for (int i = H + 1; i <= N; ++i){
    for (int j = W + 1; j <= M; ++j){
      A[i][j] = B[i - H][j];
    }
  }
  for (int i = 1; i <= H; ++i){
    for (int j = W + 1; j <= M; ++j){
      A[i][j] = B[i][j - W];
    }
  }
}

void rotateSubarrCCW(){
  copyState(A, B);
  int H = N / 2, W = M / 2;
  for (int i = 1; i <= H; ++i){
    for (int j = 1; j <= W; ++j){
      A[i][j] = B[i][j + W];
    }
  }
  for (int i = H + 1; i <= N; ++i){
    for (int j = 1; j <= W; ++j){
      A[i][j] = B[i - H][j];
    }
  }
  for (int i = H + 1; i <= N; ++i){
    for (int j = W + 1; j <= M; ++j){
      A[i][j] = B[i][j - W];
    }
  }
  for (int i = 1; i <= H; ++i){
    for (int j = W + 1; j <= M; ++j){
      A[i][j] = B[i + H][j];
    }
  }
}



void solve(){
  int command;
  void (*funcPtr[7])(void);
  funcPtr[1] = mirrorUpDown;
  funcPtr[2] = mirrorLeftRight;
  funcPtr[3] = rotate;
  funcPtr[4] = rotateCCW;
  funcPtr[5] = rotateSubarr;
  funcPtr[6] = rotateSubarrCCW;

  while (R--){
    cin >> command;
    (*funcPtr[command])();
  }
  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= M; ++j){
      cout << A[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main(){
  input();
  solve();
  return 0;
}