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
    ll n;
    cin>>n;
    vector<ll> v(n);
    ll eve=0,odd=0,minodd,mineve;
    bool firstodd=true,firsteve=true;
    for (ll i=0;i<n;i++){
        cin>>v[i];
        if(v[i]%2==0){
            eve++;
            if(firsteve){
                mineve=v[i];
                firsteve=false;
            }
            mineve=min(mineve, v[i]);
        }
        else {
            odd++;
            if(firstodd){
                minodd=v[i];
                firstodd=false;
            }
            minodd=min(minodd, v[i]);
        }
    }
    string ans="NO";
    if(eve==n || odd==n){
        ans="YES";
    }
    else if(mineve>minodd){
        ans="YES";
    }
    // cout<<"mineve = "<<mineve<<"  minodd = "<<minodd<<endl;
    cout<<ans<<endl;

}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}