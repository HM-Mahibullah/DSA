/*
Algorithın 6.4: POLISH(Q, P)
Suppose Q is an arithmetic expression written in infix notation. This algorithm finds the equivalent postfix expression P.
1. Push "(" onto STACK, and add ")" to the end of Q.
2. Scan Q from left to right and repeat Steps 3 to 6 for each element of Q until
the STACK is empty:
3. If an operand is encountered. a. to P.
4. If a left parenthesis is encountered, push it onto STACK.
5. If an operator is encountered, then:
(a) Repeatedly pop from STACK and add to P each operator (on the top of STACK) which has the same precedence as or higher precedence than.
(b) Add to STACK.
[End of If structure.)
6. If a right parenthesis is encountered, then:
(a) Repeatedly pop from STACK and add to P each operator (on
the top of STACK) until a left parenthesis is encountered.
(b) Remove the left parenthesis. [Do not add the left parenthesis to P.]
[End of If structure.] [End of Step 2 loop.]
7. Exit.
 */

#include <bits/stdc++.h>
using namespace std;

// Function to define precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^') // Exponentiation operator
        return 3;
    return 0;
}

// Function to perform the infix to postfix conversion
string infixToPostfix(string Q)
{
    stack<char> STACK;
    string P;
    string extendedQ = Q + ')'; // Add ")" to the end of Q
    STACK.push('(');            // Push "(" onto STACK

    for (char ch : extendedQ)
    {
        if (isdigit(ch) || isalpha(ch))
        { // isalpha(ch) is used to identify operands that are alphabetic variables, such as A, B, C, etc.
            P += ch;
        }
        else if (ch == '(')
        { // If '(', push to STACK
            STACK.push(ch);
        }
        else if (ch == ')')
        { // If ')', pop until '('
            while (!STACK.empty() && STACK.top() != '(')
            {
                P += STACK.top();
                STACK.pop();
            }
            STACK.pop(); // Remove the left parenthesis
        }
        else
        { // If an operator is encountered
            // Handle right-associativity for '^'
            while (!STACK.empty() && precedence(STACK.top()) > precedence(ch))
            {
                P += STACK.top();
                STACK.pop();
            }
            STACK.push(ch);
        }
    }

    return P;
}

int main()
{
    string Q;
    cout << "Enter an infix expression: ";
    getline(cin, Q);

    string postfix = infixToPostfix(Q);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

/*
               //First run//

Enter an infix expression: (A+B)*(C-D)
Postfix expression: AB+CD-*

                //second run

Enter an infix expression: A+(B*C-(D/E^F)*G)*H
Postfix expression: ABC*DEF^/G*-H*+

*/

/*
Example Walkthrough: A+(B*C-(D/E^F)*G)*H
•	Input: A+(B*C-(D/E^F)*G)*H
•	Output: ABC*DEF^/G*-H*+
Step-by-Step Conversion:
1.	Push: ( onto the stack.
2.	Process A: Add A to P.
3.	Process +: Push + onto the stack.
4.	Process (: Push ( onto the stack.
5.	Process B: Add B to P.
6.	Process *: Push * onto the stack.
7.	Process C: Add C to P.
8.	Process -: Pop * (higher precedence) and add to P. Then push - onto the stack.
9.	Process (: Push ( onto the stack.
10.	Process D: Add D to P.
11.	Process /: Push / onto the stack.
12.	Process E: Add E to P.
13.	Process ^: Push ^ onto the stack (highest precedence).
14.	Process F: Add F to P.
15.	Process ):
o	Pop ^ and add to P.
o	Pop / and add to P.
o	Pop ( and discard.
16.	Process *: Pop - (equal precedence) and add to P. Then push * onto the stack.
17.	Process G: Add G to P.
18.	Process ):
o	Pop * and add to P.
o	Pop ( and discard.
19.	Process *: Push * onto the stack.
20.	Process H: Add H to P.
21.	Process ) (added by the algorithm):
o	Pop * and add to P.
o	Pop + and add to P.
o	Pop ( and discard.
Final Postfix Expression: ABC*DEF^/G*-H*+

 */