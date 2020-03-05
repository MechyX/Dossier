#include<iostream>
using namespace std;
class doublylinkedlist;

class Node{
    int data;
    Node *next;
    Node *prev;
    public:
    friend doublylinkedlist;
};

class doublylinkedlist{
    Node *head;
    public:
    doublylinkedlist();
    void insertbeg(int data);
    void insertAfterData(int data,int aftData);
    void insertBeforeData(int data,int aftData);
    void deleteBeg();
    void deleteAfterData(int aftData);
    void deleteBeforeData(int aftData);
    void deleteNodeWithData(int aftData);
    void deleteEnd();
    void display();
};

//WORKING
doublylinkedlist :: doublylinkedlist (){
        head=NULL;
}

//WORKING
void doublylinkedlist :: insertbeg(int data){
    Node* temp= new Node;
    temp->data = data;
    temp->prev = NULL;
    

    if(head==NULL){
        head=temp;   
        temp->next = NULL;
    }
        
    else{
        temp->next=head;
        head=temp;
        temp->next->prev=temp;
        }      
}

//WORKING
void doublylinkedlist :: insertAfterData(int data,int aftData){
    Node* temp= new Node;
    temp->data =  data;

    if(head==NULL)
        cout<<"No Node Available";


    else{
            Node* t=head;
              while(t->data!=aftData)
                    t=t->next;
              
            temp->next=t->next;
            temp->prev=t;
            
            if(t->next!=NULL)
            (t->next)->prev=temp;
            
            t->next=temp;
    }

}

//WORKING
void doublylinkedlist :: insertBeforeData(int data,int aftData){
    Node* temp= new Node;
    temp->data =  data;

    if(head==NULL)
        cout<<"No Node Available";

    else{
            Node* t=head;
              while(t->data!=aftData)
                    t=t->next;
    
            temp->next=t;
            temp->prev=t->prev;

            if((t->prev)==NULL)
                head=temp;

           else
            (t->prev)->next = temp;
            
            t->prev=temp;
        }
}


//WORKING
void doublylinkedlist ::  deleteBeg(){
    if(head==NULL)
        cout<<"No Node Available";

    else{
        Node *d=head;
        (head->next)->prev=NULL;
        head=head->next;
        delete d;
    }


}
    
//WORKING
void doublylinkedlist :: deleteAfterData(int aftData){

if(head==NULL)
        cout<<"No Node Available";

else{
            Node* t=head;
              while(t->data!=aftData)
                    t=t->next;
            
            if(t->next!=NULL){
                 Node * d=t->next;
                (d->next)->prev=t;
                t->next=d->next;
                delete (d);
            }
            
            else
            {
                cout<<"End Of List"<<endl;
            }
            
}
}

//WORKING
void doublylinkedlist :: deleteBeforeData(int aftData){

    if(head==NULL)
        cout<<"No Node Available";
    
    else{
             Node* t=head;
              while(t->data!=aftData)
                    t=t->next;

            if(t->prev==head){
                Node *d=t->prev;
                head=t;
                t->prev=NULL;
                delete (d);
            }

            else if(t->prev!=NULL){
            Node * d=t->prev;
            (d->prev)->next=t;
            t->prev=d->prev;
            delete d;
            }

            else
                cout<<"No Nodes Available";
    }

   cout<<endl;
}

//WORKING
void doublylinkedlist :: deleteNodeWithData(int aftData){

    if(head==NULL)
        cout<<"No Node Available";
    
    else{
             Node* t=head;
              while(t->data!=aftData)
                    t=t->next;

            if(t->next==NULL && t->prev==NULL){
                delete(t);
                head=NULL;
            }

            else if(t->next==NULL){
                (t->prev)->next=NULL;
                delete (t);
            }
                
            
            else if(t->prev==NULL){
                      head=t->next;
                      head->prev=NULL;
                      delete(t);
                }
            
            else{
            (t->prev)->next=t->next;
            (t->next)->prev=t->prev;
            delete (t);
            }

            
    }

}

//NOT WORKING
void doublylinkedlist :: deleteEnd(){

        if(head==NULL)
            cout<<"No Node Available";

    else{
           
            Node *t =head;

            while((t->next)!=NULL){
                    t=t->next;
            }
                    
            if(t==head){
               
                    delete(head);
                    head=NULL;
            }

            else{
            t->prev->next=NULL;
            delete(t);
            }
            
    }

   
}

//WORKING
void doublylinkedlist :: display(){
    if(head==NULL)
        cout<<"No Nodes available";

    else{
         Node *t =head;

        while(t!=NULL)
        {
                cout<<t->data<<" ";
                 t=t->next;
        }

    }

    cout<<endl;
}


