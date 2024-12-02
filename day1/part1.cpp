#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
typedef long long ll;


using namespace std;
int main() {
    ifstream f("input.txt");
    
    vector<int> v_L;
    vector<int> v_R;

    int L,R;
    while(f >> L >> R){
        v_L.PB(L);
        v_R.PB(R);
    }
    sort(v_L.begin(),v_L.end());
    sort(v_R.begin(),v_R.end());
    int ans=0;
    for(int i = 0; i < v_L.size(); i++){
        ans += abs(v_L[i] - v_R[i]);
    }
    cout << ans << endl;
}
