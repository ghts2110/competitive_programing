#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

int main(){
    long long t, mn = 1e9;
    cin >> t;

    vector<int> v;

    for(int i = 0; i != t; i++){
        int num;
        cin >> num;

        v.push_back(num);
    }

    if(t == 1){
        cout << v[0] << endl;
        return 0;
    }

    for(int i = 1; i <= pow(2, t); i++){
        bitset<20> bt(i);
        long long cont1 = 0, cont2 = 0;

        for(int j = 0; j != t; j++){
            if(bt[j] == 1){
                cont1 += v[j];
            }else{
                cont2 += v[j];
            }
        }  

        mn = min(mn, abs(cont1 - cont2));
    }

    cout << mn << endl;

}
