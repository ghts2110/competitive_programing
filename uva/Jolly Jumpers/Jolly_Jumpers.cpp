#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        map<int, bool> mp;

        int last = 0;
        for(int i = 0; i != n; i++){
            int num; 
            cin >> num;

            if(i == 0){
                last = num;
                continue;
            }

            mp[abs(num-last)] = true;
            last = num;
        }

        bool val = true;
        for(int i = 1; i < n; i++){
            val &= mp[i];
        }

        if(val){
            cout << "Jolly" << endl;
        }else{
            cout << "Not jolly" << endl;
        }
    }
}
