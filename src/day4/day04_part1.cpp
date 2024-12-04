#include <bits/stdc++.h>
#include <regex>
#define PB push_back
#define MP make_pair
typedef long long ll;

using namespace std;

vector<pair<int, int>> directions = {
    {-1, -1}, {-1, 0}, {-1, 1},
    { 0, -1},          { 0, 1},
    { 1, -1}, { 1, 0}, { 1, 1}
};

bool hasXMAS(vector<vector<char>>& grid, int i, int j, pair<int, int> d) {
    string target = "XMAS";
    int n = grid.size();
    int m = grid[0].size();
    int dx = d.first, dy = d.second;
    
    for (int k = 0; k < target.size(); k++) {
        int ii = i + k * dx;
        int jj = j + k * dy;
        if (ii < 0 || ii >= n || jj < 0 || jj >= m || grid[ii][jj] != target[k]) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream f("input.txt");
    vector<vector<char>> inputs;
    string input;

    while (getline(f, input)) {
        vector<char> charLine(input.begin(), input.end());
        inputs.PB(charLine);
    }

    int n = inputs.size();
    int m = inputs[0].size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (auto d : directions) {
                if (hasXMAS(inputs, i, j, d)) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}
