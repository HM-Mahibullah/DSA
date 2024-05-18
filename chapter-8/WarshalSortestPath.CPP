
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
            if(p[i][j]==0)
            {
                p[i][j]=(int)1e7;
            }
        }
    }
  for(int w=1;w<=n;w++)
  {
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
          p[i][j]=min(p[i][j],p[i][w]+p[w][j]);
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