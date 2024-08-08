#include<iostream>
using namespace std;
struct NODE
{
    int data;
    NODE *next;
};
NODE* Head=NULL;
void PRINT()
{
    NODE* Temp=Head;
    while (Temp!=NULL)//NULL is used to represent a null pointer constant in both C and C++
    //nullptr is a keyword introduced in C++11 that represents a null pointer of any type.
    {
    cout<<"Node data="<<Temp->data
    <<",Node address="<<Temp
    <<",Next node address="<<Temp->next<<endl<<"\n";
     Temp=Temp->next;
    }
 
}
void FIRSTINSERT(int element)
{
NODE* insertnode=new NODE();// Allocate new node from AVAIL list
insertnode->data=element;// Copies new data into new node
insertnode->next=Head; // New node now points to original first node
Head=insertnode;// Changes Head so it points to the new node
}

int main()
{
int n,x,element;
cout<<"Enter creating node numbers=";
cin>>n;
if (n <= 0) 
    {
        cout << "Number of nodes should be greater than 0." << endl;
        return 0;
    }
cout<<"Enter element Node 1=";
cin>>x;
NODE* node1=new NODE();
node1->data=x;
node1->next=NULL;
Head=node1;
NODE *currentNode=node1;
for (int  i = 2; i <=n; i++)
{
cout<<"Input data elements in Node "<<i<<" =";
cin>>x;    
NODE* newNode=new NODE();//The new Node() part allocates memory and calls the constructor for the Node ().
newNode->data=x;
newNode->next=NULL;
currentNode->next=newNode;
currentNode=newNode;
}
PRINT();// Print the current list
cout<<"At beggining Creating a new node for insert element= ";
cin>>element;
FIRSTINSERT(element);
PRINT(); // Print the list again to see the new element at the beginning
return 0;



}
/* 
Enter creating node numbers=3
Enter element Node 1=6
Input data elements in Node 2 =5
Input data elements in Node 3 =9
Node data=6,Node address=0xfc6f10,Next node address=0xfc6f20

Node data=5,Node address=0xfc6f20,Next node address=0xfc6f30

Node data=9,Node address=0xfc6f30,Next node address=0

At beggining Creating a new node for insert element= 8
Node data=8,Node address=0xfc6f40,Next node address=0xfc6f10

Node data=6,Node address=0xfc6f10,Next node address=0xfc6f20

Node data=5,Node address=0xfc6f20,Next node address=0xfc6f30

Node data=9,Node address=0xfc6f30,Next node address=0 */