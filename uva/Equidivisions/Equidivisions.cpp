#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int dfs(vector<vector<int>>&v, vector<vector<int>>&visited, int i, int j){
    stack<pair<int, int>> st;
    visited[i][j] = 1;
    st.push({i, j});
    
    int cont = 0;
    while(!st.empty()){
        cont++;
        pair<int, int> no = st.top();
        st.pop();

        if(no.first-1 >= 0 && v[no.first-1][no.second] == v[no.first][no.second] &&
                visited[no.first-1][no.second] == 0){
            visited[no.first-1][no.second] = 1;
            st.push({no.first-1, no.second});
        }

        if(no.first+1 < v.size() && v[no.first+1][no.second] == v[no.first][no.second] &&
                visited[no.first+1][no.second] == 0){
            visited[no.first+1][no.second] = 1;
            st.push({no.first+1, no.second});
        }

        if(no.second-1 >= 0 && v[no.first][no.second-1] == v[no.first][no.second] &&
                visited[no.first][no.second-1] == 0){
            visited[no.first][no.second-1] = 1;
            st.push({no.first, no.second-1});
        }

        if(no.second+1 < v.size() && v[no.first][no.second+1] == v[no.first][no.second] &&
                visited[no.first][no.second+1] == 0){
            visited[no.first][no.second+1] = 1;
            st.push({no.first, no.second+1});
        }
    }

    return cont;
}

int main(){

    while(true){
        int n;
        cin >> n;

        if(n == 0){
            break;
        }

        vector<int>group(n+1);
        vector<vector<int>>v(n,vector<int>(n,n));
        vector<vector<int>>visited(n,vector<int>(n));
        
        string s;
        getline(cin,s);
        for(int i = 0; i < (n-1); i++){
            getline(cin, s);
            string save = "";
            int p1 = -1, p2 = -1;
            for(int j = 0; j != s.size()+1; j++){
                if(j == s.size() || s[j] == ' '){
                    if(save == ""){
                        continue;
                    }
                    if(p1 == -1){
                        p1 = stoi(save);
                        save = "";
                        continue;
                    }

                    if(p2 == -1){
                        p2 = stoi(save);
                        save = "";
                        p1--;
                        p2--;

                        v[p1][p2] = i;
                        p1 = -1;
                        p2 = -1;
                        continue;
                    }
                }

                save += s[j];
            }
        }

        bool equi = true;

        for(int i = 0; i < n && equi; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == 0){
                    if(n != dfs(v, visited, i, j) || group[v[i][j]] == 1){
                        equi = false;
                        break;
                    }
                    group[v[i][j]] = 1;
                }
            }
        }

        if(equi){
            cout << "good" << endl;
        }else{
            cout << "wrong" << endl;
        }
    }
}
