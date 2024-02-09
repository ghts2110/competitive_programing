#include <iostream>

using namespace std;

int main(){
  double h, l;
  while(cin >> h >> l){

    printf("%.6lf\n", (l*l - h*h)/(2*h));
  }
}