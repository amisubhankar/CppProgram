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

    void reverseLevelOrder(Node *root){
        Node *queue[10];
        Node *stack[10];
        int f=0,r=0,top=-1;
        queue[0]=root;
        while(f<=r){
            Node *curr=queue[f++];
            //pop from queue and put it uo stack
            stack[++top]=curr;
            //as reverse order so 1st right then left
            if(curr->right!=NULL){
                if(f>r){
                    r=-1;
                    f=0;
                }
                queue[++r]=curr->right;
            }
            if(curr->left!=NULL){
                if(f>r){
                    r=-1;
                    f=0;
                }
                queue[++r]=curr->left;
            }
        }

        while(top!=-1){
            cout<<stack[top]->data<<" ";
            top--;
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

    obj.reverseLevelOrder(root);
}