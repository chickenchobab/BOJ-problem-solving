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
            if (str[i] >= str[i + 1]) continue;       // 내림 차순이 처음으로 깨지는 i를 뒤에서부터 찾는다
            for (int j = len - 1; j > i && flag == 0; j --){
                if (str[i] >= str[j]) continue; 
                swap(str[i], str[j]);                 // i보다 사전 순으로 크지만 가장 작은 j를 찾아 스왑한다
                sort(str.begin() + i + 1, str.end()); // 처리가 끝난 i 뒤로는 사전순으로 가장 작은 문자열을 만든다
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