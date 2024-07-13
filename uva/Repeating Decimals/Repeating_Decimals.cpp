#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b){
        map<int, pair<bool, int>> mp;
        mp[a] = {true, 0};
        bool val = false;
        vector<int> v;

        cout << a<<"/"<<b << " = ";
        int ind = 1;
        
        if(a == 0){
            v.push_back(0);
        }

        while(true){
            if(a == 0){
                val = true;
                ind = 999;
                break;
            }

            v.push_back(a/b);
            a = (a%b)*10;

            if(mp[a].first){
                if(mp[a].second == 0){
                    v.push_back(a/b);
                    mp[a].second++;
                } 

                ind = mp[a].second;
                break;
            }
            mp[a] = {true, ind};
            ind++;
        }

        bool val2 = true;
        cout << v[0] << ".";
        if(v[0] == 0){
            val2 = false;
        }
        
        for(int i = 0; i != v.size(); i++){
            if(!val && i == ind){
                cout << "(";
            }
            if(i == 0){
                continue;
            }

            cout << v[i];

            if(i == 50 && v.size() > 51){
                cout <<"...";
                break;
            }
        }

        if(val){
            cout << "(0)" << endl;
            cout << "   1 = number of digits in repeating cycle" << endl;
        }else{
            cout << ")" << endl;
            cout << "   " << v.size()-ind << " = number of digits in repeating cycle" << endl;
        }

        cout << endl;
    }
}
