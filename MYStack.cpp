#include<iostream>

using namespace std;

class MyStack {
    public:
    int *arr;
    int len;

    MyStack() : arr(nullptr),len(0){
        cout<<"Constructor is called"<<endl;
    }
    void push(int val){
        cout<<"Push is called"<<endl;
        int *arr_new = new int[len+1];
        for (int i=0;i<len;i++){
            arr_new[i]=arr[i];
            cout<<arr[i]<<endl;
        }
        arr_new[len]=val;
        arr=arr_new;
        len++;
    }

    void pop(){
        cout<<"Pop is called"<<endl;
        len--;
        int *arr_new = new int[len+1];
        for (int i=0;i<len;i++){
            arr_new[i]=arr[i];
        }
        arr=arr_new;
    }

    int top(){
        cout<<"Top is called"<<endl;
        return arr[len-1];
    }

    int size(){
        cout<<"Size is called"<<endl;
        return len;
    }

};

int main(){
    MyStack *st = new MyStack();
    st->push(123);
    st->push(456);
    cout<<st->size()<<endl;
    // st.pop();
    cout<<st->top()<<endl;
    st->pop();
    cout<<st->top()<<endl;
    
}