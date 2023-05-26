#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define ll long long
#define pb push_back
const ll MOD=1e9+7;

using namespace std;

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=2,cnt=2;
    map<int,int> mp;
    for (int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            cnt++;
        }
        else {
            cnt=2;
        }
        ans=max(ans,cnt);
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