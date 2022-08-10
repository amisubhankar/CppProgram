#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next,*random;
public:
    Node(){};
    Node(int item){
        data=item;
        next=NULL;
        random=NULL;
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
    void connectRandom(Node *head,Node *node,int item){
        while(head!=NULL){
            if(head->data==item){
                node->random=head;
                return ;
            }
            head=head->next;
        }
        node->random=NULL;
    }
    void display(Node *head){
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
    }
    Node* clone(Node *head){
        //Stage 1: creating clone node and add after each org node
        Node *ptr=head;
        while(ptr!=NULL){
            Node *node=new Node(ptr->data*10);
            node->next=ptr->next;
            ptr->next=node;
            ptr=node->next;
        }

        //Stage 2: connect random of cloned node
        ptr=head;
        while(ptr!=NULL){
            if(ptr->random!=NULL)
                ptr->next->random=ptr->random->next;
            else
                ptr->next->random=NULL;
            ptr=ptr->next->next;
        }

        //Stage 3: create 2 seperate list orgList & cloneList
        Node *Nhead=NULL,*tail;
        ptr=head;
        while(ptr!=NULL){
            if(Nhead==NULL){
                Nhead=ptr->next;
                tail=Nhead;
            }
            else{
                tail->next=ptr->next;
                tail=ptr->next;
            }
            ptr->next=ptr->next->next;
            ptr=ptr->next;
        }
        return Nhead;
        
    }
};
int main(){
    Node obj;
    int arr[]={1,2,3,4};
    Node *head=NULL,*tail;
    for(int item:arr ){
        obj.insert(head,tail,item);
    }
    //connect to randoms
    Node *ptr=head;
    obj.connectRandom(head,ptr,4);
    ptr=ptr->next;
    obj.connectRandom(head,ptr,1);
    ptr=ptr->next;
    obj.connectRandom(head,ptr,0);
    ptr=ptr->next;
    obj.connectRandom(head,ptr,2);
    Node *Nhead=obj.clone(head);
    obj.display(head);
    cout<<endl;
    obj.display(Nhead);
    cout<<Nhead->next->next->next->random->data;
}