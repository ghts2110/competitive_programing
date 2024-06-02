#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    while(cin >> n){
        if(n == -1){
            break;
        }
        
        vector<vector<ll>> v(n, vector<ll>(5));

        for(int i = 0; i != n; i++){
            cin >> v[i][0] >> v[i][1];
            ll m, b, t;
            cin >> m >> b >> t;

            ll sum = t + (b*480) + (m*4*480);
            if(sum%60 < 60-(sum%60)){
                sum -= sum%60;
            }else{
                sum += 60-(sum%60);
            }
            v[i][4] = sum%480;
            sum /= 480;
            v[i][3] = sum%4;
            sum /= 4;
            v[i][2] = sum;
            if(v[i][3] == 0){
                v[i][3] = 4;
                v[i][2]--;
            }
        }

        for(int i = 0; i < v.size(); i++){
            for(int j = i+1; j < v.size(); j++){
                if(v[i][0] != v[j][0] && v[i][1] == v[j][1] && v[i][2] == v[j][2] && v[i][3] == v[j][3] && v[i][4] == v[j][4]){
                    v.erase(v.begin()+j);
                    v.erase(v.begin()+i);
                    j=0;
                }
            }
        }

        cout << v.size() << endl;
        for(auto it: v){
            for(int i = 0; i != it.size(); i++){
                if(i != 0){
                    cout << " ";
                }
                cout << it[i];
            }
            cout << endl;
        }
    }
    cout << -1 << endl;
}
