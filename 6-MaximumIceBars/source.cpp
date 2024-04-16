#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    vector<int> count(100001, 0);
    for (int cost : costs)
        count[cost]++;
    
    int bars = 0;
    for (int i = 0; i < count.size(); ++i) {
        if (coins >= i && count[i] > 0) {
            int numBought = min(count[i], coins / i);
            bars += numBought;
            coins -= numBought * i;
        }
    }
    return bars;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error opening files." << endl;
        return 1;
    }

    int n, coins;
    inputFile >> n >> coins;
    vector<int> costs(n);
    for (int i = 0; i < n; ++i)
        inputFile >> costs[i];
    
    int result = maxIceCream(costs, coins);
    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
