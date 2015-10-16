#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char lookup[27] = "abcdefghijklmnopqrstuvwxyz";

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        string a, b;
        cin >> a >> b;
        bool found = false;
        for(int i = 0; !found && i < 27; ++i) {
            if(a.find(lookup[i]) != string::npos && b.find(lookup[i]) != string::npos)
                found = true;
        }
        found ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
