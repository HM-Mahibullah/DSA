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
int MEAN(int A[],int N,int AVG)
{
    int i;
    for ( i = 0; i<N-1; i++)
    {
       AVG+=A[i];
    }
    return (AVG/N);
    
}
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
    cout << setw(3) << A[i];//stew give space in array elements.
    if((i+1)%5==0)
    {
        cout<<endl;
    }
    }
cout<<endl<<"Average Within 25 numbers="<<MEAN(A,25,0);
}

/*          //FIRST RUN//
ENTER 25 NUMBERS IN ARRAY USING RANDOM FUNCTION
  9  7  5 11  1
  1  4  3  1 15
  3 14  2 11 11
  9  7 11  9 13
 14  1  4 11 15

Average Within 25 numbers=7 */