#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>


using namespace std;
typedef tuple<int, int, int> e;

int n,p,sum;
int a,b,c;
int cost[10001];
int set[10001];
vector<e> ev;


int find(int x){
    if(set[x]<=0) return x;
    return (set[x]=find(set[x]));
}

void unite(int x, int y){
    int c1=find(x);
    int c2=find(y);
    if(set[c1]<set[c2])
        set[c2]=c1;
    else{
        if(set[c1]==set[c2])
            set[c2]--;
        set[c1]=c2;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    for(int i=1;i<=p;i++){
        cin>>a>>b>>c;
        ev.push_back({2*c+cost[a]+cost[b],a,b});
    }

    sort(cost+1, cost+n+1);
    sort(ev.begin(),ev.end());

    for(e tmp:ev){
        int a=get<1>(tmp);
        int b=get<2>(tmp);
        int c=get<0>(tmp);

        if(find(a)==find(b)) continue;

        unite(a,b);

        sum+=c;
            
       }
    
    cout<<sum+cost[1];

    






}