#include <iostream>
#include <algorithm>
using namespace std;

int pairs(long long int a[], int n, int k) {
    long long int ans = 0, j = n - 1;
    bool found = false;
    sort(a, a + n);
    for(long long int i = 0; i < n - 1; ++i) {
        while(abs(a[i] - a[j]) > k && j > 0 && !found) --j;
        while(abs(a[i] - a[j]) < k && j < n - 1 && found) ++j;
        if(abs(a[i] - a[j]) == k) {
            ++ans;
            found = true;
        }
        if(!found)
            j = n - 1;
    }
    
    return ans;
}

int main() {
    long long int n, k;
    cin >> n >> k;
    long long int a[n];
    for(long long int i = 0; i < n; ++i)
        cin >> a[i];
    cout << pairs(a, n, k);
    return 0;
}
