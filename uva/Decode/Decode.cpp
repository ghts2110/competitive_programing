#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, char> a, pair<int, char> b){
    if(a.first > b.first){
        return true;
    }
    else if(a.first < b.first){
        return false;
    }
    return a.second < b.second;
}

int main(){
    vector<int> mp1(26);
    vector<int> mp2(26);
    bool t = false;
    string orig;
    vector<string> end;

    while(getline(cin, orig)){
        if (orig == "" && !t){
            t = true;
            continue;
        }
        if(orig == "-1"){
            break;
        }

        if (t == false){
                for (int i = 0; i < orig.size(); i++){
                    if (isalpha(orig[i])){
                        mp1[tolower(orig[i])-'a']++;
                    }
                }
            }
            if (t){
                for(int i = 0; i < orig.size(); i++){
                    if (isalpha(orig[i])){
                        mp2[tolower(orig[i])-'a']++;
                    }
                
                }
                end.push_back(orig);               
            }
    }

    vector<pair<int,char>> p(26);
    vector<pair<int, char>> p2(26);

    for (int i = 0; i < 26; i++){
        p[i].second = 'a' + i;
        p[i].first = mp1[i];
        p2[i].second = 'a' + i;
        p2[i].first = mp2[i];
    }

    sort(p.begin(), p.end(), cmp);
    sort(p2.begin(), p2.end(), cmp);

    map<char, char> mp3;

    for(int i = 0; i < 26; i++){
        mp3[p2[i].second] = p[i].second;
    }

    for (int i = 0; i != end.size(); i++){
        for (auto j : end[i]){
            if (isalpha(j)){
                if(j >= 'A' && j <= 'Z'){
                    cout << char(mp3[tolower(j)] - 32);
                }
                else{
                    cout << mp3[j];
                }
            }
            else{
                cout << j;
            }
        }
        cout << endl;
    }
}
