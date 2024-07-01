
//FOR INPUT MATRIX
3
2 4 0
3 0 6
0 2 3

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int p[n+1][n+1];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>p[i][j];
        }
    }
  for(int w=1;w<=n;w++)
  {
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
       
           p[i][j]=p[i][j]||p[i][w]&&p[w][j];
        }
    }
  }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
        cout<<p[i][j]<<" ";

        }
        cout<<endl;
    }
}   


