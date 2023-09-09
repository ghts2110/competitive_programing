#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int last, num;
        cin >> last;

        bitset<3000> bt(0);
        for(int i = 1; i < n; i++){
            cin >> num;

            bt[abs(last-num)] = true;

            last = num;
        }

        bool val = true;
        for(int i = 1; i < n; i++){
            if(!bt[i]){
                val = false;
                break;
            }
        }

        if(val){
            cout << "Jolly" << endl;
        }else{
            cout << "Not jolly" << endl;
        }

    }
}