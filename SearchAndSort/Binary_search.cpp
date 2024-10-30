#include<bits/stdc++.h>
using namespace std;
int binary_search(int a[],int check, int size)
{
   int left=0,right=size-1,mid;
   while (left<=right)
   {
    mid=((left+right)/2);
    if(a[mid]==check)
    {
        return mid;
    }
   if (a[mid] < check)
   {
            left = mid + 1;
   }
        else
        {
            right = mid - 1;
        }
   }
   return -1;

}
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9},number=9;
    int size=sizeof(a)/sizeof(a[0]);
    cout<<size<<endl;
  
    int index=binary_search(a,number,size);
    if(index!=-1)
    {
        cout<<"The correct index is="<<index<<endl;
    }
    else
    {
        cout<<"Can't find";
    }
}
