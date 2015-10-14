#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MIN(x,y) ((x) >= (y) ? (y) : (x))

int main() {
    cout.sync_with_stdio(false);
    
    int matrix[300][300];
    int M, N, R;
    cin >> M >> N >> R;
    
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> matrix[i][j];
    
    int rectangles = MIN(M, N) >> 1; // rectangle count is even of M or N / 2
    
    for (int i = 0; i < rectangles; ++i) {
            int m = M - 2 * i; // inner m
            int n = N - 2 * i; // inner n
            int cycles = (n + m - 2) << 1; // cycles are ( n + m  - 2 ) * 2
            int temp[1200], j;
            // top row
            for (j = 0; j < n; ++j)
                temp[j] = matrix[i][i + j];
            // right column
            for (j = 0; j < m; ++j)
                temp[n - 1 + j] = matrix[i + j][i + n - 1];
            // bottom row
            for (j = 0; j < n; ++j)
                temp[n - 1 + m - 1 + j] = matrix[m + i - 1][n - 1 + i - j];
            // left column
            for (j = 0; j < m - 1; ++j) // -1 is needed here for exclusion of the corner element
                temp[2*n + m - 3 + j] = matrix[i + m - 1 - j][i];
            // set top row
            for (j = 0; j < n; ++j)
                matrix[i][i + j] = temp[(j + R) % cycles];
            // set right column
            for (j = 0; j < m; ++j)
                matrix[i + j][i + n - 1] = temp[(n - 1 + j + R) % cycles];
            // set bottom row
            for (j = 0; j < n; ++j)
                matrix[m + i - 1][n - 1 + i - j] = temp[(n + m + j + R - 2) % cycles];
            // set left column
            for (j = 0; j < m - 1; ++j) // -1 is again, exclusion of corner element
                matrix[i + m - 1 - j][i] = temp[((n << 1) + m + j + R - 3) % cycles];
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j)
            cout << matrix[i][j] << ' ';
        cout << "\n";
    }
}
