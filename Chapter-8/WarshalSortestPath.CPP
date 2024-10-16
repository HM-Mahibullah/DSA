
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


//FOR INPUT MATRIX
4
7 5 0 0
7 0 0 2
0 3 0 0 
4 0 1 0

এখানে নোড আছে 4 টি.
তাই W loop ১ম নোড এর সাপেক্ষ 4 বার ঘুরবে, ২য় নোড এর সাপেক্ষ 4 বার ঘুরবে ৩য় নোড এর সাপেক্ষে 4 বার ঘুরবে 
এবং ৪য় নোড এর সাপেক্ষে 4 বার ঘুরবে. পরবর্তীতে প্রত্যেক নোড sortest path সাপেক্ষে বের করবো.
