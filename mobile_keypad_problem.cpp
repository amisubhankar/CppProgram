#include<iostream>
#include<map>
#include<vector>
using namespace std;

void generate(string num,map<string,string> mp,string op,vector<string> &ans){
    if(num.length()==0){
        ans.push_back(op);
        return;
    }

    string digit=num.substr(0,1);
    string letters=mp[digit];
    for(int i=0;i<letters.length();i++){
        generate(num.substr(1),mp,op+letters[i],ans);
    }
}

int main(){
    string num="234";
    vector<string> ans;
    map<string,string> mp;
    mp["2"]="abc";
    mp["3"]="def";
    mp["4"]="ghi";
    mp["5"]="jkl";
    mp["6"]="mno";
    mp["7"]="pqrs";
    mp["8"]="tuv";
    mp["9"]="wxyz";

    generate(num,mp,"",ans);
    for(string str: ans){
        cout<<"'"<<str<<"'"<<" ";
    }
}