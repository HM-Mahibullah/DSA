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


/*

//FOR INPUT MATRIX
3
2 4 0
3 0 6
0 2 3
এখানে নোড আছে ৩ টি.
তাই W loop ১ম নোড এর সাপেক্ষ ৩ বার ঘুরবে, ২য় নোড এর সাপেক্ষ ৩ বার ঘুরবে এবং  ৩য় নোড এর সাপেক্ষে ৩ বার ঘুরবে.

                      //Explain every iteration
Iteration 1:
𝑤=1
For i=1
j=1:
p[1][1] = p[1][1] || (p[1][1] && p[1][1]) = 0 || (0 && 0) = 0

j=2:
p[1][2] = p[1][2] || (p[1][1] && p[1][2]) = 1 || (0 && 1) = 1

j=3:
p[1][3] = p[1][3] || (p[1][1] && p[1][3]) = 0 || (0 && 0) = 0

i=2

j=1:
p[2][1] = p[2][1] || (p[2][1] && p[1][1]) = 1 || (1 && 0) = 1

j=2:
p[2][2] = p[2][2] || (p[2][1] && p[1][2]) = 0 || (1 && 1) = 1

j=3:
p[2][3] = p[2][3] || (p[2][1] && p[1][3]) = 1 || (1 && 0) = 1

For i=3
j=1:
p[3][1] = p[3][1] || (p[3][1] && p[1][1]) = 0 || (0 && 0) = 0

j=2:
p[3][2] = p[3][2] || (p[3][1] && p[1][2]) = 1 || (0 && 1) = 1

j=3:
p[3][3] = p[3][3] || (p[3][1] && p[1][3]) = 0 || (0 && 0) = 0

Resulting Matrix After

w=1:
   1  2  3
1 [0, 1, 0]
2 [1, 1, 1]
3 [0, 1, 0]

Iteration 2:

w=2
For i=1
j=1:
p[1][1] = p[1][1] || (p[1][2] && p[2][1]) = 0 || (1 && 1) = 1

j=2:
p[1][2] = p[1][2] || (p[1][2] && p[2][2]) = 1 || (1 && 0) = 1

j=3:
p[1][3] = p[1][3] || (p[1][2] && p[2][3]) = 0 || (1 && 1) = 1

For i=2

j=1:
p[2][1] = p[2][1] || (p[2][2] && p[2][1]) = 1 || (1 && 1) = 1

j=2:
p[2][2] = p[2][2] || (p[2][2] && p[2][2]) = 1 || (1 && 0) = 1

j=3:
p[2][3] = p[2][3] || (p[2][2] && p[2][3]) = 1 || (1 && 1) = 1
For i=3

j=1:
p[3][1] = p[3][1] || (p[3][2] && p[2][1]) = 0 || (1 && 1) = 1

j=2:
p[3][2] = p[3][2] || (p[3][2] && p[2][2]) = 1 || (1 && 0) = 1

j=3:
p[3][3] = p[3][3] || (p[3][2] && p[2][3]) = 0 || (1 && 1) = 1

Resulting Matrix After

w=2:
   1  2  3
1 [1, 1, 1]
2 [1, 1, 1]
3 [1, 1, 1]

Iteration 3:
w=3
For i=1

j=1:
p[1][1] = p[1][1] || (p[1][3] && p[3][1]) = 1 || (1 && 0) = 1

j=2:
p[1][2] = p[1][2] || (p[1][3] && p[3][2]) = 1 || (1 && 1) = 1

j=3:
p[1][3] = p[1][3] || (p[1][3] && p[3][3]) = 1 || (1 && 1) = 1
For i=2

j=1:
p[2][1] = p[2][1] || (p[2][3] && p[3][1]) = 1 || (1 && 0) = 1

j=2:
p[2][2] = p[2][2] || (p[2][3] && p[3][2]) = 1 || (1 && 1) = 1

j=3:
p[2][3] = p[2][3] || (p[2][3] && p[3][3]) = 1 || (1 && 1) = 1
For i=3

j=1:
p[3][1] = p[3][1] || (p[3][3] && p[3][1]) = 1 || (1 && 0) = 1

j=2:
p[3][2] = p[3][2] || (p[3][3] && p[3][2]) = 1 || (1 && 1) = 1

j=3:
p[3][3] = p[3][3] || (p[3][3] && p[3][3]) = 1 || (1 && 1) = 1

Resulting Matrix After 
w=3:

   1  2  3
1 [1, 1, 1]
2 [1, 1, 1]
3 [1, 1, 1]
*/