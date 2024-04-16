#include <bits/stdc++.h>
using namespace std;

int counting_subgrid(vector<vector<int>>& matrix) {
    int n = matrix.size(); 
    int m = matrix[0].size();

    vector<int> row(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            row[i] |= matrix[i][j] << (m - j);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int bits = __builtin_popcount(row[i] & row[j]);
            int count = bits * (bits - 1) / 2;
            ans += count;
        }
    }

    return ans;
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int result = counting_subgrid(matrix);

    cout << result << endl;

    return 0;
}