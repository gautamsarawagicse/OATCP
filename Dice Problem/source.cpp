#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int countWays(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1; 
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }
    
    return dp[n];
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    if (!infile.is_open() || !outfile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int t;
    infile >> t; 
    
    for (int i = 0; i < t; ++i) {
        int sum;
        infile >> sum; 
        outfile << countWays(sum) << endl; 
    }
    
    infile.close();
    outfile.close();
    
    return 0;
}
