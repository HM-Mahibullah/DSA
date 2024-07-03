/*
Let W be the string ABCD. 
(a) Find the length of W. 
(b) List all substrings of W. 
(c) List all the initial substrings of W.
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string W, R;
    cout << "Enter your String \n";
    cin >> W;
    //(a) Find the length of W. 
    cout << "(a)Length of String = " << W.length() << endl;
    //(b) List all substrings of W. 
    cout <<"(b) List all substrings of W.\n\n";
    for (int i = 0; i < W.length(); i++) {
        for (int k = 1; k <= W.length()-i; k++) {
            R = W.substr(i, k);  // Extract substring starting at index i with length k
            cout << R << " ";
        }
        cout << "\n";
    }
   cout<<"(c) List all the initial substrings of W.\n\n";
      for (int len = 1; len <= W.length(); len++) {
        R = W.substr(0, len);  // Extract substring from index 0 to len-1
        cout << R << endl;
    }
    //
    return 0;
}
/*
Enter your String 
XYZST
(a)Length of String = 5

(b) List all substrings of W.
X XY XYZ XYZS XYZST
Y YZ YZS YZST
Z ZS ZST
S ST
T
(c)List all the initial substrings of W
XYZST
XYZS
XYZ
XY
X
*/