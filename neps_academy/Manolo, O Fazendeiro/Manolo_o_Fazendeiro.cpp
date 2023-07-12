#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t, q, cont = 0;
    cin >> t;
    vector<vector<int> > v(t);

    for(int i = 0; i != t; i++){
        for(int j = 0; j != t; j++){
            int num;
            cin >> num;

            v[i].push_back(num);
        }
    }


    cin >> q;

    while(q--){
        int ls, cs, le, ce; 
        cin >> ls >> cs >> le >> ce;

        ls--;
        cs--;
        le--;
        ce--;
        
        for(int i = ls; i <= le; i++){
            for(int j = cs; j <= ce; j++){
                cont += v[i][j];
                v[i][j] = 0;
            }
        }
    }

    cout << cont << endl;
}
