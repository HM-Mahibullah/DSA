/*
51 pages 
3.1 Algorithm

*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string T, P;
    cout << "Enter your Text\n";
    getline(cin,T);// Reads entire line including spaces
    cout << "Enter your keyword\n";
    cin >> P;
    size_t K = T.find(P);//size_t is an unsigned integer type, which means it cannot represent negative numbers.
    while(K != -1)
    {
        T.erase(K, P.length());
        K = T.find(P);
    }
    cout << T << endl;
    return 0;
}
//main end

/*
output
Enter your Text
ZAAABBBY
Enter your keyword
AB
output:
ZY
*/
