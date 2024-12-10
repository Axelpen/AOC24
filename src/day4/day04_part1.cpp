#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
typedef long long ll;

using namespace std;


int main() {
    ifstream f("input.txt");
    vector<string> grid;
    string line;

    while (getline(f, line)) {
        grid.PB(line);
    }

    int n = grid.size();
    int m = grid[0].size();
    string xmas = "XMAS";
    string reverse_xmas = "SAMX"; 
    int count = 0;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            if (j + 3 < m) {
                string horizontal = grid[i].substr(j, 4);
                if (horizontal == xmas || horizontal == reverse_xmas) {
                    count++;
                }
            }

            if (i + 3 < n) {
                string vertical = "";
                for (int k = 0; k < 4; k++) {
                    vertical += grid[i + k][j];
                }
                if (vertical == xmas || vertical == reverse_xmas) {
                    count++;
                }
            }

            if (i + 3 < n && j + 3 < m) {
                string diagonal_down_right = "";
                for (int k = 0; k < 4; k++) {
                    diagonal_down_right += grid[i + k][j + k];
                }
                if (diagonal_down_right == xmas || diagonal_down_right == reverse_xmas) {
                    count++;
                }
            }
            
            if (i + 3 < n && j - 3 >= 0) {
                string diagonal_down_left = "";
                for (int k = 0; k < 4; k++) {
                    diagonal_down_left += grid[i + k][j - k];
                }
                if (diagonal_down_left == xmas || diagonal_down_left == reverse_xmas) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}
