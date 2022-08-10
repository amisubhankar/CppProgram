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
    //take double traversal because of endPrev
    void rearrange(Node *head,Node *tail){
        Node *strt=head;
        Node *end=tail;
        while(! (strt==end || strt->next==end) ){
            Node *endPrev=strt;
            while (endPrev->next!=end)
            {
                endPrev=endPrev->next;
            }
            endPrev->next=NULL;
            end->next=strt->next;
            strt->next=end;
            strt=end->next;
            end=endPrev;
        }
    }
    Node* reverse(Node *head,Node *&Nhead){
        if(head->next==NULL){
            Nhead=head;
            return head;
        }
        Node *curr=reverse(head->next,Nhead);
        curr->next=head;
        head->next=NULL;
        return head;
    }
    Node* findMid(Node *head){
        Node *fast=head,*mid=head;
        while(!(fast==NULL || fast->next==NULL) ){
            mid=mid->next;
            fast=fast->next->next;
        }
        return mid;
    }
    void merge(Node *head,Node *Nhead){
        Node *curr=head;
        while(Nhead!=NULL){
            Node *temp=Nhead->next;
            Nhead->next=curr->next;
            curr->next=Nhead;
            curr=Nhead->next;
            if(curr==NULL){
                Nhead->next=temp;
                break;
            }
            Nhead=temp;
        }
    }
    void display(Node *head){
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
    }
};
int main(){
    Node obj;
    int arr[]={1,2,3,4,5,6};
    Node *head=NULL,*tail;
    for(int item:arr ){
        obj.insert(head,tail,item);
    }
    
    //S1: finding mid
    Node *mid=obj.findMid(head);
    //creating two separate list
    Node *temp=head;
    while(temp->next!=mid)
        temp=temp->next;
    temp->next=NULL;
    //S2: reverse from mid
    Node *Nhead;
    obj.reverse(mid,Nhead);
    //S3: merge(head,Nhead)
    obj.merge(head,Nhead);
    obj.display(head);
}

/*
    Single traversal possible
    1) find mid
    2)reverse from mid
    3)merge(head,mid)
*/