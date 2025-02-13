#include <iostream>
#include <vector>
#include <string>

#define pb push_back

using namespace std;

void dfs(int ind, vector<vector<int> > &v, vector<vector<bool> > &visit, string s){
   if(s.size() == 8){
    s += '0' + ind;
    cout << s << endl;
   } 
   
   for(int i = 0; i != v[ind].size(); i++){
      if(!visit[ind][v[ind][i]]){
        s += ind+'0';
        visit[ind][v[ind][i]] = true;
        visit[v[ind][i]][ind] = true;
        
        dfs(v[ind][i], v, visit, s);
      
        s.erase(s.end()-1);
        visit[ind][v[ind][i]] = false;
        visit[v[ind][i]][ind] = false;
      }
   }
}

int main(){
  vector<vector<bool> > visit(6, vector<bool>(6));
  vector<vector<int> > v(6);
  v[1].pb(2); 
  v[1].pb(3); 
  v[1].pb(5);
  v[2].pb(1); 
  v[2].pb(3); 
  v[2].pb(5);
  v[3].pb(1);
  v[3].pb(2);
  v[3].pb(4);
  v[3].pb(5);
  v[4].pb(3);
  v[4].pb(5);
  v[5].pb(1);
  v[5].pb(2);
  v[5].pb(3);
  v[5].pb(4);
  dfs(1, v, visit, "");
}
