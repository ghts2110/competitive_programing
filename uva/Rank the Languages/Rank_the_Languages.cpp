#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
int n,m;

void bfs(vector<vector<char> > &v,  vector<vector<int> > &vis, pair<int,int> p){
    queue<pair<int,int> >q;
    q.push(p);
    vis[p.first][p.second] = 1;
    while(!q.empty()){
        pair<int,int> no = q.front();
        char myl = v[no.first][no.second];
        q.pop();
        if(no.first != 0 && v[no.first-1][no.second] == myl && vis[no.first-1][no.second] != 1){
            q.push(make_pair(no.first-1,no.second));
            vis[no.first-1][no.second] = 1;
        }

        if(no.first != n-1 && v[no.first+1][no.second] == myl && vis[no.first+1][no.second] != 1){
            q.push(make_pair(no.first+1,no.second));
            vis[no.first+1][no.second] = 1;
        }
        if(no.second != m-1 && v[no.first][no.second + 1] == myl && vis[no.first][no.second + 1] != 1){
            q.push(make_pair(no.first,no.second + 1));
            vis[no.first][no.second + 1] = 1;
        }
        if(no.second != 0 && v[no.first][no.second - 1] == myl && vis[no.first][no.second - 1] != 1){
            q.push(make_pair(no.first,no.second -1));
            vis[no.first][no.second -1] = 1;
        }
    }
}

bool my(pair<int, char> i, pair<int, char> j){
    if(i.first > j.first){
        return true;
    }else if(i.first == j.first){
        if(i.second < j.second){
            return true;
        }
    }

    return false;
}

int main(){
    int test;
    cin >> test;
    for(int a = 1; a <= test; a++){
        cin >> n >>  m;

        vector<vector<char> > v(n,vector<char>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> v[i][j];
            }
        }

        vector<vector<int> > vis(n,vector<int>(m));
        map<char,int> mp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] != 1){
                    bfs(v,vis, make_pair(i,j));
                    mp[v[i][j]]++;
                }
            }

        }

        vector<pair<int,char> > ans;
        for(auto i : mp){
            ans.push_back(make_pair(i.second,i.first));
        }

        sort(ans.begin(),ans.end(), my);

        cout << "World #" << a << endl;
        for(auto i : ans){
            cout << i.second << ": " << i.first << endl;
        }
    }

}
