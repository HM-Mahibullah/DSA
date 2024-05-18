#include<bits/stdc++.h>
using namespace std;
void LargestValueOfArray(int Data[],int N)
{
    int K=0,Loc=0,Max=Data[0];
    Increment_Counter:
    K+=1;
    if(K==N)
    {
        cout<<"Loc"<<Loc<<"Max,"<<Max<<"\n";
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
int Data[]={2,3,4,6};
int N=sizeof(Data);
 LargestValueOfArray(Data,N);

}
