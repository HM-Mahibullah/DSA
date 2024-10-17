/* Algorithm 5.2: SRCHSL(INFO, LINK, START, ITEM, LOC)
LIST is a Unsorted list in memory. This algorithm finds the location LOC of the node where ITEM first appears in LIST, or sets LOC = NULL.
1. Set PTR := START.
2. Repeat Step 3 while PTR ≠ NULL:
3. If ITEM <INFO[PTR], then:
   Set PTR := LINK[PTR]. [PTR now points to next node.] 
   Else if ITEM = INFO[PTR], then: Set LOC:= PTR, and Exit. [Search is successful.]
    Set LOC:= NULL
 5. Exit. 
 */

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;//Node *next is a pointer that stores the address of the next node in a linked structure
};
Node *Head=NULL;// ব্যাখ্যা নিচের কমেন্ট ১ এ

void PRINT()
{
    Node *Temp=Head;
    while (Temp!=NULL)
    {
     cout << "Node data: " << Temp->data
        << ", Node address: " << Temp  //Temp has own address.
        << ", Next node address: " << Temp->next << endl;
     Temp=Temp->next;
    }
    
}


Node *SEARCH(int element)
{
Node *Temp=Head;
while (Temp!=NULL)//NULL is used to indicate the end of the list, meaning there are no more [nodes to process].
{
    if(Temp->data==element)
    {
        return Temp;//it returns Temp node that contains data and pointer
    }
   Temp= Temp->next;
}
return NULL;

}
int main()
{
int x,n;
cout<<"Enter Creating Numbers=";
cin>>n;
cout<<"Enter  Node 1 element=";
cin>>x;
Node *node1=new Node();//new keyword initilize memory and Node() provides default constructor which means a copy of Node that contains [data and ponter].
  
node1->data=x;
node1->next=NULL;//"NULL" Not type-safe (just 0, which is an integer)	"nullptr" Type-safe any type  (just 0, which is an any type).
Head=node1;
Node *currentNode=node1;
for (int  i =2; i <=n; i++)
{
    cout<<"Enter Node "<<i<<"element=";
    cin>>x;
    Node *newnode=new Node();//new keyword initilize memory and Node() provides default constructor which means a copy of Node that contains data and ponter.
    //ব্যাখ্যা নিচের কমেন্ট ২ এ
    newnode->data=x;
    newnode->next=NULL;
    currentNode->next=newnode;
    currentNode=newnode;

}
PRINT();

//Find the location an elemnet in link list which is unsort.
int element;
cout<<"Enter the element for search=";
cin>>element;
Node* result=SEARCH(element);//It receives pointer type Node which is Temp(data,next)
if(result!=NULL)
{
    cout<<"Element "<<element<<" is  found and address is="<<result<<endl;
    cout<<"This node element is="<<result->data;
}
else
{
    cout<<"Element "<<element<<"is not find in the  list";
}



}

/* Enter Creating Numbers=3
Enter  Node 1 element=2
Enter Node 2element=2
Enter Node 3element=5
Node data: 2, Node address: 0x10c16c0, Next node address: 0x10c16d0
Node data: 2, Node address: 0x10c16d0, Next node address: 0x10c6f78
Node data: 5, Node address: 0x10c6f78, Next node address: 0 */


/*
1.   Node *Head = NULL; 
      Explained:
                Node *Head is a pointer of type Node*. It is designed to store the address of a Node object,it is just a pointer and does not contain any 
                data or next becaus it isn't pointing to any actual Node.

               ##প্রোগ্রাম ১.
               Node *Head = NULL;  // Head points to nothing, no data or next field exists
               ##প্রোগ্রাম ২.
               Node *Head = new Node();  // Now Head points to a new Node object
               Head->data = 5;           // The data field in the node now contains 5
               Head->next = NULL;        // The next pointer of this node points to nothing (end of the list)


২. Why Use *node1 (Pointer)?
Dynamic Memory Allocation:

When you use new Node(), you dynamically allocate memory for a new Node on the heap.
The new keyword returns the address of the newly created object. Since the address is what is returned, you need a pointer (Node *) to store it.
Node *node1 is a pointer that stores the address of the node created by new Node().
   *


*/
