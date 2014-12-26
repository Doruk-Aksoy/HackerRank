#include <iostream>
#include <fstream>
#include <map>
#include <deque>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
 
int countchildren (vector<int> *v , int* children , int offset) {
    int totalSize = 0;
    if(!v[offset].size())
        children[offset] = 1;
    else if(!children[offset]) {
        for(int i = 0; i < v[offset].size() ; i++)
            totalSize += countchildren(v, children, v[offset][i]);
    }
    children[offset] = totalSize + 1;
    return children[offset];
}
 
int main() {
    int N, M;
    int res = 0;
    cin >> N >> M;
    int children[N];
    memset(children, 0, sizeof(children));
    vector<int> temp[N]; // convert to an array of values
 
    for(int i = 0; i < M ; i++) {
        int e1, e2;
        cin >> e1 >> e2;
        e1--; e2--;
        temp[e2].push_back(e1);
    }
    
    countchildren(temp, children, 0);
    for(int i = 1; i < N; i++) {
        if(!((children[i]) % 2))
            res++;
    }
 
    cout << res << endl;
    return 0;
}
