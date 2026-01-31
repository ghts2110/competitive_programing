#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool my(pair<int, pair<long long, long long>> a, pair<int, pair<long long, long long>> b){
  long long l = a.second.first * b.second.second, r = b.second.first * a.second.second;
  if(l != r){
    return l < r;
  }

  return a.first < b.first;
}

int main(){
  int cases;
  cin >> cases;

  for(int c = 0; c < cases; c++){
    if(c){
      cout << endl;
    }

    int n;
    cin >> n;
  
    vector<pair<int, pair<long long, long long>>> work(n);
    for(int i = 0; i < n; i++){
      int t, s;
      cin >> t >> s; 
      
      work[i] = {i+1, {t, s}};
    }
    
    sort(work.begin(), work.end(), my);

    for(int i = 0; i != n; i++){
      if(i){
        cout << ' ';
      }
      cout << work[i].first;
    }

    cout << endl;
  }
}
