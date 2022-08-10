#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next,*down;
public:
    Node(){};
    Node(int item){
        data=item;
        next=NULL;
        down=NULL;
    }
    void insertNext(Node *&head,Node *&tail,int item){
        if(head==NULL){
            head=tail=new Node(item);
        }
        else{
            tail->next=new Node(item);
            tail=tail->next;
        }
    }
    Node* insertDown(int arr[],int n){
        Node *head=NULL,*tail=NULL;
        for(int i=0;i<n;i++){
            if(head==NULL) 
                head=tail=new Node(arr[i]);
            else{
                tail->down=new Node(arr[i]);
                tail=tail->down;
            }
        }
        return head;
    }
    void display(Node *head){
        while(head!=NULL){
            cout<<head->data<<"->";
            Node *temp=head->down;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->down;
            }
            cout<<endl;
            head=head->next;
        }
    }
    Node* merge(Node *head1,Node* head2){
        Node *prev,*ptr;
        ptr=prev=head1;

        while(ptr!=NULL && head2!=NULL){
            if(ptr->data<head2->data){
                prev=ptr;
                ptr=ptr->down;
            }
            else{
                Node *temp=head2;
                head2=head2->down;
                if(head1==ptr){
                    temp->down=head1;
                    head1=temp;
                    prev=head1;
                }
                else{
                    temp->down=prev->down;
                    prev->down=temp;
                    prev=temp;
                }
            }
        }
        if(ptr==NULL){
            prev->down=head2;
        }

        head1->next=NULL;
        return head1;
    }
    
    Node* flatten(Node *head){
        if(head->next==NULL)
            return head;
        Node *temp=flatten(head->next);
        Node *newHead=merge(head,temp);
        return newHead;
    }
};

int main(){
    Node obj;
    Node *head=NULL,*tail=NULL;
    int arr[]={4,11,18,28};
    for(int item:arr){
        obj.insertNext(head,tail,item);
    }
    int arr1[]={6,7,30};
    int arr2[]={20};
    int arr3[]={22,50};
    int arr4[]={35,40,45};

    Node *ptr=head;

    ptr->down=obj.insertDown(arr1,sizeof(arr1)/sizeof(int));
    ptr=ptr->next;

    ptr->down=obj.insertDown(arr2,sizeof(arr2)/sizeof(int));
    ptr=ptr->next;

    ptr->down=obj.insertDown(arr3,sizeof(arr3)/sizeof(int));
    ptr=ptr->next;

    ptr->down=obj.insertDown(arr4,sizeof(arr4)/sizeof(int));
    ptr=ptr->next;

    obj.display(obj.flatten(head));
}