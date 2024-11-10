#include <iostream>
#include <algorithm>
#include <set>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
string str;
bool used[26];

void input(){
    fastio
    cin >> n;
    cin.ignore();
}

int select_title_key(){

    bool start_of_word = 1;

    for (int i = 0; i < str.length(); i ++){
        if (start_of_word && !used[tolower(str[i]) - 'a']){
            used[tolower(str[i]) - 'a'] = 1;
            return i;
        }
        if (str[i] == ' ') start_of_word = 1;
        else start_of_word = 0;
    }
    return -1;
}

int select_key(){
    for (int i = 0; i < str.length(); i ++){
        if (!used[tolower(str[i]) - 'a']){
            used[tolower(str[i]) - 'a'] = 1;
            return i;
        }
    }
}

void print(int index){
    for (int i = 0; i < str.length(); i ++){
        if (i == index) cout << '[';
        cout << str[i];
        if (i == index) cout << ']';
    }
    cout << '\n';
}

void query(){
    for (int i = 0; i < n; i ++){
        getline(cin, str);

        int index = select_title_key();
        if (index != -1) {
            print(index);
            continue;
        }
        
        index = select_key();
        print(index);
    }
}

int main(){
    input();
    query();
    return 0;
}