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
    int one=0,two=0,m=0;
    for (int i=0;i<n;i++){
        if(v[i]==1){
            one=i+1;
        }
        if(v[i]==2){
            two=i+1;
        }
        if(v[i]==n){
            m=i+1;
        }
    }
    if((one<m && m<two) || (one>m && m>two)){
        cout<<1<<" "<<1<<endl;
    }
    else if(m<one && m<two){
        if(one<two){
            cout<<m<<" "<<one<<endl;
        }
        else {
            cout<<m<<" "<<two<<endl;
        }
    }
    else if(m>one && m>two){
        if(one<two){
            cout<<m<<" "<<two<<endl;
        }
        else {
            cout<<m<<" "<<one<<endl;
        }
    }
    else {
        cout<<1<<" "<<1<<endl;
    }
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}