#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check_swap(int l, int r, vector<int>& v) {
    bool leftok = false, rightok = false;
    if(l) {
        if(v[l - 1] < v[r])
            leftok = true;
        else
            leftok = false;
    }
    else
        leftok = true;
    
    if(r + 1 < v.size()) {
        if(v[l] < v[r + 1])
            rightok = true;
        else
            rightok = false;
    }
    else
        rightok = true;
    
    for(int i = l + 1; i < r - 1; i++) {
    	if(v[i] > v[i + 1])
    		return false;
	}
    
    return leftok && rightok;
}

int check_reverse(int l, int r, vector<int>& v) {
    if(r + 1 < v.size()) {
        if(v[r + 1] > v[l]) {
            if(r - l == 2)
                return -1;
            return 1;
        }
        return 0;
    }
    
    if(r - l == 2) {
        if(v[l + 1] > v[r])
            return -1;
        return 1;
    }
    return 0;
}

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    
    bool canswap = false, canrev = false, second_interval = false, notpossible = false, defnotsorted = false;
    int badpos = 0, badpos2 = 0, badcount = 0;
    
    for(int i = 0; i < N; ++i) {
        cin >> v[i];
        if(i) {
            if(v[i] < v[i - 1]) { // not sorted position
                defnotsorted = true;
                if(second_interval)
                    notpossible = true;
                else {
                    if(badpos2) {
                        badpos2 = i;
                        if(badcount)
                            canswap = false;
                        else
                            canswap = true;
                    }
                    else {
                        badpos = i - 1;
                        badpos2 = i;
                        canswap = true;
                    }
                }
                ++badcount;
            }
            else {
                if(badpos2 && badcount > 1)
                    second_interval = true;
                badcount = 0;
            }
        }
    }
    
    if(!notpossible) {
        if(!defnotsorted)
            cout << "yes\n";
        else {
            if(canswap) {
                if(check_swap(badpos, badpos2, v))
                    cout << "yes\nswap " << badpos + 1 << " " << badpos2 + 1 << '\n';
                else
                    cout << "no\n";
            }
            else {
                int revres = check_reverse(badpos, badpos2, v);
                if(revres == 1)
                    cout << "yes\nreverse " << badpos + 1 << " " << badpos2 + 1 << '\n';
                else if(revres == -1)
                    cout << "yes\nswap " << badpos + 1 << " " << badpos2 + 1 << '\n';
                else
                    cout << "no\n";
            }
        }
    }
    else
        cout << "no\n";

    return 0;
}
