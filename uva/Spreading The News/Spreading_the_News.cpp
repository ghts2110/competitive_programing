#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int e;
    cin >> e;

    vector<vector<int> > adj(e);
    for(int i = 0; i != e; i++){
        int n;
        cin >> n;

        for(int j = 0; j != n; j++){
            int no;
            cin >> no;

            adj[i].push_back(no);
        }
    }

    int t;
    cin >> t;

    for(int i = 0; i != t; i++){
        int start;
        cin >> start;

        queue<int> q;
        vector<bool> visit(e, true);
        q.push(start);
        visit[start] = false;

        int cont = 0, mx = 0, day = 0;
        while(!q.empty()){
            queue<int> save;
            cont++;
            while(!q.empty()){
                int no = q.front();
                q.pop();

                for(auto it : adj[no]){
                    if(visit[it]){
                        visit[it] = false;
                        save.push(it);
                    }
                }

                if(mx < save.size()){
                    mx = save.size();
                    day = cont;
                }
            }

            q = save;
        }

        if(day == 0){
            cout << 0 << endl;
        }else{
            cout << mx << " " << day << endl;
        }
    }
}