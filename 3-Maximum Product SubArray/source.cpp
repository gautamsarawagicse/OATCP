 #include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;

    int currentMax = nums[0];
    int currentMin = nums[0];
    int globalMax = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        int oldCurrentMax = currentMax;
        currentMax = max({nums[i], currentMax * nums[i], currentMin * nums[i]});
        globalMax = max(currentMax, globalMax);
        currentMin = min({nums[i], currentMin * nums[i], oldCurrentMax * nums[i]});
    }

    return globalMax;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    vector<int> nums;
    int num;
    while (inputFile >> num) {
        nums.push_back(num);
    }
    inputFile.close();

    int result = maxProduct(nums);

    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }
    outputFile << result << endl;
    outputFile.close();

    return 0;
}
