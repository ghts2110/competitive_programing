#include <iostream>
#include <cmath>

using namespace std;

int main(){
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int q;
  cin >> q;

  while(q--){
    double x3, y3;
    cin >> x3 >> y3;

    int asw = (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
    if(asw > 0){
      cout << "COUNTER_CLOCKWISE" << endl;
    }else if(asw < 0){
      cout << "CLOCKWISE" << endl;
    }else{
      int mnX = min(x1, x2), mnY = min(y1, y2);
      int mxX = max(x1, x2), mxY = max(y1, y2);

      if(mnX <= x3 && x3 <= mxX && mnY <= y3 && y3 <= mxY){
        cout << "ON_SEGMENT" << endl;
      }else if((x1 < x2 && x1 > x3) || (x1 > x2 && x1 < x3) || (y1 < y2 && y1 > y3) || (y1 > y2 && y1 < y3)){
        cout << "ONLINE_BACK" << endl;
      }else{
        cout << "ONLINE_FRONT" << endl;
      }
    }
  }
}