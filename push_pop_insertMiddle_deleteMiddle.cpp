#include<iostream>
using namespace std;

class DLL{
public:
    int data;
    DLL *left,*right;
public:
    DLL(){
        data=0;
        left=right=NULL;
    }

    DLL* getnode(int data){
        DLL *ptr;
        ptr=new DLL();
        ptr->data=data;
        ptr->right=NULL;
        ptr->left=NULL;
        return ptr;
    }

    void push(DLL &head,int item){
        DLL *ptr;
        ptr=getnode(item);
        if(head.right==NULL){
            head.right=ptr;
        }
        else{
            ptr->right=head.right;
            head.right->left=ptr;
            head.right=ptr;
        }
    }

    void pop(DLL &head){
        DLL *ptr;
        if(head.right==NULL){
            cout<<"NO element";
        }
        else if(head.right->right==NULL){
            cout<<"HI";
            cout<<"Deleted element: "<<head.right->data;
            ptr=head.right;
            head.right=NULL;
        }
        else{
            cout<<"Deleted element: "<<head.right->data;
            ptr=head.right;
            head.right=head.right->right;
            head.right->left=NULL;
        }
        free(ptr);

    }

    void findMiddle(DLL &head,DLL *mid){
        if(head.right==NULL)
            cout<<"NO element";
        else{
            cout<<"Middle element is: "<<mid->data;
        }
    }

    DLL* deleteMiddle(DLL &head,DLL *mid,int size){
        DLL *ptr;
        if(head.right==NULL)
            cout<<"NO element";
        else if(head.right->right==NULL){
            cout<<"Deleted element: "<<head.right->data;
            ptr=head.right;
            head.right=NULL;
            mid=NULL;
        }
        else if(head.right==mid){
            cout<<"Deleted element: "<<head.right->data;
            ptr=mid;
            head.right=mid->right;
            head.right->left=NULL;
            mid=head.right;
        }
        else{
            cout<<"Deleted element: "<<mid->data;
            size--;
            DLL *prev=mid->left;
            DLL *next=mid->right;
            prev->right=mid->right;
            next->left=mid->left;
            ptr=mid;
            if(size%2==0)
                mid=prev;
            else    
                mid=next;

        }
        free(ptr);
        return mid;
    }

};

int main(){
    DLL head;
    DLL obj;
    DLL *mid;
    int size=0;

    for(;;){
        int choice;
        cout<<"\n\n1.Push\n2.Pop\n3.Find Middle\n4.Delete Middle\n5.exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                int data;
                cout<<"Enter data: ";
                cin>>data;
                size++;
                obj.push(head,data);
                if(size==1)
                    mid=head.right;
                else if(size%2==0)
                    mid=mid->left;
                break;
            case 2:
                obj.pop(head);
                size--;
                if(size<=0){
                    mid=NULL;
                    size=0;
                }
                else if(size%2==1)
                    mid=mid->right;
                break;
            case 3:
                obj.findMiddle(head,mid);
                break;
            case 4:
                mid=obj.deleteMiddle(head,mid,size);
                if(size>0)
                    size--;
                break;
            case 5:
                exit(0);
        }
    }
}