#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int t;

void input(){
    fastio
    cin >> t;
}

void query(){
    string str;
    while (t --){
        cin >> str;
        int len = str.length();
        int flag = 0;
        for (int i = len - 2; i >= 0 && flag == 0; i --){
            if (str[i] >= str[i + 1]) continue;       
            for (int j = len - 1; j > i && flag == 0; j --){
                if (str[i] >= str[j]) continue; 
                swap(str[i], str[j]);                 
                sort(str.begin() + i + 1, str.end()); 
                flag = 1;
            }
        }
        cout << str << '\n';
    }
}

int main(){
    input();
    query();
}