/*
Page 75
Algorithm 4.4: (Bubble Sort) BUBBLE(DATA, N)
Here DATA is an array with N elements. This algorithm sorts the elements in DATA.
1. Repeat Steps 2 and 3 for K = 1 to N – 1.
2.        Set PTR := 1. [Initializes pass pointer PTR.]
3.        Repeat while PTR ≤ N – K: [Executes pass.]
(a) If DATA[PTR] < DATA[PTR + 1], then:
Interchange DATA[PTR] and DATA[PTR + 1].
[End of If structure.]
(b) Set PTR := PTR + 1.
[End of inner loop.]
[End of Step 1 outer loop.]
4. Exit
*/
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
            swap(a[j],a[j+1]);//At j = 9, it tries to compare a[9] with a[10], but a[10] doesn't exist in the array of size 10.
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
