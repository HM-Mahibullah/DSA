#include <bits/stdc++.h>
using namespace std;


int main() //pesh element is stack
{
  
    stack<int> a;
    a.push(10);
    a.push(20);
    a.push(30);
    while(!a.empty())
    {
    cout<<"Top element:"<<a.top()<<endl;
    a.pop();
    }
      
    
    return 0;
}
