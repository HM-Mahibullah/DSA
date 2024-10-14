#include <bits/stdc++.h>
using namespace std;
string p;
string Q[100], S[100];

string mathchPrefix(string S, string C)
{
    string ck = S + C;
    int i;
    for (i = 0; i < ck.length(); i++)
    {

        if (ck.substr(i, ck.length() - i) == Q[ck.length() - i])
        {
            return Q[ck.length() - i];
            break;
        }
        /*
                 //input abababc//

    Example with Detailed Steps:
     S = " " and C = "a":
    ck = S + C = " " + "a" = "a"
    */
    }

    return " ";
}

void INITIAL()
{
    for (int i = 0; i <= p.length(); i++)
    {
        Q[i] = p.substr(0, i); // Q[0] = p.substr(0, 0) = "" (Empty string)
    }
}

int main()
{
    string T;
    int i, INDEX = -1; // Change INDEX initialization to -1 to indicate "not found"
    cout << "Enter your string\n";
    cin >> T;
    cout << "Enter your keyword\n";
    cin >> p;
    INITIAL();
    // because string base case is 0.
    S[0] = ""; // OR S[0] = Q[0];
    for (i = 0; i < T.length(); i++)
    {
        /*
                  //First function call//
        s[i+1]=Q[0];
        s[0+1]=Q[0];
        s[1]=Q[0];

                    //second funtion call//
        s[i]=s[i+1]
        s[1]=s[0+1]

        */
        S[i + 1] = mathchPrefix(S[i], T.substr(i, 1));
        if (S[i + 1] == p)
        {
            cout << "Value of i=" << i << endl;
            INDEX = i - p.length() + 1; // index count o based
            break;
        }
    }
    if (INDEX != -1)
    {
        cout << "Keyword found at index = " << INDEX << endl;
    }
    else
    {
        cout << "Keyword not found" << endl;
    }

    return 0;
}
/*
//first run
             input:Enter your string=  abababc
                  Enter your keyword=  abc


Step-by-Step Execution for Input T = "abababc" and p = "abc"
Initialize S[0] = "" because string base case is 0.

css
Copy code
Q[0] = ""
Q[1] = "a"
Q[2] = "ab"
Q[3] = "abc"
Iteration 1 (i = 0):

S[1] = matchPrefix(S[0], "a") = matchPrefix("", "a").
Concatenate S[0] + "a" = "a".
Check if "a" matches any prefix in Q. It matches Q[1], so S[1] = "a".
Iteration 2 (i = 1):

S[2] = matchPrefix(S[1], "b") = matchPrefix("a", "b").
Concatenate S[1] + "b" = "ab".
Check if "ab" matches any prefix in Q. It matches Q[2], so S[2] = "ab".
Iteration 3 (i = 2):

S[3] = matchPrefix(S[2], "a") = matchPrefix("ab", "a").
Concatenate S[2] + "a" = "aba".
Check if "aba" matches any prefix in Q. There is no match, so S[3] = "".
Iteration 4 (i = 3):

S[4] = matchPrefix(S[3], "b") = matchPrefix("", "b").
Concatenate S[3] + "b" = "b".
Check if "b" matches any prefix in Q. There is no match, so S[4] = "".
Iteration 5 (i = 4):

S[5] = matchPrefix(S[4], "a") = matchPrefix("", "a").
Concatenate S[4] + "a" = "a".
Check if "a" matches any prefix in Q. It matches Q[1], so S[5] = "a".
Iteration 6 (i = 5):

S[6] = matchPrefix(S[5], "b") = matchPrefix("a", "b").
Concatenate S[5] + "b" = "ab".
Check if "ab" matches any prefix in Q. It matches Q[2], so S[6] = "ab".
Iteration 7 (i = 6):

S[7] = matchPrefix(S[6], "c") = matchPrefix("ab", "c").
Concatenate S[6] + "c" = "abc".
Check if "abc" matches any prefix in Q. It matches Q[3], so S[7] = "abc".
Since S[7] equals the keyword "abc",

the code prints the current index value (i = 6).
The match is found at index i - p.length() + 1 = 6 - 3 + 1 = 4.

*/
