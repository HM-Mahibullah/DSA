#include<bits/stdc++.h>
using namespace std;
int  LargestValue(int Data[],int size)
{
int k=0,Loc=0,max=Data[0];
while(k<size)
{
if(max<Data[k])
{
    Loc=k;
    max=Data[k];
}
k++;
}
return Loc;
}
int main()
{
    int Data[]={1,40,9,10,2,5};
    int size=sizeof(Data)/sizeof(Data[0]);
    int Loc=LargestValue(Data,size);
    cout<<"Loc "<<Loc<<" Maximum "<<Data[Loc];
}
