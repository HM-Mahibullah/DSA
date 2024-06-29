
/*
Page 61
Program 3.14
3.14 Write a procedure which counts the number NUM of paragraphs in the short story S.
Procedure P3.14: PAR(LINE, N, NUM)
1. Set NUM := 0 and BLANK := 
2. [Initialize counter.] Set K := 2.
3. Repeat Steps 4 and 5 while K ≤ N − 1.
4.        [Compare first 5 characters of each line with BLANK.]
If SUBSTRING(LINE[K], 1, 5) = BLANK, then:
Set NUM := NUM + 1
[End of If structure.)
5.        Set K := K + 1. [Increments counter.]
[End of Step 3 loop.]
6. Return
*/



#include<bits/stdc++.h>
using namespace std;
int pra(string line[],int i,int countBlankSpace)
{
    string blank=("     ");
    int k=2;
    while (k<i-1)//Using (i-1) because of (i) is coint $$$$$ sign. 
    {
       if(line[k].substr(0,5)==blank) 
       {
        countBlankSpace++;
      
       }
        k++;
    }
    return countBlankSpace;
}
int main()
{
    string s[100];
    int i;
    for(i=0;i<sizeof(s)/sizeof(s[0]);i++)
    {
        getline(cin,s[i]);
        if(s[i]=="$$$$$")
        {
            break;
        }
    }
   i=pra(s,i,0);
   cout<<"Containg space in pragraph="<<i;
  
}

/*
if 
   input : 
        This is the first paragraph.
                                     //containg five space
        This is the second paragraph.
                                       //containg five space and this section k=2
        This is the third paragraph.
        $$$$$
    output:Containg space in pragraph=1

*/