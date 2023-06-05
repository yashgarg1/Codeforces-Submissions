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

class TreeNode{
    public:
    int val;
    TreeNode *left, *right;

    TreeNode(int x){
        val=x;
        left=NULL,right=NULL;
    }
};

void top_view(TreeNode* root){
    map<int,int> mp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto x=q.front();
        auto a=x.first;
        auto b=x.second;
        q.pop();
        // if(mp[b]==0){
            mp[b]=a->val;
        // }
        if(a->left){
            q.push({a->left,b-1});
        }
        if(a->right){
            q.push({a->right,b+1});
        }
    }
    for (auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

int main(){
    TreeNode *root = new TreeNode(1);
    TreeNode *l = new TreeNode(2);
    TreeNode *r = new TreeNode(3);
    TreeNode *lleft = new TreeNode(4);
    TreeNode *rl = new TreeNode(5);
    root->left=l;
    root->right=r;
    l->left = lleft;
    r->left = rl;
    top_view(root);
}