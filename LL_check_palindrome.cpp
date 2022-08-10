#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
public:
    Node(){};
    Node(int item){
        data=item;
        next=NULL;
    }
    void insert(Node *&head,Node *&tail,int item){
        if(head==NULL){
            head=tail=new Node(item);
        }
        else{
            tail->next=new Node(item);
            tail=tail->next;
        }
    }
    void display(Node *head){
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
    }
    Node* findMid(Node *head,bool &isOdd){
        Node *prev,*fast,*mid;
        fast=mid=head;
        while( fast!=NULL && fast->next!=NULL ){
            prev=mid;
            fast=fast->next->next;
            mid=mid->next;
        }
        //check list even or odd
        if(fast!=NULL)
            isOdd=true;
        prev->next=NULL;
        return mid;
    }
    bool compare(Node *head1,Node *head2){
        while(head1!=NULL && head2!=NULL){
            if(head1->data!=head2->data)    
                return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    Node* reverse(Node *head){
        Node *res=NULL;
        while(head!=NULL){
            Node *temp=head;
            head=head->next;
            temp->next=res;
            res=temp;
        }
        return res;
    }
};
int main(){
    Node obj;
    int arr[]={1,2,3,2,1};
    Node *head=NULL,*tail;
    for(int item:arr ){
        obj.insert(head,tail,item);
    }

    bool isOdd=false;
    Node *mid=obj.findMid(head,isOdd);
    if(isOdd)
        mid=mid->next;
    
    mid=obj.reverse(mid);

    if(obj.compare(head,mid))
        cout<<"Palindrome";
    else
        cout<<"Not Palindrome";
}