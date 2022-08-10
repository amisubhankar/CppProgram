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
    Node* segregate(Node *head){
        Node *evenHead,*oddHead,*even,*odd;
        evenHead=oddHead=NULL;
        while(head!=NULL){
            if(head->data%2==0){
                if(evenHead==NULL)
                    evenHead=even=head;
                else{
                    even->next=head;
                    even=head;
                }
            }
            else{
                if(oddHead==NULL)
                    oddHead=odd=head;
                else{
                    odd->next=head;
                    odd=head;
                }
            }
            head=head->next;
        }
        even->next=oddHead;
        return evenHead;
    }
};
int main(){
    Node obj;
    int arr[]={2,3,5,4,6,8,1};
    Node *head=NULL,*tail;
    for(int item:arr ){
        obj.insert(head,tail,item);
    }
    obj.display(obj.segregate(head));
}