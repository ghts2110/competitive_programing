#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int r1, r2, n;
  cin >> r1 >> r2 >> n;
  r2 = r1 - r2;

  int asw = 0;
  for(int i = 0; i != n; i++){
    int x, y, r;
    cin >> x >> y >> r;

    double dist = sqrt(x*x + y*y);
    if(dist-r >= r2 && dist+r <= r1){
      asw++;
    }
  }

  cout << asw << endl;
}