#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <bitset> // Very useful for this problem, converts a given string or int to an array of bits
using namespace std;

#define MAXLEN 501

int main() {
	int n, m;
	cin >> n >> m;
	string s;
    vector<bitset<MAXLEN> > v;
	for (int i = 0; i < n; i++) {
		cin >> s;
		bitset<MAXLEN> bit(s);
		v.push_back(bit);
	}

	int pick = 0, count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			bitset<MAXLEN> t = v[i] | v[j]; // find suitable person with OR
			if (t.count() > pick) {
                pick = t.count(); // count the bits
                count = 1;
            }
			else 
            if (t.count() == pick) 
                count++;
		}
	}
	cout << pick << endl;
	cout << count;
	return 0;
}
