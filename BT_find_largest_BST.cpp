#include<iostream>
using namespace std;

class List{
    public:
        int size;
        int min;
        int max;
        bool isBST;
    public:
        List(int size,int min,int max,bool isBST){
            this->size=size;
            this->min=min;
            this->max=max;
            this->isBST=isBST;
        }

};
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

    List* findLargestBST(Node *root){
        if(root==NULL)
            return new List(0,INT8_MAX,INT8_MIN,true);
        if(root->left==NULL && root->right==NULL)
            return new List(1,root->data,root->data,true);

        List *left=findLargestBST(root->left);
        List *right=findLargestBST(root->right);

        List *res=new List(0,0,0,false);
        res->size=max(left->size,right->size);

        if( left->isBST && right->isBST && left->max<root->data && right->min>root->data){
            res->min=min(root->data,left->min);
            res->max=max(root->data,right->max);
            res->isBST=true;
            res->size=left->size+right->size+1;
        }

        return res; 
    }
};

int main(){
    List *ans;
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

    ans=obj.findLargestBST(root);

    cout<<"Max node in Largest BST = "<<ans->size;
}