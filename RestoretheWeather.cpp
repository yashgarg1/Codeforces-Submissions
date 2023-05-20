#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define ll long long
// #define for(a,b) for(int i=a;i<b;i++)
// #define input(n,v) cin>>n;vector<int> v(n);

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n),c(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        cin>>b[i];
    }
    c=a;
    // sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<pair<int,int>> vp,vp1;
    for (int i=0;i<n;i++){
        vp.push_back({a[i], i});
    }
    sort(vp.begin(), vp.end());
    vector<int> ans(n);
    for (int i=0;i<n;i++){
        int x=vp[i].second ,y=b[i];
        ans[x]=y;
    }
    
    for (int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}