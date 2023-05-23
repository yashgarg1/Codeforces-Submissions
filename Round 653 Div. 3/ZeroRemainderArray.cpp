#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define ll long long
const ll MOD=1e9+7;

using namespace std;

void solve(){
    ll n,k;
    cin>>n>>k;
    map<ll,ll> mp;
    ll ans=0;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x%k]++;
        if(x%k){
            ans=max(ans, (mp[x%k]-1)*k + (k-x%k+1));
        }
    }
    cout<<ans<<endl;
    
    // cout<<min_val<<" "<<freqcnt<<endl;

}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}