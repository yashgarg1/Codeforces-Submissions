#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

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
    vector<int> a,b;
    inp(n,a);
    inp(n,b);
    map<int,int> m1,m2;
    int cnt=1;
    for (int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            cnt++;
        }
        else {
            if(m1.find(a[i-1]) != m1.end() && m1[a[i-1]]<cnt){
                m1[a[i-1]]=cnt;
            }
            else if(m1.find(a[i-1]) == m1.end()){
                m1[a[i-1]]=cnt;
            }
            cnt=1;
        }
    }
    if(m1.find(a[n-1]) != m1.end() && m1[a[n-1]]<cnt){
        m1[a[n-1]]=cnt;
    }
    else if(m1.find(a[n-1]) == m1.end()){
        m1[a[n-1]]=cnt;
    }
    cnt=1;
    for (int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            cnt++;
        }
        else {
            if(m2.find(b[i-1]) != m2.end() && m2[b[i-1]]<cnt){
                m2[b[i-1]]=cnt;
            }
            else if(m2.find(b[i-1]) == m2.end()){
                m2[b[i-1]]=cnt;
            }
            cnt=1;
        }
    }
    if(m2.find(b[n-1]) != m2.end() && m2[b[n-1]]<cnt){
        m2[b[n-1]]=cnt;
    }
    else if(m2.find(b[n-1]) == m2.end()){
        m2[b[n-1]]=cnt;
    }
    int ans=1;
    for (auto it:m1){
        // cout<<it.first<<" "<<it.second<<endl;
        if(m2.find(it.first) != m2.end()){
            ans=max(ans,it.second+m2[it.first]);
        }
        ans=max(ans,it.second);
    }
    for (auto it:m2){
        ans=max(ans,it.second);
    }
    cout<<ans<<endl;

}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
/*
    1 3 4 2 3 3 3 3 2 1 2
    3 2 1 2 3 4 4 2 2 1 1

*/