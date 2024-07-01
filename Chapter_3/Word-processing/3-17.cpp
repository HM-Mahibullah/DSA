#include<iostream>
#include<string>
using namespace std;
void INTERCHANGE(string LINK[], int FirstLine, int secontLine)
{
    string a;
    a = LINK[FirstLine];
    LINK[FirstLine] = LINK[secontLine];
    LINK[secontLine] = a;


}
int main()
{
  string S[100];
    int  i, FirstLine, SecondLine;
    cout <<  "Enter your string\n";
    for(i=1 ; i < 100; i++)
    {
        getline(cin,S[i]);
        if(S[i].substr(0,5) == "$$$$$")
        break;
    }
    cout << "Enter line number to Interchange\n";
    cout << "First Line= " ; cin >> FirstLine ;
    cout << "Second Line= "; cin >> SecondLine;
    INTERCHANGE(S,FirstLine,SecondLine);
    for(int k = 1; k <= i ; k++)
    {
        cout << S[k] <<  endl;
    }
  return 0;
}