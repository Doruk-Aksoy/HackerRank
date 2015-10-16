#include <vector>
#include <map>
#include <iostream>
using namespace std;

typedef long long unsigned int LLU;

// hash function taken from here: http://stackoverflow.com/questions/20511347/a-good-hash-function-for-a-vector -- which is the one used in boost for hash_combine
LLU hash_combine(vector<int> const& vec) {
    LLU seed = 0;
    for(auto& i : vec)
        seed ^= i + 0x9e3779b9 + (seed << 8) + (seed >> 2);
    return seed;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        string s;
        map <LLU , int> M;
        int res = 0;
        cin >> s;

        for(int j = 0; j < s.length(); ++j) {
            vector<int> freq(26, 0);
            for(int k = j; k < s.length(); ++k) {
                ++freq[s[k] - 'a']; // for each letter, increase their frequency
                ++M[hash_combine(freq)]; // for each unique vector I get, I get a unique substring, for each substring I get, I contribute n * (n - 1) / 2 for their size. Reason => nCr n 2.
            }
        }

        for(auto it = M.begin(); it != M.end(); ++it)
            res += (it->second * (it->second - 1)) >> 1;

        cout << res << "\n";
    }
    return 0;
}

