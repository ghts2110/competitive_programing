#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int g, m;
        cin >> g >> m;

        vector<int> god;
        for(int i = 0; i != g; i++){
            int num;
            cin >> num;

            god.pb(num);            
        }

        vector<int> mec;
        for(int i = 0; i != m; i++){
            int num;
            cin >> num;

            mec.pb(num);
        }

        while(god.size() != 0 && mec.size() != 0){
            if(god[0] < mec[0]){
                god.erase(god.begin());
            }else{
                mec.erase(mec.begin());
            }
        }

        if(god.size() != 0){
            cout << "Godzilla" << endl;
        }else{
            cout << "MechaGodzilla" << endl;
        }
    }
}

