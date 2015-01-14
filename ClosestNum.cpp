#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long int A[n];
    for(int j = 0; j < n; j++)
        cin >> A[j];
    sort(A, A+n);
    long long int mindiff = LLONG_MAX;
    vector<pair<int, int> > pairs;
    for(int j = 0; j < n - 1; j++)
        if(mindiff > A[j+1] - A[j]) {
        pairs.clear(); // update the vector completely for new min
        mindiff = A[j+1] - A[j];
        pairs.push_back(make_pair(A[j], A[j+1]));
    }
    else
        if(mindiff == A[j+1] - A[j])
        pairs.push_back(make_pair(A[j], A[j+1]));
        for(int j = 0; j < pairs.size(); j++)
        cout << pairs[j].first << " " << pairs[j].second << " ";
    return 0;
}
