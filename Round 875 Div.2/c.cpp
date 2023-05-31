// #include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define int long long
#define ll long long
#define ull unsigned long long
#define  FOR(i,n) for(long long i = 0; i < (n); i++)
#define  FOR1(i,n) for(long long i = 1; i <= (n); i++)
#define  FOR2(i,n) for(long long i = 2; i <= (n); i++)
#define pb push_back
#define V vector<int>
#define VV vector<V>
#define VVV vector<VV>
#define el cout<<endl;
#define fi first
#define se second
#define noo cout<<"NO"<<endl;
#define yess cout<<"YES"<<endl;
#define take(a,n) FOR(i,n) cin>>a[i];
#define print(v) for(auto it:v) cout<<it<<" "; el
#define all(v) v.begin(),v.end()
#define sort(v) sort(v.begin(),v.end())
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define w(T) 	ll T; cin>>T; while(T--)
#define input(a,n) int n; cin>>n; V a(n); take(a,n);
#define pii pair<int,int>

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1) res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res%m ;}
int nCr(int n , int r){
    if (n < r) return 0;
    if (r > n - r) r = n - r;
    ll ans = 1; ll i;
    for (i = 1; i <= r; i++){ans = (ans*(n - r + i));ans /= i;} return ans;
}
ll modinv(ll a , ll m ) {return expo(a , m-2 , m)%m;} // m is prime 
 
using namespace std;

//  int c = std::count(s.begin(), s.end(), '(');
// to_string, stoi, stoll, gcd - already exist

const int N = 2e5+4;
vector<int> g[N];
int vis[N];
int ans;
map<pii,int> mp;

void dfs(int v,int mn,int temp){
    vis[v]=1;

    for(auto u:g[v]){
        if(vis[u]) continue;
        if(mn > mp[{u,v}]){
            temp++;
            mn=mp[{u,v}];
        }
        cout<<v<<"->"<<u<<"  "<<temp<<endl;
        if(g[u].size()==1){
            // cout<<v<<","<<mn<<" ";
            ans=max(ans,temp);
        }
        dfs(u,mn,temp);
    }
}


int32_t main() {
    fast
    w(t){
        int n; cin>>n;
        ans=1; mp.clear();
        FOR(i,n+1){
             vis[i]=0; g[i].clear();
        }
        FOR(i,n-1){
            int u,v; cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
            mp[{u,v}]=i+1; mp[{v,u}]=i+1;
        }

        dfs(1,2e5+5+1,0);
        cout<<ans<<endl;

    }

	return 0;
}