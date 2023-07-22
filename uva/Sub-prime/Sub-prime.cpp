#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

int main(){
    int b, n;
    while(cin >> b >> n){
        if(b == 0){
            break;
        }

        vector<int> bank;

        for(int i = 0; i != b; i++){
            int num;
            cin >> num;

            bank.pb(num);
        }
        
        for(int i = 0; i != n; i++){
            int d, c, v;
            cin >> d >> c >> v;

            bank[d-1] -= v;
            bank[c-1] += v;
        }

        bool validate = true;
        for(int i = 0; i != b; i++){
            if(bank[i] < 0){
                validate = false;
                break;
            }
        }

        if(validate){
            cout << "S" << endl;
        }else{
            cout << "N" << endl;
        }
    }
}
