
             //Multiplication Matrix
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[2][4]={{3,6,7,9},{3,4,9,6}};//Multiplexing matrix First matrix column and second matrix row should be same.
    int b[4][2]={{1,3},{2,3},{4,8},{4,7}};
    int c[2][2];
 for(int i=0;i<2;i++)
 {
    
    for(int j=0;j<2;j++)
    {
    c[i][j]=0;
    for(int k=0;k<4;k++)
    {
    c[i][j]+=a[i][k]*b[k][j];

    }
    cout<<c[i][j]<<" ";
    }
    cout<<endl;
 }
}
/*
Role of the k Loop
The k loop iterates over the range of columns in AAA (or rows in BBB).
 For each combination of row iii in AAA and column jjj in BBB, the k loop calculates the product 
 of A[i][k]A[i][k]A[i][k] and B[k][j]B[k][j]B[k][j] and accumulates these products to obtain the final value of C[i][j]C[i][j]C[i][j].


*/