#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int n;
  double gx, gy, dx, dy;
  while(cin >> n >> gx >> gy >> dx >> dy){
    bool b = false;
    while(n--){
      double x, y;
      cin >> x >> y;

      if(b){
        continue;
      }

      double distG = sqrt((gx-x)*(gx-x)+(gy-y)*(gy-y));
      double distD = sqrt((dx-x)*(dx-x)+(dy-y)*(dy-y));

      if(distG*2 <= distD){
        b = true;
        printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", x, y);
      }
    }

    if(!b){
      cout << "The gopher cannot escape." << endl;
    }
  }
}