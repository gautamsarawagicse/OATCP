#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    // Open input file
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Read input
    int n, m;
    inputFile >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        inputFile >> a[i];

    inputFile >> m;
    int b[m];
    for (int i = 0; i < m; i++)
        inputFile >> b[i];

    inputFile.close();

    // Sort arrays
    sort(a, a + n);
    sort(b, b + m);

    // Compute intersection count
    int c = 0;
    for (int i = 0, j = 0; i < n && j < m;) {
        if (a[i] - 1 > b[j])
            j++;
        else if (a[i] < b[j] - 1)
            i++;
        else
            c++, i++, j++;
    }

    // Write output
    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }
    outputFile << c << endl;
    outputFile.close();

    return 0;
}
