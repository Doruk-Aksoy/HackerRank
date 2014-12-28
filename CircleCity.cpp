#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

typedef unsigned long long int LL;

bool IsPerfSquare (LL n) {
    LL a = (LL) sqrt(double(n));
    return (a * a == n || (a+1) * (a+1) == n);
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        LL r, k;
        cin >> r >> k;
        LL points = 0;
        for(LL j = 1; j <= r/j; j++) {
            if(IsPerfSquare(r - j*j))
                points++;
        }
        if(4*points <= k)
            cout << "possible\n";
        else
            cout << "impossible\n";
    }
    return 0;
}
