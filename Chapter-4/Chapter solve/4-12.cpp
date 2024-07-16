#include<bits/stdc++.h>
using namespace std;
int NONZEROELEMENT(int a[100][100],int size)
{
int count=0;
  for (int  i = 0; i < size; i++)
    {
    for (int  j = 0; j < size; j++)
    {
      if(a[i][j]!=0)
      {
        count++;
      }
    }
    
    }
    return count;

}
int SOMOFABOVEDIAGONAL(int a[][100],int size)//You can use a[100][100]
    {
    int sum=0;
      for(int i=1;i<size;i++)
      {
        for (int j = 0; j <i; j++)
        {
          sum+=a[j][i];
        }
        
      }
      return sum;
    }
    int PRODUCTOFTHEDIAGONAELOMENT(int a[][100],int size)//You not use a[][45] or a[][45777]
    {
        int product=0;
        for(int i=0;i<size;i++)
        {
            for(int j=i;j<=i;j++)
            {
                product+=a[i][j];
            }
        }
        return product;
    }   

int main()
{
    int size;
    cout<<"Enter element size=";
    cin>>size;
    int a[100][100];
    for (int  i = 0; i < size; i++)
    {
    for (int  j = 0; j < size; j++)
    {
        cin>>a[i][j];
    }
    
    }
    int valueofnonzeroelement=NONZEROELEMENT(a,size);
    cout<<"Total nonzero element="<<valueofnonzeroelement<<endl;
    int sum=SOMOFABOVEDIAGONAL(a,size);
    cout<<"Sum of above diagonal element ="<<sum<<endl;
    int product= PRODUCTOFTHEDIAGONAELOMENT(a,size);  
    cout<<"Product of sum on diagonal ="<<product; 
}
/*
                //First run//


Enter element size=4 
       
        9 0 4 6
        6 7 3 8
        2 8 4 5
        5 5 7 7
        
        Total nonzero element=15
        Sum of above diagonal element =26
        Product of sum on diagonal =27
    
*/