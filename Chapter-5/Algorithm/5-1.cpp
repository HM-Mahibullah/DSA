

/*
Page 120
Program 
Algorithm 5.1: (Traversing a Linked List) Let LIST be a linked list in memory. 
This algorithm traverses LIST, applying an operation PROCESS to each element 
of LIST. The variable PTR points to the node currently being processed.
1. Set PTR := START. [Initializes pointer PTR.]

2. Repeat Steps 3 and 4 while PTR ≠ NULL.

3.       Apply PROCESS to INFO[PTR].

4.       Set PTR := LINK[PTR]. [PTR now points to the next node.]
[End of Step 2 loop.]

5. Exit.
*/


/* a singly linked list:
 Youtube link:https://www.youtube.com/watch?v=nO4nuf0m0RM&list=PLgLCjVh3O6Sim5bsg0FJ3qGbvM6qtdxQe&index=3
  */
#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   Node* next;
};
Node* Head=nullptr;

void PRINT()
{
    if(Head==nullptr)
    {
        cout<<"Link is empty.";
        return;
    }
    cout << "Singly Linked List with traversing : \n";
    Node *Temp=Head;
    while (Temp!=nullptr)
    {
     cout << "Node data: " << Temp->data
        << ", Node address: " << Temp
        << ", Next node address: " << Temp->next << endl;
     Temp=Temp->next;
    }
}

int main()
{
int x,n;
Node *node1=new Node();
cout<<"Enter creating node numbers=";
cin>>n;
if (n <= 0) 
    {
        cout << "Number of nodes should be greater than 0." << endl;
     return 0;
    }
cout<<"Enter element in Node 1=";
cin>>x;
node1->data=x;
node1->next=nullptr;
Head=node1;
Node* currentNode = node1;  // Use currentNode to keep track of the last node
for (int i =2;i<=n;i++)
{
Node* newNode=new Node();
cout<<"Input data elements in Node "<<i<<" =";
cin>>x;
newNode->data=x;
newNode->next=nullptr;
currentNode->next = newNode;  // Link the current node to the new node
currentNode = newNode;  // Update currentNode to the new node
}
PRINT();//Function

}
/* 
        //First run//
Enter creating node numbers=0
Number of nodes should be greater than 0.


            //second run//

Enter creating node numbers=3
Enter element in Node 1=10
Input data elements in Node 2=20
Input data elements in Node 3=30
Singly Linked List: 
Node data: 10, Node address: 0x55a5b0134eb0, Next node address: 0x55a5b0134ed0
Node data: 20, Node address: 0x55a5b0134ed0, Next node address: 0x55a5b0134ef0
Node data: 30, Node address: 0x55a5b0134ef0, Next node address: 0 */



 /* 
 //A circular linked list:
 //Youtube link:https://www.youtube.com/watch?v=UqAaNyCPreM

 
#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   Node* next;
};
Node* Head=nullptr;

void PRINT()
{
    if(Head==nullptr)
    {
        cout<<"Link is empty.";
        return;
    }
    cout << "Circular Singly Linked List with traversing: ";
    Node *Temp=Head;
    do
    {
    cout << "Node data: " << Temp->data
        << ", Node address: " << Temp
        << ", Next node address: " << Temp->next << endl;
     Temp=Temp->next;
    } while (Temp!=Head);
    
}

int main()
{
int x,n;
Node *node1=new Node();
cout<<"Enter creating node numbers=";
cin>>n;
if (n <= 0) {
        cout << "Number of nodes should be greater than 0." << endl;
        
    }
cout<<"Enter element in Node 1=";
cin>>x;
node1->data=x;
node1->next=nullptr;
Head=node1;
Node* currentNode = node1;// Use currentNode to keep track of the last node
for (int i =2;i<=n;i++)
{
Node* newNode=new Node();
cout<<"Input data elements in Node "<<i<<" =";
cin>>x;
newNode->data=x;
newNode->next=nullptr;
currentNode->next = newNode;// Link the current node to the new node
currentNode = newNode;// Update currentNode to the new node
}
currentNode->next=Head;

PRINT();//Function

}

/* 
        //First run//
Enter creating node numbers=0
Number of nodes should be greater than 0.
List is empty.

            //second run//

Enter creating node numbers=3
Enter element in Node 1=10
Input data elements in Node 2=20
Input data elements in Node 3=30
Circular Singly Linked List: 
Node data: 10, Node address: 0x55a5b0134eb0, Next node address: 0x55a5b0134ed0
Node data: 20, Node address: 0x55a5b0134ed0, Next node address: 0x55a5b0134ef0
Node data: 30, Node address: 0x55a5b0134ef0, Next node address: 0 

*/

 
