#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int l, c;
char arr[16]; 

int alpha[2];
vector<char> v;

void input(){
    fastio
    cin >> l >> c;
    for (int i = 1; i <= c; i ++) cin >> arr[i];
}

bool vowel(char ch){
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    return false;
}

void dfs(int cur, int cnt){

    if (cnt == l) {
        if (alpha[1] < 1 || alpha[0] < 2) return;
        for (int i = 0; i < l; i ++){
            cout << v[i];
        }
        cout << '\n';
        return;
    }
    for (int nxt = cur + 1; nxt <= c; nxt ++){

        alpha[vowel(arr[nxt])] ++;
        v.push_back(arr[nxt]);

        dfs(nxt, cnt + 1);

        alpha[vowel(arr[nxt])] --;
        v.pop_back();
    }
}

int main(){
    input();
    sort(arr + 1, arr + c + 1);
    for (int i = 1; i <= c; i ++){

        alpha[vowel(arr[i])] ++;
        v.push_back(arr[i]);

        dfs(i, 1);

        alpha[vowel(arr[i])] --;
        v.pop_back();
    }
    return 0;
}