//https://www.youtube.com/watch?v=iQNZAOw67zM&t=455s
#include<bits/stdc++.h>
using namespace std;
int Insertion_sort(int a[], int size)
{
  int item;
  for(int i=1;i<size;i++)
  {
    item=a[i];
    int j=i-1;
    while(j>=0 && a[j]>item)
    {
     a[j+1]=a[j];
     j=j-1;
    }
    a[j+1]=item;
    
  }
}
int main()
{
    int a[5];
    int size=sizeof(a)/sizeof(a[0]);
    cout<<"Enter Five Elements";
    for(int  i=0;i<size;i++)
    {
        cin>>a[i];
    }
    
  
    int index=Insertion_sort(a,size);
   
for(int b:a)
{
    cout<<b;
}
}
