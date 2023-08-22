#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

int main(){
    vector<int> v;
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        v.pb(n);
    }

    int p;
    while(cin >> p){
        if(p == 0){
            break;
        }
        
        int x, y;
        vector<pair<int,int>> atalho;
        while(cin >> x >> y){
            if(x == 0 && y == 0){
                break;
            } 
            atalho.pb(make_pair(x, y));
        }

        vector<pair<int,int>> jogadas;
        while(cin >> x){
            if(x==0){
                break;
            }
            y = 1;
            if(x<0){
                y = -1;
                x *= -1;
            }

            jogadas.pb(make_pair(x, y));
        }
        
        vector<bool> play(p, true);
        vector<int> cont(p);

        int l = 0, asw = -1;
        for(int i = 0; i != v.size(); i++){
            if(play[l%p]){
                cont[l%p] += v[i];
                if(cont[l%p] > 100){
                    cont[l%p] -= v[i];
                }else if(cont[l%p] == 100 && asw == -1){
                    asw = (l%p)+1;
                }

                for(int j = 0; j != atalho.size(); j++){
                    if(cont[l%p] == atalho[j].first){
                        cont[l%p] = atalho[j].second;
                    }
                }

                for(int j = 0; j != jogadas.size(); j++){
                    if(cont[l%p] == jogadas[j].first){
                        if(jogadas[j].second == -1){
                            play[l%p] = false;
                            break;
                        }else{
                            l--;
                            break;
                        }
                    }
                }
                l++;

            }else{
                play[l%p] = true;
                l++;
                i--;
            }
        }

        cout << asw << endl;
    }


}
