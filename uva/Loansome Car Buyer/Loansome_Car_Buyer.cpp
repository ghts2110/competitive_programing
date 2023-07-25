#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

int main(){
    float m, p, e, n;
    while(cin >> m >> p >> e >> n){
        if(m < 0){
            break;
        }

        vector<pair<int, float>> v;
        for(int i =0 ;i != n; i++){
            int num;
            float f;
            cin >> num >> f;

            pair<int, float> pr(num, f);
            v.pb(pr);
        }
        pair<int, float> pr(1e9, 0);
        v.pb(pr);
        
        float d = e + p, index = 0;
        float dep;
        p = e/m;
        for(int i = 0; i <= m; i++){
            if(i == v[index].first){
               dep = v[index].second; 
                index++;
            }

            if(i == 0){
                d = d - (d*dep);
            }else{
                d = d - (d*dep);
                e -= p;
            }

            if(e < d){
                if(i == 1){
                    cout << i << " month"<< endl;
                    break;
                }
                cout << i << " months" << endl;
                break;
            }
        }
    }
}
