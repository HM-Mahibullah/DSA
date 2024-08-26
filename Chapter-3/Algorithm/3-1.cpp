/*
51 pages 
3.1 Algorithm

*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string T, P;
    cout << "Enter your Text\n";
    getline(cin,T);// Reads entire line including spaces
    cout << "Enter your keyword\n";
    cin >> P;
    size_t K = T.find(P);//size_t is an unsigned integer type, which means it cannot represent negative numbers.
    while(K != -1)
    {
        T.erase(K, P.length());
        K = T.find(P);
    }
    cout << T << endl;
    return 0;
}
//main end

/*
output
Enter your Text
ZAAABBBY
Enter your keyword
AB
output:
ZY
*/

/*
Example:
Let’s use an example to understand the process.
Input:
•	T: "This is a simple test. This test is simple."
•	P: "test"
Step-by-Step Execution:
1.	Initial State:
o	T = "This is a simple test. This test is simple."
o	P = "test"
2.	First Find:
o	K = T.find(P); → K = 17 (The first occurrence of "test" starts at index 17.)
3.	First Erase:
o	T.erase(17, P.length()); → T = "This is a simple . This test is simple." (The first "test" is removed.)
4.	Second Find:
o	K = T.find(P); → K = 24 (The next occurrence of "test" starts at index 24.)
5.	Second Erase:
o	T.erase(24, P.length()); → T = "This is a simple . This is simple." (The second "test" is removed.)
6.	No More Occurrences:
o	K = T.find(P); → K = string::npos (No more occurrences of "test" are found, so the loop ends.)
7.	Output:
o	The final output is T = "This is a simple . This is simple."

*/
