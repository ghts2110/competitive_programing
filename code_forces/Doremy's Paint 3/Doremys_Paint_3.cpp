#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> v(100001);
        int cont = 0;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            if(!v[num]){
                cont++;
            }
            v[num]++;
        }

        if(cont == 1){
            cout << "Yes" << endl;
            continue;
        }else if(cont > 2){
            cout << "No" << endl;
            continue;
        }

        bool val = false;
        int first_num = -1;

        for(int i : v){
            if(i && first_num == -1){
                first_num = i;
            }else if(i){
                if(first_num == i || abs(first_num-i) == 1){
                    val = true;
                }
                break;
            }
        }

        if(val){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}