/*
Page 79
Algorithm 4.6: (Binary Search) BINARY(DATA, LB, UB, ITEM, LOC)
Here DATA is a sorted array with lower bound LB and upper bound UB, 
and ITEM is a given item of information. The variables BEG, END and 
MID denote, respectively, the beginning, end and middle locations of 
a segment of elements of DATA. This algorithm finds the location LOC 
of ITEM in DATA or sets LOC = NULL.

1. [Initialize segment variables.]
Set BEG := LB, END := UB and MID = INT((BEG + END)/2).
2. Repeat Steps 3 and 4 while BEG ≤ END and DATA[MID] ≠ ITEM.
3.         If ITEM < DATA[MID], then:
Set END := MID – 1.
Else:
Set BEG := MID + 1.
[End of If structure.]
4.         Set MID := INT((BEG + END)/2).
[End of Step 2 loop.]
5. If DATA[MID] = ITEM, then:
Set LOC := MID.
Else:
Set LOC := NULL.
[End of If structure.]
6. Exit
*/

#include<bits/stdc++.h>
using namespace std;
int location=-1;
int BINARYSEARCH(int a[],int size,int n)
{
    int beggin=0;
    int end=size-1;
    
   
    while(beggin<=end)
    {
        int mid=((beggin+end)/2);
        if(a[mid]==n)
        {
           return  location=mid;
        }
        else if(a[mid]!=n)
        {
            if(a[mid]<n)
            {
              beggin=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
    
    }

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
    int a[7],size,n;
    size=sizeof(a)/sizeof(a[0]); 
    cout<<"         **Please entering element with ascending and descending order**\n\n";
    cout<<"Enter your array for searcing using binary search algorithm\n";
   
    INPUT(a,size);
    cout<<"Enter your checking number\n";
    cin>>n;
    BINARYSEARCH(a,size,n);
    if(location!=-1)
    {
        cout<<"Entering Element index is="<<location;
    }
    else
    {
        cout<<"Can not find you element which index is=0";
    }


}
/*
                             //first run///
  **Please entering element with ascending and descending order**

Enter your array for searcing using binary search algorithm
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

                       //second run//
         **Please entering element with ascending and descending order**

Enter your array for searcing using binary search algorithm
11
33
44
55
66
77
88
Enter your checking number
99
Can not find you element which index is=0
*/