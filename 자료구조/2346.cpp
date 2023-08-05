#include <iostream>
#include <utility>
#include <deque>

using namespace std;

int main(){
    int n, tmp, move, idx;
    cin>>n;

    deque<pair<int,int>> dq;

    for(int i=1;i<=n;i++){
        cin>>tmp;
        dq.push_back({tmp,i});
    }

    while(!dq.empty()){
        
        move = dq.front().first;
        cout<<dq.front().second<<' ';
        dq.pop_front();

        if(move>0){
            move--;
            while(move--){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            move=-(move);
            while(move--){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    

    
    
}