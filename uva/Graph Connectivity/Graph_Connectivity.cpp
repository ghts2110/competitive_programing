#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(int no, vector<vector<int>> &v, vector<int> &visit){
    visit[no] = 1;
    for(auto it : v[no]){
        if(visit[it] == 0){
            dfs(it, v, visit);
        }
    }
}

int main(){
    int t;
    cin >> t;

    bool f = true;
    while(t--){
        if(!f){
            cout <<endl;
        }
        f = false;

        char c;
        cin >> c;
        int n = c-'A'+1;
        vector<vector<int>> v(n);

        string s;
        getline(cin, s);
        while(getline(cin, s)){
            if(s == ""){
                break;
            }

            v[s[0]-'A'].push_back(s[1]-'A');
            v[s[1]-'A'].push_back(s[0]-'A');
        }   


        int asw = 0;
        vector<int> visit(n);
        for(int i = 0; i != v.size(); i++){
            if(visit[i] == 0){
                asw++;
                int cont = 0;
                dfs(i, v, visit);
                asw = max(asw, cont);
            }
        }

        cout << asw << endl;
    }
}
