#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int totalHammingDistance(vector<ll>& nums) {
    int hammingdistance = 0;
    for (int bitpos = 0; bitpos < 32; bitpos++) {
        int setbits = 0;
        for (int i = 0; i < nums.size(); i++) {
            setbits += (nums[i] >> bitpos) & 1;
        }
        hammingdistance += setbits * (nums.size() - setbits);
    }
    return hammingdistance;
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt"); 

    vector<ll> nums;
    ll num;
     while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n')  // Break loop if Enter key is pressed
            break;
    }
    int result = totalHammingDistance(nums);
    cout << result << endl;

    return 0;
}