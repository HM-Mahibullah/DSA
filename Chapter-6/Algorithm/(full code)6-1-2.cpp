/* Procedure 6.1: PUSH(STACK, TOP, MAXSTK, ITEM). This procedure pushes an ITEM onto a stack.
1. (Stack already filled?] If TOP = MAXSTK, then: Print: OVERFLOW, and Return.
2. Set TOP: TOP + 1. [Increases TOP by 1.]
3. Set STACK[TOP]:= ITEM. [Inserts ITEM in new TOP position.]
4. Return. */
#include<iostream>
#include<stack>
using namespace std;
void STACK_PUSH(int n)
{
    int element;
 stack<int>stk;
for (int i = 0; i <n; i++)
{
cin>>element;
stk.push(element);
}
cout<<"Elements in the stack: ";
while (!stk.empty())
{
  cout<<stk.top()<<" ";
  stk.pop();
}

}

int main()
{
    int n;
    cout<<"Enter number of elements in stack=";
    cin>>n;
 STACK_PUSH(n);   
}