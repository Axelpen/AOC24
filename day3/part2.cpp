#include <bits/stdc++.h>
#include <regex>
#define PB push_back
#define MP make_pair
typedef long long ll;

using namespace std;

int main() { 
    regex r(R"(mul\((\d*),(\d*)\)|(do\(\))|(don't\(\)))");
    ifstream f("input.txt");
    string input;
    string inputs = ""; 
    while(getline(f,input)){
        inputs+=input;
    }
    ll ans = 0;
    bool asd = true; //checks if do or dont
    auto words_begin = sregex_iterator(inputs.begin(), inputs.end(), r);
    auto words_end = sregex_iterator();

    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        if(match.str(0) == "do()")
            asd = true;
        else if (match.str(0) == "don't()")
        {
            asd =false;
        }
        else if(asd == true){
            ans += stoi(match.str(1)) * stoi(match.str(2));
        }
    }
    cout << ans << endl;
}
