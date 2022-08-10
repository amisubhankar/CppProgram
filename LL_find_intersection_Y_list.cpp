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
    Node* insert(Node *&head,Node *&tail,int item,int connect){
        if(head==NULL){
            head=tail=new Node(item);
        }
        else{
            tail->next=new Node(item);
            tail=tail->next;
        }
        if(item==connect){
            return tail;
        }
        return NULL;
    }
    void display(Node *head){
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
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
    int intersection(Node *head1,Node *head2){
        int n1=findSize(head1);
        int n2=findSize(head2);
        int diff=abs(n2-n1);
        //more sized LL pointed by head1
        if(n2>n1){
            Node *temp=head2;
            head2=head1;
            head1=temp;
        }
        //move head1 frwd
        while(diff>0){
            head1=head1->next;
            diff--;
        }
        while(head1!=NULL && head2!=NULL){
            if(head1==head2)
                return head1->data;
            head1=head1->next;
            head2=head2->next;
        }
        return 0;
    }

};

int main(){
    Node obj;
    int arr1[]={1,2,3,4,5};
    Node *head1=NULL,*tail,*connect;
    for(int item:arr1 ){
        if(obj.insert(head1,tail,item,3)!=NULL)
            connect=tail;
    }

    int arr2[]={3,8,9,10};
    Node *head2=NULL;
    for(int item:arr2){
        obj.insert(head2,tail,item,-1);    
    }
    tail->next=connect;
    
    cout<<"Intersection Node: "<<obj.intersection(head1,head2);
}