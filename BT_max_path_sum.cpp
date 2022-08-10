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
    int maxPathSum(Node *root,int &maxSum){
        if(root==NULL)
            return 0;
        
        int L=maxPathSum(root->left,maxSum);
        int R=maxPathSum(root->right,maxSum);

        int path=max(L,R);
        maxSum=max(maxSum,L+R+root->data);//taking 3
        maxSum=max(maxSum,path+root->data);//taking L || R (whichever max)
        maxSum=max(maxSum,max(path,root->data));//taking only root

        if(root->data > (path+root->data)) return root->data;
        else    return root->data+path;

        //return root->data>(path+root->data)?root->data:root->data+path;
    }
};

int main(){
    Node obj;
    Node *root=new Node(10);
    root->left=new Node(2);
    root->right=new Node(15);
    root->left->left=new Node(-4);
    root->left->right=new Node(-6);
    root->left->left->left=new Node(28);
    root->left->left->right=new Node(-22);
    root->right->right=new Node(-25);
    root->right->right->left=new Node(3);
    root->right->right->right=new Node(4);    

    int maxSum=INT8_MIN;
    obj.maxPathSum(root,maxSum);
    cout<<"Max Sum = "<<maxSum;
}
/*
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(-1);
    root->left->right = new Node(-4);
    root->right->left = new Node(-5);
    root->right->right = new Node(-6);
    root->left->right->left = new Node(4);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(4);
    root->right->left->left->right = new Node(-2);

    o/p = 15;
*/
/*
    Node *root=new Node(10);
    root->left=new Node(-2);
    root->right=new Node(15);
    root->left->left=new Node(67);
    root->left->right=new Node(89);
    root->right->right=new Node(-25);

    o/p = 154;
*/