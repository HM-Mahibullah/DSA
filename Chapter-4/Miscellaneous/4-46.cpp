/*
Page
Program 
4.16 Consider the polynomial

f (x) = a1xn + a2xn−1 + … + anx + an+1

Evaluating the polynomial in the obvious way would require

multiplications and n additions. However, one can rewrite the 
polynomial by successively factoring out x as follows:

f (x) = ((… ((a1x + a2)x + a3)x + …)x + an)x + an+l

This uses only n multiplications and n additions. This second 
way of evaluating a polynomial is called Horner’s method.

(a) Rewrite the polynomial f (x) = 5x4 − 6x3 + 7x2 + 8x − 9 as 
it would be evaluated using Horner’s method.

(b) Suppose the coefficients of a polynomial are in memory in a 
linear array A(N + 1). (That is, A[1] is the coefficient of xn, 
A[2] is the coefficient of xn–1, …, and A[N + 1] is the constant.) 
Write a procedure HORNER(A, N + 1, X, Y) which finds the value 
Y = F(X) for a given value X using Horner’s method.

Test the program using X = 2 and f (x) from part (a).
*/

#include<bits/stdc++.h>
using namespace std;
void HORNORS(int A[],int N,int X,int& Y)
{
    Y=A[0];
    for (int  i = 1; i <N; i++)
    {
       Y=Y*X+A[i];
    }
    
}
int main()
{
    int X=2,Y, A[5]={5,-6,7,8,-9};
    HORNORS(A,5,X,Y);
    cout<<"Evaluting this method using Hornor's mrthod="<<Y;


}

/* 


(a) Horner's Method for the Polynomial f(x)=5x4−6x3+7x2+8x−9
Using Horner's method, the polynomial can be rewritten as: f(x)=(((5x−6)x+7)x+8)x−9 

Step-by-Step Example
1.	Initialization:
Y = A[0] = 5
2.	First Iteration (i = 1):
Y = Y * X + A[1] = 5 * 2 + (-6) = 10 - 6 = 4
3.	Second Iteration (i = 2):
Y = Y * X + A[2] = 4 * 2 + 7 = 8 + 7 = 15
4.	Third Iteration (i = 3):
Y = Y * X + A[3] = 15 * 2 + 8 = 30 + 8 = 38
5.	Fourth Iteration (i = 4):
Y = Y * X + A[4] = 38 * 2 + (-9) = 76 - 9 = 67
Result
The function calculates f(2)f(2)f(2) using Horner's method, and the final result stored in Y is:
Horner's method = 67
*/
