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

// Function to check associativity of operators
// For simplicity, assuming all operators except '^' are left-associative
bool isLeftAssociative(char op)
{
    return op != '^'; // '^' is right-associative
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
        {  // isalpha(ch) is used to identify operands that are alphabetic variables, such as A, B, C, etc.
            P += ch;
        }
        else if (ch == '(')
        { // If '(', push to STACK
            STACK.push(ch);
        }
        else if (ch == ')')
        { // If ')', pop and append to output until '(' is found
            while (!STACK.empty() && STACK.top() != '(')
            {
                P += STACK.top();
                STACK.pop();
            }
            STACK.pop(); // Remove the '(' from STACK
        }
        else
        { // If an operator is encountered
            // Handle precedence and associativity
            while (!STACK.empty() && STACK.top() != '(' &&
                   (precedence(STACK.top()) > precedence(ch) ||
                    (precedence(STACK.top()) == precedence(ch) && isLeftAssociative(ch))))
            {
                P += STACK.top();
                STACK.pop();
            }
            STACK.push(ch); // Push current operator to STACK
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
ABC*DEF^/G*-H*+

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


                         //SECOND RUN//

Enter an infix expression: A/(B+D)*E-F*(G+H/K) 
Postfix expression: ABD+/E*FGHK/+*-

                     //Third Run//

Expression: A*(B+D)/E-F*(G+H/K)
Operator Precedence:
1.	+, - have the lowest precedence (1)
2.	*, / have higher precedence (2)
3.	^ has the highest precedence (3)
4.	Parentheses () override precedence.
Stack Operations and Postfix Construction:
1.	Read A: It's an operand, so append it to the postfix expression P.
o	Postfix: A
o	Stack: (
2.	Read *: It's an operator. Push it onto the stack.
o	Postfix: A
o	Stack: (*
3.	Read (: Push it onto the stack to handle the subexpression.
o	Postfix: A
o	Stack: (*(
4.	Read B: It's an operand, so append it to the postfix expression.
o	Postfix: AB
o	Stack: (*(
5.	Read +: It's an operator. Push it onto the stack.
o	Postfix: AB
o	Stack: (*(+
6.	Read D: It's an operand, so append it to the postfix expression.
o	Postfix: ABD
o	Stack: (*(+
7.	Read ): Pop from the stack to the postfix expression until ( is encountered.
o	Pop + and append to postfix.
o	Postfix: ABD+
o	Stack: (*
8.	Read /: It's an operator. Compare precedence with the top of the stack (*). Since / and * have the same precedence, pop * because of 
    left-associative(বাম-সহযোগী বলতে বোঝায় যে যখন একই পূর্বের দুটি অপারেটর কোনও অভিব্যক্তিতে উপস্থিত হয়, তখন তাদের বাম থেকে ডানে মূল্যায়ন করা হয়। )and append it to postfix, then push /.
o	Postfix: ABD+*
o	Stack: (/
9.	Read E: It's an operand, so append it to the postfix expression.
o	Postfix: ABD+*E
o	Stack: (/
10.	Read -: It's an operator. Compare precedence with /. Since - has lower precedence, pop / and append it to postfix, then push -.
o	Postfix: ABD+*E/
o	Stack: (-
11.	Read F: It's an operand, so append it to the postfix expression.
o	Postfix: ABD+*E/F
o	Stack: (-
12.	Read *: It's an operator, so push it onto the stack.
o	Postfix: ABD+*E/F
o	Stack: (-(*
13.	Read (: Push it onto the stack to handle the subexpression.
o	Postfix: ABD+*E/F
o	Stack: (-(*(
14.	Read G: It's an operand, so append it to the postfix expression.
o	Postfix: ABD+*E/FG
o	Stack: (-(*(
15.	Read +: It's an operator. Push it onto the stack.
o	Postfix: ABD+*E/FG
o	Stack: (-(*(+
16.	Read H: It's an operand, so append it to the postfix expression.
o	Postfix: ABD+*E/FGH
o	Stack: (-(*(+
17.	Read /: It's an operator. Since / has higher precedence than +, push / onto the stack.
o	Postfix: ABD+*E/FGH
o	Stack: (-(*(+/
18.	Read K: It's an operand, so append it to the postfix expression.
o	Postfix: ABD+*E/FGHK
o	Stack: (-(*(+/
19.	Read ): Pop from the stack until ( is encountered.
o	Pop / and append to postfix.
o	Pop + and append to postfix.
o	Postfix: ABD+*E/FGHK/+
o	Stack: (-(*
20.	End of expression: Pop all remaining operators from the stack and append them to the postfix expression.
o	Pop * and append to postfix.
o	Pop - and append to postfix.
o	Postfix: ABD+*E/FGHK/+*-


 */
