#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007

typedef unsigned long long int LL;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        LL n;
        cin >> n;
        cout << ((n % MOD) * (n % MOD)) % MOD << endl;
    }
    return 0;
}
