#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long int LL;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        LL N, M;
        cin >> N >> M;
        LL terms = N / M;
        LL sum = terms * ((M - 1) * M) / 2;
        if(!(N % M)) // divisible
            cout << sum << endl;
        else {
            terms = N % M;
            sum += (terms + 1) * terms / 2;
            cout << sum << endl;
        }
    }
    return 0;
}
