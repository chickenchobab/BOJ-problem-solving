#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];
int idx;

// pre to post

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num;
    while (cin >> num) {
		arr[++ idx] = num;
	}
}

void print(int s, int e){
    
    if (s > e) return;
    int root = arr[s];
    int mid;
    for (mid = s + 1; mid <= idx && arr[mid] < root; mid ++);

    print(s + 1, mid - 1);
    print(mid, e);
    cout << root << '\n';
}

int main(){
    input();
    print(1, idx);
}