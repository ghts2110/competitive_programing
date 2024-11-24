#include <iostream>

using namespace std;

int gcd(int a, int b){
  if(b==0){
    return a;
  }

  return gcd(b, a%b);
}

int lcm(long long a, long long b, int g){
  return a*b/g;
}

int main(){
  int t;
  cin >> t;

  while(t--){
    long long n, m;
    cin >> n >> m; 
    
    int g = gcd(n, m);
    int l = lcm(n, m, g);

    if(g == n && l == m){
      cout << n << " " << m << endl;
    }else{
      cout << -1 << endl;
    }
  }
}
