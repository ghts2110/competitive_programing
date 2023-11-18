#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <map>
using namespace std;

bool isquirk(int n1, int n2, int n){
    if((n1 + n2) * (n1 + n2) == n){
        return true;
    }
    return false;
}

int main(){
    int n;
    map<int,vector<string> > mp;
    while(cin >> n){
        if(mp.find(n) != mp.end()){
            for(auto it : mp[n]){
                cout << it << endl;
            }
            continue;
        }

        int p = 1, mid = 1;
        for (int i = 0; i < n; ++i) {
            p *= 10;
            if(i < n/2){
                mid *= 10;
            }
        }

        for(int i = 0; i < p; i++){
            int n1 = i%mid;
            int n2 = i/mid;

            bool b = isquirk(n1,n2, i);
            if(b){
                string v = to_string(i);
                for(int i = v.size(); i != n; i++){
                    v = "0" + v;
                }

                mp[n].push_back(v);
                cout << v << endl;
            }
        }
    }
}