#include<iostream>
using namespace std;

class Node{
    int data;
    Node *left,*right;

    public:
    Node(){}
    Node(int item){
        data=item;
        right=left=NULL;
    }

    Node* createBst(Node *root,int item){
        if(root==NULL)
            return new Node(item);
        else if(item<root->data)
            root->left=createBst(root->left,item);
        else
            root->right=createBst(root->right,item);
        return root;
    }

    void inorder(Node *root){
        if(root!=NULL){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }

    Node* inorderSuccessor(Node *root){
        while(root->left!=NULL)
            root=root->left;
        return root;
    }

    Node* deleteBST(Node *root,int item){
        if(root==NULL)
            return root;//returning null
        //find at left tree
        else if(item<root->data){
            root->left=deleteBST(root->left,item);
        }
        //find at right tree
        else if(item>root->data){
            root->right=deleteBST(root->right,item);
        }
        //find match
        else{
            //for leaf node 
            if(root->left==NULL && root->right==NULL){
                Node *temp=root;
                free(temp);
                return NULL;
            }
            //having only right child
            else if(root->left==NULL){
                Node *temp=root;
                root=root->right;
                free(temp);
                return root;
            }
            //having only left child
            else if(root->right==NULL){
                Node *temp=root;
                root=root->left;
                free(temp);
                return root;
            }
            //having 2 child
            else{
                Node *successor=inorderSuccessor(root->right);
                root->data=successor->data;
                root->right=deleteBST(root->right,successor->data);
            }
            return root;
        }
    }
};

int main(){
    Node obj;
    Node *root=NULL;
    int arr[]={6,4,5,10,8,12,11,15};
    int n=sizeof(arr)/sizeof(int);
    for(int x:arr){
        root=obj.createBst(root,x);
    }
    obj.inorder(root);
    cout<<endl;

    root=obj.deleteBST(root,6);
    obj.inorder(root);
}