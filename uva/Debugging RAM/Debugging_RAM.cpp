#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int b, v;

    while(cin >> b >> v){
        vector<pair<string, pair<int, string>>> name(v);
        
        for(int i = 0; i != v; i++){
            string s;
            int n;

            cin >> s >> n;
            name[i] = make_pair(s, make_pair(n, " "));
        }

        for(int i = 0; i != v; i++){
            for(int j = 0; j != name[i].second.first; j++){
                string s;
                cin >> s;
                
                name[i].second.second += s;
            }
        }

        int n;
        cin >> n;

        for(int i = 0; i != n; i++){
            string s;
            cin >> s;

            cout << s << "=";
            for(int j = 0; j != v; j++){
                if(s == name[j].first){
                    unsigned long long num = 0, p = 0;
                    for(int k = name[j].second.second.size()-1; k != -1; k--){
                        if(name[j].second.second[k] == '1'){
                            num += (long long)1 << p; 
                        }
                        p++;
                    }

                    cout << num;
                    break;
                }
            }
            cout << endl;
        }
    }
}
