#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        long long int n;
        cin >> n;
        if(n < 3)
            cout << -1 << endl;
        else {
            if(!(n % 4))
                cout << 3 << endl;
            else
            if(!((n-1) % 2))
                cout << 2 << endl;
            else
                cout << 4 << endl;
        }
    }
    return 0;
}
