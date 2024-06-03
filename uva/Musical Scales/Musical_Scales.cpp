#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

bool validate(vector<bool> &val, vector<int> &v){
    bool works = true;
    for(int i = 0; i != 12; i++) {

        bool inthisscale = false;
        for(int j = 0; j != v.size(); j++) {
            if(v[j] == i) {
                inthisscale = true;
            }
        }

        if(val[i] && !inthisscale) {
            works = false;
        }
    }
    return works;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v = {
        {0,2,4,5,7,9,11},
        {1,3,5,6,8,10,0},
        {2,4,6,7,9,11,1},
        {3,5,7,8,10,0,2},
        {4,6,8,9,11,1,3},
        {5,7,9,10,0,2,4},
        {6,8,10,11,1,3,5},
        {7,9,11,0,2,4,6},
        {8,10,0,1,3,5,7},
        {9,11,1,2,4,6,8},
        {10,0,2,3,5,7,9},
        {11,1,3,4,6,8,10}};

    map<string, int> mp;
    mp["A"] = 0;
    mp["A#"] = 1;
    mp["B"] = 2;
    mp["C"] = 3;
    mp["C#"] = 4;
    mp["D"] = 5;
    mp["D#"] = 6;
    mp["E"] = 7;
    mp["F"] = 8;
    mp["F#"] = 9;
    mp["G"] = 10;
    mp["G#"] = 11;

    map<int, string> mp2;
    mp2[0] = "A";
    mp2[1] = "A#";
    mp2[2] = "B";
    mp2[3] = "C";
    mp2[4] = "C#";
    mp2[5] = "D";
    mp2[6] = "D#";
    mp2[7] = "E";
    mp2[8] = "F";
    mp2[9] = "F#";
    mp2[10] = "G";
    mp2[11] = "G#";


    vector<bool> val(12, false);
    for(int i = 0; i != n; i++){
        string num;
        cin >> num;

        val[mp[num]] = true;
    }

    bool prt = false;
    for(int i = 0; i < v.size(); i++) {
        if(validate(val, v[i])) {
            prt = true;
            cout << mp2[i] << " ";
        }
    }

    if(!prt) {
        cout << "none";
    }
    cout << endl;
}
