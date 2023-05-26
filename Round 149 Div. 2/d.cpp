#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>

#define ll long long
#define pb push_back
const ll MOD=1e9+7;

using namespace std;

bool isValid1(string s) {
    stack<char> st;
    for (int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else {
            if(s[i]==')' && !st.empty() && st.top()=='('){
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    if(!st.empty()){
        return false;
    }
    return true;
}

void run1(stack<char> &st, int& i, string s, vector<int>& v){
    for (;i<s.length();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else {
            if(s[i]==')' && !st.empty() && st.top()=='('){
                st.pop();
            }
        }
        if(st.empty()){
            v[i]=1;
            return ;
        }
    }
}

void run2(stack<char> &st, int& i, string s, vector<int>& v){
    for (;i<s.length();i++){
        if(s[i]==')'){
            st.push(s[i]);
        }
        else {
            if(s[i]=='(' && !st.empty() && st.top()==')'){
                st.pop();
            }
        }
        if(st.empty()){
            v[i]=2;
            return ;
        }
    }
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<char> s1,s2;
    vector<int> v(n,0);
    for (int i=0;i<n;i++){
        if(s[i]=='('){
            run1(s1,i,s,v);
        }
        else {
            run2(s2,i,s,v);
        }
    }
    if(!s1.empty() || !s2.empty()){
        cout<<-1<<endl;
        return ;
    }
    for (int i=n-2;i>=0;i--){
        if(v[i]==0){
            v[i]=v[i+1];
        }
    }
    int cnt=0,cnt2=0,cnt1=0;
    for (int i=0;i<n;i++){
        if(v[i]==0)
        cnt++;
        if(v[i]==2){
            cnt2++;
        }
        if(v[i]==1){cnt1++;}
    }
    if(cnt==n){
        cout<<-1<<endl;
        return;
    }
    if(cnt2==n){
        for (int i=0;i<n;i++){
            v[i]=1;
        }
    }
    if(cnt1==n || cnt2==n){
        cout<<"1"<<endl;
    }
    else {
        cout<<"2"<<endl;
    }
    for (int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}

/*

if(s[i]=='('){
            s1.push(s[i]);
        }
        else {
            if(s[i]==')' && !s1.empty() && s1.top()=='('){
                s1.pop();
            }
        }
        if(s1.empty()){
            v[i]=1;
            while(!s2.empty()){
                s2.pop();
            }
            if(i<n-1){
                s1.push(s[i+1]);
                s2.push(s[i+1]);
            }
            continue;
        }
        if(s[i]==')'){
            s2.push(s[i]);
        }
        else {
            if(s[i]=='(' && !s2.empty() && s2.top()==')'){
                s2.pop();
            }
        }
        if(s2.empty()){
            v[i]=2;
            while(!s1.empty()){
                s1.pop();
            }
            if(i<n-1){
                s1.push(s[i+1]);
                s2.push(s[i+1]);
            }
            continue;
        }
*/