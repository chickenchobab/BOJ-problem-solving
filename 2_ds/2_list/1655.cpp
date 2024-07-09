#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n;
priority_queue<int, vector<int>, less<int>> maxq;
priority_queue<int, vector<int>, greater<int>> minq;

void input(){
    fastio
    cin >> n;
}

void solve(){
    int num;
    while (n --){
        cin >> num;
        if (maxq.size() <= minq.size()){
            if (minq.size() && num > minq.top()){
                minq.push(num);
                num = minq.top();
                minq.pop();
            }
            maxq.push(num);
        }
        else{
            if (maxq.size() && num < maxq.top()){
                maxq.push(num);
                num = maxq.top();
                maxq.pop();
            }
            minq.push(num);
        }   
        cout << maxq.top() << '\n';
    }
}

int main(){
    input();
    solve();
    return 0;
}