#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
typedef long long ll;


using namespace std;
int main() {
    ifstream f("input.txt");
    map<int,int> occ; //Number - Occurces
    vector<int> numbers;

    int L,R;
    while(f >> L >> R){
        numbers.PB(L);

        if(occ.find(R) == occ.end()){
            occ[R] = 1;
        }
        else{
            occ[R]++;
        }
    }

    int ans=0;

    for(size_t i = 0; i < numbers.size(); i++){
        if(occ.find(numbers[i]) == occ.end()){
            continue;
        }

        ans += numbers[i]*occ[numbers[i]];
    }
    cout << ans << endl;
}
