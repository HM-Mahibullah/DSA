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
#include <iostream>
#include <string>
using namespace std;

int COUNT(string WORD[], int N, int countNumber)
{
    string key("the");
    string BEG(key + " ");
    string END(" " + key);
    string MID(" " + key + " ");

    for (int i = 0; i < N; i++)
    {
          // Check for "the " at the beginning of the string
        if (WORD[i].substr(0, 4) == BEG)
        {
            countNumber += 1;
        }
            // Check for " the " in the middle of the string
        for (int K = 1; K <= WORD[i].length()-END.length(); K++)//because of 4 is "END string" value.
        {
            /* 
            word[i] means= "the moon in the middle of the night the"
            */
            if (WORD[i].substr(K, 5) == MID)
            {
                countNumber += 1;
            }
        }
        // Check for " the" at the end of the string
        if (WORD[i].substr(WORD[i].length()-END.length(), 4) == END)
        {
            /*
            if input=the moon in the middle of the night the
            then
                 WORD[i].substr(WORD[i].length() - 4, 4) == END
                =WORD[i].substr(38-4, 4) == END
                =WORD[i].substr(34, 4) == END
                =WORD[i].substr(34, 4) == " the"
                
            */
            countNumber += 1;
        }
    }
    return countNumber;
}

int main()
{
    string S[100];
    int i = 0;
    cout << "Enter your string\n";
    while (i <500 )
    {
        getline(cin, S[i]);
        if (S[i].substr(0, 5) == "$$$$$")
            break;
        i++;
    }
    int NUM = COUNT(S, i, 0);
    cout << "Number of ' the ' = " << NUM << " Times\n";
    return 0;
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
