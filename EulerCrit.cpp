#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int LL;

LL modpow(LL a, LL b, LL mod) {
    long long int x = 1, y = a;
    while(b > 0) {
        if(b & 1) {
            x = x * y;
            if(x > mod) x %= mod;
        }
        y = y * y;
        if(y > mod) y %= mod;
        b >>= 1;
    }
    return x;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        LL M, A;
        cin >> A >> M;
        if(!A)
            cout << "YES" << endl;
        else
        if(modpow(A, (M-1)/2, M) == M-1) // -1 equivalent of mod M is M - 1
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
