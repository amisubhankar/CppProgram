#include<iostream>
#include<vector>
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

    void printKDistFromLeaf(Node *root,vector<int> v,bool *isTraversed,int k){
        if(root==NULL)  return;

        v.push_back(root->data);
        if(root->left==NULL && root->right==NULL){
            //if not already printed
            if(!isTraversed[v[v.size()-k-1]]){
                cout<<v[v.size()-k-1]<<" , ";
                isTraversed[v[v.size()-k-1]]=true;
                
            }
            return;
        }

        printKDistFromLeaf(root->left,v,isTraversed,k);
        printKDistFromLeaf(root->right,v,isTraversed,k);
    }
};
int main(){
    Node obj;
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->left->left=new Node(8);
    root->right->right=new Node(7);
    root->right->left=new Node(6);

    bool isTraversed[20]={false};
    vector<int> v;
    obj.printKDistFromLeaf(root,v,isTraversed,3);
}