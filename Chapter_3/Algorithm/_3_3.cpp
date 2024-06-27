#include<bits/stdc++.h>
using namespace std;
int main()
{
    string string,subString;
    cout<<"Enter main string=";
    cin>>string;
    cout<<"Enter the checking string=";
    cin>>subString;
    int stringLength=string.length();
    int subStringLength=subString.length();
    int max=stringLength-subStringLength+1;
    int loopCounter=0, index=-1;
    for(int i=0;i<max;i++)
    {
           int j;
        for( j=0;j<subStringLength;++j)
        {
            loopCounter++;
       
          if(subString[j] != string[i+j])  
          {
           break;
          }
       
        }
         if(j==subStringLength)
        {
         index=i;
         break;
        }
    }
    if(index!=-1)
cout<<"Find the index which for matching is="<<index+1<<endl;
   else
   {
   
    cout<<"Can't found index for pattern matching algorithm"<<endl;
     cout<<"Total checking iteration loop="<<loopCounter;
   }

}
