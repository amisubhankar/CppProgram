#include<iostream>
#include<stack>
using namespace std;
/*
int main(){
    string str="Crack the coding interview";
    string ans="";
    string temp="";
    for(int i=0;i<str.length();i++){
        if(str[i]!=' '){
            temp+=str[i];
        }
        else{
            ans=temp+" "+ans;
            temp="";
        }
    }
    ans=temp+" "+ans;
    cout<<ans;
}
*/
//If we're not using any extra string
//we're reversing in given string only..
void swap(string &str,int strt,int end){
    char temp=str[strt];
    str[strt]=str[end];
    str[end]=temp;
}
void reverse(string &str,int strt,int end){
    while(strt<end)
        swap(str,strt++,end--);
}
int main(){
    string str="Cracking the coding interview";
    int low=0,high=0;
    //1st--> Reverse each word
    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            reverse(str,low,high);
            low=i+1;
        }
        else{
            high=i;
        }
    }
    //for reversing last word
    reverse(str,low,high);
    //cout<<str<<endl;
    //2nd--> Reverse the whole string
    reverse(str,0,str.length()-1);

    cout<<str;
}