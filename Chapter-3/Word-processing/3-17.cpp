/*
Page  62
Program 
3.17 Outline an algorithm which will interchange the kth and lth paragraphs in the short story S.
The algorithm reduces to two procedures:

Procedure A. 
Find the values of arrays BEG and END where
LINE[BEG[K]]   and   LINE[END[K]]
contain, respectively, the first and last lines of paragraph K of the story S.

Procedure B. 
Using the values of BEG[K] and END[K] and the values of BEG[L] 
and END[L], interchange the block of lines of paragraph K with the block of lines of paragraph L
*/

#include<bits/stdc++.h>
using namespace std;
void INTERCHANGE(string a[],int firstline,int secondline)
{
    string temporary;
    temporary=a[firstline];
    a[firstline]=a[secondline];
    a[secondline]=temporary;
}
int main()
{
    string s[100];
    int i,firstLine,secondline;
    cout<<"                     **This program for interghange line in a given story**            \n";
    cout<<endl;
    cout<<"Enter a sort story which has many lines\n";
    for(i=1;i<500;i++)
    {
        getline(cin,s[i]);\
        if(s[i].substr(0,5)=="$$$$$")
        break;
    }
 
    cout<<"Enter your interchage Number Line\n";
    cout<<endl;
    cout<<"Enter First Line  Number=";cin>>firstLine;
    cout<<"Enter Second Line  Number=";cin>>secondline;
    INTERCHANGE(s,firstLine,secondline);
    for(int k=1;k<=i;k++)
    {
        cout<<s[k];
        cout<<endl;
    }
}

/*
input:
      The Cow
      The Horse
      The Rat
output:
         The Rat
        The Horse
         The Cow
*/