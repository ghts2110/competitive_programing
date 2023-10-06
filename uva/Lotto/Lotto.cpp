#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

int main(){
    int k;
    int test = 1;
    while(true){
        cin >> k;
        if(!k){
            break;
        }
        if(test != 1){
            cout << endl;
        }
        test++;

        vector<int> v(k);
        for(int i = 0; i != k; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        vector<vector<int> >asw;
        for(int i = 63; i != 1<<k; i++){
            bitset<13> bt(i);
            int cont = 0;

            for(int j = 0; j != k; j++){
                if(bt[j]){
                    cont++;
                }
            }

            if(cont == 6){
                int index = 0;
                vector<int> save(6);
                for(int j = 0; j != k; j++){
                    if(bt[j]){
                        save[index] = v[j];
                        index++;
                    }
                }

                asw.push_back(save);
            }
        }

        sort(asw.begin(), asw.end());
        for(auto it : asw){
            for(int i = 0; i != 6; i++){
                if(i == 5){
                    cout << it[i] << endl;
                    break;
                }
                cout << it[i] << " ";
            }
        }
    }
}
