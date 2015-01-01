#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef unsigned long long int ULL;

int main() {
    ULL n, m;
    cin >> n;
    int x;
    map<int, int> N, M;
    for(ULL i = 0; i < n; i++) {
        cin >> x;
        if(N.find(x) != N.end())
            N[x]++;
        else
            N[x] = 1;
    }
    cin >> m;
    for(ULL i = 0; i < m; i++) {
        cin >> x;
        if(M.find(x) != M.end())
            M[x]++;
        else
            M[x] = 1;
    }
    int exit = 0;
    map<int, int> missing;
    for(map<int, int>::iterator it = N.begin(); it != N.end(); it++) {
        // counts don't match, map to missing
        if(missing.find(it->first) == missing.end() && M[it->first] != N[it->first])
            missing[it->first] = 1;
    }

    for(map<int, int>::iterator it = M.begin(); it != M.end(); it++) {
        // counts don't match, map to missing
        if(missing.find(it->first) == missing.end() && M[it->first] != N[it->first])
            missing[it->first] = 1;
    }
    
    for(map<int, int>::iterator it = missing.begin(); it != missing.end(); it++)
        cout << it->first << " ";
    
    return 0;
}
