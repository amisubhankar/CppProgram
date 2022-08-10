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

    void spiralPrinting(Node *root){
        stack<Node*> s1;
        stack<Node*> s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty() ){
            while(!s1.empty()){
                Node *curr=s1.top();
                s1.pop();
                cout<<curr->data<<" ";
                if(curr->right!=NULL)
                    s2.push(curr->right);
                if(curr->left!=NULL)
                    s2.push(curr->left);
            }
            while (!s2.empty())
            {
                Node *curr=s2.top();
                s2.pop();
                cout<<curr->data<<" ";
                if(curr->left!=NULL)
                    s1.push(curr->left);
                if(curr->right!=NULL)
                    s1.push(curr->right);
            }
            
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

    obj.spiralPrinting(root);
}