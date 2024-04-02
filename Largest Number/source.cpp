#include <bits/stdc++.h>
using namespace std;


string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int a, int b){
        string ab_ = (to_string(a) + to_string(b));
        string ba_ = (to_string(b) + to_string(a));

        return ab_ > ba_;
    });

    string ans = "";
    if(nums[0] == 0){
        return "0";
    }
    for(auto num : nums){
        ans += to_string(num);
    }
    return ans;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error opening files." << endl;
        return 1;
    }

    int n;
    inputFile >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        inputFile >> nums[i];
    
    string result = largestNumber(nums);
    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
