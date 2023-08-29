#include <iostream>
#include <vector>
#include <cmath>

#define pb push_back

using namespace std;

int main(){
    int num;

    vector<int> v;
    while(cin >> num){
        if(num == 0){
            if(v.size() == 0){
                break;
            }

            int cont = 0;
            vector<pair<int, int>> time(v.size());
            bool val = false, val2 = true;
            for(int i = 0; i != v.size(); i++){
                if(time[i].first == 0){
                    if(time[i].second == 0){
                        time[i].first = v[i]-5;
                    }else{
                        time[i].first = v[i]+5;
                    }
                }
            }

            while(1){
                int mn = 1e9;

                for(int i = 0; i != v.size(); i++){
                    mn = min(mn, time[i].first);
                }

                cont += mn;
                if(cont > 18000){
                    val2 = false;
                    break;
                }

                for(int i = 0; i != v.size(); i++){
                    time[i].first -= mn;
                    if(time[i].first == 0){
                        time[i].second ^= 1;
                        if(time[i].second == 0){
                            time[i].first = v[i]-5;
                        }else{
                            time[i].first = v[i]+5;
                        }
                    }
                }

                for(int i = 0; i != v.size(); i++){
                    if(time[i].second == 1){
                        break;
                    }

                    if(i == v.size()-1){
                        val = true;
                    }
                }

                if(val){
                    break;
                }
            }

            if(val2){
                if((cont/60)/60 > 9){
                    cout << (cont/60)/60 << ":";
                }else{
                    cout << "0" << (cont/60)/60 << ":";
                }

                if((cont/60)%60 > 9){
                    cout << (cont/60)%60 << ":";
                }else{
                    cout << "0" << (cont/60)%60 << ":";
                }

                if(cont%60 > 9){
                    cout << cont%60 << endl;
                }else{
                    cout << "0" << cont%60 << endl;
                }
            }else{
                cout << "Signals fail to synchronise in 5 hours" << endl;
            }

            v.clear();
            continue;
        }

        v.pb(num);
    }
}
