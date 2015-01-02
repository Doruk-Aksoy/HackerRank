#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int LL;

LL get_gcd (LL a, LL b) { // a < b. Euclidean Algorithm, improved (can also return 1 now)
    int r;
    while (r = b % a) {
        b = a;
        a = r;
    }
    return a;
}

void circular_rotate (LL* A, LL n, LL k) {
    k %= n;
    if(k) {
        while(k < 0) // if negative (left shift) turn to positive (right shift)
            k += n;
        int d = get_gcd(n, k); // find the element position where a common repetition can occur
        for(LL i = 0; i < d; i++) {
            LL temp = A[i];
            // while the repetition goes on, keep swapping i, f(i) and f(f(i)) etc
            for(LL j = i - k + n; j != i; j = (j - k + n) % n)
                A[(j + k) % n] = A[j];
            A[(i + k) % n] = temp;
        }    
    }
}

int main() {
    LL n, k;
    int q;
    cin >> n >> k >> q;
    LL* A = new LL[n];
    for(LL i = 0; i < n; i++)
        cin >> A[i];
    circular_rotate(A, n, k);
    for(int i = 0; i < q; i++) {
        LL x;
        cin >> x;
        cout << A[x] << endl;
    }
    delete[] A;
    return 0;
}
