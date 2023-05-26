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
    string s;
    cin>>s;
    int i=0,j=s.length()-1;
    string ans="";
    while(s[i]=='?'){
        s[i]='0';
        i++;
    }
    while(s[j]=='?'){
        s[j]='1';
        j--;
    }
    for (int k=i;k<j;k++){
        if(s[k]=='?'){
            if(s[k-1]=='1'){
                s[k]='1';
            }
            else if(s[k-1]=='0'){
                s[k]='0';
            }
        }
    }
    cout<<s<<endl;
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}