#include<bits/stdc++.h>
using namespace std;
int COUNT(string a[],int n,int countNumber)
{
    string key="the";
    string  biggin=" "+key;
    string mid=" "+key+" ";
    string end=key+" ";
    for(int i=0;i<n;i++)
    {
        if(a[i].substr(0,4)==biggin)
        {
            countNumber++;
        }
        /*
        else if(a[i].substr(a[i].length()-4,4)==end)
        {
            countNumber++;
        }
        */
       for(int k=0;k<a[i].length()-4;k++)//because of 4 is "END string" value.
       {
        if(a[i].substr(k,5)==mid)
        {
            countNumber++;
        }
       }
       if(a[i].substr(a[i].length()-4,4)==end)
        {
            countNumber++;
        }
    }
    return countNumber;
}
int main()
{
    string s[100];
    int i=0;
     cout << "Enter your string\n";
    while (i<500)
    {
      getline(cin,s[i]);
      if(s[i].substr(0,5)=="$$$$$")
      {
        break;
      }
      i++;
    }
    int num=COUNT(s,i,0);
    cout<<"Number of ' the ' = " << num << " Times\n";

    }
    /*

    //Not using fullstop(.) after 'the')

input:   the moon in the middle of the night the  
         $$$$$
output:Number of 'the' =4

// using fullstop(.) after 'the'

input:   the moon in the middle of the night the.  
         $$$$$
output:Number of 'the' =3

input:   the(one space)  
         $$$$$
output:Number of 'the' =1

input:   (one space) the  
         $$$$$
output:Number of 'the' =1

input:    the We do not count the in mother
          the We do not count the in mother
          the We do not count the in mother
          the We do not count the in mother
          $$$$$ 
output:Number of 'the' =8 
*/