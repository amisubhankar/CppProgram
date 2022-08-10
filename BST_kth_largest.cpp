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

    Node* insert(Node *root,int item){
        if(root==NULL)
            return new Node(item);
        else if(item<root->data)
            root->left=insert(root->left,item);
        else    
            root->right=insert(root->right,item);
        return root;
    }

    //do a reverse of inorder traversal
    int kthLargest(Node *root,int k){
        int count=0;
        if(root!=NULL){
            count+=kthLargest(root->right,k);
            count++;
            if(count==k)
                cout<<root->data<<" ";
            count+=kthLargest(root->left,k-count);
        }
        return count;
    }
};

int main(){
    Node *root,obj;
    root=NULL;
    int keys[] = { 13, 14, 22, 25, 23, 32, 26,28,40 };
    int n=sizeof(keys)/sizeof(int);

    for (int x : keys)
        root = obj.insert(root, x);
    
    obj.kthLargest(root,4);
   
}