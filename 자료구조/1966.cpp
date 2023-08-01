#include <iostream>
#include <queue>
#include <utility>

using namespace std;

//우선 순위를 따로 저장하는 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t,n,m,max,cnt,tmp,searched;
    cin>>t;
    for(int i=0;i<t;i++){
        queue<pair<int,int>> q;
        cin>>n>>m;
        max=0;
        for(int j=0;j<n;j++){
            cin>>tmp;
            if(max<=tmp) max=tmp;
            if(j==m) q.push({tmp,1});
            else q.push({tmp,0});
        }
        
        searched=0,cnt=0;
        while(1){
            int pr=q.front().first;
            if(pr>=max) {
                cnt++; searched=0;
                if(q.front().second) break;
            }
            else {
                q.push(q.front()); searched++;
            }
            q.pop();
            if(!q.empty() && searched==q.size()){
                searched=0; max--;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;

}