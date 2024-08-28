#include<bits/stdc++.h>
using namespace std;
string p;
string Q[100],S[100];

string F(string S, string C) {
    string ck = S + C;
   int i;
    for (i = 0; i < ck.length(); i++) 
    {
      
        if (ck.substr(i, ck.length() - i) == Q[ck.length() - i])
        {
            break;
        }
    /*
             //input abababc//

Example with Detailed Steps:
 S = " " and C = "a":
ck = S + C = " " + "a" = "a"
Let's go through the loop with this ck:
Iteration Details:
i = 0:
ck.substr(0, ck.length() - 0) = ck.substr(0, 1) = "a"
Q[1] = "a" ( Match)
 The loop breaks, and the function returns Q[1] = "a".

                    //second function call//
 S[i] = "a" and C = "b":
ck = S + C = "a" + "b" = "ab"
Let's go through the loop with this ck:
Iteration Details:
i = 0:
ck.substr(0, ck.length() - 0) = ck.substr(0, 2) = "ab"
Q[2] = "ab" ( Match)
 The loop breaks, and the function returns Q[2] = "ab".

                   //Third function call//
Consider S = "ab" and C = "a":
ck = S + C = "ab" + "a" = "aba"
Let's go through the loop with this ck:
Iteration Details:
i = 0:
ck.substr(0, ck.length() - 0) = ck.substr(0, 3) = "aba"
Q[3] = "abc" (No match)
i = 1:
ck.substr(1, ck.length() - 1) = ck.substr(1, 2) = "ba"
Q[2] = "ab" (No match)
i = 2:
ck.substr(2, ck.length() - 2) = ck.substr(2, 1) = "a"
Q[1] = "a" (Match found)
When i = 2, the substring "a" (from position 2 to the end of ck) matches the prefix Q[1] = "a". The loop breaks, and the function returns Q[1] = "a".

*/
    }
   
    return Q[ck.length() - i];
}

void INITIAL() {
    for (int i = 0; i <= p.length(); i++) {
        Q[i] = p.substr(0, i);//Q[0] = p.substr(0, 0) = "" (Empty string)
    }
}

int main() {
    string T;
    int i, INDEX = -1; // Change INDEX initialization to -1 to indicate "not found"
    cout << "Enter your string\n";
    cin >> T;
    cout << "Enter your keyword\n";
    cin >> p;
    INITIAL();
    S[0] = Q[0];
    for (i = 0; i < T.length(); i++) {
        /*
                  //First function call//
        s[i+1]=Q[0];
        s[0+1]=Q[0];
        s[1]=Q[0];

                    //secomd funtion call//
        s[i]=s[i+1]
        s[1]=s[0+1]
        
        */
        S[i + 1] = F(S[i], T.substr(i, 1));
        if (S[i + 1] == p) {
            cout<<i;
            INDEX = i-p.length()+1; //index count o based
            break;
        }
    }
    if (INDEX != -1) {
        cout << "Keyword found at index = " << INDEX << endl;
    } else {
        cout << "Keyword not found" << endl;
    }

    return 0;
}
/*
//first run
             input:Enter your string=  abababc
                  Enter your keyword=  abc
                
            output:Keyword found at index =4 
   
*/
