#include<bits/stdc++.h>
using namespace std;

void TRAVERSE(int n[],int lb,int up)
{
  cout<<"       //TRAVERSING   ARRAY//  \n";
   for (int i =lb; i <=up; i++)
   {
    cout<<n[i]<<endl;
   }
   cout<<"\n";
   
}

void REVERSE(int n[],int lb,int up)
{

    cout<<"             //REVERSING ARRAY//\n";
  for (int i =up; i>=lb; i--)
  {
    cout<<n[i]<<endl;
  }
    cout<<"\n";
  
}
int main()
{
    int n[100];
    cout<<"Enter five input  \n";
    for(int i=0;i<5;i++)
    {
        cin>>n[i];
    }
    cout<<"\n\n\n";
    TRAVERSE(n,0,4);
    REVERSE(n,0,4);
}
/*
            //First run//

Enter five input  
11
22
33
45
55



       //TRAVERSING   ARRAY//
11
22
33
45
55

             //REVERSING ARRAY//
55
45
33
22
11
*/