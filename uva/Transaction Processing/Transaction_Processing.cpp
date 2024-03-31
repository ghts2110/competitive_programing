#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main(){
    string s;
    map<string, string> name;

    while(getline(cin, s)){
        string n = "";
        n+=s[0];
        n+=s[1];
        n+=s[2];
        s.erase(s.begin());
        s.erase(s.begin());
        s.erase(s.begin());

        if(n == "000"){
            break;
        }

        name[n] = s;
    }

    map<string, pair<ll, vector<pair<string, ll>>>> mp;
    string n;
    vector<string> v;
    map<string, bool> visit;
    
    while(cin >> n){
        ll num;
        cin >> num;
        string f = "";
        f+=n[0];
        f+=n[1];
        f+=n[2];
        string s = "";
        s += n[3];
        s += n[4];
        s += n[5];

        if(f == "000"){
            break;
        }

        if(!visit[f]){
            v.push_back(f);
            visit[f] = true;
        }

        if(name[s] == ""){
            continue;
        }
        mp[f].second.push_back({s, num});
        mp[f].first += num; 
    }

    for(auto it : v){;
        
        if(mp[it].first != 0){
            cout << "*** Transaction "<< it <<" is out of balance ***" << endl;
            for(auto ij : mp[it].second){
                cout << ij.first << " " << name[ij.first];
                ll sn = to_string(double(ij.second)/100).size();

                for(int i = 0; i != 45 - name[ij.first].size() - sn; i++){
                    cout << " ";
                }
                printf("%.2f\n", double(ij.second)/100);
            }
                
            cout << "999 Out of Balance";
            ll sn = to_string(double(mp[it].first)/-100).size();       
            for(int i = 0; i != 31 - sn; i++){
                cout << " ";
            }
            printf("%.2f\n", double(mp[it].first)/-100);

            cout << endl;
        }
    }
}
