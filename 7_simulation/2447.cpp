#include <iostream>
// #include <algorithm>
// #include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
char grid[3*3*3*3*3*3*3][3*3*3*3*3*3*3];

void pointStar(int r, int c, int curSize)
{
  if (curSize == 1)
  {
    grid[r][c] = '*';
    return;
  }

  int newSize = curSize / 3;

  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    { 
      if (i == 1 && j == 1) continue;

      pointStar(r + i * newSize, c + j * newSize, newSize);
    }
  }
}

void draw()
{
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      if (grid[i][j] == '*')
        cout << grid[i][j];
      else
        cout << ' ';
    }
    cout << '\n';
  }
}

int main()
{
  fastio

  cin >> N;
  pointStar(0, 0, N);
  draw();

  return 0;
}