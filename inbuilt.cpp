
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    stack<int>temp=s;
    while(!temp.empty())
    {
        cout<<temp.top();
        temp.pop();
    }
    cout<<s.top();
    return 0;



}
