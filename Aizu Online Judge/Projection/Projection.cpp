#include <iostream>
#include <cstdio>

using namespace std;
struct Point{
  double x, y;
};

void equal(Point &a, double x, double y){
  a.x = x;
  a.y = y;
}

Point sub(Point a, Point b){
  b.x -= a.x;
  b.y -= a.y;

  return b;
}

double projection(Point v, Point u){
  return (v.x*u.x + v.y*u.y)/(v.x*v.x + v.y*v.y);
}

int main(){
  double x1, y1, x2, y2;
  Point p1 = {0, 0}, p2 = {0, 0}, p3 = {0, 0};

  cin >> x1 >> y1 >> x2 >> y2;
  equal(p1, x1, y1);
  equal(p2, x2, y2);

  int q;
  cin >> q;

  while(q--){
    double x, y;
    cin >> x >> y;
    equal(p3, x, y);

    Point v = sub(p1, p2);
    Point u = sub(p1, p3);

    double k = projection(v, u);
    double aswX = v.x*k + p1.x;
    double aswY = v.y*k + p1.y;

    printf("%.8lf %.8lf\n", aswX, aswY);
  }
}