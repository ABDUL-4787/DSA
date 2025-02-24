#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>v;
    cout<<"vector size is:"<<v.size()<<endl;
    cout<<"Vector capacity is:"<<v.capacity()<<endl;
    v.push_back(1);
    v.push_back(3);
    //v.assign(5,10);
    for (int element : v)
    {
        cout<<element<<" ";
    }
    cout<<endl;

    cout<<"vector size is:"<<v.size()<<endl;
    cout<<"Vector capacity is:"<<v.capacity()<<endl;
    return 0;

}
