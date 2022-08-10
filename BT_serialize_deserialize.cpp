#include<iostream>
#include<vector>
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
    
    void serialize(Node *root,vector<int> &v){
        if(root==NULL){
            v.push_back(-1);
            return;
        }
        v.push_back(root->data);
        serialize(root->left,v);
        serialize(root->right,v);        
    }

    Node* deSerialize(vector<int> v,int &index){
        index++;
        if(v[index]==-1)
            return NULL;
        
        Node *node=new Node(v[index]);
        node->left=deSerialize(v,index);
        node->right=deSerialize(v,index);

        return node;
    }

    void preorder(Node *root){
        if(root!=NULL){
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
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
    root->left->right->left=new Node(8);
    root->right->right=new Node(7);
    root->right->left=new Node(6);
    
    cout<<endl;
    vector<int> v;
    obj.serialize(root,v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";

    cout<<endl;
    int index=-1;
    Node *newRoot=obj.deSerialize(v,index);
    obj.preorder(newRoot);

}