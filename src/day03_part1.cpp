#include <bits/stdc++.h>
#include <regex>
#define PB push_back
#define MP make_pair
typedef long long ll;

using namespace std;
int main() { 
    regex r(R"(mul\((\d*),(\d*)\))");
    ifstream f("input.txt");
    string input;
    string inputs = ""; 
    while(getline(f,input)){
        inputs+=input;
    }
    ll ans = 0;
    auto words_begin = sregex_iterator(inputs.begin(), inputs.end(), r);
    auto words_end = sregex_iterator();

    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        ans += stoi(match.str(1)) * stoi(match.str(2));
        cout << ans << " " << match.str(1) << " " << match.str(2)<< endl;
    }
    cout << ans << endl;
}
