#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix( string& postfix) {
    stack<int> s;
    istringstream partString(postfix);//Allow every string read whthout space.
    string token;

    while (partString >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) //isdigit check true or false
        {
            s.push(stoi(token));// stoi is standerd library which convert character to digit.
        } else {
            // Token is an operator
            int A = s.top();
            s.pop();
            int B = s.top();
            s.pop();

            switch (token[0])
            {
                case '+':
                    s.push(B + A);
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
    // Example postfix expression
   // string postFix = "5 10 + 6 12 - *";
    string postFix = "5 6 2 + * 12 4 / -";//from book page 170

    int result = evaluatePostfix(postFix);
    cout << result << endl;

    return 0;
}
