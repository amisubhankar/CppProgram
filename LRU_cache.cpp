//hashing 7)
#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
        int key,value;
        Node *next,*prev;
    public:
        Node(int key,int value,Node *next,Node *prev){
            this->key=key;
            this->value=value;
            this->next=next;
            this->prev=prev;
        }
};

int size=0;
map<int,Node*> mp;
Node *front=NULL,*rear=NULL;

void put(int key,int val){
    if(size<3){
        size++;
        Node *node=new Node(key,val,NULL,rear);
        mp[key]=node;
        if(front==NULL)
            front=rear=node;
        else{
            rear->next=node;
            rear=node;
        }
    }
    else{
        //remove 1st element
        mp.erase(front->key);
        //move front to next
        front=front->next;
        front->prev=NULL;
        //create new node
        Node *node=new Node(key,val,NULL,rear);
        //insert into map and DLL
        mp[key]=node;
        rear->next=node;
        rear=node;
    }
}

int get(int key){
    if(mp.find(key)!=mp.end()){
        Node *ptr=mp[key];
        //may be there is single element
        if(ptr==front && ptr==rear){
            return mp[key]->value;
        }
        //may be get() called for last element
        else if(ptr==rear){
            return mp[key]->value;
        }
        //if get() for first element 
        else if(ptr==front){
            front=front->next;
            front->prev=NULL;
            rear->next=ptr;
            ptr->prev=rear;
            ptr->next=NULL;
            rear=ptr;
        }
        else{
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            rear->next=ptr;
            ptr->prev=rear;
            ptr->next=NULL;
            rear=ptr;
        }

        return mp[key]->value;

    }
    else
        return -1;
}

int main(){
    int ch;
    do{
        cout<<endl<<"1.Put\n2.Get\n3.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                int key,val;
                cout<<"Key: "<<endl;
                cin>>key;
                cout<<"Value: "<<endl;
                cin>>val;
                put(key,val);
                break;
            case 2:
                int k;
                cout<<"Key: "<<endl;
                cin>>k;
                cout<<get(k);
                break;
            case 3:
                exit(1);
        }
    }while(true);
}