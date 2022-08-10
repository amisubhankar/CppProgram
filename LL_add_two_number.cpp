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
    Node* moveHead(Node *head,int diff){
        Node *temp=head;
        while(diff>0){
            diff--;
            temp=temp->next;
        }
        return temp;
    }
    int addOne(Node *head1,Node *temp,Node *&head3,int carry){
        if(head1==temp) return carry;
        int c=addOne(head1->next,temp,head3,carry);
        int sum=head1->data+c;
        Node *node=new Node(sum%10);
        node->next=head3;
        head3=node;
        return (sum/10);
    }
    int add(Node *head1,Node *head2,Node *&head3){
        if(head1==NULL && head2==NULL)
            return 0;
        
        int carry=add(head1->next,head2->next,head3);
        int sum=head1->data+head2->data+carry;
        Node *node=new Node(sum%10);
        if(head3!=NULL)
            node->next=head3;
        head3=node;

        return (sum/10);
    }
};
int main(){
    Node obj;
    int arr1[]={6,7,4};
    int arr2[]={1,9,9,5,3};
    int n1=sizeof(arr1)/sizeof(int);
    int n2=sizeof(arr2)/sizeof(int);
    Node *head1,*head2,*tail;
    head1=head2=NULL;

    for(int item:arr1)
        obj.insert(head1,tail,item);
    for(int item:arr2)
        obj.insert(head2,tail,item);

    //As i want head1 = greater size List
    if(n2>n1){
        Node * temp=head1;
        head1=head2;
        head2=temp;
    }
    
    //move the head1 pointer to make it same size as other LL
    int diff=abs(n1-n2);
    Node *temp=obj.moveHead(head1,diff);

    Node *head3=NULL;
    int carry=obj.add(temp,head2,head3);
    //calculating left extra part of head1
    carry=obj.addOne(head1,temp,head3,carry);
    if(carry==1){
        Node *node=new Node(1);
        node->next=head3;
        head3=node;
    }

    obj.display(head3);
}