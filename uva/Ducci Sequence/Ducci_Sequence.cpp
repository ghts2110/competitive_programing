#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<vector<int>, bool> mp;
vector<int> seq;
bool loop;

void calculo(){
    int save = seq[0];
    for(int i = 1; i < seq.size(); i++){
        seq[i - 1] = abs(seq[i - 1] - seq[i]);
    }
    seq[seq.size() - 1] = abs(seq[seq.size() - 1] - save);

    if(mp[seq]){
        return;
    }
    mp[seq] = true;

    calculo();
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int x;
        for(int i = 0; i < n; i++){
            cin >> x;
            seq.push_back(x);
        }
        mp[seq] = true;
        loop = true;
        calculo();
        for(auto it: seq){
            if(it != 0){
                loop = false;
                break;
            }
        }
        if(!loop){
            cout << "LOOP";
        }
        else{
            cout << "ZERO";
        }
        cout << "\n";
        mp.clear();
        seq.clear();
    }   
}
