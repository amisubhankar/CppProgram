#include<iostream>
using namespace std;

void subsets(string str,string op){
    if(str.length()==0){
        (op.length()==0)?cout<<"NULL"<<endl:cout<<op<<endl;
        return;
    }
    subsets(str.substr(1),op);
    subsets(str.substr(1),op+str[0]);
}

int main(){
    string str="ABC";

    subsets(str,"");
}