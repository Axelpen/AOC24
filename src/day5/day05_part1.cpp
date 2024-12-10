#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
typedef long long ll;

using namespace std;

bool CorrectOrder(const vector<int>& input, const vector<pair<int, int>>& rules) {
    unordered_map<int, int> position;
    for (size_t i = 0; i < input.size(); ++i) {
        position[input[i]] = i;
    }

    for (const auto& rule : rules) {
        int x = rule.first, y = rule.second;
        if (position.count(x) && position.count(y)) {
            if (position[x] > position[y]) {
                return false; 
            }
        }
    }
    return true;
}

int main() {
    ifstream f("input.txt");   
    ifstream f2("input2.txt"); 
    vector<pair<int, int>> rules;

    char trash;
    int L, R;

    while (f >> L >> trash >> R) {
        rules.PB(MP(L, R));
    }

    string line;
    int sumOfMiddles = 0;

    while (getline(f2, line)) {
        stringstream ss(line);
        vector<int> input;
        int num;

        while (ss >> num) {
            input.PB(num);
        }

        if (CorrectOrder(input, rules)) {
            int middleIndex = input.size() / 2;
            sumOfMiddles += input[middleIndex];
        }
    }
    cout << sumOfMiddles << endl;
    return 0;
}
