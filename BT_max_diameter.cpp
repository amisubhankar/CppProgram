//diameter-> dist between 2 leaf node
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
    int maxDiameter(Node *root,int &maxDist){
        if(root==NULL) return 0;
        int L=maxDiameter(root->left,maxDist);
        int R=maxDiameter(root->right,maxDist);
        if(L+R+1>maxDist)
            maxDist=L+R+1;
        if(L>R) return L+1;
        else    return R+1;
    }
};

int main(){
    Node obj;
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(12);
    root->right->right=new Node(13);
    root->left->left=new Node(3);
    root->left->right=new Node(8);
    root->left->left->left=new Node(4);
    root->left->left->right=new Node(5);
    root->left->right->left=new Node(9);
    root->left->left->right->left=new Node(6);
    root->left->left->right->left->right=new Node(7);
    //root->left->right->left->right=new Node(10);
    //root->left->right->left->right->left=new Node(11);

    int maxDist=0;
    obj.maxDiameter(root,maxDist);
    cout<<maxDist;
}