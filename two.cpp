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
    void insertatfirst(int data){
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
 Doubly d;
 Doubly d1;
 d.insertatfirst(1);
  d.insertatfirst(2);
   d.insertatfirst(3);
   d1.insertatfirst(1);
  d1.insertatfirst(4);
   d1.insertatfirst(3);
d.display();
cout<<endl;
d1.display();




 return 0;
}
