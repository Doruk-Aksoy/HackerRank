#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s;
    cin >> s;
    int wmax = sqrt(s.length());
    int hmax = ceil(sqrt(s.length()));
    int area = 65536;
    int w = 0, h = 0;
    for (int r = wmax; r <= hmax; r++)
        for (int c = r; c <= hmax; c++)
            if (r * c >= s.length() && r * c < area) {
                area = r * c;
                w = r;
                h = c;
            }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            if (j*h + i < s.length())
                cout << s[j*h + i]; 
        cout << " ";
    }
    return 0;
}
