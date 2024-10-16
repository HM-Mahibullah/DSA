#include<bits/stdc++.h>
using namespace std;
int NONZEROELEMENT(int a[100][100],int size)
{
int count=0;
  for (int  i = 0; i < size; i++)
    {
    for (int  j = 0; j < size; j++)
    {
      if(a[i][j]!=0)
      {
        count++;
      }
    }
    
    }
    return count;

}
int SOMOFABOVEDIAGONAL(int a[][100],int size)//You can use a[100][100]
    {
       // Summing elements above diagonal
    int SUM = 0;
    for (int j = 1; j < n; j++) {  // J starts from 1 (column 2)
        for (int i = 0; i < j; i++) {  // I goes from 0 to J-1 (rows above diagonal)
            SUM += A[i][j];
        }
    }
      return sum;
    }

/*
Example Walkthrough:
For the matrix:

Copy code
1  2  3
4  5  6
7  8  9
We want to sum the elements above the diagonal (2, 3, and 6):

Iteration 1 (J = 2):
I = 1, Add A[1,2] (which is 2) to SUM.
Iteration 2 (J = 3):
I = 1, Add A[1,3] (which is 3) to SUM.
I = 2, Add A[2,3] (which is 6) to SUM.
The final SUM would be 2 + 3 + 6 = 11.
*/
    int PRODUCTOFTHEDIAGONAELOMENT(int a[][100],int size)//You not use a[][45] or a[][45777]
    {
      int product=1;
        for (int j = 1; j < n; j++) { // Loop over columns starting from 2nd column
        for (int i = 0; i < j; i++) { // Loop through rows up to diagonal (above diagonal elements)
            PROD *= A[i][j]; // Multiply each above diagonal element
        }
    }
     return product;
    }   

int main()
{
    int size;
    cout<<"Enter element size=";
    cin>>size;
    int a[100][100];
    for (int  i = 0; i < size; i++)
    {
    for (int  j = 0; j < size; j++)
    {
        cin>>a[i][j];
    }
    
    }
    int valueofnonzeroelement=NONZEROELEMENT(a,size);
    cout<<"Total nonzero element="<<valueofnonzeroelement<<endl;
    int sum=SOMOFABOVEDIAGONAL(a,size);
    cout<<"Sum of above diagonal element ="<<sum<<endl;
    int product= PRODUCTOFTHEDIAGONAELOMENT(a,size);  
    cout<<"Product of sum on diagonal ="<<product; 
}
/*
                //First run//


Enter element size=4 
       
        9 0 4 6
        6 7 3 8
        2 8 4 5
        5 5 7 7
        
        Total nonzero element=15
        Sum of above diagonal element =26
        Product of sum on diagonal =27
    
*/
