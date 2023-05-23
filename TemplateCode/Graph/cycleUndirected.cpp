#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define ll long long
const ll MOD=1e9+7;

using namespace std;

bool dfs(int u, int par, vector<int> &vis, vector<vector<int>> graph){
    if(vis[u]==1){
        return true;
    }
    vis[u]=1;
    for (int i=0;i<graph[u].size();i++){
        if(graph[u][i]==par){
            continue;
        }
        if(dfs(graph[u][i], u, vis, graph)){
            return true;
        }
    }
    return false;
}

//0 based indexing
bool hasCycleUndirected(int n, vector<vector<int>> graph){
    vector<int> vis(n,0);
    for (int i=0;i<n;i++){
        if(vis[i]==0){
            bool cycle=dfs(i, -1, vis, graph);
            if(cycle){return true;}
        }
    }
    return false;
}

// 1 based indexing
bool hasCycleUndirected1(int n, vector<vector<int>> graph){
    vector<int> vis(n+1,0);
    for (int i=1;i<=n;i++){
        if(vis[i]==0){
            bool cycle=dfs(i, -1, vis, graph);
            if(cycle){return true;}
        }
    }
    return false;
}

void solve(){
    int n,num_nodes;
    cin>>n>>num_nodes;
    vector<vector<int>> graph(n+1);
    for (int i=0;i<num_nodes;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if(hasCycleUndirected1(n, graph)){
        cout<<"Cycle detected"<<endl;
    }
    else {
        cout<<"No Cycle"<<endl;
    }
}

int main(){
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}