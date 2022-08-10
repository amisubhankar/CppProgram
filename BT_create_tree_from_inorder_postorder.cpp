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
    int findIndex(int inorder[],int data,int strt,int end){
        for(int i=strt;i<=end;i++)
        {
            if(inorder[i]==data)
                return i;
        }
    }
    Node *createTree(int inorder[],int postorder[],int strt,int end,int &current){
        if(strt>end)    return NULL;

        current--;
        Node *node=new Node(postorder[current]);

        if(strt==end)   return node;

        int index=findIndex(inorder,node->data,strt,end);
        //as postorder is LRN and postorder[] traverse from R --> L
        //so first may be came Right node then left
        node->right=createTree(inorder,postorder,index+1,end,current);
        node->left=createTree(inorder,postorder,strt,index-1,current);

        return node;
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
    int inorder[]={4,8,2,5,1,6,3,7};
    int postorder[]={8,4,5,2,6,7,3,1};
    int n=sizeof(inorder)/sizeof(int);
    int current=n;

    Node *root=obj.createTree(inorder,postorder,0,n-1,current);

    obj.inorderR(root);

}