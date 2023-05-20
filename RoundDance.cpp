#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define ll long long
// #define for(a,b) for(int i=a;i<b;i++)
// #define input(n,v) cin>>n;vector<int> v(n);

using namespace std;

void dfs(int i, vector<vector<int>>& graph,vector<int>& vis){
    if(vis[i]==1){
        return ;
    }
    vis[i]=1;
    for (int j=0;j<graph[i].size();j++){
        dfs(graph[i][j], graph,vis);
    }
    return ;
}

void solve(){
    int n;
    cin>>n;
    vector<int> v(n),ans;
    vector<vector<int>> graph(n+1);
    vector<int> vis(n+1,0);
    int total=0,mini=0;
    for (int i=0;i<n;i++){
        cin>>v[i];
        graph[i+1].push_back(v[i]);
        graph[v[i]].push_back(i+1);
    }
    for (int i=0;i<n;i++){
        if(vis[i+1]==0){
            dfs(i+1,graph,vis);
            total++;
        }
    }
    cout<<mini<<" "<<total<<endl;
    
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}