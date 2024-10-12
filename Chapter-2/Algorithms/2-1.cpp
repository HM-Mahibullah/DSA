//Book page 21

#include<bits/stdc++.h>
using namespace std;
void LargestValueOfArray(int Data[],int N)
{
    int K=0,Loc=0,Max=Data[0];   int K = 3; // if k=3 then Start the loop from the 4th element (0-based index)
    Increment_Counter:
    K+=1;
    if(K==N)
    {
        cout<<"Loc="<<Loc<<endl<<"Max="<<Max<<"\n";
        return;  // Properly break out of the function
    }
    if(Max<Data[K])
    {
      Loc=K;
      Max=Data[K];
    }
    goto Increment_Counter;

}
int main()
{
int Data[]={2,3,4,9,1,0,10};
int N=sizeof(Data)/sizeof(Data[0]);
 LargestValueOfArray(Data,N);

}
/*
How the Code Works for Input {2, 3, 4, 9, 15, 0, 10}:
Initial values:

Max = 2, Loc = 0, K = 0
First iteration (K = 1):

Compare Max = 2 with Data[1] = 3. Since 3 > 2, Max becomes 3 and Loc becomes 1.
Second iteration (K = 2):

Compare Max = 3 with Data[2] = 4. Since 4 > 3, Max becomes 4 and Loc becomes 2.
Third iteration (K = 3):

Compare Max = 4 with Data[3] = 9. Since 9 > 4, Max becomes 9 and Loc becomes 3.
Fourth iteration (K = 4):

Compare Max = 9 with Data[4] = 15. Since 15 > 9, Max becomes 15 and Loc becomes 4.
Fifth iteration (K = 5):

Compare Max = 15 with Data[5] = 0. Since 0 is not greater than 15, Max and Loc remain unchanged.
Sixth iteration (K = 6):

Compare Max = 15 with Data[6] = 10. Since 10 is not greater than 15, Max and Loc remain unchanged.
End of loop:

When K = 7, the loop ends because K == N.
*/
