#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void multiply_by_scalar(vector<int> & a, int n) {
    if (!n) { a.clear(); return; }
    int carry = 0;
    for (int i = 0; i < a.size(); ++i) {
        a[i] = a[i] * n + carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
    for (; carry; carry /= 10)
        a.push_back(carry % 10);
}

void print(const vector<int> & a) {
    if (a.empty()) printf("0");
    else {
        for (int i = (int)a.size()-1; i >= 0; --i)
            printf("%d", a[i]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(1,1);
    for (int i = 2; i <= n; ++i)
        multiply_by_scalar(a, i);
    print(a);
    return 0;
}
