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
    vector<int> v(n),ans;
    for (int i=0;i<n;i++){
        cin>>v[i];
    }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    bool mxi=false;
    int maxindex=0;
    for (int i=0;i<n;i++){
        if(v[i]==n){
            mxi=true;
            maxindex=i;
        }
        if(mxi){
            ans.push_back(v[i]);
        }
    }

    if(maxindex==n-1){
        if(v[maxindex-1]<=v[0]){
            for (int i=0;i<maxindex;i++){
                ans.push_back(v[i]);
            }
            for (int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
            return;
        }
    }

    if(maxindex==0){
        bool mx1=false;
        int secindex=0;
        vector<int> ans1;
        for (int i=0;i<n;i++){
            if(v[i]==n-1){
                mx1=true;
                secindex=i;
            }
            if(mx1){
                ans1.push_back(v[i]);
            }
        }
        if(secindex==n-1){
            for (int i=0;i<secindex;i++){
                ans1.push_back(v[i]);
            }
        }
        else{
            ans1.push_back(v[secindex-1]);
            for (int i=0;i<secindex-1;i++){
                ans1.push_back(v[i]);
            }
        }
        for (int i=0;i<n;i++){
            cout<<ans1[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(maxindex-1>=0){
        ans.push_back(v[maxindex-1]);
    }

    int lastindex=-1;
    for (int i=maxindex-2;i>=0;i--){
        if(v[i]>v[0]){
            ans.push_back(v[i]);
        }
        else {
            lastindex=i;
            break;
        }
    }
    if(lastindex>=0){
        for (int i=0;i<=lastindex;i++){
            ans.push_back(v[i]);
        }
    }
    for (int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
//handle reverse sorted array
//
int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}