#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include <queue>

#define ll long long
#define pb push_back
const ll MOD=1e9+7;

using namespace std;

void inp(int n, vector<int>& v){
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> v;
    inp(n,v);
    sort(v.begin(), v.end());
    if(v[0]<0){
        cout<<v[0]<<endl;
    }
    else {
        cout<<v[n-1]<<endl;
    }
    
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}