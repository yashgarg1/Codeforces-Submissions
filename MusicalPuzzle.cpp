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
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<string,int> mp;
    for (int i=0;i<n-1;i++){
        string k=s.substr(i,2);
        if(mp.find(k) == mp.end()){
            mp[k]++;
        }
    }
    cout<<mp.size()<<endl;
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}