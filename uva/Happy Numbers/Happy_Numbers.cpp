#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> v(100000);

void solution(){
    for(int i = 1; i <= 99999; i++){
        int cont = 1;
        int no = i;

        map<int, bool> mp;
        while(no != 1){
            cont++;
            string s = to_string(no);
            int sum = 0;
            for(auto it : s){
                sum += (it-'0')*(it-'0');
            }

            no = sum;

            if(mp[no]){
                cont = -1;
                break;
            }

            mp[no] = true;
        }

        v[i] = cont;
    }
}

int main(){
    solution();
    int l, h;

    bool first = true;
    while(cin >> l >> h){
        if(!first){
            cout << endl;
        }
        first = false;

        for(int i = l; i <= h; i++){
            if(v[i] != -1){
                cout << i << " " << v[i] << endl;
            }
        }
    }
}