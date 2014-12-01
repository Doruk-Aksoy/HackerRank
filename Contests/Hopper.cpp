#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long int> height;
    height.resize(n+1);
    height[0] = 0; // base case
    long long int guess = 0;
    for(int i = 1; i < n+1; i++) {
        cin >> height[i];
        if(height[i] > guess)
            guess = height[i];
    }

    int exit = 0, goup = 0;
    long long int borderguess = 0; // borderguess is the limit value I need to compare for decreasing
    long long int guesstry = 0;
    stack<long long int> guesslist;
    for(long long int energy = guess; !exit;) {
        if(!goup) {
            // Not zero, so we passed it. Try to reduce, with binary search.
            if(borderguess)
                energy = (guess+borderguess)/2;
            else
                energy = (guess)/2;
//            cout << "Reduce " << guess << ". New guess: " << energy << endl;
            guesslist.push(guess); // Keep this good guess
            guess = energy; // Update guess
        }
        goup = 0;
        for(int j = 1; !goup && j < n+1; j++) { // Try to pass
//            cout << "Try " << guess << endl;
            if(energy != height[j]) {
                if(energy > LLONG_MAX/2)
                    energy = energy - height[j];
                else
                    energy =  (energy << 1) - height[j];
            }
            else
                continue;
            if(energy < 0) { // this was wrong, we need a higher guess
//                cout << "Increase " << guess;
                guesstry = guesslist.top(); // the best possible guess
                if(!borderguess)
                    borderguess = guess;
                energy = (guess+guesstry)/2;
//                cout << ". New guess: " << energy << endl;
                if(energy == guess) {
                    exit = 1;
                    goup = 1;
                    break;
                }
                guess = energy;
                goup = 1;
            }
        }
    }
    
    cout << guesslist.top();
    return 0;
}
