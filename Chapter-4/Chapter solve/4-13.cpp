/*
Page 104 
Program
4.13 Consider an n-square tridiagonal array A as shown in Fig. 4.24. 
Note that A has n elements on the diagonal and n − 1 elements above 
and n − 1 elements below the diagonal. Hence A contains at most 3n − 2 
nonzero elements. Suppose we want to store A in a linear array B as 
indicated by the arrows in Fig. 4.24; i.e.,

B[1] = a11,   B[2] = a12,   B[3] = a21,   B[4] = a22, …
Find the formula that will give us L in terms of J and K such that
B[L] = A[J, K]
(so that one can access the value of A[J, K] from the array B).

Note that there are 3(J − 2) + 2 elements above A[J, K] 
and K − J + 1 elements to the left of A[J, K].
Hence
L = [3(J − 2) + 2] + [K − J + 1] + 1 = 2J + K − 2
*/
#include<bits/stdc++.h>
using namespace std;
int TRIDIAGONAL(int A[][4],int TRI[])
{
    int k=0;
    for (int  i = 0; i < 4; i++)
    {
    for (int j = 0; j <4; j++)
    {
        if(i==j)
        {
          if(i!=0&&j!=0)
          {
          TRI[k++]=A[i][j-1];//Back elements count
          }
          TRI[k++]=A[i][j];// Main diagonal element
          if(j!=4-1)//Zero base index
          {
            TRI[k++]=A[i][j+1];// Forward element
          }
        }
    }
    }
    return k;

}

void PRINT(int A[][4])
{
    for (int  i = 0; i < 4; i++)
    {
    for (int j = 0; j <4; j++)
    {
        cout<<A[i][j]<<" ";
    }
    cout<<endl;
    
    }
    
}
int main()
{
    int L[20],    A[4][4]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    // Array to store tridiagonal elements
     PRINT(A);
    int k=TRIDIAGONAL(A,L);
    // Print the linear array containing tridiagonal elements
    for (int  i = 0; i <k; i++)
    {
        cout<<L[i]<<" ";
    }
    // Example to access A[2][3] using the formula L = 2J + K - 2
      cout<< "\nA[2][3] = " <<L[2*3 + 2 - 2] << " ";
                       //OR use//
        //cout<< "\nA[2][3] = " <<L[2*3] << " ";


}


/*
Output
1 2 3 4 
5 6 7 8
9 10 11 12
13 14 15 16

1 2 5 6 7 10 11 12 15 16
A[2][3] = 11
*/
