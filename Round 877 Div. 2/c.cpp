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

#include <bits/stdc++.h>
using namespace std;
 
bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void inp(int n, vector<int>& v){
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    int k=1;
    vector<vector<int>> ans(n,vector<int> (m,0));
    if(!isPrime(n) || !isPrime(m)){
        if(!isPrime(n)){
            for (int i=0;i<m;i++){
                for (int j=0;j<n;j++){
                    ans[j][i]=k++;
                }
            }
        }
        else {
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++){
                    ans[i][j]=k++;
                }
            }
        }
    }
    else {
        for (int i=0;i<=n/2;i++){
            for (int j=0;j<m;j++){
                ans[i][j]=k++;
            }
            k+=m;
        }
        k=1+m;
        for (int i=(n/2)+1;i<n;i++){
            for (int j=0;j<m;j++){
                ans[i][j]=k++;
            }
            k+=m;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}