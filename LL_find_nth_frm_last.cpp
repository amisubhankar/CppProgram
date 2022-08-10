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
    void finNthFromLast(Node *head,int &n,int &item){
        if(head==NULL){
            return;
        }
        finNthFromLast(head->next,n,item);
        (n==1 && item==0)?item=head->data:n--;
    }       
};
int main(){
    Node obj;
    int arr[]={1,2,3,4,5,6};
    Node *head=NULL,*tail;
    for(int item:arr ){
        obj.insert(head,tail,item);
    }
    
    int n=5;
    int item=0;
    obj.finNthFromLast(head,n,item);
    cout<<item;
}