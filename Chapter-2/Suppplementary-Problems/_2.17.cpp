/*
page 39
Program
Find
(a) |3 + 8|, |3 − 8|, |−3 + 8|, |−3−8|;
(b) 7!, 8!, 14!/12!, 15!/16!,
*/

#include <bits/stdc++.h>
// for std::abs and std::tgamma
using namespace std;

// Function to compute absolute value
int absoluteValue(int x, int y) {
    return std::abs(x + y);
}

// Function template to compute factorial
template<typename T>
T fact(T x) {
    if (x <= 1)
        return 1;
    else
        return x * fact(x - 1);
}

// Function template to compute factorial division
template<typename T>
double factDc(T x, T y) {
    if (x < y) {
        return 1.0 / (factDc(y, x)); // Handle floating-point division correctly
    } else {
        return fact<T>(x) / fact<T>(y);
    }
}

int main() {
    // (a) |3 + 8|, |3 − 8|, |−3 + 8|, |−3−8|;
    cout << "|3 + 8| = " << absoluteValue(3, 8) << endl;
    cout << "|3 - 8| = " << absoluteValue(3, -8) << endl;
    cout << "|-3 + 8| = " << absoluteValue(-3, 8) << endl;
    cout << "|-3 - 8| = " << absoluteValue(-3, -8) << endl;

    // (b) 7!, 8!, 14!/12!, 15!/16!
    cout << "7! = " << fact<int>(7) << endl;
    cout << "8! = " << fact<int>(8) << endl;
    cout << "14! / 12! = " << factDc<int>(14, 12) << endl;
    cout << "15! / 16! = " << factDc<double>(15.0, 16.0) << endl; // Use double for more precision

    return 0;
}

//main end
///Program end

/*
output
int fact(int x)
{
    if(x == 0)
    {
        return (1);
    }
    else
    return(x*fact(x-1));
}

|3 + 8| = 4
|3 - 8| = 8
|3 + 8| = 8
|-3 -8| = 8
7! = 5040
8! = 40320
14! / 12! = 182
15! / 16! = 0.0625
*/