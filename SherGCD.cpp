#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int get_gcd (int a, int b) {// a < b. Euclidean Algorithm, improved (can also return 1 now)
    int r;
    while (r = b % a) {
        b = a;
        a = r;
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        for(int j = 1; j < n; j++) {
            int p;
            cin >> p;
            m = get_gcd(m, p);
        }
        cout << (m > 1 ? "NO" : "YES") << endl;
    }
    return 0;
}
