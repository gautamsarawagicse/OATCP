#include <bits/stdc++.h>
using namespace std;

vector<string> generateSubsequences(const string &str, string current, int index, int length) {
    vector<string> result;
    if (length == 0) {
        result.push_back(current);
        return result;
    }
    if (index == str.length()) {
        return result;
    }
    vector<string> withCurrent = generateSubsequences(str, current + str[index], index + 1, length - 1);
    result.insert(result.end(), withCurrent.begin(), withCurrent.end());
    vector<string> withoutCurrent = generateSubsequences(str, current, index + 1, length);
    result.insert(result.end(), withoutCurrent.begin(), withoutCurrent.end());
    return result;
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    int n;
    infile >> n;
    vector<vector<string>> allSubsequences;
    for (int i = 0; i < n; i++) {
        string inputString;
        infile >> inputString;
        vector<string> ans;
        set<string> uniqueSubsequences;
        for (int len = 1; len <= 4; ++len) {
            vector<string> subs = generateSubsequences(inputString, "", 0, len);
            for (int j = 0; j < subs.size(); j++) {
                if (uniqueSubsequences.find(subs[j]) == uniqueSubsequences.end()) {
                    ans.push_back(subs[j]);
                    uniqueSubsequences.insert(subs[j]);
                }
            }
        }
        allSubsequences.push_back(ans);
    }
    for (int i = 0; i < allSubsequences.size(); i++) {
        for (int j = 0; j < allSubsequences[i].size(); j++) {
            cout << allSubsequences[i][j] << endl;
            outfile << allSubsequences[i][j] << endl;
        }
        cout << endl;
        outfile << endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
