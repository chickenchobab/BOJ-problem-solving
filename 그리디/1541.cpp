#include <iostream>
#include <deque> 
using namespace std;

int main()
{
    //멍청한 코드
    deque<int> v;
    int num, tmp=0,result=0;
    char op;
    while(1){
        cin>>num;
        v.push_back(num+tmp);
        op=cin.get();
        if(op=='\n') break;
        if(op=='+') {
            tmp=v.back();
            v.pop_back();
        }
        else tmp=0;
    }

    result = v[0];
    for(int i=1; i<v.size(); i++){
        result+=-(v[i]);
    }

    cout<<result<<endl;
}

