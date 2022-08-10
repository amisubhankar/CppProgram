#include<iostream>
#include<stack>
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
    void preorder(Node *root){
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            Node *curr=stk.top();
            stk.pop();
            cout<<curr->data<<" ";
            if(curr->right!=NULL)
                stk.push(curr->right);
            if(curr->left!=NULL)
                stk.push(curr->left);
        }
    }
};

int main(){
    Node obj;
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    obj.preorder(root);
}