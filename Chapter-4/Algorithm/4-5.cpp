/*
Page 77
Algorithm 4.5: (Linear Search) LINEAR(DATA, N, ITEM, LOC)
Here DATA is a linear array with N elements, and ITEM is a given item of information. 
This algorithm finds the location LOC of ITEM in DATA, or sets LOC := 0 if the search is unsuccessful.


1. [Insert ITEM at the end of DATA.] Set DATA[N + 1] := ITEM.
2. [Initialize counter.] Set LOC := 1.
3. [Search for ITEM.]
Repeat while DATA[LOC] ≠ ITEM:
Set LOC := LOC + 1.
[End of loop.]
4. [Successful?] If LOC = N + 1, then: Set LOC := 0.
5. Exit.
*/

#include<bits/stdc++.h>
using namespace std;
int location=-1;
int LINEARSEARCH(int a[],int size,int n)
{
    for(int i=0;i<size;i++)
    {
        if(a[i]==n)
        {
            location=i;

        }

    }
    return location;
}
void INPUT (int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
}
int main()
{
    int a[10],size,n;
    size=sizeof(a)/sizeof(a[0]);
    cout<<"Enter your array\n";
    INPUT(a,size);
    cout<<"Enter your checking number\n";
    cin>>n;
    LINEARSEARCH(a,size,n);
    if(location!=-1)
    {
        cout<<"Entering Element index is="<<location;
    }
    else
    {
        cout<<"Can not find your element";
    }


}
/*
Enter your array
1
2
3
4
5
6
7
8
9
10
Enter your checking number
5
Entering Element index is=4
*/
