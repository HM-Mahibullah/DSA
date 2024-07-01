//Prime Numbers
//Book 37//

#include<bits/stdc++.h>
using namespace std;
void Crossout(int a[],int n,int k)
{
   if(a[k]==1)
   {
    return;//Not proceed loweer for loop
   }
   for(int l=k*2;l<n;l=l+k)
   {
      a[l]=1;
   }
}
int main()
{
    int n=20,k;
    int a[n];
    for(k=2;k<n;k++)
    {
        Crossout(a,n,k);
    }
    for(int j=0;j<n;j++)
    {
        if(a[j]!=1)
        {
            cout<<j;
        }
    }

}
