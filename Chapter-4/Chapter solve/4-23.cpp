/*
Page 109
Program
4-23
An array A contains 25 positive integers. Write a module which

(a) Finds all pairs of elements whose sum is 25.

(b) Finds the number EVNUM of elements of A which are even, 
    and the number ODNUM of elements of A which are odd.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A[25];
    srand(time(0));//using always '0'

    /* This ensures that the random numbers are different each time you run the program. 
    Without seeding, the rand() function will generate the same sequence of numbers each time
     you run the program. */
    cout<<"ENTER 25 NUMBERS IN ARRAY USING RANDOM FUNCTION"<<endl;
    for (int  i = 0; i <25; i++)
    {
     A[i]=rand()%15+1;
/*  
rand():
      This function generates a pseudo-random integer in the range 0 to RAND_MAX (typically a large number like 32767).


% 15:

The modulo operator (%) returns the remainder of the division of rand() by 15. This operation  the random number to the range 0 to 14.
(since the remainder when dividing by 15 can only be between 0 and 14).


+ 1:

Adding 1 shifts the range of numbers from 0-14 to 1-15. So, rand() % 15 + 1 will generate a random integer between 1 and 15 inclusive.

 */
    }
    for (int  i = 0; i <25; i++)
    {
      cout << setw(3) << A[i] ;//stew give space in array elements.
    }
for (int  i = 0; i < 25; i++)
{
for (int j = 0; j <25; j++)
{
    if(A[i]+A[j]>=25)//GREATER TNAN OR EQUAL 25
    {
        cout<<"A["<<i<<"]"<<" + A["<<j<<"]"<<"= "<<A[i]+A[j]<<endl;
          cout<<endl;
    }
}
}

 
cout<<"EVEN NUMBERS WITHIN 25 NUMBES"<<endl;

for (int i=0;i<sizeof(A)/sizeof(A[0]); i++)
{
if(A[i]%2==0)
{
    cout<<A[i]<<endl;
    cout<<endl;
}
}
cout<<"ODD NUMBERS WITHIN 25 NUMBES"<<endl;
for (int i=0;i<sizeof(A)/sizeof(A[0]); i++)
{
if(A[i]%2!=0)
{
    cout<<A[i]<<endl;
    cout<<endl;
}
}


    
    
}
/* 
         //FIRST RUN//
         
ENTER 25 NUMBERS IN ARRAY USING RANDOM FUNCTION
 12  1  2  2  6  9 10  1  5 14  4  9  8  3 11  6  8  7  6 12  5  9  3  1 14A[0] + A[9]= 26

A[0] + A[24]= 26

A[9] + A[0]= 26

A[9] + A[9]= 28

A[9] + A[14]= 25

A[9] + A[19]= 26

A[9] + A[24]= 28

A[14] + A[9]= 25

A[14] + A[24]= 25

A[19] + A[9]= 26

A[19] + A[24]= 26

A[24] + A[0]= 26

A[24] + A[9]= 28

A[24] + A[14]= 25

A[24] + A[19]= 26

A[24] + A[24]= 28

EVEN NUMBERS WITHIN 25 NUMBES
12

2

2

6

10

14

4

8

6

8

6

12

14

ODD NUMBERS WITHIN 25 NUMBES
1

9

1

5

9

3

11

7

5

9

3

1
 */