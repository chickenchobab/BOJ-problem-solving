#include <iostream>
#include <deque>

using namespace std;

string str;
char ch;
deque<char> dq;

int main(){
    cin>>str;

    int cnt=0;
    int i=0, j=str.length();

    while((ch=cin.get())!='\n'){
        dq.push_back(ch);
    }

    while(!dq.empty()){

        if(dq.front()!=str[i]){
            dq.push_back(dq.front());
            dq.pop_front(); 
            cnt++; 
        } 
        else{
            i++;


        }

    }


}