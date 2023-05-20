#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
 
#define ll long long
const ll MOD=1e9+7;
// #define for(a,b) for(int i=a;i<b;i++)
// #define input(n,v) cin>>n;vector<int> v(n);
 
using namespace std;
 
ll quickPow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1){
			res*=a;
			res%=MOD;
		}
		a*=a;
		a%=MOD;
		b>>=1;
	}
	return res;
}
 
void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> v(n);
    map<ll,ll> mp;
    set<ll> s;
    for (int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]]++;
        s.insert(v[i]);
    }
    ll ans=0,sum;
    ll mul=1;
    vector<ll> sv;
    for (auto it:s){
        sv.push_back(it);
    }
    if(m>sv.size()){
        cout<<0<<endl;
        return;
    }
    for (int i=0;i<m;i++){
        mul=mul*mp[sv[i]];
        mul=mul%MOD;
    }
    if(sv[m-1]-sv[0]==m-1){
        ans+=mul;
        ans=ans%MOD;
    }
    for (int i=m;i<sv.size();i++){
        mul=(((mul%MOD)*(mp[sv[i]]%MOD))%MOD)*(quickPow(mp[sv[i-m]],MOD-2)%MOD);
        mul=mul%MOD;
        if(sv[i]-sv[i-m+1]==m-1){
            ans+=mul;
            ans=ans%MOD;
        }
    }
    cout<<ans<<endl;
 
}
//6 7 8 9 10 11
int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}