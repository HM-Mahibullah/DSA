/*
Page 104
Program
4.14 An n-square matrix array A is said to be symmetric 
if A[J, K] = A[K, J] for all J and K.

(a)Which of the following matrices are symmetric?

(b) Describe an efficient way of storing a symmetric matrix A in memory.

(c) Suppose A and B are two n-square symmetric matrices. 
Describe an efficient way of storing A and B in memory.
*/
#include<bits/stdc++.h>
using namespace std;

//Using size_t in the template parameter is a common practice in C++ because 
//size_t is the type returned by the sizeof operator.
template<size_t M,size_t N>
void PRINT(int (&DEMO)[M][N],int ROW,int COLUMN)
{
    for (int i = 0; i <ROW; i++)
    {
      for (int  j = 0; j <COLUMN; j++)
      {
       cout<<DEMO[i][j]<<"  ";
      }
      cout<<"\n";
    }
}
                     //Question (a)//
template<size_t M,size_t N>
int  SYMMETRICS(int (&DEMO)[M][N],int ROW,int COLUMN)
{
    for (int i = 0; i <ROW; i++)
    {
      for (int  j = 0; j <COLUMN; j++)
      {
         if(DEMO[i][j]!=DEMO[j][i])
        {
         return 0;
        }
      }
 
    }
    return 1;
    
}
void CHECK(int i)
{
    if(i!=0)
    {
        cout<<"Matrix is symmetric";
    }
    else
    {
    cout<<"Matrix is not symmetric"; 
    }
}

                        //Question (b)//
template<size_t M,size_t N>
int LOWER_TRIANGULAR(int (&DEMO)[M][N],int ARRAY[],int ROW,int COLUMN)
{
int k=0;
for (int  i = 0; i < ROW; i++)
{
    for (int  j = 0; j <=i; j++)
    {
    ARRAY[k++]=DEMO[i][j];
    }
    
}
return k;

}

template<size_t M,size_t N>
int UPPER_TRIANGULAR(int (&DEMO)[M][N],int ARRAY[],int ROW,int COLUMN)
{
int k=0;
for (int  i = 0; i < ROW; i++)
{
    for (int  j = i; j <COLUMN; j++)
    {
    ARRAY[k++]=DEMO[i][j];
    }
    
}
return k;
}

int main()
{
                        //Question (a) answer//
int X[][3]={2,-3,5,-3,-2,4,5,6,8};// OR DECLARE //int X[ ][3]={2,-3,5,-3,-2,4,5,6,8};
int Y[3][4]={1,1,1,1,1,1,1,1,1,1,1,1};
int Z[3][3]={1,3,-7,3,6,-1,-7,-1,2};
cout << "Array X:\n";
CHECK(SYMMETRICS(X,3,3));
cout<<"\n";
PRINT(X,3,3);
cout << "Array Y:\n";
CHECK(SYMMETRICS(Y,3,4));
cout<<"\n";
PRINT(Y,3,4);
cout << "Array Z:\n";
CHECK(SYMMETRICS(Z,3,3));
cout<<"\n";
PRINT(Z,3,3);
                                  //Question (b)//
/*
In Question (a) Z is symmetrics matrix.So, we assume that Z new name is A.Then explain 
efficient way to storing Am atrix in menory.
We can store elements of symmetrics using lower triangular function or upper  triangular function.  
*/ 
                          
                          //using lower triangular function//
cout<<"using lower triangular function"<<endl;
int L[10];
int count=LOWER_TRIANGULAR(Z,L,3,3);
/*Lower Triangular Storage:
Saves space by storing only N*(N+1)/2 elements instead of N×N  times
*/

for (int  i = 0; i <count; i++)
{
    cout<<L[i]<<" ";
}
                          //using Upper triangular function//
cout<<endl<<"using upper triangular function"<<endl;
int count1=UPPER_TRIANGULAR(Z,L,3,3);
/*Upper Triangular Storage:
Saves space by storing only N*(N+1)/2 elements instead of N×N  times
*/

for (int  i = 0; i <count1; i++)
{
    cout<<L[i]<<" ";
}


}


/*
            //First run//

Array X:
Matrix is not symmetric
2  -3  5
-3  -2  4
5  6  8
Array Y:
Matrix is not symmetric
1  1  1  1
1  1  1  1
1  1  1  1
Array Z:
Matrix is symmetric
1  3  -7
3  6  -1
-7  -1  2
using lower triangular function
1 3 6 -7 -1 2
using upper triangular function
1 3 -7 6 -1 2




*/