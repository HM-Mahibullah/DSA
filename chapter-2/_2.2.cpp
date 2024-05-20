#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    double x1,x2;
    cout<<"Enter coefficient of x^2=";
    cin>>a;
    cout<<"Enter coefficient of x=";
    cin>>b;
    cout<<"Enter coefficient of c=";
    cin>>c;
    double D=(b*b)-4*a*c;
    if(D>0)
    {
        x1=(-b+sqrt(D))/(2.0*a);
        x2=(-b-sqrt(D))/(2.0*a);
        cout<<"Value of the first roots "<<x1<<endl;
        cout<<"Value of the second root "<<x2;
    }
    else if(D==0)
    {
        x1=-b/(2.0*a);
        cout<<"Unique value of root="<<x1;
    }
    else
    {
        cout<<"There is no real value on this equation";
    }


}   