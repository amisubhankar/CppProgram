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
    Node* findMid(Node *head){
        Node *fast,*mid,*prev;
        fast=mid=prev=head;
        while(! (fast==NULL || fast->next==NULL) ){
            prev=mid;
            mid=mid->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        return mid;
    }
    Node* merge(Node *head1,Node* head2){
        Node *prev,*ptr;
        ptr=prev=head1;

        while(ptr!=NULL && head2!=NULL){
            if(ptr->data<head2->data){
                prev=ptr;
                ptr=ptr->next;
            }
            else{
                Node *temp=head2;
                head2=head2->next;
                if(head1==ptr){
                    temp->next=head1;
                    head1=temp;
                    prev=head1;
                }
                else{
                    temp->next=prev->next;
                    prev->next=temp;
                    prev=temp;
                }
            }
        }
        if(ptr==NULL){
            prev->next=head2;
        }

        return head1;
    }
    Node* mergeSort(Node *head){
        if(head->next==NULL){
            return head;
        }
        Node *mid=findMid(head);
        head=mergeSort(head);
        mid=mergeSort(mid);
        return merge(head,mid);
    }
};
int main(){
    Node obj;
    int arr[]={4,2,8,5,1,6};
    Node *head=NULL,*tail;
    for(int item:arr ){
        obj.insert(head,tail,item);
    }

    obj.display(obj.mergeSort(head));

}