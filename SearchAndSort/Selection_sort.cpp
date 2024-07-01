#include <bits/stdc++.h>
using namespace std;
int Selection_sort(int a[],int size)
{
    int index_min,temp;
    for(int i=0;i<size-1;i++)

    {
        index_min=i;
        for(int j=i+1;j<size;j++)//whsn i=0 then j=1 || i=1 then j=2 || i=2 then j=3 || when i=3 then j=4 || when i=4 then j=5(that is nort permitted). 
        {
            if(a[j]>a[index_min])
            {
                index_min=j;
            }
            if(index_min!=i)
            {
                temp=a[i];
                a[i]=a[index_min];
                a[index_min]=temp;


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
   Selection_sort(a,size);
for(int  Strin:a)
{
    cout<<Strin;
}
//  Selection_sort(a);
//     cout << "Sorted Array: ";
//     for (int i = 0; i < 5; i++) {
//         cout << a[i] << " ";
//     }
//     cout << endl;
}