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
    ll x,k;
    cin>>x>>k;
    if(x%k != 0){
        cout<<1<<endl;
        cout<<x<<endl;
    }
    else {
        cout<<2<<endl;
        cout<<x-1<<" "<<1<<endl;
    }
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}