#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin>>n; 
    int maxcnt=0, minnum=n+1, type, num;

    queue<int> q;

    while(n--){
        cin>>type;
        if(type==1){
            cin>>num; 
            q.push(num);
        }
        if(type==2 || !n){
            if(q.size()>maxcnt){
                maxcnt=q.size();
                minnum=q.back();
            }
            else if(q.size()==maxcnt){
                if(q.back()<minnum)
                    minnum=q.back();
            }
            if(type==2) q.pop();
        }
    }
    cout<<maxcnt<<' '<<minnum;


}