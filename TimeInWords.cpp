#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string numbers[31] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "half"};

int main() {
    cout.sync_with_stdio(false);
    int h, m;
    bool suffix;
    cin >> h >> m;
    if(!m)
        cout << numbers[h] << " o' clock";
    else {
        string minute = "";
        if(m == 1 || 60 - m == 1)
            minute = " minute";
        else if(m != 30 && m != 45)
            minute = " minutes";
        if(m == 15)
            cout << numbers[m] << " past " << numbers[h];
        else if (m <= 30)
            cout << numbers[m] << minute << " past " << numbers[h];
        else
            cout << numbers[60 - m] << minute << " to " << numbers[h + 1];
    }
    return 0;
}
