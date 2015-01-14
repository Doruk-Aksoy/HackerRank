#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        long long int A[n];
        long long int sum[n]; // sum till ith index
        for(int j = 0; j < n; j++) {
            cin >> A[j];
            if(j)
                sum[j] = sum[j - 1] + A[j];
            else
                sum[j] = A[j];
        }
        if(n == 1)
            cout << "YES" << endl;
        else if (n == 2)
            cout << "NO" << endl;
        else {
            bool found = false;
            for(int j = 1; j < n; j++)
                if(sum[j - 1] == sum[n - 1] - sum[j]) { // sum till j-1 = sum of all - sum till that point
                cout << "YES" << endl;
                found |= true;
                break;
            }
            if(!found)
                cout << "NO" << endl;
        }
    }
    return 0;
}
