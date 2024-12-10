//wtf did i write 

#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
typedef long long ll;

using namespace std;

int testtest = 0;
char dir = 'T';
map<char, pair<int, int>> directions = { // first = oben unten, second = rechts links;
    {'T', MP(-1, 0)},
    {'R', MP(0, 1)},
    {'B', MP(1, 0)},
    {'L', MP(0, -1)}};

pair<int, int> findSoldier(vector<string> grid)
{
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '^')
            {
                return MP(i, j);
            }
        }
    }
    return MP(-1, -1);
}

int moveSoldier(pair<int, int> &soldierPos, const vector<string> &grid, vector<string> &markedGrid)
{
    if (testtest >= 10000)
        return 0;

    int x = soldierPos.first;
    int y = soldierPos.second;
    if (x < 0 || x >= static_cast<int>(grid.size()) || y < 0 || y >= static_cast<int>(grid[0].size()))
        return 0;

    if (markedGrid[x][y] == '.')
    {
        markedGrid[x][y] = '#';
        testtest += 1;
    }
    int newX = x + directions[dir].first;
    int newY = y + directions[dir].second;
    if (newX < 0 || newX >= static_cast<int>(grid.size()) || newY < 0 || newY >= static_cast<int>(grid[0].size()))
        return 0; 

    string buff = "";
    buff += grid[x + directions[dir].first][y + directions[dir].second];
    if (buff == "#")
    { // T-R-B-L
        dir = (dir == 'T' ? 'R' : (dir == 'B' ? 'L' : (dir == 'R' ? 'B' : 'T')));
    }
    else
    {

        soldierPos.first += directions[dir].first;
        soldierPos.second += directions[dir].second;
    }

    moveSoldier(soldierPos, grid, markedGrid);
    return 0;
}

vector<string> fillMarkedGrid(int n, int m)
{ // n = oben unten m = rechts links
    string trash = "";
    vector<string> marked;
    for (int i = 0; i < m; i++)
    {
        trash += ".";
    }
    for (int i = 0; i < n; i++)
    {
        marked.PB(trash);
    }
    return marked;
}

void printGrid(vector<string> &grid)
{
    for (const auto &row : grid)
    {
        cout << row << endl;
    }
}

int main()
{
    ifstream f("input.txt");
    vector<string> grid;
    string line;

    while (getline(f, line))
    {
        grid.PB(line);
    }

    vector<string> markedGrid = fillMarkedGrid(grid.size(), grid[0].size());
    pair<int, int> soldierPos = findSoldier(grid);
    
    moveSoldier(soldierPos, grid, markedGrid);

    cout << testtest << endl;

    // printGrid(markedGrid); //test
    return 0;
}
