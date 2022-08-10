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

    void printLeftInternal(Node *root){
        if(root!=NULL){
            if(root->left!=NULL){
                cout<<root->data<<" ";
                printLeftInternal(root->left);
            }
            else if(root->right!=NULL){
                cout<<root->data<<" ";
                printLeftInternal(root->right);
            }
        }
    }

    void printLeaf(Node *root){
        if(root!=NULL){
            printLeaf(root->left);
            if(root->left==NULL && root->right==NULL)
                cout<<root->data<<" ";
            printLeaf(root->right);
        }
    }

    void printRightInternal(Node *root){
        //as anti clockwise, 1st call func then print
        if(root!=NULL){
            if(root->right!=NULL){
                printRightInternal(root->right);
                cout<<root->data<<" ";
            }
            else if(root->left!=NULL){
                printRightInternal(root->left);
                cout<<root->data<<" ";
            }
        }
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
root->left->left->left = new Node(8);
root->left->left->right = new Node(9);
root->left->right->right = new Node(10);
root->right->right->left = new Node(11);
root->left->left->right->left = new Node(12);
root->left->left->right->right = new Node(13);
root->right->right->left->left = new Node(14);

    cout<<root->data<<" ";
    obj.printLeftInternal(root->left);
    obj.printLeaf(root);
    obj.printRightInternal(root->right);
}