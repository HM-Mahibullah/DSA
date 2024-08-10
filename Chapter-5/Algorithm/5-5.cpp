#include<iostream>
using namespace std;
struct NODE
{
 int data;
 NODE* next;
};
NODE* Head=nullptr;
NODE* Avail=nullptr;
/* Head is a pointer to a NODE structure, but it currently doesn't point to any memory location. 
It indicates that the linked list is empty or that no memory has been allocated for the head node yet. */
NODE* GETNODE()
{

if(Avail!=nullptr)
{
NODE* node=Avail;
Avail=Avail->next;
return node;//return pointer type node address
}
else
{
return new NODE();
}

}
void PRINT()
{
    NODE* Temp=Head;
    while (Temp!=nullptr)
    {
    cout<<"Node element="<<Temp->data<<" and Node address="<<Temp->next<<endl;
    Temp=Temp->next;
    }
    
}
/* void FIRSTINSERT(int element)
{
NODE* insertnode=GETNODE();
insertnode->data=element;
insertnode->next=Head;
Head=insertnode;
} */
void FREENODE(NODE* Temp)
{
  Temp->next=Avail;
  Avail=Temp;
}
/* void DELETEFIRST()
{
   
    if(Head!=nullptr)
    {
      NODE* Temp=Head;
      Head=Head->next;
      FREENODE(Temp);
    }
} */
NODE* GETLOCNODE(int n)
{
NODE* Temp=Head;
int count=1;
while (Temp!=nullptr&& count<n)
{
Temp=Temp->next;
count++;
}
return (count==n)? Temp:nullptr;
}
void InsertElementInList(int element,NODE* Loc)
{
NODE* newNode=GETNODE();
newNode->data=element;
if(Loc==nullptr)
{
newNode->next=Head;
Head=newNode;
}
else
{
    newNode->next=Loc->next;
    Loc->next=newNode;
}
}
int main()
{
int x,n,element;
cout << "Enter creating node numbers=";
    cin >> n;
    if (n <= 0) {
        cout << "Number of nodes should be greater than 0." << endl;
        return 0;
    }
cout<<"Enter element node 1=";
cin>>x;
NODE *node1=new NODE();
node1->data=x;
node1->next=nullptr;
Head=node1;
NODE* currentNode=node1;//Point node1 which has data and next
for (int  i =2; i <=n; i++)
{
cout << "Input data elements in Node " << i << " =";
    cin >> x;
NODE* newNode=GETNODE();
newNode->data=x;
newNode->next=nullptr;
currentNode->next=newNode;
currentNode=newNode;
}
PRINT();
/* cout << "At beginning,Insert element at first node = ";
cin >> element;
FIRSTINSERT(element);
PRINT();
DELETEFIRST();
cout<<"After Deleting First Node"<<endl;
PRINT(); */
int nodePosition;
cout << "After which node do you want to insert the element? (e.g., 3 for after Node 3): ";
cin >> nodePosition;
NODE* Loc=GETLOCNODE(nodePosition);
if(Loc!=nullptr)
{
cout << "Enter element to insert after Node " << nodePosition << ": ";
cin >> element;
InsertElementInList(element,Loc);
}
else {
    cout << "Invalid node position." << endl;
    }

PRINT();  // Print the list after insertion
return 0;



}
/* Enter creating node numbers=2
Enter element node 1=6
Input data elements in Node 2 =9
Node element=6 and Node address=0x916f20
Node element=9 and Node address=0
After which node do you want to insert the element? (e.g., 3 for after Node 3): 2
Enter element to insert after Node 2: 5
Node element=6 and Node address=0x916f20
Node element=9 and Node address=0x916f30
Node element=5 and Node address=0 */