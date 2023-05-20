#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define ll long long

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    string ans="YES";
    if(m>=n && n!=1){
        ans="NO";
    }

    else if(m<n && n%m==0 && m!=1){
        ans="NO";
    }
    while(n%m>0){
        m=m-(n%m);
    }
    if(n%m==0){
        ans="NO";
    }
    cout<<ans<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}