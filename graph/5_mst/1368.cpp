#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> t;

int n;
long long sum;
int u[301];
priority_queue<t, vector<t>, greater<t>> e;

int find(int x){
    if(u[x]<=0) return x;
    return (u[x]=find(u[x]));
}

void unite(int a, int b){
    int c1=find(a);
    int c2=find(b);

    if(u[c1]<u[c2]){
        u[c2]=c1;
    }
    else{
        if(u[c1]==u[c2])
            u[c2]--;
        u[c1]=c2; 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        e.push({tmp,0,i});
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>tmp;
            if(i<j)e.push({tmp, i, j});
        }
    }

    while(!e.empty()){
        t tmp = e.top();
        int a=get<1>(tmp);
        int b=get<2>(tmp);
        int c=get<0>(tmp);
        e.pop();
        
        if(find(a)==find(b)) continue;
        unite(a,b);
        
    // for(int i=1;i<=n+1;i++){
    //     cout<<u[i]<<' ';
    // }
    // cout<<a<<' '<<b<<" plus:"<<c<<'\n';
        sum+=c;
    }
    

    cout<<sum;

}