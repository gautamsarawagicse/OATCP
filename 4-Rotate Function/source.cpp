#include <bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int>& A) {
        if (A.empty())
            return 0;

        int sum = 0, F0 = 0, maxVal = INT_MIN;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            F0 += i * A[i];
        }

        vector<int> dp(A.size());
        dp[0] = F0;
        maxVal = dp[0];

        for (int i = 1; i < A.size(); i++) {
            dp[i] = dp[i - 1] + sum - A.size() * A[A.size() - i];
            maxVal = max(maxVal, dp[i]);
        }

        return maxVal;
    }

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    vector<int> A;
    int num;
    while (inputFile >> num) {
        A.push_back(num);
    }
    inputFile.close();

    int result = maxRotateFunction(A);

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }
    outputFile << result << endl;
    outputFile.close();

    return 0;
}
