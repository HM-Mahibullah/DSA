/*
Page  54
Algorithm 3.3: (Pattern Matching) P and T are strings with lengths R and S,
respectively, and are stored as arrays with one character per element. This
algorithm finds the INDEX of P in T.

1. [Initialize.] Set K := 1 and MAX : = S − R + 1.
2.  Repeat Steps 3 to 5 while K ≤ MAX:
3.    Repeat for L = 1 to R: [Tests each character of P.]
            If P[L] ≠ T[K + L − 1], then: Go to Step 5.
        [End of inner loop.]
4.    [Success.] Set INDEX = K, and Exit.
5.    Set K := K + 1.
[End of Step 2 outer loop.]
6. [Failure.] Set INDEX = 0.
7. Exit.
*/
#include <bits/stdc++.h>
using namespace std;
// int j;     //using global variable
int main()
{
    string string, subString;
    cout << "Enter main string=";
    cin >> string;
    cout << "Enter the checking string=";
    cin >> subString;
    int stringLength = string.length();
    int subStringLength = subString.length();
    int max = stringLength - subStringLength + 1;
    int loopCounter = 0, index = -1;
    for (int i = 0; i < max; i++)
    {
        int j; // like as global variable
        for (j = 0; j < subStringLength; ++j)
        {
            loopCounter++;

            if (subString[j] != string[i + j])
            {
                break;
            }
        }
        if (j == subStringLength)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        cout << "Find the index which for matching is=" << index + 1 << endl;
        cout << "Total checking iteration loop=" << loopCounter;
    }
    else
    {
        cout << "   **Can't found index for pattern matching algorithm**" << endl;
        cout << "Total checking iteration loop=" << loopCounter;
    }
}
/*
input:ababababab
    abc
output:**Can't found index for pattern matching algorithm**"
        "Total checking iteration loop=16


input:aabbaabbaabb
      aaa
output:**Can't found index for pattern matching algorithm**"
        "Total checking iteration loop=19

input:abaabbaaabbbaaaabbbb
       aaa

output:Find the index which for matching is=7
        "Total checking iteration loop=13
        */

/*
                ** OR WRITE THIS CODE ANOTHER WAY **
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string T, P;
    size_t K, MAX, S, R,loopcounter=0, INDEX = 0;


    cout << "Enter your Text\n";
    getline(cin,T);
    cout << "Enter your keyword\n";
    cin >> P;
    S = T.length(); //length of Main string
    R = P.length(); // Length of sub string
    K = 0;
    MAX = S - R + 1;
    while(K <MAX)// while(K <=MAX) means loop execute equal to  max
    {
        for(int L = 0; L < R; L++)
        {
          loopcounter++;
            if(P[L] != T[K + L])
                goto Lable;
        }
        INDEX = K;
        break;
    Lable:
        K++;

    }
    cout << "Index = " << INDEX << endl;
    cout << "Loop Count = " << loopcounter<< endl;
    return 0;
}
*/
