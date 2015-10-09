#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        ll b, w, bcost, wcost, conv, cost1, cost2, cost3;
        cin >> b >> w >> bcost >> wcost >> conv;
        cost1 = b * bcost + w * wcost;
        cost2 = b * bcost + w * (bcost + conv);
        cost3 = w * wcost + b * (wcost + conv);
        cout << min(cost1, min(cost2, cost3)) << "\n";
    }
    return 0;
}
