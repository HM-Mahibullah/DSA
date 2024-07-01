#include<bits/stdc++.h>
using namespace std;
int Bubble_sort(int a[],int size)
{
     int temp;
     for(int i=0;i<size;i++)
     {
        for(int j=0;j<size-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
     }
}
int main()
{
    int a[5];
    int size=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    Bubble_sort(a,size);
    for(int b:a)
    {
        cout<<b<<" ";
    }

}