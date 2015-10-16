#include <cmath>
#include <map>
#include <iostream>
using namespace std;

int main() {
    string a, b;
    int res = 0;
    cin >> a >> b;
    map<char, int> M;
    for(int i = 0; i < a.length(); ++i)
        ++M[a[i]];
    for(int i = 0; i < b.length(); ++i)
        --M[b[i]];
    for(auto it = M.begin(); it != M.end(); ++it) {
        if(it->second != 0) // if it's 0, it means there's equality, otherwise delete
            res += abs(it->second);
    }
    cout << res;
    return 0;
}
