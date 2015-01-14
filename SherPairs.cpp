#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef unsigned long long int LL;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        map<LL, LL> B; // holds the amount of distinct element matches like 1 - 1 on index 0, 2 - 2 on index 1 etc
        for(int j = 0; j < n; j++) {
            LL temp;
            cin >> temp;
            if(B[temp])
                B[temp]++;
            else
                B[temp] = 1;
        }
        LL sum = 0;
        for(map<LL, LL>::iterator it = B.begin(); it != B.end(); it++) {
//            cout << it->first << " " << it->second << endl;
            if(it->second > 1)
                sum += it->second * (it->second - 1);
        }
            
        cout << sum << endl;
    }
    return 0;
}
