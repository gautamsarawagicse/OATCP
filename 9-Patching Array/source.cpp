#include <bits/stdc++.h>
using namespace std;


int minPatches(vector<int>& nums, int n) {
    long long int sum = 0, cnt = 0, i = 0;
    while(sum < n){
        if(i<nums.size() && nums[i]<=sum+1){
            sum += nums[i++];
        }else{
            cnt++;
            sum += sum+1;
        }
    }
    return cnt;
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    int n, num;
    infile >> n;
    vector<int> nums;
    while (infile >> num) {
        nums.push_back(num);
    }

    int result = minPatches(nums, n);
    outfile << result << endl;

    infile.close();
    outfile.close();
    return 0;
}