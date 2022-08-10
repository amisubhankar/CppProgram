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
    int findSize(Node *head){
        int count=0;
        while(head!=NULL){
            head=head->next;
            count++;
        }
        return count;
    }
    Node* reverseKGroup(Node *head,int size,int k){
        Node *oh,*ot,*th,*tt;
        oh=ot=th=tt=NULL;
        Node *c,*f;
        c=head;f=head->next;
        int x=k;

        while(size>=x){
            while(k>0){
                if(th==NULL){
                    th=tt=c;
                    c->next=NULL;
                }
                else{
                    c->next=th;
                    th=c;
                }
                c=f;
                if(f!=NULL)
                    f=c->next;
                k--;
            }
            //connect with orginal head
            if(oh==NULL){
                oh=th;
                ot=tt;
            }
            else{
                ot->next=th;
                ot=tt;
            }
            th=tt=NULL;
            size-=x;
            k=x;
        }

        if(size!=0){
            ot->next=c;
        }

        return oh;
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
    int arr[]={1,2,3,4,5,6,7};
    Node *head=NULL,*tail;
    for(int item:arr ){
        obj.insert(head,tail,item);
    }

    head=obj.reverseKGroup(head,obj.findSize(head),2);
    obj.display(head);
};