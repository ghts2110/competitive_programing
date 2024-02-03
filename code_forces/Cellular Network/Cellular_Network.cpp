#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
  int n, m;
  cin >> n >> m;

  vector<ll> v(n), t(m+1);
  for(int i = 0; i != n;i ++){
    cin >> v[i];
  }

  t[0] = -1e18;
  for(int i = 0;i != m; i++){
    cin >> t[i+1];
  }

  sort(t.begin(), t.end());

  ll mx = 0;
  for(int i = 0; i != n; i++){
    int ind = upper_bound(t.begin(), t.end(), v[i]) - t.begin();
    mx = max(mx, min(abs(v[i] - t[ind]), abs(v[i] - t[ind-1])));
  }

  cout << mx << endl;
}