#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>

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
    int n,k,temp;
    cin>>n>>k;
    temp=n;
    int cnt=0;
    while(n>0){
        n/=2;
        cnt++;
    }
    // cout<<"cnt = "<<cnt<<endl;
    if(cnt>k){
        cout<<(1<<k)<<endl;
    }
    else {
        cout<<temp+1<<endl;
    }
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
/*
5
1 2 4 8 16 32

*/