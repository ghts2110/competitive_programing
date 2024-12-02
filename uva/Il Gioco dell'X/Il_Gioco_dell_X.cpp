#include <iostream>
#include <vector>

using namespace std;

bool validate(int x, int y, int n, vector<vector<bool> > &visit, vector<vector<char> > &v){
  if(x >= 0 && x < n && y >= 0 && y < n && !visit[x][y] && v[x][y] == 'b'){
    return true;
  }

  return false;
}

bool rec(vector<vector<char> > &v, pair<int, int> no, vector<vector<bool> > &visit, int n){
  if(no.first == n-1){
    return true;
  }

  if(visit[no.first][no.second]){
    return false;
  }

  visit[no.first][no.second] = true;

  bool b = false;
  if(validate(no.first-1, no.second-1, n, visit, v)){
    b |= rec(v, make_pair(no.first-1, no.second-1), visit, n);
  }

  if(validate(no.first-1, no.second, n, visit, v)){
    b |= rec(v, make_pair(no.first-1, no.second), visit, n);
  }
  
  if(validate(no.first, no.second-1, n, visit, v)){
    b |= rec(v, make_pair(no.first, no.second-1), visit, n);
  }

  if(validate(no.first, no.second+1, n, visit, v)){
    b |= rec(v, make_pair(no.first, no.second+1), visit, n);
  }
  
  if(validate(no.first+1, no.second, n, visit, v)){
    b |= rec(v, make_pair(no.first+1, no.second), visit, n);
  }

  if(validate(no.first+1, no.second+1, n, visit, v)){
    b |= rec(v, make_pair(no.first+1, no.second+1), visit, n);
  }

  return b;
}

int main(){
  int n, t = 1;
  while(cin >> n){
    if(!n){
      break;
    }

    vector<vector<char> > v(n, vector<char> (n));
    vector<vector<bool> > visit(n, vector<bool> (n));

    for(int i = 0; i != n; i++){
      for(int j = 0; j != n; j++){
        cin >> v[i][j];
      }
    }

    bool b = false;
    for(int i = 0; i != n; i++){
      b |= rec(v , make_pair(0, i), visit, n); 
    }

    cout << t << " ";
    t++;

    if(b){
      cout << "B" << endl;
    }else{
      cout << "W" << endl;
    }

  }
}
