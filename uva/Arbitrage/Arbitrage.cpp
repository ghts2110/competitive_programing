#include <iostream>
#include <vector>
#include <map>

using namespace std;
int n;

int main(){
    while(cin >> n){
        vector<vector<vector<double>>> v(n, vector<vector<double>> (n, vector<double> (n)));
        vector<vector<vector<vector<int>>>> ans(n, vector<vector<vector<int>>> (n, vector<vector<int>> (n)));
        
        for(int i = 0; i != n; i++){
            for(int j = 0; j != n; j++){
                ans[i][j][0].push_back(i);
                ans[i][j][0].push_back(j);
                if(i == j){
                    v[i][j][0] = 1;
                    continue;
                }
                cin >> v[i][j][0];

            }
        }


        vector<int> save;
        bool val = true;
        for(int t = 1; t != n && val; t++){
            for(int i = 0; i != n && val; i++){
                for(int j = 0; j != n && val; j++){
                    for(int k = 0; k != n && val; k++){
                        double cost = v[j][i][t-1] * v[i][k][0];
                        if(cost > v[j][k][t]){
                            v[j][k][t] = cost;
                            ans[j][k][t] = ans[j][i][t-1];
                            ans[j][k][t].push_back(k);

                            if(cost >= 1.01 && j == k){
                                save = ans[j][k][t];
                                val = false;
                            }
                        }
                    }
                }
            }
        }

        if(val){
            cout << "no arbitrage sequence exists" << endl;
        }else{
            for(int i = 0; i != save.size(); i++){
                if(i != 0){
                    cout << " ";
                }
                cout << save[i]+1;
            }
            cout << endl;
        }
     
    }
}
