#include <iostream>
#include <string>
using namespace std;

int main() {
    long long int p, q;
    bool found = false;
    cin >> p >> q;
    for(long long int i = p; i <= q; ++i) {
        string s = to_string(i * i);
        int a = 0, b = 0;
        if(s.length() > 1) {
            a = stoi(s.substr(0, s.length() >> 1));
            b = stoi(s.substr(s.length() >> 1));
        }
        else
            a = stoi(s);
        if(a + b == i) {
            cout << i << " ";
            found = true;
        }
    }
    if(!found)
        cout << "INVALID RANGE";
    return 0;
}
