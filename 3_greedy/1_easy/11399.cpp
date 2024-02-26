#include <iostream>
#include <algorithm>

using namespace std;

int n;
int time[1001];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> time[i];
    }
}

int main(){

    input();
    sort(time + 1, time + n + 1);
    int sum = time[1];
    for (int i = 2; i <= n; i ++){
        time[i] += time[i - 1];
        sum += time[i];
    }
    cout << sum;

}