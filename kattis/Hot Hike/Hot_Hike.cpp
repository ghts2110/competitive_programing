#include <iostream>
#include <vector>
#include <cmath>

#define pb push_back

using namespace std;

int main(){
    int t;
    cin >> t;

    vector<int> v;
    for(int i = 0; i != t; i++){
        int num;
        cin >> num;

        v.pb(num);        
    }

    int mn = 1e9, d;
    for(int i = 2; i != t; i++){
        if(mn > max(v[i], v[i-2])){
            mn = max(v[i], v[i-2]);
            d = i - 1;
        }
    }

    cout << d << " " << max(v[d-1], v[d+1]) << endl;
}
