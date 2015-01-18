#include <iostream>
using namespace std;
int maxXor(int l, int r) {
    int res = 0;
    for(int i = l; i <= r; i++) {
        for(int j = l; j <= r; j++) {
            if(res < (j ^ i))
                res = j ^ i;
        }
    }
    return res;
}

int main() {
    int res;
    int _l;
    cin >> _l;
    
    int _r;
    cin >> _r;
    
    res = maxXor(_l, _r);
    cout << res;
    
    return 0;
}

//////////////////////////////////////////////
//       ALTERNATIVE, FASTER SOLUTION       //
//////////////////////////////////////////////

#include <iostream>
using namespace std;

int maxXor(int l, int r) {
    int init = l ^ r;
    int res = 1;
    while (init) {
        res <<= 1;
        init >>= 1;
    }
    return res - 1;
}

int main() {
    int l, r;
    cin >> l >> r;
    cout << maxXor(l, r);
    return 0;
}
