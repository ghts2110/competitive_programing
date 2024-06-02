#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int test = 1;
    while(cin >> n){
        int h1, m1, h2, m2;
        string s;
        char c;

        vector<pair<int, int>> v;
        v.push_back({10*60,10*60});
        for(int i = 0; i != n; i++){
            cin >> h1 >> c >> m1 >> h2 >> c >> m2;
            getline(cin, s);
            v.push_back({h1*60 + m1, h2*60+m2});
        }
        v.push_back({18*60, 18*60});

        for(int i = 0; i != v.size(); i++){
            for(int j = 0; j != v.size(); j++){
                if(i == j || v[i].second == 600 || v[j].second == 600){
                    continue;
                }
                if(v[i].first <= v[j].first && v[i].second >= v[j].first){
                    v[i].second = max(v[i].second, v[j].second);
                    v[j]={600, 600};
                    j = 0;
                }
            }
        }
        
        for(int i = 0; i < v.size(); i++){
            if(i != 0 && v[i].second == 600){
                v.erase(v.begin()+i);
                i--;
            } 
        }

        vector<int> save;
        for(auto it : v){
            save.push_back(it.first);
            save.push_back(it.second);
        }
        sort(save.begin(), save.end());

        int time = 0, h = 0;
        for(int i = 1; i < save.size()-1; i+=2){
            if(save[i+1]-save[i] > time){
                time = save[i+1]-save[i];
                h = save[i];
            }
        }

        cout << "Day #"<<test<<": the longest nap starts at "<<h/60<<":";
        if(h%60 < 10){
            cout << "0"<<h%60<<" and will last for ";
        }else{
            cout<<h%60<<" and will last for ";
        }
        int hora = time/60;
        int minuto = time%60;
        if(hora != 0){
            cout << hora << " hours and ";
        }
        cout << minuto << " minutes." << endl;
        test++;
    }
}
