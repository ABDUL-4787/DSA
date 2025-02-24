#include<iostream>
using namespace std;
#define size 5
void push();
void pop();
void peek();
void display();
int stack[size],top=-1;
int main()
{int choice;
while(1){
cout<<"1.push\n2.pop\n3.peek\n4.display\n";
cout<<"enter your choice";
cin>>choice;
switch(choice){
case 1:push();
break;
case 2:pop();
break;
case 3:peek();
break;
case 4:display();
break;
case 5:exit;
default: cout<<"wrong selection";
}
}
}
void push()
{
int x;
cout<<"enter data";
cin>>x;
if(top==size-1){
cout<<"overflow";}
else{
top++;
stack[top]=x;
}
}
void pop(){
int item;
if(top==-1){
cout<<"underflow";
}
else{
item=stack[top];
top--;
cout<<item;
}}
void peek(){
if(top==-1)
cout<<"empty";
else{
cout<<stack[top];
}}
void display() {
    if (top == -1) {
        cout << "Stack is empty!\n"; // Check for empty stack
    } else {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " "; // Fixed the array access
        }
        cout << endl;
    }
}







