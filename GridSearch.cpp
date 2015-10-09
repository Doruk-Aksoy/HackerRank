#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void search_grid(string* grid, string* search, int gx, int gy, int sx, int sy) {
    int foundrow = 0, foundcol = 0; // save the found positions for matching substrings in grid
    string temp;
    
    for(int i = 0; i < gx - sx + 1; ++i) { // only look for this much as thats the total amount of substrings to fit
        for(int j = 0; j < gy - sy + 1; ++j) {
            temp = grid[i].substr(j, sy);
            if(!temp.compare(search[0])) { // found possible match?
                foundrow = i;
                foundcol = j;
            }
        }
    }
    
    string* finalgrid = new string[sx]; // final, reduced grid for matches
    for(int i = 0; i < sx; ++i){
        finalgrid[i] = grid[foundrow + i].substr(foundcol, sy); // copy matching portions
    }
    
    bool res = 1;
    for(int i = 0; i < sx; ++i)
        if(finalgrid[i].compare(search[i])) { // search only the matching portion
            res = false;
            break;
        }
    res ? cout << "YES\n" : cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        int x, y;
        cin >> x >> y;
        string* temp = new string[x];
        for(int j = 0; j < x; ++j) 
            cin >> temp[j];
        
        int row, col;
        cin >> row >> col;
        string* search = new string[row];
        for(int j = 0; j < row; ++j) 
            cin >> search[j];
        
        search_grid(temp, search, x, y, row, col);
    }
    return 0;
}
