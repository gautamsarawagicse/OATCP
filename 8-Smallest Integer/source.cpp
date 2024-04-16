#include<bits/stdc++.h>
using namespace std;

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    string s;
    int k;
    infile >> s >> k;

    stack<char> st;
    for(int i=0; i<s.size(); i++) {
        while(!st.empty() && k > 0 && st.top() > s[i]) {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }

    while(!st.empty() && k > 0) {
        st.pop();
        k--;
    }

    string ans;
    while(!st.empty()) {
        char c = st.top();
        ans += c;
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    bool one = true;
    string fans;
    for(int i=0; i<ans.size(); i++) {
        if(ans[i] != '0') {
            one = false;
        }
        if(one == false) {
            fans += ans[i];
        }
    }

    if(fans == "") outfile << "0\n";
    else outfile << fans << '\n';

    infile.close();
    outfile.close();
    return 0;
}