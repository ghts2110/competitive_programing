#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t, cont;
    cin >> t;

    vector<vector<int> > v(t, vector<int>(2));
    for(int i = 0; i != t; i++){
        cin >> v[i][1] >> v[i][0];
    }

    sort(v.begin(), v.end());

    cont = 1;
    int last = v[0][0];
    for(int j = 1; j != t; j++){
        if(v[j][1] >= last){
            cont ++;
            last = v[j][0];
    
        }
    }


    cout << cont << endl;
}
