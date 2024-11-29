#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

bool dfs(int no, int end, vector<vector<int> > adj, vector<bool> visit){
  if(no == end){
    return true;
  }

  visit[no] = true;
  for(auto it : adj[no]){
    if(!visit[it] && dfs(it, end, adj, visit)){
      return true;
    }
  }

  return false;
}

bool isPath(int i, int j, int n, vector<vector<int> > &adj){
  vector<bool> visit(n);
  return dfs(i, j, adj, visit);
}

vector<vector<int> > SCC(int n, vector<vector<int> > &adj){
  vector<vector<int> > ans;
  vector<bool> is_SCC(n);


  for(int i = 0; i != n; i++){
    if(!is_SCC[i]){
      vector<int> scc;
      scc.push_back(i);

      for(int j = i+1; j < n; j++){
        if(!is_SCC[j] && isPath(i, j, n, adj) && isPath(j, i, n, adj)){
          is_SCC[j] = true;
          scc.push_back(j); 
        }              
      }

      ans.push_back(scc);
    }  
  }

  return ans;
}

int main(){
  int n, m;
  int test = 1;

  while(cin >> n >> m){
    if(!n && !m){
      break;
    }

    map<string, bool> mp1;
    map<string, int> mp2;
    map<int, string> mp3;

    vector<vector<int> > adj(n, vector<int>());

    int ind = 0;

    for(int i = 0; i != m; i++){
      string s1, s2;
      cin >> s1 >> s2;

      if(!mp1[s1]){
        mp1[s1] = true;
        mp2[s1] = ind;
        mp3[ind] = s1;
        ind++;
      }

      if(!mp1[s2]){
        mp1[s2] = true;
        mp2[s2] = ind;
        mp3[ind] = s2;
        ind++;
      }

      adj[mp2[s1]].push_back(mp2[s2]); 
    }

    vector<vector<int> > ans = SCC(n, adj);
  
    if(test != 1){
      cout << endl;
    }

    cout << "Calling circles for data set "<<test<<":"<<endl;
    test++;
     
    for(auto it : ans){
      for(int i = 0; i != it.size(); i++){
        cout << mp3[it[i]];

        if(i != it.size()-1){
          cout << ", ";
        }
      }
      cout << endl;
    }
  }
}
