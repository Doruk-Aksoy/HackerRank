#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        bool stop = false;
        string s;
        cin >> s;
        for(int j = 1, k = s.length() - 1; !stop && k > j; ++j, --k) {
            if(abs(s[j] - s[j - 1]) != abs(s[k] - s[k - 1])) {
               cout << "Not Funny\n";
                stop = true;
            }
        }
        if(!stop)
            cout << "Funny\n";
    }
    return 0;
}
