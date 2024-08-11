//5.6 and 5.7 is same algorithm
/*
Page 132
Algorithm 5.7: INSERT(INFO, LINK, START, AVAIL, ITEM)
This algorithm inserts ITEM into a sorted linked list.

1. [Use Procedure 5.6 to find the location of the node preceding ITEM.]
Call FINDA(INFO, LINK, START, ITEM, LOC).

2. [Use Algorithm 5.5 to insert ITEM after the node with location LOC.]
Call INSLOC(INFO, LINK, START, AVAIL, LOC, ITEM).

3. Exit.
8. Return.
*/
#include<iostream>
using namespace std;
struct Node
{
int data;
Node* next;
};
int count=0;
Node* Head=nullptr;
Node* Avail=nullptr;
void PRINT()
{
 Node* Temp=Head;
 while (Temp!=nullptr)
 {
    cout<<"Node element="<<Temp->data
    <<" Next node address="<<Temp->next<<endl;
    Temp=Temp->next;
 }
}
Node* GetNode()
{
    if(Avail!=nullptr)
    {
        Node* node=Avail;
        Avail=Avail->next;
        return node;
    }
    else
    {
        return new Node();
    }
}
/* void FirstElement(int element)
{
    Node* insertnode=GetNode();
    insertnode->data=element;
    insertnode->next=Head;
    Head=insertnode;
} */
void InsertSorted(Node* &Head,int element)
{
  Node* newnode=GetNode();
  newnode->data=element;
  newnode->next=nullptr;
  if(Head==nullptr||element<= Head->data)
  {
    newnode->next=Head;
    Head=newnode;
  }
  else
  {
    Node* current=Head;
    while (current->next!=nullptr&& element> current->data)
    {
     current=current->next;
    }
    newnode->next=current->next;
    current->next=newnode;
    
  }
}

Node *SEARCH(int element)
{
Node *Temp=Head;
while (Temp!=NULL)//NULL is used to indicate the end of the list, meaning there are no more nodes to process.
{
    count++;

   if(Temp->data<element)
    {
       Temp= Temp->next;  
    }
    else if(Temp->data==element)
    {
        return Temp;//it returns Temp node that contains data and pointer
    }
    else{
        return NULL;
    }
}
}
int main()
{
    int n,x,element;
    cout<<"Enter total node numbers=";
    cin>>n;
    for (int  i=1;i<=n; i++)
    {
     cout << "Enter element for Node " << i << ": ";
    cin >> x;
    InsertSorted(Head,x);
    }
    cout<<endl;
  PRINT();
  cout<<endl;
   // Find the location of an element in the linked list which is sorted.
    cout << "Enter the element which point befor node element  to search: ";
    cin >> element;
    Node* result = SEARCH(element); // It receives pointer type Node which is Temp(data, address)
    if (result != nullptr) {
        cout << "Element " << element << " is found and address is = " << result << endl;
        cout  <<" Node number is="<<count<< endl;
    } else {
        cout << "Element " << element << " is not found in the list." << endl;
    }
cout<<endl;
cout<<"Enter insert element in node to maintain sorted list=";
cin>>element;
InsertSorted(Head,element);
PRINT();
}
/* Enter total node numbers=3
Enter element for Node 1: 6
Enter element for Node 2: 5
Enter element for Node 3: 4

Node element=4 Next node address=0x1076f20
Node element=5 Next node address=0x1076f10
Node element=6 Next node address=0

Enter the element which point befor node element  to search: 6
Element 6 is found and address is = 0x1076f10
 Node number is=3

Enter insert element in node to maintain sorted list=9
Node element=4 Next node address=0x1076f20
Node element=5 Next node address=0x1076f10
Node element=6 Next node address=0x1076f40
Node element=9 Next node address=0 */