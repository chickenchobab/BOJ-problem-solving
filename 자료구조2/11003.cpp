#include <iostream>
#include <deque>

using namespace std;

typedef pair<int,int> p;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,l,idx,tmp;
    cin>>n>>l;
    
    deque<p> dq;

    for(int i=1;i<=n;i++){
        cin>>tmp;
        idx=i-l+1;

        // for(int j=0; j<dq.size(); j++){
        //     cout<<dq[j].first<<','<<dq[j].second<<' ';
        // }
        // cout<<endl;

        while(!dq.empty() && dq.back().first>tmp){
            dq.pop_back();
        }
        dq.push_back({tmp,i});

        while(!dq.empty() && dq.front().second<idx){
            dq.pop_front();
        }
        cout<<dq.front().first<<' ';
    }
}