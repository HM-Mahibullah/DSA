/*
Page  61
Program
3-15
Write a procedure which counts the number NUM of times the word 
“the” appears in the short story S. (We do not count “the” in 
“mother,” and we assume no sentence ends with the word “the.”

************Algorithm**************
Procedure P3.15: COUNT(LINE, N, NUM)
1. Set WORD := 'THE' and NUM := 0.
2. [Prepare for the three cases.]
Set BEG := WORD//' ', END := ' '//WORD and
MID := ' ' //WORD// ''.
3. Repeat Steps 4 through 6 for K = 1 to N:
4.      [First case.] If SUBSTRING(LINE[K], 1, 4) = BEG, then:
Set NUM := NUM + 1.
5.      [Second case.] If SUBSTRING(LINE[K], 77, 4) = END, then:
Set NUM := NUM + 1.
6.      [General case.] Repeat for J = 2 to 76.
If SUBSTRING(LINE[K], J, 5) = MID, then:
      Set NUM := NUM + 1.
[End of If structure.]
[End of Step 6 loop.]
[End of Step 3 loop.]
7. Return
*/

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
