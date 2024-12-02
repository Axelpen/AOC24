#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
typedef long long ll;

using namespace std;

bool isSafe(vector<int> v){
    bool asc = true;
    bool desc = true;
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i] > v[i+1]) asc = false;
        if(v[i] < v[i+1]) desc = false;
        if(abs(v[i] - v[i+1]) < 1 || abs(v[i] - v[i+1]) > 3) return false;
    }
    return asc || desc;
}

bool isSafeWithDampener(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        vector<int> temp = v;
        temp.erase(temp.begin() + i);
        if(isSafe(temp)) return true;
    }
    return false;
}

int main() {
    ifstream f("input.txt");
    string line;
    vector<int> numbers;
    int ans = 0;
    while(getline(f,line)){
        istringstream iss(line); 
        numbers.clear(); 
        int num;
        while(iss >> num){
            numbers.PB(num);
        }
        if(isSafe(numbers) || isSafeWithDampener(numbers)) ans++;
    }
    cout << ans;
    return 0;
}
