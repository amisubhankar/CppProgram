//Graph 9)
#include<iostream>
#include<vector>
using namespace std;

int row[8]={-1,-1,-1,0,1,1,1,0};
int col[8]={-1,0,1,1,1,0,-1,-1};

class Node{
    public:
    Node* link[26];
    bool end=false;
    public:
    bool isPresent(char ch){
        if(link[ch-'a']!=NULL)  return true;
        else    return false;
    }
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
            if(!node->isPresent(word[i])){
                node->link[word[i]-'a']=new Node();
            }
            node=node->link[word[i]-'a'];
        }
        node->end=true;
    }
};

bool isPresentInMatrix(char mat[3][3],char ch,int &r,int &c){
    for(r=0;r<3;r++){
        for(c=0;c<3;c++){
            if(mat[r][c]==ch)   return true;
        }
    }
    return false;
}

bool isSafe(int r,int c,bool visited[3][3]){
    if(r<0 || c<0 || r>2 || c>2 || visited[r][c]==true){
        return false;
    }
    return true;
}

void foundRest(char mat[3][3],string ans,Node *node,bool visited[3][3],int r,int c){
    if(node->end==true){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<26;i++){
        if(node->link[i]!=NULL){
            char ch='a'+i;
            //checking 8 corner
            int k;
            for(k=0;k<8;k++){
                if(isSafe(r+row[k],c+col[k],visited) && mat[r+row[k]][c+col[k]]==ch){
                    visited[r+row[k]][c+col[k]]=true;
                    foundRest(mat,ans+ch,node->link[i],visited,r+row[k],c+col[k]);
                    visited[r+row[k]][c+col[k]]=false;
                    break;
                }
            }
        }
    }
}

void found(char mat[3][3],Trie obj){
    Node *node=obj.root;
    bool visited[3][3]={false};
    for(int i=0;i<26;i++){
        char ch='a'+i;
        string ans="";
        int r,c;
        if(node->link[i]!=NULL && isPresentInMatrix(mat,ch,r,c)){
            visited[r][c]=true;
            foundRest(mat,ans+ch,node->link[i],visited,r,c);
            visited[r][c]=false;
        }
    }
}

int main(){
    vector<string> str={"abc","abg","fgk"};
    Trie obj;
    for(string s:str)   
    {
        obj.insert(s);
    }

    char mat[3][3]={
                    {'f','a','k'},
                    {'b','g','d'},
                    {'e','c','n'}
    };

    found(mat,obj);
}