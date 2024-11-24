#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int> &v){
  int sz = v.size();
  vector<int> lis(sz, 1);

  for(int i = 1; i < sz; i++){ 
    for(int j = 0; j != i; j++){
      if(v[i] <= v[j] && lis[i] < lis[j]+1){
        lis[i] = lis[j]+1;
      }
    }
  }

  int mx = 0;
  for(auto it : lis){
    mx = max(mx, it);
  }

  return mx;
}

int main(){
  int n;
  vector<int> v;
  int test = 1;

  while(cin >> n){
    if(n == -1){
      if(v.size() == 0){
        break;
      }
      
      if(test != 1){
        cout << endl;
      }

      cout << "Test #"<<test<<":" << endl;
      test++;

      cout << "  maximum possible interceptions: " << lis(v) << endl;
      v.clear();
      continue;
    }

    v.push_back(n);
  }
}
