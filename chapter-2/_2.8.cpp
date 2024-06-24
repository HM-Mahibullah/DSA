//Book page is 36//

#include<bits/stdc++.h>
using namespace std;
template<typename T>
void  Function(T a[],T size,T &loc1,T &loc2)
{
 if(size<2)
 {
    loc1=loc2=-1;
 }
 T firstNumber=a[0];
 T secondNumber=a[1];
 if(firstNumber<secondNumber)
 {
    swap(firstNumber,secondNumber);
    loc1=1;
    loc2=0;
 }
 for(int i=2;i<size;i++)
 {
   if(a[i]>firstNumber)
   {
    secondNumber=firstNumber;
    firstNumber=a[i];
    loc2=loc1;
    loc1=i;
   }
   else if(a[i]>secondNumber)
   {
    secondNumber=a[i];
    loc2=i;
   }
 }
}
int main()
{
    int a[]={1,2,7,3,9,3};
    int size=sizeof(a)/sizeof(a[0]),loc1=0,loc2=1;
    Function<int >(a,size,loc1,loc2);
    cout<<"First Largest integer in array is="<<a[loc1]<<endl;
    cout<<"First Largest integer in array's location is="<<loc1+1<<endl;
    cout<<"Second Largest integer in array is="<<a[loc2]<<endl;
    cout<<"Second Largest integer in array's location is="<<loc2+1;

    
}

