
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

/*

//FOR INPUT MATRIX
4
7 5 0 0
7 0 0 2
0 3 0 0 
4 0 1 0

এখানে নোড আছে 4 টি.
তাই W loop ১ম নোড এর সাপেক্ষ 4 বার ঘুরবে, ২য় নোড এর সাপেক্ষ 4 বার ঘুরবে ৩য় নোড এর সাপেক্ষে 4 বার ঘুরবে 
এবং ৪য় নোড এর সাপেক্ষে 4 বার ঘুরবে. পরবর্তীতে প্রত্যেক নোড sortest path সাপেক্ষে বের করবো.


Initial Matrix (Before any iteration):

  7   5  1e7 1e7
  7   1e7 1e7 2
  1e7 3  1e7 1e7
  4   1e7 1   1e7


Iteration 1: w = 1
We check if going through vertex 1 (w=1) provides a shorter path for any pair of vertices:

For i=1:

j=1: p[1][1] = min(p[1][1], p[1][1] + p[1][1]) = min(7, 7) = 7
j=2: p[1][2] = min(p[1][2], p[1][1] + p[1][2]) = min(5, 12) = 5
j=3: p[1][3] = min(p[1][3], p[1][1] + p[1][3]) = min(1e7, 1e7 + 1e7) = 1e7
j=4: p[1][4] = min(p[1][4], p[1][1] + p[1][4]) = min(1e7, 1e7 + 1e7) = 1e7

For i=2:

j=1: p[2][1] = min(p[2][1], p[2][1] + p[1][1]) = min(7, 7 + 7) = 7
j=2: p[2][2] = min(p[2][2], p[2][1] + p[1][2]) = min(1e7, 7 + 5) = 12
j=3: p[2][3] = min(p[2][3], p[2][1] + p[1][3]) = min(1e7, 7 + 1e7) = 1e7
j=4: p[2][4] = min(p[2][4], p[2][1] + p[1][4]) = min(2, 7 + 1e7) = 2

For i=3:

j=1: p[3][1] = min(p[3][1], p[3][1] + p[1][1]) = min(1e7, 1e7 + 7) = 1e7
j=2: p[3][2] = min(p[3][2], p[3][1] + p[1][2]) = min(3, 1e7 + 5) = 3
j=3: p[3][3] = min(p[3][3], p[3][1] + p[1][3]) = min(1e7, 1e7 + 1e7) = 1e7
j=4: p[3][4] = min(p[3][4], p[3][1] + p[1][4]) = min(1e7, 1e7 + 1e7) = 1e7

For i=4:

j=1: p[4][1] = min(p[4][1], p[4][1] + p[1][1]) = min(4, 4 + 7) = 4
j=2: p[4][2] = min(p[4][2], p[4][1] + p[1][2]) = min(1e7, 4 + 5) = 9
j=3: p[4][3] = min(p[4][3], p[4][1] + p[1][3]) = min(1, 4 + 1e7) = 1
j=4: p[4][4] = min(p[4][4], p[4][1] + p[1][4]) = min(1e7, 4 + 1e7) = 1e7
Matrix after w=1:

  7   5   1e7  1e7
  7  12   1e7  2
  1e7 3   1e7  1e7
  4   9    1   1e7

Iteration 2: w=2
Now we check if going through vertex 2 (w=2) provides shorter paths:

For i=1:

j=1: p[1][1] = min(p[1][1], p[1][2] + p[2][1]) = min(7, 5 + 7) = 7
j=2: p[1][2] = min(p[1][2], p[1][2] + p[2][2]) = min(5, 5 + 12) = 5
j=3: p[1][3] = min(p[1][3], p[1][2] + p[2][3]) = min(1e7, 5 + 1e7) = 1e7
j=4: p[1][4] = min(p[1][4], p[1][2] + p[2][4]) = min(1e7, 5 + 2) = 7
For i=2:

j=1: p[2][1] = min(p[2][1], p[2][2] + p[2][1]) = min(7, 12 + 7) = 7
j=2: p[2][2] = min(p[2][2], p[2][2] + p[2][2]) = min(12, 12 + 12) = 12
j=3: p[2][3] = min(p[2][3], p[2][2] + p[2][3]) = min(1e7, 12 + 1e7) = 1e7
j=4: p[2][4] = min(p[2][4], p[2][2] + p[2][4]) = min(2, 12 + 2) = 2
For i=3:

j=1: p[3][1] = min(p[3][1], p[3][2] + p[2][1]) = min(1e7, 3 + 7) = 10
j=2: p[3][2] = min(p[3][2], p[3][2] + p[2][2]) = min(3, 3 + 12) = 3
j=3: p[3][3] = min(p[3][3], p[3][2] + p[2][3]) = min(1e7, 3 + 1e7) = 1e7
j=4: p[3][4] = min(p[3][4], p[3][2] + p[2][4]) = min(1e7, 3 + 2) = 5
For i=4:

j=1: p[4][1] = min(p[4][1], p[4][2] + p[2][1]) = min(4, 9 + 7) = 4
j=2: p[4][2] = min(p[4][2], p[4][2] + p[2][2]) = min(9, 9 + 12) = 9
j=3: p[4][3] = min(p[4][3], p[4][2] + p[2][3]) = min(1, 9 + 1e7) = 1
j=4: p[4][4] = min(p[4][4], p[4][2] + p[2][4]) = min(1e7, 9 + 2) = 11

Matrix after w=2:

  7   5   1e7   7
  7   12  1e7   2
  10  3   1e7   5
  4   9   1    11
Iteration 3: w=3
Now we check if going through vertex 3 (w=3) provides shorter paths:

For i=1:

j=1: p[1][1] = min(p[1][1], p[1][3] + p[3][1]) = min(7, 1e7 + 10) = 7
j=2: p[1][2] = min(p[1][2], p[1][3] + p[3][2]) = min(5, 1e7 + 3) = 5
j=3: p[1][3] = min(p[1][3], p[1][3] + p[3][3]) = min(1e7, 1e7 + 1e7) = 1e7
j=4: p[1][4] = min(p[1][4], p[1][3] + p[3][4]) = min(7, 1e7 + 5) = 7
For i=2:

j=1: p[2][1] = min(p[2][1], p[2][3] + p[3][1]) = min(7, 1e7 + 10) = 7
j=2: p[2][2] = min(p[2][2], p[2][3] + p[3][2]) = min(12, 1e7 + 3) = 12
j=3: p[2][3] = min(p[2][3], p[2][3] + p[3][3]) = min(1e7, 1e7 + 1e7) = 1e7
j=4: p[2][4] = min(p[2][4], p[2][3] + p[3][4]) = min(2, 1e7 + 5) = 2
For i=3:

j=1: p[3][1] = min(p[3][1], p[3][3] + p[3][1]) = min(10, 1e7 + 10) = 10
j=2: p[3][2] = min(p[3][2], p[3][3] + p[3][2]) = min(3, 1e7 + 3) = 3
j=3: p[3][3] = min(p[3][3], p[3][3] + p[3][3]) = min(1e7, 1e7 + 1e7) = 1e7
j=4: p[3][4] = min(p[3][4], p[3][3] + p[3][4]) = min(5, 1e7 + 5) = 5
For i=4:

j=1: p[4][1] = min(p[4][1], p[4][3] + p[3][1]) = min(4, 1 + 10) = 4
j=2: p[4][2] = min(p[4][2], p[4][3] + p[3][2]) = min(9, 1 + 3) = 4
j=3: p[4][3] = min(p[4][3], p[4][3] + p[3][3]) = min(1, 1 + 1e7) = 1
j=4: p[4][4] = min(p[4][4], p[4][3] + p[3][4]) = min(11, 1 + 5) = 6
Matrix after w=3:

  7   5   8   7
  7   6   3   2
  9   3   6   5
  4   4   1   6

Iteration 3: w=4 (samely explaind)

Final Output:

7  5  8  7
6  6  3  2
9  3  6  5
4  4  1  6

*/
