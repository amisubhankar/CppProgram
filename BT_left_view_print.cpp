#include<iostream>
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

    void printLeftView(Node *root,int level,int &traversed_level){
        if(root==NULL)
            return;
        if(traversed_level<level){
            cout<<root->data<<" ";
            traversed_level=level;
        }
        printLeftView(root->left,level+1,traversed_level);
        printLeftView(root->right,level+1,traversed_level);
    } 
};

int main(){
    Node obj;
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(6);
    root->right->left=new Node(5);
    root->right->right=new Node(4);
    root->right->left->left=new Node(7);
    root->right->right->left=new Node(8);

    int traversed_level=0;
    obj.printLeftView(root,1,traversed_level);
}