#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;

    public:
    Node(){}
    Node(int item){
        data=item;
        right=left=NULL;
    }

    void bottomView(Node *root,map<int,pair<int,int>> &mp,int d,int level){
        if(root==NULL)  return;

        //always put higher(means lower values) level data
        if(level>=mp[d].second){
            mp[d]= {root->data,level};
        }

        bottomView(root->left,mp,d-1,level+1);
        bottomView(root->right,mp,d+1,level+1);
    }
};
int main(){
    Node obj; 
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);  
    root->left->left->right = new Node(8);  
    root->right->right = new Node(7); 
    root->left->right->right=new Node(9);

    map<int,pair<int,int>> mp;
    obj.bottomView(root,mp,0,0);
    for(auto itr=mp.begin();itr!=mp.end();itr++)
        cout<<itr->second.first<<" ";
}

/*
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);  
    root->left->left->right = new Node(8);  
    root->right->right = new Node(7); 
    root->left->right->right=new Node(9); 

    op:: 4 8 5 9 7

    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);  
    root->left->left->right = new Node(8);  
    root->right->right = new Node(7); 
    root->right->right->left = new Node(6);

    op:: 4 8 5 6 7
*/