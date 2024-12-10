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

    int count = 0;

    for(int i = 1; i < n-1;i++){
        for(int j = 1; j < m-1; j++){
            char center = grid[i][j];
            char top_left = grid[i - 1][j - 1];
            char top_right = grid[i - 1][j + 1];
            char bottom_left = grid[i + 1][j - 1];
            char bottom_right = grid[i + 1][j + 1];

            if(center == 'A'){
                if(top_left == 'M' && top_right == 'S' && bottom_left == 'M' && bottom_right == 'S'){ 
                    count++;
                }
                if(top_left == 'S' && top_right == 'M' && bottom_left == 'S' && bottom_right == 'M'){ 
                count++;
                }
                
                if(top_left == 'S' && top_right == 'S' && bottom_left == 'M' && bottom_right == 'M'){ 
                count++;
                }
                                
                if(top_left == 'M' && top_right == 'M' && bottom_left == 'S' && bottom_right == 'S'){ 
                count++;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}