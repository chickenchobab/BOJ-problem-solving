#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<pair<int,int>> v;
    int rank[1000000],n,tmp,cnt=0;
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back({tmp,i});
    }
    sort(v.begin(), v.end());
    
    for(auto i=v.begin();i<v.end();i++){
        if(i>v.begin() && (*i).first==(*(i-1)).first)
            rank[(*i).second]=rank[(*(i-1)).second];
        else
            rank[(*i).second]=cnt++;
    }
    for(int i=0;i<n;i++){
        cout<<rank[i]<<' ';
    }




    

}