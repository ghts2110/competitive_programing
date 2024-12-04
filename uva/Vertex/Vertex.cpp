#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > &adj, int no, vector<bool> &visit){
  for(auto it : adj[no]){
    if(!visit[it]){
      visit[it] = true;
      dfs(adj, it, visit);
    } 
  }
}

int main(){
  int n;
  while(cin >> n){
    if(!n){
      break;
    }
  
    vector<vector<int> > adj(n+1, vector<int>());

    int m;
    while(cin >> m){
      if(m == 0){
        break;
      }

      int num;
      while(cin >> num){
        if(num == 0){
          break;
        }

        adj[m].push_back(num);
      }
    }

    int q;
    cin >> q;

    for(int i = 0; i != q; i++){
      int num;
      cin >> num;

      vector<bool> visit(n+1);
      dfs(adj, num, visit);

      vector<int> ans;
      for(int i = 1; i <= n; i++){
        if(!visit[i]){
          ans.push_back(i);
        }
      }

      cout << ans.size();
      for(int i = 0; i != ans.size(); i++){
          cout << " " << ans[i];
      }
      cout << endl;
    }
  }
}
