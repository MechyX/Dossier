#include<iostream>
#include"SNode.hpp"
using namespace std;

void Swap(LinkedList &L,int data1, int data2){
        bool f1=false,f2=false;
        Node *t1=L.head;
        Node *t2=L.head;
        while(t1->next!=NULL){
            if(data1==t1->next->data){
                f1=true;
                break;
            }
                
            t1=t1->next;
        }
        while(t2->next!=NULL){
            if(data2==t2->next->data){
                f2=true;
                break;
            }
                
            t2=t2->next;
        }

    if(f1==false){
        L.insertAtBeg(-1);
        t1=L.head;
    }
    else if(f2==false){
        L.insertAtBeg(-1);
        t1=L.head;
    }

    Node *temp;
    temp = t1->next;
    t1->next = t2->next;
    t2->next = temp;
    temp = t1->next->next;
    t1->next->next = t2->next->next;
    t2->next->next = temp;

    if(f1==false || f2==false){
        L.deleteAtBeg();
    }
}

int main(){
    LinkedList L;
    int i;
    for(i=1;i<=6;i++){
        L.insertAtEnd(i);
    }
    Swap(L,1,4);
    L.display();
    return 0;
}
