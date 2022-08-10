//hashing 8)
#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
        char ch;
        Node *next,*prev;
    public:
        Node(char ch,Node *next,Node *prev){
            this->ch=ch;
            this->next=next;
            this->prev=prev;
        }
};

Node* ascii_char[26]={NULL};

void add(char ch,Node *&head,Node *&tail){
    //1st time occurence
    if(ascii_char[ch-96]==NULL){
        Node *node=new Node(ch,NULL,tail);
        ascii_char[ch-96]=node;
        if(head==NULL)
            head=tail=node;
        else{
            tail->next=node;
            tail=node;
        }
    }
    //already occured so delete that node
    else{
        Node *ptr=ascii_char[ch-96];
        ascii_char[ch-96]=NULL;
        if(ptr==head && ptr==tail)
            head=tail=NULL;
        else if(ptr==head){
            head=head->next;
            head->prev=NULL;
        }
        else if(ptr==tail){
            tail=tail->prev;
            tail->next=NULL;
        }
        else{
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
        }

    }
}

int main(){
    char arr[]={'a','c','d','a','c'};
    Node *head=NULL,*tail;
    for(char ch: arr){
        add(ch,head,tail);
        cout<<ch<<"-- 1st Non-repeating number : "<<head->ch<<endl;
    }
}