#include<iostream>

using namespace std;

class String{
    public:
    String() : res(nullptr), len(0){
        cout<<"Default constructor is called"<<endl;
    }
    String(const char* ch){
        cout<<"Parametrised constructor is called"<<endl;
        len = strlen(ch);
        res = new char[len+1];
        strcpy(res, ch);
    }

    String(const String& str){
        cout<<"Copy constructor is called"<<endl;
        len = str.len;
        res = new char[len+1];
        strcpy(res, str.res);
    }

    String& operator=(const String &str){
        cout<<"Copy assignment operator is called"<<endl;
        if(this != &str){
            delete[] res;
            len = str.len;
            res = new char[len+1];
            strcpy(res, str.res);
            
        }
        return *this;
    }

    int length(){
        cout<<"Length function is called"<<endl;
        return len;
    }

    friend ostream& operator<<(ostream& out, const String& str); 

    private:
    char * res;
    unsigned int len;

};


ostream& operator<<(ostream& out, const String& str){
    out<<str.res;
    return out;
}

int main(){
    String str1;
    String str2="hello";
    String str3=str2;
    str1=str2;
    int len=str1.length();
    cout<<len<<endl;
    cout<<str2<<str1;
    // cout<<str1.len<<endl; 
}