/*
Page  62
Program
3.16 Discuss the changes that must be made in Procedure P3.15 
if one wants to count the number of occurrences of an aribitrary 
word W with length R.
*/

#include<bits/stdc++.h>
using namespace std;
int CHECK(string str[],int n,int count)
{
    string key;
    cout<<"Enter your key world\n";
    cin>>key;
    string biggin=key+" ",mid=" "+key+" ",end=" "+key;
    for(int i=0;i<n;i++)
    {
        if(str[i].substr(0,biggin.length())==biggin)
        {
            count++;
        }
      
        for(int k=0;k<str[i].length()-end.length();k++)
        {
            if(str[i].substr(k,mid.length())==mid)
            {
                count++;
            }
        }
        if(str[i].substr(str[i].length()-end.length(),end.length())==end)
        {
            count++;
        }

    }
    return count;

}
int main()
{
    string s[100];
    int i;
    cout<<"Enter your pragraph"<<endl;
    for(i=0;i<500;i++)
    {
        getline(cin,s[i]);
        if(s[i].substr(0,5)=="$$$$$")
        {
            break;
        }

    }
    int totalUserKeyNumber=CHECK(s,i,0);
    cout<<"USER KEY TOTAL NUMBERS IN A PRAGRAPH="<<totalUserKeyNumber<<endl;


}

/*
Output
Enter your string
the We do not count the in mother, and we assume no sentence ends with the word the
the We do not count the in mother, and we assume no sentence ends with the word the
the We do not count the in mother, and we assume no sentence ends with the word the
the We do not count the in mother, and we assume no sentence ends with the word the
$$$$$
Enter your key
we
Number of ' the ' = 4 Times
*/