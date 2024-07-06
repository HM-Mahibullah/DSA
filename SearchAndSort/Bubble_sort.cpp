#include<bits/stdc++.h>
using namespace std;
void SORT(int a[],int length )
{
 for(int i=0;i<length;i++)
 {
    for(int j=0;j<length-i;j++)
    {
        if(a[j]>a[j+1])
        {
            swap(a[j],a[j+1]);
        }
    }
 } 
}
int main()
{
    int a[10],i;
    cout<<"Enter your array\n";
    for(i=0;i<10;i++)
    {
        cin>>a[i];
    }
    SORT(a,i);
    cout<<"Ascending order"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
      cout<<"Descending order"<<endl;
    for(int i=9;i>=0;i--)
    {
        cout<<a[i]<<" ";
    }
}
/*
Enter your array
9
1
8
3
5
9
5
6
7
4
Ascending order
1 3 4 5 5 6 7 8 9 9
Descending order
9 9 8 7 6 5 5 4 3 1
*/
