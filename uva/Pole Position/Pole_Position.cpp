#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        vector<int> v(n), val(n);

        for(int i = 0; i != n; i++){
            int c, p;
            cin >> c >> p;

            if(p+i >= 0 && p+i < n) {
                val[p + i]++;
                v[p + i] = c;
            }
        }

        bool validate = true;
        for(auto i : val){
            if(i != 1){
                validate = false;
            }
        }

        if(validate){
            for(int i = 0; i != v.size(); i++){
                if(i == v.size()-1){
                    cout << v[i] << endl;
                    break;
                }
                cout << v[i] << " ";
            }
        }else{
            cout << -1 << endl;
        }
    }
}