#include <iostream>
// #include <algorithm>
// #include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n;
int inorder[100001], postorder[100001];
int inorderRootPos[100001];

void makeTree(int inStart, int inEnd, int postRoot)
{
  if (inStart > inEnd)
  {
    return;
  }

  int parent = postorder[postRoot];
  int inRoot = inorderRootPos[parent];

  cout << parent << ' ';

  makeTree(inStart, inRoot - 1, postRoot - (inEnd - inRoot + 1));
  makeTree(inRoot + 1, inEnd, postRoot - 1);
}

int main()
{
  fastio

  cin >> n;
  for (int i = 1; i <= n; ++i)
  {
    cin >> inorder[i];
    inorderRootPos[inorder[i]] = i;
  }
  for (int i = 1; i <= n; ++i)
  {
    cin >> postorder[i];
  }

  makeTree(1, n, 1);

  return 0;
}