/*
Page 121
Program 
Procedure: COUNT(INFO, LINK, START, NUM)

1. Set NUM : = 0. [Initializes counter.]

2. Set PTR : = START. [Initializes pointer.]

3. Repeat Steps 4 and 5 while PTR ≠ NULL.

4.       Set NUM : = NUM + 1. [Increases NUM by 1.]

5.       Set PTR : = LINK[PTR]. [Updates pointer.]
[End of Step 3 loop.]

6. Return.
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
    int count=0;
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
     count++;
    }
cout << "Total number of elements in the linked list: " << count << endl;
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

/* Enter creating node numbers=5
Enter element in Node 1=5
Input data elements in Node 2 =6
Input data elements in Node 3 =5
Input data elements in Node 4 =5
Input data elements in Node 5 =8
Singly Linked List with traversing : 
Node data: 5, Node address: 0x8516c0, Next node address: 0x8516d0
Node data: 6, Node address: 0x8516d0, Next node address: 0x856f70
Node data: 5, Node address: 0x856f70, Next node address: 0x856f80
Node data: 5, Node address: 0x856f80, Next node address: 0x856f90
Node data: 8, Node address: 0x856f90, Next node address: 0
Total number of elements in the linked list: 5 */
