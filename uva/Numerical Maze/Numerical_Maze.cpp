#include <iostream>
#include <vector>
using namespace std;

pair<pair<int,int>,pair<int,int>>ans = {{1e9,1e9},{1e9,1e9}};

void dfs(int x,int y,vector<vector<int>>&v,int max, int sx, int sy){
    if(x == v.size() -1){
        if(ans.first.second > sy){
            ans.second.first = x;
            ans.second.second = y;
            ans.first.first = sx;
            ans.first.second = sy;
        }else if(ans.first.second == sy && ans.second.second > y){
            ans.second.first = x;
            ans.second.second = y;
            ans.first.first = sx;
            ans.first.second = sy;

        }
        return;
    }
    if(v[x][y] == max){
        if(y != 0 && v[x][y-1] == 1){//esq
            dfs(x,y-1,v,max+1,sx,sy);
        }

        if(y != v[0].size() && v[x][y+1] ==  1){//dir
            dfs(x,y+1,v,max+1,sx,sy);
        }

        if(x != 0 && v[x-1][y] ==  1){//cim
            dfs(x-1,y,v,max+1,sx,sy);
        }

        if(x != v.size() && v[x+1][y] == 1){//bai
            dfs(x+1,y,v,max+1,sx,sy);
        }

    }else{
        if(y != 0 && v[x][y-1] == v[x][y] + 1){//esq
            dfs(x,y-1,v,max,sx,sy);
        }

        if(y != v[0].size() && v[x][y+1] == v[x][y] + 1){//dir
            dfs(x,y+1,v,max,sx,sy);
        }

        if(x != 0 && v[x-1][y] == v[x][y] + 1){//cim
            dfs(x-1,y,v,max,sx,sy);
        }

        if(x != v.size() && v[x+1][y] == v[x][y] + 1){//bai
            dfs(x+1,y,v,max,sx,sy);
        }

    }



}

int main(){

    int t;
    cin >> t;


    bool f = true;
    while(t--){
        int n,m;
        cin >> n >> m;
    
        if(!f){
            cout << endl;
        }

        f = false;
        ans = {{1e9, 1e9},{1e9,1e9}};
        vector<vector<int>>v(n,vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int num;
                cin >> num;
                v[i][j] = num;
            }
        }

        for(int i = 0; i < m; i++){
            if(v[0][i] == 1){
                dfs(0,i,v,1, 0, i);
            }
        }

        cout << ans.first.first+1 << " " << ans.first.second+1 << endl;
        cout << ans.second.first+1 << " " << ans.second.second+1 << endl;
    }
}
