#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

struct Point{
    double x, y;
};


double dist(pair<double, double> p1, pair<double, double> p2){
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

Point circle(Point &a, Point &b, Point &c) {
    static Point ab, ac, o;
    static double a1, b1, c1, a2, b2, c2, D, D1, D2;
    ab.x = (a.x+b.x)/2, ab.y = (a.y+b.y)/2;
    ac.x = (a.x+c.x)/2, ac.y = (a.y+c.y)/2;

    a1 = a.x-b.x, b1 = a.y-b.y;
    c1 = a1*ab.x + b1*ab.y;
    a2 = a.x-c.x, b2 = a.y-c.y;
    c2 = a2*ac.x + b2*ac.y;

    D = a1*b2-a2*b1;
    D1 = c1*b2-c2*b1;
    D2 = a1*c2-a2*c1;

    o.x = D1/D;
    o.y = D2/D;

    return o;
}

int main(){
    double ax, ay, bx, by, cx, cy;
    while(cin >> ax >> ay >> bx >> by >> cx >> cy){
        Point A = {ax, ay};
        Point B = {bx, by};
        Point C = {cx, cy};

        Point o = circle(A, B, C);
        double h = o.x;
        double k = o.y;

        double r = dist({h, k}, {ax, ay});

        double c = -2*h, d = -2*k, e = h*h + k*k - r*r;

        if(h == 0){
            printf("x^2 + ");
        }else{
            printf("(x ");
            if(h < 0){
                printf("+ ");
            }else{
                printf("- ");
            }
            printf("%.3f)^2 + ", abs(h));
        }

        if(k == 0){
            printf("y^2 = ");
        }else{
            printf("(y ");
            if(k < 0){
                printf("+ ");
            }else{
                printf("- ");
            }
            printf("%.3f)^2 = ", abs(k));
        }

        if(r == 0){
            printf("0\n");
        }else{  
            printf("%.3f^2\n", abs(r));
        }

        printf("x^2 + y^2 ");
        if(c != 0){
            if(c < 0){
                printf("- ");
            }else{
                printf("+ ");
            }
            printf("%.3fx ", abs(c));
        }

        if(d != 0){
            if(d < 0){
                printf("- ");
            }else{
                printf("+ ");
            }
            printf("%.3fy ", abs(d));
        }
        if(e == 0){
            printf("= 0\n\n");
        }else{


            if(e < 0){
                printf("- ");
            }else{
                printf("+ ");
            }
            printf("%.3f = 0\n\n", abs(e));
        }
    }
}
