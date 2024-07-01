#include <bits/stdc++.h>
using namespace std;


int main() //push elements integer type in stack
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
  //    for (; !a.empty(); a.pop())
      
    
    return 0;
}

//push element string type in stack

#include <bits/stdc++.h>
using namespace std;


int main()
{
  
    stack<string> a;
    a.push("Mahibullah");
    a.push("sharafat");
    a.push("Kaiyum");
    while(!a.empty())
    {
    cout<<"Top element:"<<a.top()<<endl;
    a.pop();
    }
      
    
    return 0;
}
