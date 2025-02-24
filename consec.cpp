#include<iostream>
using namespace std;
int main()
{
    int a[100],i,n,j,count=0;
    cin>>n;
    cout<<"enter the elements";
    for(i=0;i<n;i++)
        cin>>a[i];
    for(j=0;j<n;j++)

    {
        if(a[j+1]!=a[j]+1)
         {

          count++;
        break;}
    }
    cout<<count;
    return 0;
}
