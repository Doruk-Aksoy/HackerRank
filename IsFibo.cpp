#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int GenerateFiboTable(map<long long int, long long int> &FiboTable, long long int num) {
    if(FiboTable.count(num))
      return 1;
    for(int i = 0;; i++) {
        if (i == 0 || i == 1) FiboTable.insert(map<int, int>::value_type(i, 1));
        if(i >= 2) {
            FiboTable.insert(map<int, int>::value_type(i,  FiboTable.find(i-1)->second + FiboTable.find(i-2)->second));
        }
        if(FiboTable.find(i)->second == num)
            return 1;
        if(FiboTable.find(i)->second > num)
            return 0;
    }
}

int main() {
    int n;
    cin >> n;
    map<long long int, long long int> FiboTable;
    for(int i = 0; i < n; i++) {
        long long int num;
        cin >> num;
        int res = GenerateFiboTable(FiboTable, num); // generate up to num
        if(res)
            cout << "IsFibo";
        else
            cout << "IsNotFibo";
        cout << endl;
    }
    return 0;
}
