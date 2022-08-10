#include<iostream>
#include<map>
using namespace std;
class DLL{
    public:
    int data;
    DLL *prev,*next;

    public:
    DLL(){
        data=0;
        prev=next=NULL;
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

    void verticalSumUsingMap(Node *root,map<int,int> &mp,int d){
        if(root==NULL)  return;
        verticalSumUsingMap(root->left,mp,d-1);
        mp[d]=mp[d]+root->data;
        verticalSumUsingMap(root->right,mp,d+1);
    }

    void verticalSumUsingDLL(Node *root,DLL *&head){
        //if(root==NULL)  return;
        head->data=head->data+root->data;
        if(root->left!=NULL){
            if(head->prev==NULL){
                head->prev=new DLL();
                head->prev->next=head;
            }
            verticalSumUsingDLL(root->left,head->prev);
        }
        if(root->right!=NULL){
            if(head->next==NULL){
                head->next=new DLL();
                head->next->prev=head;
            }
            verticalSumUsingDLL(root->right,head->next);    
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
    root->left->right->left=new Node(6);
    root->right->right=new Node(7);
    root->right->right->left=new Node(8);

    //using map
    // map<int,int> mp;
    // obj.verticalSumUsingMap(root,mp,0);
    // for(auto itr=mp.begin();itr!=mp.end();itr++){
    //     cout<<itr->first<<" = "<<itr->second<<endl;
    // }

    //using DLL
    DLL *head=new DLL();
    obj.verticalSumUsingDLL(root,head);
    
    while(head->prev!=NULL)
        head=head->prev;
    
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}