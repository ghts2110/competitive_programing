#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        vector<bool> visit(s.size(), true);
        vector<vector<int> > adj(s.size());

        for(int i = 0; i != s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                int cont = 0;
                for(int j = i-1; j >= 0 && cont < 2; j--){
                    if(visit[j]){
                        adj[i].push_back(j);
                        visit[j] = false;
                        cont++;
                    }
                }
            }
        }

        string asw;
        queue<int> q;
        q.push(s.size()-1);

        while(!q.empty()){
            int no = q.front();
            asw = s[no] + asw;
            q.pop();

            for(int i = adj[no].size()-1; i != -1; i--){
                q.push(adj[no][i]);
            }
        }
        cout << asw << endl;
    }
}