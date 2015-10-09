#include <iostream>
#include <cctype>
using namespace std;

int main() {
    int len, shift;
    cin >> len;
    char input[len];
    cin >> input >> shift;

    for(int i = 0; i < len; ++i) {
        if(isalpha(input[i])) {
            int cap = (isupper(input[i])) ? 'A' : 'a';
            input[i] = cap + (input[i] - cap + shift) % 26;
        }
    }
           
    cout << input;
    
    return 0;
}
