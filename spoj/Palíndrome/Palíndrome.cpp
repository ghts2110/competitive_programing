#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int> > &v, int start, vector<int> &dist){
    dist[start] = 0;
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int no = q.front();
        q.pop();

        for(auto it : v[no]){
            if(dist[it] == -1){
                dist[it] = dist[no]+1;
                q.push(it);
            }
        }
    }
}

int main() {
    int n;
    string s;

    int test = 1;
    while(cin >> n){
        if(!n){
            break;
        }

        cin >> s;

        if(test != 1){
            cout << endl;
        }
        cout << "Teste " << test << endl;
        test++;

        vector<vector<int> > v(n+1);

        int l, r;
        for(int i = 0; i != n; i++){
            l = r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                v[l].push_back(r+1);
                l--;
                r++;
            }
        }
        for(int i = 0; i < n-1; i++){
            l = i;
            r = i+1;

            while(l >= 0 && r < n && s[l] == s[r]){
                v[l].push_back(r+1);
                l--;
                r++;
            }
        }

        vector<int> dist(n+1, -1);
        bfs(v, 0, dist);
        cout << dist[n] << endl;
    }
}
