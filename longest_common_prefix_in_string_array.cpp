//Graph 10)
#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    Node *link[26];
    bool end=false;
    int count=0;

};
class Trie{
    public:
    Node *root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node *node=root;
        for(int i=0;i<word.length();i++){
            if(node->link[word[i]-'a']==NULL){
                node->link[word[i]-'a']=new Node();
                node->count=node->count+1;
            }
            node=node->link[word[i]-'a'];
        }
        node->end=true;
    }
    string findLongestCommonPrefix(Node *node,string ans){
        if(node->end==true || node->count>1){
            return ans;
        }
        for(int i=0;i<26;i++){
            if(node->link[i]!=NULL){
                char ch='a'+i;
                ans+=ch;
                return findLongestCommonPrefix(node->link[i],ans);
            }
        }
    }
};

int main(){
    vector<string> str={"flu","flower","flight"};
    Trie obj;
    for(string s:str){
        obj.insert(s);
    }
    string ans="";
    cout<<obj.findLongestCommonPrefix(obj.root,ans);

}