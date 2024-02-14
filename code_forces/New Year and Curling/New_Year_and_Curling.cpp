#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
  int n, r;
  cin >> n >> r;

  vector<double> v(n), h(n);
  for(int i = 0; i != n; i++){
    double x;
    cin >> x;
    v[i] = x;

    double asw = r;

    for(int j = i-1; j >= 0; j--){
      double dis = abs(v[j]-x);
      if(dis <= 2*r){
        double y = sqrt(2*r*2*r-dis*dis);
        asw = max(asw, y+h[j]);
      }
    }

    h[i] = asw;
    printf("%.6lf ", asw);
    if(i == n-1){
      printf("\n");
    }
  }
}