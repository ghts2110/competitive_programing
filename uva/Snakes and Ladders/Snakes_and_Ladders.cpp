#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
       
        vector<int> v(a, 1);
        map<int, int> mp;
        for(int i = 0; i != b; i++){
            int x, y;
            cin >> x >> y;
            mp[x] = y;
        }

        bool validate = false;
        if(a == 0){
            validate = true;
        }
        for(int i = 0; i != c; i++){
            int num;
            cin >> num;

            if(validate){
                continue;
            }

            v[i%a] += num;
            if(mp[v[i%a]] != 0){
                v[i%a] = mp[v[i%a]];
            }
            if(v[i%a] >= 100){
                v[i%a] = 100;
                validate = true;
            }
        }


        for(int i = 0; i!= a; i++){
            cout << "Position of player "<<i+1<<" is "<<v[i]<<"." << endl;
        }
    }
}
