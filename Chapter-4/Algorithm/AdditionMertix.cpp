
//Addition Matrix
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[2][3]={{1,2,3},{2,3,4}};//In Sdditon Matrix two(Forst and second) matrix column and row shoulb be same.
    int b[2][3]={{1,2,3},{5,3,7}};
    int c[2][3];
    for (int  i = 0; i < 2; i++)
    {
 for (int j = 0; j <3; j++)
 {
    c[i][j]=a[i][j]+b[i][j];
    cout<<c[i][j]<<" ";
 }
 cout<<endl;
 
    }
}
/*
            //First run//
2 4 6 
7 6 11   
            


*/
