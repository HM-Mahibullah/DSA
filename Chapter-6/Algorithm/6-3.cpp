#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> s;
    istringstream partString(postfix); // Allows parsing the string by spaces
    string token;

    while (partString >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            // If token is an operand (a number)
            s.push(stoi(token)); // Convert token to integer and push onto stack
        } else {
            // Token is an operator
            int A = s.top();
            s.pop();
            int B = s.top();
            s.pop();

            switch (token[0]) {
                case '+':
                    s.push(B + A);// 'B' has large value after adding ,substrating,muliplying. 
                    break;
                case '-':
                    s.push(B - A);
                    break;
                case '*':
                    s.push(B * A);
                    break;
                case '/':
                    s.push(B / A);
                    break;
            }
        }
    }

    int value = s.top();
    s.pop();

    return value;
}

int main() {
    string String;
    cout << "Enter a postfix expression: ";
    getline(cin, String); // Input the postfix expression

/* 
                         //using getline cause//
A postfix expression often contains multiple operands and operators separated by spaces (e.g., 5 3 + 8 2 - *).
If you use cin >> Q, it would only read the first token (e.g., 5) and stop at the first space.
getline(cin, Q) reads the entire line, including spaces, so the full expression is captured as a single string. */

/*      
                //OR you can write to declare string//   
    string postFix = "5 6 2 + * 12 4 / -";
    int result = evaluatePostfix(postFix);

*/

    int result = evaluatePostfix(String); // Pass the postfix expression to the function
    cout << "The result is: " << result << endl;

    return 0;
}
/* 
               //first run
Enter a postfix expression: 5 6 2 + * 12 4 / -
The result is: 37 

              //second run
Enter a postfix expression: 5 3 + 8 2 - *
The result is: 48


*/


/* 
Applying the Statement to the Example Postfix Expression:
Postfix Expression: 5 6 2 + * 12 4 / -
Let's go through each token:
1.	Token "5":
o	isdigit(token[0]) checks if '5' is a digit. It is, so this condition is true.
o	The overall condition is true, so "5" is treated as a number.
2.	Token "6":
o	isdigit(token[0]) checks if '6' is a digit. It is, so this condition is true.
o	The overall condition is true, so "6" is treated as a number.
3.	Token "2":
o	isdigit(token[0]) checks if '2' is a digit. It is, so this condition is true.
o	The overall condition is true, so "2" is treated as a number.
4.	Token "+":
o	isdigit(token[0]) checks if '+' is a digit. It is not, so this condition is false.
o	Since token.size() is 1, token.size() > 1 is false, so the second part of the condition is not even checked.
o	The overall condition is false, so "+" is treated as an operator.
5.	Token "*":
o	isdigit(token[0]) checks if '*' is a digit. It is not, so this condition is false.
o	The second part of the condition is not checked since token.size() is 1.
o	The overall condition is false, so "*" is treated as an operator.
6.	Token "12":
o	isdigit(token[0]) checks if '1' is a digit. It is, so this condition is true.
o	The overall condition is true, so "12" is treated as a number.
7.	Token "4":
o	isdigit(token[0]) checks if '4' is a digit. It is, so this condition is true.
o	The overall condition is true, so "4" is treated as a number.
8.	Token "/":
o	isdigit(token[0]) checks if '/' is a digit. It is not, so this condition is false.
o	The second part of the condition is not checked since token.size() is 1.
o	The overall condition is false, so "/" is treated as an operator.
9.	Token "-":
o	isdigit(token[0]) checks if '-' is a digit. It is not, so this condition is false.
o	The second part of the condition is not checked since token.size() is 1.
o	The overall condition is false, so "-" is treated as an operator.

 */