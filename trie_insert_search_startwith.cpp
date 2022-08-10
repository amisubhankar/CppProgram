//graph 5)
#include<iostream>
using namespace std;

class Node{
    public:
        Node *link[26];
        bool end=false;
    public:
        bool isExist(char ch){
            return (link[ch-'a']!=NULL);
        }
        void put(char ch,Node *next){
            link[ch-'a']=next;
        }
        Node* getNext(char ch){
            return link[ch-'a'];
        }
};

class Trie{
   public: Node *root;

    public:
        Trie(){
            root=new Node();
        }
        void insert(string word){
            Node *node=root;
            for(int i=0;i<word.length();i++){
                if(!node->isExist(word[i])){
                    node->put(word[i],new Node());
                }
                node=node->getNext(word[i]);
            }
            node->end=true;
        }
        bool search(string word){
            Node *node=root;
            for(int i=0;i<word.length();i++){
                if(!node->isExist(word[i])){
                    return false;
                }
                node=node->getNext(word[i]);
            }
            return node->end;
        }
        void startWith(string str){
            Node *node=root;
            string ans="";
            for(int i=0;i<str.length();i++){
                if(!node->isExist(str[i])){
                    cout<<"NO words";
                    return;
                }
                ans+=str[i];
                node=node->getNext(str[i]);
            }
            if(node->end){
                cout<<ans;
            }
            else{
                findNextWord(node,ans);
            }
        }
        void findNextWord(Node *node,string ans){
            if(node->end){
                cout<<ans<<endl;
                return;
            }
            for(int i=0;i<26;i++){
                if(node->link[i]!=NULL){
                    char ch='a'+i;
                    findNextWord(node->link[i],ans+ch);
                }
            }
        }
        void display(Node *node){
            if(node->end){
                cout<<endl;
                return;
            }
            for(int i=0;i<26;i++){
                if(node->link[i]!=NULL){
                    char ch='a'+i;
                    cout<<ch;
                    display(node->link[i]);
                }
            }
        }
        
};
int main(){
    Trie obj;
    obj.insert("apple");
    obj.insert("apps");
    obj.insert("ban");
    obj.insert("bat");
    // obj.display(obj.root);
    //cout<<obj.search("appl");
    obj.startWith("ap");
}