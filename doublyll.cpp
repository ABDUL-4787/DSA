#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(){
        data=0;
        next=nullptr;
     prev=nullptr;

    }
    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }

};
class Doubly{
    Node* head;
    public:
    Doubly(){
    head=NULL;
    }
    void insertAtfirst(int data){
        Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    }
    void display(){
        Node* temp=head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    }
    void insertatEnd(int data){



    Node* newNode=new Node(data);
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    }
    void deletefirst(){
    Node* temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    delete temp;
    }
    void deleterear(){
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    delete temp;
    }
};
int main(){
 Doubly
 d;
 d.insertAtfirst(1);
 d.insertAtfirst(2);
 d.insertAtfirst(3);
 d.insertatEnd(7);
 d.deletefirst();
 d.deleterear();
 d.display();
 return 0;
}



