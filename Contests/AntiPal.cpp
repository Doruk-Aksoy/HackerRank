#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MOD 1000000007
typedef unsigned long long int LL;

// pow can be long long int if needed, for this problem, we don't care about it
// if pow < 0 return fast_pow(1/x, -pow);
LL fast_pow(LL x, LL pow) {
    if(pow == 0)
        return 1;
    if(pow == 1)
        return x;
    LL result = 1;
    while(pow > 0) {
        if(pow & 1)
            result = (result * x) % MOD;
        pow >>= 1;
        x = (x * x) % MOD;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        LL n, m;
        cin >> n >> m;

        LL allcases = m;
        if(n > 1)
            allcases = (allcases * (m - 1)) % MOD;
        if(n > 2)
            allcases = (allcases * (fast_pow(m-2, n-2))) % MOD;
        
        cout << allcases << endl;
    }
    return 0;
}
