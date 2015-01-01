#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long int LL;

int main() {
    int n;
    cin >> n;
    double sum = 0;
    for(int i = 0; i < n; i++) {
        LL x;
        cin >> x;
        sum = sum + x/2.0;
    }
    cout << setprecision(1) << fixed << sum;
    return 0;
}
