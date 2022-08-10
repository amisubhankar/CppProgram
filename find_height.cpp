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
        left=right=NULL;
    }

    int height(Node *root){
        if(root==NULL)
            return -1;
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);

        return 1+max(leftHeight,rightHeight);
    }
};

int main(){
    Node obj;
    Node *root;
    root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);

    cout<<"height: "<<obj.height(root->left);
}