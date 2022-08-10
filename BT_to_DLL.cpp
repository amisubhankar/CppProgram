/*after converting BT to DLL, DLL should contain node as per 
  inorder traversal of BT */
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

    Node* createBST(Node *root,int item){
        if(root==NULL)
            return new Node(item);
        else if(item<root->data)
            root->left=createBST(root->left,item);
        else
            root->right=createBST(root->right,item);
        return root;
    }

    void createDLL(Node *curr,Node *&head,Node *&prev){
        if(curr==NULL)  return;

        createDLL(curr->left,head,prev);
        if(prev==NULL){
            head=curr;
        }
        else{
            prev->right=curr;
            curr->left=prev;
        }
        prev=curr;
        
        createDLL(curr->right,head,prev);
    }

    void display(Node *head){
        if(head==NULL)  return;
        cout<<head->data<<" ";
        display(head->right);
    }

};

int main(){
    Node obj;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node *head,*prev=NULL;
    obj.createDLL(root,head,prev);
    obj.display(head);
}