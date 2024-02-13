#include <iostream>
#include <cstdio>

using namespace std;

struct Point{
  double x, y;
};

int main(){
  double rx, ry;
  Point p1 = {0, 0}, p2 = {0, 0}, p3 = {0, 0};

  cin >> rx >> ry;
  p1.x = rx;
  p1.y = ry;

  cin >> rx >> ry;
  p2.x = rx;
  p2.y = ry;

  int q;
  cin >> q;

  while(q--){
    double x, y;
    cin >> x >> y;
    p3.x = x;
    p3.y = y;

    Point v= {0, 0}, u = {0, 0};
    v.x = p2.x-p1.x;
    v.y = p2.y-p1.y;
    u.x = p3.x-p1.x;
    u.y = p3.y-p1.y;

    double kx = v.x*2*(u.x*v.x + u.y*v.y)/(v.x*v.x + v.y*v.y);
    double ky = v.y*2*(u.x*v.x + u.y*v.y)/(v.x*v.x + v.y*v.y);
    printf("%.8lf %.8lf\n", p1.x+kx-u.x, p1.y+ky-u.y);
  }
}