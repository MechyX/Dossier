#include<iostream>
using namespace std;
class LinkedList;

class Node{
    Node *next;
    int data;
    friend LinkedList;
};

class LinkedList{
    Node * head;
    public:
    LinkedList() : head(NULL) {}
    void insertAtBeg(int data);
    void insertAfterData(int data,int aftData);
    void insertAtEnd(int data);
    void deleteAtEnd();
    void deleteAtBeg();
    void deleteAfterData(int aftData);
    void display();
};


//WORKING
void LinkedList :: insertAtBeg(int data){
    Node *temp = new Node;
    temp->data= data;
   
    if(head==NULL){
            head=temp;
            head->next=NULL;
    }
                
    else{
    temp->next=head;
    head=temp;
    }
  
}

//WORKING
void LinkedList :: insertAtEnd(int data){
    Node *temp = new Node;
    temp->data= data;

    if(head==NULL){
            head=temp;
            temp->next=NULL;
            }

    else{
        Node *t = head;

        while((t->next)!=NULL)
                t=t->next;

        t->next=temp;
        temp->next=NULL;
    }


}

//WORKING
void LinkedList :: insertAfterData(int data,int aftData){
        Node *temp = new Node;
        temp->data= data;
       
           Node *t = head;
        
        while((t->data)!=aftData)
                t=t->next;

        temp->next=t->next;
        t->next=temp;
}

//WORKING
void LinkedList :: deleteAtEnd(){

    if(head==NULL)
            cout<<"0 Nodes Available"<<endl;

   
    else if((head->next)==NULL){
            delete(head);
            head=NULL;
    }


    else{
     Node *t=head;

        while(((t->next)->next)!=NULL)
                t=t->next;

        Node* d=t->next;
        t->next=NULL;
        delete(d);
    }

}

//WORKING
void  LinkedList :: deleteAtBeg(){

    if(head==NULL)
            cout<<"0 Nodes Avaliable";

    else if(head->next==NULL){
        delete head;
        head=NULL;
    }

    else{
        Node* t=head;
        head=head->next;
        delete (t);
    }            
}

//WORKING
void LinkedList :: deleteAfterData(int aftData){
    Node *t=head;

    if( (head==NULL) || (head->next==NULL))
                cout<<"0 nodes available"<<endl;

else{
    
     while((t->data)!=aftData)
     t=t->next;  

        Node* d=t->next;
        t->next=d->next;
        delete(d);    
}
}

//WORKING
void LinkedList :: display(){

    if(head==NULL)
            cout<<"0 Nodes Available";
    
    else{
            Node* t=head;
            cout<<"Data of the list"<<endl;
            while(t!=NULL){
                cout<<t->data<<" ";
                 t=t->next;
            }
            cout<<endl;   
    }


}


