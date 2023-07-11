#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main(){
    int t;
    cin >> t;

    vector<vector<int> > v(t, vector<int> (2));
    int mx = 0;
    for(int i = 0; i != t; i++){
        cin >> v[i][0] >> v[i][1]; 
    }

    sort(v.begin(), v.end());
    bitset<10001> bt(0);

    int cont = 0;
    for(int i = t-1; i != -1; i--){
        bool val = false;
        int j = v[i][1];

        while(j != 0){
            if(bt[j] == 0){
                bt[j] = 1;
                val = true;
                break;
            } 

            j--;
        }

        if(val){
            cont += v[i][0];
        }
    }

    cout << cont << endl;
}
