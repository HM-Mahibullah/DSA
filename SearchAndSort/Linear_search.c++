
#include<bits/stdc++.h>
using namespace std;
int Linear_Search(int a[],int check,int size)
{
    for(int i=0;i<size;i++)
    {
        if(a[i]==check)
        {
            return i;
        }
      
    }
      return 0;
}
int main()
{
    int a[]={1,2,3,8,4,5};
    int check=5;
    int size=sizeof(a);
    int k=Linear_Search(a,check,size);
    if(k!=0)
    {
        cout<<"the searchin value is="<<k;
    }
    else
    {
        cout<<"Not find searching value";
    }

}
