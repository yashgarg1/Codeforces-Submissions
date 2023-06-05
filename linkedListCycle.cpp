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

class LNode{
    public:
    int val;
    LNode *next;

    LNode(int x){
        val=x;
        next=NULL;
    }
};

bool hasCycle(LNode *head) {
    map<LNode*, int> mp;
    while(head != NULL){
        if(mp.find(head) != mp.end()){
            return true;
        }
        mp[head]=1;
        head=head->next;
    }
    return false;
}

int main(){
    LNode *head=new LNode(1);
    LNode *a=new LNode(2);
    LNode *b=new LNode(3);
    LNode *c=new LNode(4);
    LNode *d=new LNode(5);
    LNode *e=new LNode(6);
    head->next=a;
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    // e->next=c;
    cout<<hasCycle(head)<<endl;
}