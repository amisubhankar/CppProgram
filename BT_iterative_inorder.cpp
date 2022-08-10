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
    void inorder(Node *root){
        stack<Node*> stk;
        Node *curr=root;

        while(curr!=NULL || stk.size()>0){
            while(curr!=NULL){
                stk.push(curr);
                curr=curr->left;
            }
            curr=stk.top();
            stk.pop();
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    }

    void inorderR(Node *root){
        if(root!=NULL){
            inorderR(root->left);
            cout<<root->data<<" ";
            inorderR(root->right);
        }
    }
};

int main(){
    Node obj;
    Node *root=new Node(50);
    root->left=new Node(30);
    root->right=new Node(60);
    root->left->left=new Node(5);
    root->left->right=new Node(40);
    root->right->left=new Node(55);
    root->right->right=new Node(70);
    root->right->right->right=new Node(80);
    root->right->right->left=new Node(65);

    obj.inorder(root);
    cout<<endl;
    obj.inorderR(root);
}