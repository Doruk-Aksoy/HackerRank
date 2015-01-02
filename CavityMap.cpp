#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cavity_check (vector<string> map, int i, int j) {
    if(map[i-1][j] == 'X' || map[i][j-1] == 'X' || map[i+1][j] == 'X' || map[i][j+1] == 'X')
        return false;
    if(map[i-1][j] < map[i][j] && map[i][j-1] < map[i][j] && map[i+1][j] < map[i][j] && map[i][j+1] < map[i][j])
        return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<string> map;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        map.push_back(s);
    }
        
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < n - 1; j++) {
            if(cavity_check(map, i, j))
                map[i][j] = 'X';
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << map[i][j];
        cout << endl;
    }    
    return 0;
}
