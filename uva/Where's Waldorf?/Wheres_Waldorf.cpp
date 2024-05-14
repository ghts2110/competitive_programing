#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
int n, m;

void search(int i, int j, vector<string> &v, map<string, pair<int, int>> &mp){
    string s1 = "", s2 = "";
    for(int k = 0; k != n; k++){
        if(i+k < n){
            s1 += v[i+k][j];
        }
        if(i-k > -1){
            s2 += v[i-k][j];
        }

        if(mp[s1].first == -1){
            mp[s1] = {i, j};
        }
        if(mp[s2].first == -1){
            mp[s2] = {i, j};
        }
    }

    s1 = s2 = "";
    for(int k = 0; k != m; k++){
        if(j+k < m){
            s1 += v[i][j+k];
        }
        if(j-k > -1){
            s2 += v[i][j-k];
        }

        if(mp[s1].first == -1){
            mp[s1] = {i, j};
        }
        if(mp[s2].first == -1){
            mp[s2] = {i, j};
        }
    }

    s1 = s2 = "";
    for(int k = 0; k != min(n, m); k++){
        if(i+k < n && j+k < m){
            s1 += v[i+k][j+k];
        }
        if(i-k > -1 && j-k > -1){
            s2 += v[i-k][j-k];
        }

        if(mp[s1].first == -1){
            mp[s1] = {i, j};
        }
        if(mp[s2].first == -1){
            mp[s2] = {i, j};
        }
    }

    s1 = s2 = "";
    for(int k = 0; k != min(n, m); k++){
        if(i-k > -1 && j+k < m){
            s1 += v[i-k][j+k];
        }
        if(i+k < n && j-k > -1){
            s2 += v[i+k][j-k];
        }

        if(mp[s1].first == -1){
            mp[s1] = {i, j};
        }
        if(mp[s2].first == -1){
            mp[s2] = {i, j};
        }
    }


}

int main(){
    int t;
    cin >> t;

    bool f = true;
    while(t--){
        if(!f){
            cout << endl;
        }
        f=false;

        cin >> n >> m;
        
        vector<string> v(n);
        for(int i = 0; i != n; i++){
            for(int j = 0; j != m; j++){
                char c;
                cin >> c;

                v[i] += tolower(c);
            }
        }

        int k;
        cin >> k;

        map<string, pair<int, int>> mp;
        vector<string> save(k);
        for(int i = 0; i != k; i++){
            string s;
            cin >> s;
            for(auto it : s){
                save[i] += tolower(it);
            }

            mp[save[i]] = {-1, -1};
        }

        for(int i = 0; i != n; i++){
            for(int j = 0; j != m; j++){
                search(i, j, v, mp);
            }
        }

        for(auto it : save){
            cout << mp[it].first+1 << ' ' << mp[it].second+1 << endl;
        }
    }
}
