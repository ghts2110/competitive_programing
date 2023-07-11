#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    long long x, y, cont = 0, c0, c1;
    cin >> x >> y;

    vector<vector<int> > v(x);

    for(int i = 0; i != x; i++){
        c0 = c1 = 0;
        for(int j = 0; j != y; j++){
            int n;
            cin >> n;

            v[i].push_back(n);

            if(n == 0){
                c0++;
            }else{
                c1++;
            }
        }

        long long sumc0 = 1, sumc1 = 1;
        for(int i = 0; i != c0; i++){
            sumc0 *= 2;
        }

        for(int i = 0; i != c1; i++){
            sumc1 *= 2;
        }

        cont += (sumc0 -1) + (sumc1 -1);
    }

    for(int i = 0; i != y; i++){
        c0 = c1 = 0;
        for(int j = 0; j != x; j++){
            if(v[j][i] == 0){
                c0++;
            }else{
                c1++;
            }
        }

        long long sumc0 = 1, sumc1 = 1;
        for(int i = 0; i != c0; i++){
            sumc0 *= 2;
        }

        for(int i = 0; i != c1; i++){
            sumc1 *= 2;
        }

        cont += (sumc0 -1 - c0) + (sumc1 -1 - c1);
    }

    cout << cont << endl;
}
