#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, sum = 0; 
    cin >> n;

    vector<vector<int> > v(n);

    for(int i = 0; i != n; i++){
        for(int j = 0; j != n; j++){
            int num;
            cin >> num;

            v[i].push_back(num);
            
            if(i == 0){
                sum += num;
            }
        }
    }

    int sl, sc, sdp = 0, sds = 0;
    int f = 0, e = n - 1;
    
    for(int i = 0; i != n; i++){
        sl = sc = 0;

        for(int j = 0; j != n; j++){
            sl += v[i][j];
            sc += v[j][i];

            if(i == j){
                sdp += v[i][j];
            }
            if(i == f && j == e){
                f++;
                e--;
                sds += v[i][j];
            }
        }

        if(sl != sum || sc != sum){
            sum = -1;
        }
    }

    if(sdp != sum || sds != sum){
        sum = -1;
    }

    cout << sum << endl;
}

