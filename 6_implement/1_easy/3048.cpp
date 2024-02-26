#include <iostream>

using namespace std;

int n1, n2, t;
char arr[55];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n1 >> n2;
    char ch;
    for (int i = n1; i >= 1; i --){
        cin >> ch;
        arr[i] = ch;
    }
    for (int i = 1; i <= n2; i ++){
        cin >> ch;
        arr[n1 + i] = -ch;
    }
    cin >> t;
}

int main(){

    input();

    int idx = n1 + n2;

    while(t --){
        for (int i = 1; i < idx; i ++){
            if (arr[i] < 0 || arr[i + 1] > 0) continue;
            swap(arr[i], arr[i + 1]);
            i ++;
        }
    }

    for (int i = 1; i <= idx; i ++){
        cout << (char) abs(arr[i]);
    }
}