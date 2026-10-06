#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dfs(vector<vector<int>> v, int startNo, vector<bool>& visit){
  stack<int> q;
  q.push(startNo);
  visit[q.top()] = true;;

  int ans = 1;
  while(q.size()){
    int no = q.top();
    q.pop();

    for(int i = 0; i < v[no].size(); i++){
      //cout << "no=" << no << " vai=" << v[no][i] << " mov=" << visit[v[no][i]] << endl;
      if(visit[v[no][i]]){ 
        continue;
      }

      visit[v[no][i]] = true;;
      q.push(v[no][i]);

     ans++; 
    }
  }

  return ans;  
}

pair<int, int> farthest(vector<int> ans){
  int max = 0, no = 0;

  for(int i = 0; i != ans.size(); i++){
    if(max < ans[i]){
      max = ans[i];
      no = i;
    }
  }

  return {max, no};
}

int main(){
  int t;
  cin >> t;

  while(t--){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n+1);

    for(int i = 0; i != m; i++){
      int a, b;
      cin >> a >> b;

      v[a].push_back(b);
      v[b].push_back(a);
    }

    vector<bool> visit(n+1, false);
    int max = 0;
    for(int i = 1; i <= n; i++){
      if(visit[i]){
        continue;
      }
  
      int ans = dfs(v, i, visit);
      if(ans > max){
        max = ans;
      }
    }

    cout << max << endl;
  }
}
