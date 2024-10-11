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
