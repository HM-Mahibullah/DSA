/*
Let W be the string ABCD. 
(a) Find the length of W. 
(b)find the nummber of substrings of W. 
(c)find the nummber of initial substrings of W.
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string W, R;
    int count=0,count1=0;
    cout << "Enter your String \n";
    cin >> W;
    //(a) Find the length of W. 
    cout << "(a)Length of String = " << W.length() << endl;
    //(b) List all substrings of W. 
    cout <<"(b) List all substrings of W.\n\n";
    for (int i = 0; i < W.length(); i++) {
        for (int k = 1; k <= W.length()-i; k++) {
            count++;
            R = W.substr(i, k);  // Extract substring starting at index i with length k
            cout << R << " ";
        
        }
        cout << "\n";
    }
    cout<<"Total substring from main string="<<count;
   cout<<"(c) List all the initial substrings of W.\n\n";
      for (int len = 1; len <= W.length(); len++) {
        count1++;
        R = W.substr(0, len);  // Extract substring from index 0 to len-1
        cout << R << endl;
    }
     cout<<"Total intital substring from main string="<<count1;
    //
    return 0;
}
/*
Enter your String 
XYZST
(a)Length of String = 5

(b)find the nummber of substrings of W.
X XY XYZ XYZS XYZST
Y YZ YZS YZST
Z ZS ZST
S ST
T
  Total substring from main string=15(5+4+3+2+1)
(c)find the nummber of initial substrings of W
XYZST
XYZS
XYZ
XY
X
  Total intital substring from main string=5
*/
