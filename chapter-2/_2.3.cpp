#include<iostream>
using namespace std;
int main()
{
    int b[]={1,9,7,5,2,4},loc=0,Max=b[0],k=0;
    int N=sizeof(b)/sizeof(b[0]);
    while (N>k)
    {
        if(Max<b[k])
       {
        loc=k;
        Max=b[k];
       }
       k++;
    }
    cout<<Max<<endl;
    cout<<loc;
    
}