/*  This Algorithm is same of 4.2 Algorithm
page 73
//Using Dlete function.
*/
#include<iostream>
#include<string>
using namespace std;

int NumberOfName;

void INSERT(string LA[], int N, int K, string ITEM)
{
    int J = N;
    while(J >= K)//for(int i=N;i>=k;i--)
    
    {
        LA[J+1] = LA[J];//0 base index
        //If NumberofName is=6 then velue is=$$$$$$(zero index)
        J--;
    }
    LA[K] = ITEM;
    NumberOfName++;
}

void DELETE(string LA[], int N, int K, string ITEM)
{
    ITEM = LA[K];
    for(int j = K; j <= N-1; j++)
    {
        LA[j] = LA[j+1];
    }
    NumberOfName--;
}

void PRINT(string Name[], int count)
{
    cout << "*********Printing Names ************\n";
    for(int i = 0; i < count; i++)
    {
        cout << i+1 << ". " << Name[i] << endl;
    }
}

int INPUTNAME(string Name[])
{
    cout << "Enter names \n";
    cout << "To end input Enter '$$$$$'\n";
    for(int i = 0; i < 100; i++)
    {
        cin >> Name[i];
        if(Name[i] == "$$$$$")
            return i;
    }
    return 0;
}

int main()
{
    string Name[100];
    NumberOfName = INPUTNAME(Name);//input a b c d e f $$$$$
    cout<<NumberOfName;// If NumberOfName value=6(index=0)
    PRINT(Name, NumberOfName);
    INSERT(Name, NumberOfName, 3-1, "Ford");
    //cout<<NumberOfName;// NumberOfName value=7
    PRINT(Name, NumberOfName);
    INSERT(Name, NumberOfName, 6-1, "Taylor");
    //cout<<NumberOfName;// NumberOfName value=8
    PRINT(Name, NumberOfName);
    INSERT(Name, NumberOfName, 6-1, "Taylor");
   // cout<<NumberOfName;// NumberOfName value=9
    PRINT(Name, NumberOfName);
    INSERT(Name, NumberOfName, NumberOfName, "ZAFAR");
   // cout<<NumberOfName;// NumberOfName value=10
    PRINT(Name, NumberOfName);
    DELETE(Name, NumberOfName, 2-1, "Davis");//2-1 means 0 base index.
    //cout<<NumberOfName;// NumberOfName value=9(Decreasing) after delete
    PRINT(Name, NumberOfName);
    return 0;
}
/*
Enter names
To end input Enter '$$$$$'
Brown 
Davis  
Johnson
Smith  
Wagner 
$$$$$  
*********Printing Name ************
1. Brown
2. Davis
3. Johnson
4. Smith
5. Wagner
*********Printing Name ************
1. Brown
2. Davis
3. Ford
4. Johnson
5. Smith
6. Wagner
*********Printing Name ************
1. Brown
2. Davis
3. Ford
4. Johnson
5. Smith
6. Taylor
7. Wagner
*********Printing Name ************
1. Brown
2. Davis
3. Ford
4. Johnson
5. Smith
6. Taylor
7. Taylor
8. Wagner
*********Printing Name ************
1. Brown
2. Ford
3. Johnson
4. Smith
5. Taylor
6. Taylor
7. Wagner
*/
