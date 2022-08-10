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
};
int main(){
    Node obj;
    int arr2[]={2,4,6};
    int arr1[]={1,3,7};
    Node *head1=NULL,*head2=NULL,*tail;
    for(int item:arr1 ){
        obj.insert(head1,tail,item);
    }
    for(int item:arr2 ){
        obj.insert(head2,tail,item);
    }

    obj.display(head1);
    cout<<endl;
    obj.display(head2);
    cout<<endl;

    obj.display(obj.merge(head1,head2));
}