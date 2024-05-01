#include <bits/stdc++.h>
using namespace std;

struct Graph {
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> indeg, outdeg;
    vector<int> order;

    void buildGraph(const vector<vector<int>>& pairs) {
        for (const auto& edge : pairs) {
            int start = edge[0], end = edge[1];
            adj[start].push_back(end);
            outdeg[start]++;
            indeg[end]++;
        }
    }

    void dfs(int i) {
        while (!adj[i].empty()) {
            int j = adj[i].back();
            adj[i].pop_back();
            dfs(j);
        }
        order.push_back(i);
    }

    vector<vector<int>> validArrangement(const vector<vector<int>>& pairs) {
        int e = pairs.size();
        buildGraph(pairs);
        int startNode = outdeg.begin()->first;
        for (auto it = outdeg.begin(); it != outdeg.end(); ++it) {
            int v = it->first;
            int deg = it->second;
            if (deg == indeg[v] + 1) {
                startNode = v;
                break;
            }
        }

        dfs(startNode);

        vector<vector<int>> ans;
        ans.reserve(e);

        for (int i = order.size() - 2; i >= 0; i--)
            ans.push_back({order[i + 1], order[i]});

        return ans;
    }
};

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int n;
    inputFile >> n;

    vector<vector<int>> pairs;
    for (int i = 0; i < n; i++) {
        int a, b;
        inputFile >> a >> b;
        pairs.push_back({a, b});
    }

    Graph graph;
    vector<vector<int>> res = graph.validArrangement(pairs);

    if (res.size() != pairs.size()) {
        outputFile << "No valid arrangement possible" << endl;
        return 0;
    }

    outputFile << "Valid arrangement:" << endl;
    for (const auto& pair : res) {
        outputFile << pair[0] << " " << pair[1] << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
