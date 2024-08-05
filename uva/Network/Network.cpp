#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int asw = 0;

void dfs(vector<vector<int>> &adj, int n,  vector<int> &visit, int i, int j){
    visit[j] = 1;
    for(auto it : adj[j]){
        if(it != i && !visit[it]){
            dfs(adj, n, visit, i, it);
        }
    }
}

void AP(vector<vector<int>> &adj, int n){
    for(int i = 1; i <= n; i++){
        int cont = 0;

        vector<int> visit(n+1);

        for(int j = 1; j <= n; j++){
            if(i == j){
                continue;
            }

            if(!visit[j]){
                cont++;

                dfs(adj, n, visit, i, j);
            }
        }

        if(cont > 1){
            asw++;
        }
    }

}
int main(){
    int n;

    while(cin >> n){
        if(!n){
            break;
        }

        asw = 0;
        map<pair<int, int>, bool> mp;
        vector<vector<int>> v(n+1);
        vector<int> cont (n+1);
        string s;

        while(getline(cin, s)){
            if(s=="0"){
                break;
            }
            int no = 0;
            string save = "";

            for(int i = 0; i != s.size(); i++){
                if(s[i] != ' '){
                    save += s[i];
                }

                if(s[i] == ' ' || i == s.size()-1){
                    if(!no){
                        no = stoi(save);
                    }else{
                        int num = stoi(save);
                        v[no].push_back(num);
                        v[num].push_back(no);
                        
                        if(!mp[{no,num}]){
                            cont[no]++;
                            cont[num]++;
                        }

                        mp[{no, num}] = true;
                        mp[{num, no}] = true;
                    }
                    save = "";
                }
            }
        }

        AP(v, n);
        cout << asw << endl;
    }
}
