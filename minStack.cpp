#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include <queue>
#include<stack>

#define ll long long
#define pb push_back
const ll MOD=1e9+7;

using namespace std;

class MinStack {
public:
    stack<pair<int,int>> s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val,val});
        }
        else {
            s.push({val,min(val,s.top().second)});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

int main(){
    MinStack *s = new MinStack();
    s->push(-2);
    s->push(0);
    s->push(-3);
    cout<<s->getMin()<<endl;
    cout<<s->top()<<endl;
    s->pop();
    cout<<s->top()<<endl;
    cout<<s->getMin()<<endl;
}