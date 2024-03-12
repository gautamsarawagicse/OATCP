#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int countPaths(vector<vector<char>>& grid) {
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    dp[0][0] = (grid[0][0] == '.') ? 1 : 0;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = (grid[i][0] == '.' && dp[i-1][0] != 0) ? 1 : 0;
        dp[0][i] = (grid[0][i] == '.' && dp[0][i-1] != 0) ? 1 : 0;
    }
    
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == '.') {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    
    return dp[n-1][n-1];
}

int main() {
    ifstream inFile("input.txt"); 
    ofstream outFile("output.txt"); 

    if (!inFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    int n;
    inFile >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inFile >> grid[i][j];
        }
    }

    int paths = countPaths(grid);

    outFile << paths << endl;

    inFile.close();
    outFile.close();

    return 0;
}
